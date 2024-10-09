/*
 * File: STMF4Hall.h
 *
 * Code generated for Simulink model 'STMF4Hall'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct  8 14:53:15 2024
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

/* Block states (default storage) for system '<S68>/If Action Subsystem6' */
typedef struct {
  int8_T IfActionSubsystem6_SubsysRanBC;/* '<S68>/If Action Subsystem6' */
} DW_IfActionSubsystem6_STMF4Ha_T;

/* Block states (default storage) for system '<S68>/If Action Subsystem' */
typedef struct {
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S68>/If Action Subsystem' */
} DW_IfActionSubsystem_STMF4Hal_T;

/* Block signals for system '<S66>/Valid Halls' */
typedef struct {
  uint16_T Merge;                      /* '<S68>/Merge' */
  uint16_T Merge1;                     /* '<S68>/Merge1' */
  uint16_T Merge3;                     /* '<S68>/Merge3' */
  int16_T Merge2;                      /* '<S68>/Merge2' */
} B_ValidHalls_STMF4Hall_T;

/* Block states (default storage) for system '<S66>/Valid Halls' */
typedef struct {
  int8_T ValidHalls_SubsysRanBC;       /* '<S66>/Valid Halls' */
  int8_T SwitchCaseActionSubsystem_Subsy;
                                      /* '<S68>/Switch Case Action Subsystem' */
  int8_T IfActionSubsystem8_SubsysRanBC;/* '<S68>/If Action Subsystem8' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem5;/* '<S68>/If Action Subsystem5' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem4;/* '<S68>/If Action Subsystem4' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem3;/* '<S68>/If Action Subsystem3' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem2;/* '<S68>/If Action Subsystem2' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem1;/* '<S68>/If Action Subsystem1' */
  DW_IfActionSubsystem_STMF4Hal_T IfActionSubsystem;/* '<S68>/If Action Subsystem' */
  DW_IfActionSubsystem6_STMF4Ha_T IfActionSubsystem7;/* '<S68>/If Action Subsystem7' */
  DW_IfActionSubsystem6_STMF4Ha_T IfActionSubsystem6;/* '<S68>/If Action Subsystem6' */
} DW_ValidHalls_STMF4Hall_T;

/* Block states (default storage) for system '<S66>/Bad hall (glitch or wrong connection)' */
typedef struct {
  int8_T Badhallglitchorwrongconnection_;
                             /* '<S66>/Bad hall (glitch or wrong connection)' */
} DW_Badhallglitchorwrongconnec_T;

/* Block signals (default storage) */
typedef struct {
  real_T MultiportSwitch[2];           /* '<S10>/Multiport Switch' */
  real_T OutportBufferForOut2;         /* '<S2>/Constant' */
  real_T OutportBufferForOut2_e;       /* '<S3>/Constant' */
  real_T OutportBufferForOut2_e2;      /* '<S4>/Constant' */
  uint32_T time3;                      /* '<Root>/Timer1' */
  uint32_T time3_g;                    /* '<Root>/Timer1' */
  uint32_T time3_gw;                   /* '<Root>/Timer1' */
  uint32_T time3_k;                    /* '<Root>/Timer1' */
  uint16_T testcounter;                /* '<Root>/RT6' */
  uint16_T Output;                     /* '<S89>/Output' */
  int16_T gethalltimer;                /* '<Root>/Multiport Switch' */
  int16_T Sum;                         /* '<S2>/Sum' */
  int16_T Sum_c;                       /* '<S3>/Sum' */
  int16_T Sum_i;                       /* '<S4>/Sum' */
  uint8_T Halls;                       /* '<Root>/Data Store Read' */
  B_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S16>/Valid Halls' */
  B_ValidHalls_STMF4Hall_T ValidHalls_l;/* '<S41>/Valid Halls' */
  B_ValidHalls_STMF4Hall_T ValidHalls; /* '<S66>/Valid Halls' */
} B_STMF4Hall_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S91>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_ST_T obj_f;/* '<S109>/PWM Output' */
  stm32cube_blocks_TimerBlock_S_T obj_b;/* '<Root>/Timer1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  volatile uint32_T TmpRTBAtFunctionCallSubsystem1I;/* synthesized block */
  volatile uint32_T TmpRTBAtFunctionCallSubsystem2I;/* synthesized block */
  volatile uint32_T time3_Buffer0;     /* synthesized block */
  uint32_T Timercntprev;               /* '<Root>/Data Store Memory3' */
  uint16_T Output_DSTATE;              /* '<S89>/Output' */
  int16_T Timehall;                    /* '<Root>/Data Store Memory2' */
  int16_T GlobalDirection;             /* '<Root>/Data Store Memory5' */
  uint16_T GlobalSpeedCount;           /* '<Root>/Data Store Memory6' */
  uint16_T GlobalSpeedValidity;        /* '<Root>/Data Store Memory7' */
  uint16_T HallStateChangeFlag;        /* '<Root>/Data Store Memory8' */
  int8_T FunctionCallSubsystem3_SubsysRa;/* '<Root>/Function-Call Subsystem3' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int8_T FunctionCallSubsystem1_SubsysRa;/* '<Root>/Function-Call Subsystem1' */
  int8_T FunctionCallSubsystem2_SubsysRa;/* '<Root>/Function-Call Subsystem2' */
  uint8_T GlobalHallState;             /* '<Root>/Data Store Memory' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_a;
                             /* '<S16>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S16>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnectio_c;
                             /* '<S41>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls_l;/* '<S41>/Valid Halls' */
  DW_Badhallglitchorwrongconnec_T Badhallglitchorwrongconnection;
                             /* '<S66>/Bad hall (glitch or wrong connection)' */
  DW_ValidHalls_STMF4Hall_T ValidHalls;/* '<S66>/Valid Halls' */
} DW_STMF4Hall_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T Hallstate;                    /* '<Root>/Hall state' */
  real_T Hallangle;                    /* '<Root>/Hall angle' */
} ExtY_STMF4Hall_T;

/* Parameters for system: '<S68>/If Action Subsystem6' */
struct P_IfActionSubsystem6_STMF4Hal_T_ {
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S75>/Constant'
                                        */
  uint16_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S75>/Constant1'
                                        */
};

/* Parameters for system: '<S68>/If Action Subsystem' */
struct P_IfActionSubsystem_STMF4Hall_T_ {
  uint16_T previous_Value;             /* Computed Parameter: previous_Value
                                        * Referenced by: '<S69>/previous'
                                        */
  uint16_T next_Value;                 /* Computed Parameter: next_Value
                                        * Referenced by: '<S69>/next'
                                        */
};

/* Parameters for system: '<S66>/Valid Halls' */
struct P_ValidHalls_STMF4Hall_T_ {
  int16_T Merge2_InitialOutput;      /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S68>/Merge2'
                                      */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S77>/Constant'
                                        */
  uint16_T Merge_InitialOutput;       /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S68>/Merge'
                                       */
  uint16_T Merge1_InitialOutput;     /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S68>/Merge1'
                                      */
  uint16_T Merge3_InitialOutput;     /* Computed Parameter: Merge3_InitialOutput
                                      * Referenced by: '<S68>/Merge3'
                                      */
  boolean_T Constant_Value_i;          /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S68>/Constant'
                                        */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem5;/* '<S68>/If Action Subsystem5' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem4;/* '<S68>/If Action Subsystem4' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem3;/* '<S68>/If Action Subsystem3' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem2;/* '<S68>/If Action Subsystem2' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem1;/* '<S68>/If Action Subsystem1' */
  P_IfActionSubsystem_STMF4Hall_T IfActionSubsystem;/* '<S68>/If Action Subsystem' */
  P_IfActionSubsystem6_STMF4Hal_T IfActionSubsystem7;/* '<S68>/If Action Subsystem7' */
  P_IfActionSubsystem6_STMF4Hal_T IfActionSubsystem6;/* '<S68>/If Action Subsystem6' */
};

/* Parameters for system: '<S66>/Bad hall (glitch or wrong connection)' */
struct P_Badhallglitchorwrongconnect_T_ {
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S67>/Constant'
                                        */
  boolean_T Constant1_Value;           /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S67>/Constant1'
                                        */
};

/* Parameters (default storage) */
struct P_STMF4Hall_T_ {
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S93>/FixPt Switch'
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
  real_T Pos_PU_Y0;                    /* Expression: 0
                                        * Referenced by: '<S5>/Pos_PU'
                                        */
  real_T Constant1_Value;              /* Expression: 2
                                        * Referenced by: '<S10>/Constant1'
                                        */
  real_T Constant8_Value;              /* Expression: 60
                                        * Referenced by: '<S10>/Constant8'
                                        */
  real_T Constant2_Value;              /* Expression: 4
                                        * Referenced by: '<S10>/Constant2'
                                        */
  real_T Constant9_Value;              /* Expression: 180
                                        * Referenced by: '<S10>/Constant9'
                                        */
  real_T Constant3_Value;              /* Expression: 3
                                        * Referenced by: '<S10>/Constant3'
                                        */
  real_T Constant10_Value;             /* Expression: 120
                                        * Referenced by: '<S10>/Constant10'
                                        */
  real_T Constant4_Value;              /* Expression: 6
                                        * Referenced by: '<S10>/Constant4'
                                        */
  real_T Constant11_Value;             /* Expression: 300
                                        * Referenced by: '<S10>/Constant11'
                                        */
  real_T Constant5_Value;              /* Expression: 1
                                        * Referenced by: '<S10>/Constant5'
                                        */
  real_T Constant6_Value;              /* Expression: 5
                                        * Referenced by: '<S10>/Constant6'
                                        */
  real_T Constant14_Value;             /* Expression: 240
                                        * Referenced by: '<S10>/Constant14'
                                        */
  real_T Constant7_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/Constant7'
                                        */
  real_T DataStoreMemory1_InitialValue;/* Expression: 0
                                        * Referenced by: '<Root>/Data Store Memory1'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S10>/Constant12'
                                        */
  real_T Constant_Value_b;             /* Expression: 20
                                        * Referenced by: '<Root>/Constant'
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
  uint32_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  int16_T Out1_Y0;                     /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S4>/Out1'
                                        */
  int16_T Out1_Y0_h;                   /* Computed Parameter: Out1_Y0_h
                                        * Referenced by: '<S3>/Out1'
                                        */
  int16_T Out1_Y0_l;                   /* Computed Parameter: Out1_Y0_l
                                        * Referenced by: '<S2>/Out1'
                                        */
  int16_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  int16_T DataStoreMemory5_InitialValue;
                            /* Computed Parameter: DataStoreMemory5_InitialValue
                             * Referenced by: '<Root>/Data Store Memory5'
                             */
  uint16_T Constant_Value_fm;          /* Computed Parameter: Constant_Value_fm
                                        * Referenced by: '<S63>/Constant'
                                        */
  uint16_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S38>/Constant'
                                        */
  uint16_T Constant_Value_bh;          /* Computed Parameter: Constant_Value_bh
                                        * Referenced by: '<S13>/Constant'
                                        */
  uint16_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S93>/Constant'
                                        */
  uint16_T Out1_Y0_hj;                 /* Computed Parameter: Out1_Y0_hj
                                        * Referenced by: '<S5>/Out1'
                                        */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S92>/FixPt Constant'
                                       */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S89>/Output'
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
  uint8_T Gain_Gain;                   /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S64>/Gain'
                                        */
  uint8_T Gain_Gain_n;                 /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S39>/Gain'
                                        */
  uint8_T Gain_Gain_a;                 /* Computed Parameter: Gain_Gain_a
                                        * Referenced by: '<S14>/Gain'
                                        */
  uint8_T Gain_Gain_m;                 /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S98>/Gain'
                                        */
  uint8_T Gain1_Gain;                  /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S64>/Gain1'
                                        */
  uint8_T Gain1_Gain_l;                /* Computed Parameter: Gain1_Gain_l
                                        * Referenced by: '<S39>/Gain1'
                                        */
  uint8_T Gain1_Gain_i;                /* Computed Parameter: Gain1_Gain_i
                                        * Referenced by: '<S14>/Gain1'
                                        */
  uint8_T Gain1_Gain_p;                /* Computed Parameter: Gain1_Gain_p
                                        * Referenced by: '<S98>/Gain1'
                                        */
  uint8_T Gain2_Gain;                  /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S64>/Gain2'
                                        */
  uint8_T Gain2_Gain_d;                /* Computed Parameter: Gain2_Gain_d
                                        * Referenced by: '<S39>/Gain2'
                                        */
  uint8_T Gain2_Gain_f;                /* Computed Parameter: Gain2_Gain_f
                                        * Referenced by: '<S14>/Gain2'
                                        */
  uint8_T Gain2_Gain_n;                /* Computed Parameter: Gain2_Gain_n
                                        * Referenced by: '<S98>/Gain2'
                                        */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_a;
                             /* '<S16>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls_d;/* '<S16>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnectio_c;
                             /* '<S41>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls_l;/* '<S41>/Valid Halls' */
  P_Badhallglitchorwrongconnect_T Badhallglitchorwrongconnection;
                             /* '<S66>/Bad hall (glitch or wrong connection)' */
  P_ValidHalls_STMF4Hall_T ValidHalls; /* '<S66>/Valid Halls' */
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
 * Block '<S89>/Data Type Propagation' : Unused code path elimination
 * Block '<S92>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S13>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S38>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S63>/Data Type Conversion' : Eliminate redundant data type conversion
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
 * '<S5>'   : 'STMF4Hall/Function-Call Subsystem3'
 * '<S6>'   : 'STMF4Hall/Hardware Interrupt'
 * '<S7>'   : 'STMF4Hall/Hardware Interrupt1'
 * '<S8>'   : 'STMF4Hall/Initialize Function'
 * '<S9>'   : 'STMF4Hall/PWM Output'
 * '<S10>'  : 'STMF4Hall/Subsystem'
 * '<S11>'  : 'STMF4Hall/Digital Port Write/ECSoC'
 * '<S12>'  : 'STMF4Hall/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S13>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity'
 * '<S14>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation'
 * '<S15>'  : 'STMF4Hall/Function-Call Subsystem/Subsystem'
 * '<S16>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem'
 * '<S17>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S18>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls'
 * '<S19>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S20>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S21>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S22>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S23>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S24>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S25>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S26>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S27>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S28>'  : 'STMF4Hall/Function-Call Subsystem/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S29>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read'
 * '<S30>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read1'
 * '<S31>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read2'
 * '<S32>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read/ECSoC'
 * '<S33>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S34>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read1/ECSoC'
 * '<S35>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S36>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read2/ECSoC'
 * '<S37>'  : 'STMF4Hall/Function-Call Subsystem/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S38>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity'
 * '<S39>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation'
 * '<S40>'  : 'STMF4Hall/Function-Call Subsystem1/Subsystem'
 * '<S41>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem'
 * '<S42>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S43>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls'
 * '<S44>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S45>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S46>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S47>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S48>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S49>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S50>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S51>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S52>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S53>'  : 'STMF4Hall/Function-Call Subsystem1/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S54>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read'
 * '<S55>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read1'
 * '<S56>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read2'
 * '<S57>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read/ECSoC'
 * '<S58>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S59>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read1/ECSoC'
 * '<S60>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S61>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read2/ECSoC'
 * '<S62>'  : 'STMF4Hall/Function-Call Subsystem1/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S63>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity'
 * '<S64>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation'
 * '<S65>'  : 'STMF4Hall/Function-Call Subsystem2/Subsystem'
 * '<S66>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem'
 * '<S67>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Bad hall (glitch or wrong connection)'
 * '<S68>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls'
 * '<S69>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem'
 * '<S70>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem1'
 * '<S71>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem2'
 * '<S72>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem3'
 * '<S73>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem4'
 * '<S74>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem5'
 * '<S75>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem6'
 * '<S76>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem7'
 * '<S77>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/If Action Subsystem8'
 * '<S78>'  : 'STMF4Hall/Function-Call Subsystem2/Hall Validity/Subsystem/Valid Halls/Switch Case Action Subsystem'
 * '<S79>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read'
 * '<S80>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read1'
 * '<S81>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read2'
 * '<S82>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read/ECSoC'
 * '<S83>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S84>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read1/ECSoC'
 * '<S85>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S86>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read2/ECSoC'
 * '<S87>'  : 'STMF4Hall/Function-Call Subsystem2/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S88>'  : 'STMF4Hall/Function-Call Subsystem3/Analog to Digital Converter'
 * '<S89>'  : 'STMF4Hall/Function-Call Subsystem3/Counter Limited'
 * '<S90>'  : 'STMF4Hall/Function-Call Subsystem3/Analog to Digital Converter/ECSoC'
 * '<S91>'  : 'STMF4Hall/Function-Call Subsystem3/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S92>'  : 'STMF4Hall/Function-Call Subsystem3/Counter Limited/Increment Real World'
 * '<S93>'  : 'STMF4Hall/Function-Call Subsystem3/Counter Limited/Wrap To Zero'
 * '<S94>'  : 'STMF4Hall/Hardware Interrupt/ECSoC'
 * '<S95>'  : 'STMF4Hall/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S96>'  : 'STMF4Hall/Hardware Interrupt1/ECSoC'
 * '<S97>'  : 'STMF4Hall/Hardware Interrupt1/ECSoC/ECSimCodegen'
 * '<S98>'  : 'STMF4Hall/Initialize Function/Hallstation'
 * '<S99>'  : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read'
 * '<S100>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1'
 * '<S101>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2'
 * '<S102>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read/ECSoC'
 * '<S103>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S104>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1/ECSoC'
 * '<S105>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read1/ECSoC/ECSimCodegen'
 * '<S106>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2/ECSoC'
 * '<S107>' : 'STMF4Hall/Initialize Function/Hallstation/Digital Port Read2/ECSoC/ECSimCodegen'
 * '<S108>' : 'STMF4Hall/PWM Output/ECSoC'
 * '<S109>' : 'STMF4Hall/PWM Output/ECSoC/ECSimCodegen'
 */
#endif                                 /* STMF4Hall_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
