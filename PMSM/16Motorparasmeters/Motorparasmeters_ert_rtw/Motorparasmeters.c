/*
 * File: Motorparasmeters.c
 *
 * Code generated for Simulink model 'Motorparasmeters'.
 *
 * Model version                  : 8.24
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Nov 28 16:29:34 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Motorparasmeters.h"
#include "Motorparasmeters_types.h"
#include "Motorparasmeters_private.h"
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
BlockIO_Motorparasmeters Motorparasmeters_B;

/* Block states (default storage) */
D_Work_Motorparasmeters Motorparasmeters_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_Motorparasmeter Motorparasmeters_PrevZCSigState;

/* Real-time model */
static RT_MODEL_Motorparasmeters Motorparasmeters_M_;
RT_MODEL_Motorparasmeters *const Motorparasmeters_M = &Motorparasmeters_M_;

/* Forward declaration for local functions */
static void Motorparasmete_SystemCore_setup(stm32cube_blocks_AnalogInput_Mo *obj);
static void Motorparasm_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Moto *obj);

/* Forward declaration for local functions */
static void Motorparasm_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_Moto *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Motorparasmeters_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Motorparasmeters_M, 1));
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
  (Motorparasmeters_M->Timing.TaskCounters.TID[1])++;
  if ((Motorparasmeters_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    Motorparasmeters_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void Motorparasmete_SystemCore_setup(stm32cube_blocks_AnalogInput_Mo *obj)
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

static void Motorparasm_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Moto *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S214>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S214>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S214>/PWM Output' */
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

static void Motorparasm_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_Moto *obj)
{
  uint8_T * txBufferPtr;
  UART_Type_T b;
  txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);

  /* Start for MATLABSystem: '<S221>/UART//USART Write' incorporates:
   *  MATLABSystem: '<S220>/UART//USART Write'
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
void Motorparasmeters_step0(void)      /* Sample time: [0.001s, 0.0s] */
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
  Motorparasmeters_B.DigitalPortRead = tmp;

  /* UnitDelay: '<S1>/Unit Delay' */
  Motorparasmeters_B.UnitDelay_f = Motorparasmeters_DWork.UnitDelay_DSTATE_k;

  /* Logic: '<S1>/NOT2' */
  Motorparasmeters_B.NOT2 = !Motorparasmeters_B.UnitDelay_f;

  /* Logic: '<S1>/AND' */
  Motorparasmeters_B.AND = (Motorparasmeters_B.DigitalPortRead &&
    Motorparasmeters_B.NOT2);

  /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (Motorparasmeters_B.AND) {
    /* UnitDelay: '<S8>/Unit Delay' */
    Motorparasmeters_B.UnitDelay_a = Motorparasmeters_DWork.UnitDelay_DSTATE_a;

    /* Logic: '<S8>/NOT' */
    Motorparasmeters_B.NOT_n = !Motorparasmeters_B.UnitDelay_a;

    /* Update for UnitDelay: '<S8>/Unit Delay' */
    Motorparasmeters_DWork.UnitDelay_DSTATE_a = Motorparasmeters_B.NOT_n;
  }

  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  Motorparasmeters_DWork.Enable = Motorparasmeters_B.UnitDelay_a;

  /* RateTransition: '<Root>/RT' */
  Motorparasmeters_B.RT_n = Motorparasmeters_B.Gain;

  /* Assignment: '<S6>/Assignment' incorporates:
   *  Constant: '<S6>/Constant'
   */
  Motorparasmeters_B.Assignment[0] = Motorparasmeters_P.Constant_Value_nt[0];
  Motorparasmeters_B.Assignment[1] = Motorparasmeters_P.Constant_Value_nt[1];
  Motorparasmeters_B.Assignment[2] = Motorparasmeters_P.Constant_Value_nt[2];

  /* Assignment: '<S6>/Assignment' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  Motorparasmeters_B.Assignment[Motorparasmeters_P.Constant2_Value_nq] =
    Motorparasmeters_B.RT_n;

  /* RateTransition: '<Root>/RT1' */
  Motorparasmeters_DWork.RT1_semaphoreTaken =
    Motorparasmeters_DWork.RT1_ActiveBufIdx;
  tmp_0 = Motorparasmeters_DWork.RT1_semaphoreTaken << 1;

  /* RateTransition: '<Root>/RT1' */
  Motorparasmeters_B.RT1[0] = Motorparasmeters_DWork.RT1_Buffer[tmp_0];
  Motorparasmeters_B.RT1[1] = Motorparasmeters_DWork.RT1_Buffer[tmp_0 + 1];

  /* Assignment: '<S6>/Assignment1' */
  Motorparasmeters_B.Assignment1[0] = Motorparasmeters_B.Assignment[0];
  Motorparasmeters_B.Assignment1[1] = Motorparasmeters_B.Assignment[1];
  Motorparasmeters_B.Assignment1[2] = Motorparasmeters_B.Assignment[2];

  /* Assignment: '<S6>/Assignment1' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  Motorparasmeters_B.Assignment1[Motorparasmeters_P.Constant3_Value_e] =
    Motorparasmeters_B.RT1[0];

  /* Assignment: '<S6>/Assignment2' */
  Motorparasmeters_B.Assignment2[0] = Motorparasmeters_B.Assignment1[0];
  Motorparasmeters_B.Assignment2[1] = Motorparasmeters_B.Assignment1[1];
  Motorparasmeters_B.Assignment2[2] = Motorparasmeters_B.Assignment1[2];

  /* Assignment: '<S6>/Assignment2' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  Motorparasmeters_B.Assignment2[Motorparasmeters_P.Constant1_Value_d] =
    Motorparasmeters_B.RT1[1];

  /* MATLABSystem: '<S220>/UART//USART Write' incorporates:
   *  Constant: '<S220>/Constant4'
   */
  pinReadLoc = 3U;
  if (Motorparasmeters_P.Constant4_Value_b < 3U) {
    pinReadLoc = Motorparasmeters_P.Constant4_Value_b;
  }

  uartWriteData[0] = Motorparasmeters_B.Assignment2[0];
  uartWriteData[1] = Motorparasmeters_B.Assignment2[1];
  uartWriteData[2] = Motorparasmeters_B.Assignment2[2];

  /* Start for MATLABSystem: '<S220>/UART//USART Write' */
  tmp_0 = (int32_T)pinReadLoc;
  tmp_0 = (int32_T)((uint32_T)tmp_0 << 2);

  /* MATLABSystem: '<S220>/UART//USART Write' */
  status = MW_LPUART_TransmitUsingInterrupt
    (Motorparasmeters_DWork.obj.UARTHandle, &uartWriteData[0], (uint32_T)tmp_0,
     0U, &sentLength);

  /* MATLABSystem: '<S220>/UART//USART Write' */
  Motorparasmeters_B.UARTUSARTWrite = status;

  /* Logic: '<S220>/NOT' */
  Motorparasmeters_B.NOT = (Motorparasmeters_B.UARTUSARTWrite == 0);

  /* Outputs for Enabled SubSystem: '<S220>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S221>/Enable'
   */
  if (Motorparasmeters_B.NOT) {
    /* MATLABSystem: '<S221>/UART//USART Write' incorporates:
     *  Constant: '<S221>/Constant1'
     *  Constant: '<S221>/Constant2'
     * */
    pinReadLoc = 4U;
    if (Motorparasmeters_P.Constant2_Value_n < 4U) {
      pinReadLoc = Motorparasmeters_P.Constant2_Value_n;
    }

    uartWriteData_0[0] = Motorparasmeters_P.Constant1_Value_f[0];
    uartWriteData_0[1] = Motorparasmeters_P.Constant1_Value_f[1];
    uartWriteData_0[2] = Motorparasmeters_P.Constant1_Value_f[2];
    uartWriteData_0[3] = Motorparasmeters_P.Constant1_Value_f[3];
    MW_LPUART_TransmitUsingInterrupt(Motorparasmeters_DWork.obj_e.UARTHandle,
      &uartWriteData_0[0], pinReadLoc, 0U, &sentLength);

    /* End of MATLABSystem: '<S221>/UART//USART Write' */
  }

  /* End of Outputs for SubSystem: '<S220>/Enabled Subsystem' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  Motorparasmeters_DWork.UnitDelay_DSTATE_k = Motorparasmeters_B.DigitalPortRead;
}

/* Model step function for TID1 */
void Motorparasmeters_step1(void)      /* Sample time: [0.1s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  int32_T c;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  Motorparasmeters_B.LED = (Motorparasmeters_DWork.clockTickCounter <
    Motorparasmeters_P.PulseGenerator_Duty) &&
    (Motorparasmeters_DWork.clockTickCounter >= 0) ?
    Motorparasmeters_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  if (Motorparasmeters_DWork.clockTickCounter >=
      Motorparasmeters_P.PulseGenerator_Period - 1.0) {
    Motorparasmeters_DWork.clockTickCounter = 0;
  } else {
    Motorparasmeters_DWork.clockTickCounter++;
  }

  /* MATLABSystem: '<S219>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (Motorparasmeters_B.LED != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S219>/Digital Port Write' */
}

/* Model initialize function */
void Motorparasmeters_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Motorparasmeters_M, 0,
                sizeof(RT_MODEL_Motorparasmeters));

  /* block I/O */
  (void) memset(((void *) &Motorparasmeters_B), 0,
                sizeof(BlockIO_Motorparasmeters));

  {
    Motorparasmeters_B.LED = 0.0;
    Motorparasmeters_B.RT_n = 0.0F;
    Motorparasmeters_B.Assignment[0] = 0.0F;
    Motorparasmeters_B.Assignment[1] = 0.0F;
    Motorparasmeters_B.Assignment[2] = 0.0F;
    Motorparasmeters_B.RT1[0] = 0.0F;
    Motorparasmeters_B.RT1[1] = 0.0F;
    Motorparasmeters_B.Assignment1[0] = 0.0F;
    Motorparasmeters_B.Assignment1[1] = 0.0F;
    Motorparasmeters_B.Assignment1[2] = 0.0F;
    Motorparasmeters_B.Assignment2[0] = 0.0F;
    Motorparasmeters_B.Assignment2[1] = 0.0F;
    Motorparasmeters_B.Assignment2[2] = 0.0F;
    Motorparasmeters_B.ADvoltage[0] = 0.0F;
    Motorparasmeters_B.ADvoltage[1] = 0.0F;
    Motorparasmeters_B.OP_GainR_shunt[0] = 0.0F;
    Motorparasmeters_B.OP_GainR_shunt[1] = 0.0F;
    Motorparasmeters_B.OP_GainR_shunt1[0] = 0.0F;
    Motorparasmeters_B.OP_GainR_shunt1[1] = 0.0F;
    Motorparasmeters_B.Kalpha = 0.0F;
    Motorparasmeters_B.Kbeta = 0.0F;
    Motorparasmeters_B.UnitDelay1 = 0.0F;
    Motorparasmeters_B.UnitDelay = 0.0F;
    Motorparasmeters_B.a = 0.0F;
    Motorparasmeters_B.Delay5[0] = 0.0F;
    Motorparasmeters_B.Delay5[1] = 0.0F;
    Motorparasmeters_B.Delay5[2] = 0.0F;
    Motorparasmeters_B.Delay5[3] = 0.0F;
    Motorparasmeters_B.Delay_b = 0.0F;
    Motorparasmeters_B.Sum2 = 0.0F;
    Motorparasmeters_B.Sum3 = 0.0F;
    Motorparasmeters_B.b_invg = 0.0F;
    Motorparasmeters_B.Delay1 = 0.0F;
    Motorparasmeters_B.Sum4 = 0.0F;
    Motorparasmeters_B.Switch1[0] = 0.0F;
    Motorparasmeters_B.Switch1[1] = 0.0F;
    Motorparasmeters_B.Product = 0.0F;
    Motorparasmeters_B.UnitDelay_e = 0.0F;
    Motorparasmeters_B.Product1 = 0.0F;
    Motorparasmeters_B.Add1_o = 0.0F;
    Motorparasmeters_B.UnitDelay1_e = 0.0F;
    Motorparasmeters_B.UnitDelay_c = 0.0F;
    Motorparasmeters_B.a_c = 0.0F;
    Motorparasmeters_B.Delay_f = 0.0F;
    Motorparasmeters_B.Sum2_e = 0.0F;
    Motorparasmeters_B.Sum3_m = 0.0F;
    Motorparasmeters_B.b_invg_d = 0.0F;
    Motorparasmeters_B.Delay1_f = 0.0F;
    Motorparasmeters_B.Sum4_d = 0.0F;
    Motorparasmeters_B.Switch1_o[0] = 0.0F;
    Motorparasmeters_B.Switch1_o[1] = 0.0F;
    Motorparasmeters_B.Product_b = 0.0F;
    Motorparasmeters_B.UnitDelay_m = 0.0F;
    Motorparasmeters_B.Product1_l = 0.0F;
    Motorparasmeters_B.Add1_p = 0.0F;
    Motorparasmeters_B.Merge = 0.0F;
    Motorparasmeters_B.Merge1 = 0.0F;
    Motorparasmeters_B.Delay_fn = 0.0F;
    Motorparasmeters_B.PhaseDelay = 0.0F;
    Motorparasmeters_B.Merge_a = 0.0F;
    Motorparasmeters_B.scaleIn = 0.0F;
    Motorparasmeters_B.UnitDelay_h = 0.0F;
    Motorparasmeters_B.Switch = 0.0F;
    Motorparasmeters_B.convert_pu = 0.0F;
    Motorparasmeters_B.Merge_e = 0.0F;
    Motorparasmeters_B.indexing = 0.0F;
    Motorparasmeters_B.Lookup[0] = 0.0F;
    Motorparasmeters_B.Lookup[1] = 0.0F;
    Motorparasmeters_B.Lookup[2] = 0.0F;
    Motorparasmeters_B.Lookup[3] = 0.0F;
    Motorparasmeters_B.Sum3_i = 0.0F;
    Motorparasmeters_B.DataTypeConversion1 = 0.0F;
    Motorparasmeters_B.Sum2_g = 0.0F;
    Motorparasmeters_B.Product_h = 0.0F;
    Motorparasmeters_B.Sum4_h = 0.0F;
    Motorparasmeters_B.Sum5 = 0.0F;
    Motorparasmeters_B.Product1_k = 0.0F;
    Motorparasmeters_B.Sum6 = 0.0F;
    Motorparasmeters_B.Sum_k = 0.0F;
    Motorparasmeters_B.PProdOut = 0.0F;
    Motorparasmeters_B.Vq_OpenLoop = 0.0F;
    Motorparasmeters_B.Integrator = 0.0F;
    Motorparasmeters_B.Sum_i = 0.0F;
    Motorparasmeters_B.Saturation = 0.0F;
    Motorparasmeters_B.Sum_b = 0.0F;
    Motorparasmeters_B.PProdOut_i = 0.0F;
    Motorparasmeters_B.Constant = 0.0F;
    Motorparasmeters_B.Integrator_a = 0.0F;
    Motorparasmeters_B.Sum_o = 0.0F;
    Motorparasmeters_B.Saturation_h = 0.0F;
    Motorparasmeters_B.Switch_o = 0.0F;
    Motorparasmeters_B.Product_i = 0.0F;
    Motorparasmeters_B.Product_hz = 0.0F;
    Motorparasmeters_B.Product1_n = 0.0F;
    Motorparasmeters_B.Sum1 = 0.0F;
    Motorparasmeters_B.Merge_f[0] = 0.0F;
    Motorparasmeters_B.Merge_f[1] = 0.0F;
    Motorparasmeters_B.Switch4[0] = 0.0F;
    Motorparasmeters_B.Switch4[1] = 0.0F;
    Motorparasmeters_B.Switch4[2] = 0.0F;
    Motorparasmeters_B.Gain2 = 0.0F;
    Motorparasmeters_B.Add1_m = 0.0F;
    Motorparasmeters_B.Gain3 = 0.0F;
    Motorparasmeters_B.Gain = 0.0F;
    Motorparasmeters_B.Sign = 0.0F;
    Motorparasmeters_B.Eta = 0.0F;
    Motorparasmeters_B.Sum_c = 0.0F;
    Motorparasmeters_B.b = 0.0F;
    Motorparasmeters_B.a_n = 0.0F;
    Motorparasmeters_B.Sum1_n = 0.0F;
    Motorparasmeters_B.Sign_b = 0.0F;
    Motorparasmeters_B.Eta_h = 0.0F;
    Motorparasmeters_B.Sum_l = 0.0F;
    Motorparasmeters_B.b_j = 0.0F;
    Motorparasmeters_B.a_k = 0.0F;
    Motorparasmeters_B.Sum1_m = 0.0F;
    Motorparasmeters_B.DTC = 0.0F;
    Motorparasmeters_B.SpeedGain = 0.0F;
    Motorparasmeters_B.Switch1_d[0] = 0.0F;
    Motorparasmeters_B.Switch1_d[1] = 0.0F;
    Motorparasmeters_B.Product_m = 0.0F;
    Motorparasmeters_B.UnitDelay_i = 0.0F;
    Motorparasmeters_B.Product1_l2 = 0.0F;
    Motorparasmeters_B.Add1_g = 0.0F;
    Motorparasmeters_B.DeadZone = 0.0F;
    Motorparasmeters_B.IProdOut = 0.0F;
    Motorparasmeters_B.Switch_g = 0.0F;
    Motorparasmeters_B.DeadZone_h = 0.0F;
    Motorparasmeters_B.IProdOut_b = 0.0F;
    Motorparasmeters_B.Switch_e = 0.0F;
    Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    Motorparasmeters_B.sqrt3_by_two = 0.0F;
    Motorparasmeters_B.one_by_two = 0.0F;
    Motorparasmeters_B.add_c = 0.0F;
    Motorparasmeters_B.Kc = 0.0F;
    Motorparasmeters_B.add_b = 0.0F;
    Motorparasmeters_B.Kb = 0.0F;
    Motorparasmeters_B.Ka = 0.0F;
    Motorparasmeters_B.Min = 0.0F;
    Motorparasmeters_B.Max = 0.0F;
    Motorparasmeters_B.Add = 0.0F;
    Motorparasmeters_B.one_by_two_k = 0.0F;
    Motorparasmeters_B.Add2 = 0.0F;
    Motorparasmeters_B.Add1_k = 0.0F;
    Motorparasmeters_B.Add3 = 0.0F;
    Motorparasmeters_B.Gain_j[0] = 0.0F;
    Motorparasmeters_B.Gain_j[1] = 0.0F;
    Motorparasmeters_B.Gain_j[2] = 0.0F;
    Motorparasmeters_B.Gain_n[0] = 0.0F;
    Motorparasmeters_B.Gain_n[1] = 0.0F;
    Motorparasmeters_B.Gain_n[2] = 0.0F;
    Motorparasmeters_B.Add_c[0] = 0.0F;
    Motorparasmeters_B.Add_c[1] = 0.0F;
    Motorparasmeters_B.Add_c[2] = 0.0F;
    Motorparasmeters_B.Gain1[0] = 0.0F;
    Motorparasmeters_B.Gain1[1] = 0.0F;
    Motorparasmeters_B.Gain1[2] = 0.0F;
    Motorparasmeters_B.Product_c[0] = 0.0F;
    Motorparasmeters_B.Product_c[1] = 0.0F;
    Motorparasmeters_B.SquareRoot = 0.0F;
    Motorparasmeters_B.Switch_k = 0.0F;
    Motorparasmeters_B.Switch_f[0] = 0.0F;
    Motorparasmeters_B.Switch_f[1] = 0.0F;
    Motorparasmeters_B.Switch2 = 0.0F;
    Motorparasmeters_B.Product_mt = 0.0F;
    Motorparasmeters_B.Sum_e = 0.0F;
    Motorparasmeters_B.Product2 = 0.0F;
    Motorparasmeters_B.Merge_an = 0.0F;
    Motorparasmeters_B.Gain_p = 0.0F;
    Motorparasmeters_B.Switch_n = 0.0F;
    Motorparasmeters_B.Switch1_m = 0.0F;
    Motorparasmeters_B.Sqrt = 0.0F;
    Motorparasmeters_B.Gain_i = 0.0F;
    Motorparasmeters_B.Convert_back = 0.0F;
    Motorparasmeters_B.Convert_back_k = 0.0F;
    Motorparasmeters_B.bcos = 0.0F;
    Motorparasmeters_B.asin_f = 0.0F;
    Motorparasmeters_B.sum_Qs = 0.0F;
    Motorparasmeters_B.acos_f = 0.0F;
    Motorparasmeters_B.bsin = 0.0F;
    Motorparasmeters_B.sum_Ds = 0.0F;
    Motorparasmeters_B.Switch_d[0] = 0.0F;
    Motorparasmeters_B.Switch_d[1] = 0.0F;
    Motorparasmeters_B.algDD_o1 = 0.0F;
    Motorparasmeters_B.algDD_o2 = 0.0F;
    Motorparasmeters_B.Unary_Minus = 0.0F;
    Motorparasmeters_B.qcos = 0.0F;
    Motorparasmeters_B.dsin = 0.0F;
    Motorparasmeters_B.sum_beta = 0.0F;
    Motorparasmeters_B.dcos = 0.0F;
    Motorparasmeters_B.qsin = 0.0F;
    Motorparasmeters_B.sum_alpha = 0.0F;
    Motorparasmeters_B.Switch_p[0] = 0.0F;
    Motorparasmeters_B.Switch_p[1] = 0.0F;
    Motorparasmeters_B.algDD_o1_a = 0.0F;
    Motorparasmeters_B.algDD_o2_j = 0.0F;
    Motorparasmeters_B.Unary_Minus_i = 0.0F;
    Motorparasmeters_B.a_plus_2b = 0.0F;
    Motorparasmeters_B.one_by_sqrt3 = 0.0F;
    Motorparasmeters_B.algDD_o1_j = 0.0F;
    Motorparasmeters_B.algDD_o2_e = 0.0F;
    Motorparasmeters_B.Add_g = 0.0F;
    Motorparasmeters_B.DataTypeConversion1_p = 0.0F;
    Motorparasmeters_B.Add1_mo = 0.0F;
    Motorparasmeters_B.Input = 0.0F;
    Motorparasmeters_B.DataStoreRead_j = 0.0F;
    Motorparasmeters_B.Add1_e = 0.0F;
    Motorparasmeters_B.SaturatetomotorcalibSpeedRPM = 0.0F;
    Motorparasmeters_B.scaleOut = 0.0F;
    Motorparasmeters_B.AngleConversion = 0.0F;
    Motorparasmeters_B.Product_b1 = 0.0F;
    Motorparasmeters_B.Product2_d = 0.0F;
    Motorparasmeters_B.Sum1_k = 0.0F;
    Motorparasmeters_B.Product1_li = 0.0F;
    Motorparasmeters_B.Product3 = 0.0F;
    Motorparasmeters_B.Sum2_et = 0.0F;
    Motorparasmeters_B.Switch_o3 = 0.0F;
    Motorparasmeters_B.Atan2 = 0.0F;
    Motorparasmeters_B.Switch_nl = 0.0F;
    Motorparasmeters_B.algDD = 0.0F;
    Motorparasmeters_B.Gain_d = 0.0F;
    Motorparasmeters_B.Switch_kk = 0.0F;
    Motorparasmeters_B.Bias = 0.0F;
    Motorparasmeters_B.Bias_d = 0.0F;
    Motorparasmeters_B.Sum_bn = 0.0F;
    Motorparasmeters_B.Sum_lt = 0.0F;
    Motorparasmeters_B.Sum_d = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&Motorparasmeters_DWork, 0,
                sizeof(D_Work_Motorparasmeters));
  Motorparasmeters_DWork.UnitDelay1_DSTATE = 0.0F;
  Motorparasmeters_DWork.UnitDelay_DSTATE = 0.0F;
  Motorparasmeters_DWork.Delay5_DSTATE[0] = 0.0F;
  Motorparasmeters_DWork.Delay5_DSTATE[1] = 0.0F;
  Motorparasmeters_DWork.Delay5_DSTATE[2] = 0.0F;
  Motorparasmeters_DWork.Delay5_DSTATE[3] = 0.0F;
  Motorparasmeters_DWork.Delay_DSTATE = 0.0F;
  Motorparasmeters_DWork.Delay1_DSTATE = 0.0F;
  Motorparasmeters_DWork.UnitDelay_DSTATE_b = 0.0F;
  Motorparasmeters_DWork.UnitDelay1_DSTATE_m = 0.0F;
  Motorparasmeters_DWork.UnitDelay_DSTATE_p = 0.0F;
  Motorparasmeters_DWork.Delay_DSTATE_h = 0.0F;
  Motorparasmeters_DWork.Delay1_DSTATE_e = 0.0F;
  Motorparasmeters_DWork.UnitDelay_DSTATE_d = 0.0F;
  Motorparasmeters_DWork.Delay_DSTATE_p = 0.0F;
  Motorparasmeters_DWork.UnitDelay_DSTATE_bp = 0.0F;
  Motorparasmeters_DWork.Integrator_DSTATE = 0.0F;
  Motorparasmeters_DWork.Integrator_DSTATE_l = 0.0F;
  Motorparasmeters_DWork.UnitDelay_DSTATE_bl = 0.0F;
  Motorparasmeters_DWork.RT1_Buffer[0] = 0.0F;
  Motorparasmeters_DWork.RT1_Buffer[1] = 0.0F;
  Motorparasmeters_DWork.RT1_Buffer[2] = 0.0F;
  Motorparasmeters_DWork.RT1_Buffer[3] = 0.0F;
  Motorparasmeters_DWork.GlobleopenspeedInt = 0.0F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  Motorparasmeters_DWork.Enable =
    Motorparasmeters_P.DataStoreMemory9_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
  Motorparasmeters_DWork.IaOffset =
    Motorparasmeters_P.DataStoreMemory13_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory14' */
  Motorparasmeters_DWork.IbOffset =
    Motorparasmeters_P.DataStoreMemory14_InitialValue;
  Motorparasmeters_PrevZCSigState.Dir_Sense_Trig_ZCE = POS_ZCSIG;
  Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Motorparasmeters_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE_c = UNINITIALIZED_ZCSIG;
  Motorparasmeters_PrevZCSigState.Delay1_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  Motorparasmeters_DWork.UnitDelay_DSTATE_k =
    Motorparasmeters_P.UnitDelay_InitialCondition_e;

  /* InitializeConditions for RateTransition: '<Root>/RT1' */
  Motorparasmeters_DWork.RT1_Buffer[0] = Motorparasmeters_P.RT1_InitialCondition;
  Motorparasmeters_DWork.RT1_Buffer[1] = Motorparasmeters_P.RT1_InitialCondition;

  /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
  Motorparasmeters_DWork.clockTickCounter = 0;

  /* SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem' */
  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  Motorparasmeters_DWork.UnitDelay_DSTATE_a =
    Motorparasmeters_P.UnitDelay_InitialCondition_lg;

  /* SystemInitialize for UnitDelay: '<S8>/Unit Delay' incorporates:
   *  Outport: '<S8>/Out1'
   */
  Motorparasmeters_B.UnitDelay_a = Motorparasmeters_P.Out1_Y0_o;

  /* End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S220>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S221>/UART//USART Write' */
  Motorparasmeters_DWork.obj_e.matlabCodegenIsDeleted = false;
  Motorparasmeters_DWork.objisempty_a = true;
  Motorparasmeters_DWork.obj_e.isSetupComplete = false;
  Motorparasmeters_DWork.obj_e.isInitialized = 1;
  Motorparasm_UARTWrite_setupImpl(&Motorparasmeters_DWork.obj_e);
  Motorparasmeters_DWork.obj_e.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S220>/Enabled Subsystem' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S216>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  {
    int32_T i;

    /* Start for Constant: '<S91>/Vq_OpenLoop' */
    Motorparasmeters_B.Vq_OpenLoop = Motorparasmeters_P.Vq_OpenLoop_Value;

    /* Start for Constant: '<S90>/Constant' */
    Motorparasmeters_B.Constant = Motorparasmeters_P.Constant_Value_h;

    /* Start for DataStoreMemory: '<S59>/Data Store Memory' */
    Motorparasmeters_DWork.GlobleopenspeedInt =
      Motorparasmeters_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S16>/Data Store Memory' */
    Motorparasmeters_DWork.statcount =
      Motorparasmeters_P.DataStoreMemory_InitialValue_b;

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay1' */
    Motorparasmeters_DWork.UnitDelay1_DSTATE =
      Motorparasmeters_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
    Motorparasmeters_DWork.UnitDelay_DSTATE =
      Motorparasmeters_P.UnitDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S2>/Delay5' */
    Motorparasmeters_DWork.Delay5_DSTATE[0] =
      Motorparasmeters_P.Delay5_InitialCondition;
    Motorparasmeters_DWork.Delay5_DSTATE[1] =
      Motorparasmeters_P.Delay5_InitialCondition;
    Motorparasmeters_DWork.Delay5_DSTATE[2] =
      Motorparasmeters_P.Delay5_InitialCondition;
    Motorparasmeters_DWork.Delay5_DSTATE[3] =
      Motorparasmeters_P.Delay5_InitialCondition;

    /* InitializeConditions for Delay: '<S30>/Delay' */
    Motorparasmeters_DWork.Delay_DSTATE =
      Motorparasmeters_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S40>/Delay1' */
    Motorparasmeters_DWork.Delay1_DSTATE =
      Motorparasmeters_P.Delay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S44>/Unit Delay' */
    Motorparasmeters_DWork.UnitDelay_DSTATE_b =
      Motorparasmeters_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S41>/Unit Delay1' */
    Motorparasmeters_DWork.UnitDelay1_DSTATE_m =
      Motorparasmeters_P.UnitDelay1_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S41>/Unit Delay' */
    Motorparasmeters_DWork.UnitDelay_DSTATE_p =
      Motorparasmeters_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S31>/Delay' */
    Motorparasmeters_DWork.Delay_DSTATE_h =
      Motorparasmeters_P.Delay_InitialCondition_e;

    /* InitializeConditions for Delay: '<S41>/Delay1' */
    Motorparasmeters_DWork.Delay1_DSTATE_e =
      Motorparasmeters_P.Delay1_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S47>/Unit Delay' */
    Motorparasmeters_DWork.UnitDelay_DSTATE_d =
      Motorparasmeters_P.UnitDelay_InitialCondition_p;

    /* InitializeConditions for Delay: '<S28>/Delay' */
    Motorparasmeters_DWork.Delay_DSTATE_p =
      Motorparasmeters_P.Delay_InitialCondition_b;

    /* InitializeConditions for UnitDelay: '<S62>/Unit Delay' */
    Motorparasmeters_DWork.UnitDelay_DSTATE_bp =
      Motorparasmeters_P.UnitDelay_InitialCondition_pr;

    /* InitializeConditions for DiscreteIntegrator: '<S195>/Integrator' */
    Motorparasmeters_DWork.Integrator_DSTATE = Motorparasmeters_B.Vq_OpenLoop;
    Motorparasmeters_DWork.Integrator_PrevResetState = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator' */
    Motorparasmeters_DWork.Integrator_DSTATE_l = Motorparasmeters_B.Constant;
    Motorparasmeters_DWork.Integrator_PrevResetState_i = 0;

    /* InitializeConditions for Delay: '<S35>/Delay' */
    for (i = 0; i < 119; i++) {
      Motorparasmeters_DWork.Delay_DSTATE_a[i] =
        Motorparasmeters_P.Delay_InitialCondition_i;
    }

    Motorparasmeters_DWork.CircBufIdx = 0U;

    /* End of InitializeConditions for Delay: '<S35>/Delay' */

    /* InitializeConditions for UnitDelay: '<S50>/Unit Delay' */
    Motorparasmeters_DWork.UnitDelay_DSTATE_bl =
      Motorparasmeters_P.UnitDelay_InitialCondition_j;

    /* SystemInitialize for Triggered SubSystem: '<S29>/Dir_Sense' */
    /* SystemInitialize for Switch: '<S37>/Switch' incorporates:
     *  Outport: '<S37>/Sign'
     */
    Motorparasmeters_B.Switch_gg = Motorparasmeters_P.Sign_Y0;

    /* End of SystemInitialize for SubSystem: '<S29>/Dir_Sense' */

    /* SystemInitialize for Enabled SubSystem: '<S62>/Accumulate' */
    /* InitializeConditions for Delay: '<S63>/Delay' */
    Motorparasmeters_DWork.Delay_DSTATE_he =
      Motorparasmeters_P.Delay_InitialCondition_n;

    /* SystemInitialize for Enabled SubSystem: '<S63>/Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S64>/Input' incorporates:
     *  Outport: '<S64>/Out1'
     */
    Motorparasmeters_B.Input = Motorparasmeters_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S63>/Subsystem' */

    /* SystemInitialize for Sum: '<S63>/Add1' incorporates:
     *  Outport: '<S63>/theta_e'
     */
    Motorparasmeters_B.Add1_mo = Motorparasmeters_P.theta_e_Y0;

    /* End of SystemInitialize for SubSystem: '<S62>/Accumulate' */

    /* Start for MATLABSystem: '<S20>/Analog to Digital Converter' */
    Motorparasmeters_DWork.obj_o.isInitialized = 0;
    Motorparasmeters_DWork.obj_o.matlabCodegenIsDeleted = false;
    Motorparasmeters_DWork.objisempty_o = true;
    Motorparasmete_SystemCore_setup(&Motorparasmeters_DWork.obj_o);

    /* Start for MATLABSystem: '<S214>/PWM Output' */
    Motorparasmeters_DWork.obj_e3.matlabCodegenIsDeleted = false;
    Motorparasmeters_DWork.objisempty_k = true;
    Motorparasmeters_DWork.obj_e3.isSetupComplete = false;
    Motorparasmeters_DWork.obj_e3.isInitialized = 1;
    Motorparasm_PWMOutput_setupImpl(&Motorparasmeters_DWork.obj_e3);
    Motorparasmeters_DWork.obj_e3.isSetupComplete = true;

    /* SystemInitialize for Gain: '<S55>/OP_Gain*R_shunt1' incorporates:
     *  Outport: '<S2>/currentab'
     */
    Motorparasmeters_B.OP_GainR_shunt1[0] = Motorparasmeters_P.currentab_Y0;
    Motorparasmeters_B.OP_GainR_shunt1[1] = Motorparasmeters_P.currentab_Y0;

    /* SystemInitialize for Gain: '<S12>/Gain' incorporates:
     *  Outport: '<S2>/Rs'
     */
    Motorparasmeters_B.Gain = Motorparasmeters_P.Rs_Y0;
  }

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S216>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S10>/Digital Port Read' */
  Motorparasmeters_DWork.objisempty_f = true;
  Motorparasmeters_DWork.obj_k.isInitialized = 1;

  /* Start for MATLABSystem: '<S220>/UART//USART Write' */
  Motorparasmeters_DWork.obj.matlabCodegenIsDeleted = false;
  Motorparasmeters_DWork.objisempty = true;
  Motorparasmeters_DWork.obj.isSetupComplete = false;
  Motorparasmeters_DWork.obj.isInitialized = 1;
  Motorparasm_UARTWrite_setupImpl(&Motorparasmeters_DWork.obj);
  Motorparasmeters_DWork.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S219>/Digital Port Write' */
  Motorparasmeters_DWork.objisempty_n = true;
  Motorparasmeters_DWork.obj_kg.isInitialized = 1;

  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* DataStoreWrite: '<S4>/Data Store Write' incorporates:
   *  Constant: '<S4>/Testing get offset1'
   */
  Motorparasmeters_DWork.IaOffset = Motorparasmeters_P.Testinggetoffset1_Value;

  /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
   *  Constant: '<S4>/Testing get offset'
   */
  Motorparasmeters_DWork.IbOffset = Motorparasmeters_P.Testinggetoffset_Value;

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/* Model terminate function */
void Motorparasmeters_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S216>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S216>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S20>/Analog to Digital Converter' */
  if (!Motorparasmeters_DWork.obj_o.matlabCodegenIsDeleted) {
    Motorparasmeters_DWork.obj_o.matlabCodegenIsDeleted = true;
    if ((Motorparasmeters_DWork.obj_o.isInitialized == 1) &&
        Motorparasmeters_DWork.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(Motorparasmeters_DWork.obj_o.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S214>/PWM Output' */
  if (!Motorparasmeters_DWork.obj_e3.matlabCodegenIsDeleted) {
    Motorparasmeters_DWork.obj_e3.matlabCodegenIsDeleted = true;
    if ((Motorparasmeters_DWork.obj_e3.isInitialized == 1) &&
        Motorparasmeters_DWork.obj_e3.isSetupComplete) {
      disableCounter(Motorparasmeters_DWork.obj_e3.TimerHandle);
      disableTimerInterrupts(Motorparasmeters_DWork.obj_e3.TimerHandle, 0);
      disableTimerChannel1(Motorparasmeters_DWork.obj_e3.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(Motorparasmeters_DWork.obj_e3.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(Motorparasmeters_DWork.obj_e3.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S214>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S216>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S220>/UART//USART Write' */
  if (!Motorparasmeters_DWork.obj.matlabCodegenIsDeleted) {
    Motorparasmeters_DWork.obj.matlabCodegenIsDeleted = true;
    if ((Motorparasmeters_DWork.obj.isInitialized == 1) &&
        Motorparasmeters_DWork.obj.isSetupComplete) {
      MW_LPUART_DeInit(Motorparasmeters_DWork.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S220>/UART//USART Write' */

  /* Terminate for Enabled SubSystem: '<S220>/Enabled Subsystem' */
  /* Terminate for MATLABSystem: '<S221>/UART//USART Write' */
  if (!Motorparasmeters_DWork.obj_e.matlabCodegenIsDeleted) {
    Motorparasmeters_DWork.obj_e.matlabCodegenIsDeleted = true;
    if ((Motorparasmeters_DWork.obj_e.isInitialized == 1) &&
        Motorparasmeters_DWork.obj_e.isSetupComplete) {
      MW_LPUART_DeInit(Motorparasmeters_DWork.obj_e.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S221>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<S220>/Enabled Subsystem' */
}

void Motorparasmeters_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC1_2_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S216>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S216>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          real_T y_tmp;
          uint64_T tmp_p;
          real32_T ADvoltage;
          real32_T Bias;
          real32_T Bias_tmp;
          uint32_T Sum;
          uint16_T tmp[2];
          ZCSigState Delay_Reset_ZCE_tmp;
          int8_T Integrator_PrevResetState_tmp;
          boolean_T LogicalOperator_tmp;
          boolean_T zcEvent;

          /* MATLABSystem: '<S20>/Analog to Digital Converter' */
          injectedReadADCIntr(Motorparasmeters_DWork.obj_o.ADCHandle, ADC_READ,
                              &tmp[0]);

          /* MATLABSystem: '<S20>/Analog to Digital Converter' */
          Motorparasmeters_B.AnalogtoDigitalConverter[0] = tmp[0];
          Motorparasmeters_B.AnalogtoDigitalConverter[1] = tmp[1];

          /* Switch: '<S94>/Switch1' incorporates:
           *  Constant: '<S94>/enableInportSatMethod'
           */
          if (Motorparasmeters_P.enableInportSatMethod_Value != 0) {
            /* Switch: '<S94>/Switch1' incorporates:
             *  Constant: '<S89>/ReplaceInport_satMethod'
             */
            Motorparasmeters_B.Switch1_i =
              Motorparasmeters_P.ReplaceInport_satMethod_Value;
          } else {
            /* Switch: '<S94>/Switch1' incorporates:
             *  Constant: '<S94>/ChosenMethod'
             */
            Motorparasmeters_B.Switch1_i = Motorparasmeters_P.ChosenMethod_Value;
          }

          /* End of Switch: '<S94>/Switch1' */

          /* DataStoreRead: '<S55>/Data Store Read' */
          Motorparasmeters_B.DataStoreRead_a = Motorparasmeters_DWork.IaOffset;

          /* DataStoreRead: '<S55>/Data Store Read1' */
          Motorparasmeters_B.DataStoreRead1 = Motorparasmeters_DWork.IbOffset;

          /* DataTypeConversion: '<S55>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S20>/Analog to Digital Converter'
           */
          Motorparasmeters_B.DataTypeConversion[0] =
            Motorparasmeters_B.AnalogtoDigitalConverter[0];
          Motorparasmeters_B.DataTypeConversion[1] =
            Motorparasmeters_B.AnalogtoDigitalConverter[1];

          /* Sum: '<S55>/Add' incorporates:
           *  DataTypeConversion: '<S55>/Data Type Conversion'
           */
          Motorparasmeters_B.Add_a[0] = Motorparasmeters_B.DataTypeConversion[0]
            - Motorparasmeters_B.DataStoreRead_a;
          Motorparasmeters_B.Add_a[1] = Motorparasmeters_B.DataTypeConversion[1]
            - Motorparasmeters_B.DataStoreRead1;

          /* Gain: '<S55>/AD voltage' incorporates:
           *  Sum: '<S55>/Add'
           */
          ADvoltage = Motorparasmeters_P.ADvoltage_Gain * (real32_T)
            Motorparasmeters_B.Add_a[0];
          Motorparasmeters_B.ADvoltage[0] = ADvoltage;

          /* Gain: '<S55>/OP_Gain*R_shunt' incorporates:
           *  Gain: '<S55>/AD voltage'
           */
          ADvoltage *= Motorparasmeters_P.OP_GainR_shunt_Gain;
          Motorparasmeters_B.OP_GainR_shunt[0] = ADvoltage;

          /* Gain: '<S55>/OP_Gain*R_shunt1' incorporates:
           *  Gain: '<S55>/OP_Gain*R_shunt'
           */
          Motorparasmeters_B.OP_GainR_shunt1[0] =
            Motorparasmeters_P.OP_GainR_shunt1_Gain * ADvoltage;

          /* Gain: '<S55>/AD voltage' incorporates:
           *  Sum: '<S55>/Add'
           */
          ADvoltage = Motorparasmeters_P.ADvoltage_Gain * (real32_T)
            Motorparasmeters_B.Add_a[1];
          Motorparasmeters_B.ADvoltage[1] = ADvoltage;

          /* Gain: '<S55>/OP_Gain*R_shunt' incorporates:
           *  Gain: '<S55>/AD voltage'
           */
          ADvoltage *= Motorparasmeters_P.OP_GainR_shunt_Gain;
          Motorparasmeters_B.OP_GainR_shunt[1] = ADvoltage;

          /* Gain: '<S55>/OP_Gain*R_shunt1' incorporates:
           *  Gain: '<S55>/OP_Gain*R_shunt'
           */
          Motorparasmeters_B.OP_GainR_shunt1[1] =
            Motorparasmeters_P.OP_GainR_shunt1_Gain * ADvoltage;

          /* Outputs for Atomic SubSystem: '<S71>/Two phase CRL wrap' */
          /* AlgorithmDescriptorDelegate generated from: '<S72>/a16' */
          arm_clarke_f32(Motorparasmeters_B.OP_GainR_shunt1[0],
                         Motorparasmeters_B.OP_GainR_shunt1[1],
                         &Motorparasmeters_B.algDD_o1_j,
                         &Motorparasmeters_B.algDD_o2_e);

          /* End of Outputs for SubSystem: '<S71>/Two phase CRL wrap' */

          /* Gain: '<S71>/Kalpha' */
          Motorparasmeters_B.Kalpha = Motorparasmeters_P.Kalpha_Gain *
            Motorparasmeters_B.algDD_o1_j;

          /* Gain: '<S71>/Kbeta' */
          Motorparasmeters_B.Kbeta = Motorparasmeters_P.Kbeta_Gain *
            Motorparasmeters_B.algDD_o2_e;

          /* UnitDelay: '<S40>/Unit Delay1' */
          Motorparasmeters_B.UnitDelay1 =
            Motorparasmeters_DWork.UnitDelay1_DSTATE;

          /* UnitDelay: '<S40>/Unit Delay' */
          Motorparasmeters_B.UnitDelay = Motorparasmeters_DWork.UnitDelay_DSTATE;

          /* Gain: '<S40>/a' */
          Motorparasmeters_B.a = Motorparasmeters_P.a_Gain *
            Motorparasmeters_B.UnitDelay;

          /* Delay: '<S2>/Delay5' */
          Motorparasmeters_B.Delay5[0] = Motorparasmeters_DWork.Delay5_DSTATE[0];
          Motorparasmeters_B.Delay5[1] = Motorparasmeters_DWork.Delay5_DSTATE[1];
          Motorparasmeters_B.Delay5[2] = Motorparasmeters_DWork.Delay5_DSTATE[2];
          Motorparasmeters_B.Delay5[3] = Motorparasmeters_DWork.Delay5_DSTATE[3];

          /* DataStoreRead: '<S2>/Data Store Read' */
          Motorparasmeters_B.DataStoreRead_b = Motorparasmeters_DWork.Enable;

          /* Logic: '<S14>/Logical Operator' incorporates:
           *  Logic: '<S90>/Logical Operator1'
           *  Logic: '<S91>/Logical Operator'
           */
          LogicalOperator_tmp = !Motorparasmeters_B.DataStoreRead_b;

          /* Logic: '<S14>/Logical Operator' */
          Motorparasmeters_B.LogicalOperator = LogicalOperator_tmp;

          /* Delay: '<S30>/Delay' */
          zcEvent = (((Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE ==
                       POS_ZCSIG) != (int32_T)Motorparasmeters_B.LogicalOperator)
                     && (Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE !=
                         UNINITIALIZED_ZCSIG));
          if (zcEvent || Motorparasmeters_B.LogicalOperator) {
            Motorparasmeters_DWork.Delay_DSTATE =
              Motorparasmeters_P.Delay_InitialCondition;
          }

          Delay_Reset_ZCE_tmp = Motorparasmeters_B.LogicalOperator;
          Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S30>/Delay' */
          Motorparasmeters_B.Delay_b = Motorparasmeters_DWork.Delay_DSTATE;

          /* Sum: '<S30>/Sum2' */
          Motorparasmeters_B.Sum2 = Motorparasmeters_B.Delay_b -
            Motorparasmeters_B.Delay5[2];

          /* Sum: '<S40>/Sum3' */
          Motorparasmeters_B.Sum3 = (Motorparasmeters_B.UnitDelay1 -
            Motorparasmeters_B.a) + Motorparasmeters_B.Sum2;

          /* Gain: '<S40>/b_inv*g' incorporates:
           *  Gain: '<S41>/b_inv*g'
           */
          y_tmp = Motorparasmeters_P.SlidingModeObserver_Disturbance *
            2.1999999999999997 / 0.10703441280573596;
          Bias_tmp = (real32_T)y_tmp;
          Bias = Bias_tmp;

          /* Gain: '<S40>/b_inv*g' */
          Motorparasmeters_B.b_invg = Bias * Motorparasmeters_B.Sum3;

          /* Delay: '<S40>/Delay1' */
          zcEvent = (((Motorparasmeters_PrevZCSigState.Delay1_Reset_ZCE ==
                       POS_ZCSIG) != (int32_T)Motorparasmeters_B.LogicalOperator)
                     && (Motorparasmeters_PrevZCSigState.Delay1_Reset_ZCE !=
                         UNINITIALIZED_ZCSIG));
          if (zcEvent || Motorparasmeters_B.LogicalOperator) {
            Motorparasmeters_DWork.Delay1_DSTATE =
              Motorparasmeters_P.Delay1_InitialCondition;
          }

          Motorparasmeters_PrevZCSigState.Delay1_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S40>/Delay1' */
          Motorparasmeters_B.Delay1 = Motorparasmeters_DWork.Delay1_DSTATE;

          /* Sum: '<S40>/Sum4' */
          Motorparasmeters_B.Sum4 = Motorparasmeters_B.b_invg +
            Motorparasmeters_B.Delay1;

          /* Switch: '<S32>/Switch1' incorporates:
           *  Constant: '<S32>/UseInputPort'
           */
          if (Motorparasmeters_P.UseInputPort_Value >
              Motorparasmeters_P.Switch1_Threshold_b) {
            /* Sum: '<S32>/Sum' incorporates:
             *  Constant: '<S32>/One'
             *  Constant: '<S32>/a'
             */
            Motorparasmeters_B.Sum_d = Motorparasmeters_P.One_Value -
              Motorparasmeters_P.a_Value;

            /* Switch: '<S32>/Switch1' incorporates:
             *  Constant: '<S32>/a'
             */
            Motorparasmeters_B.Switch1[0] = Motorparasmeters_P.a_Value;
            Motorparasmeters_B.Switch1[1] = Motorparasmeters_B.Sum_d;
          } else {
            /* Switch: '<S32>/Switch1' incorporates:
             *  Constant: '<S32>/FilterConstant'
             *  Constant: '<S32>/OneMinusFilterConstant'
             */
            Motorparasmeters_B.Switch1[0] =
              Motorparasmeters_P.FilterConstant_Value;
            Motorparasmeters_B.Switch1[1] =
              Motorparasmeters_P.OneMinusFilterConstant_Value;
          }

          /* End of Switch: '<S32>/Switch1' */

          /* Product: '<S44>/Product' */
          Motorparasmeters_B.Product = Motorparasmeters_B.Sum4 *
            Motorparasmeters_B.Switch1[0];

          /* UnitDelay: '<S44>/Unit Delay' */
          Motorparasmeters_B.UnitDelay_e =
            Motorparasmeters_DWork.UnitDelay_DSTATE_b;

          /* Product: '<S44>/Product1' */
          Motorparasmeters_B.Product1 = Motorparasmeters_B.Switch1[1] *
            Motorparasmeters_B.UnitDelay_e;

          /* Sum: '<S44>/Add1' */
          Motorparasmeters_B.Add1_o = Motorparasmeters_B.Product +
            Motorparasmeters_B.Product1;

          /* Relay: '<S29>/AlphaRelay' */
          Bias = Motorparasmeters_B.Add1_o;
          Motorparasmeters_DWork.AlphaRelay_Mode = ((Bias >=
            Motorparasmeters_P.AlphaRelay_OnVal) || ((!(Bias <=
            Motorparasmeters_P.AlphaRelay_OffVal)) &&
            Motorparasmeters_DWork.AlphaRelay_Mode));
          if (Motorparasmeters_DWork.AlphaRelay_Mode) {
            /* Relay: '<S29>/AlphaRelay' */
            Motorparasmeters_B.AlphaRelay = Motorparasmeters_P.AlphaRelay_YOn;
          } else {
            /* Relay: '<S29>/AlphaRelay' */
            Motorparasmeters_B.AlphaRelay = Motorparasmeters_P.AlphaRelay_YOff;
          }

          /* End of Relay: '<S29>/AlphaRelay' */

          /* UnitDelay: '<S41>/Unit Delay1' */
          Motorparasmeters_B.UnitDelay1_e =
            Motorparasmeters_DWork.UnitDelay1_DSTATE_m;

          /* UnitDelay: '<S41>/Unit Delay' */
          Motorparasmeters_B.UnitDelay_c =
            Motorparasmeters_DWork.UnitDelay_DSTATE_p;

          /* Gain: '<S41>/a' */
          Motorparasmeters_B.a_c = Motorparasmeters_P.a_Gain_e *
            Motorparasmeters_B.UnitDelay_c;

          /* Delay: '<S31>/Delay' */
          zcEvent = (((Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE_c ==
                       POS_ZCSIG) != (int32_T)Motorparasmeters_B.LogicalOperator)
                     && (Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE_c !=
                         UNINITIALIZED_ZCSIG));
          if (zcEvent || Motorparasmeters_B.LogicalOperator) {
            Motorparasmeters_DWork.Delay_DSTATE_h =
              Motorparasmeters_P.Delay_InitialCondition_e;
          }

          Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE_c =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S31>/Delay' */
          Motorparasmeters_B.Delay_f = Motorparasmeters_DWork.Delay_DSTATE_h;

          /* Sum: '<S31>/Sum2' */
          Motorparasmeters_B.Sum2_e = Motorparasmeters_B.Delay_f -
            Motorparasmeters_B.Delay5[3];

          /* Sum: '<S41>/Sum3' */
          Motorparasmeters_B.Sum3_m = (Motorparasmeters_B.UnitDelay1_e -
            Motorparasmeters_B.a_c) + Motorparasmeters_B.Sum2_e;

          /* Gain: '<S41>/b_inv*g' */
          Bias = Bias_tmp;

          /* Gain: '<S41>/b_inv*g' */
          Motorparasmeters_B.b_invg_d = Bias * Motorparasmeters_B.Sum3_m;

          /* Delay: '<S41>/Delay1' */
          zcEvent = (((Motorparasmeters_PrevZCSigState.Delay1_Reset_ZCE_b ==
                       POS_ZCSIG) != (int32_T)Motorparasmeters_B.LogicalOperator)
                     && (Motorparasmeters_PrevZCSigState.Delay1_Reset_ZCE_b !=
                         UNINITIALIZED_ZCSIG));
          if (zcEvent || Motorparasmeters_B.LogicalOperator) {
            Motorparasmeters_DWork.Delay1_DSTATE_e =
              Motorparasmeters_P.Delay1_InitialCondition_m;
          }

          Motorparasmeters_PrevZCSigState.Delay1_Reset_ZCE_b =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S41>/Delay1' */
          Motorparasmeters_B.Delay1_f = Motorparasmeters_DWork.Delay1_DSTATE_e;

          /* Sum: '<S41>/Sum4' */
          Motorparasmeters_B.Sum4_d = Motorparasmeters_B.b_invg_d +
            Motorparasmeters_B.Delay1_f;

          /* Switch: '<S33>/Switch1' incorporates:
           *  Constant: '<S33>/UseInputPort'
           */
          if (Motorparasmeters_P.UseInputPort_Value_g >
              Motorparasmeters_P.Switch1_Threshold_bx) {
            /* Sum: '<S33>/Sum' incorporates:
             *  Constant: '<S33>/One'
             *  Constant: '<S33>/a'
             */
            Motorparasmeters_B.Sum_lt = Motorparasmeters_P.One_Value_c -
              Motorparasmeters_P.a_Value_h;

            /* Switch: '<S33>/Switch1' incorporates:
             *  Constant: '<S33>/a'
             */
            Motorparasmeters_B.Switch1_o[0] = Motorparasmeters_P.a_Value_h;
            Motorparasmeters_B.Switch1_o[1] = Motorparasmeters_B.Sum_lt;
          } else {
            /* Switch: '<S33>/Switch1' incorporates:
             *  Constant: '<S33>/FilterConstant'
             *  Constant: '<S33>/OneMinusFilterConstant'
             */
            Motorparasmeters_B.Switch1_o[0] =
              Motorparasmeters_P.FilterConstant_Value_g;
            Motorparasmeters_B.Switch1_o[1] =
              Motorparasmeters_P.OneMinusFilterConstant_Value_j;
          }

          /* End of Switch: '<S33>/Switch1' */

          /* Product: '<S47>/Product' */
          Motorparasmeters_B.Product_b = Motorparasmeters_B.Sum4_d *
            Motorparasmeters_B.Switch1_o[0];

          /* UnitDelay: '<S47>/Unit Delay' */
          Motorparasmeters_B.UnitDelay_m =
            Motorparasmeters_DWork.UnitDelay_DSTATE_d;

          /* Product: '<S47>/Product1' */
          Motorparasmeters_B.Product1_l = Motorparasmeters_B.Switch1_o[1] *
            Motorparasmeters_B.UnitDelay_m;

          /* Sum: '<S47>/Add1' */
          Motorparasmeters_B.Add1_p = Motorparasmeters_B.Product_b +
            Motorparasmeters_B.Product1_l;

          /* Relay: '<S29>/BetaRelay' */
          Bias = Motorparasmeters_B.Add1_p;
          Motorparasmeters_DWork.BetaRelay_Mode = ((Bias >=
            Motorparasmeters_P.BetaRelay_OnVal) || ((!(Bias <=
            Motorparasmeters_P.BetaRelay_OffVal)) &&
            Motorparasmeters_DWork.BetaRelay_Mode));
          if (Motorparasmeters_DWork.BetaRelay_Mode) {
            /* Relay: '<S29>/BetaRelay' */
            Motorparasmeters_B.BetaRelay = Motorparasmeters_P.BetaRelay_YOn;
          } else {
            /* Relay: '<S29>/BetaRelay' */
            Motorparasmeters_B.BetaRelay = Motorparasmeters_P.BetaRelay_YOff;
          }

          /* End of Relay: '<S29>/BetaRelay' */

          /* Outputs for Triggered SubSystem: '<S29>/Dir_Sense' incorporates:
           *  TriggerPort: '<S37>/Trigger'
           */
          zcEvent = (Motorparasmeters_B.AlphaRelay &&
                     (Motorparasmeters_PrevZCSigState.Dir_Sense_Trig_ZCE !=
                      POS_ZCSIG));
          if (zcEvent) {
            /* Logic: '<S37>/Logical Operator' */
            Motorparasmeters_B.LogicalOperator_g =
              (Motorparasmeters_B.AlphaRelay && Motorparasmeters_B.BetaRelay);

            /* Switch: '<S37>/Switch' */
            if (Motorparasmeters_B.LogicalOperator_g) {
              /* Switch: '<S37>/Switch' incorporates:
               *  Constant: '<S37>/Constant'
               */
              Motorparasmeters_B.Switch_gg = (int16_T)floor
                (Motorparasmeters_P.Constant_Value);
            } else {
              /* Switch: '<S37>/Switch' incorporates:
               *  Constant: '<S37>/Constant1'
               */
              Motorparasmeters_B.Switch_gg = (int16_T)floor
                (Motorparasmeters_P.Constant1_Value);
            }

            /* End of Switch: '<S37>/Switch' */
          }

          Motorparasmeters_PrevZCSigState.Dir_Sense_Trig_ZCE =
            Motorparasmeters_B.AlphaRelay;

          /* End of Outputs for SubSystem: '<S29>/Dir_Sense' */

          /* If: '<S29>/If' */
          if (Motorparasmeters_B.Switch_gg > 0) {
            /* Outputs for IfAction SubSystem: '<S29>/Subsystem2' incorporates:
             *  ActionPort: '<S38>/Action Port'
             */
            /* Merge: '<S29>/Merge' incorporates:
             *  UnaryMinus: '<S38>/Unary Minus'
             */
            Motorparasmeters_B.Merge = -Motorparasmeters_B.Add1_o;

            /* Merge: '<S29>/Merge1' incorporates:
             *  SignalConversion generated from: '<S38>/SigmaBeta'
             */
            Motorparasmeters_B.Merge1 = Motorparasmeters_B.Add1_p;

            /* End of Outputs for SubSystem: '<S29>/Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S29>/Subsystem3' incorporates:
             *  ActionPort: '<S39>/Action Port'
             */
            /* Merge: '<S29>/Merge1' incorporates:
             *  UnaryMinus: '<S39>/Unary Minus'
             */
            Motorparasmeters_B.Merge1 = -Motorparasmeters_B.Add1_p;

            /* Merge: '<S29>/Merge' incorporates:
             *  SignalConversion generated from: '<S39>/SigmaAlpha'
             */
            Motorparasmeters_B.Merge = Motorparasmeters_B.Add1_o;

            /* End of Outputs for SubSystem: '<S29>/Subsystem3' */
          }

          /* End of If: '<S29>/If' */

          /* Delay: '<S28>/Delay' */
          zcEvent = (((Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE_n ==
                       POS_ZCSIG) != (int32_T)Motorparasmeters_B.LogicalOperator)
                     && (Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE_n !=
                         UNINITIALIZED_ZCSIG));
          if (zcEvent || Motorparasmeters_B.LogicalOperator) {
            Motorparasmeters_DWork.Delay_DSTATE_p =
              Motorparasmeters_P.Delay_InitialCondition_b;
          }

          Motorparasmeters_PrevZCSigState.Delay_Reset_ZCE_n =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S28>/Delay' */
          Motorparasmeters_B.Delay_fn = Motorparasmeters_DWork.Delay_DSTATE_p;

          /* Constant: '<S28>/PhaseDelay' */
          y_tmp = Motorparasmeters_P.SlidingModeObserver_CutoffFreq /
            83.333333333333329;

          /* Constant: '<S28>/PhaseDelay' */
          Motorparasmeters_B.PhaseDelay = (real32_T)y_tmp;

          /* Outputs for Atomic SubSystem: '<S28>/angleCompensation' */
          /* Product: '<S36>/Product' */
          Motorparasmeters_B.Product_b1 = Motorparasmeters_B.Merge *
            Motorparasmeters_B.PhaseDelay;

          /* Product: '<S36>/Product2' */
          Motorparasmeters_B.Product2_d = Motorparasmeters_B.Merge1 *
            Motorparasmeters_B.Delay_fn;

          /* Sum: '<S36>/Sum1' */
          Motorparasmeters_B.Sum1_k = Motorparasmeters_B.Product_b1 +
            Motorparasmeters_B.Product2_d;

          /* Product: '<S36>/Product1' */
          Motorparasmeters_B.Product1_li = Motorparasmeters_B.Merge1 *
            Motorparasmeters_B.PhaseDelay;

          /* Product: '<S36>/Product3' */
          Motorparasmeters_B.Product3 = Motorparasmeters_B.Merge *
            Motorparasmeters_B.Delay_fn;

          /* Sum: '<S36>/Sum2' */
          Motorparasmeters_B.Sum2_et = Motorparasmeters_B.Product1_li -
            Motorparasmeters_B.Product3;

          /* Outputs for Atomic SubSystem: '<S36>/atan1' */
          /* Trigonometry: '<S53>/Atan2' */
          Motorparasmeters_B.Atan2 = rt_atan2f_snf(Motorparasmeters_B.Sum1_k,
            Motorparasmeters_B.Sum2_et);

          /* Outputs for Atomic SubSystem: '<S36>/atan1' */
          /* Switch: '<S53>/Switch' */
          if (Motorparasmeters_P.atan1_outputUnit >
              Motorparasmeters_P.Switch_Threshold_f) {
            /* Outputs for Atomic SubSystem: '<S53>/Per Unit' */
            /* Gain: '<S54>/Gain' */
            Motorparasmeters_B.Gain_d = Motorparasmeters_P.Gain_Gain *
              Motorparasmeters_B.Atan2;

            /* Switch: '<S54>/Switch' */
            if (Motorparasmeters_B.Gain_d >= Motorparasmeters_P.Switch_Threshold)
            {
              /* Switch: '<S54>/Switch' */
              Motorparasmeters_B.Switch_kk = Motorparasmeters_B.Gain_d;
            } else {
              /* Bias: '<S54>/Bias' */
              Motorparasmeters_B.Bias = Motorparasmeters_B.Gain_d +
                Motorparasmeters_P.Bias_Bias_g;

              /* Switch: '<S54>/Switch' */
              Motorparasmeters_B.Switch_kk = Motorparasmeters_B.Bias;
            }

            /* End of Switch: '<S54>/Switch' */
            /* End of Outputs for SubSystem: '<S53>/Per Unit' */

            /* Switch: '<S53>/Switch' */
            Motorparasmeters_B.Switch_nl = Motorparasmeters_B.Switch_kk;
          } else {
            /* Switch: '<S53>/Switch' */
            Motorparasmeters_B.Switch_nl = Motorparasmeters_B.Atan2;
          }

          /* End of Switch: '<S53>/Switch' */
          /* End of Outputs for SubSystem: '<S36>/atan1' */

          /* AlgorithmDescriptorDelegate generated from: '<S53>/a16' */
          Motorparasmeters_B.algDD = Motorparasmeters_B.Switch_nl;

          /* End of Outputs for SubSystem: '<S36>/atan1' */

          /* Switch: '<S36>/Switch' */
          if (Motorparasmeters_B.algDD > Motorparasmeters_P.Switch_Threshold_k)
          {
            /* Switch: '<S36>/Switch' */
            Motorparasmeters_B.Switch_o3 = Motorparasmeters_B.algDD;
          } else {
            /* Bias: '<S36>/Bias' */
            Motorparasmeters_B.Bias_d = Motorparasmeters_B.algDD +
              Motorparasmeters_P.Bias_Bias;

            /* Switch: '<S36>/Switch' */
            Motorparasmeters_B.Switch_o3 = Motorparasmeters_B.Bias_d;
          }

          /* End of Switch: '<S36>/Switch' */
          /* End of Outputs for SubSystem: '<S28>/angleCompensation' */

          /* DataStoreRead: '<S16>/Data Store Read' */
          Motorparasmeters_B.DataStoreRead_c = Motorparasmeters_DWork.Enable;

          /* If: '<S16>/If1' */
          if (Motorparasmeters_B.DataStoreRead_c) {
            /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S57>/Action Port'
             */
            /* DataStoreRead: '<S57>/Data Store Read' */
            Motorparasmeters_B.DataStoreRead = Motorparasmeters_DWork.statcount;

            /* Sum: '<S57>/Add1' incorporates:
             *  Constant: '<S57>/Constant'
             */
            tmp_p = (uint64_T)Motorparasmeters_P.Constant_Value_g +
              Motorparasmeters_B.DataStoreRead;
            if (tmp_p > 4294967295ULL) {
              tmp_p = 4294967295ULL;
            }

            /* Sum: '<S57>/Add1' */
            Motorparasmeters_B.Add1 = (uint32_T)tmp_p;

            /* DataStoreWrite: '<S57>/Data Store Write' */
            Motorparasmeters_DWork.statcount = Motorparasmeters_B.Add1;

            /* Merge: '<S16>/Merge2' incorporates:
             *  SignalConversion generated from: '<S57>/Out1'
             */
            Motorparasmeters_B.cont = Motorparasmeters_B.Add1;

            /* End of Outputs for SubSystem: '<S16>/If Action Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S58>/Action Port'
             */
            /* DataStoreWrite: '<S58>/Data Store Write' incorporates:
             *  Constant: '<S58>/Constant15'
             */
            Motorparasmeters_DWork.statcount =
              Motorparasmeters_P.Constant15_Value;

            /* Merge: '<S16>/Merge2' incorporates:
             *  Constant: '<S58>/Constant15'
             *  SignalConversion generated from: '<S58>/Out1'
             */
            Motorparasmeters_B.cont = Motorparasmeters_P.Constant15_Value;

            /* End of Outputs for SubSystem: '<S16>/If Action Subsystem3' */
          }

          /* End of If: '<S16>/If1' */

          /* RelationalOperator: '<S56>/Compare' incorporates:
           *  Constant: '<S56>/Constant'
           */
          Motorparasmeters_B.Compare = (Motorparasmeters_B.cont <=
            Motorparasmeters_P.EnablePWMfor8seconds_const);

          /* Logic: '<S16>/NOT' */
          Motorparasmeters_B.NOT_c = !Motorparasmeters_B.Compare;

          /* If: '<S59>/If' incorporates:
           *  Constant: '<S59>/Count for 2 sec'
           */
          if (Motorparasmeters_B.cont < Motorparasmeters_P.Countfor2sec_Value) {
            /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem' incorporates:
             *  ActionPort: '<S60>/Action Port'
             */
            /* DataStoreWrite: '<S60>/Data Store Write' incorporates:
             *  Constant: '<S60>/Constant'
             */
            Motorparasmeters_DWork.GlobleopenspeedInt =
              Motorparasmeters_P.Constant_Value_n;

            /* Merge: '<S59>/Merge' incorporates:
             *  Constant: '<S60>/Constant'
             *  SignalConversion generated from: '<S60>/Out1'
             */
            Motorparasmeters_B.Merge_a = Motorparasmeters_P.Constant_Value_n;

            /* End of Outputs for SubSystem: '<S59>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S59>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S61>/Action Port'
             */
            /* DataStoreRead: '<S61>/Data Store Read' */
            Motorparasmeters_B.DataStoreRead_j =
              Motorparasmeters_DWork.GlobleopenspeedInt;

            /* Sum: '<S61>/Add1' incorporates:
             *  Constant: '<S61>/Constant2'
             */
            Motorparasmeters_B.Add1_e = Motorparasmeters_P.Constant2_Value +
              Motorparasmeters_B.DataStoreRead_j;

            /* Saturate: '<S61>/Saturate to 'motor.calibSpeed' RPM' */
            Bias = Motorparasmeters_B.Add1_e;
            Bias_tmp = Motorparasmeters_P.SaturatetomotorcalibSpeedRPM_Lo;
            ADvoltage = Motorparasmeters_P.SaturatetomotorcalibSpeedRPM_Up;
            if (Bias > ADvoltage) {
              /* Saturate: '<S61>/Saturate to 'motor.calibSpeed' RPM' */
              Motorparasmeters_B.SaturatetomotorcalibSpeedRPM = ADvoltage;
            } else if (Bias < Bias_tmp) {
              /* Saturate: '<S61>/Saturate to 'motor.calibSpeed' RPM' */
              Motorparasmeters_B.SaturatetomotorcalibSpeedRPM = Bias_tmp;
            } else {
              /* Saturate: '<S61>/Saturate to 'motor.calibSpeed' RPM' */
              Motorparasmeters_B.SaturatetomotorcalibSpeedRPM = Bias;
            }

            /* End of Saturate: '<S61>/Saturate to 'motor.calibSpeed' RPM' */

            /* DataStoreWrite: '<S61>/Data Store Write' */
            Motorparasmeters_DWork.GlobleopenspeedInt =
              Motorparasmeters_B.SaturatetomotorcalibSpeedRPM;

            /* Merge: '<S59>/Merge' incorporates:
             *  Gain: '<S61>/Multiply1'
             */
            Motorparasmeters_B.Merge_a = Motorparasmeters_P.Multiply1_Gain *
              Motorparasmeters_B.SaturatetomotorcalibSpeedRPM;

            /* End of Outputs for SubSystem: '<S59>/If Action Subsystem2' */
          }

          /* End of If: '<S59>/If' */

          /* Gain: '<S62>/scaleIn' */
          Motorparasmeters_B.scaleIn = Motorparasmeters_P.scaleIn_Gain *
            Motorparasmeters_B.Merge_a;

          /* UnitDelay: '<S62>/Unit Delay' */
          Motorparasmeters_B.UnitDelay_h =
            Motorparasmeters_DWork.UnitDelay_DSTATE_bp;

          /* Logic: '<S62>/NOT' incorporates:
           *  Constant: '<S62>/Constant_Reset'
           */
          Motorparasmeters_B.NOT_b = !Motorparasmeters_P.Constant_Reset_Value;

          /* Outputs for Enabled SubSystem: '<S62>/Accumulate' incorporates:
           *  EnablePort: '<S63>/Enable'
           */
          if (Motorparasmeters_B.NOT_b) {
            /* Delay: '<S63>/Delay' */
            Motorparasmeters_B.Delay_e = Motorparasmeters_DWork.Delay_DSTATE_he;

            /* Outputs for Enabled SubSystem: '<S63>/Subsystem' incorporates:
             *  EnablePort: '<S64>/Enable'
             */
            if (Motorparasmeters_B.Delay_e) {
              /* SignalConversion generated from: '<S64>/Input' */
              Motorparasmeters_B.Input = Motorparasmeters_B.scaleIn;
            }

            /* End of Outputs for SubSystem: '<S63>/Subsystem' */

            /* Sum: '<S63>/Add' */
            Motorparasmeters_B.Add_g = Motorparasmeters_B.Input +
              Motorparasmeters_B.UnitDelay_h;

            /* DataTypeConversion: '<S63>/Data Type Conversion' */
            Motorparasmeters_B.DataTypeConversion_i = (int16_T)floorf
              (Motorparasmeters_B.Add_g);

            /* DataTypeConversion: '<S63>/Data Type Conversion1' */
            Motorparasmeters_B.DataTypeConversion1_p =
              Motorparasmeters_B.DataTypeConversion_i;

            /* Sum: '<S63>/Add1' */
            Motorparasmeters_B.Add1_mo = Motorparasmeters_B.Add_g -
              Motorparasmeters_B.DataTypeConversion1_p;

            /* Update for Delay: '<S63>/Delay' incorporates:
             *  Constant: '<S63>/Constant'
             */
            Motorparasmeters_DWork.Delay_DSTATE_he =
              Motorparasmeters_P.Constant_Value_a;
          }

          /* End of Outputs for SubSystem: '<S62>/Accumulate' */

          /* Switch: '<S15>/Switch' */
          if (Motorparasmeters_B.NOT_c) {
            /* Gain: '<S28>/AngleConversion' */
            Motorparasmeters_B.AngleConversion =
              Motorparasmeters_P.AngleConversion_Gain *
              Motorparasmeters_B.Switch_o3;

            /* Switch: '<S15>/Switch' */
            Motorparasmeters_B.Switch = Motorparasmeters_B.AngleConversion;
          } else {
            /* Gain: '<S62>/scaleOut' */
            Motorparasmeters_B.scaleOut = Motorparasmeters_P.scaleOut_Gain *
              Motorparasmeters_B.Add1_mo;

            /* Switch: '<S15>/Switch' */
            Motorparasmeters_B.Switch = Motorparasmeters_B.scaleOut;
          }

          /* End of Switch: '<S15>/Switch' */

          /* Gain: '<S85>/convert_pu' */
          Motorparasmeters_B.convert_pu = Motorparasmeters_P.convert_pu_Gain *
            Motorparasmeters_B.Switch;

          /* RelationalOperator: '<S86>/Compare' incorporates:
           *  Constant: '<S86>/Constant'
           */
          Motorparasmeters_B.Compare_f = (Motorparasmeters_B.convert_pu <
            Motorparasmeters_P.Constant_Value_m);

          /* DataTypeConversion: '<S85>/Data Type Conversion' */
          Motorparasmeters_B.DataTypeConversion_a = Motorparasmeters_B.Compare_f;

          /* If: '<S85>/If' */
          if (Motorparasmeters_B.DataTypeConversion_a > 0) {
            /* Outputs for IfAction SubSystem: '<S85>/If Action Subsystem' incorporates:
             *  ActionPort: '<S87>/Action Port'
             */
            /* DataTypeConversion: '<S87>/Convert_uint16' */
            Motorparasmeters_B.Convert_uint16_f = (int16_T)floorf
              (Motorparasmeters_B.convert_pu);

            /* DataTypeConversion: '<S87>/Convert_back' */
            Motorparasmeters_B.Convert_back_k =
              Motorparasmeters_B.Convert_uint16_f;

            /* Merge: '<S85>/Merge' incorporates:
             *  Sum: '<S87>/Sum'
             */
            Motorparasmeters_B.Merge_e = Motorparasmeters_B.convert_pu -
              Motorparasmeters_B.Convert_back_k;

            /* End of Outputs for SubSystem: '<S85>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S85>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S88>/Action Port'
             */
            /* DataTypeConversion: '<S88>/Convert_uint16' */
            Motorparasmeters_B.Convert_uint16 = (int16_T)
              Motorparasmeters_B.convert_pu;

            /* DataTypeConversion: '<S88>/Convert_back' */
            Motorparasmeters_B.Convert_back = Motorparasmeters_B.Convert_uint16;

            /* Merge: '<S85>/Merge' incorporates:
             *  Sum: '<S88>/Sum'
             */
            Motorparasmeters_B.Merge_e = Motorparasmeters_B.convert_pu -
              Motorparasmeters_B.Convert_back;

            /* End of Outputs for SubSystem: '<S85>/If Action Subsystem1' */
          }

          /* End of If: '<S85>/If' */

          /* Gain: '<S69>/indexing' */
          Motorparasmeters_B.indexing = Motorparasmeters_P.indexing_Gain *
            Motorparasmeters_B.Merge_e;

          /* DataTypeConversion: '<S69>/Get_Integer' */
          Motorparasmeters_B.Get_Integer = (uint16_T)Motorparasmeters_B.indexing;

          /* Sum: '<S69>/Sum' incorporates:
           *  Constant: '<S69>/offset'
           */
          Sum = (uint32_T)Motorparasmeters_P.offset_Value[0] +
            Motorparasmeters_B.Get_Integer;
          Motorparasmeters_B.Sum[0] = Sum;

          /* Selector: '<S69>/Lookup' incorporates:
           *  Constant: '<S69>/sine_table_values'
           */
          Motorparasmeters_B.Lookup[0] =
            Motorparasmeters_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S69>/Sum' incorporates:
           *  Constant: '<S69>/offset'
           */
          Sum = (uint32_T)Motorparasmeters_P.offset_Value[1] +
            Motorparasmeters_B.Get_Integer;
          Motorparasmeters_B.Sum[1] = Sum;

          /* Selector: '<S69>/Lookup' incorporates:
           *  Constant: '<S69>/sine_table_values'
           */
          Motorparasmeters_B.Lookup[1] =
            Motorparasmeters_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S69>/Sum' incorporates:
           *  Constant: '<S69>/offset'
           */
          Sum = (uint32_T)Motorparasmeters_P.offset_Value[2] +
            Motorparasmeters_B.Get_Integer;
          Motorparasmeters_B.Sum[2] = Sum;

          /* Selector: '<S69>/Lookup' incorporates:
           *  Constant: '<S69>/sine_table_values'
           */
          Motorparasmeters_B.Lookup[2] =
            Motorparasmeters_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S69>/Sum' incorporates:
           *  Constant: '<S69>/offset'
           */
          Sum = (uint32_T)Motorparasmeters_P.offset_Value[3] +
            Motorparasmeters_B.Get_Integer;
          Motorparasmeters_B.Sum[3] = Sum;

          /* Selector: '<S69>/Lookup' incorporates:
           *  Constant: '<S69>/sine_table_values'
           */
          Motorparasmeters_B.Lookup[3] =
            Motorparasmeters_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S84>/Sum3' */
          Motorparasmeters_B.Sum3_i = Motorparasmeters_B.Lookup[0] -
            Motorparasmeters_B.Lookup[1];

          /* DataTypeConversion: '<S69>/Data Type Conversion1' */
          Motorparasmeters_B.DataTypeConversion1 =
            Motorparasmeters_B.Get_Integer;

          /* Sum: '<S69>/Sum2' */
          Motorparasmeters_B.Sum2_g = Motorparasmeters_B.indexing -
            Motorparasmeters_B.DataTypeConversion1;

          /* Product: '<S84>/Product' */
          Motorparasmeters_B.Product_h = Motorparasmeters_B.Sum3_i *
            Motorparasmeters_B.Sum2_g;

          /* Sum: '<S84>/Sum4' */
          Motorparasmeters_B.Sum4_h = Motorparasmeters_B.Product_h +
            Motorparasmeters_B.Lookup[1];

          /* Sum: '<S84>/Sum5' */
          Motorparasmeters_B.Sum5 = Motorparasmeters_B.Lookup[2] -
            Motorparasmeters_B.Lookup[3];

          /* Product: '<S84>/Product1' */
          Motorparasmeters_B.Product1_k = Motorparasmeters_B.Sum5 *
            Motorparasmeters_B.Sum2_g;

          /* Sum: '<S84>/Sum6' */
          Motorparasmeters_B.Sum6 = Motorparasmeters_B.Product1_k +
            Motorparasmeters_B.Lookup[3];

          /* Outputs for Atomic SubSystem: '<S68>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S82>/a16' */
          arm_park_f32(Motorparasmeters_B.Kalpha, Motorparasmeters_B.Kbeta,
                       &Motorparasmeters_B.algDD_o1,
                       &Motorparasmeters_B.algDD_o2, Motorparasmeters_B.Sum4_h,
                       Motorparasmeters_B.Sum6);

          /* End of Outputs for SubSystem: '<S68>/Two inputs CRL' */

          /* Sum: '<S91>/Sum' incorporates:
           *  Constant: '<S17>/Constant4'
           */
          Motorparasmeters_B.Sum_k = Motorparasmeters_P.Constant4_Value -
            Motorparasmeters_B.algDD_o2;

          /* Product: '<S200>/PProd Out' incorporates:
           *  Constant: '<S70>/Kp'
           */
          Motorparasmeters_B.PProdOut = Motorparasmeters_B.Sum_k *
            Motorparasmeters_P.Kp_Value;

          /* DataStoreRead: '<S17>/Data Store Read' */
          Motorparasmeters_B.DataStoreRead_l = Motorparasmeters_DWork.Enable;

          /* Logic: '<S91>/Logical Operator' */
          Motorparasmeters_B.LogicalOperator_n = LogicalOperator_tmp;

          /* Constant: '<S91>/Vq_OpenLoop' */
          Motorparasmeters_B.Vq_OpenLoop = Motorparasmeters_P.Vq_OpenLoop_Value;

          /* DiscreteIntegrator: '<S195>/Integrator' */
          if (Motorparasmeters_B.LogicalOperator_n ||
              (Motorparasmeters_DWork.Integrator_PrevResetState != 0)) {
            Motorparasmeters_DWork.Integrator_DSTATE =
              Motorparasmeters_B.Vq_OpenLoop;
          }

          /* DiscreteIntegrator: '<S195>/Integrator' */
          Motorparasmeters_B.Integrator =
            Motorparasmeters_DWork.Integrator_DSTATE;

          /* Sum: '<S204>/Sum' */
          Motorparasmeters_B.Sum_i = Motorparasmeters_B.PProdOut +
            Motorparasmeters_B.Integrator;

          /* Saturate: '<S202>/Saturation' */
          Bias = Motorparasmeters_B.Sum_i;
          Bias_tmp = Motorparasmeters_P.DiscretePIControllerwithantiwin;
          ADvoltage = Motorparasmeters_P.DiscretePIControllerwithantiw_e;
          if (Bias > ADvoltage) {
            /* Saturate: '<S202>/Saturation' */
            Motorparasmeters_B.Saturation = ADvoltage;
          } else if (Bias < Bias_tmp) {
            /* Saturate: '<S202>/Saturation' */
            Motorparasmeters_B.Saturation = Bias_tmp;
          } else {
            /* Saturate: '<S202>/Saturation' */
            Motorparasmeters_B.Saturation = Bias;
          }

          /* End of Saturate: '<S202>/Saturation' */

          /* Sum: '<S90>/Sum' incorporates:
           *  Constant: '<S17>/Constant5'
           */
          Motorparasmeters_B.Sum_b = Motorparasmeters_P.Constant5_Value -
            Motorparasmeters_B.algDD_o1;

          /* Product: '<S147>/PProd Out' incorporates:
           *  Constant: '<S70>/Kp'
           */
          Motorparasmeters_B.PProdOut_i = Motorparasmeters_B.Sum_b *
            Motorparasmeters_P.Kp_Value;

          /* Logic: '<S90>/Logical Operator1' */
          Motorparasmeters_B.LogicalOperator1 = LogicalOperator_tmp;

          /* Constant: '<S90>/Constant' */
          Motorparasmeters_B.Constant = Motorparasmeters_P.Constant_Value_h;

          /* DiscreteIntegrator: '<S142>/Integrator' */
          if (Motorparasmeters_B.LogicalOperator1 ||
              (Motorparasmeters_DWork.Integrator_PrevResetState_i != 0)) {
            Motorparasmeters_DWork.Integrator_DSTATE_l =
              Motorparasmeters_B.Constant;
          }

          /* DiscreteIntegrator: '<S142>/Integrator' */
          Motorparasmeters_B.Integrator_a =
            Motorparasmeters_DWork.Integrator_DSTATE_l;

          /* Sum: '<S151>/Sum' */
          Motorparasmeters_B.Sum_o = Motorparasmeters_B.PProdOut_i +
            Motorparasmeters_B.Integrator_a;

          /* Saturate: '<S149>/Saturation' */
          Bias = Motorparasmeters_B.Sum_o;
          Bias_tmp = Motorparasmeters_P.DiscretePIControllerwithantiw_f;
          ADvoltage = Motorparasmeters_P.DiscretePIControllerwithantiw_b;
          if (Bias > ADvoltage) {
            /* Saturate: '<S149>/Saturation' */
            Motorparasmeters_B.Saturation_h = ADvoltage;
          } else if (Bias < Bias_tmp) {
            /* Saturate: '<S149>/Saturation' */
            Motorparasmeters_B.Saturation_h = Bias_tmp;
          } else {
            /* Saturate: '<S149>/Saturation' */
            Motorparasmeters_B.Saturation_h = Bias;
          }

          /* End of Saturate: '<S149>/Saturation' */

          /* Switch: '<S94>/Switch' incorporates:
           *  Constant: '<S94>/enableInportSatLim'
           */
          if (Motorparasmeters_P.enableInportSatLim_Value != 0) {
            /* Switch: '<S94>/Switch' incorporates:
             *  Constant: '<S89>/ReplaceInport_satLim'
             */
            Motorparasmeters_B.Switch_o =
              Motorparasmeters_P.ReplaceInport_satLim_Value;
          } else {
            /* Switch: '<S94>/Switch' incorporates:
             *  Constant: '<S94>/Constant3'
             */
            Motorparasmeters_B.Switch_o = Motorparasmeters_P.Constant3_Value;
          }

          /* End of Switch: '<S94>/Switch' */

          /* Product: '<S94>/Product' */
          Motorparasmeters_B.Product_i = Motorparasmeters_B.Switch_o *
            Motorparasmeters_B.Switch_o;

          /* Product: '<S95>/Product' */
          Motorparasmeters_B.Product_hz = Motorparasmeters_B.Saturation_h *
            Motorparasmeters_B.Saturation_h;

          /* Product: '<S95>/Product1' */
          Motorparasmeters_B.Product1_n = Motorparasmeters_B.Saturation *
            Motorparasmeters_B.Saturation;

          /* Sum: '<S95>/Sum1' */
          Motorparasmeters_B.Sum1 = Motorparasmeters_B.Product_hz +
            Motorparasmeters_B.Product1_n;

          /* If: '<S89>/If' */
          if ((Motorparasmeters_B.Switch1_i == 1) ||
              (Motorparasmeters_B.Switch1_i == 2)) {
            /* Outputs for IfAction SubSystem: '<S89>/D//Q Axis Priority' incorporates:
             *  ActionPort: '<S93>/Action Port'
             */
            /* RelationalOperator: '<S98>/Compare' incorporates:
             *  Constant: '<S98>/Constant'
             */
            Motorparasmeters_B.Compare_e = (Motorparasmeters_B.Switch1_i ==
              Motorparasmeters_P.CompareToConstant_const);

            /* RelationalOperator: '<S99>/Compare' incorporates:
             *  Constant: '<S99>/Constant'
             */
            Motorparasmeters_B.Compare_n = (Motorparasmeters_B.Switch1_i ==
              Motorparasmeters_P.CompareToConstant1_const);

            /* Switch: '<S93>/Switch' */
            if (Motorparasmeters_B.Compare_e) {
              /* Switch: '<S93>/Switch' */
              Motorparasmeters_B.Switch_f[0] = Motorparasmeters_B.Saturation_h;
              Motorparasmeters_B.Switch_f[1] = Motorparasmeters_B.Saturation;
            } else {
              /* Switch: '<S93>/Switch' */
              Motorparasmeters_B.Switch_f[0] = Motorparasmeters_B.Saturation;
              Motorparasmeters_B.Switch_f[1] = Motorparasmeters_B.Saturation_h;
            }

            /* End of Switch: '<S93>/Switch' */

            /* RelationalOperator: '<S103>/LowerRelop1' */
            Motorparasmeters_B.LowerRelop1 = (Motorparasmeters_B.Switch_f[0] >
              Motorparasmeters_B.Switch_o);

            /* Switch: '<S103>/Switch2' */
            if (Motorparasmeters_B.LowerRelop1) {
              /* Switch: '<S103>/Switch2' */
              Motorparasmeters_B.Switch2 = Motorparasmeters_B.Switch_o;
            } else {
              /* Gain: '<S102>/Gain' */
              Motorparasmeters_B.Gain_p = Motorparasmeters_P.Gain_Gain_n *
                Motorparasmeters_B.Switch_o;

              /* RelationalOperator: '<S103>/UpperRelop' */
              Motorparasmeters_B.UpperRelop = (Motorparasmeters_B.Switch_f[0] <
                Motorparasmeters_B.Gain_p);

              /* Switch: '<S103>/Switch' */
              if (Motorparasmeters_B.UpperRelop) {
                /* Switch: '<S103>/Switch' */
                Motorparasmeters_B.Switch_n = Motorparasmeters_B.Gain_p;
              } else {
                /* Switch: '<S103>/Switch' */
                Motorparasmeters_B.Switch_n = Motorparasmeters_B.Switch_f[0];
              }

              /* End of Switch: '<S103>/Switch' */

              /* Switch: '<S103>/Switch2' */
              Motorparasmeters_B.Switch2 = Motorparasmeters_B.Switch_n;
            }

            /* End of Switch: '<S103>/Switch2' */

            /* Product: '<S102>/Product' */
            Motorparasmeters_B.Product_mt = Motorparasmeters_B.Switch2 *
              Motorparasmeters_B.Switch2;

            /* Sum: '<S102>/Sum' */
            Motorparasmeters_B.Sum_e = Motorparasmeters_B.Product_i -
              Motorparasmeters_B.Product_mt;

            /* Product: '<S102>/Product2' */
            Motorparasmeters_B.Product2 = Motorparasmeters_B.Switch_f[1] *
              Motorparasmeters_B.Switch_f[1];

            /* RelationalOperator: '<S102>/Relational Operator' */
            Motorparasmeters_B.RelationalOperator_i = (Motorparasmeters_B.Sum_e >=
              Motorparasmeters_B.Product2);

            /* DataTypeConversion: '<S102>/Data Type Conversion' */
            Motorparasmeters_B.DataTypeConversion_h =
              Motorparasmeters_B.RelationalOperator_i;

            /* If: '<S102>/If' incorporates:
             *  Switch: '<S104>/Switch1'
             */
            if (Motorparasmeters_B.DataTypeConversion_h != 0) {
              /* Outputs for IfAction SubSystem: '<S102>/passThrough' incorporates:
               *  ActionPort: '<S105>/Action Port'
               */
              /* Merge: '<S102>/Merge' incorporates:
               *  SignalConversion generated from: '<S105>/ref2'
               */
              Motorparasmeters_B.Merge_an = Motorparasmeters_B.Switch_f[1];

              /* End of Outputs for SubSystem: '<S102>/passThrough' */
            } else {
              /* Outputs for IfAction SubSystem: '<S102>/limitRef2' incorporates:
               *  ActionPort: '<S104>/Action Port'
               */
              if (Motorparasmeters_B.Sum_e >
                  Motorparasmeters_P.Switch1_Threshold) {
                /* Switch: '<S104>/Switch1' */
                Motorparasmeters_B.Switch1_m = Motorparasmeters_B.Sum_e;
              } else {
                /* Switch: '<S104>/Switch1' incorporates:
                 *  Constant: '<S104>/Constant'
                 */
                Motorparasmeters_B.Switch1_m =
                  Motorparasmeters_P.Constant_Value_j;
              }

              /* Sqrt: '<S104>/Sqrt' */
              mw_arm_sqrt_f32(&Motorparasmeters_B.Switch1_m,
                              &Motorparasmeters_B.Sqrt, 1U);

              /* Switch: '<S104>/Switch' */
              if (Motorparasmeters_B.Switch_f[1] >=
                  Motorparasmeters_P.Switch_Threshold_c) {
                /* Merge: '<S102>/Merge' */
                Motorparasmeters_B.Merge_an = Motorparasmeters_B.Sqrt;
              } else {
                /* Gain: '<S104>/Gain' */
                Motorparasmeters_B.Gain_i = Motorparasmeters_P.Gain_Gain_m *
                  Motorparasmeters_B.Sqrt;

                /* Merge: '<S102>/Merge' */
                Motorparasmeters_B.Merge_an = Motorparasmeters_B.Gain_i;
              }

              /* End of Switch: '<S104>/Switch' */
              /* End of Outputs for SubSystem: '<S102>/limitRef2' */
            }

            /* End of If: '<S102>/If' */

            /* Switch: '<S93>/Switch1' */
            if (Motorparasmeters_B.Compare_n) {
              /* Merge: '<S89>/Merge' */
              Motorparasmeters_B.Merge_f[0] = Motorparasmeters_B.Switch2;
              Motorparasmeters_B.Merge_f[1] = Motorparasmeters_B.Merge_an;
            } else {
              /* Merge: '<S89>/Merge' */
              Motorparasmeters_B.Merge_f[0] = Motorparasmeters_B.Merge_an;
              Motorparasmeters_B.Merge_f[1] = Motorparasmeters_B.Switch2;
            }

            /* End of Switch: '<S93>/Switch1' */
            /* End of Outputs for SubSystem: '<S89>/D//Q Axis Priority' */
          } else {
            /* Outputs for IfAction SubSystem: '<S89>/D-Q Equivalence' incorporates:
             *  ActionPort: '<S92>/Action Port'
             */
            /* RelationalOperator: '<S92>/Relational Operator' */
            Motorparasmeters_B.RelationalOperator_j = (Motorparasmeters_B.Sum1 >
              Motorparasmeters_B.Product_i);

            /* DataTypeConversion: '<S92>/Data Type Conversion' */
            Motorparasmeters_B.DataTypeConversion_f =
              Motorparasmeters_B.RelationalOperator_j;

            /* If: '<S92>/If' */
            if (Motorparasmeters_B.DataTypeConversion_f != 0) {
              /* Outputs for IfAction SubSystem: '<S92>/Limiter' incorporates:
               *  ActionPort: '<S96>/Action Port'
               */
              /* Product: '<S96>/Product' */
              Motorparasmeters_B.Product_c[0] = Motorparasmeters_B.Saturation_h *
                Motorparasmeters_B.Switch_o;
              Motorparasmeters_B.Product_c[1] = Motorparasmeters_B.Saturation *
                Motorparasmeters_B.Switch_o;

              /* Sqrt: '<S96>/Square Root' */
              mw_arm_sqrt_f32(&Motorparasmeters_B.Sum1,
                              &Motorparasmeters_B.SquareRoot, 1U);

              /* Switch: '<S96>/Switch' */
              if (Motorparasmeters_B.SquareRoot != 0.0F) {
                /* Switch: '<S96>/Switch' */
                Motorparasmeters_B.Switch_k = Motorparasmeters_B.SquareRoot;
              } else {
                /* Switch: '<S96>/Switch' incorporates:
                 *  Constant: '<S96>/Constant'
                 */
                Motorparasmeters_B.Switch_k =
                  Motorparasmeters_P.Constant_Value_p;
              }

              /* End of Switch: '<S96>/Switch' */

              /* Merge: '<S89>/Merge' incorporates:
               *  Product: '<S96>/Divide'
               */
              Motorparasmeters_B.Merge_f[0] = Motorparasmeters_B.Product_c[0] /
                Motorparasmeters_B.Switch_k;
              Motorparasmeters_B.Merge_f[1] = Motorparasmeters_B.Product_c[1] /
                Motorparasmeters_B.Switch_k;

              /* End of Outputs for SubSystem: '<S92>/Limiter' */
            } else {
              /* Outputs for IfAction SubSystem: '<S92>/Passthrough' incorporates:
               *  ActionPort: '<S97>/Action Port'
               */
              /* Merge: '<S89>/Merge' incorporates:
               *  SignalConversion generated from: '<S97>/dqRef'
               */
              Motorparasmeters_B.Merge_f[0] = Motorparasmeters_B.Saturation_h;
              Motorparasmeters_B.Merge_f[1] = Motorparasmeters_B.Saturation;

              /* End of Outputs for SubSystem: '<S92>/Passthrough' */
            }

            /* End of If: '<S92>/If' */
            /* End of Outputs for SubSystem: '<S89>/D-Q Equivalence' */
          }

          /* End of If: '<S89>/If' */

          /* Outputs for Atomic SubSystem: '<S66>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S73>/a16' */
          arm_inv_park_f32(Motorparasmeters_B.Merge_f[0],
                           Motorparasmeters_B.Merge_f[1],
                           &Motorparasmeters_B.algDD_o1_a,
                           &Motorparasmeters_B.algDD_o2_j,
                           Motorparasmeters_B.Sum4_h, Motorparasmeters_B.Sum6);

          /* End of Outputs for SubSystem: '<S66>/Two inputs CRL' */

          /* DataStoreRead: '<S18>/Data Store Read1' */
          Motorparasmeters_B.DataStoreRead1_n = Motorparasmeters_DWork.Enable;

          /* Switch: '<S18>/Switch4' incorporates:
           *  Constant: '<S18>/stop'
           */
          if (Motorparasmeters_B.DataStoreRead1_n) {
            /* Gain: '<S81>/sqrt3_by_two' */
            Motorparasmeters_B.sqrt3_by_two =
              Motorparasmeters_P.sqrt3_by_two_Gain *
              Motorparasmeters_B.algDD_o2_j;

            /* Gain: '<S81>/one_by_two' */
            Motorparasmeters_B.one_by_two = Motorparasmeters_P.one_by_two_Gain *
              Motorparasmeters_B.algDD_o1_a;

            /* Sum: '<S81>/add_c' */
            Motorparasmeters_B.add_c = (0.0F - Motorparasmeters_B.one_by_two) -
              Motorparasmeters_B.sqrt3_by_two;

            /* Gain: '<S81>/Kc' */
            Motorparasmeters_B.Kc = Motorparasmeters_P.Kc_Gain *
              Motorparasmeters_B.add_c;

            /* Sum: '<S81>/add_b' */
            Motorparasmeters_B.add_b = Motorparasmeters_B.sqrt3_by_two -
              Motorparasmeters_B.one_by_two;

            /* Gain: '<S81>/Kb' */
            Motorparasmeters_B.Kb = Motorparasmeters_P.Kb_Gain *
              Motorparasmeters_B.add_b;

            /* Gain: '<S81>/Ka' */
            Motorparasmeters_B.Ka = Motorparasmeters_P.Ka_Gain *
              Motorparasmeters_B.algDD_o1_a;

            /* MinMax: '<S78>/Min' */
            Bias = fminf(Motorparasmeters_B.Ka, Motorparasmeters_B.Kb);
            Bias = fminf(Bias, Motorparasmeters_B.Kc);

            /* MinMax: '<S78>/Min' */
            Motorparasmeters_B.Min = Bias;

            /* MinMax: '<S78>/Max' */
            Bias = fmaxf(Motorparasmeters_B.Ka, Motorparasmeters_B.Kb);
            Bias = fmaxf(Bias, Motorparasmeters_B.Kc);

            /* MinMax: '<S78>/Max' */
            Motorparasmeters_B.Max = Bias;

            /* Sum: '<S78>/Add' */
            Motorparasmeters_B.Add = Motorparasmeters_B.Max +
              Motorparasmeters_B.Min;

            /* Gain: '<S78>/one_by_two' */
            Motorparasmeters_B.one_by_two_k =
              Motorparasmeters_P.one_by_two_Gain_g * Motorparasmeters_B.Add;

            /* Sum: '<S77>/Add2' */
            Motorparasmeters_B.Add2 = Motorparasmeters_B.one_by_two_k +
              Motorparasmeters_B.Kc;

            /* Sum: '<S77>/Add1' */
            Motorparasmeters_B.Add1_k = Motorparasmeters_B.Kb +
              Motorparasmeters_B.one_by_two_k;

            /* Sum: '<S77>/Add3' */
            Motorparasmeters_B.Add3 = Motorparasmeters_B.Ka +
              Motorparasmeters_B.one_by_two_k;

            /* Gain: '<S77>/Gain' */
            Motorparasmeters_B.Gain_j[0] = Motorparasmeters_P.Gain_Gain_mr *
              Motorparasmeters_B.Add3;
            Motorparasmeters_B.Gain_j[1] = Motorparasmeters_P.Gain_Gain_mr *
              Motorparasmeters_B.Add1_k;
            Motorparasmeters_B.Gain_j[2] = Motorparasmeters_P.Gain_Gain_mr *
              Motorparasmeters_B.Add2;

            /* Gain: '<S18>/Gain' */
            ADvoltage = Motorparasmeters_P.Gain_Gain_k *
              Motorparasmeters_B.Gain_j[0];
            Motorparasmeters_B.Gain_n[0] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += Motorparasmeters_P.Constant1_Value_a;
            Motorparasmeters_B.Add_c[0] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= Motorparasmeters_P.Gain1_Gain;
            Motorparasmeters_B.Gain1[0] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            Motorparasmeters_B.Switch4[0] = ADvoltage;

            /* Gain: '<S18>/Gain' */
            ADvoltage = Motorparasmeters_P.Gain_Gain_k *
              Motorparasmeters_B.Gain_j[1];
            Motorparasmeters_B.Gain_n[1] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += Motorparasmeters_P.Constant1_Value_a;
            Motorparasmeters_B.Add_c[1] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= Motorparasmeters_P.Gain1_Gain;
            Motorparasmeters_B.Gain1[1] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            Motorparasmeters_B.Switch4[1] = ADvoltage;

            /* Gain: '<S18>/Gain' */
            ADvoltage = Motorparasmeters_P.Gain_Gain_k *
              Motorparasmeters_B.Gain_j[2];
            Motorparasmeters_B.Gain_n[2] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += Motorparasmeters_P.Constant1_Value_a;
            Motorparasmeters_B.Add_c[2] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= Motorparasmeters_P.Gain1_Gain;
            Motorparasmeters_B.Gain1[2] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            Motorparasmeters_B.Switch4[2] = ADvoltage;
          } else {
            ADvoltage = Motorparasmeters_P.stop_Value;

            /* Switch: '<S18>/Switch4' incorporates:
             *  Constant: '<S18>/stop'
             */
            Motorparasmeters_B.Switch4[0] = ADvoltage;
            Motorparasmeters_B.Switch4[1] = ADvoltage;
            Motorparasmeters_B.Switch4[2] = ADvoltage;
          }

          /* End of Switch: '<S18>/Switch4' */

          /* Gain: '<S18>/Gain2' */
          Motorparasmeters_B.Gain2 = Motorparasmeters_P.Gain2_Gain *
            Motorparasmeters_B.Switch4[0];

          /* Sum: '<S18>/Add1' incorporates:
           *  Constant: '<S18>/Constant2'
           */
          Motorparasmeters_B.Add1_m = Motorparasmeters_B.Gain2 -
            Motorparasmeters_P.Constant2_Value_p;

          /* Gain: '<S18>/Gain3' */
          Motorparasmeters_B.Gain3 = Motorparasmeters_P.Gain3_Gain *
            Motorparasmeters_B.Add1_m;

          /* Gain: '<S12>/Gain' */
          Motorparasmeters_B.Gain = Motorparasmeters_P.Gain_Gain_kz *
            Motorparasmeters_B.Gain3;

          /* Signum: '<S30>/Sign' */
          ADvoltage = Motorparasmeters_B.Sum2;
          if (rtIsNaNF(ADvoltage)) {
            /* Signum: '<S30>/Sign' */
            Motorparasmeters_B.Sign = (rtNaNF);
          } else if (ADvoltage < 0.0F) {
            /* Signum: '<S30>/Sign' */
            Motorparasmeters_B.Sign = -1.0F;
          } else {
            /* Signum: '<S30>/Sign' */
            Motorparasmeters_B.Sign = (real32_T)(ADvoltage > 0.0F);
          }

          /* End of Signum: '<S30>/Sign' */

          /* Gain: '<S30>/Eta' incorporates:
           *  Gain: '<S31>/Eta'
           */
          y_tmp = Motorparasmeters_P.SlidingModeObserver_CurrentObse /
            2.1999999999999997;
          Bias = (real32_T)y_tmp;

          /* Gain: '<S30>/Eta' */
          Motorparasmeters_B.Eta = Bias * Motorparasmeters_B.Sign;

          /* Sum: '<S30>/Sum' */
          Motorparasmeters_B.Sum_c = Motorparasmeters_B.Delay5[0] -
            Motorparasmeters_B.Sum4;

          /* Gain: '<S30>/b' */
          Motorparasmeters_B.b = Motorparasmeters_P.b_Gain *
            Motorparasmeters_B.Sum_c;

          /* Gain: '<S30>/a' */
          Motorparasmeters_B.a_n = Motorparasmeters_P.a_Gain_a *
            Motorparasmeters_B.Delay_b;

          /* Sum: '<S30>/Sum1' */
          Motorparasmeters_B.Sum1_n = (Motorparasmeters_B.b -
            Motorparasmeters_B.Eta) + Motorparasmeters_B.a_n;

          /* Signum: '<S31>/Sign' */
          ADvoltage = Motorparasmeters_B.Sum2_e;
          if (rtIsNaNF(ADvoltage)) {
            /* Signum: '<S31>/Sign' */
            Motorparasmeters_B.Sign_b = (rtNaNF);
          } else if (ADvoltage < 0.0F) {
            /* Signum: '<S31>/Sign' */
            Motorparasmeters_B.Sign_b = -1.0F;
          } else {
            /* Signum: '<S31>/Sign' */
            Motorparasmeters_B.Sign_b = (real32_T)(ADvoltage > 0.0F);
          }

          /* End of Signum: '<S31>/Sign' */

          /* Gain: '<S31>/Eta' */
          Motorparasmeters_B.Eta_h = Bias * Motorparasmeters_B.Sign_b;

          /* Sum: '<S31>/Sum' */
          Motorparasmeters_B.Sum_l = Motorparasmeters_B.Delay5[1] -
            Motorparasmeters_B.Sum4_d;

          /* Gain: '<S31>/b' */
          Motorparasmeters_B.b_j = Motorparasmeters_P.b_Gain_g *
            Motorparasmeters_B.Sum_l;

          /* Gain: '<S31>/a' */
          Motorparasmeters_B.a_k = Motorparasmeters_P.a_Gain_g *
            Motorparasmeters_B.Delay_f;

          /* Sum: '<S31>/Sum1' */
          Motorparasmeters_B.Sum1_m = (Motorparasmeters_B.b_j -
            Motorparasmeters_B.Eta_h) + Motorparasmeters_B.a_k;

          /* Gain: '<S35>/PositionToCount' */
          Motorparasmeters_B.PositionToCount = (uint32_T)
            (Motorparasmeters_P.PositionToCount_Gain *
             Motorparasmeters_B.Switch_o3);

          /* Delay: '<S35>/Delay' */
          Motorparasmeters_B.Delay =
            Motorparasmeters_DWork.Delay_DSTATE_a[Motorparasmeters_DWork.CircBufIdx];

          /* Sum: '<S35>/SpeedCount' */
          Motorparasmeters_B.SpeedCount = (int32_T)
            Motorparasmeters_B.PositionToCount - (int32_T)
            Motorparasmeters_B.Delay;

          /* DataTypeConversion: '<S52>/DTC' */
          Motorparasmeters_B.DTC = (real32_T)Motorparasmeters_B.SpeedCount;

          /* Gain: '<S35>/SpeedGain' */
          Motorparasmeters_B.SpeedGain = Motorparasmeters_P.SpeedGain_Gain *
            Motorparasmeters_B.DTC;

          /* Switch: '<S34>/Switch1' incorporates:
           *  Constant: '<S34>/UseInputPort'
           */
          if (Motorparasmeters_P.UseInputPort_Value_p >
              Motorparasmeters_P.Switch1_Threshold_a) {
            /* Sum: '<S34>/Sum' incorporates:
             *  Constant: '<S34>/One'
             *  Constant: '<S34>/a'
             */
            Motorparasmeters_B.Sum_bn = Motorparasmeters_P.One_Value_e -
              Motorparasmeters_P.a_Value_i;

            /* Switch: '<S34>/Switch1' incorporates:
             *  Constant: '<S34>/a'
             */
            Motorparasmeters_B.Switch1_d[0] = Motorparasmeters_P.a_Value_i;
            Motorparasmeters_B.Switch1_d[1] = Motorparasmeters_B.Sum_bn;
          } else {
            /* Switch: '<S34>/Switch1' incorporates:
             *  Constant: '<S34>/FilterConstant'
             *  Constant: '<S34>/OneMinusFilterConstant'
             */
            Motorparasmeters_B.Switch1_d[0] =
              Motorparasmeters_P.FilterConstant_Value_o;
            Motorparasmeters_B.Switch1_d[1] =
              Motorparasmeters_P.OneMinusFilterConstant_Value_n;
          }

          /* End of Switch: '<S34>/Switch1' */

          /* Product: '<S50>/Product' */
          Motorparasmeters_B.Product_m = Motorparasmeters_B.SpeedGain *
            Motorparasmeters_B.Switch1_d[0];

          /* UnitDelay: '<S50>/Unit Delay' */
          Motorparasmeters_B.UnitDelay_i =
            Motorparasmeters_DWork.UnitDelay_DSTATE_bl;

          /* Product: '<S50>/Product1' */
          Motorparasmeters_B.Product1_l2 = Motorparasmeters_B.Switch1_d[1] *
            Motorparasmeters_B.UnitDelay_i;

          /* Sum: '<S50>/Add1' */
          Motorparasmeters_B.Add1_g = Motorparasmeters_B.Product_m +
            Motorparasmeters_B.Product1_l2;

          /* DeadZone: '<S134>/DeadZone' */
          if (Motorparasmeters_B.Sum_o >
              Motorparasmeters_P.DiscretePIControllerwithantiw_b) {
            /* DeadZone: '<S134>/DeadZone' */
            Motorparasmeters_B.DeadZone = Motorparasmeters_B.Sum_o -
              Motorparasmeters_P.DiscretePIControllerwithantiw_b;
          } else if (Motorparasmeters_B.Sum_o >=
                     Motorparasmeters_P.DiscretePIControllerwithantiw_f) {
            /* DeadZone: '<S134>/DeadZone' */
            Motorparasmeters_B.DeadZone = 0.0F;
          } else {
            /* DeadZone: '<S134>/DeadZone' */
            Motorparasmeters_B.DeadZone = Motorparasmeters_B.Sum_o -
              Motorparasmeters_P.DiscretePIControllerwithantiw_f;
          }

          /* End of DeadZone: '<S134>/DeadZone' */

          /* RelationalOperator: '<S132>/Relational Operator' incorporates:
           *  Constant: '<S132>/Clamping_zero'
           */
          Motorparasmeters_B.RelationalOperator =
            (Motorparasmeters_P.Clamping_zero_Value !=
             Motorparasmeters_B.DeadZone);

          /* RelationalOperator: '<S132>/fix for DT propagation issue' incorporates:
           *  Constant: '<S132>/Clamping_zero'
           */
          Motorparasmeters_B.fixforDTpropagationissue =
            (Motorparasmeters_B.DeadZone >
             Motorparasmeters_P.Clamping_zero_Value);

          /* Switch: '<S132>/Switch1' */
          if (Motorparasmeters_B.fixforDTpropagationissue) {
            /* Switch: '<S132>/Switch1' incorporates:
             *  Constant: '<S132>/Constant'
             */
            Motorparasmeters_B.Switch1_dl = Motorparasmeters_P.Constant_Value_l;
          } else {
            /* Switch: '<S132>/Switch1' incorporates:
             *  Constant: '<S132>/Constant2'
             */
            Motorparasmeters_B.Switch1_dl = Motorparasmeters_P.Constant2_Value_i;
          }

          /* End of Switch: '<S132>/Switch1' */

          /* Product: '<S139>/IProd Out' incorporates:
           *  Constant: '<S70>/Ki'
           */
          Motorparasmeters_B.IProdOut = Motorparasmeters_B.Sum_b *
            Motorparasmeters_P.Ki_Value;

          /* RelationalOperator: '<S132>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S132>/Clamping_zero'
           */
          Motorparasmeters_B.fixforDTpropagationissue1 =
            (Motorparasmeters_B.IProdOut >
             Motorparasmeters_P.Clamping_zero_Value);

          /* Switch: '<S132>/Switch2' */
          if (Motorparasmeters_B.fixforDTpropagationissue1) {
            /* Switch: '<S132>/Switch2' incorporates:
             *  Constant: '<S132>/Constant3'
             */
            Motorparasmeters_B.Switch2_g = Motorparasmeters_P.Constant3_Value_m;
          } else {
            /* Switch: '<S132>/Switch2' incorporates:
             *  Constant: '<S132>/Constant4'
             */
            Motorparasmeters_B.Switch2_g = Motorparasmeters_P.Constant4_Value_l;
          }

          /* End of Switch: '<S132>/Switch2' */

          /* RelationalOperator: '<S132>/Equal1' */
          Motorparasmeters_B.Equal1 = (Motorparasmeters_B.Switch1_dl ==
            Motorparasmeters_B.Switch2_g);

          /* Logic: '<S132>/AND3' */
          Motorparasmeters_B.AND3 = (Motorparasmeters_B.RelationalOperator &&
            Motorparasmeters_B.Equal1);

          /* Switch: '<S132>/Switch' */
          if (Motorparasmeters_B.AND3) {
            /* Switch: '<S132>/Switch' incorporates:
             *  Constant: '<S132>/Constant1'
             */
            Motorparasmeters_B.Switch_g = Motorparasmeters_P.Constant1_Value_k;
          } else {
            /* Switch: '<S132>/Switch' */
            Motorparasmeters_B.Switch_g = Motorparasmeters_B.IProdOut;
          }

          /* End of Switch: '<S132>/Switch' */

          /* DeadZone: '<S187>/DeadZone' */
          if (Motorparasmeters_B.Sum_i >
              Motorparasmeters_P.DiscretePIControllerwithantiw_e) {
            /* DeadZone: '<S187>/DeadZone' */
            Motorparasmeters_B.DeadZone_h = Motorparasmeters_B.Sum_i -
              Motorparasmeters_P.DiscretePIControllerwithantiw_e;
          } else if (Motorparasmeters_B.Sum_i >=
                     Motorparasmeters_P.DiscretePIControllerwithantiwin) {
            /* DeadZone: '<S187>/DeadZone' */
            Motorparasmeters_B.DeadZone_h = 0.0F;
          } else {
            /* DeadZone: '<S187>/DeadZone' */
            Motorparasmeters_B.DeadZone_h = Motorparasmeters_B.Sum_i -
              Motorparasmeters_P.DiscretePIControllerwithantiwin;
          }

          /* End of DeadZone: '<S187>/DeadZone' */

          /* RelationalOperator: '<S185>/Relational Operator' incorporates:
           *  Constant: '<S185>/Clamping_zero'
           */
          Motorparasmeters_B.RelationalOperator_l =
            (Motorparasmeters_P.Clamping_zero_Value_k !=
             Motorparasmeters_B.DeadZone_h);

          /* RelationalOperator: '<S185>/fix for DT propagation issue' incorporates:
           *  Constant: '<S185>/Clamping_zero'
           */
          Motorparasmeters_B.fixforDTpropagationissue_i =
            (Motorparasmeters_B.DeadZone_h >
             Motorparasmeters_P.Clamping_zero_Value_k);

          /* Switch: '<S185>/Switch1' */
          if (Motorparasmeters_B.fixforDTpropagationissue_i) {
            /* Switch: '<S185>/Switch1' incorporates:
             *  Constant: '<S185>/Constant'
             */
            Motorparasmeters_B.Switch1_c = Motorparasmeters_P.Constant_Value_jm;
          } else {
            /* Switch: '<S185>/Switch1' incorporates:
             *  Constant: '<S185>/Constant2'
             */
            Motorparasmeters_B.Switch1_c = Motorparasmeters_P.Constant2_Value_e;
          }

          /* End of Switch: '<S185>/Switch1' */

          /* Product: '<S192>/IProd Out' incorporates:
           *  Constant: '<S70>/Ki'
           */
          Motorparasmeters_B.IProdOut_b = Motorparasmeters_B.Sum_k *
            Motorparasmeters_P.Ki_Value;

          /* RelationalOperator: '<S185>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S185>/Clamping_zero'
           */
          Motorparasmeters_B.fixforDTpropagationissue1_m =
            (Motorparasmeters_B.IProdOut_b >
             Motorparasmeters_P.Clamping_zero_Value_k);

          /* Switch: '<S185>/Switch2' */
          if (Motorparasmeters_B.fixforDTpropagationissue1_m) {
            /* Switch: '<S185>/Switch2' incorporates:
             *  Constant: '<S185>/Constant3'
             */
            Motorparasmeters_B.Switch2_m = Motorparasmeters_P.Constant3_Value_h;
          } else {
            /* Switch: '<S185>/Switch2' incorporates:
             *  Constant: '<S185>/Constant4'
             */
            Motorparasmeters_B.Switch2_m = Motorparasmeters_P.Constant4_Value_m;
          }

          /* End of Switch: '<S185>/Switch2' */

          /* RelationalOperator: '<S185>/Equal1' */
          Motorparasmeters_B.Equal1_n = (Motorparasmeters_B.Switch1_c ==
            Motorparasmeters_B.Switch2_m);

          /* Logic: '<S185>/AND3' */
          Motorparasmeters_B.AND3_m = (Motorparasmeters_B.RelationalOperator_l &&
            Motorparasmeters_B.Equal1_n);

          /* Switch: '<S185>/Switch' */
          if (Motorparasmeters_B.AND3_m) {
            /* Switch: '<S185>/Switch' incorporates:
             *  Constant: '<S185>/Constant1'
             */
            Motorparasmeters_B.Switch_e = Motorparasmeters_P.Constant1_Value_c;
          } else {
            /* Switch: '<S185>/Switch' */
            Motorparasmeters_B.Switch_e = Motorparasmeters_B.IProdOut_b;
          }

          /* End of Switch: '<S185>/Switch' */

          /* MATLABSystem: '<S214>/PWM Output' */
          setDutyCycleInPercentageChannel1
            (Motorparasmeters_DWork.obj_e3.TimerHandle,
             Motorparasmeters_B.Switch4[0]);
          setDutyCycleInPercentageChannel2
            (Motorparasmeters_DWork.obj_e3.TimerHandle,
             Motorparasmeters_B.Switch4[1]);
          setDutyCycleInPercentageChannel3
            (Motorparasmeters_DWork.obj_e3.TimerHandle,
             Motorparasmeters_B.Switch4[2]);

          /* SignalConversion generated from: '<S2>/Delay5' */
          Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[0] =
            Motorparasmeters_B.algDD_o1_a;
          Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[1] =
            Motorparasmeters_B.algDD_o2_j;
          Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[2] =
            Motorparasmeters_B.Kalpha;
          Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[3] =
            Motorparasmeters_B.Kbeta;

          /* Update for UnitDelay: '<S40>/Unit Delay1' */
          Motorparasmeters_DWork.UnitDelay1_DSTATE = Motorparasmeters_B.Eta;

          /* Update for UnitDelay: '<S40>/Unit Delay' */
          Motorparasmeters_DWork.UnitDelay_DSTATE = Motorparasmeters_B.Sum2;

          /* Update for Delay: '<S2>/Delay5' */
          Motorparasmeters_DWork.Delay5_DSTATE[0] =
            Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[0];
          Motorparasmeters_DWork.Delay5_DSTATE[1] =
            Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[1];
          Motorparasmeters_DWork.Delay5_DSTATE[2] =
            Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[2];
          Motorparasmeters_DWork.Delay5_DSTATE[3] =
            Motorparasmeters_B.TmpSignalConversionAtDelay5Inpo[3];

          /* Update for Delay: '<S30>/Delay' */
          Motorparasmeters_DWork.Delay_DSTATE = Motorparasmeters_B.Sum1_n;

          /* Update for Delay: '<S40>/Delay1' */
          Motorparasmeters_DWork.Delay1_DSTATE = Motorparasmeters_B.Sum4;

          /* Update for UnitDelay: '<S44>/Unit Delay' */
          Motorparasmeters_DWork.UnitDelay_DSTATE_b = Motorparasmeters_B.Add1_o;

          /* Update for UnitDelay: '<S41>/Unit Delay1' */
          Motorparasmeters_DWork.UnitDelay1_DSTATE_m = Motorparasmeters_B.Eta_h;

          /* Update for UnitDelay: '<S41>/Unit Delay' */
          Motorparasmeters_DWork.UnitDelay_DSTATE_p = Motorparasmeters_B.Sum2_e;

          /* Update for Delay: '<S31>/Delay' */
          Motorparasmeters_DWork.Delay_DSTATE_h = Motorparasmeters_B.Sum1_m;

          /* Update for Delay: '<S41>/Delay1' */
          Motorparasmeters_DWork.Delay1_DSTATE_e = Motorparasmeters_B.Sum4_d;

          /* Update for UnitDelay: '<S47>/Unit Delay' */
          Motorparasmeters_DWork.UnitDelay_DSTATE_d = Motorparasmeters_B.Add1_p;

          /* Update for Delay: '<S28>/Delay' */
          Motorparasmeters_DWork.Delay_DSTATE_p = Motorparasmeters_B.Add1_g;

          /* Update for UnitDelay: '<S62>/Unit Delay' */
          Motorparasmeters_DWork.UnitDelay_DSTATE_bp =
            Motorparasmeters_B.Add1_mo;

          /* Update for DiscreteIntegrator: '<S195>/Integrator' */
          Motorparasmeters_DWork.Integrator_DSTATE +=
            Motorparasmeters_P.Integrator_gainval * Motorparasmeters_B.Switch_e;
          Integrator_PrevResetState_tmp = (int8_T)
            Motorparasmeters_B.LogicalOperator_n;
          Motorparasmeters_DWork.Integrator_PrevResetState =
            Integrator_PrevResetState_tmp;

          /* Update for DiscreteIntegrator: '<S142>/Integrator' */
          Motorparasmeters_DWork.Integrator_DSTATE_l +=
            Motorparasmeters_P.Integrator_gainval_p *
            Motorparasmeters_B.Switch_g;
          Motorparasmeters_DWork.Integrator_PrevResetState_i =
            Integrator_PrevResetState_tmp;

          /* Update for Delay: '<S35>/Delay' */
          Motorparasmeters_DWork.Delay_DSTATE_a[Motorparasmeters_DWork.CircBufIdx]
            = Motorparasmeters_B.PositionToCount;
          if (Motorparasmeters_DWork.CircBufIdx < 118U) {
            Motorparasmeters_DWork.CircBufIdx++;
          } else {
            Motorparasmeters_DWork.CircBufIdx = 0U;
          }

          /* End of Update for Delay: '<S35>/Delay' */

          /* Update for UnitDelay: '<S50>/Unit Delay' */
          Motorparasmeters_DWork.UnitDelay_DSTATE_bl = Motorparasmeters_B.Add1_g;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S216>/Hardware Interrupt' */

        /* RateTransition: '<Root>/RT1' incorporates:
         *  Gain: '<S55>/OP_Gain*R_shunt1'
         */
        Motorparasmeters_DWork.RT1_Buffer
          [(Motorparasmeters_DWork.RT1_semaphoreTaken == 0) << 1] =
          Motorparasmeters_B.OP_GainR_shunt1[0];
        Motorparasmeters_DWork.RT1_Buffer[1 +
          ((Motorparasmeters_DWork.RT1_semaphoreTaken == 0) << 1)] =
          Motorparasmeters_B.OP_GainR_shunt1[1];
        Motorparasmeters_DWork.RT1_ActiveBufIdx = (int8_T)
          (Motorparasmeters_DWork.RT1_semaphoreTaken == 0);
      }
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void Motorparasmeters_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
