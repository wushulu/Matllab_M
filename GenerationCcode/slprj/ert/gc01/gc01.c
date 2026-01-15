/*
 * File: gc01.c
 *
 * Code generated for Simulink model 'gc01'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Sep 22 10:06:45 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "gc01.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

/* System initialize for referenced model: 'gc01' */
void gc01_Init(RT_MODEL_gc01_T * const gc01_M)
{
  (void) (gc01_M);
}

/* Output and update for referenced model: 'gc01' */
double gc01_step(RT_MODEL_gc01_T * const gc01_M, double arg_In1, double arg_In2)
{
  /* specified return value */
  double arg_Out1;
  (void) (gc01_M);

  /* Sum: '<Root>/Add' incorporates:
   *  Constant: '<Root>/Constant'
   */
  arg_Out1 = (arg_In1 + arg_In2) + 200.0;
  return arg_Out1;
}

/* Model initialize function */
void gc01_initialize(const char **rt_errorStatus, RT_MODEL_gc01_T *const gc01_M)
{
  /* Registration code */
  {
    /* initialize error status */
    rtmSetErrorStatusPointer(gc01_M, rt_errorStatus);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
