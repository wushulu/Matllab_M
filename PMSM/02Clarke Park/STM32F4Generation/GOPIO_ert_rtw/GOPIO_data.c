/*
 * File: GOPIO_data.c
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Sep 27 23:20:48 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GOPIO.h"

/* Block parameters (default storage) */
P_GOPIO_T GOPIO_P = {
  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S17>/FixPt Switch'
   */
  2000000U,

  /* Expression: 0
   * Referenced by: '<S27>/Constant'
   */
  0.0,

  /* Expression: 2100
   * Referenced by: '<Root>/Constant3'
   */
  2100.0,

  /* Expression: 10
   * Referenced by: '<Root>/Constant1'
   */
  10.0,

  /* Expression: 50
   * Referenced by: '<Root>/Constant2'
   */
  50.0,

  /* Expression: 0.2*pi
   * Referenced by: '<Root>/Gain1'
   */
  0.62831853071795862,

  /* Expression: 180/pi
   * Referenced by: '<S8>/Gain'
   */
  57.295779513082323,

  /* Expression: 1/(dlgSett.UpperSatLimit)
   * Referenced by: '<S26>/convert_pu'
   */
  0.0027777777777777779,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<Root>/Pulse Generator'
   */
  10.0,

  /* Expression: 5
   * Referenced by: '<Root>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<Root>/Gain'
   */
  3518437209U,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S17>/Constant'
   */
  0U,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S3>/Out2'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S16>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S13>/Output'
   */
  0U,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S3>/Out3'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
