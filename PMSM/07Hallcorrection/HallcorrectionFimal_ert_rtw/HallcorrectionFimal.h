/*
 * File: HallcorrectionFimal.h
 *
 * Code generated for Simulink model 'HallcorrectionFimal'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Oct 18 17:25:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef HallcorrectionFimal_h_
#define HallcorrectionFimal_h_
#ifndef HallcorrectionFimal_COMMON_INCLUDES_
#define HallcorrectionFimal_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "ext_mode.h"
#include "main.h"
#endif                                /* HallcorrectionFimal_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "HallcorrectionFimal_types.h"
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

/* Block states (default storage) for system '<S150>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S150>/If Action Subsystem6' */
} DW_IfActionSubsystem6_Hallcor_T;

/* Block states (default storage) for system '<S150>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S150>/If Action Subsystem' */
} DW_IfActionSubsystem_Hallcorr_T;

/* Block signals for system '<S148>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S150>/Merge' */
  uint16_T Merge1;                     /* '<S150>/Merge1' */
  uint16_T Merge3;                     /* '<S150>/Merge3' */
  int16_T Merge2;                      /* '<S150>/Merge2' */
} B_ValidHalls_HallcorrectionFi_T;

/* Block states (default storage) for system '<S148>/Valid Halls' */
typedef struct {
  int8_T ValidHalls_SubsysRanBC;       /* '<S148>/Valid Halls' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                     /* '<S150>/Switch Case Action Subsystem' */
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S150>/If Action Subsystem8' */
  DW_IfActionSubsystem_Hallcorr_T IfActionSubsystem5;/* '<S150>/If Action Subsystem5' */
  DW_IfActionSubsystem_Hallcorr_T IfActionSubsystem4;/* '<S150>/If Action Subsystem4' */
  DW_IfActionSubsystem_Hallcorr_T IfActionSubsystem3;/* '<S150>/If Action Subsystem3' */
  DW_IfActionSubsystem_Hallcorr_T IfActionSubsystem2;/* '<S150>/If Action Subsystem2' */
  DW_IfActionSubsystem_Hallcorr_T IfActionSubsystem1;/* '<S150>/If Action Subsystem1' */
  DW_IfActionSubsystem_Hallcorr_T IfActionSubsystem;/* '<S150>/If Action Subsystem' */
  DW_IfActionSubsystem6_Hallcor_T IfActionSubsystem7;/* '<S150>/If Action Subsystem7' */
  DW_IfActionSubsystem6_Hallcor_T IfActionSubsystem6;/* '<S150>/If Action Subsystem6' */
} DW_ValidHalls_HallcorrectionF_T;

/* Block states (default storage) for system '<S148>/Bad hall (glitch or wrong connection)' */
typedef struct {
  int8_T Badhallglitchorwrongconnection_;
                            /* '<S148>/Bad hall (glitch or wrong connection)' */
} DW_Badhallglitchorwrongconnec_T;

/* Block states (default storage) for system '<S47>/Hall Value of 1' */
typedef struct {
  int8_T HallValueof1_SubsysRanBC;     /* '<S47>/Hall Value of 1' */
} DW_HallValueof1_Hallcorrectio_T;

/* Block signals (default storage) */
typedef struct {
  real_T Enable;                       /* '<S16>/Enable' */
  real_T rtb_Switch4_idx_0;
  uint32_T speedCountDelay;            /* '<S29>/speedCountDelay' */
  uint32_T Add1;                       /* '<S22>/Add1' */
  real32_T Pos;                        /* '<Root>/RT2' */
  real32_T Pos_offset;                 /* '<Root>/Rate Transition1' */
  real32_T W;                          /* '<Root>/Rate Transition2' */
  real32_T Gain1;                      /* '<S17>/Gain1' */
  real32_T Sum;                        /* '<S17>/Sum' */
  real32_T Add1_d;                     /* '<S74>/Add1' */
  real32_T Merge;                      /* '<S45>/Merge' */
  real32_T scaleOut;                   /* '<S25>/scaleOut' */
  real32_T Add1_l;                     /* '<S26>/Add1' */
  real32_T Input;                      /* '<S27>/Input' */
  uint16_T testct;                     /* '<Root>/RT3' */
  uint16_T DelayOneStep;               /* '<S30>/Delay One Step' */
  uint16_T Output;                     /* '<S9>/Output' */
  uint8_T Halls;                       /* '<Root>/Rate Transition3' */
  uint8_T DataStoreRead1;              /* '<S17>/Data Store Read1' */
  boolean_T validityDelay;             /* '<S29>/validityDelay' */
  B_ValidHalls_HallcorrectionFi_T ValidHalls_b;/* '<S98>/Valid Halls' */
  B_ValidHalls_HallcorrectionFi_T ValidHalls_n;/* '<S123>/Valid Halls' */
  B_ValidHalls_HallcorrectionFi_T ValidHalls;/* '<S148>/Valid Halls' */
} B_HallcorrectionFimal_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S13>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Ha_T obj_o;/* '<S176>/PWM Output' */
  stm32cube_blocks_PWMOutput_Ha_T obj_f;/* '<S87>/PWM Output' */
  stm32cube_blocks_TimerBlock_H_T obj_ff;/* '<S97>/Timer' */
  stm32cube_blocks_TimerBlock_H_T obj_a;/* '<S122>/Timer' */
  stm32cube_blocks_TimerBlock_H_T obj_i;/* '<S147>/Timer' */
  real_T HallCcapture;                 /* '<Root>/Data Store Memory10' */
  real_T HallBcapture;                 /* '<Root>/Data Store Memory4' */
  real_T HallAcapture;                 /* '<Root>/Data Store Memory2' */
  real_T Enable;                       /* '<Root>/Data Store Memory9' */
  int64_T Timehall;                    /* '<Root>/Data Store Memory3' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S17>/Discrete-Time Integrator' */
  real32_T Delay_DSTATE;               /* '<S64>/Delay' */
  real32_T UnitDelay_DSTATE;           /* '<S74>/Unit Delay' */
  real32_T UnitDelay_DSTATE_k;         /* '<S25>/Unit Delay' */
  real32_T Delay_DSTATE_a;             /* '<S24>/Delay' */
  uint32_T speedCountDelay_DSTATE;     /* '<S29>/speedCountDelay' */
  uint32_T Delay_DSTATE_k;             /* '<S22>/Delay' */
  uint32_T Delay_DSTATE_i;             /* '<S97>/Delay' */
  uint32_T Delay_DSTATE_m;             /* '<S122>/Delay' */
  uint32_T Delay_DSTATE_c;             /* '<S147>/Delay' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S17>/Discrete-Time Integrator' */
  uint32_T Timercntprev;               /* '<Root>/Data Store Memory1' */
  uint32_T GlobalSpeedCount;           /* '<Root>/Data Store Memory6' */
  uint32_T ADCSIC_PREV_T;              /* '<Root>/ADC SIC' */
  uint16_T DelayOneStep_DSTATE;        /* '<S30>/Delay One Step' */
  uint16_T Output_DSTATE;              /* '<S9>/Output' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory5' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory7' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory8' */
  boolean_T validityDelay_DSTATE;      /* '<S29>/validityDelay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S30>/Delay One Step1' */
  boolean_T Delay_DSTATE_h;            /* '<S26>/Delay' */
  int8_T ADCSIC_SubsysRanBC;           /* '<Root>/ADC SIC' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S17>/Discrete-Time Integrator' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S11>/Subsystem1' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S76>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S76>/If Action Subsystem' */
  int8_T FindOffset_SubsysRanBC;       /* '<S11>/Find Offset' */
  int8_T Subsystem_SubsysRanBC;        /* '<S64>/Subsystem' */
  int8_T SpeedanddirectionarenotvalidPos;
  /* '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
  int8_T SpeedanddirectionarevalidUsespe;
  /* '<S28>/Speed and direction are valid Use speed to extrapolate position' */
  int8_T Subsystem1_SubsysRanBC_e;     /* '<S32>/Subsystem1' */
  int8_T first_order_SubsysRanBC;      /* '<S45>/first_order' */
  int8_T second_order_SubsysRanBC;     /* '<S45>/second_order' */
  int8_T veDirection_SubsysRanBC;      /* '<S45>/+ve Direction' */
  int8_T veDirection_SubsysRanBC_g;    /* '<S45>/-ve Direction' */
  int8_T IfActionSubsystem1_SubsysRanB_k;/* '<S32>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_k;/* '<S32>/If Action Subsystem' */
  int8_T PosGen_SubsysRanBC;           /* '<S10>/PosGen' */
  int8_T UpCounter_SubsysRanBC;        /* '<S16>/Up Counter' */
  int8_T Accumulate_SubsysRanBC;       /* '<S25>/Accumulate' */
  int8_T Subsystem_SubsysRanBC_p;      /* '<S26>/Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S21>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_o;/* '<S21>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC_g;      /* '<S16>/Subsystem' */
  int8_T HA_SubsysRanBC;               /* '<Root>/HA' */
  int8_T HB_SubsysRanBC;               /* '<Root>/HB' */
  int8_T HC_SubsysRanBC;               /* '<Root>/HC' */
  uint8_T GlobalHallState;             /* '<Root>/Data Store Memory' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S17>/Discrete-Time Integrator' */
  boolean_T ADCSIC_RESET_ELAPS_T;      /* '<Root>/ADC SIC' */
  boolean_T FindOffset_MODE;           /* '<S11>/Find Offset' */
  boolean_T PosGen_MODE;               /* '<S10>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S16>/Up Counter' */
  DW_HallValueof1_Hallcorrectio_T HallValueof7_b;/* '<S35>/Hall Value of 7' */
  DW_HallValueof1_Hallcorrectio_T HallValueof6_b;/* '<S35>/Hall Value of 6' */
  DW_HallValueof1_Hallcorrectio_T HallValueof5_l;/* '<S35>/Hall Value of 5' */
  DW_HallValueof1_Hallcorrectio_T HallValueof4_j;/* '<S35>/Hall Value of 4' */
  DW_HallValueof1_Hallcorrectio_T HallValueof3_e;/* '<S35>/Hall Value of 3' */
  DW_HallValueof1_Hallcorrectio_T HallValueof2_b;/* '<S35>/Hall Value of 2' */
  DW_HallValueof1_Hallcorrectio_T HallValueof1_l;/* '<S35>/Hall Value of 1' */
  DW_HallValueof1_Hallcorrectio_T HallValueof7_e;/* '<S46>/Hall Value of 7' */
  DW_HallValueof1_Hallcorrectio_T HallValueof6_n;/* '<S46>/Hall Value of 6' */
  DW_HallValueof1_Hallcorrectio_T HallValueof5_b;/* '<S46>/Hall Value of 5' */
  DW_HallValueof1_Hallcorrectio_T HallValueof4_b;/* '<S46>/Hall Value of 4' */
  DW_HallValueof1_Hallcorrectio_T HallValueof3_h;/* '<S46>/Hall Value of 3' */
  DW_HallValueof1_Hallcorrectio_T HallValueof2_j;/* '<S46>/Hall Value of 2' */
  DW_HallValueof1_Hallcorrectio_T HallValueof1_j;/* '<S46>/Hall Value of 1' */
  DW_HallValueof1_Hallcorrectio_T HallValueof7;/* '<S47>/Hall Value of 7' */
  DW_HallValueof1_Hallcorrectio_T HallValueof6;/* '<S47>/Hall Value of 6' */
  DW_HallValueof1_Hallcorrectio_T HallValueof5;/* '<S47>/Hall Value of 5' */
  DW_HallValueof1_Hallcorrectio_T HallValueof4;/* '<S47>/Hall Value of 4' */
  DW_HallValueof1_Hallcorrectio_T HallValueof3;/* '<S47>/Hall Value of 3' */
  DW_HallValueof1_Hallcorrectio_T HallValueof2;/* '<S47>/Hall Value of 2' */
  DW_HallValueof1_Hallcorrectio_T HallValueof1;/* '<S47>/Hall Value of 1' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_o;
                             /* '<S98>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_HallcorrectionF_T ValidHalls_b;/* '<S98>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_d;
                            /* '<S123>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_HallcorrectionF_T ValidHalls_n;/* '<S123>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_k;
                            /* '<S148>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_HallcorrectionF_T ValidHalls;/* '<S148>/Valid Halls' */
} DW_HallcorrectionFimal_T;

/* Parameters for system: '<S150>/If Action Subsystem6' */
struct P_IfActionSubsystem6_Hallcorr_T_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S157>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S157>/Constant1'
                                        */
};

/* Parameters for system: '<S150>/If Action Subsystem' */
struct P_IfActionSubsystem_Hallcorre_T_ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S151>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S151>/next'
                                        */
};

/* Parameters for system: '<S148>/Valid Halls' */
struct P_ValidHalls_HallcorrectionFi_T_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S150>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S159>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S150>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S150>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S150>/Merge3'
                                      */
  boolean_T Constant_Value_b;          /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S150>/Constant'
                                        */
  P_IfActionSubsystem_Hallcorre_T IfActionSubsystem5;/* '<S150>/If Action Subsystem5' */
  P_IfActionSubsystem_Hallcorre_T IfActionSubsystem4;/* '<S150>/If Action Subsystem4' */
  P_IfActionSubsystem_Hallcorre_T IfActionSubsystem3;/* '<S150>/If Action Subsystem3' */
  P_IfActionSubsystem_Hallcorre_T IfActionSubsystem2;/* '<S150>/If Action Subsystem2' */
  P_IfActionSubsystem_Hallcorre_T IfActionSubsystem1;/* '<S150>/If Action Subsystem1' */
  P_IfActionSubsystem_Hallcorre_T IfActionSubsystem;/* '<S150>/If Action Subsystem' */
  P_IfActionSubsystem6_Hallcorr_T IfActionSubsystem7;/* '<S150>/If Action Subsystem7' */
  P_IfActionSubsystem6_Hallcorr_T IfActionSubsystem6;/* '<S150>/If Action Subsystem6' */
};

/* Parameters for system: '<S148>/Bad hall (glitch or wrong connection)' */
struct P_Badhallglitchorwrongconnect_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S149>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S149>/Constant1'
                                        */
};

/* Parameters for system: '<S47>/Hall Value of 1' */
struct P_HallValueof1_Hallcorrection_T_ {
  real32_T Constant_Value;             /* Expression: single(0.16667)
                                        * Referenced by: '<S57>/Constant'
                                        */
};

/* Parameters (default storage) */
struct P_HallcorrectionFimal_T_ {
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S68>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S69>/Constant'
                                      */
  uint32_T Disablehostafter42seconds_const;
                              /* Mask Parameter: Disablehostafter42seconds_const
                               * Referenced by: '<S18>/Constant'
                               */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S15>/FixPt Switch'
                                        */
  uint16_T SoftwareWatchdogTimer_maxCount;
                               /* Mask Parameter: SoftwareWatchdogTimer_maxCount
                                * Referenced by: '<S30>/Delay One Step'
                                */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant1_Value_c;            /* Expression: 100
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant1_Value_n;            /* Expression: 100
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S20>/Constant'
                                        */
  real_T EnPWM_Y0;                     /* Expression: 0
                                        * Referenced by: '<S16>/EnPWM'
                                        */
  real_T Constant_Value_f;             /* Expression: EnableSecondOrder
                                        * Referenced by: '<S45>/Constant'
                                        */
  real_T Constant1_Value_b;            /* Expression: 0.5
                                        * Referenced by: '<S81>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S81>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S17>/Discrete-Time Integrator'
                            */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Switch4_Threshold;            /* Expression: 0.5
                                        * Referenced by: '<S81>/Switch4'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S7>/Constant1'
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
  real_T DataStoreMemory9_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory9'
                                        */
  int64_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  int64_T Out1_Y0_m;                   /* Computed Parameter: Out1_Y0_m
                                        * Referenced by: '<S3>/Out1'
                                        */
  int64_T Out1_Y0_l;                   /* Computed Parameter: Out1_Y0_l
                                        * Referenced by: '<S2>/Out1'
                                        */
  int64_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
  int32_T Gain_Gain_f;                 /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S3>/Gain'
                                        */
  int32_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S23>/Constant'
                                        */
  real32_T Constant1_Value_op;         /* Computed Parameter: Constant1_Value_op
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
  real32_T Out1_Y0_b;                  /* Computed Parameter: Out1_Y0_b
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
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S49>/Constant'
                                        */
  real32_T Gain1_Gain_i;               /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S49>/Gain1'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S49>/Gain'
                                        */
  real32_T Gain_Gain_a;                /* Computed Parameter: Gain_Gain_a
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
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S31>/Constant'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S71>/a'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S71>/One'
                                        */
  real32_T FilterConstant_Value;     /* Computed Parameter: FilterConstant_Value
                                      * Referenced by: '<S71>/FilterConstant'
                                      */
  real32_T OneMinusFilterConstant_Value;
                             /* Computed Parameter: OneMinusFilterConstant_Value
                              * Referenced by: '<S71>/OneMinusFilterConstant'
                              */
  real32_T Offset_Y0;                  /* Computed Parameter: Offset_Y0
                                        * Referenced by: '<S70>/Offset'
                                        */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S71>/UseInputPort'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S71>/Switch1'
                                        */
  real32_T UnitDelay_InitialCondition_c;
                             /* Computed Parameter: UnitDelay_InitialCondition_c
                              * Referenced by: '<S74>/Unit Delay'
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
  real32_T one_by_two_Gain_c;          /* Computed Parameter: one_by_two_Gain_c
                                        * Referenced by: '<S91>/one_by_two'
                                        */
  real32_T Gain_Gain_b;                /* Computed Parameter: Gain_Gain_b
                                        * Referenced by: '<S90>/Gain'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S81>/Gain'
                                        */
  real32_T Offset_Y0_m;                /* Computed Parameter: Offset_Y0_m
                                        * Referenced by: '<S67>/Offset'
                                        */
  real32_T Posdegree_Y0;               /* Computed Parameter: Posdegree_Y0
                                        * Referenced by: '<S1>/Posdegree'
                                        */
  real32_T W_Y0;                       /* Computed Parameter: W_Y0
                                        * Referenced by: '<S1>/W'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S77>/Constant'
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
  real32_T Gain_Gain_fo;               /* Computed Parameter: Gain_Gain_fo
                                        * Referenced by: '<S17>/Gain'
                                        */
  real32_T Gain1_Gain_b;               /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real32_T PositionUnit_Gain;          /* Expression: single(360)
                                        * Referenced by: '<S28>/PositionUnit'
                                        */
  real32_T Vd_Ref_Value;               /* Computed Parameter: Vd_Ref_Value
                                        * Referenced by: '<S66>/Vd_Ref'
                                        */
  real32_T Vq_Value;                   /* Computed Parameter: Vq_Value
                                        * Referenced by: '<S66>/Vq'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S65>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S76>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S65>/indexing'
                                        */
  uint32_T Delay_InitialCondition_h;
                                 /* Computed Parameter: Delay_InitialCondition_h
                                  * Referenced by: '<S147>/Delay'
                                  */
  uint32_T Delay_InitialCondition_f;
                                 /* Computed Parameter: Delay_InitialCondition_f
                                  * Referenced by: '<S122>/Delay'
                                  */
  uint32_T Delay_InitialCondition_i;
                                 /* Computed Parameter: Delay_InitialCondition_i
                                  * Referenced by: '<S97>/Delay'
                                  */
  uint32_T Count_Y0;                   /* Computed Parameter: Count_Y0
                                        * Referenced by: '<S22>/Count'
                                        */
  uint32_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint32_T Delay_InitialCondition_a;
                                 /* Computed Parameter: Delay_InitialCondition_a
                                  * Referenced by: '<S22>/Delay'
                                  */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S21>/Count for 2 sec'
                                        */
  uint32_T SpeedConst_Value;
                          /* Expression: uint32(30*ClkFreq/(PolePairs*MinSpeed))
                           * Referenced by: '<S32>/SpeedConst'
                           */
  uint32_T speedcheck_Threshold;     /* Computed Parameter: speedcheck_Threshold
                                      * Referenced by: '<S33>/speed check'
                                      */
  uint32_T speedCountDelay_InitialConditio;
                          /* Computed Parameter: speedCountDelay_InitialConditio
                           * Referenced by: '<S29>/speedCountDelay'
                           */
  uint32_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint32_T DataStoreMemory6_InitialValue;
                            /* Computed Parameter: DataStoreMemory6_InitialValue
                             * Referenced by: '<Root>/Data Store Memory6'
                             */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S65>/offset'
                                        */
  int16_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  uint16_T Constant_Value_ds;          /* Computed Parameter: Constant_Value_ds
                                        * Referenced by: '<S145>/Constant'
                                        */
  uint16_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S120>/Constant'
                                        */
  uint16_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S95>/Constant'
                                        */
  uint16_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S15>/Constant'
                                        */
  uint16_T PositionEnable_Value;     /* Computed Parameter: PositionEnable_Value
                                      * Referenced by: '<S32>/PositionEnable'
                                      */
  uint16_T WatchDog_Value;             /* Computed Parameter: WatchDog_Value
                                        * Referenced by: '<S28>/WatchDog'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S84>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S84>/Switch'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S81>/stop'
                                        */
  uint16_T ct_Y0;                      /* Computed Parameter: ct_Y0
                                        * Referenced by: '<S1>/ct'
                                        */
  uint16_T Constant_Value_cz;          /* Computed Parameter: Constant_Value_cz
                                        * Referenced by: '<S34>/Constant'
                                        */
  uint16_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S33>/Constant'
                                        */
  uint16_T Order_Value;                /* Computed Parameter: Order_Value
                                        * Referenced by: '<S29>/Order'
                                        */
  uint16_T Switch_Threshold_o;         /* Computed Parameter: Switch_Threshold_o
                                        * Referenced by: '<S29>/Switch'
                                        */
  uint16_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S30>/Constant2'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S14>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S9>/Output'
                                   */
  uint16_T DataStoreMemory7_InitialValue;
                            /* Computed Parameter: DataStoreMemory7_InitialValue
                             * Referenced by: '<Root>/Data Store Memory7'
                             */
  uint16_T DataStoreMemory8_InitialValue;
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  boolean_T Delay_InitialCondition_k;
                                 /* Computed Parameter: Delay_InitialCondition_k
                                  * Referenced by: '<S26>/Delay'
                                  */
  boolean_T Constant_Value_cs;         /* Computed Parameter: Constant_Value_cs
                                        * Referenced by: '<S26>/Constant'
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
  uint8_T Gain_Gain_bp;                /* Computed Parameter: Gain_Gain_bp
                                        * Referenced by: '<S146>/Gain'
                                        */
  uint8_T Gain_Gain_px;                /* Computed Parameter: Gain_Gain_px
                                        * Referenced by: '<S121>/Gain'
                                        */
  uint8_T Gain_Gain_g;                 /* Computed Parameter: Gain_Gain_g
                                        * Referenced by: '<S96>/Gain'
                                        */
  uint8_T Gain1_Gain_o;                /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S146>/Gain1'
                                        */
  uint8_T Gain1_Gain_l;                /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S121>/Gain1'
                                        */
  uint8_T Gain1_Gain_h;                /* Computed Parameter: Gain1_Gain_h
                                        * Referenced by: '<S96>/Gain1'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S146>/Gain2'
                                        */
  uint8_T Gain2_Gain_p;                /* Computed Parameter: Gain2_Gain_p
                                        * Referenced by: '<S121>/Gain2'
                                        */
  uint8_T Gain2_Gain_j;                /* Computed Parameter: Gain2_Gain_j
                                        * Referenced by: '<S96>/Gain2'
                                        */
  uint8_T Halls_Y0;                    /* Computed Parameter: Halls_Y0
                                        * Referenced by: '<S1>/Halls'
                                        */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  P_HallValueof1_Hallcorrection_T HallValueof7_b;/* '<S35>/Hall Value of 7' */
  P_HallValueof1_Hallcorrection_T HallValueof6_b;/* '<S35>/Hall Value of 6' */
  P_HallValueof1_Hallcorrection_T HallValueof5_l;/* '<S35>/Hall Value of 5' */
  P_HallValueof1_Hallcorrection_T HallValueof4_j;/* '<S35>/Hall Value of 4' */
  P_HallValueof1_Hallcorrection_T HallValueof3_e;/* '<S35>/Hall Value of 3' */
  P_HallValueof1_Hallcorrection_T HallValueof2_b;/* '<S35>/Hall Value of 2' */
  P_HallValueof1_Hallcorrection_T HallValueof1_l;/* '<S35>/Hall Value of 1' */
  P_HallValueof1_Hallcorrection_T HallValueof7_e;/* '<S46>/Hall Value of 7' */
  P_HallValueof1_Hallcorrection_T HallValueof6_n;/* '<S46>/Hall Value of 6' */
  P_HallValueof1_Hallcorrection_T HallValueof5_b;/* '<S46>/Hall Value of 5' */
  P_HallValueof1_Hallcorrection_T HallValueof4_b;/* '<S46>/Hall Value of 4' */
  P_HallValueof1_Hallcorrection_T HallValueof3_h;/* '<S46>/Hall Value of 3' */
  P_HallValueof1_Hallcorrection_T HallValueof2_j;/* '<S46>/Hall Value of 2' */
  P_HallValueof1_Hallcorrection_T HallValueof1_j;/* '<S46>/Hall Value of 1' */
  P_HallValueof1_Hallcorrection_T HallValueof7;/* '<S47>/Hall Value of 7' */
  P_HallValueof1_Hallcorrection_T HallValueof6;/* '<S47>/Hall Value of 6' */
  P_HallValueof1_Hallcorrection_T HallValueof5;/* '<S47>/Hall Value of 5' */
  P_HallValueof1_Hallcorrection_T HallValueof4;/* '<S47>/Hall Value of 4' */
  P_HallValueof1_Hallcorrection_T HallValueof3;/* '<S47>/Hall Value of 3' */
  P_HallValueof1_Hallcorrection_T HallValueof2;/* '<S47>/Hall Value of 2' */
  P_HallValueof1_Hallcorrection_T HallValueof1;/* '<S47>/Hall Value of 1' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_o;
                             /* '<S98>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_HallcorrectionFi_T ValidHalls_b;/* '<S98>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_d;
                            /* '<S123>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_HallcorrectionFi_T ValidHalls_n;/* '<S123>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_k;
                            /* '<S148>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_HallcorrectionFi_T ValidHalls;/* '<S148>/Valid Halls' */
};

/* Real-time Model Data Structure */
struct tag_RTM_HallcorrectionFimal_T {
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
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_HallcorrectionFimal_T HallcorrectionFimal_P;

/* Block signals (default storage) */
extern B_HallcorrectionFimal_T HallcorrectionFimal_B;

/* Block states (default storage) */
extern DW_HallcorrectionFimal_T HallcorrectionFimal_DW;

/* Model entry point functions */
extern void HallcorrectionFimal_initialize(void);
extern void HallcorrectionFimal_step(void);
extern void HallcorrectionFimal_terminate(void);

/* Real-time Model object */
extern RT_MODEL_HallcorrectionFimal_T *const HallcorrectionFimal_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC_IRQHandler(void);
  void EXTI9_5_IRQHandler(void);
  void HallcorrectionFimal_configure_interrupts (void);
  void HallcorrectionFimal_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S9>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S19>/Compare' : Unused code path elimination
 * Block '<S19>/Constant' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Duplicate' : Unused code path elimination
 * Block '<S65>/Data Type Propagation' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate' : Unused code path elimination
 * Block '<S83>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Vc' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S7>/Data Type' : Unused code path elimination
 * Block '<S7>/Number of pole pairs' : Unused code path elimination
 * Block '<S7>/PWM Frequency' : Unused code path elimination
 * Block '<S28>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S28>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S28>/counterSize2' : Eliminate redundant data type conversion
 * Block '<S65>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S95>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S120>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S145>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<Root>' : 'HallcorrectionFimal'
 * '<S1>'   : 'HallcorrectionFimal/ADC SIC'
 * '<S2>'   : 'HallcorrectionFimal/HA'
 * '<S3>'   : 'HallcorrectionFimal/HB'
 * '<S4>'   : 'HallcorrectionFimal/HC'
 * '<S5>'   : 'HallcorrectionFimal/Hardware Interrupt'
 * '<S6>'   : 'HallcorrectionFimal/Hardware Interrupt2'
 * '<S7>'   : 'HallcorrectionFimal/Parameters'
 * '<S8>'   : 'HallcorrectionFimal/ADC SIC/Analog to Digital Converter'
 * '<S9>'   : 'HallcorrectionFimal/ADC SIC/Counter Limited1'
 * '<S10>'  : 'HallcorrectionFimal/ADC SIC/Subsystem'
 * '<S11>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2'
 * '<S12>'  : 'HallcorrectionFimal/ADC SIC/Analog to Digital Converter/ECSoC'
 * '<S13>'  : 'HallcorrectionFimal/ADC SIC/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S14>'  : 'HallcorrectionFimal/ADC SIC/Counter Limited1/Increment Real World'
 * '<S15>'  : 'HallcorrectionFimal/ADC SIC/Counter Limited1/Wrap To Zero'
 * '<S16>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen'
 * '<S17>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1'
 * '<S18>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Disable host after 42 seconds'
 * '<S19>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Enable PWM for 40 seconds'
 * '<S20>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Subsystem'
 * '<S21>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Subsystem1'
 * '<S22>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Up Counter'
 * '<S23>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Subsystem1/If Action Subsystem'
 * '<S24>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Subsystem1/If Action Subsystem2'
 * '<S25>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator'
 * '<S26>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S27>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S28>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1'
 * '<S29>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/ExtrapolationOrder'
 * '<S30>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Software Watchdog Timer'
 * '<S31>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S32>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position'
 * '<S33>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/VaidityCheck'
 * '<S34>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Software Watchdog Timer/Compare To Zero'
 * '<S35>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S36>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S37>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S38>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S39>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S40>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S41>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S42>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S43>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S44>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S45>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S46>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S47>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S48>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S49>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S50>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S51>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S52>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S53>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S54>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S55>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S56>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S57>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S58>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S59>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S60>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S61>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S62>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S63>'  : 'HallcorrectionFimal/ADC SIC/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S64>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Find Offset'
 * '<S65>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Sine-Cosine Lookup'
 * '<S66>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem'
 * '<S67>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem1'
 * '<S68>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Find Offset/Compare To Constant'
 * '<S69>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Find Offset/Compare To Constant1'
 * '<S70>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Find Offset/Subsystem'
 * '<S71>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Find Offset/Subsystem/IIR Filter'
 * '<S72>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S73>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S74>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S75>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Sine-Cosine Lookup/Interpolation'
 * '<S76>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Sine-Cosine Lookup/WrapUp'
 * '<S77>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S78>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S79>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S80>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/Inverse Park Transform'
 * '<S81>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM'
 * '<S82>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM Reference Generator'
 * '<S83>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/Inverse Park Transform/Two inputs CRL'
 * '<S84>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S85>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM/PWM Output'
 * '<S86>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM/PWM Output/ECSoC'
 * '<S87>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM/PWM Output/ECSoC/ECSimCodegen'
 * '<S88>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM Reference Generator/Modulation method'
 * '<S89>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM Reference Generator/Voltage Input'
 * '<S90>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM Reference Generator/Modulation method/SVPWM'
 * '<S91>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S92>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S93>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S94>'  : 'HallcorrectionFimal/ADC SIC/Subsystem2/Subsystem/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S95>'  : 'HallcorrectionFimal/HA/Hall Validity'
 * '<S96>'  : 'HallcorrectionFimal/HA/Hallstation'
 * '<S97>'  : 'HallcorrectionFimal/HA/Subsystem'
 * '<S98>'  : 'HallcorrectionFimal/HA/Hall Validity/Subsystem'
 * '<S99>'  : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S100>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls'
 * '<S101>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S102>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S103>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S104>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S105>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S106>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S107>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S108>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S109>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S110>' : 'HallcorrectionFimal/HA/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S111>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read'
 * '<S112>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read1'
 * '<S113>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read2'
 * '<S114>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read/ECSoC'
 * '<S115>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S116>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read1/ECSoC'
 * '<S117>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S118>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read2/ECSoC'
 * '<S119>' : 'HallcorrectionFimal/HA/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S120>' : 'HallcorrectionFimal/HB/Hall Validity'
 * '<S121>' : 'HallcorrectionFimal/HB/Hallstation'
 * '<S122>' : 'HallcorrectionFimal/HB/Subsystem'
 * '<S123>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem'
 * '<S124>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S125>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls'
 * '<S126>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S127>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S128>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S129>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S130>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S131>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S132>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S133>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S134>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S135>' : 'HallcorrectionFimal/HB/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S136>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read'
 * '<S137>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read1'
 * '<S138>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read2'
 * '<S139>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read/ECSoC'
 * '<S140>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S141>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read1/ECSoC'
 * '<S142>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S143>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read2/ECSoC'
 * '<S144>' : 'HallcorrectionFimal/HB/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S145>' : 'HallcorrectionFimal/HC/Hall Validity'
 * '<S146>' : 'HallcorrectionFimal/HC/Hallstation'
 * '<S147>' : 'HallcorrectionFimal/HC/Subsystem'
 * '<S148>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem'
 * '<S149>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S150>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls'
 * '<S151>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S152>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S153>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S154>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S155>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S156>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S157>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S158>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S159>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S160>' : 'HallcorrectionFimal/HC/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S161>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read'
 * '<S162>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read1'
 * '<S163>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read2'
 * '<S164>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read/ECSoC'
 * '<S165>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S166>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read1/ECSoC'
 * '<S167>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S168>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read2/ECSoC'
 * '<S169>' : 'HallcorrectionFimal/HC/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S170>' : 'HallcorrectionFimal/Hardware Interrupt/ECSoC'
 * '<S171>' : 'HallcorrectionFimal/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S172>' : 'HallcorrectionFimal/Hardware Interrupt2/ECSoC'
 * '<S173>' : 'HallcorrectionFimal/Hardware Interrupt2/ECSoC/ECSimCodegen'
 * '<S174>' : 'HallcorrectionFimal/Parameters/PWM Output'
 * '<S175>' : 'HallcorrectionFimal/Parameters/PWM Output/ECSoC'
 * '<S176>' : 'HallcorrectionFimal/Parameters/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* HallcorrectionFimal_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
