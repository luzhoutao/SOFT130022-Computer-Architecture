/* Generated automatically by the program `genrecog'
from the machine description file `md'.  */

#include "config.h"
#include "rtl.h"
#include "insn-config.h"
#include "recog.h"
#include "real.h"
#include "output.h"
#include "flags.h"

extern rtx gen_split_6 ();
extern rtx gen_split_7 ();
extern rtx gen_split_9 ();
extern rtx gen_split_10 ();
extern rtx gen_split_17 ();
extern rtx gen_split_18 ();
extern rtx gen_split_20 ();
extern rtx gen_split_21 ();
extern rtx gen_split_25 ();
extern rtx gen_split_50 ();
extern rtx gen_split_53 ();
extern rtx gen_split_56 ();
extern rtx gen_split_59 ();
extern rtx gen_split_62 ();
extern rtx gen_split_85 ();
extern rtx gen_split_86 ();
extern rtx gen_split_102 ();
extern rtx gen_split_105 ();
extern rtx gen_split_112 ();
extern rtx gen_split_113 ();
extern rtx gen_split_115 ();
extern rtx gen_split_116 ();
extern rtx gen_split_121 ();
extern rtx gen_split_122 ();
extern rtx gen_split_124 ();
extern rtx gen_split_125 ();
extern rtx gen_split_130 ();
extern rtx gen_split_131 ();
extern rtx gen_split_133 ();
extern rtx gen_split_134 ();
extern rtx gen_split_158 ();
extern rtx gen_split_162 ();
extern rtx gen_split_167 ();
extern rtx gen_split_173 ();
extern rtx gen_split_178 ();
extern rtx gen_split_184 ();

/* `recog' contains a decision tree
   that recognizes whether the rtx X0 is a valid instruction.

   recog returns -1 if the rtx is not valid.
   If the rtx is valid, recog returns a nonnegative number
   which is the insn code number for the pattern that matched.
   This is the same as the order in the machine description of
   the entry that matched.  This number can be used as an index into
   entry that matched.  This number can be used as an index into various
   insn_* tables, such as insn_templates, insn_outfun, and insn_n_operands
   (found in insn-output.c).

   The third argument to recog is an optional pointer to an int.
   If present, recog will accept a pattern if it matches except for
   missing CLOBBER expressions at the end.  In that case, the value
   pointed to by the optional pointer will be set to the number of
   CLOBBERs that need to be added (it should be initialized to zero by
   the caller).  If it is set nonzero, the caller should allocate a
   PARALLEL of the appropriate size, copy the initial entries, and call
   add_clobbers (found in insn-emit.c) to fill in the CLOBBERs.

   The function split_insns returns 0 if the rtl could not
   be split or the split rtl in a SEQUENCE if it can be.*/

rtx recog_operand[MAX_RECOG_OPERANDS];

rtx *recog_operand_loc[MAX_RECOG_OPERANDS];

rtx *recog_dup_loc[MAX_DUP_OPERANDS];

char recog_dup_num[MAX_DUP_OPERANDS];

#define operands recog_operand

int
recog_1 (x0, insn, pnum_clobbers)
     register rtx x0;
     rtx insn;
     int *pnum_clobbers;
{
  register rtx *ro = &recog_operand[0];
  register rtx x1, x2, x3, x4;
  int tem;

  x1 = XEXP (x0, 1);
  switch (GET_MODE (x1))
    {
    case SImode:
      switch (GET_CODE (x1))
	{
	case PLUS:
	  goto L13;
	case MINUS:
	  goto L80;
	case MULT:
	  goto L157;
	case DIV:
	  goto L291;
	case MOD:
	  goto L306;
	case UDIV:
	  goto L321;
	case UMOD:
	  goto L336;
	case ABS:
	  goto L349;
	case FFS:
	  goto L370;
	case NEG:
	  goto L374;
	case NOT:
	  goto L405;
	case AND:
	  goto L423;
	case IOR:
	  goto L438;
	case XOR:
	  goto L453;
	case ZERO_EXTEND:
	  goto L472;
	case SIGN_EXTEND:
	  goto L484;
	case ASHIFT:
	  goto L668;
	case ASHIFTRT:
	  goto L735;
	case LSHIFTRT:
	  goto L802;
	case EQ:
	  goto L917;
	case NE:
	  goto L932;
	case GT:
	  goto L947;
	case GE:
	  goto L952;
	case LT:
	  goto L962;
	case LE:
	  goto L967;
	case GTU:
	  goto L982;
	case GEU:
	  goto L987;
	case LTU:
	  goto L997;
	case LEU:
	  goto L1002;
	}
    }
  if (GET_CODE (x1) == UNSPEC && XINT (x1, 1) == 0 && XVECLEN (x1, 0) == 1 && 1)
    goto L534;
  goto ret0;

  L13:
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L14;
    }
  goto ret0;

  L14:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (GET_CODE (operands[2]) != CONST_INT || INTVAL (operands[2]) != -32768)
	return 3;
      }
  goto ret0;

  L80:
  x2 = XEXP (x1, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L81;
    }
  goto ret0;

  L81:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (GET_CODE (operands[2]) != CONST_INT || INTVAL (operands[2]) != -32768)
	return 14;
      }
  goto ret0;

  L157:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L158;
    }
  goto ret0;

  L158:
  x2 = XEXP (x1, 1);
  if (pnum_clobbers != 0 && register_operand (x2, SImode))
    {
      ro[2] = x2;
      *pnum_clobbers = 2;
      return 24;
    }
  goto ret0;

  L291:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L292;
    }
  goto ret0;

  L292:
  x2 = XEXP (x1, 1);
  if (pnum_clobbers != 0 && register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (!optimize)
	{
	  *pnum_clobbers = 2;
	  return 33;
	}
      }
  goto ret0;

  L306:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L307;
    }
  goto ret0;

  L307:
  x2 = XEXP (x1, 1);
  if (pnum_clobbers != 0 && register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (!optimize)
	{
	  *pnum_clobbers = 2;
	  return 34;
	}
      }
  goto ret0;

  L321:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L322;
    }
  goto ret0;

  L322:
  x2 = XEXP (x1, 1);
  if (pnum_clobbers != 0 && register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (!optimize)
	{
	  *pnum_clobbers = 2;
	  return 35;
	}
      }
  goto ret0;

  L336:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L337;
    }
  goto ret0;

  L337:
  x2 = XEXP (x1, 1);
  if (pnum_clobbers != 0 && register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (!optimize)
	{
	  *pnum_clobbers = 2;
	  return 36;
	}
      }
  goto ret0;

  L349:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      return 39;
    }
  goto ret0;

  L370:
  x2 = XEXP (x1, 0);
  if (pnum_clobbers != 0 && register_operand (x2, SImode))
    {
      ro[1] = x2;
      *pnum_clobbers = 2;
      return 42;
    }
  goto ret0;

  L374:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      return 43;
    }
  goto ret0;

  L405:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != SImode)
    goto ret0;
  if (GET_CODE (x2) == IOR && 1)
    goto L406;
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      return 48;
    }
  goto ret0;

  L406:
  x3 = XEXP (x2, 0);
  if (reg_or_0_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L407;
    }
  goto ret0;

  L407:
  x3 = XEXP (x2, 1);
  if (reg_or_0_operand (x3, SImode))
    {
      ro[2] = x3;
      return 51;
    }
  goto ret0;

  L423:
  x2 = XEXP (x1, 0);
  if (uns_arith_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L424;
    }
  goto ret0;

  L424:
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, SImode))
    {
      ro[2] = x2;
      return 54;
    }
  goto ret0;

  L438:
  x2 = XEXP (x1, 0);
  if (uns_arith_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L439;
    }
  goto ret0;

  L439:
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, SImode))
    {
      ro[2] = x2;
      return 57;
    }
  goto ret0;

  L453:
  x2 = XEXP (x1, 0);
  if (uns_arith_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L454;
    }
  goto ret0;

  L454:
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, SImode))
    {
      ro[2] = x2;
      return 60;
    }
  goto ret0;

  L472:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      if (nonimmediate_operand (x2, HImode))
	{
	  ro[1] = x2;
	  return 64;
	}
      break;
    case QImode:
      if (nonimmediate_operand (x2, QImode))
	{
	  ro[1] = x2;
	  return 66;
	}
    }
  goto ret0;

  L484:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case HImode:
      if (memory_operand (x2, HImode))
	{
	  ro[1] = x2;
	  return 68;
	}
      break;
    case QImode:
      if (memory_operand (x2, QImode))
	{
	  ro[1] = x2;
	  return 72;
	}
    }
  goto ret0;

  L668:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L669;
    }
  goto ret0;

  L669:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      return 108;
    }
  goto ret0;

  L735:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L736;
    }
  goto ret0;

  L736:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      return 117;
    }
  goto ret0;

  L802:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L803;
    }
  goto ret0;

  L803:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      return 126;
    }
  goto ret0;

  L917:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L918;
    }
  goto ret0;

  L918:
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT && XWINT (x2, 0) == 0 && 1)
    return 156;
  L923:
  if (uns_arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE)
	return 157;
      }
  goto ret0;

  L932:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L933;
    }
  goto ret0;

  L933:
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CONST_INT && XWINT (x2, 0) == 0 && 1)
    return 160;
  L938:
  if (uns_arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE)
	return 161;
      }
  goto ret0;

  L947:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L948;
    }
  goto ret0;

  L948:
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      ro[2] = x2;
      return 164;
    }
  goto ret0;

  L952:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L953;
    }
  goto ret0;

  L953:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE)
	return 166;
      }
  goto ret0;

  L962:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L963;
    }
  goto ret0;

  L963:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      return 169;
    }
  goto ret0;

  L967:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L973;
    }
  goto ret0;

  L973:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE)
	return 172;
      }
  if (GET_CODE (x2) == CONST_INT && small_int (x2, SImode))
    {
      ro[2] = x2;
      if (INTVAL (operands[2]) < 32767)
	return 171;
      }
  goto ret0;

  L982:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L983;
    }
  goto ret0;

  L983:
  x2 = XEXP (x1, 1);
  if (reg_or_0_operand (x2, SImode))
    {
      ro[2] = x2;
      return 175;
    }
  goto ret0;

  L987:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L988;
    }
  goto ret0;

  L988:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE)
	return 177;
      }
  goto ret0;

  L997:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L998;
    }
  goto ret0;

  L998:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      return 180;
    }
  goto ret0;

  L1002:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L1008;
    }
  goto ret0;

  L1008:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE)
	return 183;
      }
  if (GET_CODE (x2) == CONST_INT && small_int (x2, SImode))
    {
      ro[2] = x2;
      if (INTVAL (operands[2]) < 32767)
	return 182;
      }
  goto ret0;

  L534:
  x2 = XVECEXP (x1, 0, 0);
  if (general_operand (x2, SImode))
    {
      ro[1] = x2;
      return 81;
    }
  goto ret0;
 ret0: return -1;
}

int
recog_2 (x0, insn, pnum_clobbers)
     register rtx x0;
     rtx insn;
     int *pnum_clobbers;
{
  register rtx *ro = &recog_operand[0];
  register rtx x1, x2, x3, x4;
  int tem;

  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case DFmode:
      if (register_operand (x1, DFmode))
	{
	  ro[0] = x1;
	  goto L2;
	}
    L581:
      if (nonimmediate_operand (x1, DFmode))
	{
	  ro[0] = x1;
	  goto L582;
	}
      break;
    case SFmode:
      if (register_operand (x1, SFmode))
	{
	  ro[0] = x1;
	  goto L7;
	}
    L573:
      if (nonimmediate_operand (x1, SFmode))
	{
	  ro[0] = x1;
	  goto L574;
	}
      break;
    case SImode:
      if (register_operand (x1, SImode))
	{
	  ro[0] = x1;
	  goto L12;
	}
    L507:
      if (general_operand (x1, SImode))
	{
	  ro[0] = x1;
	  goto L508;
	}
    L536:
      if (memory_operand (x1, SImode))
	{
	  ro[0] = x1;
	  goto L537;
	}
    L549:
      if (nonimmediate_operand (x1, SImode))
	{
	  ro[0] = x1;
	  goto L550;
	}
    L178:
      if (GET_CODE (x1) == REG && XINT (x1, 0) == 65 && 1)
	goto L179;
      break;
    case DImode:
      if (register_operand (x1, DImode))
	{
	  ro[0] = x1;
	  goto L194;
	}
    L540:
      if (nonimmediate_operand (x1, DImode))
	{
	  ro[0] = x1;
	  goto L541;
	}
      break;
    case HImode:
      if (register_operand (x1, HImode))
	{
	  ro[0] = x1;
	  goto L475;
	}
    L557:
      if (nonimmediate_operand (x1, HImode))
	{
	  ro[0] = x1;
	  goto L558;
	}
      break;
    case QImode:
      if (nonimmediate_operand (x1, QImode))
	{
	  ro[0] = x1;
	  goto L566;
	}
      break;
    case CC_FPmode:
      switch (GET_CODE (x1))
	{
	case REG:
	  if (XINT (x1, 0) == 66 && 1)
	    goto L1016;
	}
      break;
    case CC_REV_FPmode:
      switch (GET_CODE (x1))
	{
	case REG:
	  if (XINT (x1, 0) == 66 && 1)
	    goto L1021;
	}
    }
  if (GET_CODE (x1) == PC && 1)
    goto L1080;
  goto ret0;

  L2:
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) != DFmode)
    {
      x1 = XEXP (x0, 0);
      goto L581;
    }
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L3;
    case MINUS:
      goto L70;
    case MULT:
      goto L137;
    case DIV:
      goto L219;
    case SQRT:
      goto L341;
    case ABS:
      goto L353;
    case NEG:
      goto L385;
    case FLOAT_EXTEND:
      goto L496;
    case FLOAT:
      goto L526;
    }
  x1 = XEXP (x0, 0);
  goto L581;

  L3:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      goto L4;
    }
  x1 = XEXP (x0, 0);
  goto L581;

  L4:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[2] = x2;
      if (TARGET_HARD_FLOAT)
	return 0;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L70:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      goto L71;
    }
  x1 = XEXP (x0, 0);
  goto L581;

  L71:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[2] = x2;
      if (TARGET_HARD_FLOAT)
	return 11;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L137:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      goto L138;
    }
  x1 = XEXP (x0, 0);
  goto L581;

  L138:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[2] = x2;
      if (TARGET_HARD_FLOAT)
	return 22;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L219:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      goto L220;
    }
  x1 = XEXP (x0, 0);
  goto L581;

  L220:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[2] = x2;
      if (TARGET_HARD_FLOAT)
	return 29;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L341:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT && HAVE_SQRT_P())
	return 37;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L353:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT)
	return 40;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L385:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT)
	return 46;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L496:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT)
	return 73;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L526:
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT)
	return 76;
      }
  x1 = XEXP (x0, 0);
  goto L581;

  L582:
  x1 = XEXP (x0, 1);
  if (general_operand (x1, DFmode))
    goto L586;
  goto ret0;

  L586:
  ro[1] = x1;
  if (TARGET_HARD_FLOAT
   && (register_operand (operands[0], DFmode)
       || register_operand (operands[1], DFmode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)
       || operands[1] == CONST0_RTX (DFmode)))
    return 100;
  L587:
  ro[1] = x1;
  if (TARGET_SOFT_FLOAT
   && (register_operand (operands[0], DFmode)
       || register_operand (operands[1], DFmode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)
       || operands[1] == CONST0_RTX (DFmode)))
    return 101;
  goto ret0;

  L7:
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) != SFmode)
    {
      x1 = XEXP (x0, 0);
      goto L573;
    }
  switch (GET_CODE (x1))
    {
    case PLUS:
      goto L8;
    case MINUS:
      goto L75;
    case MULT:
      goto L142;
    case DIV:
      goto L224;
    case SQRT:
      goto L345;
    case ABS:
      goto L357;
    case NEG:
      goto L389;
    case FLOAT_TRUNCATE:
      goto L468;
    case FLOAT:
      goto L530;
    }
  x1 = XEXP (x0, 0);
  goto L573;

  L8:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      goto L9;
    }
  x1 = XEXP (x0, 0);
  goto L573;

  L9:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[2] = x2;
      if (TARGET_HARD_FLOAT)
	return 1;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L75:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      goto L76;
    }
  x1 = XEXP (x0, 0);
  goto L573;

  L76:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[2] = x2;
      if (TARGET_HARD_FLOAT)
	return 12;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L142:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      goto L143;
    }
  x1 = XEXP (x0, 0);
  goto L573;

  L143:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[2] = x2;
      if (TARGET_HARD_FLOAT)
	return 23;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L224:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      goto L225;
    }
  x1 = XEXP (x0, 0);
  goto L573;

  L225:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[2] = x2;
      if (TARGET_HARD_FLOAT)
	return 30;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L345:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT && HAVE_SQRT_P())
	return 38;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L357:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT)
	return 41;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L389:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT)
	return 47;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L468:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT)
	return 63;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L530:
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, SImode))
    {
      ro[1] = x2;
      if (TARGET_HARD_FLOAT)
	return 77;
      }
  x1 = XEXP (x0, 0);
  goto L573;

  L574:
  x1 = XEXP (x0, 1);
  if (general_operand (x1, SFmode))
    goto L578;
  goto ret0;

  L578:
  ro[1] = x1;
  if (TARGET_HARD_FLOAT
   && (register_operand (operands[0], SFmode)
       || register_operand (operands[1], SFmode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)
       || operands[1] == CONST0_RTX (SFmode)))
    return 97;
  L579:
  ro[1] = x1;
  if (TARGET_SOFT_FLOAT
   && (register_operand (operands[0], SFmode)
       || register_operand (operands[1], SFmode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)
       || operands[1] == CONST0_RTX (SFmode)))
    return 98;
  goto ret0;
 L12:
  tem = recog_1 (x0, insn, pnum_clobbers);
  if (tem >= 0) return tem;
  x1 = XEXP (x0, 0);
  goto L507;

  L508:
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode && GET_CODE (x1) == FIX && 1)
    goto L509;
  x1 = XEXP (x0, 0);
  goto L536;

  L509:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      if (pnum_clobbers != 0 && register_operand (x2, DFmode))
	{
	  ro[1] = x2;
	  if (TARGET_HARD_FLOAT)
	    {
	      *pnum_clobbers = 2;
	      return 74;
	    }
	  }
      break;
    case SFmode:
      if (pnum_clobbers != 0 && register_operand (x2, SFmode))
	{
	  ro[1] = x2;
	  if (TARGET_HARD_FLOAT)
	    {
	      *pnum_clobbers = 2;
	      return 75;
	    }
	  }
    }
  x1 = XEXP (x0, 0);
  goto L536;

  L537:
  x1 = XEXP (x0, 1);
  if (GET_CODE (x1) == UNSPEC && XINT (x1, 1) == 0 && XVECLEN (x1, 0) == 1 && 1)
    goto L538;
  x1 = XEXP (x0, 0);
  goto L549;

  L538:
  x2 = XVECEXP (x1, 0, 0);
  if (reg_or_0_operand (x2, SImode))
    {
      ro[1] = x2;
      return 82;
    }
  x1 = XEXP (x0, 0);
  goto L549;

  L550:
  x1 = XEXP (x0, 1);
  if (general_operand (x1, SImode))
    goto L554;
  x1 = XEXP (x0, 0);
  goto L178;

  L554:
  ro[1] = x1;
  if (0 /* TARGET_DEBUG_H_MODE */
   && (register_operand (operands[0], SImode)
       || register_operand (operands[1], SImode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
    return 88;
  L555:
  ro[1] = x1;
  if (1 /* !TARGET_DEBUG_H_MODE */
   && (register_operand (operands[0], SImode)
       || register_operand (operands[1], SImode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
    return 89;
  x1 = XEXP (x0, 0);
  goto L178;

  L179:
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == SImode && GET_CODE (x1) == MULT && 1)
    goto L180;
  goto ret0;

  L180:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[0] = x2;
      goto L181;
    }
  goto ret0;

  L181:
  x2 = XEXP (x1, 1);
  if (pnum_clobbers != 0 && register_operand (x2, SImode))
    {
      ro[1] = x2;
      *pnum_clobbers = 1;
      return 26;
    }
  goto ret0;

  L194:
  x1 = XEXP (x0, 1);
  switch (GET_MODE (x1))
    {
    case DImode:
      switch (GET_CODE (x1))
	{
	case MULT:
	  goto L195;
	case NOT:
	  goto L411;
	case AND:
	  goto L428;
	case IOR:
	  goto L443;
	case XOR:
	  goto L458;
	}
      break;
    case SImode:
      if (GET_CODE (x1) == NOT && 1)
	goto L397;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L195:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != DImode)
    {
      x1 = XEXP (x0, 0);
      goto L540;
    }
  switch (GET_CODE (x2))
    {
    case SIGN_EXTEND:
      goto L196;
    case ZERO_EXTEND:
      goto L213;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L196:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L197;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L197:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode && GET_CODE (x2) == SIGN_EXTEND && 1)
    goto L198;
  x1 = XEXP (x0, 0);
  goto L540;

  L198:
  x3 = XEXP (x2, 0);
  if (pnum_clobbers != 0 && register_operand (x3, SImode))
    {
      ro[2] = x3;
      *pnum_clobbers = 1;
      return 27;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L213:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L214;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L214:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == DImode && GET_CODE (x2) == ZERO_EXTEND && 1)
    goto L215;
  x1 = XEXP (x0, 0);
  goto L540;

  L215:
  x3 = XEXP (x2, 0);
  if (pnum_clobbers != 0 && register_operand (x3, SImode))
    {
      ro[2] = x3;
      *pnum_clobbers = 1;
      return 28;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L411:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode && GET_CODE (x2) == IOR && 1)
    goto L412;
  x1 = XEXP (x0, 0);
  goto L540;

  L412:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L413;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L413:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      ro[2] = x3;
      return 52;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L428:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      ro[1] = x2;
      goto L429;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L429:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      ro[2] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 55;
      }
  x1 = XEXP (x0, 0);
  goto L540;

  L443:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      ro[1] = x2;
      goto L444;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L444:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      ro[2] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 58;
      }
  x1 = XEXP (x0, 0);
  goto L540;

  L458:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      ro[1] = x2;
      goto L459;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L459:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      ro[2] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 61;
      }
  x1 = XEXP (x0, 0);
  goto L540;

  L397:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      ro[1] = x2;
      return 49;
    }
  x1 = XEXP (x0, 0);
  goto L540;

  L541:
  x1 = XEXP (x0, 1);
  if (general_operand (x1, DImode))
    {
      ro[1] = x1;
      if (register_operand (operands[0], DImode)
   || register_operand (operands[1], DImode)
   || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)
   || operands[1] == CONST0_RTX (DImode))
	return 84;
      }
  goto ret0;

  L475:
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) != HImode)
    {
      x1 = XEXP (x0, 0);
      goto L557;
    }
  switch (GET_CODE (x1))
    {
    case ZERO_EXTEND:
      goto L476;
    case SIGN_EXTEND:
      goto L488;
    }
  x1 = XEXP (x0, 0);
  goto L557;

  L476:
  x2 = XEXP (x1, 0);
  if (nonimmediate_operand (x2, QImode))
    {
      ro[1] = x2;
      return 65;
    }
  x1 = XEXP (x0, 0);
  goto L557;

  L488:
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, QImode))
    {
      ro[1] = x2;
      return 70;
    }
  x1 = XEXP (x0, 0);
  goto L557;

  L558:
  x1 = XEXP (x0, 1);
  if (general_operand (x1, HImode))
    goto L562;
  goto ret0;

  L562:
  ro[1] = x1;
  if (0 /* TARGET_DEBUG_H_MODE */
   && (register_operand (operands[0], HImode)
       || register_operand (operands[1], HImode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
    return 91;
  L563:
  ro[1] = x1;
  if (1 /* !TARGET_DEBUG_H_MODE */
   && (register_operand (operands[0], HImode)
       || register_operand (operands[1], HImode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
    return 92;
  goto ret0;

  L566:
  x1 = XEXP (x0, 1);
  if (general_operand (x1, QImode))
    goto L570;
  goto ret0;

  L570:
  ro[1] = x1;
  if (0 /* TARGET_DEBUG_H_MODE */
   && (register_operand (operands[0], QImode)
       || register_operand (operands[1], QImode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
    return 94;
  L571:
  ro[1] = x1;
  if (1 /* !TARGET_DEBUG_H_MODE */
   && (register_operand (operands[0], QImode)
       || register_operand (operands[1], QImode)
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
    return 95;
  goto ret0;

  L1016:
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) != CC_FPmode)
    goto ret0;
  switch (GET_CODE (x1))
    {
    case EQ:
      goto L1017;
    case LT:
      goto L1027;
    case LE:
      goto L1032;
    case GT:
      goto L1037;
    case GE:
      goto L1042;
    }
  goto ret0;

  L1017:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      if (register_operand (x2, DFmode))
	{
	  ro[0] = x2;
	  goto L1018;
	}
      break;
    case SFmode:
      if (register_operand (x2, SFmode))
	{
	  ro[0] = x2;
	  goto L1048;
	}
    }
  goto ret0;

  L1018:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      return 185;
    }
  goto ret0;

  L1048:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      return 191;
    }
  goto ret0;

  L1027:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      if (register_operand (x2, DFmode))
	{
	  ro[0] = x2;
	  goto L1028;
	}
      break;
    case SFmode:
      if (register_operand (x2, SFmode))
	{
	  ro[0] = x2;
	  goto L1058;
	}
    }
  goto ret0;

  L1028:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      return 187;
    }
  goto ret0;

  L1058:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      return 193;
    }
  goto ret0;

  L1032:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      if (register_operand (x2, DFmode))
	{
	  ro[0] = x2;
	  goto L1033;
	}
      break;
    case SFmode:
      if (register_operand (x2, SFmode))
	{
	  ro[0] = x2;
	  goto L1063;
	}
    }
  goto ret0;

  L1033:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      return 188;
    }
  goto ret0;

  L1063:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      return 194;
    }
  goto ret0;

  L1037:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      if (register_operand (x2, DFmode))
	{
	  ro[0] = x2;
	  goto L1038;
	}
      break;
    case SFmode:
      if (register_operand (x2, SFmode))
	{
	  ro[0] = x2;
	  goto L1068;
	}
    }
  goto ret0;

  L1038:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      return 189;
    }
  goto ret0;

  L1068:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      return 195;
    }
  goto ret0;

  L1042:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      if (register_operand (x2, DFmode))
	{
	  ro[0] = x2;
	  goto L1043;
	}
      break;
    case SFmode:
      if (register_operand (x2, SFmode))
	{
	  ro[0] = x2;
	  goto L1073;
	}
    }
  goto ret0;

  L1043:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      return 190;
    }
  goto ret0;

  L1073:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      return 196;
    }
  goto ret0;

  L1021:
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) == CC_REV_FPmode && GET_CODE (x1) == NE && 1)
    goto L1022;
  goto ret0;

  L1022:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DFmode:
      if (register_operand (x2, DFmode))
	{
	  ro[0] = x2;
	  goto L1023;
	}
      break;
    case SFmode:
      if (register_operand (x2, SFmode))
	{
	  ro[0] = x2;
	  goto L1053;
	}
    }
  goto ret0;

  L1023:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DFmode))
    {
      ro[1] = x2;
      return 186;
    }
  goto ret0;

  L1053:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SFmode))
    {
      ro[1] = x2;
      return 192;
    }
  goto ret0;

  L1080:
  x1 = XEXP (x0, 1);
  if (register_operand (x1, SImode))
    {
      ro[0] = x1;
      return 198;
    }
  switch (GET_CODE (x1))
    {
    case IF_THEN_ELSE:
      goto L869;
    case LABEL_REF:
      goto L1077;
    }
  goto ret0;

  L869:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case CC_FPmode:
      switch (GET_CODE (x2))
	{
	case NE:
	  goto L870;
	case EQ:
	  goto L886;
	}
      break;
    case CC_REV_FPmode:
      switch (GET_CODE (x2))
	{
	case NE:
	  goto L878;
	case EQ:
	  goto L894;
	}
      break;
    case SImode:
      if (cmp_op (x2, SImode))
	{
	  ro[0] = x2;
	  goto L902;
	}
    L909:
      if (equality_op (x2, SImode))
	{
	  ro[0] = x2;
	  goto L910;
	}
    }
  goto ret0;

  L870:
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CC_FPmode && GET_CODE (x3) == REG && XINT (x3, 0) == 66 && 1)
    goto L871;
  goto ret0;

  L871:
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT && XWINT (x3, 0) == 0 && 1)
    goto L872;
  goto ret0;

  L872:
  x2 = XEXP (x1, 1);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[0] = x2;
      goto L873;
    }
  goto ret0;

  L873:
  x2 = XEXP (x1, 2);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[1] = x2;
      return 139;
    }
  goto ret0;

  L886:
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CC_FPmode && GET_CODE (x3) == REG && XINT (x3, 0) == 66 && 1)
    goto L887;
  goto ret0;

  L887:
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT && XWINT (x3, 0) == 0 && 1)
    goto L888;
  goto ret0;

  L888:
  x2 = XEXP (x1, 1);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[0] = x2;
      goto L889;
    }
  goto ret0;

  L889:
  x2 = XEXP (x1, 2);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[1] = x2;
      return 141;
    }
  goto ret0;

  L878:
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CC_REV_FPmode && GET_CODE (x3) == REG && XINT (x3, 0) == 66 && 1)
    goto L879;
  goto ret0;

  L879:
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT && XWINT (x3, 0) == 0 && 1)
    goto L880;
  goto ret0;

  L880:
  x2 = XEXP (x1, 1);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[0] = x2;
      goto L881;
    }
  goto ret0;

  L881:
  x2 = XEXP (x1, 2);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[1] = x2;
      return 140;
    }
  goto ret0;

  L894:
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) == CC_REV_FPmode && GET_CODE (x3) == REG && XINT (x3, 0) == 66 && 1)
    goto L895;
  goto ret0;

  L895:
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT && XWINT (x3, 0) == 0 && 1)
    goto L896;
  goto ret0;

  L896:
  x2 = XEXP (x1, 1);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[0] = x2;
      goto L897;
    }
  goto ret0;

  L897:
  x2 = XEXP (x1, 2);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[1] = x2;
      return 142;
    }
  goto ret0;

  L902:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L903;
    }
  goto L909;

  L903:
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT && XWINT (x3, 0) == 0 && 1)
    goto L904;
  goto L909;

  L904:
  x2 = XEXP (x1, 1);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[2] = x2;
      goto L905;
    }
  x2 = XEXP (x1, 0);
  goto L909;

  L905:
  x2 = XEXP (x1, 2);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[3] = x2;
      return 143;
    }
  x2 = XEXP (x1, 0);
  goto L909;

  L910:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L911;
    }
  goto ret0;

  L911:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L912;
    }
  goto ret0;

  L912:
  x2 = XEXP (x1, 1);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[3] = x2;
      goto L913;
    }
  goto ret0;

  L913:
  x2 = XEXP (x1, 2);
  if (pc_or_label_operand (x2, VOIDmode))
    {
      ro[4] = x2;
      return 144;
    }
  goto ret0;

  L1077:
  x2 = XEXP (x1, 0);
  ro[0] = x2;
  return 197;
 ret0: return -1;
}

int
recog_3 (x0, insn, pnum_clobbers)
     register rtx x0;
     rtx insn;
     int *pnum_clobbers;
{
  register rtx *ro = &recog_operand[0];
  register rtx x1, x2, x3, x4;
  int tem;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) != DImode)
    goto ret0;
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L19;
    case MINUS:
      goto L86;
    case MULT:
      goto L186;
    case NEG:
      goto L379;
    case ASHIFT:
      goto L674;
    case ASHIFTRT:
      goto L741;
    case LSHIFTRT:
      goto L808;
    }
  goto ret0;

  L19:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L20;
    }
  goto ret0;

  L20:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      ro[2] = x3;
      goto L21;
    }
  if (GET_CODE (x3) == CONST_INT && small_int (x3, DImode))
    {
      ro[2] = x3;
      goto L47;
    }
  goto ret0;

  L21:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L22;
  goto ret0;

  L22:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 5;
      }
  goto ret0;

  L47:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L48;
  goto ret0;

  L48:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      if (!TARGET_DEBUG_G_MODE && INTVAL (operands[2]) != -32768)
	return 8;
      }
  goto ret0;

  L86:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L87;
    }
  goto ret0;

  L87:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      ro[2] = x3;
      goto L88;
    }
  if (GET_CODE (x3) == CONST_INT && small_int (x3, DImode))
    {
      ro[2] = x3;
      goto L114;
    }
  goto ret0;

  L88:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L89;
  goto ret0;

  L89:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 16;
      }
  goto ret0;

  L114:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L115;
  goto ret0;

  L115:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      if (!TARGET_DEBUG_G_MODE && INTVAL (operands[2]) != -32768)
	return 19;
      }
  goto ret0;

  L186:
  x3 = XEXP (x2, 0);
  if (GET_MODE (x3) != DImode)
    goto ret0;
  switch (GET_CODE (x3))
    {
    case SIGN_EXTEND:
      goto L187;
    case ZERO_EXTEND:
      goto L204;
    }
  goto ret0;

  L187:
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      ro[1] = x4;
      goto L188;
    }
  goto ret0;

  L188:
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode && GET_CODE (x3) == SIGN_EXTEND && 1)
    goto L189;
  goto ret0;

  L189:
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      ro[2] = x4;
      goto L190;
    }
  goto ret0;

  L190:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L191;
  goto ret0;

  L191:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    return 27;
  goto ret0;

  L204:
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      ro[1] = x4;
      goto L205;
    }
  goto ret0;

  L205:
  x3 = XEXP (x2, 1);
  if (GET_MODE (x3) == DImode && GET_CODE (x3) == ZERO_EXTEND && 1)
    goto L206;
  goto ret0;

  L206:
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      ro[2] = x4;
      goto L207;
    }
  goto ret0;

  L207:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L208;
  goto ret0;

  L208:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == DImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    return 28;
  goto ret0;

  L379:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L380;
    }
  goto ret0;

  L380:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L381;
  goto ret0;

  L381:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 45;
      }
  goto ret0;

  L674:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L675;
    }
  goto ret0;

  L675:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L676;
    }
  if (GET_CODE (x3) == CONST_INT && small_int (x3, SImode))
    {
      ro[2] = x3;
      goto L684;
    }
  goto ret0;

  L676:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L677;
  goto ret0;

  L677:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 110;
      }
  goto ret0;

  L684:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L685;
  goto ret0;

  L685:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L712;
  goto ret0;

  L712:
  ro[3] = x2;
  if (!TARGET_DEBUG_G_MODE && (INTVAL (operands[2]) & 32) != 0)
    return 111;
  L713:
  ro[3] = x2;
  if (!TARGET_DEBUG_G_MODE
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return 114;
  goto ret0;

  L741:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L742;
    }
  goto ret0;

  L742:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L743;
    }
  if (GET_CODE (x3) == CONST_INT && small_int (x3, SImode))
    {
      ro[2] = x3;
      goto L751;
    }
  goto ret0;

  L743:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L744;
  goto ret0;

  L744:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 119;
      }
  goto ret0;

  L751:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L752;
  goto ret0;

  L752:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L779;
  goto ret0;

  L779:
  ro[3] = x2;
  if (!TARGET_DEBUG_G_MODE && (INTVAL (operands[2]) & 32) != 0)
    return 120;
  L780:
  ro[3] = x2;
  if (!TARGET_DEBUG_G_MODE
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return 123;
  goto ret0;

  L808:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L809;
    }
  goto ret0;

  L809:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L810;
    }
  if (GET_CODE (x3) == CONST_INT && small_int (x3, SImode))
    {
      ro[2] = x3;
      goto L818;
    }
  goto ret0;

  L810:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L811;
  goto ret0;

  L811:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      if (!TARGET_DEBUG_G_MODE)
	return 128;
      }
  goto ret0;

  L818:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L819;
  goto ret0;

  L819:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L846;
  goto ret0;

  L846:
  ro[3] = x2;
  if (!TARGET_DEBUG_G_MODE && (INTVAL (operands[2]) & 32) != 0)
    return 129;
  L847:
  ro[3] = x2;
  if (!TARGET_DEBUG_G_MODE
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return 132;
  goto ret0;
 ret0: return -1;
}

int
recog_4 (x0, insn, pnum_clobbers)
     register rtx x0;
     rtx insn;
     int *pnum_clobbers;
{
  register rtx *ro = &recog_operand[0];
  register rtx x1, x2, x3, x4;
  int tem;

  x1 = XVECEXP (x0, 0, 0);
  switch (GET_CODE (x1))
    {
    case SET:
      goto L17;
    case RETURN:
      goto L1090;
    case CALL:
      goto L1096;
    }
  goto ret0;

  L17:
  x2 = XEXP (x1, 0);
  switch (GET_MODE (x2))
    {
    case DImode:
      if (register_operand (x2, DImode))
	{
	  ro[0] = x2;
	  goto L18;
	}
      break;
    case SImode:
      if (GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
	goto L172;
    L243:
      if (register_operand (x2, SImode))
	{
	  ro[0] = x2;
	  goto L244;
	}
    }
  if (GET_CODE (x2) == PC && 1)
    goto L1084;
  L1126:
  if (register_operand (x2, VOIDmode))
    {
      ro[0] = x2;
      goto L1127;
    }
  goto ret0;
 L18:
  tem = recog_3 (x0, insn, pnum_clobbers);
  if (tem >= 0) return tem;
  x2 = XEXP (x1, 0);
  goto L1126;

  L172:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == MULT && 1)
    goto L173;
  x2 = XEXP (x1, 0);
  goto L243;

  L173:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[0] = x3;
      goto L174;
    }
  x2 = XEXP (x1, 0);
  goto L243;

  L174:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L175;
    }
  x2 = XEXP (x1, 0);
  goto L243;

  L175:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L176;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L243;

  L176:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    return 26;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L243;

  L244:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) != SImode)
    {
      x2 = XEXP (x1, 0);
      goto L1126;
    }
  switch (GET_CODE (x2))
    {
    case DIV:
      goto L245;
    case UDIV:
      goto L271;
    }
  x2 = XEXP (x1, 0);
  goto L1126;

  L245:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L246;
    }
  x2 = XEXP (x1, 0);
  goto L1126;

  L246:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L247;
    }
  x2 = XEXP (x1, 0);
  goto L1126;

  L247:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET && 1)
    goto L248;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L248:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      goto L249;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L249:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == MOD && 1)
    goto L250;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L250:
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, ro[1]) && 1)
    goto L251;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L251:
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, ro[2]) && pnum_clobbers != 0 && 1)
    if (optimize)
      {
	*pnum_clobbers = 2;
	return 31;
      }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L271:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L272;
    }
  x2 = XEXP (x1, 0);
  goto L1126;

  L272:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L273;
    }
  x2 = XEXP (x1, 0);
  goto L1126;

  L273:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET && 1)
    goto L274;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L274:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      goto L275;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L275:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == UMOD && 1)
    goto L276;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L276:
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, ro[1]) && 1)
    goto L277;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L277:
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, ro[2]) && pnum_clobbers != 0 && 1)
    if (optimize)
      {
	*pnum_clobbers = 2;
	return 32;
      }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1126;

  L1084:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      ro[0] = x2;
      goto L1085;
    }
  goto ret0;

  L1085:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE && 1)
    goto L1086;
  goto ret0;

  L1086:
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == LABEL_REF && 1)
    goto L1087;
  goto ret0;

  L1087:
  x3 = XEXP (x2, 0);
  ro[1] = x3;
  return 199;

  L1127:
  x2 = XEXP (x1, 1);
  if (GET_CODE (x2) == CALL && 1)
    goto L1128;
  goto ret0;

  L1128:
  x3 = XEXP (x2, 0);
  if (GET_CODE (x3) != MEM)
    goto ret0;
  if (call_insn_operand (x3, VOIDmode))
    {
      ro[1] = x3;
      goto L1129;
    }
  L1146:
  if (GET_MODE (x3) == SImode && 1)
    goto L1147;
  goto ret0;

  L1129:
  x3 = XEXP (x2, 1);
  ro[2] = x3;
  goto L1130;

  L1130:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L1131;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L1146;

  L1131:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L1140;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L1146;

  L1140:
  ro[3] = x2;
  if (!TARGET_ABICALLS && !TARGET_LONG_CALLS)
    return 210;
  L1141:
  ro[3] = x2;
  if (TARGET_ABICALLS && !TARGET_LONG_CALLS)
    return 211;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  x3 = XEXP (x2, 0);
  goto L1146;

  L1147:
  x4 = XEXP (x3, 0);
  if (register_operand (x4, SImode))
    {
      ro[1] = x4;
      goto L1148;
    }
  goto ret0;

  L1148:
  x3 = XEXP (x2, 1);
  ro[2] = x3;
  goto L1149;

  L1149:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L1150;
  goto ret0;

  L1150:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L1160;
  goto ret0;

  L1160:
  ro[3] = x2;
  if (!TARGET_ABICALLS && TARGET_LONG_CALLS)
    return 212;
  L1161:
  ro[3] = x2;
  if (TARGET_ABICALLS && TARGET_LONG_CALLS)
    return 213;
  goto ret0;

  L1090:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == USE && 1)
    goto L1091;
  goto ret0;

  L1091:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[0] = x2;
      return 201;
    }
  goto ret0;

  L1096:
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) != MEM)
    goto ret0;
  if (call_insn_operand (x2, VOIDmode))
    {
      ro[0] = x2;
      goto L1097;
    }
  L1110:
  if (GET_MODE (x2) == SImode && 1)
    goto L1111;
  goto ret0;

  L1097:
  x2 = XEXP (x1, 1);
  ro[1] = x2;
  goto L1098;

  L1098:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L1099;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1110;

  L1099:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L1106;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1110;

  L1106:
  ro[2] = x2;
  if (!TARGET_ABICALLS && !TARGET_LONG_CALLS)
    return 205;
  L1107:
  ro[2] = x2;
  if (TARGET_ABICALLS && !TARGET_LONG_CALLS)
    return 206;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L1110;

  L1111:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[0] = x3;
      goto L1112;
    }
  goto ret0;

  L1112:
  x2 = XEXP (x1, 1);
  ro[1] = x2;
  goto L1113;

  L1113:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L1114;
  goto ret0;

  L1114:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L1122;
  goto ret0;

  L1122:
  ro[2] = x2;
  if (!TARGET_ABICALLS && TARGET_LONG_CALLS)
    return 207;
  L1123:
  ro[2] = x2;
  if (TARGET_ABICALLS && TARGET_LONG_CALLS)
    return 208;
  goto ret0;
 ret0: return -1;
}

int
recog_5 (x0, insn, pnum_clobbers)
     register rtx x0;
     rtx insn;
     int *pnum_clobbers;
{
  register rtx *ro = &recog_operand[0];
  register rtx x1, x2, x3, x4;
  int tem;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != SImode)
    goto ret0;
  if (register_operand (x2, SImode))
    {
      ro[0] = x2;
      goto L147;
    }
  L499:
  if (general_operand (x2, SImode))
    {
      ro[0] = x2;
      goto L500;
    }
  goto ret0;

  L147:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) != SImode)
    {
      x2 = XEXP (x1, 0);
      goto L499;
    }
  switch (GET_CODE (x2))
    {
    case MULT:
      goto L148;
    case DIV:
      goto L282;
    case MOD:
      goto L297;
    case UDIV:
      goto L312;
    case UMOD:
      goto L327;
    case FFS:
      goto L362;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L148:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L149;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L149:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L150;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L150:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L151;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L151:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    goto L152;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L152:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L153;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L153:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
    return 24;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L282:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L283;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L283:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L284;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L284:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L285;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L285:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    goto L286;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L286:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L287;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L287:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
    if (!optimize)
      return 33;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L297:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L298;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L298:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L299;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L299:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L300;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L300:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    goto L301;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L301:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L302;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L302:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
    if (!optimize)
      return 34;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L312:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L313;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L313:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L314;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L314:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L315;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L315:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    goto L316;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L316:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L317;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L317:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
    if (!optimize)
      return 35;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L327:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L328;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L328:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L329;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L329:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L330;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L330:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    goto L331;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L331:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L332;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L332:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
    if (!optimize)
      return 36;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L362:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L363;
    }
  x2 = XEXP (x1, 0);
  goto L499;

  L363:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L364;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L364:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      ro[2] = x2;
      goto L365;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L365:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L366;
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L366:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      ro[3] = x2;
      return 42;
    }
  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 0);
  goto L499;

  L500:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == FIX && 1)
    goto L501;
  goto ret0;

  L501:
  x3 = XEXP (x2, 0);
  switch (GET_MODE (x3))
    {
    case DFmode:
      if (register_operand (x3, DFmode))
	{
	  ro[1] = x3;
	  goto L502;
	}
      break;
    case SFmode:
      if (register_operand (x3, SFmode))
	{
	  ro[1] = x3;
	  goto L515;
	}
    }
  goto ret0;

  L502:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L503;
  goto ret0;

  L503:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      ro[2] = x2;
      goto L504;
    }
  goto ret0;

  L504:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L505;
  goto ret0;

  L505:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, DFmode))
    {
      ro[3] = x2;
      if (TARGET_HARD_FLOAT)
	return 74;
      }
  goto ret0;

  L515:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L516;
  goto ret0;

  L516:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      ro[2] = x2;
      goto L517;
    }
  goto ret0;

  L517:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L518;
  goto ret0;

  L518:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SFmode))
    {
      ro[3] = x2;
      if (TARGET_HARD_FLOAT)
	return 75;
      }
  goto ret0;
 ret0: return -1;
}

int
recog (x0, insn, pnum_clobbers)
     register rtx x0;
     rtx insn;
     int *pnum_clobbers;
{
  register rtx *ro = &recog_operand[0];
  register rtx x1, x2, x3, x4;
  int tem;

  L0:
  switch (GET_CODE (x0))
    {
    case SET:
      goto L1;
    case PARALLEL:
      if (XVECLEN (x0, 0) == 2 && 1)
	goto L16;
      if (XVECLEN (x0, 0) == 3 && 1)
	goto L145;
      if (XVECLEN (x0, 0) == 4 && 1)
	goto L227;
      if (XVECLEN (x0, 0) == 8 && 1)
	goto L592;
      break;
    case UNSPEC_VOLATILE:
      if (XINT (x0, 1) == 0 && XVECLEN (x0, 0) == 1 && 1)
	goto L1093;
      break;
    case CONST_INT:
      if (XWINT (x0, 0) == 0 && 1)
	return 215;
    }
  goto ret0;
 L1:
  return recog_2 (x0, insn, pnum_clobbers);
 L16:
  return recog_4 (x0, insn, pnum_clobbers);

  L145:
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET && 1)
    goto L146;
  goto ret0;
 L146:
  return recog_5 (x0, insn, pnum_clobbers);

  L227:
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET && 1)
    goto L228;
  goto ret0;

  L228:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[0] = x2;
      goto L229;
    }
  goto ret0;

  L229:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) != SImode)
    goto ret0;
  switch (GET_CODE (x2))
    {
    case DIV:
      goto L230;
    case UDIV:
      goto L256;
    }
  goto ret0;

  L230:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L231;
    }
  goto ret0;

  L231:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L232;
    }
  goto ret0;

  L232:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET && 1)
    goto L233;
  goto ret0;

  L233:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      goto L234;
    }
  goto ret0;

  L234:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == MOD && 1)
    goto L235;
  goto ret0;

  L235:
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, ro[1]) && 1)
    goto L236;
  goto ret0;

  L236:
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, ro[2]) && 1)
    goto L237;
  goto ret0;

  L237:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L238;
  goto ret0;

  L238:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    goto L239;
  goto ret0;

  L239:
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L240;
  goto ret0;

  L240:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
    if (optimize)
      return 31;
  goto ret0;

  L256:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L257;
    }
  goto ret0;

  L257:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L258;
    }
  goto ret0;

  L258:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == SET && 1)
    goto L259;
  goto ret0;

  L259:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[3] = x2;
      goto L260;
    }
  goto ret0;

  L260:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == UMOD && 1)
    goto L261;
  goto ret0;

  L261:
  x3 = XEXP (x2, 0);
  if (rtx_equal_p (x3, ro[1]) && 1)
    goto L262;
  goto ret0;

  L262:
  x3 = XEXP (x2, 1);
  if (rtx_equal_p (x3, ro[2]) && 1)
    goto L263;
  goto ret0;

  L263:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L264;
  goto ret0;

  L264:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    goto L265;
  goto ret0;

  L265:
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L266;
  goto ret0;

  L266:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
    if (optimize)
      return 32;
  goto ret0;

  L592:
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET && 1)
    goto L593;
  goto ret0;

  L593:
  x2 = XEXP (x1, 0);
  if (memory_operand (x2, BLKmode))
    {
      ro[0] = x2;
      goto L594;
    }
  goto ret0;

  L594:
  x2 = XEXP (x1, 1);
  if (memory_operand (x2, BLKmode))
    {
      ro[1] = x2;
      goto L595;
    }
  goto ret0;

  L595:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L596;
  goto ret0;

  L596:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      ro[4] = x2;
      goto L597;
    }
  goto ret0;

  L597:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L598;
  goto ret0;

  L598:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      ro[5] = x2;
      goto L599;
    }
  goto ret0;

  L599:
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L600;
  goto ret0;

  L600:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      ro[6] = x2;
      goto L601;
    }
  goto ret0;

  L601:
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L602;
  goto ret0;

  L602:
  x2 = XEXP (x1, 0);
  if (scratch_operand (x2, SImode))
    {
      ro[7] = x2;
      goto L603;
    }
  goto ret0;

  L603:
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == USE && 1)
    goto L604;
  goto ret0;

  L604:
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == CONST_INT && small_int (x2, SImode))
    {
      ro[2] = x2;
      goto L605;
    }
  goto ret0;

  L605:
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == USE && 1)
    goto L606;
  goto ret0;

  L606:
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == CONST_INT && small_int (x2, SImode))
    {
      ro[3] = x2;
      goto L607;
    }
  goto ret0;

  L607:
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == USE && 1)
    goto L608;
  goto ret0;

  L608:
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) != CONST_INT)
    goto ret0;
  if (XWINT (x2, 0) == 0 && 1)
    return 104;
  if (GET_CODE (x2) != CONST_INT)
    goto ret0;
  if (XWINT (x2, 0) == 1 && 1)
    return 106;
  if (XWINT (x2, 0) == 2 && 1)
    return 107;
  goto ret0;

  L1093:
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == CONST_INT && XWINT (x1, 0) == 0 && 1)
    return 203;
  goto ret0;
 ret0: return -1;
}

rtx
split_1 (x0, insn)
     register rtx x0;
     rtx insn;
{
  register rtx *ro = &recog_operand[0];
  register rtx x1, x2, x3, x4;
  rtx tem;

  x1 = XVECEXP (x0, 0, 0);
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) != DImode)
    goto ret0;
  switch (GET_CODE (x2))
    {
    case PLUS:
      goto L27;
    case MINUS:
      goto L94;
    case ASHIFT:
      goto L690;
    case ASHIFTRT:
      goto L757;
    case LSHIFTRT:
      goto L824;
    }
  goto ret0;

  L27:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L28;
    }
  goto ret0;

  L28:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      ro[2] = x3;
      goto L29;
    }
  if (GET_CODE (x3) == CONST_INT && small_int (x3, DImode))
    {
      ro[2] = x3;
      goto L55;
    }
  goto ret0;

  L29:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L30;
  goto ret0;

  L30:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L39;
  goto ret0;

  L39:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && GET_CODE (operands[2]) == REG && GP_REG_P (REGNO (operands[2]))
   && (REGNO (operands[0]) != REGNO (operands[1])
       || REGNO (operands[0]) != REGNO (operands[2])))
    return gen_split_6 (operands);
  L40:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && GET_CODE (operands[2]) == REG && GP_REG_P (REGNO (operands[2]))
   && (REGNO (operands[0]) != REGNO (operands[1])
       || REGNO (operands[0]) != REGNO (operands[2])))
    return gen_split_7 (operands);
  goto ret0;

  L55:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L56;
  goto ret0;

  L56:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L65;
  goto ret0;

  L65:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && INTVAL (operands[2]) > 0)
    return gen_split_9 (operands);
  L66:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && INTVAL (operands[2]) > 0)
    return gen_split_10 (operands);
  goto ret0;

  L94:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L95;
    }
  goto ret0;

  L95:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      ro[2] = x3;
      goto L96;
    }
  if (GET_CODE (x3) == CONST_INT && small_int (x3, DImode))
    {
      ro[2] = x3;
      goto L122;
    }
  goto ret0;

  L96:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L97;
  goto ret0;

  L97:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L106;
  goto ret0;

  L106:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && GET_CODE (operands[2]) == REG && GP_REG_P (REGNO (operands[2])))
    return gen_split_17 (operands);
  L107:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && GET_CODE (operands[2]) == REG && GP_REG_P (REGNO (operands[2])))
    return gen_split_18 (operands);
  goto ret0;

  L122:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L123;
  goto ret0;

  L123:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    goto L132;
  goto ret0;

  L132:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && INTVAL (operands[2]) > 0)
    return gen_split_20 (operands);
  L133:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && INTVAL (operands[2]) > 0)
    return gen_split_21 (operands);
  goto ret0;

  L690:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L691;
    }
  goto ret0;

  L691:
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT && small_int (x3, SImode))
    {
      ro[2] = x3;
      goto L692;
    }
  goto ret0;

  L692:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L693;
  goto ret0;

  L693:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != SImode)
    goto ret0;
  if (register_operand (x2, SImode))
    goto L702;
  L721:
  if (register_operand (x2, SImode))
    goto L730;
  goto ret0;

  L702:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 32) != 0)
    return gen_split_112 (operands);
  L703:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 32) != 0)
    return gen_split_113 (operands);
  goto L721;

  L730:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return gen_split_115 (operands);
  L731:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return gen_split_116 (operands);
  goto ret0;

  L757:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L758;
    }
  goto ret0;

  L758:
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT && small_int (x3, SImode))
    {
      ro[2] = x3;
      goto L759;
    }
  goto ret0;

  L759:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L760;
  goto ret0;

  L760:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != SImode)
    goto ret0;
  if (register_operand (x2, SImode))
    goto L769;
  L788:
  if (register_operand (x2, SImode))
    goto L797;
  goto ret0;

  L769:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 32) != 0)
    return gen_split_121 (operands);
  L770:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 32) != 0)
    return gen_split_122 (operands);
  goto L788;

  L797:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return gen_split_124 (operands);
  L798:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return gen_split_125 (operands);
  goto ret0;

  L824:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L825;
    }
  goto ret0;

  L825:
  x3 = XEXP (x2, 1);
  if (GET_CODE (x3) == CONST_INT && small_int (x3, SImode))
    {
      ro[2] = x3;
      goto L826;
    }
  goto ret0;

  L826:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L827;
  goto ret0;

  L827:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != SImode)
    goto ret0;
  if (register_operand (x2, SImode))
    goto L836;
  L855:
  if (register_operand (x2, SImode))
    goto L864;
  goto ret0;

  L836:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 32) != 0)
    return gen_split_130 (operands);
  L837:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 32) != 0)
    return gen_split_131 (operands);
  goto L855;

  L864:
  ro[3] = x2;
  if (reload_completed && !WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return gen_split_133 (operands);
  L865:
  ro[3] = x2;
  if (reload_completed && WORDS_BIG_ENDIAN && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && REGNO (operands[0]) < FIRST_PSEUDO_REGISTER
   && GET_CODE (operands[1]) == REG && REGNO (operands[1]) < FIRST_PSEUDO_REGISTER
   && (INTVAL (operands[2]) & 63) < 32
   && (INTVAL (operands[2]) & 63) != 0)
    return gen_split_134 (operands);
  goto ret0;
 ret0: return 0;
}

rtx
split_insns (x0, insn)
     register rtx x0;
     rtx insn;
{
  register rtx *ro = &recog_operand[0];
  register rtx x1, x2, x3, x4;
  rtx tem;

  L23:
  switch (GET_CODE (x0))
    {
    case PARALLEL:
      if (XVECLEN (x0, 0) == 2 && 1)
	goto L24;
      if (XVECLEN (x0, 0) == 3 && 1)
	goto L160;
      if (XVECLEN (x0, 0) == 8 && 1)
	goto L610;
      break;
    case SET:
      goto L399;
    }
  goto ret0;

  L24:
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET && 1)
    goto L25;
  goto ret0;

  L25:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      ro[0] = x2;
      goto L26;
    }
  goto ret0;
 L26:
  return split_1 (x0, insn);

  L160:
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET && 1)
    goto L161;
  goto ret0;

  L161:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[0] = x2;
      goto L162;
    }
  goto ret0;

  L162:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == MULT && 1)
    goto L163;
  goto ret0;

  L163:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L164;
    }
  goto ret0;

  L164:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, SImode))
    {
      ro[2] = x3;
      goto L165;
    }
  goto ret0;

  L165:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L166;
  goto ret0;

  L166:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 64 && 1)
    goto L167;
  goto ret0;

  L167:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L168;
  goto ret0;

  L168:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == SImode && GET_CODE (x2) == REG && XINT (x2, 0) == 65 && 1)
    if (!TARGET_DEBUG_D_MODE)
      return gen_split_25 (operands);
  goto ret0;

  L610:
  x1 = XVECEXP (x0, 0, 0);
  if (GET_CODE (x1) == SET && 1)
    goto L611;
  goto ret0;

  L611:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) == BLKmode && GET_CODE (x2) == MEM && 1)
    goto L612;
  goto ret0;

  L612:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[0] = x3;
      goto L613;
    }
  goto ret0;

  L613:
  x2 = XEXP (x1, 1);
  if (GET_MODE (x2) == BLKmode && GET_CODE (x2) == MEM && 1)
    goto L614;
  goto ret0;

  L614:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, SImode))
    {
      ro[1] = x3;
      goto L615;
    }
  goto ret0;

  L615:
  x1 = XVECEXP (x0, 0, 1);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L616;
  goto ret0;

  L616:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[4] = x2;
      goto L617;
    }
  goto ret0;

  L617:
  x1 = XVECEXP (x0, 0, 2);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L618;
  goto ret0;

  L618:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[5] = x2;
      goto L619;
    }
  goto ret0;

  L619:
  x1 = XVECEXP (x0, 0, 3);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L620;
  goto ret0;

  L620:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[6] = x2;
      goto L621;
    }
  goto ret0;

  L621:
  x1 = XVECEXP (x0, 0, 4);
  if (GET_CODE (x1) == CLOBBER && 1)
    goto L622;
  goto ret0;

  L622:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[7] = x2;
      goto L623;
    }
  goto ret0;

  L623:
  x1 = XVECEXP (x0, 0, 5);
  if (GET_CODE (x1) == USE && 1)
    goto L624;
  goto ret0;

  L624:
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == CONST_INT && small_int (x2, SImode))
    {
      ro[2] = x2;
      goto L625;
    }
  goto ret0;

  L625:
  x1 = XVECEXP (x0, 0, 6);
  if (GET_CODE (x1) == USE && 1)
    goto L626;
  goto ret0;

  L626:
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == CONST_INT && small_int (x2, SImode))
    {
      ro[3] = x2;
      goto L627;
    }
  goto ret0;

  L627:
  x1 = XVECEXP (x0, 0, 7);
  if (GET_CODE (x1) == USE && 1)
    goto L628;
  goto ret0;

  L628:
  x2 = XEXP (x1, 0);
  if (GET_CODE (x2) == CONST_INT && XWINT (x2, 0) == 0 && 1)
    if (reload_completed && !TARGET_DEBUG_D_MODE && INTVAL (operands[2]) > 0)
      return gen_split_105 (operands);
  goto ret0;

  L399:
  x1 = XEXP (x0, 0);
  switch (GET_MODE (x1))
    {
    case DImode:
      if (register_operand (x1, DImode))
	{
	  ro[0] = x1;
	  goto L400;
	}
      break;
    case SImode:
      if (register_operand (x1, SImode))
	{
	  ro[0] = x1;
	  goto L926;
	}
      break;
    case DFmode:
      if (register_operand (x1, DFmode))
	{
	  ro[0] = x1;
	  goto L590;
	}
    }
  goto ret0;

  L400:
  x1 = XEXP (x0, 1);
  if (GET_MODE (x1) != DImode)
    goto ret0;
  switch (GET_CODE (x1))
    {
    case NOT:
      goto L417;
    case AND:
      goto L433;
    case IOR:
      goto L448;
    case XOR:
      goto L463;
    case SUBREG:
    case REG:
      if (register_operand (x1, DImode))
	{
	  ro[1] = x1;
	  if (reload_completed && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1])))
	    return gen_split_85 (operands);
	  }
    }
  goto ret0;

  L417:
  x2 = XEXP (x1, 0);
  if (GET_MODE (x2) != DImode)
    goto ret0;
  if (GET_CODE (x2) == IOR && 1)
    goto L418;
  if (register_operand (x2, DImode))
    {
      ro[1] = x2;
      if (reload_completed && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1])))
	return gen_split_50 (operands);
      }
  goto ret0;

  L418:
  x3 = XEXP (x2, 0);
  if (register_operand (x3, DImode))
    {
      ro[1] = x3;
      goto L419;
    }
  goto ret0;

  L419:
  x3 = XEXP (x2, 1);
  if (register_operand (x3, DImode))
    {
      ro[2] = x3;
      if (reload_completed && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && GET_CODE (operands[2]) == REG && GP_REG_P (REGNO (operands[2])))
	return gen_split_53 (operands);
      }
  goto ret0;

  L433:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      ro[1] = x2;
      goto L434;
    }
  goto ret0;

  L434:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      ro[2] = x2;
      if (reload_completed && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && GET_CODE (operands[2]) == REG && GP_REG_P (REGNO (operands[2])))
	return gen_split_56 (operands);
      }
  goto ret0;

  L448:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      ro[1] = x2;
      goto L449;
    }
  goto ret0;

  L449:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      ro[2] = x2;
      if (reload_completed && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && GET_CODE (operands[2]) == REG && GP_REG_P (REGNO (operands[2])))
	return gen_split_59 (operands);
      }
  goto ret0;

  L463:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, DImode))
    {
      ro[1] = x2;
      goto L464;
    }
  goto ret0;

  L464:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, DImode))
    {
      ro[2] = x2;
      if (reload_completed && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1]))
   && GET_CODE (operands[2]) == REG && GP_REG_P (REGNO (operands[2])))
	return gen_split_62 (operands);
      }
  goto ret0;

  L926:
  x1 = XEXP (x0, 1);
  switch (GET_MODE (x1))
    {
    case SImode:
      switch (GET_CODE (x1))
	{
	case EQ:
	  goto L927;
	case NE:
	  goto L942;
	case GE:
	  goto L957;
	case LE:
	  goto L977;
	case GEU:
	  goto L992;
	case LEU:
	  goto L1012;
	}
    }
  if (GET_CODE (x1) == CONST_INT && large_int (x1, SImode))
    {
      ro[1] = x1;
      if (!TARGET_DEBUG_D_MODE)
	return gen_split_86 (operands);
      }
  goto ret0;

  L927:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L928;
    }
  goto ret0;

  L928:
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE && !TARGET_DEBUG_D_MODE
    && (GET_CODE (operands[2]) != CONST_INT || INTVAL (operands[2]) != 0))
	return gen_split_158 (operands);
      }
  goto ret0;

  L942:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L943;
    }
  goto ret0;

  L943:
  x2 = XEXP (x1, 1);
  if (uns_arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE && !TARGET_DEBUG_D_MODE
    && (GET_CODE (operands[2]) != CONST_INT || INTVAL (operands[2]) != 0))
	return gen_split_162 (operands);
      }
  goto ret0;

  L957:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L958;
    }
  goto ret0;

  L958:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE && !TARGET_DEBUG_D_MODE)
	return gen_split_167 (operands);
      }
  goto ret0;

  L977:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L978;
    }
  goto ret0;

  L978:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE && !TARGET_DEBUG_D_MODE)
	return gen_split_173 (operands);
      }
  goto ret0;

  L992:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L993;
    }
  goto ret0;

  L993:
  x2 = XEXP (x1, 1);
  if (arith_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE && !TARGET_DEBUG_D_MODE)
	return gen_split_178 (operands);
      }
  goto ret0;

  L1012:
  x2 = XEXP (x1, 0);
  if (register_operand (x2, SImode))
    {
      ro[1] = x2;
      goto L1013;
    }
  goto ret0;

  L1013:
  x2 = XEXP (x1, 1);
  if (register_operand (x2, SImode))
    {
      ro[2] = x2;
      if (TARGET_DEBUG_C_MODE && !TARGET_DEBUG_D_MODE)
	return gen_split_184 (operands);
      }
  goto ret0;

  L590:
  x1 = XEXP (x0, 1);
  if (register_operand (x1, DFmode))
    {
      ro[1] = x1;
      if (reload_completed && !TARGET_DEBUG_D_MODE && !TARGET_DEBUG_G_MODE
   && GET_CODE (operands[0]) == REG && GP_REG_P (REGNO (operands[0]))
   && GET_CODE (operands[1]) == REG && GP_REG_P (REGNO (operands[1])))
	return gen_split_102 (operands);
      }
  goto ret0;
 ret0: return 0;
}

