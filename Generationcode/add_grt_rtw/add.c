/*
 * add.c
 *
 * Code generation for model "add".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.5 (R2021a) 14-Nov-2020
 * C source code generated on : Tue Jan 16 09:49:38 2024
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#include "add.h"
#include "add_private.h"

/* External inputs (root inport signals with default storage) */
ExtU_add_T add_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_add_T add_Y;

/* Real-time model */
static RT_MODEL_add_T add_M_;
RT_MODEL_add_T *const add_M = &add_M_;

/* Model step function */
void add_step(void)
{
  uint32_T u0;

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   */
  u0 = add_U.In1 + add_U.In2;

  /* Saturate: '<S1>/Saturation' */
  if (u0 < 1000000U) {
    /* Outport: '<Root>/Out1' */
    add_Y.Out1 = u0;
  } else {
    /* Outport: '<Root>/Out1' */
    add_Y.Out1 = 1000000U;
  }

  /* End of Saturate: '<S1>/Saturation' */
}

/* Model initialize function */
void add_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(add_M, (NULL));

  /* external inputs */
  (void)memset(&add_U, 0, sizeof(ExtU_add_T));

  /* external outputs */
  add_Y.Out1 = 0U;
}

/* Model terminate function */
void add_terminate(void)
{
  /* (no terminate code required) */
}
