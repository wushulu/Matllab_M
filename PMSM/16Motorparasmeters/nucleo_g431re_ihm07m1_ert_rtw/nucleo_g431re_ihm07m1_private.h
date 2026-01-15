/*
 * File: nucleo_g431re_ihm07m1_private.h
 *
 * Code generated for Simulink model 'nucleo_g431re_ihm07m1'.
 *
 * Model version                  : 8.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jan 16 15:47:25 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef nucleo_g431re_ihm07m1_private_h_
#define nucleo_g431re_ihm07m1_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "nucleo_g431re_ihm07m1.h"
#include "nucleo_g431re_ihm07m1_types.h"

extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern void nucleo_g431re_ihm07m1_atan2(real32_T rtu_A, real32_T rtu_B, uint16_T
  rtp_outputUnit, rtB_atan2_nucleo_g431re_ihm07m1 *localB);
extern void nucleo_g431_TwophaseCRLwrap(real32_T rtu_a, real32_T rtu_b,
  rtB_TwophaseCRLwrap_nucleo_g431 *localB);
extern void nucleo_g431re__TwoinputsCRL(real32_T rtu_Alpha, real32_T rtu_Beta,
  real32_T rtu_sine, real32_T rtu_cos, rtB_TwoinputsCRL_nucleo_g431re_ *localB);
extern void nucleo_g431r_TwoinputsCRL_j(real32_T rtu_Ds, real32_T rtu_Qs,
  real32_T rtu_sin, real32_T rtu_cos, rtB_TwoinputsCRL_nucleo_g431r_d *localB);
extern void nucleo_g4_IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_nucleo_g4 *localB);
extern void nucleo_g_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_nucleo_g *localB);
extern void nucleo_g431re_ih_Accumulate(boolean_T rtu_Enable, real32_T rtu_Theta,
  real32_T rtu_Theta_e_prev, rtB_Accumulate_nucleo_g431re_ih *localB,
  rtDW_Accumulate_nucleo_g431re_i *localDW);

#endif                                 /* nucleo_g431re_ihm07m1_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
