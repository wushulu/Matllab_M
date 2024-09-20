/*
 * add.h
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

#ifndef RTW_HEADER_add_h_
#define RTW_HEADER_add_h_
#include <string.h>
#include <stddef.h>
#ifndef add_COMMON_INCLUDES_
#define add_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* add_COMMON_INCLUDES_ */

#include "add_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* External inputs (root inport signals with default storage) */
typedef struct {
  uint32_T In1;                        /* '<Root>/In1' */
  uint32_T In2;                        /* '<Root>/In2' */
} ExtU_add_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  uint32_T Out1;                       /* '<Root>/Out1' */
} ExtY_add_T;

/* Real-time Model Data Structure */
struct tag_RTM_add_T {
  const char_T *errorStatus;
};

/* External inputs (root inport signals with default storage) */
extern ExtU_add_T add_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_add_T add_Y;

/* Model entry point functions */
extern void add_initialize(void);
extern void add_step(void);
extern void add_terminate(void);

/* Real-time Model object */
extern RT_MODEL_add_T *const add_M;

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
