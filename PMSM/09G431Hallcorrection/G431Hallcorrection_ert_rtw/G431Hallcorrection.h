/*
 * File: G431Hallcorrection.h
 *
 * Code generated for Simulink model 'G431Hallcorrection'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Oct 24 14:38:06 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef G431Hallcorrection_h_
#define G431Hallcorrection_h_
#ifndef G431Hallcorrection_COMMON_INCLUDES_
#define G431Hallcorrection_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#endif                                 /* G431Hallcorrection_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "G431Hallcorrection_types.h"
#include "zero_crossing_types.h"
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

/* Block states (default storage) for system '<S49>/Hall Value of 1' */
typedef struct {
  int8_T HallValueof1_SubsysRanBC;     /* '<S49>/Hall Value of 1' */
} DW_HallValueof1_G431Hallcorre_T;

/* Block states (default storage) for system '<S79>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S79>/If Action Subsystem' */
} DW_IfActionSubsystem_G431Hall_T;

/* Block states (default storage) for system '<S79>/If Action Subsystem1' */
typedef struct {
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S79>/If Action Subsystem1' */
} DW_IfActionSubsystem1_G431Hal_T;

/* Block states (default storage) for system '<S146>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S146>/If Action Subsystem6' */
} DW_IfActionSubsystem6_G431Hal_T;

/* Block states (default storage) for system '<S146>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S146>/If Action Subsystem' */
} DW_IfActionSubsystem_G431Ha_b_T;

/* Block signals for system '<S144>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S146>/Merge' */
  uint16_T Merge1;                     /* '<S146>/Merge1' */
  uint16_T Merge3;                     /* '<S146>/Merge3' */
  int16_T Merge2;                      /* '<S146>/Merge2' */
} B_ValidHalls_G431Hallcorrecti_T;

/* Block states (default storage) for system '<S144>/Valid Halls' */
typedef struct {
  int8_T ValidHalls_SubsysRanBC;       /* '<S144>/Valid Halls' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                     /* '<S146>/Switch Case Action Subsystem' */
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S146>/If Action Subsystem8' */
  DW_IfActionSubsystem_G431Ha_b_T IfActionSubsystem5;/* '<S146>/If Action Subsystem5' */
  DW_IfActionSubsystem_G431Ha_b_T IfActionSubsystem4;/* '<S146>/If Action Subsystem4' */
  DW_IfActionSubsystem_G431Ha_b_T IfActionSubsystem3;/* '<S146>/If Action Subsystem3' */
  DW_IfActionSubsystem_G431Ha_b_T IfActionSubsystem2;/* '<S146>/If Action Subsystem2' */
  DW_IfActionSubsystem_G431Ha_b_T IfActionSubsystem1;/* '<S146>/If Action Subsystem1' */
  DW_IfActionSubsystem_G431Ha_b_T IfActionSubsystem;/* '<S146>/If Action Subsystem' */
  DW_IfActionSubsystem6_G431Hal_T IfActionSubsystem7;/* '<S146>/If Action Subsystem7' */
  DW_IfActionSubsystem6_G431Hal_T IfActionSubsystem6;/* '<S146>/If Action Subsystem6' */
} DW_ValidHalls_G431Hallcorrect_T;

/* Block states (default storage) for system '<S144>/Bad hall (glitch or wrong connection)' */
typedef struct {
  int8_T Badhallglitchorwrongconnection_;
                            /* '<S144>/Bad hall (glitch or wrong connection)' */
} DW_Badhallglitchorwrongconnec_T;

/* Block signals (default storage) */
typedef struct {
  real_T Merge;                        /* '<S192>/Merge' */
  real_T Input;                        /* '<S304>/Input' */
  real_T rtb_Switch4_idx_0;
  real_T Add_n;                        /* '<S303>/Add' */
  uint32_T Add1_c;                     /* '<S24>/Add1' */
  uint32_T HallCt;                     /* '<Root>/Rate Transition1' */
  real32_T Intedegree;                 /* '<Root>/Rate Transition5' */
  real32_T Pswfilter;                  /* '<Root>/Rate Transition6' */
  real32_T Sum;                        /* '<S19>/Sum' */
  real32_T Gain;                       /* '<S98>/Gain' */
  real32_T Merge_h;                    /* '<S47>/Merge' */
  real32_T scaleOut;                   /* '<S27>/scaleOut' */
  real32_T Add1_j;                     /* '<S28>/Add1' */
  real32_T Input_m;                    /* '<S29>/Input' */
  uint16_T speedCountDelay;            /* '<S31>/speedCountDelay' */
  uint16_T DelayOneStep;               /* '<S32>/Delay One Step' */
  uint8_T Halls;                       /* '<Root>/Rate Transition2' */
  boolean_T validityDelay;             /* '<S31>/validityDelay' */
  boolean_T Compare;                   /* '<S21>/Compare' */
  B_ValidHalls_G431Hallcorrecti_T ValidHalls_b;/* '<S169>/Valid Halls' */
  B_ValidHalls_G431Hallcorrecti_T ValidHalls_p;/* '<S119>/Valid Halls' */
  B_ValidHalls_G431Hallcorrecti_T ValidHalls;/* '<S144>/Valid Halls' */
} B_G431Hallcorrection_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S15>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_G4_T obj_i;/* '<S85>/PWM Output' */
  stm32cube_blocks_TimerCapture_T obj_e;/* '<S4>/Timer Capture' */
  stm32cube_blocks_TimerCapture_T obj_a;/* '<S2>/Timer Capture' */
  stm32cube_blocks_TimerCapture_T obj_h;/* '<S3>/Timer Capture' */
  real_T Delay_DSTATE;                 /* '<S300>/Delay' */
  real_T Integrator_DSTATE;            /* '<S233>/Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S276>/Unit Delay' */
  real_T UnitDelay_DSTATE_d;           /* '<S301>/Unit Delay' */
  real_T Delay2_DSTATE;                /* '<S287>/Delay2' */
  real_T Delay3_DSTATE;                /* '<S287>/Delay3' */
  real_T UnitDelay_DSTATE_m;           /* '<S296>/Unit Delay' */
  real_T Delay2_DSTATE_b;              /* '<S288>/Delay2' */
  real_T Delay3_DSTATE_f;              /* '<S288>/Delay3' */
  real_T UnitDelay_DSTATE_b;           /* '<S293>/Unit Delay' */
  real_T UnitDelay_DSTATE_h;           /* '<S286>/Unit Delay' */
  real_T Delay1_DSTATE;                /* '<S279>/Delay1' */
  real_T Delay_DSTATE_g;               /* '<S279>/Delay' */
  real_T UnitDelay_DSTATE_he;          /* '<S283>/Unit Delay' */
  real_T Delay1_DSTATE_i;              /* '<S280>/Delay1' */
  real_T Delay_DSTATE_a;               /* '<S280>/Delay' */
  real_T Delay2_DSTATE_o;              /* '<S254>/Delay2' */
  real_T Delay3_DSTATE_m;              /* '<S254>/Delay3' */
  real_T UnitDelay_DSTATE_n;           /* '<S268>/Unit Delay' */
  real_T Delay2_DSTATE_l;              /* '<S255>/Delay2' */
  real_T Delay3_DSTATE_g;              /* '<S255>/Delay3' */
  real_T UnitDelay_DSTATE_dz;          /* '<S262>/Unit Delay' */
  real_T Delay_DSTATE_f;               /* '<S259>/Delay' */
  real_T Delay1_DSTATE_e;              /* '<S259>/Delay1' */
  real_T UnitDelay_DSTATE_o;           /* '<S265>/Unit Delay' */
  real_T HallCcapture;                 /* '<Root>/Data Store Memory10' */
  real_T HallAcapture;                 /* '<Root>/Data Store Memory2' */
  real_T HallBcapture;                 /* '<Root>/Data Store Memory4' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S19>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_k;         /* '<S106>/Unit Delay' */
  real32_T UnitDelay_DSTATE_hs;        /* '<S103>/Unit Delay' */
  real32_T Delay_DSTATE_ge;            /* '<S98>/Delay' */
  real32_T Delay1_DSTATE_m[2];         /* '<S98>/Delay1' */
  real32_T Delay2_DSTATE_c[3];         /* '<S98>/Delay2' */
  real32_T Delay3_DSTATE_c[3];         /* '<S98>/Delay3' */
  real32_T Delay4_DSTATE[5];           /* '<S98>/Delay4' */
  real32_T Delay_DSTATE_d;             /* '<S66>/Delay' */
  real32_T UnitDelay_DSTATE_f;         /* '<S77>/Unit Delay' */
  real32_T UnitDelay_DSTATE_i;         /* '<S27>/Unit Delay' */
  real32_T Delay_DSTATE_gq;            /* '<S26>/Delay' */
  uint32_T Delay_DSTATE_h;             /* '<S24>/Delay' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S19>/Discrete-Time Integrator' */
  int32_T clockTickCounter;            /* '<S7>/Pulse Generator' */
  uint32_T FunctionCallSubsystem_PREV_T;/* '<Root>/Function-Call Subsystem' */
  uint32_T Timehall;                   /* '<Root>/Data Store Memory3' */
  uint16_T speedCountDelay_DSTATE;     /* '<S31>/speedCountDelay' */
  uint16_T DelayOneStep_DSTATE;        /* '<S32>/Delay One Step' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory5' */
  int16_T Timercntprev;                /* '<Root>/Data Store Memory1' */
  uint16_T GlobalSpeedCount;           /* '<Root>/Data Store Memory6' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory7' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory8' */
  boolean_T Delay_DSTATE_hn;           /* '<S303>/Delay' */
  boolean_T UnitDelay_DSTATE_ov;       /* '<S259>/Unit Delay' */
  boolean_T validityDelay_DSTATE;      /* '<S31>/validityDelay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S32>/Delay One Step1' */
  boolean_T Delay_DSTATE_p;            /* '<S28>/Delay' */
  int8_T Integrator_PrevResetState;    /* '<S233>/Integrator' */
  int8_T Accumulate_SubsysRanBC;       /* '<S301>/Accumulate' */
  int8_T Subsystem_SubsysRanBC;        /* '<S303>/Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S193>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S193>/If Action Subsystem' */
  int8_T OptimizedDifferentiationMethod_;
                                   /* '<S192>/OptimizedDifferentiationMethod' */
  int8_T IntegralMethod_SubsysRanBC;   /* '<S192>/IntegralMethod' */
  int8_T DifferentiationMethod_SubsysRan;/* '<S192>/DifferentiationMethod' */
  int8_T IfActionSubsystem_SubsysRanBC_h;/* '<S190>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC_a;      /* '<S190>/Subsystem' */
  int8_T HALL_C_SubsysRanBC;           /* '<Root>/HALL_C' */
  int8_T HALL_A_SubsysRanBC;           /* '<Root>/HALL_A' */
  int8_T HALL_B_SubsysRanBC;           /* '<Root>/HALL_B' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S19>/Discrete-Time Integrator' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S13>/Enabled Subsystem' */
  int8_T Subsystem1_SubsysRanBC;       /* '<S12>/Subsystem1' */
  int8_T FindOffset_SubsysRanBC;       /* '<S12>/Find Offset' */
  int8_T Subsystem_SubsysRanBC_b;      /* '<S66>/Subsystem' */
  int8_T SpeedanddirectionarenotvalidPos;
  /* '<S30>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
  int8_T SpeedanddirectionarevalidUsespe;
  /* '<S30>/Speed and direction are valid Use speed to extrapolate position' */
  int8_T Subsystem1_SubsysRanBC_m;     /* '<S34>/Subsystem1' */
  int8_T first_order_SubsysRanBC;      /* '<S47>/first_order' */
  int8_T second_order_SubsysRanBC;     /* '<S47>/second_order' */
  int8_T veDirection_SubsysRanBC;      /* '<S47>/+ve Direction' */
  int8_T veDirection_SubsysRanBC_h;    /* '<S47>/-ve Direction' */
  int8_T IfActionSubsystem1_SubsysRanB_p;/* '<S34>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC_k;/* '<S34>/If Action Subsystem' */
  int8_T PosGen_SubsysRanBC;           /* '<S11>/PosGen' */
  int8_T UpCounter_SubsysRanBC;        /* '<S18>/Up Counter' */
  int8_T Accumulate_SubsysRanBC_a;     /* '<S27>/Accumulate' */
  int8_T Subsystem_SubsysRanBC_o;      /* '<S28>/Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S23>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_n;/* '<S23>/If Action Subsystem' */
  int8_T Subsystem_SubsysRanBC_m;      /* '<S18>/Subsystem' */
  uint8_T GlobalHallState;             /* '<Root>/Data Store Memory' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S19>/Discrete-Time Integrator' */
  boolean_T FunctionCallSubsystem_RESET_ELA;/* '<Root>/Function-Call Subsystem' */
  boolean_T FindOffset_MODE;           /* '<S12>/Find Offset' */
  boolean_T PosGen_MODE;               /* '<S11>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S18>/Up Counter' */
  DW_IfActionSubsystem1_G431Hal_T IfActionSubsystem1_k;/* '<S306>/If Action Subsystem1' */
  DW_IfActionSubsystem_G431Hall_T IfActionSubsystem_m;/* '<S306>/If Action Subsystem' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_n;
                            /* '<S169>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431Hallcorrect_T ValidHalls_b;/* '<S169>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_f;
                            /* '<S119>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431Hallcorrect_T ValidHalls_p;/* '<S119>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnection;
                            /* '<S144>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_G431Hallcorrect_T ValidHalls;/* '<S144>/Valid Halls' */
  DW_IfActionSubsystem1_G431Hal_T IfActionSubsystem1_f;/* '<S79>/If Action Subsystem1' */
  DW_IfActionSubsystem_G431Hall_T IfActionSubsystem_a;/* '<S79>/If Action Subsystem' */
  DW_HallValueof1_G431Hallcorre_T HallValueof7_e;/* '<S37>/Hall Value of 7' */
  DW_HallValueof1_G431Hallcorre_T HallValueof6_m;/* '<S37>/Hall Value of 6' */
  DW_HallValueof1_G431Hallcorre_T HallValueof5_j;/* '<S37>/Hall Value of 5' */
  DW_HallValueof1_G431Hallcorre_T HallValueof4_e;/* '<S37>/Hall Value of 4' */
  DW_HallValueof1_G431Hallcorre_T HallValueof3_b;/* '<S37>/Hall Value of 3' */
  DW_HallValueof1_G431Hallcorre_T HallValueof2_o;/* '<S37>/Hall Value of 2' */
  DW_HallValueof1_G431Hallcorre_T HallValueof1_e;/* '<S37>/Hall Value of 1' */
  DW_HallValueof1_G431Hallcorre_T HallValueof7_b;/* '<S48>/Hall Value of 7' */
  DW_HallValueof1_G431Hallcorre_T HallValueof6_g;/* '<S48>/Hall Value of 6' */
  DW_HallValueof1_G431Hallcorre_T HallValueof5_o;/* '<S48>/Hall Value of 5' */
  DW_HallValueof1_G431Hallcorre_T HallValueof4_l;/* '<S48>/Hall Value of 4' */
  DW_HallValueof1_G431Hallcorre_T HallValueof3_p;/* '<S48>/Hall Value of 3' */
  DW_HallValueof1_G431Hallcorre_T HallValueof2_p;/* '<S48>/Hall Value of 2' */
  DW_HallValueof1_G431Hallcorre_T HallValueof1_b;/* '<S48>/Hall Value of 1' */
  DW_HallValueof1_G431Hallcorre_T HallValueof7;/* '<S49>/Hall Value of 7' */
  DW_HallValueof1_G431Hallcorre_T HallValueof6;/* '<S49>/Hall Value of 6' */
  DW_HallValueof1_G431Hallcorre_T HallValueof5;/* '<S49>/Hall Value of 5' */
  DW_HallValueof1_G431Hallcorre_T HallValueof4;/* '<S49>/Hall Value of 4' */
  DW_HallValueof1_G431Hallcorre_T HallValueof3;/* '<S49>/Hall Value of 3' */
  DW_HallValueof1_G431Hallcorre_T HallValueof2;/* '<S49>/Hall Value of 2' */
  DW_HallValueof1_G431Hallcorre_T HallValueof1;/* '<S49>/Hall Value of 1' */
} DW_G431Hallcorrection_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S300>/Delay' */
  ZCSigState Delay2_Reset_ZCE;         /* '<S287>/Delay2' */
  ZCSigState Delay3_Reset_ZCE;         /* '<S287>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_m;       /* '<S288>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_b;       /* '<S288>/Delay3' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S279>/Delay1' */
  ZCSigState Delay_Reset_ZCE_k;        /* '<S279>/Delay' */
  ZCSigState Delay1_Reset_ZCE_e;       /* '<S280>/Delay1' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S280>/Delay' */
  ZCSigState Delay2_Reset_ZCE_k;       /* '<S254>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_o;       /* '<S254>/Delay3' */
  ZCSigState Delay2_Reset_ZCE_g;       /* '<S255>/Delay2' */
  ZCSigState Delay3_Reset_ZCE_k;       /* '<S255>/Delay3' */
} PrevZCX_G431Hallcorrection_T;

/* Parameters for system: '<S49>/Hall Value of 1' */
struct P_HallValueof1_G431Hallcorrec_T_ {
  real32_T Constant_Value;             /* Expression: single(0.16667)
                                        * Referenced by: '<S59>/Constant'
                                        */
};

/* Parameters for system: '<S146>/If Action Subsystem6' */
struct P_IfActionSubsystem6_G431Hall_T_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S153>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S153>/Constant1'
                                        */
};

/* Parameters for system: '<S146>/If Action Subsystem' */
struct P_IfActionSubsystem_G431Hal_g_T_ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S147>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S147>/next'
                                        */
};

/* Parameters for system: '<S144>/Valid Halls' */
struct P_ValidHalls_G431Hallcorrecti_T_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S146>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S155>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S146>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S146>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S146>/Merge3'
                                      */
  boolean_T Constant_Value_k;          /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S146>/Constant'
                                        */
  P_IfActionSubsystem_G431Hal_g_T IfActionSubsystem5;/* '<S146>/If Action Subsystem5' */
  P_IfActionSubsystem_G431Hal_g_T IfActionSubsystem4;/* '<S146>/If Action Subsystem4' */
  P_IfActionSubsystem_G431Hal_g_T IfActionSubsystem3;/* '<S146>/If Action Subsystem3' */
  P_IfActionSubsystem_G431Hal_g_T IfActionSubsystem2;/* '<S146>/If Action Subsystem2' */
  P_IfActionSubsystem_G431Hal_g_T IfActionSubsystem1;/* '<S146>/If Action Subsystem1' */
  P_IfActionSubsystem_G431Hal_g_T IfActionSubsystem;/* '<S146>/If Action Subsystem' */
  P_IfActionSubsystem6_G431Hall_T IfActionSubsystem7;/* '<S146>/If Action Subsystem7' */
  P_IfActionSubsystem6_G431Hall_T IfActionSubsystem6;/* '<S146>/If Action Subsystem6' */
};

/* Parameters for system: '<S144>/Bad hall (glitch or wrong connection)' */
struct P_Badhallglitchorwrongconnect_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S145>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S145>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_G431Hallcorrection_T_ {
  real_T PLLwithFeedForward_BlkSampleTim;
                              /* Mask Parameter: PLLwithFeedForward_BlkSampleTim
                               * Referenced by:
                               *   '<S230>/Integral Gain'
                               *   '<S254>/Gain1'
                               *   '<S255>/Gain1'
                               *   '<S279>/Gain1'
                               *   '<S279>/Gain2'
                               *   '<S280>/Gain1'
                               *   '<S280>/Gain2'
                               *   '<S287>/Gain1'
                               *   '<S288>/Gain1'
                               *   '<S300>/Gain'
                               */
  real_T PLLwithFeedForward_FreqRatio;
                                 /* Mask Parameter: PLLwithFeedForward_FreqRatio
                                  * Referenced by: '<S300>/Gain'
                                  */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S233>/Integrator'
                               */
  real_T PLLwithFeedForward_Ki;        /* Mask Parameter: PLLwithFeedForward_Ki
                                        * Referenced by: '<S230>/Integral Gain'
                                        */
  real_T PLLwithFeedForward_Kp;        /* Mask Parameter: PLLwithFeedForward_Kp
                                        * Referenced by: '<S238>/Proportional Gain'
                                        */
  real_T PLLwithFeedForward_MaximumAppli;
                              /* Mask Parameter: PLLwithFeedForward_MaximumAppli
                               * Referenced by:
                               *   '<S252>/Switch1'
                               *   '<S254>/Gain'
                               *   '<S254>/Gain1'
                               *   '<S255>/Gain'
                               *   '<S255>/Gain1'
                               *   '<S279>/Gain1'
                               *   '<S279>/Gain2'
                               *   '<S280>/Gain1'
                               *   '<S280>/Gain2'
                               *   '<S287>/Gain'
                               *   '<S287>/Gain1'
                               *   '<S288>/Gain'
                               *   '<S288>/Gain1'
                               */
  real_T CompareToConstant2_const;   /* Mask Parameter: CompareToConstant2_const
                                      * Referenced by: '<S271>/Constant'
                                      */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S270>/Constant'
                                      */
  real_T CompareToConstant4_const;   /* Mask Parameter: CompareToConstant4_const
                                      * Referenced by: '<S272>/Constant'
                                      */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S269>/Constant'
                                       */
  real_T CompareToConstant5_const;   /* Mask Parameter: CompareToConstant5_const
                                      * Referenced by: '<S273>/Constant'
                                      */
  real32_T CompareToConstant_const_o;
                                    /* Mask Parameter: CompareToConstant_const_o
                                     * Referenced by: '<S71>/Constant'
                                     */
  real32_T CompareToConstant1_const_d;
                                   /* Mask Parameter: CompareToConstant1_const_d
                                    * Referenced by: '<S72>/Constant'
                                    */
  real32_T Comparespeedlowthan20RPM_const;
                               /* Mask Parameter: Comparespeedlowthan20RPM_const
                                * Referenced by: '<S97>/Constant'
                                */
  uint32_T SpeedFeedforward_SpeedCompMetho;
                              /* Mask Parameter: SpeedFeedforward_SpeedCompMetho
                               * Referenced by: '<S192>/Constant'
                               */
  uint32_T Disablehostafter42seconds_const;
                              /* Mask Parameter: Disablehostafter42seconds_const
                               * Referenced by: '<S20>/Constant'
                               */
  uint32_T EnablePWMfor40seconds_const;
                                  /* Mask Parameter: EnablePWMfor40seconds_const
                                   * Referenced by: '<S21>/Constant'
                                   */
  uint16_T SoftwareWatchdogTimer_maxCount;
                               /* Mask Parameter: SoftwareWatchdogTimer_maxCount
                                * Referenced by: '<S32>/Delay One Step'
                                */
  real_T Constant_Value;               /* Expression: EnableSecondOrder
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 0.5
                                        * Referenced by: '<S68>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S68>/Gain1'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S19>/Discrete-Time Integrator'
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
  real_T a_Value;                      /* Expression: 0
                                        * Referenced by: '<S251>/a'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S251>/One'
                                        */
  real_T FilterConstant_Value;         /* Expression: Filter_constant
                                        * Referenced by: '<S251>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value; /* Expression: 1 - Filter_constant
                                        * Referenced by: '<S251>/OneMinusFilterConstant'
                                        */
  real_T a_Value_c;                    /* Expression: 0
                                        * Referenced by: '<S256>/a'
                                        */
  real_T One_Value_l;                  /* Expression: 1
                                        * Referenced by: '<S256>/One'
                                        */
  real_T FilterConstant_Value_o;       /* Expression: Filter_constant
                                        * Referenced by: '<S256>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value_a;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S256>/OneMinusFilterConstant'
                                         */
  real_T a_Value_i;                    /* Expression: 0
                                        * Referenced by: '<S257>/a'
                                        */
  real_T One_Value_i;                  /* Expression: 1
                                        * Referenced by: '<S257>/One'
                                        */
  real_T FilterConstant_Value_e;       /* Expression: Filter_constant
                                        * Referenced by: '<S257>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value_h;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S257>/OneMinusFilterConstant'
                                         */
  real_T a_Value_j;                    /* Expression: 0
                                        * Referenced by: '<S258>/a'
                                        */
  real_T One_Value_a;                  /* Expression: 1
                                        * Referenced by: '<S258>/One'
                                        */
  real_T FilterConstant_Value_d;       /* Expression: Filter_constant
                                        * Referenced by: '<S258>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value_l;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S258>/OneMinusFilterConstant'
                                         */
  real_T Constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S259>/Constant'
                                        */
  real_T Constant1_Value_e;            /* Expression: -1
                                        * Referenced by: '<S259>/Constant1'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S254>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S254>/Delay3'
                                        */
  real_T UseInputPort_Value;           /* Expression: FilterConstantInputType
                                        * Referenced by: '<S258>/UseInputPort'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S258>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S268>/Unit Delay'
                                        */
  real_T Delay2_InitialCondition_b;    /* Expression: 0.0
                                        * Referenced by: '<S255>/Delay2'
                                        */
  real_T Delay3_InitialCondition_j;    /* Expression: 0.0
                                        * Referenced by: '<S255>/Delay3'
                                        */
  real_T UseInputPort_Value_f;         /* Expression: FilterConstantInputType
                                        * Referenced by: '<S256>/UseInputPort'
                                        */
  real_T Switch1_Threshold_b;          /* Expression: 1
                                        * Referenced by: '<S256>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_p; /* Expression: 0
                                        * Referenced by: '<S262>/Unit Delay'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S259>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S259>/Delay1'
                                        */
  real_T UseInputPort_Value_n;         /* Expression: FilterConstantInputType
                                        * Referenced by: '<S257>/UseInputPort'
                                        */
  real_T Switch1_Threshold_l;          /* Expression: 1
                                        * Referenced by: '<S257>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_l; /* Expression: 0
                                        * Referenced by: '<S265>/Unit Delay'
                                        */
  real_T Switch1_Threshold_k;          /* Expression: 0
                                        * Referenced by: '<S250>/Switch1'
                                        */
  real_T a_Value_n;                    /* Expression: 0
                                        * Referenced by: '<S277>/a'
                                        */
  real_T One_Value_n;                  /* Expression: 1
                                        * Referenced by: '<S277>/One'
                                        */
  real_T FilterConstant_Value_p;       /* Expression: Filter_constant
                                        * Referenced by: '<S277>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value_k;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S277>/OneMinusFilterConstant'
                                         */
  real_T a_Value_e;                    /* Expression: 0
                                        * Referenced by: '<S278>/a'
                                        */
  real_T One_Value_e;                  /* Expression: 1
                                        * Referenced by: '<S278>/One'
                                        */
  real_T FilterConstant_Value_ep;      /* Expression: Filter_constant
                                        * Referenced by: '<S278>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value_p;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S278>/OneMinusFilterConstant'
                                         */
  real_T Constant_Value_e;             /* Expression: 0
                                        * Referenced by: '<S252>/Constant'
                                        */
  real_T UseInputPort_Value_g;         /* Expression: FilterConstantInputType
                                        * Referenced by: '<S278>/UseInputPort'
                                        */
  real_T Switch1_Threshold_e;          /* Expression: 1
                                        * Referenced by: '<S278>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_d; /* Expression: 0
                                        * Referenced by: '<S286>/Unit Delay'
                                        */
  real_T Delay1_InitialCondition_b;    /* Expression: 0.0
                                        * Referenced by: '<S279>/Delay1'
                                        */
  real_T Delay_InitialCondition_l;     /* Expression: 0.0
                                        * Referenced by: '<S279>/Delay'
                                        */
  real_T UseInputPort_Value_j;         /* Expression: FilterConstantInputType
                                        * Referenced by: '<S277>/UseInputPort'
                                        */
  real_T Switch1_Threshold_o;          /* Expression: 1
                                        * Referenced by: '<S277>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_l4;/* Expression: 0
                                        * Referenced by: '<S283>/Unit Delay'
                                        */
  real_T Delay1_InitialCondition_d;    /* Expression: 0.0
                                        * Referenced by: '<S280>/Delay1'
                                        */
  real_T Delay_InitialCondition_b;     /* Expression: 0.0
                                        * Referenced by: '<S280>/Delay'
                                        */
  real_T a_Value_o;                    /* Expression: 0
                                        * Referenced by: '<S289>/a'
                                        */
  real_T One_Value_m;                  /* Expression: 1
                                        * Referenced by: '<S289>/One'
                                        */
  real_T FilterConstant_Value_h;       /* Expression: Filter_constant
                                        * Referenced by: '<S289>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value_j;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S289>/OneMinusFilterConstant'
                                         */
  real_T a_Value_p;                    /* Expression: 0
                                        * Referenced by: '<S290>/a'
                                        */
  real_T One_Value_f;                  /* Expression: 1
                                        * Referenced by: '<S290>/One'
                                        */
  real_T FilterConstant_Value_j;       /* Expression: Filter_constant
                                        * Referenced by: '<S290>/FilterConstant'
                                        */
  real_T OneMinusFilterConstant_Value_pq;/* Expression: 1 - Filter_constant
                                          * Referenced by: '<S290>/OneMinusFilterConstant'
                                          */
  real_T Delay2_InitialCondition_j;    /* Expression: 0.0
                                        * Referenced by: '<S287>/Delay2'
                                        */
  real_T Delay3_InitialCondition_l;    /* Expression: 0.0
                                        * Referenced by: '<S287>/Delay3'
                                        */
  real_T UseInputPort_Value_m;         /* Expression: FilterConstantInputType
                                        * Referenced by: '<S290>/UseInputPort'
                                        */
  real_T Switch1_Threshold_g;          /* Expression: 1
                                        * Referenced by: '<S290>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_n; /* Expression: 0
                                        * Referenced by: '<S296>/Unit Delay'
                                        */
  real_T Delay2_InitialCondition_k;    /* Expression: 0.0
                                        * Referenced by: '<S288>/Delay2'
                                        */
  real_T Delay3_InitialCondition_l4;   /* Expression: 0.0
                                        * Referenced by: '<S288>/Delay3'
                                        */
  real_T UseInputPort_Value_i;         /* Expression: FilterConstantInputType
                                        * Referenced by: '<S289>/UseInputPort'
                                        */
  real_T Switch1_Threshold_f;          /* Expression: 1
                                        * Referenced by: '<S289>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_c; /* Expression: 0
                                        * Referenced by: '<S293>/Unit Delay'
                                        */
  real_T Out1_Y0;                      /* Expression: 0
                                        * Referenced by: '<S304>/Out1'
                                        */
  real_T theta_e_Y0;                   /* Expression: 0
                                        * Referenced by: '<S303>/theta_e'
                                        */
  real_T DataStoreMemory11_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory11'
                                         */
  real_T DataStoreMemory9_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory9'
                                        */
  real_T Constant_Value_c;             /* Expression: 0
                                        * Referenced by: '<S193>/Constant'
                                        */
  real_T Delay_InitialCondition_bj;    /* Expression: 0.0
                                        * Referenced by: '<S300>/Delay'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S233>/Integrator'
                                        */
  real_T Merge_InitialOutput;          /* Expression: [0]
                                        * Referenced by: '<S192>/Merge'
                                        */
  real_T UseInputPort_Value_h;         /* Expression: FilterConstantInputType
                                        * Referenced by: '<S251>/UseInputPort'
                                        */
  real_T Switch1_Threshold_p;          /* Expression: 1
                                        * Referenced by: '<S251>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_g; /* Expression: 0
                                        * Referenced by: '<S276>/Unit Delay'
                                        */
  real_T scaleIn_Gain;                 /* Expression: 1/dlgSett.scale
                                        * Referenced by: '<S301>/scaleIn'
                                        */
  real_T UnitDelay_InitialCondition_k; /* Expression: dlgSett.PhaseOffset
                                        * Referenced by: '<S301>/Unit Delay'
                                        */
  real_T scaleOut_Gain;                /* Expression: dlgSett.scale
                                        * Referenced by: '<S301>/scaleOut'
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
                                        * Referenced by: '<S25>/Constant'
                                        */
  real32_T Constant1_Value_g;          /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real32_T Delay_InitialCondition_g;
                                 /* Computed Parameter: Delay_InitialCondition_g
                                  * Referenced by: '<S26>/Delay'
                                  */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S26>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S26>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Multiply_Gain;              /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S26>/Multiply'
                                        */
  real32_T Out1_Y0_a;                  /* Computed Parameter: Out1_Y0_a
                                        * Referenced by: '<S29>/Out1'
                                        */
  real32_T theta_e_Y0_a;               /* Computed Parameter: theta_e_Y0_a
                                        * Referenced by: '<S28>/theta_e'
                                        */
  real32_T Theta_Y0;                   /* Computed Parameter: Theta_Y0
                                        * Referenced by: '<S18>/Theta'
                                        */
  real32_T scaleIn_Gain_n;             /* Computed Parameter: scaleIn_Gain_n
                                        * Referenced by: '<S27>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition_a;
                             /* Computed Parameter: UnitDelay_InitialCondition_a
                              * Referenced by: '<S27>/Unit Delay'
                              */
  real32_T scaleOut_Gain_p;            /* Computed Parameter: scaleOut_Gain_p
                                        * Referenced by: '<S27>/scaleOut'
                                        */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S51>/Constant'
                                        */
  real32_T Gain1_Gain_k;               /* Computed Parameter: Gain1_Gain_k
                                        * Referenced by: '<S51>/Gain1'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S51>/Gain'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S50>/Gain'
                                        */
  real32_T Saturation_UpperSat;        /* Expression: single(0.16667)
                                        * Referenced by: '<S47>/Saturation'
                                        */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S47>/Saturation'
                                       */
  real32_T Merge_InitialOutput_g;   /* Computed Parameter: Merge_InitialOutput_g
                                     * Referenced by: '<S47>/Merge'
                                     */
  real32_T SpeedGain_Gain;             /* Expression: single(6*MinSpeed)
                                        * Referenced by: '<S34>/SpeedGain'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S33>/Constant'
                                        */
  real32_T a_Value_g;                  /* Computed Parameter: a_Value_g
                                        * Referenced by: '<S74>/a'
                                        */
  real32_T One_Value_mb;               /* Computed Parameter: One_Value_mb
                                        * Referenced by: '<S74>/One'
                                        */
  real32_T FilterConstant_Value_f; /* Computed Parameter: FilterConstant_Value_f
                                    * Referenced by: '<S74>/FilterConstant'
                                    */
  real32_T OneMinusFilterConstant_Value_kk;
                          /* Computed Parameter: OneMinusFilterConstant_Value_kk
                           * Referenced by: '<S74>/OneMinusFilterConstant'
                           */
  real32_T Offset_Y0;                  /* Computed Parameter: Offset_Y0
                                        * Referenced by: '<S73>/Offset'
                                        */
  real32_T UseInputPort_Value_d;     /* Computed Parameter: UseInputPort_Value_d
                                      * Referenced by: '<S74>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_pw;     /* Computed Parameter: Switch1_Threshold_pw
                                      * Referenced by: '<S74>/Switch1'
                                      */
  real32_T UnitDelay_InitialCondition_lw;
                            /* Computed Parameter: UnitDelay_InitialCondition_lw
                             * Referenced by: '<S77>/Unit Delay'
                             */
  real32_T Delay_InitialCondition_bx;
                                /* Computed Parameter: Delay_InitialCondition_bx
                                 * Referenced by: '<S66>/Delay'
                                 */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S96>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S96>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S96>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S96>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S96>/Ka'
                                        */
  real32_T one_by_two_Gain_k;          /* Computed Parameter: one_by_two_Gain_k
                                        * Referenced by: '<S93>/one_by_two'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S92>/Gain'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S68>/Gain'
                                        */
  real32_T Offset_Y0_c;                /* Computed Parameter: Offset_Y0_c
                                        * Referenced by: '<S69>/Offset'
                                        */
  real32_T poswlfilter_Y0;             /* Computed Parameter: poswlfilter_Y0
                                        * Referenced by: '<S98>/poswlfilter'
                                        */
  real32_T Delay_InitialCondition_l3;
                                /* Computed Parameter: Delay_InitialCondition_l3
                                 * Referenced by: '<S98>/Delay'
                                 */
  real32_T Delay1_InitialCondition_f;
                                /* Computed Parameter: Delay1_InitialCondition_f
                                 * Referenced by: '<S98>/Delay1'
                                 */
  real32_T Delay2_InitialCondition_bu;
                               /* Computed Parameter: Delay2_InitialCondition_bu
                                * Referenced by: '<S98>/Delay2'
                                */
  real32_T Delay3_InitialCondition_a;
                                /* Computed Parameter: Delay3_InitialCondition_a
                                 * Referenced by: '<S98>/Delay3'
                                 */
  real32_T Delay4_InitialCondition;
                                  /* Computed Parameter: Delay4_InitialCondition
                                   * Referenced by: '<S98>/Delay4'
                                   */
  real32_T Gain_Gain_da;               /* Computed Parameter: Gain_Gain_da
                                        * Referenced by: '<S98>/Gain'
                                        */
  real32_T a_Value_h;                  /* Computed Parameter: a_Value_h
                                        * Referenced by: '<S99>/a'
                                        */
  real32_T One_Value_c;                /* Computed Parameter: One_Value_c
                                        * Referenced by: '<S99>/One'
                                        */
  real32_T FilterConstant_Value_i; /* Computed Parameter: FilterConstant_Value_i
                                    * Referenced by: '<S99>/FilterConstant'
                                    */
  real32_T OneMinusFilterConstant_Value_ar;
                          /* Computed Parameter: OneMinusFilterConstant_Value_ar
                           * Referenced by: '<S99>/OneMinusFilterConstant'
                           */
  real32_T a_Value_k;                  /* Computed Parameter: a_Value_k
                                        * Referenced by: '<S100>/a'
                                        */
  real32_T One_Value_ay;               /* Computed Parameter: One_Value_ay
                                        * Referenced by: '<S100>/One'
                                        */
  real32_T FilterConstant_Value_a; /* Computed Parameter: FilterConstant_Value_a
                                    * Referenced by: '<S100>/FilterConstant'
                                    */
  real32_T OneMinusFilterConstant_Value_d;
                           /* Computed Parameter: OneMinusFilterConstant_Value_d
                            * Referenced by: '<S100>/OneMinusFilterConstant'
                            */
  real32_T PWM_Y0;                     /* Computed Parameter: PWM_Y0
                                        * Referenced by: '<S1>/PWM'
                                        */
  real32_T Theta_Y0_d;                 /* Computed Parameter: Theta_Y0_d
                                        * Referenced by: '<S1>/Theta'
                                        */
  real32_T intedegree_Y0;              /* Computed Parameter: intedegree_Y0
                                        * Referenced by: '<S1>/intedegree'
                                        */
  real32_T poswlfilter_Y0_c;           /* Computed Parameter: poswlfilter_Y0_c
                                        * Referenced by: '<S1>/poswlfilter'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S80>/Constant'
                                        */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S19>/Discrete-Time Integrator'
                                 */
  real32_T DiscreteTimeIntegrator_UpperSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                           * Referenced by: '<S19>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_LowerSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                           * Referenced by: '<S19>/Discrete-Time Integrator'
                           */
  real32_T Merge_InitialOutput_p;   /* Computed Parameter: Merge_InitialOutput_p
                                     * Referenced by: '<S30>/Merge'
                                     */
  real32_T PositionUnit_Gain;          /* Expression: single(360)
                                        * Referenced by: '<S30>/PositionUnit'
                                        */
  real32_T Vd_Ref_Value;               /* Computed Parameter: Vd_Ref_Value
                                        * Referenced by: '<S70>/Vd_Ref'
                                        */
  real32_T Vq_Value;                   /* Computed Parameter: Vq_Value
                                        * Referenced by: '<S70>/Vq'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S67>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S79>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S67>/indexing'
                                        */
  real32_T UseInputPort_Value_jy;   /* Computed Parameter: UseInputPort_Value_jy
                                     * Referenced by: '<S100>/UseInputPort'
                                     */
  real32_T Switch1_Threshold_pwq;   /* Computed Parameter: Switch1_Threshold_pwq
                                     * Referenced by: '<S100>/Switch1'
                                     */
  real32_T UnitDelay_InitialCondition_le;
                            /* Computed Parameter: UnitDelay_InitialCondition_le
                             * Referenced by: '<S106>/Unit Delay'
                             */
  real32_T UseInputPort_Value_if;   /* Computed Parameter: UseInputPort_Value_if
                                     * Referenced by: '<S99>/UseInputPort'
                                     */
  real32_T Switch1_Threshold_bz;     /* Computed Parameter: Switch1_Threshold_bz
                                      * Referenced by: '<S99>/Switch1'
                                      */
  real32_T UnitDelay_InitialCondition_di;
                            /* Computed Parameter: UnitDelay_InitialCondition_di
                             * Referenced by: '<S103>/Unit Delay'
                             */
  real32_T Constant_Value_e3;          /* Computed Parameter: Constant_Value_e3
                                        * Referenced by: '<S307>/Constant'
                                        */
  real32_T sine_table_values_Value_o[1002];
                                /* Computed Parameter: sine_table_values_Value_o
                                 * Referenced by: '<S302>/sine_table_values'
                                 */
  real32_T convert_pu_Gain_e;          /* Computed Parameter: convert_pu_Gain_e
                                        * Referenced by: '<S306>/convert_pu'
                                        */
  real32_T indexing_Gain_b;            /* Computed Parameter: indexing_Gain_b
                                        * Referenced by: '<S302>/indexing'
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
                                        * Referenced by: '<S24>/Count'
                                        */
  uint32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S24>/Constant'
                                        */
  uint32_T Delay_InitialCondition_e;
                                 /* Computed Parameter: Delay_InitialCondition_e
                                  * Referenced by: '<S24>/Delay'
                                  */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S23>/Count for 2 sec'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S67>/offset'
                                        */
  int16_T offset_Value_o[4];           /* Computed Parameter: offset_Value_o
                                        * Referenced by: '<S302>/offset'
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
  uint16_T SpeedConst_Value;
                          /* Expression: uint16(10*ClkFreq/(PolePairs*MinSpeed))
                           * Referenced by: '<S34>/SpeedConst'
                           */
  uint16_T PositionEnable_Value;     /* Computed Parameter: PositionEnable_Value
                                      * Referenced by: '<S34>/PositionEnable'
                                      */
  uint16_T WatchDog_Value;             /* Computed Parameter: WatchDog_Value
                                        * Referenced by: '<S30>/WatchDog'
                                        */
  uint16_T speedcheck_Threshold;     /* Computed Parameter: speedcheck_Threshold
                                      * Referenced by: '<S35>/speed check'
                                      */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S68>/stop'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S89>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S89>/Switch'
                                        */
  uint16_T ct_Y0;                      /* Computed Parameter: ct_Y0
                                        * Referenced by: '<S1>/ct'
                                        */
  uint16_T Constant_Value_mo;          /* Computed Parameter: Constant_Value_mo
                                        * Referenced by: '<S36>/Constant'
                                        */
  uint16_T Order_Value;                /* Computed Parameter: Order_Value
                                        * Referenced by: '<S31>/Order'
                                        */
  uint16_T Switch_Threshold_h;         /* Computed Parameter: Switch_Threshold_h
                                        * Referenced by: '<S31>/Switch'
                                        */
  uint16_T speedCountDelay_InitialConditio;
                          /* Computed Parameter: speedCountDelay_InitialConditio
                           * Referenced by: '<S31>/speedCountDelay'
                           */
  uint16_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S35>/Constant'
                                        */
  uint16_T Constant2_Value_p3;         /* Computed Parameter: Constant2_Value_p3
                                        * Referenced by: '<S32>/Constant2'
                                        */
  uint16_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S133>/Constant'
                                        */
  uint16_T Constant_Value_ih;          /* Computed Parameter: Constant_Value_ih
                                        * Referenced by: '<S108>/Constant'
                                        */
  uint16_T Constant_Value_pl;          /* Computed Parameter: Constant_Value_pl
                                        * Referenced by: '<S158>/Constant'
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
                                  * Referenced by: '<S28>/Delay'
                                  */
  boolean_T Constant_Value_f;          /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S28>/Constant'
                                        */
  boolean_T EnPWM_Y0;                  /* Computed Parameter: EnPWM_Y0
                                        * Referenced by: '<S18>/EnPWM'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S27>/Constant_Reset'
                                      */
  boolean_T validityDelay_InitialCondition;
                           /* Computed Parameter: validityDelay_InitialCondition
                            * Referenced by: '<S31>/validityDelay'
                            */
  boolean_T DelayOneStep1_InitialCondition;
                           /* Computed Parameter: DelayOneStep1_InitialCondition
                            * Referenced by: '<S32>/Delay One Step1'
                            */
  boolean_T UnitDelay_InitialCondition_kj;
                            /* Computed Parameter: UnitDelay_InitialCondition_kj
                             * Referenced by: '<S259>/Unit Delay'
                             */
  boolean_T Delay_InitialCondition_o;
                                 /* Computed Parameter: Delay_InitialCondition_o
                                  * Referenced by: '<S303>/Delay'
                                  */
  boolean_T Constant_Value_a;          /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S303>/Constant'
                                        */
  boolean_T Constant_Reset_Value_c;/* Computed Parameter: Constant_Reset_Value_c
                                    * Referenced by: '<S301>/Constant_Reset'
                                    */
  uint8_T Gain_Gain_de;                /* Computed Parameter: Gain_Gain_de
                                        * Referenced by: '<S132>/Gain'
                                        */
  uint8_T Gain_Gain_jm;                /* Computed Parameter: Gain_Gain_jm
                                        * Referenced by: '<S107>/Gain'
                                        */
  uint8_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S157>/Gain'
                                        */
  uint8_T Gain1_Gain_n;                /* Computed Parameter: Gain1_Gain_n
                                        * Referenced by: '<S132>/Gain1'
                                        */
  uint8_T Gain1_Gain_o;                /* Computed Parameter: Gain1_Gain_o
                                        * Referenced by: '<S107>/Gain1'
                                        */
  uint8_T Gain1_Gain_oh;               /* Computed Parameter: Gain1_Gain_oh
                                        * Referenced by: '<S157>/Gain1'
                                        */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_n;
                            /* '<S169>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431Hallcorrecti_T ValidHalls_b;/* '<S169>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_f;
                            /* '<S119>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431Hallcorrecti_T ValidHalls_p;/* '<S119>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnection;
                            /* '<S144>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_G431Hallcorrecti_T ValidHalls;/* '<S144>/Valid Halls' */
  P_HallValueof1_G431Hallcorrec_T HallValueof7_e;/* '<S37>/Hall Value of 7' */
  P_HallValueof1_G431Hallcorrec_T HallValueof6_m;/* '<S37>/Hall Value of 6' */
  P_HallValueof1_G431Hallcorrec_T HallValueof5_j;/* '<S37>/Hall Value of 5' */
  P_HallValueof1_G431Hallcorrec_T HallValueof4_e;/* '<S37>/Hall Value of 4' */
  P_HallValueof1_G431Hallcorrec_T HallValueof3_b;/* '<S37>/Hall Value of 3' */
  P_HallValueof1_G431Hallcorrec_T HallValueof2_o;/* '<S37>/Hall Value of 2' */
  P_HallValueof1_G431Hallcorrec_T HallValueof1_e;/* '<S37>/Hall Value of 1' */
  P_HallValueof1_G431Hallcorrec_T HallValueof7_b;/* '<S48>/Hall Value of 7' */
  P_HallValueof1_G431Hallcorrec_T HallValueof6_g;/* '<S48>/Hall Value of 6' */
  P_HallValueof1_G431Hallcorrec_T HallValueof5_o;/* '<S48>/Hall Value of 5' */
  P_HallValueof1_G431Hallcorrec_T HallValueof4_l;/* '<S48>/Hall Value of 4' */
  P_HallValueof1_G431Hallcorrec_T HallValueof3_p;/* '<S48>/Hall Value of 3' */
  P_HallValueof1_G431Hallcorrec_T HallValueof2_p;/* '<S48>/Hall Value of 2' */
  P_HallValueof1_G431Hallcorrec_T HallValueof1_b;/* '<S48>/Hall Value of 1' */
  P_HallValueof1_G431Hallcorrec_T HallValueof7;/* '<S49>/Hall Value of 7' */
  P_HallValueof1_G431Hallcorrec_T HallValueof6;/* '<S49>/Hall Value of 6' */
  P_HallValueof1_G431Hallcorrec_T HallValueof5;/* '<S49>/Hall Value of 5' */
  P_HallValueof1_G431Hallcorrec_T HallValueof4;/* '<S49>/Hall Value of 4' */
  P_HallValueof1_G431Hallcorrec_T HallValueof3;/* '<S49>/Hall Value of 3' */
  P_HallValueof1_G431Hallcorrec_T HallValueof2;/* '<S49>/Hall Value of 2' */
  P_HallValueof1_G431Hallcorrec_T HallValueof1;/* '<S49>/Hall Value of 1' */
};

/* Real-time Model Data Structure */
struct tag_RTM_G431Hallcorrection_T {
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
extern P_G431Hallcorrection_T G431Hallcorrection_P;

/* Block signals (default storage) */
extern B_G431Hallcorrection_T G431Hallcorrection_B;

/* Block states (default storage) */
extern DW_G431Hallcorrection_T G431Hallcorrection_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_G431Hallcorrection_T G431Hallcorrection_PrevZCX;

/* External function called from main */
extern void G431Hallcorrection_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void G431Hallcorrection_initialize(void);
extern void G431Hallcorrection_step0(void);
extern void G431Hallcorrection_step1(void);
extern void G431Hallcorrection_terminate(void);

/* Real-time Model object */
extern RT_MODEL_G431Hallcorrection_T *const G431Hallcorrection_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC1_2_IRQHandler(void);
  void TIM3_IRQHandler(void);
  void G431Hallcorrection_configure_interrupts (void);
  void G431Hallcorrection_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S16>/FixPt Constant' : Unused code path elimination
 * Block '<S16>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S16>/FixPt Sum1' : Unused code path elimination
 * Block '<S10>/Output' : Unused code path elimination
 * Block '<S17>/Constant' : Unused code path elimination
 * Block '<S17>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S17>/FixPt Switch' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/Data Type Propagation' : Unused code path elimination
 * Block '<S81>/Data Type Duplicate' : Unused code path elimination
 * Block '<S82>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate' : Unused code path elimination
 * Block '<S88>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Vc' : Unused code path elimination
 * Block '<S96>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S100>/Data Type Duplicate' : Unused code path elimination
 * Block '<S2>/Constant1' : Unused code path elimination
 * Block '<S3>/Constant1' : Unused code path elimination
 * Block '<S4>/Constant1' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S8>/Data Type Conversion' : Unused code path elimination
 * Block '<S8>/Data Type Conversion1' : Unused code path elimination
 * Block '<S8>/FreqGain' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S189>/FilterConstant' : Unused code path elimination
 * Block '<S197>/Add1' : Unused code path elimination
 * Block '<S197>/Product' : Unused code path elimination
 * Block '<S197>/Product1' : Unused code path elimination
 * Block '<S197>/Unit Delay' : Unused code path elimination
 * Block '<S189>/One' : Unused code path elimination
 * Block '<S189>/OneMinusFilterConstant' : Unused code path elimination
 * Block '<S189>/Sum' : Unused code path elimination
 * Block '<S189>/Switch1' : Unused code path elimination
 * Block '<S189>/UseInputPort' : Unused code path elimination
 * Block '<S189>/a' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Propagation' : Unused code path elimination
 * Block '<S198>/Data Type Duplicate' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S199>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/PositionGain' : Unused code path elimination
 * Block '<S250>/Data Type Duplicate' : Unused code path elimination
 * Block '<S250>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S250>/Data Type Propagation1' : Unused code path elimination
 * Block '<S250>/Data Type Propagation2' : Unused code path elimination
 * Block '<S254>/Data Type Propagation' : Unused code path elimination
 * Block '<S254>/Data Type Propagation1' : Unused code path elimination
 * Block '<S255>/Data Type Propagation' : Unused code path elimination
 * Block '<S255>/Data Type Propagation1' : Unused code path elimination
 * Block '<S256>/Data Type Duplicate' : Unused code path elimination
 * Block '<S257>/Data Type Duplicate' : Unused code path elimination
 * Block '<S258>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Duplicate' : Unused code path elimination
 * Block '<S259>/Data Type Propagation' : Unused code path elimination
 * Block '<S251>/Data Type Duplicate' : Unused code path elimination
 * Block '<S252>/Data Type Duplicate' : Unused code path elimination
 * Block '<S252>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S252>/Data Type Propagation1' : Unused code path elimination
 * Block '<S277>/Data Type Duplicate' : Unused code path elimination
 * Block '<S278>/Data Type Duplicate' : Unused code path elimination
 * Block '<S279>/Data Type Propagation' : Unused code path elimination
 * Block '<S279>/Data Type Propagation1' : Unused code path elimination
 * Block '<S280>/Data Type Propagation' : Unused code path elimination
 * Block '<S280>/Data Type Propagation1' : Unused code path elimination
 * Block '<S253>/Data Type Duplicate' : Unused code path elimination
 * Block '<S287>/Data Type Propagation' : Unused code path elimination
 * Block '<S287>/Data Type Propagation1' : Unused code path elimination
 * Block '<S288>/Data Type Propagation' : Unused code path elimination
 * Block '<S288>/Data Type Propagation1' : Unused code path elimination
 * Block '<S289>/Data Type Duplicate' : Unused code path elimination
 * Block '<S290>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S300>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S300>/Data Type Propagation' : Unused code path elimination
 * Block '<S301>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S302>/Data Type Duplicate' : Unused code path elimination
 * Block '<S302>/Data Type Propagation' : Unused code path elimination
 * Block '<S308>/Data Type Duplicate' : Unused code path elimination
 * Block '<S309>/Data Type Duplicate' : Unused code path elimination
 * Block '<S30>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S30>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S30>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S30>/counterSize2' : Eliminate redundant data type conversion
 * Block '<S67>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S2>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S108>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S3>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S133>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S4>/Data Type Conversion3' : Eliminate redundant data type conversion
 * Block '<S158>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S8>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S198>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S198>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S199>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S199>/Data Type Conversion1' : Eliminate redundant data type conversion
 * Block '<S199>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S192>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S302>/Get_FractionVal' : Eliminate redundant data type conversion
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
 * '<Root>' : 'G431Hallcorrection'
 * '<S1>'   : 'G431Hallcorrection/Function-Call Subsystem'
 * '<S2>'   : 'G431Hallcorrection/HALL_A'
 * '<S3>'   : 'G431Hallcorrection/HALL_B'
 * '<S4>'   : 'G431Hallcorrection/HALL_C'
 * '<S5>'   : 'G431Hallcorrection/Hardware Interrupt'
 * '<S6>'   : 'G431Hallcorrection/Hardware Interrupt2'
 * '<S7>'   : 'G431Hallcorrection/LED Heart'
 * '<S8>'   : 'G431Hallcorrection/PLL with Feed Forward'
 * '<S9>'   : 'G431Hallcorrection/Function-Call Subsystem/Analog to Digital Converter'
 * '<S10>'  : 'G431Hallcorrection/Function-Call Subsystem/Counter Limited1'
 * '<S11>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem'
 * '<S12>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2'
 * '<S13>'  : 'G431Hallcorrection/Function-Call Subsystem/speedfilter '
 * '<S14>'  : 'G431Hallcorrection/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S15>'  : 'G431Hallcorrection/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S16>'  : 'G431Hallcorrection/Function-Call Subsystem/Counter Limited1/Increment Real World'
 * '<S17>'  : 'G431Hallcorrection/Function-Call Subsystem/Counter Limited1/Wrap To Zero'
 * '<S18>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen'
 * '<S19>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1'
 * '<S20>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Disable host after 42 seconds'
 * '<S21>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Enable PWM for 40 seconds'
 * '<S22>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Subsystem'
 * '<S23>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Subsystem1'
 * '<S24>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Up Counter'
 * '<S25>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/If Action Subsystem'
 * '<S26>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/If Action Subsystem2'
 * '<S27>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/Position Generator'
 * '<S28>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S29>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S30>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1'
 * '<S31>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/ExtrapolationOrder'
 * '<S32>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Software Watchdog Timer'
 * '<S33>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant'
 * '<S34>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position'
 * '<S35>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/VaidityCheck'
 * '<S36>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Software Watchdog Timer/Compare To Zero'
 * '<S37>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction'
 * '<S38>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 1'
 * '<S39>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 2'
 * '<S40>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 3'
 * '<S41>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 4'
 * '<S42>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 5'
 * '<S43>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 6'
 * '<S44>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are not valid Position will be set to the middle of the Hall quadrant/independent Direction/Hall Value of 7'
 * '<S45>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem'
 * '<S46>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/If Action Subsystem1'
 * '<S47>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1'
 * '<S48>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction'
 * '<S49>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction'
 * '<S50>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/first_order'
 * '<S51>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/second_order'
 * '<S52>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 1'
 * '<S53>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 2'
 * '<S54>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 3'
 * '<S55>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 4'
 * '<S56>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 5'
 * '<S57>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 6'
 * '<S58>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/+ve Direction/Hall Value of 7'
 * '<S59>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 1'
 * '<S60>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 2'
 * '<S61>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 3'
 * '<S62>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 4'
 * '<S63>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 5'
 * '<S64>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 6'
 * '<S65>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem/Subsystem1/Hall Speed and Position1/Speed and direction are valid Use speed to extrapolate position/Subsystem1/-ve Direction/Hall Value of 7'
 * '<S66>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Find Offset'
 * '<S67>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup'
 * '<S68>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem'
 * '<S69>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem1'
 * '<S70>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2'
 * '<S71>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Find Offset/Compare To Constant'
 * '<S72>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Find Offset/Compare To Constant1'
 * '<S73>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem'
 * '<S74>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter'
 * '<S75>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S76>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S77>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S78>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/Interpolation'
 * '<S79>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp'
 * '<S80>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S81>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S82>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S83>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output'
 * '<S84>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output/ECSoC'
 * '<S85>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem/PWM Output/ECSoC/ECSimCodegen'
 * '<S86>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform'
 * '<S87>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator'
 * '<S88>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform/Two inputs CRL'
 * '<S89>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S90>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method'
 * '<S91>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input'
 * '<S92>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method/SVPWM'
 * '<S93>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S94>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S95>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S96>'  : 'G431Hallcorrection/Function-Call Subsystem/Subsystem2/Subsystem2/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S97>'  : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /Compare speed low than 20RPM'
 * '<S98>'  : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /Enabled Subsystem'
 * '<S99>'  : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /IIR Filter'
 * '<S100>' : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /IIR Filter1'
 * '<S101>' : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /IIR Filter/IIR Filter'
 * '<S102>' : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /IIR Filter/IIR Filter/Low-pass'
 * '<S103>' : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S104>' : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /IIR Filter1/IIR Filter'
 * '<S105>' : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /IIR Filter1/IIR Filter/Low-pass'
 * '<S106>' : 'G431Hallcorrection/Function-Call Subsystem/speedfilter /IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S107>' : 'G431Hallcorrection/HALL_A/HALLVaule'
 * '<S108>' : 'G431Hallcorrection/HALL_A/Hall Validity'
 * '<S109>' : 'G431Hallcorrection/HALL_A/Subsystem1'
 * '<S110>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLB'
 * '<S111>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLB1'
 * '<S112>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLC'
 * '<S113>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLB/ECSoC'
 * '<S114>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S115>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLB1/ECSoC'
 * '<S116>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLB1/ECSoC/ECSimCodegen'
 * '<S117>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLC/ECSoC'
 * '<S118>' : 'G431Hallcorrection/HALL_A/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S119>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem'
 * '<S120>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S121>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls'
 * '<S122>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S123>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S124>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S125>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S126>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S127>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S128>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S129>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S130>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S131>' : 'G431Hallcorrection/HALL_A/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S132>' : 'G431Hallcorrection/HALL_B/HALLVaule'
 * '<S133>' : 'G431Hallcorrection/HALL_B/Hall Validity'
 * '<S134>' : 'G431Hallcorrection/HALL_B/Subsystem1'
 * '<S135>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLB'
 * '<S136>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLB1'
 * '<S137>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLC'
 * '<S138>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLB/ECSoC'
 * '<S139>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S140>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLB1/ECSoC'
 * '<S141>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLB1/ECSoC/ECSimCodegen'
 * '<S142>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLC/ECSoC'
 * '<S143>' : 'G431Hallcorrection/HALL_B/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S144>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem'
 * '<S145>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S146>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls'
 * '<S147>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S148>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S149>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S150>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S151>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S152>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S153>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S154>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S155>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S156>' : 'G431Hallcorrection/HALL_B/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S157>' : 'G431Hallcorrection/HALL_C/HALLVaule'
 * '<S158>' : 'G431Hallcorrection/HALL_C/Hall Validity'
 * '<S159>' : 'G431Hallcorrection/HALL_C/Subsystem1'
 * '<S160>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLB'
 * '<S161>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLB1'
 * '<S162>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLC'
 * '<S163>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLB/ECSoC'
 * '<S164>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLB/ECSoC/ECSimCodegen'
 * '<S165>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLB1/ECSoC'
 * '<S166>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLB1/ECSoC/ECSimCodegen'
 * '<S167>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLC/ECSoC'
 * '<S168>' : 'G431Hallcorrection/HALL_C/HALLVaule/HALLC/ECSoC/ECSimCodegen'
 * '<S169>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem'
 * '<S170>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S171>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls'
 * '<S172>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S173>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S174>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S175>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S176>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S177>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S178>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S179>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S180>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S181>' : 'G431Hallcorrection/HALL_C/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S182>' : 'G431Hallcorrection/Hardware Interrupt/ECSoC'
 * '<S183>' : 'G431Hallcorrection/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S184>' : 'G431Hallcorrection/Hardware Interrupt2/ECSoC'
 * '<S185>' : 'G431Hallcorrection/Hardware Interrupt2/ECSoC/ECSimCodegen'
 * '<S186>' : 'G431Hallcorrection/LED Heart/Digital Port Write'
 * '<S187>' : 'G431Hallcorrection/LED Heart/Digital Port Write/ECSoC'
 * '<S188>' : 'G431Hallcorrection/LED Heart/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S189>' : 'G431Hallcorrection/PLL with Feed Forward/IIR Filter'
 * '<S190>' : 'G431Hallcorrection/PLL with Feed Forward/Normalize'
 * '<S191>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller'
 * '<S192>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward'
 * '<S193>' : 'G431Hallcorrection/PLL with Feed Forward/Subsystem'
 * '<S194>' : 'G431Hallcorrection/PLL with Feed Forward/VCO'
 * '<S195>' : 'G431Hallcorrection/PLL with Feed Forward/IIR Filter/IIR Filter'
 * '<S196>' : 'G431Hallcorrection/PLL with Feed Forward/IIR Filter/IIR Filter/Low-pass'
 * '<S197>' : 'G431Hallcorrection/PLL with Feed Forward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S198>' : 'G431Hallcorrection/PLL with Feed Forward/Normalize/If Action Subsystem'
 * '<S199>' : 'G431Hallcorrection/PLL with Feed Forward/Normalize/Subsystem'
 * '<S200>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Anti-windup'
 * '<S201>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/D Gain'
 * '<S202>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/External Derivative'
 * '<S203>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Filter'
 * '<S204>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Filter ICs'
 * '<S205>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/I Gain'
 * '<S206>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Ideal P Gain'
 * '<S207>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Ideal P Gain Fdbk'
 * '<S208>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Integrator'
 * '<S209>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Integrator ICs'
 * '<S210>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/N Copy'
 * '<S211>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/N Gain'
 * '<S212>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/P Copy'
 * '<S213>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Parallel P Gain'
 * '<S214>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Reset Signal'
 * '<S215>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Saturation'
 * '<S216>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Saturation Fdbk'
 * '<S217>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Sum'
 * '<S218>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Sum Fdbk'
 * '<S219>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Tracking Mode'
 * '<S220>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Tracking Mode Sum'
 * '<S221>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Tsamp - Integral'
 * '<S222>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Tsamp - Ngain'
 * '<S223>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/postSat Signal'
 * '<S224>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/preSat Signal'
 * '<S225>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Anti-windup/Passthrough'
 * '<S226>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/D Gain/Disabled'
 * '<S227>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/External Derivative/Disabled'
 * '<S228>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Filter/Disabled'
 * '<S229>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Filter ICs/Disabled'
 * '<S230>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/I Gain/Internal Parameters'
 * '<S231>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Ideal P Gain/Passthrough'
 * '<S232>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S233>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Integrator/Discrete'
 * '<S234>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Integrator ICs/Internal IC'
 * '<S235>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S236>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/N Gain/Disabled'
 * '<S237>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/P Copy/Disabled'
 * '<S238>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S239>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Reset Signal/External Reset'
 * '<S240>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Saturation/Passthrough'
 * '<S241>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Saturation Fdbk/Disabled'
 * '<S242>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Sum/Sum_PI'
 * '<S243>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Sum Fdbk/Disabled'
 * '<S244>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Tracking Mode/Disabled'
 * '<S245>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S246>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S247>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S248>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/postSat Signal/Forward_Path'
 * '<S249>' : 'G431Hallcorrection/PLL with Feed Forward/PID Controller/preSat Signal/Forward_Path'
 * '<S250>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod'
 * '<S251>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IIR Filter'
 * '<S252>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod'
 * '<S253>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod'
 * '<S254>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/Differentiator'
 * '<S255>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/Differentiator1'
 * '<S256>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter1'
 * '<S257>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter2'
 * '<S258>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter3'
 * '<S259>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/Subsystem'
 * '<S260>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S261>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S262>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S263>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter'
 * '<S264>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass'
 * '<S265>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter2/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S266>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S267>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S268>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S269>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant'
 * '<S270>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant1'
 * '<S271>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant2'
 * '<S272>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant4'
 * '<S273>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/DifferentiationMethod/Subsystem/Compare To Constant5'
 * '<S274>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IIR Filter/IIR Filter'
 * '<S275>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass'
 * '<S276>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S277>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/IIR Filter1'
 * '<S278>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/IIR Filter3'
 * '<S279>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/Integrator'
 * '<S280>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/Integrator1'
 * '<S281>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter'
 * '<S282>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S283>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S284>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter'
 * '<S285>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S286>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/IntegralMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S287>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator'
 * '<S288>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/Differentiator1'
 * '<S289>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1'
 * '<S290>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3'
 * '<S291>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter'
 * '<S292>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass'
 * '<S293>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S294>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter'
 * '<S295>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass'
 * '<S296>' : 'G431Hallcorrection/PLL with Feed Forward/SpeedFeedforward/OptimizedDifferentiationMethod/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S297>' : 'G431Hallcorrection/PLL with Feed Forward/Subsystem/If Action Subsystem'
 * '<S298>' : 'G431Hallcorrection/PLL with Feed Forward/Subsystem/If Action Subsystem1'
 * '<S299>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem'
 * '<S300>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased'
 * '<S301>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Position Generator'
 * '<S302>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup'
 * '<S303>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Position Generator/Accumulate'
 * '<S304>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Position Generator/Accumulate/Subsystem'
 * '<S305>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/Interpolation'
 * '<S306>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/WrapUp'
 * '<S307>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S308>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S309>' : 'G431Hallcorrection/PLL with Feed Forward/VCO/Variant Subsystem/LookupTableBased/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 */
#endif                                 /* G431Hallcorrection_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
