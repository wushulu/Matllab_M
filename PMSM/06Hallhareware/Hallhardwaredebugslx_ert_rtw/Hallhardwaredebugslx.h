/*
 * File: Hallhardwaredebugslx.h
 *
 * Code generated for Simulink model 'Hallhardwaredebugslx'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Oct 12 17:53:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Hallhardwaredebugslx_h_
#define Hallhardwaredebugslx_h_
#ifndef Hallhardwaredebugslx_COMMON_INCLUDES_
#define Hallhardwaredebugslx_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#endif                               /* Hallhardwaredebugslx_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "Hallhardwaredebugslx_types.h"
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

/* Block states (default storage) for system '<S120>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S120>/If Action Subsystem6' */
} DW_IfActionSubsystem6_Hallhar_T;

/* Block states (default storage) for system '<S120>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S120>/If Action Subsystem' */
} DW_IfActionSubsystem_Hallhard_T;

/* Block signals for system '<S118>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S120>/Merge' */
  uint16_T Merge1;                     /* '<S120>/Merge1' */
  uint16_T Merge3;                     /* '<S120>/Merge3' */
  int16_T Merge2;                      /* '<S120>/Merge2' */
} B_ValidHalls_Hallhardwaredebu_T;

/* Block states (default storage) for system '<S118>/Valid Halls' */
typedef struct {
  int8_T ValidHalls_SubsysRanBC;       /* '<S118>/Valid Halls' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                     /* '<S120>/Switch Case Action Subsystem' */
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S120>/If Action Subsystem8' */
  DW_IfActionSubsystem_Hallhard_T IfActionSubsystem5;/* '<S120>/If Action Subsystem5' */
  DW_IfActionSubsystem_Hallhard_T IfActionSubsystem4;/* '<S120>/If Action Subsystem4' */
  DW_IfActionSubsystem_Hallhard_T IfActionSubsystem3;/* '<S120>/If Action Subsystem3' */
  DW_IfActionSubsystem_Hallhard_T IfActionSubsystem2;/* '<S120>/If Action Subsystem2' */
  DW_IfActionSubsystem_Hallhard_T IfActionSubsystem1;/* '<S120>/If Action Subsystem1' */
  DW_IfActionSubsystem_Hallhard_T IfActionSubsystem;/* '<S120>/If Action Subsystem' */
  DW_IfActionSubsystem6_Hallhar_T IfActionSubsystem7;/* '<S120>/If Action Subsystem7' */
  DW_IfActionSubsystem6_Hallhar_T IfActionSubsystem6;/* '<S120>/If Action Subsystem6' */
} DW_ValidHalls_Hallhardwaredeb_T;

/* Block states (default storage) for system '<S118>/Bad hall (glitch or wrong connection)' */
typedef struct {
  int8_T Badhallglitchorwrongconnection_;
                            /* '<S118>/Bad hall (glitch or wrong connection)' */
} DW_Badhallglitchorwrongconnec_T;

/* Block states (default storage) for system '<S48>/Hall Value of 1' */
typedef struct {
  int8_T HallValueof1_SubsysRanBC;     /* '<S48>/Hall Value of 1' */
} DW_HallValueof1_Hallhardwared_T;

/* Block signals (default storage) */
typedef struct {
  uint16_T DelayOneStep;               /* '<S31>/Delay One Step' */
  boolean_T validityDelay;             /* '<S30>/validityDelay' */
  B_ValidHalls_Hallhardwaredebu_T ValidHalls_i;/* '<S68>/Valid Halls' */
  B_ValidHalls_Hallhardwaredebu_T ValidHalls_f;/* '<S93>/Valid Halls' */
  B_ValidHalls_Hallhardwaredebu_T ValidHalls;/* '<S118>/Valid Halls' */
} B_Hallhardwaredebugslx_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S16>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Ha_T obj_m;/* '<S148>/PWM Output' */
  stm32cube_blocks_PWMOutput_Ha_T obj_h;/* '<S20>/PWM Output' */
  stm32cube_blocks_TimerBlock_H_T obj_e;/* '<S67>/Timer' */
  stm32cube_blocks_TimerBlock_H_T obj_et;/* '<S92>/Timer' */
  stm32cube_blocks_TimerBlock_H_T obj_etd;/* '<S117>/Timer' */
  real_T HallCcapture;                 /* '<Root>/Data Store Memory10' */
  real_T HallBcapture;                 /* '<Root>/Data Store Memory4' */
  real_T HallAcapture;                 /* '<Root>/Data Store Memory2' */
  int64_T Timehall;                    /* '<Root>/Data Store Memory3' */
  uint32_T speedCountDelay_DSTATE;     /* '<S30>/speedCountDelay' */
  uint32_T Delay_DSTATE;               /* '<S67>/Delay' */
  uint32_T Delay_DSTATE_b;             /* '<S92>/Delay' */
  uint32_T Delay_DSTATE_m;             /* '<S117>/Delay' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  uint32_T Timercntprev;               /* '<Root>/Data Store Memory1' */
  uint32_T GlobalSpeedCount;           /* '<Root>/Data Store Memory6' */
  uint16_T DelayOneStep_DSTATE;        /* '<S31>/Delay One Step' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory5' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory7' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory8' */
  boolean_T validityDelay_DSTATE;      /* '<S30>/validityDelay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S31>/Delay One Step1' */
  int8_T ADCSIC_SubsysRanBC;           /* '<Root>/ADC SIC' */
  int8_T SpeedanddirectionarenotvalidPos;
  /* '<S29>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
  int8_T SpeedanddirectionarevalidUsespe;
  /* '<S29>/Speed and direction are valid Use speed to extrapolate position' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S33>/Subsystem1' */
  int8_T first_order_SubsysRanBC;      /* '<S46>/first_order' */
  int8_T second_order_SubsysRanBC;     /* '<S46>/second_order' */
  int8_T veDirection_SubsysRanBC;      /* '<S46>/+ve Direction' */
  int8_T veDirection_SubsysRanBC_e;    /* '<S46>/-ve Direction' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S33>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S33>/If Action Subsystem' */
  int8_T HA_SubsysRanBC;               /* '<Root>/HA' */
  int8_T HB_SubsysRanBC;               /* '<Root>/HB' */
  int8_T HC_SubsysRanBC;               /* '<Root>/HC' */
  uint8_T GlobalHallState;             /* '<Root>/Data Store Memory' */
  DW_HallValueof1_Hallhardwared_T HallValueof7_i;/* '<S36>/Hall Value of 7' */
  DW_HallValueof1_Hallhardwared_T HallValueof6_m;/* '<S36>/Hall Value of 6' */
  DW_HallValueof1_Hallhardwared_T HallValueof5_p;/* '<S36>/Hall Value of 5' */
  DW_HallValueof1_Hallhardwared_T HallValueof4_c;/* '<S36>/Hall Value of 4' */
  DW_HallValueof1_Hallhardwared_T HallValueof3_jh;/* '<S36>/Hall Value of 3' */
  DW_HallValueof1_Hallhardwared_T HallValueof2_b;/* '<S36>/Hall Value of 2' */
  DW_HallValueof1_Hallhardwared_T HallValueof1_d;/* '<S36>/Hall Value of 1' */
  DW_HallValueof1_Hallhardwared_T HallValueof7_g;/* '<S47>/Hall Value of 7' */
  DW_HallValueof1_Hallhardwared_T HallValueof6_i;/* '<S47>/Hall Value of 6' */
  DW_HallValueof1_Hallhardwared_T HallValueof5_i;/* '<S47>/Hall Value of 5' */
  DW_HallValueof1_Hallhardwared_T HallValueof4_b;/* '<S47>/Hall Value of 4' */
  DW_HallValueof1_Hallhardwared_T HallValueof3_j;/* '<S47>/Hall Value of 3' */
  DW_HallValueof1_Hallhardwared_T HallValueof2_m;/* '<S47>/Hall Value of 2' */
  DW_HallValueof1_Hallhardwared_T HallValueof1_h;/* '<S47>/Hall Value of 1' */
  DW_HallValueof1_Hallhardwared_T HallValueof7;/* '<S48>/Hall Value of 7' */
  DW_HallValueof1_Hallhardwared_T HallValueof6;/* '<S48>/Hall Value of 6' */
  DW_HallValueof1_Hallhardwared_T HallValueof5;/* '<S48>/Hall Value of 5' */
  DW_HallValueof1_Hallhardwared_T HallValueof4;/* '<S48>/Hall Value of 4' */
  DW_HallValueof1_Hallhardwared_T HallValueof3;/* '<S48>/Hall Value of 3' */
  DW_HallValueof1_Hallhardwared_T HallValueof2;/* '<S48>/Hall Value of 2' */
  DW_HallValueof1_Hallhardwared_T HallValueof1;/* '<S48>/Hall Value of 1' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_g;
                             /* '<S68>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_Hallhardwaredeb_T ValidHalls_i;/* '<S68>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_d;
                             /* '<S93>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_Hallhardwaredeb_T ValidHalls_f;/* '<S93>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_h;
                            /* '<S118>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_Hallhardwaredeb_T ValidHalls;/* '<S118>/Valid Halls' */
} DW_Hallhardwaredebugslx_T;

/* Parameters for system: '<S120>/If Action Subsystem6' */
struct P_IfActionSubsystem6_Hallhard_T_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S127>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S127>/Constant1'
                                        */
};

/* Parameters for system: '<S120>/If Action Subsystem' */
struct P_IfActionSubsystem_Hallhardw_T_ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S121>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S121>/next'
                                        */
};

/* Parameters for system: '<S118>/Valid Halls' */
struct P_ValidHalls_Hallhardwaredebu_T_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S120>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S129>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S120>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S120>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S120>/Merge3'
                                      */
  boolean_T Constant_Value_d;          /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S120>/Constant'
                                        */
  P_IfActionSubsystem_Hallhardw_T IfActionSubsystem5;/* '<S120>/If Action Subsystem5' */
  P_IfActionSubsystem_Hallhardw_T IfActionSubsystem4;/* '<S120>/If Action Subsystem4' */
  P_IfActionSubsystem_Hallhardw_T IfActionSubsystem3;/* '<S120>/If Action Subsystem3' */
  P_IfActionSubsystem_Hallhardw_T IfActionSubsystem2;/* '<S120>/If Action Subsystem2' */
  P_IfActionSubsystem_Hallhardw_T IfActionSubsystem1;/* '<S120>/If Action Subsystem1' */
  P_IfActionSubsystem_Hallhardw_T IfActionSubsystem;/* '<S120>/If Action Subsystem' */
  P_IfActionSubsystem6_Hallhard_T IfActionSubsystem7;/* '<S120>/If Action Subsystem7' */
  P_IfActionSubsystem6_Hallhard_T IfActionSubsystem6;/* '<S120>/If Action Subsystem6' */
};

/* Parameters for system: '<S118>/Bad hall (glitch or wrong connection)' */
struct P_Badhallglitchorwrongconnect_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S119>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S119>/Constant1'
                                        */
};

/* Parameters for system: '<S48>/Hall Value of 1' */
struct P_HallValueof1_Hallhardwarede_T_ {
  real32_T Constant_Value;             /* Expression: single(0.16667)
                                        * Referenced by: '<S58>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_Hallhardwaredebugslx_T_ {
  uint16_T SoftwareWatchdogTimer_maxCount;
                               /* Mask Parameter: SoftwareWatchdogTimer_maxCount
                                * Referenced by: '<S31>/Delay One Step'
                                */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant1_Value_d;            /* Expression: 100
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant1_Value_b;            /* Expression: 100
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: EnableSecondOrder
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T Constant_Value_a;             /* Expression: 0.5
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Ka_Gain;                      /* Expression: 1
                                        * Referenced by: '<S27>/Ka'
                                        */
  real_T one_by_two_Gain;              /* Expression: 1/2
                                        * Referenced by: '<S27>/one_by_two'
                                        */
  real_T sqrt3_by_two_Gain;            /* Expression: sqrt(3)/2
                                        * Referenced by: '<S27>/sqrt3_by_two'
                                        */
  real_T Kb_Gain;                      /* Expression: 1
                                        * Referenced by: '<S27>/Kb'
                                        */
  real_T Kc_Gain;                      /* Expression: 1
                                        * Referenced by: '<S27>/Kc'
                                        */
  real_T one_by_two_Gain_j;            /* Expression: -0.5
                                        * Referenced by: '<S24>/one_by_two'
                                        */
  real_T Gain_Gain;                    /* Expression: 2/sqrt(3)
                                        * Referenced by: '<S23>/Gain'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 100
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 100
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T Constant1_Value_a;            /* Expression: 10
                                        * Referenced by: '<S8>/Constant1'
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
  real_T DataStoreMemory10_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory10'
                                         */
  real_T DataStoreMemory4_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory4'
                                        */
  real_T DataStoreMemory2_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory2'
                                        */
  int64_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  int64_T Out1_Y0_p;                   /* Computed Parameter: Out1_Y0_p
                                        * Referenced by: '<S3>/Out1'
                                        */
  int64_T Out1_Y0_g;                   /* Computed Parameter: Out1_Y0_g
                                        * Referenced by: '<S2>/Out1'
                                        */
  int64_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  int32_T Gain_Gain_d;                 /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S4>/Gain'
                                        */
  int32_T Gain_Gain_ei;                /* Computed Parameter: Gain_Gain_ei
                                        * Referenced by: '<S3>/Gain'
                                        */
  int32_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T Constant_Value_a1;          /* Computed Parameter: Constant_Value_a1
                                        * Referenced by: '<S50>/Constant'
                                        */
  real32_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S50>/Gain1'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S50>/Gain'
                                        */
  real32_T Gain_Gain_d0;               /* Computed Parameter: Gain_Gain_d0
                                        * Referenced by: '<S49>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Expression: single(0.16667)
                                        * Referenced by: '<S46>/Saturation'
                                        */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S46>/Saturation'
                                       */
  real32_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S46>/Merge'
                                       */
  real32_T SpeedGain_Gain;             /* Expression: single(6*MinSpeed)
                                        * Referenced by: '<S33>/SpeedGain'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S32>/Constant'
                                        */
  real32_T Posdegree_Y0;               /* Computed Parameter: Posdegree_Y0
                                        * Referenced by: '<S1>/Posdegree'
                                        */
  uint32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S117>/Delay'
                                    */
  uint32_T Delay_InitialCondition_j;
                                 /* Computed Parameter: Delay_InitialCondition_j
                                  * Referenced by: '<S92>/Delay'
                                  */
  uint32_T Delay_InitialCondition_n;
                                 /* Computed Parameter: Delay_InitialCondition_n
                                  * Referenced by: '<S67>/Delay'
                                  */
  uint32_T SpeedConst_Value;
                          /* Expression: uint32(30*ClkFreq/(PolePairs*MinSpeed))
                           * Referenced by: '<S33>/SpeedConst'
                           */
  uint32_T speedcheck_Threshold;     /* Computed Parameter: speedcheck_Threshold
                                      * Referenced by: '<S34>/speed check'
                                      */
  uint32_T speedCountDelay_InitialConditio;
                          /* Computed Parameter: speedCountDelay_InitialConditio
                           * Referenced by: '<S30>/speedCountDelay'
                           */
  uint32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint32_T DataStoreMemory6_InitialValue;
                            /* Computed Parameter: DataStoreMemory6_InitialValue
                             * Referenced by: '<Root>/Data Store Memory6'
                             */
  int16_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  uint16_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S115>/Constant'
                                        */
  uint16_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S90>/Constant'
                                        */
  uint16_T Constant_Value_oj;          /* Computed Parameter: Constant_Value_oj
                                        * Referenced by: '<S65>/Constant'
                                        */
  uint16_T PositionEnable_Value;     /* Computed Parameter: PositionEnable_Value
                                      * Referenced by: '<S33>/PositionEnable'
                                      */
  uint16_T WatchDog_Value;             /* Computed Parameter: WatchDog_Value
                                        * Referenced by: '<S29>/WatchDog'
                                        */
  uint16_T ct_Y0;                      /* Computed Parameter: ct_Y0
                                        * Referenced by: '<S1>/ct'
                                        */
  uint16_T Constant_Value_dj;          /* Computed Parameter: Constant_Value_dj
                                        * Referenced by: '<S35>/Constant'
                                        */
  uint16_T Order_Value;                /* Computed Parameter: Order_Value
                                        * Referenced by: '<S30>/Order'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S30>/Switch'
                                        */
  uint16_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S34>/Constant'
                                        */
  uint16_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S31>/Constant2'
                                        */
  uint16_T DataStoreMemory7_InitialValue;
                            /* Computed Parameter: DataStoreMemory7_InitialValue
                             * Referenced by: '<Root>/Data Store Memory7'
                             */
  uint16_T DataStoreMemory8_InitialValue;
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  boolean_T validityDelay_InitialCondition;
                           /* Computed Parameter: validityDelay_InitialCondition
                            * Referenced by: '<S30>/validityDelay'
                            */
  boolean_T DelayOneStep1_InitialCondition;
                           /* Computed Parameter: DelayOneStep1_InitialCondition
                            * Referenced by: '<S31>/Delay One Step1'
                            */
  uint8_T Gain_Gain_ea;                /* Computed Parameter: Gain_Gain_ea
                                        * Referenced by: '<S116>/Gain'
                                        */
  uint8_T Gain_Gain_n;                 /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S91>/Gain'
                                        */
  uint8_T Gain_Gain_l;                 /* Computed Parameter: Gain_Gain_l
                                        * Referenced by: '<S66>/Gain'
                                        */
  uint8_T Gain1_Gain_e;                /* Computed Parameter: Gain1_Gain_e
                                        * Referenced by: '<S116>/Gain1'
                                        */
  uint8_T Gain1_Gain_et;               /* Computed Parameter: Gain1_Gain_et
                                        * Referenced by: '<S91>/Gain1'
                                        */
  uint8_T Gain1_Gain_jt;               /* Computed Parameter: Gain1_Gain_jt
                                        * Referenced by: '<S66>/Gain1'
                                        */
  uint8_T Gain2_Gain_d;                /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S116>/Gain2'
                                        */
  uint8_T Gain2_Gain_g;                /* Computed Parameter: Gain2_Gain_g
                                        * Referenced by: '<S91>/Gain2'
                                        */
  uint8_T Gain2_Gain_h;                /* Computed Parameter: Gain2_Gain_h
                                        * Referenced by: '<S66>/Gain2'
                                        */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  P_HallValueof1_Hallhardwarede_T HallValueof7_i;/* '<S36>/Hall Value of 7' */
  P_HallValueof1_Hallhardwarede_T HallValueof6_m;/* '<S36>/Hall Value of 6' */
  P_HallValueof1_Hallhardwarede_T HallValueof5_p;/* '<S36>/Hall Value of 5' */
  P_HallValueof1_Hallhardwarede_T HallValueof4_c;/* '<S36>/Hall Value of 4' */
  P_HallValueof1_Hallhardwarede_T HallValueof3_jh;/* '<S36>/Hall Value of 3' */
  P_HallValueof1_Hallhardwarede_T HallValueof2_b;/* '<S36>/Hall Value of 2' */
  P_HallValueof1_Hallhardwarede_T HallValueof1_d;/* '<S36>/Hall Value of 1' */
  P_HallValueof1_Hallhardwarede_T HallValueof7_g;/* '<S47>/Hall Value of 7' */
  P_HallValueof1_Hallhardwarede_T HallValueof6_i;/* '<S47>/Hall Value of 6' */
  P_HallValueof1_Hallhardwarede_T HallValueof5_i;/* '<S47>/Hall Value of 5' */
  P_HallValueof1_Hallhardwarede_T HallValueof4_b;/* '<S47>/Hall Value of 4' */
  P_HallValueof1_Hallhardwarede_T HallValueof3_j;/* '<S47>/Hall Value of 3' */
  P_HallValueof1_Hallhardwarede_T HallValueof2_m;/* '<S47>/Hall Value of 2' */
  P_HallValueof1_Hallhardwarede_T HallValueof1_h;/* '<S47>/Hall Value of 1' */
  P_HallValueof1_Hallhardwarede_T HallValueof7;/* '<S48>/Hall Value of 7' */
  P_HallValueof1_Hallhardwarede_T HallValueof6;/* '<S48>/Hall Value of 6' */
  P_HallValueof1_Hallhardwarede_T HallValueof5;/* '<S48>/Hall Value of 5' */
  P_HallValueof1_Hallhardwarede_T HallValueof4;/* '<S48>/Hall Value of 4' */
  P_HallValueof1_Hallhardwarede_T HallValueof3;/* '<S48>/Hall Value of 3' */
  P_HallValueof1_Hallhardwarede_T HallValueof2;/* '<S48>/Hall Value of 2' */
  P_HallValueof1_Hallhardwarede_T HallValueof1;/* '<S48>/Hall Value of 1' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_g;
                             /* '<S68>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_Hallhardwaredebu_T ValidHalls_i;/* '<S68>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_d;
                             /* '<S93>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_Hallhardwaredebu_T ValidHalls_f;/* '<S93>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_h;
                            /* '<S118>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_Hallhardwaredebu_T ValidHalls;/* '<S118>/Valid Halls' */
};

/* Real-time Model Data Structure */
struct tag_RTM_Hallhardwaredebugslx_T {
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
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_Hallhardwaredebugslx_T Hallhardwaredebugslx_P;

/* Block signals (default storage) */
extern B_Hallhardwaredebugslx_T Hallhardwaredebugslx_B;

/* Block states (default storage) */
extern DW_Hallhardwaredebugslx_T Hallhardwaredebugslx_DW;

/* Model entry point functions */
extern void Hallhardwaredebugslx_initialize(void);
extern void Hallhardwaredebugslx_step(void);
extern void Hallhardwaredebugslx_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Hallhardwaredebugslx_T *const Hallhardwaredebugslx_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC_IRQHandler(void);
  void EXTI15_10_IRQHandler(void);
  void Hallhardwaredebugslx_configure_interrupts (void);
  void Hallhardwaredebugslx_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S17>/FixPt Constant' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S17>/FixPt Sum1' : Unused code path elimination
 * Block '<S10>/Output' : Unused code path elimination
 * Block '<S18>/Constant' : Unused code path elimination
 * Block '<S18>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S18>/FixPt Switch' : Unused code path elimination
 * Block '<S12>/Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/Vc' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/Data Type' : Unused code path elimination
 * Block '<S13>/Number of pole pairs' : Unused code path elimination
 * Block '<S13>/PWM Frequency' : Unused code path elimination
 * Block '<S28>/Discrete-Time Integrator' : Unused code path elimination
 * Block '<S28>/Gain' : Unused code path elimination
 * Block '<S29>/PositionUnit' : Unused code path elimination
 * Block '<S28>/Sum' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S8>/Data Type' : Unused code path elimination
 * Block '<S8>/Number of pole pairs' : Unused code path elimination
 * Block '<S8>/PWM Frequency' : Unused code path elimination
 * Block '<S29>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S29>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S29>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S29>/counterSize2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S65>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S90>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S115>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'Hallhardwaredebugslx'
 * '<S1>'   : 'Hallhardwaredebugslx/ADC SIC'
 * '<S2>'   : 'Hallhardwaredebugslx/HA'
 * '<S3>'   : 'Hallhardwaredebugslx/HB'
 * '<S4>'   : 'Hallhardwaredebugslx/HC'
 * '<S5>'   : 'Hallhardwaredebugslx/Hardware Interrupt'
 * '<S6>'   : 'Hallhardwaredebugslx/Hardware Interrupt2'
 * '<S7>'   : 'Hallhardwaredebugslx/Heartbeat LED'
 * '<S8>'   : 'Hallhardwaredebugslx/Parameters'
 * '<S9>'   : 'Hallhardwaredebugslx/ADC SIC/Analog to Digital Converter'
 * '<S10>'  : 'Hallhardwaredebugslx/ADC SIC/Counter Limited1'
 * '<S11>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Output'
 * '<S12>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Reference Generator'
 * '<S13>'  : 'Hallhardwaredebugslx/ADC SIC/Parameters'
 * '<S14>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem'
 * '<S15>'  : 'Hallhardwaredebugslx/ADC SIC/Analog to Digital Converter/ECSoC'
 * '<S16>'  : 'Hallhardwaredebugslx/ADC SIC/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S17>'  : 'Hallhardwaredebugslx/ADC SIC/Counter Limited1/Increment Real World'
 * '<S18>'  : 'Hallhardwaredebugslx/ADC SIC/Counter Limited1/Wrap To Zero'
 * '<S19>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Output/ECSoC'
 * '<S20>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Output/ECSoC/ECSimCodegen'
 * '<S21>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Reference Generator/Modulation method'
 * '<S22>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Reference Generator/Voltage Input'
 * '<S23>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Reference Generator/Modulation method/SVPWM'
 * '<S24>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S25>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S26>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S27>'  : 'Hallhardwaredebugslx/ADC SIC/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S28>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1'
 * '<S29>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1'
 * '<S30>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/ExtrapolationOrder'
 * '<S31>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Software Watchdog Timer'
 * '<S32>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S33>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position'
 * '<S34>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/VaidityCheck'
 * '<S35>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Software Watchdog Timer/Compare To Zero'
 * '<S36>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S37>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S38>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S39>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S40>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S41>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S42>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S43>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S44>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S45>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S46>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S47>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S48>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S49>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S50>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S51>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S52>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S53>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S54>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S55>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S56>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S57>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S58>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S59>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S60>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S61>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S62>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S63>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S64>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S65>'  : 'Hallhardwaredebugslx/HA/Hall Validity'
 * '<S66>'  : 'Hallhardwaredebugslx/HA/Hallstation'
 * '<S67>'  : 'Hallhardwaredebugslx/HA/Subsystem'
 * '<S68>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem'
 * '<S69>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S70>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls'
 * '<S71>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S72>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S73>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S74>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S75>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S76>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S77>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S78>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S79>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S80>'  : 'Hallhardwaredebugslx/HA/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S81>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read'
 * '<S82>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read1'
 * '<S83>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read2'
 * '<S84>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read/ECSoC'
 * '<S85>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S86>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read1/ECSoC'
 * '<S87>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S88>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read2/ECSoC'
 * '<S89>'  : 'Hallhardwaredebugslx/HA/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S90>'  : 'Hallhardwaredebugslx/HB/Hall Validity'
 * '<S91>'  : 'Hallhardwaredebugslx/HB/Hallstation'
 * '<S92>'  : 'Hallhardwaredebugslx/HB/Subsystem'
 * '<S93>'  : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem'
 * '<S94>'  : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S95>'  : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls'
 * '<S96>'  : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S97>'  : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S98>'  : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S99>'  : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S100>' : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S101>' : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S102>' : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S103>' : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S104>' : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S105>' : 'Hallhardwaredebugslx/HB/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S106>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read'
 * '<S107>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read1'
 * '<S108>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read2'
 * '<S109>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read/ECSoC'
 * '<S110>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S111>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read1/ECSoC'
 * '<S112>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S113>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read2/ECSoC'
 * '<S114>' : 'Hallhardwaredebugslx/HB/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S115>' : 'Hallhardwaredebugslx/HC/Hall Validity'
 * '<S116>' : 'Hallhardwaredebugslx/HC/Hallstation'
 * '<S117>' : 'Hallhardwaredebugslx/HC/Subsystem'
 * '<S118>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem'
 * '<S119>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S120>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls'
 * '<S121>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S122>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S123>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S124>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S125>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S126>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S127>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S128>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S129>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S130>' : 'Hallhardwaredebugslx/HC/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S131>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read'
 * '<S132>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read1'
 * '<S133>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read2'
 * '<S134>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read/ECSoC'
 * '<S135>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S136>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read1/ECSoC'
 * '<S137>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S138>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read2/ECSoC'
 * '<S139>' : 'Hallhardwaredebugslx/HC/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S140>' : 'Hallhardwaredebugslx/Hardware Interrupt/ECSoC'
 * '<S141>' : 'Hallhardwaredebugslx/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S142>' : 'Hallhardwaredebugslx/Hardware Interrupt2/ECSoC'
 * '<S143>' : 'Hallhardwaredebugslx/Hardware Interrupt2/ECSoC/ECSimCodegen'
 * '<S144>' : 'Hallhardwaredebugslx/Heartbeat LED/ECSoC'
 * '<S145>' : 'Hallhardwaredebugslx/Heartbeat LED/ECSoC/ECSimCodegen'
 * '<S146>' : 'Hallhardwaredebugslx/Parameters/PWM Output'
 * '<S147>' : 'Hallhardwaredebugslx/Parameters/PWM Output/ECSoC'
 * '<S148>' : 'Hallhardwaredebugslx/Parameters/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* Hallhardwaredebugslx_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
