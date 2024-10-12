/*
 * File: STMF4Hall.h
 *
 * Code generated for Simulink model 'STMF4Hall'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Oct  9 10:59:32 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef STMF4Hall_h_
#define STMF4Hall_h_
#ifndef STMF4Hall_COMMON_INCLUDES_
#define STMF4Hall_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#endif                                 /* STMF4Hall_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "STMF4Hall_types.h"
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

/* Block states (default storage) for system '<S151>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S151>/If Action Subsystem6' */
} DW_IfActionSubsystem6_STMF4Ha_T;

/* Block states (default storage) for system '<S151>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S151>/If Action Subsystem' */
} DW_IfActionSubsystem_STMF4Hal_T;

/* Block signals for system '<S149>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S151>/Merge' */
  uint16_T Merge1;                     /* '<S151>/Merge1' */
  uint16_T Merge3;                     /* '<S151>/Merge3' */
  int16_T Merge2;                      /* '<S151>/Merge2' */
} B_ValidHalls_STMF4Hall_T;

/* Block states (default storage) for system '<S149>/Valid Halls' */
typedef struct {
  int8_T ValidHalls_SubsysRanBC;       /* '<S149>/Valid Halls' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                     /* '<S151>/Switch Case Action Subsystem' */
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S151>/If Action Subsystem8' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem5;/* '<S151>/If Action Subsystem5' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem4;/* '<S151>/If Action Subsystem4' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem3;/* '<S151>/If Action Subsystem3' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem2;/* '<S151>/If Action Subsystem2' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem1;/* '<S151>/If Action Subsystem1' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem;/* '<S151>/If Action Subsystem' */
  DW_IfActionSubsystem6_STMF4Ha_T IfActionSubsystem7;/* '<S151>/If Action Subsystem7' */
  DW_IfActionSubsystem6_STMF4Ha_T IfActionSubsystem6;/* '<S151>/If Action Subsystem6' */
} DW_ValidHalls_STMF4Hall_T;

/* Block states (default storage) for system '<S149>/Bad hall (glitch or wrong connection)' */
typedef struct {
  int8_T Badhallglitchorwrongconnection_;
                            /* '<S149>/Bad hall (glitch or wrong connection)' */
} DW_Badhallglitchorwrongconnec_T;

/* Block states (default storage) for system '<S79>/Hall Value of 1' */
typedef struct {
  int8_T HallValueof1_SubsysRanBC;     /* '<S79>/Hall Value of 1' */
} DW_HallValueof1_STMF4Hall_T;

/* Block signals (default storage) */
typedef struct {
  real_T Gain4[3];                     /* '<S12>/Gain4' */
  real_T OutportBufferForOut2;         /* '<S2>/Constant' */
  real_T OutportBufferForOut2_e;       /* '<S3>/Constant' */
  real_T OutportBufferForOut2_e2;      /* '<S4>/Constant' */
  real_T rtb_Switch4_idx_0;
  uint32_T time3;                      /* '<Root>/Timer1' */
  uint32_T time3_g;                    /* '<Root>/Timer1' */
  uint32_T time3_gw;                   /* '<Root>/Timer1' */
  uint32_T time3_k;                    /* '<Root>/Timer1' */
  uint32_T speedCountDelay;            /* '<S61>/speedCountDelay' */
  uint32_T Add1;                       /* '<S37>/Add1' */
  real32_T Merge;                      /* '<S77>/Merge' */
  real32_T scaleOut;                   /* '<S40>/scaleOut' */
  real32_T Add1_h;                     /* '<S41>/Add1' */
  real32_T Input;                      /* '<S42>/Input' */
  uint16_T testcounter;                /* '<Root>/RT6' */
  uint16_T DelayOneStep;               /* '<S62>/Delay One Step' */
  uint16_T Output;                     /* '<S11>/Output' */
  int16_T gethalltimer;                /* '<Root>/Multiport Switch' */
  int16_T Sum;                         /* '<S2>/Sum' */
  int16_T Sum_c;                       /* '<S3>/Sum' */
  int16_T Sum_i;                       /* '<S4>/Sum' */
  boolean_T validityDelay;             /* '<S61>/validityDelay' */
  boolean_T Compare;                   /* '<S34>/Compare' */
  B_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S99>/Valid Halls' */
  B_ValidHalls_STMF4Hall_T ValidHalls_l;/* '<S124>/Valid Halls' */
  B_ValidHalls_STMF4Hall_T ValidHalls; /* '<S149>/Valid Halls' */
} B_STMF4Hall_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S17>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_ST_T obj_l;/* '<S58>/PWM Output' */
  stm32cube_blocks_TimerBlock_S_T obj_b;/* '<Root>/Timer1' */
  real_T Enable;                       /* '<Root>/Data Store Memory9' */
  real32_T UnitDelay_DSTATE;           /* '<S40>/Unit Delay' */
  real32_T Delay_DSTATE;               /* '<S39>/Delay' */
  real32_T Delay_DSTATE_k;             /* '<S18>/Delay' */
  real32_T UnitDelay_DSTATE_j;         /* '<S30>/Unit Delay' */
  uint32_T speedCountDelay_DSTATE;     /* '<S61>/speedCountDelay' */
  uint32_T Delay_DSTATE_a;             /* '<S37>/Delay' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  volatile uint32_T TmpRTBAtHallsensorBInport1_Buff;/* synthesized block */
  volatile uint32_T TmpRTBAtHallsensorCInport1_Buff;/* synthesized block */
  volatile uint32_T time3_Buffer0;     /* synthesized block */
  uint32_T Timercntprev;               /* '<Root>/Data Store Memory3' */
  uint16_T DelayOneStep_DSTATE;        /* '<S62>/Delay One Step' */
  uint16_T Output_DSTATE;              /* '<S11>/Output' */
  int16_T HallCcapture;                /* '<Root>/Data Store Memory12' */
  int16_T Timehall;                    /* '<Root>/Data Store Memory2' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory5' */
  int16_T HallBcapture;                /* '<Root>/Data Store Memory11' */
  int16_T HallAcapture;                /* '<Root>/Data Store Memory10' */
  uint16_T GlobalSpeedCount;           /* '<Root>/Data Store Memory6' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory7' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory8' */
  boolean_T validityDelay_DSTATE;      /* '<S61>/validityDelay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S62>/Delay One Step1' */
  boolean_T Delay_DSTATE_o;            /* '<S41>/Delay' */
  int8_T ADCSIC_SubsysRanBC;           /* '<Root>/ADC SIC' */
  int8_T SpeedanddirectionarenotvalidPos;
  /* '<S60>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
  int8_T SpeedanddirectionarevalidUsespe;
  /* '<S60>/Speed and direction are valid Use speed to extrapolate position' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S64>/Subsystem1' */
  int8_T first_order_SubsysRanBC;      /* '<S77>/first_order' */
  int8_T second_order_SubsysRanBC;     /* '<S77>/second_order' */
  int8_T veDirection_SubsysRanBC;      /* '<S77>/+ve Direction' */
  int8_T veDirection_SubsysRanBC_n;    /* '<S77>/-ve Direction' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S64>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S64>/If Action Subsystem' */
  int8_T Subsystem1_SubsysRanBC_f;     /* '<S10>/Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanB_e;/* '<S44>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_j;/* '<S44>/If Action Subsystem' */
  int8_T PosGen_SubsysRanBC;           /* '<S10>/PosGen' */
  int8_T UpCounter_SubsysRanBC;        /* '<S20>/Up Counter' */
  int8_T Accumulate_SubsysRanBC;       /* '<S40>/Accumulate' */
  int8_T Subsystem_SubsysRanBC;        /* '<S41>/Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S36>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S36>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC_p;      /* '<S20>/Subsystem' */
  int8_T FindOffset_SubsysRanBC;       /* '<S10>/Find Offset' */
  int8_T Subsystem_SubsysRanBC_l;      /* '<S18>/Subsystem' */
  int8_T HallsensorA_SubsysRanBC;      /* '<Root>/Hall sensor A' */
  int8_T HallsensorB_SubsysRanBC;      /* '<Root>/Hall sensor B' */
  int8_T HallsensorC_SubsysRanBC;      /* '<Root>/Hall sensor C' */
  uint8_T GlobalHallState;             /* '<Root>/Data Store Memory' */
  boolean_T PosGen_MODE;               /* '<S10>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S20>/Up Counter' */
  boolean_T FindOffset_MODE;           /* '<S10>/Find Offset' */
  DW_HallValueof1_STMF4Hall_T HallValueof7_n;/* '<S67>/Hall Value of 7' */
  DW_HallValueof1_STMF4Hall_T HallValueof6_d;/* '<S67>/Hall Value of 6' */
  DW_HallValueof1_STMF4Hall_T HallValueof5_o;/* '<S67>/Hall Value of 5' */
  DW_HallValueof1_STMF4Hall_T HallValueof4_n;/* '<S67>/Hall Value of 4' */
  DW_HallValueof1_STMF4Hall_T HallValueof3_m;/* '<S67>/Hall Value of 3' */
  DW_HallValueof1_STMF4Hall_T HallValueof2_n;/* '<S67>/Hall Value of 2' */
  DW_HallValueof1_STMF4Hall_T HallValueof1_a;/* '<S67>/Hall Value of 1' */
  DW_HallValueof1_STMF4Hall_T HallValueof7_h;/* '<S78>/Hall Value of 7' */
  DW_HallValueof1_STMF4Hall_T HallValueof6_i;/* '<S78>/Hall Value of 6' */
  DW_HallValueof1_STMF4Hall_T HallValueof5_h;/* '<S78>/Hall Value of 5' */
  DW_HallValueof1_STMF4Hall_T HallValueof4_l;/* '<S78>/Hall Value of 4' */
  DW_HallValueof1_STMF4Hall_T HallValueof3_k;/* '<S78>/Hall Value of 3' */
  DW_HallValueof1_STMF4Hall_T HallValueof2_i;/* '<S78>/Hall Value of 2' */
  DW_HallValueof1_STMF4Hall_T HallValueof1_d;/* '<S78>/Hall Value of 1' */
  DW_HallValueof1_STMF4Hall_T HallValueof7;/* '<S79>/Hall Value of 7' */
  DW_HallValueof1_STMF4Hall_T HallValueof6;/* '<S79>/Hall Value of 6' */
  DW_HallValueof1_STMF4Hall_T HallValueof5;/* '<S79>/Hall Value of 5' */
  DW_HallValueof1_STMF4Hall_T HallValueof4;/* '<S79>/Hall Value of 4' */
  DW_HallValueof1_STMF4Hall_T HallValueof3;/* '<S79>/Hall Value of 3' */
  DW_HallValueof1_STMF4Hall_T HallValueof2;/* '<S79>/Hall Value of 2' */
  DW_HallValueof1_STMF4Hall_T HallValueof1;/* '<S79>/Hall Value of 1' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_a;
                             /* '<S99>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S99>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_c;
                            /* '<S124>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls_l;/* '<S124>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnection;
                            /* '<S149>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls;/* '<S149>/Valid Halls' */
} DW_STMF4Hall_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Hallstate;                    /* '<Root>/Hall state' */
  real_T Hallangle;                    /* '<Root>/Hall angle' */
} ExtY_STMF4Hall_T;

/* Parameters for system: '<S151>/If Action Subsystem6' */
struct P_IfActionSubsystem6_STMF4Hal_T_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S158>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S158>/Constant1'
                                        */
};

/* Parameters for system: '<S151>/If Action Subsystem' */
struct P_IfActionSubsystem_STMF4Hall_T_ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S152>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S152>/next'
                                        */
};

/* Parameters for system: '<S149>/Valid Halls' */
struct P_ValidHalls_STMF4Hall_T_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S151>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S160>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S151>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S151>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S151>/Merge3'
                                      */
  boolean_T Constant_Value_i;          /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S151>/Constant'
                                        */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem5;/* '<S151>/If Action Subsystem5' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem4;/* '<S151>/If Action Subsystem4' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem3;/* '<S151>/If Action Subsystem3' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem2;/* '<S151>/If Action Subsystem2' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem1;/* '<S151>/If Action Subsystem1' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem;/* '<S151>/If Action Subsystem' */
  P_IfActionSubsystem6_STMF4Hal_T IfActionSubsystem7;/* '<S151>/If Action Subsystem7' */
  P_IfActionSubsystem6_STMF4Hal_T IfActionSubsystem6;/* '<S151>/If Action Subsystem6' */
};

/* Parameters for system: '<S149>/Bad hall (glitch or wrong connection)' */
struct P_Badhallglitchorwrongconnect_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S150>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S150>/Constant1'
                                        */
};

/* Parameters for system: '<S79>/Hall Value of 1' */
struct P_HallValueof1_STMF4Hall_T_ {
  real32_T Constant_Value;             /* Expression: single(0.16667)
                                        * Referenced by: '<S89>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_STMF4Hall_T_ {
  real32_T Ts;                         /* Variable: Ts
                                        * Referenced by: '<S39>/Multiply'
                                        */
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S24>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S25>/Constant'
                                      */
  uint32_T Disablehostafter22seconds_const;
                              /* Mask Parameter: Disablehostafter22seconds_const
                               * Referenced by: '<S33>/Constant'
                               */
  uint32_T EnablePWMfor20seconds_const;
                                  /* Mask Parameter: EnablePWMfor20seconds_const
                                   * Referenced by: '<S34>/Constant'
                                   */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S56>/FixPt Switch'
                                        */
  uint16_T SoftwareWatchdogTimer_maxCount;
                               /* Mask Parameter: SoftwareWatchdogTimer_maxCount
                                * Referenced by: '<S62>/Delay One Step'
                                */
  real_T Constant_Value;               /* Expression: 3
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant_Value_p;             /* Expression: 2
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant_Value_pu;            /* Expression: 0
                                        * Referenced by: '<S35>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: EnableSecondOrder
                                        * Referenced by: '<S77>/Constant'
                                        */
  real_T Pos_PU_Y0;                    /* Expression: 0
                                        * Referenced by: '<S1>/Pos_PU'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S12>/Constant1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 100
                                        * Referenced by: '<S12>/Gain4'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T DataStoreMemory4_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory4'
                                        */
  real_T DataStoreMemory9_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory9'
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
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S27>/a'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S27>/One'
                                        */
  real32_T FilterConstant_Value;     /* Computed Parameter: FilterConstant_Value
                                      * Referenced by: '<S27>/FilterConstant'
                                      */
  real32_T OneMinusFilterConstant_Value;
                             /* Computed Parameter: OneMinusFilterConstant_Value
                              * Referenced by: '<S27>/OneMinusFilterConstant'
                              */
  real32_T Offset_Y0;                  /* Computed Parameter: Offset_Y0
                                        * Referenced by: '<S26>/Offset'
                                        */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S27>/UseInputPort'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S27>/Switch1'
                                        */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S30>/Unit Delay'
                                */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S18>/Delay'
                                    */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S38>/Constant'
                                        */
  real32_T Constant1_Value_i;          /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<S39>/Constant1'
                                        */
  real32_T Delay_InitialCondition_p;
                                 /* Computed Parameter: Delay_InitialCondition_p
                                  * Referenced by: '<S39>/Delay'
                                  */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S39>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S39>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S42>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S41>/theta_e'
                                        */
  real32_T Theta_Y0;                   /* Computed Parameter: Theta_Y0
                                        * Referenced by: '<S20>/Theta'
                                        */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S40>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition_o;
                             /* Computed Parameter: UnitDelay_InitialCondition_o
                              * Referenced by: '<S40>/Unit Delay'
                              */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S40>/scaleOut'
                                        */
  real32_T Offset_Y0_l;                /* Computed Parameter: Offset_Y0_l
                                        * Referenced by: '<S23>/Offset'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S81>/Constant'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S81>/Gain1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S81>/Gain'
                                        */
  real32_T Gain_Gain_e;                /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S80>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Expression: single(0.16667)
                                        * Referenced by: '<S77>/Saturation'
                                        */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S77>/Saturation'
                                       */
  real32_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S77>/Merge'
                                       */
  real32_T SpeedGain_Gain;             /* Expression: single(MinSpeed/6000)
                                        * Referenced by: '<S64>/SpeedGain'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S63>/Constant'
                                        */
  real32_T Constant_Value_ls;          /* Computed Parameter: Constant_Value_ls
                                        * Referenced by: '<S45>/Constant'
                                        */
  real32_T PositionUnit_Gain;          /* Expression: single(1)
                                        * Referenced by: '<S60>/PositionUnit'
                                        */
  real32_T Vd_Ref_Value;               /* Computed Parameter: Vd_Ref_Value
                                        * Referenced by: '<S10>/Vd_Ref'
                                        */
  real32_T Vq_Value;                   /* Computed Parameter: Vq_Value
                                        * Referenced by: '<S10>/Vq'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S21>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S44>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S21>/indexing'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S54>/Ka'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S54>/one_by_two'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S54>/sqrt3_by_two'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S54>/Kb'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S54>/Kc'
                                        */
  real32_T one_by_two_Gain_j;          /* Computed Parameter: one_by_two_Gain_j
                                        * Referenced by: '<S51>/one_by_two'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S50>/Gain'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S12>/Gain3'
                                        */
  uint32_T Count_Y0;                   /* Computed Parameter: Count_Y0
                                        * Referenced by: '<S37>/Count'
                                        */
  uint32_T Constant_Value_ns;          /* Computed Parameter: Constant_Value_ns
                                        * Referenced by: '<S37>/Constant'
                                        */
  uint32_T Delay_InitialCondition_m;
                                 /* Computed Parameter: Delay_InitialCondition_m
                                  * Referenced by: '<S37>/Delay'
                                  */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S36>/Count for 2 sec'
                                        */
  uint32_T SpeedConst_Value;
                          /* Expression: uint32(10*ClkFreq/(PolePairs*MinSpeed))
                           * Referenced by: '<S64>/SpeedConst'
                           */
  uint32_T speedcheck_Threshold;     /* Computed Parameter: speedcheck_Threshold
                                      * Referenced by: '<S65>/speed check'
                                      */
  uint32_T speedCountDelay_InitialConditio;
                          /* Computed Parameter: speedCountDelay_InitialConditio
                           * Referenced by: '<S61>/speedCountDelay'
                           */
  uint32_T TmpRTBAtHallsensorBInport1_Init;
                          /* Computed Parameter: TmpRTBAtHallsensorBInport1_Init
                           * Referenced by:
                           */
  uint32_T TmpRTBAtHallsensorCInport1_Init;
                          /* Computed Parameter: TmpRTBAtHallsensorCInport1_Init
                           * Referenced by:
                           */
  uint32_T time3_InitialCondition; /* Computed Parameter: time3_InitialCondition
                                    * Referenced by:
                                    */
  uint32_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  int16_T Out1_Y0_m;                   /* Computed Parameter: Out1_Y0_m
                                        * Referenced by: '<S4>/Out1'
                                        */
  int16_T Out1_Y0_h;                   /* Computed Parameter: Out1_Y0_h
                                        * Referenced by: '<S3>/Out1'
                                        */
  int16_T Out1_Y0_l;                   /* Computed Parameter: Out1_Y0_l
                                        * Referenced by: '<S2>/Out1'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S21>/offset'
                                        */
  int16_T DataStoreMemory12_InitialValue;
                           /* Computed Parameter: DataStoreMemory12_InitialValue
                            * Referenced by: '<Root>/Data Store Memory12'
                            */
  int16_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  int16_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  int16_T DataStoreMemory11_InitialValue;
                           /* Computed Parameter: DataStoreMemory11_InitialValue
                            * Referenced by: '<Root>/Data Store Memory11'
                            */
  int16_T DataStoreMemory10_InitialValue;
                           /* Computed Parameter: DataStoreMemory10_InitialValue
                            * Referenced by: '<Root>/Data Store Memory10'
                            */
  uint16_T Constant_Value_fm;          /* Computed Parameter: Constant_Value_fm
                                        * Referenced by: '<S146>/Constant'
                                        */
  uint16_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S121>/Constant'
                                        */
  uint16_T Constant_Value_bh;          /* Computed Parameter: Constant_Value_bh
                                        * Referenced by: '<S96>/Constant'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S32>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S32>/Switch'
                                        */
  uint16_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S56>/Constant'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S12>/stop'
                                        */
  uint16_T PositionEnable_Value;     /* Computed Parameter: PositionEnable_Value
                                      * Referenced by: '<S64>/PositionEnable'
                                      */
  uint16_T WatchDog_Value;             /* Computed Parameter: WatchDog_Value
                                        * Referenced by: '<S60>/WatchDog'
                                        */
  uint16_T Out1_Y0_hj;                 /* Computed Parameter: Out1_Y0_hj
                                        * Referenced by: '<S1>/Out1'
                                        */
  uint16_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S66>/Constant'
                                        */
  uint16_T Order_Value;                /* Computed Parameter: Order_Value
                                        * Referenced by: '<S61>/Order'
                                        */
  uint16_T Switch_Threshold_i;         /* Computed Parameter: Switch_Threshold_i
                                        * Referenced by: '<S61>/Switch'
                                        */
  uint16_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S65>/Constant'
                                        */
  uint16_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S62>/Constant2'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S55>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S11>/Output'
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
  boolean_T Delay_InitialCondition_h;
                                 /* Computed Parameter: Delay_InitialCondition_h
                                  * Referenced by: '<S41>/Delay'
                                  */
  boolean_T Constant_Value_n0;         /* Computed Parameter: Constant_Value_n0
                                        * Referenced by: '<S41>/Constant'
                                        */
  boolean_T EnPWM_Y0;                  /* Computed Parameter: EnPWM_Y0
                                        * Referenced by: '<S20>/EnPWM'
                                        */
  boolean_T EnableHost_Y0;             /* Computed Parameter: EnableHost_Y0
                                        * Referenced by: '<S20>/EnableHost'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S40>/Constant_Reset'
                                      */
  boolean_T validityDelay_InitialCondition;
                           /* Computed Parameter: validityDelay_InitialCondition
                            * Referenced by: '<S61>/validityDelay'
                            */
  boolean_T DelayOneStep1_InitialCondition;
                           /* Computed Parameter: DelayOneStep1_InitialCondition
                            * Referenced by: '<S62>/Delay One Step1'
                            */
  uint8_T Gain_Gain_h;                 /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S147>/Gain'
                                        */
  uint8_T Gain_Gain_n;                 /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S122>/Gain'
                                        */
  uint8_T Gain_Gain_av;                /* Computed Parameter: Gain_Gain_av
                                        * Referenced by: '<S97>/Gain'
                                        */
  uint8_T Gain_Gain_m;                 /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S177>/Gain'
                                        */
  uint8_T Gain1_Gain_k;                /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S147>/Gain1'
                                        */
  uint8_T Gain1_Gain_l;                /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S122>/Gain1'
                                        */
  uint8_T Gain1_Gain_i;                /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S97>/Gain1'
                                        */
  uint8_T Gain1_Gain_p;                /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S177>/Gain1'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S147>/Gain2'
                                        */
  uint8_T Gain2_Gain_d;                /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S122>/Gain2'
                                        */
  uint8_T Gain2_Gain_f;                /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S97>/Gain2'
                                        */
  uint8_T Gain2_Gain_n;                /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<S177>/Gain2'
                                        */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  P_HallValueof1_STMF4Hall_T HallValueof7_n;/* '<S67>/Hall Value of 7' */
  P_HallValueof1_STMF4Hall_T HallValueof6_d;/* '<S67>/Hall Value of 6' */
  P_HallValueof1_STMF4Hall_T HallValueof5_o;/* '<S67>/Hall Value of 5' */
  P_HallValueof1_STMF4Hall_T HallValueof4_n;/* '<S67>/Hall Value of 4' */
  P_HallValueof1_STMF4Hall_T HallValueof3_m;/* '<S67>/Hall Value of 3' */
  P_HallValueof1_STMF4Hall_T HallValueof2_n;/* '<S67>/Hall Value of 2' */
  P_HallValueof1_STMF4Hall_T HallValueof1_a;/* '<S67>/Hall Value of 1' */
  P_HallValueof1_STMF4Hall_T HallValueof7_h;/* '<S78>/Hall Value of 7' */
  P_HallValueof1_STMF4Hall_T HallValueof6_i;/* '<S78>/Hall Value of 6' */
  P_HallValueof1_STMF4Hall_T HallValueof5_h;/* '<S78>/Hall Value of 5' */
  P_HallValueof1_STMF4Hall_T HallValueof4_l;/* '<S78>/Hall Value of 4' */
  P_HallValueof1_STMF4Hall_T HallValueof3_k;/* '<S78>/Hall Value of 3' */
  P_HallValueof1_STMF4Hall_T HallValueof2_i;/* '<S78>/Hall Value of 2' */
  P_HallValueof1_STMF4Hall_T HallValueof1_d;/* '<S78>/Hall Value of 1' */
  P_HallValueof1_STMF4Hall_T HallValueof7;/* '<S79>/Hall Value of 7' */
  P_HallValueof1_STMF4Hall_T HallValueof6;/* '<S79>/Hall Value of 6' */
  P_HallValueof1_STMF4Hall_T HallValueof5;/* '<S79>/Hall Value of 5' */
  P_HallValueof1_STMF4Hall_T HallValueof4;/* '<S79>/Hall Value of 4' */
  P_HallValueof1_STMF4Hall_T HallValueof3;/* '<S79>/Hall Value of 3' */
  P_HallValueof1_STMF4Hall_T HallValueof2;/* '<S79>/Hall Value of 2' */
  P_HallValueof1_STMF4Hall_T HallValueof1;/* '<S79>/Hall Value of 1' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_a;
                             /* '<S99>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S99>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_c;
                            /* '<S124>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls_l;/* '<S124>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnection;
                            /* '<S149>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls; /* '<S149>/Valid Halls' */
};

/* Real-time Model Data Structure */
struct tag_RTM_STMF4Hall_T {
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
    uint32_T clockTick6;
    struct {
      uint16_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_STMF4Hall_T STMF4Hall_P;

/* Block signals (default storage) */
extern B_STMF4Hall_T STMF4Hall_B;

/* Block states (default storage) */
extern DW_STMF4Hall_T STMF4Hall_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_STMF4Hall_T STMF4Hall_Y;

/* External function called from main */
extern void STMF4Hall_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void STMF4Hall_initialize(void);
extern void STMF4Hall_step0(void);
extern void STMF4Hall_step1(void);
extern void STMF4Hall_terminate(void);

/* Real-time Model object */
extern RT_MODEL_STMF4Hall_T *const STMF4Hall_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void EXTI15_10_IRQHandler(void);
  void ADC_IRQHandler(void);
  void STMF4Hall_configure_interrupts (void);
  void STMF4Hall_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Propagation' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Vc' : Unused code path elimination
 * Block '<S54>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S55>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Constant' : Unused code path elimination
 * Block '<S12>/Sum' : Unused code path elimination
 * Block '<S14>/Data Type' : Unused code path elimination
 * Block '<S14>/Number of pole pairs' : Unused code path elimination
 * Block '<S14>/PWM Frequency' : Unused code path elimination
 * Block '<S21>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S60>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S96>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S121>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'STMF4Hall'
 * '<S1>'   : 'STMF4Hall/ADC SIC'
 * '<S2>'   : 'STMF4Hall/Hall sensor A'
 * '<S3>'   : 'STMF4Hall/Hall sensor B'
 * '<S4>'   : 'STMF4Hall/Hall sensor C'
 * '<S5>'   : 'STMF4Hall/Hardware Interrupt'
 * '<S6>'   : 'STMF4Hall/Hardware Interrupt1'
 * '<S7>'   : 'STMF4Hall/Heartbeat LED'
 * '<S8>'   : 'STMF4Hall/Initialize Function'
 * '<S9>'   : 'STMF4Hall/ADC SIC/Analog to Digital Converter'
 * '<S10>'  : 'STMF4Hall/ADC SIC/Control_System'
 * '<S11>'  : 'STMF4Hall/ADC SIC/Counter Limited'
 * '<S12>'  : 'STMF4Hall/ADC SIC/Output Scaling'
 * '<S13>'  : 'STMF4Hall/ADC SIC/PWM Output'
 * '<S14>'  : 'STMF4Hall/ADC SIC/Parameters'
 * '<S15>'  : 'STMF4Hall/ADC SIC/Subsystem'
 * '<S16>'  : 'STMF4Hall/ADC SIC/Analog to Digital Converter/ECSoC'
 * '<S17>'  : 'STMF4Hall/ADC SIC/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S18>'  : 'STMF4Hall/ADC SIC/Control_System/Find Offset'
 * '<S19>'  : 'STMF4Hall/ADC SIC/Control_System/Inverse Park Transform'
 * '<S20>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen'
 * '<S21>'  : 'STMF4Hall/ADC SIC/Control_System/Sine-Cosine Lookup'
 * '<S22>'  : 'STMF4Hall/ADC SIC/Control_System/Space Vector Generator'
 * '<S23>'  : 'STMF4Hall/ADC SIC/Control_System/Subsystem1'
 * '<S24>'  : 'STMF4Hall/ADC SIC/Control_System/Find Offset/Compare To Constant'
 * '<S25>'  : 'STMF4Hall/ADC SIC/Control_System/Find Offset/Compare To Constant1'
 * '<S26>'  : 'STMF4Hall/ADC SIC/Control_System/Find Offset/Subsystem'
 * '<S27>'  : 'STMF4Hall/ADC SIC/Control_System/Find Offset/Subsystem/IIR Filter'
 * '<S28>'  : 'STMF4Hall/ADC SIC/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S29>'  : 'STMF4Hall/ADC SIC/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S30>'  : 'STMF4Hall/ADC SIC/Control_System/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S31>'  : 'STMF4Hall/ADC SIC/Control_System/Inverse Park Transform/Two inputs CRL'
 * '<S32>'  : 'STMF4Hall/ADC SIC/Control_System/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S33>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Disable host after 22 seconds'
 * '<S34>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Enable PWM for 20 seconds'
 * '<S35>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Subsystem'
 * '<S36>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Subsystem1'
 * '<S37>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Up Counter'
 * '<S38>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Subsystem1/If Action Subsystem'
 * '<S39>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Subsystem1/If Action Subsystem2'
 * '<S40>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Subsystem1/Position Generator'
 * '<S41>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S42>'  : 'STMF4Hall/ADC SIC/Control_System/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S43>'  : 'STMF4Hall/ADC SIC/Control_System/Sine-Cosine Lookup/Interpolation'
 * '<S44>'  : 'STMF4Hall/ADC SIC/Control_System/Sine-Cosine Lookup/WrapUp'
 * '<S45>'  : 'STMF4Hall/ADC SIC/Control_System/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S46>'  : 'STMF4Hall/ADC SIC/Control_System/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S47>'  : 'STMF4Hall/ADC SIC/Control_System/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S48>'  : 'STMF4Hall/ADC SIC/Control_System/Space Vector Generator/Modulation method'
 * '<S49>'  : 'STMF4Hall/ADC SIC/Control_System/Space Vector Generator/Voltage Input'
 * '<S50>'  : 'STMF4Hall/ADC SIC/Control_System/Space Vector Generator/Modulation method/SVPWM'
 * '<S51>'  : 'STMF4Hall/ADC SIC/Control_System/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S52>'  : 'STMF4Hall/ADC SIC/Control_System/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S53>'  : 'STMF4Hall/ADC SIC/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S54>'  : 'STMF4Hall/ADC SIC/Control_System/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S55>'  : 'STMF4Hall/ADC SIC/Counter Limited/Increment Real World'
 * '<S56>'  : 'STMF4Hall/ADC SIC/Counter Limited/Wrap To Zero'
 * '<S57>'  : 'STMF4Hall/ADC SIC/PWM Output/ECSoC'
 * '<S58>'  : 'STMF4Hall/ADC SIC/PWM Output/ECSoC/ECSimCodegen'
 * '<S59>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall'
 * '<S60>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position'
 * '<S61>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/ExtrapolationOrder'
 * '<S62>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer'
 * '<S63>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S64>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position'
 * '<S65>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/VaidityCheck'
 * '<S66>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Software Watchdog Timer/Compare To Zero'
 * '<S67>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S68>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S69>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S70>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S71>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S72>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S73>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S74>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S75>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S76>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S77>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S78>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S79>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S80>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S81>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S82>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S83>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S84>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S85>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S86>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S87>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S88>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S89>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S90>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S91>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S92>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S93>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S94>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S95>'  : 'STMF4Hall/ADC SIC/Subsystem/Calculate Position from Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S96>'  : 'STMF4Hall/Hall sensor A/Hall Validity'
 * '<S97>'  : 'STMF4Hall/Hall sensor A/Hallstation'
 * '<S98>'  : 'STMF4Hall/Hall sensor A/Subsystem'
 * '<S99>'  : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem'
 * '<S100>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S101>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls'
 * '<S102>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S103>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S104>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S105>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S106>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S107>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S108>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S109>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S110>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S111>' : 'STMF4Hall/Hall sensor A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S112>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read'
 * '<S113>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read1'
 * '<S114>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read2'
 * '<S115>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read/ECSoC'
 * '<S116>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S117>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read1/ECSoC'
 * '<S118>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S119>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read2/ECSoC'
 * '<S120>' : 'STMF4Hall/Hall sensor A/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S121>' : 'STMF4Hall/Hall sensor B/Hall Validity'
 * '<S122>' : 'STMF4Hall/Hall sensor B/Hallstation'
 * '<S123>' : 'STMF4Hall/Hall sensor B/Subsystem'
 * '<S124>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem'
 * '<S125>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S126>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls'
 * '<S127>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S128>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S129>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S130>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S131>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S132>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S133>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S134>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S135>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S136>' : 'STMF4Hall/Hall sensor B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S137>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read'
 * '<S138>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read1'
 * '<S139>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read2'
 * '<S140>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read/ECSoC'
 * '<S141>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S142>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read1/ECSoC'
 * '<S143>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S144>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read2/ECSoC'
 * '<S145>' : 'STMF4Hall/Hall sensor B/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S146>' : 'STMF4Hall/Hall sensor C/Hall Validity'
 * '<S147>' : 'STMF4Hall/Hall sensor C/Hallstation'
 * '<S148>' : 'STMF4Hall/Hall sensor C/Subsystem'
 * '<S149>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem'
 * '<S150>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S151>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls'
 * '<S152>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S153>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S154>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S155>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S156>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S157>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S158>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S159>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S160>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S161>' : 'STMF4Hall/Hall sensor C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S162>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read'
 * '<S163>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read1'
 * '<S164>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read2'
 * '<S165>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read/ECSoC'
 * '<S166>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S167>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read1/ECSoC'
 * '<S168>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S169>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read2/ECSoC'
 * '<S170>' : 'STMF4Hall/Hall sensor C/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S171>' : 'STMF4Hall/Hardware Interrupt/ECSoC'
 * '<S172>' : 'STMF4Hall/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S173>' : 'STMF4Hall/Hardware Interrupt1/ECSoC'
 * '<S174>' : 'STMF4Hall/Hardware Interrupt1/ECSoC/ECSimCodegen'
 * '<S175>' : 'STMF4Hall/Heartbeat LED/ECSoC'
 * '<S176>' : 'STMF4Hall/Heartbeat LED/ECSoC/ECSimCodegen'
 * '<S177>' : 'STMF4Hall/Initialize Function/Hallstation'
 * '<S178>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read'
 * '<S179>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1'
 * '<S180>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2'
 * '<S181>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read/ECSoC'
 * '<S182>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S183>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1/ECSoC'
 * '<S184>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S185>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2/ECSoC'
 * '<S186>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 */
#endif                                 /* STMF4Hall_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
