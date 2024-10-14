/*
 * File: Hallhardwaredebugslx.h
 *
 * Code generated for Simulink model 'Hallhardwaredebugslx'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Oct 14 17:50:09 2024
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
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#include "stm_uart.h"
#endif                               /* Hallhardwaredebugslx_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "Hallhardwaredebugslx_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals for system '<S118>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S120>/Merge' */
  uint16_T Merge1;                     /* '<S120>/Merge1' */
  uint16_T Merge3;                     /* '<S120>/Merge3' */
  int16_T Merge2;                      /* '<S120>/Merge2' */
} B_ValidHalls_Hallhardwaredebu_T;

/* Block signals (default storage) */
typedef struct {
  uint32_T speedCountDelay;            /* '<S30>/speedCountDelay' */
  uint32_T Add1;                       /* '<S23>/Add1' */
  real32_T Add1_e;                     /* '<S157>/Add1' */
  real32_T Sum;                        /* '<S18>/Sum' */
  real32_T Merge;                      /* '<S46>/Merge' */
  real32_T scaleOut;                   /* '<S26>/scaleOut' */
  real32_T Add1_n;                     /* '<S27>/Add1' */
  real32_T Input;                      /* '<S28>/Input' */
  uint16_T DelayOneStep;               /* '<S31>/Delay One Step' */
  boolean_T validityDelay;             /* '<S30>/validityDelay' */
  boolean_T Compare;                   /* '<S20>/Compare' */
  B_ValidHalls_Hallhardwaredebu_T ValidHalls_i;/* '<S68>/Valid Halls' */
  B_ValidHalls_Hallhardwaredebu_T ValidHalls_f;/* '<S93>/Valid Halls' */
  B_ValidHalls_Hallhardwaredebu_T ValidHalls;/* '<S118>/Valid Halls' */
} B_Hallhardwaredebugslx_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_UARTWrite_Ha_T obj; /* '<Root>/UART//USART Write' */
  stm32cube_blocks_AnalogInput__T obj_g;/* '<S14>/Analog to Digital Converter' */
  stm32cube_blocks_TimerBlock_H_T obj_e;/* '<S67>/Timer' */
  stm32cube_blocks_TimerBlock_H_T obj_et;/* '<S92>/Timer' */
  stm32cube_blocks_TimerBlock_H_T obj_etd;/* '<S117>/Timer' */
  stm32cube_blocks_PWMOutput_Ha_T obj_h;/* '<S170>/PWM Output' */
  stm32cube_blocks_PWMOutput_Ha_T obj_m;/* '<S146>/PWM Output' */
  real_T HallCcapture;                 /* '<Root>/Data Store Memory10' */
  real_T HallBcapture;                 /* '<Root>/Data Store Memory4' */
  real_T HallAcapture;                 /* '<Root>/Data Store Memory2' */
  real_T Enable;                       /* '<Root>/Data Store Memory9' */
  int64_T Timehall;                    /* '<Root>/Data Store Memory3' */
  real32_T Delay_DSTATE;               /* '<S147>/Delay' */
  real32_T UnitDelay_DSTATE;           /* '<S157>/Unit Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S18>/Discrete-Time Integrator' */
  real32_T UnitDelay_DSTATE_e;         /* '<S26>/Unit Delay' */
  real32_T Delay_DSTATE_f;             /* '<S25>/Delay' */
  uint32_T speedCountDelay_DSTATE;     /* '<S30>/speedCountDelay' */
  uint32_T Delay_DSTATE_n;             /* '<S23>/Delay' */
  uint32_T Delay_DSTATE_m;             /* '<S67>/Delay' */
  uint32_T Delay_DSTATE_b;             /* '<S92>/Delay' */
  uint32_T Delay_DSTATE_mw;            /* '<S117>/Delay' */
  real32_T DiscreteTimeIntegrator_PREV_U;/* '<S18>/Discrete-Time Integrator' */
  uint32_T Timercntprev;               /* '<Root>/Data Store Memory1' */
  uint32_T GlobalSpeedCount;           /* '<Root>/Data Store Memory6' */
  uint32_T ADCSIC_PREV_T;              /* '<Root>/ADC SIC' */
  uint16_T DelayOneStep_DSTATE;        /* '<S31>/Delay One Step' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory5' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory7' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory8' */
  boolean_T validityDelay_DSTATE;      /* '<S30>/validityDelay' */
  boolean_T DelayOneStep1_DSTATE;      /* '<S31>/Delay One Step1' */
  boolean_T Delay_DSTATE_k;            /* '<S27>/Delay' */
  int8_T DiscreteTimeIntegrator_PrevRese;/* '<S18>/Discrete-Time Integrator' */
  uint8_T GlobalHallState;             /* '<Root>/Data Store Memory' */
  uint8_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S18>/Discrete-Time Integrator' */
  boolean_T ADCSIC_RESET_ELAPS_T;      /* '<Root>/ADC SIC' */
  boolean_T FindOffset_MODE;           /* '<S8>/Find Offset' */
  boolean_T PosGen_MODE;               /* '<S12>/PosGen' */
  boolean_T UpCounter_MODE;            /* '<S17>/Up Counter' */
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
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S151>/Constant'
                                       */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S152>/Constant'
                                      */
  uint32_T Disablehostafter42seconds_const;
                              /* Mask Parameter: Disablehostafter42seconds_const
                               * Referenced by: '<S19>/Constant'
                               */
  uint32_T EnablePWMfor40seconds_const;
                                  /* Mask Parameter: EnablePWMfor40seconds_const
                                   * Referenced by: '<S20>/Constant'
                                   */
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
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S21>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: EnableSecondOrder
                                        * Referenced by: '<S46>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S18>/Discrete-Time Integrator'
                            */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant1_Value_a;            /* Expression: 10
                                        * Referenced by: '<S7>/Constant1'
                                        */
  real_T Constant1_Value_pw;           /* Expression: 0.5
                                        * Referenced by: '<S164>/Constant1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<S164>/Gain1'
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
  int32_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S4>/Gain'
                                        */
  int32_T Gain_Gain_e;                 /* Computed Parameter: Gain_Gain_e
                                        * Referenced by: '<S3>/Gain'
                                        */
  int32_T Gain_Gain_p;                 /* Computed Parameter: Gain_Gain_p
                                        * Referenced by: '<S2>/Gain'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S24>/Constant'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S25>/Delay'
                                    */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S25>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S25>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Multiply_Gain;              /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S25>/Multiply'
                                        */
  real32_T Out1_Y0_l;                  /* Computed Parameter: Out1_Y0_l
                                        * Referenced by: '<S28>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S27>/theta_e'
                                        */
  real32_T Theta_Y0;                   /* Computed Parameter: Theta_Y0
                                        * Referenced by: '<S17>/Theta'
                                        */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S26>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S26>/Unit Delay'
                                */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S26>/scaleOut'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S50>/Constant'
                                        */
  real32_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<S50>/Gain1'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S50>/Gain'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
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
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S18>/Discrete-Time Integrator'
                                 */
  real32_T DiscreteTimeIntegrator_UpperSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
                           * Referenced by: '<S18>/Discrete-Time Integrator'
                           */
  real32_T DiscreteTimeIntegrator_LowerSat;
                          /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
                           * Referenced by: '<S18>/Discrete-Time Integrator'
                           */
  real32_T Gain_Gain_o;                /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<S18>/Gain'
                                        */
  real32_T PositionUnit_Gain;          /* Expression: single(360)
                                        * Referenced by: '<S29>/PositionUnit'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S154>/a'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S154>/One'
                                        */
  real32_T FilterConstant_Value;     /* Computed Parameter: FilterConstant_Value
                                      * Referenced by: '<S154>/FilterConstant'
                                      */
  real32_T OneMinusFilterConstant_Value;
                             /* Computed Parameter: OneMinusFilterConstant_Value
                              * Referenced by: '<S154>/OneMinusFilterConstant'
                              */
  real32_T Offset_Y0;                  /* Computed Parameter: Offset_Y0
                                        * Referenced by: '<S153>/Offset'
                                        */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S154>/UseInputPort'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S154>/Switch1'
                                        */
  real32_T UnitDelay_InitialCondition_i;
                             /* Computed Parameter: UnitDelay_InitialCondition_i
                              * Referenced by: '<S157>/Unit Delay'
                              */
  real32_T Delay_InitialCondition_i;
                                 /* Computed Parameter: Delay_InitialCondition_i
                                  * Referenced by: '<S147>/Delay'
                                  */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S177>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S177>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S177>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S177>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S177>/Ka'
                                        */
  real32_T one_by_two_Gain_j;          /* Computed Parameter: one_by_two_Gain_j
                                        * Referenced by: '<S174>/one_by_two'
                                        */
  real32_T Gain_Gain_f;                /* Computed Parameter: Gain_Gain_f
                                        * Referenced by: '<S173>/Gain'
                                        */
  real32_T Gain_Gain_es;               /* Computed Parameter: Gain_Gain_es
                                        * Referenced by: '<S164>/Gain'
                                        */
  real32_T Offset_Y0_i;                /* Computed Parameter: Offset_Y0_i
                                        * Referenced by: '<S150>/Offset'
                                        */
  real32_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S160>/Constant'
                                        */
  real32_T Vd_Ref_Value;               /* Computed Parameter: Vd_Ref_Value
                                        * Referenced by: '<S149>/Vd_Ref'
                                        */
  real32_T Vq_Value;                   /* Computed Parameter: Vq_Value
                                        * Referenced by: '<S149>/Vq'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S148>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S159>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S148>/indexing'
                                        */
  uint32_T Delay_InitialCondition_l;
                                 /* Computed Parameter: Delay_InitialCondition_l
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
  uint32_T Count_Y0;                   /* Computed Parameter: Count_Y0
                                        * Referenced by: '<S23>/Count'
                                        */
  uint32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S23>/Constant'
                                        */
  uint32_T Delay_InitialCondition_p;
                                 /* Computed Parameter: Delay_InitialCondition_p
                                  * Referenced by: '<S23>/Delay'
                                  */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S22>/Count for 2 sec'
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
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S148>/offset'
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
  uint16_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S34>/Constant'
                                        */
  uint16_T Order_Value;                /* Computed Parameter: Order_Value
                                        * Referenced by: '<S30>/Order'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S30>/Switch'
                                        */
  uint16_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S31>/Constant2'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S167>/Offset'
                                        */
  uint16_T Switch_Threshold_j;         /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S167>/Switch'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S164>/stop'
                                        */
  uint16_T DataStoreMemory7_InitialValue;
                            /* Computed Parameter: DataStoreMemory7_InitialValue
                             * Referenced by: '<Root>/Data Store Memory7'
                             */
  uint16_T DataStoreMemory8_InitialValue;
                            /* Computed Parameter: DataStoreMemory8_InitialValue
                             * Referenced by: '<Root>/Data Store Memory8'
                             */
  boolean_T Delay_InitialCondition_no;
                                /* Computed Parameter: Delay_InitialCondition_no
                                 * Referenced by: '<S27>/Delay'
                                 */
  boolean_T Constant_Value_nl;         /* Computed Parameter: Constant_Value_nl
                                        * Referenced by: '<S27>/Constant'
                                        */
  boolean_T EnPWM_Y0;                  /* Computed Parameter: EnPWM_Y0
                                        * Referenced by: '<S17>/EnPWM'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S26>/Constant_Reset'
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
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
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
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTick4;
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
 * Block '<S15>/FixPt Constant' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S15>/FixPt Sum1' : Unused code path elimination
 * Block '<S10>/Output' : Unused code path elimination
 * Block '<S16>/Constant' : Unused code path elimination
 * Block '<S16>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S16>/FixPt Switch' : Unused code path elimination
 * Block '<S11>/Data Type' : Unused code path elimination
 * Block '<S11>/Number of pole pairs' : Unused code path elimination
 * Block '<S11>/PWM Frequency' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate2' : Unused code path elimination
 * Block '<Root>/Data Type Conversion' : Unused code path elimination
 * Block '<S2>/Constant' : Unused code path elimination
 * Block '<S3>/Constant' : Unused code path elimination
 * Block '<S4>/Constant' : Unused code path elimination
 * Block '<S7>/Data Type' : Unused code path elimination
 * Block '<S7>/Number of pole pairs' : Unused code path elimination
 * Block '<S7>/PWM Frequency' : Unused code path elimination
 * Block '<Root>/RT3' : Unused code path elimination
 * Block '<S154>/Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/Data Type Duplicate' : Unused code path elimination
 * Block '<S148>/Data Type Propagation' : Unused code path elimination
 * Block '<S161>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S166>/Data Type Duplicate' : Unused code path elimination
 * Block '<S166>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S165>/Data Type Duplicate' : Unused code path elimination
 * Block '<S165>/Vc' : Unused code path elimination
 * Block '<S177>/Data Type Duplicate' : Unused code path elimination
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
 * Block '<S148>/Get_FractionVal' : Eliminate redundant data type conversion
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
 * '<S7>'   : 'Hallhardwaredebugslx/Parameters'
 * '<S8>'   : 'Hallhardwaredebugslx/Subsystem2'
 * '<S9>'   : 'Hallhardwaredebugslx/ADC SIC/Analog to Digital Converter'
 * '<S10>'  : 'Hallhardwaredebugslx/ADC SIC/Counter Limited1'
 * '<S11>'  : 'Hallhardwaredebugslx/ADC SIC/Parameters'
 * '<S12>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem'
 * '<S13>'  : 'Hallhardwaredebugslx/ADC SIC/Analog to Digital Converter/ECSoC'
 * '<S14>'  : 'Hallhardwaredebugslx/ADC SIC/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S15>'  : 'Hallhardwaredebugslx/ADC SIC/Counter Limited1/Increment Real World'
 * '<S16>'  : 'Hallhardwaredebugslx/ADC SIC/Counter Limited1/Wrap To Zero'
 * '<S17>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen'
 * '<S18>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/Subsystem1'
 * '<S19>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Disable host after 42 seconds'
 * '<S20>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Enable PWM for 40 seconds'
 * '<S21>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Subsystem'
 * '<S22>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Subsystem1'
 * '<S23>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Up Counter'
 * '<S24>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Subsystem1/If Action Subsystem'
 * '<S25>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Subsystem1/If Action Subsystem2'
 * '<S26>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator'
 * '<S27>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate'
 * '<S28>'  : 'Hallhardwaredebugslx/ADC SIC/Subsystem/PosGen/Subsystem1/Position Generator/Accumulate/Subsystem'
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
 * '<S144>' : 'Hallhardwaredebugslx/Parameters/PWM Output'
 * '<S145>' : 'Hallhardwaredebugslx/Parameters/PWM Output/ECSoC'
 * '<S146>' : 'Hallhardwaredebugslx/Parameters/PWM Output/ECSoC/ECSimCodegen'
 * '<S147>' : 'Hallhardwaredebugslx/Subsystem2/Find Offset'
 * '<S148>' : 'Hallhardwaredebugslx/Subsystem2/Sine-Cosine Lookup'
 * '<S149>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem'
 * '<S150>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem1'
 * '<S151>' : 'Hallhardwaredebugslx/Subsystem2/Find Offset/Compare To Constant'
 * '<S152>' : 'Hallhardwaredebugslx/Subsystem2/Find Offset/Compare To Constant1'
 * '<S153>' : 'Hallhardwaredebugslx/Subsystem2/Find Offset/Subsystem'
 * '<S154>' : 'Hallhardwaredebugslx/Subsystem2/Find Offset/Subsystem/IIR Filter'
 * '<S155>' : 'Hallhardwaredebugslx/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter'
 * '<S156>' : 'Hallhardwaredebugslx/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S157>' : 'Hallhardwaredebugslx/Subsystem2/Find Offset/Subsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S158>' : 'Hallhardwaredebugslx/Subsystem2/Sine-Cosine Lookup/Interpolation'
 * '<S159>' : 'Hallhardwaredebugslx/Subsystem2/Sine-Cosine Lookup/WrapUp'
 * '<S160>' : 'Hallhardwaredebugslx/Subsystem2/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S161>' : 'Hallhardwaredebugslx/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S162>' : 'Hallhardwaredebugslx/Subsystem2/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S163>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/Inverse Park Transform'
 * '<S164>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM'
 * '<S165>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM Reference Generator'
 * '<S166>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/Inverse Park Transform/Two inputs CRL'
 * '<S167>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S168>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM/PWM Output'
 * '<S169>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM/PWM Output/ECSoC'
 * '<S170>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM/PWM Output/ECSoC/ECSimCodegen'
 * '<S171>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM Reference Generator/Modulation method'
 * '<S172>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM Reference Generator/Voltage Input'
 * '<S173>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM Reference Generator/Modulation method/SVPWM'
 * '<S174>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S175>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S176>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S177>' : 'Hallhardwaredebugslx/Subsystem2/Subsystem/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 */
#endif                                 /* Hallhardwaredebugslx_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
