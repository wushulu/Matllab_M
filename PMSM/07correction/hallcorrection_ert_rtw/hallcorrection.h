/*
 * File: hallcorrection.h
 *
 * Code generated for Simulink model 'hallcorrection'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Oct 12 17:20:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef hallcorrection_h_
#define hallcorrection_h_
#ifndef hallcorrection_COMMON_INCLUDES_
#define hallcorrection_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#endif                                 /* hallcorrection_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "hallcorrection_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  uint16_T RateTransition;             /* '<Root>/Rate Transition' */
  uint16_T Output;                     /* '<S4>/Output' */
} B_hallcorrection_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S7>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_ha_T obj_d;/* '<S11>/PWM Output' */
  uint16_T Output_DSTATE;              /* '<S4>/Output' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
} DW_hallcorrection_T;

/* Parameters (default storage) */
struct P_hallcorrection_T_ {
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S9>/FixPt Switch'
                                        */
  real_T Constant_Value;               /* Expression: 25
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint16_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S9>/Constant'
                                        */
  uint16_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S1>/Out1'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S8>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S4>/Output'
                                   */
};

/* Real-time Model Data Structure */
struct tag_RTM_hallcorrection_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_hallcorrection_T hallcorrection_P;

/* Block signals (default storage) */
extern B_hallcorrection_T hallcorrection_B;

/* Block states (default storage) */
extern DW_hallcorrection_T hallcorrection_DW;

/* Model entry point functions */
extern void hallcorrection_initialize(void);
extern void hallcorrection_step(void);
extern void hallcorrection_terminate(void);

/* Real-time Model object */
extern RT_MODEL_hallcorrection_T *const hallcorrection_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC_IRQHandler(void);
  void hallcorrection_configure_interrupts (void);
  void hallcorrection_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/FixPt Data Type Duplicate1' : Unused code path elimination
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
 * '<Root>' : 'hallcorrection'
 * '<S1>'   : 'hallcorrection/Function-Call Subsystem'
 * '<S2>'   : 'hallcorrection/Hardware Interrupt'
 * '<S3>'   : 'hallcorrection/Function-Call Subsystem/Analog to Digital Converter'
 * '<S4>'   : 'hallcorrection/Function-Call Subsystem/Counter Limited'
 * '<S5>'   : 'hallcorrection/Function-Call Subsystem/PWM Output'
 * '<S6>'   : 'hallcorrection/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S7>'   : 'hallcorrection/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S8>'   : 'hallcorrection/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S9>'   : 'hallcorrection/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S10>'  : 'hallcorrection/Function-Call Subsystem/PWM Output/ECSoC'
 * '<S11>'  : 'hallcorrection/Function-Call Subsystem/PWM Output/ECSoC/ECSimCodegen'
 * '<S12>'  : 'hallcorrection/Hardware Interrupt/ECSoC'
 * '<S13>'  : 'hallcorrection/Hardware Interrupt/ECSoC/ECSimCodegen'
 */
#endif                                 /* hallcorrection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
