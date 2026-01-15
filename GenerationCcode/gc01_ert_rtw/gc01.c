/*
 * File: gc01.c
 *
 * Code generated for Simulink model 'gc01'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Sep 22 15:15:15 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives:
 *    1. ROM efficiency
 *    2. MISRA C:2012 guidelines
 * Validation result: Not run
 */

#include "gc01.h"

/* Model step function */
double gc01_step(double arg_In1, double arg_In2)
{
  /* specified return value */
  double arg_Out1;

  /* Outport: '<Root>/Out1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/In2'
   *  Sum: '<Root>/Add'
   */
  arg_Out1 = arg_In1 + arg_In2;
  return arg_Out1;
}

/* Model initialize function */
void gc01_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void gc01_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
