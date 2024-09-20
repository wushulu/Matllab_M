/*
 * File: GOPIO.h
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.68
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Sep 13 15:22:06 2024
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
#include "rtGetNaN.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T DiscreteTimeIntegrator;       /* '<S203>/Discrete-Time Integrator' */
  real_T Mod;                          /* '<S209>/Mod' */
  real_T VectorConcatenate[3];         /* '<S202>/Vector Concatenate' */
  real_T Add4[3];                      /* '<S11>/Add4' */
  real_T IProdOut;                     /* '<S163>/IProd Out' */
  real_T DeadZone;                     /* '<S158>/DeadZone' */
  real_T DeadZone_d;                   /* '<S106>/DeadZone' */
  real_T convert_pu;                   /* '<S193>/convert_pu' */
  real_T sine_cosine_o2;               /* '<S205>/sine_cosine' */
  real_T sine_cosine_o1;               /* '<S205>/sine_cosine' */
  real_T MtrElcPos;                    /* '<S209>/polepair' */
  real_T Add_b;                        /* '<S216>/Add' */
} B_GOPIO_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S13>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_GO_T obj_c;/* '<S200>/PWM Output' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S222>/Discrete-Time Integrator3' */
  real_T UnitDelay_DSTATE;             /* '<S206>/Unit Delay' */
  real_T DiscreteTimeIntegrator3_DSTAT_g;/* '<S221>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S203>/Discrete-Time Integrator' */
  real_T Integrator_DSTATE;            /* '<S166>/Integrator' */
  real_T Integrator_DSTATE_e;          /* '<S114>/Integrator' */
  real_T Integrator_DSTATE_j;          /* '<S62>/Integrator' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S193>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S193>/If Action Subsystem' */
  uint8_T DiscreteTimeIntegrator3_IC_LOAD;/* '<S222>/Discrete-Time Integrator3' */
  uint8_T DiscreteTimeIntegrator3_IC_LO_m;/* '<S221>/Discrete-Time Integrator3' */
} DW_GOPIO_T;

/* Parameters (default storage) */
struct P_GOPIO_T_ {
  real_T PIController2_InitialConditionF;
                              /* Mask Parameter: PIController2_InitialConditionF
                               * Referenced by: '<S166>/Integrator'
                               */
  real_T PIController1_InitialConditionF;
                              /* Mask Parameter: PIController1_InitialConditionF
                               * Referenced by: '<S114>/Integrator'
                               */
  real_T PIController_InitialConditionFo;
                              /* Mask Parameter: PIController_InitialConditionFo
                               * Referenced by: '<S62>/Integrator'
                               */
  real_T Int1_L;                       /* Mask Parameter: Int1_L
                                        * Referenced by: '<S208>/Constant'
                                        */
  real_T PIController2_LowerSaturationLi;
                              /* Mask Parameter: PIController2_LowerSaturationLi
                               * Referenced by:
                               *   '<S173>/Saturation'
                               *   '<S158>/DeadZone'
                               */
  real_T PIController1_LowerSaturationLi;
                              /* Mask Parameter: PIController1_LowerSaturationLi
                               * Referenced by:
                               *   '<S121>/Saturation'
                               *   '<S106>/DeadZone'
                               */
  real_T PIController_LowerSaturationLim;
                              /* Mask Parameter: PIController_LowerSaturationLim
                               * Referenced by:
                               *   '<S69>/Saturation'
                               *   '<S54>/DeadZone'
                               */
  real_T SurfaceMountPMSM_P;           /* Mask Parameter: SurfaceMountPMSM_P
                                        * Referenced by:
                                        *   '<S203>/Gain'
                                        *   '<S203>/Gain4'
                                        *   '<S209>/polepair'
                                        *   '<S217>/Gain2'
                                        */
  real_T SurfaceMountPMSM_Rs;          /* Mask Parameter: SurfaceMountPMSM_Rs
                                        * Referenced by:
                                        *   '<S225>/Constant'
                                        *   '<S229>/Constant'
                                        */
  real_T Int1_Ts;                      /* Mask Parameter: Int1_Ts
                                        * Referenced by: '<S206>/Gain1'
                                        */
  real_T Int1_U;                       /* Mask Parameter: Int1_U
                                        * Referenced by: '<S207>/Constant'
                                        */
  real_T PIController2_UpperSaturationLi;
                              /* Mask Parameter: PIController2_UpperSaturationLi
                               * Referenced by:
                               *   '<S173>/Saturation'
                               *   '<S158>/DeadZone'
                               */
  real_T PIController1_UpperSaturationLi;
                              /* Mask Parameter: PIController1_UpperSaturationLi
                               * Referenced by:
                               *   '<S121>/Saturation'
                               *   '<S106>/DeadZone'
                               */
  real_T PIController_UpperSaturationLim;
                              /* Mask Parameter: PIController_UpperSaturationLim
                               * Referenced by:
                               *   '<S69>/Saturation'
                               *   '<S54>/DeadZone'
                               */
  real_T SurfaceMountPMSM_idq0[2];     /* Mask Parameter: SurfaceMountPMSM_idq0
                                        * Referenced by:
                                        *   '<S221>/Constant'
                                        *   '<S222>/Constant'
                                        */
  real_T SurfaceMountPMSM_lambda_pm_calc;
                              /* Mask Parameter: SurfaceMountPMSM_lambda_pm_calc
                               * Referenced by:
                               *   '<S217>/Gain1'
                               *   '<S228>/Constant'
                               */
  real_T SurfaceMountPMSM_mechanical[3];
                                  /* Mask Parameter: SurfaceMountPMSM_mechanical
                                   * Referenced by:
                                   *   '<S203>/Constant'
                                   *   '<S203>/Constant2'
                                   *   '<S203>/Constant4'
                                   */
  real_T SurfaceMountPMSM_omega_init;
                                  /* Mask Parameter: SurfaceMountPMSM_omega_init
                                   * Referenced by: '<S203>/Discrete-Time Integrator'
                                   */
  real_T SurfaceMountPMSM_theta_init;
                                  /* Mask Parameter: SurfaceMountPMSM_theta_init
                                   * Referenced by: '<S206>/Unit Delay'
                                   */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T PWM_Y0;                       /* Computed Parameter: PWM_Y0
                                        * Referenced by: '<S3>/PWM'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S52>/Constant1'
                                        */
  real_T Constant1_Value_p;            /* Expression: 0
                                        * Referenced by: '<S104>/Constant1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 0
                                        * Referenced by: '<S156>/Constant1'
                                        */
  real_T Constant_Value_h;             /* Expression: 0
                                        * Referenced by: '<S194>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 10
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant6'
                                        */
  real_T Constant1_Value_d;            /* Expression: 6
                                        * Referenced by: '<S11>/Constant1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S166>/Integrator'
                                        */
  real_T one_by_3_Gain;                /* Expression: 1/3
                                        * Referenced by: '<S24>/one_by_3'
                                        */
  real_T one_by_sqrt3_Gain;            /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S24>/one_by_sqrt3_'
                                        */
  real_T Kalphabeta0_Gain[3];          /* Expression: [1 1 1]
                                        * Referenced by: '<S24>/Kalphabeta0'
                                        */
  real_T sine_table_values_Value[1002];/* Expression: dlgSett.sin_table
                                        * Referenced by: '<S23>/sine_table_values'
                                        */
  real_T convert_pu_Gain;              /* Expression: 1/(dlgSett.UpperSatLimit)
                                        * Referenced by: '<S193>/convert_pu'
                                        */
  real_T indexing_Gain;                /* Expression: dlgSett.index_gain
                                        * Referenced by: '<S23>/indexing'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<S11>/Constant5'
                                        */
  real_T Constant7_Value;              /* Expression: 0.89
                                        * Referenced by: '<S11>/Constant7'
                                        */
  real_T Integrator_gainval_e;       /* Computed Parameter: Integrator_gainval_e
                                      * Referenced by: '<S114>/Integrator'
                                      */
  real_T Integrator_gainval_p;       /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S62>/Integrator'
                                      */
  real_T Ka_Gain;                      /* Expression: 1
                                        * Referenced by: '<S189>/Ka'
                                        */
  real_T one_by_two_Gain;              /* Expression: 1/2
                                        * Referenced by: '<S189>/one_by_two'
                                        */
  real_T sqrt3_by_two_Gain;            /* Expression: sqrt(3)/2
                                        * Referenced by: '<S189>/sqrt3_by_two'
                                        */
  real_T Kb_Gain;                      /* Expression: 1
                                        * Referenced by: '<S189>/Kb'
                                        */
  real_T Kc_Gain;                      /* Expression: 1
                                        * Referenced by: '<S189>/Kc'
                                        */
  real_T one_by_two_Gain_h;            /* Expression: -0.5
                                        * Referenced by: '<S186>/one_by_two'
                                        */
  real_T Gain_Gain;                    /* Expression: 2/sqrt(3)
                                        * Referenced by: '<S185>/Gain'
                                        */
  real_T Gain_Gain_d;                  /* Expression: 1
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Constant9_Value;              /* Expression: 0.5
                                        * Referenced by: '<S11>/Constant9'
                                        */
  real_T Constant3_Value;              /* Expression: 0.0065
                                        * Referenced by: '<S11>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: 0.01
                                        * Referenced by: '<S11>/Constant8'
                                        */
  real_T Clamping_zero_Value;          /* Expression: 0
                                        * Referenced by: '<S52>/Clamping_zero'
                                        */
  real_T Clamping_zero_Value_b;        /* Expression: 0
                                        * Referenced by: '<S104>/Clamping_zero'
                                        */
  real_T Clamping_zero_Value_bd;       /* Expression: 0
                                        * Referenced by: '<S156>/Clamping_zero'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: 1
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S1>/Saturation2'
                                        */
  real_T Gain_Gain_d0;                 /* Expression: 1/3
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Constant2_Value;              /* Expression: 110
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S1>/Switch'
                                        */
  real_T Constant_Value_ht[2];         /* Expression: Ldq
                                        * Referenced by: '<S220>/Constant'
                                        */
  real_T Constant_Value_e[2];          /* Expression: Ldq
                                        * Referenced by: '<S223>/Constant'
                                        */
  real_T Constant_Value_o[2];          /* Expression: Ldq
                                        * Referenced by: '<S224>/Constant'
                                        */
  real_T Constant1_Value_e[2];         /* Expression: Ldq
                                        * Referenced by: '<S225>/Constant1'
                                        */
  real_T Constant_Value_d[2];          /* Expression: Ldq
                                        * Referenced by: '<S226>/Constant'
                                        */
  real_T Constant_Value_f[2];          /* Expression: Ldq
                                        * Referenced by: '<S227>/Constant'
                                        */
  real_T Constant1_Value_a[2];         /* Expression: Ldq
                                        * Referenced by: '<S228>/Constant1'
                                        */
  real_T Constant1_Value_j[2];         /* Expression: Ldq
                                        * Referenced by: '<S229>/Constant1'
                                        */
  real_T Constant2_Value_m;            /* Expression: 2
                                        * Referenced by: '<S229>/Constant2'
                                        */
  real_T Constant1_Value_m;            /* Expression: 2
                                        * Referenced by: '<S222>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                           * Referenced by: '<S222>/Discrete-Time Integrator3'
                           */
  real_T DiscreteTimeIntegrator3_UpperSa;/* Expression: 10e6
                                          * Referenced by: '<S222>/Discrete-Time Integrator3'
                                          */
  real_T DiscreteTimeIntegrator3_LowerSa;/* Expression: -10e6
                                          * Referenced by: '<S222>/Discrete-Time Integrator3'
                                          */
  real_T Gain_Gain_g;                  /* Expression: 2/3
                                        * Referenced by: '<S214>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1/3
                                        * Referenced by: '<S214>/Gain1'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1/3
                                        * Referenced by: '<S214>/Gain4'
                                        */
  real_T Gain2_Gain;                   /* Expression: sqrt(3)/3
                                        * Referenced by: '<S214>/Gain2'
                                        */
  real_T Gain3_Gain_m;                 /* Expression: -sqrt(3)/3
                                        * Referenced by: '<S214>/Gain3'
                                        */
  real_T Constant1_Value_l;            /* Expression: 2
                                        * Referenced by: '<S226>/Constant1'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S221>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator3_gainv_h;
                          /* Computed Parameter: DiscreteTimeIntegrator3_gainv_h
                           * Referenced by: '<S221>/Discrete-Time Integrator3'
                           */
  real_T DiscreteTimeIntegrator3_Upper_n;/* Expression: 10e6
                                          * Referenced by: '<S221>/Discrete-Time Integrator3'
                                          */
  real_T DiscreteTimeIntegrator3_Lower_o;/* Expression: -10e6
                                          * Referenced by: '<S221>/Discrete-Time Integrator3'
                                          */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S203>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_UpperSat;/* Expression: 10e6
                                          * Referenced by: '<S203>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_LowerSat;/* Expression: -10e6
                                          * Referenced by: '<S203>/Discrete-Time Integrator'
                                          */
  real_T Constant1_Value_h0;           /* Expression: 1
                                        * Referenced by: '<S227>/Constant1'
                                        */
  real_T Constant2_Value_e;            /* Expression: 2
                                        * Referenced by: '<S227>/Constant2'
                                        */
  real_T Constant2_Value_l;            /* Expression: 2
                                        * Referenced by: '<S228>/Constant2'
                                        */
  real_T Constant1_Value_c;            /* Expression: 2
                                        * Referenced by: '<S224>/Constant1'
                                        */
  real_T Constant2_Value_f;            /* Expression: 1
                                        * Referenced by: '<S224>/Constant2'
                                        */
  real_T Constant1_Value_f;            /* Expression: 1
                                        * Referenced by: '<S223>/Constant1'
                                        */
  real_T Constant2_Value_p;            /* Expression: 1
                                        * Referenced by: '<S225>/Constant2'
                                        */
  real_T Constant5_Value_l;            /* Expression: 2
                                        * Referenced by: '<S203>/Constant5'
                                        */
  real_T Constant1_Value_la;           /* Expression: 0.01
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant1_Value_km;           /* Expression: 1
                                        * Referenced by: '<S220>/Constant1'
                                        */
  real_T Constant2_Value_d;            /* Expression: 2
                                        * Referenced by: '<S220>/Constant2'
                                        */
  real_T Constant3_Value_e;            /* Expression: 3
                                        * Referenced by: '<S203>/Constant3'
                                        */
  real_T Constant1_Value_cb;           /* Expression: 1
                                        * Referenced by: '<S203>/Constant1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: -1/2
                                        * Referenced by: '<S215>/Gain1'
                                        */
  real_T Gain4_Gain_f;                 /* Expression: -sqrt(3)/2
                                        * Referenced by: '<S215>/Gain4'
                                        */
  real_T Gain3_Gain_j;                 /* Expression: sqrt(3)/2
                                        * Referenced by: '<S215>/Gain3'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: -1/2
                                        * Referenced by: '<S215>/Gain2'
                                        */
  real_T Constant_Value_k;             /* Expression: 2*pi
                                        * Referenced by: '<S209>/Constant'
                                        */
  real_T Constant3_Value_m;            /* Expression: 8000
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
  real32_T Constant3_Value_p;          /* Computed Parameter: Constant3_Value_p
                                        * Referenced by: '<S206>/Constant3'
                                        */
  real32_T Constant1_Value_fj;         /* Computed Parameter: Constant1_Value_fj
                                        * Referenced by: '<S206>/Constant1'
                                        */
  uint32_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S3>/Out2'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S23>/offset'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S26>/Offset'
                                        */
  uint16_T Switch_Threshold_d;         /* Computed Parameter: Switch_Threshold_d
                                        * Referenced by: '<S26>/Switch'
                                        */
  uint16_T Offset_Value_h;             /* Computed Parameter: Offset_Value_h
                                        * Referenced by: '<S191>/Offset'
                                        */
  uint16_T Switch_Threshold_l;         /* Computed Parameter: Switch_Threshold_l
                                        * Referenced by: '<S191>/Switch'
                                        */
  uint16_T Out3_Y0;                    /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S3>/Out3'
                                        */
  int8_T Constant_Value_la;            /* Computed Parameter: Constant_Value_la
                                        * Referenced by: '<S52>/Constant'
                                        */
  int8_T Constant2_Value_mk;           /* Computed Parameter: Constant2_Value_mk
                                        * Referenced by: '<S52>/Constant2'
                                        */
  int8_T Constant3_Value_d;            /* Computed Parameter: Constant3_Value_d
                                        * Referenced by: '<S52>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S52>/Constant4'
                                        */
  int8_T Constant_Value_a;             /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S104>/Constant'
                                        */
  int8_T Constant2_Value_j;            /* Computed Parameter: Constant2_Value_j
                                        * Referenced by: '<S104>/Constant2'
                                        */
  int8_T Constant3_Value_d5;           /* Computed Parameter: Constant3_Value_d5
                                        * Referenced by: '<S104>/Constant3'
                                        */
  int8_T Constant4_Value_g;            /* Computed Parameter: Constant4_Value_g
                                        * Referenced by: '<S104>/Constant4'
                                        */
  int8_T Constant_Value_j;             /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S156>/Constant'
                                        */
  int8_T Constant2_Value_b;            /* Computed Parameter: Constant2_Value_b
                                        * Referenced by: '<S156>/Constant2'
                                        */
  int8_T Constant3_Value_l;            /* Computed Parameter: Constant3_Value_l
                                        * Referenced by: '<S156>/Constant3'
                                        */
  int8_T Constant4_Value_o;            /* Computed Parameter: Constant4_Value_o
                                        * Referenced by: '<S156>/Constant4'
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
    uint32_T clockTick2;
    struct {
      uint16_T TID[2];
    } TaskCounters;

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

/* External function called from main */
extern void GOPIO_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void GOPIO_initialize(void);
extern void GOPIO_step0(void);
extern void GOPIO_step1(void);
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
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S14>/FixPt Constant' : Unused code path elimination
 * Block '<S14>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S14>/FixPt Sum1' : Unused code path elimination
 * Block '<S10>/Output' : Unused code path elimination
 * Block '<S15>/Constant' : Unused code path elimination
 * Block '<S15>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S15>/FixPt Switch' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Vc' : Unused code path elimination
 * Block '<S189>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate' : Unused code path elimination
 * Block '<S190>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Propagation' : Unused code path elimination
 * Block '<S195>/Data Type Duplicate' : Unused code path elimination
 * Block '<S196>/Data Type Duplicate' : Unused code path elimination
 * Block '<S203>/Abs' : Unused code path elimination
 * Block '<S203>/Add' : Unused code path elimination
 * Block '<S203>/Product3' : Unused code path elimination
 * Block '<S203>/Product4' : Unused code path elimination
 * Block '<S204>/Add' : Unused code path elimination
 * Block '<S204>/Add2' : Unused code path elimination
 * Block '<S204>/Add4' : Unused code path elimination
 * Block '<S204>/Constant' : Unused code path elimination
 * Block '<S204>/Gain' : Unused code path elimination
 * Block '<S204>/Gain1' : Unused code path elimination
 * Block '<S204>/Gain2' : Unused code path elimination
 * Block '<S204>/Product' : Unused code path elimination
 * Block '<S204>/Product1' : Unused code path elimination
 * Block '<S204>/Product11' : Unused code path elimination
 * Block '<S204>/Product12' : Unused code path elimination
 * Block '<S204>/Product2' : Unused code path elimination
 * Block '<S204>/Product3' : Unused code path elimination
 * Block '<S204>/Product4' : Unused code path elimination
 * Block '<S23>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<Root>/Rate Transition1' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition2' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition3' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition4' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition5' : Eliminated since input and output rates are identical
 * Block '<Root>/Rate Transition6' : Eliminated since input and output rates are identical
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
 * '<S1>'   : 'GOPIO/Average-Value Inverter'
 * '<S2>'   : 'GOPIO/Digital Port Write'
 * '<S3>'   : 'GOPIO/Function-Call Subsystem'
 * '<S4>'   : 'GOPIO/Hardware Interrupt'
 * '<S5>'   : 'GOPIO/PWM Output'
 * '<S6>'   : 'GOPIO/Surface Mount PMSM'
 * '<S7>'   : 'GOPIO/Digital Port Write/ECSoC'
 * '<S8>'   : 'GOPIO/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S9>'   : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter'
 * '<S10>'  : 'GOPIO/Function-Call Subsystem/Counter Limited'
 * '<S11>'  : 'GOPIO/Function-Call Subsystem/Subsystem1'
 * '<S12>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S13>'  : 'GOPIO/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S14>'  : 'GOPIO/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S15>'  : 'GOPIO/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S16>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/Clarke Transform'
 * '<S17>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/Inverse Park Transform1'
 * '<S18>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller'
 * '<S19>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1'
 * '<S20>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2'
 * '<S21>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PWM Reference Generator1'
 * '<S22>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/Park Transform1'
 * '<S23>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/Sine-Cosine Lookup'
 * '<S24>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/Clarke Transform/Three phase input'
 * '<S25>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/Inverse Park Transform1/Two inputs CRL'
 * '<S26>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/Inverse Park Transform1/Two inputs CRL/Switch_Axis'
 * '<S27>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Anti-windup'
 * '<S28>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/D Gain'
 * '<S29>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/External Derivative'
 * '<S30>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Filter'
 * '<S31>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Filter ICs'
 * '<S32>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/I Gain'
 * '<S33>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Ideal P Gain'
 * '<S34>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Ideal P Gain Fdbk'
 * '<S35>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Integrator'
 * '<S36>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Integrator ICs'
 * '<S37>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/N Copy'
 * '<S38>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/N Gain'
 * '<S39>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/P Copy'
 * '<S40>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Parallel P Gain'
 * '<S41>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Reset Signal'
 * '<S42>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Saturation'
 * '<S43>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Saturation Fdbk'
 * '<S44>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Sum'
 * '<S45>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Sum Fdbk'
 * '<S46>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Tracking Mode'
 * '<S47>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Tracking Mode Sum'
 * '<S48>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Tsamp - Integral'
 * '<S49>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Tsamp - Ngain'
 * '<S50>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/postSat Signal'
 * '<S51>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/preSat Signal'
 * '<S52>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S53>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S54>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S55>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/D Gain/Disabled'
 * '<S56>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/External Derivative/Disabled'
 * '<S57>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Filter/Disabled'
 * '<S58>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Filter ICs/Disabled'
 * '<S59>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/I Gain/External Parameters'
 * '<S60>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Ideal P Gain/Passthrough'
 * '<S61>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Ideal P Gain Fdbk/Disabled'
 * '<S62>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Integrator/Discrete'
 * '<S63>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Integrator ICs/Internal IC'
 * '<S64>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/N Copy/Disabled wSignal Specification'
 * '<S65>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/N Gain/Disabled'
 * '<S66>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/P Copy/Disabled'
 * '<S67>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Parallel P Gain/External Parameters'
 * '<S68>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Reset Signal/Disabled'
 * '<S69>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Saturation/Enabled'
 * '<S70>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Saturation Fdbk/Disabled'
 * '<S71>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Sum/Sum_PI'
 * '<S72>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Sum Fdbk/Disabled'
 * '<S73>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Tracking Mode/Disabled'
 * '<S74>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Tracking Mode Sum/Passthrough'
 * '<S75>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S76>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/Tsamp - Ngain/Passthrough'
 * '<S77>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/postSat Signal/Forward_Path'
 * '<S78>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller/preSat Signal/Forward_Path'
 * '<S79>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Anti-windup'
 * '<S80>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/D Gain'
 * '<S81>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/External Derivative'
 * '<S82>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Filter'
 * '<S83>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Filter ICs'
 * '<S84>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/I Gain'
 * '<S85>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Ideal P Gain'
 * '<S86>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Ideal P Gain Fdbk'
 * '<S87>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Integrator'
 * '<S88>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Integrator ICs'
 * '<S89>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/N Copy'
 * '<S90>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/N Gain'
 * '<S91>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/P Copy'
 * '<S92>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Parallel P Gain'
 * '<S93>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Reset Signal'
 * '<S94>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Saturation'
 * '<S95>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Saturation Fdbk'
 * '<S96>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Sum'
 * '<S97>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Sum Fdbk'
 * '<S98>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Tracking Mode'
 * '<S99>'  : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Tracking Mode Sum'
 * '<S100>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Tsamp - Integral'
 * '<S101>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Tsamp - Ngain'
 * '<S102>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/postSat Signal'
 * '<S103>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/preSat Signal'
 * '<S104>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Anti-windup/Disc. Clamping Parallel'
 * '<S105>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S106>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S107>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/D Gain/Disabled'
 * '<S108>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/External Derivative/Disabled'
 * '<S109>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Filter/Disabled'
 * '<S110>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Filter ICs/Disabled'
 * '<S111>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/I Gain/External Parameters'
 * '<S112>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Ideal P Gain/Passthrough'
 * '<S113>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Ideal P Gain Fdbk/Disabled'
 * '<S114>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Integrator/Discrete'
 * '<S115>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Integrator ICs/Internal IC'
 * '<S116>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/N Copy/Disabled wSignal Specification'
 * '<S117>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/N Gain/Disabled'
 * '<S118>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/P Copy/Disabled'
 * '<S119>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Parallel P Gain/External Parameters'
 * '<S120>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Reset Signal/Disabled'
 * '<S121>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Saturation/Enabled'
 * '<S122>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Saturation Fdbk/Disabled'
 * '<S123>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Sum/Sum_PI'
 * '<S124>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Sum Fdbk/Disabled'
 * '<S125>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Tracking Mode/Disabled'
 * '<S126>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Tracking Mode Sum/Passthrough'
 * '<S127>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Tsamp - Integral/TsSignalSpecification'
 * '<S128>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/Tsamp - Ngain/Passthrough'
 * '<S129>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/postSat Signal/Forward_Path'
 * '<S130>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller1/preSat Signal/Forward_Path'
 * '<S131>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Anti-windup'
 * '<S132>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/D Gain'
 * '<S133>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/External Derivative'
 * '<S134>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Filter'
 * '<S135>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Filter ICs'
 * '<S136>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/I Gain'
 * '<S137>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Ideal P Gain'
 * '<S138>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Ideal P Gain Fdbk'
 * '<S139>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Integrator'
 * '<S140>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Integrator ICs'
 * '<S141>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/N Copy'
 * '<S142>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/N Gain'
 * '<S143>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/P Copy'
 * '<S144>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Parallel P Gain'
 * '<S145>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Reset Signal'
 * '<S146>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Saturation'
 * '<S147>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Saturation Fdbk'
 * '<S148>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Sum'
 * '<S149>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Sum Fdbk'
 * '<S150>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Tracking Mode'
 * '<S151>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Tracking Mode Sum'
 * '<S152>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Tsamp - Integral'
 * '<S153>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Tsamp - Ngain'
 * '<S154>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/postSat Signal'
 * '<S155>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/preSat Signal'
 * '<S156>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Anti-windup/Disc. Clamping Parallel'
 * '<S157>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S158>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S159>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/D Gain/Disabled'
 * '<S160>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/External Derivative/Disabled'
 * '<S161>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Filter/Disabled'
 * '<S162>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Filter ICs/Disabled'
 * '<S163>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/I Gain/External Parameters'
 * '<S164>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Ideal P Gain/Passthrough'
 * '<S165>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Ideal P Gain Fdbk/Disabled'
 * '<S166>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Integrator/Discrete'
 * '<S167>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Integrator ICs/Internal IC'
 * '<S168>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/N Copy/Disabled wSignal Specification'
 * '<S169>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/N Gain/Disabled'
 * '<S170>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/P Copy/Disabled'
 * '<S171>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Parallel P Gain/External Parameters'
 * '<S172>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Reset Signal/Disabled'
 * '<S173>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Saturation/Enabled'
 * '<S174>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Saturation Fdbk/Disabled'
 * '<S175>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Sum/Sum_PI'
 * '<S176>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Sum Fdbk/Disabled'
 * '<S177>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Tracking Mode/Disabled'
 * '<S178>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Tracking Mode Sum/Passthrough'
 * '<S179>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Tsamp - Integral/TsSignalSpecification'
 * '<S180>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/Tsamp - Ngain/Passthrough'
 * '<S181>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/postSat Signal/Forward_Path'
 * '<S182>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PI Controller2/preSat Signal/Forward_Path'
 * '<S183>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PWM Reference Generator1/Modulation method'
 * '<S184>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PWM Reference Generator1/Voltage Input'
 * '<S185>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PWM Reference Generator1/Modulation method/SVPWM'
 * '<S186>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PWM Reference Generator1/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S187>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PWM Reference Generator1/Voltage Input/Valphabeta'
 * '<S188>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PWM Reference Generator1/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S189>' : 'GOPIO/Function-Call Subsystem/Subsystem1/PWM Reference Generator1/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S190>' : 'GOPIO/Function-Call Subsystem/Subsystem1/Park Transform1/Two inputs CRL'
 * '<S191>' : 'GOPIO/Function-Call Subsystem/Subsystem1/Park Transform1/Two inputs CRL/Switch_Axis'
 * '<S192>' : 'GOPIO/Function-Call Subsystem/Subsystem1/Sine-Cosine Lookup/Interpolation'
 * '<S193>' : 'GOPIO/Function-Call Subsystem/Subsystem1/Sine-Cosine Lookup/WrapUp'
 * '<S194>' : 'GOPIO/Function-Call Subsystem/Subsystem1/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S195>' : 'GOPIO/Function-Call Subsystem/Subsystem1/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S196>' : 'GOPIO/Function-Call Subsystem/Subsystem1/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S197>' : 'GOPIO/Hardware Interrupt/ECSoC'
 * '<S198>' : 'GOPIO/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S199>' : 'GOPIO/PWM Output/ECSoC'
 * '<S200>' : 'GOPIO/PWM Output/ECSoC/ECSimCodegen'
 * '<S201>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete'
 * '<S202>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete'
 * '<S203>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle'
 * '<S204>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1'
 * '<S205>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic'
 * '<S206>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1'
 * '<S207>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Compare To Constant'
 * '<S208>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Mechanical and Angle/Int1/Compare To Constant1'
 * '<S209>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/MechToElect'
 * '<S210>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator'
 * '<S211>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrNotTrnsfrd Input'
 * '<S212>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrStored Input'
 * '<S213>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/Motor Units1/Power Accounting Bus Creator/PwrTrnsfrd Input'
 * '<S214>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Clarke Transform'
 * '<S215>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Clarke Transform'
 * '<S216>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Inverse Park Transform'
 * '<S217>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque'
 * '<S218>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit'
 * '<S219>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Park Transform'
 * '<S220>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/Machine Torque/Subsystem'
 * '<S221>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage'
 * '<S222>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage'
 * '<S223>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem'
 * '<S224>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem1'
 * '<S225>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/D Axis Stator Voltage/Subsystem2'
 * '<S226>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem'
 * '<S227>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem1'
 * '<S228>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem2'
 * '<S229>' : 'GOPIO/Surface Mount PMSM/PMSM Torque Input Exterior Discrete/PMSM Torque Input Core Discrete/PMSM Electromagnetic/PMSM Equivalent Circuit/Q Axis Stator Voltage/Subsystem3'
 */
#endif                                 /* GOPIO_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
