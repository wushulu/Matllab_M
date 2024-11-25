/*
 * File: IFstart.c
 *
 * Code generated for Simulink model 'IFstart'.
 *
 * Model version                  : 8.20
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Nov 25 09:02:04 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "IFstart.h"
#include "IFstart_types.h"
#include "IFstart_private.h"
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
BlockIO_IFstart IFstart_B;

/* Block states (default storage) */
D_Work_IFstart IFstart_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_IFstart IFstart_PrevZCSigState;

/* Real-time model */
static RT_MODEL_IFstart IFstart_M_;
RT_MODEL_IFstart *const IFstart_M = &IFstart_M_;

/* Forward declaration for local functions */
static void IFstart_SystemCore_setup(stm32cube_blocks_AnalogInput_IF *obj);
static void IFstart_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_IFst *obj);

/* Forward declaration for local functions */
static void IFstart_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_IFst *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void IFstart_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(IFstart_M, 1));
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
  (IFstart_M->Timing.TaskCounters.TID[1])++;
  if ((IFstart_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    IFstart_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void IFstart_SystemCore_setup(stm32cube_blocks_AnalogInput_IF *obj)
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

static void IFstart_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_IFst *obj)
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

static void IFstart_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_IFst *obj)
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
void IFstart_step0(void)               /* Sample time: [0.001s, 0.0s] */
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
  IFstart_B.DigitalPortRead = tmp;

  /* UnitDelay: '<S1>/Unit Delay' */
  IFstart_B.UnitDelay_f = IFstart_DWork.UnitDelay_DSTATE_k;

  /* Logic: '<S1>/NOT2' */
  IFstart_B.NOT2 = !IFstart_B.UnitDelay_f;

  /* Logic: '<S1>/AND' */
  IFstart_B.AND = (IFstart_B.DigitalPortRead && IFstart_B.NOT2);

  /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S8>/Enable'
   */
  if (IFstart_B.AND) {
    /* UnitDelay: '<S8>/Unit Delay' */
    IFstart_B.UnitDelay_a = IFstart_DWork.UnitDelay_DSTATE_a;

    /* Logic: '<S8>/NOT' */
    IFstart_B.NOT_n = !IFstart_B.UnitDelay_a;

    /* Update for UnitDelay: '<S8>/Unit Delay' */
    IFstart_DWork.UnitDelay_DSTATE_a = IFstart_B.NOT_n;
  }

  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  IFstart_DWork.Enable = IFstart_B.UnitDelay_a;

  /* RateTransition: '<Root>/RT' */
  IFstart_B.RT_n = IFstart_B.AngleConversion;

  /* Assignment: '<S6>/Assignment' incorporates:
   *  Constant: '<S6>/Constant'
   */
  IFstart_B.Assignment[0] = IFstart_P.Constant_Value_nt[0];
  IFstart_B.Assignment[1] = IFstart_P.Constant_Value_nt[1];
  IFstart_B.Assignment[2] = IFstart_P.Constant_Value_nt[2];

  /* Assignment: '<S6>/Assignment' incorporates:
   *  Constant: '<S6>/Constant2'
   */
  IFstart_B.Assignment[IFstart_P.Constant2_Value_nq] = IFstart_B.RT_n;

  /* RateTransition: '<Root>/RT1' */
  IFstart_DWork.RT1_semaphoreTaken = IFstart_DWork.RT1_ActiveBufIdx;
  tmp_0 = IFstart_DWork.RT1_semaphoreTaken << 1;

  /* RateTransition: '<Root>/RT1' */
  IFstart_B.RT1[0] = IFstart_DWork.RT1_Buffer[tmp_0];
  IFstart_B.RT1[1] = IFstart_DWork.RT1_Buffer[tmp_0 + 1];

  /* Assignment: '<S6>/Assignment1' */
  IFstart_B.Assignment1[0] = IFstart_B.Assignment[0];
  IFstart_B.Assignment1[1] = IFstart_B.Assignment[1];
  IFstart_B.Assignment1[2] = IFstart_B.Assignment[2];

  /* Assignment: '<S6>/Assignment1' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  IFstart_B.Assignment1[IFstart_P.Constant3_Value_e] = IFstart_B.RT1[0];

  /* Assignment: '<S6>/Assignment2' */
  IFstart_B.Assignment2[0] = IFstart_B.Assignment1[0];
  IFstart_B.Assignment2[1] = IFstart_B.Assignment1[1];
  IFstart_B.Assignment2[2] = IFstart_B.Assignment1[2];

  /* Assignment: '<S6>/Assignment2' incorporates:
   *  Constant: '<S6>/Constant1'
   */
  IFstart_B.Assignment2[IFstart_P.Constant1_Value_d] = IFstart_B.RT1[1];

  /* MATLABSystem: '<S219>/UART//USART Write' incorporates:
   *  Constant: '<S219>/Constant4'
   */
  pinReadLoc = 3U;
  if (IFstart_P.Constant4_Value_b < 3U) {
    pinReadLoc = IFstart_P.Constant4_Value_b;
  }

  uartWriteData[0] = IFstart_B.Assignment2[0];
  uartWriteData[1] = IFstart_B.Assignment2[1];
  uartWriteData[2] = IFstart_B.Assignment2[2];

  /* Start for MATLABSystem: '<S219>/UART//USART Write' */
  tmp_0 = (int32_T)pinReadLoc;
  tmp_0 = (int32_T)((uint32_T)tmp_0 << 2);

  /* MATLABSystem: '<S219>/UART//USART Write' */
  status = MW_LPUART_TransmitUsingInterrupt(IFstart_DWork.obj.UARTHandle,
    &uartWriteData[0], (uint32_T)tmp_0, 0U, &sentLength);

  /* MATLABSystem: '<S219>/UART//USART Write' */
  IFstart_B.UARTUSARTWrite = status;

  /* Logic: '<S219>/NOT' */
  IFstart_B.NOT = (IFstart_B.UARTUSARTWrite == 0);

  /* Outputs for Enabled SubSystem: '<S219>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S220>/Enable'
   */
  if (IFstart_B.NOT) {
    /* MATLABSystem: '<S220>/UART//USART Write' incorporates:
     *  Constant: '<S220>/Constant1'
     *  Constant: '<S220>/Constant2'
     * */
    pinReadLoc = 4U;
    if (IFstart_P.Constant2_Value_n < 4U) {
      pinReadLoc = IFstart_P.Constant2_Value_n;
    }

    uartWriteData_0[0] = IFstart_P.Constant1_Value_f[0];
    uartWriteData_0[1] = IFstart_P.Constant1_Value_f[1];
    uartWriteData_0[2] = IFstart_P.Constant1_Value_f[2];
    uartWriteData_0[3] = IFstart_P.Constant1_Value_f[3];
    MW_LPUART_TransmitUsingInterrupt(IFstart_DWork.obj_e.UARTHandle,
      &uartWriteData_0[0], pinReadLoc, 0U, &sentLength);

    /* End of MATLABSystem: '<S220>/UART//USART Write' */
  }

  /* End of Outputs for SubSystem: '<S219>/Enabled Subsystem' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  IFstart_DWork.UnitDelay_DSTATE_k = IFstart_B.DigitalPortRead;
}

/* Model step function for TID1 */
void IFstart_step1(void)               /* Sample time: [0.1s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  int32_T c;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  IFstart_B.LED = (IFstart_DWork.clockTickCounter <
                   IFstart_P.PulseGenerator_Duty) &&
    (IFstart_DWork.clockTickCounter >= 0) ? IFstart_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  if (IFstart_DWork.clockTickCounter >= IFstart_P.PulseGenerator_Period - 1.0) {
    IFstart_DWork.clockTickCounter = 0;
  } else {
    IFstart_DWork.clockTickCounter++;
  }

  /* MATLABSystem: '<S218>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (IFstart_B.LED != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S218>/Digital Port Write' */
}

/* Model initialize function */
void IFstart_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)IFstart_M, 0,
                sizeof(RT_MODEL_IFstart));

  /* block I/O */
  (void) memset(((void *) &IFstart_B), 0,
                sizeof(BlockIO_IFstart));

  {
    IFstart_B.LED = 0.0;
    IFstart_B.RT_n = 0.0F;
    IFstart_B.Assignment[0] = 0.0F;
    IFstart_B.Assignment[1] = 0.0F;
    IFstart_B.Assignment[2] = 0.0F;
    IFstart_B.RT1[0] = 0.0F;
    IFstart_B.RT1[1] = 0.0F;
    IFstart_B.Assignment1[0] = 0.0F;
    IFstart_B.Assignment1[1] = 0.0F;
    IFstart_B.Assignment1[2] = 0.0F;
    IFstart_B.Assignment2[0] = 0.0F;
    IFstart_B.Assignment2[1] = 0.0F;
    IFstart_B.Assignment2[2] = 0.0F;
    IFstart_B.Switch[0] = 0.0F;
    IFstart_B.Switch[1] = 0.0F;
    IFstart_B.ADvoltage[0] = 0.0F;
    IFstart_B.ADvoltage[1] = 0.0F;
    IFstart_B.OP_GainR_shunt[0] = 0.0F;
    IFstart_B.OP_GainR_shunt[1] = 0.0F;
    IFstart_B.OP_GainR_shunt1[0] = 0.0F;
    IFstart_B.OP_GainR_shunt1[1] = 0.0F;
    IFstart_B.Kalpha = 0.0F;
    IFstart_B.Kbeta = 0.0F;
    IFstart_B.UnitDelay1 = 0.0F;
    IFstart_B.UnitDelay = 0.0F;
    IFstart_B.a = 0.0F;
    IFstart_B.Delay5[0] = 0.0F;
    IFstart_B.Delay5[1] = 0.0F;
    IFstart_B.Delay5[2] = 0.0F;
    IFstart_B.Delay5[3] = 0.0F;
    IFstart_B.Delay_b = 0.0F;
    IFstart_B.Sum2 = 0.0F;
    IFstart_B.Sum3 = 0.0F;
    IFstart_B.b_invg = 0.0F;
    IFstart_B.Delay1 = 0.0F;
    IFstart_B.Sum4 = 0.0F;
    IFstart_B.Switch1[0] = 0.0F;
    IFstart_B.Switch1[1] = 0.0F;
    IFstart_B.Product = 0.0F;
    IFstart_B.UnitDelay_e = 0.0F;
    IFstart_B.Product1 = 0.0F;
    IFstart_B.Add1_o = 0.0F;
    IFstart_B.UnitDelay1_e = 0.0F;
    IFstart_B.UnitDelay_c = 0.0F;
    IFstart_B.a_c = 0.0F;
    IFstart_B.Delay_f = 0.0F;
    IFstart_B.Sum2_e = 0.0F;
    IFstart_B.Sum3_m = 0.0F;
    IFstart_B.b_invg_d = 0.0F;
    IFstart_B.Delay1_f = 0.0F;
    IFstart_B.Sum4_d = 0.0F;
    IFstart_B.Switch1_o[0] = 0.0F;
    IFstart_B.Switch1_o[1] = 0.0F;
    IFstart_B.Product_b = 0.0F;
    IFstart_B.UnitDelay_m = 0.0F;
    IFstart_B.Product1_l = 0.0F;
    IFstart_B.Add1_p = 0.0F;
    IFstart_B.Merge = 0.0F;
    IFstart_B.Merge1 = 0.0F;
    IFstart_B.Delay_fn = 0.0F;
    IFstart_B.PhaseDelay = 0.0F;
    IFstart_B.AngleConversion = 0.0F;
    IFstart_B.Merge_a = 0.0F;
    IFstart_B.scaleIn = 0.0F;
    IFstart_B.UnitDelay_h = 0.0F;
    IFstart_B.Switch_n = 0.0F;
    IFstart_B.convert_pu = 0.0F;
    IFstart_B.Merge_e = 0.0F;
    IFstart_B.indexing = 0.0F;
    IFstart_B.Lookup[0] = 0.0F;
    IFstart_B.Lookup[1] = 0.0F;
    IFstart_B.Lookup[2] = 0.0F;
    IFstart_B.Lookup[3] = 0.0F;
    IFstart_B.Sum3_i = 0.0F;
    IFstart_B.DataTypeConversion1 = 0.0F;
    IFstart_B.Sum2_g = 0.0F;
    IFstart_B.Product_h = 0.0F;
    IFstart_B.Sum4_h = 0.0F;
    IFstart_B.Sum5 = 0.0F;
    IFstart_B.Product1_k = 0.0F;
    IFstart_B.Sum6 = 0.0F;
    IFstart_B.Sum_k = 0.0F;
    IFstart_B.PProdOut = 0.0F;
    IFstart_B.Vq_OpenLoop = 0.0F;
    IFstart_B.Integrator = 0.0F;
    IFstart_B.Sum_i = 0.0F;
    IFstart_B.Saturation = 0.0F;
    IFstart_B.Sum_b = 0.0F;
    IFstart_B.PProdOut_i = 0.0F;
    IFstart_B.Constant = 0.0F;
    IFstart_B.Integrator_a = 0.0F;
    IFstart_B.Sum_o = 0.0F;
    IFstart_B.Saturation_h = 0.0F;
    IFstart_B.Switch_o = 0.0F;
    IFstart_B.Product_i = 0.0F;
    IFstart_B.Product_hz = 0.0F;
    IFstart_B.Product1_n = 0.0F;
    IFstart_B.Sum1 = 0.0F;
    IFstart_B.Merge_f[0] = 0.0F;
    IFstart_B.Merge_f[1] = 0.0F;
    IFstart_B.Switch4[0] = 0.0F;
    IFstart_B.Switch4[1] = 0.0F;
    IFstart_B.Switch4[2] = 0.0F;
    IFstart_B.Sign = 0.0F;
    IFstart_B.Eta = 0.0F;
    IFstart_B.Sum_c = 0.0F;
    IFstart_B.b = 0.0F;
    IFstart_B.a_n = 0.0F;
    IFstart_B.Sum1_n = 0.0F;
    IFstart_B.Sign_b = 0.0F;
    IFstart_B.Eta_h = 0.0F;
    IFstart_B.Sum_l = 0.0F;
    IFstart_B.b_j = 0.0F;
    IFstart_B.a_k = 0.0F;
    IFstart_B.Sum1_m = 0.0F;
    IFstart_B.DTC = 0.0F;
    IFstart_B.SpeedGain = 0.0F;
    IFstart_B.Switch1_d[0] = 0.0F;
    IFstart_B.Switch1_d[1] = 0.0F;
    IFstart_B.Product_m = 0.0F;
    IFstart_B.UnitDelay_i = 0.0F;
    IFstart_B.Product1_l2 = 0.0F;
    IFstart_B.Add1_g = 0.0F;
    IFstart_B.DeadZone = 0.0F;
    IFstart_B.IProdOut = 0.0F;
    IFstart_B.Switch_g = 0.0F;
    IFstart_B.DeadZone_h = 0.0F;
    IFstart_B.IProdOut_b = 0.0F;
    IFstart_B.Switch_e = 0.0F;
    IFstart_B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    IFstart_B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    IFstart_B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    IFstart_B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    IFstart_B.sqrt3_by_two = 0.0F;
    IFstart_B.one_by_two = 0.0F;
    IFstart_B.add_c = 0.0F;
    IFstart_B.Kc = 0.0F;
    IFstart_B.add_b = 0.0F;
    IFstart_B.Kb = 0.0F;
    IFstart_B.Ka = 0.0F;
    IFstart_B.Min = 0.0F;
    IFstart_B.Max = 0.0F;
    IFstart_B.Add = 0.0F;
    IFstart_B.one_by_two_k = 0.0F;
    IFstart_B.Add2 = 0.0F;
    IFstart_B.Add1_k = 0.0F;
    IFstart_B.Add3 = 0.0F;
    IFstart_B.Gain[0] = 0.0F;
    IFstart_B.Gain[1] = 0.0F;
    IFstart_B.Gain[2] = 0.0F;
    IFstart_B.Gain_n[0] = 0.0F;
    IFstart_B.Gain_n[1] = 0.0F;
    IFstart_B.Gain_n[2] = 0.0F;
    IFstart_B.Add_c[0] = 0.0F;
    IFstart_B.Add_c[1] = 0.0F;
    IFstart_B.Add_c[2] = 0.0F;
    IFstart_B.Gain1[0] = 0.0F;
    IFstart_B.Gain1[1] = 0.0F;
    IFstart_B.Gain1[2] = 0.0F;
    IFstart_B.Product_c[0] = 0.0F;
    IFstart_B.Product_c[1] = 0.0F;
    IFstart_B.SquareRoot = 0.0F;
    IFstart_B.Switch_k = 0.0F;
    IFstart_B.Switch_f[0] = 0.0F;
    IFstart_B.Switch_f[1] = 0.0F;
    IFstart_B.Switch2 = 0.0F;
    IFstart_B.Product_mt = 0.0F;
    IFstart_B.Sum_e = 0.0F;
    IFstart_B.Product2 = 0.0F;
    IFstart_B.Merge_an = 0.0F;
    IFstart_B.Gain_p = 0.0F;
    IFstart_B.Switch_nw = 0.0F;
    IFstart_B.Switch1_m = 0.0F;
    IFstart_B.Sqrt = 0.0F;
    IFstart_B.Gain_i = 0.0F;
    IFstart_B.Convert_back = 0.0F;
    IFstart_B.Convert_back_k = 0.0F;
    IFstart_B.bcos = 0.0F;
    IFstart_B.asin_f = 0.0F;
    IFstart_B.sum_Qs = 0.0F;
    IFstart_B.acos_f = 0.0F;
    IFstart_B.bsin = 0.0F;
    IFstart_B.sum_Ds = 0.0F;
    IFstart_B.Switch_d[0] = 0.0F;
    IFstart_B.Switch_d[1] = 0.0F;
    IFstart_B.algDD_o1 = 0.0F;
    IFstart_B.algDD_o2 = 0.0F;
    IFstart_B.Unary_Minus = 0.0F;
    IFstart_B.qcos = 0.0F;
    IFstart_B.dsin = 0.0F;
    IFstart_B.sum_beta = 0.0F;
    IFstart_B.dcos = 0.0F;
    IFstart_B.qsin = 0.0F;
    IFstart_B.sum_alpha = 0.0F;
    IFstart_B.Switch_p[0] = 0.0F;
    IFstart_B.Switch_p[1] = 0.0F;
    IFstart_B.algDD_o1_a = 0.0F;
    IFstart_B.algDD_o2_j = 0.0F;
    IFstart_B.Unary_Minus_i = 0.0F;
    IFstart_B.a_plus_2b = 0.0F;
    IFstart_B.one_by_sqrt3 = 0.0F;
    IFstart_B.algDD_o1_j = 0.0F;
    IFstart_B.algDD_o2_e = 0.0F;
    IFstart_B.Add_g = 0.0F;
    IFstart_B.DataTypeConversion1_p = 0.0F;
    IFstart_B.Add1_m = 0.0F;
    IFstart_B.Input = 0.0F;
    IFstart_B.DataStoreRead_j = 0.0F;
    IFstart_B.Add1_e = 0.0F;
    IFstart_B.SaturatetomotorcalibSpeedRPM = 0.0F;
    IFstart_B.scaleOut = 0.0F;
    IFstart_B.Product_b1 = 0.0F;
    IFstart_B.Product2_d = 0.0F;
    IFstart_B.Sum1_k = 0.0F;
    IFstart_B.Product1_li = 0.0F;
    IFstart_B.Product3 = 0.0F;
    IFstart_B.Sum2_et = 0.0F;
    IFstart_B.Switch_o3 = 0.0F;
    IFstart_B.Atan2 = 0.0F;
    IFstart_B.Switch_nl = 0.0F;
    IFstart_B.algDD = 0.0F;
    IFstart_B.Gain_d = 0.0F;
    IFstart_B.Switch_kk = 0.0F;
    IFstart_B.Bias = 0.0F;
    IFstart_B.Bias_d = 0.0F;
    IFstart_B.Sum_bn = 0.0F;
    IFstart_B.Sum_lt = 0.0F;
    IFstart_B.Sum_d = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&IFstart_DWork, 0,
                sizeof(D_Work_IFstart));
  IFstart_DWork.UnitDelay1_DSTATE = 0.0F;
  IFstart_DWork.UnitDelay_DSTATE = 0.0F;
  IFstart_DWork.Delay5_DSTATE[0] = 0.0F;
  IFstart_DWork.Delay5_DSTATE[1] = 0.0F;
  IFstart_DWork.Delay5_DSTATE[2] = 0.0F;
  IFstart_DWork.Delay5_DSTATE[3] = 0.0F;
  IFstart_DWork.Delay_DSTATE = 0.0F;
  IFstart_DWork.Delay1_DSTATE = 0.0F;
  IFstart_DWork.UnitDelay_DSTATE_b = 0.0F;
  IFstart_DWork.UnitDelay1_DSTATE_m = 0.0F;
  IFstart_DWork.UnitDelay_DSTATE_p = 0.0F;
  IFstart_DWork.Delay_DSTATE_h = 0.0F;
  IFstart_DWork.Delay1_DSTATE_e = 0.0F;
  IFstart_DWork.UnitDelay_DSTATE_d = 0.0F;
  IFstart_DWork.Delay_DSTATE_p = 0.0F;
  IFstart_DWork.UnitDelay_DSTATE_bp = 0.0F;
  IFstart_DWork.Integrator_DSTATE = 0.0F;
  IFstart_DWork.Integrator_DSTATE_l = 0.0F;
  IFstart_DWork.UnitDelay_DSTATE_bl = 0.0F;
  IFstart_DWork.RT1_Buffer[0] = 0.0F;
  IFstart_DWork.RT1_Buffer[1] = 0.0F;
  IFstart_DWork.RT1_Buffer[2] = 0.0F;
  IFstart_DWork.RT1_Buffer[3] = 0.0F;
  IFstart_DWork.GlobleopenspeedInt = 0.0F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  IFstart_DWork.Enable = IFstart_P.DataStoreMemory9_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
  IFstart_DWork.IaOffset = IFstart_P.DataStoreMemory13_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory14' */
  IFstart_DWork.IbOffset = IFstart_P.DataStoreMemory14_InitialValue;
  IFstart_PrevZCSigState.Dir_Sense_Trig_ZCE = POS_ZCSIG;
  IFstart_PrevZCSigState.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  IFstart_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  IFstart_PrevZCSigState.Delay_Reset_ZCE_c = UNINITIALIZED_ZCSIG;
  IFstart_PrevZCSigState.Delay1_Reset_ZCE_b = UNINITIALIZED_ZCSIG;
  IFstart_PrevZCSigState.Delay_Reset_ZCE_n = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  IFstart_DWork.UnitDelay_DSTATE_k = IFstart_P.UnitDelay_InitialCondition_e;

  /* InitializeConditions for RateTransition: '<Root>/RT1' */
  IFstart_DWork.RT1_Buffer[0] = IFstart_P.RT1_InitialCondition;
  IFstart_DWork.RT1_Buffer[1] = IFstart_P.RT1_InitialCondition;

  /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
  IFstart_DWork.clockTickCounter = 0;

  /* SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem' */
  /* InitializeConditions for UnitDelay: '<S8>/Unit Delay' */
  IFstart_DWork.UnitDelay_DSTATE_a = IFstart_P.UnitDelay_InitialCondition_lg;

  /* SystemInitialize for UnitDelay: '<S8>/Unit Delay' incorporates:
   *  Outport: '<S8>/Out1'
   */
  IFstart_B.UnitDelay_a = IFstart_P.Out1_Y0_o;

  /* End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem' */

  /* SystemInitialize for Enabled SubSystem: '<S219>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S220>/UART//USART Write' */
  IFstart_DWork.obj_e.matlabCodegenIsDeleted = false;
  IFstart_DWork.objisempty_a = true;
  IFstart_DWork.obj_e.isSetupComplete = false;
  IFstart_DWork.obj_e.isInitialized = 1;
  IFstart_UARTWrite_setupImpl(&IFstart_DWork.obj_e);
  IFstart_DWork.obj_e.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S219>/Enabled Subsystem' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  {
    int32_T i;

    /* Start for Constant: '<S90>/Vq_OpenLoop' */
    IFstart_B.Vq_OpenLoop = IFstart_P.Vq_OpenLoop_Value;

    /* Start for Constant: '<S89>/Constant' */
    IFstart_B.Constant = IFstart_P.Constant_Value_h;

    /* Start for DataStoreMemory: '<S58>/Data Store Memory' */
    IFstart_DWork.GlobleopenspeedInt = IFstart_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S16>/Data Store Memory' */
    IFstart_DWork.statcount = IFstart_P.DataStoreMemory_InitialValue_b;

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay1' */
    IFstart_DWork.UnitDelay1_DSTATE = IFstart_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
    IFstart_DWork.UnitDelay_DSTATE = IFstart_P.UnitDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S2>/Delay5' */
    IFstart_DWork.Delay5_DSTATE[0] = IFstart_P.Delay5_InitialCondition;
    IFstart_DWork.Delay5_DSTATE[1] = IFstart_P.Delay5_InitialCondition;
    IFstart_DWork.Delay5_DSTATE[2] = IFstart_P.Delay5_InitialCondition;
    IFstart_DWork.Delay5_DSTATE[3] = IFstart_P.Delay5_InitialCondition;

    /* InitializeConditions for Delay: '<S29>/Delay' */
    IFstart_DWork.Delay_DSTATE = IFstart_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S39>/Delay1' */
    IFstart_DWork.Delay1_DSTATE = IFstart_P.Delay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S43>/Unit Delay' */
    IFstart_DWork.UnitDelay_DSTATE_b = IFstart_P.UnitDelay_InitialCondition_l;

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay1' */
    IFstart_DWork.UnitDelay1_DSTATE_m = IFstart_P.UnitDelay1_InitialCondition_p;

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
    IFstart_DWork.UnitDelay_DSTATE_p = IFstart_P.UnitDelay_InitialCondition_i;

    /* InitializeConditions for Delay: '<S30>/Delay' */
    IFstart_DWork.Delay_DSTATE_h = IFstart_P.Delay_InitialCondition_e;

    /* InitializeConditions for Delay: '<S40>/Delay1' */
    IFstart_DWork.Delay1_DSTATE_e = IFstart_P.Delay1_InitialCondition_m;

    /* InitializeConditions for UnitDelay: '<S46>/Unit Delay' */
    IFstart_DWork.UnitDelay_DSTATE_d = IFstart_P.UnitDelay_InitialCondition_p;

    /* InitializeConditions for Delay: '<S27>/Delay' */
    IFstart_DWork.Delay_DSTATE_p = IFstart_P.Delay_InitialCondition_b;

    /* InitializeConditions for UnitDelay: '<S61>/Unit Delay' */
    IFstart_DWork.UnitDelay_DSTATE_bp = IFstart_P.UnitDelay_InitialCondition_pr;

    /* InitializeConditions for DiscreteIntegrator: '<S194>/Integrator' */
    IFstart_DWork.Integrator_DSTATE = IFstart_B.Vq_OpenLoop;
    IFstart_DWork.Integrator_PrevResetState = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S141>/Integrator' */
    IFstart_DWork.Integrator_DSTATE_l = IFstart_B.Constant;
    IFstart_DWork.Integrator_PrevResetState_i = 0;

    /* InitializeConditions for Delay: '<S34>/Delay' */
    for (i = 0; i < 119; i++) {
      IFstart_DWork.Delay_DSTATE_a[i] = IFstart_P.Delay_InitialCondition_i;
    }

    IFstart_DWork.CircBufIdx = 0U;

    /* End of InitializeConditions for Delay: '<S34>/Delay' */

    /* InitializeConditions for UnitDelay: '<S49>/Unit Delay' */
    IFstart_DWork.UnitDelay_DSTATE_bl = IFstart_P.UnitDelay_InitialCondition_j;

    /* SystemInitialize for Triggered SubSystem: '<S28>/Dir_Sense' */
    /* SystemInitialize for Switch: '<S36>/Switch' incorporates:
     *  Outport: '<S36>/Sign'
     */
    IFstart_B.Switch_gg = IFstart_P.Sign_Y0;

    /* End of SystemInitialize for SubSystem: '<S28>/Dir_Sense' */

    /* SystemInitialize for Enabled SubSystem: '<S61>/Accumulate' */
    /* InitializeConditions for Delay: '<S62>/Delay' */
    IFstart_DWork.Delay_DSTATE_he = IFstart_P.Delay_InitialCondition_n;

    /* SystemInitialize for Enabled SubSystem: '<S62>/Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S63>/Input' incorporates:
     *  Outport: '<S63>/Out1'
     */
    IFstart_B.Input = IFstart_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S62>/Subsystem' */

    /* SystemInitialize for Sum: '<S62>/Add1' incorporates:
     *  Outport: '<S62>/theta_e'
     */
    IFstart_B.Add1_m = IFstart_P.theta_e_Y0;

    /* End of SystemInitialize for SubSystem: '<S61>/Accumulate' */

    /* Start for MATLABSystem: '<S20>/Analog to Digital Converter' */
    IFstart_DWork.obj_o.isInitialized = 0;
    IFstart_DWork.obj_o.matlabCodegenIsDeleted = false;
    IFstart_DWork.objisempty_o = true;
    IFstart_SystemCore_setup(&IFstart_DWork.obj_o);

    /* Start for MATLABSystem: '<S213>/PWM Output' */
    IFstart_DWork.obj_e3.matlabCodegenIsDeleted = false;
    IFstart_DWork.objisempty_k = true;
    IFstart_DWork.obj_e3.isSetupComplete = false;
    IFstart_DWork.obj_e3.isInitialized = 1;
    IFstart_PWMOutput_setupImpl(&IFstart_DWork.obj_e3);
    IFstart_DWork.obj_e3.isSetupComplete = true;

    /* SystemInitialize for Gain: '<S27>/AngleConversion' incorporates:
     *  Outport: '<S2>/theta'
     */
    IFstart_B.AngleConversion = IFstart_P.theta_Y0;

    /* SystemInitialize for Gain: '<S54>/OP_Gain*R_shunt1' incorporates:
     *  Outport: '<S2>/currentab'
     */
    IFstart_B.OP_GainR_shunt1[0] = IFstart_P.currentab_Y0;
    IFstart_B.OP_GainR_shunt1[1] = IFstart_P.currentab_Y0;
  }

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S10>/Digital Port Read' */
  IFstart_DWork.objisempty_f = true;
  IFstart_DWork.obj_k.isInitialized = 1;

  /* Start for MATLABSystem: '<S219>/UART//USART Write' */
  IFstart_DWork.obj.matlabCodegenIsDeleted = false;
  IFstart_DWork.objisempty = true;
  IFstart_DWork.obj.isSetupComplete = false;
  IFstart_DWork.obj.isInitialized = 1;
  IFstart_UARTWrite_setupImpl(&IFstart_DWork.obj);
  IFstart_DWork.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S218>/Digital Port Write' */
  IFstart_DWork.objisempty_n = true;
  IFstart_DWork.obj_kg.isInitialized = 1;

  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* DataStoreWrite: '<S4>/Data Store Write' incorporates:
   *  Constant: '<S4>/Testing get offset1'
   */
  IFstart_DWork.IaOffset = IFstart_P.Testinggetoffset1_Value;

  /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
   *  Constant: '<S4>/Testing get offset'
   */
  IFstart_DWork.IbOffset = IFstart_P.Testinggetoffset_Value;

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/* Model terminate function */
void IFstart_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S20>/Analog to Digital Converter' */
  if (!IFstart_DWork.obj_o.matlabCodegenIsDeleted) {
    IFstart_DWork.obj_o.matlabCodegenIsDeleted = true;
    if ((IFstart_DWork.obj_o.isInitialized == 1) &&
        IFstart_DWork.obj_o.isSetupComplete) {
      ADC_Handle_Deinit(IFstart_DWork.obj_o.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S213>/PWM Output' */
  if (!IFstart_DWork.obj_e3.matlabCodegenIsDeleted) {
    IFstart_DWork.obj_e3.matlabCodegenIsDeleted = true;
    if ((IFstart_DWork.obj_e3.isInitialized == 1) &&
        IFstart_DWork.obj_e3.isSetupComplete) {
      disableCounter(IFstart_DWork.obj_e3.TimerHandle);
      disableTimerInterrupts(IFstart_DWork.obj_e3.TimerHandle, 0);
      disableTimerChannel1(IFstart_DWork.obj_e3.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(IFstart_DWork.obj_e3.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(IFstart_DWork.obj_e3.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S213>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S219>/UART//USART Write' */
  if (!IFstart_DWork.obj.matlabCodegenIsDeleted) {
    IFstart_DWork.obj.matlabCodegenIsDeleted = true;
    if ((IFstart_DWork.obj.isInitialized == 1) &&
        IFstart_DWork.obj.isSetupComplete) {
      MW_LPUART_DeInit(IFstart_DWork.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S219>/UART//USART Write' */

  /* Terminate for Enabled SubSystem: '<S219>/Enabled Subsystem' */
  /* Terminate for MATLABSystem: '<S220>/UART//USART Write' */
  if (!IFstart_DWork.obj_e.matlabCodegenIsDeleted) {
    IFstart_DWork.obj_e.matlabCodegenIsDeleted = true;
    if ((IFstart_DWork.obj_e.isInitialized == 1) &&
        IFstart_DWork.obj_e.isSetupComplete) {
      MW_LPUART_DeInit(IFstart_DWork.obj_e.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S220>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<S219>/Enabled Subsystem' */
}

void IFstart_configure_interrupts(void)
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
          boolean_T LogicalOperator_tmp;
          boolean_T zcEvent;

          /* Switch: '<S93>/Switch1' incorporates:
           *  Constant: '<S93>/enableInportSatMethod'
           */
          if (IFstart_P.enableInportSatMethod_Value != 0) {
            /* Switch: '<S93>/Switch1' incorporates:
             *  Constant: '<S88>/ReplaceInport_satMethod'
             */
            IFstart_B.Switch1_i = IFstart_P.ReplaceInport_satMethod_Value;
          } else {
            /* Switch: '<S93>/Switch1' incorporates:
             *  Constant: '<S93>/ChosenMethod'
             */
            IFstart_B.Switch1_i = IFstart_P.ChosenMethod_Value;
          }

          /* End of Switch: '<S93>/Switch1' */

          /* DataStoreRead: '<S16>/Data Store Read' */
          IFstart_B.DataStoreRead_c = IFstart_DWork.Enable;

          /* If: '<S16>/If1' */
          if (IFstart_B.DataStoreRead_c) {
            /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S56>/Action Port'
             */
            /* DataStoreRead: '<S56>/Data Store Read' */
            IFstart_B.DataStoreRead = IFstart_DWork.statcount;

            /* Sum: '<S56>/Add1' incorporates:
             *  Constant: '<S56>/Constant'
             */
            tmp_p = (uint64_T)IFstart_P.Constant_Value_g +
              IFstart_B.DataStoreRead;
            if (tmp_p > 4294967295ULL) {
              tmp_p = 4294967295ULL;
            }

            /* Sum: '<S56>/Add1' */
            IFstart_B.Add1 = (uint32_T)tmp_p;

            /* DataStoreWrite: '<S56>/Data Store Write' */
            IFstart_DWork.statcount = IFstart_B.Add1;

            /* Merge: '<S16>/Merge2' incorporates:
             *  SignalConversion generated from: '<S56>/Out1'
             */
            IFstart_B.cont = IFstart_B.Add1;

            /* End of Outputs for SubSystem: '<S16>/If Action Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S16>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S57>/Action Port'
             */
            /* DataStoreWrite: '<S57>/Data Store Write' incorporates:
             *  Constant: '<S57>/Constant15'
             */
            IFstart_DWork.statcount = IFstart_P.Constant15_Value;

            /* Merge: '<S16>/Merge2' incorporates:
             *  Constant: '<S57>/Constant15'
             *  SignalConversion generated from: '<S57>/Out1'
             */
            IFstart_B.cont = IFstart_P.Constant15_Value;

            /* End of Outputs for SubSystem: '<S16>/If Action Subsystem3' */
          }

          /* End of If: '<S16>/If1' */

          /* RelationalOperator: '<S55>/Compare' incorporates:
           *  Constant: '<S55>/Constant'
           */
          IFstart_B.Compare = (IFstart_B.cont <=
                               IFstart_P.EnablePWMfor8seconds_const);

          /* Logic: '<S16>/NOT' */
          IFstart_B.NOT_c = !IFstart_B.Compare;

          /* Switch: '<S17>/Switch' */
          if (IFstart_B.NOT_c) {
            /* Switch: '<S17>/Switch' incorporates:
             *  Constant: '<S17>/Constant4'
             *  Constant: '<S17>/Constant5'
             */
            IFstart_B.Switch[0] = IFstart_P.Constant5_Value;
            IFstart_B.Switch[1] = IFstart_P.Constant4_Value;
          } else {
            /* Switch: '<S17>/Switch' incorporates:
             *  Constant: '<S17>/Constant1'
             *  Constant: '<S17>/Constant6'
             */
            IFstart_B.Switch[0] = IFstart_P.Constant6_Value;
            IFstart_B.Switch[1] = IFstart_P.Constant1_Value_b;
          }

          /* End of Switch: '<S17>/Switch' */

          /* DataStoreRead: '<S54>/Data Store Read' */
          IFstart_B.DataStoreRead_a = IFstart_DWork.IaOffset;

          /* DataStoreRead: '<S54>/Data Store Read1' */
          IFstart_B.DataStoreRead1 = IFstart_DWork.IbOffset;

          /* MATLABSystem: '<S20>/Analog to Digital Converter' */
          injectedReadADCIntr(IFstart_DWork.obj_o.ADCHandle, ADC_READ, &tmp[0]);

          /* MATLABSystem: '<S20>/Analog to Digital Converter' */
          AnalogtoDigitalConverter = tmp[0];
          IFstart_B.AnalogtoDigitalConverter[0] = AnalogtoDigitalConverter;

          /* DataTypeConversion: '<S54>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S20>/Analog to Digital Converter'
           */
          IFstart_B.DataTypeConversion[0] = AnalogtoDigitalConverter;

          /* MATLABSystem: '<S20>/Analog to Digital Converter' */
          AnalogtoDigitalConverter = tmp[1];
          IFstart_B.AnalogtoDigitalConverter[1] = AnalogtoDigitalConverter;

          /* DataTypeConversion: '<S54>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S20>/Analog to Digital Converter'
           */
          IFstart_B.DataTypeConversion[1] = AnalogtoDigitalConverter;

          /* Sum: '<S54>/Add' incorporates:
           *  DataTypeConversion: '<S54>/Data Type Conversion'
           */
          IFstart_B.Add_a[0] = IFstart_B.DataTypeConversion[0] -
            IFstart_B.DataStoreRead_a;
          IFstart_B.Add_a[1] = IFstart_B.DataTypeConversion[1] -
            IFstart_B.DataStoreRead1;

          /* Gain: '<S54>/AD voltage' incorporates:
           *  Sum: '<S54>/Add'
           */
          ADvoltage = IFstart_P.ADvoltage_Gain * (real32_T)IFstart_B.Add_a[0];
          IFstart_B.ADvoltage[0] = ADvoltage;

          /* Gain: '<S54>/OP_Gain*R_shunt' incorporates:
           *  Gain: '<S54>/AD voltage'
           */
          ADvoltage *= IFstart_P.OP_GainR_shunt_Gain;
          IFstart_B.OP_GainR_shunt[0] = ADvoltage;

          /* Gain: '<S54>/OP_Gain*R_shunt1' incorporates:
           *  Gain: '<S54>/OP_Gain*R_shunt'
           */
          IFstart_B.OP_GainR_shunt1[0] = IFstart_P.OP_GainR_shunt1_Gain *
            ADvoltage;

          /* Gain: '<S54>/AD voltage' incorporates:
           *  Sum: '<S54>/Add'
           */
          ADvoltage = IFstart_P.ADvoltage_Gain * (real32_T)IFstart_B.Add_a[1];
          IFstart_B.ADvoltage[1] = ADvoltage;

          /* Gain: '<S54>/OP_Gain*R_shunt' incorporates:
           *  Gain: '<S54>/AD voltage'
           */
          ADvoltage *= IFstart_P.OP_GainR_shunt_Gain;
          IFstart_B.OP_GainR_shunt[1] = ADvoltage;

          /* Gain: '<S54>/OP_Gain*R_shunt1' incorporates:
           *  Gain: '<S54>/OP_Gain*R_shunt'
           */
          IFstart_B.OP_GainR_shunt1[1] = IFstart_P.OP_GainR_shunt1_Gain *
            ADvoltage;

          /* Outputs for Atomic SubSystem: '<S70>/Two phase CRL wrap' */
          /* AlgorithmDescriptorDelegate generated from: '<S71>/a16' */
          arm_clarke_f32(IFstart_B.OP_GainR_shunt1[0],
                         IFstart_B.OP_GainR_shunt1[1], &IFstart_B.algDD_o1_j,
                         &IFstart_B.algDD_o2_e);

          /* End of Outputs for SubSystem: '<S70>/Two phase CRL wrap' */

          /* Gain: '<S70>/Kalpha' */
          IFstart_B.Kalpha = IFstart_P.Kalpha_Gain * IFstart_B.algDD_o1_j;

          /* Gain: '<S70>/Kbeta' */
          IFstart_B.Kbeta = IFstart_P.Kbeta_Gain * IFstart_B.algDD_o2_e;

          /* UnitDelay: '<S39>/Unit Delay1' */
          IFstart_B.UnitDelay1 = IFstart_DWork.UnitDelay1_DSTATE;

          /* UnitDelay: '<S39>/Unit Delay' */
          IFstart_B.UnitDelay = IFstart_DWork.UnitDelay_DSTATE;

          /* Gain: '<S39>/a' */
          IFstart_B.a = IFstart_P.a_Gain * IFstart_B.UnitDelay;

          /* Delay: '<S2>/Delay5' */
          IFstart_B.Delay5[0] = IFstart_DWork.Delay5_DSTATE[0];
          IFstart_B.Delay5[1] = IFstart_DWork.Delay5_DSTATE[1];
          IFstart_B.Delay5[2] = IFstart_DWork.Delay5_DSTATE[2];
          IFstart_B.Delay5[3] = IFstart_DWork.Delay5_DSTATE[3];

          /* DataStoreRead: '<S2>/Data Store Read' */
          IFstart_B.DataStoreRead_b = IFstart_DWork.Enable;

          /* Logic: '<S14>/Logical Operator' incorporates:
           *  Logic: '<S89>/Logical Operator1'
           *  Logic: '<S90>/Logical Operator'
           */
          LogicalOperator_tmp = !IFstart_B.DataStoreRead_b;

          /* Logic: '<S14>/Logical Operator' */
          IFstart_B.LogicalOperator = LogicalOperator_tmp;

          /* Delay: '<S29>/Delay' */
          zcEvent = (((IFstart_PrevZCSigState.Delay_Reset_ZCE == POS_ZCSIG) !=
                      (int32_T)IFstart_B.LogicalOperator) &&
                     (IFstart_PrevZCSigState.Delay_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || IFstart_B.LogicalOperator) {
            IFstart_DWork.Delay_DSTATE = IFstart_P.Delay_InitialCondition;
          }

          Delay_Reset_ZCE_tmp = IFstart_B.LogicalOperator;
          IFstart_PrevZCSigState.Delay_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S29>/Delay' */
          IFstart_B.Delay_b = IFstart_DWork.Delay_DSTATE;

          /* Sum: '<S29>/Sum2' */
          IFstart_B.Sum2 = IFstart_B.Delay_b - IFstart_B.Delay5[2];

          /* Sum: '<S39>/Sum3' */
          IFstart_B.Sum3 = (IFstart_B.UnitDelay1 - IFstart_B.a) + IFstart_B.Sum2;

          /* Gain: '<S39>/b_inv*g' incorporates:
           *  Gain: '<S40>/b_inv*g'
           */
          y_tmp = IFstart_P.SlidingModeObserver_Disturbance * 2.2 /
            0.077159178038513326;
          Bias_tmp = (real32_T)y_tmp;
          Bias = Bias_tmp;

          /* Gain: '<S39>/b_inv*g' */
          IFstart_B.b_invg = Bias * IFstart_B.Sum3;

          /* Delay: '<S39>/Delay1' */
          zcEvent = (((IFstart_PrevZCSigState.Delay1_Reset_ZCE == POS_ZCSIG) !=
                      (int32_T)IFstart_B.LogicalOperator) &&
                     (IFstart_PrevZCSigState.Delay1_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || IFstart_B.LogicalOperator) {
            IFstart_DWork.Delay1_DSTATE = IFstart_P.Delay1_InitialCondition;
          }

          IFstart_PrevZCSigState.Delay1_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S39>/Delay1' */
          IFstart_B.Delay1 = IFstart_DWork.Delay1_DSTATE;

          /* Sum: '<S39>/Sum4' */
          IFstart_B.Sum4 = IFstart_B.b_invg + IFstart_B.Delay1;

          /* Switch: '<S31>/Switch1' incorporates:
           *  Constant: '<S31>/UseInputPort'
           */
          if (IFstart_P.UseInputPort_Value > IFstart_P.Switch1_Threshold_b) {
            /* Sum: '<S31>/Sum' incorporates:
             *  Constant: '<S31>/One'
             *  Constant: '<S31>/a'
             */
            IFstart_B.Sum_d = IFstart_P.One_Value - IFstart_P.a_Value;

            /* Switch: '<S31>/Switch1' incorporates:
             *  Constant: '<S31>/a'
             */
            IFstart_B.Switch1[0] = IFstart_P.a_Value;
            IFstart_B.Switch1[1] = IFstart_B.Sum_d;
          } else {
            /* Switch: '<S31>/Switch1' incorporates:
             *  Constant: '<S31>/FilterConstant'
             *  Constant: '<S31>/OneMinusFilterConstant'
             */
            IFstart_B.Switch1[0] = IFstart_P.FilterConstant_Value;
            IFstart_B.Switch1[1] = IFstart_P.OneMinusFilterConstant_Value;
          }

          /* End of Switch: '<S31>/Switch1' */

          /* Product: '<S43>/Product' */
          IFstart_B.Product = IFstart_B.Sum4 * IFstart_B.Switch1[0];

          /* UnitDelay: '<S43>/Unit Delay' */
          IFstart_B.UnitDelay_e = IFstart_DWork.UnitDelay_DSTATE_b;

          /* Product: '<S43>/Product1' */
          IFstart_B.Product1 = IFstart_B.Switch1[1] * IFstart_B.UnitDelay_e;

          /* Sum: '<S43>/Add1' */
          IFstart_B.Add1_o = IFstart_B.Product + IFstart_B.Product1;

          /* Relay: '<S28>/AlphaRelay' */
          Bias = IFstart_B.Add1_o;
          IFstart_DWork.AlphaRelay_Mode = ((Bias >= IFstart_P.AlphaRelay_OnVal) ||
            ((!(Bias <= IFstart_P.AlphaRelay_OffVal)) &&
             IFstart_DWork.AlphaRelay_Mode));
          if (IFstart_DWork.AlphaRelay_Mode) {
            /* Relay: '<S28>/AlphaRelay' */
            IFstart_B.AlphaRelay = IFstart_P.AlphaRelay_YOn;
          } else {
            /* Relay: '<S28>/AlphaRelay' */
            IFstart_B.AlphaRelay = IFstart_P.AlphaRelay_YOff;
          }

          /* End of Relay: '<S28>/AlphaRelay' */

          /* UnitDelay: '<S40>/Unit Delay1' */
          IFstart_B.UnitDelay1_e = IFstart_DWork.UnitDelay1_DSTATE_m;

          /* UnitDelay: '<S40>/Unit Delay' */
          IFstart_B.UnitDelay_c = IFstart_DWork.UnitDelay_DSTATE_p;

          /* Gain: '<S40>/a' */
          IFstart_B.a_c = IFstart_P.a_Gain_e * IFstart_B.UnitDelay_c;

          /* Delay: '<S30>/Delay' */
          zcEvent = (((IFstart_PrevZCSigState.Delay_Reset_ZCE_c == POS_ZCSIG) !=
                      (int32_T)IFstart_B.LogicalOperator) &&
                     (IFstart_PrevZCSigState.Delay_Reset_ZCE_c !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || IFstart_B.LogicalOperator) {
            IFstart_DWork.Delay_DSTATE_h = IFstart_P.Delay_InitialCondition_e;
          }

          IFstart_PrevZCSigState.Delay_Reset_ZCE_c = Delay_Reset_ZCE_tmp;

          /* Delay: '<S30>/Delay' */
          IFstart_B.Delay_f = IFstart_DWork.Delay_DSTATE_h;

          /* Sum: '<S30>/Sum2' */
          IFstart_B.Sum2_e = IFstart_B.Delay_f - IFstart_B.Delay5[3];

          /* Sum: '<S40>/Sum3' */
          IFstart_B.Sum3_m = (IFstart_B.UnitDelay1_e - IFstart_B.a_c) +
            IFstart_B.Sum2_e;

          /* Gain: '<S40>/b_inv*g' */
          Bias = Bias_tmp;

          /* Gain: '<S40>/b_inv*g' */
          IFstart_B.b_invg_d = Bias * IFstart_B.Sum3_m;

          /* Delay: '<S40>/Delay1' */
          zcEvent = (((IFstart_PrevZCSigState.Delay1_Reset_ZCE_b == POS_ZCSIG)
                      != (int32_T)IFstart_B.LogicalOperator) &&
                     (IFstart_PrevZCSigState.Delay1_Reset_ZCE_b !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || IFstart_B.LogicalOperator) {
            IFstart_DWork.Delay1_DSTATE_e = IFstart_P.Delay1_InitialCondition_m;
          }

          IFstart_PrevZCSigState.Delay1_Reset_ZCE_b = Delay_Reset_ZCE_tmp;

          /* Delay: '<S40>/Delay1' */
          IFstart_B.Delay1_f = IFstart_DWork.Delay1_DSTATE_e;

          /* Sum: '<S40>/Sum4' */
          IFstart_B.Sum4_d = IFstart_B.b_invg_d + IFstart_B.Delay1_f;

          /* Switch: '<S32>/Switch1' incorporates:
           *  Constant: '<S32>/UseInputPort'
           */
          if (IFstart_P.UseInputPort_Value_g > IFstart_P.Switch1_Threshold_bx) {
            /* Sum: '<S32>/Sum' incorporates:
             *  Constant: '<S32>/One'
             *  Constant: '<S32>/a'
             */
            IFstart_B.Sum_lt = IFstart_P.One_Value_c - IFstart_P.a_Value_h;

            /* Switch: '<S32>/Switch1' incorporates:
             *  Constant: '<S32>/a'
             */
            IFstart_B.Switch1_o[0] = IFstart_P.a_Value_h;
            IFstart_B.Switch1_o[1] = IFstart_B.Sum_lt;
          } else {
            /* Switch: '<S32>/Switch1' incorporates:
             *  Constant: '<S32>/FilterConstant'
             *  Constant: '<S32>/OneMinusFilterConstant'
             */
            IFstart_B.Switch1_o[0] = IFstart_P.FilterConstant_Value_g;
            IFstart_B.Switch1_o[1] = IFstart_P.OneMinusFilterConstant_Value_j;
          }

          /* End of Switch: '<S32>/Switch1' */

          /* Product: '<S46>/Product' */
          IFstart_B.Product_b = IFstart_B.Sum4_d * IFstart_B.Switch1_o[0];

          /* UnitDelay: '<S46>/Unit Delay' */
          IFstart_B.UnitDelay_m = IFstart_DWork.UnitDelay_DSTATE_d;

          /* Product: '<S46>/Product1' */
          IFstart_B.Product1_l = IFstart_B.Switch1_o[1] * IFstart_B.UnitDelay_m;

          /* Sum: '<S46>/Add1' */
          IFstart_B.Add1_p = IFstart_B.Product_b + IFstart_B.Product1_l;

          /* Relay: '<S28>/BetaRelay' */
          Bias = IFstart_B.Add1_p;
          IFstart_DWork.BetaRelay_Mode = ((Bias >= IFstart_P.BetaRelay_OnVal) ||
            ((!(Bias <= IFstart_P.BetaRelay_OffVal)) &&
             IFstart_DWork.BetaRelay_Mode));
          if (IFstart_DWork.BetaRelay_Mode) {
            /* Relay: '<S28>/BetaRelay' */
            IFstart_B.BetaRelay = IFstart_P.BetaRelay_YOn;
          } else {
            /* Relay: '<S28>/BetaRelay' */
            IFstart_B.BetaRelay = IFstart_P.BetaRelay_YOff;
          }

          /* End of Relay: '<S28>/BetaRelay' */

          /* Outputs for Triggered SubSystem: '<S28>/Dir_Sense' incorporates:
           *  TriggerPort: '<S36>/Trigger'
           */
          zcEvent = (IFstart_B.AlphaRelay &&
                     (IFstart_PrevZCSigState.Dir_Sense_Trig_ZCE != POS_ZCSIG));
          if (zcEvent) {
            /* Logic: '<S36>/Logical Operator' */
            IFstart_B.LogicalOperator_g = (IFstart_B.AlphaRelay &&
              IFstart_B.BetaRelay);

            /* Switch: '<S36>/Switch' */
            if (IFstart_B.LogicalOperator_g) {
              /* Switch: '<S36>/Switch' incorporates:
               *  Constant: '<S36>/Constant'
               */
              IFstart_B.Switch_gg = (int16_T)floor(IFstart_P.Constant_Value);
            } else {
              /* Switch: '<S36>/Switch' incorporates:
               *  Constant: '<S36>/Constant1'
               */
              IFstart_B.Switch_gg = (int16_T)floor(IFstart_P.Constant1_Value);
            }

            /* End of Switch: '<S36>/Switch' */
          }

          IFstart_PrevZCSigState.Dir_Sense_Trig_ZCE = IFstart_B.AlphaRelay;

          /* End of Outputs for SubSystem: '<S28>/Dir_Sense' */

          /* If: '<S28>/If' */
          if (IFstart_B.Switch_gg > 0) {
            /* Outputs for IfAction SubSystem: '<S28>/Subsystem2' incorporates:
             *  ActionPort: '<S37>/Action Port'
             */
            /* Merge: '<S28>/Merge' incorporates:
             *  UnaryMinus: '<S37>/Unary Minus'
             */
            IFstart_B.Merge = -IFstart_B.Add1_o;

            /* Merge: '<S28>/Merge1' incorporates:
             *  SignalConversion generated from: '<S37>/SigmaBeta'
             */
            IFstart_B.Merge1 = IFstart_B.Add1_p;

            /* End of Outputs for SubSystem: '<S28>/Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S28>/Subsystem3' incorporates:
             *  ActionPort: '<S38>/Action Port'
             */
            /* Merge: '<S28>/Merge1' incorporates:
             *  UnaryMinus: '<S38>/Unary Minus'
             */
            IFstart_B.Merge1 = -IFstart_B.Add1_p;

            /* Merge: '<S28>/Merge' incorporates:
             *  SignalConversion generated from: '<S38>/SigmaAlpha'
             */
            IFstart_B.Merge = IFstart_B.Add1_o;

            /* End of Outputs for SubSystem: '<S28>/Subsystem3' */
          }

          /* End of If: '<S28>/If' */

          /* Delay: '<S27>/Delay' */
          zcEvent = (((IFstart_PrevZCSigState.Delay_Reset_ZCE_n == POS_ZCSIG) !=
                      (int32_T)IFstart_B.LogicalOperator) &&
                     (IFstart_PrevZCSigState.Delay_Reset_ZCE_n !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || IFstart_B.LogicalOperator) {
            IFstart_DWork.Delay_DSTATE_p = IFstart_P.Delay_InitialCondition_b;
          }

          IFstart_PrevZCSigState.Delay_Reset_ZCE_n = Delay_Reset_ZCE_tmp;

          /* Delay: '<S27>/Delay' */
          IFstart_B.Delay_fn = IFstart_DWork.Delay_DSTATE_p;

          /* Constant: '<S27>/PhaseDelay' */
          y_tmp = IFstart_P.SlidingModeObserver_CutoffFreq / 83.333333333333329;

          /* Constant: '<S27>/PhaseDelay' */
          IFstart_B.PhaseDelay = (real32_T)y_tmp;

          /* Outputs for Atomic SubSystem: '<S27>/angleCompensation' */
          /* Product: '<S35>/Product' */
          IFstart_B.Product_b1 = IFstart_B.Merge * IFstart_B.PhaseDelay;

          /* Product: '<S35>/Product2' */
          IFstart_B.Product2_d = IFstart_B.Merge1 * IFstart_B.Delay_fn;

          /* Sum: '<S35>/Sum1' */
          IFstart_B.Sum1_k = IFstart_B.Product_b1 + IFstart_B.Product2_d;

          /* Product: '<S35>/Product1' */
          IFstart_B.Product1_li = IFstart_B.Merge1 * IFstart_B.PhaseDelay;

          /* Product: '<S35>/Product3' */
          IFstart_B.Product3 = IFstart_B.Merge * IFstart_B.Delay_fn;

          /* Sum: '<S35>/Sum2' */
          IFstart_B.Sum2_et = IFstart_B.Product1_li - IFstart_B.Product3;

          /* Outputs for Atomic SubSystem: '<S35>/atan1' */
          /* Trigonometry: '<S52>/Atan2' */
          IFstart_B.Atan2 = rt_atan2f_snf(IFstart_B.Sum1_k, IFstart_B.Sum2_et);

          /* Outputs for Atomic SubSystem: '<S35>/atan1' */
          /* Switch: '<S52>/Switch' */
          if (IFstart_P.atan1_outputUnit > IFstart_P.Switch_Threshold_f) {
            /* Outputs for Atomic SubSystem: '<S52>/Per Unit' */
            /* Gain: '<S53>/Gain' */
            IFstart_B.Gain_d = IFstart_P.Gain_Gain * IFstart_B.Atan2;

            /* Switch: '<S53>/Switch' */
            if (IFstart_B.Gain_d >= IFstart_P.Switch_Threshold) {
              /* Switch: '<S53>/Switch' */
              IFstart_B.Switch_kk = IFstart_B.Gain_d;
            } else {
              /* Bias: '<S53>/Bias' */
              IFstart_B.Bias = IFstart_B.Gain_d + IFstart_P.Bias_Bias_g;

              /* Switch: '<S53>/Switch' */
              IFstart_B.Switch_kk = IFstart_B.Bias;
            }

            /* End of Switch: '<S53>/Switch' */
            /* End of Outputs for SubSystem: '<S52>/Per Unit' */

            /* Switch: '<S52>/Switch' */
            IFstart_B.Switch_nl = IFstart_B.Switch_kk;
          } else {
            /* Switch: '<S52>/Switch' */
            IFstart_B.Switch_nl = IFstart_B.Atan2;
          }

          /* End of Switch: '<S52>/Switch' */
          /* End of Outputs for SubSystem: '<S35>/atan1' */

          /* AlgorithmDescriptorDelegate generated from: '<S52>/a16' */
          IFstart_B.algDD = IFstart_B.Switch_nl;

          /* End of Outputs for SubSystem: '<S35>/atan1' */

          /* Switch: '<S35>/Switch' */
          if (IFstart_B.algDD > IFstart_P.Switch_Threshold_k) {
            /* Switch: '<S35>/Switch' */
            IFstart_B.Switch_o3 = IFstart_B.algDD;
          } else {
            /* Bias: '<S35>/Bias' */
            IFstart_B.Bias_d = IFstart_B.algDD + IFstart_P.Bias_Bias;

            /* Switch: '<S35>/Switch' */
            IFstart_B.Switch_o3 = IFstart_B.Bias_d;
          }

          /* End of Switch: '<S35>/Switch' */
          /* End of Outputs for SubSystem: '<S27>/angleCompensation' */

          /* Gain: '<S27>/AngleConversion' */
          IFstart_B.AngleConversion = IFstart_P.AngleConversion_Gain *
            IFstart_B.Switch_o3;

          /* If: '<S58>/If' incorporates:
           *  Constant: '<S58>/Count for 2 sec'
           */
          if (IFstart_B.cont < IFstart_P.Countfor2sec_Value) {
            /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem' incorporates:
             *  ActionPort: '<S59>/Action Port'
             */
            /* DataStoreWrite: '<S59>/Data Store Write' incorporates:
             *  Constant: '<S59>/Constant'
             */
            IFstart_DWork.GlobleopenspeedInt = IFstart_P.Constant_Value_n;

            /* Merge: '<S58>/Merge' incorporates:
             *  Constant: '<S59>/Constant'
             *  SignalConversion generated from: '<S59>/Out1'
             */
            IFstart_B.Merge_a = IFstart_P.Constant_Value_n;

            /* End of Outputs for SubSystem: '<S58>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S58>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S60>/Action Port'
             */
            /* DataStoreRead: '<S60>/Data Store Read' */
            IFstart_B.DataStoreRead_j = IFstart_DWork.GlobleopenspeedInt;

            /* Sum: '<S60>/Add1' incorporates:
             *  Constant: '<S60>/Constant2'
             */
            IFstart_B.Add1_e = IFstart_P.Constant2_Value +
              IFstart_B.DataStoreRead_j;

            /* Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */
            Bias = IFstart_B.Add1_e;
            Bias_tmp = IFstart_P.SaturatetomotorcalibSpeedRPM_Lo;
            ADvoltage = IFstart_P.SaturatetomotorcalibSpeedRPM_Up;
            if (Bias > ADvoltage) {
              /* Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */
              IFstart_B.SaturatetomotorcalibSpeedRPM = ADvoltage;
            } else if (Bias < Bias_tmp) {
              /* Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */
              IFstart_B.SaturatetomotorcalibSpeedRPM = Bias_tmp;
            } else {
              /* Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */
              IFstart_B.SaturatetomotorcalibSpeedRPM = Bias;
            }

            /* End of Saturate: '<S60>/Saturate to 'motor.calibSpeed' RPM' */

            /* DataStoreWrite: '<S60>/Data Store Write' */
            IFstart_DWork.GlobleopenspeedInt =
              IFstart_B.SaturatetomotorcalibSpeedRPM;

            /* Merge: '<S58>/Merge' incorporates:
             *  Gain: '<S60>/Multiply1'
             */
            IFstart_B.Merge_a = IFstart_P.Multiply1_Gain *
              IFstart_B.SaturatetomotorcalibSpeedRPM;

            /* End of Outputs for SubSystem: '<S58>/If Action Subsystem2' */
          }

          /* End of If: '<S58>/If' */

          /* Gain: '<S61>/scaleIn' */
          IFstart_B.scaleIn = IFstart_P.scaleIn_Gain * IFstart_B.Merge_a;

          /* UnitDelay: '<S61>/Unit Delay' */
          IFstart_B.UnitDelay_h = IFstart_DWork.UnitDelay_DSTATE_bp;

          /* Logic: '<S61>/NOT' incorporates:
           *  Constant: '<S61>/Constant_Reset'
           */
          IFstart_B.NOT_b = !IFstart_P.Constant_Reset_Value;

          /* Outputs for Enabled SubSystem: '<S61>/Accumulate' incorporates:
           *  EnablePort: '<S62>/Enable'
           */
          if (IFstart_B.NOT_b) {
            /* Delay: '<S62>/Delay' */
            IFstart_B.Delay_e = IFstart_DWork.Delay_DSTATE_he;

            /* Outputs for Enabled SubSystem: '<S62>/Subsystem' incorporates:
             *  EnablePort: '<S63>/Enable'
             */
            if (IFstart_B.Delay_e) {
              /* SignalConversion generated from: '<S63>/Input' */
              IFstart_B.Input = IFstart_B.scaleIn;
            }

            /* End of Outputs for SubSystem: '<S62>/Subsystem' */

            /* Sum: '<S62>/Add' */
            IFstart_B.Add_g = IFstart_B.Input + IFstart_B.UnitDelay_h;

            /* DataTypeConversion: '<S62>/Data Type Conversion' */
            IFstart_B.DataTypeConversion_i = (int16_T)floorf(IFstart_B.Add_g);

            /* DataTypeConversion: '<S62>/Data Type Conversion1' */
            IFstart_B.DataTypeConversion1_p = IFstart_B.DataTypeConversion_i;

            /* Sum: '<S62>/Add1' */
            IFstart_B.Add1_m = IFstart_B.Add_g - IFstart_B.DataTypeConversion1_p;

            /* Update for Delay: '<S62>/Delay' incorporates:
             *  Constant: '<S62>/Constant'
             */
            IFstart_DWork.Delay_DSTATE_he = IFstart_P.Constant_Value_a;
          }

          /* End of Outputs for SubSystem: '<S61>/Accumulate' */

          /* Switch: '<S15>/Switch' */
          if (IFstart_B.NOT_c) {
            /* Switch: '<S15>/Switch' */
            IFstart_B.Switch_n = IFstart_B.AngleConversion;
          } else {
            /* Gain: '<S61>/scaleOut' */
            IFstart_B.scaleOut = IFstart_P.scaleOut_Gain * IFstart_B.Add1_m;

            /* Switch: '<S15>/Switch' */
            IFstart_B.Switch_n = IFstart_B.scaleOut;
          }

          /* End of Switch: '<S15>/Switch' */

          /* Gain: '<S84>/convert_pu' */
          IFstart_B.convert_pu = IFstart_P.convert_pu_Gain * IFstart_B.Switch_n;

          /* RelationalOperator: '<S85>/Compare' incorporates:
           *  Constant: '<S85>/Constant'
           */
          IFstart_B.Compare_f = (IFstart_B.convert_pu <
            IFstart_P.Constant_Value_m);

          /* DataTypeConversion: '<S84>/Data Type Conversion' */
          IFstart_B.DataTypeConversion_a = IFstart_B.Compare_f;

          /* If: '<S84>/If' */
          if (IFstart_B.DataTypeConversion_a > 0) {
            /* Outputs for IfAction SubSystem: '<S84>/If Action Subsystem' incorporates:
             *  ActionPort: '<S86>/Action Port'
             */
            /* DataTypeConversion: '<S86>/Convert_uint16' */
            IFstart_B.Convert_uint16_f = (int16_T)floorf(IFstart_B.convert_pu);

            /* DataTypeConversion: '<S86>/Convert_back' */
            IFstart_B.Convert_back_k = IFstart_B.Convert_uint16_f;

            /* Merge: '<S84>/Merge' incorporates:
             *  Sum: '<S86>/Sum'
             */
            IFstart_B.Merge_e = IFstart_B.convert_pu - IFstart_B.Convert_back_k;

            /* End of Outputs for SubSystem: '<S84>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S84>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S87>/Action Port'
             */
            /* DataTypeConversion: '<S87>/Convert_uint16' */
            IFstart_B.Convert_uint16 = (int16_T)IFstart_B.convert_pu;

            /* DataTypeConversion: '<S87>/Convert_back' */
            IFstart_B.Convert_back = IFstart_B.Convert_uint16;

            /* Merge: '<S84>/Merge' incorporates:
             *  Sum: '<S87>/Sum'
             */
            IFstart_B.Merge_e = IFstart_B.convert_pu - IFstart_B.Convert_back;

            /* End of Outputs for SubSystem: '<S84>/If Action Subsystem1' */
          }

          /* End of If: '<S84>/If' */

          /* Gain: '<S68>/indexing' */
          IFstart_B.indexing = IFstart_P.indexing_Gain * IFstart_B.Merge_e;

          /* DataTypeConversion: '<S68>/Get_Integer' */
          IFstart_B.Get_Integer = (uint16_T)IFstart_B.indexing;

          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/offset'
           */
          Sum = (uint32_T)IFstart_P.offset_Value[0] + IFstart_B.Get_Integer;
          IFstart_B.Sum[0] = Sum;

          /* Selector: '<S68>/Lookup' incorporates:
           *  Constant: '<S68>/sine_table_values'
           */
          IFstart_B.Lookup[0] = IFstart_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/offset'
           */
          Sum = (uint32_T)IFstart_P.offset_Value[1] + IFstart_B.Get_Integer;
          IFstart_B.Sum[1] = Sum;

          /* Selector: '<S68>/Lookup' incorporates:
           *  Constant: '<S68>/sine_table_values'
           */
          IFstart_B.Lookup[1] = IFstart_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/offset'
           */
          Sum = (uint32_T)IFstart_P.offset_Value[2] + IFstart_B.Get_Integer;
          IFstart_B.Sum[2] = Sum;

          /* Selector: '<S68>/Lookup' incorporates:
           *  Constant: '<S68>/sine_table_values'
           */
          IFstart_B.Lookup[2] = IFstart_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S68>/Sum' incorporates:
           *  Constant: '<S68>/offset'
           */
          Sum = (uint32_T)IFstart_P.offset_Value[3] + IFstart_B.Get_Integer;
          IFstart_B.Sum[3] = Sum;

          /* Selector: '<S68>/Lookup' incorporates:
           *  Constant: '<S68>/sine_table_values'
           */
          IFstart_B.Lookup[3] = IFstart_P.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S83>/Sum3' */
          IFstart_B.Sum3_i = IFstart_B.Lookup[0] - IFstart_B.Lookup[1];

          /* DataTypeConversion: '<S68>/Data Type Conversion1' */
          IFstart_B.DataTypeConversion1 = IFstart_B.Get_Integer;

          /* Sum: '<S68>/Sum2' */
          IFstart_B.Sum2_g = IFstart_B.indexing - IFstart_B.DataTypeConversion1;

          /* Product: '<S83>/Product' */
          IFstart_B.Product_h = IFstart_B.Sum3_i * IFstart_B.Sum2_g;

          /* Sum: '<S83>/Sum4' */
          IFstart_B.Sum4_h = IFstart_B.Product_h + IFstart_B.Lookup[1];

          /* Sum: '<S83>/Sum5' */
          IFstart_B.Sum5 = IFstart_B.Lookup[2] - IFstart_B.Lookup[3];

          /* Product: '<S83>/Product1' */
          IFstart_B.Product1_k = IFstart_B.Sum5 * IFstart_B.Sum2_g;

          /* Sum: '<S83>/Sum6' */
          IFstart_B.Sum6 = IFstart_B.Product1_k + IFstart_B.Lookup[3];

          /* Outputs for Atomic SubSystem: '<S67>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S81>/a16' */
          arm_park_f32(IFstart_B.Kalpha, IFstart_B.Kbeta, &IFstart_B.algDD_o1,
                       &IFstart_B.algDD_o2, IFstart_B.Sum4_h, IFstart_B.Sum6);

          /* End of Outputs for SubSystem: '<S67>/Two inputs CRL' */

          /* Sum: '<S90>/Sum' */
          IFstart_B.Sum_k = IFstart_B.Switch[1] - IFstart_B.algDD_o2;

          /* Product: '<S199>/PProd Out' incorporates:
           *  Constant: '<S69>/Kp'
           */
          IFstart_B.PProdOut = IFstart_B.Sum_k * IFstart_P.Kp_Value;

          /* DataStoreRead: '<S17>/Data Store Read' */
          IFstart_B.DataStoreRead_e = IFstart_DWork.Enable;

          /* Logic: '<S90>/Logical Operator' */
          IFstart_B.LogicalOperator_n = LogicalOperator_tmp;

          /* Constant: '<S90>/Vq_OpenLoop' */
          IFstart_B.Vq_OpenLoop = IFstart_P.Vq_OpenLoop_Value;

          /* DiscreteIntegrator: '<S194>/Integrator' */
          if (IFstart_B.LogicalOperator_n ||
              (IFstart_DWork.Integrator_PrevResetState != 0)) {
            IFstart_DWork.Integrator_DSTATE = IFstart_B.Vq_OpenLoop;
          }

          /* DiscreteIntegrator: '<S194>/Integrator' */
          IFstart_B.Integrator = IFstart_DWork.Integrator_DSTATE;

          /* Sum: '<S203>/Sum' */
          IFstart_B.Sum_i = IFstart_B.PProdOut + IFstart_B.Integrator;

          /* Saturate: '<S201>/Saturation' */
          Bias = IFstart_B.Sum_i;
          Bias_tmp = IFstart_P.DiscretePIControllerwithantiwin;
          ADvoltage = IFstart_P.DiscretePIControllerwithantiw_e;
          if (Bias > ADvoltage) {
            /* Saturate: '<S201>/Saturation' */
            IFstart_B.Saturation = ADvoltage;
          } else if (Bias < Bias_tmp) {
            /* Saturate: '<S201>/Saturation' */
            IFstart_B.Saturation = Bias_tmp;
          } else {
            /* Saturate: '<S201>/Saturation' */
            IFstart_B.Saturation = Bias;
          }

          /* End of Saturate: '<S201>/Saturation' */

          /* Sum: '<S89>/Sum' */
          IFstart_B.Sum_b = IFstart_B.Switch[0] - IFstart_B.algDD_o1;

          /* Product: '<S146>/PProd Out' incorporates:
           *  Constant: '<S69>/Kp'
           */
          IFstart_B.PProdOut_i = IFstart_B.Sum_b * IFstart_P.Kp_Value;

          /* Logic: '<S89>/Logical Operator1' */
          IFstart_B.LogicalOperator1 = LogicalOperator_tmp;

          /* Constant: '<S89>/Constant' */
          IFstart_B.Constant = IFstart_P.Constant_Value_h;

          /* DiscreteIntegrator: '<S141>/Integrator' */
          if (IFstart_B.LogicalOperator1 ||
              (IFstart_DWork.Integrator_PrevResetState_i != 0)) {
            IFstart_DWork.Integrator_DSTATE_l = IFstart_B.Constant;
          }

          /* DiscreteIntegrator: '<S141>/Integrator' */
          IFstart_B.Integrator_a = IFstart_DWork.Integrator_DSTATE_l;

          /* Sum: '<S150>/Sum' */
          IFstart_B.Sum_o = IFstart_B.PProdOut_i + IFstart_B.Integrator_a;

          /* Saturate: '<S148>/Saturation' */
          Bias = IFstart_B.Sum_o;
          Bias_tmp = IFstart_P.DiscretePIControllerwithantiw_f;
          ADvoltage = IFstart_P.DiscretePIControllerwithantiw_b;
          if (Bias > ADvoltage) {
            /* Saturate: '<S148>/Saturation' */
            IFstart_B.Saturation_h = ADvoltage;
          } else if (Bias < Bias_tmp) {
            /* Saturate: '<S148>/Saturation' */
            IFstart_B.Saturation_h = Bias_tmp;
          } else {
            /* Saturate: '<S148>/Saturation' */
            IFstart_B.Saturation_h = Bias;
          }

          /* End of Saturate: '<S148>/Saturation' */

          /* Switch: '<S93>/Switch' incorporates:
           *  Constant: '<S93>/enableInportSatLim'
           */
          if (IFstart_P.enableInportSatLim_Value != 0) {
            /* Switch: '<S93>/Switch' incorporates:
             *  Constant: '<S88>/ReplaceInport_satLim'
             */
            IFstart_B.Switch_o = IFstart_P.ReplaceInport_satLim_Value;
          } else {
            /* Switch: '<S93>/Switch' incorporates:
             *  Constant: '<S93>/Constant3'
             */
            IFstart_B.Switch_o = IFstart_P.Constant3_Value;
          }

          /* End of Switch: '<S93>/Switch' */

          /* Product: '<S93>/Product' */
          IFstart_B.Product_i = IFstart_B.Switch_o * IFstart_B.Switch_o;

          /* Product: '<S94>/Product' */
          IFstart_B.Product_hz = IFstart_B.Saturation_h * IFstart_B.Saturation_h;

          /* Product: '<S94>/Product1' */
          IFstart_B.Product1_n = IFstart_B.Saturation * IFstart_B.Saturation;

          /* Sum: '<S94>/Sum1' */
          IFstart_B.Sum1 = IFstart_B.Product_hz + IFstart_B.Product1_n;

          /* If: '<S88>/If' */
          if ((IFstart_B.Switch1_i == 1) || (IFstart_B.Switch1_i == 2)) {
            /* Outputs for IfAction SubSystem: '<S88>/D//Q Axis Priority' incorporates:
             *  ActionPort: '<S92>/Action Port'
             */
            /* RelationalOperator: '<S97>/Compare' incorporates:
             *  Constant: '<S97>/Constant'
             */
            IFstart_B.Compare_e = (IFstart_B.Switch1_i ==
              IFstart_P.CompareToConstant_const);

            /* RelationalOperator: '<S98>/Compare' incorporates:
             *  Constant: '<S98>/Constant'
             */
            IFstart_B.Compare_n = (IFstart_B.Switch1_i ==
              IFstart_P.CompareToConstant1_const);

            /* Switch: '<S92>/Switch' */
            if (IFstart_B.Compare_e) {
              /* Switch: '<S92>/Switch' */
              IFstart_B.Switch_f[0] = IFstart_B.Saturation_h;
              IFstart_B.Switch_f[1] = IFstart_B.Saturation;
            } else {
              /* Switch: '<S92>/Switch' */
              IFstart_B.Switch_f[0] = IFstart_B.Saturation;
              IFstart_B.Switch_f[1] = IFstart_B.Saturation_h;
            }

            /* End of Switch: '<S92>/Switch' */

            /* RelationalOperator: '<S102>/LowerRelop1' */
            IFstart_B.LowerRelop1 = (IFstart_B.Switch_f[0] > IFstart_B.Switch_o);

            /* Switch: '<S102>/Switch2' */
            if (IFstart_B.LowerRelop1) {
              /* Switch: '<S102>/Switch2' */
              IFstart_B.Switch2 = IFstart_B.Switch_o;
            } else {
              /* Gain: '<S101>/Gain' */
              IFstart_B.Gain_p = IFstart_P.Gain_Gain_n * IFstart_B.Switch_o;

              /* RelationalOperator: '<S102>/UpperRelop' */
              IFstart_B.UpperRelop = (IFstart_B.Switch_f[0] < IFstart_B.Gain_p);

              /* Switch: '<S102>/Switch' */
              if (IFstart_B.UpperRelop) {
                /* Switch: '<S102>/Switch' */
                IFstart_B.Switch_nw = IFstart_B.Gain_p;
              } else {
                /* Switch: '<S102>/Switch' */
                IFstart_B.Switch_nw = IFstart_B.Switch_f[0];
              }

              /* End of Switch: '<S102>/Switch' */

              /* Switch: '<S102>/Switch2' */
              IFstart_B.Switch2 = IFstart_B.Switch_nw;
            }

            /* End of Switch: '<S102>/Switch2' */

            /* Product: '<S101>/Product' */
            IFstart_B.Product_mt = IFstart_B.Switch2 * IFstart_B.Switch2;

            /* Sum: '<S101>/Sum' */
            IFstart_B.Sum_e = IFstart_B.Product_i - IFstart_B.Product_mt;

            /* Product: '<S101>/Product2' */
            IFstart_B.Product2 = IFstart_B.Switch_f[1] * IFstart_B.Switch_f[1];

            /* RelationalOperator: '<S101>/Relational Operator' */
            IFstart_B.RelationalOperator_i = (IFstart_B.Sum_e >=
              IFstart_B.Product2);

            /* DataTypeConversion: '<S101>/Data Type Conversion' */
            IFstart_B.DataTypeConversion_h = IFstart_B.RelationalOperator_i;

            /* If: '<S101>/If' incorporates:
             *  Switch: '<S103>/Switch1'
             */
            if (IFstart_B.DataTypeConversion_h != 0) {
              /* Outputs for IfAction SubSystem: '<S101>/passThrough' incorporates:
               *  ActionPort: '<S104>/Action Port'
               */
              /* Merge: '<S101>/Merge' incorporates:
               *  SignalConversion generated from: '<S104>/ref2'
               */
              IFstart_B.Merge_an = IFstart_B.Switch_f[1];

              /* End of Outputs for SubSystem: '<S101>/passThrough' */
            } else {
              /* Outputs for IfAction SubSystem: '<S101>/limitRef2' incorporates:
               *  ActionPort: '<S103>/Action Port'
               */
              if (IFstart_B.Sum_e > IFstart_P.Switch1_Threshold) {
                /* Switch: '<S103>/Switch1' */
                IFstart_B.Switch1_m = IFstart_B.Sum_e;
              } else {
                /* Switch: '<S103>/Switch1' incorporates:
                 *  Constant: '<S103>/Constant'
                 */
                IFstart_B.Switch1_m = IFstart_P.Constant_Value_j;
              }

              /* Sqrt: '<S103>/Sqrt' */
              mw_arm_sqrt_f32(&IFstart_B.Switch1_m, &IFstart_B.Sqrt, 1U);

              /* Switch: '<S103>/Switch' */
              if (IFstart_B.Switch_f[1] >= IFstart_P.Switch_Threshold_c) {
                /* Merge: '<S101>/Merge' */
                IFstart_B.Merge_an = IFstart_B.Sqrt;
              } else {
                /* Gain: '<S103>/Gain' */
                IFstart_B.Gain_i = IFstart_P.Gain_Gain_m * IFstart_B.Sqrt;

                /* Merge: '<S101>/Merge' */
                IFstart_B.Merge_an = IFstart_B.Gain_i;
              }

              /* End of Switch: '<S103>/Switch' */
              /* End of Outputs for SubSystem: '<S101>/limitRef2' */
            }

            /* End of If: '<S101>/If' */

            /* Switch: '<S92>/Switch1' */
            if (IFstart_B.Compare_n) {
              /* Merge: '<S88>/Merge' */
              IFstart_B.Merge_f[0] = IFstart_B.Switch2;
              IFstart_B.Merge_f[1] = IFstart_B.Merge_an;
            } else {
              /* Merge: '<S88>/Merge' */
              IFstart_B.Merge_f[0] = IFstart_B.Merge_an;
              IFstart_B.Merge_f[1] = IFstart_B.Switch2;
            }

            /* End of Switch: '<S92>/Switch1' */
            /* End of Outputs for SubSystem: '<S88>/D//Q Axis Priority' */
          } else {
            /* Outputs for IfAction SubSystem: '<S88>/D-Q Equivalence' incorporates:
             *  ActionPort: '<S91>/Action Port'
             */
            /* RelationalOperator: '<S91>/Relational Operator' */
            IFstart_B.RelationalOperator_j = (IFstart_B.Sum1 >
              IFstart_B.Product_i);

            /* DataTypeConversion: '<S91>/Data Type Conversion' */
            IFstart_B.DataTypeConversion_f = IFstart_B.RelationalOperator_j;

            /* If: '<S91>/If' */
            if (IFstart_B.DataTypeConversion_f != 0) {
              /* Outputs for IfAction SubSystem: '<S91>/Limiter' incorporates:
               *  ActionPort: '<S95>/Action Port'
               */
              /* Product: '<S95>/Product' */
              IFstart_B.Product_c[0] = IFstart_B.Saturation_h *
                IFstart_B.Switch_o;
              IFstart_B.Product_c[1] = IFstart_B.Saturation * IFstart_B.Switch_o;

              /* Sqrt: '<S95>/Square Root' */
              mw_arm_sqrt_f32(&IFstart_B.Sum1, &IFstart_B.SquareRoot, 1U);

              /* Switch: '<S95>/Switch' */
              if (IFstart_B.SquareRoot != 0.0F) {
                /* Switch: '<S95>/Switch' */
                IFstart_B.Switch_k = IFstart_B.SquareRoot;
              } else {
                /* Switch: '<S95>/Switch' incorporates:
                 *  Constant: '<S95>/Constant'
                 */
                IFstart_B.Switch_k = IFstart_P.Constant_Value_p;
              }

              /* End of Switch: '<S95>/Switch' */

              /* Merge: '<S88>/Merge' incorporates:
               *  Product: '<S95>/Divide'
               */
              IFstart_B.Merge_f[0] = IFstart_B.Product_c[0] / IFstart_B.Switch_k;
              IFstart_B.Merge_f[1] = IFstart_B.Product_c[1] / IFstart_B.Switch_k;

              /* End of Outputs for SubSystem: '<S91>/Limiter' */
            } else {
              /* Outputs for IfAction SubSystem: '<S91>/Passthrough' incorporates:
               *  ActionPort: '<S96>/Action Port'
               */
              /* Merge: '<S88>/Merge' incorporates:
               *  SignalConversion generated from: '<S96>/dqRef'
               */
              IFstart_B.Merge_f[0] = IFstart_B.Saturation_h;
              IFstart_B.Merge_f[1] = IFstart_B.Saturation;

              /* End of Outputs for SubSystem: '<S91>/Passthrough' */
            }

            /* End of If: '<S91>/If' */
            /* End of Outputs for SubSystem: '<S88>/D-Q Equivalence' */
          }

          /* End of If: '<S88>/If' */

          /* Outputs for Atomic SubSystem: '<S65>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S72>/a16' */
          arm_inv_park_f32(IFstart_B.Merge_f[0], IFstart_B.Merge_f[1],
                           &IFstart_B.algDD_o1_a, &IFstart_B.algDD_o2_j,
                           IFstart_B.Sum4_h, IFstart_B.Sum6);

          /* End of Outputs for SubSystem: '<S65>/Two inputs CRL' */

          /* DataStoreRead: '<S18>/Data Store Read1' */
          IFstart_B.DataStoreRead1_n = IFstart_DWork.Enable;

          /* Switch: '<S18>/Switch4' incorporates:
           *  Constant: '<S18>/stop'
           */
          if (IFstart_B.DataStoreRead1_n) {
            /* Gain: '<S80>/sqrt3_by_two' */
            IFstart_B.sqrt3_by_two = IFstart_P.sqrt3_by_two_Gain *
              IFstart_B.algDD_o2_j;

            /* Gain: '<S80>/one_by_two' */
            IFstart_B.one_by_two = IFstart_P.one_by_two_Gain *
              IFstart_B.algDD_o1_a;

            /* Sum: '<S80>/add_c' */
            IFstart_B.add_c = (0.0F - IFstart_B.one_by_two) -
              IFstart_B.sqrt3_by_two;

            /* Gain: '<S80>/Kc' */
            IFstart_B.Kc = IFstart_P.Kc_Gain * IFstart_B.add_c;

            /* Sum: '<S80>/add_b' */
            IFstart_B.add_b = IFstart_B.sqrt3_by_two - IFstart_B.one_by_two;

            /* Gain: '<S80>/Kb' */
            IFstart_B.Kb = IFstart_P.Kb_Gain * IFstart_B.add_b;

            /* Gain: '<S80>/Ka' */
            IFstart_B.Ka = IFstart_P.Ka_Gain * IFstart_B.algDD_o1_a;

            /* MinMax: '<S77>/Min' */
            Bias = fminf(IFstart_B.Ka, IFstart_B.Kb);
            Bias = fminf(Bias, IFstart_B.Kc);

            /* MinMax: '<S77>/Min' */
            IFstart_B.Min = Bias;

            /* MinMax: '<S77>/Max' */
            Bias = fmaxf(IFstart_B.Ka, IFstart_B.Kb);
            Bias = fmaxf(Bias, IFstart_B.Kc);

            /* MinMax: '<S77>/Max' */
            IFstart_B.Max = Bias;

            /* Sum: '<S77>/Add' */
            IFstart_B.Add = IFstart_B.Max + IFstart_B.Min;

            /* Gain: '<S77>/one_by_two' */
            IFstart_B.one_by_two_k = IFstart_P.one_by_two_Gain_g * IFstart_B.Add;

            /* Sum: '<S76>/Add2' */
            IFstart_B.Add2 = IFstart_B.one_by_two_k + IFstart_B.Kc;

            /* Sum: '<S76>/Add1' */
            IFstart_B.Add1_k = IFstart_B.Kb + IFstart_B.one_by_two_k;

            /* Sum: '<S76>/Add3' */
            IFstart_B.Add3 = IFstart_B.Ka + IFstart_B.one_by_two_k;

            /* Gain: '<S76>/Gain' */
            IFstart_B.Gain[0] = IFstart_P.Gain_Gain_mr * IFstart_B.Add3;
            IFstart_B.Gain[1] = IFstart_P.Gain_Gain_mr * IFstart_B.Add1_k;
            IFstart_B.Gain[2] = IFstart_P.Gain_Gain_mr * IFstart_B.Add2;

            /* Gain: '<S18>/Gain' */
            ADvoltage = IFstart_P.Gain_Gain_k * IFstart_B.Gain[0];
            IFstart_B.Gain_n[0] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += IFstart_P.Constant1_Value_a;
            IFstart_B.Add_c[0] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= IFstart_P.Gain1_Gain;
            IFstart_B.Gain1[0] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            IFstart_B.Switch4[0] = ADvoltage;

            /* Gain: '<S18>/Gain' */
            ADvoltage = IFstart_P.Gain_Gain_k * IFstart_B.Gain[1];
            IFstart_B.Gain_n[1] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += IFstart_P.Constant1_Value_a;
            IFstart_B.Add_c[1] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= IFstart_P.Gain1_Gain;
            IFstart_B.Gain1[1] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            IFstart_B.Switch4[1] = ADvoltage;

            /* Gain: '<S18>/Gain' */
            ADvoltage = IFstart_P.Gain_Gain_k * IFstart_B.Gain[2];
            IFstart_B.Gain_n[2] = ADvoltage;

            /* Sum: '<S18>/Add' incorporates:
             *  Constant: '<S18>/Constant1'
             */
            ADvoltage += IFstart_P.Constant1_Value_a;
            IFstart_B.Add_c[2] = ADvoltage;

            /* Gain: '<S18>/Gain1' */
            ADvoltage *= IFstart_P.Gain1_Gain;
            IFstart_B.Gain1[2] = ADvoltage;

            /* Switch: '<S18>/Switch4' */
            IFstart_B.Switch4[2] = ADvoltage;
          } else {
            ADvoltage = IFstart_P.stop_Value;

            /* Switch: '<S18>/Switch4' incorporates:
             *  Constant: '<S18>/stop'
             */
            IFstart_B.Switch4[0] = ADvoltage;
            IFstart_B.Switch4[1] = ADvoltage;
            IFstart_B.Switch4[2] = ADvoltage;
          }

          /* End of Switch: '<S18>/Switch4' */

          /* MATLABSystem: '<S213>/PWM Output' */
          setDutyCycleInPercentageChannel1(IFstart_DWork.obj_e3.TimerHandle,
            IFstart_B.Switch4[0]);
          setDutyCycleInPercentageChannel2(IFstart_DWork.obj_e3.TimerHandle,
            IFstart_B.Switch4[1]);
          setDutyCycleInPercentageChannel3(IFstart_DWork.obj_e3.TimerHandle,
            IFstart_B.Switch4[2]);

          /* Signum: '<S29>/Sign' */
          ADvoltage = IFstart_B.Sum2;
          if (rtIsNaNF(ADvoltage)) {
            /* Signum: '<S29>/Sign' */
            IFstart_B.Sign = (rtNaNF);
          } else if (ADvoltage < 0.0F) {
            /* Signum: '<S29>/Sign' */
            IFstart_B.Sign = -1.0F;
          } else {
            /* Signum: '<S29>/Sign' */
            IFstart_B.Sign = (real32_T)(ADvoltage > 0.0F);
          }

          /* End of Signum: '<S29>/Sign' */

          /* Gain: '<S29>/Eta' incorporates:
           *  Gain: '<S30>/Eta'
           */
          y_tmp = IFstart_P.SlidingModeObserver_CurrentObse / 2.2;
          Bias = (real32_T)y_tmp;

          /* Gain: '<S29>/Eta' */
          IFstart_B.Eta = Bias * IFstart_B.Sign;

          /* Sum: '<S29>/Sum' */
          IFstart_B.Sum_c = IFstart_B.Delay5[0] - IFstart_B.Sum4;

          /* Gain: '<S29>/b' */
          IFstart_B.b = IFstart_P.b_Gain * IFstart_B.Sum_c;

          /* Gain: '<S29>/a' */
          IFstart_B.a_n = IFstart_P.a_Gain_a * IFstart_B.Delay_b;

          /* Sum: '<S29>/Sum1' */
          IFstart_B.Sum1_n = (IFstart_B.b - IFstart_B.Eta) + IFstart_B.a_n;

          /* Signum: '<S30>/Sign' */
          ADvoltage = IFstart_B.Sum2_e;
          if (rtIsNaNF(ADvoltage)) {
            /* Signum: '<S30>/Sign' */
            IFstart_B.Sign_b = (rtNaNF);
          } else if (ADvoltage < 0.0F) {
            /* Signum: '<S30>/Sign' */
            IFstart_B.Sign_b = -1.0F;
          } else {
            /* Signum: '<S30>/Sign' */
            IFstart_B.Sign_b = (real32_T)(ADvoltage > 0.0F);
          }

          /* End of Signum: '<S30>/Sign' */

          /* Gain: '<S30>/Eta' */
          IFstart_B.Eta_h = Bias * IFstart_B.Sign_b;

          /* Sum: '<S30>/Sum' */
          IFstart_B.Sum_l = IFstart_B.Delay5[1] - IFstart_B.Sum4_d;

          /* Gain: '<S30>/b' */
          IFstart_B.b_j = IFstart_P.b_Gain_g * IFstart_B.Sum_l;

          /* Gain: '<S30>/a' */
          IFstart_B.a_k = IFstart_P.a_Gain_g * IFstart_B.Delay_f;

          /* Sum: '<S30>/Sum1' */
          IFstart_B.Sum1_m = (IFstart_B.b_j - IFstart_B.Eta_h) + IFstart_B.a_k;

          /* Gain: '<S34>/PositionToCount' */
          IFstart_B.PositionToCount = (uint32_T)(IFstart_P.PositionToCount_Gain *
            IFstart_B.Switch_o3);

          /* Delay: '<S34>/Delay' */
          IFstart_B.Delay =
            IFstart_DWork.Delay_DSTATE_a[IFstart_DWork.CircBufIdx];

          /* Sum: '<S34>/SpeedCount' */
          IFstart_B.SpeedCount = (int32_T)IFstart_B.PositionToCount - (int32_T)
            IFstart_B.Delay;

          /* DataTypeConversion: '<S51>/DTC' */
          IFstart_B.DTC = (real32_T)IFstart_B.SpeedCount;

          /* Gain: '<S34>/SpeedGain' */
          IFstart_B.SpeedGain = IFstart_P.SpeedGain_Gain * IFstart_B.DTC;

          /* Switch: '<S33>/Switch1' incorporates:
           *  Constant: '<S33>/UseInputPort'
           */
          if (IFstart_P.UseInputPort_Value_p > IFstart_P.Switch1_Threshold_a) {
            /* Sum: '<S33>/Sum' incorporates:
             *  Constant: '<S33>/One'
             *  Constant: '<S33>/a'
             */
            IFstart_B.Sum_bn = IFstart_P.One_Value_e - IFstart_P.a_Value_i;

            /* Switch: '<S33>/Switch1' incorporates:
             *  Constant: '<S33>/a'
             */
            IFstart_B.Switch1_d[0] = IFstart_P.a_Value_i;
            IFstart_B.Switch1_d[1] = IFstart_B.Sum_bn;
          } else {
            /* Switch: '<S33>/Switch1' incorporates:
             *  Constant: '<S33>/FilterConstant'
             *  Constant: '<S33>/OneMinusFilterConstant'
             */
            IFstart_B.Switch1_d[0] = IFstart_P.FilterConstant_Value_o;
            IFstart_B.Switch1_d[1] = IFstart_P.OneMinusFilterConstant_Value_n;
          }

          /* End of Switch: '<S33>/Switch1' */

          /* Product: '<S49>/Product' */
          IFstart_B.Product_m = IFstart_B.SpeedGain * IFstart_B.Switch1_d[0];

          /* UnitDelay: '<S49>/Unit Delay' */
          IFstart_B.UnitDelay_i = IFstart_DWork.UnitDelay_DSTATE_bl;

          /* Product: '<S49>/Product1' */
          IFstart_B.Product1_l2 = IFstart_B.Switch1_d[1] * IFstart_B.UnitDelay_i;

          /* Sum: '<S49>/Add1' */
          IFstart_B.Add1_g = IFstart_B.Product_m + IFstart_B.Product1_l2;

          /* DeadZone: '<S133>/DeadZone' */
          if (IFstart_B.Sum_o > IFstart_P.DiscretePIControllerwithantiw_b) {
            /* DeadZone: '<S133>/DeadZone' */
            IFstart_B.DeadZone = IFstart_B.Sum_o -
              IFstart_P.DiscretePIControllerwithantiw_b;
          } else if (IFstart_B.Sum_o >=
                     IFstart_P.DiscretePIControllerwithantiw_f) {
            /* DeadZone: '<S133>/DeadZone' */
            IFstart_B.DeadZone = 0.0F;
          } else {
            /* DeadZone: '<S133>/DeadZone' */
            IFstart_B.DeadZone = IFstart_B.Sum_o -
              IFstart_P.DiscretePIControllerwithantiw_f;
          }

          /* End of DeadZone: '<S133>/DeadZone' */

          /* RelationalOperator: '<S131>/Relational Operator' incorporates:
           *  Constant: '<S131>/Clamping_zero'
           */
          IFstart_B.RelationalOperator = (IFstart_P.Clamping_zero_Value !=
            IFstart_B.DeadZone);

          /* RelationalOperator: '<S131>/fix for DT propagation issue' incorporates:
           *  Constant: '<S131>/Clamping_zero'
           */
          IFstart_B.fixforDTpropagationissue = (IFstart_B.DeadZone >
            IFstart_P.Clamping_zero_Value);

          /* Switch: '<S131>/Switch1' */
          if (IFstart_B.fixforDTpropagationissue) {
            /* Switch: '<S131>/Switch1' incorporates:
             *  Constant: '<S131>/Constant'
             */
            IFstart_B.Switch1_dl = IFstart_P.Constant_Value_l;
          } else {
            /* Switch: '<S131>/Switch1' incorporates:
             *  Constant: '<S131>/Constant2'
             */
            IFstart_B.Switch1_dl = IFstart_P.Constant2_Value_i;
          }

          /* End of Switch: '<S131>/Switch1' */

          /* Product: '<S138>/IProd Out' incorporates:
           *  Constant: '<S69>/Ki'
           */
          IFstart_B.IProdOut = IFstart_B.Sum_b * IFstart_P.Ki_Value;

          /* RelationalOperator: '<S131>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S131>/Clamping_zero'
           */
          IFstart_B.fixforDTpropagationissue1 = (IFstart_B.IProdOut >
            IFstart_P.Clamping_zero_Value);

          /* Switch: '<S131>/Switch2' */
          if (IFstart_B.fixforDTpropagationissue1) {
            /* Switch: '<S131>/Switch2' incorporates:
             *  Constant: '<S131>/Constant3'
             */
            IFstart_B.Switch2_g = IFstart_P.Constant3_Value_m;
          } else {
            /* Switch: '<S131>/Switch2' incorporates:
             *  Constant: '<S131>/Constant4'
             */
            IFstart_B.Switch2_g = IFstart_P.Constant4_Value_l;
          }

          /* End of Switch: '<S131>/Switch2' */

          /* RelationalOperator: '<S131>/Equal1' */
          IFstart_B.Equal1 = (IFstart_B.Switch1_dl == IFstart_B.Switch2_g);

          /* Logic: '<S131>/AND3' */
          IFstart_B.AND3 = (IFstart_B.RelationalOperator && IFstart_B.Equal1);

          /* Switch: '<S131>/Switch' */
          if (IFstart_B.AND3) {
            /* Switch: '<S131>/Switch' incorporates:
             *  Constant: '<S131>/Constant1'
             */
            IFstart_B.Switch_g = IFstart_P.Constant1_Value_k;
          } else {
            /* Switch: '<S131>/Switch' */
            IFstart_B.Switch_g = IFstart_B.IProdOut;
          }

          /* End of Switch: '<S131>/Switch' */

          /* DeadZone: '<S186>/DeadZone' */
          if (IFstart_B.Sum_i > IFstart_P.DiscretePIControllerwithantiw_e) {
            /* DeadZone: '<S186>/DeadZone' */
            IFstart_B.DeadZone_h = IFstart_B.Sum_i -
              IFstart_P.DiscretePIControllerwithantiw_e;
          } else if (IFstart_B.Sum_i >=
                     IFstart_P.DiscretePIControllerwithantiwin) {
            /* DeadZone: '<S186>/DeadZone' */
            IFstart_B.DeadZone_h = 0.0F;
          } else {
            /* DeadZone: '<S186>/DeadZone' */
            IFstart_B.DeadZone_h = IFstart_B.Sum_i -
              IFstart_P.DiscretePIControllerwithantiwin;
          }

          /* End of DeadZone: '<S186>/DeadZone' */

          /* RelationalOperator: '<S184>/Relational Operator' incorporates:
           *  Constant: '<S184>/Clamping_zero'
           */
          IFstart_B.RelationalOperator_l = (IFstart_P.Clamping_zero_Value_k !=
            IFstart_B.DeadZone_h);

          /* RelationalOperator: '<S184>/fix for DT propagation issue' incorporates:
           *  Constant: '<S184>/Clamping_zero'
           */
          IFstart_B.fixforDTpropagationissue_i = (IFstart_B.DeadZone_h >
            IFstart_P.Clamping_zero_Value_k);

          /* Switch: '<S184>/Switch1' */
          if (IFstart_B.fixforDTpropagationissue_i) {
            /* Switch: '<S184>/Switch1' incorporates:
             *  Constant: '<S184>/Constant'
             */
            IFstart_B.Switch1_c = IFstart_P.Constant_Value_jm;
          } else {
            /* Switch: '<S184>/Switch1' incorporates:
             *  Constant: '<S184>/Constant2'
             */
            IFstart_B.Switch1_c = IFstart_P.Constant2_Value_e;
          }

          /* End of Switch: '<S184>/Switch1' */

          /* Product: '<S191>/IProd Out' incorporates:
           *  Constant: '<S69>/Ki'
           */
          IFstart_B.IProdOut_b = IFstart_B.Sum_k * IFstart_P.Ki_Value;

          /* RelationalOperator: '<S184>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S184>/Clamping_zero'
           */
          IFstart_B.fixforDTpropagationissue1_m = (IFstart_B.IProdOut_b >
            IFstart_P.Clamping_zero_Value_k);

          /* Switch: '<S184>/Switch2' */
          if (IFstart_B.fixforDTpropagationissue1_m) {
            /* Switch: '<S184>/Switch2' incorporates:
             *  Constant: '<S184>/Constant3'
             */
            IFstart_B.Switch2_m = IFstart_P.Constant3_Value_h;
          } else {
            /* Switch: '<S184>/Switch2' incorporates:
             *  Constant: '<S184>/Constant4'
             */
            IFstart_B.Switch2_m = IFstart_P.Constant4_Value_m;
          }

          /* End of Switch: '<S184>/Switch2' */

          /* RelationalOperator: '<S184>/Equal1' */
          IFstart_B.Equal1_n = (IFstart_B.Switch1_c == IFstart_B.Switch2_m);

          /* Logic: '<S184>/AND3' */
          IFstart_B.AND3_m = (IFstart_B.RelationalOperator_l &&
                              IFstart_B.Equal1_n);

          /* Switch: '<S184>/Switch' */
          if (IFstart_B.AND3_m) {
            /* Switch: '<S184>/Switch' incorporates:
             *  Constant: '<S184>/Constant1'
             */
            IFstart_B.Switch_e = IFstart_P.Constant1_Value_c;
          } else {
            /* Switch: '<S184>/Switch' */
            IFstart_B.Switch_e = IFstart_B.IProdOut_b;
          }

          /* End of Switch: '<S184>/Switch' */

          /* SignalConversion generated from: '<S2>/Delay5' */
          IFstart_B.TmpSignalConversionAtDelay5Inpo[0] = IFstart_B.algDD_o1_a;
          IFstart_B.TmpSignalConversionAtDelay5Inpo[1] = IFstart_B.algDD_o2_j;
          IFstart_B.TmpSignalConversionAtDelay5Inpo[2] = IFstart_B.Kalpha;
          IFstart_B.TmpSignalConversionAtDelay5Inpo[3] = IFstart_B.Kbeta;

          /* Update for UnitDelay: '<S39>/Unit Delay1' */
          IFstart_DWork.UnitDelay1_DSTATE = IFstart_B.Eta;

          /* Update for UnitDelay: '<S39>/Unit Delay' */
          IFstart_DWork.UnitDelay_DSTATE = IFstart_B.Sum2;

          /* Update for Delay: '<S2>/Delay5' */
          IFstart_DWork.Delay5_DSTATE[0] =
            IFstart_B.TmpSignalConversionAtDelay5Inpo[0];
          IFstart_DWork.Delay5_DSTATE[1] =
            IFstart_B.TmpSignalConversionAtDelay5Inpo[1];
          IFstart_DWork.Delay5_DSTATE[2] =
            IFstart_B.TmpSignalConversionAtDelay5Inpo[2];
          IFstart_DWork.Delay5_DSTATE[3] =
            IFstart_B.TmpSignalConversionAtDelay5Inpo[3];

          /* Update for Delay: '<S29>/Delay' */
          IFstart_DWork.Delay_DSTATE = IFstart_B.Sum1_n;

          /* Update for Delay: '<S39>/Delay1' */
          IFstart_DWork.Delay1_DSTATE = IFstart_B.Sum4;

          /* Update for UnitDelay: '<S43>/Unit Delay' */
          IFstart_DWork.UnitDelay_DSTATE_b = IFstart_B.Add1_o;

          /* Update for UnitDelay: '<S40>/Unit Delay1' */
          IFstart_DWork.UnitDelay1_DSTATE_m = IFstart_B.Eta_h;

          /* Update for UnitDelay: '<S40>/Unit Delay' */
          IFstart_DWork.UnitDelay_DSTATE_p = IFstart_B.Sum2_e;

          /* Update for Delay: '<S30>/Delay' */
          IFstart_DWork.Delay_DSTATE_h = IFstart_B.Sum1_m;

          /* Update for Delay: '<S40>/Delay1' */
          IFstart_DWork.Delay1_DSTATE_e = IFstart_B.Sum4_d;

          /* Update for UnitDelay: '<S46>/Unit Delay' */
          IFstart_DWork.UnitDelay_DSTATE_d = IFstart_B.Add1_p;

          /* Update for Delay: '<S27>/Delay' */
          IFstart_DWork.Delay_DSTATE_p = IFstart_B.Add1_g;

          /* Update for UnitDelay: '<S61>/Unit Delay' */
          IFstart_DWork.UnitDelay_DSTATE_bp = IFstart_B.Add1_m;

          /* Update for DiscreteIntegrator: '<S194>/Integrator' */
          IFstart_DWork.Integrator_DSTATE += IFstart_P.Integrator_gainval *
            IFstart_B.Switch_e;
          Integrator_PrevResetState_tmp = (int8_T)IFstart_B.LogicalOperator_n;
          IFstart_DWork.Integrator_PrevResetState =
            Integrator_PrevResetState_tmp;

          /* Update for DiscreteIntegrator: '<S141>/Integrator' */
          IFstart_DWork.Integrator_DSTATE_l += IFstart_P.Integrator_gainval_p *
            IFstart_B.Switch_g;
          IFstart_DWork.Integrator_PrevResetState_i =
            Integrator_PrevResetState_tmp;

          /* Update for Delay: '<S34>/Delay' */
          IFstart_DWork.Delay_DSTATE_a[IFstart_DWork.CircBufIdx] =
            IFstart_B.PositionToCount;
          if (IFstart_DWork.CircBufIdx < 118U) {
            IFstart_DWork.CircBufIdx++;
          } else {
            IFstart_DWork.CircBufIdx = 0U;
          }

          /* End of Update for Delay: '<S34>/Delay' */

          /* Update for UnitDelay: '<S49>/Unit Delay' */
          IFstart_DWork.UnitDelay_DSTATE_bl = IFstart_B.Add1_g;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S215>/Hardware Interrupt' */

        /* RateTransition: '<Root>/RT1' incorporates:
         *  Gain: '<S54>/OP_Gain*R_shunt1'
         */
        IFstart_DWork.RT1_Buffer[(IFstart_DWork.RT1_semaphoreTaken == 0) << 1] =
          IFstart_B.OP_GainR_shunt1[0];
        IFstart_DWork.RT1_Buffer[1 + ((IFstart_DWork.RT1_semaphoreTaken == 0) <<
          1)] = IFstart_B.OP_GainR_shunt1[1];
        IFstart_DWork.RT1_ActiveBufIdx = (int8_T)
          (IFstart_DWork.RT1_semaphoreTaken == 0);
      }
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void IFstart_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
