#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* An implementation of 5-stage classic pipeline simulation */

/* don't count instructions flag, enabled by default, disable for inst count */
#undef NO_INSN_COUNT

#include "host.h"
#include "misc.h"
#include "machine.h"
#include "regs.h"
#include "memory.h"
#include "loader.h"
#include "syscall.h"
#include "dlite.h"
#include "sim.h"
#include "sim-pipe.h"

#include "cache.h"

/* simulated registers */
static struct regs_t regs;

static struct cache_t *cp;

/* simulated memory */
static struct mem_t *mem = NULL;

/* register simulator-specific options */
void
sim_reg_options(struct opt_odb_t *odb)
{
  opt_reg_header(odb, 
"sim-pipe: This simulator implements based on sim-fast.\n"
		 );
}

/* check simulator-specific option values */
void
sim_check_options(struct opt_odb_t *odb, int argc, char **argv)
{
  if (dlite_active)
    fatal("sim-pipe does not support DLite debugging");
}

/* register simulator-specific statistics */
void
sim_reg_stats(struct stat_sdb_t *sdb)
{
#ifndef NO_INSN_COUNT
  stat_reg_counter(sdb, "sim_num_insn",
		   "total number of instructions executed",
		   &sim_num_insn, sim_num_insn, NULL);
#endif /* !NO_INSN_COUNT */
  stat_reg_int(sdb, "sim_elapsed_time",
	       "total simulation time in seconds",
	       &sim_elapsed_time, 0, NULL);
#ifndef NO_INSN_COUNT
  stat_reg_formula(sdb, "sim_inst_rate",
		   "simulation speed (in insts/sec)",
		   "sim_num_insn / sim_elapsed_time", NULL);
#endif /* !NO_INSN_COUNT */
  ld_reg_stats(sdb);
  mem_reg_stats(mem, sdb);
}

/* the buffer for each stage */
struct ifid_buf fd;
struct idex_buf de;
struct exmem_buf em;
struct memwb_buf mw;

/* the trace output file */
FILE *trace;

/* current instruction*/
md_inst_t inss[5];
md_addr_t pcs[5];

/*whether target address*/
int valid_jump;

/* trace stages */
char *stages[] = {"[IF]", "[ID]", "[EX]", "[MEM]", "[WB]"};

#define DNA			(-1)

/* general register dependence decoders */
#define DGPR(N)			(N)
#define DGPR_D(N)		((N) &~1)

/* floating point register dependence decoders */
#define DFPR_L(N)		(((N)+32)&~1)
#define DFPR_F(N)		(((N)+32)&~1)
#define DFPR_D(N)		(((N)+32)&~1)

/* miscellaneous register dependence decoders */
#define DHI			(0+32+32)
#define DLO			(1+32+32)
#define DFCC		(2+32+32)
#define DTMP		(3+32+32)

unsigned int blk_access_fn(enum mem_cmd cmd, md_addr_t baddr, int bsize, struct cache_blk_t *blk, tick_t now){
	return 0;
}
void
sim_init(void)
{
  /* allocate and initialize register file */
  regs_init(&regs);

  /* allocate and initialize memory space */
  mem = mem_create("mem");
  mem_init(mem);

  /* initialize stage latches (the buffers)*/
  /* IF/ID */
  memset(&fd.inst, '\0', sizeof(md_inst_t));
  fd.PC = 0;
  fd.NPC = 0;
  fd.latched = 0;

  /* ID/EX */
  de.PC = 0;
  de.NPC = 0;
  memset(&de.inst, '\0', sizeof(md_inst_t));
  de.opcode = 0;
  memset(&de.oprand, '\0', sizeof(oprand_t));

  /* EX/MEM */
  em.PC = 0;
  em.NPC = 0;
  memset(&em.inst, '\0', sizeof(md_inst_t));
  em.ALUres = 0;
  em.regDest = 0;

  /* MEM/WB */
  mw.PC = 0;
  mw.NPC = 0;
  memset(&mw.inst, '\0', sizeof(md_inst_t));
  mw.ALUres = 0;
  mw.regDest = 0;

  cp = cache_create("cache", 16, 16, FALSE, 0, 4, FIFO, blk_access_fn, 1);
}

/* load program into simulated state */
void
sim_load_prog(char *fname,		/* program to load */
	      int argc, char **argv,	/* program arguments */
	      char **envp)		/* program environment */
{
  /* load program text and data, set up environment, memory, and regs */
  ld_load_prog(fname, argc, argv, envp, &regs, mem, TRUE);
}

/* print simulator-specific configuration information */
void
sim_aux_config(FILE *stream)
{  
	/* nothing currently */
}

/* dump simulator-specific auxiliary simulator statistics */
void
sim_aux_stats(FILE *stream)
{  /* nada */}

/* un-initialize simulator-specific state */
void 
sim_uninit(void)
{ /* nada */ }


/*
 * configure the execution engine
 */

/* next program counter */
#define SET_NPC(EXPR)		(regs.regs_NPC = (EXPR))

/* current program counter */
#define CPC			(regs.regs_PC)

/* general purpose registers */
#define GPR(N)			(regs.regs_R[N])
#define SET_GPR(N,EXPR)		(regs.regs_R[N] = (EXPR))
#define DECLARE_FAULT(EXP) 	{;}
#if defined(TARGET_PISA)

/* floating point registers, L->word, F->single-prec, D->double-prec */
#define FPR_L(N)		(regs.regs_F.l[(N)])
#define SET_FPR_L(N,EXPR)	(regs.regs_F.l[(N)] = (EXPR))
#define FPR_F(N)		(regs.regs_F.f[(N)])
#define SET_FPR_F(N,EXPR)	(regs.regs_F.f[(N)] = (EXPR))
#define FPR_D(N)		(regs.regs_F.d[(N) >> 1])
#define SET_FPR_D(N,EXPR)	(regs.regs_F.d[(N) >> 1] = (EXPR))

/* miscellaneous register accessors */
#define SET_HI(EXPR)		(regs.regs_C.hi = (EXPR))
#define HI			(regs.regs_C.hi)
#define SET_LO(EXPR)		(regs.regs_C.lo = (EXPR))
#define LO			(regs.regs_C.lo)
#define FCC			(regs.regs_C.fcc)
#define SET_FCC(EXPR)		(regs.regs_C.fcc = (EXPR))

#endif

/* precise architected memory state accessor macros */
#define READ_BYTE(SRC, FAULT)						\
  ((FAULT) = md_fault_none, MEM_READ_BYTE(mem, (SRC)))
#define READ_HALF(SRC, FAULT)						\
  ((FAULT) = md_fault_none, MEM_READ_HALF(mem, (SRC)))
#define READ_WORD(SRC, FAULT)						\
  ((FAULT) = md_fault_none, MEM_READ_WORD(mem, (SRC)))
#ifdef HOST_HAS_QWORD
#define READ_QWORD(SRC, FAULT)						\
  ((FAULT) = md_fault_none, MEM_READ_QWORD(mem, (SRC)))
#endif /* HOST_HAS_QWORD */

#define WRITE_BYTE(SRC, DST, FAULT)					\
  ((FAULT) = md_fault_none, MEM_WRITE_BYTE(mem, (DST), (SRC)))
#define WRITE_HALF(SRC, DST, FAULT)					\
  ((FAULT) = md_fault_none, MEM_WRITE_HALF(mem, (DST), (SRC)))
#define WRITE_WORD(SRC, DST, FAULT)					\
  ((FAULT) = md_fault_none, MEM_WRITE_WORD(mem, (DST), (SRC)))
#ifdef HOST_HAS_QWORD
#define WRITE_QWORD(SRC, DST, FAULT)					\
  ((FAULT) = md_fault_none, MEM_WRITE_QWORD(mem, (DST), (SRC)))
#endif /* HOST_HAS_QWORD */

/* system call handler macro */
#define SYSCALL(INST)	sys_syscall(&regs, mem_access, mem, INST, TRUE)

#ifndef NO_INSN_COUNT
#define INC_INSN_CTR()	sim_num_insn++
#else /* !NO_INSN_COUNT */
#define INC_INSN_CTR()	/* nada */
#endif /* NO_INSN_COUNT */

#define CLOCK() sim_clkn++


/* start simulation, program loaded, processor precise state initialized */
void
sim_main(void)
{
  fprintf(stderr, "sim: ** starting *pipe* functional simulation **\n");

  /* must have natural byte/word ordering */
  if (sim_swap_bytes || sim_swap_words)
    fatal("sim: *pipe* functional simulation cannot swap bytes or words");

  /* set up initial default next PC */
  regs.regs_NPC = regs.regs_PC;
  /* maintain $r0 semantics */
  regs.regs_R[MD_REG_ZERO] = 0;

  trace = fopen("trace.txt","w+");

  while (TRUE)
  {
	CLOCK();
	/*start your pipeline simulation
	 *executed in the inversed order!!
         *! when 'write to' and 'read from' a register simutaneously, write first.
	 */
	do_wb();
	do_mem();
	do_ex();
	do_id();
	do_if();
        
  }
}

void do_if()
{
  md_inst_t instruction;

    regs.regs_PC = regs.regs_NPC;
    MD_FETCH_INSTI(instruction, mem, CPC);   
SET_NPC(CPC + sizeof(md_inst_t));
    if(!fd.latched){
    	fd.PC = CPC;
    	fd.NPC = regs.regs_NPC;
    	fd.inst = instruction;
    }

  inss[0] = instruction;
  pcs[0] = CPC;
}

void insert_nop_de(){
  de.inst = MD_NOP_INST;
  /* control signal */
  memset(&de.exe_signal, '\0', sizeof(exeSig_t));
  de.exe_signal.operation = 5; // no operation
  memset(&de.mem_signal, '\0', sizeof(memSig_t));
  memset(&de.wb_signal, '\0', sizeof(wbSig_t));
}
void insert_nop_fd(){
  fd.inst = MD_NOP_INST;
  
}
/* read from buffer 'fd'
 * write to buffer 'de'
 */
void do_id()
{
    inss[1] = fd.inst;
    pcs[1] = fd.PC;
    /* for common information*/
    md_inst_t inst = fd.inst;    
    de.PC = fd.PC;/*NPC*/
    de.NPC = fd.NPC;
    de.inst = inst;/*instruction*/
    MD_SET_OPCODE(de.opcode, inst);/*opcode*/

    /* all task: 
       (1) decode register number
       (2) read register number
       (3) set control signal
     */
// decode register
#define DEFINST(OP,MSK,NAME,OPFORM,RES,FLAGS,O1,O2,I1,I2,I3)\
  if (OP==de.opcode){\
    de.oprand.out1 = O1;\
    de.oprand.out2 = O2;\
    de.oprand.in1 = I1;\
    de.oprand.in2 = I2;\
    de.oprand.in3 = I3;\
    goto READ_OPRAND_VALUE;\
  }
#define DEFLINK(OP,MSK,NAME,MASK,SHIFT)
#define CONNECT(OP)
#include "machine.def"

READ_OPRAND_VALUE:
    switch(de.opcode){
    case LUI:
         de.data1 = IMMI(de.inst);
         break;
    case ADDU:case ADD:case SUB:case SUBU:case AND_:case OR:case XOR:case NOR:
         de.data1 = GPR(de.oprand.in1);
         de.data2 = GPR(de.oprand.in2);
         break;
    case ADDIU:case SLTI:case ANDI:case ADDI:case ORI:
         de.data1 = GPR(de.oprand.in1);
         de.imm = IMMI(de.inst);
         break;
    case SLL:
         de.data1 = GPR(de.oprand.in1);
         de.shamt = SHAMT(de.inst);
         break;
    case SW:
         de.data1 = GPR(de.oprand.in2);/* bs(rs): base address */
	 de.data2 = GPR(de.oprand.in1);/* rt: contain the value to store */
         int temp = de.oprand.in1;
         de.oprand.in1 = de.oprand.in2;
         de.oprand.in2 = temp;
         de.imm = IMMI(de.inst);
         break;
     case LW:
         de.data1 = GPR(de.oprand.in2);/* bs(rs): base address*/
         de.oprand.in1 = de.oprand.in2;
         de.oprand.in2 = DNA;
         de.imm = IMMI(de.inst);/*imm: memory offset*/
         break;
     case JUMP:
         de.jtarg = TARGI(de.inst);
         break;
     case BNE:case BEQ:
         de.data1 = GPR(de.oprand.in1);
         de.data2 = GPR(de.oprand.in2);//printf("data2 in decode for bne: %d\n", de.oprand.in2);
         de.imm = IMMI(de.inst); /*imm: memory offset*/
         break;
  }

  memset(&de.exe_signal, '\0', sizeof(exeSig_t));
  de.exe_signal.operation = 5; // no operation
  memset(&de.mem_signal, '\0', sizeof(memSig_t));
  memset(&de.wb_signal, '\0', sizeof(wbSig_t));
  //set control signal, delegate to each instruction in machine.def
  switch(de.opcode){
  #define DEFINST(OP,MSK,NAME,OPFORM,RES,FLAGS,O1,O2,I1,I2,I3)\
    case OP:\
      SYMCAT(OP, _SIGSET);\
      break;
  #include "machine.def"
     
  }
  int hazard = 0;
//for de/ex data hazard
  if(em.wb_signal.alu2reg && em.regDest != 0){
    if(em.regDest == de.oprand.in1){
       de.data1 = em.ALUres;
    }else if(em.regDest == de.oprand.in2){
       de.data2 = em.ALUres;
    }
  }
 
  if(em.wb_signal.mem2reg && (em.regDest != 0
                              && (em.regDest == de.oprand.in1 || em.regDest == de.oprand.in2))){
     //only forward cannot save the day
     insert_nop_de();
     fd.latched = 1;
     hazard = 1;
  }
// for de/mem data hazard
   if(mw.wb_signal.alu2reg && mw.regDest != 0){
      if(mw.regDest == de.oprand.in1){
       de.data1 = mw.ALUres;
      }else if(mw.regDest == de.oprand.in2){
       de.data2 = mw.ALUres;
      }
   }
   
   if(mw.wb_signal.mem2reg && mw.regDest != 0){
     if(mw.regDest == de.oprand.in1){
       de.data1 = mw.memData;
     }else if(mw.regDest == de.oprand.in2){
       de.data2 = mw.memData;
     }
   }

//for control hazard
  if(de.mem_signal.branch){
    // move computation of the jump address to decode stage
    md_addr_t jump_addr;
    if(de.exe_signal.jaddr == 1){
      // from target(jump)
      jump_addr = (de.PC & 036000000000) | (de.jtarg << 2);
      if(de.opcode == JUMP){ 
      	regs.regs_NPC = jump_addr;
      	valid_jump = 1;
      }
    }else if(de.exe_signal.jaddr == 2){
      // from offset(bne)
      jump_addr = de.NPC + (de.imm << 2);
      if((de.opcode == BNE && de.data1 != de.data2)
		|| (de.opcode == BEQ && de.data1 == de.data2)){ // move the equality unit to decode stage
           regs.regs_NPC = jump_addr;
           valid_jump = 1;
      }
    }
  }

  // the fd is opened from this cycle on
  if(hazard == 0 && fd.latched == 1){
     if(!valid_jump)
         regs.regs_NPC = regs.regs_PC;
     else
         valid_jump = 0;
     fd.latched = 0;
  }
  
  if(hazard == 0 && fd.latched == 0){
    valid_jump = 0;
  }
}

void do_ex()
{
  /* information for common instruction */
  em.inst = de.inst;
  em.PC = de.PC;
  em.NPC = de.NPC;
 
  /* pass on control signal */
  em.mem_signal = de.mem_signal;
  em.wb_signal = de.wb_signal;
  
  /* for addu
     (1) choose data2
     (2) ALU computation
     (3) set condition code
   */

  em.cond = 1; //default condition code is true
  //choose data2
  int data2 = 0;
  switch(de.exe_signal.data2Src)
  {
    case 0:
      data2 = de.data2; break;
    case 1:
      data2 = de.imm; break;
    case 2:
      data2 = de.shamt; break;
    case 3:
      data2 = 16; break;
  }

  // ALU compute
  switch(de.exe_signal.operation){
    case 0:
        if(de.exe_signal.overflow)
           if (OVER(de.data1, data2))						
              DECLARE_FAULT(md_fault_overflow);	
	em.ALUres = de.data1 + data2; break;
    case 1:
	 if(de.exe_signal.underflow)
    	     if (UNDER(de.data1, de.data2))					
      	         DECLARE_FAULT(md_fault_overflow);	
	em.ALUres = de.data1 - data2; break;
    case 2:
    	em.ALUres = de.data1 < data2; break;
    case 3:
        em.ALUres = de.data1 << data2;break;
    case 4:
        em.ALUres = de.data1 & data2;break;
    case 5:
        goto NO_NEED_UPDATE_COND;
    case 6: 
        em.ALUres = (de.data1 != data2);break;
    case 7:
	em.ALUres = (de.data1 == data2);break;
    case 8:
	em.ALUres = (de.data1 | data2); break;
    case 9:
	em.ALUres = de.data1 ^ de.data2;break;
    case 10:
	em.ALUres = ~(de.data1 | de.data2);break;
  }
  em.cond = (em.ALUres != 0);
NO_NEED_UPDATE_COND:
  // for jump; to compute the jump address
  /* has been moved to decode stage */

  //pass on register destination (invalid when regWrite == 0)
  em.regDest = de.oprand.out1;

  /* for store */
  em.data2 = de.data2;

  inss[2] = em.inst;
  pcs[2] = em.PC;
}

void do_mem()
{
  /* information for common instruction */
  mw.inst = em.inst;
  mw.PC = em.PC;
  mw.NPC = em.NPC;

  /* pass on control signal */
  mw.wb_signal = em.wb_signal;
  
  /* for addu */
  mw.ALUres = em.ALUres;
  mw.regDest = em.regDest;

  /* for sw */
  if(em.mem_signal.writeMem == 1){
    /**enum md_fault_type _fault;
    WRITE_WORD((word_t) em.data2, em.ALUres, _fault);			
    if (_fault != md_fault_none)
      DECLARE_FAULT(_fault);**/	
	cache_access(cp, Write, em.ALUres, (word_t *)&(em.data2), sizeof(word_t), sim_clkn, NULL, NULL);		
  }

  /* for lw */
  if(em.mem_signal.readMem == 1){
    /**enum md_fault_type _fault;	
    word_t result = READ_WORD(em.ALUres, _fault);
    if (_fault != md_fault_none)
      DECLARE_FAULT(_fault);
    mw.memData = result;**/	
	cache_access(cp, Read, em.ALUres, (word_t *)&(mw.memData), sizeof(word_t), sim_clkn, NULL, NULL);
  }

  // for branch: set NPC 
  /* has been moved to decode stage*/

  inss[3] = mw.inst;
  pcs[3] = mw.PC;
}                                                                                        

void do_wb()
{
  inss[4] = mw.inst;
  pcs[4] = mw.PC;
  /* for addu */
  if(mw.wb_signal.alu2reg  == 1)
      SET_GPR(mw.regDest, mw.ALUres);

  if(mw.wb_signal.mem2reg == 1)
     SET_GPR(mw.regDest, mw.memData);

  if(mw.wb_signal.exitCode2reg == 1){
	cache_flush(cp, sim_clkn);
	cache_stats(cp, stdout);
fprintf(trace, "[Cycle %d]----------------------------------------------------------------------\n", sim_clkn);
        enum md_opcode op;
        for(int i = 0; i<5; i++){
          fprintf(trace, "%s ", stages[i]);
	  MD_SET_OPCODE(op, inss[i]);
          if(op == OP_NA)
          	fprintf(trace, "Empty");
          else
		md_print_insn(inss[i], pcs[i], trace);
          fprintf(trace, "\n");
        }
        enum md_fault_type _fault;
        fprintf(trace, "[REGS] r[2]=0x%x r[3]=0x%x r[4]=0x%x r[5]=0x%x r[6]=0x%x mem=%d\n", 
		GPR(2), GPR(3), GPR(4), GPR(5), GPR(6), READ_WORD(GPR(30)+16, _fault));
        fprintf(trace, "-------------------------------------------------------------------------------------------------\n");
    SET_GPR(2, SS_SYS_exit);
    sys_syscall(&regs, mem_access, mem, mw.inst, TRUE);
  }
}

