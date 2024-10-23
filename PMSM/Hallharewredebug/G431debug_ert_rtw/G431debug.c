/*
 * File: G431debug.c
 *
 * Code generated for Simulink model 'G431debug'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct 15 07:24:12 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G431debug.h"
#include "rtwtypes.h"

/* Block states (default storage) */
DW_G431debug_T G431debug_DW;

/* Real-time model */
static RT_MODEL_G431debug_T G431debug_M_;
RT_MODEL_G431debug_T *const G431debug_M = &G431debug_M_;

/* Model step function */
void G431debug_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T c;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (G431debug_DW.clockTickCounter <
                        G431debug_P.PulseGenerator_Duty) &&
    (G431debug_DW.clockTickCounter >= 0) ? G431debug_P.PulseGenerator_Amp : 0.0;
  if (G431debug_DW.clockTickCounter >= G431debug_P.PulseGenerator_Period - 1.0)
  {
    G431debug_DW.clockTickCounter = 0;
  } else {
    G431debug_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S3>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S3>/Digital Port Write' */
}

/* Model initialize function */
void G431debug_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void G431debug_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
