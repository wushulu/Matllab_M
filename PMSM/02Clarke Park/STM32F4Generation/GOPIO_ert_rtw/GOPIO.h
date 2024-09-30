/*
 * File: GOPIO.h
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

#ifndef GOPIO_h_
#define GOPIO_h_
#ifndef GOPIO_COMMON_INCLUDES_
#define GOPIO_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#include "main.h"
#endif                                 /* GOPIO_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "GOPIO_types.h"
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
  uint32_T Output;                     /* '<S13>/Output' */
} B_GOPIO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S15>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_GO_T obj_e;/* '<S21>/PWM Output' */
  uint32_T Output_DSTATE;              /* '<S13>/Output' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_GOPIO_T;

/* Parameters (default storage) */
struct P_GOPIO_T_ {
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S17>/FixPt Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S27>/Constant'
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
  real_T Gain1_Gain;                   /* Expression: 0.2*pi
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S8>/Gain'
                                        */
  real_T convert_pu_Gain;              /* Expression: 1/(dlgSett.UpperSatLimit)
                                        * Referenced by: '<S26>/convert_pu'
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
  uint32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S17>/Constant'
                                        */
  uint32_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S3>/Out2'
                                        */
  uint32_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S16>/FixPt Constant'
                                       */
  uint32_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S13>/Output'
                                   */
  uint16_T Out3_Y0;                    /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S3>/Out3'
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
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Kalphabeta0' : Unused code path elimination
 * Block '<S9>/Sum' : Unused code path elimination
 * Block '<S9>/Sum1' : Unused code path elimination
 * Block '<S9>/Sum2' : Unused code path elimination
 * Block '<S9>/one_by_3' : Unused code path elimination
 * Block '<S9>/one_by_sqrt3_' : Unused code path elimination
 * Block '<S13>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S24>/Data Type Conversion1' : Unused code path elimination
 * Block '<S24>/Get_FractionVal' : Unused code path elimination
 * Block '<S24>/Get_Integer' : Unused code path elimination
 * Block '<S25>/Product' : Unused code path elimination
 * Block '<S25>/Product1' : Unused code path elimination
 * Block '<S25>/Sum3' : Unused code path elimination
 * Block '<S25>/Sum4' : Unused code path elimination
 * Block '<S25>/Sum5' : Unused code path elimination
 * Block '<S25>/Sum6' : Unused code path elimination
 * Block '<S24>/Lookup' : Unused code path elimination
 * Block '<S24>/Sum' : Unused code path elimination
 * Block '<S24>/Sum2' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/indexing' : Unused code path elimination
 * Block '<S24>/offset' : Unused code path elimination
 * Block '<S24>/sine_table_values' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S30>/Offset' : Unused code path elimination
 * Block '<S30>/Switch' : Unused code path elimination
 * Block '<S30>/Unary_Minus' : Unused code path elimination
 * Block '<S23>/acos' : Unused code path elimination
 * Block '<S23>/asin' : Unused code path elimination
 * Block '<S23>/bcos' : Unused code path elimination
 * Block '<S23>/bsin' : Unused code path elimination
 * Block '<S23>/sum_Ds' : Unused code path elimination
 * Block '<S23>/sum_Qs' : Unused code path elimination
 * Block '<S7>/0' : Unused code path elimination
 * Block '<S7>/Gain1' : Unused code path elimination
 * Block '<S7>/d' : Unused code path elimination
 * Block '<S7>/q' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Scope2' : Unused code path elimination
 * Block '<Root>/Scope3' : Unused code path elimination
 * Block '<Root>/Sine Wave' : Unused code path elimination
 * Block '<Root>/Sine Wave1' : Unused code path elimination
 * Block '<Root>/Sine Wave2' : Unused code path elimination
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
 * '<S1>'   : 'GOPIO/Clarke Transform'
 * '<S2>'   : 'GOPIO/Digital Port Write'
 * '<S3>'   : 'GOPIO/Function-Call Subsystem'
 * '<S4>'   : 'GOPIO/Hardware Interrupt'
 * '<S5>'   : 'GOPIO/PWM Output'
 * '<S6>'   : 'GOPIO/Park Transform'
 * '<S7>'   : 'GOPIO/Park Transform2'
 * '<S8>'   : 'GOPIO/Radians to Degrees'
 * '<S9>'   : 'GOPIO/Clarke Transform/Three phase input'
 * '<S10>'  : 'GOPIO/Digital Port Write/ECSoC'
 * '<S11>'  : 'GOPIO/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S12>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter'
 * '<S13>'  : 'GOPIO/Function-Call Subsystem/Counter Limited'
 * '<S14>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S15>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S16>'  : 'GOPIO/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S17>'  : 'GOPIO/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S18>'  : 'GOPIO/Hardware Interrupt/ECSoC'
 * '<S19>'  : 'GOPIO/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S20>'  : 'GOPIO/PWM Output/ECSoC'
 * '<S21>'  : 'GOPIO/PWM Output/ECSoC/ECSimCodegen'
 * '<S22>'  : 'GOPIO/Park Transform/Sine Cosine'
 * '<S23>'  : 'GOPIO/Park Transform/Two inputs CRL'
 * '<S24>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S25>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/Interpolation'
 * '<S26>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp'
 * '<S27>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S28>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S29>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S30>'  : 'GOPIO/Park Transform/Two inputs CRL/Switch_Axis'
 */
#endif                                 /* GOPIO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
