/* Generated automatically by the program `genemit'
from the machine description file `md'.  */

#include "config.h"
#include "rtl.h"
#include "expr.h"
#include "real.h"
#include "output.h"
#include "insn-config.h"

#include "insn-flags.h"

#include "insn-codes.h"

extern char *insn_operand_constraint[][MAX_RECOG_OPERANDS];

extern rtx recog_operand[];
#define operands emit_operand

#define FAIL goto _fail

#define DONE goto _done

rtx
gen_adddf3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (PLUS, DFmode,
	operand1,
	operand2));
}

rtx
gen_addsf3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (PLUS, SFmode,
	operand1,
	operand2));
}

rtx
gen_addsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;

{
  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) == -32768)
    operands[2] = force_reg (SImode, operands[2]);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (PLUS, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_addsi3_internal (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (PLUS, SImode,
	operand1,
	operand2));
}

rtx
gen_adddi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  rtx operand3;
  rtx operands[4];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;

{
  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) == -32768)
    operands[2] = force_reg (DImode, operands[2]);

  operands[3] = gen_reg_rtx (SImode);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (PLUS, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_adddi3_internal_1 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (PLUS, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_6 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LTU, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_7 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LTU, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_adddi3_internal_2 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (PLUS, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_9 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LTU, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_10 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LTU, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (PLUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_subdf3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MINUS, DFmode,
	operand1,
	operand2));
}

rtx
gen_subsf3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MINUS, SFmode,
	operand1,
	operand2));
}

rtx
gen_subsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;

{
  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) == -32768)
    operands[2] = force_reg (SImode, operands[2]);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MINUS, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_subsi3_internal (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MINUS, SImode,
	operand1,
	operand2));
}

rtx
gen_subdi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  rtx operand3;
  rtx operands[4];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;
operands[3] = gen_reg_rtx (SImode);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MINUS, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_subdi3_internal (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MINUS, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_17 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LTU, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_18 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LTU, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_subdi3_internal_2 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MINUS, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_20 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LTU, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_21 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LTU, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (MINUS, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_muldf3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MULT, DFmode,
	operand1,
	operand2));
}

rtx
gen_mulsf3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MULT, SFmode,
	operand1,
	operand2));
}

rtx
gen_mulsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MULT, SImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65))));
}

rtx
gen_split_25 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	gen_rtx (REG, SImode,
	65),
	gen_rtx (MULT, SImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64)))));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (REG, SImode,
	65)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_mulsi3_internal (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	gen_rtx (REG, SImode,
	65),
	gen_rtx (MULT, SImode,
	operand0,
	operand1)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64))));
}

rtx
gen_mulsidi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MULT, DImode,
	gen_rtx (SIGN_EXTEND, DImode,
	operand1),
	gen_rtx (SIGN_EXTEND, DImode,
	operand2))),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, DImode,
	64))));
}

rtx
gen_umulsidi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MULT, DImode,
	gen_rtx (ZERO_EXTEND, DImode,
	operand1),
	gen_rtx (ZERO_EXTEND, DImode,
	operand2))),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, DImode,
	64))));
}

rtx
gen_divdf3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (DIV, DFmode,
	operand1,
	operand2));
}

rtx
gen_divsf3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (DIV, SFmode,
	operand1,
	operand2));
}

rtx
gen_divmodsi4 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (4,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (DIV, SImode,
	operand1,
	operand2)),
		gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (MOD, SImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65))));
}

rtx
gen_udivmodsi4 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (4,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (UDIV, SImode,
	operand1,
	operand2)),
		gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (UMOD, SImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65))));
}

rtx
gen_divsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (DIV, SImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65))));
}

rtx
gen_modsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (MOD, SImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65))));
}

rtx
gen_udivsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (UDIV, SImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65))));
}

rtx
gen_umodsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (UMOD, SImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65))));
}

rtx
gen_sqrtdf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (SQRT, DFmode,
	operand1));
}

rtx
gen_sqrtsf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (SQRT, SFmode,
	operand1));
}

rtx
gen_abssi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ABS, SImode,
	operand1));
}

rtx
gen_absdf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ABS, DFmode,
	operand1));
}

rtx
gen_abssf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ABS, SFmode,
	operand1));
}

rtx
gen_ffssi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (FFS, SImode,
	operand1)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0))));
}

rtx
gen_negsi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NEG, SImode,
	operand1));
}

rtx
gen_negdi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
operands[2] = gen_reg_rtx (SImode);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NEG, DImode,
	operand1)),
		gen_rtx (CLOBBER, VOIDmode,
	operand2))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_negdi2_internal (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NEG, DImode,
	operand1)),
		gen_rtx (CLOBBER, VOIDmode,
	operand2)));
}

rtx
gen_negdf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NEG, DFmode,
	operand1));
}

rtx
gen_negsf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NEG, SFmode,
	operand1));
}

rtx
gen_one_cmplsi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NOT, SImode,
	operand1));
}

rtx
gen_one_cmpldi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NOT, SImode,
	operand1));
}

rtx
gen_split_50 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (NOT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (NOT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_norsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NOT, SImode,
	gen_rtx (IOR, SImode,
	operand1,
	operand2)));
}

rtx
gen_nordi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NOT, DImode,
	gen_rtx (IOR, DImode,
	operand1,
	operand2)));
}

rtx
gen_split_53 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (NOT, SImode,
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0)))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (NOT, SImode,
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1)))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_andsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (AND, SImode,
	operand1,
	operand2));
}

rtx
gen_anddi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (AND, DImode,
	operand1,
	operand2));
}

rtx
gen_split_56 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (AND, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (AND, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_iorsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (IOR, SImode,
	operand1,
	operand2));
}

rtx
gen_iordi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (IOR, DImode,
	operand1,
	operand2));
}

rtx
gen_split_59 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_xorsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (XOR, SImode,
	operand1,
	operand2));
}

rtx
gen_xordi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (XOR, DImode,
	operand1,
	operand2));
}

rtx
gen_split_62 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (XOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	gen_rtx (SUBREG, SImode,
	operand2,
	0))));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (XOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	gen_rtx (SUBREG, SImode,
	operand2,
	1))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_truncdfsf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (FLOAT_TRUNCATE, SFmode,
	operand1));
}

rtx
gen_zero_extendhisi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ZERO_EXTEND, SImode,
	operand1));
}

rtx
gen_zero_extendqihi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ZERO_EXTEND, HImode,
	operand1));
}

rtx
gen_zero_extendqisi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ZERO_EXTEND, SImode,
	operand1));
}

rtx
gen_extendhisi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if (optimize && GET_CODE (operands[1]) == MEM)
    operands[1] = force_not_mem (operands[1]);

  if (GET_CODE (operands[1]) != MEM)
    {
      rtx op1   = gen_lowpart (SImode, operands[1]);
      rtx temp  = gen_reg_rtx (SImode);
      rtx shift = gen_rtx (CONST_INT, VOIDmode, 16);

      emit_insn (gen_ashlsi3 (temp, op1, shift));
      emit_insn (gen_ashrsi3 (operands[0], temp, shift));
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (SIGN_EXTEND, SImode,
	operand1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_extendhisi2_internal (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (SIGN_EXTEND, SImode,
	operand1));
}

rtx
gen_extendqihi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if (optimize && GET_CODE (operands[1]) == MEM)
    operands[1] = force_not_mem (operands[1]);

  if (GET_CODE (operands[1]) != MEM)
    {
      rtx op0   = gen_lowpart (SImode, operands[0]);
      rtx op1   = gen_lowpart (SImode, operands[1]);
      rtx temp  = gen_reg_rtx (SImode);
      rtx shift = gen_rtx (CONST_INT, VOIDmode, 24);

      emit_insn (gen_ashlsi3 (temp, op1, shift));
      emit_insn (gen_ashrsi3 (op0, temp, shift));
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (SIGN_EXTEND, HImode,
	operand1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_extendqihi2_internal (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (SIGN_EXTEND, HImode,
	operand1));
}

rtx
gen_extendqisi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if (optimize && GET_CODE (operands[1]) == MEM)
    operands[1] = force_not_mem (operands[1]);

  if (GET_CODE (operands[1]) != MEM)
    {
      rtx op1   = gen_lowpart (SImode, operands[1]);
      rtx temp  = gen_reg_rtx (SImode);
      rtx shift = gen_rtx (CONST_INT, VOIDmode, 24);

      emit_insn (gen_ashlsi3 (temp, op1, shift));
      emit_insn (gen_ashrsi3 (operands[0], temp, shift));
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (SIGN_EXTEND, SImode,
	operand1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_extendqisi2_insn (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (SIGN_EXTEND, SImode,
	operand1));
}

rtx
gen_extendsfdf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (FLOAT_EXTEND, DFmode,
	operand1));
}

rtx
gen_fix_truncdfsi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (FIX, SImode,
	operand1)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, DFmode, 0))));
}

rtx
gen_fix_truncsfsi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (FIX, SImode,
	operand1)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SFmode, 0))));
}

rtx
gen_floatsidf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (FLOAT, DFmode,
	operand1));
}

rtx
gen_floatsisf2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (FLOAT, SFmode,
	operand1));
}

rtx
gen_fixuns_truncdfsi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  rtx reg1 = gen_reg_rtx (DFmode);
  rtx reg2 = gen_reg_rtx (DFmode);
  rtx reg3 = gen_reg_rtx (SImode);
  rtx label1 = gen_label_rtx ();
  rtx label2 = gen_label_rtx ();
  REAL_VALUE_TYPE offset = REAL_VALUE_LDEXP (1.0, 31);

  if (reg1)			/* turn off complaints about unreached code */
    {
      emit_move_insn (reg1, immed_real_const_1 (offset, DFmode));
      do_pending_stack_adjust ();

      emit_insn (gen_cmpdf (operands[1], reg1));
      emit_jump_insn (gen_bge (label1));

      emit_insn (gen_fix_truncdfsi2 (operands[0], operands[1]));
      emit_jump_insn (gen_rtx (SET, VOIDmode, pc_rtx,
			       gen_rtx (LABEL_REF, VOIDmode, label2)));
      emit_barrier ();

      emit_label (label1);
      emit_move_insn (reg2, gen_rtx (MINUS, DFmode, operands[1], reg1));
      emit_move_insn (reg3, gen_rtx (CONST_INT, VOIDmode, 0x80000000));

      emit_insn (gen_fix_truncdfsi2 (operands[0], reg2));
      emit_insn (gen_iorsi3 (operands[0], operands[0], reg3));

      emit_label (label2);

      /* allow REG_NOTES to be set on last insn (labels don't have enough
	 fields, and can't be used for REG_NOTES anyway).  */
      emit_insn (gen_rtx (USE, VOIDmode, stack_pointer_rtx));
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (UNSIGNED_FIX, SImode,
	operand1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_fixuns_truncsfsi2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  rtx reg1 = gen_reg_rtx (SFmode);
  rtx reg2 = gen_reg_rtx (SFmode);
  rtx reg3 = gen_reg_rtx (SImode);
  rtx label1 = gen_label_rtx ();
  rtx label2 = gen_label_rtx ();
  REAL_VALUE_TYPE offset = REAL_VALUE_LDEXP (1.0, 31);

  if (reg1)			/* turn off complaints about unreached code */
    {
      emit_move_insn (reg1, immed_real_const_1 (offset, SFmode));
      do_pending_stack_adjust ();

      emit_insn (gen_cmpsf (operands[1], reg1));
      emit_jump_insn (gen_bge (label1));

      emit_insn (gen_fix_truncsfsi2 (operands[0], operands[1]));
      emit_jump_insn (gen_rtx (SET, VOIDmode, pc_rtx,
			       gen_rtx (LABEL_REF, VOIDmode, label2)));
      emit_barrier ();

      emit_label (label1);
      emit_move_insn (reg2, gen_rtx (MINUS, SFmode, operands[1], reg1));
      emit_move_insn (reg3, gen_rtx (CONST_INT, VOIDmode, 0x80000000));

      emit_insn (gen_fix_truncsfsi2 (operands[0], reg2));
      emit_insn (gen_iorsi3 (operands[0], operands[0], reg3));

      emit_label (label2);

      /* allow REG_NOTES to be set on last insn (labels don't have enough
	 fields, and can't be used for REG_NOTES anyway).  */
      emit_insn (gen_rtx (USE, VOIDmode, stack_pointer_rtx));
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (UNSIGNED_FIX, SImode,
	operand1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movsi_unaligned (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  /* Handle stores.  */
  if (GET_CODE (operands[0]) == MEM)
    {
      rtx reg = gen_reg_rtx (SImode);
      rtx insn = emit_insn (gen_movsi_ulw (reg, operands[1]));
      rtx addr = XEXP (operands[0], 0);
      if (CONSTANT_P (addr))
	REG_NOTES (insn) = gen_rtx (EXPR_LIST, REG_EQUIV, addr, REG_NOTES (insn));

      if (reg_or_0_operand (operands[1], SImode))
	DONE;

      operands[1] = reg;
    }

  /* Generate appropriate load, store.  If not a load or store,
     do a normal movsi.  */
  if (GET_CODE (operands[0]) != MEM && GET_CODE (operands[1]) != MEM)
    {
      emit_insn (gen_movsi (operands[0], operands[1]));
      DONE;
    }

  /* Fall through and generate normal code.  */
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (UNSPEC, VOIDmode,
	gen_rtvec (1,
		operand1),
	0)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movsi_ulw (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (UNSPEC, VOIDmode,
	gen_rtvec (1,
		operand1),
	0));
}

rtx
gen_movsi_usw (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (UNSPEC, VOIDmode,
	gen_rtvec (1,
		operand1),
	0));
}

rtx
gen_movdi (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if ((reload_in_progress | reload_completed) == 0
      && !register_operand (operands[0], DImode)
      && !register_operand (operands[1], DImode)
      && (GET_CODE (operands[1]) != CONST_INT || INTVAL (operands[1]) != 0)
      && operands[1] != CONST0_RTX (DImode))
    {
      rtx temp = force_reg (DImode, operands[1]);
      emit_move_insn (operands[0], temp);
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	operand1));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movdi_internal (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_split_85 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (SUBREG, SImode,
	operand1,
	0)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (SUBREG, SImode,
	operand1,
	1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_86 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx _val = 0;
  start_sequence ();

{
  operands[2] = gen_rtx (CONST_INT, VOIDmode, INTVAL (operands[1]) & 0xffff0000);
  operands[3] = gen_rtx (CONST_INT, VOIDmode, INTVAL (operands[1]) & 0x0000ffff);
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	operand2));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (IOR, SImode,
	operand0,
	operand3)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movsi (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if ((reload_in_progress | reload_completed) == 0
      && !register_operand (operands[0], SImode)
      && !register_operand (operands[1], SImode)
      && (GET_CODE (operands[1]) != CONST_INT || INTVAL (operands[1]) != 0))
    {
      rtx temp = force_reg (SImode, operands[1]);
      emit_move_insn (operands[0], temp);
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	operand1));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movsi_internal1 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movsi_internal2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movhi (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if ((reload_in_progress | reload_completed) == 0
      && !register_operand (operands[0], HImode)
      && !register_operand (operands[1], HImode)
      && (GET_CODE (operands[1]) != CONST_INT || INTVAL (operands[1]) != 0))
    {
      rtx temp = force_reg (HImode, operands[1]);
      emit_move_insn (operands[0], temp);
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	operand1));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movhi_internal1 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movhi_internal2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movqi (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if ((reload_in_progress | reload_completed) == 0
      && !register_operand (operands[0], QImode)
      && !register_operand (operands[1], QImode)
      && (GET_CODE (operands[1]) != CONST_INT || INTVAL (operands[1]) != 0))
    {
      rtx temp = force_reg (QImode, operands[1]);
      emit_move_insn (operands[0], temp);
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	operand1));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movqi_internal1 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movqi_internal2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movsf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if ((reload_in_progress | reload_completed) == 0
      && !register_operand (operands[0], SFmode)
      && !register_operand (operands[1], SFmode)
      && (GET_CODE (operands[1]) != CONST_INT || INTVAL (operands[1]) != 0)
      && operands[1] != CONST0_RTX (SFmode))
    {
      rtx temp = force_reg (SFmode, operands[1]);
      emit_move_insn (operands[0], temp);
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	operand1));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movsf_internal1 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movsf_internal2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movdf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if ((reload_in_progress | reload_completed) == 0
      && !register_operand (operands[0], DFmode)
      && !register_operand (operands[1], DFmode)
      && (GET_CODE (operands[1]) != CONST_INT || INTVAL (operands[1]) != 0)
      && operands[1] != CONST0_RTX (DFmode))
    {
      rtx temp = force_reg (DFmode, operands[1]);
      emit_move_insn (operands[0], temp);
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	operand1));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movdf_internal1 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_movdf_internal2 (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	operand1);
}

rtx
gen_split_102 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (SUBREG, SImode,
	operand1,
	0)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (SUBREG, SImode,
	operand1,
	1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movstrsi (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  rtx operands[4];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;
  operands[3] = operand3;

{
  if (operands[0])		/* avoid unused code messages */
    {
      expand_block_move (operands);
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	gen_rtx (MEM, BLKmode,
	operand0),
	gen_rtx (MEM, BLKmode,
	operand1)),
		gen_rtx (USE, VOIDmode,
	operand2),
		gen_rtx (USE, VOIDmode,
	operand3))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movstrsi_internal (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (8,
		gen_rtx (SET, VOIDmode,
	operand0,
	operand1),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (USE, VOIDmode,
	operand2),
		gen_rtx (USE, VOIDmode,
	operand3),
		gen_rtx (USE, VOIDmode,
	const0_rtx)));
}

rtx
gen_split_105 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx operand5;
  rtx operand6;
  rtx operand7;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  operand5 = operands[5];
  operand6 = operands[6];
  operand7 = operands[7];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (8,
		gen_rtx (SET, VOIDmode,
	gen_rtx (MEM, BLKmode,
	operand0),
	gen_rtx (MEM, BLKmode,
	operand1)),
		gen_rtx (CLOBBER, VOIDmode,
	operand4),
		gen_rtx (CLOBBER, VOIDmode,
	operand5),
		gen_rtx (CLOBBER, VOIDmode,
	operand6),
		gen_rtx (CLOBBER, VOIDmode,
	operand7),
		gen_rtx (USE, VOIDmode,
	operand2),
		gen_rtx (USE, VOIDmode,
	operand3),
		gen_rtx (USE, VOIDmode,
	const1_rtx))));
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (8,
		gen_rtx (SET, VOIDmode,
	gen_rtx (MEM, BLKmode,
	operand0),
	gen_rtx (MEM, BLKmode,
	operand1)),
		gen_rtx (CLOBBER, VOIDmode,
	operand4),
		gen_rtx (CLOBBER, VOIDmode,
	operand5),
		gen_rtx (CLOBBER, VOIDmode,
	operand6),
		gen_rtx (CLOBBER, VOIDmode,
	operand7),
		gen_rtx (USE, VOIDmode,
	operand2),
		gen_rtx (USE, VOIDmode,
	operand3),
		gen_rtx (USE, VOIDmode,
	GEN_INT (2)))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_movstrsi_internal2 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (8,
		gen_rtx (SET, VOIDmode,
	operand0,
	operand1),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (USE, VOIDmode,
	operand2),
		gen_rtx (USE, VOIDmode,
	operand3),
		gen_rtx (USE, VOIDmode,
	const1_rtx)));
}

rtx
gen_movstrsi_internal3 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (8,
		gen_rtx (SET, VOIDmode,
	operand0,
	operand1),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0)),
		gen_rtx (USE, VOIDmode,
	operand2),
		gen_rtx (USE, VOIDmode,
	operand3),
		gen_rtx (USE, VOIDmode,
	GEN_INT (2))));
}

rtx
gen_ashlsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFT, SImode,
	operand1,
	operand2));
}

rtx
gen_ashldi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  rtx operand3;
  rtx operands[4];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;
operands[3] = gen_reg_rtx (SImode);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_ashldi3_internal (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_ashldi3_internal2 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_112 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	const0_rtx));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_113 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	const0_rtx));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_ashldi3_internal3 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_115 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();

{
  int amount = INTVAL (operands[2]);
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand4)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	operand3)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_116 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();

{
  int amount = INTVAL (operands[2]);
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand4)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	operand3)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_ashrsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFTRT, SImode,
	operand1,
	operand2));
}

rtx
gen_ashrdi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  rtx operand3;
  rtx operands[4];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;
operands[3] = gen_reg_rtx (SImode);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFTRT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_ashrdi3_internal (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFTRT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_ashrdi3_internal2 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFTRT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_121 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (ASHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (ASHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	GEN_INT (31))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_122 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (ASHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (ASHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	GEN_INT (31))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_ashrdi3_internal3 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (ASHIFTRT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_124 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();

{
  int amount = INTVAL (operands[2]);
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand4)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	operand3)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (ASHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_125 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();

{
  int amount = INTVAL (operands[2]);
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand4)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	operand3)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (ASHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_lshrsi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LSHIFTRT, SImode,
	operand1,
	operand2));
}

rtx
gen_lshrdi3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  rtx operand3;
  rtx operands[4];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;
operands[3] = gen_reg_rtx (SImode);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LSHIFTRT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_lshrdi3_internal (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LSHIFTRT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_lshrdi3_internal2 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LSHIFTRT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_130 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	const0_rtx));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_131 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();
operands[2] = gen_rtx (CONST_INT, VOIDmode, (XINT (operands[2], 0))& 0x1f);
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	const0_rtx));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_lshrdi3_internal3 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LSHIFTRT, DImode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_split_133 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();

{
  int amount = INTVAL (operands[2]);
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand4)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	operand3)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_split_134 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx operand3;
  rtx operand4;
  rtx _val = 0;
  start_sequence ();

{
  int amount = INTVAL (operands[2]);
  operands[2] = gen_rtx (CONST_INT, VOIDmode, (amount & 31));
  operands[4] = gen_rtx (CONST_INT, VOIDmode, ((-amount) & 31));
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  operand4 = operands[4];
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	1),
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand3,
	gen_rtx (ASHIFT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand4)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	gen_rtx (IOR, SImode,
	gen_rtx (SUBREG, SImode,
	operand0,
	1),
	operand3)));
  emit_insn (gen_rtx (SET, VOIDmode,
	gen_rtx (SUBREG, SImode,
	operand0,
	0),
	gen_rtx (LSHIFTRT, SImode,
	gen_rtx (SUBREG, SImode,
	operand1,
	0),
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_cmpsi (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if (operands[0])		/* avoid unused code message */
    {
      branch_cmp[0] = operands[0];
      branch_cmp[1] = operands[1];
      branch_type = CMP_SI;
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	cc0_rtx,
	gen_rtx (COMPARE, CCmode,
	operand0,
	operand1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_tstsi (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code message */
    {
      branch_cmp[0] = operands[0];
      branch_cmp[1] = const0_rtx;
      branch_type = CMP_SI;
      DONE;
    }
}
  operand0 = operands[0];
  emit_insn (gen_rtx (SET, VOIDmode,
	cc0_rtx,
	operand0));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_cmpdf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if (operands[0])		/* avoid unused code message */
    {
      branch_cmp[0] = operands[0];
      branch_cmp[1] = operands[1];
      branch_type = CMP_DF;
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	cc0_rtx,
	gen_rtx (COMPARE, CC_FPmode,
	operand0,
	operand1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_cmpsf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;

{
  if (operands[0])		/* avoid unused code message */
    {
      branch_cmp[0] = operands[0];
      branch_cmp[1] = operands[1];
      branch_type = CMP_SF;
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	cc0_rtx,
	gen_rtx (COMPARE, CC_FPmode,
	operand0,
	operand1)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_branch_fp_ne (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (NE, CC_FPmode,
	gen_rtx (REG, CC_FPmode,
	66),
	const0_rtx),
	operand0,
	operand1));
}

rtx
gen_branch_fp_ne_rev (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (NE, CC_REV_FPmode,
	gen_rtx (REG, CC_REV_FPmode,
	66),
	const0_rtx),
	operand0,
	operand1));
}

rtx
gen_branch_fp_eq (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (EQ, CC_FPmode,
	gen_rtx (REG, CC_FPmode,
	66),
	const0_rtx),
	operand0,
	operand1));
}

rtx
gen_branch_fp_eq_rev (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (EQ, CC_REV_FPmode,
	gen_rtx (REG, CC_REV_FPmode,
	66),
	const0_rtx),
	operand0,
	operand1));
}

rtx
gen_branch_zero (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (GET_CODE (operand0), SImode,
		operand1,
		const0_rtx),
	operand2,
	operand3));
}

rtx
gen_branch_equality (operand0, operand1, operand2, operand3, operand4)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
     rtx operand4;
{
  return gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (GET_CODE (operand0), SImode,
		operand1,
		operand2),
	operand3,
	operand4));
}

rtx
gen_beq (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, EQ);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (EQ, CC_EQmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_bne (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, NE);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (NE, CC_EQmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_bgt (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, GT);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (GT, CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_bge (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, GE);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (GE, CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_blt (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, LT);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (LT, CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_ble (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, LE);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (LE, CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_bgtu (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, GTU);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (GTU, CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_bgeu (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, GEU);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (GEU, CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_bltu (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, LTU);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (LTU, CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_bleu (operand0)
     rtx operand0;
{
  rtx operands[1];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (operands[0])		/* avoid unused code warning */
    {
      gen_conditional_branch (operands, LEU);
      DONE;
    }
}
  operand0 = operands[0];
  emit_jump_insn (gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (IF_THEN_ELSE, VOIDmode,
	gen_rtx (LEU, CCmode,
	cc0_rtx,
	const0_rtx),
	gen_rtx (LABEL_REF, VOIDmode,
	operand0),
	pc_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_seq (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (EQ, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) < 0)
    operands[2] = force_reg (SImode, operands[2]);

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (EQ, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_seq_si_zero (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (EQ, SImode,
	operand1,
	const0_rtx));
}

rtx
gen_seq_si (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (EQ, SImode,
	operand1,
	operand2));
}

rtx
gen_split_158 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (XOR, SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LTU, SImode,
	operand0,
	const1_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sne (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (NE, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) < 0)
    operands[2] = force_reg (SImode, operands[2]);

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NE, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sne_si_zero (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NE, SImode,
	operand1,
	const0_rtx));
}

rtx
gen_sne_si (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (NE, SImode,
	operand1,
	operand2));
}

rtx
gen_split_162 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (XOR, SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GTU, SImode,
	operand0,
	const0_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sgt (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (GT, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) != 0)
    operands[2] = force_reg (SImode, operands[2]);

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GT, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sgt_si (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GT, SImode,
	operand1,
	operand2));
}

rtx
gen_sge (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (GE, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GE, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sge_si (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GE, SImode,
	operand1,
	operand2));
}

rtx
gen_split_167 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LT, SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (XOR, SImode,
	operand0,
	const1_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_slt (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (LT, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LT, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_slt_si (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LT, SImode,
	operand1,
	operand2));
}

rtx
gen_sle (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (LE, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) >= 32767)
    operands[2] = force_reg (SImode, operands[2]);

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LE, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sle_si_const (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LE, SImode,
	operand1,
	operand2));
}

rtx
gen_sle_si_reg (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LE, SImode,
	operand1,
	operand2));
}

rtx
gen_split_173 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LT, SImode,
	operand2,
	operand1)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (XOR, SImode,
	operand0,
	const1_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sgtu (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (GTU, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) != 0)
    operands[2] = force_reg (SImode, operands[2]);

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GTU, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sgtu_si (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GTU, SImode,
	operand1,
	operand2));
}

rtx
gen_sgeu (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (GEU, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GEU, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sgeu_si (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (GEU, SImode,
	operand1,
	operand2));
}

rtx
gen_split_178 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LTU, SImode,
	operand1,
	operand2)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (XOR, SImode,
	operand0,
	const1_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sltu (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (LTU, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LTU, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sltu_si (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LTU, SImode,
	operand1,
	operand2));
}

rtx
gen_sleu (operand0)
     rtx operand0;
{
  rtx operand1;
  rtx operand2;
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;

{
  if (branch_type != CMP_SI)
    FAIL;

  /* set up operands from compare.  */
  operands[1] = branch_cmp[0];
  operands[2] = branch_cmp[1];

  if (!TARGET_DEBUG_C_MODE)
    {
      gen_int_relational (LEU, operands[0], operands[1], operands[2], (int *)0);
      DONE;
    }

  if (GET_CODE (operands[2]) == CONST_INT && INTVAL (operands[2]) >= 32767)
    operands[2] = force_reg (SImode, operands[2]);

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LEU, SImode,
	operand1,
	operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_sleu_si_const (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LEU, SImode,
	operand1,
	operand2));
}

rtx
gen_sleu_si_reg (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LEU, SImode,
	operand1,
	operand2));
}

rtx
gen_split_184 (operands)
     rtx *operands;
{
  rtx operand0;
  rtx operand1;
  rtx operand2;
  rtx _val = 0;
  start_sequence ();

  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (LTU, SImode,
	operand2,
	operand1)));
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (XOR, SImode,
	operand0,
	const1_rtx)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_seq_df (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (EQ, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_sne_df (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_REV_FPmode,
	66),
	gen_rtx (NE, CC_REV_FPmode,
	operand0,
	operand1));
}

rtx
gen_slt_df (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (LT, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_sle_df (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (LE, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_sgt_df (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (GT, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_sge_df (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (GE, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_seq_sf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (EQ, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_sne_sf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_REV_FPmode,
	66),
	gen_rtx (NE, CC_REV_FPmode,
	operand0,
	operand1));
}

rtx
gen_slt_sf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (LT, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_sle_sf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (LE, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_sgt_sf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (GT, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_sge_sf (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (SET, VOIDmode,
	gen_rtx (REG, CC_FPmode,
	66),
	gen_rtx (GE, CC_FPmode,
	operand0,
	operand1));
}

rtx
gen_jump (operand0)
     rtx operand0;
{
  return gen_rtx (SET, VOIDmode,
	pc_rtx,
	gen_rtx (LABEL_REF, VOIDmode,
	operand0));
}

rtx
gen_indirect_jump (operand0)
     rtx operand0;
{
  return gen_rtx (SET, VOIDmode,
	pc_rtx,
	operand0);
}

rtx
gen_tablejump (operand0, operand1)
     rtx operand0;
     rtx operand1;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	pc_rtx,
	operand0),
		gen_rtx (USE, VOIDmode,
	gen_rtx (LABEL_REF, VOIDmode,
	operand1))));
}

rtx
gen_return ()
{
  return gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (RETURN, VOIDmode),
		gen_rtx (USE, VOIDmode,
	gen_rtx (REG, SImode,
	31))));
}

rtx
gen_return_internal (operand0)
     rtx operand0;
{
  return gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (2,
		gen_rtx (RETURN, VOIDmode),
		gen_rtx (USE, VOIDmode,
	operand0)));
}

rtx
gen_prologue ()
{
  rtx _val = 0;
  start_sequence ();

{
  if (ss_isa >= 0)		/* avoid unused code warnings */
    {
      ss_expand_prologue ();
      DONE;
    }
}
  emit_insn (const1_rtx);
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_blockage ()
{
  return gen_rtx (UNSPEC_VOLATILE, VOIDmode,
	gen_rtvec (1,
		const0_rtx),
	0);
}

rtx
gen_call (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  rtx operands[4];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;
  operands[3] = operand3;

{
  rtx addr;

  if (operands[0])		/* eliminate unused code warnings */
    {
      addr = XEXP (operands[0], 0);
      if ((GET_CODE (addr) != REG && (!CONSTANT_ADDRESS_P (addr) || TARGET_LONG_CALLS))
	  || ! call_insn_operand (operands[0], VOIDmode))
	XEXP (operands[0], 0) = copy_to_mode_reg (Pmode, addr);

      /* In order to pass small structures by value in registers
	 compatibly with the SS compiler, we need to shift the value
	 into the high part of the register.  Function_arg has encoded
	 a PARALLEL rtx, holding a vector of adjustments to be made
	 as the next_arg_reg variable, so we split up the insns,
	 and emit them separately.  */

      if (operands[2] != (rtx)0 && GET_CODE (operands[2]) == PARALLEL)
	{
	  rtvec adjust = XVEC (operands[2], 0);
	  int num = GET_NUM_ELEM (adjust);
	  int i;

	  for (i = 0; i < num; i++)
	    emit_insn (RTVEC_ELT (adjust, i));
	}

      emit_call_insn (gen_call_internal1 (operands[0], operands[1],
					  gen_rtx (REG, Pmode, GP_REG_FIRST + 31)));
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_call_insn (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (4,
		gen_rtx (CALL, VOIDmode,
	operand0,
	operand1),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	31)),
		gen_rtx (USE, VOIDmode,
	operand2),
		gen_rtx (USE, VOIDmode,
	operand3))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_call_internal1 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (CALL, VOIDmode,
	operand0,
	operand1),
		gen_rtx (CLOBBER, VOIDmode,
	operand2)));
}

rtx
gen_call_internal2 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (CALL, VOIDmode,
	operand0,
	operand1),
		gen_rtx (CLOBBER, VOIDmode,
	operand2)));
}

rtx
gen_call_internal3 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (CALL, VOIDmode,
	gen_rtx (MEM, SImode,
	operand0),
	operand1),
		gen_rtx (CLOBBER, VOIDmode,
	operand2)));
}

rtx
gen_call_internal4 (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (CALL, VOIDmode,
	gen_rtx (MEM, SImode,
	operand0),
	operand1),
		gen_rtx (CLOBBER, VOIDmode,
	operand2)));
}

rtx
gen_call_value (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  rtx operands[4];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;
  operands[3] = operand3;

{
  rtx addr;

  if (operands[0])		/* eliminate unused code warning */
    {
      addr = XEXP (operands[1], 0);
      if ((GET_CODE (addr) != REG && (!CONSTANT_ADDRESS_P (addr) || TARGET_LONG_CALLS))
	  || ! call_insn_operand (operands[1], VOIDmode))
	XEXP (operands[1], 0) = copy_to_mode_reg (Pmode, addr);

      /* In order to pass small structures by value in registers
	 compatibly with the SS compiler, we need to shift the value
	 into the high part of the register.  Function_arg has encoded
	 a PARALLEL rtx, holding a vector of adjustments to be made
	 as the next_arg_reg variable, so we split up the insns,
	 and emit them separately.  */

      if (operands[3] != (rtx)0 && GET_CODE (operands[3]) == PARALLEL)
	{
	  rtvec adjust = XVEC (operands[3], 0);
	  int num = GET_NUM_ELEM (adjust);
	  int i;

	  for (i = 0; i < num; i++)
	    emit_insn (RTVEC_ELT (adjust, i));
	}

      emit_call_insn (gen_call_value_internal1 (operands[0], operands[1], operands[2],
					        gen_rtx (REG, Pmode, GP_REG_FIRST + 31)));

      DONE;
    }

}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  operand3 = operands[3];
  emit_call_insn (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (3,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (CALL, VOIDmode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	31)),
		gen_rtx (USE, VOIDmode,
	operand3))));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_call_value_internal1 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (CALL, VOIDmode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_call_value_internal2 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (CALL, VOIDmode,
	operand1,
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_call_value_internal3 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (CALL, VOIDmode,
	gen_rtx (MEM, SImode,
	operand1),
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_call_value_internal4 (operand0, operand1, operand2, operand3)
     rtx operand0;
     rtx operand1;
     rtx operand2;
     rtx operand3;
{
  return gen_rtx (PARALLEL, VOIDmode, gen_rtvec (2,
		gen_rtx (SET, VOIDmode,
	operand0,
	gen_rtx (CALL, VOIDmode,
	gen_rtx (MEM, SImode,
	operand1),
	operand2)),
		gen_rtx (CLOBBER, VOIDmode,
	operand3)));
}

rtx
gen_untyped_call (operand0, operand1, operand2)
     rtx operand0;
     rtx operand1;
     rtx operand2;
{
  rtx operands[3];
  rtx _val = 0;
  start_sequence ();
  operands[0] = operand0;
  operands[1] = operand1;
  operands[2] = operand2;

{
  if (operands[0])		/* silence statement not reached warnings */
    {
      int i;

      emit_call_insn (gen_call (operands[0], const0_rtx, NULL, const0_rtx));

      for (i = 0; i < XVECLEN (operands[2], 0); i++)
	{
	  rtx set = XVECEXP (operands[2], 0, i);
	  emit_move_insn (SET_DEST (set), SET_SRC (set));
	}

      emit_insn (gen_blockage ());
      DONE;
    }
}
  operand0 = operands[0];
  operand1 = operands[1];
  operand2 = operands[2];
  emit_call_insn (gen_rtx (PARALLEL, VOIDmode,
	gen_rtvec (3,
		gen_rtx (CALL, VOIDmode,
	operand0,
	const0_rtx),
		operand1,
		operand2)));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}

rtx
gen_nop ()
{
  return const0_rtx;
}

rtx
gen_probe ()
{
  rtx operand0;
  rtx operand1;
  rtx operands[2];
  rtx _val = 0;
  start_sequence ();

{
  operands[0] = gen_reg_rtx (SImode);
  operands[1] = gen_rtx (MEM, SImode, stack_pointer_rtx);
  MEM_VOLATILE_P (operands[1]) = TRUE;

  /* fall through and generate default code */
}
  operand0 = operands[0];
  operand1 = operands[1];
  emit_insn (gen_rtx (SET, VOIDmode,
	operand0,
	operand1));
 _done:
  _val = gen_sequence ();
 _fail:
  end_sequence ();
  return _val;
}



void
add_clobbers (pattern, insn_code_number)
     rtx pattern;
     int insn_code_number;
{
  int i;

  switch (insn_code_number)
    {
    case 75:
      XVECEXP (pattern, 0, 1) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0));
      XVECEXP (pattern, 0, 2) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SFmode, 0));
      break;

    case 74:
      XVECEXP (pattern, 0, 1) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0));
      XVECEXP (pattern, 0, 2) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, DFmode, 0));
      break;

    case 42:
      XVECEXP (pattern, 0, 1) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0));
      XVECEXP (pattern, 0, 2) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (SCRATCH, SImode, 0));
      break;

    case 32:
    case 31:
      XVECEXP (pattern, 0, 2) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64));
      XVECEXP (pattern, 0, 3) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65));
      break;

    case 28:
    case 27:
      XVECEXP (pattern, 0, 1) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, DImode,
	64));
      break;

    case 26:
      XVECEXP (pattern, 0, 1) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64));
      break;

    case 36:
    case 35:
    case 34:
    case 33:
    case 24:
      XVECEXP (pattern, 0, 1) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	64));
      XVECEXP (pattern, 0, 2) = gen_rtx (CLOBBER, VOIDmode,
	gen_rtx (REG, SImode,
	65));
      break;

    default:
      abort ();
    }
}

void
init_mov_optab ()
{
#ifdef HAVE_movcc_eq
  if (HAVE_movcc_eq)
    mov_optab->handlers[(int) CC_EQmode].insn_code = CODE_FOR_movcc_eq;
#endif
#ifdef HAVE_movcc_fp
  if (HAVE_movcc_fp)
    mov_optab->handlers[(int) CC_FPmode].insn_code = CODE_FOR_movcc_fp;
#endif
#ifdef HAVE_movcc_0
  if (HAVE_movcc_0)
    mov_optab->handlers[(int) CC_0mode].insn_code = CODE_FOR_movcc_0;
#endif
#ifdef HAVE_movcc_rev_fp
  if (HAVE_movcc_rev_fp)
    mov_optab->handlers[(int) CC_REV_FPmode].insn_code = CODE_FOR_movcc_rev_fp;
#endif
}
