/*
 * File: G431debug.h
 *
 * Code generated for Simulink model 'G431debug'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct 15 07:24:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef G431debug_h_
#define G431debug_h_
#ifndef G431debug_COMMON_INCLUDES_
#define G431debug_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#include "main.h"
#endif                                 /* G431debug_COMMON_INCLUDES_ */

#include "G431debug_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_G431debug_T;

/* Parameters (default storage) */
struct P_G431debug_T_ {
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_G431debug_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_G431debug_T G431debug_P;

/* Block states (default storage) */
extern DW_G431debug_T G431debug_DW;

/* Model entry point functions */
extern void G431debug_initialize(void);
extern void G431debug_step(void);
extern void G431debug_terminate(void);

/* Real-time Model object */
extern RT_MODEL_G431debug_T *const G431debug_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'G431debug'
 * '<S1>'   : 'G431debug/Digital Port Write'
 * '<S2>'   : 'G431debug/Digital Port Write/ECSoC'
 * '<S3>'   : 'G431debug/Digital Port Write/ECSoC/ECSimCodegen'
 */
#endif                                 /* G431debug_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
