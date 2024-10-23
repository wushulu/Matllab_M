/*
 * File: HalltimerInterface.h
 *
 * Code generated for Simulink model 'HalltimerInterface'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Oct 17 16:59:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef HalltimerInterface_h_
#define HalltimerInterface_h_
#ifndef HalltimerInterface_COMMON_INCLUDES_
#define HalltimerInterface_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "math.h"
#include "main.h"
#endif                                 /* HalltimerInterface_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "HalltimerInterface_types.h"
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
  uint16_T DataTypeConversion;         /* '<S4>/Data Type Conversion' */
  uint16_T DataTypeConversion_b;       /* '<S3>/Data Type Conversion' */
} B_HalltimerInterface_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_TimerCapture_T obj; /* '<S3>/Timer Capture' */
  stm32cube_blocks_AnalogInput__T obj_j;/* '<S18>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Ha_T obj_o;/* '<S27>/PWM Output' */
  uint16_T Output_DSTATE;              /* '<S16>/Output' */
  uint16_T Output_DSTATE_k;            /* '<S12>/Output' */
  int8_T FunctionCallSubsystem1_SubsysRa;/* '<Root>/Function-Call Subsystem1' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
} DW_HalltimerInterface_T;

/* Parameters (default storage) */
struct P_HalltimerInterface_T_ {
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S14>/FixPt Switch'
                                        */
  uint16_T WrapToZero_Threshold_a;     /* Mask Parameter: WrapToZero_Threshold_a
                                        * Referenced by: '<S20>/FixPt Switch'
                                        */
  real_T Constant1_Value;              /* Expression: 10
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T DataStoreMemory_InitialValue; /* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  real_T DataStoreMemory10_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory10'
                                         */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  real_T DataStoreMemory3_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory3'
                                        */
  real_T DataStoreMemory4_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory4'
                                        */
  real_T DataStoreMemory5_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory5'
                                        */
  real_T DataStoreMemory6_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory6'
                                        */
  real_T DataStoreMemory7_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory7'
                                        */
  real_T DataStoreMemory8_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory8'
                                        */
  real_T DataStoreMemory9_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory9'
                                        */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S14>/Constant'
                                        */
  uint16_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S3>/Out1'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S13>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S12>/Output'
                                   */
  uint16_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S20>/Constant'
                                        */
  uint16_T Out1_Y0_b;                  /* Computed Parameter: Out1_Y0_b
                                        * Referenced by: '<S4>/Out1'
                                        */
  uint16_T FixPtConstant_Value_n;   /* Computed Parameter: FixPtConstant_Value_n
                                     * Referenced by: '<S19>/FixPt Constant'
                                     */
  uint16_T Output_InitialCondition_j;
                                /* Computed Parameter: Output_InitialCondition_j
                                 * Referenced by: '<S16>/Output'
                                 */
};

/* Real-time Model Data Structure */
struct tag_RTM_HalltimerInterface_T {
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
    uint32_T clockTick2;
    uint32_T clockTick3;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_HalltimerInterface_T HalltimerInterface_P;

/* Block signals (default storage) */
extern B_HalltimerInterface_T HalltimerInterface_B;

/* Block states (default storage) */
extern DW_HalltimerInterface_T HalltimerInterface_DW;

/* Model entry point functions */
extern void HalltimerInterface_initialize(void);
extern void HalltimerInterface_step(void);
extern void HalltimerInterface_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HalltimerInterface_T *const HalltimerInterface_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void TIM3_IRQHandler(void);
  void ADC_IRQHandler(void);
  void HalltimerInterface_configure_interrupts (void);
  void HalltimerInterface_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S12>/Data Type Propagation' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S7>/Data Type' : Unused code path elimination
 * Block '<S7>/Number of pole pairs' : Unused code path elimination
 * Block '<S7>/PWM Frequency' : Unused code path elimination
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
 * '<Root>' : 'HalltimerInterface'
 * '<S1>'   : 'HalltimerInterface/Digital Port Read'
 * '<S2>'   : 'HalltimerInterface/Digital Port Write'
 * '<S3>'   : 'HalltimerInterface/Function-Call Subsystem'
 * '<S4>'   : 'HalltimerInterface/Function-Call Subsystem1'
 * '<S5>'   : 'HalltimerInterface/Hardware Interrupt'
 * '<S6>'   : 'HalltimerInterface/Hardware Interrupt2'
 * '<S7>'   : 'HalltimerInterface/Parameters'
 * '<S8>'   : 'HalltimerInterface/Digital Port Read/ECSoC'
 * '<S9>'   : 'HalltimerInterface/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S10>'  : 'HalltimerInterface/Digital Port Write/ECSoC'
 * '<S11>'  : 'HalltimerInterface/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S12>'  : 'HalltimerInterface/Function-Call Subsystem/Counter Limited'
 * '<S13>'  : 'HalltimerInterface/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S14>'  : 'HalltimerInterface/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S15>'  : 'HalltimerInterface/Function-Call Subsystem1/Analog to Digital Converter'
 * '<S16>'  : 'HalltimerInterface/Function-Call Subsystem1/Counter Limited'
 * '<S17>'  : 'HalltimerInterface/Function-Call Subsystem1/Analog to Digital Converter/ECSoC'
 * '<S18>'  : 'HalltimerInterface/Function-Call Subsystem1/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S19>'  : 'HalltimerInterface/Function-Call Subsystem1/Counter Limited/Increment Real World'
 * '<S20>'  : 'HalltimerInterface/Function-Call Subsystem1/Counter Limited/Wrap To Zero'
 * '<S21>'  : 'HalltimerInterface/Hardware Interrupt/ECSoC'
 * '<S22>'  : 'HalltimerInterface/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S23>'  : 'HalltimerInterface/Hardware Interrupt2/ECSoC'
 * '<S24>'  : 'HalltimerInterface/Hardware Interrupt2/ECSoC/ECSimCodegen'
 * '<S25>'  : 'HalltimerInterface/Parameters/PWM Output'
 * '<S26>'  : 'HalltimerInterface/Parameters/PWM Output/ECSoC'
 * '<S27>'  : 'HalltimerInterface/Parameters/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* HalltimerInterface_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
