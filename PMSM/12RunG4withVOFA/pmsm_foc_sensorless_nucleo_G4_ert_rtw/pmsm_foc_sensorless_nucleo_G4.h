/*
 * File: pmsm_foc_sensorless_nucleo_G4.h
 *
 * Code generated for Simulink model 'pmsm_foc_sensorless_nucleo_G4'.
 *
 * Model version                  : 8.13
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Nov 13 17:04:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef pmsm_foc_sensorless_nucleo_G4_h_
#define pmsm_foc_sensorless_nucleo_G4_h_
#ifndef pmsm_foc_sensorless_nucleo_G4_COMMON_INCLUDES_
#define pmsm_foc_sensorless_nucleo_G4_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#include "stm_lpuart.h"
#endif                      /* pmsm_foc_sensorless_nucleo_G4_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "pmsm_foc_sensorless_nucleo_G4_types.h"
#include "rtGetNaN.h"
#include <string.h>
#include <stddef.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define pmsm_foc_sensorless_nucleo_G4_M (pmsm_foc_sensorless_nucleo_G_M)

/* Block signals (default storage) */
typedef struct {
  real_T LED;                          /* '<S5>/Pulse Generator' */
  uint32_T cont;                       /* '<S15>/Merge2' */
  uint32_T Sum[4];                     /* '<S63>/Sum' */
  uint32_T PositionToCount;            /* '<S29>/PositionToCount' */
  uint32_T Delay;                      /* '<S29>/Delay' */
  uint32_T DataStoreRead;              /* '<S51>/Data Store Read' */
  uint32_T Add1;                       /* '<S51>/Add1' */
  real32_T RT_n;                       /* '<Root>/RT' */
  real32_T Assignment[3];              /* '<S6>/Assignment' */
  real32_T RT1[2];                     /* '<Root>/RT1' */
  real32_T Assignment1[3];             /* '<S6>/Assignment1' */
  real32_T Assignment2[3];             /* '<S6>/Assignment2' */
  real32_T ADvoltage[2];               /* '<S49>/AD voltage' */
  real32_T OP_GainR_shunt[2];          /* '<S49>/OP_Gain*R_shunt' */
  real32_T OP_GainR_shunt1[2];         /* '<S49>/OP_Gain*R_shunt1' */
  real32_T Kalpha;                     /* '<S65>/Kalpha' */
  real32_T Kbeta;                      /* '<S65>/Kbeta' */
  real32_T UnitDelay1;                 /* '<S34>/Unit Delay1' */
  real32_T UnitDelay;                  /* '<S34>/Unit Delay' */
  real32_T a;                          /* '<S34>/a' */
  real32_T Delay5[4];                  /* '<S2>/Delay5' */
  real32_T Delay_b;                    /* '<S24>/Delay' */
  real32_T Sum2;                       /* '<S24>/Sum2' */
  real32_T Sum3;                       /* '<S34>/Sum3' */
  real32_T b_invg;                     /* '<S34>/b_inv*g' */
  real32_T Delay1;                     /* '<S34>/Delay1' */
  real32_T Sum4;                       /* '<S34>/Sum4' */
  real32_T Switch1[2];                 /* '<S26>/Switch1' */
  real32_T Product;                    /* '<S38>/Product' */
  real32_T UnitDelay_e;                /* '<S38>/Unit Delay' */
  real32_T Product1;                   /* '<S38>/Product1' */
  real32_T Add1_o;                     /* '<S38>/Add1' */
  real32_T UnitDelay1_e;               /* '<S35>/Unit Delay1' */
  real32_T UnitDelay_c;                /* '<S35>/Unit Delay' */
  real32_T a_c;                        /* '<S35>/a' */
  real32_T Delay_f;                    /* '<S25>/Delay' */
  real32_T Sum2_e;                     /* '<S25>/Sum2' */
  real32_T Sum3_m;                     /* '<S35>/Sum3' */
  real32_T b_invg_d;                   /* '<S35>/b_inv*g' */
  real32_T Delay1_f;                   /* '<S35>/Delay1' */
  real32_T Sum4_d;                     /* '<S35>/Sum4' */
  real32_T Switch1_o[2];               /* '<S27>/Switch1' */
  real32_T Product_b;                  /* '<S41>/Product' */
  real32_T UnitDelay_m;                /* '<S41>/Unit Delay' */
  real32_T Product1_l;                 /* '<S41>/Product1' */
  real32_T Add1_p;                     /* '<S41>/Add1' */
  real32_T Merge;                      /* '<S23>/Merge' */
  real32_T Merge1;                     /* '<S23>/Merge1' */
  real32_T Delay_fn;                   /* '<S22>/Delay' */
  real32_T PhaseDelay;                 /* '<S22>/PhaseDelay' */
  real32_T AngleConversion;            /* '<S22>/AngleConversion' */
  real32_T Merge_a;                    /* '<S53>/Merge' */
  real32_T scaleIn;                    /* '<S56>/scaleIn' */
  real32_T UnitDelay_h;                /* '<S56>/Unit Delay' */
  real32_T Switch;                     /* '<S14>/Switch' */
  real32_T convert_pu;                 /* '<S79>/convert_pu' */
  real32_T Merge_e;                    /* '<S79>/Merge' */
  real32_T indexing;                   /* '<S63>/indexing' */
  real32_T Lookup[4];                  /* '<S63>/Lookup' */
  real32_T Sum3_i;                     /* '<S78>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S63>/Data Type Conversion1' */
  real32_T Sum2_g;                     /* '<S63>/Sum2' */
  real32_T Product_h;                  /* '<S78>/Product' */
  real32_T Sum4_h;                     /* '<S78>/Sum4' */
  real32_T Sum5;                       /* '<S78>/Sum5' */
  real32_T Product1_k;                 /* '<S78>/Product1' */
  real32_T Sum6;                       /* '<S78>/Sum6' */
  real32_T Sum_k;                      /* '<S85>/Sum' */
  real32_T PProdOut;                   /* '<S194>/PProd Out' */
  real32_T UnitDelay_g;                /* '<S85>/Unit Delay' */
  real32_T Integrator;                 /* '<S189>/Integrator' */
  real32_T Sum_i;                      /* '<S198>/Sum' */
  real32_T Saturation;                 /* '<S196>/Saturation' */
  real32_T Switch_d;                   /* '<S85>/Switch' */
  real32_T Sum_b;                      /* '<S84>/Sum' */
  real32_T PProdOut_i;                 /* '<S141>/PProd Out' */
  real32_T UnitDelay_b;                /* '<S84>/Unit Delay' */
  real32_T Integrator_a;               /* '<S136>/Integrator' */
  real32_T Sum_o;                      /* '<S145>/Sum' */
  real32_T Saturation_h;               /* '<S143>/Saturation' */
  real32_T Switch_o;                   /* '<S84>/Switch' */
  real32_T Switch_oc;                  /* '<S88>/Switch' */
  real32_T Product_i;                  /* '<S88>/Product' */
  real32_T Product_hz;                 /* '<S89>/Product' */
  real32_T Product1_n;                 /* '<S89>/Product1' */
  real32_T Sum1;                       /* '<S89>/Sum1' */
  real32_T Merge_f[2];                 /* '<S83>/Merge' */
  real32_T Switch4[3];                 /* '<S17>/Switch4' */
  real32_T Sign;                       /* '<S24>/Sign' */
  real32_T Eta;                        /* '<S24>/Eta' */
  real32_T Sum_c;                      /* '<S24>/Sum' */
  real32_T b;                          /* '<S24>/b' */
  real32_T a_n;                        /* '<S24>/a' */
  real32_T Sum1_n;                     /* '<S24>/Sum1' */
  real32_T Sign_b;                     /* '<S25>/Sign' */
  real32_T Eta_h;                      /* '<S25>/Eta' */
  real32_T Sum_l;                      /* '<S25>/Sum' */
  real32_T b_j;                        /* '<S25>/b' */
  real32_T a_k;                        /* '<S25>/a' */
  real32_T Sum1_m;                     /* '<S25>/Sum1' */
  real32_T DTC;                        /* '<S46>/DTC' */
  real32_T SpeedGain;                  /* '<S29>/SpeedGain' */
  real32_T Switch1_d[2];               /* '<S28>/Switch1' */
  real32_T Product_m;                  /* '<S44>/Product' */
  real32_T UnitDelay_i;                /* '<S44>/Unit Delay' */
  real32_T Product1_l2;                /* '<S44>/Product1' */
  real32_T Add1_g;                     /* '<S44>/Add1' */
  real32_T DeadZone;                   /* '<S128>/DeadZone' */
  real32_T IProdOut;                   /* '<S133>/IProd Out' */
  real32_T Switch_g;                   /* '<S126>/Switch' */
  real32_T DeadZone_h;                 /* '<S181>/DeadZone' */
  real32_T IProdOut_b;                 /* '<S186>/IProd Out' */
  real32_T Switch_e;                   /* '<S179>/Switch' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two;               /* '<S75>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S75>/one_by_two' */
  real32_T add_c;                      /* '<S75>/add_c' */
  real32_T Kc;                         /* '<S75>/Kc' */
  real32_T add_b;                      /* '<S75>/add_b' */
  real32_T Kb;                         /* '<S75>/Kb' */
  real32_T Ka;                         /* '<S75>/Ka' */
  real32_T Min;                        /* '<S72>/Min' */
  real32_T Max;                        /* '<S72>/Max' */
  real32_T Add;                        /* '<S72>/Add' */
  real32_T one_by_two_k;               /* '<S72>/one_by_two' */
  real32_T Add2;                       /* '<S71>/Add2' */
  real32_T Add1_k;                     /* '<S71>/Add1' */
  real32_T Add3;                       /* '<S71>/Add3' */
  real32_T Gain[3];                    /* '<S71>/Gain' */
  real32_T Gain_n[3];                  /* '<S17>/Gain' */
  real32_T Add_c[3];                   /* '<S17>/Add' */
  real32_T Gain1[3];                   /* '<S17>/Gain1' */
  real32_T Saturation_i;               /* '<S84>/Saturation' */
  real32_T Product_c[2];               /* '<S90>/Product' */
  real32_T SquareRoot;                 /* '<S90>/Square Root' */
  real32_T Switch_k;                   /* '<S90>/Switch' */
  real32_T Switch_f[2];                /* '<S87>/Switch' */
  real32_T Switch2;                    /* '<S97>/Switch2' */
  real32_T Product_mt;                 /* '<S96>/Product' */
  real32_T Sum_e;                      /* '<S96>/Sum' */
  real32_T Product2;                   /* '<S96>/Product2' */
  real32_T Merge_an;                   /* '<S96>/Merge' */
  real32_T Gain_p;                     /* '<S96>/Gain' */
  real32_T Switch_n;                   /* '<S97>/Switch' */
  real32_T Switch1_m;                  /* '<S98>/Switch1' */
  real32_T Sqrt;                       /* '<S98>/Sqrt' */
  real32_T Gain_i;                     /* '<S98>/Gain' */
  real32_T Convert_back;               /* '<S82>/Convert_back' */
  real32_T Convert_back_k;             /* '<S81>/Convert_back' */
  real32_T bcos;                       /* '<S76>/bcos' */
  real32_T asin_f;                     /* '<S76>/asin' */
  real32_T sum_Qs;                     /* '<S76>/sum_Qs' */
  real32_T acos_f;                     /* '<S76>/acos' */
  real32_T bsin;                       /* '<S76>/bsin' */
  real32_T sum_Ds;                     /* '<S76>/sum_Ds' */
  real32_T Switch_dt[2];               /* '<S77>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Unary_Minus;                /* '<S77>/Unary_Minus' */
  real32_T qcos;                       /* '<S67>/qcos' */
  real32_T dsin;                       /* '<S67>/dsin' */
  real32_T sum_beta;                   /* '<S67>/sum_beta' */
  real32_T dcos;                       /* '<S67>/dcos' */
  real32_T qsin;                       /* '<S67>/qsin' */
  real32_T sum_alpha;                  /* '<S67>/sum_alpha' */
  real32_T Switch_p[2];                /* '<S68>/Switch' */
  real32_T algDD_o1_a;
  real32_T algDD_o2_j;
  real32_T Unary_Minus_i;              /* '<S68>/Unary_Minus' */
  real32_T a_plus_2b;                  /* '<S66>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S66>/one_by_sqrt3' */
  real32_T algDD_o1_j;
  real32_T algDD_o2_e;
  real32_T Add_g;                      /* '<S57>/Add' */
  real32_T DataTypeConversion1_p;      /* '<S57>/Data Type Conversion1' */
  real32_T Add1_m;                     /* '<S57>/Add1' */
  real32_T Input;                      /* '<S58>/Input' */
  real32_T DataStoreRead_j;            /* '<S55>/Data Store Read' */
  real32_T Add1_e;                     /* '<S55>/Add1' */
  real32_T SaturatetomotorcalibSpeedRPM;
                                /* '<S55>/Saturate to 'motor.calibSpeed' RPM' */
  real32_T scaleOut;                   /* '<S56>/scaleOut' */
  real32_T Product_b1;                 /* '<S30>/Product' */
  real32_T Product2_d;                 /* '<S30>/Product2' */
  real32_T Sum1_k;                     /* '<S30>/Sum1' */
  real32_T Product1_li;                /* '<S30>/Product1' */
  real32_T Product3;                   /* '<S30>/Product3' */
  real32_T Sum2_et;                    /* '<S30>/Sum2' */
  real32_T Switch_o3;                  /* '<S30>/Switch' */
  real32_T Atan2;                      /* '<S47>/Atan2' */
  real32_T Switch_nl;                  /* '<S47>/Switch' */
  real32_T algDD;
  real32_T Gain_d;                     /* '<S48>/Gain' */
  real32_T Switch_kk;                  /* '<S48>/Switch' */
  real32_T Bias;                       /* '<S48>/Bias' */
  real32_T Bias_d;                     /* '<S30>/Bias' */
  real32_T Sum_bn;                     /* '<S28>/Sum' */
  real32_T Sum_lt;                     /* '<S27>/Sum' */
  real32_T Sum_d;                      /* '<S26>/Sum' */
  int32_T DataTypeConversion[2];       /* '<S49>/Data Type Conversion' */
  int32_T Add_a[2];                    /* '<S49>/Add' */
  int32_T SpeedCount;                  /* '<S29>/SpeedCount' */
  uint16_T UARTUSARTWrite;             /* '<S214>/UART//USART Write' */
  uint16_T Switch1_i;                  /* '<S88>/Switch1' */
  uint16_T DataTypeConversion_a;       /* '<S79>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S63>/Get_Integer' */
  uint16_T DataTypeConversion_f;       /* '<S86>/Data Type Conversion' */
  uint16_T DataTypeConversion_h;       /* '<S96>/Data Type Conversion' */
  uint16_T AnalogtoDigitalConverter[2];/* '<S19>/Analog to Digital Converter' */
  int16_T DataStoreRead_a;             /* '<S49>/Data Store Read' */
  int16_T DataStoreRead1;              /* '<S49>/Data Store Read1' */
  int16_T Convert_uint16;              /* '<S82>/Convert_uint16' */
  int16_T Convert_uint16_f;            /* '<S81>/Convert_uint16' */
  int16_T DataTypeConversion_i;        /* '<S57>/Data Type Conversion' */
  int16_T Switch_gg;                   /* '<S31>/Switch' */
  int8_T Switch1_dl;                   /* '<S126>/Switch1' */
  int8_T Switch2_g;                    /* '<S126>/Switch2' */
  int8_T Switch1_c;                    /* '<S179>/Switch1' */
  int8_T Switch2_m;                    /* '<S179>/Switch2' */
  boolean_T UnitDelay_f;               /* '<S1>/Unit Delay' */
  boolean_T NOT2;                      /* '<S1>/NOT2' */
  boolean_T AND;                       /* '<S1>/AND' */
  boolean_T NOT;                       /* '<S214>/NOT' */
  boolean_T DataStoreRead_b;           /* '<S2>/Data Store Read' */
  boolean_T LogicalOperator;           /* '<S13>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S23>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S23>/BetaRelay' */
  boolean_T DataStoreRead_c;           /* '<S15>/Data Store Read' */
  boolean_T Compare;                   /* '<S50>/Compare' */
  boolean_T NOT_c;                     /* '<S15>/NOT' */
  boolean_T NOT_b;                     /* '<S56>/NOT' */
  boolean_T Compare_f;                 /* '<S80>/Compare' */
  boolean_T LogicalOperator_n;         /* '<S85>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S84>/Logical Operator1' */
  boolean_T DataStoreRead1_n;          /* '<S17>/Data Store Read1' */
  boolean_T RelationalOperator;        /* '<S126>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S126>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S126>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S126>/Equal1' */
  boolean_T AND3;                      /* '<S126>/AND3' */
  boolean_T RelationalOperator_l;      /* '<S179>/Relational Operator' */
  boolean_T fixforDTpropagationissue_i;
                                     /* '<S179>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_m;
                                    /* '<S179>/fix for DT propagation issue1' */
  boolean_T Equal1_n;                  /* '<S179>/Equal1' */
  boolean_T AND3_m;                    /* '<S179>/AND3' */
  boolean_T RelationalOperator_j;      /* '<S86>/Relational Operator' */
  boolean_T Compare_e;                 /* '<S92>/Compare' */
  boolean_T Compare_n;                 /* '<S93>/Compare' */
  boolean_T LowerRelop1;               /* '<S97>/LowerRelop1' */
  boolean_T RelationalOperator_i;      /* '<S96>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S97>/UpperRelop' */
  boolean_T Delay_e;                   /* '<S57>/Delay' */
  boolean_T LogicalOperator_g;         /* '<S31>/Logical Operator' */
  boolean_T UnitDelay_a;               /* '<S8>/Unit Delay' */
  boolean_T NOT_n;                     /* '<S8>/NOT' */
  boolean_T DigitalPortRead;           /* '<S10>/Digital Port Read' */
} BlockIO_pmsm_foc_sensorless_nuc;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_UARTWrite_pmsm obj; /* '<S214>/UART//USART Write' */
  stm32cube_blocks_UARTWrite_pmsm obj_e;/* '<S215>/UART//USART Write' */
  stm32cube_blocks_AnalogInput_pm obj_o;/* '<S19>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_pmsm obj_e3;/* '<S208>/PWM Output' */
  uint64_T Add1_DWORK1;                /* '<S51>/Add1' */
  real32_T UnitDelay1_DSTATE;          /* '<S34>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S34>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S2>/Delay5' */
  real32_T Delay_DSTATE;               /* '<S24>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S34>/Delay1' */
  real32_T UnitDelay_DSTATE_b;         /* '<S38>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_m;        /* '<S35>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_p;         /* '<S35>/Unit Delay' */
  real32_T Delay_DSTATE_h;             /* '<S25>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S35>/Delay1' */
  real32_T UnitDelay_DSTATE_d;         /* '<S41>/Unit Delay' */
  real32_T Delay_DSTATE_p;             /* '<S22>/Delay' */
  real32_T UnitDelay_DSTATE_bp;        /* '<S56>/Unit Delay' */
  real32_T UnitDelay_DSTATE_bv;        /* '<S85>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S189>/Integrator' */
  real32_T UnitDelay_DSTATE_c;         /* '<S84>/Unit Delay' */
  real32_T Integrator_DSTATE_l;        /* '<S136>/Integrator' */
  real32_T UnitDelay_DSTATE_bl;        /* '<S44>/Unit Delay' */
  uint32_T Delay_DSTATE_a[119];        /* '<S29>/Delay' */
  volatile real32_T RT1_Buffer[4];     /* '<Root>/RT1' */
  real32_T GlobleopenspeedInt;         /* '<S53>/Data Store Memory' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T Add_DWORK1[2];               /* '<S49>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S29>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S63>/Sum' */
  uint32_T CircBufIdx;                 /* '<S29>/Delay' */
  uint32_T statcount;                  /* '<S15>/Data Store Memory' */
  stm32cube_blocks_DigitalPortRea obj_k;/* '<S10>/Digital Port Read' */
  stm32cube_blocks_DigitalPortWri obj_kg;/* '<S213>/Digital Port Write' */
  int16_T IaOffset;                    /* '<Root>/Data Store Memory13' */
  int16_T IbOffset;                    /* '<Root>/Data Store Memory14' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S1>/Unit Delay' */
  boolean_T Delay_DSTATE_he;           /* '<S57>/Delay' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S8>/Unit Delay' */
  volatile int8_T RT1_ActiveBufIdx;    /* '<Root>/RT1' */
  volatile int8_T RT1_semaphoreTaken;  /* '<Root>/RT1' */
  int8_T Integrator_PrevResetState;    /* '<S189>/Integrator' */
  int8_T Integrator_PrevResetState_i;  /* '<S136>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S189>/Integrator' */
  uint8_T Integrator_IC_LOADING_o;     /* '<S136>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory9' */
  boolean_T objisempty;                /* '<S214>/UART//USART Write' */
  boolean_T objisempty_a;              /* '<S215>/UART//USART Write' */
  boolean_T objisempty_n;              /* '<S213>/Digital Port Write' */
  boolean_T AlphaRelay_Mode;           /* '<S23>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S23>/BetaRelay' */
  boolean_T objisempty_k;              /* '<S208>/PWM Output' */
  boolean_T objisempty_o;              /* '<S19>/Analog to Digital Converter' */
  boolean_T objisempty_f;              /* '<S10>/Digital Port Read' */
} D_Work_pmsm_foc_sensorless_nucl;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S24>/Delay' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S34>/Delay1' */
  ZCSigState Delay_Reset_ZCE_c;        /* '<S25>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S35>/Delay1' */
  ZCSigState Delay_Reset_ZCE_n;        /* '<S22>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S23>/Dir_Sense' */
} PrevZCSigStates_pmsm_foc_sensor;

/* Parameters (default storage) */
struct Parameters_pmsm_foc_sensorless__ {
  real_T SlidingModeObserver_CurrentObse;
                              /* Mask Parameter: SlidingModeObserver_CurrentObse
                               * Referenced by:
                               *   '<S24>/Eta'
                               *   '<S25>/Eta'
                               */
  real_T SlidingModeObserver_CutoffFreq;
                               /* Mask Parameter: SlidingModeObserver_CutoffFreq
                                * Referenced by: '<S22>/PhaseDelay'
                                */
  real_T SlidingModeObserver_Disturbance;
                              /* Mask Parameter: SlidingModeObserver_Disturbance
                               * Referenced by:
                               *   '<S34>/b_inv*g'
                               *   '<S35>/b_inv*g'
                               */
  real32_T DiscretePIControllerwithantiwin;
                              /* Mask Parameter: DiscretePIControllerwithantiwin
                               * Referenced by:
                               *   '<S196>/Saturation'
                               *   '<S181>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_f;
                              /* Mask Parameter: DiscretePIControllerwithantiw_f
                               * Referenced by:
                               *   '<S143>/Saturation'
                               *   '<S128>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_e;
                              /* Mask Parameter: DiscretePIControllerwithantiw_e
                               * Referenced by:
                               *   '<S196>/Saturation'
                               *   '<S181>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_b;
                              /* Mask Parameter: DiscretePIControllerwithantiw_b
                               * Referenced by:
                               *   '<S143>/Saturation'
                               *   '<S128>/DeadZone'
                               */
  uint32_T EnablePWMfor8seconds_const;
                                   /* Mask Parameter: EnablePWMfor8seconds_const
                                    * Referenced by: '<S50>/Constant'
                                    */
  uint16_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S92>/Constant'
                                       */
  uint16_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S93>/Constant'
                                      */
  uint16_T atan1_outputUnit;           /* Mask Parameter: atan1_outputUnit
                                        * Referenced by: '<S47>/Constant'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S31>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S31>/Constant1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 10
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 5
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S5>/Pulse Generator'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S26>/a'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S26>/One'
                                        */
  real32_T FilterConstant_Value;       /* Expression: Filter_constant
                                        * Referenced by: '<S26>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S26>/OneMinusFilterConstant'
                                         */
  real32_T a_Value_h;                  /* Computed Parameter: a_Value_h
                                        * Referenced by: '<S27>/a'
                                        */
  real32_T One_Value_c;                /* Computed Parameter: One_Value_c
                                        * Referenced by: '<S27>/One'
                                        */
  real32_T FilterConstant_Value_g;     /* Expression: Filter_constant
                                        * Referenced by: '<S27>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value_j;/* Expression: 1 - Filter_constant
                                           * Referenced by: '<S27>/OneMinusFilterConstant'
                                           */
  real32_T a_Value_i;                  /* Computed Parameter: a_Value_i
                                        * Referenced by: '<S28>/a'
                                        */
  real32_T One_Value_e;                /* Computed Parameter: One_Value_e
                                        * Referenced by: '<S28>/One'
                                        */
  real32_T FilterConstant_Value_o;     /* Expression: Filter_constant
                                        * Referenced by: '<S28>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value_n;/* Expression: 1 - Filter_constant
                                           * Referenced by: '<S28>/OneMinusFilterConstant'
                                           */
  real32_T Bias_Bias;                  /* Expression: single(2*pi)
                                        * Referenced by: '<S30>/Bias'
                                        */
  real32_T Bias_Bias_g;                /* Computed Parameter: Bias_Bias_g
                                        * Referenced by: '<S48>/Bias'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S48>/Gain'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S48>/Switch'
                                        */
  real32_T Switch_Threshold_k;         /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S30>/Switch'
                                        */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S56>/scaleOut'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S54>/Constant'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S55>/Constant2'
                                        */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S55>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S55>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Multiply1_Gain;             /* Computed Parameter: Multiply1_Gain
                                        * Referenced by: '<S55>/Multiply1'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S58>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S57>/theta_e'
                                        */
  real32_T one_by_sqrt3_Gain;          /* Computed Parameter: one_by_sqrt3_Gain
                                        * Referenced by: '<S66>/one_by_sqrt3'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S98>/Constant'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S98>/Gain'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S98>/Switch1'
                                        */
  real32_T Switch_Threshold_c;         /* Computed Parameter: Switch_Threshold_c
                                        * Referenced by: '<S98>/Switch'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S96>/Gain'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S90>/Constant'
                                        */
  real32_T ReplaceInport_satLim_Value;
                               /* Computed Parameter: ReplaceInport_satLim_Value
                                * Referenced by: '<S83>/ReplaceInport_satLim'
                                */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S88>/Constant3'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S84>/Constant'
                                        */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S84>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S84>/Saturation'
                                       */
  real32_T Vq_OpenLoop_Value;          /* Computed Parameter: Vq_OpenLoop_Value
                                        * Referenced by: '<S85>/Vq_OpenLoop'
                                        */
  real32_T Constant1_Value_a;          /* Computed Parameter: Constant1_Value_a
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S75>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S75>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S75>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S75>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S75>/Ka'
                                        */
  real32_T one_by_two_Gain_g;          /* Computed Parameter: one_by_two_Gain_g
                                        * Referenced by: '<S72>/one_by_two'
                                        */
  real32_T Gain_Gain_mr;               /* Computed Parameter: Gain_Gain_mr
                                        * Referenced by: '<S71>/Gain'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S17>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S17>/Gain1'
                                        */
  real32_T theta_Y0;                   /* Computed Parameter: theta_Y0
                                        * Referenced by: '<S2>/theta'
                                        */
  real32_T currentab_Y0;               /* Computed Parameter: currentab_Y0
                                        * Referenced by: '<S2>/currentab'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S80>/Constant'
                                        */
  real32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S126>/Constant1'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S179>/Constant1'
                                        */
  real32_T Constant2_Value_c;          /* Computed Parameter: Constant2_Value_c
                                        * Referenced by: '<S16>/Constant2'
                                        */
  real32_T ADvoltage_Gain;             /* Computed Parameter: ADvoltage_Gain
                                        * Referenced by: '<S49>/AD voltage'
                                        */
  real32_T OP_GainR_shunt_Gain;       /* Computed Parameter: OP_GainR_shunt_Gain
                                       * Referenced by: '<S49>/OP_Gain*R_shunt'
                                       */
  real32_T OP_GainR_shunt1_Gain;     /* Computed Parameter: OP_GainR_shunt1_Gain
                                      * Referenced by: '<S49>/OP_Gain*R_shunt1'
                                      */
  real32_T Kalpha_Gain;                /* Computed Parameter: Kalpha_Gain
                                        * Referenced by: '<S65>/Kalpha'
                                        */
  real32_T Kbeta_Gain;                 /* Computed Parameter: Kbeta_Gain
                                        * Referenced by: '<S65>/Kbeta'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S63>/sine_table_values'
                                   */
  real32_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S34>/Unit Delay1'
                               */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S34>/Unit Delay'
                                */
  real32_T a_Gain;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S34>/a'
   */
  real32_T Delay5_InitialCondition;
                                  /* Computed Parameter: Delay5_InitialCondition
                                   * Referenced by: '<S2>/Delay5'
                                   */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S24>/Delay'
                                    */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S34>/Delay1'
                                   */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S26>/UseInputPort'
                                        */
  real32_T Switch1_Threshold_b;       /* Computed Parameter: Switch1_Threshold_b
                                       * Referenced by: '<S26>/Switch1'
                                       */
  real32_T UnitDelay_InitialCondition_l;
                             /* Computed Parameter: UnitDelay_InitialCondition_l
                              * Referenced by: '<S38>/Unit Delay'
                              */
  real32_T AlphaRelay_OnVal;           /* Computed Parameter: AlphaRelay_OnVal
                                        * Referenced by: '<S23>/AlphaRelay'
                                        */
  real32_T AlphaRelay_OffVal;          /* Computed Parameter: AlphaRelay_OffVal
                                        * Referenced by: '<S23>/AlphaRelay'
                                        */
  real32_T UnitDelay1_InitialCondition_p;
                            /* Computed Parameter: UnitDelay1_InitialCondition_p
                             * Referenced by: '<S35>/Unit Delay1'
                             */
  real32_T UnitDelay_InitialCondition_i;
                             /* Computed Parameter: UnitDelay_InitialCondition_i
                              * Referenced by: '<S35>/Unit Delay'
                              */
  real32_T a_Gain_e;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S35>/a'
   */
  real32_T Delay_InitialCondition_e;
                                 /* Computed Parameter: Delay_InitialCondition_e
                                  * Referenced by: '<S25>/Delay'
                                  */
  real32_T Delay1_InitialCondition_m;
                                /* Computed Parameter: Delay1_InitialCondition_m
                                 * Referenced by: '<S35>/Delay1'
                                 */
  real32_T UseInputPort_Value_g;     /* Computed Parameter: UseInputPort_Value_g
                                      * Referenced by: '<S27>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_bx;     /* Computed Parameter: Switch1_Threshold_bx
                                      * Referenced by: '<S27>/Switch1'
                                      */
  real32_T UnitDelay_InitialCondition_p;
                             /* Computed Parameter: UnitDelay_InitialCondition_p
                              * Referenced by: '<S41>/Unit Delay'
                              */
  real32_T BetaRelay_OnVal;            /* Computed Parameter: BetaRelay_OnVal
                                        * Referenced by: '<S23>/BetaRelay'
                                        */
  real32_T BetaRelay_OffVal;           /* Computed Parameter: BetaRelay_OffVal
                                        * Referenced by: '<S23>/BetaRelay'
                                        */
  real32_T Delay_InitialCondition_b;
                                 /* Computed Parameter: Delay_InitialCondition_b
                                  * Referenced by: '<S22>/Delay'
                                  */
  real32_T AngleConversion_Gain;     /* Computed Parameter: AngleConversion_Gain
                                      * Referenced by: '<S22>/AngleConversion'
                                      */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S56>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition_pr;
                            /* Computed Parameter: UnitDelay_InitialCondition_pr
                             * Referenced by: '<S56>/Unit Delay'
                             */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S79>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S63>/indexing'
                                        */
  real32_T Kp_Value;                   /* Computed Parameter: Kp_Value
                                        * Referenced by: '<S64>/Kp'
                                        */
  real32_T UnitDelay_InitialCondition_h;
                             /* Computed Parameter: UnitDelay_InitialCondition_h
                              * Referenced by: '<S85>/Unit Delay'
                              */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S189>/Integrator'
                                        */
  real32_T Constant3_Value_o;          /* Computed Parameter: Constant3_Value_o
                                        * Referenced by: '<S16>/Constant3'
                                        */
  real32_T UnitDelay_InitialCondition_b;
                             /* Computed Parameter: UnitDelay_InitialCondition_b
                              * Referenced by: '<S84>/Unit Delay'
                              */
  real32_T Integrator_gainval_p;     /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S136>/Integrator'
                                      */
  real32_T b_Gain;
  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S24>/b'
   */
  real32_T a_Gain_a;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S24>/a'
   */
  real32_T b_Gain_g;
  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S25>/b'
   */
  real32_T a_Gain_g;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S25>/a'
   */
  real32_T PositionToCount_Gain;     /* Computed Parameter: PositionToCount_Gain
                                      * Referenced by: '<S29>/PositionToCount'
                                      */
  real32_T SpeedGain_Gain;             /* Computed Parameter: SpeedGain_Gain
                                        * Referenced by: '<S29>/SpeedGain'
                                        */
  real32_T UseInputPort_Value_p;     /* Computed Parameter: UseInputPort_Value_p
                                      * Referenced by: '<S28>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_a;       /* Computed Parameter: Switch1_Threshold_a
                                       * Referenced by: '<S28>/Switch1'
                                       */
  real32_T UnitDelay_InitialCondition_j;
                             /* Computed Parameter: UnitDelay_InitialCondition_j
                              * Referenced by: '<S44>/Unit Delay'
                              */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S53>/Data Store Memory'
                              */
  real32_T Ki_Value;                   /* Computed Parameter: Ki_Value
                                        * Referenced by: '<S64>/Ki'
                                        */
  real32_T Clamping_zero_Value;       /* Computed Parameter: Clamping_zero_Value
                                       * Referenced by: '<S126>/Clamping_zero'
                                       */
  real32_T Clamping_zero_Value_k;   /* Computed Parameter: Clamping_zero_Value_k
                                     * Referenced by: '<S179>/Clamping_zero'
                                     */
  real32_T Constant_Value_nt[3];       /* Computed Parameter: Constant_Value_nt
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T RT1_InitialCondition;     /* Computed Parameter: RT1_InitialCondition
                                      * Referenced by: '<Root>/RT1'
                                      */
  uint32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S51>/Constant'
                                        */
  uint32_T Constant15_Value;           /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S52>/Constant15'
                                        */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S53>/Count for 2 sec'
                                        */
  uint32_T Delay_InitialCondition_i;
                                 /* Computed Parameter: Delay_InitialCondition_i
                                  * Referenced by: '<S29>/Delay'
                                  */
  uint32_T DataStoreMemory_InitialValue_b;
                           /* Computed Parameter: DataStoreMemory_InitialValue_b
                            * Referenced by: '<S15>/Data Store Memory'
                            */
  int16_T Sign_Y0;                     /* Computed Parameter: Sign_Y0
                                        * Referenced by: '<S31>/Sign'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S63>/offset'
                                        */
  int16_T Testinggetoffset1_Value;/* Computed Parameter: Testinggetoffset1_Value
                                   * Referenced by: '<S4>/Testing get offset1'
                                   */
  int16_T Testinggetoffset_Value;  /* Computed Parameter: Testinggetoffset_Value
                                    * Referenced by: '<S4>/Testing get offset'
                                    */
  int16_T DataStoreMemory13_InitialValue;
                           /* Computed Parameter: DataStoreMemory13_InitialValue
                            * Referenced by: '<Root>/Data Store Memory13'
                            */
  int16_T DataStoreMemory14_InitialValue;
                           /* Computed Parameter: DataStoreMemory14_InitialValue
                            * Referenced by: '<Root>/Data Store Memory14'
                            */
  uint16_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S47>/Switch'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S68>/Offset'
                                        */
  uint16_T Switch_Threshold_kk;       /* Computed Parameter: Switch_Threshold_kk
                                       * Referenced by: '<S68>/Switch'
                                       */
  uint16_T Offset_Value_l;             /* Computed Parameter: Offset_Value_l
                                        * Referenced by: '<S77>/Offset'
                                        */
  uint16_T Switch_Threshold_g;         /* Computed Parameter: Switch_Threshold_g
                                        * Referenced by: '<S77>/Switch'
                                        */
  uint16_T ReplaceInport_satMethod_Value;
                            /* Computed Parameter: ReplaceInport_satMethod_Value
                             * Referenced by: '<S83>/ReplaceInport_satMethod'
                             */
  uint16_T ChosenMethod_Value;         /* Computed Parameter: ChosenMethod_Value
                                        * Referenced by: '<S88>/ChosenMethod'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S17>/stop'
                                        */
  uint16_T Out1_Y0_j;                  /* Computed Parameter: Out1_Y0_j
                                        * Referenced by: '<S2>/Out1'
                                        */
  uint16_T enableInportSatMethod_Value;
                              /* Computed Parameter: enableInportSatMethod_Value
                               * Referenced by: '<S88>/enableInportSatMethod'
                               */
  uint16_T enableInportSatLim_Value;
                                 /* Computed Parameter: enableInportSatLim_Value
                                  * Referenced by: '<S88>/enableInportSatLim'
                                  */
  boolean_T Out1_Y0_o;                 /* Computed Parameter: Out1_Y0_o
                                        * Referenced by: '<S8>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition_lg;/* Expression: true
                                           * Referenced by: '<S8>/Unit Delay'
                                           */
  boolean_T Delay_InitialCondition_n;
                                 /* Computed Parameter: Delay_InitialCondition_n
                                  * Referenced by: '<S57>/Delay'
                                  */
  boolean_T Constant_Value_a;          /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S57>/Constant'
                                        */
  boolean_T AlphaRelay_YOn;            /* Computed Parameter: AlphaRelay_YOn
                                        * Referenced by: '<S23>/AlphaRelay'
                                        */
  boolean_T AlphaRelay_YOff;           /* Computed Parameter: AlphaRelay_YOff
                                        * Referenced by: '<S23>/AlphaRelay'
                                        */
  boolean_T BetaRelay_YOn;             /* Computed Parameter: BetaRelay_YOn
                                        * Referenced by: '<S23>/BetaRelay'
                                        */
  boolean_T BetaRelay_YOff;            /* Computed Parameter: BetaRelay_YOff
                                        * Referenced by: '<S23>/BetaRelay'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S56>/Constant_Reset'
                                      */
  boolean_T UnitDelay_InitialCondition_e;/* Expression: false
                                          * Referenced by: '<S1>/Unit Delay'
                                          */
  boolean_T DataStoreMemory9_InitialValue;
                            /* Computed Parameter: DataStoreMemory9_InitialValue
                             * Referenced by: '<Root>/Data Store Memory9'
                             */
  int8_T Constant_Value_l;             /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S126>/Constant'
                                        */
  int8_T Constant2_Value_i;            /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S126>/Constant2'
                                        */
  int8_T Constant3_Value_m;            /* Computed Parameter: Constant3_Value_m
                                        * Referenced by: '<S126>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S126>/Constant4'
                                        */
  int8_T Constant_Value_jm;            /* Computed Parameter: Constant_Value_jm
                                        * Referenced by: '<S179>/Constant'
                                        */
  int8_T Constant2_Value_e;            /* Computed Parameter: Constant2_Value_e
                                        * Referenced by: '<S179>/Constant2'
                                        */
  int8_T Constant3_Value_h;            /* Computed Parameter: Constant3_Value_h
                                        * Referenced by: '<S179>/Constant3'
                                        */
  int8_T Constant4_Value_m;            /* Computed Parameter: Constant4_Value_m
                                        * Referenced by: '<S179>/Constant4'
                                        */
  uint8_T Constant1_Value_f[4];        /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S215>/Constant1'
                                        */
  uint8_T Constant2_Value_n;           /* Computed Parameter: Constant2_Value_n
                                        * Referenced by: '<S215>/Constant2'
                                        */
  uint8_T Constant2_Value_nq;          /* Computed Parameter: Constant2_Value_nq
                                        * Referenced by: '<S6>/Constant2'
                                        */
  uint8_T Constant3_Value_e;           /* Computed Parameter: Constant3_Value_e
                                        * Referenced by: '<S6>/Constant3'
                                        */
  uint8_T Constant1_Value_d;           /* Computed Parameter: Constant1_Value_d
                                        * Referenced by: '<S6>/Constant1'
                                        */
  uint8_T Constant4_Value_b;           /* Computed Parameter: Constant4_Value_b
                                        * Referenced by: '<S214>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pmsm_foc_sensorless_nuc {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern Parameters_pmsm_foc_sensorless_ pmsm_foc_sensorless_nucleo_G4_P;

/* Block signals (default storage) */
extern BlockIO_pmsm_foc_sensorless_nuc pmsm_foc_sensorless_nucleo_G4_B;

/* Block states (default storage) */
extern D_Work_pmsm_foc_sensorless_nucl pmsm_foc_sensorless_nucle_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_pmsm_foc_sensor pmsm_foc_sensorl_PrevZCSigState;

/* External function called from main */
extern void pmsm_foc_sensorless_nucleo_G4_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void pmsm_foc_sensorless_nucleo_G4_initialize(void);
extern void pmsm_foc_sensorless_nucleo_G4_step0(void);
extern void pmsm_foc_sensorless_nucleo_G4_step1(void);
extern void pmsm_foc_sensorless_nucleo_G4_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pmsm_foc_sensorless_nu *const pmsm_foc_sensorless_nucleo_G_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC1_2_IRQHandler(void);
  void pmsm_foc_sensorless_nucleo_G4_configure_interrupts (void);
  void pmsm_foc_sensorless_nucleo_G4_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

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
 * '<Root>' : 'pmsm_foc_sensorless_nucleo_G4'
 * '<S1>'   : 'pmsm_foc_sensorless_nucleo_G4/Button start'
 * '<S2>'   : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem'
 * '<S3>'   : 'pmsm_foc_sensorless_nucleo_G4/Hardware Interrupt'
 * '<S4>'   : 'pmsm_foc_sensorless_nucleo_G4/Initialize Function'
 * '<S5>'   : 'pmsm_foc_sensorless_nucleo_G4/LED Heart'
 * '<S6>'   : 'pmsm_foc_sensorless_nucleo_G4/Subsystem1'
 * '<S7>'   : 'pmsm_foc_sensorless_nucleo_G4/Button start/Digital Port Read'
 * '<S8>'   : 'pmsm_foc_sensorless_nucleo_G4/Button start/Enabled Subsystem'
 * '<S9>'   : 'pmsm_foc_sensorless_nucleo_G4/Button start/Digital Port Read/ECSoC'
 * '<S10>'  : 'pmsm_foc_sensorless_nucleo_G4/Button start/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S11>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Analog to Digital Converter'
 * '<S12>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Counter Limited'
 * '<S13>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO'
 * '<S14>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem1'
 * '<S15>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2'
 * '<S16>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3'
 * '<S17>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem4'
 * '<S18>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S19>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S20>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S21>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S22>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer'
 * '<S23>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch'
 * '<S24>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Ealpha_est'
 * '<S25>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Ebeta_est'
 * '<S26>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha'
 * '<S27>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta'
 * '<S28>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter'
 * '<S29>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement'
 * '<S30>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation'
 * '<S31>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S32>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S33>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S34>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S35>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S36>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S37>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S38>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S39>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S40>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S41>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S42>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S43>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S44>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S45>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S46>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S47>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation/atan1'
 * '<S48>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 * '<S49>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem1/Feedbackt_Current'
 * '<S50>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/Enable PWM for 8 seconds'
 * '<S51>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/If Action Subsystem2'
 * '<S52>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/If Action Subsystem3'
 * '<S53>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/Subsystem1'
 * '<S54>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/Subsystem1/If Action Subsystem'
 * '<S55>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/Subsystem1/If Action Subsystem2'
 * '<S56>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator'
 * '<S57>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator/Accumulate'
 * '<S58>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S59>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Clarke Transform'
 * '<S60>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Inverse Park Transform'
 * '<S61>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/PWM Reference Generator'
 * '<S62>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Park Transform1'
 * '<S63>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup'
 * '<S64>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem'
 * '<S65>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Clarke Transform/Two phase input'
 * '<S66>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S67>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Inverse Park Transform/Two inputs CRL'
 * '<S68>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S69>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method'
 * '<S70>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input'
 * '<S71>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method/SVPWM'
 * '<S72>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S73>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S74>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S75>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S76>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Park Transform1/Two inputs CRL'
 * '<S77>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Park Transform1/Two inputs CRL/Switch_Axis'
 * '<S78>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/Interpolation'
 * '<S79>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp'
 * '<S80>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S81>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S82>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S83>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter'
 * '<S84>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id'
 * '<S85>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq'
 * '<S86>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence'
 * '<S87>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority'
 * '<S88>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/Inport//Dialog Selection'
 * '<S89>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/Magnitude_calc'
 * '<S90>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S91>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S92>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S93>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S94>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S95>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S96>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S97>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S98>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S99>'  : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S100>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S101>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S102>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S103>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S104>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S105>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S106>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S107>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S108>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S109>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S110>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S111>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S112>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S113>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S114>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S115>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S116>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S117>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S118>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S119>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S120>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S121>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S122>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S123>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S124>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S125>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S126>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S127>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S128>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S129>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S130>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S131>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S132>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S133>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S134>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S135>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S136>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S137>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S138>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S139>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S140>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S141>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S142>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S143>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S144>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S145>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S146>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S147>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S148>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S149>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S150>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S151>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S152>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S153>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S154>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S155>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S156>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S157>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S158>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S159>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S160>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S161>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S162>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S163>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S164>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S165>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S166>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S167>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S168>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S169>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S170>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S171>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S172>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S173>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S174>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S175>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S176>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S177>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S178>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S179>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S180>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S181>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S182>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S183>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S184>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S185>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S186>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S187>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S188>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S189>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S190>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S191>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S192>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S193>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S194>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S195>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S196>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S197>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S198>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S199>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S200>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S201>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S202>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S203>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S204>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S205>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S206>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem4/PWM Output'
 * '<S207>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem4/PWM Output/ECSoC'
 * '<S208>' : 'pmsm_foc_sensorless_nucleo_G4/Function-Call Subsystem/Subsystem4/PWM Output/ECSoC/ECSimCodegen'
 * '<S209>' : 'pmsm_foc_sensorless_nucleo_G4/Hardware Interrupt/ECSoC'
 * '<S210>' : 'pmsm_foc_sensorless_nucleo_G4/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S211>' : 'pmsm_foc_sensorless_nucleo_G4/LED Heart/Digital Port Write'
 * '<S212>' : 'pmsm_foc_sensorless_nucleo_G4/LED Heart/Digital Port Write/ECSoC'
 * '<S213>' : 'pmsm_foc_sensorless_nucleo_G4/LED Heart/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S214>' : 'pmsm_foc_sensorless_nucleo_G4/Subsystem1/Subsystem'
 * '<S215>' : 'pmsm_foc_sensorless_nucleo_G4/Subsystem1/Subsystem/Enabled Subsystem'
 */
#endif                                 /* pmsm_foc_sensorless_nucleo_G4_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
