/*
 * File: Motorparasmeters.h
 *
 * Code generated for Simulink model 'Motorparasmeters'.
 *
 * Model version                  : 8.24
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Nov 28 16:29:34 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Motorparasmeters_h_
#define Motorparasmeters_h_
#ifndef Motorparasmeters_COMMON_INCLUDES_
#define Motorparasmeters_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#include "stm_lpuart.h"
#endif                                 /* Motorparasmeters_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "Motorparasmeters_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T LED;                          /* '<S5>/Pulse Generator' */
  uint32_T cont;                       /* '<S16>/Merge2' */
  uint32_T Sum[4];                     /* '<S69>/Sum' */
  uint32_T PositionToCount;            /* '<S35>/PositionToCount' */
  uint32_T Delay;                      /* '<S35>/Delay' */
  uint32_T DataStoreRead;              /* '<S57>/Data Store Read' */
  uint32_T Add1;                       /* '<S57>/Add1' */
  real32_T RT_n;                       /* '<Root>/RT' */
  real32_T Assignment[3];              /* '<S6>/Assignment' */
  real32_T RT1[2];                     /* '<Root>/RT1' */
  real32_T Assignment1[3];             /* '<S6>/Assignment1' */
  real32_T Assignment2[3];             /* '<S6>/Assignment2' */
  real32_T ADvoltage[2];               /* '<S55>/AD voltage' */
  real32_T OP_GainR_shunt[2];          /* '<S55>/OP_Gain*R_shunt' */
  real32_T OP_GainR_shunt1[2];         /* '<S55>/OP_Gain*R_shunt1' */
  real32_T Kalpha;                     /* '<S71>/Kalpha' */
  real32_T Kbeta;                      /* '<S71>/Kbeta' */
  real32_T UnitDelay1;                 /* '<S40>/Unit Delay1' */
  real32_T UnitDelay;                  /* '<S40>/Unit Delay' */
  real32_T a;                          /* '<S40>/a' */
  real32_T Delay5[4];                  /* '<S2>/Delay5' */
  real32_T Delay_b;                    /* '<S30>/Delay' */
  real32_T Sum2;                       /* '<S30>/Sum2' */
  real32_T Sum3;                       /* '<S40>/Sum3' */
  real32_T b_invg;                     /* '<S40>/b_inv*g' */
  real32_T Delay1;                     /* '<S40>/Delay1' */
  real32_T Sum4;                       /* '<S40>/Sum4' */
  real32_T Switch1[2];                 /* '<S32>/Switch1' */
  real32_T Product;                    /* '<S44>/Product' */
  real32_T UnitDelay_e;                /* '<S44>/Unit Delay' */
  real32_T Product1;                   /* '<S44>/Product1' */
  real32_T Add1_o;                     /* '<S44>/Add1' */
  real32_T UnitDelay1_e;               /* '<S41>/Unit Delay1' */
  real32_T UnitDelay_c;                /* '<S41>/Unit Delay' */
  real32_T a_c;                        /* '<S41>/a' */
  real32_T Delay_f;                    /* '<S31>/Delay' */
  real32_T Sum2_e;                     /* '<S31>/Sum2' */
  real32_T Sum3_m;                     /* '<S41>/Sum3' */
  real32_T b_invg_d;                   /* '<S41>/b_inv*g' */
  real32_T Delay1_f;                   /* '<S41>/Delay1' */
  real32_T Sum4_d;                     /* '<S41>/Sum4' */
  real32_T Switch1_o[2];               /* '<S33>/Switch1' */
  real32_T Product_b;                  /* '<S47>/Product' */
  real32_T UnitDelay_m;                /* '<S47>/Unit Delay' */
  real32_T Product1_l;                 /* '<S47>/Product1' */
  real32_T Add1_p;                     /* '<S47>/Add1' */
  real32_T Merge;                      /* '<S29>/Merge' */
  real32_T Merge1;                     /* '<S29>/Merge1' */
  real32_T Delay_fn;                   /* '<S28>/Delay' */
  real32_T PhaseDelay;                 /* '<S28>/PhaseDelay' */
  real32_T Merge_a;                    /* '<S59>/Merge' */
  real32_T scaleIn;                    /* '<S62>/scaleIn' */
  real32_T UnitDelay_h;                /* '<S62>/Unit Delay' */
  real32_T Switch;                     /* '<S15>/Switch' */
  real32_T convert_pu;                 /* '<S85>/convert_pu' */
  real32_T Merge_e;                    /* '<S85>/Merge' */
  real32_T indexing;                   /* '<S69>/indexing' */
  real32_T Lookup[4];                  /* '<S69>/Lookup' */
  real32_T Sum3_i;                     /* '<S84>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S69>/Data Type Conversion1' */
  real32_T Sum2_g;                     /* '<S69>/Sum2' */
  real32_T Product_h;                  /* '<S84>/Product' */
  real32_T Sum4_h;                     /* '<S84>/Sum4' */
  real32_T Sum5;                       /* '<S84>/Sum5' */
  real32_T Product1_k;                 /* '<S84>/Product1' */
  real32_T Sum6;                       /* '<S84>/Sum6' */
  real32_T Sum_k;                      /* '<S91>/Sum' */
  real32_T PProdOut;                   /* '<S200>/PProd Out' */
  real32_T Vq_OpenLoop;                /* '<S91>/Vq_OpenLoop' */
  real32_T Integrator;                 /* '<S195>/Integrator' */
  real32_T Sum_i;                      /* '<S204>/Sum' */
  real32_T Saturation;                 /* '<S202>/Saturation' */
  real32_T Sum_b;                      /* '<S90>/Sum' */
  real32_T PProdOut_i;                 /* '<S147>/PProd Out' */
  real32_T Constant;                   /* '<S90>/Constant' */
  real32_T Integrator_a;               /* '<S142>/Integrator' */
  real32_T Sum_o;                      /* '<S151>/Sum' */
  real32_T Saturation_h;               /* '<S149>/Saturation' */
  real32_T Switch_o;                   /* '<S94>/Switch' */
  real32_T Product_i;                  /* '<S94>/Product' */
  real32_T Product_hz;                 /* '<S95>/Product' */
  real32_T Product1_n;                 /* '<S95>/Product1' */
  real32_T Sum1;                       /* '<S95>/Sum1' */
  real32_T Merge_f[2];                 /* '<S89>/Merge' */
  real32_T Switch4[3];                 /* '<S18>/Switch4' */
  real32_T Gain2;                      /* '<S18>/Gain2' */
  real32_T Add1_m;                     /* '<S18>/Add1' */
  real32_T Gain3;                      /* '<S18>/Gain3' */
  real32_T Gain;                       /* '<S12>/Gain' */
  real32_T Sign;                       /* '<S30>/Sign' */
  real32_T Eta;                        /* '<S30>/Eta' */
  real32_T Sum_c;                      /* '<S30>/Sum' */
  real32_T b;                          /* '<S30>/b' */
  real32_T a_n;                        /* '<S30>/a' */
  real32_T Sum1_n;                     /* '<S30>/Sum1' */
  real32_T Sign_b;                     /* '<S31>/Sign' */
  real32_T Eta_h;                      /* '<S31>/Eta' */
  real32_T Sum_l;                      /* '<S31>/Sum' */
  real32_T b_j;                        /* '<S31>/b' */
  real32_T a_k;                        /* '<S31>/a' */
  real32_T Sum1_m;                     /* '<S31>/Sum1' */
  real32_T DTC;                        /* '<S52>/DTC' */
  real32_T SpeedGain;                  /* '<S35>/SpeedGain' */
  real32_T Switch1_d[2];               /* '<S34>/Switch1' */
  real32_T Product_m;                  /* '<S50>/Product' */
  real32_T UnitDelay_i;                /* '<S50>/Unit Delay' */
  real32_T Product1_l2;                /* '<S50>/Product1' */
  real32_T Add1_g;                     /* '<S50>/Add1' */
  real32_T DeadZone;                   /* '<S134>/DeadZone' */
  real32_T IProdOut;                   /* '<S139>/IProd Out' */
  real32_T Switch_g;                   /* '<S132>/Switch' */
  real32_T DeadZone_h;                 /* '<S187>/DeadZone' */
  real32_T IProdOut_b;                 /* '<S192>/IProd Out' */
  real32_T Switch_e;                   /* '<S185>/Switch' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two;               /* '<S81>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S81>/one_by_two' */
  real32_T add_c;                      /* '<S81>/add_c' */
  real32_T Kc;                         /* '<S81>/Kc' */
  real32_T add_b;                      /* '<S81>/add_b' */
  real32_T Kb;                         /* '<S81>/Kb' */
  real32_T Ka;                         /* '<S81>/Ka' */
  real32_T Min;                        /* '<S78>/Min' */
  real32_T Max;                        /* '<S78>/Max' */
  real32_T Add;                        /* '<S78>/Add' */
  real32_T one_by_two_k;               /* '<S78>/one_by_two' */
  real32_T Add2;                       /* '<S77>/Add2' */
  real32_T Add1_k;                     /* '<S77>/Add1' */
  real32_T Add3;                       /* '<S77>/Add3' */
  real32_T Gain_j[3];                  /* '<S77>/Gain' */
  real32_T Gain_n[3];                  /* '<S18>/Gain' */
  real32_T Add_c[3];                   /* '<S18>/Add' */
  real32_T Gain1[3];                   /* '<S18>/Gain1' */
  real32_T Product_c[2];               /* '<S96>/Product' */
  real32_T SquareRoot;                 /* '<S96>/Square Root' */
  real32_T Switch_k;                   /* '<S96>/Switch' */
  real32_T Switch_f[2];                /* '<S93>/Switch' */
  real32_T Switch2;                    /* '<S103>/Switch2' */
  real32_T Product_mt;                 /* '<S102>/Product' */
  real32_T Sum_e;                      /* '<S102>/Sum' */
  real32_T Product2;                   /* '<S102>/Product2' */
  real32_T Merge_an;                   /* '<S102>/Merge' */
  real32_T Gain_p;                     /* '<S102>/Gain' */
  real32_T Switch_n;                   /* '<S103>/Switch' */
  real32_T Switch1_m;                  /* '<S104>/Switch1' */
  real32_T Sqrt;                       /* '<S104>/Sqrt' */
  real32_T Gain_i;                     /* '<S104>/Gain' */
  real32_T Convert_back;               /* '<S88>/Convert_back' */
  real32_T Convert_back_k;             /* '<S87>/Convert_back' */
  real32_T bcos;                       /* '<S82>/bcos' */
  real32_T asin_f;                     /* '<S82>/asin' */
  real32_T sum_Qs;                     /* '<S82>/sum_Qs' */
  real32_T acos_f;                     /* '<S82>/acos' */
  real32_T bsin;                       /* '<S82>/bsin' */
  real32_T sum_Ds;                     /* '<S82>/sum_Ds' */
  real32_T Switch_d[2];                /* '<S83>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Unary_Minus;                /* '<S83>/Unary_Minus' */
  real32_T qcos;                       /* '<S73>/qcos' */
  real32_T dsin;                       /* '<S73>/dsin' */
  real32_T sum_beta;                   /* '<S73>/sum_beta' */
  real32_T dcos;                       /* '<S73>/dcos' */
  real32_T qsin;                       /* '<S73>/qsin' */
  real32_T sum_alpha;                  /* '<S73>/sum_alpha' */
  real32_T Switch_p[2];                /* '<S74>/Switch' */
  real32_T algDD_o1_a;
  real32_T algDD_o2_j;
  real32_T Unary_Minus_i;              /* '<S74>/Unary_Minus' */
  real32_T a_plus_2b;                  /* '<S72>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S72>/one_by_sqrt3' */
  real32_T algDD_o1_j;
  real32_T algDD_o2_e;
  real32_T Add_g;                      /* '<S63>/Add' */
  real32_T DataTypeConversion1_p;      /* '<S63>/Data Type Conversion1' */
  real32_T Add1_mo;                    /* '<S63>/Add1' */
  real32_T Input;                      /* '<S64>/Input' */
  real32_T DataStoreRead_j;            /* '<S61>/Data Store Read' */
  real32_T Add1_e;                     /* '<S61>/Add1' */
  real32_T SaturatetomotorcalibSpeedRPM;
                                /* '<S61>/Saturate to 'motor.calibSpeed' RPM' */
  real32_T scaleOut;                   /* '<S62>/scaleOut' */
  real32_T AngleConversion;            /* '<S28>/AngleConversion' */
  real32_T Product_b1;                 /* '<S36>/Product' */
  real32_T Product2_d;                 /* '<S36>/Product2' */
  real32_T Sum1_k;                     /* '<S36>/Sum1' */
  real32_T Product1_li;                /* '<S36>/Product1' */
  real32_T Product3;                   /* '<S36>/Product3' */
  real32_T Sum2_et;                    /* '<S36>/Sum2' */
  real32_T Switch_o3;                  /* '<S36>/Switch' */
  real32_T Atan2;                      /* '<S53>/Atan2' */
  real32_T Switch_nl;                  /* '<S53>/Switch' */
  real32_T algDD;
  real32_T Gain_d;                     /* '<S54>/Gain' */
  real32_T Switch_kk;                  /* '<S54>/Switch' */
  real32_T Bias;                       /* '<S54>/Bias' */
  real32_T Bias_d;                     /* '<S36>/Bias' */
  real32_T Sum_bn;                     /* '<S34>/Sum' */
  real32_T Sum_lt;                     /* '<S33>/Sum' */
  real32_T Sum_d;                      /* '<S32>/Sum' */
  int32_T DataTypeConversion[2];       /* '<S55>/Data Type Conversion' */
  int32_T Add_a[2];                    /* '<S55>/Add' */
  int32_T SpeedCount;                  /* '<S35>/SpeedCount' */
  uint16_T UARTUSARTWrite;             /* '<S220>/UART//USART Write' */
  uint16_T Switch1_i;                  /* '<S94>/Switch1' */
  uint16_T DataTypeConversion_a;       /* '<S85>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S69>/Get_Integer' */
  uint16_T DataTypeConversion_f;       /* '<S92>/Data Type Conversion' */
  uint16_T DataTypeConversion_h;       /* '<S102>/Data Type Conversion' */
  uint16_T AnalogtoDigitalConverter[2];/* '<S20>/Analog to Digital Converter' */
  int16_T DataStoreRead_a;             /* '<S55>/Data Store Read' */
  int16_T DataStoreRead1;              /* '<S55>/Data Store Read1' */
  int16_T Convert_uint16;              /* '<S88>/Convert_uint16' */
  int16_T Convert_uint16_f;            /* '<S87>/Convert_uint16' */
  int16_T DataTypeConversion_i;        /* '<S63>/Data Type Conversion' */
  int16_T Switch_gg;                   /* '<S37>/Switch' */
  int8_T Switch1_dl;                   /* '<S132>/Switch1' */
  int8_T Switch2_g;                    /* '<S132>/Switch2' */
  int8_T Switch1_c;                    /* '<S185>/Switch1' */
  int8_T Switch2_m;                    /* '<S185>/Switch2' */
  boolean_T UnitDelay_f;               /* '<S1>/Unit Delay' */
  boolean_T NOT2;                      /* '<S1>/NOT2' */
  boolean_T AND;                       /* '<S1>/AND' */
  boolean_T NOT;                       /* '<S220>/NOT' */
  boolean_T DataStoreRead_b;           /* '<S2>/Data Store Read' */
  boolean_T LogicalOperator;           /* '<S14>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S29>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S29>/BetaRelay' */
  boolean_T DataStoreRead_c;           /* '<S16>/Data Store Read' */
  boolean_T Compare;                   /* '<S56>/Compare' */
  boolean_T NOT_c;                     /* '<S16>/NOT' */
  boolean_T NOT_b;                     /* '<S62>/NOT' */
  boolean_T Compare_f;                 /* '<S86>/Compare' */
  boolean_T DataStoreRead_l;           /* '<S17>/Data Store Read' */
  boolean_T LogicalOperator_n;         /* '<S91>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S90>/Logical Operator1' */
  boolean_T DataStoreRead1_n;          /* '<S18>/Data Store Read1' */
  boolean_T RelationalOperator;        /* '<S132>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S132>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S132>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S132>/Equal1' */
  boolean_T AND3;                      /* '<S132>/AND3' */
  boolean_T RelationalOperator_l;      /* '<S185>/Relational Operator' */
  boolean_T fixforDTpropagationissue_i;
                                     /* '<S185>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_m;
                                    /* '<S185>/fix for DT propagation issue1' */
  boolean_T Equal1_n;                  /* '<S185>/Equal1' */
  boolean_T AND3_m;                    /* '<S185>/AND3' */
  boolean_T RelationalOperator_j;      /* '<S92>/Relational Operator' */
  boolean_T Compare_e;                 /* '<S98>/Compare' */
  boolean_T Compare_n;                 /* '<S99>/Compare' */
  boolean_T LowerRelop1;               /* '<S103>/LowerRelop1' */
  boolean_T RelationalOperator_i;      /* '<S102>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S103>/UpperRelop' */
  boolean_T Delay_e;                   /* '<S63>/Delay' */
  boolean_T LogicalOperator_g;         /* '<S37>/Logical Operator' */
  boolean_T UnitDelay_a;               /* '<S8>/Unit Delay' */
  boolean_T NOT_n;                     /* '<S8>/NOT' */
  boolean_T DigitalPortRead;           /* '<S10>/Digital Port Read' */
} BlockIO_Motorparasmeters;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_UARTWrite_Moto obj; /* '<S220>/UART//USART Write' */
  stm32cube_blocks_UARTWrite_Moto obj_e;/* '<S221>/UART//USART Write' */
  stm32cube_blocks_AnalogInput_Mo obj_o;/* '<S20>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_Moto obj_e3;/* '<S214>/PWM Output' */
  uint64_T Add1_DWORK1;                /* '<S57>/Add1' */
  real32_T UnitDelay1_DSTATE;          /* '<S40>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S40>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S2>/Delay5' */
  real32_T Delay_DSTATE;               /* '<S30>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S40>/Delay1' */
  real32_T UnitDelay_DSTATE_b;         /* '<S44>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_m;        /* '<S41>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_p;         /* '<S41>/Unit Delay' */
  real32_T Delay_DSTATE_h;             /* '<S31>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S41>/Delay1' */
  real32_T UnitDelay_DSTATE_d;         /* '<S47>/Unit Delay' */
  real32_T Delay_DSTATE_p;             /* '<S28>/Delay' */
  real32_T UnitDelay_DSTATE_bp;        /* '<S62>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S195>/Integrator' */
  real32_T Integrator_DSTATE_l;        /* '<S142>/Integrator' */
  real32_T UnitDelay_DSTATE_bl;        /* '<S50>/Unit Delay' */
  uint32_T Delay_DSTATE_a[119];        /* '<S35>/Delay' */
  volatile real32_T RT1_Buffer[4];     /* '<Root>/RT1' */
  real32_T GlobleopenspeedInt;         /* '<S59>/Data Store Memory' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T Add_DWORK1[2];               /* '<S55>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S35>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S69>/Sum' */
  uint32_T CircBufIdx;                 /* '<S35>/Delay' */
  uint32_T statcount;                  /* '<S16>/Data Store Memory' */
  stm32cube_blocks_DigitalPortRea obj_k;/* '<S10>/Digital Port Read' */
  stm32cube_blocks_DigitalPortWri obj_kg;/* '<S219>/Digital Port Write' */
  int16_T IaOffset;                    /* '<Root>/Data Store Memory13' */
  int16_T IbOffset;                    /* '<Root>/Data Store Memory14' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S1>/Unit Delay' */
  boolean_T Delay_DSTATE_he;           /* '<S63>/Delay' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S8>/Unit Delay' */
  volatile int8_T RT1_ActiveBufIdx;    /* '<Root>/RT1' */
  volatile int8_T RT1_semaphoreTaken;  /* '<Root>/RT1' */
  int8_T Integrator_PrevResetState;    /* '<S195>/Integrator' */
  int8_T Integrator_PrevResetState_i;  /* '<S142>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory9' */
  boolean_T objisempty;                /* '<S220>/UART//USART Write' */
  boolean_T objisempty_a;              /* '<S221>/UART//USART Write' */
  boolean_T objisempty_n;              /* '<S219>/Digital Port Write' */
  boolean_T AlphaRelay_Mode;           /* '<S29>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S29>/BetaRelay' */
  boolean_T objisempty_k;              /* '<S214>/PWM Output' */
  boolean_T objisempty_o;              /* '<S20>/Analog to Digital Converter' */
  boolean_T objisempty_f;              /* '<S10>/Digital Port Read' */
} D_Work_Motorparasmeters;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S30>/Delay' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S40>/Delay1' */
  ZCSigState Delay_Reset_ZCE_c;        /* '<S31>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S41>/Delay1' */
  ZCSigState Delay_Reset_ZCE_n;        /* '<S28>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S29>/Dir_Sense' */
} PrevZCSigStates_Motorparasmeter;

/* Parameters (default storage) */
struct Parameters_Motorparasmeters_ {
  real_T SlidingModeObserver_CurrentObse;
                              /* Mask Parameter: SlidingModeObserver_CurrentObse
                               * Referenced by:
                               *   '<S30>/Eta'
                               *   '<S31>/Eta'
                               */
  real_T SlidingModeObserver_CutoffFreq;
                               /* Mask Parameter: SlidingModeObserver_CutoffFreq
                                * Referenced by: '<S28>/PhaseDelay'
                                */
  real_T SlidingModeObserver_Disturbance;
                              /* Mask Parameter: SlidingModeObserver_Disturbance
                               * Referenced by:
                               *   '<S40>/b_inv*g'
                               *   '<S41>/b_inv*g'
                               */
  real32_T DiscretePIControllerwithantiwin;
                              /* Mask Parameter: DiscretePIControllerwithantiwin
                               * Referenced by:
                               *   '<S202>/Saturation'
                               *   '<S187>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_f;
                              /* Mask Parameter: DiscretePIControllerwithantiw_f
                               * Referenced by:
                               *   '<S149>/Saturation'
                               *   '<S134>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_e;
                              /* Mask Parameter: DiscretePIControllerwithantiw_e
                               * Referenced by:
                               *   '<S202>/Saturation'
                               *   '<S187>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_b;
                              /* Mask Parameter: DiscretePIControllerwithantiw_b
                               * Referenced by:
                               *   '<S149>/Saturation'
                               *   '<S134>/DeadZone'
                               */
  uint32_T EnablePWMfor8seconds_const;
                                   /* Mask Parameter: EnablePWMfor8seconds_const
                                    * Referenced by: '<S56>/Constant'
                                    */
  uint16_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S98>/Constant'
                                       */
  uint16_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S99>/Constant'
                                      */
  uint16_T atan1_outputUnit;           /* Mask Parameter: atan1_outputUnit
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S37>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S37>/Constant1'
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
                                        * Referenced by: '<S32>/a'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S32>/One'
                                        */
  real32_T FilterConstant_Value;       /* Expression: Filter_constant
                                        * Referenced by: '<S32>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S32>/OneMinusFilterConstant'
                                         */
  real32_T a_Value_h;                  /* Computed Parameter: a_Value_h
                                        * Referenced by: '<S33>/a'
                                        */
  real32_T One_Value_c;                /* Computed Parameter: One_Value_c
                                        * Referenced by: '<S33>/One'
                                        */
  real32_T FilterConstant_Value_g;     /* Expression: Filter_constant
                                        * Referenced by: '<S33>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value_j;/* Expression: 1 - Filter_constant
                                           * Referenced by: '<S33>/OneMinusFilterConstant'
                                           */
  real32_T a_Value_i;                  /* Computed Parameter: a_Value_i
                                        * Referenced by: '<S34>/a'
                                        */
  real32_T One_Value_e;                /* Computed Parameter: One_Value_e
                                        * Referenced by: '<S34>/One'
                                        */
  real32_T FilterConstant_Value_o;     /* Expression: Filter_constant
                                        * Referenced by: '<S34>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value_n;/* Expression: 1 - Filter_constant
                                           * Referenced by: '<S34>/OneMinusFilterConstant'
                                           */
  real32_T Bias_Bias;                  /* Expression: single(2*pi)
                                        * Referenced by: '<S36>/Bias'
                                        */
  real32_T Bias_Bias_g;                /* Computed Parameter: Bias_Bias_g
                                        * Referenced by: '<S54>/Bias'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S54>/Gain'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S54>/Switch'
                                        */
  real32_T Switch_Threshold_k;         /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S36>/Switch'
                                        */
  real32_T AngleConversion_Gain;     /* Computed Parameter: AngleConversion_Gain
                                      * Referenced by: '<S28>/AngleConversion'
                                      */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S62>/scaleOut'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S60>/Constant'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S61>/Constant2'
                                        */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S61>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S61>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Multiply1_Gain;             /* Computed Parameter: Multiply1_Gain
                                        * Referenced by: '<S61>/Multiply1'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S64>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S63>/theta_e'
                                        */
  real32_T one_by_sqrt3_Gain;          /* Computed Parameter: one_by_sqrt3_Gain
                                        * Referenced by: '<S72>/one_by_sqrt3'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S104>/Constant'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S104>/Gain'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S104>/Switch1'
                                        */
  real32_T Switch_Threshold_c;         /* Computed Parameter: Switch_Threshold_c
                                        * Referenced by: '<S104>/Switch'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S102>/Gain'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S96>/Constant'
                                        */
  real32_T ReplaceInport_satLim_Value;
                               /* Computed Parameter: ReplaceInport_satLim_Value
                                * Referenced by: '<S89>/ReplaceInport_satLim'
                                */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S94>/Constant3'
                                        */
  real32_T Constant1_Value_a;          /* Computed Parameter: Constant1_Value_a
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S81>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S81>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S81>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S81>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S81>/Ka'
                                        */
  real32_T one_by_two_Gain_g;          /* Computed Parameter: one_by_two_Gain_g
                                        * Referenced by: '<S78>/one_by_two'
                                        */
  real32_T Gain_Gain_mr;               /* Computed Parameter: Gain_Gain_mr
                                        * Referenced by: '<S77>/Gain'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S18>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real32_T currentab_Y0;               /* Computed Parameter: currentab_Y0
                                        * Referenced by: '<S2>/currentab'
                                        */
  real32_T speed_Y0;                   /* Computed Parameter: speed_Y0
                                        * Referenced by: '<S2>/speed'
                                        */
  real32_T Rs_Y0;                      /* Computed Parameter: Rs_Y0
                                        * Referenced by: '<S2>/Rs'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S86>/Constant'
                                        */
  real32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S132>/Constant1'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S185>/Constant1'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S17>/Constant4'
                                        */
  real32_T ADvoltage_Gain;             /* Computed Parameter: ADvoltage_Gain
                                        * Referenced by: '<S55>/AD voltage'
                                        */
  real32_T OP_GainR_shunt_Gain;       /* Computed Parameter: OP_GainR_shunt_Gain
                                       * Referenced by: '<S55>/OP_Gain*R_shunt'
                                       */
  real32_T OP_GainR_shunt1_Gain;     /* Computed Parameter: OP_GainR_shunt1_Gain
                                      * Referenced by: '<S55>/OP_Gain*R_shunt1'
                                      */
  real32_T Kalpha_Gain;                /* Computed Parameter: Kalpha_Gain
                                        * Referenced by: '<S71>/Kalpha'
                                        */
  real32_T Kbeta_Gain;                 /* Computed Parameter: Kbeta_Gain
                                        * Referenced by: '<S71>/Kbeta'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S69>/sine_table_values'
                                   */
  real32_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S40>/Unit Delay1'
                               */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S40>/Unit Delay'
                                */
  real32_T a_Gain;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S40>/a'
   */
  real32_T Delay5_InitialCondition;
                                  /* Computed Parameter: Delay5_InitialCondition
                                   * Referenced by: '<S2>/Delay5'
                                   */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S30>/Delay'
                                    */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S40>/Delay1'
                                   */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S32>/UseInputPort'
                                        */
  real32_T Switch1_Threshold_b;       /* Computed Parameter: Switch1_Threshold_b
                                       * Referenced by: '<S32>/Switch1'
                                       */
  real32_T UnitDelay_InitialCondition_l;
                             /* Computed Parameter: UnitDelay_InitialCondition_l
                              * Referenced by: '<S44>/Unit Delay'
                              */
  real32_T AlphaRelay_OnVal;           /* Computed Parameter: AlphaRelay_OnVal
                                        * Referenced by: '<S29>/AlphaRelay'
                                        */
  real32_T AlphaRelay_OffVal;          /* Computed Parameter: AlphaRelay_OffVal
                                        * Referenced by: '<S29>/AlphaRelay'
                                        */
  real32_T UnitDelay1_InitialCondition_p;
                            /* Computed Parameter: UnitDelay1_InitialCondition_p
                             * Referenced by: '<S41>/Unit Delay1'
                             */
  real32_T UnitDelay_InitialCondition_i;
                             /* Computed Parameter: UnitDelay_InitialCondition_i
                              * Referenced by: '<S41>/Unit Delay'
                              */
  real32_T a_Gain_e;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S41>/a'
   */
  real32_T Delay_InitialCondition_e;
                                 /* Computed Parameter: Delay_InitialCondition_e
                                  * Referenced by: '<S31>/Delay'
                                  */
  real32_T Delay1_InitialCondition_m;
                                /* Computed Parameter: Delay1_InitialCondition_m
                                 * Referenced by: '<S41>/Delay1'
                                 */
  real32_T UseInputPort_Value_g;     /* Computed Parameter: UseInputPort_Value_g
                                      * Referenced by: '<S33>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_bx;     /* Computed Parameter: Switch1_Threshold_bx
                                      * Referenced by: '<S33>/Switch1'
                                      */
  real32_T UnitDelay_InitialCondition_p;
                             /* Computed Parameter: UnitDelay_InitialCondition_p
                              * Referenced by: '<S47>/Unit Delay'
                              */
  real32_T BetaRelay_OnVal;            /* Computed Parameter: BetaRelay_OnVal
                                        * Referenced by: '<S29>/BetaRelay'
                                        */
  real32_T BetaRelay_OffVal;           /* Computed Parameter: BetaRelay_OffVal
                                        * Referenced by: '<S29>/BetaRelay'
                                        */
  real32_T Delay_InitialCondition_b;
                                 /* Computed Parameter: Delay_InitialCondition_b
                                  * Referenced by: '<S28>/Delay'
                                  */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S62>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition_pr;
                            /* Computed Parameter: UnitDelay_InitialCondition_pr
                             * Referenced by: '<S62>/Unit Delay'
                             */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S85>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S69>/indexing'
                                        */
  real32_T Kp_Value;                   /* Computed Parameter: Kp_Value
                                        * Referenced by: '<S70>/Kp'
                                        */
  real32_T Vq_OpenLoop_Value;          /* Computed Parameter: Vq_OpenLoop_Value
                                        * Referenced by: '<S91>/Vq_OpenLoop'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S195>/Integrator'
                                        */
  real32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S17>/Constant5'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S90>/Constant'
                                        */
  real32_T Integrator_gainval_p;     /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S142>/Integrator'
                                      */
  real32_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S18>/Gain2'
                                        */
  real32_T Constant2_Value_p;          /* Computed Parameter: Constant2_Value_p
                                        * Referenced by: '<S18>/Constant2'
                                        */
  real32_T Gain3_Gain;                 /* Computed Parameter: Gain3_Gain
                                        * Referenced by: '<S18>/Gain3'
                                        */
  real32_T Gain_Gain_kz;               /* Computed Parameter: Gain_Gain_kz
                                        * Referenced by: '<S12>/Gain'
                                        */
  real32_T b_Gain;
  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S30>/b'
   */
  real32_T a_Gain_a;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S30>/a'
   */
  real32_T b_Gain_g;
  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S31>/b'
   */
  real32_T a_Gain_g;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S31>/a'
   */
  real32_T PositionToCount_Gain;     /* Computed Parameter: PositionToCount_Gain
                                      * Referenced by: '<S35>/PositionToCount'
                                      */
  real32_T SpeedGain_Gain;             /* Computed Parameter: SpeedGain_Gain
                                        * Referenced by: '<S35>/SpeedGain'
                                        */
  real32_T UseInputPort_Value_p;     /* Computed Parameter: UseInputPort_Value_p
                                      * Referenced by: '<S34>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_a;       /* Computed Parameter: Switch1_Threshold_a
                                       * Referenced by: '<S34>/Switch1'
                                       */
  real32_T UnitDelay_InitialCondition_j;
                             /* Computed Parameter: UnitDelay_InitialCondition_j
                              * Referenced by: '<S50>/Unit Delay'
                              */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S59>/Data Store Memory'
                              */
  real32_T Ki_Value;                   /* Computed Parameter: Ki_Value
                                        * Referenced by: '<S70>/Ki'
                                        */
  real32_T Clamping_zero_Value;       /* Computed Parameter: Clamping_zero_Value
                                       * Referenced by: '<S132>/Clamping_zero'
                                       */
  real32_T Clamping_zero_Value_k;   /* Computed Parameter: Clamping_zero_Value_k
                                     * Referenced by: '<S185>/Clamping_zero'
                                     */
  real32_T Constant_Value_nt[3];       /* Computed Parameter: Constant_Value_nt
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T RT1_InitialCondition;     /* Computed Parameter: RT1_InitialCondition
                                      * Referenced by: '<Root>/RT1'
                                      */
  uint32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S57>/Constant'
                                        */
  uint32_T Constant15_Value;           /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S58>/Constant15'
                                        */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S59>/Count for 2 sec'
                                        */
  uint32_T Delay_InitialCondition_i;
                                 /* Computed Parameter: Delay_InitialCondition_i
                                  * Referenced by: '<S35>/Delay'
                                  */
  uint32_T DataStoreMemory_InitialValue_b;
                           /* Computed Parameter: DataStoreMemory_InitialValue_b
                            * Referenced by: '<S16>/Data Store Memory'
                            */
  int16_T Sign_Y0;                     /* Computed Parameter: Sign_Y0
                                        * Referenced by: '<S37>/Sign'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S69>/offset'
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
                                        * Referenced by: '<S53>/Switch'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S74>/Offset'
                                        */
  uint16_T Switch_Threshold_kk;       /* Computed Parameter: Switch_Threshold_kk
                                       * Referenced by: '<S74>/Switch'
                                       */
  uint16_T Offset_Value_l;             /* Computed Parameter: Offset_Value_l
                                        * Referenced by: '<S83>/Offset'
                                        */
  uint16_T Switch_Threshold_g;         /* Computed Parameter: Switch_Threshold_g
                                        * Referenced by: '<S83>/Switch'
                                        */
  uint16_T ReplaceInport_satMethod_Value;
                            /* Computed Parameter: ReplaceInport_satMethod_Value
                             * Referenced by: '<S89>/ReplaceInport_satMethod'
                             */
  uint16_T ChosenMethod_Value;         /* Computed Parameter: ChosenMethod_Value
                                        * Referenced by: '<S94>/ChosenMethod'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S18>/stop'
                                        */
  uint16_T Out1_Y0_j;                  /* Computed Parameter: Out1_Y0_j
                                        * Referenced by: '<S2>/Out1'
                                        */
  uint16_T enableInportSatMethod_Value;
                              /* Computed Parameter: enableInportSatMethod_Value
                               * Referenced by: '<S94>/enableInportSatMethod'
                               */
  uint16_T enableInportSatLim_Value;
                                 /* Computed Parameter: enableInportSatLim_Value
                                  * Referenced by: '<S94>/enableInportSatLim'
                                  */
  boolean_T Out1_Y0_o;                 /* Computed Parameter: Out1_Y0_o
                                        * Referenced by: '<S8>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition_lg;/* Expression: true
                                           * Referenced by: '<S8>/Unit Delay'
                                           */
  boolean_T Delay_InitialCondition_n;
                                 /* Computed Parameter: Delay_InitialCondition_n
                                  * Referenced by: '<S63>/Delay'
                                  */
  boolean_T Constant_Value_a;          /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S63>/Constant'
                                        */
  boolean_T AlphaRelay_YOn;            /* Computed Parameter: AlphaRelay_YOn
                                        * Referenced by: '<S29>/AlphaRelay'
                                        */
  boolean_T AlphaRelay_YOff;           /* Computed Parameter: AlphaRelay_YOff
                                        * Referenced by: '<S29>/AlphaRelay'
                                        */
  boolean_T BetaRelay_YOn;             /* Computed Parameter: BetaRelay_YOn
                                        * Referenced by: '<S29>/BetaRelay'
                                        */
  boolean_T BetaRelay_YOff;            /* Computed Parameter: BetaRelay_YOff
                                        * Referenced by: '<S29>/BetaRelay'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S62>/Constant_Reset'
                                      */
  boolean_T UnitDelay_InitialCondition_e;/* Expression: false
                                          * Referenced by: '<S1>/Unit Delay'
                                          */
  boolean_T DataStoreMemory9_InitialValue;
                            /* Computed Parameter: DataStoreMemory9_InitialValue
                             * Referenced by: '<Root>/Data Store Memory9'
                             */
  int8_T Constant_Value_l;             /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S132>/Constant'
                                        */
  int8_T Constant2_Value_i;            /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S132>/Constant2'
                                        */
  int8_T Constant3_Value_m;            /* Computed Parameter: Constant3_Value_m
                                        * Referenced by: '<S132>/Constant3'
                                        */
  int8_T Constant4_Value_l;            /* Computed Parameter: Constant4_Value_l
                                        * Referenced by: '<S132>/Constant4'
                                        */
  int8_T Constant_Value_jm;            /* Computed Parameter: Constant_Value_jm
                                        * Referenced by: '<S185>/Constant'
                                        */
  int8_T Constant2_Value_e;            /* Computed Parameter: Constant2_Value_e
                                        * Referenced by: '<S185>/Constant2'
                                        */
  int8_T Constant3_Value_h;            /* Computed Parameter: Constant3_Value_h
                                        * Referenced by: '<S185>/Constant3'
                                        */
  int8_T Constant4_Value_m;            /* Computed Parameter: Constant4_Value_m
                                        * Referenced by: '<S185>/Constant4'
                                        */
  uint8_T Constant1_Value_f[4];        /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S221>/Constant1'
                                        */
  uint8_T Constant2_Value_n;           /* Computed Parameter: Constant2_Value_n
                                        * Referenced by: '<S221>/Constant2'
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
                                        * Referenced by: '<S220>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Motorparasmeters {
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
extern Parameters_Motorparasmeters Motorparasmeters_P;

/* Block signals (default storage) */
extern BlockIO_Motorparasmeters Motorparasmeters_B;

/* Block states (default storage) */
extern D_Work_Motorparasmeters Motorparasmeters_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_Motorparasmeter Motorparasmeters_PrevZCSigState;

/* External function called from main */
extern void Motorparasmeters_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Motorparasmeters_initialize(void);
extern void Motorparasmeters_step0(void);
extern void Motorparasmeters_step1(void);
extern void Motorparasmeters_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Motorparasmeters *const Motorparasmeters_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC1_2_IRQHandler(void);
  void Motorparasmeters_configure_interrupts (void);
  void Motorparasmeters_unconfigure_interrupts (void);

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
 * '<Root>' : 'Motorparasmeters'
 * '<S1>'   : 'Motorparasmeters/Button start'
 * '<S2>'   : 'Motorparasmeters/Function-Call Subsystem'
 * '<S3>'   : 'Motorparasmeters/Hardware Interrupt'
 * '<S4>'   : 'Motorparasmeters/Initialize Function'
 * '<S5>'   : 'Motorparasmeters/LED Heart'
 * '<S6>'   : 'Motorparasmeters/Subsystem1'
 * '<S7>'   : 'Motorparasmeters/Button start/Digital Port Read'
 * '<S8>'   : 'Motorparasmeters/Button start/Enabled Subsystem'
 * '<S9>'   : 'Motorparasmeters/Button start/Digital Port Read/ECSoC'
 * '<S10>'  : 'Motorparasmeters/Button start/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S11>'  : 'Motorparasmeters/Function-Call Subsystem/Analog to Digital Converter'
 * '<S12>'  : 'Motorparasmeters/Function-Call Subsystem/Caculate parasmeters'
 * '<S13>'  : 'Motorparasmeters/Function-Call Subsystem/Counter Limited'
 * '<S14>'  : 'Motorparasmeters/Function-Call Subsystem/SMO'
 * '<S15>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem1'
 * '<S16>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2'
 * '<S17>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3'
 * '<S18>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem4'
 * '<S19>'  : 'Motorparasmeters/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S20>'  : 'Motorparasmeters/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S21>'  : 'Motorparasmeters/Function-Call Subsystem/Caculate parasmeters/Power caculation'
 * '<S22>'  : 'Motorparasmeters/Function-Call Subsystem/Caculate parasmeters/Power caculation/IIR Filter'
 * '<S23>'  : 'Motorparasmeters/Function-Call Subsystem/Caculate parasmeters/Power caculation/IIR Filter/IIR Filter'
 * '<S24>'  : 'Motorparasmeters/Function-Call Subsystem/Caculate parasmeters/Power caculation/IIR Filter/IIR Filter/Low-pass'
 * '<S25>'  : 'Motorparasmeters/Function-Call Subsystem/Caculate parasmeters/Power caculation/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S26>'  : 'Motorparasmeters/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S27>'  : 'Motorparasmeters/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S28>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer'
 * '<S29>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch'
 * '<S30>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Ealpha_est'
 * '<S31>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Ebeta_est'
 * '<S32>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha'
 * '<S33>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta'
 * '<S34>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter'
 * '<S35>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement'
 * '<S36>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation'
 * '<S37>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S38>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S39>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S40>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S41>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S42>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S43>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S44>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S45>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S46>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S47>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S48>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S49>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S50>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S51>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S52>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S53>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation/atan1'
 * '<S54>'  : 'Motorparasmeters/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 * '<S55>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem1/Feedbackt_Current'
 * '<S56>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/Enable PWM for 8 seconds'
 * '<S57>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/If Action Subsystem2'
 * '<S58>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/If Action Subsystem3'
 * '<S59>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/Subsystem1'
 * '<S60>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/Subsystem1/If Action Subsystem'
 * '<S61>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/Subsystem1/If Action Subsystem2'
 * '<S62>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator'
 * '<S63>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator/Accumulate'
 * '<S64>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S65>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Clarke Transform'
 * '<S66>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Inverse Park Transform'
 * '<S67>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/PWM Reference Generator'
 * '<S68>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Park Transform1'
 * '<S69>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup'
 * '<S70>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem'
 * '<S71>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Clarke Transform/Two phase input'
 * '<S72>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S73>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Inverse Park Transform/Two inputs CRL'
 * '<S74>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S75>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method'
 * '<S76>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input'
 * '<S77>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method/SVPWM'
 * '<S78>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S79>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S80>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S81>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S82>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Park Transform1/Two inputs CRL'
 * '<S83>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Park Transform1/Two inputs CRL/Switch_Axis'
 * '<S84>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/Interpolation'
 * '<S85>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp'
 * '<S86>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S87>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S88>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S89>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter'
 * '<S90>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id'
 * '<S91>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq'
 * '<S92>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence'
 * '<S93>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority'
 * '<S94>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/Inport//Dialog Selection'
 * '<S95>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/Magnitude_calc'
 * '<S96>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S97>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S98>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S99>'  : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S100>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S101>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S102>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S103>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S104>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S105>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S106>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S107>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S108>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S109>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S110>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S111>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S112>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S113>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S114>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S115>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S116>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S117>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S118>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S119>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S120>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S121>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S122>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S123>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S124>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S125>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S126>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S127>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S128>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S129>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S130>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S131>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S132>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S133>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S134>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S135>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S136>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S137>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S138>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S139>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S140>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S141>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S142>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S143>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S144>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S145>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S146>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S147>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S148>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S149>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S150>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S151>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S152>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S153>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S154>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S155>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S156>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S157>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S158>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S159>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S160>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S161>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S162>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S163>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S164>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S165>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S166>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S167>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S168>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S169>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S170>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S171>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S172>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S173>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S174>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S175>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S176>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S177>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S178>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S179>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S180>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S181>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S182>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S183>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S184>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S185>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S186>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S187>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S188>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S189>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S190>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S191>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S192>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S193>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S194>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S195>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S196>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S197>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S198>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S199>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S200>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S201>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S202>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S203>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S204>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S205>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S206>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S207>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S208>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S209>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S210>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S211>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S212>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem4/PWM Output'
 * '<S213>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem4/PWM Output/ECSoC'
 * '<S214>' : 'Motorparasmeters/Function-Call Subsystem/Subsystem4/PWM Output/ECSoC/ECSimCodegen'
 * '<S215>' : 'Motorparasmeters/Hardware Interrupt/ECSoC'
 * '<S216>' : 'Motorparasmeters/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S217>' : 'Motorparasmeters/LED Heart/Digital Port Write'
 * '<S218>' : 'Motorparasmeters/LED Heart/Digital Port Write/ECSoC'
 * '<S219>' : 'Motorparasmeters/LED Heart/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S220>' : 'Motorparasmeters/Subsystem1/Subsystem'
 * '<S221>' : 'Motorparasmeters/Subsystem1/Subsystem/Enabled Subsystem'
 */
#endif                                 /* Motorparasmeters_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
