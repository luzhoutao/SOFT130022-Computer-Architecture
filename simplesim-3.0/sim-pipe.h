#include "machine.h"

typedef struct{
  /* operation signal 
   * 00-add, 01-sub, 02-less than, 03-left shift, 04-logic and, 05-no operation, 06-not equal, 07-equal
   */
  int operation;
  // the source of data2: 0-from register; 1-from immediate number; 2-from shamt; 3-reserved imm(16)
  int data2Src;
  /*compute the jump address
   * 0-no, 1-from jump target, 2-from imm(offset)
   */
  int jaddr;
  /* if check overflow */
  int overflow;
  /* if check underflow */
  int underflow;
} exeSig_t;

typedef struct{
  // whether to write memory
  int writeMem;
  // whether to read memory
  int readMem;
  // whether there is a branch
  int branch;
} memSig_t;

typedef struct{
  // whether write back or not
  int alu2reg;
  int mem2reg;
  int exitCode2reg;
} wbSig_t;

/* define values related to operands, all possible combinations are included 
   (store the actual value)*/
typedef struct{
  int in1, in2, in3;
  int out1, out2;
}oprand_t;


/*define buffer between fetch and decode stage*/
struct ifid_buf {
  md_inst_t inst;	    /* instruction that has been fetched */
  md_addr_t PC;	        /* pc value of current instruction */
  md_addr_t NPC;		/* the next instruction to fetch */

  int latched; /*cannot be revised*/
};


/*define buffer between decode and execute stage*/
struct idex_buf {
  md_addr_t PC;			/* the current instruction*/
  md_addr_t NPC;
  md_inst_t inst;		/* instruction in ID stage */ 
  int opcode;			/* operation number */
  oprand_t oprand;		/* operand */
  int data1;
  int data2;
  int imm;
  int shamt;
  int jtarg;

  /* control signal */
  exeSig_t exe_signal;
  memSig_t mem_signal;
  wbSig_t wb_signal;

  /* access status */
  int status;
};

/*define buffer between execute and memory stage*/
struct exmem_buf{
  md_addr_t PC;			/* the current instruction*/
  md_addr_t NPC;
  md_inst_t inst;		/* instruction in EX stage */
  int ALUres;			/* the computed result from ALU */
  int regDest;			/* the possble register number to write */
  int data2;
  int cond;
  /* control signal */
  memSig_t mem_signal;
  wbSig_t wb_signal;

/* access status */
  int status;
};

/*define buffer between memory and writeback stage*/
struct memwb_buf{
  md_addr_t PC;
  md_addr_t NPC;
  md_inst_t inst;		/* instruction in MEM stage */
  int ALUres;			/* the computed result from ALU */
  int memData;
  int regDest;			/* the possible register number to write */
  /* control signal */
  wbSig_t wb_signal;

  /* access status */
  int status;
};
  

/*do fetch stage*/
void do_if();

/*do decode stage*/
void do_id();

/*do execute stage*/
void do_ex();

/*do memory stage*/
void do_mem();

int sim_clkn;

/*do write_back to register*/
void do_wb();

#define MD_FETCH_INSTI(INST, MEM, PC)					\
  { INST.a = MEM_READ_WORD(mem, (PC));					\
    INST.b = MEM_READ_WORD(mem, (PC) + sizeof(word_t)); }

#define SET_OPCODE(OP, INST) ((OP) = ((INST).a & 0xff)) 

#define RSI(INST)		((INST.b >> 24)& 0xff)		/* reg source #1 */
#define RTI(INST)		((INST.b >> 16) & 0xff)		/* reg source #2 */
#define RDI(INST)		((INST.b >> 8) & 0xff)		/* reg dest */
#define SHAMT(INST)		((INST.b) & 0xff)   		/* shift */

#define IMMI(INST)	((int)((/* signed */short)(INST.b & 0xffff)))	/*get immediate value*/
#define TARGI(INST)	(INST.b & 0x3ffffff)		/*jump target*/
