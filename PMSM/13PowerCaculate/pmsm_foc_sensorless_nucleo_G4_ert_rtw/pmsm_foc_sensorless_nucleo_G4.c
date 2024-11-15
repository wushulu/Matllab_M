/*
 * File: pmsm_foc_sensorless_nucleo_G4.c
 *
 * Code generated for Simulink model 'pmsm_foc_sensorless_nucleo_G4'.
 *
 * Model version                  : 8.14
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Nov 15 15:18:01 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pmsm_foc_sensorless_nucleo_G4.h"
#include "pmsm_foc_sensorless_nucleo_G4_types.h"
#include "pmsm_foc_sensorless_nucleo_G4_private.h"
#include "rtwtypes.h"
#include "arm_math.h"
#include <math.h>
#include "mw_cmsis.h"
#include "rt_nonfinite.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "zero_crossing_types.h"
#include <string.h>
#include "rt_defines.h"

/* Block signals (default storage) */
BlockIO_pmsm_foc_sensorless_nuc pmsm_foc_sensorless_nucleo_G4_B;

/* Block states (default storage) */
D_Work_pmsm_foc_sensorless_nucl pmsm_foc_sensorless_nucle_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_pmsm_foc_sensor pmsm_foc_sensorl_PrevZCSigState;

/* Real-time model */
static RT_MODEL_pmsm_foc_sensorless_nu pmsm_foc_sensorless_nucleo_G_M_;
RT_MODEL_pmsm_foc_sensorless_nu *const pmsm_foc_sensorless_nucleo_G_M =
  &pmsm_foc_sensorless_nucleo_G_M_;

/* Forward declaration for local functions */
static void pmsm_foc_senso_SystemCore_setup(stm32cube_blocks_AnalogInput_pm *obj);
static void pmsm_foc_se_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_pmsm *obj);

/* Forward declaration for local functions */
static void pmsm_foc_se_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_pmsm *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void pmsm_foc_sensorless_nucleo_G4_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(pmsm_foc_sensorless_nucleo_G_M, 1));
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
  (pmsm_foc_sensorless_nucleo_G_M->Timing.TaskCounters.TID[1])++;
  if ((pmsm_foc_sensorless_nucleo_G_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    pmsm_foc_sensorless_nucleo_G_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void pmsm_foc_senso_SystemCore_setup(stm32cube_blocks_AnalogInput_pm *obj)
{
  void * internalBufferPtr;
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S20>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  internalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S20>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.InternalBufferPtr = internalBufferPtr;

  /* Start for MATLABSystem: '<S20>/Analog to Digital Converter' */
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 2U;
  adcStructLoc.InjectedNoOfConversion = 2U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS);
  enableADCAutomaticCalibrationOffset(obj->ADCHandle, 2);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

static void pmsm_foc_se_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_pmsm *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S213>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S213>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S213>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_p;
    if (u1 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0F) {
      tmp_p = 1;
    } else {
      tmp_p = -1;
    }

    y = atan2f((real32_T)tmp_p, (real32_T)tmp);
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = atan2f(u0, u1);
  }

  return y;
}

static void pmsm_foc_se_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_pmsm *obj)
{
  uint8_T * txBufferPtr;
  UART_Type_T b;
  txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);

  /* Start for MATLABSystem: '<S220>/UART//USART Write' incorporates:
   *  MATLABSystem: '<S219>/UART//USART Write'
   */
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = LPUART1;
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  b.buffer.txBufferPtr = txBufferPtr;
  obj->UARTHandle = MW_LPUART_Initialize(&b);
}

/* Model step function for TID0 */
void pmsm_foc_sensorless_nucleo_G4_step0(void) /* Sample time: [0.001s, 0.0s] */
{
  int32_T tmp_0;
  real32_T uartWriteData[3];
  uint32_T pinReadLoc;
  uint32_T sentLength;
  uint16_T status;
  uint8_T uartWriteData_0[4];
  boolean_T tmp;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* MATLABSystem: '<S10>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);
  tmp = ((pinReadLoc & 8192U) != 0U);

  /* MATLABSystem: '<S10>/Digital Port Read' */
  pmsm_foc_sensorless_nucleo_G4_B.DigitalPortRead = tmp;

  /* UnitDelay: '<S1>/Unit Delay' */
  pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_f =
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_k;

  /* Logic: '<S1>/NOT2' */
  pmsm_foc_sensorless_nucleo_G4_B.NOT2 =
    !pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_f;

  /* Logic: '<S1>/AND' */
  pmsm_foc_sensorless_nucleo_G4_B.AND =
    (pmsm_foc_sensorless_nucleo_G4_B.DigitalPortRead &&
     pmsm_foc_sensorless_nucleo_G4_B.NOT2);

  /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (pmsm_foc_sensorless_nucleo_G4_B.AND) {
    /* UnitDelay: '<S8>/Unit Delay' */
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_a =
      pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_a;

    /* Logic: '<S8>/NOT' */
    pmsm_foc_sensorless_nucleo_G4_B.NOT_n =
      !pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_a;

    /* Update for UnitDelay: '<S8>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_a =
      pmsm_foc_sensorless_nucleo_G4_B.NOT_n;
  }

  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  pmsm_foc_sensorless_nucle_DWork.Enable =
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_a;

  /* RateTransition: '<Root>/RT' */
  pmsm_foc_sensorless_nucleo_G4_B.RT_n = pmsm_foc_sensorless_nucleo_G4_B.Add1_f;

  /* Assignment: '<S6>/Assignment' incorporates:
   *  Constant: '<S6>/Constant'
   */
  pmsm_foc_sensorless_nucleo_G4_B.Assignment[0] =
    pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_nt[0];
  pmsm_foc_sensorless_nucleo_G4_B.Assignment[1] =
    pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_nt[1];
  pmsm_foc_sensorless_nucleo_G4_B.Assignment[2] =
    pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_nt[2];

  /* Assignment: '<S6>/Assignment' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  pmsm_foc_sensorless_nucleo_G4_B.Assignment[pmsm_foc_sensorless_nucleo_G4_P.Constant2_Value_nq]
    = pmsm_foc_sensorless_nucleo_G4_B.RT_n;

  /* RateTransition: '<Root>/RT1' */
  pmsm_foc_sensorless_nucle_DWork.RT1_semaphoreTaken =
    pmsm_foc_sensorless_nucle_DWork.RT1_ActiveBufIdx;
  tmp_0 = pmsm_foc_sensorless_nucle_DWork.RT1_semaphoreTaken << 1;

  /* RateTransition: '<Root>/RT1' */
  pmsm_foc_sensorless_nucleo_G4_B.RT1[0] =
    pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[tmp_0];
  pmsm_foc_sensorless_nucleo_G4_B.RT1[1] =
    pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[tmp_0 + 1];

  /* Assignment: '<S6>/Assignment1' */
  pmsm_foc_sensorless_nucleo_G4_B.Assignment1[0] =
    pmsm_foc_sensorless_nucleo_G4_B.Assignment[0];
  pmsm_foc_sensorless_nucleo_G4_B.Assignment1[1] =
    pmsm_foc_sensorless_nucleo_G4_B.Assignment[1];
  pmsm_foc_sensorless_nucleo_G4_B.Assignment1[2] =
    pmsm_foc_sensorless_nucleo_G4_B.Assignment[2];

  /* Assignment: '<S6>/Assignment1' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  pmsm_foc_sensorless_nucleo_G4_B.Assignment1[pmsm_foc_sensorless_nucleo_G4_P.Constant3_Value_e]
    = pmsm_foc_sensorless_nucleo_G4_B.RT1[0];

  /* Assignment: '<S6>/Assignment2' */
  pmsm_foc_sensorless_nucleo_G4_B.Assignment2[0] =
    pmsm_foc_sensorless_nucleo_G4_B.Assignment1[0];
  pmsm_foc_sensorless_nucleo_G4_B.Assignment2[1] =
    pmsm_foc_sensorless_nucleo_G4_B.Assignment1[1];
  pmsm_foc_sensorless_nucleo_G4_B.Assignment2[2] =
    pmsm_foc_sensorless_nucleo_G4_B.Assignment1[2];

  /* Assignment: '<S6>/Assignment2' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  pmsm_foc_sensorless_nucleo_G4_B.Assignment2[pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_d]
    = pmsm_foc_sensorless_nucleo_G4_B.RT1[1];

  /* MATLABSystem: '<S219>/UART//USART Write' incorporates:
   *  Constant: '<S219>/Constant4'
   */
  pinReadLoc = 3U;
  if (pmsm_foc_sensorless_nucleo_G4_P.Constant4_Value_b < 3U) {
    pinReadLoc = pmsm_foc_sensorless_nucleo_G4_P.Constant4_Value_b;
  }

  uartWriteData[0] = pmsm_foc_sensorless_nucleo_G4_B.Assignment2[0];
  uartWriteData[1] = pmsm_foc_sensorless_nucleo_G4_B.Assignment2[1];
  uartWriteData[2] = pmsm_foc_sensorless_nucleo_G4_B.Assignment2[2];

  /* Start for MATLABSystem: '<S219>/UART//USART Write' */
  tmp_0 = (int32_T)pinReadLoc;
  tmp_0 = (int32_T)((uint32_T)tmp_0 << 2);

  /* MATLABSystem: '<S219>/UART//USART Write' */
  status = MW_LPUART_TransmitUsingInterrupt
    (pmsm_foc_sensorless_nucle_DWork.obj.UARTHandle, &uartWriteData[0],
     (uint32_T)tmp_0, 0U, &sentLength);

  /* MATLABSystem: '<S219>/UART//USART Write' */
  pmsm_foc_sensorless_nucleo_G4_B.UARTUSARTWrite = status;

  /* Logic: '<S219>/NOT' */
  pmsm_foc_sensorless_nucleo_G4_B.NOT =
    (pmsm_foc_sensorless_nucleo_G4_B.UARTUSARTWrite == 0);

  /* Outputs for Enabled SubSystem: '<S219>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S220>/Enable'
   */
  if (pmsm_foc_sensorless_nucleo_G4_B.NOT) {
    /* MATLABSystem: '<S220>/UART//USART Write' incorporates:
     *  Constant: '<S220>/Constant1'
     *  Constant: '<S220>/Constant2'
     * */
    pinReadLoc = 4U;
    if (pmsm_foc_sensorless_nucleo_G4_P.Constant2_Value_n < 4U) {
      pinReadLoc = pmsm_foc_sensorless_nucleo_G4_P.Constant2_Value_n;
    }

    uartWriteData_0[0] = pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_f[0];
    uartWriteData_0[1] = pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_f[1];
    uartWriteData_0[2] = pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_f[2];
    uartWriteData_0[3] = pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_f[3];
    MW_LPUART_TransmitUsingInterrupt
      (pmsm_foc_sensorless_nucle_DWork.obj_e.UARTHandle, &uartWriteData_0[0],
       pinReadLoc, 0U, &sentLength);

    /* End of MATLABSystem: '<S220>/UART//USART Write' */
  }

  /* End of Outputs for SubSystem: '<S219>/Enabled Subsystem' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_k =
    pmsm_foc_sensorless_nucleo_G4_B.DigitalPortRead;
}

/* Model step function for TID1 */
void pmsm_foc_sensorless_nucleo_G4_step1(void) /* Sample time: [0.1s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  int32_T c;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  pmsm_foc_sensorless_nucleo_G4_B.LED =
    (pmsm_foc_sensorless_nucle_DWork.clockTickCounter <
     pmsm_foc_sensorless_nucleo_G4_P.PulseGenerator_Duty) &&
    (pmsm_foc_sensorless_nucle_DWork.clockTickCounter >= 0) ?
    pmsm_foc_sensorless_nucleo_G4_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  if (pmsm_foc_sensorless_nucle_DWork.clockTickCounter >=
      pmsm_foc_sensorless_nucleo_G4_P.PulseGenerator_Period - 1.0) {
    pmsm_foc_sensorless_nucle_DWork.clockTickCounter = 0;
  } else {
    pmsm_foc_sensorless_nucle_DWork.clockTickCounter++;
  }

  /* MATLABSystem: '<S218>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (pmsm_foc_sensorless_nucleo_G4_B.LED != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S218>/Digital Port Write' */
}

/* Model initialize function */
void pmsm_foc_sensorless_nucleo_G4_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)pmsm_foc_sensorless_nucleo_G_M, 0,
                sizeof(RT_MODEL_pmsm_foc_sensorless_nu));

  /* block I/O */
  (void) memset(((void *) &pmsm_foc_sensorless_nucleo_G4_B), 0,
                sizeof(BlockIO_pmsm_foc_sensorless_nuc));

  {
    pmsm_foc_sensorless_nucleo_G4_B.LED = 0.0;
    pmsm_foc_sensorless_nucleo_G4_B.RT_n = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.RT1[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.RT1[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment1[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment1[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment1[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment2[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment2[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Assignment2[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.ADvoltage[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.ADvoltage[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Kalpha = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Kbeta = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay1 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.a = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay5[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay5[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay5[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay5[3] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay_b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum2 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum3 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.b_invg = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay1 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum4 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product1 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add1_o = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay1_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_c = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.a_c = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay_f = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum2_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum3_m = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.b_invg_d = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay1_f = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum4_d = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1_o[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1_o[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_m = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product1_l = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add1_p = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Merge = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Merge1 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Delay_fn = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.PhaseDelay = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Merge_a = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.scaleIn = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_h = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.convert_pu = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Merge_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.indexing = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Lookup[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Lookup[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Lookup[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Lookup[3] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum3_i = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion1 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum2_g = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_h = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum4_h = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum5 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product1_k = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum6 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_k = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.PProdOut = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_g = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Integrator = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_i = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Saturation = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_d = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.PProdOut_i = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Integrator_a = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_o = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Saturation_h = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_o = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_oc = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_i = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_hz = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product1_n = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum1 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Merge_f[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Merge_f[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch4[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch4[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch4[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_l = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product1_f = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1_k[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1_k[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_ik = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_n = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product1_j = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add1_f = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sign = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Eta = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_c = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.a_n = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum1_n = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sign_b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Eta_h = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_l = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.b_j = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.a_k = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum1_m = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.DTC = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.SpeedGain = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1_d[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1_d[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_m = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_i = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product1_l2 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add1_g = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.DeadZone = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.IProdOut = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_g = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.DeadZone_h = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.IProdOut_b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.sqrt3_by_two = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.one_by_two = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.add_c = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Kc = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.add_b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Kb = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Ka = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Min = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Max = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.one_by_two_k = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add2 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add1_k = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add3 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_j[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_j[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_j[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_n[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_n[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_n[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add_c[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add_c[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add_c[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain1[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain1[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain1[2] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Saturation_i = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_c[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_c[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.SquareRoot = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_k = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_f[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_f[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch2 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_mt = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product2 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Merge_an = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_p = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_n = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch1_m = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sqrt = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_i = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Convert_back = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Convert_back_k = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.bcos = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.asin_f = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.sum_Qs = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.acos_f = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.bsin = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.sum_Ds = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_dt[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_dt[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.algDD_o1 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.algDD_o2 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Unary_Minus = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.qcos = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.dsin = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.sum_beta = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.dcos = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.qsin = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.sum_alpha = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_p[0] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_p[1] = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.algDD_o1_a = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.algDD_o2_j = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Unary_Minus_i = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.a_plus_2b = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.one_by_sqrt3 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.algDD_o1_j = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.algDD_o2_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add_g = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion1_p = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add1_m = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Input = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_j = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Add1_e = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.SaturatetomotorcalibSpeedRPM = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.scaleOut = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.AngleConversion = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product_b1 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product2_d = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum1_k = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product1_li = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Product3 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum2_et = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_o3 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Atan2 = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_nl = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.algDD = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Gain_d = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Switch_kk = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Bias = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Bias_d = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_bn = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_lt = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_d = 0.0F;
    pmsm_foc_sensorless_nucleo_G4_B.Sum_io = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&pmsm_foc_sensorless_nucle_DWork, 0,
                sizeof(D_Work_pmsm_foc_sensorless_nucl));
  pmsm_foc_sensorless_nucle_DWork.UnitDelay1_DSTATE = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[0] = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[1] = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[2] = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[3] = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_b = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay1_DSTATE_m = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_p = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_h = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE_e = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_d = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_p = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bp = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bv = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_c = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE_l = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_m = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bl = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[0] = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[1] = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[2] = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[3] = 0.0F;
  pmsm_foc_sensorless_nucle_DWork.GlobleopenspeedInt = 0.0F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  pmsm_foc_sensorless_nucle_DWork.Enable =
    pmsm_foc_sensorless_nucleo_G4_P.DataStoreMemory9_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
  pmsm_foc_sensorless_nucle_DWork.IaOffset =
    pmsm_foc_sensorless_nucleo_G4_P.DataStoreMemory13_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory14' */
  pmsm_foc_sensorless_nucle_DWork.IbOffset =
    pmsm_foc_sensorless_nucleo_G4_P.DataStoreMemory14_InitialValue;
  pmsm_foc_sensorl_PrevZCSigState.Dir_Sense_Trig_ZCE = POS_ZCSIG;
  pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  pmsm_foc_sensorl_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE_c = UNINITIALIZED_ZCSIG;
  pmsm_foc_sensorl_PrevZCSigState.Delay1_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_k =
    pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_e;

  /* InitializeConditions for RateTransition: '<Root>/RT1' */
  pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[0] =
    pmsm_foc_sensorless_nucleo_G4_P.RT1_InitialCondition;
  pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[1] =
    pmsm_foc_sensorless_nucleo_G4_P.RT1_InitialCondition;

  /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
  pmsm_foc_sensorless_nucle_DWork.clockTickCounter = 0;

  /* SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem' */
  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_a =
    pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_lg;

  /* SystemInitialize for UnitDelay: '<S8>/Unit Delay' incorporates:
   *  Outport: '<S8>/Out1'
   */
  pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_a =
    pmsm_foc_sensorless_nucleo_G4_P.Out1_Y0_o;

  /* End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S219>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S220>/UART//USART Write' */
  pmsm_foc_sensorless_nucle_DWork.obj_e.matlabCodegenIsDeleted = false;
  pmsm_foc_sensorless_nucle_DWork.objisempty_a = true;
  pmsm_foc_sensorless_nucle_DWork.obj_e.isSetupComplete = false;
  pmsm_foc_sensorless_nucle_DWork.obj_e.isInitialized = 1;
  pmsm_foc_se_UARTWrite_setupImpl(&pmsm_foc_sensorless_nucle_DWork.obj_e);
  pmsm_foc_sensorless_nucle_DWork.obj_e.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S219>/Enabled Subsystem' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  {
    int32_T i;

    /* Start for DataStoreMemory: '<S58>/Data Store Memory' */
    pmsm_foc_sensorless_nucle_DWork.GlobleopenspeedInt =
      pmsm_foc_sensorless_nucleo_G4_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S16>/Data Store Memory' */
    pmsm_foc_sensorless_nucle_DWork.statcount =
      pmsm_foc_sensorless_nucleo_G4_P.DataStoreMemory_InitialValue_b;

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay1' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay1_DSTATE =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S2>/Delay5' */
    pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[0] =
      pmsm_foc_sensorless_nucleo_G4_P.Delay5_InitialCondition;
    pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[1] =
      pmsm_foc_sensorless_nucleo_G4_P.Delay5_InitialCondition;
    pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[2] =
      pmsm_foc_sensorless_nucleo_G4_P.Delay5_InitialCondition;
    pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[3] =
      pmsm_foc_sensorless_nucleo_G4_P.Delay5_InitialCondition;

    /* InitializeConditions for Delay: '<S29>/Delay' */
    pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE =
      pmsm_foc_sensorless_nucleo_G4_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S39>/Delay1' */
    pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE =
      pmsm_foc_sensorless_nucleo_G4_P.Delay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S43>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_b =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay1' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay1_DSTATE_m =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay1_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_p =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S30>/Delay' */
    pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_h =
      pmsm_foc_sensorless_nucleo_G4_P.Delay_InitialCondition_e;

    /* InitializeConditions for Delay: '<S40>/Delay1' */
    pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE_e =
      pmsm_foc_sensorless_nucleo_G4_P.Delay1_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_d =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_p;

    /* InitializeConditions for Delay: '<S27>/Delay' */
    pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_p =
      pmsm_foc_sensorless_nucleo_G4_P.Delay_InitialCondition_b;

    /* InitializeConditions for UnitDelay: '<S61>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bp =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_pr;

    /* InitializeConditions for UnitDelay: '<S90>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bv =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_h;

    /* InitializeConditions for DiscreteIntegrator: '<S194>/Integrator' */
    pmsm_foc_sensorless_nucle_DWork.Integrator_PrevResetState = 0;
    pmsm_foc_sensorless_nucle_DWork.Integrator_IC_LOADING = 1U;

    /* InitializeConditions for UnitDelay: '<S89>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_c =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_b;

    /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator' */
    pmsm_foc_sensorless_nucle_DWork.Integrator_PrevResetState_i = 0;
    pmsm_foc_sensorless_nucle_DWork.Integrator_IC_LOADING_o = 1U;

    /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_m =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_o;

    /* InitializeConditions for Delay: '<S34>/Delay' */
    for (i = 0; i < 119; i++) {
      pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_a[i] =
        pmsm_foc_sensorless_nucleo_G4_P.Delay_InitialCondition_i;
    }

    pmsm_foc_sensorless_nucle_DWork.CircBufIdx = 0U;

    /* End of InitializeConditions for Delay: '<S34>/Delay' */

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay' */
    pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bl =
      pmsm_foc_sensorless_nucleo_G4_P.UnitDelay_InitialCondition_j;

    /* SystemInitialize for Triggered SubSystem: '<S28>/Dir_Sense' */
    /* SystemInitialize for Switch: '<S36>/Switch' incorporates:
     *  Outport: '<S36>/Sign'
     */
    pmsm_foc_sensorless_nucleo_G4_B.Switch_gg =
      pmsm_foc_sensorless_nucleo_G4_P.Sign_Y0;

    /* End of SystemInitialize for SubSystem: '<S28>/Dir_Sense' */

    /* SystemInitialize for Enabled SubSystem: '<S61>/Accumulate' */
    /* InitializeConditions for Delay: '<S62>/Delay' */
    pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_he =
      pmsm_foc_sensorless_nucleo_G4_P.Delay_InitialCondition_n;

    /* SystemInitialize for Enabled SubSystem: '<S62>/Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S63>/Input' incorporates:
     *  Outport: '<S63>/Out1'
     */
    pmsm_foc_sensorless_nucleo_G4_B.Input =
      pmsm_foc_sensorless_nucleo_G4_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S62>/Subsystem' */

    /* SystemInitialize for Sum: '<S62>/Add1' incorporates:
     *  Outport: '<S62>/theta_e'
     */
    pmsm_foc_sensorless_nucleo_G4_B.Add1_m =
      pmsm_foc_sensorless_nucleo_G4_P.theta_e_Y0;

    /* End of SystemInitialize for SubSystem: '<S61>/Accumulate' */

    /* Start for MATLABSystem: '<S20>/Analog to Digital Converter' */
    pmsm_foc_sensorless_nucle_DWork.obj_o.isInitialized = 0;
    pmsm_foc_sensorless_nucle_DWork.obj_o.matlabCodegenIsDeleted = false;
    pmsm_foc_sensorless_nucle_DWork.objisempty_o = true;
    pmsm_foc_senso_SystemCore_setup(&pmsm_foc_sensorless_nucle_DWork.obj_o);

    /* Start for MATLABSystem: '<S213>/PWM Output' */
    pmsm_foc_sensorless_nucle_DWork.obj_e3.matlabCodegenIsDeleted = false;
    pmsm_foc_sensorless_nucle_DWork.objisempty_k = true;
    pmsm_foc_sensorless_nucle_DWork.obj_e3.isSetupComplete = false;
    pmsm_foc_sensorless_nucle_DWork.obj_e3.isInitialized = 1;
    pmsm_foc_se_PWMOutput_setupImpl(&pmsm_foc_sensorless_nucle_DWork.obj_e3);
    pmsm_foc_sensorless_nucle_DWork.obj_e3.isSetupComplete = true;

    /* SystemInitialize for Gain: '<S27>/AngleConversion' incorporates:
     *  Outport: '<S2>/theta'
     */
    pmsm_foc_sensorless_nucleo_G4_B.AngleConversion =
      pmsm_foc_sensorless_nucleo_G4_P.theta_Y0;

    /* SystemInitialize for Gain: '<S54>/OP_Gain*R_shunt1' incorporates:
     *  Outport: '<S2>/currentab'
     */
    pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[0] =
      pmsm_foc_sensorless_nucleo_G4_P.currentab_Y0;
    pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[1] =
      pmsm_foc_sensorless_nucleo_G4_P.currentab_Y0;

    /* SystemInitialize for Sum: '<S26>/Add1' incorporates:
     *  Outport: '<S2>/Out2'
     */
    pmsm_foc_sensorless_nucleo_G4_B.Add1_f =
      pmsm_foc_sensorless_nucleo_G4_P.Out2_Y0;
  }

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S10>/Digital Port Read' */
  pmsm_foc_sensorless_nucle_DWork.objisempty_f = true;
  pmsm_foc_sensorless_nucle_DWork.obj_k.isInitialized = 1;

  /* Start for MATLABSystem: '<S219>/UART//USART Write' */
  pmsm_foc_sensorless_nucle_DWork.obj.matlabCodegenIsDeleted = false;
  pmsm_foc_sensorless_nucle_DWork.objisempty = true;
  pmsm_foc_sensorless_nucle_DWork.obj.isSetupComplete = false;
  pmsm_foc_sensorless_nucle_DWork.obj.isInitialized = 1;
  pmsm_foc_se_UARTWrite_setupImpl(&pmsm_foc_sensorless_nucle_DWork.obj);
  pmsm_foc_sensorless_nucle_DWork.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S218>/Digital Port Write' */
  pmsm_foc_sensorless_nucle_DWork.objisempty_n = true;
  pmsm_foc_sensorless_nucle_DWork.obj_kg.isInitialized = 1;

  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* DataStoreWrite: '<S4>/Data Store Write' incorporates:
   *  Constant: '<S4>/Testing get offset1'
   */
  pmsm_foc_sensorless_nucle_DWork.IaOffset =
    pmsm_foc_sensorless_nucleo_G4_P.Testinggetoffset1_Value;

  /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
   *  Constant: '<S4>/Testing get offset'
   */
  pmsm_foc_sensorless_nucle_DWork.IbOffset =
    pmsm_foc_sensorless_nucleo_G4_P.Testinggetoffset_Value;

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/* Model terminate function */
void pmsm_foc_sensorless_nucleo_G4_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S20>/Analog to Digital Converter' */
  if (!pmsm_foc_sensorless_nucle_DWork.obj_o.matlabCodegenIsDeleted) {
    pmsm_foc_sensorless_nucle_DWork.obj_o.matlabCodegenIsDeleted = true;
    if ((pmsm_foc_sensorless_nucle_DWork.obj_o.isInitialized == 1) &&
        pmsm_foc_sensorless_nucle_DWork.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(pmsm_foc_sensorless_nucle_DWork.obj_o.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S213>/PWM Output' */
  if (!pmsm_foc_sensorless_nucle_DWork.obj_e3.matlabCodegenIsDeleted) {
    pmsm_foc_sensorless_nucle_DWork.obj_e3.matlabCodegenIsDeleted = true;
    if ((pmsm_foc_sensorless_nucle_DWork.obj_e3.isInitialized == 1) &&
        pmsm_foc_sensorless_nucle_DWork.obj_e3.isSetupComplete) {
      disableCounter(pmsm_foc_sensorless_nucle_DWork.obj_e3.TimerHandle);
      disableTimerInterrupts(pmsm_foc_sensorless_nucle_DWork.obj_e3.TimerHandle,
        0);
      disableTimerChannel1(pmsm_foc_sensorless_nucle_DWork.obj_e3.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(pmsm_foc_sensorless_nucle_DWork.obj_e3.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(pmsm_foc_sensorless_nucle_DWork.obj_e3.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S213>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S219>/UART//USART Write' */
  if (!pmsm_foc_sensorless_nucle_DWork.obj.matlabCodegenIsDeleted) {
    pmsm_foc_sensorless_nucle_DWork.obj.matlabCodegenIsDeleted = true;
    if ((pmsm_foc_sensorless_nucle_DWork.obj.isInitialized == 1) &&
        pmsm_foc_sensorless_nucle_DWork.obj.isSetupComplete) {
      MW_LPUART_DeInit(pmsm_foc_sensorless_nucle_DWork.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S219>/UART//USART Write' */

  /* Terminate for Enabled SubSystem: '<S219>/Enabled Subsystem' */
  /* Terminate for MATLABSystem: '<S220>/UART//USART Write' */
  if (!pmsm_foc_sensorless_nucle_DWork.obj_e.matlabCodegenIsDeleted) {
    pmsm_foc_sensorless_nucle_DWork.obj_e.matlabCodegenIsDeleted = true;
    if ((pmsm_foc_sensorless_nucle_DWork.obj_e.isInitialized == 1) &&
        pmsm_foc_sensorless_nucle_DWork.obj_e.isSetupComplete) {
      MW_LPUART_DeInit(pmsm_foc_sensorless_nucle_DWork.obj_e.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S220>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<S219>/Enabled Subsystem' */
}

void pmsm_foc_sensorless_nucleo_G4_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC1_2_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S215>/Hardware Interrupt' */
void ADC1_2_IRQHandler(void)
{
  uint32_T priority_mask;
  priority_mask = MW_HWI_MaskInterrupt();

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
        /* S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          real_T y_tmp;
          uint64_T tmp_p;
          real32_T ADvoltage;
          real32_T Bias;
          real32_T Bias_tmp;
          uint32_T Sum;
          uint16_T tmp[2];
          uint16_T AnalogtoDigitalConverter;
          ZCSigState Delay_Reset_ZCE_tmp;
          int8_T Integrator_PrevResetState_tmp;
          boolean_T zcEvent;

          /* Switch: '<S93>/Switch1' incorporates:
           *  Constant: '<S93>/enableInportSatMethod'
           */
          if (pmsm_foc_sensorless_nucleo_G4_P.enableInportSatMethod_Value != 0)
          {
            /* Switch: '<S93>/Switch1' incorporates:
             *  Constant: '<S88>/ReplaceInport_satMethod'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_i =
              pmsm_foc_sensorless_nucleo_G4_P.ReplaceInport_satMethod_Value;
          } else {
            /* Switch: '<S93>/Switch1' incorporates:
             *  Constant: '<S93>/ChosenMethod'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_i =
              pmsm_foc_sensorless_nucleo_G4_P.ChosenMethod_Value;
          }

          /* End of Switch: '<S93>/Switch1' */

          /* DataStoreRead: '<S54>/Data Store Read' */
          pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_a =
            pmsm_foc_sensorless_nucle_DWork.IaOffset;

          /* DataStoreRead: '<S54>/Data Store Read1' */
          pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead1 =
            pmsm_foc_sensorless_nucle_DWork.IbOffset;

          /* MATLABSystem: '<S20>/Analog to Digital Converter' */
          injectedReadADCIntr(pmsm_foc_sensorless_nucle_DWork.obj_o.ADCHandle,
                              ADC_READ, &tmp[0]);

          /* MATLABSystem: '<S20>/Analog to Digital Converter' */
          AnalogtoDigitalConverter = tmp[0];
          pmsm_foc_sensorless_nucleo_G4_B.AnalogtoDigitalConverter[0] =
            AnalogtoDigitalConverter;

          /* DataTypeConversion: '<S54>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S20>/Analog to Digital Converter'
           */
          pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion[0] =
            AnalogtoDigitalConverter;

          /* MATLABSystem: '<S20>/Analog to Digital Converter' */
          AnalogtoDigitalConverter = tmp[1];
          pmsm_foc_sensorless_nucleo_G4_B.AnalogtoDigitalConverter[1] =
            AnalogtoDigitalConverter;

          /* DataTypeConversion: '<S54>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S20>/Analog to Digital Converter'
           */
          pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion[1] =
            AnalogtoDigitalConverter;

          /* Sum: '<S54>/Add' incorporates:
           *  DataTypeConversion: '<S54>/Data Type Conversion'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Add_a[0] =
            pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion[0] -
            pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_a;
          pmsm_foc_sensorless_nucleo_G4_B.Add_a[1] =
            pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion[1] -
            pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead1;

          /* Gain: '<S54>/AD voltage' incorporates:
           *  Sum: '<S54>/Add'
           */
          ADvoltage = pmsm_foc_sensorless_nucleo_G4_P.ADvoltage_Gain * (real32_T)
            pmsm_foc_sensorless_nucleo_G4_B.Add_a[0];
          pmsm_foc_sensorless_nucleo_G4_B.ADvoltage[0] = ADvoltage;

          /* Gain: '<S54>/OP_Gain*R_shunt' incorporates:
           *  Gain: '<S54>/AD voltage'
           */
          ADvoltage *= pmsm_foc_sensorless_nucleo_G4_P.OP_GainR_shunt_Gain;
          pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt[0] = ADvoltage;

          /* Gain: '<S54>/OP_Gain*R_shunt1' incorporates:
           *  Gain: '<S54>/OP_Gain*R_shunt'
           */
          pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[0] =
            pmsm_foc_sensorless_nucleo_G4_P.OP_GainR_shunt1_Gain * ADvoltage;

          /* Gain: '<S54>/AD voltage' incorporates:
           *  Sum: '<S54>/Add'
           */
          ADvoltage = pmsm_foc_sensorless_nucleo_G4_P.ADvoltage_Gain * (real32_T)
            pmsm_foc_sensorless_nucleo_G4_B.Add_a[1];
          pmsm_foc_sensorless_nucleo_G4_B.ADvoltage[1] = ADvoltage;

          /* Gain: '<S54>/OP_Gain*R_shunt' incorporates:
           *  Gain: '<S54>/AD voltage'
           */
          ADvoltage *= pmsm_foc_sensorless_nucleo_G4_P.OP_GainR_shunt_Gain;
          pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt[1] = ADvoltage;

          /* Gain: '<S54>/OP_Gain*R_shunt1' incorporates:
           *  Gain: '<S54>/OP_Gain*R_shunt'
           */
          pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[1] =
            pmsm_foc_sensorless_nucleo_G4_P.OP_GainR_shunt1_Gain * ADvoltage;

          /* Outputs for Atomic SubSystem: '<S70>/Two phase CRL wrap' */
          /* AlgorithmDescriptorDelegate generated from: '<S71>/a16' */
          arm_clarke_f32(pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[0],
                         pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[1],
                         &pmsm_foc_sensorless_nucleo_G4_B.algDD_o1_j,
                         &pmsm_foc_sensorless_nucleo_G4_B.algDD_o2_e);

          /* End of Outputs for SubSystem: '<S70>/Two phase CRL wrap' */

          /* Gain: '<S70>/Kalpha' */
          pmsm_foc_sensorless_nucleo_G4_B.Kalpha =
            pmsm_foc_sensorless_nucleo_G4_P.Kalpha_Gain *
            pmsm_foc_sensorless_nucleo_G4_B.algDD_o1_j;

          /* Gain: '<S70>/Kbeta' */
          pmsm_foc_sensorless_nucleo_G4_B.Kbeta =
            pmsm_foc_sensorless_nucleo_G4_P.Kbeta_Gain *
            pmsm_foc_sensorless_nucleo_G4_B.algDD_o2_e;

          /* UnitDelay: '<S39>/Unit Delay1' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay1 =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay1_DSTATE;

          /* UnitDelay: '<S39>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE;

          /* Gain: '<S39>/a' */
          pmsm_foc_sensorless_nucleo_G4_B.a =
            pmsm_foc_sensorless_nucleo_G4_P.a_Gain *
            pmsm_foc_sensorless_nucleo_G4_B.UnitDelay;

          /* Delay: '<S2>/Delay5' */
          pmsm_foc_sensorless_nucleo_G4_B.Delay5[0] =
            pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[0];
          pmsm_foc_sensorless_nucleo_G4_B.Delay5[1] =
            pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[1];
          pmsm_foc_sensorless_nucleo_G4_B.Delay5[2] =
            pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[2];
          pmsm_foc_sensorless_nucleo_G4_B.Delay5[3] =
            pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[3];

          /* DataStoreRead: '<S2>/Data Store Read' */
          pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_b =
            pmsm_foc_sensorless_nucle_DWork.Enable;

          /* Logic: '<S14>/Logical Operator' */
          pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator =
            !pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_b;

          /* Delay: '<S29>/Delay' */
          zcEvent = (((pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE ==
                       POS_ZCSIG) != (int32_T)
                      pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) &&
                     (pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) {
            pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE =
              pmsm_foc_sensorless_nucleo_G4_P.Delay_InitialCondition;
          }

          Delay_Reset_ZCE_tmp = pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator;
          pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S29>/Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.Delay_b =
            pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE;

          /* Sum: '<S29>/Sum2' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum2 =
            pmsm_foc_sensorless_nucleo_G4_B.Delay_b -
            pmsm_foc_sensorless_nucleo_G4_B.Delay5[2];

          /* Sum: '<S39>/Sum3' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum3 =
            (pmsm_foc_sensorless_nucleo_G4_B.UnitDelay1 -
             pmsm_foc_sensorless_nucleo_G4_B.a) +
            pmsm_foc_sensorless_nucleo_G4_B.Sum2;

          /* Gain: '<S39>/b_inv*g' incorporates:
           *  Gain: '<S40>/b_inv*g'
           */
          y_tmp =
            pmsm_foc_sensorless_nucleo_G4_P.SlidingModeObserver_Disturbance /
            0.077159178038513326;
          Bias_tmp = (real32_T)y_tmp;
          Bias = Bias_tmp;

          /* Gain: '<S39>/b_inv*g' */
          pmsm_foc_sensorless_nucleo_G4_B.b_invg = Bias *
            pmsm_foc_sensorless_nucleo_G4_B.Sum3;

          /* Delay: '<S39>/Delay1' */
          zcEvent = (((pmsm_foc_sensorl_PrevZCSigState.Delay1_Reset_ZCE ==
                       POS_ZCSIG) != (int32_T)
                      pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) &&
                     (pmsm_foc_sensorl_PrevZCSigState.Delay1_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) {
            pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE =
              pmsm_foc_sensorless_nucleo_G4_P.Delay1_InitialCondition;
          }

          pmsm_foc_sensorl_PrevZCSigState.Delay1_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S39>/Delay1' */
          pmsm_foc_sensorless_nucleo_G4_B.Delay1 =
            pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE;

          /* Sum: '<S39>/Sum4' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum4 =
            pmsm_foc_sensorless_nucleo_G4_B.b_invg +
            pmsm_foc_sensorless_nucleo_G4_B.Delay1;

          /* Switch: '<S31>/Switch1' incorporates:
           *  Constant: '<S31>/UseInputPort'
           */
          if (pmsm_foc_sensorless_nucleo_G4_P.UseInputPort_Value >
              pmsm_foc_sensorless_nucleo_G4_P.Switch1_Threshold_b) {
            /* Sum: '<S31>/Sum' incorporates:
             *  Constant: '<S31>/One'
             *  Constant: '<S31>/a'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Sum_d =
              pmsm_foc_sensorless_nucleo_G4_P.One_Value_p -
              pmsm_foc_sensorless_nucleo_G4_P.a_Value_i;

            /* Switch: '<S31>/Switch1' incorporates:
             *  Constant: '<S31>/a'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1[0] =
              pmsm_foc_sensorless_nucleo_G4_P.a_Value_i;
            pmsm_foc_sensorless_nucleo_G4_B.Switch1[1] =
              pmsm_foc_sensorless_nucleo_G4_B.Sum_d;
          } else {
            /* Switch: '<S31>/Switch1' incorporates:
             *  Constant: '<S31>/FilterConstant'
             *  Constant: '<S31>/OneMinusFilterConstant'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1[0] =
              pmsm_foc_sensorless_nucleo_G4_P.FilterConstant_Value_f;
            pmsm_foc_sensorless_nucleo_G4_B.Switch1[1] =
              pmsm_foc_sensorless_nucleo_G4_P.OneMinusFilterConstant_Value_f;
          }

          /* End of Switch: '<S31>/Switch1' */

          /* Product: '<S43>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product =
            pmsm_foc_sensorless_nucleo_G4_B.Sum4 *
            pmsm_foc_sensorless_nucleo_G4_B.Switch1[0];

          /* UnitDelay: '<S43>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_e =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_b;

          /* Product: '<S43>/Product1' */
          pmsm_foc_sensorless_nucleo_G4_B.Product1 =
            pmsm_foc_sensorless_nucleo_G4_B.Switch1[1] *
            pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_e;

          /* Sum: '<S43>/Add1' */
          pmsm_foc_sensorless_nucleo_G4_B.Add1_o =
            pmsm_foc_sensorless_nucleo_G4_B.Product +
            pmsm_foc_sensorless_nucleo_G4_B.Product1;

          /* Relay: '<S28>/AlphaRelay' */
          Bias = pmsm_foc_sensorless_nucleo_G4_B.Add1_o;
          pmsm_foc_sensorless_nucle_DWork.AlphaRelay_Mode = ((Bias >=
            pmsm_foc_sensorless_nucleo_G4_P.AlphaRelay_OnVal) || ((!(Bias <=
            pmsm_foc_sensorless_nucleo_G4_P.AlphaRelay_OffVal)) &&
            pmsm_foc_sensorless_nucle_DWork.AlphaRelay_Mode));
          if (pmsm_foc_sensorless_nucle_DWork.AlphaRelay_Mode) {
            /* Relay: '<S28>/AlphaRelay' */
            pmsm_foc_sensorless_nucleo_G4_B.AlphaRelay =
              pmsm_foc_sensorless_nucleo_G4_P.AlphaRelay_YOn;
          } else {
            /* Relay: '<S28>/AlphaRelay' */
            pmsm_foc_sensorless_nucleo_G4_B.AlphaRelay =
              pmsm_foc_sensorless_nucleo_G4_P.AlphaRelay_YOff;
          }

          /* End of Relay: '<S28>/AlphaRelay' */

          /* UnitDelay: '<S40>/Unit Delay1' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay1_e =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay1_DSTATE_m;

          /* UnitDelay: '<S40>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_c =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_p;

          /* Gain: '<S40>/a' */
          pmsm_foc_sensorless_nucleo_G4_B.a_c =
            pmsm_foc_sensorless_nucleo_G4_P.a_Gain_e *
            pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_c;

          /* Delay: '<S30>/Delay' */
          zcEvent = (((pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE_c ==
                       POS_ZCSIG) != (int32_T)
                      pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) &&
                     (pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE_c !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) {
            pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_h =
              pmsm_foc_sensorless_nucleo_G4_P.Delay_InitialCondition_e;
          }

          pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE_c =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S30>/Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.Delay_f =
            pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_h;

          /* Sum: '<S30>/Sum2' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum2_e =
            pmsm_foc_sensorless_nucleo_G4_B.Delay_f -
            pmsm_foc_sensorless_nucleo_G4_B.Delay5[3];

          /* Sum: '<S40>/Sum3' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum3_m =
            (pmsm_foc_sensorless_nucleo_G4_B.UnitDelay1_e -
             pmsm_foc_sensorless_nucleo_G4_B.a_c) +
            pmsm_foc_sensorless_nucleo_G4_B.Sum2_e;

          /* Gain: '<S40>/b_inv*g' */
          Bias = Bias_tmp;

          /* Gain: '<S40>/b_inv*g' */
          pmsm_foc_sensorless_nucleo_G4_B.b_invg_d = Bias *
            pmsm_foc_sensorless_nucleo_G4_B.Sum3_m;

          /* Delay: '<S40>/Delay1' */
          zcEvent = (((pmsm_foc_sensorl_PrevZCSigState.Delay1_Reset_ZCE_b ==
                       POS_ZCSIG) != (int32_T)
                      pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) &&
                     (pmsm_foc_sensorl_PrevZCSigState.Delay1_Reset_ZCE_b !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) {
            pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE_e =
              pmsm_foc_sensorless_nucleo_G4_P.Delay1_InitialCondition_m;
          }

          pmsm_foc_sensorl_PrevZCSigState.Delay1_Reset_ZCE_b =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S40>/Delay1' */
          pmsm_foc_sensorless_nucleo_G4_B.Delay1_f =
            pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE_e;

          /* Sum: '<S40>/Sum4' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum4_d =
            pmsm_foc_sensorless_nucleo_G4_B.b_invg_d +
            pmsm_foc_sensorless_nucleo_G4_B.Delay1_f;

          /* Switch: '<S32>/Switch1' incorporates:
           *  Constant: '<S32>/UseInputPort'
           */
          if (pmsm_foc_sensorless_nucleo_G4_P.UseInputPort_Value_g >
              pmsm_foc_sensorless_nucleo_G4_P.Switch1_Threshold_bx) {
            /* Sum: '<S32>/Sum' incorporates:
             *  Constant: '<S32>/One'
             *  Constant: '<S32>/a'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Sum_lt =
              pmsm_foc_sensorless_nucleo_G4_P.One_Value_c -
              pmsm_foc_sensorless_nucleo_G4_P.a_Value_h;

            /* Switch: '<S32>/Switch1' incorporates:
             *  Constant: '<S32>/a'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_o[0] =
              pmsm_foc_sensorless_nucleo_G4_P.a_Value_h;
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_o[1] =
              pmsm_foc_sensorless_nucleo_G4_B.Sum_lt;
          } else {
            /* Switch: '<S32>/Switch1' incorporates:
             *  Constant: '<S32>/FilterConstant'
             *  Constant: '<S32>/OneMinusFilterConstant'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_o[0] =
              pmsm_foc_sensorless_nucleo_G4_P.FilterConstant_Value_g;
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_o[1] =
              pmsm_foc_sensorless_nucleo_G4_P.OneMinusFilterConstant_Value_j;
          }

          /* End of Switch: '<S32>/Switch1' */

          /* Product: '<S46>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product_b =
            pmsm_foc_sensorless_nucleo_G4_B.Sum4_d *
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_o[0];

          /* UnitDelay: '<S46>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_m =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_d;

          /* Product: '<S46>/Product1' */
          pmsm_foc_sensorless_nucleo_G4_B.Product1_l =
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_o[1] *
            pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_m;

          /* Sum: '<S46>/Add1' */
          pmsm_foc_sensorless_nucleo_G4_B.Add1_p =
            pmsm_foc_sensorless_nucleo_G4_B.Product_b +
            pmsm_foc_sensorless_nucleo_G4_B.Product1_l;

          /* Relay: '<S28>/BetaRelay' */
          Bias = pmsm_foc_sensorless_nucleo_G4_B.Add1_p;
          pmsm_foc_sensorless_nucle_DWork.BetaRelay_Mode = ((Bias >=
            pmsm_foc_sensorless_nucleo_G4_P.BetaRelay_OnVal) || ((!(Bias <=
            pmsm_foc_sensorless_nucleo_G4_P.BetaRelay_OffVal)) &&
            pmsm_foc_sensorless_nucle_DWork.BetaRelay_Mode));
          if (pmsm_foc_sensorless_nucle_DWork.BetaRelay_Mode) {
            /* Relay: '<S28>/BetaRelay' */
            pmsm_foc_sensorless_nucleo_G4_B.BetaRelay =
              pmsm_foc_sensorless_nucleo_G4_P.BetaRelay_YOn;
          } else {
            /* Relay: '<S28>/BetaRelay' */
            pmsm_foc_sensorless_nucleo_G4_B.BetaRelay =
              pmsm_foc_sensorless_nucleo_G4_P.BetaRelay_YOff;
          }

          /* End of Relay: '<S28>/BetaRelay' */

          /* Outputs for Triggered SubSystem: '<S28>/Dir_Sense' incorporates:
           *  TriggerPort: '<S36>/Trigger'
           */
          zcEvent = (pmsm_foc_sensorless_nucleo_G4_B.AlphaRelay &&
                     (pmsm_foc_sensorl_PrevZCSigState.Dir_Sense_Trig_ZCE !=
                      POS_ZCSIG));
          if (zcEvent) {
            /* Logic: '<S36>/Logical Operator' */
            pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator_g =
              (pmsm_foc_sensorless_nucleo_G4_B.AlphaRelay &&
               pmsm_foc_sensorless_nucleo_G4_B.BetaRelay);

            /* Switch: '<S36>/Switch' */
            if (pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator_g) {
              /* Switch: '<S36>/Switch' incorporates:
               *  Constant: '<S36>/Constant'
               */
              pmsm_foc_sensorless_nucleo_G4_B.Switch_gg = (int16_T)floor
                (pmsm_foc_sensorless_nucleo_G4_P.Constant_Value);
            } else {
              /* Switch: '<S36>/Switch' incorporates:
               *  Constant: '<S36>/Constant1'
               */
              pmsm_foc_sensorless_nucleo_G4_B.Switch_gg = (int16_T)floor
                (pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value);
            }

            /* End of Switch: '<S36>/Switch' */
          }

          pmsm_foc_sensorl_PrevZCSigState.Dir_Sense_Trig_ZCE =
            pmsm_foc_sensorless_nucleo_G4_B.AlphaRelay;

          /* End of Outputs for SubSystem: '<S28>/Dir_Sense' */

          /* If: '<S28>/If' */
          if (pmsm_foc_sensorless_nucleo_G4_B.Switch_gg > 0) {
            /* Outputs for IfAction SubSystem: '<S28>/Subsystem2' incorporates:
             *  ActionPort: '<S37>/Action Port'
             */
            /* Merge: '<S28>/Merge' incorporates:
             *  UnaryMinus: '<S37>/Unary Minus'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Merge =
              -pmsm_foc_sensorless_nucleo_G4_B.Add1_o;

            /* Merge: '<S28>/Merge1' incorporates:
             *  SignalConversion generated from: '<S37>/SigmaBeta'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Merge1 =
              pmsm_foc_sensorless_nucleo_G4_B.Add1_p;

            /* End of Outputs for SubSystem: '<S28>/Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S28>/Subsystem3' incorporates:
             *  ActionPort: '<S38>/Action Port'
             */
            /* Merge: '<S28>/Merge1' incorporates:
             *  UnaryMinus: '<S38>/Unary Minus'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Merge1 =
              -pmsm_foc_sensorless_nucleo_G4_B.Add1_p;

            /* Merge: '<S28>/Merge' incorporates:
             *  SignalConversion generated from: '<S38>/SigmaAlpha'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Merge =
              pmsm_foc_sensorless_nucleo_G4_B.Add1_o;

            /* End of Outputs for SubSystem: '<S28>/Subsystem3' */
          }

          /* End of If: '<S28>/If' */

          /* Delay: '<S27>/Delay' */
          zcEvent = (((pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE_n ==
                       POS_ZCSIG) != (int32_T)
                      pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) &&
                     (pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE_n !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator) {
            pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_p =
              pmsm_foc_sensorless_nucleo_G4_P.Delay_InitialCondition_b;
          }

          pmsm_foc_sensorl_PrevZCSigState.Delay_Reset_ZCE_n =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S27>/Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.Delay_fn =
            pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_p;

          /* Constant: '<S27>/PhaseDelay' */
          y_tmp = pmsm_foc_sensorless_nucleo_G4_P.SlidingModeObserver_CutoffFreq
            / 83.333333333333329;

          /* Constant: '<S27>/PhaseDelay' */
          pmsm_foc_sensorless_nucleo_G4_B.PhaseDelay = (real32_T)y_tmp;

          /* Outputs for Atomic SubSystem: '<S27>/angleCompensation' */
          /* Product: '<S35>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product_b1 =
            pmsm_foc_sensorless_nucleo_G4_B.Merge *
            pmsm_foc_sensorless_nucleo_G4_B.PhaseDelay;

          /* Product: '<S35>/Product2' */
          pmsm_foc_sensorless_nucleo_G4_B.Product2_d =
            pmsm_foc_sensorless_nucleo_G4_B.Merge1 *
            pmsm_foc_sensorless_nucleo_G4_B.Delay_fn;

          /* Sum: '<S35>/Sum1' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum1_k =
            pmsm_foc_sensorless_nucleo_G4_B.Product_b1 +
            pmsm_foc_sensorless_nucleo_G4_B.Product2_d;

          /* Product: '<S35>/Product1' */
          pmsm_foc_sensorless_nucleo_G4_B.Product1_li =
            pmsm_foc_sensorless_nucleo_G4_B.Merge1 *
            pmsm_foc_sensorless_nucleo_G4_B.PhaseDelay;

          /* Product: '<S35>/Product3' */
          pmsm_foc_sensorless_nucleo_G4_B.Product3 =
            pmsm_foc_sensorless_nucleo_G4_B.Merge *
            pmsm_foc_sensorless_nucleo_G4_B.Delay_fn;

          /* Sum: '<S35>/Sum2' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum2_et =
            pmsm_foc_sensorless_nucleo_G4_B.Product1_li -
            pmsm_foc_sensorless_nucleo_G4_B.Product3;

          /* Outputs for Atomic SubSystem: '<S35>/atan1' */
          /* Trigonometry: '<S52>/Atan2' */
          pmsm_foc_sensorless_nucleo_G4_B.Atan2 = rt_atan2f_snf
            (pmsm_foc_sensorless_nucleo_G4_B.Sum1_k,
             pmsm_foc_sensorless_nucleo_G4_B.Sum2_et);

          /* Outputs for Atomic SubSystem: '<S35>/atan1' */
          /* Switch: '<S52>/Switch' */
          if (pmsm_foc_sensorless_nucleo_G4_P.atan1_outputUnit >
              pmsm_foc_sensorless_nucleo_G4_P.Switch_Threshold_f) {
            /* Outputs for Atomic SubSystem: '<S52>/Per Unit' */
            /* Gain: '<S53>/Gain' */
            pmsm_foc_sensorless_nucleo_G4_B.Gain_d =
              pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.Atan2;

            /* Switch: '<S53>/Switch' */
            if (pmsm_foc_sensorless_nucleo_G4_B.Gain_d >=
                pmsm_foc_sensorless_nucleo_G4_P.Switch_Threshold) {
              /* Switch: '<S53>/Switch' */
              pmsm_foc_sensorless_nucleo_G4_B.Switch_kk =
                pmsm_foc_sensorless_nucleo_G4_B.Gain_d;
            } else {
              /* Bias: '<S53>/Bias' */
              pmsm_foc_sensorless_nucleo_G4_B.Bias =
                pmsm_foc_sensorless_nucleo_G4_B.Gain_d +
                pmsm_foc_sensorless_nucleo_G4_P.Bias_Bias_g;

              /* Switch: '<S53>/Switch' */
              pmsm_foc_sensorless_nucleo_G4_B.Switch_kk =
                pmsm_foc_sensorless_nucleo_G4_B.Bias;
            }

            /* End of Switch: '<S53>/Switch' */
            /* End of Outputs for SubSystem: '<S52>/Per Unit' */

            /* Switch: '<S52>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_nl =
              pmsm_foc_sensorless_nucleo_G4_B.Switch_kk;
          } else {
            /* Switch: '<S52>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_nl =
              pmsm_foc_sensorless_nucleo_G4_B.Atan2;
          }

          /* End of Switch: '<S52>/Switch' */
          /* End of Outputs for SubSystem: '<S35>/atan1' */

          /* AlgorithmDescriptorDelegate generated from: '<S52>/a16' */
          pmsm_foc_sensorless_nucleo_G4_B.algDD =
            pmsm_foc_sensorless_nucleo_G4_B.Switch_nl;

          /* End of Outputs for SubSystem: '<S35>/atan1' */

          /* Switch: '<S35>/Switch' */
          if (pmsm_foc_sensorless_nucleo_G4_B.algDD >
              pmsm_foc_sensorless_nucleo_G4_P.Switch_Threshold_k) {
            /* Switch: '<S35>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_o3 =
              pmsm_foc_sensorless_nucleo_G4_B.algDD;
          } else {
            /* Bias: '<S35>/Bias' */
            pmsm_foc_sensorless_nucleo_G4_B.Bias_d =
              pmsm_foc_sensorless_nucleo_G4_B.algDD +
              pmsm_foc_sensorless_nucleo_G4_P.Bias_Bias;

            /* Switch: '<S35>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_o3 =
              pmsm_foc_sensorless_nucleo_G4_B.Bias_d;
          }

          /* End of Switch: '<S35>/Switch' */
          /* End of Outputs for SubSystem: '<S27>/angleCompensation' */

          /* DataStoreRead: '<S16>/Data Store Read' */
          pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_c =
            pmsm_foc_sensorless_nucle_DWork.Enable;

          /* If: '<S16>/If1' */
          if (pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_c) {
            /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S56>/Action Port'
             */
            /* DataStoreRead: '<S56>/Data Store Read' */
            pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead =
              pmsm_foc_sensorless_nucle_DWork.statcount;

            /* Sum: '<S56>/Add1' incorporates:
             *  Constant: '<S56>/Constant'
             */
            tmp_p = (uint64_T)pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_g +
              pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead;
            if (tmp_p > 4294967295ULL) {
              tmp_p = 4294967295ULL;
            }

            /* Sum: '<S56>/Add1' */
            pmsm_foc_sensorless_nucleo_G4_B.Add1 = (uint32_T)tmp_p;

            /* DataStoreWrite: '<S56>/Data Store Write' */
            pmsm_foc_sensorless_nucle_DWork.statcount =
              pmsm_foc_sensorless_nucleo_G4_B.Add1;

            /* Merge: '<S16>/Merge2' incorporates:
             *  SignalConversion generated from: '<S56>/Out1'
             */
            pmsm_foc_sensorless_nucleo_G4_B.cont =
              pmsm_foc_sensorless_nucleo_G4_B.Add1;

            /* End of Outputs for SubSystem: '<S16>/If Action Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S57>/Action Port'
             */
            /* DataStoreWrite: '<S57>/Data Store Write' incorporates:
             *  Constant: '<S57>/Constant15'
             */
            pmsm_foc_sensorless_nucle_DWork.statcount =
              pmsm_foc_sensorless_nucleo_G4_P.Constant15_Value;

            /* Merge: '<S16>/Merge2' incorporates:
             *  Constant: '<S57>/Constant15'
             *  SignalConversion generated from: '<S57>/Out1'
             */
            pmsm_foc_sensorless_nucleo_G4_B.cont =
              pmsm_foc_sensorless_nucleo_G4_P.Constant15_Value;

            /* End of Outputs for SubSystem: '<S16>/If Action Subsystem3' */
          }

          /* End of If: '<S16>/If1' */

          /* RelationalOperator: '<S55>/Compare' incorporates:
           *  Constant: '<S55>/Constant'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Compare =
            (pmsm_foc_sensorless_nucleo_G4_B.cont <=
             pmsm_foc_sensorless_nucleo_G4_P.EnablePWMfor8seconds_const);

          /* Logic: '<S16>/NOT' */
          pmsm_foc_sensorless_nucleo_G4_B.NOT_c =
            !pmsm_foc_sensorless_nucleo_G4_B.Compare;

          /* If: '<S58>/If' incorporates:
           *  Constant: '<S58>/Count for 2 sec'
           */
          if (pmsm_foc_sensorless_nucleo_G4_B.cont <
              pmsm_foc_sensorless_nucleo_G4_P.Countfor2sec_Value) {
            /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem' incorporates:
             *  ActionPort: '<S59>/Action Port'
             */
            /* DataStoreWrite: '<S59>/Data Store Write' incorporates:
             *  Constant: '<S59>/Constant'
             */
            pmsm_foc_sensorless_nucle_DWork.GlobleopenspeedInt =
              pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_n;

            /* Merge: '<S58>/Merge' incorporates:
             *  Constant: '<S59>/Constant'
             *  SignalConversion generated from: '<S59>/Out1'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Merge_a =
              pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_n;

            /* End of Outputs for SubSystem: '<S58>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S60>/Action Port'
             */
            /* DataStoreRead: '<S60>/Data Store Read' */
            pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_j =
              pmsm_foc_sensorless_nucle_DWork.GlobleopenspeedInt;

            /* Sum: '<S60>/Add1' incorporates:
             *  Constant: '<S60>/Constant2'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Add1_e =
              pmsm_foc_sensorless_nucleo_G4_P.Constant2_Value +
              pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead_j;

            /* Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */
            Bias = pmsm_foc_sensorless_nucleo_G4_B.Add1_e;
            Bias_tmp =
              pmsm_foc_sensorless_nucleo_G4_P.SaturatetomotorcalibSpeedRPM_Lo;
            ADvoltage =
              pmsm_foc_sensorless_nucleo_G4_P.SaturatetomotorcalibSpeedRPM_Up;
            if (Bias > ADvoltage) {
              /* Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */
              pmsm_foc_sensorless_nucleo_G4_B.SaturatetomotorcalibSpeedRPM =
                ADvoltage;
            } else if (Bias < Bias_tmp) {
              /* Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */
              pmsm_foc_sensorless_nucleo_G4_B.SaturatetomotorcalibSpeedRPM =
                Bias_tmp;
            } else {
              /* Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */
              pmsm_foc_sensorless_nucleo_G4_B.SaturatetomotorcalibSpeedRPM =
                Bias;
            }

            /* End of Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */

            /* DataStoreWrite: '<S60>/Data Store Write' */
            pmsm_foc_sensorless_nucle_DWork.GlobleopenspeedInt =
              pmsm_foc_sensorless_nucleo_G4_B.SaturatetomotorcalibSpeedRPM;

            /* Merge: '<S58>/Merge' incorporates:
             *  Gain: '<S60>/Multiply1'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Merge_a =
              pmsm_foc_sensorless_nucleo_G4_P.Multiply1_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.SaturatetomotorcalibSpeedRPM;

            /* End of Outputs for SubSystem: '<S58>/If Action Subsystem2' */
          }

          /* End of If: '<S58>/If' */

          /* Gain: '<S61>/scaleIn' */
          pmsm_foc_sensorless_nucleo_G4_B.scaleIn =
            pmsm_foc_sensorless_nucleo_G4_P.scaleIn_Gain *
            pmsm_foc_sensorless_nucleo_G4_B.Merge_a;

          /* UnitDelay: '<S61>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_h =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bp;

          /* Logic: '<S61>/NOT' incorporates:
           *  Constant: '<S61>/Constant_Reset'
           */
          pmsm_foc_sensorless_nucleo_G4_B.NOT_b =
            !pmsm_foc_sensorless_nucleo_G4_P.Constant_Reset_Value;

          /* Outputs for Enabled SubSystem: '<S61>/Accumulate' incorporates:
           *  EnablePort: '<S62>/Enable'
           */
          if (pmsm_foc_sensorless_nucleo_G4_B.NOT_b) {
            /* Delay: '<S62>/Delay' */
            pmsm_foc_sensorless_nucleo_G4_B.Delay_e =
              pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_he;

            /* Outputs for Enabled SubSystem: '<S62>/Subsystem' incorporates:
             *  EnablePort: '<S63>/Enable'
             */
            if (pmsm_foc_sensorless_nucleo_G4_B.Delay_e) {
              /* SignalConversion generated from: '<S63>/Input' */
              pmsm_foc_sensorless_nucleo_G4_B.Input =
                pmsm_foc_sensorless_nucleo_G4_B.scaleIn;
            }

            /* End of Outputs for SubSystem: '<S62>/Subsystem' */

            /* Sum: '<S62>/Add' */
            pmsm_foc_sensorless_nucleo_G4_B.Add_g =
              pmsm_foc_sensorless_nucleo_G4_B.Input +
              pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_h;

            /* DataTypeConversion: '<S62>/Data Type Conversion' */
            pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion_i = (int16_T)
              floorf(pmsm_foc_sensorless_nucleo_G4_B.Add_g);

            /* DataTypeConversion: '<S62>/Data Type Conversion1' */
            pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion1_p =
              pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion_i;

            /* Sum: '<S62>/Add1' */
            pmsm_foc_sensorless_nucleo_G4_B.Add1_m =
              pmsm_foc_sensorless_nucleo_G4_B.Add_g -
              pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion1_p;

            /* Update for Delay: '<S62>/Delay' incorporates:
             *  Constant: '<S62>/Constant'
             */
            pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_he =
              pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_a;
          }

          /* End of Outputs for SubSystem: '<S61>/Accumulate' */

          /* Switch: '<S15>/Switch' */
          if (pmsm_foc_sensorless_nucleo_G4_B.NOT_c) {
            /* Gain: '<S27>/AngleConversion' */
            pmsm_foc_sensorless_nucleo_G4_B.AngleConversion =
              pmsm_foc_sensorless_nucleo_G4_P.AngleConversion_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.Switch_o3;

            /* Switch: '<S15>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch =
              pmsm_foc_sensorless_nucleo_G4_B.AngleConversion;
          } else {
            /* Gain: '<S61>/scaleOut' */
            pmsm_foc_sensorless_nucleo_G4_B.scaleOut =
              pmsm_foc_sensorless_nucleo_G4_P.scaleOut_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.Add1_m;

            /* Switch: '<S15>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch =
              pmsm_foc_sensorless_nucleo_G4_B.scaleOut;
          }

          /* End of Switch: '<S15>/Switch' */

          /* Gain: '<S84>/convert_pu' */
          pmsm_foc_sensorless_nucleo_G4_B.convert_pu =
            pmsm_foc_sensorless_nucleo_G4_P.convert_pu_Gain *
            pmsm_foc_sensorless_nucleo_G4_B.Switch;

          /* RelationalOperator: '<S85>/Compare' incorporates:
           *  Constant: '<S85>/Constant'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Compare_f =
            (pmsm_foc_sensorless_nucleo_G4_B.convert_pu <
             pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_m);

          /* DataTypeConversion: '<S84>/Data Type Conversion' */
          pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion_a =
            pmsm_foc_sensorless_nucleo_G4_B.Compare_f;

          /* If: '<S84>/If' */
          if (pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion_a > 0) {
            /* Outputs for IfAction SubSystem: '<S84>/If Action Subsystem' incorporates:
             *  ActionPort: '<S86>/Action Port'
             */
            /* DataTypeConversion: '<S86>/Convert_uint16' */
            pmsm_foc_sensorless_nucleo_G4_B.Convert_uint16_f = (int16_T)floorf
              (pmsm_foc_sensorless_nucleo_G4_B.convert_pu);

            /* DataTypeConversion: '<S86>/Convert_back' */
            pmsm_foc_sensorless_nucleo_G4_B.Convert_back_k =
              pmsm_foc_sensorless_nucleo_G4_B.Convert_uint16_f;

            /* Merge: '<S84>/Merge' incorporates:
             *  Sum: '<S86>/Sum'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Merge_e =
              pmsm_foc_sensorless_nucleo_G4_B.convert_pu -
              pmsm_foc_sensorless_nucleo_G4_B.Convert_back_k;

            /* End of Outputs for SubSystem: '<S84>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S84>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S87>/Action Port'
             */
            /* DataTypeConversion: '<S87>/Convert_uint16' */
            pmsm_foc_sensorless_nucleo_G4_B.Convert_uint16 = (int16_T)
              pmsm_foc_sensorless_nucleo_G4_B.convert_pu;

            /* DataTypeConversion: '<S87>/Convert_back' */
            pmsm_foc_sensorless_nucleo_G4_B.Convert_back =
              pmsm_foc_sensorless_nucleo_G4_B.Convert_uint16;

            /* Merge: '<S84>/Merge' incorporates:
             *  Sum: '<S87>/Sum'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Merge_e =
              pmsm_foc_sensorless_nucleo_G4_B.convert_pu -
              pmsm_foc_sensorless_nucleo_G4_B.Convert_back;

            /* End of Outputs for SubSystem: '<S84>/If Action Subsystem1' */
          }

          /* End of If: '<S84>/If' */

          /* Gain: '<S68>/indexing' */
          pmsm_foc_sensorless_nucleo_G4_B.indexing =
            pmsm_foc_sensorless_nucleo_G4_P.indexing_Gain *
            pmsm_foc_sensorless_nucleo_G4_B.Merge_e;

          /* DataTypeConversion: '<S68>/Get_Integer' */
          pmsm_foc_sensorless_nucleo_G4_B.Get_Integer = (uint16_T)
            pmsm_foc_sensorless_nucleo_G4_B.indexing;

          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/offset'
           */
          Sum = (uint32_T)pmsm_foc_sensorless_nucleo_G4_P.offset_Value[0] +
            pmsm_foc_sensorless_nucleo_G4_B.Get_Integer;
          pmsm_foc_sensorless_nucleo_G4_B.Sum[0] = Sum;

          /* Selector: '<S68>/Lookup' incorporates:
           *  Constant: '<S68>/sine_table_values'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Lookup[0] =
            pmsm_foc_sensorless_nucleo_G4_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/offset'
           */
          Sum = (uint32_T)pmsm_foc_sensorless_nucleo_G4_P.offset_Value[1] +
            pmsm_foc_sensorless_nucleo_G4_B.Get_Integer;
          pmsm_foc_sensorless_nucleo_G4_B.Sum[1] = Sum;

          /* Selector: '<S68>/Lookup' incorporates:
           *  Constant: '<S68>/sine_table_values'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Lookup[1] =
            pmsm_foc_sensorless_nucleo_G4_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/offset'
           */
          Sum = (uint32_T)pmsm_foc_sensorless_nucleo_G4_P.offset_Value[2] +
            pmsm_foc_sensorless_nucleo_G4_B.Get_Integer;
          pmsm_foc_sensorless_nucleo_G4_B.Sum[2] = Sum;

          /* Selector: '<S68>/Lookup' incorporates:
           *  Constant: '<S68>/sine_table_values'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Lookup[2] =
            pmsm_foc_sensorless_nucleo_G4_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/offset'
           */
          Sum = (uint32_T)pmsm_foc_sensorless_nucleo_G4_P.offset_Value[3] +
            pmsm_foc_sensorless_nucleo_G4_B.Get_Integer;
          pmsm_foc_sensorless_nucleo_G4_B.Sum[3] = Sum;

          /* Selector: '<S68>/Lookup' incorporates:
           *  Constant: '<S68>/sine_table_values'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Lookup[3] =
            pmsm_foc_sensorless_nucleo_G4_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S83>/Sum3' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum3_i =
            pmsm_foc_sensorless_nucleo_G4_B.Lookup[0] -
            pmsm_foc_sensorless_nucleo_G4_B.Lookup[1];

          /* DataTypeConversion: '<S68>/Data Type Conversion1' */
          pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion1 =
            pmsm_foc_sensorless_nucleo_G4_B.Get_Integer;

          /* Sum: '<S68>/Sum2' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum2_g =
            pmsm_foc_sensorless_nucleo_G4_B.indexing -
            pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion1;

          /* Product: '<S83>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product_h =
            pmsm_foc_sensorless_nucleo_G4_B.Sum3_i *
            pmsm_foc_sensorless_nucleo_G4_B.Sum2_g;

          /* Sum: '<S83>/Sum4' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum4_h =
            pmsm_foc_sensorless_nucleo_G4_B.Product_h +
            pmsm_foc_sensorless_nucleo_G4_B.Lookup[1];

          /* Sum: '<S83>/Sum5' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum5 =
            pmsm_foc_sensorless_nucleo_G4_B.Lookup[2] -
            pmsm_foc_sensorless_nucleo_G4_B.Lookup[3];

          /* Product: '<S83>/Product1' */
          pmsm_foc_sensorless_nucleo_G4_B.Product1_k =
            pmsm_foc_sensorless_nucleo_G4_B.Sum5 *
            pmsm_foc_sensorless_nucleo_G4_B.Sum2_g;

          /* Sum: '<S83>/Sum6' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum6 =
            pmsm_foc_sensorless_nucleo_G4_B.Product1_k +
            pmsm_foc_sensorless_nucleo_G4_B.Lookup[3];

          /* Outputs for Atomic SubSystem: '<S67>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S81>/a16' */
          arm_park_f32(pmsm_foc_sensorless_nucleo_G4_B.Kalpha,
                       pmsm_foc_sensorless_nucleo_G4_B.Kbeta,
                       &pmsm_foc_sensorless_nucleo_G4_B.algDD_o1,
                       &pmsm_foc_sensorless_nucleo_G4_B.algDD_o2,
                       pmsm_foc_sensorless_nucleo_G4_B.Sum4_h,
                       pmsm_foc_sensorless_nucleo_G4_B.Sum6);

          /* End of Outputs for SubSystem: '<S67>/Two inputs CRL' */

          /* Sum: '<S90>/Sum' incorporates:
           *  Constant: '<S17>/Constant2'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Sum_k =
            pmsm_foc_sensorless_nucleo_G4_P.Constant2_Value_c -
            pmsm_foc_sensorless_nucleo_G4_B.algDD_o2;

          /* Product: '<S199>/PProd Out' incorporates:
           *  Constant: '<S69>/Kp'
           */
          pmsm_foc_sensorless_nucleo_G4_B.PProdOut =
            pmsm_foc_sensorless_nucleo_G4_B.Sum_k *
            pmsm_foc_sensorless_nucleo_G4_P.Kp_Value;

          /* Logic: '<S90>/Logical Operator' incorporates:
           *  Logic: '<S89>/Logical Operator1'
           */
          zcEvent = !pmsm_foc_sensorless_nucleo_G4_B.NOT_c;

          /* Logic: '<S90>/Logical Operator' */
          pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator_n = zcEvent;

          /* UnitDelay: '<S90>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_g =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bv;

          /* DiscreteIntegrator: '<S194>/Integrator' */
          if (pmsm_foc_sensorless_nucle_DWork.Integrator_IC_LOADING != 0) {
            pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE =
              pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_g;
          }

          if (pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator_n ||
              (pmsm_foc_sensorless_nucle_DWork.Integrator_PrevResetState != 0))
          {
            pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE =
              pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_g;
          }

          /* DiscreteIntegrator: '<S194>/Integrator' */
          pmsm_foc_sensorless_nucleo_G4_B.Integrator =
            pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE;

          /* Sum: '<S203>/Sum' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum_i =
            pmsm_foc_sensorless_nucleo_G4_B.PProdOut +
            pmsm_foc_sensorless_nucleo_G4_B.Integrator;

          /* Saturate: '<S201>/Saturation' */
          Bias = pmsm_foc_sensorless_nucleo_G4_B.Sum_i;
          Bias_tmp =
            pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiwin;
          ADvoltage =
            pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_e;
          if (Bias > ADvoltage) {
            /* Saturate: '<S201>/Saturation' */
            pmsm_foc_sensorless_nucleo_G4_B.Saturation = ADvoltage;
          } else if (Bias < Bias_tmp) {
            /* Saturate: '<S201>/Saturation' */
            pmsm_foc_sensorless_nucleo_G4_B.Saturation = Bias_tmp;
          } else {
            /* Saturate: '<S201>/Saturation' */
            pmsm_foc_sensorless_nucleo_G4_B.Saturation = Bias;
          }

          /* End of Saturate: '<S201>/Saturation' */

          /* Switch: '<S90>/Switch' */
          if (pmsm_foc_sensorless_nucleo_G4_B.NOT_c) {
            /* Switch: '<S90>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_d =
              pmsm_foc_sensorless_nucleo_G4_B.Saturation;
          } else {
            /* Switch: '<S90>/Switch' incorporates:
             *  Constant: '<S90>/Vq_OpenLoop'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_d =
              pmsm_foc_sensorless_nucleo_G4_P.Vq_OpenLoop_Value;
          }

          /* End of Switch: '<S90>/Switch' */

          /* Sum: '<S89>/Sum' incorporates:
           *  Constant: '<S17>/Constant3'
           */
          pmsm_foc_sensorless_nucleo_G4_B.Sum_b =
            pmsm_foc_sensorless_nucleo_G4_P.Constant3_Value_o -
            pmsm_foc_sensorless_nucleo_G4_B.algDD_o1;

          /* Product: '<S146>/PProd Out' incorporates:
           *  Constant: '<S69>/Kp'
           */
          pmsm_foc_sensorless_nucleo_G4_B.PProdOut_i =
            pmsm_foc_sensorless_nucleo_G4_B.Sum_b *
            pmsm_foc_sensorless_nucleo_G4_P.Kp_Value;

          /* Logic: '<S89>/Logical Operator1' */
          pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator1 = zcEvent;

          /* UnitDelay: '<S89>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_b =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_c;

          /* DiscreteIntegrator: '<S141>/Integrator' */
          if (pmsm_foc_sensorless_nucle_DWork.Integrator_IC_LOADING_o != 0) {
            pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE_l =
              pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_b;
          }

          if (pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator1 ||
              (pmsm_foc_sensorless_nucle_DWork.Integrator_PrevResetState_i != 0))
          {
            pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE_l =
              pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_b;
          }

          /* DiscreteIntegrator: '<S141>/Integrator' */
          pmsm_foc_sensorless_nucleo_G4_B.Integrator_a =
            pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE_l;

          /* Sum: '<S150>/Sum' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum_o =
            pmsm_foc_sensorless_nucleo_G4_B.PProdOut_i +
            pmsm_foc_sensorless_nucleo_G4_B.Integrator_a;

          /* Saturate: '<S148>/Saturation' */
          Bias = pmsm_foc_sensorless_nucleo_G4_B.Sum_o;
          Bias_tmp =
            pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_f;
          ADvoltage =
            pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_b;
          if (Bias > ADvoltage) {
            /* Saturate: '<S148>/Saturation' */
            pmsm_foc_sensorless_nucleo_G4_B.Saturation_h = ADvoltage;
          } else if (Bias < Bias_tmp) {
            /* Saturate: '<S148>/Saturation' */
            pmsm_foc_sensorless_nucleo_G4_B.Saturation_h = Bias_tmp;
          } else {
            /* Saturate: '<S148>/Saturation' */
            pmsm_foc_sensorless_nucleo_G4_B.Saturation_h = Bias;
          }

          /* End of Saturate: '<S148>/Saturation' */

          /* Switch: '<S89>/Switch' */
          if (pmsm_foc_sensorless_nucleo_G4_B.NOT_c) {
            /* Switch: '<S89>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_o =
              pmsm_foc_sensorless_nucleo_G4_B.Saturation_h;
          } else {
            /* Saturate: '<S89>/Saturation' incorporates:
             *  Constant: '<S89>/Constant'
             */
            Bias = pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_h;
            Bias_tmp = pmsm_foc_sensorless_nucleo_G4_P.Saturation_LowerSat;
            ADvoltage = pmsm_foc_sensorless_nucleo_G4_P.Saturation_UpperSat;
            if (Bias > ADvoltage) {
              /* Saturate: '<S89>/Saturation' */
              pmsm_foc_sensorless_nucleo_G4_B.Saturation_i = ADvoltage;
            } else if (Bias < Bias_tmp) {
              /* Saturate: '<S89>/Saturation' */
              pmsm_foc_sensorless_nucleo_G4_B.Saturation_i = Bias_tmp;
            } else {
              /* Saturate: '<S89>/Saturation' */
              pmsm_foc_sensorless_nucleo_G4_B.Saturation_i = Bias;
            }

            /* End of Saturate: '<S89>/Saturation' */

            /* Switch: '<S89>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_o =
              pmsm_foc_sensorless_nucleo_G4_B.Saturation_i;
          }

          /* End of Switch: '<S89>/Switch' */

          /* Switch: '<S93>/Switch' incorporates:
           *  Constant: '<S93>/enableInportSatLim'
           */
          if (pmsm_foc_sensorless_nucleo_G4_P.enableInportSatLim_Value != 0) {
            /* Switch: '<S93>/Switch' incorporates:
             *  Constant: '<S88>/ReplaceInport_satLim'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_oc =
              pmsm_foc_sensorless_nucleo_G4_P.ReplaceInport_satLim_Value;
          } else {
            /* Switch: '<S93>/Switch' incorporates:
             *  Constant: '<S93>/Constant3'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_oc =
              pmsm_foc_sensorless_nucleo_G4_P.Constant3_Value;
          }

          /* End of Switch: '<S93>/Switch' */

          /* Product: '<S93>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product_i =
            pmsm_foc_sensorless_nucleo_G4_B.Switch_oc *
            pmsm_foc_sensorless_nucleo_G4_B.Switch_oc;

          /* Product: '<S94>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product_hz =
            pmsm_foc_sensorless_nucleo_G4_B.Switch_o *
            pmsm_foc_sensorless_nucleo_G4_B.Switch_o;

          /* Product: '<S94>/Product1' */
          pmsm_foc_sensorless_nucleo_G4_B.Product1_n =
            pmsm_foc_sensorless_nucleo_G4_B.Switch_d *
            pmsm_foc_sensorless_nucleo_G4_B.Switch_d;

          /* Sum: '<S94>/Sum1' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum1 =
            pmsm_foc_sensorless_nucleo_G4_B.Product_hz +
            pmsm_foc_sensorless_nucleo_G4_B.Product1_n;

          /* If: '<S88>/If' */
          if ((pmsm_foc_sensorless_nucleo_G4_B.Switch1_i == 1) ||
              (pmsm_foc_sensorless_nucleo_G4_B.Switch1_i == 2)) {
            /* Outputs for IfAction SubSystem: '<S88>/D//Q Axis Priority' incorporates:
             *  ActionPort: '<S92>/Action Port'
             */
            /* RelationalOperator: '<S97>/Compare' incorporates:
             *  Constant: '<S97>/Constant'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Compare_e =
              (pmsm_foc_sensorless_nucleo_G4_B.Switch1_i ==
               pmsm_foc_sensorless_nucleo_G4_P.CompareToConstant_const);

            /* RelationalOperator: '<S98>/Compare' incorporates:
             *  Constant: '<S98>/Constant'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Compare_n =
              (pmsm_foc_sensorless_nucleo_G4_B.Switch1_i ==
               pmsm_foc_sensorless_nucleo_G4_P.CompareToConstant1_const);

            /* Switch: '<S92>/Switch' */
            if (pmsm_foc_sensorless_nucleo_G4_B.Compare_e) {
              /* Switch: '<S92>/Switch' */
              pmsm_foc_sensorless_nucleo_G4_B.Switch_f[0] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_o;
              pmsm_foc_sensorless_nucleo_G4_B.Switch_f[1] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_d;
            } else {
              /* Switch: '<S92>/Switch' */
              pmsm_foc_sensorless_nucleo_G4_B.Switch_f[0] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_d;
              pmsm_foc_sensorless_nucleo_G4_B.Switch_f[1] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_o;
            }

            /* End of Switch: '<S92>/Switch' */

            /* RelationalOperator: '<S102>/LowerRelop1' */
            pmsm_foc_sensorless_nucleo_G4_B.LowerRelop1 =
              (pmsm_foc_sensorless_nucleo_G4_B.Switch_f[0] >
               pmsm_foc_sensorless_nucleo_G4_B.Switch_oc);

            /* Switch: '<S102>/Switch2' */
            if (pmsm_foc_sensorless_nucleo_G4_B.LowerRelop1) {
              /* Switch: '<S102>/Switch2' */
              pmsm_foc_sensorless_nucleo_G4_B.Switch2 =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_oc;
            } else {
              /* Gain: '<S101>/Gain' */
              pmsm_foc_sensorless_nucleo_G4_B.Gain_p =
                pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_n *
                pmsm_foc_sensorless_nucleo_G4_B.Switch_oc;

              /* RelationalOperator: '<S102>/UpperRelop' */
              pmsm_foc_sensorless_nucleo_G4_B.UpperRelop =
                (pmsm_foc_sensorless_nucleo_G4_B.Switch_f[0] <
                 pmsm_foc_sensorless_nucleo_G4_B.Gain_p);

              /* Switch: '<S102>/Switch' */
              if (pmsm_foc_sensorless_nucleo_G4_B.UpperRelop) {
                /* Switch: '<S102>/Switch' */
                pmsm_foc_sensorless_nucleo_G4_B.Switch_n =
                  pmsm_foc_sensorless_nucleo_G4_B.Gain_p;
              } else {
                /* Switch: '<S102>/Switch' */
                pmsm_foc_sensorless_nucleo_G4_B.Switch_n =
                  pmsm_foc_sensorless_nucleo_G4_B.Switch_f[0];
              }

              /* End of Switch: '<S102>/Switch' */

              /* Switch: '<S102>/Switch2' */
              pmsm_foc_sensorless_nucleo_G4_B.Switch2 =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_n;
            }

            /* End of Switch: '<S102>/Switch2' */

            /* Product: '<S101>/Product' */
            pmsm_foc_sensorless_nucleo_G4_B.Product_mt =
              pmsm_foc_sensorless_nucleo_G4_B.Switch2 *
              pmsm_foc_sensorless_nucleo_G4_B.Switch2;

            /* Sum: '<S101>/Sum' */
            pmsm_foc_sensorless_nucleo_G4_B.Sum_e =
              pmsm_foc_sensorless_nucleo_G4_B.Product_i -
              pmsm_foc_sensorless_nucleo_G4_B.Product_mt;

            /* Product: '<S101>/Product2' */
            pmsm_foc_sensorless_nucleo_G4_B.Product2 =
              pmsm_foc_sensorless_nucleo_G4_B.Switch_f[1] *
              pmsm_foc_sensorless_nucleo_G4_B.Switch_f[1];

            /* RelationalOperator: '<S101>/Relational Operator' */
            pmsm_foc_sensorless_nucleo_G4_B.RelationalOperator_i =
              (pmsm_foc_sensorless_nucleo_G4_B.Sum_e >=
               pmsm_foc_sensorless_nucleo_G4_B.Product2);

            /* DataTypeConversion: '<S101>/Data Type Conversion' */
            pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion_h =
              pmsm_foc_sensorless_nucleo_G4_B.RelationalOperator_i;

            /* If: '<S101>/If' incorporates:
             *  Switch: '<S103>/Switch1'
             */
            if (pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion_h != 0) {
              /* Outputs for IfAction SubSystem: '<S101>/passThrough' incorporates:
               *  ActionPort: '<S104>/Action Port'
               */
              /* Merge: '<S101>/Merge' incorporates:
               *  SignalConversion generated from: '<S104>/ref2'
               */
              pmsm_foc_sensorless_nucleo_G4_B.Merge_an =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_f[1];

              /* End of Outputs for SubSystem: '<S101>/passThrough' */
            } else {
              /* Outputs for IfAction SubSystem: '<S101>/limitRef2' incorporates:
               *  ActionPort: '<S103>/Action Port'
               */
              if (pmsm_foc_sensorless_nucleo_G4_B.Sum_e >
                  pmsm_foc_sensorless_nucleo_G4_P.Switch1_Threshold) {
                /* Switch: '<S103>/Switch1' */
                pmsm_foc_sensorless_nucleo_G4_B.Switch1_m =
                  pmsm_foc_sensorless_nucleo_G4_B.Sum_e;
              } else {
                /* Switch: '<S103>/Switch1' incorporates:
                 *  Constant: '<S103>/Constant'
                 */
                pmsm_foc_sensorless_nucleo_G4_B.Switch1_m =
                  pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_j;
              }

              /* Sqrt: '<S103>/Sqrt' */
              mw_arm_sqrt_f32(&pmsm_foc_sensorless_nucleo_G4_B.Switch1_m,
                              &pmsm_foc_sensorless_nucleo_G4_B.Sqrt, 1U);

              /* Switch: '<S103>/Switch' */
              if (pmsm_foc_sensorless_nucleo_G4_B.Switch_f[1] >=
                  pmsm_foc_sensorless_nucleo_G4_P.Switch_Threshold_c) {
                /* Merge: '<S101>/Merge' */
                pmsm_foc_sensorless_nucleo_G4_B.Merge_an =
                  pmsm_foc_sensorless_nucleo_G4_B.Sqrt;
              } else {
                /* Gain: '<S103>/Gain' */
                pmsm_foc_sensorless_nucleo_G4_B.Gain_i =
                  pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_m *
                  pmsm_foc_sensorless_nucleo_G4_B.Sqrt;

                /* Merge: '<S101>/Merge' */
                pmsm_foc_sensorless_nucleo_G4_B.Merge_an =
                  pmsm_foc_sensorless_nucleo_G4_B.Gain_i;
              }

              /* End of Switch: '<S103>/Switch' */
              /* End of Outputs for SubSystem: '<S101>/limitRef2' */
            }

            /* End of If: '<S101>/If' */

            /* Switch: '<S92>/Switch1' */
            if (pmsm_foc_sensorless_nucleo_G4_B.Compare_n) {
              /* Merge: '<S88>/Merge' */
              pmsm_foc_sensorless_nucleo_G4_B.Merge_f[0] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch2;
              pmsm_foc_sensorless_nucleo_G4_B.Merge_f[1] =
                pmsm_foc_sensorless_nucleo_G4_B.Merge_an;
            } else {
              /* Merge: '<S88>/Merge' */
              pmsm_foc_sensorless_nucleo_G4_B.Merge_f[0] =
                pmsm_foc_sensorless_nucleo_G4_B.Merge_an;
              pmsm_foc_sensorless_nucleo_G4_B.Merge_f[1] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch2;
            }

            /* End of Switch: '<S92>/Switch1' */
            /* End of Outputs for SubSystem: '<S88>/D//Q Axis Priority' */
          } else {
            /* Outputs for IfAction SubSystem: '<S88>/D-Q Equivalence' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            /* RelationalOperator: '<S91>/Relational Operator' */
            pmsm_foc_sensorless_nucleo_G4_B.RelationalOperator_j =
              (pmsm_foc_sensorless_nucleo_G4_B.Sum1 >
               pmsm_foc_sensorless_nucleo_G4_B.Product_i);

            /* DataTypeConversion: '<S91>/Data Type Conversion' */
            pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion_f =
              pmsm_foc_sensorless_nucleo_G4_B.RelationalOperator_j;

            /* If: '<S91>/If' */
            if (pmsm_foc_sensorless_nucleo_G4_B.DataTypeConversion_f != 0) {
              /* Outputs for IfAction SubSystem: '<S91>/Limiter' incorporates:
               *  ActionPort: '<S95>/Action Port'
               */
              /* Product: '<S95>/Product' */
              pmsm_foc_sensorless_nucleo_G4_B.Product_c[0] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_o *
                pmsm_foc_sensorless_nucleo_G4_B.Switch_oc;
              pmsm_foc_sensorless_nucleo_G4_B.Product_c[1] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_d *
                pmsm_foc_sensorless_nucleo_G4_B.Switch_oc;

              /* Sqrt: '<S95>/Square Root' */
              mw_arm_sqrt_f32(&pmsm_foc_sensorless_nucleo_G4_B.Sum1,
                              &pmsm_foc_sensorless_nucleo_G4_B.SquareRoot, 1U);

              /* Switch: '<S95>/Switch' */
              if (pmsm_foc_sensorless_nucleo_G4_B.SquareRoot != 0.0F) {
                /* Switch: '<S95>/Switch' */
                pmsm_foc_sensorless_nucleo_G4_B.Switch_k =
                  pmsm_foc_sensorless_nucleo_G4_B.SquareRoot;
              } else {
                /* Switch: '<S95>/Switch' incorporates:
                 *  Constant: '<S95>/Constant'
                 */
                pmsm_foc_sensorless_nucleo_G4_B.Switch_k =
                  pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_p;
              }

              /* End of Switch: '<S95>/Switch' */

              /* Merge: '<S88>/Merge' incorporates:
               *  Product: '<S95>/Divide'
               */
              pmsm_foc_sensorless_nucleo_G4_B.Merge_f[0] =
                pmsm_foc_sensorless_nucleo_G4_B.Product_c[0] /
                pmsm_foc_sensorless_nucleo_G4_B.Switch_k;
              pmsm_foc_sensorless_nucleo_G4_B.Merge_f[1] =
                pmsm_foc_sensorless_nucleo_G4_B.Product_c[1] /
                pmsm_foc_sensorless_nucleo_G4_B.Switch_k;

              /* End of Outputs for SubSystem: '<S91>/Limiter' */
            } else {
              /* Outputs for IfAction SubSystem: '<S91>/Passthrough' incorporates:
               *  ActionPort: '<S96>/Action Port'
               */
              /* Merge: '<S88>/Merge' incorporates:
               *  SignalConversion generated from: '<S96>/dqRef'
               */
              pmsm_foc_sensorless_nucleo_G4_B.Merge_f[0] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_o;
              pmsm_foc_sensorless_nucleo_G4_B.Merge_f[1] =
                pmsm_foc_sensorless_nucleo_G4_B.Switch_d;

              /* End of Outputs for SubSystem: '<S91>/Passthrough' */
            }

            /* End of If: '<S91>/If' */
            /* End of Outputs for SubSystem: '<S88>/D-Q Equivalence' */
          }

          /* End of If: '<S88>/If' */

          /* Outputs for Atomic SubSystem: '<S65>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S72>/a16' */
          arm_inv_park_f32(pmsm_foc_sensorless_nucleo_G4_B.Merge_f[0],
                           pmsm_foc_sensorless_nucleo_G4_B.Merge_f[1],
                           &pmsm_foc_sensorless_nucleo_G4_B.algDD_o1_a,
                           &pmsm_foc_sensorless_nucleo_G4_B.algDD_o2_j,
                           pmsm_foc_sensorless_nucleo_G4_B.Sum4_h,
                           pmsm_foc_sensorless_nucleo_G4_B.Sum6);

          /* End of Outputs for SubSystem: '<S65>/Two inputs CRL' */

          /* DataStoreRead: '<S18>/Data Store Read1' */
          pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead1_n =
            pmsm_foc_sensorless_nucle_DWork.Enable;

          /* Switch: '<S18>/Switch4' incorporates:
           *  Constant: '<S18>/stop'
           */
          if (pmsm_foc_sensorless_nucleo_G4_B.DataStoreRead1_n) {
            /* Gain: '<S80>/sqrt3_by_two' */
            pmsm_foc_sensorless_nucleo_G4_B.sqrt3_by_two =
              pmsm_foc_sensorless_nucleo_G4_P.sqrt3_by_two_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.algDD_o2_j;

            /* Gain: '<S80>/one_by_two' */
            pmsm_foc_sensorless_nucleo_G4_B.one_by_two =
              pmsm_foc_sensorless_nucleo_G4_P.one_by_two_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.algDD_o1_a;

            /* Sum: '<S80>/add_c' */
            pmsm_foc_sensorless_nucleo_G4_B.add_c = (0.0F -
              pmsm_foc_sensorless_nucleo_G4_B.one_by_two) -
              pmsm_foc_sensorless_nucleo_G4_B.sqrt3_by_two;

            /* Gain: '<S80>/Kc' */
            pmsm_foc_sensorless_nucleo_G4_B.Kc =
              pmsm_foc_sensorless_nucleo_G4_P.Kc_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.add_c;

            /* Sum: '<S80>/add_b' */
            pmsm_foc_sensorless_nucleo_G4_B.add_b =
              pmsm_foc_sensorless_nucleo_G4_B.sqrt3_by_two -
              pmsm_foc_sensorless_nucleo_G4_B.one_by_two;

            /* Gain: '<S80>/Kb' */
            pmsm_foc_sensorless_nucleo_G4_B.Kb =
              pmsm_foc_sensorless_nucleo_G4_P.Kb_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.add_b;

            /* Gain: '<S80>/Ka' */
            pmsm_foc_sensorless_nucleo_G4_B.Ka =
              pmsm_foc_sensorless_nucleo_G4_P.Ka_Gain *
              pmsm_foc_sensorless_nucleo_G4_B.algDD_o1_a;

            /* MinMax: '<S77>/Min' */
            Bias = fminf(pmsm_foc_sensorless_nucleo_G4_B.Ka,
                         pmsm_foc_sensorless_nucleo_G4_B.Kb);
            Bias = fminf(Bias, pmsm_foc_sensorless_nucleo_G4_B.Kc);

            /* MinMax: '<S77>/Min' */
            pmsm_foc_sensorless_nucleo_G4_B.Min = Bias;

            /* MinMax: '<S77>/Max' */
            Bias = fmaxf(pmsm_foc_sensorless_nucleo_G4_B.Ka,
                         pmsm_foc_sensorless_nucleo_G4_B.Kb);
            Bias = fmaxf(Bias, pmsm_foc_sensorless_nucleo_G4_B.Kc);

            /* MinMax: '<S77>/Max' */
            pmsm_foc_sensorless_nucleo_G4_B.Max = Bias;

            /* Sum: '<S77>/Add' */
            pmsm_foc_sensorless_nucleo_G4_B.Add_e =
              pmsm_foc_sensorless_nucleo_G4_B.Max +
              pmsm_foc_sensorless_nucleo_G4_B.Min;

            /* Gain: '<S77>/one_by_two' */
            pmsm_foc_sensorless_nucleo_G4_B.one_by_two_k =
              pmsm_foc_sensorless_nucleo_G4_P.one_by_two_Gain_g *
              pmsm_foc_sensorless_nucleo_G4_B.Add_e;

            /* Sum: '<S76>/Add2' */
            pmsm_foc_sensorless_nucleo_G4_B.Add2 =
              pmsm_foc_sensorless_nucleo_G4_B.one_by_two_k +
              pmsm_foc_sensorless_nucleo_G4_B.Kc;

            /* Sum: '<S76>/Add1' */
            pmsm_foc_sensorless_nucleo_G4_B.Add1_k =
              pmsm_foc_sensorless_nucleo_G4_B.Kb +
              pmsm_foc_sensorless_nucleo_G4_B.one_by_two_k;

            /* Sum: '<S76>/Add3' */
            pmsm_foc_sensorless_nucleo_G4_B.Add3 =
              pmsm_foc_sensorless_nucleo_G4_B.Ka +
              pmsm_foc_sensorless_nucleo_G4_B.one_by_two_k;

            /* Gain: '<S76>/Gain' */
            pmsm_foc_sensorless_nucleo_G4_B.Gain_j[0] =
              pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_mr *
              pmsm_foc_sensorless_nucleo_G4_B.Add3;
            pmsm_foc_sensorless_nucleo_G4_B.Gain_j[1] =
              pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_mr *
              pmsm_foc_sensorless_nucleo_G4_B.Add1_k;
            pmsm_foc_sensorless_nucleo_G4_B.Gain_j[2] =
              pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_mr *
              pmsm_foc_sensorless_nucleo_G4_B.Add2;

            /* Gain: '<S18>/Gain' */
            ADvoltage = pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_k *
              pmsm_foc_sensorless_nucleo_G4_B.Gain_j[0];
            pmsm_foc_sensorless_nucleo_G4_B.Gain_n[0] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_a;
            pmsm_foc_sensorless_nucleo_G4_B.Add_c[0] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= pmsm_foc_sensorless_nucleo_G4_P.Gain1_Gain;
            pmsm_foc_sensorless_nucleo_G4_B.Gain1[0] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch4[0] = ADvoltage;

            /* Gain: '<S18>/Gain' */
            ADvoltage = pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_k *
              pmsm_foc_sensorless_nucleo_G4_B.Gain_j[1];
            pmsm_foc_sensorless_nucleo_G4_B.Gain_n[1] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_a;
            pmsm_foc_sensorless_nucleo_G4_B.Add_c[1] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= pmsm_foc_sensorless_nucleo_G4_P.Gain1_Gain;
            pmsm_foc_sensorless_nucleo_G4_B.Gain1[1] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch4[1] = ADvoltage;

            /* Gain: '<S18>/Gain' */
            ADvoltage = pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_k *
              pmsm_foc_sensorless_nucleo_G4_B.Gain_j[2];
            pmsm_foc_sensorless_nucleo_G4_B.Gain_n[2] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_a;
            pmsm_foc_sensorless_nucleo_G4_B.Add_c[2] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= pmsm_foc_sensorless_nucleo_G4_P.Gain1_Gain;
            pmsm_foc_sensorless_nucleo_G4_B.Gain1[2] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch4[2] = ADvoltage;
          } else {
            ADvoltage = pmsm_foc_sensorless_nucleo_G4_P.stop_Value;

            /* Switch: '<S18>/Switch4' incorporates:
             *  Constant: '<S18>/stop'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch4[0] = ADvoltage;
            pmsm_foc_sensorless_nucleo_G4_B.Switch4[1] = ADvoltage;
            pmsm_foc_sensorless_nucleo_G4_B.Switch4[2] = ADvoltage;
          }

          /* End of Switch: '<S18>/Switch4' */

          /* MATLABSystem: '<S213>/PWM Output' */
          setDutyCycleInPercentageChannel1
            (pmsm_foc_sensorless_nucle_DWork.obj_e3.TimerHandle,
             pmsm_foc_sensorless_nucleo_G4_B.Switch4[0]);
          setDutyCycleInPercentageChannel2
            (pmsm_foc_sensorless_nucle_DWork.obj_e3.TimerHandle,
             pmsm_foc_sensorless_nucleo_G4_B.Switch4[1]);
          setDutyCycleInPercentageChannel3
            (pmsm_foc_sensorless_nucle_DWork.obj_e3.TimerHandle,
             pmsm_foc_sensorless_nucleo_G4_B.Switch4[2]);

          /* Product: '<S13>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product_l =
            pmsm_foc_sensorless_nucleo_G4_B.algDD_o1 *
            pmsm_foc_sensorless_nucleo_G4_B.Merge_f[0];

          /* Product: '<S13>/Product1' */
          pmsm_foc_sensorless_nucleo_G4_B.Product1_f =
            pmsm_foc_sensorless_nucleo_G4_B.algDD_o2 *
            pmsm_foc_sensorless_nucleo_G4_B.Merge_f[1];

          /* Sum: '<S13>/Add' */
          pmsm_foc_sensorless_nucleo_G4_B.Add =
            pmsm_foc_sensorless_nucleo_G4_B.Product_l +
            pmsm_foc_sensorless_nucleo_G4_B.Product1_f;

          /* Gain: '<S13>/Gain' */
          pmsm_foc_sensorless_nucleo_G4_B.Gain =
            pmsm_foc_sensorless_nucleo_G4_P.Gain_Gain_f *
            pmsm_foc_sensorless_nucleo_G4_B.Add;

          /* Switch: '<S23>/Switch1' incorporates:
           *  Constant: '<S23>/UseInputPort'
           */
          if (pmsm_foc_sensorless_nucleo_G4_P.UseInputPort_Value_p >
              pmsm_foc_sensorless_nucleo_G4_P.Switch1_Threshold_o) {
            /* Sum: '<S23>/Sum' incorporates:
             *  Constant: '<S23>/One'
             *  Constant: '<S23>/a'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Sum_io =
              pmsm_foc_sensorless_nucleo_G4_P.One_Value -
              pmsm_foc_sensorless_nucleo_G4_P.a_Value;

            /* Switch: '<S23>/Switch1' incorporates:
             *  Constant: '<S23>/a'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_k[0] =
              pmsm_foc_sensorless_nucleo_G4_P.a_Value;
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_k[1] =
              pmsm_foc_sensorless_nucleo_G4_B.Sum_io;
          } else {
            /* Switch: '<S23>/Switch1' incorporates:
             *  Constant: '<S23>/FilterConstant'
             *  Constant: '<S23>/OneMinusFilterConstant'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_k[0] =
              pmsm_foc_sensorless_nucleo_G4_P.FilterConstant_Value;
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_k[1] =
              pmsm_foc_sensorless_nucleo_G4_P.OneMinusFilterConstant_Value;
          }

          /* End of Switch: '<S23>/Switch1' */

          /* Product: '<S26>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product_ik =
            pmsm_foc_sensorless_nucleo_G4_B.Gain *
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_k[0];

          /* UnitDelay: '<S26>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_n =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_m;

          /* Product: '<S26>/Product1' */
          pmsm_foc_sensorless_nucleo_G4_B.Product1_j =
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_k[1] *
            pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_n;

          /* Sum: '<S26>/Add1' */
          pmsm_foc_sensorless_nucleo_G4_B.Add1_f =
            pmsm_foc_sensorless_nucleo_G4_B.Product_ik +
            pmsm_foc_sensorless_nucleo_G4_B.Product1_j;

          /* Signum: '<S29>/Sign' */
          ADvoltage = pmsm_foc_sensorless_nucleo_G4_B.Sum2;
          if (rtIsNaNF(ADvoltage)) {
            /* Signum: '<S29>/Sign' */
            pmsm_foc_sensorless_nucleo_G4_B.Sign = (rtNaNF);
          } else if (ADvoltage < 0.0F) {
            /* Signum: '<S29>/Sign' */
            pmsm_foc_sensorless_nucleo_G4_B.Sign = -1.0F;
          } else {
            /* Signum: '<S29>/Sign' */
            pmsm_foc_sensorless_nucleo_G4_B.Sign = (real32_T)(ADvoltage > 0.0F);
          }

          /* End of Signum: '<S29>/Sign' */

          /* Gain: '<S29>/Eta' */
          y_tmp =
            pmsm_foc_sensorless_nucleo_G4_P.SlidingModeObserver_CurrentObse;
          Bias = (real32_T)y_tmp;

          /* Gain: '<S29>/Eta' */
          pmsm_foc_sensorless_nucleo_G4_B.Eta = Bias *
            pmsm_foc_sensorless_nucleo_G4_B.Sign;

          /* Sum: '<S29>/Sum' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum_c =
            pmsm_foc_sensorless_nucleo_G4_B.Delay5[0] -
            pmsm_foc_sensorless_nucleo_G4_B.Sum4;

          /* Gain: '<S29>/b' */
          pmsm_foc_sensorless_nucleo_G4_B.b =
            pmsm_foc_sensorless_nucleo_G4_P.b_Gain *
            pmsm_foc_sensorless_nucleo_G4_B.Sum_c;

          /* Gain: '<S29>/a' */
          pmsm_foc_sensorless_nucleo_G4_B.a_n =
            pmsm_foc_sensorless_nucleo_G4_P.a_Gain_a *
            pmsm_foc_sensorless_nucleo_G4_B.Delay_b;

          /* Sum: '<S29>/Sum1' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum1_n =
            (pmsm_foc_sensorless_nucleo_G4_B.b -
             pmsm_foc_sensorless_nucleo_G4_B.Eta) +
            pmsm_foc_sensorless_nucleo_G4_B.a_n;

          /* Signum: '<S30>/Sign' */
          ADvoltage = pmsm_foc_sensorless_nucleo_G4_B.Sum2_e;
          if (rtIsNaNF(ADvoltage)) {
            /* Signum: '<S30>/Sign' */
            pmsm_foc_sensorless_nucleo_G4_B.Sign_b = (rtNaNF);
          } else if (ADvoltage < 0.0F) {
            /* Signum: '<S30>/Sign' */
            pmsm_foc_sensorless_nucleo_G4_B.Sign_b = -1.0F;
          } else {
            /* Signum: '<S30>/Sign' */
            pmsm_foc_sensorless_nucleo_G4_B.Sign_b = (real32_T)(ADvoltage > 0.0F);
          }

          /* End of Signum: '<S30>/Sign' */

          /* Gain: '<S30>/Eta' */
          pmsm_foc_sensorless_nucleo_G4_B.Eta_h = Bias *
            pmsm_foc_sensorless_nucleo_G4_B.Sign_b;

          /* Sum: '<S30>/Sum' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum_l =
            pmsm_foc_sensorless_nucleo_G4_B.Delay5[1] -
            pmsm_foc_sensorless_nucleo_G4_B.Sum4_d;

          /* Gain: '<S30>/b' */
          pmsm_foc_sensorless_nucleo_G4_B.b_j =
            pmsm_foc_sensorless_nucleo_G4_P.b_Gain_g *
            pmsm_foc_sensorless_nucleo_G4_B.Sum_l;

          /* Gain: '<S30>/a' */
          pmsm_foc_sensorless_nucleo_G4_B.a_k =
            pmsm_foc_sensorless_nucleo_G4_P.a_Gain_g *
            pmsm_foc_sensorless_nucleo_G4_B.Delay_f;

          /* Sum: '<S30>/Sum1' */
          pmsm_foc_sensorless_nucleo_G4_B.Sum1_m =
            (pmsm_foc_sensorless_nucleo_G4_B.b_j -
             pmsm_foc_sensorless_nucleo_G4_B.Eta_h) +
            pmsm_foc_sensorless_nucleo_G4_B.a_k;

          /* Gain: '<S34>/PositionToCount' */
          pmsm_foc_sensorless_nucleo_G4_B.PositionToCount = (uint32_T)
            (pmsm_foc_sensorless_nucleo_G4_P.PositionToCount_Gain *
             pmsm_foc_sensorless_nucleo_G4_B.Switch_o3);

          /* Delay: '<S34>/Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.Delay =
            pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_a[pmsm_foc_sensorless_nucle_DWork.CircBufIdx];

          /* Sum: '<S34>/SpeedCount' */
          pmsm_foc_sensorless_nucleo_G4_B.SpeedCount = (int32_T)
            pmsm_foc_sensorless_nucleo_G4_B.PositionToCount - (int32_T)
            pmsm_foc_sensorless_nucleo_G4_B.Delay;

          /* DataTypeConversion: '<S51>/DTC' */
          pmsm_foc_sensorless_nucleo_G4_B.DTC = (real32_T)
            pmsm_foc_sensorless_nucleo_G4_B.SpeedCount;

          /* Gain: '<S34>/SpeedGain' */
          pmsm_foc_sensorless_nucleo_G4_B.SpeedGain =
            pmsm_foc_sensorless_nucleo_G4_P.SpeedGain_Gain *
            pmsm_foc_sensorless_nucleo_G4_B.DTC;

          /* Switch: '<S33>/Switch1' incorporates:
           *  Constant: '<S33>/UseInputPort'
           */
          if (pmsm_foc_sensorless_nucleo_G4_P.UseInputPort_Value_p0 >
              pmsm_foc_sensorless_nucleo_G4_P.Switch1_Threshold_a) {
            /* Sum: '<S33>/Sum' incorporates:
             *  Constant: '<S33>/One'
             *  Constant: '<S33>/a'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Sum_bn =
              pmsm_foc_sensorless_nucleo_G4_P.One_Value_e -
              pmsm_foc_sensorless_nucleo_G4_P.a_Value_i2;

            /* Switch: '<S33>/Switch1' incorporates:
             *  Constant: '<S33>/a'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_d[0] =
              pmsm_foc_sensorless_nucleo_G4_P.a_Value_i2;
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_d[1] =
              pmsm_foc_sensorless_nucleo_G4_B.Sum_bn;
          } else {
            /* Switch: '<S33>/Switch1' incorporates:
             *  Constant: '<S33>/FilterConstant'
             *  Constant: '<S33>/OneMinusFilterConstant'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_d[0] =
              pmsm_foc_sensorless_nucleo_G4_P.FilterConstant_Value_o;
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_d[1] =
              pmsm_foc_sensorless_nucleo_G4_P.OneMinusFilterConstant_Value_n;
          }

          /* End of Switch: '<S33>/Switch1' */

          /* Product: '<S49>/Product' */
          pmsm_foc_sensorless_nucleo_G4_B.Product_m =
            pmsm_foc_sensorless_nucleo_G4_B.SpeedGain *
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_d[0];

          /* UnitDelay: '<S49>/Unit Delay' */
          pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_i =
            pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bl;

          /* Product: '<S49>/Product1' */
          pmsm_foc_sensorless_nucleo_G4_B.Product1_l2 =
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_d[1] *
            pmsm_foc_sensorless_nucleo_G4_B.UnitDelay_i;

          /* Sum: '<S49>/Add1' */
          pmsm_foc_sensorless_nucleo_G4_B.Add1_g =
            pmsm_foc_sensorless_nucleo_G4_B.Product_m +
            pmsm_foc_sensorless_nucleo_G4_B.Product1_l2;

          /* DeadZone: '<S133>/DeadZone' */
          if (pmsm_foc_sensorless_nucleo_G4_B.Sum_o >
              pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_b) {
            /* DeadZone: '<S133>/DeadZone' */
            pmsm_foc_sensorless_nucleo_G4_B.DeadZone =
              pmsm_foc_sensorless_nucleo_G4_B.Sum_o -
              pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_b;
          } else if (pmsm_foc_sensorless_nucleo_G4_B.Sum_o >=
                     pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_f)
          {
            /* DeadZone: '<S133>/DeadZone' */
            pmsm_foc_sensorless_nucleo_G4_B.DeadZone = 0.0F;
          } else {
            /* DeadZone: '<S133>/DeadZone' */
            pmsm_foc_sensorless_nucleo_G4_B.DeadZone =
              pmsm_foc_sensorless_nucleo_G4_B.Sum_o -
              pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_f;
          }

          /* End of DeadZone: '<S133>/DeadZone' */

          /* RelationalOperator: '<S131>/Relational Operator' incorporates:
           *  Constant: '<S131>/Clamping_zero'
           */
          pmsm_foc_sensorless_nucleo_G4_B.RelationalOperator =
            (pmsm_foc_sensorless_nucleo_G4_P.Clamping_zero_Value !=
             pmsm_foc_sensorless_nucleo_G4_B.DeadZone);

          /* RelationalOperator: '<S131>/fix for DT propagation issue' incorporates:
           *  Constant: '<S131>/Clamping_zero'
           */
          pmsm_foc_sensorless_nucleo_G4_B.fixforDTpropagationissue =
            (pmsm_foc_sensorless_nucleo_G4_B.DeadZone >
             pmsm_foc_sensorless_nucleo_G4_P.Clamping_zero_Value);

          /* Switch: '<S131>/Switch1' */
          if (pmsm_foc_sensorless_nucleo_G4_B.fixforDTpropagationissue) {
            /* Switch: '<S131>/Switch1' incorporates:
             *  Constant: '<S131>/Constant'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_dl =
              pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_l;
          } else {
            /* Switch: '<S131>/Switch1' incorporates:
             *  Constant: '<S131>/Constant2'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_dl =
              pmsm_foc_sensorless_nucleo_G4_P.Constant2_Value_i;
          }

          /* End of Switch: '<S131>/Switch1' */

          /* Product: '<S138>/IProd Out' incorporates:
           *  Constant: '<S69>/Ki'
           */
          pmsm_foc_sensorless_nucleo_G4_B.IProdOut =
            pmsm_foc_sensorless_nucleo_G4_B.Sum_b *
            pmsm_foc_sensorless_nucleo_G4_P.Ki_Value;

          /* RelationalOperator: '<S131>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S131>/Clamping_zero'
           */
          pmsm_foc_sensorless_nucleo_G4_B.fixforDTpropagationissue1 =
            (pmsm_foc_sensorless_nucleo_G4_B.IProdOut >
             pmsm_foc_sensorless_nucleo_G4_P.Clamping_zero_Value);

          /* Switch: '<S131>/Switch2' */
          if (pmsm_foc_sensorless_nucleo_G4_B.fixforDTpropagationissue1) {
            /* Switch: '<S131>/Switch2' incorporates:
             *  Constant: '<S131>/Constant3'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch2_g =
              pmsm_foc_sensorless_nucleo_G4_P.Constant3_Value_m;
          } else {
            /* Switch: '<S131>/Switch2' incorporates:
             *  Constant: '<S131>/Constant4'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch2_g =
              pmsm_foc_sensorless_nucleo_G4_P.Constant4_Value;
          }

          /* End of Switch: '<S131>/Switch2' */

          /* RelationalOperator: '<S131>/Equal1' */
          pmsm_foc_sensorless_nucleo_G4_B.Equal1 =
            (pmsm_foc_sensorless_nucleo_G4_B.Switch1_dl ==
             pmsm_foc_sensorless_nucleo_G4_B.Switch2_g);

          /* Logic: '<S131>/AND3' */
          pmsm_foc_sensorless_nucleo_G4_B.AND3 =
            (pmsm_foc_sensorless_nucleo_G4_B.RelationalOperator &&
             pmsm_foc_sensorless_nucleo_G4_B.Equal1);

          /* Switch: '<S131>/Switch' */
          if (pmsm_foc_sensorless_nucleo_G4_B.AND3) {
            /* Switch: '<S131>/Switch' incorporates:
             *  Constant: '<S131>/Constant1'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_g =
              pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_k;
          } else {
            /* Switch: '<S131>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_g =
              pmsm_foc_sensorless_nucleo_G4_B.IProdOut;
          }

          /* End of Switch: '<S131>/Switch' */

          /* DeadZone: '<S186>/DeadZone' */
          if (pmsm_foc_sensorless_nucleo_G4_B.Sum_i >
              pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_e) {
            /* DeadZone: '<S186>/DeadZone' */
            pmsm_foc_sensorless_nucleo_G4_B.DeadZone_h =
              pmsm_foc_sensorless_nucleo_G4_B.Sum_i -
              pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiw_e;
          } else if (pmsm_foc_sensorless_nucleo_G4_B.Sum_i >=
                     pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiwin)
          {
            /* DeadZone: '<S186>/DeadZone' */
            pmsm_foc_sensorless_nucleo_G4_B.DeadZone_h = 0.0F;
          } else {
            /* DeadZone: '<S186>/DeadZone' */
            pmsm_foc_sensorless_nucleo_G4_B.DeadZone_h =
              pmsm_foc_sensorless_nucleo_G4_B.Sum_i -
              pmsm_foc_sensorless_nucleo_G4_P.DiscretePIControllerwithantiwin;
          }

          /* End of DeadZone: '<S186>/DeadZone' */

          /* RelationalOperator: '<S184>/Relational Operator' incorporates:
           *  Constant: '<S184>/Clamping_zero'
           */
          pmsm_foc_sensorless_nucleo_G4_B.RelationalOperator_l =
            (pmsm_foc_sensorless_nucleo_G4_P.Clamping_zero_Value_k !=
             pmsm_foc_sensorless_nucleo_G4_B.DeadZone_h);

          /* RelationalOperator: '<S184>/fix for DT propagation issue' incorporates:
           *  Constant: '<S184>/Clamping_zero'
           */
          pmsm_foc_sensorless_nucleo_G4_B.fixforDTpropagationissue_i =
            (pmsm_foc_sensorless_nucleo_G4_B.DeadZone_h >
             pmsm_foc_sensorless_nucleo_G4_P.Clamping_zero_Value_k);

          /* Switch: '<S184>/Switch1' */
          if (pmsm_foc_sensorless_nucleo_G4_B.fixforDTpropagationissue_i) {
            /* Switch: '<S184>/Switch1' incorporates:
             *  Constant: '<S184>/Constant'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_c =
              pmsm_foc_sensorless_nucleo_G4_P.Constant_Value_jm;
          } else {
            /* Switch: '<S184>/Switch1' incorporates:
             *  Constant: '<S184>/Constant2'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch1_c =
              pmsm_foc_sensorless_nucleo_G4_P.Constant2_Value_e;
          }

          /* End of Switch: '<S184>/Switch1' */

          /* Product: '<S191>/IProd Out' incorporates:
           *  Constant: '<S69>/Ki'
           */
          pmsm_foc_sensorless_nucleo_G4_B.IProdOut_b =
            pmsm_foc_sensorless_nucleo_G4_B.Sum_k *
            pmsm_foc_sensorless_nucleo_G4_P.Ki_Value;

          /* RelationalOperator: '<S184>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S184>/Clamping_zero'
           */
          pmsm_foc_sensorless_nucleo_G4_B.fixforDTpropagationissue1_m =
            (pmsm_foc_sensorless_nucleo_G4_B.IProdOut_b >
             pmsm_foc_sensorless_nucleo_G4_P.Clamping_zero_Value_k);

          /* Switch: '<S184>/Switch2' */
          if (pmsm_foc_sensorless_nucleo_G4_B.fixforDTpropagationissue1_m) {
            /* Switch: '<S184>/Switch2' incorporates:
             *  Constant: '<S184>/Constant3'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch2_m =
              pmsm_foc_sensorless_nucleo_G4_P.Constant3_Value_h;
          } else {
            /* Switch: '<S184>/Switch2' incorporates:
             *  Constant: '<S184>/Constant4'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch2_m =
              pmsm_foc_sensorless_nucleo_G4_P.Constant4_Value_m;
          }

          /* End of Switch: '<S184>/Switch2' */

          /* RelationalOperator: '<S184>/Equal1' */
          pmsm_foc_sensorless_nucleo_G4_B.Equal1_n =
            (pmsm_foc_sensorless_nucleo_G4_B.Switch1_c ==
             pmsm_foc_sensorless_nucleo_G4_B.Switch2_m);

          /* Logic: '<S184>/AND3' */
          pmsm_foc_sensorless_nucleo_G4_B.AND3_m =
            (pmsm_foc_sensorless_nucleo_G4_B.RelationalOperator_l &&
             pmsm_foc_sensorless_nucleo_G4_B.Equal1_n);

          /* Switch: '<S184>/Switch' */
          if (pmsm_foc_sensorless_nucleo_G4_B.AND3_m) {
            /* Switch: '<S184>/Switch' incorporates:
             *  Constant: '<S184>/Constant1'
             */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_e =
              pmsm_foc_sensorless_nucleo_G4_P.Constant1_Value_c;
          } else {
            /* Switch: '<S184>/Switch' */
            pmsm_foc_sensorless_nucleo_G4_B.Switch_e =
              pmsm_foc_sensorless_nucleo_G4_B.IProdOut_b;
          }

          /* End of Switch: '<S184>/Switch' */

          /* SignalConversion generated from: '<S2>/Delay5' */
          pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[0] =
            pmsm_foc_sensorless_nucleo_G4_B.algDD_o1_a;
          pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[1] =
            pmsm_foc_sensorless_nucleo_G4_B.algDD_o2_j;
          pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[2] =
            pmsm_foc_sensorless_nucleo_G4_B.Kalpha;
          pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[3] =
            pmsm_foc_sensorless_nucleo_G4_B.Kbeta;

          /* Update for UnitDelay: '<S39>/Unit Delay1' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay1_DSTATE =
            pmsm_foc_sensorless_nucleo_G4_B.Eta;

          /* Update for UnitDelay: '<S39>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE =
            pmsm_foc_sensorless_nucleo_G4_B.Sum2;

          /* Update for Delay: '<S2>/Delay5' */
          pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[0] =
            pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[0];
          pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[1] =
            pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[1];
          pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[2] =
            pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[2];
          pmsm_foc_sensorless_nucle_DWork.Delay5_DSTATE[3] =
            pmsm_foc_sensorless_nucleo_G4_B.TmpSignalConversionAtDelay5Inpo[3];

          /* Update for Delay: '<S29>/Delay' */
          pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE =
            pmsm_foc_sensorless_nucleo_G4_B.Sum1_n;

          /* Update for Delay: '<S39>/Delay1' */
          pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE =
            pmsm_foc_sensorless_nucleo_G4_B.Sum4;

          /* Update for UnitDelay: '<S43>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_b =
            pmsm_foc_sensorless_nucleo_G4_B.Add1_o;

          /* Update for UnitDelay: '<S40>/Unit Delay1' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay1_DSTATE_m =
            pmsm_foc_sensorless_nucleo_G4_B.Eta_h;

          /* Update for UnitDelay: '<S40>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_p =
            pmsm_foc_sensorless_nucleo_G4_B.Sum2_e;

          /* Update for Delay: '<S30>/Delay' */
          pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_h =
            pmsm_foc_sensorless_nucleo_G4_B.Sum1_m;

          /* Update for Delay: '<S40>/Delay1' */
          pmsm_foc_sensorless_nucle_DWork.Delay1_DSTATE_e =
            pmsm_foc_sensorless_nucleo_G4_B.Sum4_d;

          /* Update for UnitDelay: '<S46>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_d =
            pmsm_foc_sensorless_nucleo_G4_B.Add1_p;

          /* Update for Delay: '<S27>/Delay' */
          pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_p =
            pmsm_foc_sensorless_nucleo_G4_B.Add1_g;

          /* Update for UnitDelay: '<S61>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bp =
            pmsm_foc_sensorless_nucleo_G4_B.Add1_m;

          /* Update for UnitDelay: '<S90>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bv =
            pmsm_foc_sensorless_nucleo_G4_B.Switch_d;

          /* Update for DiscreteIntegrator: '<S194>/Integrator' */
          pmsm_foc_sensorless_nucle_DWork.Integrator_IC_LOADING = 0U;
          pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE +=
            pmsm_foc_sensorless_nucleo_G4_P.Integrator_gainval *
            pmsm_foc_sensorless_nucleo_G4_B.Switch_e;
          Integrator_PrevResetState_tmp = (int8_T)
            pmsm_foc_sensorless_nucleo_G4_B.LogicalOperator_n;
          pmsm_foc_sensorless_nucle_DWork.Integrator_PrevResetState =
            Integrator_PrevResetState_tmp;

          /* Update for UnitDelay: '<S89>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_c =
            pmsm_foc_sensorless_nucleo_G4_B.Switch_o;

          /* Update for DiscreteIntegrator: '<S141>/Integrator' */
          pmsm_foc_sensorless_nucle_DWork.Integrator_IC_LOADING_o = 0U;
          pmsm_foc_sensorless_nucle_DWork.Integrator_DSTATE_l +=
            pmsm_foc_sensorless_nucleo_G4_P.Integrator_gainval_p *
            pmsm_foc_sensorless_nucleo_G4_B.Switch_g;
          pmsm_foc_sensorless_nucle_DWork.Integrator_PrevResetState_i =
            Integrator_PrevResetState_tmp;

          /* Update for UnitDelay: '<S26>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_m =
            pmsm_foc_sensorless_nucleo_G4_B.Add1_f;

          /* Update for Delay: '<S34>/Delay' */
          pmsm_foc_sensorless_nucle_DWork.Delay_DSTATE_a[pmsm_foc_sensorless_nucle_DWork.CircBufIdx]
            = pmsm_foc_sensorless_nucleo_G4_B.PositionToCount;
          if (pmsm_foc_sensorless_nucle_DWork.CircBufIdx < 118U) {
            pmsm_foc_sensorless_nucle_DWork.CircBufIdx++;
          } else {
            pmsm_foc_sensorless_nucle_DWork.CircBufIdx = 0U;
          }

          /* End of Update for Delay: '<S34>/Delay' */

          /* Update for UnitDelay: '<S49>/Unit Delay' */
          pmsm_foc_sensorless_nucle_DWork.UnitDelay_DSTATE_bl =
            pmsm_foc_sensorless_nucleo_G4_B.Add1_g;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

        /* RateTransition: '<Root>/RT1' incorporates:
         *  Gain: '<S54>/OP_Gain*R_shunt1'
         */
        pmsm_foc_sensorless_nucle_DWork.RT1_Buffer
          [(pmsm_foc_sensorless_nucle_DWork.RT1_semaphoreTaken == 0) << 1] =
          pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[0];
        pmsm_foc_sensorless_nucle_DWork.RT1_Buffer[1 +
          ((pmsm_foc_sensorless_nucle_DWork.RT1_semaphoreTaken == 0) << 1)] =
          pmsm_foc_sensorless_nucleo_G4_B.OP_GainR_shunt1[1];
        pmsm_foc_sensorless_nucle_DWork.RT1_ActiveBufIdx = (int8_T)
          (pmsm_foc_sensorless_nucle_DWork.RT1_semaphoreTaken == 0);
      }
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void pmsm_foc_sensorless_nucleo_G4_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
