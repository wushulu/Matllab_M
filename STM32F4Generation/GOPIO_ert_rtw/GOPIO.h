/*
 * File: GOPIO.h
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Sep  6 21:50:22 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef GOPIO_h_
#define GOPIO_h_
#ifndef GOPIO_COMMON_INCLUDES_
#define GOPIO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#include "stm_uart.h"
#endif                                 /* GOPIO_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "GOPIO_types.h"
#include "rtGetNaN.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T Sin;                          /* '<S2>/Sin' */
} B_GOPIO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_UARTWrite_GO_T obj; /* '<Root>/UART//USART Write' */
  stm32cube_blocks_AnalogInput__T obj_g;/* '<S10>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_GO_T obj_h;/* '<S16>/PWM Output' */
  uint32_T Output_DSTATE;              /* '<S8>/Output' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_GOPIO_T;

/* Parameters (default storage) */
struct P_GOPIO_T_ {
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S12>/FixPt Switch'
                                        */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S2>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S2>/Out2'
                                        */
  real_T Constant_Value;               /* Expression: 2*pi
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 2100
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant2'
                                        */
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
  uint32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S2>/Gain'
                                        */
  uint32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint32_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S8>/Output'
                                   */
  uint32_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S11>/FixPt Constant'
                                       */
  uint16_T Out3_Y0;                    /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S2>/Out3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_GOPIO_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_GOPIO_T GOPIO_P;

/* Block signals (default storage) */
extern B_GOPIO_T GOPIO_B;

/* Block states (default storage) */
extern DW_GOPIO_T GOPIO_DW;

/* Model entry point functions */
extern void GOPIO_initialize(void);
extern void GOPIO_step(void);
extern void GOPIO_terminate(void);

/* Real-time Model object */
extern RT_MODEL_GOPIO_T *const GOPIO_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC_IRQHandler(void);
  void GOPIO_configure_interrupts (void);
  void GOPIO_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion1' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S2>/Sin1' : Unused code path elimination
 */

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
 * '<Root>' : 'GOPIO'
 * '<S1>'   : 'GOPIO/Digital Port Write'
 * '<S2>'   : 'GOPIO/Function-Call Subsystem'
 * '<S3>'   : 'GOPIO/Hardware Interrupt'
 * '<S4>'   : 'GOPIO/PWM Output'
 * '<S5>'   : 'GOPIO/Digital Port Write/ECSoC'
 * '<S6>'   : 'GOPIO/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S7>'   : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter'
 * '<S8>'   : 'GOPIO/Function-Call Subsystem/Counter Limited'
 * '<S9>'   : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S10>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S11>'  : 'GOPIO/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S12>'  : 'GOPIO/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S13>'  : 'GOPIO/Hardware Interrupt/ECSoC'
 * '<S14>'  : 'GOPIO/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S15>'  : 'GOPIO/PWM Output/ECSoC'
 * '<S16>'  : 'GOPIO/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* GOPIO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
