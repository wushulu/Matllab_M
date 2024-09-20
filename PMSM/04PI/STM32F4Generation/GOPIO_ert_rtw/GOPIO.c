/*
 * File: GOPIO.c
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

#include "GOPIO.h"
#include "GOPIO_types.h"
#include "GOPIO_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include <float.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_GOPIO_T GOPIO_B;

/* Block states (default storage) */
DW_GOPIO_T GOPIO_DW;

/* Real-time model */
static RT_MODEL_GOPIO_T GOPIO_M_;
RT_MODEL_GOPIO_T *const GOPIO_M = &GOPIO_M_;

/* Forward declaration for local functions */
static void GOPIO_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);

/* Forward declaration for local functions */
static void GOPIO_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_GO_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void GOPIO_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(GOPIO_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (GOPIO_M->Timing.TaskCounters.TID[1])++;
  if ((GOPIO_M->Timing.TaskCounters.TID[1]) > 3999) {/* Sample time: [0.1s, 0.0s] */
    GOPIO_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void GOPIO_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 2U;
  adcStructLoc.InjectedNoOfConversion = 2U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

static void GOPIO_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_GO_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S200>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S200>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S200>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/* Model step function for TID0 */
void GOPIO_step0(void)                 /* Sample time: [2.5E-5s, 0.0s] */
{
  real_T rtb_Gain2;
  real_T rtb_Gain4_tmp;
  real_T rtb_Product_g;
  real_T rtb_Product_n_idx_0;
  real_T rtb_Product_n_idx_1;
  real_T rtb_Product_n_idx_2;
  uint32_T freq;

  {                                    /* Sample time: [2.5E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Saturate: '<S1>/Saturation2' */
  if (GOPIO_B.Add4[0] > GOPIO_P.Saturation2_UpperSat) {
    rtb_Product_n_idx_0 = GOPIO_P.Saturation2_UpperSat;
  } else if (GOPIO_B.Add4[0] < GOPIO_P.Saturation2_LowerSat) {
    rtb_Product_n_idx_0 = GOPIO_P.Saturation2_LowerSat;
  } else {
    rtb_Product_n_idx_0 = GOPIO_B.Add4[0];
  }

  if (GOPIO_B.Add4[1] > GOPIO_P.Saturation2_UpperSat) {
    rtb_Product_n_idx_1 = GOPIO_P.Saturation2_UpperSat;
  } else if (GOPIO_B.Add4[1] < GOPIO_P.Saturation2_LowerSat) {
    rtb_Product_n_idx_1 = GOPIO_P.Saturation2_LowerSat;
  } else {
    rtb_Product_n_idx_1 = GOPIO_B.Add4[1];
  }

  if (GOPIO_B.Add4[2] > GOPIO_P.Saturation2_UpperSat) {
    rtb_Product_n_idx_2 = GOPIO_P.Saturation2_UpperSat;
  } else if (GOPIO_B.Add4[2] < GOPIO_P.Saturation2_LowerSat) {
    rtb_Product_n_idx_2 = GOPIO_P.Saturation2_LowerSat;
  } else {
    rtb_Product_n_idx_2 = GOPIO_B.Add4[2];
  }

  /* End of Saturate: '<S1>/Saturation2' */

  /* Gain: '<S1>/Gain' incorporates:
   *  Sum: '<S1>/Sum'
   */
  GOPIO_B.sine_cosine_o2 = ((rtb_Product_n_idx_1 + rtb_Product_n_idx_2) +
    rtb_Product_n_idx_0) * GOPIO_P.Gain_Gain_d0;

  /* Switch: '<S1>/Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S1>/Constant'
   */
  if (GOPIO_P.Constant2_Value >= GOPIO_P.Switch_Threshold) {
    GOPIO_B.MtrElcPos = GOPIO_P.Constant2_Value;
  } else {
    GOPIO_B.MtrElcPos = GOPIO_P.Constant_Value;
  }

  /* End of Switch: '<S1>/Switch' */

  /* Product: '<S1>/Product' incorporates:
   *  Sum: '<S1>/Sum1'
   *  Sum: '<S1>/Sum2'
   *  Sum: '<S1>/Sum3'
   */
  rtb_Product_n_idx_0 = (rtb_Product_n_idx_0 - GOPIO_B.sine_cosine_o2) *
    GOPIO_B.MtrElcPos;
  rtb_Product_n_idx_1 = (rtb_Product_n_idx_1 - GOPIO_B.sine_cosine_o2) *
    GOPIO_B.MtrElcPos;
  rtb_Product_n_idx_2 = (rtb_Product_n_idx_2 - GOPIO_B.sine_cosine_o2) *
    GOPIO_B.MtrElcPos;

  /* DiscreteIntegrator: '<S222>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S222>/Constant'
   *  Constant: '<S222>/Constant1'
   *  MultiPortSwitch: '<S222>/Index Vector'
   */
  if (GOPIO_DW.DiscreteTimeIntegrator3_IC_LOAD != 0) {
    GOPIO_DW.DiscreteTimeIntegrator3_DSTATE = GOPIO_P.SurfaceMountPMSM_idq0
      [(int32_T)GOPIO_P.Constant1_Value_m - 1];
    if (GOPIO_DW.DiscreteTimeIntegrator3_DSTATE >
        GOPIO_P.DiscreteTimeIntegrator3_UpperSa) {
      GOPIO_DW.DiscreteTimeIntegrator3_DSTATE =
        GOPIO_P.DiscreteTimeIntegrator3_UpperSa;
    } else if (GOPIO_DW.DiscreteTimeIntegrator3_DSTATE <
               GOPIO_P.DiscreteTimeIntegrator3_LowerSa) {
      GOPIO_DW.DiscreteTimeIntegrator3_DSTATE =
        GOPIO_P.DiscreteTimeIntegrator3_LowerSa;
    }
  }

  /* Switch: '<S206>/Switch1' incorporates:
   *  Constant: '<S206>/Constant1'
   *  Constant: '<S208>/Constant'
   *  RelationalOperator: '<S208>/Compare'
   *  Sum: '<S206>/Add1'
   *  UnitDelay: '<S206>/Unit Delay'
   */
  if (GOPIO_DW.UnitDelay_DSTATE >= GOPIO_P.Int1_L) {
    /* Switch: '<S206>/Switch' incorporates:
     *  Constant: '<S206>/Constant3'
     *  Constant: '<S207>/Constant'
     *  RelationalOperator: '<S207>/Compare'
     *  Sum: '<S206>/Subtract'
     */
    if (GOPIO_DW.UnitDelay_DSTATE <= GOPIO_P.Int1_U) {
      GOPIO_B.MtrElcPos = GOPIO_DW.UnitDelay_DSTATE;
    } else {
      GOPIO_B.MtrElcPos = GOPIO_DW.UnitDelay_DSTATE - GOPIO_P.Constant3_Value_p;
    }

    /* End of Switch: '<S206>/Switch' */
  } else {
    GOPIO_B.MtrElcPos = GOPIO_DW.UnitDelay_DSTATE + GOPIO_P.Constant1_Value_fj;
  }

  /* End of Switch: '<S206>/Switch1' */

  /* Gain: '<S203>/Gain4' incorporates:
   *  Gain: '<S209>/polepair'
   */
  rtb_Gain4_tmp = GOPIO_P.SurfaceMountPMSM_P * GOPIO_B.MtrElcPos;

  /* Trigonometry: '<S205>/sine_cosine' incorporates:
   *  Gain: '<S203>/Gain4'
   */
  GOPIO_B.sine_cosine_o1 = sin(rtb_Gain4_tmp);
  GOPIO_B.sine_cosine_o2 = cos(rtb_Gain4_tmp);

  /* Sum: '<S214>/Add' incorporates:
   *  Gain: '<S214>/Gain'
   *  Gain: '<S214>/Gain1'
   *  Gain: '<S214>/Gain4'
   */
  rtb_Product_n_idx_0 = (GOPIO_P.Gain_Gain_g * rtb_Product_n_idx_0 +
    GOPIO_P.Gain1_Gain * rtb_Product_n_idx_1) + GOPIO_P.Gain4_Gain *
    rtb_Product_n_idx_2;

  /* Sum: '<S214>/Add1' incorporates:
   *  Gain: '<S214>/Gain2'
   *  Gain: '<S214>/Gain3'
   */
  rtb_Product_n_idx_1 = GOPIO_P.Gain2_Gain * rtb_Product_n_idx_1 +
    GOPIO_P.Gain3_Gain_m * rtb_Product_n_idx_2;

  /* DiscreteIntegrator: '<S221>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S221>/Constant'
   *  Constant: '<S221>/Constant1'
   *  MultiPortSwitch: '<S221>/Index Vector'
   */
  if (GOPIO_DW.DiscreteTimeIntegrator3_IC_LO_m != 0) {
    GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g = GOPIO_P.SurfaceMountPMSM_idq0
      [(int32_T)GOPIO_P.Constant1_Value_k - 1];
    if (GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g >
        GOPIO_P.DiscreteTimeIntegrator3_Upper_n) {
      GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g =
        GOPIO_P.DiscreteTimeIntegrator3_Upper_n;
    } else if (GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g <
               GOPIO_P.DiscreteTimeIntegrator3_Lower_o) {
      GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g =
        GOPIO_P.DiscreteTimeIntegrator3_Lower_o;
    }
  }

  /* DiscreteIntegrator: '<S203>/Discrete-Time Integrator' */
  GOPIO_B.DiscreteTimeIntegrator = GOPIO_DW.DiscreteTimeIntegrator_DSTATE;

  /* Gain: '<S203>/Gain' */
  rtb_Product_n_idx_2 = GOPIO_P.SurfaceMountPMSM_P *
    GOPIO_B.DiscreteTimeIntegrator;

  /* Product: '<S224>/Product' incorporates:
   *  Constant: '<S224>/Constant'
   *  Constant: '<S224>/Constant1'
   *  Constant: '<S224>/Constant2'
   *  DiscreteIntegrator: '<S222>/Discrete-Time Integrator3'
   *  MultiPortSwitch: '<S224>/Index Vector'
   *  MultiPortSwitch: '<S224>/Index Vector2'
   *  Product: '<S221>/Product'
   */
  rtb_Product_g = rtb_Product_n_idx_2 * GOPIO_DW.DiscreteTimeIntegrator3_DSTATE *
    GOPIO_P.Constant_Value_o[(int32_T)GOPIO_P.Constant1_Value_c - 1] /
    GOPIO_P.Constant_Value_o[(int32_T)GOPIO_P.Constant2_Value_f - 1];

  /* Gain: '<S217>/Gain2' incorporates:
   *  Constant: '<S220>/Constant'
   *  Constant: '<S220>/Constant1'
   *  Constant: '<S220>/Constant2'
   *  DiscreteIntegrator: '<S221>/Discrete-Time Integrator3'
   *  DiscreteIntegrator: '<S222>/Discrete-Time Integrator3'
   *  Gain: '<S217>/Gain1'
   *  MultiPortSwitch: '<S220>/Index Vector'
   *  MultiPortSwitch: '<S220>/Index Vector1'
   *  Product: '<S217>/Product'
   *  Product: '<S220>/Product'
   *  Sum: '<S217>/Add'
   *  Sum: '<S220>/Add'
   */
  rtb_Gain2 = ((GOPIO_P.Constant_Value_ht[(int32_T)GOPIO_P.Constant1_Value_km -
                1] - GOPIO_P.Constant_Value_ht[(int32_T)
                GOPIO_P.Constant2_Value_d - 1]) *
               (GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g *
                GOPIO_DW.DiscreteTimeIntegrator3_DSTATE) +
               GOPIO_P.SurfaceMountPMSM_lambda_pm_calc *
               GOPIO_DW.DiscreteTimeIntegrator3_DSTATE) * (1.5 *
    GOPIO_P.SurfaceMountPMSM_P);

  /* Sum: '<S206>/Add' incorporates:
   *  Gain: '<S206>/Gain1'
   *  UnitDelay: '<S206>/Unit Delay'
   */
  GOPIO_DW.UnitDelay_DSTATE = GOPIO_P.Int1_Ts * GOPIO_B.DiscreteTimeIntegrator +
    GOPIO_B.MtrElcPos;

  /* Sum: '<S216>/Add1' incorporates:
   *  DiscreteIntegrator: '<S221>/Discrete-Time Integrator3'
   *  DiscreteIntegrator: '<S222>/Discrete-Time Integrator3'
   *  Product: '<S216>/Product2'
   *  Product: '<S216>/Product3'
   */
  GOPIO_B.MtrElcPos = GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g *
    GOPIO_B.sine_cosine_o2 - GOPIO_DW.DiscreteTimeIntegrator3_DSTATE *
    GOPIO_B.sine_cosine_o1;

  /* SignalConversion generated from: '<S202>/Vector Concatenate' */
  GOPIO_B.VectorConcatenate[0] = GOPIO_B.MtrElcPos;

  /* Sum: '<S216>/Add' incorporates:
   *  DiscreteIntegrator: '<S221>/Discrete-Time Integrator3'
   *  DiscreteIntegrator: '<S222>/Discrete-Time Integrator3'
   *  Product: '<S216>/Product'
   *  Product: '<S216>/Product1'
   */
  GOPIO_B.Add_b = GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g *
    GOPIO_B.sine_cosine_o1 + GOPIO_DW.DiscreteTimeIntegrator3_DSTATE *
    GOPIO_B.sine_cosine_o2;

  /* Sum: '<S215>/Subtract2' incorporates:
   *  Gain: '<S215>/Gain1'
   *  Gain: '<S215>/Gain4'
   */
  GOPIO_B.VectorConcatenate[2] = GOPIO_P.Gain1_Gain_c * GOPIO_B.MtrElcPos +
    GOPIO_P.Gain4_Gain_f * GOPIO_B.Add_b;

  /* Sum: '<S215>/Subtract1' incorporates:
   *  Gain: '<S215>/Gain2'
   *  Gain: '<S215>/Gain3'
   */
  GOPIO_B.VectorConcatenate[1] = GOPIO_P.Gain2_Gain_o * GOPIO_B.MtrElcPos +
    GOPIO_P.Gain3_Gain_j * GOPIO_B.Add_b;

  /* Math: '<S209>/Mod' incorporates:
   *  Constant: '<S209>/Constant'
   */
  GOPIO_B.Mod = rt_modd_snf(rtb_Gain4_tmp, GOPIO_P.Constant_Value_k);

  /* MATLABSystem: '<S200>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  rtb_Gain4_tmp = rt_roundd_snf(GOPIO_P.Constant3_Value_m);
  if (rtb_Gain4_tmp < 4.294967296E+9) {
    if (rtb_Gain4_tmp >= 0.0) {
      freq = (uint32_T)rtb_Gain4_tmp;
    } else {
      freq = 0U;
    }
  } else {
    freq = MAX_uint32_T;
  }

  freq = checkFrequencyAndDutyCycleLimits(GOPIO_DW.obj_c.TimerHandle, freq);
  setFrequencyAccToInput(GOPIO_DW.obj_c.TimerHandle, freq);
  setDutyCycleInPercentageChannel1(GOPIO_DW.obj_c.TimerHandle, GOPIO_B.Add4[0]);
  setDutyCycleInPercentageChannel2(GOPIO_DW.obj_c.TimerHandle, GOPIO_B.Add4[1]);
  setDutyCycleInPercentageChannel3(GOPIO_DW.obj_c.TimerHandle, GOPIO_B.Add4[2]);

  /* End of MATLABSystem: '<S200>/PWM Output' */

  /* Update for DiscreteIntegrator: '<S222>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S226>/Constant'
   *  Constant: '<S226>/Constant1'
   *  Constant: '<S227>/Constant'
   *  Constant: '<S227>/Constant1'
   *  Constant: '<S227>/Constant2'
   *  Constant: '<S228>/Constant'
   *  Constant: '<S228>/Constant1'
   *  Constant: '<S228>/Constant2'
   *  Constant: '<S229>/Constant'
   *  Constant: '<S229>/Constant1'
   *  Constant: '<S229>/Constant2'
   *  DiscreteIntegrator: '<S221>/Discrete-Time Integrator3'
   *  MultiPortSwitch: '<S226>/Index Vector'
   *  MultiPortSwitch: '<S227>/Index Vector'
   *  MultiPortSwitch: '<S227>/Index Vector1'
   *  MultiPortSwitch: '<S228>/Index Vector'
   *  MultiPortSwitch: '<S229>/Index Vector'
   *  Product: '<S219>/Product'
   *  Product: '<S219>/Product1'
   *  Product: '<S222>/Product'
   *  Product: '<S226>/Product'
   *  Product: '<S227>/Product'
   *  Product: '<S228>/Product'
   *  Product: '<S229>/Product'
   *  Sum: '<S219>/Add'
   *  Sum: '<S222>/Add'
   */
  GOPIO_DW.DiscreteTimeIntegrator3_IC_LOAD = 0U;
  GOPIO_DW.DiscreteTimeIntegrator3_DSTATE += ((((rtb_Product_n_idx_1 *
    GOPIO_B.sine_cosine_o2 - rtb_Product_n_idx_0 * GOPIO_B.sine_cosine_o1) /
    GOPIO_P.Constant_Value_d[(int32_T)GOPIO_P.Constant1_Value_l - 1] -
    GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g * rtb_Product_n_idx_2 *
    GOPIO_P.Constant_Value_f[(int32_T)GOPIO_P.Constant1_Value_h0 - 1] /
    GOPIO_P.Constant_Value_f[(int32_T)GOPIO_P.Constant2_Value_e - 1]) -
    rtb_Product_n_idx_2 * GOPIO_P.SurfaceMountPMSM_lambda_pm_calc /
    GOPIO_P.Constant1_Value_a[(int32_T)GOPIO_P.Constant2_Value_l - 1]) -
    GOPIO_DW.DiscreteTimeIntegrator3_DSTATE * GOPIO_P.SurfaceMountPMSM_Rs /
    GOPIO_P.Constant1_Value_j[(int32_T)GOPIO_P.Constant2_Value_m - 1]) *
    GOPIO_P.DiscreteTimeIntegrator3_gainval;
  if (GOPIO_DW.DiscreteTimeIntegrator3_DSTATE >
      GOPIO_P.DiscreteTimeIntegrator3_UpperSa) {
    GOPIO_DW.DiscreteTimeIntegrator3_DSTATE =
      GOPIO_P.DiscreteTimeIntegrator3_UpperSa;
  } else if (GOPIO_DW.DiscreteTimeIntegrator3_DSTATE <
             GOPIO_P.DiscreteTimeIntegrator3_LowerSa) {
    GOPIO_DW.DiscreteTimeIntegrator3_DSTATE =
      GOPIO_P.DiscreteTimeIntegrator3_LowerSa;
  }

  /* End of Update for DiscreteIntegrator: '<S222>/Discrete-Time Integrator3' */

  /* Update for DiscreteIntegrator: '<S221>/Discrete-Time Integrator3' incorporates:
   *  Constant: '<S223>/Constant'
   *  Constant: '<S223>/Constant1'
   *  Constant: '<S225>/Constant'
   *  Constant: '<S225>/Constant1'
   *  Constant: '<S225>/Constant2'
   *  MultiPortSwitch: '<S223>/Index Vector'
   *  MultiPortSwitch: '<S225>/Index Vector'
   *  Product: '<S219>/Product2'
   *  Product: '<S219>/Product3'
   *  Product: '<S223>/Product'
   *  Product: '<S225>/Product'
   *  Sum: '<S219>/Add1'
   *  Sum: '<S221>/Add'
   */
  GOPIO_DW.DiscreteTimeIntegrator3_IC_LO_m = 0U;
  GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g += (((rtb_Product_n_idx_0 *
    GOPIO_B.sine_cosine_o2 + rtb_Product_n_idx_1 * GOPIO_B.sine_cosine_o1) /
    GOPIO_P.Constant_Value_e[(int32_T)GOPIO_P.Constant1_Value_f - 1] +
    rtb_Product_g) - GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g *
    GOPIO_P.SurfaceMountPMSM_Rs / GOPIO_P.Constant1_Value_e[(int32_T)
    GOPIO_P.Constant2_Value_p - 1]) * GOPIO_P.DiscreteTimeIntegrator3_gainv_h;
  if (GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g >
      GOPIO_P.DiscreteTimeIntegrator3_Upper_n) {
    GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g =
      GOPIO_P.DiscreteTimeIntegrator3_Upper_n;
  } else if (GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g <
             GOPIO_P.DiscreteTimeIntegrator3_Lower_o) {
    GOPIO_DW.DiscreteTimeIntegrator3_DSTAT_g =
      GOPIO_P.DiscreteTimeIntegrator3_Lower_o;
  }

  /* End of Update for DiscreteIntegrator: '<S221>/Discrete-Time Integrator3' */

  /* Signum: '<S203>/Sign' */
  if (rtIsNaN(GOPIO_B.DiscreteTimeIntegrator)) {
    rtb_Gain4_tmp = (rtNaN);
  } else if (GOPIO_B.DiscreteTimeIntegrator < 0.0) {
    rtb_Gain4_tmp = -1.0;
  } else {
    rtb_Gain4_tmp = (GOPIO_B.DiscreteTimeIntegrator > 0.0);
  }

  /* Update for DiscreteIntegrator: '<S203>/Discrete-Time Integrator' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<S203>/Constant'
   *  Constant: '<S203>/Constant1'
   *  Constant: '<S203>/Constant2'
   *  Constant: '<S203>/Constant3'
   *  Constant: '<S203>/Constant4'
   *  Constant: '<S203>/Constant5'
   *  MultiPortSwitch: '<S203>/Index Vector'
   *  MultiPortSwitch: '<S203>/Index Vector1'
   *  MultiPortSwitch: '<S203>/Index Vector2'
   *  Product: '<S203>/Divide'
   *  Product: '<S203>/Divide1'
   *  Product: '<S203>/Divide2'
   *  Signum: '<S203>/Sign'
   *  Sum: '<S203>/Sum1'
   */
  GOPIO_DW.DiscreteTimeIntegrator_DSTATE += (((rtb_Gain2 -
    GOPIO_P.Constant1_Value_la) - GOPIO_P.SurfaceMountPMSM_mechanical[(int32_T)
    GOPIO_P.Constant5_Value_l - 1] * GOPIO_B.DiscreteTimeIntegrator) -
    GOPIO_P.SurfaceMountPMSM_mechanical[(int32_T)GOPIO_P.Constant3_Value_e - 1] *
    rtb_Gain4_tmp) / GOPIO_P.SurfaceMountPMSM_mechanical[(int32_T)
    GOPIO_P.Constant1_Value_cb - 1] * GOPIO_P.DiscreteTimeIntegrator_gainval;
  if (GOPIO_DW.DiscreteTimeIntegrator_DSTATE >
      GOPIO_P.DiscreteTimeIntegrator_UpperSat) {
    GOPIO_DW.DiscreteTimeIntegrator_DSTATE =
      GOPIO_P.DiscreteTimeIntegrator_UpperSat;
  } else if (GOPIO_DW.DiscreteTimeIntegrator_DSTATE <
             GOPIO_P.DiscreteTimeIntegrator_LowerSat) {
    GOPIO_DW.DiscreteTimeIntegrator_DSTATE =
      GOPIO_P.DiscreteTimeIntegrator_LowerSat;
  }

  /* End of Update for DiscreteIntegrator: '<S203>/Discrete-Time Integrator' */

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  GOPIO_M->Timing.taskTime0 =
    ((time_T)(++GOPIO_M->Timing.clockTick0)) * GOPIO_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void GOPIO_step1(void)                 /* Sample time: [0.1s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T c;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (GOPIO_DW.clockTickCounter < GOPIO_P.PulseGenerator_Duty)
    && (GOPIO_DW.clockTickCounter >= 0) ? GOPIO_P.PulseGenerator_Amp : 0.0;
  if (GOPIO_DW.clockTickCounter >= GOPIO_P.PulseGenerator_Period - 1.0) {
    GOPIO_DW.clockTickCounter = 0;
  } else {
    GOPIO_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S8>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S8>/Digital Port Write' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  GOPIO_M->Timing.clockTick1++;
}

/* Model initialize function */
void GOPIO_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(GOPIO_M, 5.0);
  GOPIO_M->Timing.stepSize0 = 2.5E-5;

  /* External mode info */
  GOPIO_M->Sizes.checksums[0] = (3967061023U);
  GOPIO_M->Sizes.checksums[1] = (1401279590U);
  GOPIO_M->Sizes.checksums[2] = (603548607U);
  GOPIO_M->Sizes.checksums[3] = (846100475U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[27];
    GOPIO_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[5] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[6] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[7] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[8] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[9] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[10] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[11] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[12] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[13] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[14] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[15] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[16] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[17] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[18] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[19] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[20] = (sysRanDType *)&GOPIO_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&GOPIO_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[23] = &rtAlwaysEnabled;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    systemRan[26] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GOPIO_M->extModeInfo,
      &GOPIO_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GOPIO_M->extModeInfo, GOPIO_M->Sizes.checksums);
    rteiSetTPtr(GOPIO_M->extModeInfo, rtmGetTPtr(GOPIO_M));
  }

  /* InitializeConditions for DiscreteIntegrator: '<S222>/Discrete-Time Integrator3' */
  GOPIO_DW.DiscreteTimeIntegrator3_IC_LOAD = 1U;

  /* InitializeConditions for UnitDelay: '<S206>/Unit Delay' */
  GOPIO_DW.UnitDelay_DSTATE = GOPIO_P.SurfaceMountPMSM_theta_init;

  /* InitializeConditions for DiscreteIntegrator: '<S221>/Discrete-Time Integrator3' */
  GOPIO_DW.DiscreteTimeIntegrator3_IC_LO_m = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S203>/Discrete-Time Integrator' */
  GOPIO_DW.DiscreteTimeIntegrator_DSTATE = GOPIO_P.SurfaceMountPMSM_omega_init;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S198>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  GOPIO_M->Timing.clockTick2 = GOPIO_M->Timing.clockTick0;

  /* InitializeConditions for DiscreteIntegrator: '<S166>/Integrator' */
  GOPIO_DW.Integrator_DSTATE = GOPIO_P.PIController2_InitialConditionF;

  /* InitializeConditions for DiscreteIntegrator: '<S114>/Integrator' */
  GOPIO_DW.Integrator_DSTATE_e = GOPIO_P.PIController1_InitialConditionF;

  /* InitializeConditions for DiscreteIntegrator: '<S62>/Integrator' */
  GOPIO_DW.Integrator_DSTATE_j = GOPIO_P.PIController_InitialConditionFo;

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  GOPIO_DW.obj.isInitialized = 0;
  GOPIO_DW.obj.matlabCodegenIsDeleted = false;
  GOPIO_SystemCore_setup(&GOPIO_DW.obj);

  /* SystemInitialize for Sum: '<S11>/Add4' incorporates:
   *  Outport: '<S3>/PWM'
   */
  GOPIO_B.Add4[0] = GOPIO_P.PWM_Y0;
  GOPIO_B.Add4[1] = GOPIO_P.PWM_Y0;
  GOPIO_B.Add4[2] = GOPIO_P.PWM_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S198>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S200>/PWM Output' */
  GOPIO_DW.obj_c.matlabCodegenIsDeleted = false;
  GOPIO_DW.obj_c.isSetupComplete = false;
  GOPIO_DW.obj_c.isInitialized = 1;
  GOPIO_PWMOutput_setupImpl(&GOPIO_DW.obj_c);
  GOPIO_DW.obj_c.isSetupComplete = true;
}

/* Model terminate function */
void GOPIO_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S198>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S198>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  if (!GOPIO_DW.obj.matlabCodegenIsDeleted) {
    GOPIO_DW.obj.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj.isInitialized == 1) && GOPIO_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(GOPIO_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S198>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S200>/PWM Output' */
  if (!GOPIO_DW.obj_c.matlabCodegenIsDeleted) {
    GOPIO_DW.obj_c.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj_c.isInitialized == 1) && GOPIO_DW.obj_c.isSetupComplete) {
      disableCounter(GOPIO_DW.obj_c.TimerHandle);
      disableTimerInterrupts(GOPIO_DW.obj_c.TimerHandle, 0);
      disableTimerChannel1(GOPIO_DW.obj_c.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(GOPIO_DW.obj_c.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(GOPIO_DW.obj_c.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S200>/PWM Output' */
}

void GOPIO_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S198>/Hardware Interrupt' */
void ADC_IRQHandler(void)
{
  /* Event: ADC1 Inj EoCS */
  /* Check event ADC1 Inj EoCS occurred */
  if (0 != (
#if defined(MW_ADC1_ENABLED) && (defined(MW_ADC1_INJ_IRQ_ENABLED) && (MW_ADC1_INJ_IRQ_ENABLED==1))
            (0 != LL_ADC_IsEnabledIT_JEOS(ADC1)) && (0 != ADC_IsActiveFlagJEOS
        (&(MW_ADC1_VAR)))
#else
            (0 != LL_ADC_IsEnabledIT_JEOS(ADC1)) && (0 !=
        LL_ADC_IsActiveFlag_JEOS(ADC1))
#endif
            )) {
    /* Clear occurred ADC1 Inj EoCS event */
    LL_ADC_ClearFlag_JEOS(ADC1);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(GOPIO_DW.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(GOPIO_DW.IfActionSubsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(GOPIO_DW.FunctionCallSubsystem_SubsysRan);

        /* S-Function (HardwareInterrupt_sfun): '<S198>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          real_T rtb_Kalphabeta0_idx_0;
          real_T rtb_Kalphabeta0_idx_1;
          real_T rtb_Saturation_m;
          real_T rtb_Sum4;
          real_T rtb_Sum6;
          real_T rtb_Switch_n_idx_0;
          real_T rtb_Switch_n_idx_1;
          uint16_T tmp[2];
          uint16_T rtb_Get_Integer;
          int8_T tmp_e;
          int8_T tmp_p;
          GOPIO_M->Timing.clockTick2 = GOPIO_M->Timing.clockTick0;

          /* MATLABSystem: '<S13>/Analog to Digital Converter' */
          injectedReadADCIntr(GOPIO_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* Sum: '<S11>/Add3' incorporates:
           *  Constant: '<S3>/Constant'
           */
          GOPIO_B.IProdOut = GOPIO_P.Constant_Value_l -
            GOPIO_B.DiscreteTimeIntegrator;

          /* Sum: '<S175>/Sum' incorporates:
           *  Constant: '<S11>/Constant1'
           *  DiscreteIntegrator: '<S166>/Integrator'
           *  Product: '<S171>/PProd Out'
           */
          GOPIO_B.DeadZone = GOPIO_B.IProdOut * GOPIO_P.Constant1_Value_d +
            GOPIO_DW.Integrator_DSTATE;

          /* Gain: '<S24>/Kalphabeta0' incorporates:
           *  Gain: '<S24>/one_by_3'
           *  Gain: '<S24>/one_by_sqrt3_'
           *  Sum: '<S24>/Sum'
           *  Sum: '<S24>/Sum1'
           *  Sum: '<S24>/Sum2'
           */
          rtb_Kalphabeta0_idx_0 = (GOPIO_B.VectorConcatenate[0] -
            ((GOPIO_B.VectorConcatenate[0] + GOPIO_B.VectorConcatenate[1]) +
             GOPIO_B.VectorConcatenate[2]) * GOPIO_P.one_by_3_Gain) *
            GOPIO_P.Kalphabeta0_Gain[0];
          rtb_Kalphabeta0_idx_1 = (GOPIO_B.VectorConcatenate[1] -
            GOPIO_B.VectorConcatenate[2]) * GOPIO_P.one_by_sqrt3_Gain *
            GOPIO_P.Kalphabeta0_Gain[1];

          /* Gain: '<S193>/convert_pu' incorporates:
           *  Constant: '<S11>/Constant6'
           *  Sum: '<S11>/Add'
           */
          GOPIO_B.convert_pu = (GOPIO_B.Mod - GOPIO_P.Constant6_Value) *
            GOPIO_P.convert_pu_Gain;

          /* If: '<S193>/If' incorporates:
           *  Constant: '<S194>/Constant'
           *  RelationalOperator: '<S194>/Compare'
           */
          if (GOPIO_B.convert_pu < GOPIO_P.Constant_Value_h) {
            /* Outputs for IfAction SubSystem: '<S193>/If Action Subsystem' incorporates:
             *  ActionPort: '<S195>/Action Port'
             */
            /* DataTypeConversion: '<S195>/Convert_uint16' */
            GOPIO_B.DeadZone_d = floor(GOPIO_B.convert_pu);
            if (rtIsInf(GOPIO_B.DeadZone_d)) {
              GOPIO_B.DeadZone_d = 0.0;
            } else {
              GOPIO_B.DeadZone_d = fmod(GOPIO_B.DeadZone_d, 65536.0);
            }

            /* Sum: '<S195>/Sum' incorporates:
             *  DataTypeConversion: '<S195>/Convert_back'
             *  DataTypeConversion: '<S195>/Convert_uint16'
             */
            GOPIO_B.convert_pu -= (real_T)(GOPIO_B.DeadZone_d < 0.0 ? (int32_T)
              (int16_T)-(int16_T)(uint16_T)-GOPIO_B.DeadZone_d : (int32_T)
              (int16_T)(uint16_T)GOPIO_B.DeadZone_d);

            /* End of Outputs for SubSystem: '<S193>/If Action Subsystem' */

            /* Update for IfAction SubSystem: '<S193>/If Action Subsystem' incorporates:
             *  ActionPort: '<S195>/Action Port'
             */
            /* Update for If: '<S193>/If' */
            GOPIO_DW.IfActionSubsystem_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S193>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S193>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S196>/Action Port'
             */
            /* DataTypeConversion: '<S196>/Convert_uint16' */
            GOPIO_B.DeadZone_d = trunc(GOPIO_B.convert_pu);
            if (rtIsNaN(GOPIO_B.DeadZone_d) || rtIsInf(GOPIO_B.DeadZone_d)) {
              GOPIO_B.DeadZone_d = 0.0;
            } else {
              GOPIO_B.DeadZone_d = fmod(GOPIO_B.DeadZone_d, 65536.0);
            }

            /* Sum: '<S196>/Sum' incorporates:
             *  DataTypeConversion: '<S196>/Convert_back'
             *  DataTypeConversion: '<S196>/Convert_uint16'
             */
            GOPIO_B.convert_pu -= (real_T)(GOPIO_B.DeadZone_d < 0.0 ? (int32_T)
              (int16_T)-(int16_T)(uint16_T)-GOPIO_B.DeadZone_d : (int32_T)
              (int16_T)(uint16_T)GOPIO_B.DeadZone_d);

            /* End of Outputs for SubSystem: '<S193>/If Action Subsystem1' */

            /* Update for IfAction SubSystem: '<S193>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S196>/Action Port'
             */
            /* Update for If: '<S193>/If' */
            GOPIO_DW.IfActionSubsystem1_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S193>/If Action Subsystem1' */
          }

          /* End of If: '<S193>/If' */

          /* Gain: '<S23>/indexing' */
          GOPIO_B.convert_pu *= GOPIO_P.indexing_Gain;

          /* DataTypeConversion: '<S23>/Get_Integer' */
          GOPIO_B.DeadZone_d = trunc(GOPIO_B.convert_pu);
          if (rtIsNaN(GOPIO_B.DeadZone_d) || rtIsInf(GOPIO_B.DeadZone_d)) {
            GOPIO_B.DeadZone_d = 0.0;
          } else {
            GOPIO_B.DeadZone_d = fmod(GOPIO_B.DeadZone_d, 65536.0);
          }

          rtb_Get_Integer = (uint16_T)(GOPIO_B.DeadZone_d < 0.0 ? (int32_T)
            (uint16_T)-(int16_T)(uint16_T)-GOPIO_B.DeadZone_d : (int32_T)
            (uint16_T)GOPIO_B.DeadZone_d);

          /* End of DataTypeConversion: '<S23>/Get_Integer' */

          /* Sum: '<S23>/Sum2' incorporates:
           *  DataTypeConversion: '<S23>/Data Type Conversion1'
           */
          GOPIO_B.DeadZone_d = GOPIO_B.convert_pu - (real_T)rtb_Get_Integer;

          /* Selector: '<S23>/Lookup' incorporates:
           *  Constant: '<S23>/offset'
           *  Constant: '<S23>/sine_table_values'
           *  Sum: '<S192>/Sum3'
           *  Sum: '<S23>/Sum'
           */
          GOPIO_B.convert_pu = GOPIO_P.sine_table_values_Value[(int32_T)
            ((uint32_T)GOPIO_P.offset_Value[1] + rtb_Get_Integer)];

          /* Sum: '<S192>/Sum4' incorporates:
           *  Constant: '<S23>/offset'
           *  Constant: '<S23>/sine_table_values'
           *  Product: '<S192>/Product'
           *  Selector: '<S23>/Lookup'
           *  Sum: '<S192>/Sum3'
           *  Sum: '<S23>/Sum'
           */
          rtb_Sum4 = (GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
            GOPIO_P.offset_Value[0] + rtb_Get_Integer)] - GOPIO_B.convert_pu) *
            GOPIO_B.DeadZone_d + GOPIO_B.convert_pu;

          /* Selector: '<S23>/Lookup' incorporates:
           *  Constant: '<S23>/offset'
           *  Constant: '<S23>/sine_table_values'
           *  Sum: '<S192>/Sum5'
           *  Sum: '<S23>/Sum'
           */
          GOPIO_B.convert_pu = GOPIO_P.sine_table_values_Value[(int32_T)
            ((uint32_T)GOPIO_P.offset_Value[3] + rtb_Get_Integer)];

          /* Sum: '<S192>/Sum6' incorporates:
           *  Constant: '<S23>/offset'
           *  Constant: '<S23>/sine_table_values'
           *  Product: '<S192>/Product1'
           *  Selector: '<S23>/Lookup'
           *  Sum: '<S192>/Sum5'
           *  Sum: '<S23>/Sum'
           */
          rtb_Sum6 = (GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
            GOPIO_P.offset_Value[2] + rtb_Get_Integer)] - GOPIO_B.convert_pu) *
            GOPIO_B.DeadZone_d + GOPIO_B.convert_pu;

          /* Outputs for Atomic SubSystem: '<S22>/Two inputs CRL' */
          /* Switch: '<S191>/Switch' incorporates:
           *  Constant: '<S191>/Offset'
           *  Product: '<S190>/acos'
           *  Product: '<S190>/asin'
           *  Product: '<S190>/bcos'
           *  Product: '<S190>/bsin'
           *  Sum: '<S190>/sum_Ds'
           *  Sum: '<S190>/sum_Qs'
           *  UnaryMinus: '<S191>/Unary_Minus'
           */
          if (GOPIO_P.Offset_Value_h > GOPIO_P.Switch_Threshold_l) {
            rtb_Switch_n_idx_0 = -(rtb_Kalphabeta0_idx_1 * rtb_Sum6 -
              rtb_Kalphabeta0_idx_0 * rtb_Sum4);
            rtb_Switch_n_idx_1 = rtb_Kalphabeta0_idx_0 * rtb_Sum6 +
              rtb_Kalphabeta0_idx_1 * rtb_Sum4;
          } else {
            rtb_Switch_n_idx_0 = rtb_Kalphabeta0_idx_0 * rtb_Sum6 +
              rtb_Kalphabeta0_idx_1 * rtb_Sum4;
            rtb_Switch_n_idx_1 = rtb_Kalphabeta0_idx_1 * rtb_Sum6 -
              rtb_Kalphabeta0_idx_0 * rtb_Sum4;
          }

          /* End of Switch: '<S191>/Switch' */
          /* End of Outputs for SubSystem: '<S22>/Two inputs CRL' */

          /* Saturate: '<S173>/Saturation' */
          if (GOPIO_B.DeadZone > GOPIO_P.PIController2_UpperSaturationLi) {
            GOPIO_B.DeadZone_d = GOPIO_P.PIController2_UpperSaturationLi;
          } else if (GOPIO_B.DeadZone < GOPIO_P.PIController2_LowerSaturationLi)
          {
            GOPIO_B.DeadZone_d = GOPIO_P.PIController2_LowerSaturationLi;
          } else {
            GOPIO_B.DeadZone_d = GOPIO_B.DeadZone;
          }

          /* Outputs for Atomic SubSystem: '<S22>/Two inputs CRL' */
          /* Sum: '<S11>/Add1' incorporates:
           *  AlgorithmDescriptorDelegate generated from: '<S190>/a16'
           *  Saturate: '<S173>/Saturation'
           */
          rtb_Kalphabeta0_idx_0 = GOPIO_B.DeadZone_d - rtb_Switch_n_idx_1;

          /* Sum: '<S11>/Add2' incorporates:
           *  AlgorithmDescriptorDelegate generated from: '<S190>/a16'
           *  Constant: '<S11>/Constant5'
           */
          GOPIO_B.convert_pu = GOPIO_P.Constant5_Value - rtb_Switch_n_idx_0;

          /* End of Outputs for SubSystem: '<S22>/Two inputs CRL' */

          /* Sum: '<S123>/Sum' incorporates:
           *  Constant: '<S11>/Constant7'
           *  DiscreteIntegrator: '<S114>/Integrator'
           *  Product: '<S119>/PProd Out'
           */
          GOPIO_B.DeadZone_d = GOPIO_B.convert_pu * GOPIO_P.Constant7_Value +
            GOPIO_DW.Integrator_DSTATE_e;

          /* Saturate: '<S121>/Saturation' */
          if (GOPIO_B.DeadZone_d > GOPIO_P.PIController1_UpperSaturationLi) {
            rtb_Switch_n_idx_1 = GOPIO_P.PIController1_UpperSaturationLi;
          } else if (GOPIO_B.DeadZone_d <
                     GOPIO_P.PIController1_LowerSaturationLi) {
            rtb_Switch_n_idx_1 = GOPIO_P.PIController1_LowerSaturationLi;
          } else {
            rtb_Switch_n_idx_1 = GOPIO_B.DeadZone_d;
          }

          /* End of Saturate: '<S121>/Saturation' */

          /* Sum: '<S71>/Sum' incorporates:
           *  Constant: '<S11>/Constant7'
           *  DiscreteIntegrator: '<S62>/Integrator'
           *  Product: '<S67>/PProd Out'
           */
          rtb_Kalphabeta0_idx_1 = rtb_Kalphabeta0_idx_0 *
            GOPIO_P.Constant7_Value + GOPIO_DW.Integrator_DSTATE_j;

          /* Saturate: '<S69>/Saturation' */
          if (rtb_Kalphabeta0_idx_1 > GOPIO_P.PIController_UpperSaturationLim) {
            rtb_Saturation_m = GOPIO_P.PIController_UpperSaturationLim;
          } else if (rtb_Kalphabeta0_idx_1 <
                     GOPIO_P.PIController_LowerSaturationLim) {
            rtb_Saturation_m = GOPIO_P.PIController_LowerSaturationLim;
          } else {
            rtb_Saturation_m = rtb_Kalphabeta0_idx_1;
          }

          /* End of Saturate: '<S69>/Saturation' */

          /* Outputs for Atomic SubSystem: '<S17>/Two inputs CRL' */
          /* Switch: '<S26>/Switch' incorporates:
           *  Constant: '<S26>/Offset'
           *  Product: '<S25>/dcos'
           *  Product: '<S25>/dsin'
           *  Product: '<S25>/qcos'
           *  Product: '<S25>/qsin'
           *  Sum: '<S25>/sum_alpha'
           *  Sum: '<S25>/sum_beta'
           *  UnaryMinus: '<S26>/Unary_Minus'
           */
          if (GOPIO_P.Offset_Value > GOPIO_P.Switch_Threshold_d) {
            rtb_Switch_n_idx_0 = rtb_Saturation_m * rtb_Sum6 +
              rtb_Switch_n_idx_1 * rtb_Sum4;
            rtb_Switch_n_idx_1 = -(rtb_Switch_n_idx_1 * rtb_Sum6 -
              rtb_Saturation_m * rtb_Sum4);
          } else {
            rtb_Switch_n_idx_0 = rtb_Switch_n_idx_1 * rtb_Sum6 -
              rtb_Saturation_m * rtb_Sum4;
            rtb_Switch_n_idx_1 = rtb_Saturation_m * rtb_Sum6 +
              rtb_Switch_n_idx_1 * rtb_Sum4;
          }

          /* End of Switch: '<S26>/Switch' */

          /* Gain: '<S189>/Ka' incorporates:
           *  AlgorithmDescriptorDelegate generated from: '<S25>/a16'
           */
          rtb_Sum4 = GOPIO_P.Ka_Gain * rtb_Switch_n_idx_0;

          /* Gain: '<S189>/one_by_two' incorporates:
           *  AlgorithmDescriptorDelegate generated from: '<S25>/a16'
           */
          rtb_Switch_n_idx_0 *= GOPIO_P.one_by_two_Gain;

          /* Gain: '<S189>/sqrt3_by_two' incorporates:
           *  AlgorithmDescriptorDelegate generated from: '<S25>/a16'
           */
          rtb_Sum6 = GOPIO_P.sqrt3_by_two_Gain * rtb_Switch_n_idx_1;

          /* End of Outputs for SubSystem: '<S17>/Two inputs CRL' */

          /* Gain: '<S189>/Kb' incorporates:
           *  Sum: '<S189>/add_b'
           */
          rtb_Switch_n_idx_1 = (rtb_Sum6 - rtb_Switch_n_idx_0) * GOPIO_P.Kb_Gain;

          /* Gain: '<S189>/Kc' incorporates:
           *  Sum: '<S189>/add_c'
           */
          rtb_Sum6 = ((0.0 - rtb_Switch_n_idx_0) - rtb_Sum6) * GOPIO_P.Kc_Gain;

          /* Gain: '<S186>/one_by_two' incorporates:
           *  MinMax: '<S186>/Max'
           *  MinMax: '<S186>/Min'
           *  Sum: '<S186>/Add'
           */
          rtb_Switch_n_idx_0 = (fmax(fmax(rtb_Sum4, rtb_Switch_n_idx_1),
            rtb_Sum6) + fmin(fmin(rtb_Sum4, rtb_Switch_n_idx_1), rtb_Sum6)) *
            GOPIO_P.one_by_two_Gain_h;

          /* Sum: '<S11>/Add4' incorporates:
           *  Constant: '<S11>/Constant9'
           *  Gain: '<S11>/Gain'
           *  Gain: '<S11>/Gain3'
           *  Gain: '<S185>/Gain'
           *  Sum: '<S185>/Add1'
           *  Sum: '<S185>/Add2'
           *  Sum: '<S185>/Add3'
           */
          GOPIO_B.Add4[0] = (rtb_Sum4 + rtb_Switch_n_idx_0) * GOPIO_P.Gain_Gain *
            GOPIO_P.Gain_Gain_d * GOPIO_P.Gain3_Gain + GOPIO_P.Constant9_Value;
          GOPIO_B.Add4[1] = (rtb_Switch_n_idx_1 + rtb_Switch_n_idx_0) *
            GOPIO_P.Gain_Gain * GOPIO_P.Gain_Gain_d * GOPIO_P.Gain3_Gain +
            GOPIO_P.Constant9_Value;
          GOPIO_B.Add4[2] = (rtb_Switch_n_idx_0 + rtb_Sum6) * GOPIO_P.Gain_Gain *
            GOPIO_P.Gain_Gain_d * GOPIO_P.Gain3_Gain + GOPIO_P.Constant9_Value;

          /* DeadZone: '<S54>/DeadZone' */
          if (rtb_Kalphabeta0_idx_1 > GOPIO_P.PIController_UpperSaturationLim) {
            rtb_Kalphabeta0_idx_1 -= GOPIO_P.PIController_UpperSaturationLim;
          } else if (rtb_Kalphabeta0_idx_1 >=
                     GOPIO_P.PIController_LowerSaturationLim) {
            rtb_Kalphabeta0_idx_1 = 0.0;
          } else {
            rtb_Kalphabeta0_idx_1 -= GOPIO_P.PIController_LowerSaturationLim;
          }

          /* End of DeadZone: '<S54>/DeadZone' */

          /* Product: '<S59>/IProd Out' incorporates:
           *  Constant: '<S11>/Constant8'
           */
          rtb_Kalphabeta0_idx_0 *= GOPIO_P.Constant8_Value;

          /* DeadZone: '<S106>/DeadZone' */
          if (GOPIO_B.DeadZone_d > GOPIO_P.PIController1_UpperSaturationLi) {
            GOPIO_B.DeadZone_d -= GOPIO_P.PIController1_UpperSaturationLi;
          } else if (GOPIO_B.DeadZone_d >=
                     GOPIO_P.PIController1_LowerSaturationLi) {
            GOPIO_B.DeadZone_d = 0.0;
          } else {
            GOPIO_B.DeadZone_d -= GOPIO_P.PIController1_LowerSaturationLi;
          }

          /* End of DeadZone: '<S106>/DeadZone' */

          /* Product: '<S111>/IProd Out' incorporates:
           *  Constant: '<S11>/Constant8'
           */
          GOPIO_B.convert_pu *= GOPIO_P.Constant8_Value;

          /* DeadZone: '<S158>/DeadZone' */
          if (GOPIO_B.DeadZone > GOPIO_P.PIController2_UpperSaturationLi) {
            GOPIO_B.DeadZone -= GOPIO_P.PIController2_UpperSaturationLi;
          } else if (GOPIO_B.DeadZone >= GOPIO_P.PIController2_LowerSaturationLi)
          {
            GOPIO_B.DeadZone = 0.0;
          } else {
            GOPIO_B.DeadZone -= GOPIO_P.PIController2_LowerSaturationLi;
          }

          /* End of DeadZone: '<S158>/DeadZone' */

          /* Product: '<S163>/IProd Out' incorporates:
           *  Constant: '<S11>/Constant3'
           */
          GOPIO_B.IProdOut *= GOPIO_P.Constant3_Value;

          /* Switch: '<S156>/Switch1' incorporates:
           *  Constant: '<S156>/Clamping_zero'
           *  Constant: '<S156>/Constant'
           *  Constant: '<S156>/Constant2'
           *  RelationalOperator: '<S156>/fix for DT propagation issue'
           */
          if (GOPIO_B.DeadZone > GOPIO_P.Clamping_zero_Value_bd) {
            tmp_p = GOPIO_P.Constant_Value_j;
          } else {
            tmp_p = GOPIO_P.Constant2_Value_b;
          }

          /* Switch: '<S156>/Switch2' incorporates:
           *  Constant: '<S156>/Clamping_zero'
           *  Constant: '<S156>/Constant3'
           *  Constant: '<S156>/Constant4'
           *  RelationalOperator: '<S156>/fix for DT propagation issue1'
           */
          if (GOPIO_B.IProdOut > GOPIO_P.Clamping_zero_Value_bd) {
            tmp_e = GOPIO_P.Constant3_Value_l;
          } else {
            tmp_e = GOPIO_P.Constant4_Value_o;
          }

          /* Switch: '<S156>/Switch' incorporates:
           *  Constant: '<S156>/Clamping_zero'
           *  Constant: '<S156>/Constant1'
           *  Logic: '<S156>/AND3'
           *  RelationalOperator: '<S156>/Equal1'
           *  RelationalOperator: '<S156>/Relational Operator'
           *  Switch: '<S156>/Switch1'
           *  Switch: '<S156>/Switch2'
           */
          if ((GOPIO_P.Clamping_zero_Value_bd != GOPIO_B.DeadZone) && (tmp_p ==
               tmp_e)) {
            GOPIO_B.IProdOut = GOPIO_P.Constant1_Value_h;
          }

          /* Update for DiscreteIntegrator: '<S166>/Integrator' incorporates:
           *  Switch: '<S156>/Switch'
           */
          GOPIO_DW.Integrator_DSTATE += GOPIO_P.Integrator_gainval *
            GOPIO_B.IProdOut;

          /* Switch: '<S104>/Switch1' incorporates:
           *  Constant: '<S104>/Clamping_zero'
           *  Constant: '<S104>/Constant'
           *  Constant: '<S104>/Constant2'
           *  RelationalOperator: '<S104>/fix for DT propagation issue'
           */
          if (GOPIO_B.DeadZone_d > GOPIO_P.Clamping_zero_Value_b) {
            tmp_p = GOPIO_P.Constant_Value_a;
          } else {
            tmp_p = GOPIO_P.Constant2_Value_j;
          }

          /* Switch: '<S104>/Switch2' incorporates:
           *  Constant: '<S104>/Clamping_zero'
           *  Constant: '<S104>/Constant3'
           *  Constant: '<S104>/Constant4'
           *  RelationalOperator: '<S104>/fix for DT propagation issue1'
           */
          if (GOPIO_B.convert_pu > GOPIO_P.Clamping_zero_Value_b) {
            tmp_e = GOPIO_P.Constant3_Value_d5;
          } else {
            tmp_e = GOPIO_P.Constant4_Value_g;
          }

          /* Switch: '<S104>/Switch' incorporates:
           *  Constant: '<S104>/Clamping_zero'
           *  Constant: '<S104>/Constant1'
           *  Logic: '<S104>/AND3'
           *  RelationalOperator: '<S104>/Equal1'
           *  RelationalOperator: '<S104>/Relational Operator'
           *  Switch: '<S104>/Switch1'
           *  Switch: '<S104>/Switch2'
           */
          if ((GOPIO_P.Clamping_zero_Value_b != GOPIO_B.DeadZone_d) && (tmp_p ==
               tmp_e)) {
            GOPIO_B.convert_pu = GOPIO_P.Constant1_Value_p;
          }

          /* Update for DiscreteIntegrator: '<S114>/Integrator' incorporates:
           *  Switch: '<S104>/Switch'
           */
          GOPIO_DW.Integrator_DSTATE_e += GOPIO_P.Integrator_gainval_e *
            GOPIO_B.convert_pu;

          /* Switch: '<S52>/Switch1' incorporates:
           *  Constant: '<S52>/Clamping_zero'
           *  Constant: '<S52>/Constant'
           *  Constant: '<S52>/Constant2'
           *  RelationalOperator: '<S52>/fix for DT propagation issue'
           */
          if (rtb_Kalphabeta0_idx_1 > GOPIO_P.Clamping_zero_Value) {
            tmp_p = GOPIO_P.Constant_Value_la;
          } else {
            tmp_p = GOPIO_P.Constant2_Value_mk;
          }

          /* Switch: '<S52>/Switch2' incorporates:
           *  Constant: '<S52>/Clamping_zero'
           *  Constant: '<S52>/Constant3'
           *  Constant: '<S52>/Constant4'
           *  RelationalOperator: '<S52>/fix for DT propagation issue1'
           */
          if (rtb_Kalphabeta0_idx_0 > GOPIO_P.Clamping_zero_Value) {
            tmp_e = GOPIO_P.Constant3_Value_d;
          } else {
            tmp_e = GOPIO_P.Constant4_Value;
          }

          /* Switch: '<S52>/Switch' incorporates:
           *  Constant: '<S52>/Clamping_zero'
           *  Constant: '<S52>/Constant1'
           *  Logic: '<S52>/AND3'
           *  RelationalOperator: '<S52>/Equal1'
           *  RelationalOperator: '<S52>/Relational Operator'
           *  Switch: '<S52>/Switch1'
           *  Switch: '<S52>/Switch2'
           */
          if ((GOPIO_P.Clamping_zero_Value != rtb_Kalphabeta0_idx_1) && (tmp_p ==
               tmp_e)) {
            rtb_Kalphabeta0_idx_0 = GOPIO_P.Constant1_Value;
          }

          /* Update for DiscreteIntegrator: '<S62>/Integrator' incorporates:
           *  Switch: '<S52>/Switch'
           */
          GOPIO_DW.Integrator_DSTATE_j += GOPIO_P.Integrator_gainval_p *
            rtb_Kalphabeta0_idx_0;
          GOPIO_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S198>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((GOPIO_M->Timing.clockTick2) *
        2.5E-5);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
}

void GOPIO_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
