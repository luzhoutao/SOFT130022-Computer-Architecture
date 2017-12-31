/* Generated automatically by the program `genflags'
from the machine description file `md'.  */

#define HAVE_adddf3 (TARGET_HARD_FLOAT)
#define HAVE_addsf3 (TARGET_HARD_FLOAT)
#define HAVE_addsi3 1
#define HAVE_addsi3_internal (GET_CODE (operands[2]) != CONST_INT || INTVAL (operands[2]) != -32768)
#define HAVE_adddi3 (!TARGET_DEBUG_G_MODE)
#define HAVE_adddi3_internal_1 (!TARGET_DEBUG_G_MODE)
#define HAVE_adddi3_internal_2 (!TARGET_DEBUG_G_MODE && INTVAL (operands[2]) != -32768)
#define HAVE_subdf3 (TARGET_HARD_FLOAT)
#define HAVE_subsf3 (TARGET_HARD_FLOAT)
#define HAVE_subsi3 1
#define HAVE_subsi3_internal (GET_CODE (operands[2]) != CONST_INT || INTVAL (operands[2]) != -32768)
#define HAVE_subdi3 (!TARGET_DEBUG_G_MODE)
#define HAVE_subdi3_internal (!TARGET_DEBUG_G_MODE)
#define HAVE_subdi3_internal_2 (!TARGET_DEBUG_G_MODE && INTVAL (operands[2]) != -32768)
#define HAVE_muldf3 (TARGET_HARD_FLOAT)
#define HAVE_mulsf3 (TARGET_HARD_FLOAT)
#define HAVE_mulsi3 1
#define HAVE_mulsi3_internal 1
#define HAVE_mulsidi3 1
#define HAVE_umulsidi3 1
#define HAVE_divdf3 (TARGET_HARD_FLOAT)
#define HAVE_divsf3 (TARGET_HARD_FLOAT)
#define HAVE_divmodsi4 (optimize)
#define HAVE_udivmodsi4 (optimize)
#define HAVE_divsi3 (!optimize)
#define HAVE_modsi3 (!optimize)
#define HAVE_udivsi3 (!optimize)
#define HAVE_umodsi3 (!optimize)
#define HAVE_sqrtdf2 (TARGET_HARD_FLOAT && HAVE_SQRT_P())
#define HAVE_sqrtsf2 (TARGET_HARD_FLOAT && HAVE_SQRT_P())
#define HAVE_abssi2 1
#define HAVE_absdf2 (TARGET_HARD_FLOAT)
#define HAVE_abssf2 (TARGET_HARD_FLOAT)
#define HAVE_ffssi2 1
#define HAVE_negsi2 1
#define HAVE_negdi2 (!TARGET_DEBUG_G_MODE)
#define HAVE_negdi2_internal (!TARGET_DEBUG_G_MODE)
#define HAVE_negdf2 (TARGET_HARD_FLOAT)
#define HAVE_negsf2 (TARGET_HARD_FLOAT)
#define HAVE_one_cmplsi2 1
#define HAVE_one_cmpldi2 1
#define HAVE_norsi3 1
#define HAVE_nordi3 1
#define HAVE_andsi3 1
#define HAVE_anddi3 (!TARGET_DEBUG_G_MODE)
#define HAVE_iorsi3 1
#define HAVE_iordi3 (!TARGET_DEBUG_G_MODE)
#define HAVE_xorsi3 1
#define HAVE_xordi3 (!TARGET_DEBUG_G_MODE)
#define HAVE_truncdfsf2 (TARGET_HARD_FLOAT)
#define HAVE_zero_extendhisi2 1
#define HAVE_zero_extendqihi2 1
#define HAVE_zero_extendqisi2 1
#define HAVE_extendhisi2 1
#define HAVE_extendhisi2_internal 1
#define HAVE_extendqihi2 1
#define HAVE_extendqihi2_internal 1
#define HAVE_extendqisi2 1
#define HAVE_extendqisi2_insn 1
#define HAVE_extendsfdf2 (TARGET_HARD_FLOAT)
#define HAVE_fix_truncdfsi2 (TARGET_HARD_FLOAT)
#define HAVE_fix_truncsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_floatsidf2 (TARGET_HARD_FLOAT)
#define HAVE_floatsisf2 (TARGET_HARD_FLOAT)
#define HAVE_fixuns_truncdfsi2 (TARGET_HARD_FLOAT)
#define HAVE_fixuns_truncsfsi2 (TARGET_HARD_FLOAT)
#define HAVE_movsi_unaligned 1
#define HAVE_movsi_ulw 1
#define HAVE_movsi_usw 1
#define HAVE_movdi 1
#define HAVE_movdi_internal (register_operand (operands[0], DImode) \
   || register_operand (operands[1], DImode) \
   || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0) \
   || operands[1] == CONST0_RTX (DImode))
#define HAVE_movsi 1
#define HAVE_movsi_internal1 (0 /* TARGET_DEBUG_H_MODE */ \
   && (register_operand (operands[0], SImode) \
       || register_operand (operands[1], SImode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
#define HAVE_movsi_internal2 (1 /* !TARGET_DEBUG_H_MODE */ \
   && (register_operand (operands[0], SImode) \
       || register_operand (operands[1], SImode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
#define HAVE_movhi 1
#define HAVE_movhi_internal1 (0 /* TARGET_DEBUG_H_MODE */ \
   && (register_operand (operands[0], HImode) \
       || register_operand (operands[1], HImode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
#define HAVE_movhi_internal2 (1 /* !TARGET_DEBUG_H_MODE */ \
   && (register_operand (operands[0], HImode) \
       || register_operand (operands[1], HImode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
#define HAVE_movqi 1
#define HAVE_movqi_internal1 (0 /* TARGET_DEBUG_H_MODE */ \
   && (register_operand (operands[0], QImode) \
       || register_operand (operands[1], QImode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
#define HAVE_movqi_internal2 (1 /* !TARGET_DEBUG_H_MODE */ \
   && (register_operand (operands[0], QImode) \
       || register_operand (operands[1], QImode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0)))
#define HAVE_movsf 1
#define HAVE_movsf_internal1 (TARGET_HARD_FLOAT \
   && (register_operand (operands[0], SFmode) \
       || register_operand (operands[1], SFmode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0) \
       || operands[1] == CONST0_RTX (SFmode)))
#define HAVE_movsf_internal2 (TARGET_SOFT_FLOAT \
   && (register_operand (operands[0], SFmode) \
       || register_operand (operands[1], SFmode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0) \
       || operands[1] == CONST0_RTX (SFmode)))
#define HAVE_movdf 1
#define HAVE_movdf_internal1 (TARGET_HARD_FLOAT \
   && (register_operand (operands[0], DFmode) \
       || register_operand (operands[1], DFmode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0) \
       || operands[1] == CONST0_RTX (DFmode)))
#define HAVE_movdf_internal2 (TARGET_SOFT_FLOAT \
   && (register_operand (operands[0], DFmode) \
       || register_operand (operands[1], DFmode) \
       || (GET_CODE (operands[1]) == CONST_INT && INTVAL (operands[1]) == 0) \
       || operands[1] == CONST0_RTX (DFmode)))
#define HAVE_movstrsi 1
#define HAVE_movstrsi_internal 1
#define HAVE_movstrsi_internal2 1
#define HAVE_movstrsi_internal3 1
#define HAVE_ashlsi3 1
#define HAVE_ashldi3 (!TARGET_DEBUG_G_MODE)
#define HAVE_ashldi3_internal (!TARGET_DEBUG_G_MODE)
#define HAVE_ashldi3_internal2 (!TARGET_DEBUG_G_MODE && (INTVAL (operands[2]) & 32) != 0)
#define HAVE_ashldi3_internal3 (!TARGET_DEBUG_G_MODE \
   && (INTVAL (operands[2]) & 63) < 32 \
   && (INTVAL (operands[2]) & 63) != 0)
#define HAVE_ashrsi3 1
#define HAVE_ashrdi3 (!TARGET_DEBUG_G_MODE)
#define HAVE_ashrdi3_internal (!TARGET_DEBUG_G_MODE)
#define HAVE_ashrdi3_internal2 (!TARGET_DEBUG_G_MODE && (INTVAL (operands[2]) & 32) != 0)
#define HAVE_ashrdi3_internal3 (!TARGET_DEBUG_G_MODE \
   && (INTVAL (operands[2]) & 63) < 32 \
   && (INTVAL (operands[2]) & 63) != 0)
#define HAVE_lshrsi3 1
#define HAVE_lshrdi3 (!TARGET_DEBUG_G_MODE)
#define HAVE_lshrdi3_internal (!TARGET_DEBUG_G_MODE)
#define HAVE_lshrdi3_internal2 (!TARGET_DEBUG_G_MODE && (INTVAL (operands[2]) & 32) != 0)
#define HAVE_lshrdi3_internal3 (!TARGET_DEBUG_G_MODE \
   && (INTVAL (operands[2]) & 63) < 32 \
   && (INTVAL (operands[2]) & 63) != 0)
#define HAVE_cmpsi 1
#define HAVE_tstsi 1
#define HAVE_cmpdf (TARGET_HARD_FLOAT)
#define HAVE_cmpsf (TARGET_HARD_FLOAT)
#define HAVE_branch_fp_ne 1
#define HAVE_branch_fp_ne_rev 1
#define HAVE_branch_fp_eq 1
#define HAVE_branch_fp_eq_rev 1
#define HAVE_branch_zero 1
#define HAVE_branch_equality 1
#define HAVE_beq 1
#define HAVE_bne 1
#define HAVE_bgt 1
#define HAVE_bge 1
#define HAVE_blt 1
#define HAVE_ble 1
#define HAVE_bgtu 1
#define HAVE_bgeu 1
#define HAVE_bltu 1
#define HAVE_bleu 1
#define HAVE_seq 1
#define HAVE_seq_si_zero 1
#define HAVE_seq_si (TARGET_DEBUG_C_MODE)
#define HAVE_sne 1
#define HAVE_sne_si_zero 1
#define HAVE_sne_si (TARGET_DEBUG_C_MODE)
#define HAVE_sgt 1
#define HAVE_sgt_si 1
#define HAVE_sge 1
#define HAVE_sge_si (TARGET_DEBUG_C_MODE)
#define HAVE_slt 1
#define HAVE_slt_si 1
#define HAVE_sle 1
#define HAVE_sle_si_const (INTVAL (operands[2]) < 32767)
#define HAVE_sle_si_reg (TARGET_DEBUG_C_MODE)
#define HAVE_sgtu 1
#define HAVE_sgtu_si 1
#define HAVE_sgeu 1
#define HAVE_sgeu_si (TARGET_DEBUG_C_MODE)
#define HAVE_sltu 1
#define HAVE_sltu_si 1
#define HAVE_sleu 1
#define HAVE_sleu_si_const (INTVAL (operands[2]) < 32767)
#define HAVE_sleu_si_reg (TARGET_DEBUG_C_MODE)
#define HAVE_seq_df 1
#define HAVE_sne_df 1
#define HAVE_slt_df 1
#define HAVE_sle_df 1
#define HAVE_sgt_df 1
#define HAVE_sge_df 1
#define HAVE_seq_sf 1
#define HAVE_sne_sf 1
#define HAVE_slt_sf 1
#define HAVE_sle_sf 1
#define HAVE_sgt_sf 1
#define HAVE_sge_sf 1
#define HAVE_jump 1
#define HAVE_indirect_jump 1
#define HAVE_tablejump 1
#define HAVE_return (simple_epilogue_p ())
#define HAVE_return_internal 1
#define HAVE_prologue 1
#define HAVE_blockage 1
#define HAVE_call 1
#define HAVE_call_internal1 (!TARGET_ABICALLS && !TARGET_LONG_CALLS)
#define HAVE_call_internal2 (TARGET_ABICALLS && !TARGET_LONG_CALLS)
#define HAVE_call_internal3 (!TARGET_ABICALLS && TARGET_LONG_CALLS)
#define HAVE_call_internal4 (TARGET_ABICALLS && TARGET_LONG_CALLS)
#define HAVE_call_value 1
#define HAVE_call_value_internal1 (!TARGET_ABICALLS && !TARGET_LONG_CALLS)
#define HAVE_call_value_internal2 (TARGET_ABICALLS && !TARGET_LONG_CALLS)
#define HAVE_call_value_internal3 (!TARGET_ABICALLS && TARGET_LONG_CALLS)
#define HAVE_call_value_internal4 (TARGET_ABICALLS && TARGET_LONG_CALLS)
#define HAVE_untyped_call 1
#define HAVE_nop 1
#define HAVE_probe 1

#ifndef NO_MD_PROTOTYPES
extern rtx gen_adddf3               PROTO((rtx, rtx, rtx));
extern rtx gen_addsf3               PROTO((rtx, rtx, rtx));
extern rtx gen_addsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_addsi3_internal      PROTO((rtx, rtx, rtx));
extern rtx gen_adddi3               PROTO((rtx, rtx, rtx));
extern rtx gen_adddi3_internal_1    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_adddi3_internal_2    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_subdf3               PROTO((rtx, rtx, rtx));
extern rtx gen_subsf3               PROTO((rtx, rtx, rtx));
extern rtx gen_subsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_subsi3_internal      PROTO((rtx, rtx, rtx));
extern rtx gen_subdi3               PROTO((rtx, rtx, rtx));
extern rtx gen_subdi3_internal      PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_subdi3_internal_2    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_muldf3               PROTO((rtx, rtx, rtx));
extern rtx gen_mulsf3               PROTO((rtx, rtx, rtx));
extern rtx gen_mulsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_mulsi3_internal      PROTO((rtx, rtx));
extern rtx gen_mulsidi3             PROTO((rtx, rtx, rtx));
extern rtx gen_umulsidi3            PROTO((rtx, rtx, rtx));
extern rtx gen_divdf3               PROTO((rtx, rtx, rtx));
extern rtx gen_divsf3               PROTO((rtx, rtx, rtx));
extern rtx gen_divmodsi4            PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_udivmodsi4           PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_divsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_modsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_udivsi3              PROTO((rtx, rtx, rtx));
extern rtx gen_umodsi3              PROTO((rtx, rtx, rtx));
extern rtx gen_sqrtdf2              PROTO((rtx, rtx));
extern rtx gen_sqrtsf2              PROTO((rtx, rtx));
extern rtx gen_abssi2               PROTO((rtx, rtx));
extern rtx gen_absdf2               PROTO((rtx, rtx));
extern rtx gen_abssf2               PROTO((rtx, rtx));
extern rtx gen_ffssi2               PROTO((rtx, rtx));
extern rtx gen_negsi2               PROTO((rtx, rtx));
extern rtx gen_negdi2               PROTO((rtx, rtx));
extern rtx gen_negdi2_internal      PROTO((rtx, rtx, rtx));
extern rtx gen_negdf2               PROTO((rtx, rtx));
extern rtx gen_negsf2               PROTO((rtx, rtx));
extern rtx gen_one_cmplsi2          PROTO((rtx, rtx));
extern rtx gen_one_cmpldi2          PROTO((rtx, rtx));
extern rtx gen_norsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_nordi3               PROTO((rtx, rtx, rtx));
extern rtx gen_andsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_anddi3               PROTO((rtx, rtx, rtx));
extern rtx gen_iorsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_iordi3               PROTO((rtx, rtx, rtx));
extern rtx gen_xorsi3               PROTO((rtx, rtx, rtx));
extern rtx gen_xordi3               PROTO((rtx, rtx, rtx));
extern rtx gen_truncdfsf2           PROTO((rtx, rtx));
extern rtx gen_zero_extendhisi2     PROTO((rtx, rtx));
extern rtx gen_zero_extendqihi2     PROTO((rtx, rtx));
extern rtx gen_zero_extendqisi2     PROTO((rtx, rtx));
extern rtx gen_extendhisi2          PROTO((rtx, rtx));
extern rtx gen_extendhisi2_internal PROTO((rtx, rtx));
extern rtx gen_extendqihi2          PROTO((rtx, rtx));
extern rtx gen_extendqihi2_internal PROTO((rtx, rtx));
extern rtx gen_extendqisi2          PROTO((rtx, rtx));
extern rtx gen_extendqisi2_insn     PROTO((rtx, rtx));
extern rtx gen_extendsfdf2          PROTO((rtx, rtx));
extern rtx gen_fix_truncdfsi2       PROTO((rtx, rtx));
extern rtx gen_fix_truncsfsi2       PROTO((rtx, rtx));
extern rtx gen_floatsidf2           PROTO((rtx, rtx));
extern rtx gen_floatsisf2           PROTO((rtx, rtx));
extern rtx gen_fixuns_truncdfsi2    PROTO((rtx, rtx));
extern rtx gen_fixuns_truncsfsi2    PROTO((rtx, rtx));
extern rtx gen_movsi_unaligned      PROTO((rtx, rtx));
extern rtx gen_movsi_ulw            PROTO((rtx, rtx));
extern rtx gen_movsi_usw            PROTO((rtx, rtx));
extern rtx gen_movdi                PROTO((rtx, rtx));
extern rtx gen_movdi_internal       PROTO((rtx, rtx));
extern rtx gen_movsi                PROTO((rtx, rtx));
extern rtx gen_movsi_internal1      PROTO((rtx, rtx));
extern rtx gen_movsi_internal2      PROTO((rtx, rtx));
extern rtx gen_movhi                PROTO((rtx, rtx));
extern rtx gen_movhi_internal1      PROTO((rtx, rtx));
extern rtx gen_movhi_internal2      PROTO((rtx, rtx));
extern rtx gen_movqi                PROTO((rtx, rtx));
extern rtx gen_movqi_internal1      PROTO((rtx, rtx));
extern rtx gen_movqi_internal2      PROTO((rtx, rtx));
extern rtx gen_movsf                PROTO((rtx, rtx));
extern rtx gen_movsf_internal1      PROTO((rtx, rtx));
extern rtx gen_movsf_internal2      PROTO((rtx, rtx));
extern rtx gen_movdf                PROTO((rtx, rtx));
extern rtx gen_movdf_internal1      PROTO((rtx, rtx));
extern rtx gen_movdf_internal2      PROTO((rtx, rtx));
extern rtx gen_movstrsi             PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_movstrsi_internal    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_movstrsi_internal2   PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_movstrsi_internal3   PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_ashlsi3              PROTO((rtx, rtx, rtx));
extern rtx gen_ashldi3              PROTO((rtx, rtx, rtx));
extern rtx gen_ashldi3_internal     PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_ashldi3_internal2    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_ashldi3_internal3    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_ashrsi3              PROTO((rtx, rtx, rtx));
extern rtx gen_ashrdi3              PROTO((rtx, rtx, rtx));
extern rtx gen_ashrdi3_internal     PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_ashrdi3_internal2    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_ashrdi3_internal3    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_lshrsi3              PROTO((rtx, rtx, rtx));
extern rtx gen_lshrdi3              PROTO((rtx, rtx, rtx));
extern rtx gen_lshrdi3_internal     PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_lshrdi3_internal2    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_lshrdi3_internal3    PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_cmpsi                PROTO((rtx, rtx));
extern rtx gen_tstsi                PROTO((rtx));
extern rtx gen_cmpdf                PROTO((rtx, rtx));
extern rtx gen_cmpsf                PROTO((rtx, rtx));
extern rtx gen_branch_fp_ne         PROTO((rtx, rtx));
extern rtx gen_branch_fp_ne_rev     PROTO((rtx, rtx));
extern rtx gen_branch_fp_eq         PROTO((rtx, rtx));
extern rtx gen_branch_fp_eq_rev     PROTO((rtx, rtx));
extern rtx gen_branch_zero          PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_branch_equality      PROTO((rtx, rtx, rtx, rtx, rtx));
extern rtx gen_beq                  PROTO((rtx));
extern rtx gen_bne                  PROTO((rtx));
extern rtx gen_bgt                  PROTO((rtx));
extern rtx gen_bge                  PROTO((rtx));
extern rtx gen_blt                  PROTO((rtx));
extern rtx gen_ble                  PROTO((rtx));
extern rtx gen_bgtu                 PROTO((rtx));
extern rtx gen_bgeu                 PROTO((rtx));
extern rtx gen_bltu                 PROTO((rtx));
extern rtx gen_bleu                 PROTO((rtx));
extern rtx gen_seq                  PROTO((rtx));
extern rtx gen_seq_si_zero          PROTO((rtx, rtx));
extern rtx gen_seq_si               PROTO((rtx, rtx, rtx));
extern rtx gen_sne                  PROTO((rtx));
extern rtx gen_sne_si_zero          PROTO((rtx, rtx));
extern rtx gen_sne_si               PROTO((rtx, rtx, rtx));
extern rtx gen_sgt                  PROTO((rtx));
extern rtx gen_sgt_si               PROTO((rtx, rtx, rtx));
extern rtx gen_sge                  PROTO((rtx));
extern rtx gen_sge_si               PROTO((rtx, rtx, rtx));
extern rtx gen_slt                  PROTO((rtx));
extern rtx gen_slt_si               PROTO((rtx, rtx, rtx));
extern rtx gen_sle                  PROTO((rtx));
extern rtx gen_sle_si_const         PROTO((rtx, rtx, rtx));
extern rtx gen_sle_si_reg           PROTO((rtx, rtx, rtx));
extern rtx gen_sgtu                 PROTO((rtx));
extern rtx gen_sgtu_si              PROTO((rtx, rtx, rtx));
extern rtx gen_sgeu                 PROTO((rtx));
extern rtx gen_sgeu_si              PROTO((rtx, rtx, rtx));
extern rtx gen_sltu                 PROTO((rtx));
extern rtx gen_sltu_si              PROTO((rtx, rtx, rtx));
extern rtx gen_sleu                 PROTO((rtx));
extern rtx gen_sleu_si_const        PROTO((rtx, rtx, rtx));
extern rtx gen_sleu_si_reg          PROTO((rtx, rtx, rtx));
extern rtx gen_seq_df               PROTO((rtx, rtx));
extern rtx gen_sne_df               PROTO((rtx, rtx));
extern rtx gen_slt_df               PROTO((rtx, rtx));
extern rtx gen_sle_df               PROTO((rtx, rtx));
extern rtx gen_sgt_df               PROTO((rtx, rtx));
extern rtx gen_sge_df               PROTO((rtx, rtx));
extern rtx gen_seq_sf               PROTO((rtx, rtx));
extern rtx gen_sne_sf               PROTO((rtx, rtx));
extern rtx gen_slt_sf               PROTO((rtx, rtx));
extern rtx gen_sle_sf               PROTO((rtx, rtx));
extern rtx gen_sgt_sf               PROTO((rtx, rtx));
extern rtx gen_sge_sf               PROTO((rtx, rtx));
extern rtx gen_jump                 PROTO((rtx));
extern rtx gen_indirect_jump        PROTO((rtx));
extern rtx gen_tablejump            PROTO((rtx, rtx));
extern rtx gen_return               PROTO((void));
extern rtx gen_return_internal      PROTO((rtx));
extern rtx gen_prologue             PROTO((void));
extern rtx gen_blockage             PROTO((void));
extern rtx gen_call_internal1       PROTO((rtx, rtx, rtx));
extern rtx gen_call_internal2       PROTO((rtx, rtx, rtx));
extern rtx gen_call_internal3       PROTO((rtx, rtx, rtx));
extern rtx gen_call_internal4       PROTO((rtx, rtx, rtx));
extern rtx gen_call_value_internal1 PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_call_value_internal2 PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_call_value_internal3 PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_call_value_internal4 PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_untyped_call         PROTO((rtx, rtx, rtx));
extern rtx gen_nop                  PROTO((void));
extern rtx gen_probe                PROTO((void));

#ifdef MD_CALL_PROTOTYPES
extern rtx gen_call                 PROTO((rtx, rtx, rtx, rtx));
extern rtx gen_call_value           PROTO((rtx, rtx, rtx, rtx));

#else /* !MD_CALL_PROTOTYPES */
extern rtx gen_call ();
extern rtx gen_call_value ();
#endif /* !MD_CALL_PROTOTYPES */

#else  /* NO_MD_PROTOTYPES */
extern rtx gen_adddf3 ();
extern rtx gen_addsf3 ();
extern rtx gen_addsi3 ();
extern rtx gen_addsi3_internal ();
extern rtx gen_adddi3 ();
extern rtx gen_adddi3_internal_1 ();
extern rtx gen_adddi3_internal_2 ();
extern rtx gen_subdf3 ();
extern rtx gen_subsf3 ();
extern rtx gen_subsi3 ();
extern rtx gen_subsi3_internal ();
extern rtx gen_subdi3 ();
extern rtx gen_subdi3_internal ();
extern rtx gen_subdi3_internal_2 ();
extern rtx gen_muldf3 ();
extern rtx gen_mulsf3 ();
extern rtx gen_mulsi3 ();
extern rtx gen_mulsi3_internal ();
extern rtx gen_mulsidi3 ();
extern rtx gen_umulsidi3 ();
extern rtx gen_divdf3 ();
extern rtx gen_divsf3 ();
extern rtx gen_divmodsi4 ();
extern rtx gen_udivmodsi4 ();
extern rtx gen_divsi3 ();
extern rtx gen_modsi3 ();
extern rtx gen_udivsi3 ();
extern rtx gen_umodsi3 ();
extern rtx gen_sqrtdf2 ();
extern rtx gen_sqrtsf2 ();
extern rtx gen_abssi2 ();
extern rtx gen_absdf2 ();
extern rtx gen_abssf2 ();
extern rtx gen_ffssi2 ();
extern rtx gen_negsi2 ();
extern rtx gen_negdi2 ();
extern rtx gen_negdi2_internal ();
extern rtx gen_negdf2 ();
extern rtx gen_negsf2 ();
extern rtx gen_one_cmplsi2 ();
extern rtx gen_one_cmpldi2 ();
extern rtx gen_norsi3 ();
extern rtx gen_nordi3 ();
extern rtx gen_andsi3 ();
extern rtx gen_anddi3 ();
extern rtx gen_iorsi3 ();
extern rtx gen_iordi3 ();
extern rtx gen_xorsi3 ();
extern rtx gen_xordi3 ();
extern rtx gen_truncdfsf2 ();
extern rtx gen_zero_extendhisi2 ();
extern rtx gen_zero_extendqihi2 ();
extern rtx gen_zero_extendqisi2 ();
extern rtx gen_extendhisi2 ();
extern rtx gen_extendhisi2_internal ();
extern rtx gen_extendqihi2 ();
extern rtx gen_extendqihi2_internal ();
extern rtx gen_extendqisi2 ();
extern rtx gen_extendqisi2_insn ();
extern rtx gen_extendsfdf2 ();
extern rtx gen_fix_truncdfsi2 ();
extern rtx gen_fix_truncsfsi2 ();
extern rtx gen_floatsidf2 ();
extern rtx gen_floatsisf2 ();
extern rtx gen_fixuns_truncdfsi2 ();
extern rtx gen_fixuns_truncsfsi2 ();
extern rtx gen_movsi_unaligned ();
extern rtx gen_movsi_ulw ();
extern rtx gen_movsi_usw ();
extern rtx gen_movdi ();
extern rtx gen_movdi_internal ();
extern rtx gen_movsi ();
extern rtx gen_movsi_internal1 ();
extern rtx gen_movsi_internal2 ();
extern rtx gen_movhi ();
extern rtx gen_movhi_internal1 ();
extern rtx gen_movhi_internal2 ();
extern rtx gen_movqi ();
extern rtx gen_movqi_internal1 ();
extern rtx gen_movqi_internal2 ();
extern rtx gen_movsf ();
extern rtx gen_movsf_internal1 ();
extern rtx gen_movsf_internal2 ();
extern rtx gen_movdf ();
extern rtx gen_movdf_internal1 ();
extern rtx gen_movdf_internal2 ();
extern rtx gen_movstrsi ();
extern rtx gen_movstrsi_internal ();
extern rtx gen_movstrsi_internal2 ();
extern rtx gen_movstrsi_internal3 ();
extern rtx gen_ashlsi3 ();
extern rtx gen_ashldi3 ();
extern rtx gen_ashldi3_internal ();
extern rtx gen_ashldi3_internal2 ();
extern rtx gen_ashldi3_internal3 ();
extern rtx gen_ashrsi3 ();
extern rtx gen_ashrdi3 ();
extern rtx gen_ashrdi3_internal ();
extern rtx gen_ashrdi3_internal2 ();
extern rtx gen_ashrdi3_internal3 ();
extern rtx gen_lshrsi3 ();
extern rtx gen_lshrdi3 ();
extern rtx gen_lshrdi3_internal ();
extern rtx gen_lshrdi3_internal2 ();
extern rtx gen_lshrdi3_internal3 ();
extern rtx gen_cmpsi ();
extern rtx gen_tstsi ();
extern rtx gen_cmpdf ();
extern rtx gen_cmpsf ();
extern rtx gen_branch_fp_ne ();
extern rtx gen_branch_fp_ne_rev ();
extern rtx gen_branch_fp_eq ();
extern rtx gen_branch_fp_eq_rev ();
extern rtx gen_branch_zero ();
extern rtx gen_branch_equality ();
extern rtx gen_beq ();
extern rtx gen_bne ();
extern rtx gen_bgt ();
extern rtx gen_bge ();
extern rtx gen_blt ();
extern rtx gen_ble ();
extern rtx gen_bgtu ();
extern rtx gen_bgeu ();
extern rtx gen_bltu ();
extern rtx gen_bleu ();
extern rtx gen_seq ();
extern rtx gen_seq_si_zero ();
extern rtx gen_seq_si ();
extern rtx gen_sne ();
extern rtx gen_sne_si_zero ();
extern rtx gen_sne_si ();
extern rtx gen_sgt ();
extern rtx gen_sgt_si ();
extern rtx gen_sge ();
extern rtx gen_sge_si ();
extern rtx gen_slt ();
extern rtx gen_slt_si ();
extern rtx gen_sle ();
extern rtx gen_sle_si_const ();
extern rtx gen_sle_si_reg ();
extern rtx gen_sgtu ();
extern rtx gen_sgtu_si ();
extern rtx gen_sgeu ();
extern rtx gen_sgeu_si ();
extern rtx gen_sltu ();
extern rtx gen_sltu_si ();
extern rtx gen_sleu ();
extern rtx gen_sleu_si_const ();
extern rtx gen_sleu_si_reg ();
extern rtx gen_seq_df ();
extern rtx gen_sne_df ();
extern rtx gen_slt_df ();
extern rtx gen_sle_df ();
extern rtx gen_sgt_df ();
extern rtx gen_sge_df ();
extern rtx gen_seq_sf ();
extern rtx gen_sne_sf ();
extern rtx gen_slt_sf ();
extern rtx gen_sle_sf ();
extern rtx gen_sgt_sf ();
extern rtx gen_sge_sf ();
extern rtx gen_jump ();
extern rtx gen_indirect_jump ();
extern rtx gen_tablejump ();
extern rtx gen_return ();
extern rtx gen_return_internal ();
extern rtx gen_prologue ();
extern rtx gen_blockage ();
extern rtx gen_call_internal1 ();
extern rtx gen_call_internal2 ();
extern rtx gen_call_internal3 ();
extern rtx gen_call_internal4 ();
extern rtx gen_call_value_internal1 ();
extern rtx gen_call_value_internal2 ();
extern rtx gen_call_value_internal3 ();
extern rtx gen_call_value_internal4 ();
extern rtx gen_untyped_call ();
extern rtx gen_nop ();
extern rtx gen_probe ();
extern rtx gen_call ();
extern rtx gen_call_value ();
#endif  /* NO_MD_PROTOTYPES */
