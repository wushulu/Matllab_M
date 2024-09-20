/*
 * File: GOPIO_private.h
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

#ifndef GOPIO_private_h_
#define GOPIO_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "GOPIO_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);

#endif                                 /* GOPIO_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
