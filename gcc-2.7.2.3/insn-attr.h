/* Generated automatically by the program `genattr'
from the machine description file `md'.  */

#ifndef PROTO
#if defined (USE_PROTOTYPES) ? USE_PROTOTYPES : defined (__STDC__)
#define PROTO(ARGS) ARGS
#else
#define PROTO(ARGS) ()
#endif
#endif
#define HAVE_ATTR_alternative
#define get_attr_alternative(insn) which_alternative
#define HAVE_ATTR_type
enum attr_type {TYPE_UNKNOWN, TYPE_BRANCH, TYPE_JUMP, TYPE_CALL, TYPE_LOAD, TYPE_STORE, TYPE_MOVE, TYPE_XFER, TYPE_HILO, TYPE_ARITH, TYPE_DARITH, TYPE_IMUL, TYPE_IDIV, TYPE_ICMP, TYPE_FADD, TYPE_FMUL, TYPE_FDIV, TYPE_FABS, TYPE_FNEG, TYPE_FCMP, TYPE_FCVT, TYPE_FSQRT, TYPE_MULTI, TYPE_NOP};
extern enum attr_type get_attr_type ();

#define HAVE_ATTR_mode
enum attr_mode {MODE_UNKNOWN, MODE_NONE, MODE_QI, MODE_HI, MODE_SI, MODE_DI, MODE_SF, MODE_DF, MODE_FPSW};
extern enum attr_mode get_attr_mode ();

#define HAVE_ATTR_length
extern int get_attr_length ();
extern void init_lengths ();
extern void shorten_branches PROTO((rtx));
extern int insn_default_length PROTO((rtx));
extern int insn_variable_length_p PROTO((rtx));
extern int insn_current_length PROTO((rtx));

extern int *insn_addresses;
extern int insn_current_address;

#define HAVE_ATTR_dslot
enum attr_dslot {DSLOT_NO, DSLOT_YES};
extern enum attr_dslot get_attr_dslot ();

#define HAVE_ATTR_cpu
enum attr_cpu {CPU_DEFAULT, CPU_R3000, CPU_R6000, CPU_R4000};
extern enum attr_cpu get_attr_cpu ();

#define HAVE_ATTR_branch_likely
enum attr_branch_likely {BRANCH_LIKELY_NO, BRANCH_LIKELY_YES};
extern enum attr_branch_likely get_attr_branch_likely ();

#define HAVE_ATTR_abicalls
enum attr_abicalls {ABICALLS_NO, ABICALLS_YES};
extern enum attr_abicalls get_attr_abicalls ();

#define INSN_SCHEDULING

extern int result_ready_cost PROTO((rtx));
extern int function_units_used PROTO((rtx));

extern struct function_unit_desc
{
  char *name;
  int bitmask;
  int multiplicity;
  int simultaneity;
  int default_cost;
  int max_issue_delay;
  int (*ready_cost_function) ();
  int (*conflict_cost_function) ();
  int max_blockage;
  unsigned int (*blockage_range_function) ();
  int (*blockage_function) ();
} function_units[];

#define FUNCTION_UNITS_SIZE 6
#define MIN_MULTIPLICITY 1
#define MAX_MULTIPLICITY 1
#define MIN_SIMULTANEITY 0
#define MAX_SIMULTANEITY 1
#define MIN_READY_COST 1
#define MAX_READY_COST 112
#define MIN_ISSUE_DELAY 1
#define MAX_ISSUE_DELAY 1
#define MIN_BLOCKAGE 1
#define MAX_BLOCKAGE 112
#define BLOCKAGE_BITS 8
#define INSN_QUEUE_SIZE 128

#define ATTR_FLAG_forward	0x1
#define ATTR_FLAG_backward	0x2
#define ATTR_FLAG_likely	0x4
#define ATTR_FLAG_very_likely	0x8
#define ATTR_FLAG_unlikely	0x10
#define ATTR_FLAG_very_unlikely	0x20
