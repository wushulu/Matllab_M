/*
 * File: STMF4Hall.h
 *
 * Code generated for Simulink model 'STMF4Hall'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Sep 30 14:28:23 2024
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

/* Block states (default storage) for system '<S104>/Hall Value of 1' */
typedef struct {
  int8_T HallValueof1_SubsysRanBC;     /* '<S104>/Hall Value of 1' */
} DW_HallValueof1_STMF4Hall_T;

/* Block states (default storage) for system '<S66>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S66>/If Action Subsystem6' */
} DW_IfActionSubsystem6_STMF4Ha_T;

/* Block states (default storage) for system '<S66>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S66>/If Action Subsystem' */
} DW_IfActionSubsystem_STMF4Hal_T;

/* Block signals for system '<S64>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S66>/Merge' */
  uint16_T Merge1;                     /* '<S66>/Merge1' */
  uint16_T Merge3;                     /* '<S66>/Merge3' */
  int16_T Merge2;                      /* '<S66>/Merge2' */
} B_ValidHalls_STMF4Hall_T;

/* Block states (default storage) for system '<S64>/Valid Halls' */
typedef struct {
  int8_T ValidHalls_SubsysRanBC;       /* '<S64>/Valid Halls' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                      /* '<S66>/Switch Case Action Subsystem' */
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S66>/If Action Subsystem8' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem5;/* '<S66>/If Action Subsystem5' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem4;/* '<S66>/If Action Subsystem4' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem3;/* '<S66>/If Action Subsystem3' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem2;/* '<S66>/If Action Subsystem2' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem1;/* '<S66>/If Action Subsystem1' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem;/* '<S66>/If Action Subsystem' */
  DW_IfActionSubsystem6_STMF4Ha_T IfActionSubsystem7;/* '<S66>/If Action Subsystem7' */
  DW_IfActionSubsystem6_STMF4Ha_T IfActionSubsystem6;/* '<S66>/If Action Subsystem6' */
} DW_ValidHalls_STMF4Hall_T;

/* Block states (default storage) for system '<S64>/Bad hall (glitch or wrong connection)' */
typedef struct {
  int8_T Badhallglitchorwrongconnection_;
                             /* '<S64>/Bad hall (glitch or wrong connection)' */
} DW_Badhallglitchorwrongconnec_T;

/* Block signals (default storage) */
typedef struct {
  real_T MultiportSwitch[2];           /* '<S8>/Multiport Switch' */
  real_T OutportBufferForOut2;         /* '<S2>/Constant' */
  real_T OutportBufferForOut2_e;       /* '<S3>/Constant' */
  real_T OutportBufferForOut2_e2;      /* '<S4>/Constant' */
  uint32_T time3;                      /* '<Root>/Timer1' */
  uint32_T time3_g;                    /* '<Root>/Timer1' */
  uint32_T time3_gw;                   /* '<Root>/Timer1' */
  uint32_T time3_k;                    /* '<Root>/Timer1' */
  uint16_T DelayOneStep;               /* '<S87>/Delay One Step' */
  int16_T gethalltimer;                /* '<Root>/Multiport Switch' */
  int16_T Sum;                         /* '<S2>/Sum' */
  int16_T Sum_p;                       /* '<S3>/Sum' */
  int16_T Sum_b;                       /* '<S4>/Sum' */
  uint8_T Halls;                       /* '<Root>/Data Store Read' */
  boolean_T validityDelay;             /* '<S86>/validityDelay' */
  B_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S14>/Valid Halls' */
  B_ValidHalls_STMF4Hall_T ValidHalls_h;/* '<S39>/Valid Halls' */
  B_ValidHalls_STMF4Hall_T ValidHalls; /* '<S64>/Valid Halls' */
} B_STMF4Hall_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_TimerBlock_S_T obj; /* '<Root>/Timer1' */
  stm32cube_blocks_TimerBlock_S_T obj_p;/* '<Root>/Timer' */
  uint32_T speedCountDelay_DSTATE;     /* '<S86>/speedCountDelay' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  volatile uint32_T TmpRTBAtFunctionCallSubsystem1I;/* synthesized block */
  volatile uint32_T TmpRTBAtFunctionCallSubsystem2I;/* synthesized block */
  volatile uint32_T time3_Buffer0;     /* synthesized block */
  uint32_T Timercntprev;               /* '<Root>/Data Store Memory3' */
  uint16_T DelayOneStep_DSTATE;        /* '<S87>/Delay One Step' */
  int16_T Timehall;                    /* '<Root>/Data Store Memory2' */
  boolean_T validityDelay_DSTATE;      /* '<S86>/validityDelay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S87>/Delay One Step1' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int8_T FunctionCallSubsystem1_SubsysRa;/* '<Root>/Function-Call Subsystem1' */
  int8_T FunctionCallSubsystem2_SubsysRa;/* '<Root>/Function-Call Subsystem2' */
  int8_T SpeedanddirectionarenotvalidPos;
  /* '<S5>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
  int8_T SpeedanddirectionarevalidUsespe;
    /* '<S5>/Speed and direction are valid Use speed to extrapolate position' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S89>/Subsystem1' */
  int8_T first_order_SubsysRanBC;      /* '<S102>/first_order' */
  int8_T second_order_SubsysRanBC;     /* '<S102>/second_order' */
  int8_T veDirection_SubsysRanBC;      /* '<S102>/+ve Direction' */
  int8_T veDirection_SubsysRanBC_c;    /* '<S102>/-ve Direction' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S89>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S89>/If Action Subsystem' */
  uint8_T Hall_State;                  /* '<Root>/Data Store Memory' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnecti_a1;
                             /* '<S14>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S14>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_a;
                             /* '<S39>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls_h;/* '<S39>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnection;
                             /* '<S64>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls;/* '<S64>/Valid Halls' */
  DW_HallValueof1_STMF4Hall_T HallValueof7_a;/* '<S92>/Hall Value of 7' */
  DW_HallValueof1_STMF4Hall_T HallValueof6_o;/* '<S92>/Hall Value of 6' */
  DW_HallValueof1_STMF4Hall_T HallValueof5_k;/* '<S92>/Hall Value of 5' */
  DW_HallValueof1_STMF4Hall_T HallValueof4_b;/* '<S92>/Hall Value of 4' */
  DW_HallValueof1_STMF4Hall_T HallValueof3_h;/* '<S92>/Hall Value of 3' */
  DW_HallValueof1_STMF4Hall_T HallValueof2_i;/* '<S92>/Hall Value of 2' */
  DW_HallValueof1_STMF4Hall_T HallValueof1_j;/* '<S92>/Hall Value of 1' */
  DW_HallValueof1_STMF4Hall_T HallValueof7_e;/* '<S103>/Hall Value of 7' */
  DW_HallValueof1_STMF4Hall_T HallValueof6_b;/* '<S103>/Hall Value of 6' */
  DW_HallValueof1_STMF4Hall_T HallValueof5_j;/* '<S103>/Hall Value of 5' */
  DW_HallValueof1_STMF4Hall_T HallValueof4_h;/* '<S103>/Hall Value of 4' */
  DW_HallValueof1_STMF4Hall_T HallValueof3_d;/* '<S103>/Hall Value of 3' */
  DW_HallValueof1_STMF4Hall_T HallValueof2_l;/* '<S103>/Hall Value of 2' */
  DW_HallValueof1_STMF4Hall_T HallValueof1_b;/* '<S103>/Hall Value of 1' */
  DW_HallValueof1_STMF4Hall_T HallValueof7;/* '<S104>/Hall Value of 7' */
  DW_HallValueof1_STMF4Hall_T HallValueof6;/* '<S104>/Hall Value of 6' */
  DW_HallValueof1_STMF4Hall_T HallValueof5;/* '<S104>/Hall Value of 5' */
  DW_HallValueof1_STMF4Hall_T HallValueof4;/* '<S104>/Hall Value of 4' */
  DW_HallValueof1_STMF4Hall_T HallValueof3;/* '<S104>/Hall Value of 3' */
  DW_HallValueof1_STMF4Hall_T HallValueof2;/* '<S104>/Hall Value of 2' */
  DW_HallValueof1_STMF4Hall_T HallValueof1;/* '<S104>/Hall Value of 1' */
} DW_STMF4Hall_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Hallstate;                    /* '<Root>/Hall state' */
  real_T Hallangle;                    /* '<Root>/Hall angle' */
} ExtY_STMF4Hall_T;

/* Parameters for system: '<S104>/Hall Value of 1' */
struct P_HallValueof1_STMF4Hall_T_ {
  real32_T Constant_Value;             /* Expression: single(0.16667)
                                        * Referenced by: '<S114>/Constant'
                                        */
};

/* Parameters for system: '<S66>/If Action Subsystem6' */
struct P_IfActionSubsystem6_STMF4Hal_T_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S73>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S73>/Constant1'
                                        */
};

/* Parameters for system: '<S66>/If Action Subsystem' */
struct P_IfActionSubsystem_STMF4Hall_T_ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S67>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S67>/next'
                                        */
};

/* Parameters for system: '<S64>/Valid Halls' */
struct P_ValidHalls_STMF4Hall_T_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S66>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S75>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S66>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S66>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S66>/Merge3'
                                      */
  boolean_T Constant_Value_j;          /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S66>/Constant'
                                        */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem5;/* '<S66>/If Action Subsystem5' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem4;/* '<S66>/If Action Subsystem4' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem3;/* '<S66>/If Action Subsystem3' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem2;/* '<S66>/If Action Subsystem2' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem1;/* '<S66>/If Action Subsystem1' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem;/* '<S66>/If Action Subsystem' */
  P_IfActionSubsystem6_STMF4Hal_T IfActionSubsystem7;/* '<S66>/If Action Subsystem7' */
  P_IfActionSubsystem6_STMF4Hal_T IfActionSubsystem6;/* '<S66>/If Action Subsystem6' */
};

/* Parameters for system: '<S64>/Bad hall (glitch or wrong connection)' */
struct P_Badhallglitchorwrongconnect_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S65>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S65>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_STMF4Hall_T_ {
  uint16_T SoftwareWatchdogTimer_maxCount;
                               /* Mask Parameter: SoftwareWatchdogTimer_maxCount
                                * Referenced by: '<S87>/Delay One Step'
                                */
  real_T Constant_Value;               /* Expression: EnableSecondOrder
                                        * Referenced by: '<S102>/Constant'
                                        */
  real_T Constant_Value_e;             /* Expression: 3
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T Constant_Value_n;             /* Expression: 2
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 1
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S8>/Constant1'
                                        */
  real_T Constant8_Value;              /* Expression: 60
                                        * Referenced by: '<S8>/Constant8'
                                        */
  real_T Constant2_Value;              /* Expression: 4
                                        * Referenced by: '<S8>/Constant2'
                                        */
  real_T Constant9_Value;              /* Expression: 180
                                        * Referenced by: '<S8>/Constant9'
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S8>/Constant3'
                                        */
  real_T Constant10_Value;             /* Expression: 120
                                        * Referenced by: '<S8>/Constant10'
                                        */
  real_T Constant4_Value;              /* Expression: 6
                                        * Referenced by: '<S8>/Constant4'
                                        */
  real_T Constant11_Value;             /* Expression: 300
                                        * Referenced by: '<S8>/Constant11'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S8>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 5
                                        * Referenced by: '<S8>/Constant6'
                                        */
  real_T Constant14_Value;             /* Expression: 240
                                        * Referenced by: '<S8>/Constant14'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S8>/Constant7'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  real_T DataStoreMemory5_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory5'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S8>/Constant12'
                                        */
  real_T DataStoreMemory4_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory4'
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
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S106>/Constant'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S106>/Gain1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S106>/Gain'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S105>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Expression: single(0.16667)
                                        * Referenced by: '<S102>/Saturation'
                                        */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S102>/Saturation'
                                       */
  real32_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S102>/Merge'
                                       */
  real32_T SpeedGain_Gain;             /* Expression: single(MinSpeed)
                                        * Referenced by: '<S89>/SpeedGain'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S88>/Constant'
                                        */
  uint32_T SpeedConst_Value;
                          /* Expression: uint32(30*ClkFreq/(PolePairs*MinSpeed))
                           * Referenced by: '<S89>/SpeedConst'
                           */
  uint32_T speedcheck_Threshold;     /* Computed Parameter: speedcheck_Threshold
                                      * Referenced by: '<S90>/speed check'
                                      */
  uint32_T TmpRTBAtFunctionCallSubsystem1I;
                          /* Computed Parameter: TmpRTBAtFunctionCallSubsystem1I
                           * Referenced by:
                           */
  uint32_T TmpRTBAtFunctionCallSubsystem2I;
                          /* Computed Parameter: TmpRTBAtFunctionCallSubsystem2I
                           * Referenced by:
                           */
  uint32_T time3_InitialCondition; /* Computed Parameter: time3_InitialCondition
                                    * Referenced by:
                                    */
  uint32_T speedCountDelay_InitialConditio;
                          /* Computed Parameter: speedCountDelay_InitialConditio
                           * Referenced by: '<S86>/speedCountDelay'
                           */
  uint32_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  int16_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  int16_T Out1_Y0_b;                   /* Computed Parameter: Out1_Y0_b
                                        * Referenced by: '<S3>/Out1'
                                        */
  int16_T Out1_Y0_l;                   /* Computed Parameter: Out1_Y0_l
                                        * Referenced by: '<S2>/Out1'
                                        */
  int16_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  uint16_T PositionEnable_Value;     /* Computed Parameter: PositionEnable_Value
                                      * Referenced by: '<S89>/PositionEnable'
                                      */
  uint16_T Constant_Value_np;          /* Computed Parameter: Constant_Value_np
                                        * Referenced by: '<S91>/Constant'
                                        */
  uint16_T Order_Value;                /* Computed Parameter: Order_Value
                                        * Referenced by: '<S86>/Order'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S86>/Switch'
                                        */
  uint16_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S90>/Constant'
                                        */
  uint16_T Constant2_Value_m;          /* Computed Parameter: Constant2_Value_m
                                        * Referenced by: '<S87>/Constant2'
                                        */
  boolean_T validityDelay_InitialCondition;
                           /* Computed Parameter: validityDelay_InitialCondition
                            * Referenced by: '<S86>/validityDelay'
                            */
  boolean_T DelayOneStep1_InitialCondition;
                           /* Computed Parameter: DelayOneStep1_InitialCondition
                            * Referenced by: '<S87>/Delay One Step1'
                            */
  uint8_T Gain_Gain_g;                 /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S62>/Gain'
                                        */
  uint8_T Gain_Gain_h;                 /* Computed Parameter: Gain_Gain_h
                                        * Referenced by: '<S37>/Gain'
                                        */
  uint8_T Gain_Gain_a;                 /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S12>/Gain'
                                        */
  uint8_T Gain_Gain_m;                 /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S123>/Gain'
                                        */
  uint8_T Gain1_Gain_c;                /* Computed Parameter: Gain1_Gain_c
                                        * Referenced by: '<S62>/Gain1'
                                        */
  uint8_T Gain1_Gain_d;                /* Computed Parameter: Gain1_Gain_d
                                        * Referenced by: '<S37>/Gain1'
                                        */
  uint8_T Gain1_Gain_i;                /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S12>/Gain1'
                                        */
  uint8_T Gain1_Gain_p;                /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S123>/Gain1'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S62>/Gain2'
                                        */
  uint8_T Gain2_Gain_m;                /* Computed Parameter: Gain2_Gain_m
                                        * Referenced by: '<S37>/Gain2'
                                        */
  uint8_T Gain2_Gain_f;                /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S12>/Gain2'
                                        */
  uint8_T Gain2_Gain_n;                /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<S123>/Gain2'
                                        */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnecti_a1;
                             /* '<S14>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S14>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_a;
                             /* '<S39>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls_h;/* '<S39>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnection;
                             /* '<S64>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls; /* '<S64>/Valid Halls' */
  P_HallValueof1_STMF4Hall_T HallValueof7_a;/* '<S92>/Hall Value of 7' */
  P_HallValueof1_STMF4Hall_T HallValueof6_o;/* '<S92>/Hall Value of 6' */
  P_HallValueof1_STMF4Hall_T HallValueof5_k;/* '<S92>/Hall Value of 5' */
  P_HallValueof1_STMF4Hall_T HallValueof4_b;/* '<S92>/Hall Value of 4' */
  P_HallValueof1_STMF4Hall_T HallValueof3_h;/* '<S92>/Hall Value of 3' */
  P_HallValueof1_STMF4Hall_T HallValueof2_i;/* '<S92>/Hall Value of 2' */
  P_HallValueof1_STMF4Hall_T HallValueof1_j;/* '<S92>/Hall Value of 1' */
  P_HallValueof1_STMF4Hall_T HallValueof7_e;/* '<S103>/Hall Value of 7' */
  P_HallValueof1_STMF4Hall_T HallValueof6_b;/* '<S103>/Hall Value of 6' */
  P_HallValueof1_STMF4Hall_T HallValueof5_j;/* '<S103>/Hall Value of 5' */
  P_HallValueof1_STMF4Hall_T HallValueof4_h;/* '<S103>/Hall Value of 4' */
  P_HallValueof1_STMF4Hall_T HallValueof3_d;/* '<S103>/Hall Value of 3' */
  P_HallValueof1_STMF4Hall_T HallValueof2_l;/* '<S103>/Hall Value of 2' */
  P_HallValueof1_STMF4Hall_T HallValueof1_b;/* '<S103>/Hall Value of 1' */
  P_HallValueof1_STMF4Hall_T HallValueof7;/* '<S104>/Hall Value of 7' */
  P_HallValueof1_STMF4Hall_T HallValueof6;/* '<S104>/Hall Value of 6' */
  P_HallValueof1_STMF4Hall_T HallValueof5;/* '<S104>/Hall Value of 5' */
  P_HallValueof1_STMF4Hall_T HallValueof4;/* '<S104>/Hall Value of 4' */
  P_HallValueof1_STMF4Hall_T HallValueof3;/* '<S104>/Hall Value of 3' */
  P_HallValueof1_STMF4Hall_T HallValueof2;/* '<S104>/Hall Value of 2' */
  P_HallValueof1_STMF4Hall_T HallValueof1;/* '<S104>/Hall Value of 1' */
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
  void STMF4Hall_configure_interrupts (void);
  void STMF4Hall_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S11>/Constant' : Unused code path elimination
 * Block '<S14>/Data Type Conversion' : Unused code path elimination
 * Block '<S11>/counterSize' : Unused code path elimination
 * Block '<S36>/Constant' : Unused code path elimination
 * Block '<S39>/Data Type Conversion' : Unused code path elimination
 * Block '<S36>/counterSize' : Unused code path elimination
 * Block '<S61>/Constant' : Unused code path elimination
 * Block '<S64>/Data Type Conversion' : Unused code path elimination
 * Block '<S61>/counterSize' : Unused code path elimination
 * Block '<S5>/PositionUnit' : Unused code path elimination
 * Block '<S5>/Switch' : Unused code path elimination
 * Block '<S5>/WatchDog' : Unused code path elimination
 * Block '<S11>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S36>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S61>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S5>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S5>/counterSize1' : Eliminate redundant data type conversion
 * Block '<S5>/counterSize2' : Eliminate redundant data type conversion
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
 * '<S1>'   : 'STMF4Hall/Digital Port Write'
 * '<S2>'   : 'STMF4Hall/Function-Call Subsystem'
 * '<S3>'   : 'STMF4Hall/Function-Call Subsystem1'
 * '<S4>'   : 'STMF4Hall/Function-Call Subsystem2'
 * '<S5>'   : 'STMF4Hall/Hall Speed and Position'
 * '<S6>'   : 'STMF4Hall/Hardware Interrupt'
 * '<S7>'   : 'STMF4Hall/Initialize Function'
 * '<S8>'   : 'STMF4Hall/Subsystem'
 * '<S9>'   : 'STMF4Hall/Digital Port Write/ECSoC'
 * '<S10>'  : 'STMF4Hall/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S11>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity'
 * '<S12>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation'
 * '<S13>'  : 'STMF4Hall/Function-Call Subsystem/Subsystem'
 * '<S14>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem'
 * '<S15>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S16>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls'
 * '<S17>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S18>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S19>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S20>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S21>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S22>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S23>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S24>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S25>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S26>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S27>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read'
 * '<S28>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read1'
 * '<S29>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read2'
 * '<S30>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read/ECSoC'
 * '<S31>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S32>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read1/ECSoC'
 * '<S33>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S34>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read2/ECSoC'
 * '<S35>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S36>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity'
 * '<S37>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation'
 * '<S38>'  : 'STMF4Hall/Function-Call Subsystem1/Subsystem'
 * '<S39>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem'
 * '<S40>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S41>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls'
 * '<S42>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S43>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S44>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S45>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S46>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S47>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S48>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S49>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S50>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S51>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S52>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read'
 * '<S53>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read1'
 * '<S54>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read2'
 * '<S55>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read/ECSoC'
 * '<S56>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S57>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read1/ECSoC'
 * '<S58>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S59>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read2/ECSoC'
 * '<S60>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S61>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity'
 * '<S62>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation'
 * '<S63>'  : 'STMF4Hall/Function-Call Subsystem2/Subsystem'
 * '<S64>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem'
 * '<S65>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S66>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls'
 * '<S67>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S68>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S69>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S70>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S71>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S72>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S73>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S74>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S75>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S76>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S77>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read'
 * '<S78>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read1'
 * '<S79>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read2'
 * '<S80>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read/ECSoC'
 * '<S81>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S82>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read1/ECSoC'
 * '<S83>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S84>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read2/ECSoC'
 * '<S85>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S86>'  : 'STMF4Hall/Hall Speed and Position/ExtrapolationOrder'
 * '<S87>'  : 'STMF4Hall/Hall Speed and Position/Software Watchdog Timer'
 * '<S88>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S89>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position'
 * '<S90>'  : 'STMF4Hall/Hall Speed and Position/VaidityCheck'
 * '<S91>'  : 'STMF4Hall/Hall Speed and Position/Software Watchdog Timer/Compare To Zero'
 * '<S92>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S93>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S94>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S95>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S96>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S97>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S98>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S99>'  : 'STMF4Hall/Hall Speed and Position/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S100>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S101>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S102>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S103>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S104>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S105>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S106>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S107>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S108>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S109>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S110>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S111>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S112>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S113>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S114>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S115>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S116>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S117>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S118>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S119>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S120>' : 'STMF4Hall/Hall Speed and Position/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S121>' : 'STMF4Hall/Hardware Interrupt/ECSoC'
 * '<S122>' : 'STMF4Hall/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S123>' : 'STMF4Hall/Initialize Function/Hallstation'
 * '<S124>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read'
 * '<S125>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1'
 * '<S126>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2'
 * '<S127>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read/ECSoC'
 * '<S128>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S129>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1/ECSoC'
 * '<S130>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S131>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2/ECSoC'
 * '<S132>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 */
#endif                                 /* STMF4Hall_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
