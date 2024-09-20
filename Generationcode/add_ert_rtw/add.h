/*
 * File: add.h
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

#ifndef RTW_HEADER_add_h_
#define RTW_HEADER_add_h_
#ifndef add_COMMON_INCLUDES_
#define add_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* add_COMMON_INCLUDES_ */

/* Model Code Variants */

/* Macros for accessing real-time model data structure */

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint32_T In1;                        /* '<Root>/In1' */
  uint32_T In2;                        /* '<Root>/In2' */
} ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint32_T Out1;                       /* '<Root>/Out1' */
} ExtY;

/* External inputs (root inport signals with default storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void add_initialize(void);
extern void add_step(void);

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
 * '<Root>' : 'add'
 * '<S1>'   : 'add/Subsystem'
 */
#endif                                 /* RTW_HEADER_add_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
