/* Generated automatically by the program `genoutput'
from the machine description file `md'.  */

#include "config.h"
#include "rtl.h"
#include "regs.h"
#include "hard-reg-set.h"
#include "real.h"
#include "insn-config.h"

#include "conditions.h"
#include "insn-flags.h"
#include "insn-attr.h"

#include "insn-codes.h"

#include "recog.h"

#include <stdio.h>
#include "output.h"

static char *
output_3 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  return (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) < 0)
    ? "subu\t%0,%z1,%n2"
    : "addu\t%0,%z1,%2";
}
}

static char *
output_5 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  return (REGNO (operands[0]) == REGNO (operands[1])
	  && REGNO (operands[0]) == REGNO (operands[2]))
    ? "srl\t%3,%L0,31\n\tsll\t%M0,%M0,1\n\tsll\t%L0,%L1,1\n\taddu\t%M0,%M0,%3"
    : "addu\t%L0,%L1,%L2\n\tsltu\t%3,%L0,%L2\n\taddu\t%M0,%M1,%M2\n\taddu\t%M0,%M0,%3";
}
}

static char *
output_8 (operands, insn)
     rtx *operands;
     rtx insn;
{
  static /*const*/ char *const strings_8[] = {
    "addu\t%L0,%L1,%2\n\tsltu\t%3,%L0,%2\n\taddu\t%M0,%M1,%3",
    "move\t%L0,%L1\n\tmove\t%M0,%M1",
    "subu\t%L0,%L1,%n2\n\tsltu\t%3,%L0,%2\n\tsubu\t%M0,%M1,1\n\taddu\t%M0,%M0,%3",
  };
  return strings_8[which_alternative];
}

static char *
output_14 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  return (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) < 0)
    ? "addu\t%0,%z1,%n2"
    : "subu\t%0,%z1,%2";
}
}

static char *
output_19 (operands, insn)
     rtx *operands;
     rtx insn;
{
  static /*const*/ char *const strings_19[] = {
    "sltu\t%3,%L1,%2\n\tsubu\t%L0,%L1,%2\n\tsubu\t%M0,%M1,%3",
    "move\t%L0,%L1\n\tmove\t%M0,%M1",
    "sltu\t%3,%L1,%2\n\tsubu\t%L0,%L1,%2\n\tsubu\t%M0,%M1,1\n\tsubu\t%M0,%M0,%3",
  };
  return strings_19[which_alternative];
}

static char *
output_24 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];

  xoperands[0] = operands[0];
  xoperands[1] = gen_rtx (REG, SImode, LO_REGNUM);

  output_asm_insn ("mult\t%1,%2", operands);
  output_asm_insn (ss_move_1word (xoperands, insn), xoperands);
  return "";
}
}

static char *
output_27 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];

  xoperands[0] = operands[0];
  xoperands[1] = gen_rtx (REG, DImode, MD_REG_FIRST);

  output_asm_insn ("mult\t%1,%2", operands);
  output_asm_insn (ss_move_2words (xoperands, insn), xoperands);
  return "";
}
}

static char *
output_28 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];

  xoperands[0] = operands[0];
  xoperands[1] = gen_rtx (REG, DImode, MD_REG_FIRST);

  output_asm_insn ("multu\t%1,%2", operands);
  output_asm_insn (ss_move_2words (xoperands, insn), xoperands);
  return "";
}
}

static char *
output_31 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (find_reg_note (insn, REG_UNUSED, operands[3]))
    return "div\t%0,%1,%2";

  if (find_reg_note (insn, REG_UNUSED, operands[0]))
    return "rem\t%3,%1,%2";

  return "div\t%0,%1,%2\n\tmfhi\t%3";
}
}

static char *
output_32 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (find_reg_note (insn, REG_UNUSED, operands[3]))
    return "divu\t%0,%1,%2";

  if (find_reg_note (insn, REG_UNUSED, operands[0]))
    return "remu\t%3,%1,%2";

  return "divu\t%0,%1,%2\n\tmfhi\t%3";
}
}

static char *
output_39 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  dslots_jump_total++;
  dslots_jump_filled++;
  operands[2] = const0_rtx;

  return (REGNO (operands[0]) == REGNO (operands[1]))
		? "bgez\t%1,1f%#\n\tsubu\t%0,%z2,%0\n1:"
		: "%(move\t%0,%1\n\tbgez\t%1,1f\n\tsubu\t%0,%z2,%0\n1:%)";
}
}

static char *
output_42 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  dslots_jump_total += 2;
  dslots_jump_filled += 2;
  operands[4] = const0_rtx;

  if (optimize && find_reg_note (insn, REG_DEAD, operands[1]))
    return "%(\
move\t%0,%z4\n\
\tbeq\t%1,%z4,2f\n\
1:\tand\t%2,%1,0x0001\n\
\taddu\t%0,%0,1\n\
\tsrl\t%1,%1,1\n\
\tbeq\t%2,%z4,1b\n\
2:%)";

  return "%(\
move\t%0,%z4\n\
\tmove\t%3,%1\n\
\tbeq\t%3,%z4,2f\n\
1:\tand\t%2,%3,0x0001\n\
\taddu\t%0,%0,1\n\
\tsrl\t%3,%3,1\n\
\tbeq\t%2,%z4,1b\n\
2:%)";
}
}

static char *
output_43 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[2] = const0_rtx;
  return "subu\t%0,%z2,%1";
}
}

static char *
output_45 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[3] = const0_rtx;
  return "subu\t%L0,%z3,%L1\n\tsubu\t%M0,%z3,%M1\n\tsltu\t%2,%z3,%L0\n\tsubu\t%M0,%M0,%2";
}
}

static char *
output_48 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[2] = const0_rtx;
  return "nor\t%0,%z2,%1";
}
}

static char *
output_49 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[2] = const0_rtx;
  return "nor\t%M0,%z2,%M1\n\tnor\t%L0,%z2,%L1";
}
}

static char *
output_54 (operands, insn)
     rtx *operands;
     rtx insn;
{
  static /*const*/ char *const strings_54[] = {
    "and\t%0,%1,%2",
    "andi\t%0,%1,%x2",
  };
  return strings_54[which_alternative];
}

static char *
output_57 (operands, insn)
     rtx *operands;
     rtx insn;
{
  static /*const*/ char *const strings_57[] = {
    "or\t%0,%1,%2",
    "ori\t%0,%1,%x2",
  };
  return strings_57[which_alternative];
}

static char *
output_60 (operands, insn)
     rtx *operands;
     rtx insn;
{
  static /*const*/ char *const strings_60[] = {
    "xor\t%0,%1,%2",
    "xori\t%0,%1,%x2",
  };
  return strings_60[which_alternative];
}

static char *
output_64 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (which_alternative == 0)
    return "andi\t%0,%1,0xffff";
  else
    return ss_move_1word (operands, insn, TRUE);
}
}

static char *
output_65 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (which_alternative == 0)
    return "andi\t%0,%1,0x00ff";
  else
    return ss_move_1word (operands, insn, TRUE);
}
}

static char *
output_66 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (which_alternative == 0)
    return "andi\t%0,%1,0x00ff";
  else
    return ss_move_1word (operands, insn, TRUE);
}
}

static char *
output_68 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, FALSE);
}

static char *
output_70 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, FALSE);
}

static char *
output_72 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, FALSE);
}

static char *
output_74 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];

  if (which_alternative == 1)
    return "trunc.w.d %0,%1,%2";

  output_asm_insn ("trunc.w.d %3,%1,%2", operands);

  xoperands[0] = operands[0];
  xoperands[1] = operands[3];
  output_asm_insn (ss_move_1word (xoperands, insn, FALSE), xoperands);
  return "";
}
}

static char *
output_75 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];

  if (which_alternative == 1)
    return "trunc.w.s %0,%1,%2";

  output_asm_insn ("trunc.w.s %3,%1,%2", operands);

  xoperands[0] = operands[0];
  xoperands[1] = operands[3];
  output_asm_insn (ss_move_1word (xoperands, insn, FALSE), xoperands);
  return "";
}
}

static char *
output_76 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  dslots_load_total++;
  if (GET_CODE (operands[1]) == MEM) {
    rtx addr = XEXP(operands[1], 0);
    return "l.s\t%0,%1%#\n\tcvt.d.w\t%0,%0";
  }

  return "mtc1\t%1,%0%#\n\tcvt.d.w\t%0,%0";
}
}

static char *
output_77 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  dslots_load_total++;
  if (GET_CODE (operands[1]) == MEM) {
    rtx addr = XEXP(operands[1], 0);
    return "l.s\t%0,%1%#\n\tcvt.s.w\t%0,%0";
  }

  return "mtc1\t%1,%0%#\n\tcvt.s.w\t%0,%0";
}
}

static char *
output_81 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  enum rtx_code code;
  char *ret;
  rtx offset;
  rtx addr;
  rtx mem_addr;

  if (which_alternative != 0)
    return ss_move_1word (operands, insn, FALSE);

  if (TARGET_STATS)
    ss_count_memory_refs (operands[1], 2);

  /* The stack/frame pointers are always aligned, so we can convert
     to the faster lw if we are referencing an aligned stack location.  */

  offset = const0_rtx;
  addr = XEXP (operands[1], 0);
  mem_addr = eliminate_constant_term (addr, &offset);

  if ((INTVAL (offset) & (UNITS_PER_WORD-1)) == 0
      && (mem_addr == stack_pointer_rtx || mem_addr == frame_pointer_rtx))
    ret = "lw\t%0,%1";

  else
    {
      ret = "ulw\t%0,%1";
      if (TARGET_GAS)
	{
	  enum rtx_code code = GET_CODE (addr);

	  if (code == CONST || code == SYMBOL_REF || code == LABEL_REF)
	    {
	      operands[2] = gen_rtx (REG, SImode, GP_REG_FIRST + 1);
	      ret = "%[la\t%2,%1\n\tulw\t%0,0(%2)%]";
	    }
	}
    }

  return ss_fill_delay_slot (ret, DELAY_LOAD, operands, insn);
}
}

static char *
output_82 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx offset = const0_rtx;
  rtx addr = XEXP (operands[0], 0);
  rtx mem_addr = eliminate_constant_term (addr, &offset);

  if (TARGET_STATS)
    ss_count_memory_refs (operands[0], 2);

  /* The stack/frame pointers are always aligned, so we can convert
     to the faster sw if we are referencing an aligned stack location.  */

  if ((INTVAL (offset) & (UNITS_PER_WORD-1)) == 0
      && (mem_addr == stack_pointer_rtx || mem_addr == frame_pointer_rtx))
    return "sw\t%1,%0";


  if (TARGET_GAS)
    {
      enum rtx_code code = GET_CODE (XEXP (operands[0], 0));

      if (code == CONST || code == SYMBOL_REF || code == LABEL_REF)
	{
	  operands[2] = gen_rtx (REG, SImode, GP_REG_FIRST + 1);
	  return "%[la\t%2,%0\n\tusw\t%z1,0(%2)%]";
	}
    }

  return "usw\t%z1,%0";
}
}

static char *
output_84 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_2words (operands, insn); 
}

static char *
output_88 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, TRUE);
}

static char *
output_89 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, TRUE);
}

static char *
output_91 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, TRUE);
}

static char *
output_92 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, TRUE);
}

static char *
output_94 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, TRUE);
}

static char *
output_95 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, TRUE);
}

static char *
output_97 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, FALSE);
}

static char *
output_98 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_1word (operands, insn, FALSE);
}

static char *
output_100 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_2words (operands, insn); 
}

static char *
output_101 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return ss_move_2words (operands, insn); 
}

static char *
output_104 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return output_block_move (insn, operands, 4, BLOCK_MOVE_NORMAL);
}

static char *
output_106 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return output_block_move (insn, operands, 4, BLOCK_MOVE_NOT_LAST);
}

static char *
output_107 (operands, insn)
     rtx *operands;
     rtx insn;
{
 return output_block_move (insn, operands, 4, BLOCK_MOVE_LAST);
}

static char *
output_108 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);

  return "sll\t%0,%1,%2";
}
}

static char *
output_110 (operands, insn)
     rtx *operands;
     rtx insn;
{
 
{
  operands[4] = const0_rtx;
  dslots_jump_total += 3;
  dslots_jump_filled += 2;

  return "FIXME\n\
sll\t%3,%2,26\n\
\tbgez\t%3,1f\n\
\tsll\t%M0,%L1,%2\n\
\t%(b\t3f\n\
\tmove\t%L0,%z4%)\n\
\n\
1:\n\
\t%(beq\t%3,%z4,2f\n\
\tsll\t%M0,%M1,%2%)\n\
\n\
\tsubu\t%3,%z4,%2\n\
\tsrl\t%3,%L1,%3\n\
\tor\t%M0,%M0,%3\n\
2:\n\
\tsll\t%L0,%L1,%2\n\
3:";
}
}

static char *
output_111 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  operands[4] = const0_rtx;
  return "sll\t%M0,%L1,%2\n\tmove\t%L0,%z4";
}
}

static char *
output_114 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  int amount = INTVAL (operands[2]);

  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = const0_rtx;
  operands[5] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));

  return "sll\t%M0,%M1,%2\n\tsrl\t%3,%L1,%5\n\tor\t%M0,%M0,%3\n\tsll\t%L0,%L1,%2";
}
}

static char *
output_117 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);

  return "sra\t%0,%1,%2";
}
}

static char *
output_119 (operands, insn)
     rtx *operands;
     rtx insn;
{
 
{
  operands[4] = const0_rtx;
  dslots_jump_total += 3;
  dslots_jump_filled += 2;

  return "FIXME\n\
sll\t%3,%2,26\n\
\tbgez\t%3,1f\n\
\tsra\t%L0,%M1,%2\n\
\t%(b\t3f\n\
\tsra\t%M0,%M1,31%)\n\
\n\
1:\n\
\t%(beq\t%3,%z4,2f\n\
\tsrl\t%L0,%L1,%2%)\n\
\n\
\tsubu\t%3,%z4,%2\n\
\tsll\t%3,%M1,%3\n\
\tor\t%L0,%L0,%3\n\
2:\n\
\tsra\t%M0,%M1,%2\n\
3:";
}
}

static char *
output_120 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  return "sra\t%L0,%M1,%2\n\tsra\t%M0,%M1,31";
}
}

static char *
output_123 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  int amount = INTVAL (operands[2]);

  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));

  return "srl\t%L0,%L1,%2\n\tsll\t%3,%M1,%4\n\tor\t%L0,%L0,%3\n\tsra\t%M0,%M1,%2";
}
}

static char *
output_126 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (GET_CODE (operands[2]) == CONST_INT)
    operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);

  return "srl\t%0,%1,%2";
}
}

static char *
output_128 (operands, insn)
     rtx *operands;
     rtx insn;
{
 
{
  operands[4] = const0_rtx;
  dslots_jump_total += 3;
  dslots_jump_filled += 2;

  return "FIXME\n\
sll\t%3,%2,26\n\
\tbgez\t%3,1f\n\
\tsrl\t%L0,%M1,%2\n\
\t%(b\t3f\n\
\tmove\t%M0,%z4%)\n\
\n\
1:\n\
\t%(beq\t%3,%z4,2f\n\
\tsrl\t%L0,%L1,%2%)\n\
\n\
\tsubu\t%3,%z4,%2\n\
\tsll\t%3,%M1,%3\n\
\tor\t%L0,%L0,%3\n\
2:\n\
\tsrl\t%M0,%M1,%2\n\
3:";
}
}

static char *
output_129 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  operands[4] = const0_rtx;
  return "srl\t%L0,%M1,%2\n\tmove\t%M0,%z4";
}
}

static char *
output_132 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  int amount = INTVAL (operands[2]);

  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));

  return "srl\t%L0,%L1,%2\n\tsll\t%3,%M1,%4\n\tor\t%L0,%L0,%3\n\tsrl\t%M0,%M1,%2";
}
}

static char *
output_139 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  ss_branch_likely = (final_sequence && INSN_ANNULLED_BRANCH_P (insn));
  return (operands[0] != pc_rtx) ? "%*bc1t%?\t%0" : "%*bc1f%?\t%1";
}
}

static char *
output_140 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  ss_branch_likely = (final_sequence && INSN_ANNULLED_BRANCH_P (insn));
  return (operands[0] != pc_rtx) ? "%*bc1f%?\t%0" : "%*bc1t%?\t%1";
}
}

static char *
output_141 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  ss_branch_likely = (final_sequence && INSN_ANNULLED_BRANCH_P (insn));
  return (operands[0] != pc_rtx) ? "%*bc1f%?\t%0" : "%*bc1t%?\t%1";
}
}

static char *
output_142 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  ss_branch_likely = (final_sequence && INSN_ANNULLED_BRANCH_P (insn));
  return (operands[0] != pc_rtx) ? "%*bc1t%?\t%0" : "%*bc1f%?\t%1";
}
}

static char *
output_143 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  ss_branch_likely = (final_sequence && INSN_ANNULLED_BRANCH_P (insn));
  if (operands[2] != pc_rtx)
    {				/* normal jump */
      switch (GET_CODE (operands[0]))
	{
	case EQ:  return "%*beq%?\t%z1,%.,%2";
	case NE:  return "%*bne%?\t%z1,%.,%2";
	case GTU: return "%*bne%?\t%z1,%.,%2";
	case LEU: return "%*beq%?\t%z1,%.,%2";
	case GEU: return "%*j\t%2";
	case LTU: return "%*bne%?\t%.,%.,%2";
	}

      return "%*b%C0z%?\t%z1,%2";
    }
  else
    {				/* inverted jump */
      switch (GET_CODE (operands[0]))
	{
	case EQ:  return "%*bne%?\t%z1,%.,%3";
	case NE:  return "%*beq%?\t%z1,%.,%3";
	case GTU: return "%*beq%?\t%z1,%.,%3";
	case LEU: return "%*bne%?\t%z1,%.,%3";
	case GEU: return "%*beq%?\t%.,%.,%3";
	case LTU: return "%*j\t%3";
	}

      return "%*b%N0z%?\t%z1,%3";
    }
}
}

static char *
output_144 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  ss_branch_likely = (final_sequence && INSN_ANNULLED_BRANCH_P (insn));
  return (operands[3] != pc_rtx)
	? "%*b%C0%?\t%z1,%z2,%3"
	: "%*b%N0%?\t%z1,%z2,%4";
}
}

static char *
output_157 (operands, insn)
     rtx *operands;
     rtx insn;
{
  static /*const*/ char *const strings_157[] = {
    "xor\t%0,%1,%2\n\tsltu\t%0,%0,1",
    "xori\t%0,%1,%2\n\tsltu\t%0,%0,1",
  };
  return strings_157[which_alternative];
}

static char *
output_161 (operands, insn)
     rtx *operands;
     rtx insn;
{
  static /*const*/ char *const strings_161[] = {
    "xor\t%0,%1,%2\n\tsltu\t%0,%.,%0",
    "xori\t%0,%1,%x2\n\tsltu\t%0,%.,%0",
  };
  return strings_161[which_alternative];
}

static char *
output_171 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[2] = gen_rtx (CONST_INT, VOIDmode, INTVAL (operands[2])+1);
  return "slt\t%0,%1,%2";
}
}

static char *
output_182 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  operands[2] = gen_rtx (CONST_INT, VOIDmode, INTVAL (operands[2])+1);
  return "sltu\t%0,%1,%2";
}
}

static char *
output_185 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.eq.d\t%0,%1", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_186 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.eq.d\t%0,%1", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_187 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.lt.d\t%0,%1", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_188 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.le.d\t%0,%1", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_189 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.lt.d\t%1,%0", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_190 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.le.d\t%1,%0", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_191 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.eq.s\t%0,%1", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_192 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.eq.s\t%0,%1", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_193 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.lt.s\t%0,%1", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_194 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.le.s\t%0,%1", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_195 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.lt.s\t%1,%0", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_196 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  rtx xoperands[10];
  xoperands[0] = gen_rtx (REG, CC_FPmode, FPSW_REGNUM);
  xoperands[1] = operands[0];
  xoperands[2] = operands[1];

  return ss_fill_delay_slot ("c.le.s\t%1,%0", DELAY_FCMP, xoperands, insn);
}
}

static char *
output_197 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (GET_CODE (operands[0]) == REG)
    return "%*j\t%0";
  else
    return "%*j\t%l0";
}
}

static char *
output_205 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  register rtx target = XEXP (operands[0], 0);

  if (GET_CODE (target) == SYMBOL_REF)
    return "%*jal\t%0";

  else if (GET_CODE (target) == CONST_INT)
    {
      operands[0] = target;
      return "%*%[li\t%@,%0\n\tjal\t%2,%@%]";
    }

  else
    {
      operands[0] = target;
      return "%*jal\t%2,%0";
    }
}
}

static char *
output_206 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  register rtx target = XEXP (operands[0], 0);

  if (GET_CODE (target) == SYMBOL_REF)
    return "jal\t%0";

  else if (GET_CODE (target) == CONST_INT)
    {
      operands[0] = target;
      return "li\t%^,%0\n\tjal\t%2,%^";
    }

  else
    {
      operands[0] = target;
      if (REGNO (target) != PIC_FUNCTION_ADDR_REGNUM)
	return "move\t%^,%0\n\tjal\t%2,%^";
      else
	return "jal\t%2,%0";
    }
}
}

static char *
output_208 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (REGNO (operands[0]) != PIC_FUNCTION_ADDR_REGNUM)
    return "move\t%^,%0\n\tjal\t%2,%^";
  else
    return "jal\t%2,%0";
}
}

static char *
output_210 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  register rtx target = XEXP (operands[1], 0);

  if (GET_CODE (target) == SYMBOL_REF)
    return "%*jal\t%1";

  else if (GET_CODE (target) == CONST_INT)
    {
      operands[1] = target;
      return "%*%[li\t%@,%1\n\tjal\t%3,%@%]";
    }

  else
    {
      operands[1] = target;
      return "%*jal\t%3,%1";
    }
}
}

static char *
output_211 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  register rtx target = XEXP (operands[1], 0);

  if (GET_CODE (target) == SYMBOL_REF)
    return "jal\t%1";

  else if (GET_CODE (target) == CONST_INT)
    {
      operands[1] = target;
      return "li\t%^,%1\n\tjal\t%3,%^";
    }

  else
    {
      operands[1] = target;
      if (REGNO (target) != PIC_FUNCTION_ADDR_REGNUM)
	return "move\t%^,%1\n\tjal\t%3,%^";
      else
	return "jal\t%3,%1";
    }
}
}

static char *
output_213 (operands, insn)
     rtx *operands;
     rtx insn;
{

{
  if (REGNO (operands[1]) != PIC_FUNCTION_ADDR_REGNUM)
    return "move\t%^,%1\n\tjal\t%3,%^";
  else
    return "jal\t%3,%1";
}
}

char * const insn_template[] =
  {
    "add.d\t%0,%1,%2",
    "add.s\t%0,%1,%2",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    "sub.d\t%0,%1,%2",
    "sub.s\t%0,%1,%2",
    0,
    0,
    0,
    "sltu\t%3,%L1,%L2\n\tsubu\t%L0,%L1,%L2\n\tsubu\t%M0,%M1,%M2\n\tsubu\t%M0,%M0,%3",
    0,
    0,
    0,
    0,
    0,
    "mul.d\t%0,%1,%2",
    "mul.s\t%0,%1,%2",
    0,
    0,
    "mult\t%0,%1",
    0,
    0,
    "div.d\t%0,%1,%2",
    "div.s\t%0,%1,%2",
    0,
    0,
    "div\t%0,%1,%2",
    "rem\t%0,%1,%2",
    "divu\t%0,%1,%2",
    "remu\t%0,%1,%2",
    "sqrt.d\t%0,%1",
    "sqrt.s\t%0,%1",
    0,
    "abs.d\t%0,%1",
    "abs.s\t%0,%1",
    0,
    0,
    0,
    0,
    "neg.d\t%0,%1",
    "neg.s\t%0,%1",
    0,
    0,
    0,
    "nor\t%0,%z1,%z2",
    "nor\t%M0,%M1,%M2\n\tnor\t%L0,%L1,%L2",
    0,
    0,
    "and\t%M0,%M1,%M2\n\tand\t%L0,%L1,%L2",
    0,
    0,
    "or\t%M0,%M1,%M2\n\tor\t%L0,%L1,%L2",
    0,
    0,
    "xor\t%M0,%M1,%M2\n\txor\t%L0,%L1,%L2",
    0,
    "cvt.s.d\t%0,%1",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    "cvt.d.s\t%0,%1",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    "sltu\t%0,%1,1",
    0,
    0,
    0,
    "sltu\t%0,%.,%1",
    0,
    0,
    0,
    "slt\t%0,%z2,%1",
    0,
    "slt\t%0,%1,%2\n\txori\t%0,%0,0x0001",
    0,
    0,
    "slt\t%0,%1,%2",
    0,
    0,
    "slt\t%0,%z2,%1\n\txori\t%0,%0,0x0001",
    0,
    0,
    "sltu\t%0,%z2,%1",
    0,
    "sltu\t%0,%1,%2\n\txori\t%0,%0,0x0001",
    0,
    0,
    "sltu\t%0,%1,%2",
    0,
    0,
    "sltu\t%0,%z2,%1\n\txori\t%0,%0,0x0001",
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    "%*j\t%0",
    "%*j\t%0",
    0,
    "%*j\t%0",
    0,
    "",
    0,
    0,
    0,
    "%*jal\t%2,%0",
    0,
    0,
    0,
    0,
    "%*jal\t%3,%1",
    0,
    0,
    "%(nop%)",
    0,
  };

char *(*const insn_outfun[])() =
  {
    0,
    0,
    0,
    output_3,
    0,
    output_5,
    0,
    0,
    output_8,
    0,
    0,
    0,
    0,
    0,
    output_14,
    0,
    0,
    0,
    0,
    output_19,
    0,
    0,
    0,
    0,
    output_24,
    0,
    0,
    output_27,
    output_28,
    0,
    0,
    output_31,
    output_32,
    0,
    0,
    0,
    0,
    0,
    0,
    output_39,
    0,
    0,
    output_42,
    output_43,
    0,
    output_45,
    0,
    0,
    output_48,
    output_49,
    0,
    0,
    0,
    0,
    output_54,
    0,
    0,
    output_57,
    0,
    0,
    output_60,
    0,
    0,
    0,
    output_64,
    output_65,
    output_66,
    0,
    output_68,
    0,
    output_70,
    0,
    output_72,
    0,
    output_74,
    output_75,
    output_76,
    output_77,
    0,
    0,
    0,
    output_81,
    output_82,
    0,
    output_84,
    0,
    0,
    0,
    output_88,
    output_89,
    0,
    output_91,
    output_92,
    0,
    output_94,
    output_95,
    0,
    output_97,
    output_98,
    0,
    output_100,
    output_101,
    0,
    0,
    output_104,
    0,
    output_106,
    output_107,
    output_108,
    0,
    output_110,
    output_111,
    0,
    0,
    output_114,
    0,
    0,
    output_117,
    0,
    output_119,
    output_120,
    0,
    0,
    output_123,
    0,
    0,
    output_126,
    0,
    output_128,
    output_129,
    0,
    0,
    output_132,
    0,
    0,
    0,
    0,
    0,
    0,
    output_139,
    output_140,
    output_141,
    output_142,
    output_143,
    output_144,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    output_157,
    0,
    0,
    0,
    output_161,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    output_171,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    output_182,
    0,
    0,
    output_185,
    output_186,
    output_187,
    output_188,
    output_189,
    output_190,
    output_191,
    output_192,
    output_193,
    output_194,
    output_195,
    output_196,
    output_197,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    output_205,
    output_206,
    0,
    output_208,
    0,
    output_210,
    output_211,
    0,
    output_213,
    0,
    0,
    0,
  };

rtx (*const insn_gen_function[]) () =
  {
    gen_adddf3,
    gen_addsf3,
    gen_addsi3,
    gen_addsi3_internal,
    gen_adddi3,
    gen_adddi3_internal_1,
    0,
    0,
    gen_adddi3_internal_2,
    0,
    0,
    gen_subdf3,
    gen_subsf3,
    gen_subsi3,
    gen_subsi3_internal,
    gen_subdi3,
    gen_subdi3_internal,
    0,
    0,
    gen_subdi3_internal_2,
    0,
    0,
    gen_muldf3,
    gen_mulsf3,
    gen_mulsi3,
    0,
    gen_mulsi3_internal,
    gen_mulsidi3,
    gen_umulsidi3,
    gen_divdf3,
    gen_divsf3,
    gen_divmodsi4,
    gen_udivmodsi4,
    gen_divsi3,
    gen_modsi3,
    gen_udivsi3,
    gen_umodsi3,
    gen_sqrtdf2,
    gen_sqrtsf2,
    gen_abssi2,
    gen_absdf2,
    gen_abssf2,
    gen_ffssi2,
    gen_negsi2,
    gen_negdi2,
    gen_negdi2_internal,
    gen_negdf2,
    gen_negsf2,
    gen_one_cmplsi2,
    gen_one_cmpldi2,
    0,
    gen_norsi3,
    gen_nordi3,
    0,
    gen_andsi3,
    gen_anddi3,
    0,
    gen_iorsi3,
    gen_iordi3,
    0,
    gen_xorsi3,
    gen_xordi3,
    0,
    gen_truncdfsf2,
    gen_zero_extendhisi2,
    gen_zero_extendqihi2,
    gen_zero_extendqisi2,
    gen_extendhisi2,
    gen_extendhisi2_internal,
    gen_extendqihi2,
    gen_extendqihi2_internal,
    gen_extendqisi2,
    gen_extendqisi2_insn,
    gen_extendsfdf2,
    gen_fix_truncdfsi2,
    gen_fix_truncsfsi2,
    gen_floatsidf2,
    gen_floatsisf2,
    gen_fixuns_truncdfsi2,
    gen_fixuns_truncsfsi2,
    gen_movsi_unaligned,
    gen_movsi_ulw,
    gen_movsi_usw,
    gen_movdi,
    gen_movdi_internal,
    0,
    0,
    gen_movsi,
    gen_movsi_internal1,
    gen_movsi_internal2,
    gen_movhi,
    gen_movhi_internal1,
    gen_movhi_internal2,
    gen_movqi,
    gen_movqi_internal1,
    gen_movqi_internal2,
    gen_movsf,
    gen_movsf_internal1,
    gen_movsf_internal2,
    gen_movdf,
    gen_movdf_internal1,
    gen_movdf_internal2,
    0,
    gen_movstrsi,
    gen_movstrsi_internal,
    0,
    gen_movstrsi_internal2,
    gen_movstrsi_internal3,
    gen_ashlsi3,
    gen_ashldi3,
    gen_ashldi3_internal,
    gen_ashldi3_internal2,
    0,
    0,
    gen_ashldi3_internal3,
    0,
    0,
    gen_ashrsi3,
    gen_ashrdi3,
    gen_ashrdi3_internal,
    gen_ashrdi3_internal2,
    0,
    0,
    gen_ashrdi3_internal3,
    0,
    0,
    gen_lshrsi3,
    gen_lshrdi3,
    gen_lshrdi3_internal,
    gen_lshrdi3_internal2,
    0,
    0,
    gen_lshrdi3_internal3,
    0,
    0,
    gen_cmpsi,
    gen_tstsi,
    gen_cmpdf,
    gen_cmpsf,
    gen_branch_fp_ne,
    gen_branch_fp_ne_rev,
    gen_branch_fp_eq,
    gen_branch_fp_eq_rev,
    gen_branch_zero,
    gen_branch_equality,
    gen_beq,
    gen_bne,
    gen_bgt,
    gen_bge,
    gen_blt,
    gen_ble,
    gen_bgtu,
    gen_bgeu,
    gen_bltu,
    gen_bleu,
    gen_seq,
    gen_seq_si_zero,
    gen_seq_si,
    0,
    gen_sne,
    gen_sne_si_zero,
    gen_sne_si,
    0,
    gen_sgt,
    gen_sgt_si,
    gen_sge,
    gen_sge_si,
    0,
    gen_slt,
    gen_slt_si,
    gen_sle,
    gen_sle_si_const,
    gen_sle_si_reg,
    0,
    gen_sgtu,
    gen_sgtu_si,
    gen_sgeu,
    gen_sgeu_si,
    0,
    gen_sltu,
    gen_sltu_si,
    gen_sleu,
    gen_sleu_si_const,
    gen_sleu_si_reg,
    0,
    gen_seq_df,
    gen_sne_df,
    gen_slt_df,
    gen_sle_df,
    gen_sgt_df,
    gen_sge_df,
    gen_seq_sf,
    gen_sne_sf,
    gen_slt_sf,
    gen_sle_sf,
    gen_sgt_sf,
    gen_sge_sf,
    gen_jump,
    gen_indirect_jump,
    gen_tablejump,
    gen_return,
    gen_return_internal,
    gen_prologue,
    gen_blockage,
    gen_call,
    gen_call_internal1,
    gen_call_internal2,
    gen_call_internal3,
    gen_call_internal4,
    gen_call_value,
    gen_call_value_internal1,
    gen_call_value_internal2,
    gen_call_value_internal3,
    gen_call_value_internal4,
    gen_untyped_call,
    gen_nop,
    gen_probe,
  };

char *insn_name[] =
  {
    "adddf3",
    "addsf3",
    "addsi3",
    "addsi3_internal",
    "adddi3",
    "adddi3_internal_1",
    "adddi3_internal_1+1",
    "adddi3_internal_2-1",
    "adddi3_internal_2",
    "adddi3_internal_2+1",
    "subdf3-1",
    "subdf3",
    "subsf3",
    "subsi3",
    "subsi3_internal",
    "subdi3",
    "subdi3_internal",
    "subdi3_internal+1",
    "subdi3_internal_2-1",
    "subdi3_internal_2",
    "subdi3_internal_2+1",
    "muldf3-1",
    "muldf3",
    "mulsf3",
    "mulsi3",
    "mulsi3+1",
    "mulsi3_internal",
    "mulsidi3",
    "umulsidi3",
    "divdf3",
    "divsf3",
    "divmodsi4",
    "udivmodsi4",
    "divsi3",
    "modsi3",
    "udivsi3",
    "umodsi3",
    "sqrtdf2",
    "sqrtsf2",
    "abssi2",
    "absdf2",
    "abssf2",
    "ffssi2",
    "negsi2",
    "negdi2",
    "negdi2_internal",
    "negdf2",
    "negsf2",
    "one_cmplsi2",
    "one_cmpldi2",
    "one_cmpldi2+1",
    "norsi3",
    "nordi3",
    "nordi3+1",
    "andsi3",
    "anddi3",
    "anddi3+1",
    "iorsi3",
    "iordi3",
    "iordi3+1",
    "xorsi3",
    "xordi3",
    "xordi3+1",
    "truncdfsf2",
    "zero_extendhisi2",
    "zero_extendqihi2",
    "zero_extendqisi2",
    "extendhisi2",
    "extendhisi2_internal",
    "extendqihi2",
    "extendqihi2_internal",
    "extendqisi2",
    "extendqisi2_insn",
    "extendsfdf2",
    "fix_truncdfsi2",
    "fix_truncsfsi2",
    "floatsidf2",
    "floatsisf2",
    "fixuns_truncdfsi2",
    "fixuns_truncsfsi2",
    "movsi_unaligned",
    "movsi_ulw",
    "movsi_usw",
    "movdi",
    "movdi_internal",
    "movdi_internal+1",
    "movsi-1",
    "movsi",
    "movsi_internal1",
    "movsi_internal2",
    "movhi",
    "movhi_internal1",
    "movhi_internal2",
    "movqi",
    "movqi_internal1",
    "movqi_internal2",
    "movsf",
    "movsf_internal1",
    "movsf_internal2",
    "movdf",
    "movdf_internal1",
    "movdf_internal2",
    "movdf_internal2+1",
    "movstrsi",
    "movstrsi_internal",
    "movstrsi_internal+1",
    "movstrsi_internal2",
    "movstrsi_internal3",
    "ashlsi3",
    "ashldi3",
    "ashldi3_internal",
    "ashldi3_internal2",
    "ashldi3_internal2+1",
    "ashldi3_internal3-1",
    "ashldi3_internal3",
    "ashldi3_internal3+1",
    "ashrsi3-1",
    "ashrsi3",
    "ashrdi3",
    "ashrdi3_internal",
    "ashrdi3_internal2",
    "ashrdi3_internal2+1",
    "ashrdi3_internal3-1",
    "ashrdi3_internal3",
    "ashrdi3_internal3+1",
    "lshrsi3-1",
    "lshrsi3",
    "lshrdi3",
    "lshrdi3_internal",
    "lshrdi3_internal2",
    "lshrdi3_internal2+1",
    "lshrdi3_internal3-1",
    "lshrdi3_internal3",
    "lshrdi3_internal3+1",
    "cmpsi-1",
    "cmpsi",
    "tstsi",
    "cmpdf",
    "cmpsf",
    "branch_fp_ne",
    "branch_fp_ne_rev",
    "branch_fp_eq",
    "branch_fp_eq_rev",
    "branch_zero",
    "branch_equality",
    "beq",
    "bne",
    "bgt",
    "bge",
    "blt",
    "ble",
    "bgtu",
    "bgeu",
    "bltu",
    "bleu",
    "seq",
    "seq_si_zero",
    "seq_si",
    "seq_si+1",
    "sne",
    "sne_si_zero",
    "sne_si",
    "sne_si+1",
    "sgt",
    "sgt_si",
    "sge",
    "sge_si",
    "sge_si+1",
    "slt",
    "slt_si",
    "sle",
    "sle_si_const",
    "sle_si_reg",
    "sle_si_reg+1",
    "sgtu",
    "sgtu_si",
    "sgeu",
    "sgeu_si",
    "sgeu_si+1",
    "sltu",
    "sltu_si",
    "sleu",
    "sleu_si_const",
    "sleu_si_reg",
    "sleu_si_reg+1",
    "seq_df",
    "sne_df",
    "slt_df",
    "sle_df",
    "sgt_df",
    "sge_df",
    "seq_sf",
    "sne_sf",
    "slt_sf",
    "sle_sf",
    "sgt_sf",
    "sge_sf",
    "jump",
    "indirect_jump",
    "tablejump",
    "return",
    "return_internal",
    "prologue",
    "blockage",
    "call",
    "call_internal1",
    "call_internal2",
    "call_internal3",
    "call_internal4",
    "call_value",
    "call_value_internal1",
    "call_value_internal2",
    "call_value_internal3",
    "call_value_internal4",
    "untyped_call",
    "nop",
    "probe",
  };
char **insn_name_ptr = insn_name;

const int insn_n_operands[] =
  {
    3,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    4,
    3,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    4,
    3,
    3,
    3,
    3,
    2,
    3,
    3,
    3,
    3,
    4,
    4,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    4,
    2,
    2,
    3,
    2,
    2,
    2,
    2,
    2,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    4,
    4,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    4,
    8,
    8,
    8,
    8,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    4,
    4,
    2,
    1,
    2,
    2,
    2,
    2,
    2,
    2,
    4,
    5,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    2,
    3,
    3,
    1,
    2,
    3,
    3,
    1,
    3,
    1,
    3,
    3,
    1,
    3,
    1,
    3,
    3,
    3,
    1,
    3,
    1,
    3,
    3,
    1,
    3,
    1,
    3,
    3,
    3,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    2,
    0,
    1,
    1,
    0,
    1,
    0,
    0,
    4,
    3,
    3,
    3,
    3,
    4,
    4,
    4,
    4,
    4,
    3,
    0,
    0,
  };

const int insn_n_dups[] =
  {
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    2,
    2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    2,
    0,
    0,
    0,
    2,
    0,
    0,
    0,
    2,
    0,
    2,
    0,
    0,
    2,
    0,
    2,
    0,
    0,
    0,
    2,
    0,
    2,
    0,
    0,
    2,
    0,
    2,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    2,
  };

char *const insn_operand_constraint[][MAX_RECOG_OPERANDS] =
  {
    { "=f", "f", "f", },
    { "=f", "f", "f", },
    { "=d", "dJ", "dI", },
    { "=d", "dJ", "dI", },
    { "", "", "", },
    { "=d,&d", "0,d", "d,d", "=d,d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=d,d,d", "%d,%d,%d", "P,J,N", "=d,d,d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=f", "f", "f", },
    { "=f", "f", "f", },
    { "=d", "dJ", "dI", },
    { "=d", "dJ", "dI", },
    { "=d", "d", "d", },
    { "=d", "d", "d", "=d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=d,d,d", "d,d,d", "P,J,N", "=d,d,d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=f", "f", "f", },
    { "=f", "f", "f", },
    { "=d", "d", "d", },
    { "", "", "", },
    { "d", "d", },
    { "=d", "d", "d", },
    { "=d", "d", "d", },
    { "=f", "f", "f", },
    { "=f", "f", "f", },
    { "=d", "d", "d", "=d", },
    { "=d", "d", "d", "=d", },
    { "=d", "d", "d", },
    { "=d", "d", "d", },
    { "=d", "d", "d", },
    { "=d", "d", "d", },
    { "=f", "f", },
    { "=f", "f", },
    { "=d", "d", },
    { "=f", "f", },
    { "=f", "f", },
    { "=&d", "d", "=&d", "=&d", },
    { "=d", "d", },
    { "=d", "d", },
    { "=d", "d", "=d", },
    { "=f", "f", },
    { "=f", "f", },
    { "=d", "d", },
    { "=d", "d", },
    { "", "", },
    { "=d", "dJ", "dJ", },
    { "=d", "d", "d", },
    { "", "", "", },
    { "=d,d", "%d,d", "d,K", },
    { "=d", "d", "d", },
    { "", "", "", },
    { "=d,d", "%d,d", "d,K", },
    { "=d", "d", "d", },
    { "", "", "", },
    { "=d,d", "%d,d", "d,K", },
    { "=d", "d", "d", },
    { "", "", "", },
    { "=f", "f", },
    { "=d,d,d", "d,R,m", },
    { "=d,d,d", "d,R,m", },
    { "=d,d,d", "d,R,m", },
    { "", "", },
    { "=d,d", "R,m", },
    { "", "", },
    { "=d,d", "R,m", },
    { "", "", },
    { "=d,d", "R,m", },
    { "=f", "f", },
    { "=d,*f,R,o", "f,*f,f,f", "=d,*d,&d,&d", "=f,*X,f,f", },
    { "=d,*f,R,o", "f,*f,f,f", "=d,*d,&d,&d", "=f,*X,f,f", },
    { "=f,f,f", "d,R,m", },
    { "=f,f,f", "d,R,m", },
    { "", "", },
    { "", "", },
    { "", "", },
    { "=&d,&d,d,d", "R,o,dIKL,M", },
    { "=R,o", "dJ,dJ", },
    { "", "", },
    { "=d,d,d,d,R,o,*d,*x", "d,iF,R,o,d,d,*x,*d", },
    { "", "", },
    { "", "", },
    { "", "", },
    { "=d,d,d,d,d,d,R,m,*d,*f*z,*f,*f,*f,*R,*m,*x,*d", "d,S,IKL,Mnis,R,m,dJ,dJ,*f*z,*d,*f,*R,*m,*f,*f,*d,*x", },
    { "=d,d,d,d,d,d,R,m,*d,*z,*d,*x", "d,S,IKL,Mnis,R,m,dJ,dJ,*z,*d,*x,*d", },
    { "", "", },
    { "=d,d,d,d,R,m,*d,*f,*f*z,*x,*d", "d,IK,R,m,dJ,dJ,*f*z,*d,*f,*d,*x", },
    { "=d,d,d,d,R,m,*d,*z,*x,*d", "d,IK,R,m,dJ,dJ,*z,*d,*d,*x", },
    { "", "", },
    { "=d,d,d,d,R,m,*d,*f*z,*f,*x,*d", "d,IK,R,m,dJ,dJ,*f*z,*d,*f,*d,*x", },
    { "=d,d,d,d,R,m,*d,*z,*x,*d", "d,IK,R,m,dJ,dJ,*z,*d,*d,*x", },
    { "", "", },
    { "=f,f,f,f,R,m,*f,*d,*d,*d,*d,*R,*m", "f,G,R,Em,fG,fG,*d,*f,*G*d,*R,*E*m,*d,*d", },
    { "=d,d,d,R,m", "      Gd,R,Em,d,d", },
    { "", "", },
    { "=f,f,f,R,o,f,*f,*d,*d,*d,*d,*R,*o", "f,R,o,fG,fG,E,*d,*f,*d*G,*R,*o*E,*d,*d", },
    { "=d,d,d,R,o", "dG,R,oE,d,d", },
    { "", "", },
    { "", "", "", "", },
    { "=To", "To", "I", "I", "=&d", "=&d", "=&d", "=&d", },
    { "", "", "", "", "", "", "", "", },
    { "=To", "To", "I", "I", "=&d", "=&d", "=&d", "=&d", },
    { "=To", "To", "I", "I", "=&d", "=&d", "=&d", "=&d", },
    { "=d", "d", "dI", },
    { "", "", "", },
    { "=&d", "d", "d", "=d", },
    { "=d", "d", "IJK", "=d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=d", "d", "IJK", "=d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=d", "d", "dI", },
    { "", "", "", },
    { "=&d", "d", "d", "=d", },
    { "=d", "d", "IJK", "=d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=d", "d", "IJK", "=d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=d", "d", "dI", },
    { "", "", "", },
    { "=&d", "d", "d", "=d", },
    { "=d", "d", "IJK", "=d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "=d", "d", "IJK", "=d", },
    { "", "", "", "", },
    { "", "", "", "", },
    { "", "", },
    { "", },
    { "", "", },
    { "", "", },
    { "", "", },
    { "", "", },
    { "", "", },
    { "", "", },
    { "", "d", "", "", },
    { "", "d", "d", "", "", },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { "=d", },
    { "=d", "d", },
    { "=d,d", "%d,d", "d,K", },
    { "", "", "", },
    { "=d", },
    { "=d", "d", },
    { "=d,d", "%d,d", "d,K", },
    { "", "", "", },
    { "=d", },
    { "=d", "d", "dJ", },
    { "=d", },
    { "=d", "d", "dI", },
    { "", "", "", },
    { "=d", },
    { "=d", "d", "dI", },
    { "=d", },
    { "=d", "d", "I", },
    { "=d", "d", "d", },
    { "", "", "", },
    { "=d", },
    { "=d", "d", "dJ", },
    { "=d", },
    { "=d", "d", "dI", },
    { "", "", "", },
    { "=d", },
    { "=d", "d", "dI", },
    { "=d", },
    { "=d", "d", "I", },
    { "=d", "d", "d", },
    { "", "", "", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { "f", "f", },
    { 0 },
    { "d", },
    { "d", },
    { 0 },
    { "d", },
    { 0 },
    { 0 },
    { "m", "i", "", "", },
    { "m", "i", "=d", },
    { "m", "i", "=d", },
    { "r", "i", "=d", },
    { "r", "i", "=d", },
    { "=df", "m", "i", "", },
    { "=df", "m", "i", "=d", },
    { "=df", "m", "i", "=d", },
    { "=df", "r", "i", "=d", },
    { "=df", "r", "i", "=d", },
    { "", "", "", },
    { 0 },
    { 0 },
  };

const enum machine_mode insn_operand_mode[][MAX_RECOG_OPERANDS] =
  {
    { DFmode, DFmode, DFmode, },
    { SFmode, SFmode, SFmode, },
    { SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, DImode, },
    { DImode, DImode, DImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { DImode, DImode, DImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { DFmode, DFmode, DFmode, },
    { SFmode, SFmode, SFmode, },
    { SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, DImode, },
    { DImode, DImode, DImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { DImode, DImode, DImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { DFmode, DFmode, DFmode, },
    { SFmode, SFmode, SFmode, },
    { SImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, SImode, },
    { DImode, SImode, SImode, },
    { DImode, SImode, SImode, },
    { DFmode, DFmode, DFmode, },
    { SFmode, SFmode, SFmode, },
    { SImode, SImode, SImode, SImode, },
    { SImode, SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { DFmode, DFmode, },
    { SFmode, SFmode, },
    { SImode, SImode, },
    { DFmode, DFmode, },
    { SFmode, SFmode, },
    { SImode, SImode, SImode, SImode, },
    { SImode, SImode, },
    { DImode, DImode, },
    { DImode, DImode, SImode, },
    { DFmode, DFmode, },
    { SFmode, SFmode, },
    { SImode, SImode, },
    { DImode, DImode, },
    { VOIDmode, VOIDmode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, DImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, DImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, DImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, DImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SFmode, DFmode, },
    { SImode, HImode, },
    { HImode, QImode, },
    { SImode, QImode, },
    { SImode, HImode, },
    { SImode, HImode, },
    { HImode, QImode, },
    { HImode, QImode, },
    { SImode, QImode, },
    { SImode, QImode, },
    { DFmode, SFmode, },
    { SImode, DFmode, SImode, DFmode, },
    { SImode, SFmode, SImode, SFmode, },
    { DFmode, SImode, },
    { SFmode, SImode, },
    { SImode, DFmode, },
    { SImode, SFmode, },
    { SImode, SImode, },
    { SImode, SImode, },
    { SImode, SImode, },
    { DImode, DImode, },
    { DImode, DImode, },
    { VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, },
    { SImode, SImode, },
    { SImode, SImode, },
    { SImode, SImode, },
    { HImode, HImode, },
    { HImode, HImode, },
    { HImode, HImode, },
    { QImode, QImode, },
    { QImode, QImode, },
    { QImode, QImode, },
    { SFmode, SFmode, },
    { SFmode, SFmode, },
    { SFmode, SFmode, },
    { DFmode, DFmode, },
    { DFmode, DFmode, },
    { DFmode, DFmode, },
    { VOIDmode, VOIDmode, },
    { BLKmode, BLKmode, SImode, SImode, },
    { BLKmode, BLKmode, SImode, SImode, SImode, SImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { BLKmode, BLKmode, SImode, SImode, SImode, SImode, SImode, SImode, },
    { BLKmode, BLKmode, SImode, SImode, SImode, SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, SImode, },
    { DImode, DImode, SImode, SImode, },
    { DImode, DImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { DImode, DImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, SImode, },
    { DImode, DImode, SImode, SImode, },
    { DImode, DImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { DImode, DImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { SImode, SImode, SImode, },
    { DImode, DImode, SImode, },
    { DImode, DImode, SImode, SImode, },
    { DImode, DImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { DImode, DImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { SImode, SImode, },
    { SImode, },
    { DFmode, DFmode, },
    { SFmode, SFmode, },
    { VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, },
    { SImode, SImode, VOIDmode, VOIDmode, },
    { SImode, SImode, SImode, VOIDmode, VOIDmode, },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode },
    { SImode, },
    { SImode, SImode, },
    { SImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, },
    { SImode, SImode, },
    { SImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, },
    { SImode, SImode, SImode, },
    { SImode, },
    { SImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, },
    { SImode, SImode, SImode, },
    { SImode, },
    { SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, },
    { SImode, SImode, SImode, },
    { SImode, },
    { SImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { SImode, },
    { SImode, SImode, SImode, },
    { SImode, },
    { SImode, SImode, SImode, },
    { SImode, SImode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { DFmode, DFmode, },
    { DFmode, DFmode, },
    { DFmode, DFmode, },
    { DFmode, DFmode, },
    { DFmode, DFmode, },
    { DFmode, DFmode, },
    { SFmode, SFmode, },
    { SFmode, SFmode, },
    { SFmode, SFmode, },
    { SFmode, SFmode, },
    { SFmode, SFmode, },
    { SFmode, SFmode, },
    { VOIDmode },
    { SImode, },
    { SImode, },
    { VOIDmode },
    { SImode, },
    { VOIDmode },
    { VOIDmode },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, SImode, },
    { VOIDmode, VOIDmode, SImode, },
    { SImode, VOIDmode, SImode, },
    { SImode, VOIDmode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode, VOIDmode, VOIDmode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, SImode, },
    { VOIDmode, SImode, VOIDmode, SImode, },
    { VOIDmode, SImode, VOIDmode, SImode, },
    { VOIDmode, VOIDmode, VOIDmode, },
    { VOIDmode },
    { VOIDmode },
  };

const char insn_operand_strict_low[][MAX_RECOG_OPERANDS] =
  {
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, },
    { 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0, },
    { 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, 0, },
    { 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0, 0, },
    { 0 },
    { 0, },
    { 0, },
    { 0 },
    { 0, },
    { 0 },
    { 0 },
    { 0, 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, },
    { 0 },
    { 0 },
  };

extern int register_operand ();
extern int reg_or_0_operand ();
extern int arith_operand ();
extern int small_int ();
extern int scratch_operand ();
extern int uns_arith_operand ();
extern int nonimmediate_operand ();
extern int memory_operand ();
extern int general_operand ();
extern int arith32_operand ();
extern int immediate_operand ();
extern int pc_or_label_operand ();
extern int cmp_op ();
extern int equality_op ();
extern int call_insn_operand ();

int (*const insn_operand_predicate[][MAX_RECOG_OPERANDS])() =
  {
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, reg_or_0_operand, arith_operand, },
    { register_operand, reg_or_0_operand, arith_operand, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, register_operand, register_operand, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, small_int, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, reg_or_0_operand, arith_operand, },
    { register_operand, reg_or_0_operand, arith_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, small_int, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { 0, 0, 0, },
    { register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, scratch_operand, scratch_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { 0, 0, },
    { register_operand, reg_or_0_operand, reg_or_0_operand, },
    { register_operand, register_operand, register_operand, },
    { 0, 0, 0, },
    { register_operand, uns_arith_operand, uns_arith_operand, },
    { register_operand, register_operand, register_operand, },
    { 0, 0, 0, },
    { register_operand, uns_arith_operand, uns_arith_operand, },
    { register_operand, register_operand, register_operand, },
    { 0, 0, 0, },
    { register_operand, uns_arith_operand, uns_arith_operand, },
    { register_operand, register_operand, register_operand, },
    { 0, 0, 0, },
    { register_operand, register_operand, },
    { register_operand, nonimmediate_operand, },
    { register_operand, nonimmediate_operand, },
    { register_operand, nonimmediate_operand, },
    { register_operand, nonimmediate_operand, },
    { register_operand, memory_operand, },
    { register_operand, nonimmediate_operand, },
    { register_operand, memory_operand, },
    { register_operand, nonimmediate_operand, },
    { register_operand, memory_operand, },
    { register_operand, register_operand, },
    { general_operand, register_operand, scratch_operand, scratch_operand, },
    { general_operand, register_operand, scratch_operand, scratch_operand, },
    { register_operand, nonimmediate_operand, },
    { register_operand, nonimmediate_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { general_operand, general_operand, },
    { register_operand, general_operand, },
    { memory_operand, reg_or_0_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { 0, 0, },
    { 0, 0, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { nonimmediate_operand, general_operand, },
    { 0, 0, },
    { general_operand, general_operand, arith32_operand, immediate_operand, },
    { memory_operand, memory_operand, small_int, small_int, scratch_operand, scratch_operand, scratch_operand, scratch_operand, },
    { 0, 0, 0, 0, 0, 0, 0, 0, },
    { memory_operand, memory_operand, small_int, small_int, scratch_operand, scratch_operand, scratch_operand, scratch_operand, },
    { memory_operand, memory_operand, small_int, small_int, scratch_operand, scratch_operand, scratch_operand, scratch_operand, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, register_operand, register_operand, register_operand, },
    { register_operand, register_operand, small_int, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, small_int, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, register_operand, register_operand, register_operand, },
    { register_operand, register_operand, small_int, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, small_int, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, register_operand, register_operand, register_operand, },
    { register_operand, register_operand, small_int, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, register_operand, small_int, register_operand, },
    { 0, 0, 0, 0, },
    { 0, 0, 0, 0, },
    { register_operand, arith_operand, },
    { register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { pc_or_label_operand, pc_or_label_operand, },
    { pc_or_label_operand, pc_or_label_operand, },
    { pc_or_label_operand, pc_or_label_operand, },
    { pc_or_label_operand, pc_or_label_operand, },
    { cmp_op, register_operand, pc_or_label_operand, pc_or_label_operand, },
    { equality_op, register_operand, register_operand, pc_or_label_operand, pc_or_label_operand, },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { 0 },
    { register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, uns_arith_operand, },
    { 0, 0, 0, },
    { register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, uns_arith_operand, },
    { 0, 0, 0, },
    { register_operand, },
    { register_operand, register_operand, reg_or_0_operand, },
    { register_operand, },
    { register_operand, register_operand, arith_operand, },
    { 0, 0, 0, },
    { register_operand, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, },
    { register_operand, register_operand, small_int, },
    { register_operand, register_operand, register_operand, },
    { 0, 0, 0, },
    { register_operand, },
    { register_operand, register_operand, reg_or_0_operand, },
    { register_operand, },
    { register_operand, register_operand, arith_operand, },
    { 0, 0, 0, },
    { register_operand, },
    { register_operand, register_operand, arith_operand, },
    { register_operand, },
    { register_operand, register_operand, small_int, },
    { register_operand, register_operand, register_operand, },
    { 0, 0, 0, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { register_operand, register_operand, },
    { 0 },
    { register_operand, },
    { register_operand, },
    { 0 },
    { register_operand, },
    { 0 },
    { 0 },
    { memory_operand, 0, 0, 0, },
    { call_insn_operand, 0, register_operand, },
    { call_insn_operand, 0, register_operand, },
    { register_operand, 0, register_operand, },
    { register_operand, 0, register_operand, },
    { register_operand, memory_operand, 0, 0, },
    { register_operand, call_insn_operand, 0, register_operand, },
    { register_operand, call_insn_operand, 0, register_operand, },
    { register_operand, register_operand, 0, register_operand, },
    { register_operand, register_operand, 0, register_operand, },
    { 0, 0, 0, },
    { 0 },
    { 0 },
  };

const int insn_n_alternatives[] =
  {
    1,
    1,
    1,
    1,
    0,
    2,
    0,
    0,
    3,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    3,
    0,
    0,
    1,
    1,
    1,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    0,
    2,
    1,
    0,
    2,
    1,
    0,
    2,
    1,
    0,
    1,
    3,
    3,
    3,
    0,
    2,
    0,
    2,
    0,
    2,
    1,
    4,
    4,
    3,
    3,
    0,
    0,
    0,
    4,
    2,
    0,
    8,
    0,
    0,
    0,
    17,
    12,
    0,
    11,
    10,
    0,
    11,
    10,
    0,
    13,
    5,
    0,
    13,
    5,
    0,
    0,
    1,
    0,
    1,
    1,
    1,
    0,
    1,
    1,
    0,
    0,
    1,
    0,
    0,
    1,
    0,
    1,
    1,
    0,
    0,
    1,
    0,
    0,
    1,
    0,
    1,
    1,
    0,
    0,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    1,
    1,
    2,
    0,
    1,
    1,
    2,
    0,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    1,
    1,
    0,
    1,
    0,
    0,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    1,
    0,
    0,
    0,
  };
