/*
 * File: IFstart.h
 *
 * Code generated for Simulink model 'IFstart'.
 *
 * Model version                  : 8.20
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Nov 25 09:02:04 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef IFstart_h_
#define IFstart_h_
#ifndef IFstart_COMMON_INCLUDES_
#define IFstart_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#include "stm_lpuart.h"
#endif                                 /* IFstart_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "IFstart_types.h"
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
  uint32_T Sum[4];                     /* '<S68>/Sum' */
  uint32_T PositionToCount;            /* '<S34>/PositionToCount' */
  uint32_T Delay;                      /* '<S34>/Delay' */
  uint32_T DataStoreRead;              /* '<S56>/Data Store Read' */
  uint32_T Add1;                       /* '<S56>/Add1' */
  real32_T RT_n;                       /* '<Root>/RT' */
  real32_T Assignment[3];              /* '<S6>/Assignment' */
  real32_T RT1[2];                     /* '<Root>/RT1' */
  real32_T Assignment1[3];             /* '<S6>/Assignment1' */
  real32_T Assignment2[3];             /* '<S6>/Assignment2' */
  real32_T Switch[2];                  /* '<S17>/Switch' */
  real32_T ADvoltage[2];               /* '<S54>/AD voltage' */
  real32_T OP_GainR_shunt[2];          /* '<S54>/OP_Gain*R_shunt' */
  real32_T OP_GainR_shunt1[2];         /* '<S54>/OP_Gain*R_shunt1' */
  real32_T Kalpha;                     /* '<S70>/Kalpha' */
  real32_T Kbeta;                      /* '<S70>/Kbeta' */
  real32_T UnitDelay1;                 /* '<S39>/Unit Delay1' */
  real32_T UnitDelay;                  /* '<S39>/Unit Delay' */
  real32_T a;                          /* '<S39>/a' */
  real32_T Delay5[4];                  /* '<S2>/Delay5' */
  real32_T Delay_b;                    /* '<S29>/Delay' */
  real32_T Sum2;                       /* '<S29>/Sum2' */
  real32_T Sum3;                       /* '<S39>/Sum3' */
  real32_T b_invg;                     /* '<S39>/b_inv*g' */
  real32_T Delay1;                     /* '<S39>/Delay1' */
  real32_T Sum4;                       /* '<S39>/Sum4' */
  real32_T Switch1[2];                 /* '<S31>/Switch1' */
  real32_T Product;                    /* '<S43>/Product' */
  real32_T UnitDelay_e;                /* '<S43>/Unit Delay' */
  real32_T Product1;                   /* '<S43>/Product1' */
  real32_T Add1_o;                     /* '<S43>/Add1' */
  real32_T UnitDelay1_e;               /* '<S40>/Unit Delay1' */
  real32_T UnitDelay_c;                /* '<S40>/Unit Delay' */
  real32_T a_c;                        /* '<S40>/a' */
  real32_T Delay_f;                    /* '<S30>/Delay' */
  real32_T Sum2_e;                     /* '<S30>/Sum2' */
  real32_T Sum3_m;                     /* '<S40>/Sum3' */
  real32_T b_invg_d;                   /* '<S40>/b_inv*g' */
  real32_T Delay1_f;                   /* '<S40>/Delay1' */
  real32_T Sum4_d;                     /* '<S40>/Sum4' */
  real32_T Switch1_o[2];               /* '<S32>/Switch1' */
  real32_T Product_b;                  /* '<S46>/Product' */
  real32_T UnitDelay_m;                /* '<S46>/Unit Delay' */
  real32_T Product1_l;                 /* '<S46>/Product1' */
  real32_T Add1_p;                     /* '<S46>/Add1' */
  real32_T Merge;                      /* '<S28>/Merge' */
  real32_T Merge1;                     /* '<S28>/Merge1' */
  real32_T Delay_fn;                   /* '<S27>/Delay' */
  real32_T PhaseDelay;                 /* '<S27>/PhaseDelay' */
  real32_T AngleConversion;            /* '<S27>/AngleConversion' */
  real32_T Merge_a;                    /* '<S58>/Merge' */
  real32_T scaleIn;                    /* '<S61>/scaleIn' */
  real32_T UnitDelay_h;                /* '<S61>/Unit Delay' */
  real32_T Switch_n;                   /* '<S15>/Switch' */
  real32_T convert_pu;                 /* '<S84>/convert_pu' */
  real32_T Merge_e;                    /* '<S84>/Merge' */
  real32_T indexing;                   /* '<S68>/indexing' */
  real32_T Lookup[4];                  /* '<S68>/Lookup' */
  real32_T Sum3_i;                     /* '<S83>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S68>/Data Type Conversion1' */
  real32_T Sum2_g;                     /* '<S68>/Sum2' */
  real32_T Product_h;                  /* '<S83>/Product' */
  real32_T Sum4_h;                     /* '<S83>/Sum4' */
  real32_T Sum5;                       /* '<S83>/Sum5' */
  real32_T Product1_k;                 /* '<S83>/Product1' */
  real32_T Sum6;                       /* '<S83>/Sum6' */
  real32_T Sum_k;                      /* '<S90>/Sum' */
  real32_T PProdOut;                   /* '<S199>/PProd Out' */
  real32_T Vq_OpenLoop;                /* '<S90>/Vq_OpenLoop' */
  real32_T Integrator;                 /* '<S194>/Integrator' */
  real32_T Sum_i;                      /* '<S203>/Sum' */
  real32_T Saturation;                 /* '<S201>/Saturation' */
  real32_T Sum_b;                      /* '<S89>/Sum' */
  real32_T PProdOut_i;                 /* '<S146>/PProd Out' */
  real32_T Constant;                   /* '<S89>/Constant' */
  real32_T Integrator_a;               /* '<S141>/Integrator' */
  real32_T Sum_o;                      /* '<S150>/Sum' */
  real32_T Saturation_h;               /* '<S148>/Saturation' */
  real32_T Switch_o;                   /* '<S93>/Switch' */
  real32_T Product_i;                  /* '<S93>/Product' */
  real32_T Product_hz;                 /* '<S94>/Product' */
  real32_T Product1_n;                 /* '<S94>/Product1' */
  real32_T Sum1;                       /* '<S94>/Sum1' */
  real32_T Merge_f[2];                 /* '<S88>/Merge' */
  real32_T Switch4[3];                 /* '<S18>/Switch4' */
  real32_T Sign;                       /* '<S29>/Sign' */
  real32_T Eta;                        /* '<S29>/Eta' */
  real32_T Sum_c;                      /* '<S29>/Sum' */
  real32_T b;                          /* '<S29>/b' */
  real32_T a_n;                        /* '<S29>/a' */
  real32_T Sum1_n;                     /* '<S29>/Sum1' */
  real32_T Sign_b;                     /* '<S30>/Sign' */
  real32_T Eta_h;                      /* '<S30>/Eta' */
  real32_T Sum_l;                      /* '<S30>/Sum' */
  real32_T b_j;                        /* '<S30>/b' */
  real32_T a_k;                        /* '<S30>/a' */
  real32_T Sum1_m;                     /* '<S30>/Sum1' */
  real32_T DTC;                        /* '<S51>/DTC' */
  real32_T SpeedGain;                  /* '<S34>/SpeedGain' */
  real32_T Switch1_d[2];               /* '<S33>/Switch1' */
  real32_T Product_m;                  /* '<S49>/Product' */
  real32_T UnitDelay_i;                /* '<S49>/Unit Delay' */
  real32_T Product1_l2;                /* '<S49>/Product1' */
  real32_T Add1_g;                     /* '<S49>/Add1' */
  real32_T DeadZone;                   /* '<S133>/DeadZone' */
  real32_T IProdOut;                   /* '<S138>/IProd Out' */
  real32_T Switch_g;                   /* '<S131>/Switch' */
  real32_T DeadZone_h;                 /* '<S186>/DeadZone' */
  real32_T IProdOut_b;                 /* '<S191>/IProd Out' */
  real32_T Switch_e;                   /* '<S184>/Switch' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two;               /* '<S80>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S80>/one_by_two' */
  real32_T add_c;                      /* '<S80>/add_c' */
  real32_T Kc;                         /* '<S80>/Kc' */
  real32_T add_b;                      /* '<S80>/add_b' */
  real32_T Kb;                         /* '<S80>/Kb' */
  real32_T Ka;                         /* '<S80>/Ka' */
  real32_T Min;                        /* '<S77>/Min' */
  real32_T Max;                        /* '<S77>/Max' */
  real32_T Add;                        /* '<S77>/Add' */
  real32_T one_by_two_k;               /* '<S77>/one_by_two' */
  real32_T Add2;                       /* '<S76>/Add2' */
  real32_T Add1_k;                     /* '<S76>/Add1' */
  real32_T Add3;                       /* '<S76>/Add3' */
  real32_T Gain[3];                    /* '<S76>/Gain' */
  real32_T Gain_n[3];                  /* '<S18>/Gain' */
  real32_T Add_c[3];                   /* '<S18>/Add' */
  real32_T Gain1[3];                   /* '<S18>/Gain1' */
  real32_T Product_c[2];               /* '<S95>/Product' */
  real32_T SquareRoot;                 /* '<S95>/Square Root' */
  real32_T Switch_k;                   /* '<S95>/Switch' */
  real32_T Switch_f[2];                /* '<S92>/Switch' */
  real32_T Switch2;                    /* '<S102>/Switch2' */
  real32_T Product_mt;                 /* '<S101>/Product' */
  real32_T Sum_e;                      /* '<S101>/Sum' */
  real32_T Product2;                   /* '<S101>/Product2' */
  real32_T Merge_an;                   /* '<S101>/Merge' */
  real32_T Gain_p;                     /* '<S101>/Gain' */
  real32_T Switch_nw;                  /* '<S102>/Switch' */
  real32_T Switch1_m;                  /* '<S103>/Switch1' */
  real32_T Sqrt;                       /* '<S103>/Sqrt' */
  real32_T Gain_i;                     /* '<S103>/Gain' */
  real32_T Convert_back;               /* '<S87>/Convert_back' */
  real32_T Convert_back_k;             /* '<S86>/Convert_back' */
  real32_T bcos;                       /* '<S81>/bcos' */
  real32_T asin_f;                     /* '<S81>/asin' */
  real32_T sum_Qs;                     /* '<S81>/sum_Qs' */
  real32_T acos_f;                     /* '<S81>/acos' */
  real32_T bsin;                       /* '<S81>/bsin' */
  real32_T sum_Ds;                     /* '<S81>/sum_Ds' */
  real32_T Switch_d[2];                /* '<S82>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T Unary_Minus;                /* '<S82>/Unary_Minus' */
  real32_T qcos;                       /* '<S72>/qcos' */
  real32_T dsin;                       /* '<S72>/dsin' */
  real32_T sum_beta;                   /* '<S72>/sum_beta' */
  real32_T dcos;                       /* '<S72>/dcos' */
  real32_T qsin;                       /* '<S72>/qsin' */
  real32_T sum_alpha;                  /* '<S72>/sum_alpha' */
  real32_T Switch_p[2];                /* '<S73>/Switch' */
  real32_T algDD_o1_a;
  real32_T algDD_o2_j;
  real32_T Unary_Minus_i;              /* '<S73>/Unary_Minus' */
  real32_T a_plus_2b;                  /* '<S71>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S71>/one_by_sqrt3' */
  real32_T algDD_o1_j;
  real32_T algDD_o2_e;
  real32_T Add_g;                      /* '<S62>/Add' */
  real32_T DataTypeConversion1_p;      /* '<S62>/Data Type Conversion1' */
  real32_T Add1_m;                     /* '<S62>/Add1' */
  real32_T Input;                      /* '<S63>/Input' */
  real32_T DataStoreRead_j;            /* '<S60>/Data Store Read' */
  real32_T Add1_e;                     /* '<S60>/Add1' */
  real32_T SaturatetomotorcalibSpeedRPM;
                                /* '<S60>/Saturate to 'motor.calibSpeed' RPM' */
  real32_T scaleOut;                   /* '<S61>/scaleOut' */
  real32_T Product_b1;                 /* '<S35>/Product' */
  real32_T Product2_d;                 /* '<S35>/Product2' */
  real32_T Sum1_k;                     /* '<S35>/Sum1' */
  real32_T Product1_li;                /* '<S35>/Product1' */
  real32_T Product3;                   /* '<S35>/Product3' */
  real32_T Sum2_et;                    /* '<S35>/Sum2' */
  real32_T Switch_o3;                  /* '<S35>/Switch' */
  real32_T Atan2;                      /* '<S52>/Atan2' */
  real32_T Switch_nl;                  /* '<S52>/Switch' */
  real32_T algDD;
  real32_T Gain_d;                     /* '<S53>/Gain' */
  real32_T Switch_kk;                  /* '<S53>/Switch' */
  real32_T Bias;                       /* '<S53>/Bias' */
  real32_T Bias_d;                     /* '<S35>/Bias' */
  real32_T Sum_bn;                     /* '<S33>/Sum' */
  real32_T Sum_lt;                     /* '<S32>/Sum' */
  real32_T Sum_d;                      /* '<S31>/Sum' */
  int32_T DataTypeConversion[2];       /* '<S54>/Data Type Conversion' */
  int32_T Add_a[2];                    /* '<S54>/Add' */
  int32_T SpeedCount;                  /* '<S34>/SpeedCount' */
  uint16_T UARTUSARTWrite;             /* '<S219>/UART//USART Write' */
  uint16_T Switch1_i;                  /* '<S93>/Switch1' */
  uint16_T DataTypeConversion_a;       /* '<S84>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S68>/Get_Integer' */
  uint16_T DataTypeConversion_f;       /* '<S91>/Data Type Conversion' */
  uint16_T DataTypeConversion_h;       /* '<S101>/Data Type Conversion' */
  uint16_T AnalogtoDigitalConverter[2];/* '<S20>/Analog to Digital Converter' */
  int16_T DataStoreRead_a;             /* '<S54>/Data Store Read' */
  int16_T DataStoreRead1;              /* '<S54>/Data Store Read1' */
  int16_T Convert_uint16;              /* '<S87>/Convert_uint16' */
  int16_T Convert_uint16_f;            /* '<S86>/Convert_uint16' */
  int16_T DataTypeConversion_i;        /* '<S62>/Data Type Conversion' */
  int16_T Switch_gg;                   /* '<S36>/Switch' */
  int8_T Switch1_dl;                   /* '<S131>/Switch1' */
  int8_T Switch2_g;                    /* '<S131>/Switch2' */
  int8_T Switch1_c;                    /* '<S184>/Switch1' */
  int8_T Switch2_m;                    /* '<S184>/Switch2' */
  boolean_T UnitDelay_f;               /* '<S1>/Unit Delay' */
  boolean_T NOT2;                      /* '<S1>/NOT2' */
  boolean_T AND;                       /* '<S1>/AND' */
  boolean_T NOT;                       /* '<S219>/NOT' */
  boolean_T DataStoreRead_c;           /* '<S16>/Data Store Read' */
  boolean_T Compare;                   /* '<S55>/Compare' */
  boolean_T NOT_c;                     /* '<S16>/NOT' */
  boolean_T DataStoreRead_b;           /* '<S2>/Data Store Read' */
  boolean_T LogicalOperator;           /* '<S14>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S28>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S28>/BetaRelay' */
  boolean_T NOT_b;                     /* '<S61>/NOT' */
  boolean_T Compare_f;                 /* '<S85>/Compare' */
  boolean_T DataStoreRead_e;           /* '<S17>/Data Store Read' */
  boolean_T LogicalOperator_n;         /* '<S90>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S89>/Logical Operator1' */
  boolean_T DataStoreRead1_n;          /* '<S18>/Data Store Read1' */
  boolean_T RelationalOperator;        /* '<S131>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S131>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S131>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S131>/Equal1' */
  boolean_T AND3;                      /* '<S131>/AND3' */
  boolean_T RelationalOperator_l;      /* '<S184>/Relational Operator' */
  boolean_T fixforDTpropagationissue_i;
                                     /* '<S184>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_m;
                                    /* '<S184>/fix for DT propagation issue1' */
  boolean_T Equal1_n;                  /* '<S184>/Equal1' */
  boolean_T AND3_m;                    /* '<S184>/AND3' */
  boolean_T RelationalOperator_j;      /* '<S91>/Relational Operator' */
  boolean_T Compare_e;                 /* '<S97>/Compare' */
  boolean_T Compare_n;                 /* '<S98>/Compare' */
  boolean_T LowerRelop1;               /* '<S102>/LowerRelop1' */
  boolean_T RelationalOperator_i;      /* '<S101>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S102>/UpperRelop' */
  boolean_T Delay_e;                   /* '<S62>/Delay' */
  boolean_T LogicalOperator_g;         /* '<S36>/Logical Operator' */
  boolean_T UnitDelay_a;               /* '<S8>/Unit Delay' */
  boolean_T NOT_n;                     /* '<S8>/NOT' */
  boolean_T DigitalPortRead;           /* '<S10>/Digital Port Read' */
} BlockIO_IFstart;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_UARTWrite_IFst obj; /* '<S219>/UART//USART Write' */
  stm32cube_blocks_UARTWrite_IFst obj_e;/* '<S220>/UART//USART Write' */
  stm32cube_blocks_AnalogInput_IF obj_o;/* '<S20>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_IFst obj_e3;/* '<S213>/PWM Output' */
  uint64_T Add1_DWORK1;                /* '<S56>/Add1' */
  real32_T UnitDelay1_DSTATE;          /* '<S39>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S39>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S2>/Delay5' */
  real32_T Delay_DSTATE;               /* '<S29>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S39>/Delay1' */
  real32_T UnitDelay_DSTATE_b;         /* '<S43>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_m;        /* '<S40>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_p;         /* '<S40>/Unit Delay' */
  real32_T Delay_DSTATE_h;             /* '<S30>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S40>/Delay1' */
  real32_T UnitDelay_DSTATE_d;         /* '<S46>/Unit Delay' */
  real32_T Delay_DSTATE_p;             /* '<S27>/Delay' */
  real32_T UnitDelay_DSTATE_bp;        /* '<S61>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S194>/Integrator' */
  real32_T Integrator_DSTATE_l;        /* '<S141>/Integrator' */
  real32_T UnitDelay_DSTATE_bl;        /* '<S49>/Unit Delay' */
  uint32_T Delay_DSTATE_a[119];        /* '<S34>/Delay' */
  volatile real32_T RT1_Buffer[4];     /* '<Root>/RT1' */
  real32_T GlobleopenspeedInt;         /* '<S58>/Data Store Memory' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T Add_DWORK1[2];               /* '<S54>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S34>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S68>/Sum' */
  uint32_T CircBufIdx;                 /* '<S34>/Delay' */
  uint32_T statcount;                  /* '<S16>/Data Store Memory' */
  stm32cube_blocks_DigitalPortRea obj_k;/* '<S10>/Digital Port Read' */
  stm32cube_blocks_DigitalPortWri obj_kg;/* '<S218>/Digital Port Write' */
  int16_T IaOffset;                    /* '<Root>/Data Store Memory13' */
  int16_T IbOffset;                    /* '<Root>/Data Store Memory14' */
  boolean_T UnitDelay_DSTATE_k;        /* '<S1>/Unit Delay' */
  boolean_T Delay_DSTATE_he;           /* '<S62>/Delay' */
  boolean_T UnitDelay_DSTATE_a;        /* '<S8>/Unit Delay' */
  volatile int8_T RT1_ActiveBufIdx;    /* '<Root>/RT1' */
  volatile int8_T RT1_semaphoreTaken;  /* '<Root>/RT1' */
  int8_T Integrator_PrevResetState;    /* '<S194>/Integrator' */
  int8_T Integrator_PrevResetState_i;  /* '<S141>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory9' */
  boolean_T objisempty;                /* '<S219>/UART//USART Write' */
  boolean_T objisempty_a;              /* '<S220>/UART//USART Write' */
  boolean_T objisempty_n;              /* '<S218>/Digital Port Write' */
  boolean_T AlphaRelay_Mode;           /* '<S28>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S28>/BetaRelay' */
  boolean_T objisempty_k;              /* '<S213>/PWM Output' */
  boolean_T objisempty_o;              /* '<S20>/Analog to Digital Converter' */
  boolean_T objisempty_f;              /* '<S10>/Digital Port Read' */
} D_Work_IFstart;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S29>/Delay' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S39>/Delay1' */
  ZCSigState Delay_Reset_ZCE_c;        /* '<S30>/Delay' */
  ZCSigState Delay1_Reset_ZCE_b;       /* '<S40>/Delay1' */
  ZCSigState Delay_Reset_ZCE_n;        /* '<S27>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S28>/Dir_Sense' */
} PrevZCSigStates_IFstart;

/* Parameters (default storage) */
struct Parameters_IFstart_ {
  real_T SlidingModeObserver_CurrentObse;
                              /* Mask Parameter: SlidingModeObserver_CurrentObse
                               * Referenced by:
                               *   '<S29>/Eta'
                               *   '<S30>/Eta'
                               */
  real_T SlidingModeObserver_CutoffFreq;
                               /* Mask Parameter: SlidingModeObserver_CutoffFreq
                                * Referenced by: '<S27>/PhaseDelay'
                                */
  real_T SlidingModeObserver_Disturbance;
                              /* Mask Parameter: SlidingModeObserver_Disturbance
                               * Referenced by:
                               *   '<S39>/b_inv*g'
                               *   '<S40>/b_inv*g'
                               */
  real32_T DiscretePIControllerwithantiwin;
                              /* Mask Parameter: DiscretePIControllerwithantiwin
                               * Referenced by:
                               *   '<S201>/Saturation'
                               *   '<S186>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_f;
                              /* Mask Parameter: DiscretePIControllerwithantiw_f
                               * Referenced by:
                               *   '<S148>/Saturation'
                               *   '<S133>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_e;
                              /* Mask Parameter: DiscretePIControllerwithantiw_e
                               * Referenced by:
                               *   '<S201>/Saturation'
                               *   '<S186>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_b;
                              /* Mask Parameter: DiscretePIControllerwithantiw_b
                               * Referenced by:
                               *   '<S148>/Saturation'
                               *   '<S133>/DeadZone'
                               */
  uint32_T EnablePWMfor8seconds_const;
                                   /* Mask Parameter: EnablePWMfor8seconds_const
                                    * Referenced by: '<S55>/Constant'
                                    */
  uint16_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S97>/Constant'
                                       */
  uint16_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S98>/Constant'
                                      */
  uint16_T atan1_outputUnit;           /* Mask Parameter: atan1_outputUnit
                                        * Referenced by: '<S52>/Constant'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S36>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S36>/Constant1'
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
                                        * Referenced by: '<S31>/a'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S31>/One'
                                        */
  real32_T FilterConstant_Value;       /* Expression: Filter_constant
                                        * Referenced by: '<S31>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value;/* Expression: 1 - Filter_constant
                                         * Referenced by: '<S31>/OneMinusFilterConstant'
                                         */
  real32_T a_Value_h;                  /* Computed Parameter: a_Value_h
                                        * Referenced by: '<S32>/a'
                                        */
  real32_T One_Value_c;                /* Computed Parameter: One_Value_c
                                        * Referenced by: '<S32>/One'
                                        */
  real32_T FilterConstant_Value_g;     /* Expression: Filter_constant
                                        * Referenced by: '<S32>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value_j;/* Expression: 1 - Filter_constant
                                           * Referenced by: '<S32>/OneMinusFilterConstant'
                                           */
  real32_T a_Value_i;                  /* Computed Parameter: a_Value_i
                                        * Referenced by: '<S33>/a'
                                        */
  real32_T One_Value_e;                /* Computed Parameter: One_Value_e
                                        * Referenced by: '<S33>/One'
                                        */
  real32_T FilterConstant_Value_o;     /* Expression: Filter_constant
                                        * Referenced by: '<S33>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value_n;/* Expression: 1 - Filter_constant
                                           * Referenced by: '<S33>/OneMinusFilterConstant'
                                           */
  real32_T Bias_Bias;                  /* Expression: single(2*pi)
                                        * Referenced by: '<S35>/Bias'
                                        */
  real32_T Bias_Bias_g;                /* Computed Parameter: Bias_Bias_g
                                        * Referenced by: '<S53>/Bias'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S53>/Gain'
                                        */
  real32_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S53>/Switch'
                                        */
  real32_T Switch_Threshold_k;         /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S35>/Switch'
                                        */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S61>/scaleOut'
                                        */
  real32_T Constant_Value_n;           /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S59>/Constant'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S60>/Constant2'
                                        */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S60>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S60>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Multiply1_Gain;             /* Computed Parameter: Multiply1_Gain
                                        * Referenced by: '<S60>/Multiply1'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S63>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S62>/theta_e'
                                        */
  real32_T one_by_sqrt3_Gain;          /* Computed Parameter: one_by_sqrt3_Gain
                                        * Referenced by: '<S71>/one_by_sqrt3'
                                        */
  real32_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S103>/Constant'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S103>/Gain'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S103>/Switch1'
                                        */
  real32_T Switch_Threshold_c;         /* Computed Parameter: Switch_Threshold_c
                                        * Referenced by: '<S103>/Switch'
                                        */
  real32_T Gain_Gain_n;                /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<S101>/Gain'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S95>/Constant'
                                        */
  real32_T ReplaceInport_satLim_Value;
                               /* Computed Parameter: ReplaceInport_satLim_Value
                                * Referenced by: '<S88>/ReplaceInport_satLim'
                                */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S93>/Constant3'
                                        */
  real32_T Constant5_Value;            /* Computed Parameter: Constant5_Value
                                        * Referenced by: '<S17>/Constant5'
                                        */
  real32_T Constant4_Value;            /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S17>/Constant4'
                                        */
  real32_T Constant6_Value;            /* Computed Parameter: Constant6_Value
                                        * Referenced by: '<S17>/Constant6'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real32_T Constant1_Value_a;          /* Computed Parameter: Constant1_Value_a
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S80>/sqrt3_by_two'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S80>/one_by_two'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S80>/Kc'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S80>/Kb'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S80>/Ka'
                                        */
  real32_T one_by_two_Gain_g;          /* Computed Parameter: one_by_two_Gain_g
                                        * Referenced by: '<S77>/one_by_two'
                                        */
  real32_T Gain_Gain_mr;               /* Computed Parameter: Gain_Gain_mr
                                        * Referenced by: '<S76>/Gain'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S18>/Gain'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real32_T theta_Y0;                   /* Computed Parameter: theta_Y0
                                        * Referenced by: '<S2>/theta'
                                        */
  real32_T currentab_Y0;               /* Computed Parameter: currentab_Y0
                                        * Referenced by: '<S2>/currentab'
                                        */
  real32_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S2>/Out2'
                                        */
  real32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S85>/Constant'
                                        */
  real32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S131>/Constant1'
                                        */
  real32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S184>/Constant1'
                                        */
  real32_T ADvoltage_Gain;             /* Computed Parameter: ADvoltage_Gain
                                        * Referenced by: '<S54>/AD voltage'
                                        */
  real32_T OP_GainR_shunt_Gain;       /* Computed Parameter: OP_GainR_shunt_Gain
                                       * Referenced by: '<S54>/OP_Gain*R_shunt'
                                       */
  real32_T OP_GainR_shunt1_Gain;     /* Computed Parameter: OP_GainR_shunt1_Gain
                                      * Referenced by: '<S54>/OP_Gain*R_shunt1'
                                      */
  real32_T Kalpha_Gain;                /* Computed Parameter: Kalpha_Gain
                                        * Referenced by: '<S70>/Kalpha'
                                        */
  real32_T Kbeta_Gain;                 /* Computed Parameter: Kbeta_Gain
                                        * Referenced by: '<S70>/Kbeta'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S68>/sine_table_values'
                                   */
  real32_T UnitDelay1_InitialCondition;
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<S39>/Unit Delay1'
                               */
  real32_T UnitDelay_InitialCondition;
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<S39>/Unit Delay'
                                */
  real32_T a_Gain;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S39>/a'
   */
  real32_T Delay5_InitialCondition;
                                  /* Computed Parameter: Delay5_InitialCondition
                                   * Referenced by: '<S2>/Delay5'
                                   */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S29>/Delay'
                                    */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S39>/Delay1'
                                   */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S31>/UseInputPort'
                                        */
  real32_T Switch1_Threshold_b;       /* Computed Parameter: Switch1_Threshold_b
                                       * Referenced by: '<S31>/Switch1'
                                       */
  real32_T UnitDelay_InitialCondition_l;
                             /* Computed Parameter: UnitDelay_InitialCondition_l
                              * Referenced by: '<S43>/Unit Delay'
                              */
  real32_T AlphaRelay_OnVal;           /* Computed Parameter: AlphaRelay_OnVal
                                        * Referenced by: '<S28>/AlphaRelay'
                                        */
  real32_T AlphaRelay_OffVal;          /* Computed Parameter: AlphaRelay_OffVal
                                        * Referenced by: '<S28>/AlphaRelay'
                                        */
  real32_T UnitDelay1_InitialCondition_p;
                            /* Computed Parameter: UnitDelay1_InitialCondition_p
                             * Referenced by: '<S40>/Unit Delay1'
                             */
  real32_T UnitDelay_InitialCondition_i;
                             /* Computed Parameter: UnitDelay_InitialCondition_i
                              * Referenced by: '<S40>/Unit Delay'
                              */
  real32_T a_Gain_e;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S40>/a'
   */
  real32_T Delay_InitialCondition_e;
                                 /* Computed Parameter: Delay_InitialCondition_e
                                  * Referenced by: '<S30>/Delay'
                                  */
  real32_T Delay1_InitialCondition_m;
                                /* Computed Parameter: Delay1_InitialCondition_m
                                 * Referenced by: '<S40>/Delay1'
                                 */
  real32_T UseInputPort_Value_g;     /* Computed Parameter: UseInputPort_Value_g
                                      * Referenced by: '<S32>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_bx;     /* Computed Parameter: Switch1_Threshold_bx
                                      * Referenced by: '<S32>/Switch1'
                                      */
  real32_T UnitDelay_InitialCondition_p;
                             /* Computed Parameter: UnitDelay_InitialCondition_p
                              * Referenced by: '<S46>/Unit Delay'
                              */
  real32_T BetaRelay_OnVal;            /* Computed Parameter: BetaRelay_OnVal
                                        * Referenced by: '<S28>/BetaRelay'
                                        */
  real32_T BetaRelay_OffVal;           /* Computed Parameter: BetaRelay_OffVal
                                        * Referenced by: '<S28>/BetaRelay'
                                        */
  real32_T Delay_InitialCondition_b;
                                 /* Computed Parameter: Delay_InitialCondition_b
                                  * Referenced by: '<S27>/Delay'
                                  */
  real32_T AngleConversion_Gain;     /* Computed Parameter: AngleConversion_Gain
                                      * Referenced by: '<S27>/AngleConversion'
                                      */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S61>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition_pr;
                            /* Computed Parameter: UnitDelay_InitialCondition_pr
                             * Referenced by: '<S61>/Unit Delay'
                             */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S84>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S68>/indexing'
                                        */
  real32_T Kp_Value;                   /* Computed Parameter: Kp_Value
                                        * Referenced by: '<S69>/Kp'
                                        */
  real32_T Vq_OpenLoop_Value;          /* Computed Parameter: Vq_OpenLoop_Value
                                        * Referenced by: '<S90>/Vq_OpenLoop'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S194>/Integrator'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S89>/Constant'
                                        */
  real32_T Integrator_gainval_p;     /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S141>/Integrator'
                                      */
  real32_T b_Gain;
  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S29>/b'
   */
  real32_T a_Gain_a;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S29>/a'
   */
  real32_T b_Gain_g;
  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S30>/b'
   */
  real32_T a_Gain_g;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S30>/a'
   */
  real32_T PositionToCount_Gain;     /* Computed Parameter: PositionToCount_Gain
                                      * Referenced by: '<S34>/PositionToCount'
                                      */
  real32_T SpeedGain_Gain;             /* Computed Parameter: SpeedGain_Gain
                                        * Referenced by: '<S34>/SpeedGain'
                                        */
  real32_T UseInputPort_Value_p;     /* Computed Parameter: UseInputPort_Value_p
                                      * Referenced by: '<S33>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_a;       /* Computed Parameter: Switch1_Threshold_a
                                       * Referenced by: '<S33>/Switch1'
                                       */
  real32_T UnitDelay_InitialCondition_j;
                             /* Computed Parameter: UnitDelay_InitialCondition_j
                              * Referenced by: '<S49>/Unit Delay'
                              */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S58>/Data Store Memory'
                              */
  real32_T Ki_Value;                   /* Computed Parameter: Ki_Value
                                        * Referenced by: '<S69>/Ki'
                                        */
  real32_T Clamping_zero_Value;       /* Computed Parameter: Clamping_zero_Value
                                       * Referenced by: '<S131>/Clamping_zero'
                                       */
  real32_T Clamping_zero_Value_k;   /* Computed Parameter: Clamping_zero_Value_k
                                     * Referenced by: '<S184>/Clamping_zero'
                                     */
  real32_T Constant_Value_nt[3];       /* Computed Parameter: Constant_Value_nt
                                        * Referenced by: '<S6>/Constant'
                                        */
  real32_T RT1_InitialCondition;     /* Computed Parameter: RT1_InitialCondition
                                      * Referenced by: '<Root>/RT1'
                                      */
  uint32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S56>/Constant'
                                        */
  uint32_T Constant15_Value;           /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S57>/Constant15'
                                        */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S58>/Count for 2 sec'
                                        */
  uint32_T Delay_InitialCondition_i;
                                 /* Computed Parameter: Delay_InitialCondition_i
                                  * Referenced by: '<S34>/Delay'
                                  */
  uint32_T DataStoreMemory_InitialValue_b;
                           /* Computed Parameter: DataStoreMemory_InitialValue_b
                            * Referenced by: '<S16>/Data Store Memory'
                            */
  int16_T Sign_Y0;                     /* Computed Parameter: Sign_Y0
                                        * Referenced by: '<S36>/Sign'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S68>/offset'
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
                                        * Referenced by: '<S52>/Switch'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S73>/Offset'
                                        */
  uint16_T Switch_Threshold_kk;       /* Computed Parameter: Switch_Threshold_kk
                                       * Referenced by: '<S73>/Switch'
                                       */
  uint16_T Offset_Value_l;             /* Computed Parameter: Offset_Value_l
                                        * Referenced by: '<S82>/Offset'
                                        */
  uint16_T Switch_Threshold_g;         /* Computed Parameter: Switch_Threshold_g
                                        * Referenced by: '<S82>/Switch'
                                        */
  uint16_T ReplaceInport_satMethod_Value;
                            /* Computed Parameter: ReplaceInport_satMethod_Value
                             * Referenced by: '<S88>/ReplaceInport_satMethod'
                             */
  uint16_T ChosenMethod_Value;         /* Computed Parameter: ChosenMethod_Value
                                        * Referenced by: '<S93>/ChosenMethod'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S18>/stop'
                                        */
  uint16_T Out1_Y0_j;                  /* Computed Parameter: Out1_Y0_j
                                        * Referenced by: '<S2>/Out1'
                                        */
  uint16_T enableInportSatMethod_Value;
                              /* Computed Parameter: enableInportSatMethod_Value
                               * Referenced by: '<S93>/enableInportSatMethod'
                               */
  uint16_T enableInportSatLim_Value;
                                 /* Computed Parameter: enableInportSatLim_Value
                                  * Referenced by: '<S93>/enableInportSatLim'
                                  */
  boolean_T Out1_Y0_o;                 /* Computed Parameter: Out1_Y0_o
                                        * Referenced by: '<S8>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition_lg;/* Expression: true
                                           * Referenced by: '<S8>/Unit Delay'
                                           */
  boolean_T Delay_InitialCondition_n;
                                 /* Computed Parameter: Delay_InitialCondition_n
                                  * Referenced by: '<S62>/Delay'
                                  */
  boolean_T Constant_Value_a;          /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S62>/Constant'
                                        */
  boolean_T AlphaRelay_YOn;            /* Computed Parameter: AlphaRelay_YOn
                                        * Referenced by: '<S28>/AlphaRelay'
                                        */
  boolean_T AlphaRelay_YOff;           /* Computed Parameter: AlphaRelay_YOff
                                        * Referenced by: '<S28>/AlphaRelay'
                                        */
  boolean_T BetaRelay_YOn;             /* Computed Parameter: BetaRelay_YOn
                                        * Referenced by: '<S28>/BetaRelay'
                                        */
  boolean_T BetaRelay_YOff;            /* Computed Parameter: BetaRelay_YOff
                                        * Referenced by: '<S28>/BetaRelay'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S61>/Constant_Reset'
                                      */
  boolean_T UnitDelay_InitialCondition_e;/* Expression: false
                                          * Referenced by: '<S1>/Unit Delay'
                                          */
  boolean_T DataStoreMemory9_InitialValue;
                            /* Computed Parameter: DataStoreMemory9_InitialValue
                             * Referenced by: '<Root>/Data Store Memory9'
                             */
  int8_T Constant_Value_l;             /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S131>/Constant'
                                        */
  int8_T Constant2_Value_i;            /* Computed Parameter: Constant2_Value_i
                                        * Referenced by: '<S131>/Constant2'
                                        */
  int8_T Constant3_Value_m;            /* Computed Parameter: Constant3_Value_m
                                        * Referenced by: '<S131>/Constant3'
                                        */
  int8_T Constant4_Value_l;            /* Computed Parameter: Constant4_Value_l
                                        * Referenced by: '<S131>/Constant4'
                                        */
  int8_T Constant_Value_jm;            /* Computed Parameter: Constant_Value_jm
                                        * Referenced by: '<S184>/Constant'
                                        */
  int8_T Constant2_Value_e;            /* Computed Parameter: Constant2_Value_e
                                        * Referenced by: '<S184>/Constant2'
                                        */
  int8_T Constant3_Value_h;            /* Computed Parameter: Constant3_Value_h
                                        * Referenced by: '<S184>/Constant3'
                                        */
  int8_T Constant4_Value_m;            /* Computed Parameter: Constant4_Value_m
                                        * Referenced by: '<S184>/Constant4'
                                        */
  uint8_T Constant1_Value_f[4];        /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S220>/Constant1'
                                        */
  uint8_T Constant2_Value_n;           /* Computed Parameter: Constant2_Value_n
                                        * Referenced by: '<S220>/Constant2'
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
                                        * Referenced by: '<S219>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_IFstart {
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
extern Parameters_IFstart IFstart_P;

/* Block signals (default storage) */
extern BlockIO_IFstart IFstart_B;

/* Block states (default storage) */
extern D_Work_IFstart IFstart_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_IFstart IFstart_PrevZCSigState;

/* External function called from main */
extern void IFstart_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void IFstart_initialize(void);
extern void IFstart_step0(void);
extern void IFstart_step1(void);
extern void IFstart_terminate(void);

/* Real-time Model object */
extern RT_MODEL_IFstart *const IFstart_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC1_2_IRQHandler(void);
  void IFstart_configure_interrupts (void);
  void IFstart_unconfigure_interrupts (void);

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
 * '<Root>' : 'IFstart'
 * '<S1>'   : 'IFstart/Button start'
 * '<S2>'   : 'IFstart/Function-Call Subsystem'
 * '<S3>'   : 'IFstart/Hardware Interrupt'
 * '<S4>'   : 'IFstart/Initialize Function'
 * '<S5>'   : 'IFstart/LED Heart'
 * '<S6>'   : 'IFstart/Subsystem1'
 * '<S7>'   : 'IFstart/Button start/Digital Port Read'
 * '<S8>'   : 'IFstart/Button start/Enabled Subsystem'
 * '<S9>'   : 'IFstart/Button start/Digital Port Read/ECSoC'
 * '<S10>'  : 'IFstart/Button start/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S11>'  : 'IFstart/Function-Call Subsystem/Analog to Digital Converter'
 * '<S12>'  : 'IFstart/Function-Call Subsystem/Counter Limited'
 * '<S13>'  : 'IFstart/Function-Call Subsystem/Power caculation'
 * '<S14>'  : 'IFstart/Function-Call Subsystem/SMO'
 * '<S15>'  : 'IFstart/Function-Call Subsystem/Subsystem1'
 * '<S16>'  : 'IFstart/Function-Call Subsystem/Subsystem2'
 * '<S17>'  : 'IFstart/Function-Call Subsystem/Subsystem3'
 * '<S18>'  : 'IFstart/Function-Call Subsystem/Subsystem4'
 * '<S19>'  : 'IFstart/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S20>'  : 'IFstart/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S21>'  : 'IFstart/Function-Call Subsystem/Counter Limited/Increment Real World'
 * '<S22>'  : 'IFstart/Function-Call Subsystem/Counter Limited/Wrap To Zero'
 * '<S23>'  : 'IFstart/Function-Call Subsystem/Power caculation/IIR Filter'
 * '<S24>'  : 'IFstart/Function-Call Subsystem/Power caculation/IIR Filter/IIR Filter'
 * '<S25>'  : 'IFstart/Function-Call Subsystem/Power caculation/IIR Filter/IIR Filter/Low-pass'
 * '<S26>'  : 'IFstart/Function-Call Subsystem/Power caculation/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S27>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer'
 * '<S28>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch'
 * '<S29>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Ealpha_est'
 * '<S30>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Ebeta_est'
 * '<S31>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha'
 * '<S32>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta'
 * '<S33>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter'
 * '<S34>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement'
 * '<S35>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation'
 * '<S36>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S37>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S38>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S39>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S40>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S41>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S42>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S43>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S44>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S45>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S46>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S47>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S48>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S49>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S50>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S51>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S52>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation/atan1'
 * '<S53>'  : 'IFstart/Function-Call Subsystem/SMO/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 * '<S54>'  : 'IFstart/Function-Call Subsystem/Subsystem1/Feedbackt_Current'
 * '<S55>'  : 'IFstart/Function-Call Subsystem/Subsystem2/Enable PWM for 8 seconds'
 * '<S56>'  : 'IFstart/Function-Call Subsystem/Subsystem2/If Action Subsystem2'
 * '<S57>'  : 'IFstart/Function-Call Subsystem/Subsystem2/If Action Subsystem3'
 * '<S58>'  : 'IFstart/Function-Call Subsystem/Subsystem2/Subsystem1'
 * '<S59>'  : 'IFstart/Function-Call Subsystem/Subsystem2/Subsystem1/If Action Subsystem'
 * '<S60>'  : 'IFstart/Function-Call Subsystem/Subsystem2/Subsystem1/If Action Subsystem2'
 * '<S61>'  : 'IFstart/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator'
 * '<S62>'  : 'IFstart/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator/Accumulate'
 * '<S63>'  : 'IFstart/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S64>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Clarke Transform'
 * '<S65>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Inverse Park Transform'
 * '<S66>'  : 'IFstart/Function-Call Subsystem/Subsystem3/PWM Reference Generator'
 * '<S67>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Park Transform1'
 * '<S68>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup'
 * '<S69>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem'
 * '<S70>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Clarke Transform/Two phase input'
 * '<S71>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S72>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Inverse Park Transform/Two inputs CRL'
 * '<S73>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S74>'  : 'IFstart/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method'
 * '<S75>'  : 'IFstart/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input'
 * '<S76>'  : 'IFstart/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method/SVPWM'
 * '<S77>'  : 'IFstart/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S78>'  : 'IFstart/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S79>'  : 'IFstart/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S80>'  : 'IFstart/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S81>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Park Transform1/Two inputs CRL'
 * '<S82>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Park Transform1/Two inputs CRL/Switch_Axis'
 * '<S83>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/Interpolation'
 * '<S84>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp'
 * '<S85>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S86>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S87>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S88>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter'
 * '<S89>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id'
 * '<S90>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq'
 * '<S91>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence'
 * '<S92>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority'
 * '<S93>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/Inport//Dialog Selection'
 * '<S94>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/Magnitude_calc'
 * '<S95>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S96>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S97>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S98>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S99>'  : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S100>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S101>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S102>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S103>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S104>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S105>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S106>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S107>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S108>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S109>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S110>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S111>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S112>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S113>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S114>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S115>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S116>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S117>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S118>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S119>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S120>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S121>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S122>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S123>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S124>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S125>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S126>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S127>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S128>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S129>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S130>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S131>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S132>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S133>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S134>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S135>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S136>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S137>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S138>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S139>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S140>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S141>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S142>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S143>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S144>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S145>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S146>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S147>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S148>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S149>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S150>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S151>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S152>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S153>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S154>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S155>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S156>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S157>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S158>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S159>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S160>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S161>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S162>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S163>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S164>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S165>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S166>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S167>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S168>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S169>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S170>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S171>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S172>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S173>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S174>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S175>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S176>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S177>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S178>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S179>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S180>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S181>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S182>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S183>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S184>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S185>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S186>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S187>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S188>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S189>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S190>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S191>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S192>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S193>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S194>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S195>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S196>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S197>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S198>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S199>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S200>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S201>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S202>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S203>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S204>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S205>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S206>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S207>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S208>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S209>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S210>' : 'IFstart/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S211>' : 'IFstart/Function-Call Subsystem/Subsystem4/PWM Output'
 * '<S212>' : 'IFstart/Function-Call Subsystem/Subsystem4/PWM Output/ECSoC'
 * '<S213>' : 'IFstart/Function-Call Subsystem/Subsystem4/PWM Output/ECSoC/ECSimCodegen'
 * '<S214>' : 'IFstart/Hardware Interrupt/ECSoC'
 * '<S215>' : 'IFstart/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S216>' : 'IFstart/LED Heart/Digital Port Write'
 * '<S217>' : 'IFstart/LED Heart/Digital Port Write/ECSoC'
 * '<S218>' : 'IFstart/LED Heart/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S219>' : 'IFstart/Subsystem1/Subsystem'
 * '<S220>' : 'IFstart/Subsystem1/Subsystem/Enabled Subsystem'
 */
#endif                                 /* IFstart_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
