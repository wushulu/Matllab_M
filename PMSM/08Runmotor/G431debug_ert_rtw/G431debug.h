/*
 * File: G431debug.h
 *
 * Code generated for Simulink model 'G431debug'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct 22 16:35:15 2024
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
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#endif                                 /* G431debug_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "G431debug_types.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block states (default storage) for system '<S98>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S98>/If Action Subsystem6' */
} DW_IfActionSubsystem6_G431deb_T;

/* Block states (default storage) for system '<S98>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S98>/If Action Subsystem' */
} DW_IfActionSubsystem_G431debu_T;

/* Block signals for system '<S96>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S98>/Merge' */
  uint16_T Merge1;                     /* '<S98>/Merge1' */
  uint16_T Merge3;                     /* '<S98>/Merge3' */
  int16_T Merge2;                      /* '<S98>/Merge2' */
} B_ValidHalls_G431debug_T;

/* Block states (default storage) for system '<S96>/Valid Halls' */
typedef struct {
  int8_T ValidHalls_SubsysRanBC;       /* '<S96>/Valid Halls' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                      /* '<S98>/Switch Case Action Subsystem' */
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S98>/If Action Subsystem8' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem5;/* '<S98>/If Action Subsystem5' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem4;/* '<S98>/If Action Subsystem4' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem3;/* '<S98>/If Action Subsystem3' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem2;/* '<S98>/If Action Subsystem2' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem1;/* '<S98>/If Action Subsystem1' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem;/* '<S98>/If Action Subsystem' */
  DW_IfActionSubsystem6_G431deb_T IfActionSubsystem7;/* '<S98>/If Action Subsystem7' */
  DW_IfActionSubsystem6_G431deb_T IfActionSubsystem6;/* '<S98>/If Action Subsystem6' */
} DW_ValidHalls_G431debug_T;

/* Block states (default storage) for system '<S96>/Bad hall (glitch or wrong connection)' */
typedef struct {
  int8_T Badhallglitchorwrongconnection_;
                             /* '<S96>/Bad hall (glitch or wrong connection)' */
} DW_Badhallglitchorwrongconnec_T;

/* Block signals (default storage) */
typedef struct {
  uint32_T Add1_c;                     /* '<S22>/Add1' */
  uint32_T HallCt;                     /* '<Root>/Rate Transition1' */
  real32_T scaleOut;                   /* '<S25>/scaleOut' */
  real32_T Add1_j;                     /* '<S26>/Add1' */
  real32_T Input;                      /* '<S27>/Input' */
  uint16_T testct;                     /* '<Root>/Rate Transition' */
  uint16_T Output;                     /* '<S9>/Output' */
  boolean_T Compare;                   /* '<S19>/Compare' */
  B_ValidHalls_G431debug_T ValidHalls_b;/* '<S121>/Valid Halls' */
  B_ValidHalls_G431debug_T ValidHalls_p;/* '<S71>/Valid Halls' */
  B_ValidHalls_G431debug_T ValidHalls; /* '<S96>/Valid Halls' */
} B_G431debug_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S13>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_G4_T obj_i;/* '<S47>/PWM Output' */
  stm32cube_blocks_TimerCapture_T obj_p;/* '<S111>/Timer Capture' */
  stm32cube_blocks_TimerCapture_T obj_a;/* '<S61>/Timer Capture' */
  stm32cube_blocks_TimerCapture_T obj_k;/* '<S86>/Timer Capture' */
  real_T UnitDelay_DSTATE;             /* '<S39>/Unit Delay' */
  real_T HallAcapture;                 /* '<Root>/Data Store Memory2' */
  real32_T Delay_DSTATE;               /* '<S28>/Delay' */
  real32_T UnitDelay_DSTATE_i;         /* '<S25>/Unit Delay' */
  real32_T Delay_DSTATE_g;             /* '<S24>/Delay' */
  uint32_T Delay_DSTATE_h;             /* '<S22>/Delay' */
  int32_T clockTickCounter;            /* '<S7>/Pulse Generator' */
  uint32_T Timehall;                   /* '<Root>/Data Store Memory3' */
  uint16_T Delay_DSTATE_m;             /* '<S111>/Delay' */
  uint16_T Delay_DSTATE_d;             /* '<S61>/Delay' */
  uint16_T Delay_DSTATE_k;             /* '<S86>/Delay' */
  uint16_T Output_DSTATE;              /* '<S9>/Output' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory5' */
  uint16_T Timercntprev;               /* '<Root>/Data Store Memory1' */
  uint16_T GlobalSpeedCount;           /* '<Root>/Data Store Memory6' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory7' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory8' */
  boolean_T Delay_DSTATE_p;            /* '<S26>/Delay' */
  int8_T HALL_C_SubsysRanBC;           /* '<Root>/HALL_C' */
  int8_T HALL_A_SubsysRanBC;           /* '<Root>/HALL_A' */
  int8_T HALL_B_SubsysRanBC;           /* '<Root>/HALL_B' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S11>/Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S41>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S41>/If Action Subsystem' */
  int8_T FindOffset_SubsysRanBC;       /* '<S11>/Find Offset' */
  int8_T Subsystem_SubsysRanBC;        /* '<S28>/Subsystem' */
  int8_T PosGen_SubsysRanBC;           /* '<S10>/PosGen' */
  int8_T UpCounter_SubsysRanBC;        /* '<S16>/Up Counter' */
  int8_T Accumulate_SubsysRanBC;       /* '<S25>/Accumulate' */
  int8_T Subsystem_SubsysRanBC_o;      /* '<S26>/Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S21>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S21>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC_m;      /* '<S16>/Subsystem' */
  uint8_T GlobalHallState;             /* '<Root>/Data Store Memory' */
  boolean_T FindOffset_MODE;           /* '<S11>/Find Offset' */
  boolean_T PosGen_MODE;               /* '<S10>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S16>/Up Counter' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_n;
                            /* '<S121>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431debug_T ValidHalls_b;/* '<S121>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_f;
                             /* '<S71>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431debug_T ValidHalls_p;/* '<S71>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnection;
                             /* '<S96>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431debug_T ValidHalls;/* '<S96>/Valid Halls' */
} DW_G431debug_T;

/* Parameters for system: '<S98>/If Action Subsystem6' */
struct P_IfActionSubsystem6_G431debu_T_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S105>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S105>/Constant1'
                                        */
};

/* Parameters for system: '<S98>/If Action Subsystem' */
struct P_IfActionSubsystem_G431debug_T_ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S99>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S99>/next'
                                        */
};

/* Parameters for system: '<S96>/Valid Halls' */
struct P_ValidHalls_G431debug_T_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S98>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S107>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S98>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S98>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S98>/Merge3'
                                      */
  boolean_T Constant_Value_k;          /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S98>/Constant'
                                        */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem5;/* '<S98>/If Action Subsystem5' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem4;/* '<S98>/If Action Subsystem4' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem3;/* '<S98>/If Action Subsystem3' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem2;/* '<S98>/If Action Subsystem2' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem1;/* '<S98>/If Action Subsystem1' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem;/* '<S98>/If Action Subsystem' */
  P_IfActionSubsystem6_G431debu_T IfActionSubsystem7;/* '<S98>/If Action Subsystem7' */
  P_IfActionSubsystem6_G431debu_T IfActionSubsystem6;/* '<S98>/If Action Subsystem6' */
};

/* Parameters for system: '<S96>/Bad hall (glitch or wrong connection)' */
struct P_Badhallglitchorwrongconnect_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S97>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S97>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_G431debug_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S33>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S34>/Constant'
                                      */
  uint32_T Disablehostafter42seconds_const;
                              /* Mask Parameter: Disablehostafter42seconds_const
                               * Referenced by: '<S18>/Constant'
                               */
  uint32_T EnablePWMfor40seconds_const;
                                  /* Mask Parameter: EnablePWMfor40seconds_const
                                   * Referenced by: '<S19>/Constant'
                                   */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S15>/FixPt Switch'
                                        */
  real_T a_Value;                      /* Expression: 0
                                        * Referenced by: '<S36>/a'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S36>/One'
                                        */
  real_T FilterConstant_Value;         /* Expression: Filter_constant
                                        * Referenced by: '<S36>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value; /* Expression: 1 - Filter_constant
                                        * Referenced by: '<S36>/OneMinusFilterConstant'
                                        */
  real_T Offset_Y0;                    /* Computed Parameter: Offset_Y0
                                        * Referenced by: '<S35>/Offset'
                                        */
  real_T UseInputPort_Value;           /* Expression: FilterConstantInputType
                                        * Referenced by: '<S36>/UseInputPort'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S36>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S39>/Unit Delay'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S30>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T Offset_Y0_c;                  /* Computed Parameter: Offset_Y0_c
                                        * Referenced by: '<S31>/Offset'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant2_Value;              /* Expression: 100
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Constant2_Value_b;            /* Expression: 100
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant2_Value_p;            /* Expression: 100
                                        * Referenced by: '<S4>/Constant2'
                                        */
  real_T DataStoreMemory10_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory10'
                                         */
  real_T DataStoreMemory11_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory11'
                                         */
  real_T DataStoreMemory4_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory4'
                                        */
  real_T DataStoreMemory9_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory9'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S7>/Pulse Generator'
                                        */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  real32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S23>/Constant'
                                        */
  real32_T Constant1_Value_g;          /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S24>/Delay'
                                    */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S24>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S24>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Multiply_Gain;              /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S24>/Multiply'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S27>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S26>/theta_e'
                                        */
  real32_T Theta_Y0;                   /* Computed Parameter: Theta_Y0
                                        * Referenced by: '<S16>/Theta'
                                        */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S25>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition_a;
                             /* Computed Parameter: UnitDelay_InitialCondition_a
                              * Referenced by: '<S25>/Unit Delay'
                              */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S25>/scaleOut'
                                        */
  real32_T Delay_InitialCondition_b;
                                 /* Computed Parameter: Delay_InitialCondition_b
                                  * Referenced by: '<S28>/Delay'
                                  */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S58>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S58>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S58>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S58>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S58>/Ka'
                                        */
  real32_T one_by_two_Gain_k;          /* Computed Parameter: one_by_two_Gain_k
                                        * Referenced by: '<S55>/one_by_two'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S54>/Gain'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S30>/Gain'
                                        */
  real32_T PWM_Y0;                     /* Computed Parameter: PWM_Y0
                                        * Referenced by: '<S1>/PWM'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S42>/Constant'
                                        */
  real32_T Vd_Ref_Value;               /* Computed Parameter: Vd_Ref_Value
                                        * Referenced by: '<S32>/Vd_Ref'
                                        */
  real32_T Vq_Value;                   /* Computed Parameter: Vq_Value
                                        * Referenced by: '<S32>/Vq'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S29>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S41>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S29>/indexing'
                                        */
  uint32_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S3>/Out2'
                                        */
  uint32_T Out2_Y0_g;                  /* Computed Parameter: Out2_Y0_g
                                        * Referenced by: '<S2>/Out2'
                                        */
  uint32_T Out2_Y0_a;                  /* Computed Parameter: Out2_Y0_a
                                        * Referenced by: '<S4>/Out2'
                                        */
  uint32_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  uint32_T Count_Y0;                   /* Computed Parameter: Count_Y0
                                        * Referenced by: '<S22>/Count'
                                        */
  uint32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint32_T Delay_InitialCondition_e;
                                 /* Computed Parameter: Delay_InitialCondition_e
                                  * Referenced by: '<S22>/Delay'
                                  */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S21>/Count for 2 sec'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S29>/offset'
                                        */
  int16_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  uint16_T Gain_Gain_l;                /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S3>/Gain'
                                        */
  uint16_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S2>/Gain'
                                        */
  uint16_T Gain_Gain_i;                /* Computed Parameter: Gain_Gain_i
                                        * Referenced by: '<S4>/Gain'
                                        */
  uint16_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S15>/Constant'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S30>/stop'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S51>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S51>/Switch'
                                        */
  uint16_T ct_Y0;                      /* Computed Parameter: ct_Y0
                                        * Referenced by: '<S1>/ct'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S14>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S9>/Output'
                                   */
  uint16_T Delay_InitialCondition_i;
                                 /* Computed Parameter: Delay_InitialCondition_i
                                  * Referenced by: '<S86>/Delay'
                                  */
  uint16_T Constant_Value_l5;          /* Computed Parameter: Constant_Value_l5
                                        * Referenced by: '<S85>/Constant'
                                        */
  uint16_T Delay_InitialCondition_c;
                                 /* Computed Parameter: Delay_InitialCondition_c
                                  * Referenced by: '<S61>/Delay'
                                  */
  uint16_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S60>/Constant'
                                        */
  uint16_T Delay_InitialCondition_h;
                                 /* Computed Parameter: Delay_InitialCondition_h
                                  * Referenced by: '<S111>/Delay'
                                  */
  uint16_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S110>/Constant'
                                        */
  uint16_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint16_T DataStoreMemory6_InitialValue;
                            /* Computed Parameter: DataStoreMemory6_InitialValue
                             * Referenced by: '<Root>/Data Store Memory6'
                             */
  uint16_T DataStoreMemory7_InitialValue;
                            /* Computed Parameter: DataStoreMemory7_InitialValue
                             * Referenced by: '<Root>/Data Store Memory7'
                             */
  uint16_T DataStoreMemory8_InitialValue;
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  boolean_T Delay_InitialCondition_f;
                                 /* Computed Parameter: Delay_InitialCondition_f
                                  * Referenced by: '<S26>/Delay'
                                  */
  boolean_T Constant_Value_f;          /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S26>/Constant'
                                        */
  boolean_T EnPWM_Y0;                  /* Computed Parameter: EnPWM_Y0
                                        * Referenced by: '<S16>/EnPWM'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S25>/Constant_Reset'
                                      */
  uint8_T Gain_Gain_d;                 /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S84>/Gain'
                                        */
  uint8_T Gain_Gain_j;                 /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S59>/Gain'
                                        */
  uint8_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S109>/Gain'
                                        */
  uint8_T Gain1_Gain_n;                /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S84>/Gain1'
                                        */
  uint8_T Gain1_Gain_o;                /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S59>/Gain1'
                                        */
  uint8_T Gain1_Gain_oh;               /* Computed Parameter: Gain1_Gain_oh
                                        * Referenced by: '<S109>/Gain1'
                                        */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_n;
                            /* '<S121>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431debug_T ValidHalls_b;/* '<S121>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_f;
                             /* '<S71>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431debug_T ValidHalls_p;/* '<S71>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnection;
                             /* '<S96>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431debug_T ValidHalls; /* '<S96>/Valid Halls' */
};

/* Real-time Model Data Structure */
struct tag_RTM_G431debug_T {
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
    uint32_T clockTick4;
    uint32_T clockTick5;
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_G431debug_T G431debug_P;

/* Block signals (default storage) */
extern B_G431debug_T G431debug_B;

/* Block states (default storage) */
extern DW_G431debug_T G431debug_DW;

/* External function called from main */
extern void G431debug_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void G431debug_initialize(void);
extern void G431debug_step0(void);
extern void G431debug_step1(void);
extern void G431debug_terminate(void);

/* Real-time Model object */
extern RT_MODEL_G431debug_T *const G431debug_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC1_2_IRQHandler(void);
  void TIM3_IRQHandler(void);
  void G431debug_configure_interrupts (void);
  void G431debug_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Duplicate' : Unused code path elimination
 * Block '<S29>/Data Type Propagation' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate' : Unused code path elimination
 * Block '<S50>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S49>/Data Type Duplicate' : Unused code path elimination
 * Block '<S49>/Vc' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S29>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S85>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S110>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'G431debug'
 * '<S1>'   : 'G431debug/Function-Call Subsystem'
 * '<S2>'   : 'G431debug/HALL_A'
 * '<S3>'   : 'G431debug/HALL_B'
 * '<S4>'   : 'G431debug/HALL_C'
 * '<S5>'   : 'G431debug/Hardware Interrupt'
 * '<S6>'   : 'G431debug/Hardware Interrupt2'
 * '<S7>'   : 'G431debug/LED Heart'
 * '<S8>'   : 'G431debug/Function-Call Subsystem/Analog to Digital Converter'
 * '<S9>'   : 'G431debug/Function-Call Subsystem/Counter Limited1'
 * '<S10>'  : 'G431debug/Function-Call Subsystem/Subsystem'
 * '<S11>'  : 'G431debug/Function-Call Subsystem/Subsystem2'
 * '<S12>'  : 'G431debug/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S13>'  : 'G431debug/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S14>'  : 'G431debug/Function-Call Subsystem/Counter Limited1/Increment Real World'
 * '<S15>'  : 'G431debug/Function-Call Subsystem/Counter Limited1/Wrap To Zero'
 * '<S16>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen'
 * '<S17>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1'
 * '<S18>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Disable host after 42 seconds'
 * '<S19>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Enable PWM for 40 seconds'
 * '<S20>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Subsystem'
 * '<S21>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Subsystem1'
 * '<S22>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Up Counter'
 * '<S23>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/If Action Subsystem'
 * '<S24>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/If Action Subsystem2'
 * '<S25>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/Position Generator'
 * '<S26>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S27>'  : 'G431debug/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S28>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset'
 * '<S29>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup'
 * '<S30>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem'
 * '<S31>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem1'
 * '<S32>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2'
 * '<S33>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Compare To Constant'
 * '<S34>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Compare To Constant1'
 * '<S35>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem'
 * '<S36>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter'
 * '<S37>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S38>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S39>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S40>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/Interpolation'
 * '<S41>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp'
 * '<S42>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S43>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S44>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S45>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output'
 * '<S46>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output/ECSoC'
 * '<S47>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output/ECSoC/ECSimCodegen'
 * '<S48>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform'
 * '<S49>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator'
 * '<S50>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform/Two inputs CRL'
 * '<S51>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S52>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method'
 * '<S53>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input'
 * '<S54>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method/SVPWM'
 * '<S55>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S56>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S57>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S58>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S59>'  : 'G431debug/HALL_A/HALLVaule'
 * '<S60>'  : 'G431debug/HALL_A/Hall Validity'
 * '<S61>'  : 'G431debug/HALL_A/Subsystem'
 * '<S62>'  : 'G431debug/HALL_A/HALLVaule/HALLA'
 * '<S63>'  : 'G431debug/HALL_A/HALLVaule/HALLB'
 * '<S64>'  : 'G431debug/HALL_A/HALLVaule/HALLC'
 * '<S65>'  : 'G431debug/HALL_A/HALLVaule/HALLA/ECSoC'
 * '<S66>'  : 'G431debug/HALL_A/HALLVaule/HALLA/ECSoC/ECSimCodegen'
 * '<S67>'  : 'G431debug/HALL_A/HALLVaule/HALLB/ECSoC'
 * '<S68>'  : 'G431debug/HALL_A/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S69>'  : 'G431debug/HALL_A/HALLVaule/HALLC/ECSoC'
 * '<S70>'  : 'G431debug/HALL_A/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S71>'  : 'G431debug/HALL_A/Hall Validity/Subsystem'
 * '<S72>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S73>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls'
 * '<S74>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S75>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S76>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S77>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S78>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S79>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S80>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S81>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S82>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S83>'  : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S84>'  : 'G431debug/HALL_B/HALLVaule'
 * '<S85>'  : 'G431debug/HALL_B/Hall Validity'
 * '<S86>'  : 'G431debug/HALL_B/Subsystem'
 * '<S87>'  : 'G431debug/HALL_B/HALLVaule/HALLA'
 * '<S88>'  : 'G431debug/HALL_B/HALLVaule/HALLB'
 * '<S89>'  : 'G431debug/HALL_B/HALLVaule/HALLC'
 * '<S90>'  : 'G431debug/HALL_B/HALLVaule/HALLA/ECSoC'
 * '<S91>'  : 'G431debug/HALL_B/HALLVaule/HALLA/ECSoC/ECSimCodegen'
 * '<S92>'  : 'G431debug/HALL_B/HALLVaule/HALLB/ECSoC'
 * '<S93>'  : 'G431debug/HALL_B/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S94>'  : 'G431debug/HALL_B/HALLVaule/HALLC/ECSoC'
 * '<S95>'  : 'G431debug/HALL_B/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S96>'  : 'G431debug/HALL_B/Hall Validity/Subsystem'
 * '<S97>'  : 'G431debug/HALL_B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S98>'  : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls'
 * '<S99>'  : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S100>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S101>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S102>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S103>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S104>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S105>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S106>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S107>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S108>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S109>' : 'G431debug/HALL_C/HALLVaule'
 * '<S110>' : 'G431debug/HALL_C/Hall Validity'
 * '<S111>' : 'G431debug/HALL_C/Subsystem'
 * '<S112>' : 'G431debug/HALL_C/HALLVaule/HALLA'
 * '<S113>' : 'G431debug/HALL_C/HALLVaule/HALLB'
 * '<S114>' : 'G431debug/HALL_C/HALLVaule/HALLC'
 * '<S115>' : 'G431debug/HALL_C/HALLVaule/HALLA/ECSoC'
 * '<S116>' : 'G431debug/HALL_C/HALLVaule/HALLA/ECSoC/ECSimCodegen'
 * '<S117>' : 'G431debug/HALL_C/HALLVaule/HALLB/ECSoC'
 * '<S118>' : 'G431debug/HALL_C/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S119>' : 'G431debug/HALL_C/HALLVaule/HALLC/ECSoC'
 * '<S120>' : 'G431debug/HALL_C/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S121>' : 'G431debug/HALL_C/Hall Validity/Subsystem'
 * '<S122>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S123>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls'
 * '<S124>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S125>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S126>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S127>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S128>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S129>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S130>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S131>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S132>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S133>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S134>' : 'G431debug/Hardware Interrupt/ECSoC'
 * '<S135>' : 'G431debug/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S136>' : 'G431debug/Hardware Interrupt2/ECSoC'
 * '<S137>' : 'G431debug/Hardware Interrupt2/ECSoC/ECSimCodegen'
 * '<S138>' : 'G431debug/LED Heart/Digital Port Write'
 * '<S139>' : 'G431debug/LED Heart/Digital Port Write/ECSoC'
 * '<S140>' : 'G431debug/LED Heart/Digital Port Write/ECSoC/ECSimCodegen'
 */
#endif                                 /* G431debug_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
