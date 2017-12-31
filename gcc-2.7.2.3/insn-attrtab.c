/* Generated automatically by the program `genattrtab'
from the machine description file `md'.  */

#include "config.h"
#include "rtl.h"
#include "insn-config.h"
#include "recog.h"
#include "regs.h"
#include "real.h"
#include "output.h"
#include "insn-attr.h"

#define operands recog_operand

int
insn_current_length (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 0;

    }
}

int
insn_variable_length_p (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 0;

    }
}

int
insn_default_length (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 101:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 0) || (which_alternative == 1))
        {
	  return 2;
        }
      else if (which_alternative == 2)
        {
	  return 4;
        }
      else if (which_alternative == 3)
        {
	  return 2;
        }
      else
        {
	  return 4;
        }

    case 100:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 1;
        }
      else if (which_alternative == 1)
        {
	  return 2;
        }
      else if (which_alternative == 2)
        {
	  return 4;
        }
      else if (which_alternative == 3)
        {
	  return 2;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return 4;
        }
      else if ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 8) || (which_alternative == 9))))
        {
	  return 2;
        }
      else if (which_alternative == 10)
        {
	  return 4;
        }
      else if (which_alternative == 11)
        {
	  return 2;
        }
      else
        {
	  return 4;
        }

    case 98:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 0) || (which_alternative == 1))
        {
	  return 1;
        }
      else if (which_alternative == 2)
        {
	  return 2;
        }
      else if (which_alternative == 3)
        {
	  return 1;
        }
      else
        {
	  return 2;
        }

    case 97:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 0) || ((which_alternative == 1) || (which_alternative == 2)))
        {
	  return 1;
        }
      else if (which_alternative == 3)
        {
	  return 2;
        }
      else if (which_alternative == 4)
        {
	  return 1;
        }
      else if (which_alternative == 5)
        {
	  return 2;
        }
      else if ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 8) || (which_alternative == 9))))
        {
	  return 1;
        }
      else if (which_alternative == 10)
        {
	  return 2;
        }
      else if (which_alternative == 11)
        {
	  return 1;
        }
      else
        {
	  return 2;
        }

    case 95:
    case 92:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 0) || ((which_alternative == 1) || (which_alternative == 2)))
        {
	  return 1;
        }
      else if (which_alternative == 3)
        {
	  return 2;
        }
      else if (which_alternative == 4)
        {
	  return 1;
        }
      else if (which_alternative == 5)
        {
	  return 2;
        }
      else if ((which_alternative == 6) || ((which_alternative == 7) || (which_alternative == 8)))
        {
	  return 1;
        }
      else
        {
	  return 1;
        }

    case 94:
    case 91:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 0) || ((which_alternative == 1) || (which_alternative == 2)))
        {
	  return 1;
        }
      else if (which_alternative == 3)
        {
	  return 2;
        }
      else if (which_alternative == 4)
        {
	  return 1;
        }
      else if (which_alternative == 5)
        {
	  return 2;
        }
      else if ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 8) || (which_alternative == 9))))
        {
	  return 1;
        }
      else
        {
	  return 1;
        }

    case 89:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 1;
        }
      else if (which_alternative == 1)
        {
	  return 2;
        }
      else if (which_alternative == 2)
        {
	  return 1;
        }
      else if (which_alternative == 3)
        {
	  return 2;
        }
      else if (which_alternative == 4)
        {
	  return 1;
        }
      else if (which_alternative == 5)
        {
	  return 2;
        }
      else if (which_alternative == 6)
        {
	  return 1;
        }
      else if (which_alternative == 7)
        {
	  return 2;
        }
      else if ((which_alternative == 8) || ((which_alternative == 9) || (which_alternative == 10)))
        {
	  return 1;
        }
      else
        {
	  return 1;
        }

    case 88:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 1;
        }
      else if (which_alternative == 1)
        {
	  return 2;
        }
      else if (which_alternative == 2)
        {
	  return 1;
        }
      else if (which_alternative == 3)
        {
	  return 2;
        }
      else if (which_alternative == 4)
        {
	  return 1;
        }
      else if (which_alternative == 5)
        {
	  return 2;
        }
      else if (which_alternative == 6)
        {
	  return 1;
        }
      else if (which_alternative == 7)
        {
	  return 2;
        }
      else if ((which_alternative == 8) || ((which_alternative == 9) || ((which_alternative == 10) || (which_alternative == 11))))
        {
	  return 1;
        }
      else if (which_alternative == 12)
        {
	  return 2;
        }
      else if (which_alternative == 13)
        {
	  return 1;
        }
      else if (which_alternative == 14)
        {
	  return 2;
        }
      else if (which_alternative == 15)
        {
	  return 1;
        }
      else
        {
	  return 1;
        }

    case 66:
    case 65:
    case 64:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative != 2)
        {
	  return 1;
        }
      else
        {
	  return 2;
        }

    case 213:
    case 211:
    case 208:
    case 206:
    case 183:
    case 177:
    case 172:
    case 166:
    case 161:
    case 157:
    case 129:
    case 120:
    case 111:
    case 61:
    case 58:
    case 55:
    case 52:
    case 49:
      return 2;

    case 203:
      return 0;

    case 132:
    case 123:
    case 114:
    case 45:
    case 28:
    case 27:
    case 16:
    case 5:
      return 4;

    case 128:
    case 119:
    case 110:
      return 12 /* 0xc */;

    case 106:
    case 104:
      return 20 /* 0x14 */;

    case 84:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 2;
        }
      else if (which_alternative == 1)
        {
	  return 4;
        }
      else if (which_alternative == 2)
        {
	  return 2;
        }
      else if (which_alternative == 3)
        {
	  return 4;
        }
      else if (which_alternative == 4)
        {
	  return 2;
        }
      else if (which_alternative == 5)
        {
	  return 4;
        }
      else if (which_alternative == 6)
        {
	  return 2;
        }
      else
        {
	  return 2;
        }

    case 82:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 2;
        }
      else
        {
	  return 4;
        }

    case 81:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 2;
        }
      else if (which_alternative == 1)
        {
	  return 4;
        }
      else if (which_alternative == 2)
        {
	  return 1;
        }
      else
        {
	  return 2;
        }

    case 77:
    case 76:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 3;
        }
      else if (which_alternative == 1)
        {
	  return 4;
        }
      else
        {
	  return 3;
        }

    case 75:
    case 74:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 11 /* 0xb */;
        }
      else if (which_alternative == 1)
        {
	  return 9;
        }
      else if (which_alternative == 2)
        {
	  return 10 /* 0xa */;
        }
      else
        {
	  return 11 /* 0xb */;
        }

    case 72:
    case 70:
    case 68:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 1;
        }
      else
        {
	  return 2;
        }

    case 42:
      return 6;

    case 39:
    case 24:
      return 3;

    case 36:
    case 35:
    case 34:
      return 14 /* 0xe */;

    case 33:
    case 32:
    case 31:
      return 13 /* 0xd */;

    case 19:
    case 8:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return 3;
        }
      else if (which_alternative == 1)
        {
	  return 2;
        }
      else
        {
	  return 4;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 1;

    }
}

int
result_ready_cost (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 196:
    case 195:
    case 194:
    case 193:
    case 192:
    case 191:
    case 190:
    case 189:
    case 188:
    case 187:
    case 186:
    case 185:
      return 2;

    case 100:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 3;
        }
      else if ((((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 6) || (which_alternative == 7)))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 101:
    case 98:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || (which_alternative == 2)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 3;
        }
      else if (((which_alternative == 1) || (which_alternative == 2)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 97:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 3;
        }
      else if ((((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 1) || ((which_alternative == 6) || (which_alternative == 7))))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 95:
    case 92:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && (which_alternative != 7)))))))))
        {
	  return 3;
        }
      else if ((((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 6) || (which_alternative == 7)))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 94:
    case 91:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && (which_alternative != 8))))))))))
        {
	  return 3;
        }
      else if ((((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 6) || (which_alternative == 7)))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 89:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && ((which_alternative != 8) && (which_alternative != 9)))))))))))
        {
	  return 3;
        }
      else if ((((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 8) || (which_alternative == 9)))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 88:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && ((which_alternative != 8) && ((which_alternative != 9) && ((which_alternative != 10) && ((which_alternative != 11) && ((which_alternative != 12) && ((which_alternative != 13) && (which_alternative != 14))))))))))))))))
        {
	  return 3;
        }
      else if ((((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 8) || (which_alternative == 9)))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 84:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && (which_alternative != 5)))))))
        {
	  return 3;
        }
      else if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 81:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 0) || (which_alternative == 1)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 3;
        }
      else if (((which_alternative == 0) || (which_alternative == 1)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 72:
    case 70:
    case 68:
      if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 3;
        }
      else
        {
	  return 2;
        }

    case 66:
    case 65:
    case 64:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative != 0) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 3;
        }
      else if ((which_alternative != 0) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 47:
    case 46:
    case 41:
    case 40:
    case 38:
    case 37:
      if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else
        {
	  return 1;
        }

    case 36:
    case 35:
    case 34:
    case 33:
    case 32:
    case 31:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000))))))
        {
	  return 69 /* 0x45 */;
        }
      else if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 38 /* 0x26 */;
        }
      else
        {
	  return 35 /* 0x23 */;
        }

    case 30:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  return 23 /* 0x17 */;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 15 /* 0xf */;
        }
      else
        {
	  return 12 /* 0xc */;
        }

    case 29:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  return 36 /* 0x24 */;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 19 /* 0x13 */;
        }
      else
        {
	  return 16 /* 0x10 */;
        }

    case 28:
    case 27:
    case 26:
    case 24:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000))))))))
        {
	  return 17 /* 0x11 */;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 12 /* 0xc */;
        }
      else
        {
	  return 10 /* 0xa */;
        }

    case 23:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  return 7;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 5;
        }
      else
        {
	  return 4;
        }

    case 22:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  return 8;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 6;
        }
      else
        {
	  return 5;
        }

    case 12:
    case 11:
    case 1:
    case 0:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  return 4;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 3;
        }
      else
        {
	  return 2;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 1;

    }
}

int
divide_unit_ready_cost (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 30:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 15 /* 0xf */;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 12 /* 0xc */;
        }
      else
        {
	  return 23 /* 0x17 */;
        }

    case 29:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 16 /* 0x10 */;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 19 /* 0x13 */;
        }
      else
        {
	  return 36 /* 0x24 */;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 112 /* 0x70 */;

    }
}

unsigned int
divide_unit_blockage_range (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 786544 /* 0xc0070 */;

    }
}

int
mult_unit_ready_cost (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 23:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 5;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 4;
        }
      else
        {
	  return 7;
        }

    case 22:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 6;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 5;
        }
      else
        {
	  return 8;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 8;

    }
}

unsigned int
mult_unit_blockage_range (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 262152 /* 0x40008 */;

    }
}

int
adder_unit_ready_cost (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 47:
    case 46:
    case 41:
    case 40:
    case 38:
    case 37:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 1;
        }
      else
        {
	  return 2;
        }

    case 12:
    case 11:
    case 1:
    case 0:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))
        {
	  return 3;
        }
      else if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 4;
        }
      else
        {
	  return 2;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 4;

    }
}

unsigned int
adder_unit_blockage_range (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 65540 /* 0x10004 */;

    }
}

int
imuldiv_unit_ready_cost (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 36:
    case 35:
    case 34:
    case 33:
    case 32:
    case 31:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 35 /* 0x23 */;
        }
      else if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  return 38 /* 0x26 */;
        }
      else
        {
	  return 69 /* 0x45 */;
        }

    case 28:
    case 27:
    case 26:
    case 24:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000))))))
        {
	  return 10 /* 0xa */;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 12 /* 0xc */;
        }
      else
        {
	  return 17 /* 0x11 */;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 69 /* 0x45 */;

    }
}

unsigned int
imuldiv_unit_blockage_range (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 655429 /* 0xa0045 */;

    }
}

int
addr_unit_ready_cost (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 2;

    }
}

int
memory_unit_ready_cost (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 100:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 6) || (which_alternative == 7)))
        {
	  return 2;
        }
      else if ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 11) || (which_alternative == 12))))
        {
	  return 1;
        }
      else
        {
	  return 3;
        }

    case 101:
    case 98:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || (which_alternative == 2)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else if ((which_alternative != 0) && ((which_alternative != 1) && (which_alternative != 2)))
        {
	  return 1;
        }
      else
        {
	  return 3;
        }

    case 97:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 1) || ((which_alternative == 6) || (which_alternative == 7))))
        {
	  return 2;
        }
      else if ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))
        {
	  return 1;
        }
      else
        {
	  return 3;
        }

    case 95:
    case 94:
    case 92:
    case 91:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 6) || (which_alternative == 7)))
        {
	  return 2;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return 1;
        }
      else
        {
	  return 3;
        }

    case 89:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 8) || (which_alternative == 9)))
        {
	  return 2;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return 1;
        }
      else
        {
	  return 3;
        }

    case 88:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) || ((which_alternative == 8) || (which_alternative == 9)))
        {
	  return 2;
        }
      else if ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 13) || (which_alternative == 14))))
        {
	  return 1;
        }
      else
        {
	  return 3;
        }

    case 84:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return 1;
        }
      else
        {
	  return 3;
        }

    case 107:
    case 82:
      return 1;

    case 81:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 0) || (which_alternative == 1)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else
        {
	  return 3;
        }

    case 72:
    case 70:
    case 68:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 2;
        }
      else
        {
	  return 3;
        }

    case 66:
    case 65:
    case 64:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative != 0) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 2;
        }
      else
        {
	  return 3;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 3;

    }
}

unsigned int
memory_unit_blockage_range (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 100:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return 65538 /* 0x10002 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 101:
    case 98:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || (which_alternative == 2)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if (((which_alternative == 1) || (which_alternative == 2)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 97:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else if ((which_alternative == 1) || ((which_alternative == 6) || (which_alternative == 7)))
        {
	  return 65538 /* 0x10002 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 95:
    case 92:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if (((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return 65538 /* 0x10002 */;
        }
      else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && (which_alternative != 5))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 94:
    case 91:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if (((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return 65538 /* 0x10002 */;
        }
      else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && (which_alternative != 8)))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 89:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else if ((which_alternative == 8) || (which_alternative == 9))
        {
	  return 65538 /* 0x10002 */;
        }
      else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && (which_alternative != 7))))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 88:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else if ((which_alternative == 8) || (which_alternative == 9))
        {
	  return 65538 /* 0x10002 */;
        }
      else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && ((which_alternative != 10) && ((which_alternative != 11) && ((which_alternative != 12) && ((which_alternative != 13) && (which_alternative != 14)))))))))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 84:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if ((((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && (which_alternative != 5)))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 81:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 0) || (which_alternative == 1)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if (((which_alternative == 0) || (which_alternative == 1)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case 72:
    case 70:
    case 68:
      if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  return 65538 /* 0x10002 */;
        }
      else
        {
	  return 65537 /* 0x10001 */;
        }

    case 66:
    case 65:
    case 64:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative != 0) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  return 65538 /* 0x10002 */;
        }
      else if ((which_alternative != 0) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  return 65537 /* 0x10001 */;
        }
      else
        {
	  return 65539 /* 0x10003 */;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return 65539 /* 0x10003 */;

    }
}

int
function_units_used (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 196:
    case 195:
    case 194:
    case 193:
    case 192:
    case 191:
    case 190:
    case 189:
    case 188:
    case 187:
    case 186:
    case 185:
      if ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))) || (((ss_cpu_attr) == (CPU_DEFAULT))))))
        {
	  return 1;
        }
      else
        {
	  return 0;
        }

    case 100:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative != 6) && (which_alternative != 7)) && (((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 11) && (which_alternative != 12)))) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 5) && ((which_alternative != 9) && (which_alternative != 10))))))) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 101:
    case 98:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 0) || ((which_alternative == 1) || (which_alternative == 2))) && ((which_alternative != 1) && (which_alternative != 2))) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 97:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative != 1) && ((which_alternative != 6) && (which_alternative != 7))) && (((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 11) && (which_alternative != 12)))) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 9) && (which_alternative != 10)))))) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 95:
    case 92:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 6) || (which_alternative == 7)))))))) && (((which_alternative != 6) && (which_alternative != 7)) && (((which_alternative != 4) && (which_alternative != 5)) && ((which_alternative != 2) && (which_alternative != 3))))) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 94:
    case 91:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 6) || ((which_alternative == 7) || (which_alternative == 8))))))))) && (((which_alternative != 6) && (which_alternative != 7)) && (((which_alternative != 4) && (which_alternative != 5)) && ((which_alternative != 2) && (which_alternative != 3))))) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 89:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 8) || (which_alternative == 9)))))))))) && (((which_alternative != 8) && (which_alternative != 9)) && (((which_alternative != 6) && (which_alternative != 7)) && ((which_alternative != 1) && ((which_alternative != 4) && (which_alternative != 5)))))) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 88:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 8) || ((which_alternative == 9) || ((which_alternative == 10) || ((which_alternative == 11) || ((which_alternative == 12) || ((which_alternative == 13) || (which_alternative == 14))))))))))))))) && (((which_alternative != 8) && (which_alternative != 9)) && (((which_alternative != 6) && ((which_alternative != 7) && ((which_alternative != 13) && (which_alternative != 14)))) && ((which_alternative != 1) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 11) && (which_alternative != 12)))))))) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 84:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || (which_alternative == 5)))))) && (((which_alternative != 4) && (which_alternative != 5)) && ((which_alternative != 2) && (which_alternative != 3)))) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 81:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative != 0) && (which_alternative != 1)) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 107:
    case 82:
    case 72:
    case 70:
    case 68:
      return 0;

    case 66:
    case 65:
    case 64:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 0) && (((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))))) || (((ss_cpu_attr) == (CPU_DEFAULT)))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    case 30:
    case 29:
      if ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))) || (((ss_cpu_attr) == (CPU_DEFAULT))))))
        {
	  return 5;
        }
      else
        {
	  return 0;
        }

    case 36:
    case 35:
    case 34:
    case 33:
    case 32:
    case 31:
    case 28:
    case 27:
    case 26:
    case 24:
      if ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))) || (((ss_cpu_attr) == (CPU_DEFAULT))))))
        {
	  return 2;
        }
      else
        {
	  return 0;
        }

    case 23:
    case 22:
      if ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))) || (((ss_cpu_attr) == (CPU_DEFAULT))))))
        {
	  return 4;
        }
      else
        {
	  return 0;
        }

    case 47:
    case 46:
    case 41:
    case 40:
    case 38:
    case 37:
    case 12:
    case 11:
    case 1:
    case 0:
      if ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))) || (((ss_cpu_attr) == (CPU_DEFAULT))))))
        {
	  return 3;
        }
      else
        {
	  return 0;
        }

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      if ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000)))))) || ((((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000))))) || (((ss_cpu_attr) == (CPU_DEFAULT))))))
        {
	  return -1 /* 0xffffffff */;
        }
      else
        {
	  return 0;
        }

    }
}

enum attr_abicalls
get_attr_abicalls ()
{
}

enum attr_branch_likely
get_attr_branch_likely ()
{
}

enum attr_cpu
get_attr_cpu ()
{
}

enum attr_dslot
get_attr_dslot (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 100:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) || ((which_alternative == 6) || (which_alternative == 7)))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 101:
    case 98:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 1) || (which_alternative == 2))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 97:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) || ((which_alternative == 1) || ((which_alternative == 6) || (which_alternative == 7))))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 95:
    case 92:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) || (((which_alternative == 6) || (which_alternative == 7)) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && (which_alternative != 7))))))))))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 94:
    case 91:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) || (((which_alternative == 6) || (which_alternative == 7)) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && (which_alternative != 8)))))))))))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 89:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) || (((which_alternative == 8) || (which_alternative == 9)) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && ((which_alternative != 8) && (which_alternative != 9))))))))))))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 88:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) || (((which_alternative == 8) || (which_alternative == 9)) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && ((which_alternative != 8) && ((which_alternative != 9) && ((which_alternative != 10) && ((which_alternative != 11) && ((which_alternative != 12) && ((which_alternative != 13) && (which_alternative != 14)))))))))))))))))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 84:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && (which_alternative != 5)))))))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 81:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 0) || (which_alternative == 1))
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 66:
    case 65:
    case 64:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative != 0)
        {
	  return DSLOT_YES;
        }
      else
        {
	  return DSLOT_NO;
        }

    case 213:
    case 212:
    case 211:
    case 210:
    case 208:
    case 207:
    case 206:
    case 205:
    case 201:
    case 199:
    case 198:
    case 197:
    case 196:
    case 195:
    case 194:
    case 193:
    case 192:
    case 191:
    case 190:
    case 189:
    case 188:
    case 187:
    case 186:
    case 185:
    case 144:
    case 143:
    case 142:
    case 141:
    case 140:
    case 139:
    case 72:
    case 70:
    case 68:
      return DSLOT_YES;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      return DSLOT_NO;

    }
}

enum attr_mode
get_attr_mode (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 185:
    case 186:
    case 187:
    case 188:
    case 189:
    case 190:
    case 191:
    case 192:
    case 193:
    case 194:
    case 195:
    case 196:
      return MODE_FPSW;

    case 0:
    case 11:
    case 22:
    case 29:
    case 37:
    case 40:
    case 46:
    case 73:
    case 74:
    case 76:
    case 100:
    case 101:
      return MODE_DF;

    case 1:
    case 12:
    case 23:
    case 30:
    case 38:
    case 41:
    case 47:
    case 63:
    case 75:
    case 77:
    case 97:
    case 98:
      return MODE_SF;

    case 5:
    case 8:
    case 16:
    case 19:
    case 45:
    case 49:
    case 52:
    case 55:
    case 58:
    case 61:
    case 84:
    case 111:
    case 114:
    case 119:
    case 120:
    case 123:
    case 128:
    case 129:
    case 132:
      return MODE_DI;

    case 65:
    case 91:
    case 92:
      return MODE_HI;

    case 94:
    case 95:
      return MODE_QI;

    case 104:
    case 106:
    case 107:
    case 139:
    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
    case 197:
    case 198:
    case 199:
    case 201:
    case 203:
    case 205:
    case 206:
    case 207:
    case 208:
    case 210:
    case 211:
    case 212:
    case 213:
    case 215:
      return MODE_NONE;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
      return MODE_UNKNOWN;

    default:
      return MODE_SI;

    }
}

enum attr_type
get_attr_type (insn)
     rtx insn;
{
  switch (recog_memoized (insn))
    {
    case 100:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else if ((which_alternative == 1) || (which_alternative == 2))
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 3) || (which_alternative == 4))
        {
	  return TYPE_STORE;
        }
      else if (which_alternative == 5)
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return TYPE_XFER;
        }
      else if (which_alternative == 8)
        {
	  return TYPE_MOVE;
        }
      else if ((which_alternative == 9) || (which_alternative == 10))
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 11)
        {
	  return TYPE_STORE;
        }
      else
        {
	  return TYPE_STORE;
        }

    case 101:
    case 98:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else if ((which_alternative == 1) || (which_alternative == 2))
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 3)
        {
	  return TYPE_STORE;
        }
      else
        {
	  return TYPE_STORE;
        }

    case 97:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return TYPE_XFER;
        }
      else if ((which_alternative == 2) || (which_alternative == 3))
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return TYPE_STORE;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return TYPE_XFER;
        }
      else if (which_alternative == 8)
        {
	  return TYPE_MOVE;
        }
      else if ((which_alternative == 9) || (which_alternative == 10))
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 11)
        {
	  return TYPE_STORE;
        }
      else
        {
	  return TYPE_STORE;
        }

    case 95:
    case 92:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return TYPE_ARITH;
        }
      else if ((which_alternative == 2) || (which_alternative == 3))
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return TYPE_STORE;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return TYPE_XFER;
        }
      else
        {
	  return TYPE_HILO;
        }

    case 94:
    case 91:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return TYPE_ARITH;
        }
      else if ((which_alternative == 2) || (which_alternative == 3))
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return TYPE_STORE;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return TYPE_XFER;
        }
      else if (which_alternative == 8)
        {
	  return TYPE_MOVE;
        }
      else
        {
	  return TYPE_HILO;
        }

    case 89:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 2) || (which_alternative == 3))
        {
	  return TYPE_ARITH;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return TYPE_STORE;
        }
      else if ((which_alternative == 8) || (which_alternative == 9))
        {
	  return TYPE_XFER;
        }
      else
        {
	  return TYPE_HILO;
        }

    case 88:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 2) || (which_alternative == 3))
        {
	  return TYPE_ARITH;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  return TYPE_STORE;
        }
      else if ((which_alternative == 8) || (which_alternative == 9))
        {
	  return TYPE_XFER;
        }
      else if (which_alternative == 10)
        {
	  return TYPE_MOVE;
        }
      else if ((which_alternative == 11) || (which_alternative == 12))
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 13) || (which_alternative == 14))
        {
	  return TYPE_STORE;
        }
      else
        {
	  return TYPE_HILO;
        }

    case 84:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_MOVE;
        }
      else if (which_alternative == 1)
        {
	  return TYPE_ARITH;
        }
      else if ((which_alternative == 2) || (which_alternative == 3))
        {
	  return TYPE_LOAD;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  return TYPE_STORE;
        }
      else
        {
	  return TYPE_HILO;
        }

    case 81:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if ((which_alternative == 0) || (which_alternative == 1))
        {
	  return TYPE_LOAD;
        }
      else if (which_alternative == 2)
        {
	  return TYPE_MOVE;
        }
      else
        {
	  return TYPE_ARITH;
        }

    case 66:
    case 65:
    case 64:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (which_alternative == 0)
        {
	  return TYPE_ARITH;
        }
      else
        {
	  return TYPE_LOAD;
        }

    case 215:
      return TYPE_NOP;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    case 39:
    case 42:
    case 104:
    case 106:
      return TYPE_MULTI;

    case 63:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
      return TYPE_FCVT;

    case 185:
    case 186:
    case 187:
    case 188:
    case 189:
    case 190:
    case 191:
    case 192:
    case 193:
    case 194:
    case 195:
    case 196:
      return TYPE_FCMP;

    case 46:
    case 47:
      return TYPE_FNEG;

    case 37:
    case 38:
    case 40:
    case 41:
      return TYPE_FABS;

    case 29:
    case 30:
      return TYPE_FDIV;

    case 22:
    case 23:
      return TYPE_FMUL;

    case 0:
    case 1:
    case 11:
    case 12:
      return TYPE_FADD;

    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
      return TYPE_IDIV;

    case 24:
    case 26:
    case 27:
    case 28:
      return TYPE_IMUL;

    case 5:
    case 8:
    case 16:
    case 19:
    case 45:
    case 49:
    case 52:
    case 55:
    case 58:
    case 61:
    case 110:
    case 111:
    case 114:
    case 119:
    case 120:
    case 123:
    case 128:
    case 129:
    case 132:
      return TYPE_DARITH;

    case 82:
    case 107:
      return TYPE_STORE;

    case 68:
    case 70:
    case 72:
      return TYPE_LOAD;

    case 205:
    case 206:
    case 207:
    case 208:
    case 210:
    case 211:
    case 212:
    case 213:
      return TYPE_CALL;

    case 197:
    case 198:
    case 199:
    case 201:
      return TYPE_JUMP;

    case 139:
    case 140:
    case 141:
    case 142:
    case 143:
    case 144:
      return TYPE_BRANCH;

    case 203:
      return TYPE_UNKNOWN;

    default:
      return TYPE_ARITH;

    }
}

static int
divide_unit_blockage (executing_insn, candidate_insn)
     rtx executing_insn;
     rtx candidate_insn;
{
  rtx insn;
  int casenum;

  insn = executing_insn;
  switch (recog_memoized (insn))
    {
    case 30:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  casenum = 0;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  casenum = 1;
        }
      else
        {
	  casenum = 2;
        }
      break;

    case 29:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  casenum = 3;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  casenum = 4;
        }
      else
        {
	  casenum = 5;
        }
      break;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      casenum = 7;
      break;

    }

  insn = candidate_insn;
  switch (casenum)
    {
    case 0:
      return 23 /* 0x17 */;

    case 1:
      return 12 /* 0xc */;

    case 2:
      return 15 /* 0xf */;

    case 3:
      return 36 /* 0x24 */;

    case 4:
      return 19 /* 0x13 */;

    case 5:
      return 16 /* 0x10 */;

    case 7:
      return 112 /* 0x70 */;

    }
}

static int
mult_unit_blockage (executing_insn, candidate_insn)
     rtx executing_insn;
     rtx candidate_insn;
{
  rtx insn;
  int casenum;

  insn = executing_insn;
  switch (recog_memoized (insn))
    {
    case 23:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  casenum = 0;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  casenum = 1;
        }
      else
        {
	  casenum = 2;
        }
      break;

    case 22:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  casenum = 3;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  casenum = 4;
        }
      else
        {
	  casenum = 5;
        }
      break;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      casenum = 5;
      break;

    }

  insn = candidate_insn;
  switch (casenum)
    {
    case 0:
      return 7;

    case 1:
      return 4;

    case 2:
      return 5;

    case 3:
      return 8;

    case 4:
      return 5;

    case 5:
      return 6;

    }
}

static int
adder_unit_blockage (executing_insn, candidate_insn)
     rtx executing_insn;
     rtx candidate_insn;
{
  rtx insn;
  int casenum;

  insn = executing_insn;
  switch (recog_memoized (insn))
    {
    case 47:
    case 46:
    case 41:
    case 40:
    case 38:
    case 37:
      if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 3;
        }
      else
        {
	  casenum = 4;
        }
      break;

    case 12:
    case 11:
    case 1:
    case 0:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && ((ss_cpu_attr) == (CPU_R6000)))))))
        {
	  casenum = 0;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  casenum = 1;
        }
      else
        {
	  casenum = 2;
        }
      break;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      casenum = 4;
      break;

    }

  insn = candidate_insn;
  switch (casenum)
    {
    case 0:
      return 4;

    case 1:
      return 2;

    case 2:
      return 3;

    case 3:
      return 2;

    case 4:
      return 1;

    }
}

static int
imuldiv_unit_blockage (executing_insn, candidate_insn)
     rtx executing_insn;
     rtx candidate_insn;
{
  rtx insn;
  int casenum;

  insn = executing_insn;
  switch (recog_memoized (insn))
    {
    case 36:
    case 35:
    case 34:
    case 33:
    case 32:
    case 31:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000))))))))
        {
	  casenum = 3;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  casenum = 4;
        }
      else
        {
	  casenum = 5;
        }
      break;

    case 28:
    case 27:
    case 26:
    case 24:
      if ((! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((! ((ss_cpu_attr) == (CPU_R3000))) && (! ((ss_cpu_attr) == (CPU_R6000))))))))
        {
	  casenum = 0;
        }
      else if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
        {
	  casenum = 1;
        }
      else
        {
	  casenum = 2;
        }
      break;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      casenum = 5;
      break;

    }

  insn = candidate_insn;
  switch (casenum)
    {
    case 0:
      return 17 /* 0x11 */;

    case 1:
      return 12 /* 0xc */;

    case 2:
      return 10 /* 0xa */;

    case 3:
      return 38 /* 0x26 */;

    case 4:
      return 35 /* 0x23 */;

    case 5:
      return 69 /* 0x45 */;

    }
}

static int
memory_unit_blockage (executing_insn, candidate_insn)
     rtx executing_insn;
     rtx candidate_insn;
{
  rtx insn;
  int casenum;

  insn = executing_insn;
  switch (recog_memoized (insn))
    {
    case 100:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  casenum = 0;
        }
      else if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 1;
        }
      else if ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 11) || (which_alternative == 12))))
        {
	  casenum = 2;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  casenum = 3;
        }
      else
        {
	  casenum = 4;
        }
      break;

    case 101:
    case 98:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || (which_alternative == 2)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  casenum = 0;
        }
      else if (((which_alternative == 1) || (which_alternative == 2)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 1;
        }
      else if ((which_alternative != 0) && ((which_alternative != 1) && (which_alternative != 2)))
        {
	  casenum = 2;
        }
      else
        {
	  casenum = 4;
        }
      break;

    case 97:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  casenum = 0;
        }
      else if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 1;
        }
      else if ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))
        {
	  casenum = 2;
        }
      else if ((which_alternative == 1) || ((which_alternative == 6) || (which_alternative == 7)))
        {
	  casenum = 3;
        }
      else
        {
	  casenum = 4;
        }
      break;

    case 95:
    case 94:
    case 92:
    case 91:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  casenum = 0;
        }
      else if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 1;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  casenum = 2;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  casenum = 3;
        }
      else
        {
	  casenum = 4;
        }
      break;

    case 89:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  casenum = 0;
        }
      else if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 1;
        }
      else if ((which_alternative == 6) || (which_alternative == 7))
        {
	  casenum = 2;
        }
      else if ((which_alternative == 8) || (which_alternative == 9))
        {
	  casenum = 3;
        }
      else
        {
	  casenum = 4;
        }
      break;

    case 88:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  casenum = 0;
        }
      else if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 1;
        }
      else if ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 13) || (which_alternative == 14))))
        {
	  casenum = 2;
        }
      else if ((which_alternative == 8) || (which_alternative == 9))
        {
	  casenum = 3;
        }
      else
        {
	  casenum = 4;
        }
      break;

    case 84:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
        {
	  casenum = 0;
        }
      else if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 1;
        }
      else if ((which_alternative == 4) || (which_alternative == 5))
        {
	  casenum = 2;
        }
      else
        {
	  casenum = 4;
        }
      break;

    case 107:
    case 82:
      casenum = 2;
      break;

    case 81:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 0;
        }
      else
        {
	  casenum = 1;
        }
      break;

    case 72:
    case 70:
    case 68:
      if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 0;
        }
      else
        {
	  casenum = 1;
        }
      break;

    case 66:
    case 65:
    case 64:
      insn_extract (insn);
      if (! constrain_operands (INSN_CODE (insn), reload_completed))
        fatal_insn_not_found (insn);
      if (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
        {
	  casenum = 0;
        }
      else
        {
	  casenum = 1;
        }
      break;

    case -1:
      if (GET_CODE (PATTERN (insn)) != ASM_INPUT
          && asm_noperands (PATTERN (insn)) < 0)
        fatal_insn_not_found (insn);
    default:
      casenum = 4;
      break;

    }

  insn = candidate_insn;
  switch (casenum)
    {
    case 0:
      switch (recog_memoized (insn))
	{
        case 100:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 6) || (which_alternative == 7))
	    {
	      return 2;
	    }
	  else
	    {
	      return 3;
	    }

        case 101:
        case 98:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 1) || (which_alternative == 2)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 1) || (which_alternative == 2)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 97:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 1) || ((which_alternative == 6) || (which_alternative == 7)))
	    {
	      return 2;
	    }
	  else
	    {
	      return 3;
	    }

        case 95:
        case 92:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 6) || (which_alternative == 7))
	    {
	      return 2;
	    }
	  else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && (which_alternative != 5))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 94:
        case 91:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 6) || (which_alternative == 7))
	    {
	      return 2;
	    }
	  else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && (which_alternative != 8)))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 89:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 8) || (which_alternative == 9))
	    {
	      return 2;
	    }
	  else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && (which_alternative != 7))))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 88:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 8) || (which_alternative == 9))
	    {
	      return 2;
	    }
	  else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && ((which_alternative != 10) && ((which_alternative != 11) && ((which_alternative != 12) && ((which_alternative != 13) && (which_alternative != 14)))))))))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 84:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if ((((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && (which_alternative != 5)))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 81:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 72:
        case 70:
        case 68:
	  if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 66:
        case 65:
        case 64:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case -1:
	  if (GET_CODE (PATTERN (insn)) != ASM_INPUT
	      && asm_noperands (PATTERN (insn)) < 0)
	    fatal_insn_not_found (insn);
        default:
	  return 3;

      }

    case 1:
      switch (recog_memoized (insn))
	{
        case 100:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 5) && ((which_alternative != 9) && (which_alternative != 10))))) && ((which_alternative != 6) && (which_alternative != 7)))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 101:
        case 98:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative != 0) && ((which_alternative != 1) && (which_alternative != 2))) || (((which_alternative != 1) && (which_alternative != 2)) && ((which_alternative == 0) || ((which_alternative == 1) || (which_alternative == 2)))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 97:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 9) && (which_alternative != 10)))) && ((which_alternative != 1) && ((which_alternative != 6) && (which_alternative != 7))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 95:
        case 92:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 4) || ((which_alternative == 5) || (((which_alternative != 2) && (which_alternative != 3)) && (((which_alternative != 6) && (which_alternative != 7)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 6) || (which_alternative == 7))))))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 94:
        case 91:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 4) || ((which_alternative == 5) || (((which_alternative != 2) && (which_alternative != 3)) && (((which_alternative != 6) && (which_alternative != 7)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 6) || ((which_alternative == 7) || (which_alternative == 8)))))))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 89:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 6) || ((which_alternative == 7) || (((which_alternative != 1) && ((which_alternative != 4) && (which_alternative != 5))) && (((which_alternative != 8) && (which_alternative != 9)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 8) || (which_alternative == 9))))))))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 88:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 13) || ((which_alternative == 14) || (((which_alternative != 1) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 11) && (which_alternative != 12))))) && (((which_alternative != 8) && (which_alternative != 9)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 8) || ((which_alternative == 9) || ((which_alternative == 10) || ((which_alternative == 11) || (which_alternative == 12)))))))))))))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 84:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 4) || ((which_alternative == 5) || (((which_alternative != 2) && (which_alternative != 3)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || (which_alternative == 3)))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 81:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  return 1;

        case 72:
        case 70:
        case 68:
	  return 1;

        case 66:
        case 65:
        case 64:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  return 1;

        case -1:
	  if (GET_CODE (PATTERN (insn)) != ASM_INPUT
	      && asm_noperands (PATTERN (insn)) < 0)
	    fatal_insn_not_found (insn);
        default:
	  return 2;

      }

    case 2:
      return 1;

    case 3:
      switch (recog_memoized (insn))
	{
        case 100:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 5) && ((which_alternative != 9) && (which_alternative != 10))))) && ((which_alternative != 6) && (which_alternative != 7)))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 101:
        case 98:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative != 0) && ((which_alternative != 1) && (which_alternative != 2))) || (((which_alternative != 1) && (which_alternative != 2)) && ((which_alternative == 0) || ((which_alternative == 1) || (which_alternative == 2)))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 97:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 9) && (which_alternative != 10)))) && ((which_alternative != 1) && ((which_alternative != 6) && (which_alternative != 7))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 95:
        case 92:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 4) || ((which_alternative == 5) || (((which_alternative != 2) && (which_alternative != 3)) && (((which_alternative != 6) && (which_alternative != 7)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 6) || (which_alternative == 7))))))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 94:
        case 91:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 4) || ((which_alternative == 5) || (((which_alternative != 2) && (which_alternative != 3)) && (((which_alternative != 6) && (which_alternative != 7)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 6) || ((which_alternative == 7) || (which_alternative == 8)))))))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 89:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 6) || ((which_alternative == 7) || (((which_alternative != 1) && ((which_alternative != 4) && (which_alternative != 5))) && (((which_alternative != 8) && (which_alternative != 9)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 8) || (which_alternative == 9))))))))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 88:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 6) || ((which_alternative == 7) || ((which_alternative == 13) || ((which_alternative == 14) || (((which_alternative != 1) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 11) && (which_alternative != 12))))) && (((which_alternative != 8) && (which_alternative != 9)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 8) || ((which_alternative == 9) || ((which_alternative == 10) || ((which_alternative == 11) || (which_alternative == 12)))))))))))))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 84:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if ((which_alternative == 4) || ((which_alternative == 5) || (((which_alternative != 2) && (which_alternative != 3)) && ((which_alternative == 0) || ((which_alternative == 1) || ((which_alternative == 2) || (which_alternative == 3)))))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 81:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  return 1;

        case 72:
        case 70:
        case 68:
	  return 1;

        case 66:
        case 65:
        case 64:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  return 1;

        case -1:
	  if (GET_CODE (PATTERN (insn)) != ASM_INPUT
	      && asm_noperands (PATTERN (insn)) < 0)
	    fatal_insn_not_found (insn);
        default:
	  return 2;

      }

    case 4:
      switch (recog_memoized (insn))
	{
        case 100:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 1) || ((which_alternative == 2) || ((which_alternative == 5) || ((which_alternative == 9) || (which_alternative == 10))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 6) || (which_alternative == 7))
	    {
	      return 2;
	    }
	  else
	    {
	      return 3;
	    }

        case 101:
        case 98:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 1) || (which_alternative == 2)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 1) || (which_alternative == 2)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 97:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 2) || ((which_alternative == 3) || ((which_alternative == 9) || (which_alternative == 10)))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 1) || ((which_alternative == 6) || (which_alternative == 7)))
	    {
	      return 2;
	    }
	  else
	    {
	      return 3;
	    }

        case 95:
        case 92:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 6) || (which_alternative == 7))
	    {
	      return 2;
	    }
	  else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && (which_alternative != 5))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 94:
        case 91:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 6) || (which_alternative == 7))
	    {
	      return 2;
	    }
	  else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && (which_alternative != 8)))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 89:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 1) || ((which_alternative == 4) || (which_alternative == 5))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 8) || (which_alternative == 9))
	    {
	      return 2;
	    }
	  else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && (which_alternative != 7))))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 88:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if (((which_alternative == 1) || ((which_alternative == 4) || ((which_alternative == 5) || ((which_alternative == 11) || (which_alternative == 12))))) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))))
	    {
	      return 1;
	    }
	  else if ((which_alternative == 8) || (which_alternative == 9))
	    {
	      return 2;
	    }
	  else if ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && ((which_alternative != 5) && ((which_alternative != 6) && ((which_alternative != 7) && ((which_alternative != 10) && ((which_alternative != 11) && ((which_alternative != 12) && ((which_alternative != 13) && (which_alternative != 14)))))))))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 84:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((which_alternative == 2) || (which_alternative == 3)) && (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))
	    {
	      return 2;
	    }
	  else if ((((which_alternative == 2) || (which_alternative == 3)) && (! (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000)))))) || ((which_alternative != 0) && ((which_alternative != 1) && ((which_alternative != 2) && ((which_alternative != 3) && ((which_alternative != 4) && (which_alternative != 5)))))))
	    {
	      return 1;
	    }
	  else
	    {
	      return 3;
	    }

        case 81:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 72:
        case 70:
        case 68:
	  if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case 66:
        case 65:
        case 64:
	  insn_extract (insn);
	  if (! constrain_operands (INSN_CODE (insn), reload_completed))
	    fatal_insn_not_found (insn);
	  if (((! ((ss_cpu_attr) == (CPU_DEFAULT))) && ((ss_cpu_attr) == (CPU_R3000))))
	    {
	      return 2;
	    }
	  else
	    {
	      return 1;
	    }

        case -1:
	  if (GET_CODE (PATTERN (insn)) != ASM_INPUT
	      && asm_noperands (PATTERN (insn)) < 0)
	    fatal_insn_not_found (insn);
        default:
	  return 3;

      }

    }
}

struct function_unit_desc function_units[] = {
  {"memory", 1, 1, 0, 1, 1, memory_unit_ready_cost, 0, 3, memory_unit_blockage_range, memory_unit_blockage}, 
  {"addr", 2, 1, 0, 1, 1, addr_unit_ready_cost, 0, 1, 0, 0}, 
  {"imuldiv", 4, 1, 1, 1, 1, imuldiv_unit_ready_cost, 0, 69, imuldiv_unit_blockage_range, imuldiv_unit_blockage}, 
  {"adder", 8, 1, 1, 1, 1, adder_unit_ready_cost, 0, 4, adder_unit_blockage_range, adder_unit_blockage}, 
  {"mult", 16, 1, 1, 1, 1, mult_unit_ready_cost, 0, 8, mult_unit_blockage_range, mult_unit_blockage}, 
  {"divide", 32, 1, 1, 1, 1, divide_unit_ready_cost, 0, 112, divide_unit_blockage_range, divide_unit_blockage}, 
};

