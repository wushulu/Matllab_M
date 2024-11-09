/*
 * File: G431currentloop.h
 *
 * Code generated for Simulink model 'G431currentloop'.
 *
 * Model version                  : 1.59
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Nov  8 16:32:23 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef G431currentloop_h_
#define G431currentloop_h_
#ifndef G431currentloop_COMMON_INCLUDES_
#define G431currentloop_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#endif                                 /* G431currentloop_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "G431currentloop_types.h"
#include "rtGetNaN.h"
#include <string.h>
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

/* Block signals (default storage) */
typedef struct {
  real_T ab;                           /* '<Root>/Rate Transition1' */
  real_T LED;                          /* '<S5>/Pulse Generator' */
  real_T DataStoreRead;                /* '<S45>/Data Store Read' */
  real_T DataStoreRead1;               /* '<S45>/Data Store Read1' */
  real_T Add[2];                       /* '<S45>/Add' */
  real_T ADvoltage[2];                 /* '<S45>/AD voltage' */
  real_T OP_GainR_shunt[2];            /* '<S45>/OP_Gain*R_shunt' */
  real_T OP_GainR_shunt1[2];           /* '<S45>/OP_Gain*R_shunt1' */
  real_T Kalpha;                       /* '<S61>/Kalpha' */
  real_T Kbeta;                        /* '<S61>/Kbeta' */
  real_T UnitDelay1;                   /* '<S30>/Unit Delay1' */
  real_T UnitDelay;                    /* '<S30>/Unit Delay' */
  real_T a;                            /* '<S30>/a' */
  real_T Delay5[4];                    /* '<S2>/Delay5' */
  real_T Delay;                        /* '<S20>/Delay' */
  real_T Sum2;                         /* '<S20>/Sum2' */
  real_T Sum3;                         /* '<S30>/Sum3' */
  real_T b_invg;                       /* '<S30>/b_inv*g' */
  real_T Delay1;                       /* '<S30>/Delay1' */
  real_T Sum4;                         /* '<S30>/Sum4' */
  real_T Switch1[2];                   /* '<S22>/Switch1' */
  real_T Product;                      /* '<S34>/Product' */
  real_T UnitDelay_h;                  /* '<S34>/Unit Delay' */
  real_T Product1;                     /* '<S34>/Product1' */
  real_T Add1;                         /* '<S34>/Add1' */
  real_T UnitDelay1_k;                 /* '<S31>/Unit Delay1' */
  real_T UnitDelay_o;                  /* '<S31>/Unit Delay' */
  real_T a_e;                          /* '<S31>/a' */
  real_T Delay_f;                      /* '<S21>/Delay' */
  real_T Sum2_f;                       /* '<S21>/Sum2' */
  real_T Sum3_p;                       /* '<S31>/Sum3' */
  real_T b_invg_g;                     /* '<S31>/b_inv*g' */
  real_T Delay1_e;                     /* '<S31>/Delay1' */
  real_T Sum4_p;                       /* '<S31>/Sum4' */
  real_T Switch1_c[2];                 /* '<S23>/Switch1' */
  real_T Product_g;                    /* '<S37>/Product' */
  real_T UnitDelay_c;                  /* '<S37>/Unit Delay' */
  real_T Product1_j;                   /* '<S37>/Product1' */
  real_T Add1_o;                       /* '<S37>/Add1' */
  real_T Merge;                        /* '<S19>/Merge' */
  real_T Merge1;                       /* '<S19>/Merge1' */
  real_T Sign;                         /* '<S20>/Sign' */
  real_T Eta;                          /* '<S20>/Eta' */
  real_T Sum;                          /* '<S20>/Sum' */
  real_T b;                            /* '<S20>/b' */
  real_T a_g;                          /* '<S20>/a' */
  real_T Sum1;                         /* '<S20>/Sum1' */
  real_T Sign_h;                       /* '<S21>/Sign' */
  real_T Eta_i;                        /* '<S21>/Eta' */
  real_T Sum_l;                        /* '<S21>/Sum' */
  real_T b_g;                          /* '<S21>/b' */
  real_T a_l;                          /* '<S21>/a' */
  real_T Sum1_g;                       /* '<S21>/Sum1' */
  real_T TmpSignalConversionAtDelay5Inpo[4];
  real_T sqrt3_by_two;                 /* '<S71>/sqrt3_by_two' */
  real_T one_by_two;                   /* '<S71>/one_by_two' */
  real_T add_c;                        /* '<S71>/add_c' */
  real_T Kc;                           /* '<S71>/Kc' */
  real_T add_b;                        /* '<S71>/add_b' */
  real_T Kb;                           /* '<S71>/Kb' */
  real_T Ka;                           /* '<S71>/Ka' */
  real_T Min;                          /* '<S68>/Min' */
  real_T Max;                          /* '<S68>/Max' */
  real_T Add_j;                        /* '<S68>/Add' */
  real_T one_by_two_d;                 /* '<S68>/one_by_two' */
  real_T Add2;                         /* '<S67>/Add2' */
  real_T Add1_j;                       /* '<S67>/Add1' */
  real_T Add3;                         /* '<S67>/Add3' */
  real_T Gain[3];                      /* '<S67>/Gain' */
  real_T bcos;                         /* '<S72>/bcos' */
  real_T asin_j;                       /* '<S72>/asin' */
  real_T sum_Qs;                       /* '<S72>/sum_Qs' */
  real_T acos_p;                       /* '<S72>/acos' */
  real_T bsin;                         /* '<S72>/bsin' */
  real_T sum_Ds;                       /* '<S72>/sum_Ds' */
  real_T Unary_Minus;                  /* '<S73>/Unary_Minus' */
  real_T Switch[2];                    /* '<S64>/Switch' */
  real_T algDD_o1;
  real_T algDD_o2;
  real_T a_plus_2b;                    /* '<S62>/a_plus_2b' */
  real_T one_by_sqrt3;                 /* '<S62>/one_by_sqrt3' */
  real_T algDD_o1_l;
  real_T algDD_o2_b;
  real_T Product_n;                    /* '<S26>/Product' */
  real_T Product2;                     /* '<S26>/Product2' */
  real_T Sum1_f;                       /* '<S26>/Sum1' */
  real_T Product1_b;                   /* '<S26>/Product1' */
  real_T Product3;                     /* '<S26>/Product3' */
  real_T Sum2_l;                       /* '<S26>/Sum2' */
  real_T Switch_l;                     /* '<S26>/Switch' */
  real_T DataTypeConversion;           /* '<S43>/Data Type Conversion' */
  real_T Switch_b;                     /* '<S43>/Switch' */
  real_T algDD;
  real_T Gain_p;                       /* '<S44>/Gain' */
  real_T Switch_h;                     /* '<S44>/Switch' */
  real_T Bias;                         /* '<S44>/Bias' */
  real_T Bias_f;                       /* '<S26>/Bias' */
  real_T Sum_h;                        /* '<S23>/Sum' */
  real_T Sum_k;                        /* '<S22>/Sum' */
  uint32_T cont;                       /* '<S13>/Merge2' */
  uint32_T Sum_b[4];                   /* '<S59>/Sum' */
  uint32_T PositionToCount;            /* '<S25>/PositionToCount' */
  uint32_T Delay_o;                    /* '<S25>/Delay' */
  uint32_T DataStoreRead_p;            /* '<S47>/Data Store Read' */
  uint32_T Add1_g;                     /* '<S47>/Add1' */
  real32_T RateTransition;             /* '<Root>/Rate Transition' */
  real32_T Delay_i;                    /* '<S18>/Delay' */
  real32_T PhaseDelay;                 /* '<S18>/PhaseDelay' */
  real32_T AngleConversion;            /* '<S18>/AngleConversion' */
  real32_T Merge_i;                    /* '<S49>/Merge' */
  real32_T scaleIn;                    /* '<S52>/scaleIn' */
  real32_T UnitDelay_e;                /* '<S52>/Unit Delay' */
  real32_T Switch_g;                   /* '<S12>/Switch' */
  real32_T convert_pu;                 /* '<S75>/convert_pu' */
  real32_T Merge_d;                    /* '<S75>/Merge' */
  real32_T indexing;                   /* '<S59>/indexing' */
  real32_T Lookup[4];                  /* '<S59>/Lookup' */
  real32_T Sum3_h;                     /* '<S74>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S59>/Data Type Conversion1' */
  real32_T Sum2_p;                     /* '<S59>/Sum2' */
  real32_T Product_a;                  /* '<S74>/Product' */
  real32_T Sum4_m;                     /* '<S74>/Sum4' */
  real32_T Sum5;                       /* '<S74>/Sum5' */
  real32_T Product1_a;                 /* '<S74>/Product1' */
  real32_T Sum6;                       /* '<S74>/Sum6' */
  real32_T Sum_p;                      /* '<S81>/Sum' */
  real32_T PProdOut;                   /* '<S190>/PProd Out' */
  real32_T Vq_OpenLoop;                /* '<S81>/Vq_OpenLoop' */
  real32_T Integrator;                 /* '<S185>/Integrator' */
  real32_T Sum_l0;                     /* '<S194>/Sum' */
  real32_T Saturation;                 /* '<S192>/Saturation' */
  real32_T Sum_c;                      /* '<S80>/Sum' */
  real32_T PProdOut_g;                 /* '<S137>/PProd Out' */
  real32_T Constant;                   /* '<S80>/Constant' */
  real32_T Integrator_e;               /* '<S132>/Integrator' */
  real32_T Sum_o;                      /* '<S141>/Sum' */
  real32_T Saturation_c;               /* '<S139>/Saturation' */
  real32_T Switch_c;                   /* '<S84>/Switch' */
  real32_T Product_ah;                 /* '<S84>/Product' */
  real32_T Product_ar;                 /* '<S85>/Product' */
  real32_T Product1_k;                 /* '<S85>/Product1' */
  real32_T Sum1_l;                     /* '<S85>/Sum1' */
  real32_T Merge_n[2];                 /* '<S79>/Merge' */
  real32_T Switch4[3];                 /* '<S15>/Switch4' */
  real32_T DTC;                        /* '<S42>/DTC' */
  real32_T SpeedGain;                  /* '<S25>/SpeedGain' */
  real32_T Switch1_p[2];               /* '<S24>/Switch1' */
  real32_T Product_h;                  /* '<S40>/Product' */
  real32_T UnitDelay_m;                /* '<S40>/Unit Delay' */
  real32_T Product1_d;                 /* '<S40>/Product1' */
  real32_T Add1_h;                     /* '<S40>/Add1' */
  real32_T DeadZone;                   /* '<S124>/DeadZone' */
  real32_T IProdOut;                   /* '<S129>/IProd Out' */
  real32_T Switch_p;                   /* '<S122>/Switch' */
  real32_T DeadZone_p;                 /* '<S177>/DeadZone' */
  real32_T IProdOut_i;                 /* '<S182>/IProd Out' */
  real32_T Switch_j;                   /* '<S175>/Switch' */
  real32_T Gain_d[3];                  /* '<S15>/Gain' */
  real32_T Add_l[3];                   /* '<S15>/Add' */
  real32_T Gain1[3];                   /* '<S15>/Gain1' */
  real32_T Product_i[2];               /* '<S86>/Product' */
  real32_T SquareRoot;                 /* '<S86>/Square Root' */
  real32_T Switch_cc;                  /* '<S86>/Switch' */
  real32_T Switch_bs[2];               /* '<S83>/Switch' */
  real32_T Switch2;                    /* '<S93>/Switch2' */
  real32_T Product_n1;                 /* '<S92>/Product' */
  real32_T Sum_j;                      /* '<S92>/Sum' */
  real32_T Product2_b;                 /* '<S92>/Product2' */
  real32_T Merge_e;                    /* '<S92>/Merge' */
  real32_T Gain_l;                     /* '<S92>/Gain' */
  real32_T Switch_k;                   /* '<S93>/Switch' */
  real32_T Switch1_c1;                 /* '<S94>/Switch1' */
  real32_T Sqrt;                       /* '<S94>/Sqrt' */
  real32_T Gain_j;                     /* '<S94>/Gain' */
  real32_T Convert_back;               /* '<S78>/Convert_back' */
  real32_T Convert_back_h;             /* '<S77>/Convert_back' */
  real32_T Switch_f[2];                /* '<S73>/Switch' */
  real32_T algDD_o1_le;
  real32_T algDD_o2_h;
  real32_T qcos;                       /* '<S63>/qcos' */
  real32_T dsin;                       /* '<S63>/dsin' */
  real32_T sum_beta;                   /* '<S63>/sum_beta' */
  real32_T dcos;                       /* '<S63>/dcos' */
  real32_T qsin;                       /* '<S63>/qsin' */
  real32_T sum_alpha;                  /* '<S63>/sum_alpha' */
  real32_T Unary_Minus_f;              /* '<S64>/Unary_Minus' */
  real32_T Add_k;                      /* '<S53>/Add' */
  real32_T DataTypeConversion1_n;      /* '<S53>/Data Type Conversion1' */
  real32_T Add1_d;                     /* '<S53>/Add1' */
  real32_T Input;                      /* '<S54>/Input' */
  real32_T DataStoreRead_b;            /* '<S51>/Data Store Read' */
  real32_T Add1_a;                     /* '<S51>/Add1' */
  real32_T SaturatetomotorcalibSpeedRPM;
                                /* '<S51>/Saturate to 'motor.calibSpeed' RPM' */
  real32_T scaleOut;                   /* '<S52>/scaleOut' */
  real32_T DataTypeConversion1_f;      /* '<S43>/Data Type Conversion1' */
  real32_T DataTypeConversion2;        /* '<S43>/Data Type Conversion2' */
  real32_T Atan2;                      /* '<S43>/Atan2' */
  real32_T Sum_m;                      /* '<S24>/Sum' */
  int32_T DataTypeConversion_l[2];     /* '<S45>/Data Type Conversion' */
  int32_T SpeedCount;                  /* '<S25>/SpeedCount' */
  uint16_T Switch1_pj;                 /* '<S84>/Switch1' */
  uint16_T DataTypeConversion_b;       /* '<S75>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S59>/Get_Integer' */
  uint16_T DataTypeConversion_c;       /* '<S82>/Data Type Conversion' */
  uint16_T DataTypeConversion_bl;      /* '<S92>/Data Type Conversion' */
  uint16_T AnalogtoDigitalConverter[2];/* '<S17>/Analog to Digital Converter' */
  int16_T Convert_uint16;              /* '<S78>/Convert_uint16' */
  int16_T Convert_uint16_j;            /* '<S77>/Convert_uint16' */
  int16_T DataTypeConversion_i;        /* '<S53>/Data Type Conversion' */
  int16_T Switch_o;                    /* '<S27>/Switch' */
  int8_T Switch1_a;                    /* '<S122>/Switch1' */
  int8_T Switch2_n;                    /* '<S122>/Switch2' */
  int8_T Switch1_j;                    /* '<S175>/Switch1' */
  int8_T Switch2_nn;                   /* '<S175>/Switch2' */
  boolean_T UnitDelay_ok;              /* '<S1>/Unit Delay' */
  boolean_T NOT2;                      /* '<S1>/NOT2' */
  boolean_T AND;                       /* '<S1>/AND' */
  boolean_T DataStoreRead_d;           /* '<S2>/Data Store Read' */
  boolean_T LogicalOperator;           /* '<S11>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S19>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S19>/BetaRelay' */
  boolean_T DataStoreRead_h;           /* '<S13>/Data Store Read' */
  boolean_T Compare;                   /* '<S46>/Compare' */
  boolean_T NOT;                       /* '<S13>/NOT' */
  boolean_T NOT_o;                     /* '<S52>/NOT' */
  boolean_T Compare_h;                 /* '<S76>/Compare' */
  boolean_T DataStoreRead_d0;          /* '<S14>/Data Store Read' */
  boolean_T LogicalOperator_i;         /* '<S81>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S80>/Logical Operator1' */
  boolean_T DataStoreRead1_b;          /* '<S15>/Data Store Read1' */
  boolean_T RelationalOperator;        /* '<S122>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S122>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S122>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S122>/Equal1' */
  boolean_T AND3;                      /* '<S122>/AND3' */
  boolean_T RelationalOperator_g;      /* '<S175>/Relational Operator' */
  boolean_T fixforDTpropagationissue_a;
                                     /* '<S175>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_o;
                                    /* '<S175>/fix for DT propagation issue1' */
  boolean_T Equal1_d;                  /* '<S175>/Equal1' */
  boolean_T AND3_g;                    /* '<S175>/AND3' */
  boolean_T RelationalOperator_o;      /* '<S82>/Relational Operator' */
  boolean_T Compare_d;                 /* '<S88>/Compare' */
  boolean_T Compare_f;                 /* '<S89>/Compare' */
  boolean_T LowerRelop1;               /* '<S93>/LowerRelop1' */
  boolean_T RelationalOperator_p;      /* '<S92>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S93>/UpperRelop' */
  boolean_T Delay_m;                   /* '<S53>/Delay' */
  boolean_T LogicalOperator_b;         /* '<S27>/Logical Operator' */
  boolean_T UnitDelay_p;               /* '<S7>/Unit Delay' */
  boolean_T NOT_h;                     /* '<S7>/NOT' */
  boolean_T DigitalPortRead;           /* '<S9>/Digital Port Read' */
} B_G431currentloop_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput__T obj; /* '<S17>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_G4_T obj_h;/* '<S204>/PWM Output' */
  real_T UnitDelay1_DSTATE;            /* '<S30>/Unit Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S30>/Unit Delay' */
  real_T Delay5_DSTATE[4];             /* '<S2>/Delay5' */
  real_T Delay_DSTATE;                 /* '<S20>/Delay' */
  real_T Delay1_DSTATE;                /* '<S30>/Delay1' */
  real_T UnitDelay_DSTATE_c;           /* '<S34>/Unit Delay' */
  real_T UnitDelay1_DSTATE_f;          /* '<S31>/Unit Delay1' */
  real_T UnitDelay_DSTATE_j;           /* '<S31>/Unit Delay' */
  real_T Delay_DSTATE_p;               /* '<S21>/Delay' */
  real_T Delay1_DSTATE_f;              /* '<S31>/Delay1' */
  real_T UnitDelay_DSTATE_ca;          /* '<S37>/Unit Delay' */
  real_T IaOffset;                     /* '<Root>/Data Store Memory13' */
  real_T IbOffset;                     /* '<Root>/Data Store Memory14' */
  real_T Add_DWORK1[2];                /* '<S45>/Add' */
  uint64_T Add1_DWORK1;                /* '<S47>/Add1' */
  real32_T Delay_DSTATE_pt;            /* '<S18>/Delay' */
  real32_T UnitDelay_DSTATE_i;         /* '<S52>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S185>/Integrator' */
  real32_T Integrator_DSTATE_e;        /* '<S132>/Integrator' */
  real32_T UnitDelay_DSTATE_p;         /* '<S40>/Unit Delay' */
  uint32_T Delay_DSTATE_h[24];         /* '<S25>/Delay' */
  real32_T GlobleopenspeedInt;         /* '<S49>/Data Store Memory' */
  int32_T clockTickCounter;            /* '<S5>/Pulse Generator' */
  int32_T SpeedCount_DWORK1;           /* '<S25>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S59>/Sum' */
  uint32_T CircBufIdx;                 /* '<S25>/Delay' */
  uint32_T statcount;                  /* '<S13>/Data Store Memory' */
  stm32cube_blocks_DigitalPortR_T obj_m;/* '<S9>/Digital Port Read' */
  stm32cube_blocks_DigitalPortW_T obj_f;/* '<S209>/Digital Port Write' */
  boolean_T UnitDelay_DSTATE_m;        /* '<S1>/Unit Delay' */
  boolean_T Delay_DSTATE_j;            /* '<S53>/Delay' */
  boolean_T UnitDelay_DSTATE_g;        /* '<S7>/Unit Delay' */
  int8_T FunctionCallSubsystem_SubsysRan;/* '<Root>/Function-Call Subsystem' */
  int8_T Integrator_PrevResetState;    /* '<S185>/Integrator' */
  int8_T Integrator_PrevResetState_n;  /* '<S132>/Integrator' */
  int8_T DQEquivalence_SubsysRanBC;    /* '<S79>/D-Q Equivalence' */
  int8_T Passthrough_SubsysRanBC;      /* '<S82>/Passthrough' */
  int8_T Limiter_SubsysRanBC;          /* '<S82>/Limiter' */
  int8_T DQAxisPriority_SubsysRanBC;   /* '<S79>/D//Q Axis Priority' */
  int8_T limitRef2_SubsysRanBC;        /* '<S92>/limitRef2' */
  int8_T passThrough_SubsysRanBC;      /* '<S92>/passThrough' */
  int8_T IfActionSubsystem1_SubsysRanBC;/* '<S75>/If Action Subsystem1' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S75>/If Action Subsystem' */
  int8_T Accumulate_SubsysRanBC;       /* '<S52>/Accumulate' */
  int8_T Subsystem_SubsysRanBC;        /* '<S53>/Subsystem' */
  int8_T IfActionSubsystem2_SubsysRanBC;/* '<S49>/If Action Subsystem2' */
  int8_T IfActionSubsystem_SubsysRanBC_e;/* '<S49>/If Action Subsystem' */
  int8_T IfActionSubsystem3_SubsysRanBC;/* '<S13>/If Action Subsystem3' */
  int8_T IfActionSubsystem2_SubsysRanB_l;/* '<S13>/If Action Subsystem2' */
  int8_T Subsystem3_SubsysRanBC;       /* '<S19>/Subsystem3' */
  int8_T Subsystem2_SubsysRanBC;       /* '<S19>/Subsystem2' */
  int8_T Dir_Sense_SubsysRanBC;        /* '<S19>/Dir_Sense' */
  int8_T EnabledSubsystem_SubsysRanBC; /* '<S1>/Enabled Subsystem' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory9' */
  boolean_T objisempty;                /* '<S209>/Digital Port Write' */
  boolean_T AlphaRelay_Mode;           /* '<S19>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S19>/BetaRelay' */
  boolean_T objisempty_i;              /* '<S204>/PWM Output' */
  boolean_T objisempty_a;              /* '<S17>/Analog to Digital Converter' */
  boolean_T objisempty_e;              /* '<S9>/Digital Port Read' */
} DW_G431currentloop_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S20>/Delay' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S30>/Delay1' */
  ZCSigState Delay_Reset_ZCE_m;        /* '<S21>/Delay' */
  ZCSigState Delay1_Reset_ZCE_j;       /* '<S31>/Delay1' */
  ZCSigState Delay_Reset_ZCE_o;        /* '<S18>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S19>/Dir_Sense' */
} PrevZCX_G431currentloop_T;

/* Parameters (default storage) */
struct P_G431currentloop_T_ {
  real_T SlidingModeObserver_CurrentObse;
                              /* Mask Parameter: SlidingModeObserver_CurrentObse
                               * Referenced by:
                               *   '<S20>/Eta'
                               *   '<S21>/Eta'
                               */
  real_T SlidingModeObserver_CutoffFreq;
                               /* Mask Parameter: SlidingModeObserver_CutoffFreq
                                * Referenced by: '<S18>/PhaseDelay'
                                */
  real_T SlidingModeObserver_Disturbance;
                              /* Mask Parameter: SlidingModeObserver_Disturbance
                               * Referenced by:
                               *   '<S30>/b_inv*g'
                               *   '<S31>/b_inv*g'
                               */
  real32_T DiscretePIControllerwithantiwin;
                              /* Mask Parameter: DiscretePIControllerwithantiwin
                               * Referenced by:
                               *   '<S192>/Saturation'
                               *   '<S177>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_e;
                              /* Mask Parameter: DiscretePIControllerwithantiw_e
                               * Referenced by:
                               *   '<S139>/Saturation'
                               *   '<S124>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_a;
                              /* Mask Parameter: DiscretePIControllerwithantiw_a
                               * Referenced by:
                               *   '<S192>/Saturation'
                               *   '<S177>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_l;
                              /* Mask Parameter: DiscretePIControllerwithantiw_l
                               * Referenced by:
                               *   '<S139>/Saturation'
                               *   '<S124>/DeadZone'
                               */
  uint32_T EnablePWMfor8seconds_const;
                                   /* Mask Parameter: EnablePWMfor8seconds_const
                                    * Referenced by: '<S46>/Constant'
                                    */
  uint16_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S88>/Constant'
                                       */
  uint16_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S89>/Constant'
                                      */
  uint16_T atan1_outputUnit;           /* Mask Parameter: atan1_outputUnit
                                        * Referenced by: '<S43>/Constant'
                                        */
  real_T Constant_Value;               /* Expression: -1
                                        * Referenced by: '<S27>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T a_Value;                      /* Expression: 0
                                        * Referenced by: '<S22>/a'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S22>/One'
                                        */
  real_T FilterConstant_Value;       /* Computed Parameter: FilterConstant_Value
                                      * Referenced by: '<S22>/FilterConstant'
                                      */
  real_T OneMinusFilterConstant_Value;
                             /* Computed Parameter: OneMinusFilterConstant_Value
                              * Referenced by: '<S22>/OneMinusFilterConstant'
                              */
  real_T a_Value_c;                    /* Expression: 0
                                        * Referenced by: '<S23>/a'
                                        */
  real_T One_Value_l;                  /* Expression: 1
                                        * Referenced by: '<S23>/One'
                                        */
  real_T FilterConstant_Value_l;   /* Computed Parameter: FilterConstant_Value_l
                                    * Referenced by: '<S23>/FilterConstant'
                                    */
  real_T OneMinusFilterConstant_Value_e;
                           /* Computed Parameter: OneMinusFilterConstant_Value_e
                            * Referenced by: '<S23>/OneMinusFilterConstant'
                            */
  real_T Bias_Bias;                    /* Computed Parameter: Bias_Bias
                                        * Referenced by: '<S26>/Bias'
                                        */
  real_T Bias_Bias_a;                  /* Expression: 1
                                        * Referenced by: '<S44>/Bias'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/(2*pi)
                                        * Referenced by: '<S44>/Gain'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S44>/Switch'
                                        */
  real_T Switch_Threshold_i;           /* Expression: 0
                                        * Referenced by: '<S26>/Switch'
                                        */
  real_T one_by_sqrt3_Gain;            /* Expression: 1/sqrt(3)
                                        * Referenced by: '<S62>/one_by_sqrt3'
                                        */
  real_T sqrt3_by_two_Gain;            /* Expression: sqrt(3)/2
                                        * Referenced by: '<S71>/sqrt3_by_two'
                                        */
  real_T one_by_two_Gain;              /* Expression: 1/2
                                        * Referenced by: '<S71>/one_by_two'
                                        */
  real_T Kc_Gain;                      /* Expression: 1
                                        * Referenced by: '<S71>/Kc'
                                        */
  real_T Kb_Gain;                      /* Expression: 1
                                        * Referenced by: '<S71>/Kb'
                                        */
  real_T Ka_Gain;                      /* Expression: 1
                                        * Referenced by: '<S71>/Ka'
                                        */
  real_T one_by_two_Gain_g;            /* Expression: -0.5
                                        * Referenced by: '<S68>/one_by_two'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 2/sqrt(3)
                                        * Referenced by: '<S67>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: 0.5
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T currentab_Y0;                 /* Computed Parameter: currentab_Y0
                                        * Referenced by: '<S2>/currentab'
                                        */
  real_T Kalpha_Gain;                  /* Expression: 1
                                        * Referenced by: '<S61>/Kalpha'
                                        */
  real_T Kbeta_Gain;                   /* Expression: 1
                                        * Referenced by: '<S61>/Kbeta'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S30>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S30>/Unit Delay'
                                        */
  real_T Delay5_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S2>/Delay5'
                                        */
  real_T Delay_InitialCondition;       /* Expression: 0.0
                                        * Referenced by: '<S20>/Delay'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0.0
                                        * Referenced by: '<S30>/Delay1'
                                        */
  real_T UseInputPort_Value;           /* Expression: FilterConstantInputType
                                        * Referenced by: '<S22>/UseInputPort'
                                        */
  real_T Switch1_Threshold;            /* Expression: 1
                                        * Referenced by: '<S22>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_n; /* Expression: 0
                                        * Referenced by: '<S34>/Unit Delay'
                                        */
  real_T AlphaRelay_OnVal;             /* Expression: 0.02
                                        * Referenced by: '<S19>/AlphaRelay'
                                        */
  real_T AlphaRelay_OffVal;            /* Expression: -0.02
                                        * Referenced by: '<S19>/AlphaRelay'
                                        */
  real_T UnitDelay1_InitialCondition_a;/* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay1'
                                        */
  real_T UnitDelay_InitialCondition_c; /* Expression: 0
                                        * Referenced by: '<S31>/Unit Delay'
                                        */
  real_T Delay_InitialCondition_m;     /* Expression: 0.0
                                        * Referenced by: '<S21>/Delay'
                                        */
  real_T Delay1_InitialCondition_j;    /* Expression: 0.0
                                        * Referenced by: '<S31>/Delay1'
                                        */
  real_T UseInputPort_Value_g;         /* Expression: FilterConstantInputType
                                        * Referenced by: '<S23>/UseInputPort'
                                        */
  real_T Switch1_Threshold_h;          /* Expression: 1
                                        * Referenced by: '<S23>/Switch1'
                                        */
  real_T UnitDelay_InitialCondition_k; /* Expression: 0
                                        * Referenced by: '<S37>/Unit Delay'
                                        */
  real_T BetaRelay_OnVal;              /* Expression: 0.02
                                        * Referenced by: '<S19>/BetaRelay'
                                        */
  real_T BetaRelay_OffVal;             /* Expression: -0.02
                                        * Referenced by: '<S19>/BetaRelay'
                                        */
  real_T PositionToCount_Gain;         /* Expression: (4294967296/6.2832)
                                        * Referenced by: '<S25>/PositionToCount'
                                        */
  real_T Testinggetoffset1_Value;      /* Expression: 2051
                                        * Referenced by: '<S4>/Testing get offset1'
                                        */
  real_T Testinggetoffset_Value;       /* Expression: 2075
                                        * Referenced by: '<S4>/Testing get offset'
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
  real_T DataStoreMemory13_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory13'
                                         */
  real_T DataStoreMemory14_InitialValue;/* Expression: 0
                                         * Referenced by: '<Root>/Data Store Memory14'
                                         */
  real32_T a_Value_j;                  /* Computed Parameter: a_Value_j
                                        * Referenced by: '<S24>/a'
                                        */
  real32_T One_Value_f;                /* Computed Parameter: One_Value_f
                                        * Referenced by: '<S24>/One'
                                        */
  real32_T FilterConstant_Value_k;     /* Expression: Filter_constant
                                        * Referenced by: '<S24>/FilterConstant'
                                        */
  real32_T OneMinusFilterConstant_Value_f;/* Expression: 1 - Filter_constant
                                           * Referenced by: '<S24>/OneMinusFilterConstant'
                                           */
  real32_T scaleOut_Gain;              /* Computed Parameter: scaleOut_Gain
                                        * Referenced by: '<S52>/scaleOut'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S50>/Constant'
                                        */
  real32_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S51>/Constant2'
                                        */
  real32_T SaturatetomotorcalibSpeedRPM_Up;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
                           * Referenced by: '<S51>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T SaturatetomotorcalibSpeedRPM_Lo;
                          /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
                           * Referenced by: '<S51>/Saturate to 'motor.calibSpeed' RPM'
                           */
  real32_T Multiply1_Gain;             /* Computed Parameter: Multiply1_Gain
                                        * Referenced by: '<S51>/Multiply1'
                                        */
  real32_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S54>/Out1'
                                        */
  real32_T theta_e_Y0;                 /* Computed Parameter: theta_e_Y0
                                        * Referenced by: '<S53>/theta_e'
                                        */
  real32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S94>/Constant'
                                        */
  real32_T Gain_Gain_j;                /* Computed Parameter: Gain_Gain_j
                                        * Referenced by: '<S94>/Gain'
                                        */
  real32_T Switch1_Threshold_b;       /* Computed Parameter: Switch1_Threshold_b
                                       * Referenced by: '<S94>/Switch1'
                                       */
  real32_T Switch_Threshold_g;         /* Computed Parameter: Switch_Threshold_g
                                        * Referenced by: '<S94>/Switch'
                                        */
  real32_T Gain_Gain_m;                /* Computed Parameter: Gain_Gain_m
                                        * Referenced by: '<S92>/Gain'
                                        */
  real32_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S86>/Constant'
                                        */
  real32_T ReplaceInport_satLim_Value;
                               /* Computed Parameter: ReplaceInport_satLim_Value
                                * Referenced by: '<S79>/ReplaceInport_satLim'
                                */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S84>/Constant3'
                                        */
  real32_T Constant1_Value_e;          /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real32_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S15>/Gain1'
                                        */
  real32_T theta_Y0;                   /* Computed Parameter: theta_Y0
                                        * Referenced by: '<S2>/theta'
                                        */
  real32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S76>/Constant'
                                        */
  real32_T Constant1_Value_b;          /* Computed Parameter: Constant1_Value_b
                                        * Referenced by: '<S122>/Constant1'
                                        */
  real32_T Constant1_Value_ex;         /* Computed Parameter: Constant1_Value_ex
                                        * Referenced by: '<S175>/Constant1'
                                        */
  real32_T Constant2_Value_c;          /* Computed Parameter: Constant2_Value_c
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real32_T ADvoltage_Gain;             /* Computed Parameter: ADvoltage_Gain
                                        * Referenced by: '<S45>/AD voltage'
                                        */
  real32_T OP_GainR_shunt_Gain;       /* Computed Parameter: OP_GainR_shunt_Gain
                                       * Referenced by: '<S45>/OP_Gain*R_shunt'
                                       */
  real32_T OP_GainR_shunt1_Gain;     /* Computed Parameter: OP_GainR_shunt1_Gain
                                      * Referenced by: '<S45>/OP_Gain*R_shunt1'
                                      */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S59>/sine_table_values'
                                   */
  real32_T a_Gain;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S30>/a'
   */
  real32_T a_Gain_d;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S31>/a'
   */
  real32_T Delay_InitialCondition_m4;
                                /* Computed Parameter: Delay_InitialCondition_m4
                                 * Referenced by: '<S18>/Delay'
                                 */
  real32_T AngleConversion_Gain;     /* Computed Parameter: AngleConversion_Gain
                                      * Referenced by: '<S18>/AngleConversion'
                                      */
  real32_T scaleIn_Gain;               /* Computed Parameter: scaleIn_Gain
                                        * Referenced by: '<S52>/scaleIn'
                                        */
  real32_T UnitDelay_InitialCondition_nx;
                            /* Computed Parameter: UnitDelay_InitialCondition_nx
                             * Referenced by: '<S52>/Unit Delay'
                             */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S75>/convert_pu'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S59>/indexing'
                                        */
  real32_T Kp_Value;                   /* Computed Parameter: Kp_Value
                                        * Referenced by: '<S60>/Kp'
                                        */
  real32_T Vq_OpenLoop_Value;          /* Computed Parameter: Vq_OpenLoop_Value
                                        * Referenced by: '<S81>/Vq_OpenLoop'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S185>/Integrator'
                                        */
  real32_T Constant3_Value_k;          /* Computed Parameter: Constant3_Value_k
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S80>/Constant'
                                        */
  real32_T Integrator_gainval_m;     /* Computed Parameter: Integrator_gainval_m
                                      * Referenced by: '<S132>/Integrator'
                                      */
  real32_T b_Gain;
  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S20>/b'
   */
  real32_T a_Gain_b;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S20>/a'
   */
  real32_T b_Gain_h;
  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S21>/b'
   */
  real32_T a_Gain_o;
  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S21>/a'
   */
  real32_T SpeedGain_Gain;             /* Computed Parameter: SpeedGain_Gain
                                        * Referenced by: '<S25>/SpeedGain'
                                        */
  real32_T UseInputPort_Value_o;     /* Computed Parameter: UseInputPort_Value_o
                                      * Referenced by: '<S24>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_k;       /* Computed Parameter: Switch1_Threshold_k
                                       * Referenced by: '<S24>/Switch1'
                                       */
  real32_T UnitDelay_InitialCondition_e;
                             /* Computed Parameter: UnitDelay_InitialCondition_e
                              * Referenced by: '<S40>/Unit Delay'
                              */
  real32_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<S49>/Data Store Memory'
                              */
  real32_T Ki_Value;                   /* Computed Parameter: Ki_Value
                                        * Referenced by: '<S60>/Ki'
                                        */
  real32_T Clamping_zero_Value;       /* Computed Parameter: Clamping_zero_Value
                                       * Referenced by: '<S122>/Clamping_zero'
                                       */
  real32_T Clamping_zero_Value_c;   /* Computed Parameter: Clamping_zero_Value_c
                                     * Referenced by: '<S175>/Clamping_zero'
                                     */
  uint32_T Constant_Value_hu;          /* Computed Parameter: Constant_Value_hu
                                        * Referenced by: '<S47>/Constant'
                                        */
  uint32_T Constant15_Value;           /* Computed Parameter: Constant15_Value
                                        * Referenced by: '<S48>/Constant15'
                                        */
  uint32_T Countfor2sec_Value;         /* Computed Parameter: Countfor2sec_Value
                                        * Referenced by: '<S49>/Count for 2 sec'
                                        */
  uint32_T Delay_InitialCondition_i;
                                 /* Computed Parameter: Delay_InitialCondition_i
                                  * Referenced by: '<S25>/Delay'
                                  */
  uint32_T DataStoreMemory_InitialValue_k;
                           /* Computed Parameter: DataStoreMemory_InitialValue_k
                            * Referenced by: '<S13>/Data Store Memory'
                            */
  int16_T Sign_Y0;                     /* Computed Parameter: Sign_Y0
                                        * Referenced by: '<S27>/Sign'
                                        */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S59>/offset'
                                        */
  uint16_T Switch_Threshold_b;         /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S43>/Switch'
                                        */
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S64>/Offset'
                                        */
  uint16_T Switch_Threshold_k;         /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S64>/Switch'
                                        */
  uint16_T Offset_Value_p;             /* Computed Parameter: Offset_Value_p
                                        * Referenced by: '<S73>/Offset'
                                        */
  uint16_T Switch_Threshold_f;         /* Computed Parameter: Switch_Threshold_f
                                        * Referenced by: '<S73>/Switch'
                                        */
  uint16_T ReplaceInport_satMethod_Value;
                            /* Computed Parameter: ReplaceInport_satMethod_Value
                             * Referenced by: '<S79>/ReplaceInport_satMethod'
                             */
  uint16_T ChosenMethod_Value;         /* Computed Parameter: ChosenMethod_Value
                                        * Referenced by: '<S84>/ChosenMethod'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S15>/stop'
                                        */
  uint16_T enableInportSatMethod_Value;
                              /* Computed Parameter: enableInportSatMethod_Value
                               * Referenced by: '<S84>/enableInportSatMethod'
                               */
  uint16_T enableInportSatLim_Value;
                                 /* Computed Parameter: enableInportSatLim_Value
                                  * Referenced by: '<S84>/enableInportSatLim'
                                  */
  boolean_T Out1_Y0_h;                 /* Computed Parameter: Out1_Y0_h
                                        * Referenced by: '<S7>/Out1'
                                        */
  boolean_T UnitDelay_InitialCondition_i;/* Expression: true
                                          * Referenced by: '<S7>/Unit Delay'
                                          */
  boolean_T Delay_InitialCondition_f;
                                 /* Computed Parameter: Delay_InitialCondition_f
                                  * Referenced by: '<S53>/Delay'
                                  */
  boolean_T Constant_Value_j;          /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S53>/Constant'
                                        */
  boolean_T AlphaRelay_YOn;            /* Computed Parameter: AlphaRelay_YOn
                                        * Referenced by: '<S19>/AlphaRelay'
                                        */
  boolean_T AlphaRelay_YOff;           /* Computed Parameter: AlphaRelay_YOff
                                        * Referenced by: '<S19>/AlphaRelay'
                                        */
  boolean_T BetaRelay_YOn;             /* Computed Parameter: BetaRelay_YOn
                                        * Referenced by: '<S19>/BetaRelay'
                                        */
  boolean_T BetaRelay_YOff;            /* Computed Parameter: BetaRelay_YOff
                                        * Referenced by: '<S19>/BetaRelay'
                                        */
  boolean_T Constant_Reset_Value;    /* Computed Parameter: Constant_Reset_Value
                                      * Referenced by: '<S52>/Constant_Reset'
                                      */
  boolean_T UnitDelay_InitialCondition_eq;/* Expression: false
                                           * Referenced by: '<S1>/Unit Delay'
                                           */
  boolean_T DataStoreMemory9_InitialValue;
                            /* Computed Parameter: DataStoreMemory9_InitialValue
                             * Referenced by: '<Root>/Data Store Memory9'
                             */
  int8_T Constant_Value_m;             /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S122>/Constant'
                                        */
  int8_T Constant2_Value_j;            /* Computed Parameter: Constant2_Value_j
                                        * Referenced by: '<S122>/Constant2'
                                        */
  int8_T Constant3_Value_j;            /* Computed Parameter: Constant3_Value_j
                                        * Referenced by: '<S122>/Constant3'
                                        */
  int8_T Constant4_Value;              /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S122>/Constant4'
                                        */
  int8_T Constant_Value_c;             /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S175>/Constant'
                                        */
  int8_T Constant2_Value_g;            /* Computed Parameter: Constant2_Value_g
                                        * Referenced by: '<S175>/Constant2'
                                        */
  int8_T Constant3_Value_m;            /* Computed Parameter: Constant3_Value_m
                                        * Referenced by: '<S175>/Constant3'
                                        */
  int8_T Constant4_Value_p;            /* Computed Parameter: Constant4_Value_p
                                        * Referenced by: '<S175>/Constant4'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_G431currentloop_T {
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
    struct {
      uint8_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_G431currentloop_T G431currentloop_P;

/* Block signals (default storage) */
extern B_G431currentloop_T G431currentloop_B;

/* Block states (default storage) */
extern DW_G431currentloop_T G431currentloop_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_G431currentloop_T G431currentloop_PrevZCX;

/* External function called from main */
extern void G431currentloop_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void G431currentloop_initialize(void);
extern void G431currentloop_step0(void);
extern void G431currentloop_step1(void);
extern void G431currentloop_terminate(void);

/* Real-time Model object */
extern RT_MODEL_G431currentloop_T *const G431currentloop_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC1_2_IRQHandler(void);
  void G431currentloop_configure_interrupts (void);
  void G431currentloop_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S18>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S20>/Data Type Duplicate' : Unused code path elimination
 * Block '<S20>/Data Type Propagation1' : Unused code path elimination
 * Block '<S30>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Duplicate' : Unused code path elimination
 * Block '<S21>/Data Type Propagation1' : Unused code path elimination
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/Data Type Duplicate' : Unused code path elimination
 * Block '<S23>/Data Type Duplicate' : Unused code path elimination
 * Block '<S24>/Data Type Duplicate' : Unused code path elimination
 * Block '<S18>/SpeedConversion' : Unused code path elimination
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S26>/Data Type Propagation' : Unused code path elimination
 * Block '<S26>/DatatypeSet' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S52>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S62>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate' : Unused code path elimination
 * Block '<S63>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S57>/Data Type Duplicate' : Unused code path elimination
 * Block '<S57>/Vc' : Unused code path elimination
 * Block '<S71>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate' : Unused code path elimination
 * Block '<S72>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S59>/Data Type Duplicate' : Unused code path elimination
 * Block '<S59>/Data Type Propagation' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S78>/Data Type Duplicate' : Unused code path elimination
 * Block '<S86>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Propagation' : Unused code path elimination
 * Block '<S94>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S84>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S85>/Sqrt' : Unused code path elimination
 * Block '<S26>/Data Type Conversion' : Eliminate redundant data type conversion
 * Block '<S59>/Get_FractionVal' : Eliminate redundant data type conversion
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
 * '<Root>' : 'G431currentloop'
 * '<S1>'   : 'G431currentloop/Button start'
 * '<S2>'   : 'G431currentloop/Function-Call Subsystem'
 * '<S3>'   : 'G431currentloop/Hardware Interrupt'
 * '<S4>'   : 'G431currentloop/Initialize Function'
 * '<S5>'   : 'G431currentloop/LED Heart'
 * '<S6>'   : 'G431currentloop/Button start/Digital Port Read'
 * '<S7>'   : 'G431currentloop/Button start/Enabled Subsystem'
 * '<S8>'   : 'G431currentloop/Button start/Digital Port Read/ECSoC'
 * '<S9>'   : 'G431currentloop/Button start/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S10>'  : 'G431currentloop/Function-Call Subsystem/Analog to Digital Converter'
 * '<S11>'  : 'G431currentloop/Function-Call Subsystem/SOM'
 * '<S12>'  : 'G431currentloop/Function-Call Subsystem/Subsystem1'
 * '<S13>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2'
 * '<S14>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3'
 * '<S15>'  : 'G431currentloop/Function-Call Subsystem/Subsystem4'
 * '<S16>'  : 'G431currentloop/Function-Call Subsystem/Analog to Digital Converter/ECSoC'
 * '<S17>'  : 'G431currentloop/Function-Call Subsystem/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S18>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer'
 * '<S19>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Direction_Latch'
 * '<S20>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Ealpha_est'
 * '<S21>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Ebeta_est'
 * '<S22>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Filter_Ealpha'
 * '<S23>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Filter_Ebeta'
 * '<S24>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/IIR Filter'
 * '<S25>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Speed Measurement'
 * '<S26>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/angleCompensation'
 * '<S27>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S28>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S29>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S30>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S31>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S32>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S33>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S34>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S35>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S36>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S37>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S38>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S39>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S40>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S41>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S42>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S43>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/angleCompensation/atan1'
 * '<S44>'  : 'G431currentloop/Function-Call Subsystem/SOM/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 * '<S45>'  : 'G431currentloop/Function-Call Subsystem/Subsystem1/Feedbackt_Current'
 * '<S46>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/Enable PWM for 8 seconds'
 * '<S47>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/If Action Subsystem2'
 * '<S48>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/If Action Subsystem3'
 * '<S49>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/Subsystem1'
 * '<S50>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/Subsystem1/If Action Subsystem'
 * '<S51>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/Subsystem1/If Action Subsystem2'
 * '<S52>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator'
 * '<S53>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator/Accumulate'
 * '<S54>'  : 'G431currentloop/Function-Call Subsystem/Subsystem2/Subsystem1/Position Generator/Accumulate/Subsystem'
 * '<S55>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Clarke Transform'
 * '<S56>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Inverse Park Transform'
 * '<S57>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/PWM Reference Generator'
 * '<S58>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Park Transform1'
 * '<S59>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup'
 * '<S60>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem'
 * '<S61>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Clarke Transform/Two phase input'
 * '<S62>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S63>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Inverse Park Transform/Two inputs CRL'
 * '<S64>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S65>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method'
 * '<S66>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input'
 * '<S67>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method/SVPWM'
 * '<S68>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S69>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S70>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S71>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S72>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Park Transform1/Two inputs CRL'
 * '<S73>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Park Transform1/Two inputs CRL/Switch_Axis'
 * '<S74>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/Interpolation'
 * '<S75>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp'
 * '<S76>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S77>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S78>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S79>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter'
 * '<S80>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id'
 * '<S81>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq'
 * '<S82>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence'
 * '<S83>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority'
 * '<S84>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/Inport//Dialog Selection'
 * '<S85>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/Magnitude_calc'
 * '<S86>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S87>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S88>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S89>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S90>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S91>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S92>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S93>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S94>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S95>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S96>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S97>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S98>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S99>'  : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S100>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S101>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S102>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S103>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S104>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S105>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S106>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S107>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S108>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S109>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S110>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S111>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S112>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S113>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S114>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S115>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S116>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S117>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S118>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S119>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S120>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S121>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S122>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S123>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S124>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S125>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S126>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S127>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S128>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S129>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S130>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S131>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S132>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S133>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S134>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S135>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S136>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S137>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S138>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S139>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S140>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S141>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S142>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S143>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S144>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S145>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S146>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S147>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S148>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S149>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S150>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S151>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S152>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S153>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S154>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S155>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S156>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S157>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S158>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S159>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S160>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S161>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S162>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S163>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S164>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S165>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S166>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S167>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S168>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S169>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S170>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S171>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S172>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S173>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S174>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S175>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S176>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S177>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S178>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S179>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S180>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S181>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S182>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S183>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S184>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S185>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S186>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S187>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S188>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S189>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S190>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S191>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S192>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S193>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S194>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S195>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S196>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S197>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S198>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S199>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S200>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S201>' : 'G431currentloop/Function-Call Subsystem/Subsystem3/Subsystem/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S202>' : 'G431currentloop/Function-Call Subsystem/Subsystem4/PWM Output'
 * '<S203>' : 'G431currentloop/Function-Call Subsystem/Subsystem4/PWM Output/ECSoC'
 * '<S204>' : 'G431currentloop/Function-Call Subsystem/Subsystem4/PWM Output/ECSoC/ECSimCodegen'
 * '<S205>' : 'G431currentloop/Hardware Interrupt/ECSoC'
 * '<S206>' : 'G431currentloop/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S207>' : 'G431currentloop/LED Heart/Digital Port Write'
 * '<S208>' : 'G431currentloop/LED Heart/Digital Port Write/ECSoC'
 * '<S209>' : 'G431currentloop/LED Heart/Digital Port Write/ECSoC/ECSimCodegen'
 */
#endif                                 /* G431currentloop_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
