/*
 * File: mcb_param_est_sensorless_nucleo_g474re_ihm07m1_private.h
 *
 * Code generated for Simulink model 'mcb_param_est_sensorless_nucleo_g474re_ihm07m1'.
 *
 * Model version                  : 8.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Jan 15 15:15:17 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_param_est_sensorless_nucleo_g474re_ihm07m1_private_h_
#define mcb_param_est_sensorless_nucleo_g474re_ihm07m1_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "mcb_param_est_sensorless_nucleo_g474re_ihm07m1.h"
#include "mcb_param_est_sensorless_nucleo_g474re_ihm07m1_types.h"

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern void mcb_param_est_sensorl_atan2(real32_T rtu_A, real32_T rtu_B, uint16_T
  rtp_outputUnit, rtB_atan2_mcb_param_est_sensorl *localB);
extern void mcb_param_e_TwophaseCRLwrap(real32_T rtu_a, real32_T rtu_b,
  rtB_TwophaseCRLwrap_mcb_param_e *localB);
extern void mcb_param_est__TwoinputsCRL(real32_T rtu_Alpha, real32_T rtu_Beta,
  real32_T rtu_sine, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_param_est_ *localB);
extern void mcb_param_es_TwoinputsCRL_j(real32_T rtu_Ds, real32_T rtu_Qs,
  real32_T rtu_sin, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_param_es_d *localB);
extern void mcb_param_IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_mcb_param *localB);
extern void mcb_para_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_mcb_para *localB);
extern void mcb_param_est_se_Accumulate(boolean_T rtu_Enable, real32_T rtu_Theta,
  real32_T rtu_Theta_e_prev, rtB_Accumulate_mcb_param_est_se *localB,
  rtDW_Accumulate_mcb_param_est_s *localDW);

#endif           /* mcb_param_est_sensorless_nucleo_g474re_ihm07m1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
