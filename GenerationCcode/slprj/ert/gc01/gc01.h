/*
 * File: gc01.h
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

#ifndef gc01_h_
#define gc01_h_
#ifndef gc01_COMMON_INCLUDES_
#define gc01_COMMON_INCLUDES_
#include <stdbool.h>
#include <stdint.h>
#include "complex_types.h"
#include "math.h"
#endif                                 /* gc01_COMMON_INCLUDES_ */

/* Forward declaration for rtModel */
typedef struct tag_RTM_gc01_T RT_MODEL_gc01_T;

/* Self model data, for model 'gc01' */
struct tag_RTM_gc01_T {
  const char **errorStatus;
};

/* Model reference registration function */
extern void gc01_initialize(const char **rt_errorStatus, RT_MODEL_gc01_T *const
  gc01_M);
extern void gc01_Init(RT_MODEL_gc01_T * const gc01_M);
extern double gc01_step(RT_MODEL_gc01_T * const gc01_M, double arg_In1, double
  arg_In2);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'gc01'
 */
#endif                                 /* gc01_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
