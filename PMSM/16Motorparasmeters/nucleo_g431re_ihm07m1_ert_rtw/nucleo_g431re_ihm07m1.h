/*
 * File: nucleo_g431re_ihm07m1.h
 *
 * Code generated for Simulink model 'nucleo_g431re_ihm07m1'.
 *
 * Model version                  : 8.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jan 16 10:47:28 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef nucleo_g431re_ihm07m1_h_
#define nucleo_g431re_ihm07m1_h_
#ifndef nucleo_g431re_ihm07m1_COMMON_INCLUDES_
#define nucleo_g431re_ihm07m1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "string.h"
#include "main.h"
#include "stm_lpuart.h"
#endif                              /* nucleo_g431re_ihm07m1_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "nucleo_g431re_ihm07m1_types.h"
#include "rt_r32zcfcn.h"
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

/* Block signals for system '<S33>/atan2' */
typedef struct {
  real32_T Atan2;                      /* '<S35>/Atan2' */
  real32_T Switch;                     /* '<S35>/Switch' */
  real32_T algDD;
  real32_T Gain;                       /* '<S38>/Gain' */
  real32_T Switch_g;                   /* '<S38>/Switch' */
  real32_T Bias;                       /* '<S38>/Bias' */
} rtB_atan2_nucleo_g431re_ihm07m1;

/* Block signals for system '<S67>/Two phase CRL wrap' */
typedef struct {
  real32_T a_plus_2b;                  /* '<S68>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S68>/one_by_sqrt3' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwophaseCRLwrap_nucleo_g431;

/* Block signals for system '<S65>/Two inputs CRL' */
typedef struct {
  real32_T acos_b;                     /* '<S69>/acos' */
  real32_T bsin;                       /* '<S69>/bsin' */
  real32_T sum_Ds;                     /* '<S69>/sum_Ds' */
  real32_T bcos;                       /* '<S69>/bcos' */
  real32_T asin_a;                     /* '<S69>/asin' */
  real32_T sum_Qs;                     /* '<S69>/sum_Qs' */
  real32_T Switch[2];                  /* '<S70>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_nucleo_g431re_;

/* Block signals for system '<S77>/Two inputs CRL' */
typedef struct {
  real32_T qcos;                       /* '<S78>/qcos' */
  real32_T dsin;                       /* '<S78>/dsin' */
  real32_T sum_beta;                   /* '<S78>/sum_beta' */
  real32_T dcos;                       /* '<S78>/dcos' */
  real32_T qsin;                       /* '<S78>/qsin' */
  real32_T sum_alpha;                  /* '<S78>/sum_alpha' */
  real32_T Switch[2];                  /* '<S79>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
} rtB_TwoinputsCRL_nucleo_g431r_d;

/* Block signals for system '<S95>/If Action Subsystem' */
typedef struct {
  real32_T Convert_back;               /* '<S97>/Convert_back' */
  int16_T Convert_uint16;              /* '<S97>/Convert_uint16' */
} rtB_IfActionSubsystem_nucleo_g4;

/* Block signals for system '<S95>/If Action Subsystem1' */
typedef struct {
  real32_T Convert_back;               /* '<S98>/Convert_back' */
  int16_T Convert_uint16;              /* '<S98>/Convert_uint16' */
} rtB_IfActionSubsystem1_nucleo_g;

/* Block signals for system '<S85>/Accumulate' */
typedef struct {
  real32_T Add;                        /* '<S101>/Add' */
  real32_T DataTypeConversion1;        /* '<S101>/Data Type Conversion1' */
  real32_T Add1;                       /* '<S101>/Add1' */
  real32_T Input;                      /* '<S102>/Input' */
  int16_T DataTypeConversion;          /* '<S101>/Data Type Conversion' */
  boolean_T Delay;                     /* '<S101>/Delay' */
} rtB_Accumulate_nucleo_g431re_ih;

/* Block states (default storage) for system '<S85>/Accumulate' */
typedef struct {
  boolean_T Delay_DSTATE;              /* '<S101>/Delay' */
} rtDW_Accumulate_nucleo_g431re_i;

/* Block signals (default storage) */
typedef struct {
  uint32_T DataTypeConversion2;        /* '<S320>/Data Type Conversion2' */
  uint32_T DataTypeConversion;         /* '<S322>/Data Type Conversion' */
  uint32_T BitwiseAND1;                /* '<S347>/Bitwise AND1' */
  uint32_T ShiftArithmetic;            /* '<S347>/Shift Arithmetic' */
  uint32_T BitwiseAND2;                /* '<S347>/Bitwise AND2' */
  uint32_T ShiftArithmetic1;           /* '<S347>/Shift Arithmetic1' */
  uint32_T BitwiseAND;                 /* '<S347>/Bitwise AND' */
  uint32_T UnitDelay;                  /* '<S347>/Unit Delay' */
  uint32_T Sum[4];                     /* '<S62>/Sum' */
  uint32_T SpeedToCount;               /* '<S50>/SpeedToCount' */
  uint32_T Delay;                      /* '<S50>/Delay' */
  uint32_T DataTypeConversion_b;       /* '<S13>/Data Type Conversion' */
  uint32_T BytePack[2];                /* '<S288>/Byte Pack' */
  uint32_T Merge[3];                   /* '<S300>/Merge' */
  uint32_T Merge1;                     /* '<S300>/Merge1' */
  uint32_T IndexVector;                /* '<S306>/Index Vector' */
  uint32_T Add;                        /* '<S306>/Add' */
  uint32_T Data[2];                    /* '<S303>/Data' */
  uint32_T Data_f[2];                  /* '<S304>/Data' */
  uint32_T Data_fw[2];                 /* '<S305>/Data' */
  uint32_T estParIdx;                  /* '<S287>/estParIdx' */
  uint32_T Sum_d[4];                   /* '<S243>/Sum' */
  uint32_T Sum_o[4];                   /* '<S233>/Sum' */
  uint32_T Sum_ot[4];                  /* '<S90>/Sum' */
  real32_T DataTypeConversion1;        /* '<S347>/Data Type Conversion1' */
  real32_T DataTypeConversion2_n;      /* '<S347>/Data Type Conversion2' */
  real32_T Switch;                     /* '<S347>/Switch' */
  real32_T DataStoreRead;              /* '<S347>/Data Store Read' */
  real32_T Saturation;                 /* '<S334>/Saturation' */
  real32_T Saturation_f;               /* '<S333>/Saturation' */
  real32_T Saturation_fo;              /* '<S332>/Saturation' */
  real32_T Saturation_d;               /* '<S330>/Saturation' */
  real32_T Saturation_h;               /* '<S329>/Saturation' */
  real32_T Saturation_j;               /* '<S328>/Saturation' */
  real32_T Saturation_i;               /* '<S324>/Saturation' */
  real32_T UARTUSARTRead_o1[2];        /* '<S320>/UART//USART Read' */
  real32_T In1[2];                     /* '<S343>/In1' */
  real32_T UnitDelay_a;                /* '<S13>/Unit Delay' */
  real32_T UnitDelay3;                 /* '<S13>/Unit Delay3' */
  real32_T DataTypeConversion4[4];     /* '<S20>/Data Type Conversion4' */
  real32_T count_to_PU[4];             /* '<S20>/count_to_PU' */
  real32_T Vab;                        /* '<S66>/Sum' */
  real32_T Vca;                        /* '<S66>/Sum2' */
  real32_T Sum3;                       /* '<S66>/Sum3' */
  real32_T Va;                         /* '<S66>/Gain2' */
  real32_T Vbc;                        /* '<S66>/Sum1' */
  real32_T Sum4;                       /* '<S66>/Sum4' */
  real32_T Vb;                         /* '<S66>/Gain3' */
  real32_T UnitDelay3_b;               /* '<S19>/Unit Delay3' */
  real32_T UnitDelay4;                 /* '<S19>/Unit Delay4' */
  real32_T UnitDelay9;                 /* '<S13>/Unit Delay9' */
  real32_T Switch_h[2];                /* '<S18>/Switch' */
  real32_T Switch1[2];                 /* '<S24>/Switch1' */
  real32_T Product[2];                 /* '<S27>/Product' */
  real32_T UnitDelay_e[2];             /* '<S27>/Unit Delay' */
  real32_T Product1[2];                /* '<S27>/Product1' */
  real32_T Add1[2];                    /* '<S27>/Add1' */
  real32_T Sum6[2];                    /* '<S21>/Sum6' */
  real32_T UnitDelay1;                 /* '<S19>/Unit Delay1' */
  real32_T UnitDelay2;                 /* '<S19>/Unit Delay2' */
  real32_T Switch1_e[2];               /* '<S28>/Switch1' */
  real32_T Product_c[2];               /* '<S31>/Product' */
  real32_T UnitDelay_o[2];             /* '<S31>/Unit Delay' */
  real32_T Product1_b[2];              /* '<S31>/Product1' */
  real32_T Add1_i[2];                  /* '<S31>/Add1' */
  real32_T Sum6_p[2];                  /* '<S22>/Sum6' */
  real32_T DataStoreRead2;             /* '<S7>/Data Store Read2' */
  real32_T DataStoreRead_n;            /* '<S7>/Data Store Read' */
  real32_T Product_i;                  /* '<S18>/Product' */
  real32_T DataStoreRead1;             /* '<S7>/Data Store Read1' */
  real32_T Gain;                       /* '<S7>/Gain' */
  real32_T Scaling;                    /* '<S18>/Scaling' */
  real32_T Product_l;                  /* '<S45>/Product' */
  real32_T Sum3_i;                     /* '<S37>/Sum3' */
  real32_T Gain_l;                     /* '<S37>/Gain' */
  real32_T Delay_j;                    /* '<S37>/Delay' */
  real32_T Sum_k;                      /* '<S37>/Sum' */
  real32_T DataStoreRead3;             /* '<S7>/Data Store Read3' */
  real32_T Product1_g;                 /* '<S18>/Product1' */
  real32_T Scaling1;                   /* '<S18>/Scaling1' */
  real32_T Product_m;                  /* '<S37>/Product' */
  real32_T Sum1;                       /* '<S37>/Sum1' */
  real32_T Switch1_ej[2];              /* '<S44>/Switch1' */
  real32_T Product_io;                 /* '<S48>/Product' */
  real32_T UnitDelay_g;                /* '<S48>/Unit Delay' */
  real32_T Product1_p;                 /* '<S48>/Product1' */
  real32_T Add1_io;                    /* '<S48>/Add1' */
  real32_T Sum6_l;                     /* '<S37>/Sum6' */
  real32_T Product_k;                  /* '<S40>/Product' */
  real32_T Sum3_h;                     /* '<S36>/Sum3' */
  real32_T Gain_d;                     /* '<S36>/Gain' */
  real32_T Delay_b;                    /* '<S36>/Delay' */
  real32_T Sum_h;                      /* '<S36>/Sum' */
  real32_T Product_im;                 /* '<S36>/Product' */
  real32_T Sum1_o;                     /* '<S36>/Sum1' */
  real32_T Switch1_b[2];               /* '<S39>/Switch1' */
  real32_T Product_a;                  /* '<S43>/Product' */
  real32_T UnitDelay_oq;               /* '<S43>/Unit Delay' */
  real32_T Product1_h;                 /* '<S43>/Product1' */
  real32_T Add1_c;                     /* '<S43>/Add1' */
  real32_T Sum6_h;                     /* '<S36>/Sum6' */
  real32_T Switch_d;                   /* '<S19>/Switch' */
  real32_T Merge_p;                    /* '<S252>/Merge' */
  real32_T indexing;                   /* '<S62>/indexing' */
  real32_T Lookup[4];                  /* '<S62>/Lookup' */
  real32_T Sum3_f;                     /* '<S251>/Sum3' */
  real32_T DataTypeConversion1_f;      /* '<S62>/Data Type Conversion1' */
  real32_T Sum2;                       /* '<S62>/Sum2' */
  real32_T Product_b;                  /* '<S251>/Product' */
  real32_T Sum4_h;                     /* '<S251>/Sum4' */
  real32_T Sum5;                       /* '<S251>/Sum5' */
  real32_T Product1_e;                 /* '<S251>/Product1' */
  real32_T Sum6_f;                     /* '<S251>/Sum6' */
  real32_T DataStoreRead_o;            /* '<S17>/Data Store Read' */
  real32_T DataStoreRead1_p;           /* '<S17>/Data Store Read1' */
  real32_T DataTypeConversion4_f[2];   /* '<S17>/Data Type Conversion4' */
  real32_T count_to_PU1[2];            /* '<S17>/count_to_PU1' */
  real32_T UnitDelay2_g;               /* '<S13>/Unit Delay2' */
  real32_T UnitDelay_n;                /* '<S1>/Unit Delay' */
  real32_T Switch1_g[2];               /* '<S9>/Switch1' */
  real32_T Product_o;                  /* '<S268>/Product' */
  real32_T UnitDelay_nf;               /* '<S268>/Unit Delay' */
  real32_T Product1_em;                /* '<S268>/Product1' */
  real32_T Add1_k;                     /* '<S268>/Add1' */
  real32_T DataStoreRead_k;            /* '<S1>/Data Store Read' */
  real32_T Product_e;                  /* '<S1>/Product' */
  real32_T Switch_m;                   /* '<S14>/Switch' */
  real32_T UnitDelay1_a;               /* '<S13>/Unit Delay1' */
  real32_T Switch_c[2];                /* '<S60>/Switch' */
  real32_T OpenLoop2CloseLoop[5];      /* '<S19>/OpenLoop2CloseLoop' */
  real32_T MultiportSwitch[2];         /* '<S61>/Multiport Switch' */
  real32_T DataStoreRead_oc;           /* '<S34>/Data Store Read' */
  real32_T DataStoreRead1_f;           /* '<S34>/Data Store Read1' */
  real32_T Product_ct;                 /* '<S50>/Product' */
  real32_T Divide;                     /* '<S50>/Divide' */
  real32_T Product1_g0;                /* '<S50>/Product1' */
  real32_T Switch1_c[2];               /* '<S49>/Switch1' */
  real32_T Product_f;                  /* '<S54>/Product' */
  real32_T UnitDelay_l;                /* '<S54>/Unit Delay' */
  real32_T Product1_a;                 /* '<S54>/Product1' */
  real32_T Add1_j;                     /* '<S54>/Add1' */
  real32_T Divide_b;                   /* '<S34>/Divide' */
  real32_T DataStoreRead_a;            /* '<S276>/Data Store Read' */
  real32_T DataStoreRead1_k;           /* '<S276>/Data Store Read1' */
  real32_T DataStoreRead2_p;           /* '<S276>/Data Store Read2' */
  real32_T DataStoreRead3_l;           /* '<S276>/Data Store Read3' */
  real32_T DataStoreRead4;             /* '<S276>/Data Store Read4' */
  real32_T DataStoreRead5;             /* '<S276>/Data Store Read5' */
  real32_T DataStoreRead6;             /* '<S276>/Data Store Read6' */
  real32_T DataStoreRead7;             /* '<S276>/Data Store Read7' */
  real32_T DataStoreRead8;             /* '<S276>/Data Store Read8' */
  real32_T DataStoreRead9;             /* '<S276>/Data Store Read9' */
  real32_T DataStoreRead2_a;           /* '<S13>/Data Store Read2' */
  real32_T Product_n;                  /* '<S13>/Product' */
  real32_T UnitDelay8;                 /* '<S279>/Unit Delay8' */
  real32_T Switch_l;                   /* '<S279>/Switch' */
  real32_T curTime;                    /* '<S279>/Sum' */
  real32_T DataStoreRead_ad;           /* '<S13>/Data Store Read' */
  real32_T DataStoreRead3_e;           /* '<S13>/Data Store Read3' */
  real32_T DataStoreRead4_p;           /* '<S13>/Data Store Read4' */
  real32_T DataStoreRead5_p;           /* '<S13>/Data Store Read5' */
  real32_T DataStoreRead8_p;           /* '<S13>/Data Store Read8' */
  real32_T DataStoreRead7_h;           /* '<S13>/Data Store Read7' */
  real32_T DataStoreRead1_km;          /* '<S13>/Data Store Read1' */
  real32_T DataStoreRead6_f;           /* '<S13>/Data Store Read6' */
  real32_T DataStoreRead9_e;           /* '<S13>/Data Store Read9' */
  real32_T inverter_V_max;             /* '<S13>/inverter_V_max' */
  real32_T DataStoreRead10;            /* '<S13>/Data Store Read10' */
  real32_T UnitDelay4_m;               /* '<S13>/Unit Delay4' */
  real32_T PWM_Enable;                 /* '<S273>/Data Store Read' */
  real32_T Switch1_o[3];               /* '<S273>/Switch1' */
  real32_T UnitDelay_j;                /* '<S286>/Unit Delay' */
  real32_T Switch_n;                   /* '<S299>/Switch' */
  real32_T DataStoreRead_e;            /* '<S16>/Data Store Read' */
  real32_T Vq;                         /* '<S16>/SelectSignal1' */
  real32_T TmpSignalConversionAtBytePackIn[2];
  real32_T estimatedParameter;         /* '<S287>/estimatedParameter' */
  real32_T Gain_h;                     /* '<S293>/Gain' */
  real32_T Gain_lx;                    /* '<S292>/Gain' */
  real32_T DataStoreRead_g;            /* '<S281>/Data Store Read' */
  real32_T DataStoreRead1_j;           /* '<S281>/Data Store Read1' */
  real32_T Abs;                        /* '<S282>/Abs' */
  real32_T Abs1;                       /* '<S282>/Abs1' */
  real32_T Product_ms;                 /* '<S282>/Product' */
  real32_T derating;                   /* '<S282>/derating' */
  real32_T Sum_b;                      /* '<S282>/Sum' */
  real32_T Merge_c;                    /* '<S282>/Merge' */
  real32_T Sum2_d;                     /* '<S282>/Sum2' */
  real32_T Product1_pz;                /* '<S281>/Product1' */
  real32_T Divide_n;                   /* '<S281>/Divide' */
  real32_T Product_by;                 /* '<S281>/Product' */
  real32_T Divide1;                    /* '<S285>/Divide1' */
  real32_T TmpSignalConversionAtSFunctionI[10];/* '<S13>/MATLAB Function' */
  real32_T TmpSignalConversionAtSFunctio_g[6];/* '<S13>/MATLAB Function' */
  real32_T TmpSignalConversionAtSFunctio_j[3];/* '<S13>/MATLAB Function' */
  real32_T testNumOut;                 /* '<S13>/MATLAB Function' */
  real32_T injFreqOut;                 /* '<S13>/MATLAB Function' */
  real32_T refSignalOut;               /* '<S13>/MATLAB Function' */
  real32_T refSignalOut1;              /* '<S13>/MATLAB Function' */
  real32_T estimatedParameterOut;      /* '<S13>/MATLAB Function' */
  real32_T testEnableOut;              /* '<S13>/MATLAB Function' */
  real32_T estParIdxOut;               /* '<S13>/MATLAB Function' */
  real32_T Kp_iOut;                    /* '<S13>/MATLAB Function' */
  real32_T Ki_iOut;                    /* '<S13>/MATLAB Function' */
  real32_T PhaseDiff;                  /* '<S13>/MATLAB Function' */
  real32_T Add_k[3];                   /* '<S273>/Add' */
  real32_T PWM_Counter_Period[3];      /* '<S273>/PWM_Counter_Period' */
  real32_T sqrt3_by_two;               /* '<S262>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S262>/one_by_two' */
  real32_T add_c;                      /* '<S262>/add_c' */
  real32_T add_b;                      /* '<S262>/add_b' */
  real32_T Min;                        /* '<S259>/Min' */
  real32_T Max;                        /* '<S259>/Max' */
  real32_T Add_g;                      /* '<S259>/Add' */
  real32_T one_by_two_b;               /* '<S259>/one_by_two' */
  real32_T Add2;                       /* '<S258>/Add2' */
  real32_T Add1_p;                     /* '<S258>/Add1' */
  real32_T Add3;                       /* '<S258>/Add3' */
  real32_T Gain_a[3];                  /* '<S258>/Gain' */
  real32_T Gain_ll;                    /* '<S231>/Gain' */
  real32_T UnitDelay_b;                /* '<S232>/Unit Delay' */
  real32_T Merge_c5;                   /* '<S237>/Merge' */
  real32_T Gain_p;                     /* '<S241>/Gain' */
  real32_T UnitDelay_p;                /* '<S242>/Unit Delay' */
  real32_T Merge_i;                    /* '<S247>/Merge' */
  real32_T IndexVector_b[2];           /* '<S105>/Index Vector' */
  real32_T OutportBufferForRefVq;
  real32_T indexing_k;                 /* '<S243>/indexing' */
  real32_T DataTypeConversion1_b;      /* '<S243>/Data Type Conversion1' */
  real32_T Sum2_k;                     /* '<S243>/Sum2' */
  real32_T Lookup_j[4];                /* '<S243>/Lookup' */
  real32_T Sum3_b;                     /* '<S246>/Sum3' */
  real32_T Product_j;                  /* '<S246>/Product' */
  real32_T Sum4_f;                     /* '<S246>/Sum4' */
  real32_T Product_g;                  /* '<S241>/Product' */
  real32_T indexing_a;                 /* '<S233>/indexing' */
  real32_T DataTypeConversion1_a;      /* '<S233>/Data Type Conversion1' */
  real32_T Sum2_h;                     /* '<S233>/Sum2' */
  real32_T Lookup_g[4];                /* '<S233>/Lookup' */
  real32_T Sum3_d;                     /* '<S236>/Sum3' */
  real32_T Product_cm;                 /* '<S236>/Product' */
  real32_T Sum4_hf;                    /* '<S236>/Sum4' */
  real32_T Product_oe;                 /* '<S231>/Product' */
  real32_T Sum_l;                      /* '<S231>/Sum' */
  real32_T DataStoreRead_ga;           /* '<S104>/Data Store Read' */
  real32_T DataStoreRead4_j;           /* '<S104>/Data Store Read4' */
  real32_T Sum_i;                      /* '<S104>/Sum' */
  real32_T Product1_o;                 /* '<S104>/Product1' */
  real32_T Add_ge;                     /* '<S104>/Add' */
  real32_T Sum1_j;                     /* '<S104>/Sum1' */
  real32_T Product2;                   /* '<S104>/Product2' */
  real32_T Add1_a;                     /* '<S104>/Add1' */
  real32_T DataStoreRead1_g;           /* '<S104>/Data Store Read1' */
  real32_T PProdOut;                   /* '<S215>/PProd Out' */
  real32_T Integrator;                 /* '<S210>/Integrator' */
  real32_T Sum_j;                      /* '<S219>/Sum' */
  real32_T Saturation_g;               /* '<S217>/Saturation' */
  real32_T PProdOut_k;                 /* '<S163>/PProd Out' */
  real32_T Integrator_i;               /* '<S158>/Integrator' */
  real32_T Sum_c;                      /* '<S167>/Sum' */
  real32_T Saturation_jy;              /* '<S165>/Saturation' */
  real32_T Switch_p;                   /* '<S111>/Switch' */
  real32_T Product_lw;                 /* '<S111>/Product' */
  real32_T Product_lr;                 /* '<S112>/Product' */
  real32_T Product1_n;                 /* '<S112>/Product1' */
  real32_T Sum1_e;                     /* '<S112>/Sum1' */
  real32_T Merge_b[2];                 /* '<S106>/Merge' */
  real32_T DataStoreRead2_n;           /* '<S104>/Data Store Read2' */
  real32_T DeadZone;                   /* '<S150>/DeadZone' */
  real32_T Product_oa;                 /* '<S104>/Product' */
  real32_T IProdOut;                   /* '<S155>/IProd Out' */
  real32_T Switch_i;                   /* '<S148>/Switch' */
  real32_T DeadZone_p;                 /* '<S202>/DeadZone' */
  real32_T IProdOut_c;                 /* '<S207>/IProd Out' */
  real32_T Switch_o;                   /* '<S200>/Switch' */
  real32_T Product_l5[2];              /* '<S113>/Product' */
  real32_T SquareRoot;                 /* '<S113>/Square Root' */
  real32_T Switch_a;                   /* '<S113>/Switch' */
  real32_T Switch_b[2];                /* '<S110>/Switch' */
  real32_T Switch2;                    /* '<S120>/Switch2' */
  real32_T Product_cx;                 /* '<S119>/Product' */
  real32_T Sum_g;                      /* '<S119>/Sum' */
  real32_T Product2_l;                 /* '<S119>/Product2' */
  real32_T Merge_d;                    /* '<S119>/Merge' */
  real32_T Gain_d3;                    /* '<S119>/Gain' */
  real32_T Switch_f;                   /* '<S120>/Switch' */
  real32_T Switch1_p;                  /* '<S121>/Switch1' */
  real32_T Sqrt;                       /* '<S121>/Sqrt' */
  real32_T Gain_c;                     /* '<S121>/Gain' */
  real32_T Eps;                        /* '<S86>/Ramp Generator' */
  real32_T DataStoreRead4_n;           /* '<S81>/Data Store Read4' */
  real32_T rpm2freq01xspeed_rated;     /* '<S81>/rpm2freq (0.1xspeed_rated)' */
  real32_T DataStoreRead2_j;           /* '<S81>/Data Store Read2' */
  real32_T Product1_k;                 /* '<S81>/Product1' */
  real32_T Product_fr;                 /* '<S81>/Product' */
  real32_T Frequency;                  /* '<S81>/Abs' */
  real32_T Vbyf;                       /* '<S87>/V-by-f' */
  real32_T DataStoreRead3_b;           /* '<S87>/Data Store Read3' */
  real32_T DataStoreRead4_a;           /* '<S87>/Data Store Read4' */
  real32_T Product2_k;                 /* '<S87>/Product2' */
  real32_T Divide_o;                   /* '<S87>/Divide' */
  real32_T Correction_Factor_sinePWM;  /* '<S81>/Correction_Factor_sinePWM' */
  real32_T Amplitude;                  /* '<S81>/Saturation1' */
  real32_T UnaryMinus;                 /* '<S82>/Unary Minus' */
  real32_T position_increment;         /* '<S81>/position_increment' */
  real32_T scaleIn;                    /* '<S85>/scaleIn' */
  real32_T UnitDelay_gn;               /* '<S85>/Unit Delay' */
  real32_T scaleOut;                   /* '<S85>/scaleOut' */
  real32_T Eps_h;                      /* '<S81>/Direction' */
  real32_T convert_pu;                 /* '<S95>/convert_pu' */
  real32_T Merge_h;                    /* '<S95>/Merge' */
  real32_T indexing_kt;                /* '<S90>/indexing' */
  real32_T Lookup_p[4];                /* '<S90>/Lookup' */
  real32_T Sum3_bh;                    /* '<S94>/Sum3' */
  real32_T DataTypeConversion1_g;      /* '<S90>/Data Type Conversion1' */
  real32_T Sum2_g;                     /* '<S90>/Sum2' */
  real32_T Product_cg;                 /* '<S94>/Product' */
  real32_T Sum4_p;                     /* '<S94>/Sum4' */
  real32_T Sum5_l;                     /* '<S94>/Sum5' */
  real32_T Product1_kj;                /* '<S94>/Product1' */
  real32_T Sum6_b;                     /* '<S94>/Sum6' */
  real32_T Ka;                         /* '<S91>/Ka' */
  real32_T one_by_two_g;               /* '<S91>/one_by_two' */
  real32_T sqrt3_by_two_e;             /* '<S91>/sqrt3_by_two' */
  real32_T add_b_d;                    /* '<S91>/add_b' */
  real32_T Kb;                         /* '<S91>/Kb' */
  real32_T add_c_f;                    /* '<S91>/add_c' */
  real32_T Kc;                         /* '<S91>/Kc' */
  real32_T Kalpha;                     /* '<S99>/Kalpha' */
  real32_T Kbeta;                      /* '<S99>/Kbeta' */
  real32_T Divide_j;                   /* '<S86>/Divide' */
  real32_T Sample_Time;                /* '<S86>/Sample_Time' */
  real32_T Sum_kc;                     /* '<S81>/Sum' */
  real32_T Gain_o[2];                  /* '<S18>/Gain' */
  int32_T DataTypeConversion2_a;       /* '<S17>/Data Type Conversion2' */
  int32_T DataTypeConversion3;         /* '<S17>/Data Type Conversion3' */
  int32_T DataTypeConversion_o[2];     /* '<S17>/Data Type Conversion' */
  int32_T Add_b[2];                    /* '<S17>/Add' */
  int32_T SpeedCount;                  /* '<S50>/SpeedCount' */
  uint16_T UARTUSARTRead_o2;           /* '<S320>/UART//USART Read' */
  uint16_T DataTypeConversion1_p;      /* '<S18>/Data Type Conversion1' */
  uint16_T DataTypeConversion_bv;      /* '<S252>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S62>/Get_Integer' */
  uint16_T Switch_fl;                  /* '<S8>/Switch' */
  uint16_T Output;                     /* '<S302>/Output' */
  uint16_T FixPtSum1;                  /* '<S307>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S308>/FixPt Switch' */
  uint16_T DataTypeConversion_n;       /* '<S282>/Data Type Conversion' */
  uint16_T DataTypeConversion_a[3];    /* '<S273>/Data Type Conversion' */
  uint16_T AnalogtoDigitalConverter[3];
                                      /* '<S271>/Analog to Digital Converter' */
  uint16_T DataTypeConversion_e;       /* '<S237>/Data Type Conversion' */
  uint16_T DataTypeConversion_nx;      /* '<S247>/Data Type Conversion' */
  uint16_T Get_Integer_b;              /* '<S243>/Get_Integer' */
  uint16_T Get_Integer_f;              /* '<S233>/Get_Integer' */
  uint16_T Switch1_cp;                 /* '<S111>/Switch1' */
  uint16_T DataTypeConversion_l;       /* '<S109>/Data Type Conversion' */
  uint16_T DataTypeConversion_k;       /* '<S119>/Data Type Conversion' */
  uint16_T DataTypeConversion_no;      /* '<S95>/Data Type Conversion' */
  uint16_T Get_Integer_g;              /* '<S90>/Get_Integer' */
  uint16_T AnalogtoDigitalConverter_c[3];
                                      /* '<S311>/Analog to Digital Converter' */
  int16_T WhileIterator;               /* '<S306>/While Iterator' */
  int8_T Switch1_j;                    /* '<S148>/Switch1' */
  int8_T Switch2_n;                    /* '<S148>/Switch2' */
  int8_T Switch1_n;                    /* '<S200>/Switch1' */
  int8_T Switch2_j;                    /* '<S200>/Switch2' */
  boolean_T Compare;                   /* '<S342>/Compare' */
  boolean_T UnitDelay_m;               /* '<S4>/Unit Delay' */
  boolean_T NOT;                       /* '<S4>/NOT' */
  boolean_T RelationalOperator;        /* '<S347>/Relational Operator' */
  boolean_T Compare_h;                 /* '<S80>/Compare' */
  boolean_T NOT_g;                     /* '<S59>/NOT' */
  boolean_T UnitDelay_i;               /* '<S59>/Unit Delay' */
  boolean_T Compare_g;                 /* '<S32>/Compare' */
  boolean_T NOT_h;                     /* '<S23>/NOT' */
  boolean_T Compare_j;                 /* '<S253>/Compare' */
  boolean_T DataStoreRead1_jd;         /* '<S19>/Data Store Read1' */
  boolean_T DataStoreRead2_c;          /* '<S19>/Data Store Read2' */
  boolean_T Compare_c;                 /* '<S280>/Compare' */
  boolean_T Compare_e;                 /* '<S103>/Compare' */
  boolean_T NOT_p;                     /* '<S60>/NOT' */
  boolean_T OR;                        /* '<S19>/OR' */
  boolean_T Equal;                     /* '<S286>/Equal' */
  boolean_T UnitDelay_g2;              /* '<S301>/Unit Delay' */
  boolean_T NOT_j;                     /* '<S301>/NOT' */
  boolean_T Compare_cl;                /* '<S283>/Compare' */
  boolean_T NOT_o;                     /* '<S232>/NOT' */
  boolean_T Compare_k;                 /* '<S238>/Compare' */
  boolean_T NOT_f;                     /* '<S242>/NOT' */
  boolean_T Compare_k5;                /* '<S248>/Compare' */
  boolean_T DataStoreRead3_d;          /* '<S104>/Data Store Read3' */
  boolean_T AND;                       /* '<S104>/AND' */
  boolean_T NOT_fd;                    /* '<S104>/NOT' */
  boolean_T RelationalOperator_k;      /* '<S148>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S148>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S148>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S148>/Equal1' */
  boolean_T AND3;                      /* '<S148>/AND3' */
  boolean_T RelationalOperator_c;      /* '<S200>/Relational Operator' */
  boolean_T fixforDTpropagationissue_o;
                                     /* '<S200>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_d;
                                    /* '<S200>/fix for DT propagation issue1' */
  boolean_T Equal1_g;                  /* '<S200>/Equal1' */
  boolean_T AND3_i;                    /* '<S200>/AND3' */
  boolean_T RelationalOperator_o;      /* '<S109>/Relational Operator' */
  boolean_T Compare_f;                 /* '<S115>/Compare' */
  boolean_T Compare_p;                 /* '<S116>/Compare' */
  boolean_T LowerRelop1;               /* '<S120>/LowerRelop1' */
  boolean_T RelationalOperator_e;      /* '<S119>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S120>/UpperRelop' */
  boolean_T NOT_fm;                    /* '<S86>/NOT' */
  boolean_T Compare_i;                 /* '<S84>/Compare' */
  boolean_T AND_j;                     /* '<S81>/AND' */
  boolean_T NOT_d;                     /* '<S85>/NOT' */
  boolean_T Compare_ek;                /* '<S96>/Compare' */
  rtB_IfActionSubsystem1_nucleo_g IfActionSubsystem1;/* '<S252>/If Action Subsystem1' */
  rtB_IfActionSubsystem_nucleo_g4 IfActionSubsystem;/* '<S252>/If Action Subsystem' */
  rtB_IfActionSubsystem1_nucleo_g IfActionSubsystem1_a;/* '<S247>/If Action Subsystem1' */
  rtB_IfActionSubsystem_nucleo_g4 IfActionSubsystem_h;/* '<S247>/If Action Subsystem' */
  rtB_Accumulate_nucleo_g431re_ih Accumulate_k;/* '<S242>/Accumulate' */
  rtB_IfActionSubsystem1_nucleo_g IfActionSubsystem1_b;/* '<S237>/If Action Subsystem1' */
  rtB_IfActionSubsystem_nucleo_g4 IfActionSubsystem_d;/* '<S237>/If Action Subsystem' */
  rtB_Accumulate_nucleo_g431re_ih Accumulate_f;/* '<S232>/Accumulate' */
  rtB_Accumulate_nucleo_g431re_ih Accumulate;/* '<S85>/Accumulate' */
  rtB_TwophaseCRLwrap_nucleo_g431 TwophaseCRLwrap_o;/* '<S99>/Two phase CRL wrap' */
  rtB_IfActionSubsystem1_nucleo_g IfActionSubsystem1_g;/* '<S95>/If Action Subsystem1' */
  rtB_IfActionSubsystem_nucleo_g4 IfActionSubsystem_b;/* '<S95>/If Action Subsystem' */
  rtB_TwoinputsCRL_nucleo_g431r_d TwoinputsCRL_ou;/* '<S89>/Two inputs CRL' */
  rtB_TwoinputsCRL_nucleo_g431r_d TwoinputsCRL_j;/* '<S77>/Two inputs CRL' */
  rtB_TwoinputsCRL_nucleo_g431re_ TwoinputsCRL_o;/* '<S72>/Two inputs CRL' */
  rtB_TwophaseCRLwrap_nucleo_g431 TwophaseCRLwrap_k;/* '<S73>/Two phase CRL wrap' */
  rtB_TwoinputsCRL_nucleo_g431re_ TwoinputsCRL;/* '<S65>/Two inputs CRL' */
  rtB_TwophaseCRLwrap_nucleo_g431 TwophaseCRLwrap;/* '<S67>/Two phase CRL wrap' */
  rtB_atan2_nucleo_g431re_ihm07m1 atan2_e;/* '<S34>/atan2' */
  rtB_atan2_nucleo_g431re_ihm07m1 atan2_n;/* '<S33>/atan2' */
} BlockIO_nucleo_g431re_ihm07m1;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_AnalogInput_nu obj;/* '<S271>/Analog to Digital Converter' */
  stm32cube_blocks_AnalogInput_nu obj_h;
                                      /* '<S311>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_nucl obj_a;/* '<S319>/PWM Output' */
  stm32cube_blocks_PWMOutput_nucl obj_f;/* '<S275>/PWM Output' */
  stm32cube_blocks_UARTWrite_nucl obj_o;/* '<S306>/UART//USART Write' */
  stm32cube_blocks_UARTRead_nucle obj_e;/* '<S320>/UART//USART Read' */
  real32_T UnitDelay_DSTATE;           /* '<S13>/Unit Delay' */
  real32_T UnitDelay3_DSTATE;          /* '<S13>/Unit Delay3' */
  real32_T UnitDelay3_DSTATE_i;        /* '<S19>/Unit Delay3' */
  real32_T UnitDelay4_DSTATE;          /* '<S19>/Unit Delay4' */
  real32_T UnitDelay9_DSTATE;          /* '<S13>/Unit Delay9' */
  real32_T UnitDelay_DSTATE_a[2];      /* '<S27>/Unit Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S19>/Unit Delay1' */
  real32_T UnitDelay2_DSTATE;          /* '<S19>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_d[2];      /* '<S31>/Unit Delay' */
  real32_T Delay_DSTATE;               /* '<S37>/Delay' */
  real32_T UnitDelay_DSTATE_m;         /* '<S48>/Unit Delay' */
  real32_T Delay_DSTATE_h;             /* '<S36>/Delay' */
  real32_T UnitDelay_DSTATE_b;         /* '<S43>/Unit Delay' */
  real32_T UnitDelay2_DSTATE_m;        /* '<S13>/Unit Delay2' */
  real32_T UnitDelay_DSTATE_i;         /* '<S1>/Unit Delay' */
  real32_T UnitDelay_DSTATE_f;         /* '<S268>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_m;        /* '<S13>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_c;         /* '<S54>/Unit Delay' */
  real32_T UnitDelay8_DSTATE;          /* '<S279>/Unit Delay8' */
  real32_T UnitDelay4_DSTATE_n;        /* '<S13>/Unit Delay4' */
  real32_T UnitDelay_DSTATE_e;         /* '<S286>/Unit Delay' */
  real32_T UnitDelay_DSTATE_o;         /* '<S232>/Unit Delay' */
  real32_T UnitDelay_DSTATE_j;         /* '<S242>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S210>/Integrator' */
  real32_T Integrator_DSTATE_c;        /* '<S158>/Integrator' */
  real32_T RampGenerator_DSTATE;       /* '<S86>/Ramp Generator' */
  real32_T UnitDelay_DSTATE_ba;        /* '<S85>/Unit Delay' */
  uint32_T UnitDelay_DSTATE_n;         /* '<S347>/Unit Delay' */
  uint32_T Delay_DSTATE_o[800];        /* '<S50>/Delay' */
  real32_T V_rated;                    /* '<Root>/Data Store Memory10' */
  real32_T speed_rated;                /* '<Root>/Data Store Memory11' */
  real32_T pole_pairs;                 /* '<Root>/Data Store Memory12' */
  real32_T RsMeasTestTime;             /* '<Root>/Data Store Memory13' */
  real32_T selSig2;                    /* '<Root>/Data Store Memory14' */
  real32_T selSig1;                    /* '<Root>/Data Store Memory15' */
  real32_T sigma;                      /* '<Root>/Data Store Memory18' */
  real32_T R_board;                    /* '<Root>/Data Store Memory20' */
  real32_T inverter_V_max;             /* '<Root>/Data Store Memory28' */
  real32_T Vd_ref_OL;                  /* '<Root>/Data Store Memory31' */
  real32_T freq_low;                   /* '<Root>/Data Store Memory32' */
  real32_T freq_high;                  /* '<Root>/Data Store Memory33' */
  real32_T freq_step;                  /* '<Root>/Data Store Memory34' */
  real32_T Vd_dc;                      /* '<Root>/Data Store Memory35' */
  real32_T Vdq_amp;                    /* '<Root>/Data Store Memory36' */
  real32_T Iq_ref_CL;                  /* '<Root>/Data Store Memory37' */
  real32_T under_voltage_limit;        /* '<Root>/Data Store Memory38' */
  real32_T over_current_limit;         /* '<Root>/Data Store Memory39' */
  real32_T inertia_end_speed;          /* '<Root>/Data Store Memory41' */
  real32_T testEnableFromHost;         /* '<Root>/Data Store Memory7' */
  real32_T currentPU_RWV;              /* '<Root>/Data Store Memory8' */
  real32_T I_rated;                    /* '<Root>/Data Store Memory9' */
  real32_T Rs;                         /* '<Root>/Data Store Memory' */
  real32_T Ld;                         /* '<Root>/Data Store Memory16' */
  real32_T Lq;                         /* '<Root>/Data Store Memory17' */
  real32_T Bemf;                       /* '<Root>/Data Store Memory19' */
  real32_T J;                          /* '<Root>/Data Store Memory21' */
  real32_T B;                          /* '<Root>/Data Store Memory22' */
  real32_T Kp_i;                       /* '<Root>/Data Store Memory23' */
  real32_T Ki_i;                       /* '<Root>/Data Store Memory24' */
  real32_T errorID;                    /* '<Root>/Data Store Memory25' */
  real32_T PhaseDiffValid;             /* '<Root>/Data Store Memory40' */
  real32_T Ia_avg_cal;                 /* '<Root>/Data Store Memory5' */
  real32_T Ib_avg_cal;                 /* '<Root>/Data Store Memory6' */
  real32_T flag;                       /* '<S13>/MATLAB Function' */
  real32_T errorID_m;                  /* '<S13>/MATLAB Function' */
  real32_T estParIdx;                  /* '<S13>/MATLAB Function' */
  real32_T phaseDiffRad;               /* '<S13>/MATLAB Function' */
  real32_T PhaseDiffValidityLd;        /* '<S13>/MATLAB Function' */
  real32_T PhaseDiffValidityLq;        /* '<S13>/MATLAB Function' */
  real32_T flagNextVal;                /* '<S13>/MATLAB Function' */
  real32_T delay;                      /* '<S13>/MATLAB Function' */
  real32_T estimatedParameter;         /* '<S13>/MATLAB Function' */
  real32_T voltagePU_RWV;              /* '<S13>/MATLAB Function' */
  real32_T Kp_i_d;                     /* '<S13>/MATLAB Function' */
  real32_T Ki_i_d;                     /* '<S13>/MATLAB Function' */
  real32_T PhaseDiffVal;               /* '<S13>/MATLAB Function' */
  real32_T testNum;                    /* '<S13>/MATLAB Function' */
  real32_T testEnable;                 /* '<S13>/MATLAB Function' */
  real32_T injFreq;                    /* '<S13>/MATLAB Function' */
  real32_T lambda;                     /* '<S13>/MATLAB Function' */
  real32_T speed_radPerSec;            /* '<S13>/MATLAB Function' */
  real32_T estL;                       /* '<S13>/MATLAB Function' */
  real32_T numWaves;                   /* '<S13>/MATLAB Function' */
  real32_T refSignal;                  /* '<S13>/MATLAB Function' */
  real32_T refSignal1;                 /* '<S13>/MATLAB Function' */
  real32_T savedTimeInstance;          /* '<S13>/MATLAB Function' */
  real32_T timeInstance1;              /* '<S13>/MATLAB Function' */
  real32_T samplesPerHalfCycle;        /* '<S13>/MATLAB Function' */
  real32_T sinIdx;                     /* '<S13>/MATLAB Function' */
  real32_T count1;                     /* '<S13>/MATLAB Function' */
  real32_T count2;                     /* '<S13>/MATLAB Function' */
  real32_T count3;                     /* '<S13>/MATLAB Function' */
  real32_T arraySine[1000];            /* '<S13>/MATLAB Function' */
  real32_T max;                        /* '<S13>/MATLAB Function' */
  real32_T min;                        /* '<S13>/MATLAB Function' */
  real32_T Sig1;                       /* '<S13>/MATLAB Function' */
  real32_T Sig2;                       /* '<S13>/MATLAB Function' */
  real32_T Sig1Prev;                   /* '<S13>/MATLAB Function' */
  real32_T Sig2Prev;                   /* '<S13>/MATLAB Function' */
  real32_T Sig1Mean;                   /* '<S13>/MATLAB Function' */
  real32_T Sig2Mean;                   /* '<S13>/MATLAB Function' */
  real32_T Sig3Mean;                   /* '<S13>/MATLAB Function' */
  real32_T Sig4Mean;                   /* '<S13>/MATLAB Function' */
  real32_T Sig5Mean;                   /* '<S13>/MATLAB Function' */
  int32_T Add_DWORK1[2];               /* '<S17>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S50>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S62>/Sum' */
  uint32_T CircBufIdx;                 /* '<S50>/Delay' */
  uint32_T Add_DWORK1_l;               /* '<S306>/Add' */
  stm32cube_blocks_DigitalPortWri obj_k;/* '<S316>/Digital Port Write' */
  stm32cube_blocks_DigitalPortWri obj_g;/* '<S265>/Digital Port Write' */
  uint16_T Output_DSTATE;              /* '<S302>/Output' */
  boolean_T UnitDelay_DSTATE_h;        /* '<S4>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_g;        /* '<S59>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_oq;       /* '<S301>/Unit Delay' */
  int8_T Integrator_PrevResetState;    /* '<S210>/Integrator' */
  int8_T Integrator_PrevResetState_k;  /* '<S158>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S210>/Integrator' */
  uint8_T Integrator_IC_LOADING_g;     /* '<S158>/Integrator' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory29' */
  boolean_T disableOL;                 /* '<Root>/Data Store Memory30' */
  boolean_T objisempty;                /* '<S320>/UART//USART Read' */
  boolean_T objisempty_o;              /* '<S319>/PWM Output' */
  boolean_T objisempty_c;              /* '<S316>/Digital Port Write' */
  boolean_T objisempty_a;              /* '<S306>/UART//USART Write' */
  boolean_T voltagePU_RWV_not_empty;   /* '<S13>/MATLAB Function' */
  boolean_T objisempty_h;              /* '<S275>/PWM Output' */
  boolean_T objisempty_e;             /* '<S271>/Analog to Digital Converter' */
  boolean_T objisempty_m;              /* '<S265>/Digital Port Write' */
  boolean_T objisempty_m0;            /* '<S311>/Analog to Digital Converter' */
  boolean_T OpenLoopStartUp_MODE;      /* '<S59>/Open Loop Start-Up' */
  rtDW_Accumulate_nucleo_g431re_i Accumulate_k;/* '<S242>/Accumulate' */
  rtDW_Accumulate_nucleo_g431re_i Accumulate_f;/* '<S232>/Accumulate' */
  rtDW_Accumulate_nucleo_g431re_i Accumulate;/* '<S85>/Accumulate' */
} D_Work_nucleo_g431re_ihm07m1;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S37>/Delay' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S36>/Delay' */
  ZCSigState SaveToMemory_Trig_ZCE;    /* '<S15>/SaveToMemory' */
  ZCSigState TriggeredSubsystem_Trig_ZCE;/* '<S13>/Triggered Subsystem' */
} PrevZCSigStates_nucleo_g431re_i;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S62>/sine_table_values'
   *   '<S90>/sine_table_values'
   *   '<S233>/sine_table_values'
   *   '<S243>/sine_table_values'
   */
  real32_T pooled12[1002];
} ConstParam_nucleo_g431re_ihm07m;

/* Real-time Model Data Structure */
struct tag_RTM_nucleo_g431re_ihm07m1 {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_nucleo_g431re_ihm07m1 nucleo_g431re_ihm07m1_B;

/* Block states (default storage) */
extern D_Work_nucleo_g431re_ihm07m1 nucleo_g431re_ihm07m1_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_nucleo_g431re_i nucleo_g431re_ih_PrevZCSigState;

/* Constant parameters (default storage) */
extern const ConstParam_nucleo_g431re_ihm07m nucleo_g431re_ihm07m1_ConstP;

/* External function called from main */
extern void nucleo_g431re_ihm07m1_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void nucleo_g431re_ihm07m1_initialize(void);
extern void nucleo_g431re_ihm07m1_step0(void);
extern void nucleo_g431re_ihm07m1_step1(void);
extern void nucleo_g431re_ihm07m1_step2(void);
extern void nucleo_g431re_ihm07m1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_nucleo_g431re_ihm07m1 *const nucleo_g431re_ihm07m1_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC1_2_IRQHandler(void);
  void nucleo_g431re_ihm07m1_configure_interrupts (void);
  void nucleo_g431re_ihm07m1_unconfigure_interrupts (void);

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
 * '<Root>' : 'nucleo_g431re_ihm07m1'
 * '<S1>'   : 'nucleo_g431re_ihm07m1/Alogrithm'
 * '<S2>'   : 'nucleo_g431re_ihm07m1/Function-Call Subsystem'
 * '<S3>'   : 'nucleo_g431re_ihm07m1/Hardware Interrupt'
 * '<S4>'   : 'nucleo_g431re_ihm07m1/Heartbeat'
 * '<S5>'   : 'nucleo_g431re_ihm07m1/Initialize Function'
 * '<S6>'   : 'nucleo_g431re_ihm07m1/SerialReceive'
 * '<S7>'   : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm'
 * '<S8>'   : 'nucleo_g431re_ihm07m1/Alogrithm/EnableMosfets'
 * '<S9>'   : 'nucleo_g431re_ihm07m1/Alogrithm/IIR Filter'
 * '<S10>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Inputs'
 * '<S11>'  : 'nucleo_g431re_ihm07m1/Alogrithm/MuxAllSignals'
 * '<S12>'  : 'nucleo_g431re_ihm07m1/Alogrithm/PWM_HW'
 * '<S13>'  : 'nucleo_g431re_ihm07m1/Alogrithm/ParameterEstimationTests'
 * '<S14>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Reference signal  conditioning'
 * '<S15>'  : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send'
 * '<S16>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Signal Selection'
 * '<S17>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/CurrentScaling1'
 * '<S18>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer'
 * '<S19>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors'
 * '<S20>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Voltage Scaling'
 * '<S21>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal'
 * '<S22>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal1'
 * '<S23>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver'
 * '<S24>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal/IIR Filter'
 * '<S25>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal/IIR Filter/IIR Filter'
 * '<S26>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass'
 * '<S27>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S28>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal1/IIR Filter'
 * '<S29>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal1/IIR Filter/IIR Filter'
 * '<S30>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal1/IIR Filter/IIR Filter/Low-pass'
 * '<S31>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/DC component removal1/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S32>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/Compare To Constant'
 * '<S33>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem'
 * '<S34>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/SpeedMeasurementSubsystem'
 * '<S35>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/atan2'
 * '<S36>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiAlpha'
 * '<S37>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiBeta'
 * '<S38>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/atan2/Per Unit'
 * '<S39>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiAlpha/IIR Filter3'
 * '<S40>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiAlpha/Scaling'
 * '<S41>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiAlpha/IIR Filter3/IIR Filter'
 * '<S42>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiAlpha/IIR Filter3/IIR Filter/Low-pass'
 * '<S43>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiAlpha/IIR Filter3/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S44>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiBeta/IIR Filter'
 * '<S45>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiBeta/Scaling'
 * '<S46>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiBeta/IIR Filter/IIR Filter'
 * '<S47>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiBeta/IIR Filter/IIR Filter/Low-pass'
 * '<S48>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/FluxObserverSubsystem/psiBeta/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S49>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/SpeedMeasurementSubsystem/IIR Filter'
 * '<S50>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/SpeedMeasurementSubsystem/Speed_measurement'
 * '<S51>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/SpeedMeasurementSubsystem/atan2'
 * '<S52>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/SpeedMeasurementSubsystem/IIR Filter/IIR Filter'
 * '<S53>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/SpeedMeasurementSubsystem/IIR Filter/IIR Filter/Low-pass'
 * '<S54>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/SpeedMeasurementSubsystem/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S55>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Flux Observer/FluxObvserver/SpeedMeasurementSubsystem/atan2/Per Unit'
 * '<S56>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark'
 * '<S57>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark '
 * '<S58>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Inverse Park Transform'
 * '<S59>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up'
 * '<S60>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop'
 * '<S61>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/SendSignalOverSerial'
 * '<S62>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Sine-Cosine Lookup'
 * '<S63>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Space Vector Generator1'
 * '<S64>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark/Clarke Transform'
 * '<S65>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark/Park Transform'
 * '<S66>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark/Pole_Voltage to Phase_Voltage'
 * '<S67>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark/Clarke Transform/Two phase input'
 * '<S68>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S69>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark/Park Transform/Two inputs CRL'
 * '<S70>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S71>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark /Clarke Transform'
 * '<S72>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark /Park Transform'
 * '<S73>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark /Clarke Transform/Two phase input'
 * '<S74>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark /Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S75>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark /Park Transform/Two inputs CRL'
 * '<S76>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/ClarkePark /Park Transform/Two inputs CRL/Switch_Axis'
 * '<S77>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Inverse Park Transform/Inverse Park Transform'
 * '<S78>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Inverse Park Transform/Inverse Park Transform/Two inputs CRL'
 * '<S79>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Inverse Park Transform/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S80>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Compare To Constant1'
 * '<S81>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up'
 * '<S82>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator'
 * '<S83>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/Clarke Transform'
 * '<S84>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/Compare To Constant'
 * '<S85>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/Position Generator'
 * '<S86>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/Ramp Generator'
 * '<S87>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/V-by-f'
 * '<S88>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S89>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S90>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup'
 * '<S91>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Two phase input'
 * '<S92>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL'
 * '<S93>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S94>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/Interpolation'
 * '<S95>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp'
 * '<S96>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S97>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S98>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/3-Phase Sine Voltage Generator/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S99>'  : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/Clarke Transform/Two phase input'
 * '<S100>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S101>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/Position Generator/Accumulate'
 * '<S102>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Open Loop Start-Up/Open Loop Start-Up/Position Generator/Accumulate/Subsystem'
 * '<S103>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Compare To Constant'
 * '<S104>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control'
 * '<S105>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop'
 * '<S106>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter'
 * '<S107>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset'
 * '<S108>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1'
 * '<S109>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D-Q Equivalence'
 * '<S110>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority'
 * '<S111>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/Inport//Dialog Selection'
 * '<S112>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/Magnitude_calc'
 * '<S113>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S114>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S115>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S116>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S117>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S118>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S119>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S120>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S121>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S122>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S123>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S124>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S125>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S126>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S127>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S128>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S129>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S130>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S131>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S132>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S133>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S134>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S135>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S136>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S137>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S138>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S139>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S140>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S141>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S142>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S143>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S144>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S145>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S146>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S147>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S148>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S149>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S150>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S151>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S152>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S153>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S154>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S155>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S156>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S157>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S158>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S159>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S160>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S161>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S162>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S163>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S164>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S165>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S166>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S167>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S168>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S169>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S170>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S171>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S172>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S173>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S174>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S175>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Anti-windup'
 * '<S176>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/D Gain'
 * '<S177>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/External Derivative'
 * '<S178>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Filter'
 * '<S179>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Filter ICs'
 * '<S180>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/I Gain'
 * '<S181>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Ideal P Gain'
 * '<S182>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Ideal P Gain Fdbk'
 * '<S183>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Integrator'
 * '<S184>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Integrator ICs'
 * '<S185>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/N Copy'
 * '<S186>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/N Gain'
 * '<S187>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/P Copy'
 * '<S188>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Parallel P Gain'
 * '<S189>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Reset Signal'
 * '<S190>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Saturation'
 * '<S191>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Saturation Fdbk'
 * '<S192>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Sum'
 * '<S193>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Sum Fdbk'
 * '<S194>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Tracking Mode'
 * '<S195>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Tracking Mode Sum'
 * '<S196>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Tsamp - Integral'
 * '<S197>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Tsamp - Ngain'
 * '<S198>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/postSat Signal'
 * '<S199>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/preSat Signal'
 * '<S200>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Anti-windup/Disc. Clamping Parallel'
 * '<S201>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S202>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S203>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/D Gain/Disabled'
 * '<S204>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/External Derivative/Disabled'
 * '<S205>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Filter/Disabled'
 * '<S206>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Filter ICs/Disabled'
 * '<S207>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/I Gain/External Parameters'
 * '<S208>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Ideal P Gain/Passthrough'
 * '<S209>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Ideal P Gain Fdbk/Disabled'
 * '<S210>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Integrator/Discrete'
 * '<S211>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Integrator ICs/External IC'
 * '<S212>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/N Copy/Disabled wSignal Specification'
 * '<S213>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/N Gain/Disabled'
 * '<S214>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/P Copy/Disabled'
 * '<S215>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Parallel P Gain/External Parameters'
 * '<S216>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Reset Signal/External Reset'
 * '<S217>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Saturation/Enabled'
 * '<S218>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Saturation Fdbk/Disabled'
 * '<S219>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Sum/Sum_PI'
 * '<S220>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Sum Fdbk/Disabled'
 * '<S221>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Tracking Mode/Disabled'
 * '<S222>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Tracking Mode Sum/Passthrough'
 * '<S223>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Tsamp - Integral/TsSignalSpecification'
 * '<S224>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/Tsamp - Ngain/Passthrough'
 * '<S225>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/postSat Signal/Forward_Path'
 * '<S226>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/Control/Discrete PI Controller  with anti-windup & reset1/preSat Signal/Forward_Path'
 * '<S227>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/ADC_Calibration'
 * '<S228>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas'
 * '<S229>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/Rs_Measurement'
 * '<S230>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas'
 * '<S231>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2'
 * '<S232>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Position Generator'
 * '<S233>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Sine-Cosine Lookup'
 * '<S234>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Position Generator/Accumulate'
 * '<S235>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Position Generator/Accumulate/Subsystem'
 * '<S236>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Sine-Cosine Lookup/Interpolation'
 * '<S237>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Sine-Cosine Lookup/WrapUp'
 * '<S238>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S239>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S240>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/BiasedSineWaveLdMeas/Sine2/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S241>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3'
 * '<S242>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Position Generator'
 * '<S243>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Sine-Cosine Lookup'
 * '<S244>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Position Generator/Accumulate'
 * '<S245>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Position Generator/Accumulate/Subsystem'
 * '<S246>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Sine-Cosine Lookup/Interpolation'
 * '<S247>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Sine-Cosine Lookup/WrapUp'
 * '<S248>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S249>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S250>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/OpenLoop_CloseLoop/OpenLoop/SineWaveLqMeas/Sine3/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S251>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Sine-Cosine Lookup/Interpolation'
 * '<S252>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Sine-Cosine Lookup/WrapUp'
 * '<S253>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S254>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S255>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S256>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Space Vector Generator1/Modulation method'
 * '<S257>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Space Vector Generator1/Voltage Input'
 * '<S258>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Space Vector Generator1/Modulation method/SVPWM'
 * '<S259>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Space Vector Generator1/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S260>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Space Vector Generator1/Voltage Input/Valphabeta'
 * '<S261>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Space Vector Generator1/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S262>' : 'nucleo_g431re_ihm07m1/Alogrithm/Control Algorithm/Generating Raw Space Vectors/Space Vector Generator1/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S263>' : 'nucleo_g431re_ihm07m1/Alogrithm/EnableMosfets/Digital Port Write'
 * '<S264>' : 'nucleo_g431re_ihm07m1/Alogrithm/EnableMosfets/Digital Port Write/ECSoC'
 * '<S265>' : 'nucleo_g431re_ihm07m1/Alogrithm/EnableMosfets/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S266>' : 'nucleo_g431re_ihm07m1/Alogrithm/IIR Filter/IIR Filter'
 * '<S267>' : 'nucleo_g431re_ihm07m1/Alogrithm/IIR Filter/IIR Filter/Low-pass'
 * '<S268>' : 'nucleo_g431re_ihm07m1/Alogrithm/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S269>' : 'nucleo_g431re_ihm07m1/Alogrithm/Inputs/Analog to Digital Converter'
 * '<S270>' : 'nucleo_g431re_ihm07m1/Alogrithm/Inputs/Analog to Digital Converter/ECSoC'
 * '<S271>' : 'nucleo_g431re_ihm07m1/Alogrithm/Inputs/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S272>' : 'nucleo_g431re_ihm07m1/Alogrithm/PWM_HW/PWM Output'
 * '<S273>' : 'nucleo_g431re_ihm07m1/Alogrithm/PWM_HW/PWM scaling'
 * '<S274>' : 'nucleo_g431re_ihm07m1/Alogrithm/PWM_HW/PWM Output/ECSoC'
 * '<S275>' : 'nucleo_g431re_ihm07m1/Alogrithm/PWM_HW/PWM Output/ECSoC/ECSimCodegen'
 * '<S276>' : 'nucleo_g431re_ihm07m1/Alogrithm/ParameterEstimationTests/Algorithm Parameters'
 * '<S277>' : 'nucleo_g431re_ihm07m1/Alogrithm/ParameterEstimationTests/MATLAB Function'
 * '<S278>' : 'nucleo_g431re_ihm07m1/Alogrithm/ParameterEstimationTests/Triggered Subsystem'
 * '<S279>' : 'nucleo_g431re_ihm07m1/Alogrithm/ParameterEstimationTests/counter'
 * '<S280>' : 'nucleo_g431re_ihm07m1/Alogrithm/Reference signal  conditioning/Compare To Constant'
 * '<S281>' : 'nucleo_g431re_ihm07m1/Alogrithm/Reference signal  conditioning/Torque_control_with_speed_limit'
 * '<S282>' : 'nucleo_g431re_ihm07m1/Alogrithm/Reference signal  conditioning/Torque_control_with_speed_limit/Derating Function'
 * '<S283>' : 'nucleo_g431re_ihm07m1/Alogrithm/Reference signal  conditioning/Torque_control_with_speed_limit/Derating Function/Compare To Constant'
 * '<S284>' : 'nucleo_g431re_ihm07m1/Alogrithm/Reference signal  conditioning/Torque_control_with_speed_limit/Derating Function/Handle divide by 0'
 * '<S285>' : 'nucleo_g431re_ihm07m1/Alogrithm/Reference signal  conditioning/Torque_control_with_speed_limit/Derating Function/If Action Subsystem'
 * '<S286>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/ChangeDetect'
 * '<S287>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory'
 * '<S288>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send'
 * '<S289>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/B'
 * '<S290>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/Bemf'
 * '<S291>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/ErrorCase'
 * '<S292>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/Ia_cal_val'
 * '<S293>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/Ib_cal_val'
 * '<S294>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/J'
 * '<S295>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/Ld'
 * '<S296>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/Lq'
 * '<S297>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/PhaseDiffValidity'
 * '<S298>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/SaveToMemory/Rs'
 * '<S299>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/AlternateData'
 * '<S300>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/Serial Send'
 * '<S301>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/AlternateData/Alternate_0_2'
 * '<S302>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/Serial Send/Counter Limited'
 * '<S303>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/Serial Send/Data'
 * '<S304>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/Serial Send/End'
 * '<S305>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/Serial Send/Start'
 * '<S306>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/Serial Send/While Iterator Subsystem'
 * '<S307>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/Serial Send/Counter Limited/Increment Real World'
 * '<S308>' : 'nucleo_g431re_ihm07m1/Alogrithm/SaveEstParam_Serial Send/Serial Send/Serial Send/Counter Limited/Wrap To Zero'
 * '<S309>' : 'nucleo_g431re_ihm07m1/Function-Call Subsystem/Analog to Digital Converter1'
 * '<S310>' : 'nucleo_g431re_ihm07m1/Function-Call Subsystem/Analog to Digital Converter1/ECSoC'
 * '<S311>' : 'nucleo_g431re_ihm07m1/Function-Call Subsystem/Analog to Digital Converter1/ECSoC/ECSimCodegen'
 * '<S312>' : 'nucleo_g431re_ihm07m1/Hardware Interrupt/ECSoC'
 * '<S313>' : 'nucleo_g431re_ihm07m1/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S314>' : 'nucleo_g431re_ihm07m1/Heartbeat/Digital Port Write'
 * '<S315>' : 'nucleo_g431re_ihm07m1/Heartbeat/Digital Port Write/ECSoC'
 * '<S316>' : 'nucleo_g431re_ihm07m1/Heartbeat/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S317>' : 'nucleo_g431re_ihm07m1/Initialize Function/PWM Output'
 * '<S318>' : 'nucleo_g431re_ihm07m1/Initialize Function/PWM Output/ECSoC'
 * '<S319>' : 'nucleo_g431re_ihm07m1/Initialize Function/PWM Output/ECSoC/ECSimCodegen'
 * '<S320>' : 'nucleo_g431re_ihm07m1/SerialReceive/Rx_single'
 * '<S321>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem'
 * '<S322>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem10'
 * '<S323>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem11'
 * '<S324>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem13'
 * '<S325>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem14'
 * '<S326>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem15'
 * '<S327>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem16'
 * '<S328>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem17'
 * '<S329>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem18'
 * '<S330>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem19'
 * '<S331>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem2'
 * '<S332>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem20'
 * '<S333>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem21'
 * '<S334>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem22'
 * '<S335>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem3'
 * '<S336>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem4'
 * '<S337>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem5'
 * '<S338>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem6'
 * '<S339>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem7'
 * '<S340>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem8'
 * '<S341>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem9'
 * '<S342>' : 'nucleo_g431re_ihm07m1/SerialReceive/Rx_single/Compare To Zero'
 * '<S343>' : 'nucleo_g431re_ihm07m1/SerialReceive/Rx_single/Enabled Subsystem'
 * '<S344>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem/Compare To Constant'
 * '<S345>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem/Compare To Constant1'
 * '<S346>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem/Compare To Constant2'
 * '<S347>' : 'nucleo_g431re_ihm07m1/SerialReceive/Switch Case Action Subsystem10/bytepack'
 */
#endif                                 /* nucleo_g431re_ihm07m1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
