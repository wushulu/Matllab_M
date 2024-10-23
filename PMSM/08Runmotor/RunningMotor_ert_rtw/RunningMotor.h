/*
 * File: RunningMotor.h
 *
 * Code generated for Simulink model 'RunningMotor'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Oct 18 11:53:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RunningMotor_h_
#define RunningMotor_h_
#ifndef RunningMotor_COMMON_INCLUDES_
#define RunningMotor_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#endif                                 /* RunningMotor_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "RunningMotor_types.h"
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
  uint32_T Add1_h;                     /* '<S19>/Add1' */
  real32_T PWM;                        /* '<Root>/RT1' */
  real32_T Sum6;                       /* '<S37>/Sum6' */
  real32_T scaleOut;                   /* '<S22>/scaleOut' */
  real32_T Add1_n;                     /* '<S23>/Add1' */
  real32_T Input;                      /* '<S24>/Input' */
  uint16_T testct;                     /* '<Root>/RT3' */
  uint16_T Output;                     /* '<S5>/Output' */
  boolean_T Compare;                   /* '<S16>/Compare' */
} B_RunningMotor_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S10>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Ru_T obj_m;/* '<S61>/PWM Output' */
  stm32cube_blocks_PWMOutput_Ru_T obj_h;/* '<S45>/PWM Output' */
  real_T UnitDelay_DSTATE;             /* '<S36>/Unit Delay' */
  real32_T Delay_DSTATE;               /* '<S25>/Delay' */
  real32_T UnitDelay_DSTATE_e;         /* '<S22>/Unit Delay' */
  real32_T Delay_DSTATE_f;             /* '<S21>/Delay' */
  uint32_T Delay_DSTATE_n;             /* '<S19>/Delay' */
  uint16_T Output_DSTATE;              /* '<S5>/Output' */
  boolean_T Delay_DSTATE_k;            /* '<S23>/Delay' */
  int8_T ADCSIC_SubsysRanBC;           /* '<Root>/ADC SIC' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S8>/Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S38>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S38>/If Action Subsystem' */
  int8_T FindOffset_SubsysRanBC;       /* '<S8>/Find Offset' */
  int8_T Subsystem_SubsysRanBC;        /* '<S25>/Subsystem' */
  int8_T PosGen_SubsysRanBC;           /* '<S7>/PosGen' */
  int8_T UpCounter_SubsysRanBC;        /* '<S13>/Up Counter' */
  int8_T Accumulate_SubsysRanBC;       /* '<S22>/Accumulate' */
  int8_T Subsystem_SubsysRanBC_d;      /* '<S23>/Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S18>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_m;/* '<S18>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC_dk;     /* '<S13>/Subsystem' */
  boolean_T FindOffset_MODE;           /* '<S8>/Find Offset' */
  boolean_T PosGen_MODE;               /* '<S7>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S13>/Up Counter' */
} DW_RunningMotor_T;

/* Parameters (default storage) */
struct P_RunningMotor_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S30>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S31>/Constant'
                                      */
  uint32_T Disablehostafter42seconds_const;
                              /* Mask Parameter: Disablehostafter42seconds_const
                               * Referenced by: '<S15>/Constant'
                               */
  uint32_T EnablePWMfor40seconds_const;
                                  /* Mask Parameter: EnablePWMfor40seconds_const
                                   * Referenced by: '<S16>/Constant'
                                   */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S12>/FixPt Switch'
                                        */
  real_T a_Value;                      /* Expression: 0
                                        * Referenced by: '<S33>/a'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S33>/One'
                                        */
  real_T FilterConstant_Value;         /* Expression: Filter_constant
                                        * Referenced by: '<S33>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value; /* Expression: 1 - Filter_constant
                                        * Referenced by: '<S33>/OneMinusFilterConstant'
                                        */
  real_T Offset_Y0;                    /* Computed Parameter: Offset_Y0
                                        * Referenced by: '<S32>/Offset'
                                        */
  real_T UseInputPort_Value;           /* Expression: FilterConstantInputType
                                        * Referenced by: '<S33>/UseInputPort'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S33>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S36>/Unit Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S42>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S42>/Gain1'
                                        */
  real_T Offset_Y0_i;                  /* Computed Parameter: Offset_Y0_i
                                        * Referenced by: '<S28>/Offset'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant1_Value_a;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S20>/Constant'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S21>/Delay'
                                    */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S21>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S21>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Multiply_Gain;              /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S21>/Multiply'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S24>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S23>/theta_e'
                                        */
  real32_T Theta_Y0;                   /* Computed Parameter: Theta_Y0
                                        * Referenced by: '<S13>/Theta'
                                        */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S22>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition_h;
                             /* Computed Parameter: UnitDelay_InitialCondition_h
                              * Referenced by: '<S22>/Unit Delay'
                              */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S22>/scaleOut'
                                        */
  real32_T Delay_InitialCondition_i;
                                 /* Computed Parameter: Delay_InitialCondition_i
                                  * Referenced by: '<S25>/Delay'
                                  */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S56>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S56>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S56>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S56>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S56>/Ka'
                                        */
  real32_T one_by_two_Gain_j;          /* Computed Parameter: one_by_two_Gain_j
                                        * Referenced by: '<S53>/one_by_two'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S52>/Gain'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S42>/Gain'
                                        */
  real32_T PWM_Y0;                     /* Computed Parameter: PWM_Y0
                                        * Referenced by: '<S1>/PWM'
                                        */
  real32_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S39>/Constant'
                                        */
  real32_T Vd_Ref_Value;               /* Computed Parameter: Vd_Ref_Value
                                        * Referenced by: '<S29>/Vd_Ref'
                                        */
  real32_T Vq_Value;                   /* Computed Parameter: Vq_Value
                                        * Referenced by: '<S29>/Vq'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S26>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S38>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S26>/indexing'
                                        */
  uint32_T Count_Y0;                   /* Computed Parameter: Count_Y0
                                        * Referenced by: '<S19>/Count'
                                        */
  uint32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S19>/Constant'
                                        */
  uint32_T Delay_InitialCondition_p;
                                 /* Computed Parameter: Delay_InitialCondition_p
                                  * Referenced by: '<S19>/Delay'
                                  */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S18>/Count for 2 sec'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S26>/offset'
                                        */
  uint16_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S42>/stop'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S49>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S49>/Switch'
                                        */
  uint16_T ct_Y0;                      /* Computed Parameter: ct_Y0
                                        * Referenced by: '<S1>/ct'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S11>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S5>/Output'
                                   */
  boolean_T Delay_InitialCondition_n;
                                 /* Computed Parameter: Delay_InitialCondition_n
                                  * Referenced by: '<S23>/Delay'
                                  */
  boolean_T Constant_Value_nl;         /* Computed Parameter: Constant_Value_nl
                                        * Referenced by: '<S23>/Constant'
                                        */
  boolean_T EnPWM_Y0;                  /* Computed Parameter: EnPWM_Y0
                                        * Referenced by: '<S13>/EnPWM'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S22>/Constant_Reset'
                                      */
};

/* Real-time Model Data Structure */
struct tag_RTM_RunningMotor_T {
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
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_RunningMotor_T RunningMotor_P;

/* Block signals (default storage) */
extern B_RunningMotor_T RunningMotor_B;

/* Block states (default storage) */
extern DW_RunningMotor_T RunningMotor_DW;

/* Model entry point functions */
extern void RunningMotor_initialize(void);
extern void RunningMotor_step(void);
extern void RunningMotor_terminate(void);

/* Real-time Model object */
extern RT_MODEL_RunningMotor_T *const RunningMotor_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC_IRQHandler(void);
  void RunningMotor_configure_interrupts (void);
  void RunningMotor_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S6>/Data Type' : Unused code path elimination
 * Block '<S6>/Number of pole pairs' : Unused code path elimination
 * Block '<S6>/PWM Frequency' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S33>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S41>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate' : Unused code path elimination
 * Block '<S48>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Vc' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/Data Type' : Unused code path elimination
 * Block '<S3>/Number of pole pairs' : Unused code path elimination
 * Block '<S3>/PWM Frequency' : Unused code path elimination
 * Block '<S26>/Get_FractionVal' : Eliminate redundant data type conversion
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
 * '<Root>' : 'RunningMotor'
 * '<S1>'   : 'RunningMotor/ADC SIC'
 * '<S2>'   : 'RunningMotor/Hardware Interrupt2'
 * '<S3>'   : 'RunningMotor/Parameters'
 * '<S4>'   : 'RunningMotor/ADC SIC/Analog to Digital Converter'
 * '<S5>'   : 'RunningMotor/ADC SIC/Counter Limited1'
 * '<S6>'   : 'RunningMotor/ADC SIC/Parameters'
 * '<S7>'   : 'RunningMotor/ADC SIC/Subsystem'
 * '<S8>'   : 'RunningMotor/ADC SIC/Subsystem2'
 * '<S9>'   : 'RunningMotor/ADC SIC/Analog to Digital Converter/ECSoC'
 * '<S10>'  : 'RunningMotor/ADC SIC/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S11>'  : 'RunningMotor/ADC SIC/Counter Limited1/Increment Real World'
 * '<S12>'  : 'RunningMotor/ADC SIC/Counter Limited1/Wrap To Zero'
 * '<S13>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen'
 * '<S14>'  : 'RunningMotor/ADC SIC/Subsystem/Subsystem1'
 * '<S15>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Disable host after 42 seconds'
 * '<S16>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Enable PWM for 40 seconds'
 * '<S17>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Subsystem'
 * '<S18>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Subsystem1'
 * '<S19>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Up Counter'
 * '<S20>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Subsystem1/If Action Subsystem'
 * '<S21>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Subsystem1/If Action Subsystem2'
 * '<S22>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator'
 * '<S23>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S24>'  : 'RunningMotor/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S25>'  : 'RunningMotor/ADC SIC/Subsystem2/Find Offset'
 * '<S26>'  : 'RunningMotor/ADC SIC/Subsystem2/Sine-Cosine Lookup'
 * '<S27>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem'
 * '<S28>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem1'
 * '<S29>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2'
 * '<S30>'  : 'RunningMotor/ADC SIC/Subsystem2/Find Offset/Compare To Constant'
 * '<S31>'  : 'RunningMotor/ADC SIC/Subsystem2/Find Offset/Compare To Constant1'
 * '<S32>'  : 'RunningMotor/ADC SIC/Subsystem2/Find Offset/Subsystem'
 * '<S33>'  : 'RunningMotor/ADC SIC/Subsystem2/Find Offset/Subsystem/IIR Filter'
 * '<S34>'  : 'RunningMotor/ADC SIC/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S35>'  : 'RunningMotor/ADC SIC/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S36>'  : 'RunningMotor/ADC SIC/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S37>'  : 'RunningMotor/ADC SIC/Subsystem2/Sine-Cosine Lookup/Interpolation'
 * '<S38>'  : 'RunningMotor/ADC SIC/Subsystem2/Sine-Cosine Lookup/WrapUp'
 * '<S39>'  : 'RunningMotor/ADC SIC/Subsystem2/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S40>'  : 'RunningMotor/ADC SIC/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S41>'  : 'RunningMotor/ADC SIC/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S42>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem/PWM'
 * '<S43>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem/PWM/PWM Output'
 * '<S44>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem/PWM/PWM Output/ECSoC'
 * '<S45>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem/PWM/PWM Output/ECSoC/ECSimCodegen'
 * '<S46>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/Inverse Park Transform'
 * '<S47>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/PWM Reference Generator'
 * '<S48>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/Inverse Park Transform/Two inputs CRL'
 * '<S49>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S50>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method'
 * '<S51>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input'
 * '<S52>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method/SVPWM'
 * '<S53>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S54>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S55>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S56>'  : 'RunningMotor/ADC SIC/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S57>'  : 'RunningMotor/Hardware Interrupt2/ECSoC'
 * '<S58>'  : 'RunningMotor/Hardware Interrupt2/ECSoC/ECSimCodegen'
 * '<S59>'  : 'RunningMotor/Parameters/PWM Output'
 * '<S60>'  : 'RunningMotor/Parameters/PWM Output/ECSoC'
 * '<S61>'  : 'RunningMotor/Parameters/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* RunningMotor_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
