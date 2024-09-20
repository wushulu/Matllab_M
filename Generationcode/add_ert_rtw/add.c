/*
 * File: add.c
 *
 * Code generated for Simulink model 'add'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue Jan 16 09:56:05 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "add.h"

/* External inputs (root inport signals with default storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
ExtY rtY;

/* Model step function */
void add_step(void)
{
  uint32_T u0;

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  u0 = rtU.In1 + rtU.In2;

  /* Saturate: '<S1>/Saturation' */
  if (u0 < 1000000U) {
    /* Outport: '<Root>/Out1' */
    rtY.Out1 = u0;
  } else {
    /* Outport: '<Root>/Out1' */
    rtY.Out1 = 1000000U;
  }

  /* End of Saturate: '<S1>/Saturation' */
}

/* Model initialize function */
void add_initialize(void)
{
  /* (no initialization code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
