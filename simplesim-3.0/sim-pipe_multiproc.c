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
#include "mycache.h"
#include "pipe.h"
#include <signal.h>
#include <sys/time.h>

//#define DEBUG
#ifndef Ready
#define Ready 1
#endif

#define PENALTY 9
enum md_fault_type _fault;
/* types for shared memory */
typedef unsigned int* Heartbeat_t;
typedef struct clkn_buf_t{
    int clkn;
    int status;
} clkn_buf_t;

/* arguments for shared memory */
key_t heartbeat_key;
#define heartbeat_num 3
#define SET_HEARTBEAT(val)\
    heartbeat[0] = val;\
    heartbeat[1] = val;\
    heartbeat[2] = val;
key_t regs_key;
key_t mem_key;
key_t cache_key;
key_t mem_access_key;
#define FOR_FETCH 0
#define FOR_MEMORY 1
key_t de_key;
key_t em_key;
key_t mw_key;
key_t clkn_buf_key;
key_t reg_rd_key;
int heartbeat_shmid;
int regs_shmid;
int mem_shmid;
int cache_shmid;
int de_shmid;
int em_shmid;
int mw_shmid;
#define CAN_READ 0
#define CAN_WRITE 1
#define DONE 3
int clkn_buf_shmid;
int mem_access_shmid;
int reg_rd_shmid;

/* shared memory */
Heartbeat_t heartbeat;
#define Ready 1
static struct regs_t *regs;
static struct mem_t *mem = NULL;
static ucache_t *cp = NULL;
int enable_icache = 0;
int enable_dcache = 0;
struct idex_buf *de;
struct exmem_buf *em;
struct memwb_buf *mw;
clkn_buf_t *clkn_buf;
int *mem_access_status;
int *reg_rd;

/* output file for every core */
FILE *trace0, *trace1, *trace2, *trace3;
struct timeval start, end;

int pid[3];  // all 3 child processes

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
  for(int i = 0; i<argc; i++){
  	if(strcmp(argv[i],"-dcache")==0){
  		printf("The data cache simulation is enabled.\n");
		enable_dcache = 1;
	}
	if(strcmp(argv[i],"-icache")==0){
		printf("The instruction cache simulation is enabled.\n");
		enable_icache = 1;
	}
  }
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
struct ifid_buf fd;  // no need to put into share memory

/* the trace output file */
FILE *trace;

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

void
shm_key_init()
{
  heartbeat_key = 9;
  regs_key = 1;
  mem_key = 2;
  cache_key = 3;
  de_key = 4;
  em_key = 5;
  mw_key = 6;
  clkn_buf_key = 7;
  mem_access_key = 8;
  reg_rd_key = 10;
}

void
sim_init(void)
{
  shm_key_init();
  /* allocate and initialize register file */
  regs = (struct regs_t *)Shmalloc(regs_key, sizeof(struct regs_t), &regs_shmid);
  regs_init(regs);

  /* allocate and initialize memory space */
  mem = mem_shm_create("mem", mem_key, &mem_shmid);  // to do for page and pte
  mem_init(mem);

  /* allocate shared hearbeat buffer */
  heartbeat = (Heartbeat_t)Shmalloc(heartbeat_key, heartbeat_num * sizeof(long), &heartbeat_shmid);
  SET_HEARTBEAT(!Ready);

  /* allocate de buffer, em buffer and mw buffer in shm */
  de = (struct idex_buf *)Shmalloc(de_key, sizeof(struct idex_buf), &de_shmid);
  em = (struct exmem_buf *)Shmalloc(em_key, sizeof(struct exmem_buf), &em_shmid);
  mw = (struct memwb_buf *)Shmalloc(mw_key, sizeof(struct memwb_buf), &mw_shmid);
  /* allocate clkn counter */
  clkn_buf = (clkn_buf_t *)Shmalloc(clkn_buf_key, sizeof(clkn_buf_t), &clkn_buf_shmid);
  clkn_buf->status = Ready;
  clkn_buf->clkn = 0;
  /* allocate memory access key */
  mem_access_status = (int *)Shmalloc(mem_access_key, sizeof(int), &mem_access_shmid);
  *mem_access_status = FOR_MEMORY;
  /* allocate register read status buffer */
  reg_rd = (int *)Shmalloc(reg_rd_key, sizeof(int), &reg_rd_shmid);
  *reg_rd = !Ready;

  /* initialize stage latches (the buffers)*/
  /* IF/ID */
  memset(&fd.inst, '\0', sizeof(md_inst_t));
  fd.PC = 0;
  fd.NPC = 0;
  fd.latched = 0;

  /* ID/EX */
  de->PC = 0;
  de->NPC = 0;
  memset(&de->inst, '\0', sizeof(md_inst_t));
  de->opcode = 0;
  memset(&de->oprand, '\0', sizeof(oprand_t));
  de->status = DONE;

  /* EX/MEM */
  em->PC = 0;
  em->NPC = 0;
  memset(&em->inst, '\0', sizeof(md_inst_t));
  em->ALUres = 0;
  em->regDest = 0;
  de->status = DONE;

  /* MEM/WB */
  mw->PC = 0;
  mw->NPC = 0;
  memset(&(mw->inst), '\0', sizeof(md_inst_t));
  mw->ALUres = 0;
  mw->regDest = 0;
  de->status = DONE;

  /*initialize the cache space*/
  if(enable_icache | enable_dcache)
      cp = ucache_shm_init(cache_key, &cache_shmid);
}

/* load program into simulated state */
void
sim_load_prog(char *fname,		/* program to load */
	      int argc, char **argv,	/* program arguments */
	      char **envp)		/* program environment */
{
  /* load program text and data, set up environment, memory, and regs */
  ld_load_prog(fname, argc, argv, envp, regs, mem, TRUE);
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
{ /* nada */
// close all file output stream
fclose(trace0);
fclose(trace1);
fclose(trace2);
fclose(trace3);
}


/*
 * configure the execution engine
 */

/* next program counter */
#define SET_NPC(EXPR)		(regs->regs_NPC = (EXPR))

/* current program counter */
#define CPC			(regs->regs_PC)

/* general purpose registers */
#define GPR(N)			(regs->regs_R[N])
#define SET_GPR(N,EXPR)		(regs->regs_R[N] = (EXPR))
#define DECLARE_FAULT(EXP) 	{;}
#if defined(TARGET_PISA)

/* floating point registers, L->word, F->single-prec, D->double-prec */
#define FPR_L(N)		(regs->regs_F.l[(N)])
#define SET_FPR_L(N,EXPR)	(regs->regs_F.l[(N)] = (EXPR))
#define FPR_F(N)		(regs->regs_F.f[(N)])
#define SET_FPR_F(N,EXPR)	(regs->regs_F.f[(N)] = (EXPR))
#define FPR_D(N)		(regs->regs_F.d[(N) >> 1])
#define SET_FPR_D(N,EXPR)	(regs->regs_F.d[(N) >> 1] = (EXPR))

/* miscellaneous register accessors */
#define SET_HI(EXPR)		(regs->regs_C.hi = (EXPR))
#define HI			(regs->regs_C.hi)
#define SET_LO(EXPR)		(regs->regs_C.lo = (EXPR))
#define LO			(regs->regs_C.lo)
#define FCC			(regs->regs_C.fcc)
#define SET_FCC(EXPR)		(regs->regs_C.fcc = (EXPR))

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
#define SYSCALL(INST)	sys_syscall(regs, mem_access, mem, INST, TRUE)

#ifndef NO_INSN_COUNT
#define INC_INSN_CTR()	sim_num_insn++
#else /* !NO_INSN_COUNT */
#define INC_INSN_CTR()	/* nada */
#endif /* NO_INSN_COUNT */


#define CLOCK() clkn_buf->clkn++	// change the counter to the shared space

#define print_regs(trace) \
fprintf(trace, "[REGS] r[4]=0x%x r[5]=0x%x r[6]=0x%x r[8]=0x%x r[9]=0x%x r[10]=0x%x r[16]=0x%x r[17]=0x%x r[18]=0x%x\n", \
		GPR(4), GPR(5), GPR(6), GPR(8), GPR(9), GPR(10), GPR(16), GPR(17), GPR(18));   // the macro for debug :(

//fetch & decode
void
sim_core0(void){
  // register the process to cpu 0
  set_cpu(0);
  while(TRUE){
  	WAIT_WHILE_STATUS(heartbeat[0], ==, !Ready);
        do_id();
        do_if();
  	SET_STATUS(heartbeat[0], !Ready);
  }
}

// execute
void
sim_core1(void){
  // register the process to cpu 1
  set_cpu(1);
  while(TRUE){
  	WAIT_WHILE_STATUS(heartbeat[1], ==, !Ready);
        do_ex();
  	SET_STATUS(heartbeat[1], !Ready);
  }
}

// memory & writeback
void
sim_core2(void){
  // register the process to cpu 2
  set_cpu(2);
  while(TRUE){
  	WAIT_WHILE_STATUS(heartbeat[2], ==, !Ready);
        do_wb();
        do_mem();
  	SET_STATUS(heartbeat[2], !Ready);
  }
}

void
myexit(){
  // kill other two left child process
  wait(NULL);
  kill(pid[0],SIGKILL);
  wait(NULL);
  kill(pid[1], SIGKILL);
  wait(NULL);
  // free a bunch of shared memory
  Shmfree(regs_shmid);
  Shmfree(mem_shmid);
  if(enable_icache | enable_dcache)
	Shmfree(cache_shmid);
  Shmfree(de_shmid);
  Shmfree(em_shmid);
  Shmfree(mw_shmid);
  Shmfree(clkn_buf_shmid);
  Shmfree(mem_access_shmid);
  Shmfree(heartbeat_shmid);
  Shmfree(reg_rd_shmid);
  // the main process exit, too
  exit(0);
}

// main control
void
sim_core3(void){
  // register the main process to cpu3
  set_cpu(3);
  int temp = 0; // for debug

  // register the signal handler for SIGCHLD to be notified when the process (mem/writeback) execute the exit syscall
  signal(SIGCHLD, myexit);
  while (TRUE)
  {
      // wait for all the stage finish the pass clock period
      WAIT_WHILE_STATUS(heartbeat[0], ==, Ready);
      WAIT_WHILE_STATUS(heartbeat[1], ==, Ready);
      WAIT_WHILE_STATUS(heartbeat[2], ==, Ready);
      CLOCK();

      /**printf("--%d--\n", sim_clkn);
      printf("register 5 = %d, set to 7\n", GPR(5));
      SET_GPR(5, GPR(5)+1);
      ucache_access(cp, Write, 5000000, (word_t *) &temp_cache, sizeof(int)/sizeof(word_t));
      temp_cache++;
      sleep(2);**/

/*** my debug output :( It is too complicated even if it is just a trivial error ***/

      //printf("[%d] mem: %x\n",clkn_buf->clkn, READ_WORD(GPR(30)+16, _fault));
      //printf("[%d]\n", clkn_buf->clkn);
      //if(GPR(8)%0x100<10 && GPR(8)>temp)
      //printf("GPR(8) = 0x%x/0x%x\n", temp = GPR(8), GPR(6));
      //printf("GPR(3) = 0x%x/0x%x\n", temp = GPR(3), GPR(0));
      //if(clkn_buf->clkn % 1000000 < 20){
      //fprintf(stderr, "clock : %d GPR(8) = 0x%x/0x%x GPR(9) = 0x%x/0x%x GPR(10) = 0x%x/0x%x\n", clkn_buf->clkn, GPR(8), GPR(6), GPR(9), GPR(5), GPR(10), GPR(5));
      //}

      // reset the share memory status
      SET_STATUS(*mem_access_status, FOR_MEMORY);
      SET_STATUS(*reg_rd, !Ready);
      SET_STATUS(de->status, CAN_READ);
      SET_STATUS(em->status, CAN_READ);
      SET_STATUS(mw->status, CAN_READ);
      // notify the child processes to go on executing
      SET_STATUS(heartbeat[0], Ready);
      SET_STATUS(heartbeat[1], Ready);
      SET_STATUS(heartbeat[2], Ready);
  }
}

/* start simulation, program loaded, processor precise state initialized */
void
sim_main(void)
{
  fprintf(stderr, "sim: ** starting *pipe* functional simulation **\n");

  /* must have natural byte/word ordering */
  if (sim_swap_bytes || sim_swap_words)
    fatal("sim: *pipe* functional simulation cannot swap bytes or words");

  /* set up initial default next PC */
  regs->regs_NPC = regs->regs_PC;
  /* maintain $r0 semantics */
  regs->regs_R[MD_REG_ZERO] = 0;

/***** all trace file for debugging ******/

  /**trace1 = fopen("core1_e.txt","w+");
  setlinebuf(trace1);
  trace0 = fopen("core0_fd.txt", "w+");
  setlinebuf(trace0);
  trace2 = fopen("core2_mw.txt", "w+");
  setlinebuf(trace2);
  trace3 = fopen("main_core.txt", "w+");
  setlinebuf(trace3);
  mem_access_trace = fopen("mem_access_d1.txt", "w+");
  setlinebuf(mem_access_trace);**/

gettimeofday(&start, NULL);
  // create all the processes
  if((pid[0] = fork())<0){
  	fprintf(stderr, "sim_main: 1st fork failed!\n");
	exit(-1);
  }else if(pid[0] == 0){
    //1st child process
    sim_core0();
  }else if(pid[0] > 0){
    if((pid[1] = fork())<0){
        fprintf(stderr, "sim_main: 2nd fork failed!\n");
	exit(-1);
    }else if(pid[1] == 0){
        //2nd child process
	sim_core1();
    }else{
        if((pid[2] = fork())<0){
	    fprintf(stderr, "sim_main: 3rd fork failed!\n");
	    exit(-1);
	}else if(pid[2] == 0){
	    //3rd child process
            sim_core2();
  	}else{
	    //main process
            sim_core3();
	} 
     }
  }

 /************** the old sequential version control logic *****************/

/**while (TRUE)
  {
	CLOCK();
	/*start your pipeline simulation
	 *executed in the inversed order!!
         *! when 'write to' and 'read from' a register simutaneously, write first.
	 *
	do_wb();
	do_mem();
	do_ex();
	do_id();
	do_if();

	/**if(sim_clkn>100)
		exit(0);**/
        /**fprintf(trace, "[Cycle %d]----------------------------------------------------------------------\n", sim_clkn);
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
        
  }**/
}


// the fetch stage
void do_if()
{
  md_inst_t instruction;
  regs->regs_PC = regs->regs_NPC;
  int lat = 0;

// wait for the signal to access cache/memory
WAIT_WHILE_STATUS(*mem_access_status, !=, FOR_FETCH);

  if(!enable_icache){
      MD_FETCH_INSTI(instruction, mem, CPC);
      lat = PENALTY;
  }else{
      lat = ucache_access(cp, Read, CPC, (word_t *) &instruction, 2);
  }

SET_STATUS(*mem_access_status, FOR_MEMORY);


    SET_NPC(CPC + sizeof(md_inst_t));
    if(!fd.latched){
    	fd.PC = CPC;
    	fd.NPC = regs->regs_NPC;
    	fd.inst = instruction;
        WAIT_WHILE_STATUS(clkn_buf->status, ==, !Ready);
        SET_STATUS(clkn_buf->status, !Ready);
	for(;lat>0;lat--)
	    CLOCK();
        SET_STATUS(clkn_buf->status, Ready);
    }
}

void insert_nop_de(){
  de->inst = MD_NOP_INST;
  /* control signal */
  memset(&(de->exe_signal), '\0', sizeof(exeSig_t));
  de->exe_signal.operation = 5; // no operation
  memset(&(de->mem_signal), '\0', sizeof(memSig_t));
  memset(&(de->wb_signal), '\0', sizeof(wbSig_t));
}
void insert_nop_fd(){
  fd.inst = MD_NOP_INST;
  
}
/* read from buffer 'fd'
 * write to buffer 'de'
 */
void do_id()
{
    /* for common information*/
    md_inst_t inst = fd.inst; 
    int opcode; 
    MD_SET_OPCODE(opcode, inst);/*opcode*/

    /* all task: 
       (1) decode register number
       (2) read register number
       (3) set control signal
     */
// decode register
  int in1, in2, in3;
  int out1, out2;
#define DEFINST(OP,MSK,NAME,OPFORM,RES,FLAGS,O1,O2,I1,I2,I3)\
  if (OP==opcode){\
    out1 = O1;\
    out2 = O2;\
    in1 = I1;\
    in2 = I2;\
    in3 = I3;\
    goto READ_OPRAND_VALUE;\
  }
#define DEFLINK(OP,MSK,NAME,MASK,SHIFT)
#define CONNECT(OP)
#include "mymachine.def"

int data1 = 0, data2 = 0, imm = 0, shamt = 0, jtarg = 0;
READ_OPRAND_VALUE:

// read from register after write to register
WAIT_WHILE_STATUS(*reg_rd, ==, !Ready);

    switch(opcode){
    case LUI:
         data1 = IMMI(inst);
         break;
    case ADDU:case ADD:case SUB:case SUBU:case AND_:case OR:case XOR:case NOR:case MULTU:
         data1 = GPR(in1);
         data2 = GPR(in2);
         break;
    case ADDIU:case SLTI:case ANDI:case ADDI:case ORI:
         data1 = GPR(in1);
         imm = IMMI(inst);
         break;
    case SLL:
         data1 = GPR(in1);
         shamt = SHAMT(inst);
         break;
    case SW:
         data1 = GPR(in2);/* bs(rs): base address */
	 data2 = GPR(in1);/* rt: contain the value to store */
         int temp = in1;
         in1 = in2;
         in2 = temp;
         imm = IMMI(inst);
         break;
     case LW:
         data1 = GPR(in2);/* bs(rs): base address*/
         in1 = in2;
         in2 = DNA;
         imm = IMMI(inst);/*imm: memory offset*/
         break;
     case JUMP:
         jtarg = TARGI(inst);
         break;
     case BNE:case BEQ:
         data1 = GPR(in1);
         data2 = GPR(in2);//printf("data2 in decode for bne: %d\n", de->oprand.in2);
         imm = IMMI(inst); /*imm: memory offset*/
         break;
	case MFLO:
		 SET_GPR(out1, LO);
		 break;
  }

  //wait for de buffer finishing read
  WAIT_WHILE_STATUS(de->status, !=, CAN_WRITE);
  de->NPC = fd.NPC;
  de->PC = fd.PC;
  de->inst = inst;
  de->opcode = opcode;
  de->oprand.in1 = in1; de->oprand.in2 = in2; de->oprand.in3 = in3;
  de->oprand.out1 = out1; de->oprand.out2 = out2;
  de->data1 = data1;
  de->data2 = data2;
  de->imm = imm;
  de->shamt = shamt;
  de->jtarg = jtarg;
  memset(&(de->exe_signal), '\0', sizeof(exeSig_t));
  de->exe_signal.operation = 5; // no operation
  memset(&(de->mem_signal), '\0', sizeof(memSig_t));
  memset(&(de->wb_signal), '\0', sizeof(wbSig_t));
  //set control signal, delegate to each instruction in machine.def
  switch(de->opcode){
  #define DEFINST(OP,MSK,NAME,OPFORM,RES,FLAGS,O1,O2,I1,I2,I3)\
    case OP:\
      SYMCAT(OP, _SIGSET);\
      break;
  #include "mymachine.def"
     
  }
  
  int hazard = 0;

// for de/mem data hazard
   WAIT_WHILE_STATUS(mw->status, !=, DONE);
   if(mw->wb_signal.alu2reg && mw->regDest != 0){
      if(mw->regDest == de->oprand.in1){
       de->data1 = mw->ALUres;  //fprintf(trace0, "data hazard with mem(alu,1)\n");
      }else if(mw->regDest == de->oprand.in2){
       de->data2 = mw->ALUres;  //fprintf(trace0, "data hazard with mem(alu,2)\n");
      }
   }
   
   if(mw->wb_signal.mem2reg && mw->regDest != 0){
     if(mw->regDest == de->oprand.in1){
       de->data1 = mw->memData;  //fprintf(trace0, "data hazard with mem(mem,1)\n");
     }else if(mw->regDest == de->oprand.in2){
       de->data2 = mw->memData;  //fprintf(trace0, "data hazard with mem(mem,2)\n");
     }
   }

//for de/ex data hazard

  WAIT_WHILE_STATUS(em->status, !=, DONE);
  if(em->wb_signal.alu2reg && em->regDest != 0){
    if(em->regDest == de->oprand.in1){
       de->data1 = em->ALUres;      //fprintf(trace0, "data hazard with exe(alu,1)\n");
    }else if(em->regDest == de->oprand.in2){
       de->data2 = em->ALUres;      //fprintf(trace0, "data hazard with exe(alu,2)\n");
    }
  }
  if(em->wb_signal.mem2reg && (em->regDest != 0
                              && (em->regDest == de->oprand.in1 || em->regDest == de->oprand.in2))){
     //only forward cannot save the day
     insert_nop_de();
     fd.latched = 1;
     hazard = 1;
     //fprintf(trace0, "data hazard with exe(mem,1|2)\n");
  }
//for control hazard
  if(de->mem_signal.branch){
    // move computation of the jump address to decode stage
    md_addr_t jump_addr;
    if(de->exe_signal.jaddr == 1){
      // from target(jump)
      jump_addr = (de->PC & 036000000000) | (de->jtarg << 2);
      if(de->opcode == JUMP){ 
      	regs->regs_NPC = jump_addr;
      	valid_jump = 1;
      }
    }else if(de->exe_signal.jaddr == 2){
      // from offset(bne)
      //fprintf(stderr, "to jump with data1 %d, data2 %d\n", data1, data2);
      jump_addr = de->NPC + (de->imm << 2);
      if((de->opcode == BNE && de->data1 != de->data2)
		|| (de->opcode == BEQ && de->data1 == de->data2)){ // move the equality unit to decode stage
           regs->regs_NPC = jump_addr;
           valid_jump = 1;
      }
    }
  }

  // the fd is opened from this cycle on
  if(hazard == 0 && fd.latched == 1){
     if(!valid_jump)
         regs->regs_NPC = regs->regs_PC;
     else
         valid_jump = 0;
     fd.latched = 0;
  }
  
  if(hazard == 0 && fd.latched == 0){
    valid_jump = 0;
  }
  SET_STATUS(de->status, DONE);
}
void do_ex()
{
  // wait for de buffer can be read
  WAIT_WHILE_STATUS(de->status, !=, CAN_READ);
  /* information for common instruction */
  md_inst_t inst = de->inst;
  md_addr_t PC = de->PC;
  md_addr_t NPC = de->NPC;
  memSig_t mem_signal = de->mem_signal;
  wbSig_t wb_signal = de->wb_signal;
  exeSig_t exe_signal = de->exe_signal;
  int cond;
  int opcode = de->opcode;
  int data1 = de->data1;
  int data2 = de->data2;
  int data2_c;
  int imm = de->imm;
  int shamt = de->shamt;
  int regDest = de->oprand.out1;
  SET_STATUS(de->status, CAN_WRITE);

  /* for addu
     (1) choose data2
     (2) ALU computation
     (3) set condition code
   */

  cond = 1; //default condition code is true
  //choose data2
  switch(exe_signal.data2Src)
  {
    case 0:
      data2_c = data2; break;
    case 1:
      data2_c = imm; break;
    case 2:
      data2_c = shamt; break;
    case 3:
      data2_c = 16; break;
  }



  // multiplication
  if(opcode == MULTU){
	int _i;								

    /* HI,LO <- [rs] * [rt], integer product of [rs] & [rt] to HI/LO */	
    SET_HI(0);								
    SET_LO(0);								
    if (data2_c & 020000000000)						
      SET_LO(data1);							
									
    for (_i = 0; _i < 31; _i++){									
	    SET_HI(HI << 1);						
	    SET_HI(HI + extractl(LO, 31, 1));				
	    SET_LO(LO << 1);					
	    if ((extractl(data2_c, 30 - _i, 1)) == 1){								
	        if (((unsigned)037777777777 - (unsigned)LO) < (unsigned)(data1)){		
		        SET_HI(HI + 1);						 
	        }								
	        SET_LO(LO + data1);					
	    }								
   }			
  }
  // ALU compute
  int ALUres;
  switch(exe_signal.operation){
    case 0:
        if(exe_signal.overflow)
           if (OVER(data1, data2_c))						
              DECLARE_FAULT(md_fault_overflow);	
	ALUres = data1 + data2_c; break;
    case 1:
	 if(exe_signal.underflow)
    	     if (UNDER(data1, data2_c))					
      	         DECLARE_FAULT(md_fault_overflow);	
	ALUres = data1 - data2_c; break;
    case 2:
    	ALUres = data1 < data2_c; break;
    case 3:
        ALUres = data1 << data2_c;break;
    case 4:
        ALUres = data1 & data2_c;break;
    case 5:
        goto NO_NEED_UPDATE_COND;
    case 6: 
        ALUres = (data1 != data2_c);break;
    case 7:
	ALUres = (data1 == data2_c);break;
    case 8:
	ALUres = (data1 | data2_c); break;
    case 9:
	ALUres = data1 ^ data2_c;break;
    case 10:
	ALUres = ~(data1 | data2_c);break;
  }
  cond = (ALUres != 0);
NO_NEED_UPDATE_COND:
  // for jump; to compute the jump address
  /* has been moved to decode stage */

  // wait for em buffer can be written
  WAIT_WHILE_STATUS(em->status, !=, CAN_WRITE);
  em->NPC = NPC;
  em->PC = PC;
  em->inst = inst;
  em->cond = cond;
  em->ALUres = ALUres;
  em->data2 = data2;
  //pass on register destination (invalid when regWrite == 0)
  em->regDest = regDest;
  em->mem_signal = mem_signal;
  em->wb_signal = wb_signal;
  SET_STATUS(em->status, DONE);
}

void do_mem()
{
  // wait for em buffer can be read
  WAIT_WHILE_STATUS(em->status, !=, CAN_READ);
  /* information for common instruction */
  md_inst_t inst = em->inst;
  md_addr_t PC = em->PC;
  md_addr_t NPC = em->NPC;

  /* pass on control signal */
  wbSig_t wb_signal = em->wb_signal;
  
  /* for addu */
  int ALUres = em->ALUres;
  int regDest = em->regDest;

  memSig_t mem_signal = em->mem_signal;
  int data2 = em->data2;
  SET_STATUS(em->status, CAN_WRITE);

  int memData;

  /* for sw */
  if(mem_signal.writeMem == 1){
      int lat;
      WAIT_WHILE_STATUS(*mem_access_status, !=, FOR_MEMORY);
      if(!enable_dcache){
          enum md_fault_type _fault;
          WRITE_WORD((word_t) data2, ALUres, _fault);			
          if (_fault != md_fault_none)
              DECLARE_FAULT(_fault);
	  lat = PENALTY;
      }else{
	  lat = ucache_access(cp, Write, ALUres, (word_t *) &data2, 1);
      }
      SET_STATUS(*mem_access_status, FOR_FETCH);

      WAIT_WHILE_STATUS(clkn_buf->status, ==, !Ready);
      SET_STATUS(clkn_buf->status, !Ready);
      for(;lat>0;lat--)
          CLOCK();
      SET_STATUS(clkn_buf->status, Ready);
  }

  /* for lw */
  if(mem_signal.readMem == 1){
      int lat;
      WAIT_WHILE_STATUS(*mem_access_status, !=, FOR_MEMORY);

      if(!enable_dcache){
          enum md_fault_type _fault;
          word_t result = READ_WORD(ALUres, _fault);
          if (_fault != md_fault_none)
              DECLARE_FAULT(_fault);
          memData = result;
	  lat = PENALTY;
      }else{
          lat = ucache_access(cp, Read, ALUres, (word_t *) &memData, 1);
      }
      SET_STATUS(*mem_access_status, FOR_FETCH);

      WAIT_WHILE_STATUS(clkn_buf->status, ==, !Ready);
      SET_STATUS(clkn_buf->status, !Ready);
      for(;lat>0;lat--)
          CLOCK();
      SET_STATUS(clkn_buf->status, Ready);
  }
  // ensure fetch have the access to memory/cache
  SET_STATUS(*mem_access_status, FOR_FETCH);

  // wait for mw buffer can be written
  WAIT_WHILE_STATUS(mw->status, !=, CAN_WRITE);
  mw->NPC = NPC;
  mw->PC = PC;
  mw->inst = inst;
  mw->memData = memData;
  mw->ALUres = ALUres;
  mw->regDest = regDest;
  mw->wb_signal = wb_signal;
  SET_STATUS(mw->status, DONE);

  // for branch: set NPC 
  /* has been moved to decode stage*/
}                                                                                        

void do_wb()
{
  // wait for mw buffer can be read
  WAIT_WHILE_STATUS(mw->status, !=, CAN_READ);
  if(mw->wb_signal.alu2reg  == 1)
      SET_GPR(mw->regDest, mw->ALUres);

  if(mw->wb_signal.mem2reg == 1)
     SET_GPR(mw->regDest, mw->memData);

  SET_STATUS(*reg_rd, Ready);
  if(mw->wb_signal.exitCode2reg == 1){
      if(cp != NULL){
          ucache_flush(cp);
          printf("access %d, miss %d, hit %d, replace %d, write back %d\n", cp->access, cp->miss, cp->hit, cp->replace, cp->write_back);
      }
      printf("clock :%d\n", clkn_buf->clkn);
      SET_GPR(2, SS_SYS_exit);
  gettimeofday(&end, NULL);
printf("elapse %.2f s\n", (end.tv_sec-start.tv_sec)+(end.tv_usec-start.tv_usec)/1000000.0);
      SYSCALL(mw->inst);
      // the parent process having been notified
  }
  SET_STATUS(mw->status, CAN_WRITE);
}

/******************************************************
Here is to simulate the cache access for SimpleScalar
********************************************************/

/**void print_line(ucache_line_t *line){
	printf("valid=%d, dirty=%d, tag=0x%x, data=%x %x %x %x ",
			line->valid, line->dirty, line->tag, line->data[0], line->data[1], line->data[2], line->data[3]);
}
void print_cache(ucache_t *cp){
	printf("access %d, miss %d, hit %d, replace %d, write back %d\n", cp->access, cp->miss, cp->hit, cp->replace, cp->write_back);
	for(int i = 0; i<16; i++){
		printf("set %d----------------------\n", i+1);
		ucache_set_t set = cp->sets[i];
		for(int j = 0; j<4; j++){
			ucache_line_t *line = set.lines+j;
			print_line(line);
			if(line==set.head)
				printf("<-head");
			if(line==set.tail)
				printf("<-tail");
			printf("\n");
		}
	}
}**/
ucache_t *ucache_init(){
	ucache_t* cp = (ucache_t *) calloc(1, sizeof(ucache_t));
	return cp;
}

// obtain the cache space from shared memory
ucache_t *ucache_shm_init(key_t key, int *shmid){
	ucache_t* cp = (ucache_t *) Shmalloc(key, sizeof(ucache_t), shmid);
	return cp;
}

int ucache_access(ucache_t *cp, enum mem_cmd cmd, md_addr_t addr, word_t *data, 
	int size/*how many words*/){	

	int latency = 0;
	unsigned int tag = ADDR_TAG(addr);
	unsigned int index = ADDR_INDEX(addr);
	unsigned int block = ADDR_BLOCK(addr);
	ucache_line_t *line, *repl;
	ucache_set_t *set;
	int i;

	// the new access to the cache
	cp->access++;
	set = cp->sets+index;
	//printf("addr=0x%x, tag=0x%x, index=%d, block#=%d\n", addr, tag, index, block);
	for(line=set->head; line!=NULL; line = line->next){
		if(line->valid == 1 && line->tag == tag)
			goto CACHE_HIT;
	}

	//printf("miss\n");
	cp->miss++; // cache miss
	//fprintf(trace, "miss %x\n", addr);
	latency = PENALTY;

	//find the replaced line
	for(i = 0; i<4; i++){
		line = set->lines+i;
		//printf("valid=%x\n", line->valid);
		if(line->valid == 0){
			//printf("find free line:\n");
			//print_line(line);
			goto FIND_FREE;
		}
	}

	// the set is fully filled
	//printf("replace\n");
	cp->replace ++;
	repl = set->head;
	repl->next->prev = NULL;
	set->head = repl->next;
	repl->next = NULL;
	repl->prev = NULL; // redundant

	if(repl->dirty == 1){
		//wirte back the dirty block
		//printf("write back\n");
		cp->write_back ++;
		md_addr_t wb_addr = (repl->tag<<8) | (index<<4);
		for(i=0; i<4; i++){
			enum md_fault_type _fault;
//printf("start writing, addr = 0x%x, data = %d \n", wb_addr+(i*4), repl->data[i]);
			WRITE_WORD(repl->data[i], wb_addr+(i*4), _fault);	
//printf("end writing\n");		
    		if (_fault != md_fault_none)
      			DECLARE_FAULT(_fault);
		}
	}
	repl->valid = 0;
	repl->dirty = 0;
	line = repl;
	
 FIND_FREE:
	// read from the memory
       //printf("find free\n");
	for(i=0; i<4; i++){
		word_t result;
		enum md_fault_type _fault;
		result = READ_WORD(((tag<<8) | (index<<4))+(i*4), _fault);
   		if (_fault != md_fault_none)
      		DECLARE_FAULT(_fault);
		line->data[i] = result;
	}
	// set the line
	line->valid = 1;
	line->tag = tag;
	line->dirty = 0;
	line->prev = NULL;
	line->next = NULL;
	
	if(set->head == NULL){
		set->head = line;
		set->tail = line;
	}else{
		// update the tail line, set linkers
		set->tail->next = line;
		line->prev = set->tail;
		set->tail = line;
	}

	//do the command
	if(cmd == Read){
		int i;
		for(i=0; i<size; i++){
			//printf("%d ", i);
			memcpy(data+i, line->data+block+i, sizeof(word_t));
			//printf("[%x]", *(line->data+block+i));
		}//printf("\n");
	}else if(cmd == Write){
		memcpy(line->data+block, data, sizeof(word_t));
		line->dirty = 1;
	}
	return latency;

CACHE_HIT:
	cp->hit++;
	//printf("hit %x\n", addr);
	if(cmd == Read){
		int i;
		for(i=0; i<size; i++){
			//printf("%d ", i);
			memcpy(data+i, line->data+block+i, sizeof(word_t));
			//printf("[%x]", *(line->data+block+i));
		}//printf("\n");
	}else if(cmd == Write){
		memcpy(line->data+block, data, sizeof(word_t));
		line->dirty = 1;
	}
	return latency;
}

void ucache_flush(ucache_t* cp){
	ucache_set_t set;
	ucache_line_t line;
	for(int i = 0; i<16; i++){
		set = cp->sets[i];
		for(int j = 0; j<4; j++){
			line = set.lines[j];
			if(line.dirty==1){
				cp->write_back ++;
				md_addr_t wb_addr = (line.tag<<8) | (i<<4);
				for(int k=0; k<4; k++){
					enum md_fault_type _fault;
					WRITE_WORD(line.data[k], wb_addr+(k*4),	_fault);
				}
			}
		}
	}
}






