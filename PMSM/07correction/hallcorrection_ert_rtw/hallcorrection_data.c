/*
 * File: hallcorrection_data.c
 *
 * Code generated for Simulink model 'hallcorrection'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Oct 12 17:20:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hallcorrection.h"

/* Block parameters (default storage) */
P_hallcorrection_T hallcorrection_P = {
  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S9>/FixPt Switch'
   */
  20000U,

  /* Expression: 25
   * Referenced by: '<S1>/Constant'
   */
  25.0,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S9>/Constant'
   */
  0U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S1>/Out1'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S8>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S4>/Output'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
