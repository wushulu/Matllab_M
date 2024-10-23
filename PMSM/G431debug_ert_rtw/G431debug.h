/*
 * File: G431debug.h
 *
 * Code generated for Simulink model 'G431debug'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct 22 17:37:57 2024
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

/* Block states (default storage) for system '<S47>/Hall Value of 1' */
typedef struct {
  int8_T HallValueof1_SubsysRanBC;     /* '<S47>/Hall Value of 1' */
} DW_HallValueof1_G431debug_T;

/* Block states (default storage) for system '<S134>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S134>/If Action Subsystem6' */
} DW_IfActionSubsystem6_G431deb_T;

/* Block states (default storage) for system '<S134>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S134>/If Action Subsystem' */
} DW_IfActionSubsystem_G431debu_T;

/* Block signals for system '<S132>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S134>/Merge' */
  uint16_T Merge1;                     /* '<S134>/Merge1' */
  uint16_T Merge3;                     /* '<S134>/Merge3' */
  int16_T Merge2;                      /* '<S134>/Merge2' */
} B_ValidHalls_G431debug_T;

/* Block states (default storage) for system '<S132>/Valid Halls' */
typedef struct {
  int8_T ValidHalls_SubsysRanBC;       /* '<S132>/Valid Halls' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                     /* '<S134>/Switch Case Action Subsystem' */
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S134>/If Action Subsystem8' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem5;/* '<S134>/If Action Subsystem5' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem4;/* '<S134>/If Action Subsystem4' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem3;/* '<S134>/If Action Subsystem3' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem2;/* '<S134>/If Action Subsystem2' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem1;/* '<S134>/If Action Subsystem1' */
  DW_IfActionSubsystem_G431debu_T IfActionSubsystem;/* '<S134>/If Action Subsystem' */
  DW_IfActionSubsystem6_G431deb_T IfActionSubsystem7;/* '<S134>/If Action Subsystem7' */
  DW_IfActionSubsystem6_G431deb_T IfActionSubsystem6;/* '<S134>/If Action Subsystem6' */
} DW_ValidHalls_G431debug_T;

/* Block states (default storage) for system '<S132>/Bad hall (glitch or wrong connection)' */
typedef struct {
  int8_T Badhallglitchorwrongconnection_;
                            /* '<S132>/Bad hall (glitch or wrong connection)' */
} DW_Badhallglitchorwrongconnec_T;

/* Block signals (default storage) */
typedef struct {
  real_T rtb_Switch4_idx_0;
  uint32_T Add1;                       /* '<S22>/Add1' */
  uint32_T HallCt;                     /* '<Root>/Rate Transition1' */
  real32_T pstheta;                    /* '<Root>/Rate Transition3' */
  real32_T Psw;                        /* '<Root>/Rate Transition4' */
  real32_T Gain1;                      /* '<S17>/Gain1' */
  real32_T PositionUnit;               /* '<S28>/PositionUnit' */
  real32_T Merge;                      /* '<S45>/Merge' */
  real32_T scaleOut;                   /* '<S25>/scaleOut' */
  real32_T Add1_j;                     /* '<S26>/Add1' */
  real32_T Input;                      /* '<S27>/Input' */
  uint16_T testct;                     /* '<Root>/Rate Transition' */
  uint16_T DelayOneStep;               /* '<S30>/Delay One Step' */
  uint16_T speedCountDelay;            /* '<S29>/speedCountDelay' */
  uint16_T Output;                     /* '<S9>/Output' */
  uint8_T Halls;                       /* '<Root>/Rate Transition2' */
  boolean_T validityDelay;             /* '<S29>/validityDelay' */
  boolean_T Compare;                   /* '<S19>/Compare' */
  B_ValidHalls_G431debug_T ValidHalls_b;/* '<S157>/Valid Halls' */
  B_ValidHalls_G431debug_T ValidHalls_p;/* '<S107>/Valid Halls' */
  B_ValidHalls_G431debug_T ValidHalls; /* '<S132>/Valid Halls' */
} B_G431debug_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S13>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_G4_T obj_i;/* '<S83>/PWM Output' */
  stm32cube_blocks_TimerCapture_T obj_e;/* '<S4>/Timer Capture' */
  stm32cube_blocks_TimerCapture_T obj_a;/* '<S2>/Timer Capture' */
  stm32cube_blocks_TimerCapture_T obj_h;/* '<S3>/Timer Capture' */
  real_T HallCcapture;                 /* '<Root>/Data Store Memory10' */
  real_T HallAcapture;                 /* '<Root>/Data Store Memory2' */
  real_T HallBcapture;                 /* '<Root>/Data Store Memory4' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S17>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE;               /* '<S64>/Delay' */
  real32_T UnitDelay_DSTATE;           /* '<S75>/Unit Delay' */
  real32_T UnitDelay_DSTATE_i;         /* '<S25>/Unit Delay' */
  real32_T Delay_DSTATE_g;             /* '<S24>/Delay' */
  uint32_T Delay_DSTATE_h;             /* '<S22>/Delay' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S17>/Discrete-Time Integrator' */
  int32_T clockTickCounter;            /* '<S7>/Pulse Generator' */
  uint32_T FunctionCallSubsystem_PREV_T;/* '<Root>/Function-Call Subsystem' */
  uint32_T Timehall;                   /* '<Root>/Data Store Memory3' */
  uint16_T DelayOneStep_DSTATE;        /* '<S30>/Delay One Step' */
  uint16_T speedCountDelay_DSTATE;     /* '<S29>/speedCountDelay' */
  uint16_T Output_DSTATE;              /* '<S9>/Output' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory5' */
  int16_T Timercntprev;                /* '<Root>/Data Store Memory1' */
  uint16_T GlobalSpeedCount;           /* '<Root>/Data Store Memory6' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory7' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory8' */
  boolean_T validityDelay_DSTATE;      /* '<S29>/validityDelay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S30>/Delay One Step1' */
  boolean_T Delay_DSTATE_p;            /* '<S26>/Delay' */
  int8_T HALL_C_SubsysRanBC;           /* '<Root>/HALL_C' */
  int8_T HALL_A_SubsysRanBC;           /* '<Root>/HALL_A' */
  int8_T HALL_B_SubsysRanBC;           /* '<Root>/HALL_B' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S17>/Discrete-Time Integrator' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S11>/Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S77>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S77>/If Action Subsystem' */
  int8_T FindOffset_SubsysRanBC;       /* '<S11>/Find Offset' */
  int8_T Subsystem_SubsysRanBC;        /* '<S64>/Subsystem' */
  int8_T SpeedanddirectionarenotvalidPos;
  /* '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
  int8_T SpeedanddirectionarevalidUsespe;
  /* '<S28>/Speed and direction are valid Use speed to extrapolate position' */
  int8_T Subsystem1_SubsysRanBC_m;     /* '<S32>/Subsystem1' */
  int8_T first_order_SubsysRanBC;      /* '<S45>/first_order' */
  int8_T second_order_SubsysRanBC;     /* '<S45>/second_order' */
  int8_T veDirection_SubsysRanBC;      /* '<S45>/+ve Direction' */
  int8_T veDirection_SubsysRanBC_h;    /* '<S45>/-ve Direction' */
  int8_T IfActionSubsystem1_SubsysRanB_p;/* '<S32>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_k;/* '<S32>/If Action Subsystem' */
  int8_T PosGen_SubsysRanBC;           /* '<S10>/PosGen' */
  int8_T UpCounter_SubsysRanBC;        /* '<S16>/Up Counter' */
  int8_T Accumulate_SubsysRanBC;       /* '<S25>/Accumulate' */
  int8_T Subsystem_SubsysRanBC_o;      /* '<S26>/Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S21>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S21>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC_m;      /* '<S16>/Subsystem' */
  uint8_T GlobalHallState;             /* '<Root>/Data Store Memory' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S17>/Discrete-Time Integrator' */
  boolean_T FunctionCallSubsystem_RESET_ELA;/* '<Root>/Function-Call Subsystem' */
  boolean_T FindOffset_MODE;           /* '<S11>/Find Offset' */
  boolean_T PosGen_MODE;               /* '<S10>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S16>/Up Counter' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_n;
                            /* '<S157>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431debug_T ValidHalls_b;/* '<S157>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_f;
                            /* '<S107>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431debug_T ValidHalls_p;/* '<S107>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnection;
                            /* '<S132>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431debug_T ValidHalls;/* '<S132>/Valid Halls' */
  DW_HallValueof1_G431debug_T HallValueof7_e;/* '<S35>/Hall Value of 7' */
  DW_HallValueof1_G431debug_T HallValueof6_m;/* '<S35>/Hall Value of 6' */
  DW_HallValueof1_G431debug_T HallValueof5_j;/* '<S35>/Hall Value of 5' */
  DW_HallValueof1_G431debug_T HallValueof4_e;/* '<S35>/Hall Value of 4' */
  DW_HallValueof1_G431debug_T HallValueof3_b;/* '<S35>/Hall Value of 3' */
  DW_HallValueof1_G431debug_T HallValueof2_o;/* '<S35>/Hall Value of 2' */
  DW_HallValueof1_G431debug_T HallValueof1_e;/* '<S35>/Hall Value of 1' */
  DW_HallValueof1_G431debug_T HallValueof7_b;/* '<S46>/Hall Value of 7' */
  DW_HallValueof1_G431debug_T HallValueof6_g;/* '<S46>/Hall Value of 6' */
  DW_HallValueof1_G431debug_T HallValueof5_o;/* '<S46>/Hall Value of 5' */
  DW_HallValueof1_G431debug_T HallValueof4_l;/* '<S46>/Hall Value of 4' */
  DW_HallValueof1_G431debug_T HallValueof3_p;/* '<S46>/Hall Value of 3' */
  DW_HallValueof1_G431debug_T HallValueof2_p;/* '<S46>/Hall Value of 2' */
  DW_HallValueof1_G431debug_T HallValueof1_b;/* '<S46>/Hall Value of 1' */
  DW_HallValueof1_G431debug_T HallValueof7;/* '<S47>/Hall Value of 7' */
  DW_HallValueof1_G431debug_T HallValueof6;/* '<S47>/Hall Value of 6' */
  DW_HallValueof1_G431debug_T HallValueof5;/* '<S47>/Hall Value of 5' */
  DW_HallValueof1_G431debug_T HallValueof4;/* '<S47>/Hall Value of 4' */
  DW_HallValueof1_G431debug_T HallValueof3;/* '<S47>/Hall Value of 3' */
  DW_HallValueof1_G431debug_T HallValueof2;/* '<S47>/Hall Value of 2' */
  DW_HallValueof1_G431debug_T HallValueof1;/* '<S47>/Hall Value of 1' */
} DW_G431debug_T;

/* Parameters for system: '<S47>/Hall Value of 1' */
struct P_HallValueof1_G431debug_T_ {
  real32_T Constant_Value;             /* Expression: single(0.16667)
                                        * Referenced by: '<S57>/Constant'
                                        */
};

/* Parameters for system: '<S134>/If Action Subsystem6' */
struct P_IfActionSubsystem6_G431debu_T_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S141>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S141>/Constant1'
                                        */
};

/* Parameters for system: '<S134>/If Action Subsystem' */
struct P_IfActionSubsystem_G431debug_T_ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S135>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S135>/next'
                                        */
};

/* Parameters for system: '<S132>/Valid Halls' */
struct P_ValidHalls_G431debug_T_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S134>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S143>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S134>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S134>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S134>/Merge3'
                                      */
  boolean_T Constant_Value_k;          /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S134>/Constant'
                                        */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem5;/* '<S134>/If Action Subsystem5' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem4;/* '<S134>/If Action Subsystem4' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem3;/* '<S134>/If Action Subsystem3' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem2;/* '<S134>/If Action Subsystem2' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem1;/* '<S134>/If Action Subsystem1' */
  P_IfActionSubsystem_G431debug_T IfActionSubsystem;/* '<S134>/If Action Subsystem' */
  P_IfActionSubsystem6_G431debu_T IfActionSubsystem7;/* '<S134>/If Action Subsystem7' */
  P_IfActionSubsystem6_G431debu_T IfActionSubsystem6;/* '<S134>/If Action Subsystem6' */
};

/* Parameters for system: '<S132>/Bad hall (glitch or wrong connection)' */
struct P_Badhallglitchorwrongconnect_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S133>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S133>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_G431debug_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S69>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S70>/Constant'
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
  uint16_T SoftwareWatchdogTimer_maxCount;
                               /* Mask Parameter: SoftwareWatchdogTimer_maxCount
                                * Referenced by: '<S30>/Delay One Step'
                                */
  real_T Constant_Value;               /* Expression: EnableSecondOrder
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S66>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S66>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S17>/Discrete-Time Integrator'
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
  real_T DataStoreMemory11_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory11'
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
  real_T DataStoreMemory10_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory10'
                                         */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  real_T DataStoreMemory4_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory4'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
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
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S25>/Unit Delay'
                                */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S25>/scaleOut'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S49>/Constant'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S49>/Gain1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S49>/Gain'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S48>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Expression: single(0.16667)
                                        * Referenced by: '<S45>/Saturation'
                                        */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S45>/Saturation'
                                       */
  real32_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S45>/Merge'
                                       */
  real32_T SpeedGain_Gain;             /* Expression: single(6*MinSpeed)
                                        * Referenced by: '<S32>/SpeedGain'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S31>/Constant'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S72>/a'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S72>/One'
                                        */
  real32_T FilterConstant_Value;     /* Computed Parameter: FilterConstant_Value
                                      * Referenced by: '<S72>/FilterConstant'
                                      */
  real32_T OneMinusFilterConstant_Value;
                             /* Computed Parameter: OneMinusFilterConstant_Value
                              * Referenced by: '<S72>/OneMinusFilterConstant'
                              */
  real32_T Offset_Y0;                  /* Computed Parameter: Offset_Y0
                                        * Referenced by: '<S71>/Offset'
                                        */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S72>/UseInputPort'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S72>/Switch1'
                                        */
  real32_T UnitDelay_InitialCondition_l;
                             /* Computed Parameter: UnitDelay_InitialCondition_l
                              * Referenced by: '<S75>/Unit Delay'
                              */
  real32_T Delay_InitialCondition_b;
                                 /* Computed Parameter: Delay_InitialCondition_b
                                  * Referenced by: '<S64>/Delay'
                                  */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S94>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S94>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S94>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S94>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S94>/Ka'
                                        */
  real32_T one_by_two_Gain_k;          /* Computed Parameter: one_by_two_Gain_k
                                        * Referenced by: '<S91>/one_by_two'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S90>/Gain'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S66>/Gain'
                                        */
  real32_T Offset_Y0_c;                /* Computed Parameter: Offset_Y0_c
                                        * Referenced by: '<S67>/Offset'
                                        */
  real32_T PWM_Y0;                     /* Computed Parameter: PWM_Y0
                                        * Referenced by: '<S1>/PWM'
                                        */
  real32_T posw_Y0;                    /* Computed Parameter: posw_Y0
                                        * Referenced by: '<S1>/posw'
                                        */
  real32_T Theta_Y0_d;                 /* Computed Parameter: Theta_Y0_d
                                        * Referenced by: '<S1>/Theta'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S78>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S17>/Discrete-Time Integrator'
                                 */
  real32_T DiscreteTimeIntegrator_UpperSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                           * Referenced by: '<S17>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_LowerSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                           * Referenced by: '<S17>/Discrete-Time Integrator'
                           */
  real32_T Gain1_Gain_p;               /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real32_T PositionUnit_Gain;          /* Expression: single(360)
                                        * Referenced by: '<S28>/PositionUnit'
                                        */
  real32_T Vd_Ref_Value;               /* Computed Parameter: Vd_Ref_Value
                                        * Referenced by: '<S68>/Vd_Ref'
                                        */
  real32_T Vq_Value;                   /* Computed Parameter: Vq_Value
                                        * Referenced by: '<S68>/Vq'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S65>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S77>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S65>/indexing'
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
                                        * Referenced by: '<S65>/offset'
                                        */
  int16_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  int16_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
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
  uint16_T SpeedConst_Value;
                          /* Expression: uint16(10*ClkFreq/(PolePairs*MinSpeed))
                           * Referenced by: '<S32>/SpeedConst'
                           */
  uint16_T PositionEnable_Value;     /* Computed Parameter: PositionEnable_Value
                                      * Referenced by: '<S32>/PositionEnable'
                                      */
  uint16_T WatchDog_Value;             /* Computed Parameter: WatchDog_Value
                                        * Referenced by: '<S28>/WatchDog'
                                        */
  uint16_T speedcheck_Threshold;     /* Computed Parameter: speedcheck_Threshold
                                      * Referenced by: '<S33>/speed check'
                                      */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S66>/stop'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S87>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S87>/Switch'
                                        */
  uint16_T ct_Y0;                      /* Computed Parameter: ct_Y0
                                        * Referenced by: '<S1>/ct'
                                        */
  uint16_T Constant_Value_mo;          /* Computed Parameter: Constant_Value_mo
                                        * Referenced by: '<S34>/Constant'
                                        */
  uint16_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S33>/Constant'
                                        */
  uint16_T Order_Value;                /* Computed Parameter: Order_Value
                                        * Referenced by: '<S29>/Order'
                                        */
  uint16_T Switch_Threshold_h;         /* Computed Parameter: Switch_Threshold_h
                                        * Referenced by: '<S29>/Switch'
                                        */
  uint16_T speedCountDelay_InitialConditio;
                          /* Computed Parameter: speedCountDelay_InitialConditio
                           * Referenced by: '<S29>/speedCountDelay'
                           */
  uint16_T Constant2_Value_p3;         /* Computed Parameter: Constant2_Value_p3
                                        * Referenced by: '<S30>/Constant2'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S14>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S9>/Output'
                                   */
  uint16_T Constant_Value_l5;          /* Computed Parameter: Constant_Value_l5
                                        * Referenced by: '<S121>/Constant'
                                        */
  uint16_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S96>/Constant'
                                        */
  uint16_T Constant_Value_pl;          /* Computed Parameter: Constant_Value_pl
                                        * Referenced by: '<S146>/Constant'
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
  boolean_T validityDelay_InitialCondition;
                           /* Computed Parameter: validityDelay_InitialCondition
                            * Referenced by: '<S29>/validityDelay'
                            */
  boolean_T DelayOneStep1_InitialCondition;
                           /* Computed Parameter: DelayOneStep1_InitialCondition
                            * Referenced by: '<S30>/Delay One Step1'
                            */
  uint8_T Gain_Gain_de;                /* Computed Parameter: Gain_Gain_de
                                        * Referenced by: '<S120>/Gain'
                                        */
  uint8_T Gain_Gain_jm;                /* Computed Parameter: Gain_Gain_jm
                                        * Referenced by: '<S95>/Gain'
                                        */
  uint8_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S145>/Gain'
                                        */
  uint8_T Gain1_Gain_n;                /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S120>/Gain1'
                                        */
  uint8_T Gain1_Gain_o;                /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S95>/Gain1'
                                        */
  uint8_T Gain1_Gain_oh;               /* Computed Parameter: Gain1_Gain_oh
                                        * Referenced by: '<S145>/Gain1'
                                        */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_n;
                            /* '<S157>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431debug_T ValidHalls_b;/* '<S157>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_f;
                            /* '<S107>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431debug_T ValidHalls_p;/* '<S107>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnection;
                            /* '<S132>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431debug_T ValidHalls; /* '<S132>/Valid Halls' */
  P_HallValueof1_G431debug_T HallValueof7_e;/* '<S35>/Hall Value of 7' */
  P_HallValueof1_G431debug_T HallValueof6_m;/* '<S35>/Hall Value of 6' */
  P_HallValueof1_G431debug_T HallValueof5_j;/* '<S35>/Hall Value of 5' */
  P_HallValueof1_G431debug_T HallValueof4_e;/* '<S35>/Hall Value of 4' */
  P_HallValueof1_G431debug_T HallValueof3_b;/* '<S35>/Hall Value of 3' */
  P_HallValueof1_G431debug_T HallValueof2_o;/* '<S35>/Hall Value of 2' */
  P_HallValueof1_G431debug_T HallValueof1_e;/* '<S35>/Hall Value of 1' */
  P_HallValueof1_G431debug_T HallValueof7_b;/* '<S46>/Hall Value of 7' */
  P_HallValueof1_G431debug_T HallValueof6_g;/* '<S46>/Hall Value of 6' */
  P_HallValueof1_G431debug_T HallValueof5_o;/* '<S46>/Hall Value of 5' */
  P_HallValueof1_G431debug_T HallValueof4_l;/* '<S46>/Hall Value of 4' */
  P_HallValueof1_G431debug_T HallValueof3_p;/* '<S46>/Hall Value of 3' */
  P_HallValueof1_G431debug_T HallValueof2_p;/* '<S46>/Hall Value of 2' */
  P_HallValueof1_G431debug_T HallValueof1_b;/* '<S46>/Hall Value of 1' */
  P_HallValueof1_G431debug_T HallValueof7;/* '<S47>/Hall Value of 7' */
  P_HallValueof1_G431debug_T HallValueof6;/* '<S47>/Hall Value of 6' */
  P_HallValueof1_G431debug_T HallValueof5;/* '<S47>/Hall Value of 5' */
  P_HallValueof1_G431debug_T HallValueof4;/* '<S47>/Hall Value of 4' */
  P_HallValueof1_G431debug_T HallValueof3;/* '<S47>/Hall Value of 3' */
  P_HallValueof1_G431debug_T HallValueof2;/* '<S47>/Hall Value of 2' */
  P_HallValueof1_G431debug_T HallValueof1;/* '<S47>/Hall Value of 1' */
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
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Propagation' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S80>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S85>/Data Type Duplicate' : Unused code path elimination
 * Block '<S85>/Vc' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S28>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S28>/counterSize2' : Eliminate redundant data type conversion
 * Block '<S65>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S121>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S146>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S28>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1'
 * '<S29>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/ExtrapolationOrder'
 * '<S30>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Software Watchdog Timer'
 * '<S31>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S32>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position'
 * '<S33>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/VaidityCheck'
 * '<S34>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Software Watchdog Timer/Compare To Zero'
 * '<S35>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S36>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S37>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S38>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S39>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S40>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S41>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S42>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S43>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S44>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S45>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S46>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S47>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S48>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S49>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S50>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S51>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S52>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S53>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S54>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S55>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S56>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S57>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S58>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S59>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S60>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S61>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S62>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S63>'  : 'G431debug/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S64>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset'
 * '<S65>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup'
 * '<S66>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem'
 * '<S67>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem1'
 * '<S68>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2'
 * '<S69>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Compare To Constant'
 * '<S70>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Compare To Constant1'
 * '<S71>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem'
 * '<S72>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter'
 * '<S73>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S74>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S75>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S76>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/Interpolation'
 * '<S77>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp'
 * '<S78>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S79>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S80>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S81>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output'
 * '<S82>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output/ECSoC'
 * '<S83>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output/ECSoC/ECSimCodegen'
 * '<S84>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform'
 * '<S85>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator'
 * '<S86>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform/Two inputs CRL'
 * '<S87>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S88>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method'
 * '<S89>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input'
 * '<S90>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method/SVPWM'
 * '<S91>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S92>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S93>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S94>'  : 'G431debug/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S95>'  : 'G431debug/HALL_A/HALLVaule'
 * '<S96>'  : 'G431debug/HALL_A/Hall Validity'
 * '<S97>'  : 'G431debug/HALL_A/Subsystem1'
 * '<S98>'  : 'G431debug/HALL_A/HALLVaule/HALLA'
 * '<S99>'  : 'G431debug/HALL_A/HALLVaule/HALLB'
 * '<S100>' : 'G431debug/HALL_A/HALLVaule/HALLC'
 * '<S101>' : 'G431debug/HALL_A/HALLVaule/HALLA/ECSoC'
 * '<S102>' : 'G431debug/HALL_A/HALLVaule/HALLA/ECSoC/ECSimCodegen'
 * '<S103>' : 'G431debug/HALL_A/HALLVaule/HALLB/ECSoC'
 * '<S104>' : 'G431debug/HALL_A/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S105>' : 'G431debug/HALL_A/HALLVaule/HALLC/ECSoC'
 * '<S106>' : 'G431debug/HALL_A/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S107>' : 'G431debug/HALL_A/Hall Validity/Subsystem'
 * '<S108>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S109>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls'
 * '<S110>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S111>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S112>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S113>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S114>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S115>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S116>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S117>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S118>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S119>' : 'G431debug/HALL_A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S120>' : 'G431debug/HALL_B/HALLVaule'
 * '<S121>' : 'G431debug/HALL_B/Hall Validity'
 * '<S122>' : 'G431debug/HALL_B/Subsystem1'
 * '<S123>' : 'G431debug/HALL_B/HALLVaule/HALLA'
 * '<S124>' : 'G431debug/HALL_B/HALLVaule/HALLB'
 * '<S125>' : 'G431debug/HALL_B/HALLVaule/HALLC'
 * '<S126>' : 'G431debug/HALL_B/HALLVaule/HALLA/ECSoC'
 * '<S127>' : 'G431debug/HALL_B/HALLVaule/HALLA/ECSoC/ECSimCodegen'
 * '<S128>' : 'G431debug/HALL_B/HALLVaule/HALLB/ECSoC'
 * '<S129>' : 'G431debug/HALL_B/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S130>' : 'G431debug/HALL_B/HALLVaule/HALLC/ECSoC'
 * '<S131>' : 'G431debug/HALL_B/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S132>' : 'G431debug/HALL_B/Hall Validity/Subsystem'
 * '<S133>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S134>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls'
 * '<S135>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S136>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S137>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S138>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S139>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S140>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S141>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S142>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S143>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S144>' : 'G431debug/HALL_B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S145>' : 'G431debug/HALL_C/HALLVaule'
 * '<S146>' : 'G431debug/HALL_C/Hall Validity'
 * '<S147>' : 'G431debug/HALL_C/Subsystem1'
 * '<S148>' : 'G431debug/HALL_C/HALLVaule/HALLA'
 * '<S149>' : 'G431debug/HALL_C/HALLVaule/HALLB'
 * '<S150>' : 'G431debug/HALL_C/HALLVaule/HALLC'
 * '<S151>' : 'G431debug/HALL_C/HALLVaule/HALLA/ECSoC'
 * '<S152>' : 'G431debug/HALL_C/HALLVaule/HALLA/ECSoC/ECSimCodegen'
 * '<S153>' : 'G431debug/HALL_C/HALLVaule/HALLB/ECSoC'
 * '<S154>' : 'G431debug/HALL_C/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S155>' : 'G431debug/HALL_C/HALLVaule/HALLC/ECSoC'
 * '<S156>' : 'G431debug/HALL_C/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S157>' : 'G431debug/HALL_C/Hall Validity/Subsystem'
 * '<S158>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S159>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls'
 * '<S160>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S161>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S162>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S163>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S164>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S165>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S166>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S167>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S168>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S169>' : 'G431debug/HALL_C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S170>' : 'G431debug/Hardware Interrupt/ECSoC'
 * '<S171>' : 'G431debug/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S172>' : 'G431debug/Hardware Interrupt2/ECSoC'
 * '<S173>' : 'G431debug/Hardware Interrupt2/ECSoC/ECSimCodegen'
 * '<S174>' : 'G431debug/LED Heart/Digital Port Write'
 * '<S175>' : 'G431debug/LED Heart/Digital Port Write/ECSoC'
 * '<S176>' : 'G431debug/LED Heart/Digital Port Write/ECSoC/ECSimCodegen'
 */
#endif                                 /* G431debug_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
