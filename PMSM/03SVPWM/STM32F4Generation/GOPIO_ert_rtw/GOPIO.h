/*
 * File: GOPIO.h
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Sep 27 23:32:46 2024
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

/* Block states (default storage) for system '<S26>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S26>/If Action Subsystem' */
} DW_IfActionSubsystem_GOPIO_T;

/* Block states (default storage) for system '<S26>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S26>/If Action Subsystem1' */
} DW_IfActionSubsystem1_GOPIO_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain1[3];                     /* '<S10>/Gain1' */
  real_T Gain4[3];                     /* '<Root>/Gain4' */
  GPIO_TypeDef * portNameLoc;
  real_T Ia;                           /* '<Root>/Sine Wave' */
  real_T Ib;                           /* '<Root>/Sine Wave1' */
  real_T Ic;                           /* '<Root>/Sine Wave2' */
  real_T Constant4;                    /* '<Root>/Constant4' */
  real_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T TmpSignalConversionAtTAQSigLo_g[3];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Inverse Park Transform_at_outport_0Inport1' */
  real_T algDD_o1;                     /* '<S94>/algDD' */
  real_T algDD_o2;                     /* '<S94>/algDD' */
  real_T algDD_o1_p;
  real_T algDD_o2_f;
  real_T Gain1_m;                      /* '<Root>/Gain1' */
  uint32_T timer3cn;                   /* '<Root>/Timer' */
  uint32_T Output;                     /* '<S16>/Output' */
} B_GOPIO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S18>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_GO_T obj_e;/* '<S85>/PWM Output' */
  stm32cube_blocks_TimerBlock_G_T obj_j;/* '<Root>/Timer' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<Root>/Scope4' */

  uint32_T Output_DSTATE;              /* '<S16>/Output' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  DW_IfActionSubsystem1_GOPIO_T IfActionSubsystem1_f;/* '<S97>/If Action Subsystem1' */
  DW_IfActionSubsystem_GOPIO_T IfActionSubsystem_g;/* '<S97>/If Action Subsystem' */
  DW_IfActionSubsystem1_GOPIO_T IfActionSubsystem1;/* '<S26>/If Action Subsystem1' */
  DW_IfActionSubsystem_GOPIO_T IfActionSubsystem;/* '<S26>/If Action Subsystem' */
} DW_GOPIO_T;

/* Parameters (default storage) */
struct P_GOPIO_T_ {
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S20>/FixPt Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: 0
                                        * Referenced by: '<S98>/Constant'
                                        */
  real_T sine_table_values_Value[1002];/* Expression: dlgSett.sin_table
                                        * Referenced by: '<S95>/sine_table_values'
                                        */
  real_T sine_table_values_Value_b[1002];/* Expression: dlgSett.sin_table
                                          * Referenced by: '<S23>/sine_table_values'
                                          */
  real_T Gain1_Gain;                   /* Expression: 0.2*pi
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 180/pi
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T convert_pu_Gain;              /* Expression: 1/(dlgSett.UpperSatLimit)
                                        * Referenced by: '<S26>/convert_pu'
                                        */
  real_T indexing_Gain;                /* Expression: dlgSett.index_gain
                                        * Referenced by: '<S23>/indexing'
                                        */
  real_T convert_pu_Gain_n;            /* Expression: 1/(dlgSett.UpperSatLimit)
                                        * Referenced by: '<S97>/convert_pu'
                                        */
  real_T indexing_Gain_c;              /* Expression: dlgSett.index_gain
                                        * Referenced by: '<S95>/indexing'
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
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T one_by_3_Gain;                /* Expression: 1/3
                                        * Referenced by: '<S12>/one_by_3'
                                        */
  real_T one_by_sqrt3_Gain;            /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S12>/one_by_sqrt3_'
                                        */
  real_T Kalphabeta0_Gain[3];          /* Expression: [1 1 1]
                                        * Referenced by: '<S12>/Kalphabeta0'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/11
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Ka_Gain;                      /* Expression: 1
                                        * Referenced by: '<S92>/Ka'
                                        */
  real_T one_by_two_Gain;              /* Expression: 1/2
                                        * Referenced by: '<S92>/one_by_two'
                                        */
  real_T sqrt3_by_two_Gain;            /* Expression: sqrt(3)/2
                                        * Referenced by: '<S92>/sqrt3_by_two'
                                        */
  real_T Kb_Gain;                      /* Expression: 1
                                        * Referenced by: '<S92>/Kb'
                                        */
  real_T Kc_Gain;                      /* Expression: 1
                                        * Referenced by: '<S92>/Kc'
                                        */
  real_T one_by_two_Gain_d;            /* Expression: -0.5
                                        * Referenced by: '<S89>/one_by_two'
                                        */
  real_T Gain_Gain_m;                  /* Expression: 2/sqrt(3)
                                        * Referenced by: '<S88>/Gain'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T Constant_Value_p;             /* Expression: 0.5
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T Constant3_Value;              /* Expression: 2100
                                        * Referenced by: '<Root>/Constant3'
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
                                        * Referenced by: '<S20>/Constant'
                                        */
  uint32_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S3>/Out2'
                                        */
  uint32_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S19>/FixPt Constant'
                                       */
  uint32_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S16>/Output'
                                   */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S23>/offset'
                                        */
  int16_T offset_Value_h[4];           /* Computed Parameter: offset_Value_h
                                        * Referenced by: '<S95>/offset'
                                        */
  uint16_T Out3_Y0;                    /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S3>/Out3'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S31>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S31>/Switch'
                                        */
  uint16_T Offset_Value_i;             /* Computed Parameter: Offset_Value_i
                                        * Referenced by: '<S101>/Offset'
                                        */
  uint16_T Switch_Threshold_i;         /* Computed Parameter: Switch_Threshold_i
                                        * Referenced by: '<S101>/Switch'
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
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/Data Type Propagation' : Unused code path elimination
 * Block '<S19>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S28>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S57>/AND3' : Unused code path elimination
 * Block '<S57>/Clamping_zero' : Unused code path elimination
 * Block '<S57>/Constant' : Unused code path elimination
 * Block '<S57>/Constant1' : Unused code path elimination
 * Block '<S57>/Constant2' : Unused code path elimination
 * Block '<S57>/Constant3' : Unused code path elimination
 * Block '<S57>/Constant4' : Unused code path elimination
 * Block '<S59>/DeadZone' : Unused code path elimination
 * Block '<S57>/Equal1' : Unused code path elimination
 * Block '<S57>/Relational Operator' : Unused code path elimination
 * Block '<S57>/Switch' : Unused code path elimination
 * Block '<S57>/Switch1' : Unused code path elimination
 * Block '<S57>/Switch2' : Unused code path elimination
 * Block '<S57>/fix for DT propagation issue' : Unused code path elimination
 * Block '<S57>/fix for DT propagation issue1' : Unused code path elimination
 * Block '<S64>/IProd Out' : Unused code path elimination
 * Block '<S67>/Integrator' : Unused code path elimination
 * Block '<S72>/PProd Out' : Unused code path elimination
 * Block '<S74>/Saturation' : Unused code path elimination
 * Block '<S76>/Sum' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Vc' : Unused code path elimination
 * Block '<S92>/Data Type Duplicate' : Unused code path elimination
 * Block '<S95>/Data Type Duplicate' : Unused code path elimination
 * Block '<S95>/Data Type Propagation' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S95>/Get_FractionVal' : Eliminate redundant data type conversion
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
 * '<S5>'   : 'GOPIO/Inverse Park Transform'
 * '<S6>'   : 'GOPIO/PI Controller'
 * '<S7>'   : 'GOPIO/PWM Output'
 * '<S8>'   : 'GOPIO/PWM Reference Generator1'
 * '<S9>'   : 'GOPIO/Park Transform'
 * '<S10>'  : 'GOPIO/Park Transform2'
 * '<S11>'  : 'GOPIO/Radians to Degrees'
 * '<S12>'  : 'GOPIO/Clarke Transform/Three phase input'
 * '<S13>'  : 'GOPIO/Digital Port Write/ECSoC'
 * '<S14>'  : 'GOPIO/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S15>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter'
 * '<S16>'  : 'GOPIO/Function-Call Subsystem/Counter Limited'
 * '<S17>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S18>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S19>'  : 'GOPIO/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S20>'  : 'GOPIO/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S21>'  : 'GOPIO/Hardware Interrupt/ECSoC'
 * '<S22>'  : 'GOPIO/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S23>'  : 'GOPIO/Inverse Park Transform/Sine Cosine'
 * '<S24>'  : 'GOPIO/Inverse Park Transform/Three inputs'
 * '<S25>'  : 'GOPIO/Inverse Park Transform/Sine Cosine/Interpolation'
 * '<S26>'  : 'GOPIO/Inverse Park Transform/Sine Cosine/WrapUp'
 * '<S27>'  : 'GOPIO/Inverse Park Transform/Sine Cosine/WrapUp/Compare To Zero'
 * '<S28>'  : 'GOPIO/Inverse Park Transform/Sine Cosine/WrapUp/If Action Subsystem'
 * '<S29>'  : 'GOPIO/Inverse Park Transform/Sine Cosine/WrapUp/If Action Subsystem1'
 * '<S30>'  : 'GOPIO/Inverse Park Transform/Three inputs/Two inputs CRL'
 * '<S31>'  : 'GOPIO/Inverse Park Transform/Three inputs/Two inputs CRL/Switch_Axis'
 * '<S32>'  : 'GOPIO/PI Controller/Anti-windup'
 * '<S33>'  : 'GOPIO/PI Controller/D Gain'
 * '<S34>'  : 'GOPIO/PI Controller/External Derivative'
 * '<S35>'  : 'GOPIO/PI Controller/Filter'
 * '<S36>'  : 'GOPIO/PI Controller/Filter ICs'
 * '<S37>'  : 'GOPIO/PI Controller/I Gain'
 * '<S38>'  : 'GOPIO/PI Controller/Ideal P Gain'
 * '<S39>'  : 'GOPIO/PI Controller/Ideal P Gain Fdbk'
 * '<S40>'  : 'GOPIO/PI Controller/Integrator'
 * '<S41>'  : 'GOPIO/PI Controller/Integrator ICs'
 * '<S42>'  : 'GOPIO/PI Controller/N Copy'
 * '<S43>'  : 'GOPIO/PI Controller/N Gain'
 * '<S44>'  : 'GOPIO/PI Controller/P Copy'
 * '<S45>'  : 'GOPIO/PI Controller/Parallel P Gain'
 * '<S46>'  : 'GOPIO/PI Controller/Reset Signal'
 * '<S47>'  : 'GOPIO/PI Controller/Saturation'
 * '<S48>'  : 'GOPIO/PI Controller/Saturation Fdbk'
 * '<S49>'  : 'GOPIO/PI Controller/Sum'
 * '<S50>'  : 'GOPIO/PI Controller/Sum Fdbk'
 * '<S51>'  : 'GOPIO/PI Controller/Tracking Mode'
 * '<S52>'  : 'GOPIO/PI Controller/Tracking Mode Sum'
 * '<S53>'  : 'GOPIO/PI Controller/Tsamp - Integral'
 * '<S54>'  : 'GOPIO/PI Controller/Tsamp - Ngain'
 * '<S55>'  : 'GOPIO/PI Controller/postSat Signal'
 * '<S56>'  : 'GOPIO/PI Controller/preSat Signal'
 * '<S57>'  : 'GOPIO/PI Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S58>'  : 'GOPIO/PI Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S59>'  : 'GOPIO/PI Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S60>'  : 'GOPIO/PI Controller/D Gain/Disabled'
 * '<S61>'  : 'GOPIO/PI Controller/External Derivative/Disabled'
 * '<S62>'  : 'GOPIO/PI Controller/Filter/Disabled'
 * '<S63>'  : 'GOPIO/PI Controller/Filter ICs/Disabled'
 * '<S64>'  : 'GOPIO/PI Controller/I Gain/External Parameters'
 * '<S65>'  : 'GOPIO/PI Controller/Ideal P Gain/Passthrough'
 * '<S66>'  : 'GOPIO/PI Controller/Ideal P Gain Fdbk/Disabled'
 * '<S67>'  : 'GOPIO/PI Controller/Integrator/Discrete'
 * '<S68>'  : 'GOPIO/PI Controller/Integrator ICs/External IC'
 * '<S69>'  : 'GOPIO/PI Controller/N Copy/Disabled wSignal Specification'
 * '<S70>'  : 'GOPIO/PI Controller/N Gain/Disabled'
 * '<S71>'  : 'GOPIO/PI Controller/P Copy/Disabled'
 * '<S72>'  : 'GOPIO/PI Controller/Parallel P Gain/External Parameters'
 * '<S73>'  : 'GOPIO/PI Controller/Reset Signal/Disabled'
 * '<S74>'  : 'GOPIO/PI Controller/Saturation/Enabled'
 * '<S75>'  : 'GOPIO/PI Controller/Saturation Fdbk/Disabled'
 * '<S76>'  : 'GOPIO/PI Controller/Sum/Sum_PI'
 * '<S77>'  : 'GOPIO/PI Controller/Sum Fdbk/Disabled'
 * '<S78>'  : 'GOPIO/PI Controller/Tracking Mode/Disabled'
 * '<S79>'  : 'GOPIO/PI Controller/Tracking Mode Sum/Passthrough'
 * '<S80>'  : 'GOPIO/PI Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S81>'  : 'GOPIO/PI Controller/Tsamp - Ngain/Passthrough'
 * '<S82>'  : 'GOPIO/PI Controller/postSat Signal/Forward_Path'
 * '<S83>'  : 'GOPIO/PI Controller/preSat Signal/Forward_Path'
 * '<S84>'  : 'GOPIO/PWM Output/ECSoC'
 * '<S85>'  : 'GOPIO/PWM Output/ECSoC/ECSimCodegen'
 * '<S86>'  : 'GOPIO/PWM Reference Generator1/Modulation method'
 * '<S87>'  : 'GOPIO/PWM Reference Generator1/Voltage Input'
 * '<S88>'  : 'GOPIO/PWM Reference Generator1/Modulation method/SVPWM'
 * '<S89>'  : 'GOPIO/PWM Reference Generator1/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S90>'  : 'GOPIO/PWM Reference Generator1/Voltage Input/Valphabeta'
 * '<S91>'  : 'GOPIO/PWM Reference Generator1/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S92>'  : 'GOPIO/PWM Reference Generator1/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S93>'  : 'GOPIO/Park Transform/Sine Cosine'
 * '<S94>'  : 'GOPIO/Park Transform/Two inputs CRL'
 * '<S95>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup'
 * '<S96>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/Interpolation'
 * '<S97>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp'
 * '<S98>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S99>'  : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S100>' : 'GOPIO/Park Transform/Sine Cosine/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S101>' : 'GOPIO/Park Transform/Two inputs CRL/Switch_Axis'
 */
#endif                                 /* GOPIO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
