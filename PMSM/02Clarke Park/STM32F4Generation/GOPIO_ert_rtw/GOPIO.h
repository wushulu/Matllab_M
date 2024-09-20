/*
 * File: GOPIO.h
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Sep  4 21:01:52 2024
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
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#endif                                 /* GOPIO_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "GOPIO_types.h"
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
  real_T DataTypeConversion;           /* '<Root>/Data Type Conversion' */
  real_T Ia;                           /* '<Root>/Sine Wave' */
  real_T Ib;                           /* '<Root>/Sine Wave1' */
  real_T Ic;                           /* '<Root>/Sine Wave2' */
  real_T Gain1[3];                     /* '<S7>/Gain1' */
  real_T TmpSignalConversionAtTAQSigLogg[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T algDD_o1;                     /* '<S23>/algDD' */
  real_T algDD_o2;                     /* '<S23>/algDD' */
  uint32_T Output;                     /* '<S13>/Output' */
} B_GOPIO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S15>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_GO_T obj_e;/* '<S21>/PWM Output' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  uint32_T Output_DSTATE;              /* '<S13>/Output' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S26>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S26>/If Action Subsystem' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
} DW_GOPIO_T;

/* Parameters (default storage) */
struct P_GOPIO_T_ {
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S17>/FixPt Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T sine_table_values_Value[1002];/* Expression: dlgSett.sin_table
                                        * Referenced by: '<S24>/sine_table_values'
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
  real_T indexing_Gain;                /* Expression: dlgSett.index_gain
                                        * Referenced by: '<S24>/indexing'
                                        */
  real_T SineWave_Amp;                 /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 0.2*pi
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: pi/2
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave1_Amp;                /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 0.2*pi
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: -2/3*pi+pi/2
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave2_Amp;                /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 0.2*pi
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 2/3*pi+pi/2
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: K2
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T one_by_3_Gain;                /* Expression: 1/3
                                        * Referenced by: '<S9>/one_by_3'
                                        */
  real_T one_by_sqrt3_Gain;            /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S9>/one_by_sqrt3_'
                                        */
  real_T Kalphabeta0_Gain[3];          /* Expression: [1 1 1]
                                        * Referenced by: '<S9>/Kalphabeta0'
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
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S24>/offset'
                                        */
  uint16_T Out3_Y0;                    /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S3>/Out3'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S30>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S30>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_GOPIO_T {
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
 * Block '<S13>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S24>/Get_FractionVal' : Eliminate redundant data type conversion
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
