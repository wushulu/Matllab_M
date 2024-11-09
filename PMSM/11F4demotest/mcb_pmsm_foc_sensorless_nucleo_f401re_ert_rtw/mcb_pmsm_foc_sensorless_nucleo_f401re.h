/*
 * File: mcb_pmsm_foc_sensorless_nucleo_f401re.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_nucleo_f401re'.
 *
 * Model version                  : 8.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Nov  8 22:37:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_sensorless_nucleo_f401re_h_
#define mcb_pmsm_foc_sensorless_nucleo_f401re_h_
#ifndef mcb_pmsm_foc_sensorless_nucleo_f401re_COMMON_INCLUDES_
#define mcb_pmsm_foc_sensorless_nucleo_f401re_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "main.h"
#include "stm_uart.h"
#endif              /* mcb_pmsm_foc_sensorless_nucleo_f401re_COMMON_INCLUDES_ */

#include "mw_stm32_nvic.h"
#include "mcb_pmsm_foc_sensorless_nucleo_f401re_types.h"
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

#define mcb_pmsm_foc_sensorless_nucleo_f401re_M (mcb_pmsm_foc_sensorless_nucl_M)

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real_T IntegrateTime;                /* '<S220>/Integrate Time' */
  real32_T Switch;                     /* '<S214>/Switch' */
  real32_T Constant2;                  /* '<S6>/Constant2' */
  real32_T RateLimiter;                /* '<S216>/Rate Limiter' */
  real32_T RateLimiter1;               /* '<S216>/Rate Limiter1' */
  real32_T Switch_p;                   /* '<S216>/Switch' */
  real32_T Switch1[2];                 /* '<S277>/Switch1' */
  real32_T Product;                    /* '<S280>/Product' */
  real32_T UnitDelay;                  /* '<S280>/Unit Delay' */
  real32_T Product1;                   /* '<S280>/Product1' */
  real32_T Add1;                       /* '<S280>/Add1' */
  real32_T Abs;                        /* '<S217>/Abs' */
  real32_T Switch_i;                   /* '<S217>/Switch' */
  real32_T Sum;                        /* '<S215>/Sum' */
  real32_T PProdOut;                   /* '<S265>/PProd Out' */
  real32_T Ki2;                        /* '<S215>/Ki2' */
  real32_T Integrator;                 /* '<S260>/Integrator' */
  real32_T Sum_b;                      /* '<S269>/Sum' */
  real32_T DeadZone;                   /* '<S252>/DeadZone' */
  real32_T IProdOut;                   /* '<S257>/IProd Out' */
  real32_T Switch_pd;                  /* '<S250>/Switch' */
  real32_T Saturation;                 /* '<S267>/Saturation' */
  real32_T Switch1_l;                  /* '<S217>/Switch1' */
  real32_T Passvalue;                  /* '<S220>/Pass value' */
  real32_T Gain1;                      /* '<S214>/Gain1' */
  real32_T rpm2PU1;                    /* '<S214>/rpm2PU1' */
  uint16_T AnalogtoDigitalConverter;  /* '<S222>/Analog to Digital Converter' */
  int8_T Switch1_o;                    /* '<S250>/Switch1' */
  int8_T Switch2;                      /* '<S250>/Switch2' */
  boolean_T NOT;                       /* '<S218>/NOT' */
  boolean_T UnitDelay_n;               /* '<S218>/Unit Delay' */
  boolean_T NOT2;                      /* '<S218>/NOT2' */
  boolean_T AND;                       /* '<S218>/AND' */
  boolean_T UnitDelay_l;               /* '<S220>/Unit Delay' */
  boolean_T RelationalOperator;        /* '<S220>/Relational Operator' */
  boolean_T Switch2_m;                 /* '<S217>/Switch2' */
  boolean_T AND_g;                     /* '<S215>/AND' */
  boolean_T LogicalOperator;           /* '<S215>/Logical Operator' */
  boolean_T RelationalOperator_l;      /* '<S250>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S250>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S250>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S250>/Equal1' */
  boolean_T AND3;                      /* '<S250>/AND3' */
  boolean_T Switch_o;                  /* '<S283>/Switch' */
  boolean_T NOT_p;                     /* '<S283>/NOT' */
  boolean_T UnitDelay_k;               /* '<S282>/Unit Delay' */
  boolean_T NOT_b;                     /* '<S282>/NOT' */
  boolean_T DigitalPortRead;           /* '<S285>/Digital Port Read' */
  boolean_T Compare;                   /* '<S223>/Compare' */
} rtB_SpeedControl_mcb_pmsm_foc_s;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  stm32cube_blocks_AnalogInput_mc obj;/* '<S222>/Analog to Digital Converter' */
  real_T IntegrateTime_DSTATE;         /* '<S220>/Integrate Time' */
  real32_T UnitDelay_DSTATE;           /* '<S280>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S260>/Integrator' */
  real32_T PrevY;                      /* '<S216>/Rate Limiter' */
  real32_T PrevY_d;                    /* '<S216>/Rate Limiter1' */
  stm32cube_blocks_DigitalPortWri obj_j;/* '<S288>/Digital Port Write' */
  stm32cube_blocks_DigitalPortRea obj_n;/* '<S285>/Digital Port Read' */
  boolean_T UnitDelay_DSTATE_l;        /* '<S218>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_b;        /* '<S220>/Unit Delay' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S282>/Unit Delay' */
  int8_T IntegrateTime_PrevResetState; /* '<S220>/Integrate Time' */
  int8_T Integrator_PrevResetState;    /* '<S260>/Integrator' */
  boolean_T objisempty;                /* '<S288>/Digital Port Write' */
  boolean_T objisempty_h;              /* '<S285>/Digital Port Read' */
  boolean_T objisempty_m;             /* '<S222>/Analog to Digital Converter' */
} rtDW_SpeedControl_mcb_pmsm_foc_;

/* Block signals (default storage) */
typedef struct {
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T SineWave1;                    /* '<Root>/Sine Wave1' */
  real_T SineWave2;                    /* '<Root>/Sine Wave2' */
  uint32_T Sum[4];                     /* '<S21>/Sum' */
  uint32_T PositionToCount;            /* '<S183>/PositionToCount' */
  uint32_T Delay;                      /* '<S183>/Delay' */
  real32_T DataTypeConversion;         /* '<Root>/Data Type Conversion' */
  real32_T Assignment[3];              /* '<S7>/Assignment' */
  real32_T DataTypeConversion1;        /* '<Root>/Data Type Conversion1' */
  real32_T Assignment1[3];             /* '<S7>/Assignment1' */
  real32_T DataTypeConversion2;        /* '<Root>/Data Type Conversion2' */
  real32_T Assignment2[3];             /* '<S7>/Assignment2' */
  real32_T RT3;                        /* '<Root>/RT3' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T GetADCVoltage[2];           /* '<S174>/Get ADC Voltage' */
  real32_T GetCurrents[2];             /* '<S174>/Get Currents' */
  real32_T PU_Conversion[2];           /* '<S174>/PU_Conversion' */
  real32_T InvertingNoninvertingCurrentmea[2];
       /* '<S171>/Inverting // Non-inverting  Current measurement  amplifier' */
  real32_T UnitDelay1;                 /* '<S188>/Unit Delay1' */
  real32_T UnitDelay;                  /* '<S188>/Unit Delay' */
  real32_T a;                          /* '<S188>/a' */
  real32_T Delay5[4];                  /* '<S2>/Delay5' */
  real32_T Delay_g;                    /* '<S178>/Delay' */
  real32_T Sum2;                       /* '<S178>/Sum2' */
  real32_T Sum3;                       /* '<S188>/Sum3' */
  real32_T b_invg;                     /* '<S188>/b_inv*g' */
  real32_T Delay1;                     /* '<S188>/Delay1' */
  real32_T Sum4;                       /* '<S188>/Sum4' */
  real32_T Switch1[2];                 /* '<S180>/Switch1' */
  real32_T Product;                    /* '<S192>/Product' */
  real32_T UnitDelay_o;                /* '<S192>/Unit Delay' */
  real32_T Product1;                   /* '<S192>/Product1' */
  real32_T Add1;                       /* '<S192>/Add1' */
  real32_T UnitDelay1_k;               /* '<S189>/Unit Delay1' */
  real32_T UnitDelay_e;                /* '<S189>/Unit Delay' */
  real32_T a_g;                        /* '<S189>/a' */
  real32_T Delay_c;                    /* '<S179>/Delay' */
  real32_T Sum2_b;                     /* '<S179>/Sum2' */
  real32_T Sum3_n;                     /* '<S189>/Sum3' */
  real32_T b_invg_n;                   /* '<S189>/b_inv*g' */
  real32_T Delay1_n;                   /* '<S189>/Delay1' */
  real32_T Sum4_g;                     /* '<S189>/Sum4' */
  real32_T Switch1_b[2];               /* '<S181>/Switch1' */
  real32_T Product_e;                  /* '<S195>/Product' */
  real32_T UnitDelay_l;                /* '<S195>/Unit Delay' */
  real32_T Product1_m;                 /* '<S195>/Product1' */
  real32_T Add1_i;                     /* '<S195>/Add1' */
  real32_T Merge;                      /* '<S177>/Merge' */
  real32_T Merge1;                     /* '<S177>/Merge1' */
  real32_T Delay_f;                    /* '<S176>/Delay' */
  real32_T Gain;                       /* '<S19>/Gain' */
  real32_T UnitDelay_p;                /* '<S150>/Unit Delay' */
  real32_T Switch;                     /* '<S19>/Switch' */
  real32_T Merge_g;                    /* '<S156>/Merge' */
  real32_T indexing;                   /* '<S21>/indexing' */
  real32_T Lookup[4];                  /* '<S21>/Lookup' */
  real32_T Sum3_p;                     /* '<S155>/Sum3' */
  real32_T DataTypeConversion1_o;      /* '<S21>/Data Type Conversion1' */
  real32_T Sum2_bl;                    /* '<S21>/Sum2' */
  real32_T Product_ez;                 /* '<S155>/Product' */
  real32_T Sum4_f;                     /* '<S155>/Sum4' */
  real32_T Sum5;                       /* '<S155>/Sum5' */
  real32_T Product1_n;                 /* '<S155>/Product1' */
  real32_T Sum6;                       /* '<S155>/Sum6' */
  real32_T Sum_g;                      /* '<S27>/Sum' */
  real32_T PProdOut;                   /* '<S136>/PProd Out' */
  real32_T UnitDelay_c;                /* '<S27>/Unit Delay' */
  real32_T Integrator;                 /* '<S131>/Integrator' */
  real32_T Sum_l;                      /* '<S140>/Sum' */
  real32_T Switch_h;                   /* '<S27>/Switch' */
  real32_T Sum_k;                      /* '<S26>/Sum' */
  real32_T PProdOut_a;                 /* '<S83>/PProd Out' */
  real32_T UnitDelay_m;                /* '<S26>/Unit Delay' */
  real32_T Integrator_c;               /* '<S78>/Integrator' */
  real32_T Sum_kn;                     /* '<S87>/Sum' */
  real32_T Switch_l;                   /* '<S26>/Switch' */
  real32_T Switch_f;                   /* '<S30>/Switch' */
  real32_T Product_b;                  /* '<S30>/Product' */
  real32_T Product_k;                  /* '<S31>/Product' */
  real32_T Product1_no;                /* '<S31>/Product1' */
  real32_T Sum1;                       /* '<S31>/Sum1' */
  real32_T Merge_e[2];                 /* '<S25>/Merge' */
  real32_T DeadZone;                   /* '<S70>/DeadZone' */
  real32_T IProdOut;                   /* '<S75>/IProd Out' */
  real32_T Switch_fm;                  /* '<S68>/Switch' */
  real32_T DeadZone_d;                 /* '<S123>/DeadZone' */
  real32_T IProdOut_h;                 /* '<S128>/IProd Out' */
  real32_T Switch_m;                   /* '<S121>/Switch' */
  real32_T Sign;                       /* '<S178>/Sign' */
  real32_T Eta;                        /* '<S178>/Eta' */
  real32_T Sum_i;                      /* '<S178>/Sum' */
  real32_T b;                          /* '<S178>/b' */
  real32_T a_o;                        /* '<S178>/a' */
  real32_T Sum1_c;                     /* '<S178>/Sum1' */
  real32_T Sign_m;                     /* '<S179>/Sign' */
  real32_T Eta_e;                      /* '<S179>/Eta' */
  real32_T Sum_iv;                     /* '<S179>/Sum' */
  real32_T b_n;                        /* '<S179>/b' */
  real32_T a_gy;                       /* '<S179>/a' */
  real32_T Sum1_h;                     /* '<S179>/Sum1' */
  real32_T DTC;                        /* '<S200>/DTC' */
  real32_T SpeedGain;                  /* '<S183>/SpeedGain' */
  real32_T Switch1_bl[2];              /* '<S182>/Switch1' */
  real32_T Product_m;                  /* '<S198>/Product' */
  real32_T UnitDelay_g;                /* '<S198>/Unit Delay' */
  real32_T Product1_mm;                /* '<S198>/Product1' */
  real32_T Add1_c;                     /* '<S198>/Add1' */
  real32_T SpeedConversion;            /* '<S176>/SpeedConversion' */
  real32_T PWM_Duty_Cycles[3];         /* '<S15>/Switch' */
  real32_T Scale_to_PWM_Counter_PRD[3];/* '<S14>/Scale_to_PWM_Counter_PRD' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T sqrt3_by_two;               /* '<S166>/sqrt3_by_two' */
  real32_T one_by_two;                 /* '<S166>/one_by_two' */
  real32_T add_c;                      /* '<S166>/add_c' */
  real32_T add_b;                      /* '<S166>/add_b' */
  real32_T Min;                        /* '<S163>/Min' */
  real32_T Max;                        /* '<S163>/Max' */
  real32_T Add;                        /* '<S163>/Add' */
  real32_T one_by_two_p;               /* '<S163>/one_by_two' */
  real32_T Add3;                       /* '<S162>/Add3' */
  real32_T Add2;                       /* '<S162>/Add2' */
  real32_T Add1_i4;                    /* '<S162>/Add1' */
  real32_T Gain_f[3];                  /* '<S162>/Gain' */
  real32_T One_by_Two[3];              /* '<S15>/One_by_Two' */
  real32_T Sum_h[3];                   /* '<S15>/Sum' */
  real32_T Product_c;                  /* '<S184>/Product' */
  real32_T Product2;                   /* '<S184>/Product2' */
  real32_T Sum1_h1;                    /* '<S184>/Sum1' */
  real32_T Product1_f;                 /* '<S184>/Product1' */
  real32_T Product3;                   /* '<S184>/Product3' */
  real32_T Sum2_k;                     /* '<S184>/Sum2' */
  real32_T Switch_l4;                  /* '<S184>/Switch' */
  real32_T Atan2;                      /* '<S201>/Atan2' */
  real32_T Switch_i;                   /* '<S201>/Switch' */
  real32_T algDD;
  real32_T Gain_n;                     /* '<S202>/Gain' */
  real32_T Switch_b;                   /* '<S202>/Switch' */
  real32_T Bias;                       /* '<S202>/Bias' */
  real32_T Bias_e;                     /* '<S184>/Bias' */
  real32_T Convert_back;               /* '<S159>/Convert_back' */
  real32_T Convert_back_a;             /* '<S158>/Convert_back' */
  real32_T acos_k;                     /* '<S153>/acos' */
  real32_T bsin;                       /* '<S153>/bsin' */
  real32_T sum_Ds;                     /* '<S153>/sum_Ds' */
  real32_T bcos;                       /* '<S153>/bcos' */
  real32_T asin_e;                     /* '<S153>/asin' */
  real32_T sum_Qs;                     /* '<S153>/sum_Qs' */
  real32_T Switch_o[2];                /* '<S154>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T AngleConversion;            /* '<S176>/AngleConversion' */
  real32_T Add_o;                      /* '<S151>/Add' */
  real32_T DataTypeConversion1_j;      /* '<S151>/Data Type Conversion1' */
  real32_T Add1_g;                     /* '<S151>/Add1' */
  real32_T Input;                      /* '<S152>/Input' */
  real32_T qcos;                       /* '<S148>/qcos' */
  real32_T dsin;                       /* '<S148>/dsin' */
  real32_T sum_beta;                   /* '<S148>/sum_beta' */
  real32_T dcos;                       /* '<S148>/dcos' */
  real32_T qsin;                       /* '<S148>/qsin' */
  real32_T sum_alpha;                  /* '<S148>/sum_alpha' */
  real32_T Switch_ih[2];               /* '<S149>/Switch' */
  real32_T algDD_o1_o;
  real32_T algDD_o2_k;
  real32_T Saturation;                 /* '<S138>/Saturation' */
  real32_T Abs;                        /* '<S26>/Abs' */
  real32_T Saturation_h;               /* '<S26>/Saturation' */
  real32_T Saturation_i;               /* '<S85>/Saturation' */
  real32_T Product_l[2];               /* '<S32>/Product' */
  real32_T SquareRoot;                 /* '<S32>/Square Root' */
  real32_T Switch_a;                   /* '<S32>/Switch' */
  real32_T Switch_fu[2];               /* '<S29>/Switch' */
  real32_T Switch2;                    /* '<S39>/Switch2' */
  real32_T Product_d;                  /* '<S38>/Product' */
  real32_T Sum_n;                      /* '<S38>/Sum' */
  real32_T Product2_l;                 /* '<S38>/Product2' */
  real32_T Merge_gk;                   /* '<S38>/Merge' */
  real32_T Gain_d;                     /* '<S38>/Gain' */
  real32_T Switch_p;                   /* '<S39>/Switch' */
  real32_T Switch1_n;                  /* '<S40>/Switch1' */
  real32_T Sqrt;                       /* '<S40>/Sqrt' */
  real32_T Gain_du;                    /* '<S40>/Gain' */
  real32_T a_plus_2b;                  /* '<S24>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S24>/one_by_sqrt3' */
  real32_T algDD_o1_n;
  real32_T algDD_o2_e;
  int32_T DataTypeConversion_j[2];     /* '<S171>/Data Type Conversion' */
  int32_T Add_p[2];                    /* '<S171>/Add' */
  int32_T SpeedCount;                  /* '<S183>/SpeedCount' */
  uint16_T UARTUSARTWrite;             /* '<S289>/UART//USART Write' */
  uint16_T DataStoreRead1;             /* '<S171>/Data Store Read1' */
  uint16_T DataStoreRead2;             /* '<S171>/Data Store Read2' */
  uint16_T Switch1_h;                  /* '<S30>/Switch1' */
  uint16_T DataTypeConversion_jp;      /* '<S156>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S21>/Get_Integer' */
  uint16_T AnalogtoDigitalConverter[2];
                                      /* '<S170>/Analog to Digital Converter' */
  uint16_T DataTypeConversion_m;       /* '<S28>/Data Type Conversion' */
  uint16_T DataTypeConversion_e;       /* '<S38>/Data Type Conversion' */
  int16_T Switch_oo;                   /* '<S185>/Switch' */
  int16_T Convert_uint16;              /* '<S159>/Convert_uint16' */
  int16_T Convert_uint16_h;            /* '<S158>/Convert_uint16' */
  int16_T DataTypeConversion_a;        /* '<S151>/Data Type Conversion' */
  int8_T Switch1_m;                    /* '<S68>/Switch1' */
  int8_T Switch2_p;                    /* '<S68>/Switch2' */
  int8_T Switch1_l;                    /* '<S121>/Switch1' */
  int8_T Switch2_k;                    /* '<S121>/Switch2' */
  boolean_T NOT;                       /* '<S289>/NOT' */
  boolean_T RT5;                       /* '<Root>/RT5' */
  boolean_T RT_f;                      /* '<Root>/RT' */
  boolean_T UnitDelay_o1;              /* '<S4>/Unit Delay' */
  boolean_T NOT_n;                     /* '<S4>/NOT' */
  boolean_T LogicalOperator;           /* '<S175>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S177>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S177>/BetaRelay' */
  boolean_T NOT_f;                     /* '<S150>/NOT' */
  boolean_T Compare;                   /* '<S157>/Compare' */
  boolean_T LogicalOperator_i;         /* '<S27>/Logical Operator' */
  boolean_T LogicalOperator_n;         /* '<S26>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S68>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S68>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S68>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S68>/Equal1' */
  boolean_T AND3;                      /* '<S68>/AND3' */
  boolean_T RelationalOperator_c;      /* '<S121>/Relational Operator' */
  boolean_T fixforDTpropagationissue_p;
                                     /* '<S121>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_o;
                                    /* '<S121>/fix for DT propagation issue1' */
  boolean_T Equal1_b;                  /* '<S121>/Equal1' */
  boolean_T AND3_b;                    /* '<S121>/AND3' */
  boolean_T LogicalOperator_f;         /* '<S185>/Logical Operator' */
  boolean_T Delay_fv;                  /* '<S151>/Delay' */
  boolean_T RelationalOperator_e;      /* '<S28>/Relational Operator' */
  boolean_T Compare_e;                 /* '<S34>/Compare' */
  boolean_T Compare_g;                 /* '<S35>/Compare' */
  boolean_T LowerRelop1;               /* '<S39>/LowerRelop1' */
  boolean_T RelationalOperator_h;      /* '<S38>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S39>/UpperRelop' */
  rtB_SpeedControl_mcb_pmsm_foc_s SpeedControl;/* '<Root>/Speed Control' */
} BlockIO_mcb_pmsm_foc_sensorless;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  stm32cube_blocks_UARTWrite_mcb_ obj; /* '<S289>/UART//USART Write' */
  stm32cube_blocks_UARTWrite_mcb_ obj_h;/* '<S290>/UART//USART Write1' */
  stm32cube_blocks_AnalogInput_f obj_d;
                                      /* '<S170>/Analog to Digital Converter' */
  stm32cube_blocks_PWMOutput_mcb_ obj_b;/* '<S205>/PWM Output' */
  real32_T UnitDelay1_DSTATE;          /* '<S188>/Unit Delay1' */
  real32_T UnitDelay_DSTATE;           /* '<S188>/Unit Delay' */
  real32_T Delay5_DSTATE[4];           /* '<S2>/Delay5' */
  real32_T Delay_DSTATE;               /* '<S178>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S188>/Delay1' */
  real32_T UnitDelay_DSTATE_o;         /* '<S192>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_n;        /* '<S189>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_m;         /* '<S189>/Unit Delay' */
  real32_T Delay_DSTATE_k;             /* '<S179>/Delay' */
  real32_T Delay1_DSTATE_e;            /* '<S189>/Delay1' */
  real32_T UnitDelay_DSTATE_g;         /* '<S195>/Unit Delay' */
  real32_T Delay_DSTATE_e;             /* '<S176>/Delay' */
  real32_T UnitDelay_DSTATE_h;         /* '<S150>/Unit Delay' */
  real32_T UnitDelay_DSTATE_a;         /* '<S27>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S131>/Integrator' */
  real32_T UnitDelay_DSTATE_p;         /* '<S26>/Unit Delay' */
  real32_T Integrator_DSTATE_a;        /* '<S78>/Integrator' */
  real32_T UnitDelay_DSTATE_hu;        /* '<S198>/Unit Delay' */
  uint32_T Delay_DSTATE_p[29];         /* '<S183>/Delay' */
  volatile real32_T RT1_Buffer0;       /* '<Root>/RT1' */
  int32_T counter;                     /* '<Root>/Sine Wave' */
  int32_T counter_g;                   /* '<Root>/Sine Wave1' */
  int32_T counter_k;                   /* '<Root>/Sine Wave2' */
  int32_T Add_DWORK1[2];               /* '<S171>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S183>/SpeedCount' */
  uint32_T Sum_DWORK1[4];              /* '<S21>/Sum' */
  uint32_T CircBufIdx;                 /* '<S183>/Delay' */
  stm32cube_blocks_DigitalPortWri obj_ds;/* '<S212>/Digital Port Write' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  boolean_T UnitDelay_DSTATE_c;        /* '<S4>/Unit Delay' */
  boolean_T Delay_DSTATE_b;            /* '<S151>/Delay' */
  int8_T Integrator_PrevResetState;    /* '<S131>/Integrator' */
  int8_T Integrator_PrevResetState_e;  /* '<S78>/Integrator' */
  uint8_T Integrator_IC_LOADING;       /* '<S131>/Integrator' */
  uint8_T Integrator_IC_LOADING_b;     /* '<S78>/Integrator' */
  volatile boolean_T RT_Buffer0;       /* '<Root>/RT' */
  volatile boolean_T RT5_Buffer0;      /* '<Root>/RT5' */
  boolean_T objisempty;                /* '<S289>/UART//USART Write' */
  boolean_T objisempty_n;              /* '<S290>/UART//USART Write1' */
  boolean_T objisempty_c;              /* '<S212>/Digital Port Write' */
  boolean_T AlphaRelay_Mode;           /* '<S177>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S177>/BetaRelay' */
  boolean_T objisempty_a;              /* '<S205>/PWM Output' */
  boolean_T objisempty_e;             /* '<S170>/Analog to Digital Converter' */
  rtDW_SpeedControl_mcb_pmsm_foc_ SpeedControl;/* '<Root>/Speed Control' */
} D_Work_mcb_pmsm_foc_sensorless_;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay_Reset_ZCE;          /* '<S178>/Delay' */
  ZCSigState Delay1_Reset_ZCE;         /* '<S188>/Delay1' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S179>/Delay' */
  ZCSigState Delay1_Reset_ZCE_n;       /* '<S189>/Delay1' */
  ZCSigState Delay_Reset_ZCE_h;        /* '<S176>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S177>/Dir_Sense' */
} PrevZCSigStates_mcb_pmsm_foc_se;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S21>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstParam_mcb_pmsm_foc_sensorl;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_sensorless {
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
extern BlockIO_mcb_pmsm_foc_sensorless mcb_pmsm_foc_sensorless_nucle_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_foc_sensorless_ mcb_pmsm_foc_sensorless_n_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_mcb_pmsm_foc_se mcb_pmsm_foc_sen_PrevZCSigState;

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_foc_sensorl mcb_pmsm_foc_sensorless__ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_sensorless_nucleo_f401re_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_sensorless_nucleo_f401re_initialize(void);
extern void mcb_pmsm_foc_sensorless_nucleo_f401re_step0(void);
extern void mcb_pmsm_foc_sensorless_nucleo_f401re_step1(void);
extern void mcb_pmsm_foc_sensorless_nucleo_f401re_step2(void);
extern void mcb_pmsm_foc_sensorless_nucleo_f401re_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_sensorles *const mcb_pmsm_foc_sensorless_nucl_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  void ADC_IRQHandler(void);
  void mcb_pmsm_foc_sensorless_nucleo_f401re_configure_interrupts (void);
  void mcb_pmsm_foc_sensorless_nucleo_f401re_unconfigure_interrupts (void);

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
 * '<Root>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re'
 * '<S1>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Code generation'
 * '<S2>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control'
 * '<S3>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Hardware Init'
 * '<S4>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Heartbeat LED'
 * '<S5>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Inverter and Motor - Plant Model'
 * '<S6>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control'
 * '<S7>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Subsystem1'
 * '<S8>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Code generation/Hardware Interrupt'
 * '<S9>'   : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Code generation/Hardware Interrupt/ECSoC'
 * '<S10>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Code generation/Hardware Interrupt/ECSoC/ECSimCodegen'
 * '<S11>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop'
 * '<S12>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/HW_Inputs'
 * '<S13>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling'
 * '<S14>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Inverter (Code Generation)'
 * '<S15>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Output Scaling'
 * '<S16>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Clarke Transform'
 * '<S17>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers'
 * '<S18>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Inverse Park Transform'
 * '<S19>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Open_Loop_Control'
 * '<S20>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Park Transform'
 * '<S21>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Sine-Cosine Lookup'
 * '<S22>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Space Vector Generator'
 * '<S23>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Clarke Transform/Two phase input'
 * '<S24>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S25>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter'
 * '<S26>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id'
 * '<S27>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq'
 * '<S28>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S29>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S30>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S31>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S32>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S33>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S34>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S35>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S36>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S37>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S38>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S39>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S40>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S41>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S42>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S43>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S44>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S45>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S46>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S47>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S48>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S49>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S50>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S51>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S52>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S53>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S54>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S55>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S56>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S57>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S58>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S59>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S60>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S61>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S62>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S63>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S64>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S65>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S66>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S67>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S68>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S69>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S70>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S71>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S72>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S73>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S74>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S75>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S76>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S77>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S78>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S79>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S80>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S81>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S82>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S83>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S84>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S85>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S86>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S87>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S88>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S89>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S90>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S91>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S92>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S93>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S94>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S95>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S96>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S97>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S98>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S99>'  : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S100>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S101>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S102>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S103>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S104>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S105>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S106>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S107>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S108>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S109>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S110>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S111>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S112>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S113>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S114>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S115>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S116>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S117>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S118>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S119>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S120>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S121>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S122>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S123>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S124>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S125>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S126>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S127>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S128>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S129>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S130>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S131>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S132>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S133>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S134>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S135>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S136>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S137>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S138>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S139>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S140>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S141>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S142>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S143>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S144>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S145>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S146>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S147>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S148>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL'
 * '<S149>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S150>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Open_Loop_Control/Position Generator'
 * '<S151>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Open_Loop_Control/Position Generator/Accumulate'
 * '<S152>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Open_Loop_Control/Position Generator/Accumulate/Subsystem'
 * '<S153>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Park Transform/Two inputs CRL'
 * '<S154>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S155>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Sine-Cosine Lookup/Interpolation'
 * '<S156>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Sine-Cosine Lookup/WrapUp'
 * '<S157>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S158>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S159>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S160>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Space Vector Generator/Modulation method'
 * '<S161>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Space Vector Generator/Voltage Input'
 * '<S162>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM'
 * '<S163>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S164>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S165>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S166>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S167>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S168>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/HW_Inputs/Sensor Driver Blocks (codegen)/Analog to Digital Converter'
 * '<S169>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/HW_Inputs/Sensor Driver Blocks (codegen)/Analog to Digital Converter/ECSoC'
 * '<S170>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/HW_Inputs/Sensor Driver Blocks (codegen)/Analog to Digital Converter/ECSoC/ECSimCodegen'
 * '<S171>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S172>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed'
 * '<S173>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate Phase Currents/Data_Type'
 * '<S174>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S175>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer'
 * '<S176>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer'
 * '<S177>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch'
 * '<S178>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est'
 * '<S179>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est'
 * '<S180>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha'
 * '<S181>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta'
 * '<S182>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter'
 * '<S183>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement'
 * '<S184>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation'
 * '<S185>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S186>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S187>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S188>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S189>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S190>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S191>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S192>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S193>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S194>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S195>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S196>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S197>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S198>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S199>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S200>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S201>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1'
 * '<S202>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Input Scaling/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 * '<S203>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Inverter (Code Generation)/PWM Output'
 * '<S204>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Inverter (Code Generation)/PWM Output/ECSoC'
 * '<S205>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Current Control/Inverter (Code Generation)/PWM Output/ECSoC/ECSimCodegen'
 * '<S206>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Hardware Init/Offset Calculations'
 * '<S207>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Hardware Init/Offset Calculations/Codegen'
 * '<S208>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Hardware Init/Offset Calculations/Codegen/Default ADC Offset'
 * '<S209>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Heartbeat LED/Code generation'
 * '<S210>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Heartbeat LED/Code generation/Digital Port Write'
 * '<S211>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Heartbeat LED/Code generation/Digital Port Write/ECSoC'
 * '<S212>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Heartbeat LED/Code generation/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S213>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Inverter and Motor - Plant Model/Codegeneration'
 * '<S214>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Calculate Speed Reference'
 * '<S215>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed'
 * '<S216>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/SlewRate'
 * '<S217>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Speed_Ref_Selector'
 * '<S218>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor'
 * '<S219>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Calculate Speed Reference/Speed Reference'
 * '<S220>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Calculate Speed Reference/Subsystem1'
 * '<S221>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Calculate Speed Reference/Speed Reference/ECSoC'
 * '<S222>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Calculate Speed Reference/Speed Reference/ECSoC/ECSimCodegen'
 * '<S223>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Calculate Speed Reference/Subsystem1/Compare To Time'
 * '<S224>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S225>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S226>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S227>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S228>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S229>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S230>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S231>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S232>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S233>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S234>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S235>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S236>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S237>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S238>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S239>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S240>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S241>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S242>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S243>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S244>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S245>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S246>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S247>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S248>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S249>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S250>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S251>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S252>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S253>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S254>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S255>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S256>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S257>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S258>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S259>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S260>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S261>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S262>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S263>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S264>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S265>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S266>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S267>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S268>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S269>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S270>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S271>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S272>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S273>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S274>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S275>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S276>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S277>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Speed_Ref_Selector/Zero_Cancellation'
 * '<S278>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Speed_Ref_Selector/Zero_Cancellation/IIR Filter'
 * '<S279>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Speed_Ref_Selector/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S280>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Speed_Ref_Selector/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S281>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor/Digital Port Read'
 * '<S282>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor/Enabled Subsystem'
 * '<S283>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor/Hardware Initialization'
 * '<S284>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor/Digital Port Read/ECSoC'
 * '<S285>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor/Digital Port Read/ECSoC/ECSimCodegen'
 * '<S286>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor/Hardware Initialization/Digital Port Write'
 * '<S287>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor/Hardware Initialization/Digital Port Write/ECSoC'
 * '<S288>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Speed Control/Start and Stop Motor/Hardware Initialization/Digital Port Write/ECSoC/ECSimCodegen'
 * '<S289>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Subsystem1/Subsystem'
 * '<S290>' : 'mcb_pmsm_foc_sensorless_nucleo_f401re/Subsystem1/Subsystem/Enabled Subsystem'
 */
#endif                            /* mcb_pmsm_foc_sensorless_nucleo_f401re_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
