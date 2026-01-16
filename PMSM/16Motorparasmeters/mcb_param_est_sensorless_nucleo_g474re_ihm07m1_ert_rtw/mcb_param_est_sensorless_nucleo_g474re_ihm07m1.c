/*
 * File: mcb_param_est_sensorless_nucleo_g474re_ihm07m1.c
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

#include "mcb_param_est_sensorless_nucleo_g474re_ihm07m1.h"
#include "rtwtypes.h"
#include "mcb_param_est_sensorless_nucleo_g474re_ihm07m1_types.h"
#include "mcb_param_est_sensorless_nucleo_g474re_ihm07m1_private.h"
#include "arm_math.h"
#include <math.h>
#include "mw_cmsis.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "zero_crossing_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Block signals (default storage) */
BlockIO_mcb_param_est_sensorles mcb_param_est_sensorless_nucl_B;

/* Block states (default storage) */
D_Work_mcb_param_est_sensorless mcb_param_est_sensorless__DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_mcb_param_est_s mcb_param_est_se_PrevZCSigState;

/* Real-time model */
static RT_MODEL_mcb_param_est_sensorle mcb_param_est_sensorless_nuc_M_;
RT_MODEL_mcb_param_est_sensorle *const mcb_param_est_sensorless_nuc_M =
  &mcb_param_est_sensorless_nuc_M_;

/* Forward declaration for local functions */
static void mcb_param_est__SystemCore_setup(stm32cube_blocks_AnalogInput_mc *obj);

/* Forward declaration for local functions */
static void mcb_param_e_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_mcb_ *obj);
static void mcb_param_es_SystemCore_setup_h(stm32cube_blocks_AnalogInput_mc *obj);
static void mcb_param_e_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mcb_ *obj);

/* Forward declaration for local functions */
static void mcb_param_es_SystemCore_setup_g(stm32cube_blocks_UARTRead_mcb_p *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_param_est_sensorless_nucleo_g474re_ihm07m1_SetEventsForThisBaseStep
  (boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_param_est_sensorless_nuc_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(mcb_param_est_sensorless_nuc_M, 2));
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
  (mcb_param_est_sensorless_nuc_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_param_est_sensorless_nuc_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.0005s, 0.0s] */
    mcb_param_est_sensorless_nuc_M->Timing.TaskCounters.TID[1] = 0;
  }

  (mcb_param_est_sensorless_nuc_M->Timing.TaskCounters.TID[2])++;
  if ((mcb_param_est_sensorless_nuc_M->Timing.TaskCounters.TID[2]) > 4999) {/* Sample time: [0.5s, 0.0s] */
    mcb_param_est_sensorless_nuc_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void mcb_param_est__SystemCore_setup(stm32cube_blocks_AnalogInput_mc *obj)
{
  void * internalBufferPtr;
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S311>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  internalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S311>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.InternalBufferPtr = internalBufferPtr;

  /* Start for MATLABSystem: '<S311>/Analog to Digital Converter' */
  adcStructLoc.peripheralPtr = ADC2;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 3U;
  adcStructLoc.InjectedNoOfConversion = 3U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS);
  enableADCAutomaticCalibrationOffset(obj->ADCHandle, 2);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (rtIsNaNF(u0) || rtIsNaNF(u1)) {
    y = (rtNaNF);
  } else if (rtIsInfF(u0) && rtIsInfF(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u1 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2f((real32_T)tmp_0, (real32_T)tmp);
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

/*
 * Output and update for atomic system:
 *    '<S33>/atan2'
 *    '<S34>/atan2'
 */
void mcb_param_est_sensorl_atan2(real32_T rtu_A, real32_T rtu_B, uint16_T
  rtp_outputUnit, rtB_atan2_mcb_param_est_sensorl *localB)
{
  /* Trigonometry: '<S35>/Atan2' */
  localB->Atan2 = rt_atan2f_snf(rtu_A, rtu_B);

  /* Switch: '<S35>/Switch' incorporates:
   *  Constant: '<S35>/Constant'
   */
  if (rtp_outputUnit > 1) {
    /* Outputs for Atomic SubSystem: '<S35>/Per Unit' */
    /* Gain: '<S38>/Gain' */
    localB->Gain = 0.159154937F * localB->Atan2;

    /* Switch: '<S38>/Switch' */
    if (localB->Gain >= 0.0F) {
      /* Switch: '<S38>/Switch' */
      localB->Switch_g = localB->Gain;
    } else {
      /* Bias: '<S38>/Bias' */
      localB->Bias = localB->Gain + 1.0F;

      /* Switch: '<S38>/Switch' */
      localB->Switch_g = localB->Bias;
    }

    /* End of Switch: '<S38>/Switch' */
    /* End of Outputs for SubSystem: '<S35>/Per Unit' */

    /* Switch: '<S35>/Switch' */
    localB->Switch = localB->Switch_g;
  } else {
    /* Switch: '<S35>/Switch' */
    localB->Switch = localB->Atan2;
  }

  /* End of Switch: '<S35>/Switch' */

  /* AlgorithmDescriptorDelegate generated from: '<S35>/a16' */
  localB->algDD = localB->Switch;
}

/*
 * Output and update for atomic system:
 *    '<S67>/Two phase CRL wrap'
 *    '<S73>/Two phase CRL wrap'
 *    '<S99>/Two phase CRL wrap'
 */
void mcb_param_e_TwophaseCRLwrap(real32_T rtu_a, real32_T rtu_b,
  rtB_TwophaseCRLwrap_mcb_param_e *localB)
{
  /* AlgorithmDescriptorDelegate generated from: '<S68>/a16' */
  arm_clarke_f32(rtu_a, rtu_b, &localB->algDD_o1, &localB->algDD_o2);
}

/*
 * Output and update for atomic system:
 *    '<S65>/Two inputs CRL'
 *    '<S72>/Two inputs CRL'
 */
void mcb_param_est__TwoinputsCRL(real32_T rtu_Alpha, real32_T rtu_Beta, real32_T
  rtu_sine, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_param_est_ *localB)
{
  /* AlgorithmDescriptorDelegate generated from: '<S69>/a16' */
  arm_park_f32(rtu_Alpha, rtu_Beta, &localB->algDD_o1, &localB->algDD_o2,
               rtu_sine, rtu_cos);
}

/*
 * Output and update for atomic system:
 *    '<S77>/Two inputs CRL'
 *    '<S89>/Two inputs CRL'
 */
void mcb_param_es_TwoinputsCRL_j(real32_T rtu_Ds, real32_T rtu_Qs, real32_T
  rtu_sin, real32_T rtu_cos, rtB_TwoinputsCRL_mcb_param_es_d *localB)
{
  /* AlgorithmDescriptorDelegate generated from: '<S78>/a16' */
  arm_inv_park_f32(rtu_Ds, rtu_Qs, &localB->algDD_o1, &localB->algDD_o2, rtu_sin,
                   rtu_cos);
}

/*
 * Output and update for action system:
 *    '<S95>/If Action Subsystem'
 *    '<S237>/If Action Subsystem'
 *    '<S247>/If Action Subsystem'
 *    '<S252>/If Action Subsystem'
 */
void mcb_param_IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem_mcb_param *localB)
{
  /* DataTypeConversion: '<S97>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)floorf(rtu_In1);

  /* DataTypeConversion: '<S97>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S97>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for action system:
 *    '<S95>/If Action Subsystem1'
 *    '<S237>/If Action Subsystem1'
 *    '<S247>/If Action Subsystem1'
 *    '<S252>/If Action Subsystem1'
 */
void mcb_para_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1,
  rtB_IfActionSubsystem1_mcb_para *localB)
{
  /* DataTypeConversion: '<S98>/Convert_uint16' */
  localB->Convert_uint16 = (int16_T)rtu_In1;

  /* DataTypeConversion: '<S98>/Convert_back' */
  localB->Convert_back = localB->Convert_uint16;

  /* Sum: '<S98>/Sum' */
  *rty_Out1 = rtu_In1 - localB->Convert_back;
}

/*
 * Output and update for enable system:
 *    '<S85>/Accumulate'
 *    '<S232>/Accumulate'
 *    '<S242>/Accumulate'
 */
void mcb_param_est_se_Accumulate(boolean_T rtu_Enable, real32_T rtu_Theta,
  real32_T rtu_Theta_e_prev, rtB_Accumulate_mcb_param_est_se *localB,
  rtDW_Accumulate_mcb_param_est_s *localDW)
{
  /* Outputs for Enabled SubSystem: '<S85>/Accumulate' incorporates:
   *  EnablePort: '<S101>/Enable'
   */
  if (rtu_Enable) {
    /* Delay: '<S101>/Delay' */
    localB->Delay = localDW->Delay_DSTATE;

    /* Outputs for Enabled SubSystem: '<S101>/Subsystem' incorporates:
     *  EnablePort: '<S102>/Enable'
     */
    if (localB->Delay) {
      /* SignalConversion generated from: '<S102>/Input' */
      localB->Input = rtu_Theta;
    }

    /* End of Outputs for SubSystem: '<S101>/Subsystem' */

    /* Sum: '<S101>/Add' */
    localB->Add = localB->Input + rtu_Theta_e_prev;

    /* DataTypeConversion: '<S101>/Data Type Conversion' */
    localB->DataTypeConversion = (int16_T)floorf(localB->Add);

    /* DataTypeConversion: '<S101>/Data Type Conversion1' */
    localB->DataTypeConversion1 = localB->DataTypeConversion;

    /* Sum: '<S101>/Add1' */
    localB->Add1 = localB->Add - localB->DataTypeConversion1;

    /* Update for Delay: '<S101>/Delay' incorporates:
     *  Constant: '<S101>/Constant'
     */
    localDW->Delay_DSTATE = true;
  }

  /* End of Outputs for SubSystem: '<S85>/Accumulate' */
}

static void mcb_param_e_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_mcb_ *obj)
{
  uint8_T * txBufferPtr;
  UART_Type_T b;

  /* Start for MATLABSystem: '<S306>/UART//USART Write' */
  obj->UARTInternalBuffer = GET_LPUART1_TRANSMIT_BUFFER();
  txBufferPtr = obj->UARTInternalBuffer;
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_DMA_MODE;
  b.peripheralPtr = LPUART1;
  b.txdmaPeripheralPtr = DMA1;
  b.txdmastream = LL_DMA_CHANNEL_2;
  b.buffer.txBufferSize = 128U;
  b.buffer.txBufferPtr = txBufferPtr;
  obj->UARTHandle = MW_LPUART_Initialize(&b);
}

static void mcb_param_es_SystemCore_setup_h(stm32cube_blocks_AnalogInput_mc *obj)
{
  void * internalBufferPtr;
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S271>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  internalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S271>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.InternalBufferPtr = internalBufferPtr;

  /* Start for MATLABSystem: '<S271>/Analog to Digital Converter' */
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 3U;
  adcStructLoc.InjectedNoOfConversion = 3U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS);
  enableADCAutomaticCalibrationOffset(obj->ADCHandle, 2);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

static void mcb_param_e_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mcb_ *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S275>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S275>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S275>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void mcb_param_es_SystemCore_setup_g(stm32cube_blocks_UARTRead_mcb_p *obj)
{
  uint8_T * rxBufferPtr;
  UART_Type_T b;

  /* Start for MATLABSystem: '<S320>/UART//USART Read' */
  obj->isInitialized = 1;
  obj->UARTInternalBuffer = GET_LPUART1_RECEIVE_BUFFER();
  rxBufferPtr = obj->UARTInternalBuffer;
  b.enableRxOrTx = 1.0;

  /* Start for MATLABSystem: '<S320>/UART//USART Read' */
  b.mode = UART_RX_DMA_MODE;
  b.peripheralPtr = LPUART1;
  b.rxdmaPeripheralPtr = DMA1;
  b.rxdmastream = LL_DMA_CHANNEL_1;
  b.disableDMAIntOnError = false;

  /* Start for MATLABSystem: '<S320>/UART//USART Read' */
  b.buffer.rxBufferSize = 1024U;
  b.buffer.rxBufferPtr = rxBufferPtr;
  obj->UARTHandle = MW_LPUART_Initialize(&b);
  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void mcb_param_est_sensorless_nucleo_g474re_ihm07m1_step0(void) /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void mcb_param_est_sensorless_nucleo_g474re_ihm07m1_step1(void) /* Sample time: [0.0005s, 0.0s] */
{
  int32_T y;
  real32_T tmp[2];
  real32_T u0;
  uint32_T dataBytesToRead;
  uint32_T receivedLength;
  uint16_T status;

  /* MATLABSystem: '<S320>/UART//USART Read' */
  dataBytesToRead = getBytesToBeReadFromBuffer
    (mcb_param_est_sensorless__DWork.obj_e.UARTHandle, 8U, 0U);
  if (dataBytesToRead > 0U) {
    y = (int32_T)(dataBytesToRead % 4U);
    receivedLength = dataBytesToRead - (uint32_T)y;
    if (receivedLength > dataBytesToRead) {
      receivedLength = 0U;
    }

    dataBytesToRead = receivedLength;
    status = MW_LPUART_ReceiveUsingBuffer
      (mcb_param_est_sensorless__DWork.obj_e.UARTHandle, &tmp[0],
       dataBytesToRead, &receivedLength);
  } else {
    status = MW_LPUART_GetReadErrorStatus
      (mcb_param_est_sensorless__DWork.obj_e.UARTHandle);
  }

  if (dataBytesToRead < 8U) {
    status |= 1;
  }

  /* MATLABSystem: '<S320>/UART//USART Read' */
  mcb_param_est_sensorless_nucl_B.UARTUSARTRead_o1[0] = tmp[0];
  mcb_param_est_sensorless_nucl_B.UARTUSARTRead_o1[1] = tmp[1];

  /* MATLABSystem: '<S320>/UART//USART Read' */
  mcb_param_est_sensorless_nucl_B.UARTUSARTRead_o2 = status;

  /* RelationalOperator: '<S342>/Compare' incorporates:
   *  Constant: '<S342>/Constant'
   */
  mcb_param_est_sensorless_nucl_B.Compare =
    (mcb_param_est_sensorless_nucl_B.UARTUSARTRead_o2 == 0);

  /* Outputs for Enabled SubSystem: '<S320>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S343>/Enable'
   */
  if (mcb_param_est_sensorless_nucl_B.Compare) {
    /* SignalConversion generated from: '<S343>/In1' incorporates:
     *  MATLABSystem: '<S320>/UART//USART Read'
     */
    mcb_param_est_sensorless_nucl_B.In1[0] =
      mcb_param_est_sensorless_nucl_B.UARTUSARTRead_o1[0];
    mcb_param_est_sensorless_nucl_B.In1[1] =
      mcb_param_est_sensorless_nucl_B.UARTUSARTRead_o1[1];
  }

  /* End of Outputs for SubSystem: '<S320>/Enabled Subsystem' */

  /* DataTypeConversion: '<S320>/Data Type Conversion2' */
  mcb_param_est_sensorless_nucl_B.DataTypeConversion2 = (uint32_T)
    mcb_param_est_sensorless_nucl_B.In1[1];

  /* SwitchCase: '<S6>/Switch Case' */
  switch ((int32_T)mcb_param_est_sensorless_nucl_B.DataTypeConversion2) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S321>/Action Port'
     */
    /* DataStoreWrite: '<S321>/Data Store Write1' */
    mcb_param_est_sensorless__DWork.I_rated =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S331>/Action Port'
     */
    /* DataStoreWrite: '<S331>/Data Store Write2' */
    mcb_param_est_sensorless__DWork.V_rated =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem2' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem3' incorporates:
     *  ActionPort: '<S335>/Action Port'
     */
    /* DataStoreWrite: '<S335>/Data Store Write4' */
    mcb_param_est_sensorless__DWork.speed_rated =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem3' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem4' incorporates:
     *  ActionPort: '<S336>/Action Port'
     */
    /* DataStoreWrite: '<S336>/Data Store Write3' */
    mcb_param_est_sensorless__DWork.pole_pairs =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem4' */
    break;

   case 5:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem6' incorporates:
     *  ActionPort: '<S338>/Action Port'
     */
    /* DataStoreWrite: '<S338>/Data Store Write3' */
    mcb_param_est_sensorless__DWork.RsMeasTestTime =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem6' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem7' incorporates:
     *  ActionPort: '<S339>/Action Port'
     */
    /* DataStoreWrite: '<S339>/Data Store Write3' */
    mcb_param_est_sensorless__DWork.R_board =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem7' */
    break;

   case 7:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem8' incorporates:
     *  ActionPort: '<S340>/Action Port'
     */
    /* DataStoreWrite: '<S340>/Data Store Write3' */
    mcb_param_est_sensorless__DWork.currentPU_RWV =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem8' */
    break;

   case 8:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem9' incorporates:
     *  ActionPort: '<S341>/Action Port'
     */
    /* DataStoreWrite: '<S341>/Data Store Write3' */
    mcb_param_est_sensorless__DWork.sigma = mcb_param_est_sensorless_nucl_B.In1
      [0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem9' */
    break;

   case 9:
    break;

   case 10:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem5' incorporates:
     *  ActionPort: '<S337>/Action Port'
     */
    /* DataStoreWrite: '<S337>/Data Store Write3' */
    mcb_param_est_sensorless__DWork.inverter_V_max =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem5' */
    break;

   case 13:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem13' incorporates:
     *  ActionPort: '<S324>/Action Port'
     */
    /* Saturate: '<S324>/Saturation' */
    u0 = mcb_param_est_sensorless_nucl_B.In1[0];
    if (u0 > 0.5F) {
      /* Saturate: '<S324>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_i = 0.5F;
    } else if (u0 < 0.01F) {
      /* Saturate: '<S324>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_i = 0.01F;
    } else {
      /* Saturate: '<S324>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_i = u0;
    }

    /* End of Saturate: '<S324>/Saturation' */

    /* DataStoreWrite: '<S324>/Data Store Write' */
    mcb_param_est_sensorless__DWork.Vd_ref_OL =
      mcb_param_est_sensorless_nucl_B.Saturation_i;

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem13' */
    break;

   case 14:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem14' incorporates:
     *  ActionPort: '<S325>/Action Port'
     */
    /* DataStoreWrite: '<S325>/Data Store Write' */
    mcb_param_est_sensorless__DWork.freq_low =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem14' */
    break;

   case 15:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem15' incorporates:
     *  ActionPort: '<S326>/Action Port'
     */
    /* DataStoreWrite: '<S326>/Data Store Write' */
    mcb_param_est_sensorless__DWork.freq_high =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem15' */
    break;

   case 16:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem16' incorporates:
     *  ActionPort: '<S327>/Action Port'
     */
    /* DataStoreWrite: '<S327>/Data Store Write' */
    mcb_param_est_sensorless__DWork.freq_step =
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem16' */
    break;

   case 17:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem17' incorporates:
     *  ActionPort: '<S328>/Action Port'
     */
    /* Saturate: '<S328>/Saturation' */
    u0 = mcb_param_est_sensorless_nucl_B.In1[0];
    if (u0 > 0.5F) {
      /* Saturate: '<S328>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_j = 0.5F;
    } else if (u0 < 0.01F) {
      /* Saturate: '<S328>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_j = 0.01F;
    } else {
      /* Saturate: '<S328>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_j = u0;
    }

    /* End of Saturate: '<S328>/Saturation' */

    /* DataStoreWrite: '<S328>/Data Store Write' */
    mcb_param_est_sensorless__DWork.Vd_dc =
      mcb_param_est_sensorless_nucl_B.Saturation_j;

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem17' */
    break;

   case 18:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem18' incorporates:
     *  ActionPort: '<S329>/Action Port'
     */
    /* Saturate: '<S329>/Saturation' */
    u0 = mcb_param_est_sensorless_nucl_B.In1[0];
    if (u0 > 0.9F) {
      /* Saturate: '<S329>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_h = 0.9F;
    } else if (u0 < 0.001F) {
      /* Saturate: '<S329>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_h = 0.001F;
    } else {
      /* Saturate: '<S329>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_h = u0;
    }

    /* End of Saturate: '<S329>/Saturation' */

    /* DataStoreWrite: '<S329>/Data Store Write' */
    mcb_param_est_sensorless__DWork.Vdq_amp =
      mcb_param_est_sensorless_nucl_B.Saturation_h;

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem18' */
    break;

   case 19:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem19' incorporates:
     *  ActionPort: '<S330>/Action Port'
     */
    /* Saturate: '<S330>/Saturation' */
    u0 = mcb_param_est_sensorless_nucl_B.In1[0];
    if (u0 > 0.5F) {
      /* Saturate: '<S330>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_d = 0.5F;
    } else if (u0 < 0.05F) {
      /* Saturate: '<S330>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_d = 0.05F;
    } else {
      /* Saturate: '<S330>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_d = u0;
    }

    /* End of Saturate: '<S330>/Saturation' */

    /* DataStoreWrite: '<S330>/Data Store Write' */
    mcb_param_est_sensorless__DWork.Iq_ref_CL =
      mcb_param_est_sensorless_nucl_B.Saturation_d;

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem19' */
    break;

   case 20:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem20' incorporates:
     *  ActionPort: '<S332>/Action Port'
     */
    /* Saturate: '<S332>/Saturation' */
    u0 = mcb_param_est_sensorless_nucl_B.In1[0];
    if (u0 > 1.0F) {
      /* Saturate: '<S332>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_fo = 1.0F;
    } else if (u0 < 0.1F) {
      /* Saturate: '<S332>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_fo = 0.1F;
    } else {
      /* Saturate: '<S332>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_fo = u0;
    }

    /* End of Saturate: '<S332>/Saturation' */

    /* DataStoreWrite: '<S332>/Data Store Write' */
    mcb_param_est_sensorless__DWork.under_voltage_limit =
      mcb_param_est_sensorless_nucl_B.Saturation_fo;

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem20' */
    break;

   case 21:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem21' incorporates:
     *  ActionPort: '<S333>/Action Port'
     */
    /* Saturate: '<S333>/Saturation' */
    u0 = mcb_param_est_sensorless_nucl_B.In1[0];
    if (u0 > 1.2F) {
      /* Saturate: '<S333>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_f = 1.2F;
    } else if (u0 < 0.2F) {
      /* Saturate: '<S333>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_f = 0.2F;
    } else {
      /* Saturate: '<S333>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation_f = u0;
    }

    /* End of Saturate: '<S333>/Saturation' */

    /* DataStoreWrite: '<S333>/Data Store Write' */
    mcb_param_est_sensorless__DWork.over_current_limit =
      mcb_param_est_sensorless_nucl_B.Saturation_f;

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem21' */
    break;

   case 22:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem22' incorporates:
     *  ActionPort: '<S334>/Action Port'
     */
    /* Saturate: '<S334>/Saturation' */
    u0 = mcb_param_est_sensorless_nucl_B.In1[0];
    if (u0 > 0.7F) {
      /* Saturate: '<S334>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation = 0.7F;
    } else if (u0 < 0.25F) {
      /* Saturate: '<S334>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation = 0.25F;
    } else {
      /* Saturate: '<S334>/Saturation' */
      mcb_param_est_sensorless_nucl_B.Saturation = u0;
    }

    /* End of Saturate: '<S334>/Saturation' */

    /* DataStoreWrite: '<S334>/Data Store Write1' */
    mcb_param_est_sensorless__DWork.inertia_end_speed =
      mcb_param_est_sensorless_nucl_B.Saturation;

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem22' */
    break;

   case 23:
    /* Outputs for IfAction SubSystem: '<S6>/Switch Case Action Subsystem10' incorporates:
     *  ActionPort: '<S322>/Action Port'
     */
    /* DataTypeConversion: '<S322>/Data Type Conversion' */
    mcb_param_est_sensorless_nucl_B.DataTypeConversion = (uint32_T)
      mcb_param_est_sensorless_nucl_B.In1[0];

    /* S-Function (sfix_bitop): '<S347>/Bitwise AND1' incorporates:
     *  Constant: '<S347>/Constant1'
     */
    mcb_param_est_sensorless_nucl_B.BitwiseAND1 =
      mcb_param_est_sensorless_nucl_B.DataTypeConversion & 65280U;

    /* ArithShift: '<S347>/Shift Arithmetic' incorporates:
     *  S-Function (sfix_bitop): '<S347>/Bitwise AND1'
     */
    mcb_param_est_sensorless_nucl_B.ShiftArithmetic =
      mcb_param_est_sensorless_nucl_B.BitwiseAND1 >> 8;

    /* DataTypeConversion: '<S347>/Data Type Conversion1' */
    mcb_param_est_sensorless_nucl_B.DataTypeConversion1 = (real32_T)
      mcb_param_est_sensorless_nucl_B.ShiftArithmetic;

    /* DataStoreWrite: '<S322>/Data Store Write1' */
    mcb_param_est_sensorless__DWork.selSig1 =
      mcb_param_est_sensorless_nucl_B.DataTypeConversion1;

    /* S-Function (sfix_bitop): '<S347>/Bitwise AND2' incorporates:
     *  Constant: '<S347>/Constant2'
     */
    mcb_param_est_sensorless_nucl_B.BitwiseAND2 =
      mcb_param_est_sensorless_nucl_B.DataTypeConversion & 254U;

    /* ArithShift: '<S347>/Shift Arithmetic1' incorporates:
     *  S-Function (sfix_bitop): '<S347>/Bitwise AND2'
     */
    mcb_param_est_sensorless_nucl_B.ShiftArithmetic1 =
      mcb_param_est_sensorless_nucl_B.BitwiseAND2 >> 1;

    /* DataTypeConversion: '<S347>/Data Type Conversion2' */
    mcb_param_est_sensorless_nucl_B.DataTypeConversion2_n = (real32_T)
      mcb_param_est_sensorless_nucl_B.ShiftArithmetic1;

    /* DataStoreWrite: '<S322>/Data Store Write2' */
    mcb_param_est_sensorless__DWork.selSig2 =
      mcb_param_est_sensorless_nucl_B.DataTypeConversion2_n;

    /* S-Function (sfix_bitop): '<S347>/Bitwise AND' incorporates:
     *  Constant: '<S347>/Constant3'
     */
    mcb_param_est_sensorless_nucl_B.BitwiseAND =
      mcb_param_est_sensorless_nucl_B.DataTypeConversion & 1U;

    /* UnitDelay: '<S347>/Unit Delay' */
    mcb_param_est_sensorless_nucl_B.UnitDelay =
      mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_n;

    /* RelationalOperator: '<S347>/Relational Operator' */
    mcb_param_est_sensorless_nucl_B.RelationalOperator =
      (mcb_param_est_sensorless_nucl_B.UnitDelay !=
       mcb_param_est_sensorless_nucl_B.BitwiseAND);

    /* Switch: '<S347>/Switch' */
    if (mcb_param_est_sensorless_nucl_B.RelationalOperator) {
      /* Switch: '<S347>/Switch' */
      mcb_param_est_sensorless_nucl_B.Switch = (real32_T)
        mcb_param_est_sensorless_nucl_B.BitwiseAND;
    } else {
      /* DataStoreRead: '<S347>/Data Store Read' */
      mcb_param_est_sensorless_nucl_B.DataStoreRead =
        mcb_param_est_sensorless__DWork.testEnableFromHost;

      /* Switch: '<S347>/Switch' */
      mcb_param_est_sensorless_nucl_B.Switch =
        mcb_param_est_sensorless_nucl_B.DataStoreRead;
    }

    /* End of Switch: '<S347>/Switch' */

    /* DataStoreWrite: '<S322>/Data Store Write3' */
    mcb_param_est_sensorless__DWork.testEnableFromHost =
      mcb_param_est_sensorless_nucl_B.Switch;

    /* Update for UnitDelay: '<S347>/Unit Delay' */
    mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_n =
      mcb_param_est_sensorless_nucl_B.BitwiseAND;

    /* End of Outputs for SubSystem: '<S6>/Switch Case Action Subsystem10' */
    break;

   default:
    /* no actions */
    break;
  }

  /* End of SwitchCase: '<S6>/Switch Case' */
}

/* Model step function for TID2 */
void mcb_param_est_sensorless_nucleo_g474re_ihm07m1_step2(void) /* Sample time: [0.5s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  int32_T c;

  /* UnitDelay: '<S4>/Unit Delay' */
  mcb_param_est_sensorless_nucl_B.UnitDelay_m =
    mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_h;

  /* MATLABSystem: '<S316>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (mcb_param_est_sensorless_nucl_B.UnitDelay_m) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S316>/Digital Port Write' */

  /* Logic: '<S4>/NOT' */
  mcb_param_est_sensorless_nucl_B.NOT =
    !mcb_param_est_sensorless_nucl_B.UnitDelay_m;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_h =
    mcb_param_est_sensorless_nucl_B.NOT;
}

/* Model initialize function */
void mcb_param_est_sensorless_nucleo_g474re_ihm07m1_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)mcb_param_est_sensorless_nuc_M, 0,
                sizeof(RT_MODEL_mcb_param_est_sensorle));

  /* block I/O */
  (void) memset(((void *) &mcb_param_est_sensorless_nucl_B), 0,
                sizeof(BlockIO_mcb_param_est_sensorles));

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[i] = 0.0F;
    }

    for (i = 0; i < 10; i++) {
      mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[i] = 0.0F;
    }

    mcb_param_est_sensorless_nucl_B.DataTypeConversion1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion2_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation_fo = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation_d = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation_i = 0.0F;
    mcb_param_est_sensorless_nucl_B.UARTUSARTRead_o1[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UARTUSARTRead_o1[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.In1[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.In1[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay3 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion4[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion4[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion4[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion4[3] = 0.0F;
    mcb_param_est_sensorless_nucl_B.count_to_PU[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.count_to_PU[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.count_to_PU[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.count_to_PU[3] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Vab = 0.0F;
    mcb_param_est_sensorless_nucl_B.Vca = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum3 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Va = 0.0F;
    mcb_param_est_sensorless_nucl_B.Vbc = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum4 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Vb = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay3_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay4 = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay9 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_h[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_h[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_e[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_e[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum6[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum6[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_e[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_e[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_c[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_c[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_o[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_o[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_b[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_b[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1_i[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1_i[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum6_p[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum6_p[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_i = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain = 0.0F;
    mcb_param_est_sensorless_nucl_B.Scaling = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum3_i = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.Delay_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead3 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.Scaling1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_m = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_ej[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_ej[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_io = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1_io = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum6_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum3_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_d = 0.0F;
    mcb_param_est_sensorless_nucl_B.Delay_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_im = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum1_o = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_b[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_b[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_oq = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1_c = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum6_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_d = 0.0F;
    mcb_param_est_sensorless_nucl_B.Merge_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.indexing = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup[3] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum3_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion1_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum4_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum5 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_e = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum6_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_o = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead1_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion4_f[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion4_f[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.count_to_PU1[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.count_to_PU1[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay2_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_g[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_g[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_o = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_nf = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_em = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_e = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_m = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay1_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_c[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_c[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.MultiportSwitch[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.MultiportSwitch[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_oc = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead1_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_ct = 0.0F;
    mcb_param_est_sensorless_nucl_B.Divide = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_g0 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_c[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_c[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Divide_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead1_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead2_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead3_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead4 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead5 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead6 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead7 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead8 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead9 = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead2_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay8 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.curTime = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_ad = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead3_e = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead4_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead5_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead8_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead7_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead1_km = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead6_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead9_e = 0.0F;
    mcb_param_est_sensorless_nucl_B.inverter_V_max = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead10 = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay4_m = 0.0F;
    mcb_param_est_sensorless_nucl_B.PWM_Enable = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_o[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_o[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_o[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_e = 0.0F;
    mcb_param_est_sensorless_nucl_B.Vq = 0.0F;
    mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtBytePackIn[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtBytePackIn[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.estimatedParameter = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_lx = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead1_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Abs = 0.0F;
    mcb_param_est_sensorless_nucl_B.Abs1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_ms = 0.0F;
    mcb_param_est_sensorless_nucl_B.derating = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Merge_c = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum2_d = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_pz = 0.0F;
    mcb_param_est_sensorless_nucl_B.Divide_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_by = 0.0F;
    mcb_param_est_sensorless_nucl_B.Divide1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.testNumOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.injFreqOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.refSignalOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.refSignalOut1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.estimatedParameterOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.testEnableOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.estParIdxOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.Kp_iOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.Ki_iOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.PhaseDiff = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add_k[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add_k[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add_k[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.PWM_Counter_Period[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.PWM_Counter_Period[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.PWM_Counter_Period[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.sqrt3_by_two = 0.0F;
    mcb_param_est_sensorless_nucl_B.one_by_two = 0.0F;
    mcb_param_est_sensorless_nucl_B.add_c = 0.0F;
    mcb_param_est_sensorless_nucl_B.add_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Min = 0.0F;
    mcb_param_est_sensorless_nucl_B.Max = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.one_by_two_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add3 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_a[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_a[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_a[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_ll = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Merge_c5 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.Merge_i = 0.0F;
    mcb_param_est_sensorless_nucl_B.IndexVector_b[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.IndexVector_b[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.OutportBufferForRefVq = 0.0F;
    mcb_param_est_sensorless_nucl_B.indexing_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion1_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum2_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_j[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_j[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_j[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_j[3] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum3_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum4_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.indexing_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion1_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum2_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_g[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_g[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_g[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_g[3] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum3_d = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_cm = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum4_hf = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_oe = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead_ga = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead4_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_i = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_o = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add_ge = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum1_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Add1_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead1_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.PProdOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.Integrator = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.PProdOut_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.Integrator_i = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_c = 0.0F;
    mcb_param_est_sensorless_nucl_B.Saturation_jy = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_lw = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_lr = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum1_e = 0.0F;
    mcb_param_est_sensorless_nucl_B.Merge_b[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Merge_b[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead2_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.DeadZone = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_oa = 0.0F;
    mcb_param_est_sensorless_nucl_B.IProdOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_i = 0.0F;
    mcb_param_est_sensorless_nucl_B.DeadZone_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.IProdOut_c = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_o = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_l5[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_l5[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.SquareRoot = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_b[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_b[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_cx = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product2_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.Merge_d = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_d3 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.Switch1_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sqrt = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_c = 0.0F;
    mcb_param_est_sensorless_nucl_B.Eps = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead4_n = 0.0F;
    mcb_param_est_sensorless_nucl_B.rpm2freq01xspeed_rated = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead2_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_fr = 0.0F;
    mcb_param_est_sensorless_nucl_B.Frequency = 0.0F;
    mcb_param_est_sensorless_nucl_B.Vbyf = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead3_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataStoreRead4_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product2_k = 0.0F;
    mcb_param_est_sensorless_nucl_B.Divide_o = 0.0F;
    mcb_param_est_sensorless_nucl_B.Correction_Factor_sinePWM = 0.0F;
    mcb_param_est_sensorless_nucl_B.Amplitude = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnaryMinus = 0.0F;
    mcb_param_est_sensorless_nucl_B.position_increment = 0.0F;
    mcb_param_est_sensorless_nucl_B.scaleIn = 0.0F;
    mcb_param_est_sensorless_nucl_B.UnitDelay_gn = 0.0F;
    mcb_param_est_sensorless_nucl_B.scaleOut = 0.0F;
    mcb_param_est_sensorless_nucl_B.Eps_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.convert_pu = 0.0F;
    mcb_param_est_sensorless_nucl_B.Merge_h = 0.0F;
    mcb_param_est_sensorless_nucl_B.indexing_kt = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_p[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_p[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_p[2] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Lookup_p[3] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum3_bh = 0.0F;
    mcb_param_est_sensorless_nucl_B.DataTypeConversion1_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum2_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product_cg = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum4_p = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum5_l = 0.0F;
    mcb_param_est_sensorless_nucl_B.Product1_kj = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum6_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.Ka = 0.0F;
    mcb_param_est_sensorless_nucl_B.one_by_two_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.sqrt3_by_two_e = 0.0F;
    mcb_param_est_sensorless_nucl_B.add_b_d = 0.0F;
    mcb_param_est_sensorless_nucl_B.Kb = 0.0F;
    mcb_param_est_sensorless_nucl_B.add_c_f = 0.0F;
    mcb_param_est_sensorless_nucl_B.Kc = 0.0F;
    mcb_param_est_sensorless_nucl_B.Kalpha = 0.0F;
    mcb_param_est_sensorless_nucl_B.Kbeta = 0.0F;
    mcb_param_est_sensorless_nucl_B.Divide_j = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sample_Time = 0.0F;
    mcb_param_est_sensorless_nucl_B.Sum_kc = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_o[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.Gain_o[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.IfActionSubsystem1.Convert_back = 0.0F;
    mcb_param_est_sensorless_nucl_B.IfActionSubsystem.Convert_back = 0.0F;
    mcb_param_est_sensorless_nucl_B.IfActionSubsystem1_a.Convert_back = 0.0F;
    mcb_param_est_sensorless_nucl_B.IfActionSubsystem_h.Convert_back = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate_k.Add = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate_k.DataTypeConversion1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate_k.Add1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate_k.Input = 0.0F;
    mcb_param_est_sensorless_nucl_B.IfActionSubsystem1_b.Convert_back = 0.0F;
    mcb_param_est_sensorless_nucl_B.IfActionSubsystem_d.Convert_back = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate_f.Add = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate_f.DataTypeConversion1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate_f.Add1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate_f.Input = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate.Add = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate.DataTypeConversion1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate.Add1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.Accumulate.Input = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_o.a_plus_2b = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_o.one_by_sqrt3 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_o.algDD_o1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_o.algDD_o2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.IfActionSubsystem1_g.Convert_back = 0.0F;
    mcb_param_est_sensorless_nucl_B.IfActionSubsystem_b.Convert_back = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.qcos = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.dsin = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.sum_beta = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.dcos = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.qsin = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.sum_alpha = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.Switch[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.Switch[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.algDD_o1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.algDD_o2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.qcos = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.dsin = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.sum_beta = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.dcos = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.qsin = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.sum_alpha = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.Switch[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.Switch[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.acos_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.bsin = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.sum_Ds = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.bcos = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.asin_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.sum_Qs = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.Switch[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.Switch[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k.a_plus_2b = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k.one_by_sqrt3 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k.algDD_o1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k.algDD_o2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.acos_b = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.bsin = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.sum_Ds = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.bcos = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.asin_a = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.sum_Qs = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.Switch[0] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.Switch[1] = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.algDD_o1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwoinputsCRL.algDD_o2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap.a_plus_2b = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap.one_by_sqrt3 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap.algDD_o1 = 0.0F;
    mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap.algDD_o2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_e.Atan2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_e.Switch = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_e.algDD = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_e.Gain = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_e.Switch_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_e.Bias = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_n.Atan2 = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_n.Switch = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_n.algDD = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_n.Gain = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_n.Switch_g = 0.0F;
    mcb_param_est_sensorless_nucl_B.atan2_n.Bias = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_param_est_sensorless__DWork, 0,
                sizeof(D_Work_mcb_param_est_sensorless));
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay3_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay3_DSTATE_i = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay4_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay9_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_a[0] = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_a[1] = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay1_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay2_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_d[0] = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_d[1] = 0.0F;
  mcb_param_est_sensorless__DWork.Delay_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_m = 0.0F;
  mcb_param_est_sensorless__DWork.Delay_DSTATE_h = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_b = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay2_DSTATE_m = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_i = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_f = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay1_DSTATE_m = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_c = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay8_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay4_DSTATE_n = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_e = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_o = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_j = 0.0F;
  mcb_param_est_sensorless__DWork.Integrator_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.Integrator_DSTATE_c = 0.0F;
  mcb_param_est_sensorless__DWork.RampGenerator_DSTATE = 0.0F;
  mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_ba = 0.0F;
  mcb_param_est_sensorless__DWork.V_rated = 0.0F;
  mcb_param_est_sensorless__DWork.speed_rated = 0.0F;
  mcb_param_est_sensorless__DWork.pole_pairs = 0.0F;
  mcb_param_est_sensorless__DWork.RsMeasTestTime = 0.0F;
  mcb_param_est_sensorless__DWork.selSig2 = 0.0F;
  mcb_param_est_sensorless__DWork.selSig1 = 0.0F;
  mcb_param_est_sensorless__DWork.sigma = 0.0F;
  mcb_param_est_sensorless__DWork.R_board = 0.0F;
  mcb_param_est_sensorless__DWork.inverter_V_max = 0.0F;
  mcb_param_est_sensorless__DWork.Vd_ref_OL = 0.0F;
  mcb_param_est_sensorless__DWork.freq_low = 0.0F;
  mcb_param_est_sensorless__DWork.freq_high = 0.0F;
  mcb_param_est_sensorless__DWork.freq_step = 0.0F;
  mcb_param_est_sensorless__DWork.Vd_dc = 0.0F;
  mcb_param_est_sensorless__DWork.Vdq_amp = 0.0F;
  mcb_param_est_sensorless__DWork.Iq_ref_CL = 0.0F;
  mcb_param_est_sensorless__DWork.under_voltage_limit = 0.0F;
  mcb_param_est_sensorless__DWork.over_current_limit = 0.0F;
  mcb_param_est_sensorless__DWork.inertia_end_speed = 0.0F;
  mcb_param_est_sensorless__DWork.testEnableFromHost = 0.0F;
  mcb_param_est_sensorless__DWork.currentPU_RWV = 0.0F;
  mcb_param_est_sensorless__DWork.I_rated = 0.0F;
  mcb_param_est_sensorless__DWork.Rs = 0.0F;
  mcb_param_est_sensorless__DWork.Ld = 0.0F;
  mcb_param_est_sensorless__DWork.Lq = 0.0F;
  mcb_param_est_sensorless__DWork.Bemf = 0.0F;
  mcb_param_est_sensorless__DWork.J = 0.0F;
  mcb_param_est_sensorless__DWork.B = 0.0F;
  mcb_param_est_sensorless__DWork.Kp_i = 0.0F;
  mcb_param_est_sensorless__DWork.Ki_i = 0.0F;
  mcb_param_est_sensorless__DWork.errorID = 0.0F;
  mcb_param_est_sensorless__DWork.PhaseDiffValid = 0.0F;
  mcb_param_est_sensorless__DWork.Ia_avg_cal = 0.0F;
  mcb_param_est_sensorless__DWork.Ib_avg_cal = 0.0F;
  mcb_param_est_sensorless__DWork.flag = 0.0F;
  mcb_param_est_sensorless__DWork.errorID_m = 0.0F;
  mcb_param_est_sensorless__DWork.estParIdx = 0.0F;
  mcb_param_est_sensorless__DWork.phaseDiffRad = 0.0F;
  mcb_param_est_sensorless__DWork.PhaseDiffValidityLd = 0.0F;
  mcb_param_est_sensorless__DWork.PhaseDiffValidityLq = 0.0F;
  mcb_param_est_sensorless__DWork.flagNextVal = 0.0F;
  mcb_param_est_sensorless__DWork.delay = 0.0F;
  mcb_param_est_sensorless__DWork.estimatedParameter = 0.0F;
  mcb_param_est_sensorless__DWork.voltagePU_RWV = 0.0F;
  mcb_param_est_sensorless__DWork.Kp_i_d = 0.0F;
  mcb_param_est_sensorless__DWork.Ki_i_d = 0.0F;
  mcb_param_est_sensorless__DWork.PhaseDiffVal = 0.0F;
  mcb_param_est_sensorless__DWork.testNum = 0.0F;
  mcb_param_est_sensorless__DWork.testEnable = 0.0F;
  mcb_param_est_sensorless__DWork.injFreq = 0.0F;
  mcb_param_est_sensorless__DWork.lambda = 0.0F;
  mcb_param_est_sensorless__DWork.speed_radPerSec = 0.0F;
  mcb_param_est_sensorless__DWork.estL = 0.0F;
  mcb_param_est_sensorless__DWork.numWaves = 0.0F;
  mcb_param_est_sensorless__DWork.refSignal = 0.0F;
  mcb_param_est_sensorless__DWork.refSignal1 = 0.0F;
  mcb_param_est_sensorless__DWork.savedTimeInstance = 0.0F;
  mcb_param_est_sensorless__DWork.timeInstance1 = 0.0F;
  mcb_param_est_sensorless__DWork.samplesPerHalfCycle = 0.0F;
  mcb_param_est_sensorless__DWork.sinIdx = 0.0F;
  mcb_param_est_sensorless__DWork.count1 = 0.0F;
  mcb_param_est_sensorless__DWork.count2 = 0.0F;
  mcb_param_est_sensorless__DWork.count3 = 0.0F;

  {
    int32_T i;
    for (i = 0; i < 1000; i++) {
      mcb_param_est_sensorless__DWork.arraySine[i] = 0.0F;
    }
  }

  mcb_param_est_sensorless__DWork.max = 0.0F;
  mcb_param_est_sensorless__DWork.min = 0.0F;
  mcb_param_est_sensorless__DWork.Sig1 = 0.0F;
  mcb_param_est_sensorless__DWork.Sig2 = 0.0F;
  mcb_param_est_sensorless__DWork.Sig1Prev = 0.0F;
  mcb_param_est_sensorless__DWork.Sig2Prev = 0.0F;
  mcb_param_est_sensorless__DWork.Sig1Mean = 0.0F;
  mcb_param_est_sensorless__DWork.Sig2Mean = 0.0F;
  mcb_param_est_sensorless__DWork.Sig3Mean = 0.0F;
  mcb_param_est_sensorless__DWork.Sig4Mean = 0.0F;
  mcb_param_est_sensorless__DWork.Sig5Mean = 0.0F;

  {
    TIM_Type_T b;
    uint32_T freq;
    boolean_T isSlaveModeTriggerEnabled;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
    mcb_param_est_sensorless__DWork.V_rated = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory11' */
    mcb_param_est_sensorless__DWork.speed_rated = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory12' */
    mcb_param_est_sensorless__DWork.pole_pairs = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
    mcb_param_est_sensorless__DWork.RsMeasTestTime = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory14' */
    mcb_param_est_sensorless__DWork.selSig2 = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory15' */
    mcb_param_est_sensorless__DWork.selSig1 = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory18' */
    mcb_param_est_sensorless__DWork.sigma = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory20' */
    mcb_param_est_sensorless__DWork.R_board = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory28' */
    mcb_param_est_sensorless__DWork.inverter_V_max = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory31' */
    mcb_param_est_sensorless__DWork.Vd_ref_OL = 0.1F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory32' */
    mcb_param_est_sensorless__DWork.freq_low = 400.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory33' */
    mcb_param_est_sensorless__DWork.freq_high = 1000.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory34' */
    mcb_param_est_sensorless__DWork.freq_step = 10.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory35' */
    mcb_param_est_sensorless__DWork.Vd_dc = 0.1F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory36' */
    mcb_param_est_sensorless__DWork.Vdq_amp = 0.05F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory37' */
    mcb_param_est_sensorless__DWork.Iq_ref_CL = 0.2F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory38' */
    mcb_param_est_sensorless__DWork.under_voltage_limit = 0.8F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory39' */
    mcb_param_est_sensorless__DWork.over_current_limit = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory41' */
    mcb_param_est_sensorless__DWork.inertia_end_speed = 0.25F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
    mcb_param_est_sensorless__DWork.testEnableFromHost = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
    mcb_param_est_sensorless__DWork.currentPU_RWV = 0.1F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
    mcb_param_est_sensorless__DWork.I_rated = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    mcb_param_est_sensorless__DWork.Rs = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory16' */
    mcb_param_est_sensorless__DWork.Ld = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory17' */
    mcb_param_est_sensorless__DWork.Lq = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory19' */
    mcb_param_est_sensorless__DWork.Bemf = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory21' */
    mcb_param_est_sensorless__DWork.J = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory22' */
    mcb_param_est_sensorless__DWork.B = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory30' */
    mcb_param_est_sensorless__DWork.disableOL = true;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    mcb_param_est_sensorless__DWork.Ia_avg_cal = 1.0F;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    mcb_param_est_sensorless__DWork.Ib_avg_cal = 1.0F;
    mcb_param_est_se_PrevZCSigState.TriggeredSubsystem_Trig_ZCE =
      UNINITIALIZED_ZCSIG;
    mcb_param_est_se_PrevZCSigState.SaveToMemory_Trig_ZCE = UNINITIALIZED_ZCSIG;
    mcb_param_est_se_PrevZCSigState.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    mcb_param_est_se_PrevZCSigState.Delay_Reset_ZCE_l = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */
    /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

    /* Start for MATLABSystem: '<S311>/Analog to Digital Converter' */
    mcb_param_est_sensorless__DWork.obj_h.isInitialized = 0;
    mcb_param_est_sensorless__DWork.obj_h.matlabCodegenIsDeleted = false;
    mcb_param_est_sensorless__DWork.objisempty_m0 = true;
    mcb_param_est__SystemCore_setup(&mcb_param_est_sensorless__DWork.obj_h);

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Alogrithm'
     */
    /* System initialize for function-call system: '<Root>/Alogrithm' */
    {
      int32_T i;

      /* InitializeConditions for UnitDelay: '<S13>/Unit Delay9' */
      mcb_param_est_sensorless__DWork.UnitDelay9_DSTATE = 1.0F;

      /* InitializeConditions for Delay: '<S37>/Delay' */
      mcb_param_est_sensorless__DWork.Delay_DSTATE = 0.0F;

      /* InitializeConditions for Delay: '<S36>/Delay' */
      mcb_param_est_sensorless__DWork.Delay_DSTATE_h = 0.0F;

      /* InitializeConditions for Delay: '<S50>/Delay' */
      mcb_param_est_sensorless__DWork.CircBufIdx = 0U;

      /* InitializeConditions for UnitDelay: '<S301>/Unit Delay' */
      mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_oq = true;

      /* SystemInitialize for Enabled SubSystem: '<S60>/Control' */
      /* InitializeConditions for DiscreteIntegrator: '<S210>/Integrator' */
      mcb_param_est_sensorless__DWork.Integrator_PrevResetState = 0;
      mcb_param_est_sensorless__DWork.Integrator_IC_LOADING = 1U;

      /* InitializeConditions for DiscreteIntegrator: '<S158>/Integrator' */
      mcb_param_est_sensorless__DWork.Integrator_PrevResetState_k = 0;
      mcb_param_est_sensorless__DWork.Integrator_IC_LOADING_g = 1U;

      /* SystemInitialize for Merge: '<S106>/Merge' */
      mcb_param_est_sensorless_nucl_B.Merge_b[0] = 0.0F;
      mcb_param_est_sensorless_nucl_B.Merge_b[1] = 0.0F;

      /* End of SystemInitialize for SubSystem: '<S60>/Control' */

      /* SystemInitialize for MATLAB Function: '<S13>/MATLAB Function' */
      mcb_param_est_sensorless__DWork.voltagePU_RWV_not_empty = false;
      mcb_param_est_sensorless__DWork.flag = 0.0F;
      mcb_param_est_sensorless__DWork.errorID_m = 0.0F;
      mcb_param_est_sensorless__DWork.estParIdx = 20.0F;
      mcb_param_est_sensorless__DWork.phaseDiffRad = 0.0F;
      mcb_param_est_sensorless__DWork.PhaseDiffValidityLd = 1.0F;
      mcb_param_est_sensorless__DWork.PhaseDiffValidityLq = 1.0F;
      mcb_param_est_sensorless__DWork.flagNextVal = 1.0F;
      mcb_param_est_sensorless__DWork.delay = 1.0F;
      mcb_param_est_sensorless__DWork.estimatedParameter = 0.0F;
      mcb_param_est_sensorless__DWork.Kp_i_d = 0.0F;
      mcb_param_est_sensorless__DWork.Ki_i_d = 0.0F;
      mcb_param_est_sensorless__DWork.PhaseDiffVal = 0.0F;
      mcb_param_est_sensorless__DWork.testNum = 0.0F;
      mcb_param_est_sensorless__DWork.testEnable = 1.0F;
      mcb_param_est_sensorless__DWork.injFreq = 0.0F;
      mcb_param_est_sensorless__DWork.lambda = 0.0F;
      mcb_param_est_sensorless__DWork.speed_radPerSec = 0.0F;
      mcb_param_est_sensorless__DWork.estL = 0.0F;
      mcb_param_est_sensorless__DWork.numWaves = 0.0F;
      mcb_param_est_sensorless__DWork.refSignal = 0.0F;
      mcb_param_est_sensorless__DWork.refSignal1 = 0.0F;
      mcb_param_est_sensorless__DWork.savedTimeInstance = 0.0F;
      mcb_param_est_sensorless__DWork.timeInstance1 = 0.0F;
      mcb_param_est_sensorless__DWork.samplesPerHalfCycle = 0.0F;
      mcb_param_est_sensorless__DWork.sinIdx = 1.0F;
      mcb_param_est_sensorless__DWork.count1 = 0.0F;
      mcb_param_est_sensorless__DWork.count2 = 0.0F;
      mcb_param_est_sensorless__DWork.count3 = 0.0F;
      for (i = 0; i < 1000; i++) {
        mcb_param_est_sensorless__DWork.arraySine[i] = 0.0F;
      }

      mcb_param_est_sensorless__DWork.max = 0.0F;
      mcb_param_est_sensorless__DWork.min = 0.0F;
      mcb_param_est_sensorless__DWork.Sig1 = 0.0F;
      mcb_param_est_sensorless__DWork.Sig2 = 0.0F;
      mcb_param_est_sensorless__DWork.Sig1Prev = 0.0F;
      mcb_param_est_sensorless__DWork.Sig2Prev = 0.0F;
      mcb_param_est_sensorless__DWork.Sig1Mean = 0.0F;
      mcb_param_est_sensorless__DWork.Sig2Mean = 0.0F;
      mcb_param_est_sensorless__DWork.Sig3Mean = 0.0F;
      mcb_param_est_sensorless__DWork.Sig4Mean = 0.0F;
      mcb_param_est_sensorless__DWork.Sig5Mean = 0.0F;

      /* End of SystemInitialize for MATLAB Function: '<S13>/MATLAB Function' */

      /* SystemInitialize for Iterator SubSystem: '<S300>/While Iterator Subsystem' */
      /* Start for MATLABSystem: '<S306>/UART//USART Write' */
      mcb_param_est_sensorless__DWork.obj_o.matlabCodegenIsDeleted = false;
      mcb_param_est_sensorless__DWork.objisempty_a = true;
      mcb_param_est_sensorless__DWork.obj_o.isSetupComplete = false;
      mcb_param_est_sensorless__DWork.obj_o.isInitialized = 1;
      mcb_param_e_UARTWrite_setupImpl(&mcb_param_est_sensorless__DWork.obj_o);
      mcb_param_est_sensorless__DWork.obj_o.isSetupComplete = true;

      /* End of SystemInitialize for SubSystem: '<S300>/While Iterator Subsystem' */

      /* SystemInitialize for Triggered SubSystem: '<S15>/SaveToMemory' */
      /* SystemInitialize for SignalConversion generated from: '<S287>/estParIdx' incorporates:
       *  Outport: '<S287>/Idx'
       */
      mcb_param_est_sensorless_nucl_B.estParIdx = 20U;

      /* End of SystemInitialize for SubSystem: '<S15>/SaveToMemory' */

      /* Start for MATLABSystem: '<S271>/Analog to Digital Converter' */
      mcb_param_est_sensorless__DWork.obj.isInitialized = 0;
      mcb_param_est_sensorless__DWork.obj.matlabCodegenIsDeleted = false;
      mcb_param_est_sensorless__DWork.objisempty_e = true;
      mcb_param_es_SystemCore_setup_h(&mcb_param_est_sensorless__DWork.obj);

      /* Start for MATLABSystem: '<S265>/Digital Port Write' */
      mcb_param_est_sensorless__DWork.objisempty_m = true;
      mcb_param_est_sensorless__DWork.obj_g.isInitialized = 1;

      /* Start for MATLABSystem: '<S275>/PWM Output' */
      mcb_param_est_sensorless__DWork.obj_f.matlabCodegenIsDeleted = false;
      mcb_param_est_sensorless__DWork.objisempty_h = true;
      mcb_param_est_sensorless__DWork.obj_f.isSetupComplete = false;
      mcb_param_est_sensorless__DWork.obj_f.isInitialized = 1;
      mcb_param_e_PWMOutput_setupImpl(&mcb_param_est_sensorless__DWork.obj_f);
      mcb_param_est_sensorless__DWork.obj_f.isSetupComplete = true;
    }

    /* SystemInitialize for Atomic SubSystem: '<Root>/Initialize Function' */
    /* Start for MATLABSystem: '<S319>/PWM Output' */
    mcb_param_est_sensorless__DWork.obj_a.matlabCodegenIsDeleted = false;
    mcb_param_est_sensorless__DWork.objisempty_o = true;
    mcb_param_est_sensorless__DWork.obj_a.isInitialized = 1;
    b.PeripheralPtr = TIM1;
    b.isCenterAlignedMode = false;
    b.repetitionCounter = 0U;
    mcb_param_est_sensorless__DWork.obj_a.TimerHandle = Timer_Handle_Init(&b);
    enableTimerInterrupts(mcb_param_est_sensorless__DWork.obj_a.TimerHandle, 0);
    isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled
      (mcb_param_est_sensorless__DWork.obj_a.TimerHandle);
    if (!isSlaveModeTriggerEnabled) {
      enableCounter(mcb_param_est_sensorless__DWork.obj_a.TimerHandle, true);
    }

    mcb_param_est_sensorless__DWork.obj_a.isSetupComplete = true;

    /* End of SystemInitialize for SubSystem: '<Root>/Initialize Function' */

    /* Start for MATLABSystem: '<S320>/UART//USART Read' */
    mcb_param_est_sensorless__DWork.obj_e.isInitialized = 0;
    mcb_param_est_sensorless__DWork.obj_e.matlabCodegenIsDeleted = false;
    mcb_param_est_sensorless__DWork.objisempty = true;
    mcb_param_es_SystemCore_setup_g(&mcb_param_est_sensorless__DWork.obj_e);

    /* Start for MATLABSystem: '<S316>/Digital Port Write' */
    mcb_param_est_sensorless__DWork.objisempty_c = true;
    mcb_param_est_sensorless__DWork.obj_k.isInitialized = 1;

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* MATLABSystem: '<S319>/PWM Output' incorporates:
     *  Constant: '<S5>/Constant'
     */
    freq = checkFrequencyAndDutyCycleLimits
      (mcb_param_est_sensorless__DWork.obj_a.TimerHandle, 8500U);
    setFrequencyAccToInput(mcb_param_est_sensorless__DWork.obj_a.TimerHandle,
      freq);

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void mcb_param_est_sensorless_nucleo_g474re_ihm07m1_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S311>/Analog to Digital Converter' */
  if (!mcb_param_est_sensorless__DWork.obj_h.matlabCodegenIsDeleted) {
    mcb_param_est_sensorless__DWork.obj_h.matlabCodegenIsDeleted = true;
    if ((mcb_param_est_sensorless__DWork.obj_h.isInitialized == 1) &&
        mcb_param_est_sensorless__DWork.obj_h.isSetupComplete) {
      ADC_Handle_Deinit(mcb_param_est_sensorless__DWork.obj_h.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S311>/Analog to Digital Converter' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Alogrithm'
   */
  /* Termination for function-call system: '<Root>/Alogrithm' */

  /* Terminate for MATLABSystem: '<S271>/Analog to Digital Converter' */
  if (!mcb_param_est_sensorless__DWork.obj.matlabCodegenIsDeleted) {
    mcb_param_est_sensorless__DWork.obj.matlabCodegenIsDeleted = true;
    if ((mcb_param_est_sensorless__DWork.obj.isInitialized == 1) &&
        mcb_param_est_sensorless__DWork.obj.isSetupComplete) {
      ADC_Handle_Deinit(mcb_param_est_sensorless__DWork.obj.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S271>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S275>/PWM Output' */
  if (!mcb_param_est_sensorless__DWork.obj_f.matlabCodegenIsDeleted) {
    mcb_param_est_sensorless__DWork.obj_f.matlabCodegenIsDeleted = true;
    if ((mcb_param_est_sensorless__DWork.obj_f.isInitialized == 1) &&
        mcb_param_est_sensorless__DWork.obj_f.isSetupComplete) {
      disableCounter(mcb_param_est_sensorless__DWork.obj_f.TimerHandle);
      disableTimerInterrupts(mcb_param_est_sensorless__DWork.obj_f.TimerHandle,
        0);
      disableTimerChannel1(mcb_param_est_sensorless__DWork.obj_f.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel2(mcb_param_est_sensorless__DWork.obj_f.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel3(mcb_param_est_sensorless__DWork.obj_f.TimerHandle,
                           ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S275>/PWM Output' */

  /* Terminate for Iterator SubSystem: '<S300>/While Iterator Subsystem' */
  /* Terminate for MATLABSystem: '<S306>/UART//USART Write' */
  if (!mcb_param_est_sensorless__DWork.obj_o.matlabCodegenIsDeleted) {
    mcb_param_est_sensorless__DWork.obj_o.matlabCodegenIsDeleted = true;
    if ((mcb_param_est_sensorless__DWork.obj_o.isInitialized == 1) &&
        mcb_param_est_sensorless__DWork.obj_o.isSetupComplete) {
      MW_LPUART_DeInit(mcb_param_est_sensorless__DWork.obj_o.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S306>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<S300>/While Iterator Subsystem' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S320>/UART//USART Read' */
  if (!mcb_param_est_sensorless__DWork.obj_e.matlabCodegenIsDeleted) {
    mcb_param_est_sensorless__DWork.obj_e.matlabCodegenIsDeleted = true;
    if ((mcb_param_est_sensorless__DWork.obj_e.isInitialized == 1) &&
        mcb_param_est_sensorless__DWork.obj_e.isSetupComplete) {
      MW_LPUART_DeInit(mcb_param_est_sensorless__DWork.obj_e.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S320>/UART//USART Read' */

  /* Terminate for Atomic SubSystem: '<Root>/Initialize Function' */
  /* Terminate for MATLABSystem: '<S319>/PWM Output' */
  if (!mcb_param_est_sensorless__DWork.obj_a.matlabCodegenIsDeleted) {
    mcb_param_est_sensorless__DWork.obj_a.matlabCodegenIsDeleted = true;
    if ((mcb_param_est_sensorless__DWork.obj_a.isInitialized == 1) &&
        mcb_param_est_sensorless__DWork.obj_a.isSetupComplete) {
      disableCounter(mcb_param_est_sensorless__DWork.obj_a.TimerHandle);
      disableTimerInterrupts(mcb_param_est_sensorless__DWork.obj_a.TimerHandle,
        0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S319>/PWM Output' */
  /* End of Terminate for SubSystem: '<Root>/Initialize Function' */
}

void mcb_param_est_sensorless_nucleo_g474re_ihm07m1_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC1_2_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S313>/Hardware Interrupt' */
void ADC1_2_IRQHandler(void)
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
        /* S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          uint16_T tmp[3];

          /* MATLABSystem: '<S311>/Analog to Digital Converter' */
          injectedReadADCIntr(mcb_param_est_sensorless__DWork.obj_h.ADCHandle,
                              ADC_READ, &tmp[0]);

          /* MATLABSystem: '<S311>/Analog to Digital Converter' */
          mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter_c[0] = tmp[0];
          mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter_c[1] = tmp[1];
          mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter_c[2] = tmp[2];
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' */
      }
    }
  }

  /* Event: ADC2 Inj EoCS */
  /* Check event ADC2 Inj EoCS occurred */
  if (0 != (
#if defined(MW_ADC2_ENABLED) && (defined(MW_ADC2_INJ_IRQ_ENABLED) && (MW_ADC2_INJ_IRQ_ENABLED==1))
            (0 != LL_ADC_IsEnabledIT_JEOS(ADC2)) && (0 != ADC_IsActiveFlagJEOS
        (&(MW_ADC2_VAR)))
#else
            (0 != LL_ADC_IsEnabledIT_JEOS(ADC2)) && (0 !=
        LL_ADC_IsActiveFlag_JEOS(ADC2))
#endif
            )) {
    /* Clear occurred ADC2 Inj EoCS event */
    LL_ADC_ClearFlag_JEOS(ADC2);
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Alogrithm' */
        {
          GPIO_TypeDef * portNameLoc;
          int32_T i;
          real32_T Bias;
          real32_T Product;
          real32_T timeInstance2;
          uint32_T pinWriteLoc;
          uint32_T sentLength;
          int16_T s306_iter;
          uint16_T tmp[3];
          uint16_T DataTypeConversion_a;
          boolean_T zcEvent;
          ZCEventType zcEvent_p;

          /* user code (Output function Body for TID4) */

          /* System '<Root>/Alogrithm' */
          LL_GPIO_SetOutputPin(GPIOC, LL_GPIO_PIN_8);

          /* UnitDelay: '<S13>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_a =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE;

          /* RelationalOperator: '<S80>/Compare' incorporates:
           *  Constant: '<S80>/Constant'
           */
          mcb_param_est_sensorless_nucl_B.Compare_h =
            (mcb_param_est_sensorless_nucl_B.UnitDelay_a >= 4.0F);

          /* Logic: '<S59>/NOT' */
          mcb_param_est_sensorless_nucl_B.NOT_g =
            !mcb_param_est_sensorless_nucl_B.Compare_h;

          /* DataStoreWrite: '<S59>/Data Store Write' */
          mcb_param_est_sensorless__DWork.disableOL =
            mcb_param_est_sensorless_nucl_B.NOT_g;

          /* UnitDelay: '<S59>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_i =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_g;

          /* UnitDelay: '<S13>/Unit Delay3' */
          mcb_param_est_sensorless_nucl_B.UnitDelay3 =
            mcb_param_est_sensorless__DWork.UnitDelay3_DSTATE;

          /* Outputs for Enabled SubSystem: '<S59>/Open Loop Start-Up' incorporates:
           *  EnablePort: '<S81>/Enable1'
           */
          if (mcb_param_est_sensorless_nucl_B.Compare_h) {
            mcb_param_est_sensorless__DWork.OpenLoopStartUp_MODE = true;

            /* Logic: '<S86>/NOT' */
            mcb_param_est_sensorless_nucl_B.NOT_fm =
              !mcb_param_est_sensorless_nucl_B.UnitDelay_i;

            /* DiscreteIntegrator: '<S86>/Ramp Generator' */
            if (mcb_param_est_sensorless_nucl_B.NOT_fm) {
              mcb_param_est_sensorless__DWork.RampGenerator_DSTATE = 0.0F;
            }

            /* DiscreteIntegrator: '<S86>/Ramp Generator' */
            mcb_param_est_sensorless_nucl_B.Eps =
              mcb_param_est_sensorless__DWork.RampGenerator_DSTATE;

            /* RelationalOperator: '<S84>/Compare' incorporates:
             *  Constant: '<S84>/Constant'
             */
            mcb_param_est_sensorless_nucl_B.Compare_i =
              (mcb_param_est_sensorless_nucl_B.Eps >= 0.99F);

            /* Logic: '<S81>/AND' */
            mcb_param_est_sensorless_nucl_B.AND_j =
              (mcb_param_est_sensorless_nucl_B.Compare_i &&
               mcb_param_est_sensorless_nucl_B.UnitDelay_i);

            /* DataStoreWrite: '<S81>/Data Store Write' */
            mcb_param_est_sensorless__DWork.EnClosedLoop =
              mcb_param_est_sensorless_nucl_B.AND_j;

            /* DataStoreRead: '<S81>/Data Store Read4' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead4_n =
              mcb_param_est_sensorless__DWork.speed_rated;

            /* Gain: '<S81>/rpm2freq (0.1xspeed_rated)' */
            mcb_param_est_sensorless_nucl_B.rpm2freq01xspeed_rated =
              0.00166666671F * mcb_param_est_sensorless_nucl_B.DataStoreRead4_n;

            /* DataStoreRead: '<S81>/Data Store Read2' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead2_j =
              mcb_param_est_sensorless__DWork.pole_pairs;

            /* Product: '<S81>/Product1' */
            mcb_param_est_sensorless_nucl_B.Product1_k =
              mcb_param_est_sensorless_nucl_B.rpm2freq01xspeed_rated *
              mcb_param_est_sensorless_nucl_B.DataStoreRead2_j;

            /* Product: '<S81>/Product' */
            mcb_param_est_sensorless_nucl_B.Product_fr =
              mcb_param_est_sensorless_nucl_B.Product1_k *
              mcb_param_est_sensorless_nucl_B.Eps;

            /* Abs: '<S81>/Abs' */
            mcb_param_est_sensorless_nucl_B.Frequency = fabsf
              (mcb_param_est_sensorless_nucl_B.Product_fr);

            /* Gain: '<S87>/V-by-f' */
            mcb_param_est_sensorless_nucl_B.Vbyf = 60.0F *
              mcb_param_est_sensorless_nucl_B.Frequency;

            /* DataStoreRead: '<S87>/Data Store Read3' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead3_b =
              mcb_param_est_sensorless__DWork.pole_pairs;

            /* DataStoreRead: '<S87>/Data Store Read4' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead4_a =
              mcb_param_est_sensorless__DWork.speed_rated;

            /* Product: '<S87>/Product2' */
            mcb_param_est_sensorless_nucl_B.Product2_k =
              mcb_param_est_sensorless_nucl_B.DataStoreRead3_b *
              mcb_param_est_sensorless_nucl_B.DataStoreRead4_a;

            /* Product: '<S87>/Divide' */
            mcb_param_est_sensorless_nucl_B.Divide_o =
              mcb_param_est_sensorless_nucl_B.Vbyf /
              mcb_param_est_sensorless_nucl_B.Product2_k;

            /* Gain: '<S81>/Correction_Factor_sinePWM' */
            mcb_param_est_sensorless_nucl_B.Correction_Factor_sinePWM =
              1.15470052F * mcb_param_est_sensorless_nucl_B.Divide_o;

            /* Saturate: '<S81>/Saturation1' */
            Bias = mcb_param_est_sensorless_nucl_B.Correction_Factor_sinePWM;
            if (Bias > 0.95F) {
              /* Saturate: '<S81>/Saturation1' */
              mcb_param_est_sensorless_nucl_B.Amplitude = 0.95F;
            } else if (Bias < 0.1F) {
              /* Saturate: '<S81>/Saturation1' */
              mcb_param_est_sensorless_nucl_B.Amplitude = 0.1F;
            } else {
              /* Saturate: '<S81>/Saturation1' */
              mcb_param_est_sensorless_nucl_B.Amplitude = Bias;
            }

            /* End of Saturate: '<S81>/Saturation1' */

            /* UnaryMinus: '<S82>/Unary Minus' */
            mcb_param_est_sensorless_nucl_B.UnaryMinus =
              -mcb_param_est_sensorless_nucl_B.Amplitude;

            /* Gain: '<S81>/position_increment' */
            mcb_param_est_sensorless_nucl_B.position_increment = 0.000628318521F
              * mcb_param_est_sensorless_nucl_B.Frequency;

            /* Gain: '<S85>/scaleIn' */
            mcb_param_est_sensorless_nucl_B.scaleIn = 0.159154937F *
              mcb_param_est_sensorless_nucl_B.position_increment;

            /* UnitDelay: '<S85>/Unit Delay' */
            mcb_param_est_sensorless_nucl_B.UnitDelay_gn =
              mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_ba;

            /* Logic: '<S85>/NOT' */
            mcb_param_est_sensorless_nucl_B.NOT_d = true;

            /* Outputs for Enabled SubSystem: '<S85>/Accumulate' */
            mcb_param_est_se_Accumulate(true,
              mcb_param_est_sensorless_nucl_B.scaleIn,
              mcb_param_est_sensorless_nucl_B.UnitDelay_gn,
              &mcb_param_est_sensorless_nucl_B.Accumulate,
              &mcb_param_est_sensorless__DWork.Accumulate);

            /* End of Outputs for SubSystem: '<S85>/Accumulate' */

            /* Gain: '<S85>/scaleOut' */
            mcb_param_est_sensorless_nucl_B.scaleOut = 6.28318548F *
              mcb_param_est_sensorless_nucl_B.Accumulate.Add1;

            /* Switch: '<S81>/Direction' */
            if (mcb_param_est_sensorless_nucl_B.UnitDelay3 > 0.0F) {
              /* Switch: '<S81>/Direction' */
              mcb_param_est_sensorless_nucl_B.Eps_h =
                mcb_param_est_sensorless_nucl_B.scaleOut;
            } else {
              /* Sum: '<S81>/Sum' incorporates:
               *  Constant: '<S81>/ '
               */
              mcb_param_est_sensorless_nucl_B.Sum_kc = 6.28318548F -
                mcb_param_est_sensorless_nucl_B.scaleOut;

              /* Switch: '<S81>/Direction' */
              mcb_param_est_sensorless_nucl_B.Eps_h =
                mcb_param_est_sensorless_nucl_B.Sum_kc;
            }

            /* End of Switch: '<S81>/Direction' */

            /* Gain: '<S95>/convert_pu' */
            mcb_param_est_sensorless_nucl_B.convert_pu = 0.159154937F *
              mcb_param_est_sensorless_nucl_B.Eps_h;

            /* RelationalOperator: '<S96>/Compare' incorporates:
             *  Constant: '<S96>/Constant'
             */
            mcb_param_est_sensorless_nucl_B.Compare_ek =
              (mcb_param_est_sensorless_nucl_B.convert_pu < 0.0F);

            /* DataTypeConversion: '<S95>/Data Type Conversion' */
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_no =
              mcb_param_est_sensorless_nucl_B.Compare_ek;

            /* If: '<S95>/If' */
            if (mcb_param_est_sensorless_nucl_B.DataTypeConversion_no > 0) {
              /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem' incorporates:
               *  ActionPort: '<S97>/Action Port'
               */
              mcb_param_IfActionSubsystem
                (mcb_param_est_sensorless_nucl_B.convert_pu,
                 &mcb_param_est_sensorless_nucl_B.Merge_h,
                 &mcb_param_est_sensorless_nucl_B.IfActionSubsystem_b);

              /* End of Outputs for SubSystem: '<S95>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S98>/Action Port'
               */
              mcb_para_IfActionSubsystem1
                (mcb_param_est_sensorless_nucl_B.convert_pu,
                 &mcb_param_est_sensorless_nucl_B.Merge_h,
                 &mcb_param_est_sensorless_nucl_B.IfActionSubsystem1_g);

              /* End of Outputs for SubSystem: '<S95>/If Action Subsystem1' */
            }

            /* End of If: '<S95>/If' */

            /* Gain: '<S90>/indexing' */
            mcb_param_est_sensorless_nucl_B.indexing_kt = 800.0F *
              mcb_param_est_sensorless_nucl_B.Merge_h;

            /* DataTypeConversion: '<S90>/Get_Integer' */
            mcb_param_est_sensorless_nucl_B.Get_Integer_g = (uint16_T)
              mcb_param_est_sensorless_nucl_B.indexing_kt;

            /* Sum: '<S90>/Sum' incorporates:
             *  Constant: '<S90>/offset'
             */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_g + 1U;
            mcb_param_est_sensorless_nucl_B.Sum_ot[0] = pinWriteLoc;

            /* Selector: '<S90>/Lookup' incorporates:
             *  Constant: '<S90>/sine_table_values'
             */
            mcb_param_est_sensorless_nucl_B.Lookup_p[0] =
              mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

            /* Sum: '<S90>/Sum' */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_g;
            mcb_param_est_sensorless_nucl_B.Sum_ot[1] = pinWriteLoc;

            /* Selector: '<S90>/Lookup' incorporates:
             *  Constant: '<S90>/sine_table_values'
             */
            mcb_param_est_sensorless_nucl_B.Lookup_p[1] =
              mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

            /* Sum: '<S90>/Sum' incorporates:
             *  Constant: '<S90>/offset'
             */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_g + 201U;
            mcb_param_est_sensorless_nucl_B.Sum_ot[2] = pinWriteLoc;

            /* Selector: '<S90>/Lookup' incorporates:
             *  Constant: '<S90>/sine_table_values'
             */
            mcb_param_est_sensorless_nucl_B.Lookup_p[2] =
              mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

            /* Sum: '<S90>/Sum' incorporates:
             *  Constant: '<S90>/offset'
             */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_g + 200U;
            mcb_param_est_sensorless_nucl_B.Sum_ot[3] = pinWriteLoc;

            /* Selector: '<S90>/Lookup' incorporates:
             *  Constant: '<S90>/sine_table_values'
             */
            mcb_param_est_sensorless_nucl_B.Lookup_p[3] =
              mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

            /* Sum: '<S94>/Sum3' */
            mcb_param_est_sensorless_nucl_B.Sum3_bh =
              mcb_param_est_sensorless_nucl_B.Lookup_p[0] -
              mcb_param_est_sensorless_nucl_B.Lookup_p[1];

            /* DataTypeConversion: '<S90>/Data Type Conversion1' */
            mcb_param_est_sensorless_nucl_B.DataTypeConversion1_g =
              mcb_param_est_sensorless_nucl_B.Get_Integer_g;

            /* Sum: '<S90>/Sum2' */
            mcb_param_est_sensorless_nucl_B.Sum2_g =
              mcb_param_est_sensorless_nucl_B.indexing_kt -
              mcb_param_est_sensorless_nucl_B.DataTypeConversion1_g;

            /* Product: '<S94>/Product' */
            mcb_param_est_sensorless_nucl_B.Product_cg =
              mcb_param_est_sensorless_nucl_B.Sum3_bh *
              mcb_param_est_sensorless_nucl_B.Sum2_g;

            /* Sum: '<S94>/Sum4' */
            mcb_param_est_sensorless_nucl_B.Sum4_p =
              mcb_param_est_sensorless_nucl_B.Product_cg +
              mcb_param_est_sensorless_nucl_B.Lookup_p[1];

            /* Sum: '<S94>/Sum5' */
            mcb_param_est_sensorless_nucl_B.Sum5_l =
              mcb_param_est_sensorless_nucl_B.Lookup_p[2] -
              mcb_param_est_sensorless_nucl_B.Lookup_p[3];

            /* Product: '<S94>/Product1' */
            mcb_param_est_sensorless_nucl_B.Product1_kj =
              mcb_param_est_sensorless_nucl_B.Sum5_l *
              mcb_param_est_sensorless_nucl_B.Sum2_g;

            /* Sum: '<S94>/Sum6' */
            mcb_param_est_sensorless_nucl_B.Sum6_b =
              mcb_param_est_sensorless_nucl_B.Product1_kj +
              mcb_param_est_sensorless_nucl_B.Lookup_p[3];

            /* Outputs for Atomic SubSystem: '<S89>/Two inputs CRL' */
            /* Constant: '<S82>/Constant' */
            mcb_param_es_TwoinputsCRL_j(0.0F,
              mcb_param_est_sensorless_nucl_B.UnaryMinus,
              mcb_param_est_sensorless_nucl_B.Sum4_p,
              mcb_param_est_sensorless_nucl_B.Sum6_b,
              &mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou);

            /* End of Outputs for SubSystem: '<S89>/Two inputs CRL' */

            /* Gain: '<S91>/Ka' */
            mcb_param_est_sensorless_nucl_B.Ka =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.algDD_o1;

            /* Gain: '<S91>/one_by_two' */
            mcb_param_est_sensorless_nucl_B.one_by_two_g = 0.5F *
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.algDD_o1;

            /* Gain: '<S91>/sqrt3_by_two' */
            mcb_param_est_sensorless_nucl_B.sqrt3_by_two_e = 0.866025388F *
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_ou.algDD_o2;

            /* Sum: '<S91>/add_b' */
            mcb_param_est_sensorless_nucl_B.add_b_d =
              mcb_param_est_sensorless_nucl_B.sqrt3_by_two_e -
              mcb_param_est_sensorless_nucl_B.one_by_two_g;

            /* Gain: '<S91>/Kb' */
            mcb_param_est_sensorless_nucl_B.Kb =
              mcb_param_est_sensorless_nucl_B.add_b_d;

            /* Sum: '<S91>/add_c' */
            mcb_param_est_sensorless_nucl_B.add_c_f = (0.0F -
              mcb_param_est_sensorless_nucl_B.one_by_two_g) -
              mcb_param_est_sensorless_nucl_B.sqrt3_by_two_e;

            /* Gain: '<S91>/Kc' */
            mcb_param_est_sensorless_nucl_B.Kc =
              mcb_param_est_sensorless_nucl_B.add_c_f;

            /* Outputs for Atomic SubSystem: '<S99>/Two phase CRL wrap' */
            mcb_param_e_TwophaseCRLwrap(mcb_param_est_sensorless_nucl_B.Ka,
              mcb_param_est_sensorless_nucl_B.Kb,
              &mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_o);

            /* End of Outputs for SubSystem: '<S99>/Two phase CRL wrap' */

            /* Gain: '<S99>/Kalpha' */
            mcb_param_est_sensorless_nucl_B.Kalpha =
              mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_o.algDD_o1;

            /* Gain: '<S99>/Kbeta' */
            mcb_param_est_sensorless_nucl_B.Kbeta =
              mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_o.algDD_o2;

            /* Product: '<S86>/Divide' incorporates:
             *  Constant: '<S81>/Ramp_Time (sec)'
             *  Constant: '<S86>/One'
             */
            mcb_param_est_sensorless_nucl_B.Divide_j = 0.333333343F;

            /* Gain: '<S86>/Sample_Time' */
            mcb_param_est_sensorless_nucl_B.Sample_Time = 3.33333337E-5F;

            /* Update for DiscreteIntegrator: '<S86>/Ramp Generator' */
            mcb_param_est_sensorless__DWork.RampGenerator_DSTATE +=
              3.33333337E-5F;
            if (mcb_param_est_sensorless__DWork.RampGenerator_DSTATE > 1.0F) {
              mcb_param_est_sensorless__DWork.RampGenerator_DSTATE = 1.0F;
            } else if (mcb_param_est_sensorless__DWork.RampGenerator_DSTATE <
                       0.0F) {
              mcb_param_est_sensorless__DWork.RampGenerator_DSTATE = 0.0F;
            }

            /* End of Update for DiscreteIntegrator: '<S86>/Ramp Generator' */

            /* Update for UnitDelay: '<S85>/Unit Delay' */
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_ba =
              mcb_param_est_sensorless_nucl_B.Accumulate.Add1;
          } else if (mcb_param_est_sensorless__DWork.OpenLoopStartUp_MODE) {
            /* Disable for DiscreteIntegrator: '<S86>/Ramp Generator' */
            mcb_param_est_sensorless__DWork.RampGenerator_DSTATE =
              mcb_param_est_sensorless_nucl_B.Eps;
            mcb_param_est_sensorless__DWork.OpenLoopStartUp_MODE = false;
          }

          /* End of Outputs for SubSystem: '<S59>/Open Loop Start-Up' */

          /* MATLABSystem: '<S271>/Analog to Digital Converter' */
          injectedReadADCIntr(mcb_param_est_sensorless__DWork.obj.ADCHandle,
                              ADC_READ, &tmp[0]);

          /* MATLABSystem: '<S271>/Analog to Digital Converter' */
          mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter[0] = tmp[0];
          mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter[1] = tmp[1];
          mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter[2] = tmp[2];

          /* DataTypeConversion: '<S20>/Data Type Conversion4' */
          mcb_param_est_sensorless_nucl_B.DataTypeConversion4[0] =
            mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter_c[0];
          mcb_param_est_sensorless_nucl_B.DataTypeConversion4[1] =
            mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter[2];
          mcb_param_est_sensorless_nucl_B.DataTypeConversion4[2] =
            mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter_c[1];
          mcb_param_est_sensorless_nucl_B.DataTypeConversion4[3] =
            mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter_c[2];

          /* Gain: '<S20>/count_to_PU' */
          mcb_param_est_sensorless_nucl_B.count_to_PU[0] = 0.000244140625F *
            mcb_param_est_sensorless_nucl_B.DataTypeConversion4[0];
          mcb_param_est_sensorless_nucl_B.count_to_PU[1] = 0.000244140625F *
            mcb_param_est_sensorless_nucl_B.DataTypeConversion4[1];
          mcb_param_est_sensorless_nucl_B.count_to_PU[2] = 0.000244140625F *
            mcb_param_est_sensorless_nucl_B.DataTypeConversion4[2];
          mcb_param_est_sensorless_nucl_B.count_to_PU[3] = 0.000244140625F *
            mcb_param_est_sensorless_nucl_B.DataTypeConversion4[3];

          /* Sum: '<S66>/Sum' */
          mcb_param_est_sensorless_nucl_B.Vab =
            mcb_param_est_sensorless_nucl_B.count_to_PU[0] -
            mcb_param_est_sensorless_nucl_B.count_to_PU[1];

          /* Sum: '<S66>/Sum2' */
          mcb_param_est_sensorless_nucl_B.Vca =
            mcb_param_est_sensorless_nucl_B.count_to_PU[2] -
            mcb_param_est_sensorless_nucl_B.count_to_PU[0];

          /* Sum: '<S66>/Sum3' */
          mcb_param_est_sensorless_nucl_B.Sum3 =
            mcb_param_est_sensorless_nucl_B.Vab -
            mcb_param_est_sensorless_nucl_B.Vca;

          /* Gain: '<S66>/Gain2' */
          mcb_param_est_sensorless_nucl_B.Va = 0.333333343F *
            mcb_param_est_sensorless_nucl_B.Sum3;

          /* Sum: '<S66>/Sum1' */
          mcb_param_est_sensorless_nucl_B.Vbc =
            mcb_param_est_sensorless_nucl_B.count_to_PU[1] -
            mcb_param_est_sensorless_nucl_B.count_to_PU[2];

          /* Sum: '<S66>/Sum4' */
          mcb_param_est_sensorless_nucl_B.Sum4 =
            mcb_param_est_sensorless_nucl_B.Vbc -
            mcb_param_est_sensorless_nucl_B.Vab;

          /* Gain: '<S66>/Gain3' */
          mcb_param_est_sensorless_nucl_B.Vb = 0.333333343F *
            mcb_param_est_sensorless_nucl_B.Sum4;

          /* Outputs for Atomic SubSystem: '<S67>/Two phase CRL wrap' */
          mcb_param_e_TwophaseCRLwrap(mcb_param_est_sensorless_nucl_B.Va,
            mcb_param_est_sensorless_nucl_B.Vb,
            &mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap);

          /* End of Outputs for SubSystem: '<S67>/Two phase CRL wrap' */

          /* UnitDelay: '<S19>/Unit Delay3' */
          mcb_param_est_sensorless_nucl_B.UnitDelay3_b =
            mcb_param_est_sensorless__DWork.UnitDelay3_DSTATE_i;

          /* UnitDelay: '<S19>/Unit Delay4' */
          mcb_param_est_sensorless_nucl_B.UnitDelay4 =
            mcb_param_est_sensorless__DWork.UnitDelay4_DSTATE;

          /* UnitDelay: '<S13>/Unit Delay9' */
          mcb_param_est_sensorless_nucl_B.UnitDelay9 =
            mcb_param_est_sensorless__DWork.UnitDelay9_DSTATE;

          /* DataTypeConversion: '<S18>/Data Type Conversion1' */
          mcb_param_est_sensorless_nucl_B.DataTypeConversion1_p = (uint16_T)
            mcb_param_est_sensorless_nucl_B.UnitDelay9;

          /* Switch: '<S18>/Switch' */
          if (mcb_param_est_sensorless_nucl_B.DataTypeConversion1_p > 0) {
            /* Switch: '<S18>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_h[0] =
              mcb_param_est_sensorless_nucl_B.UnitDelay3_b;
            mcb_param_est_sensorless_nucl_B.Switch_h[1] =
              mcb_param_est_sensorless_nucl_B.UnitDelay4;
          } else {
            /* Gain: '<S18>/Gain' */
            mcb_param_est_sensorless_nucl_B.Gain_o[0] = 4.56130743F *
              mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap.algDD_o1;
            mcb_param_est_sensorless_nucl_B.Gain_o[1] = 4.56130743F *
              mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap.algDD_o2;

            /* Switch: '<S18>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_h[0] =
              mcb_param_est_sensorless_nucl_B.Gain_o[0];
            mcb_param_est_sensorless_nucl_B.Switch_h[1] =
              mcb_param_est_sensorless_nucl_B.Gain_o[1];
          }

          /* End of Switch: '<S18>/Switch' */

          /* Switch: '<S24>/Switch1' incorporates:
           *  Constant: '<S24>/FilterConstant'
           *  Constant: '<S24>/OneMinusFilterConstant'
           */
          mcb_param_est_sensorless_nucl_B.Switch1[0] = 0.01F;
          mcb_param_est_sensorless_nucl_B.Switch1[1] = 0.99F;

          /* UnitDelay: '<S19>/Unit Delay1' */
          mcb_param_est_sensorless_nucl_B.UnitDelay1 =
            mcb_param_est_sensorless__DWork.UnitDelay1_DSTATE;

          /* UnitDelay: '<S19>/Unit Delay2' */
          mcb_param_est_sensorless_nucl_B.UnitDelay2 =
            mcb_param_est_sensorless__DWork.UnitDelay2_DSTATE;

          /* Switch: '<S28>/Switch1' incorporates:
           *  Constant: '<S28>/FilterConstant'
           *  Constant: '<S28>/OneMinusFilterConstant'
           */
          mcb_param_est_sensorless_nucl_B.Switch1_e[0] = 0.01F;
          mcb_param_est_sensorless_nucl_B.Switch1_e[1] = 0.99F;

          /* Product: '<S31>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_c[0] =
            mcb_param_est_sensorless_nucl_B.UnitDelay1 * 0.01F;
          mcb_param_est_sensorless_nucl_B.Product_c[1] =
            mcb_param_est_sensorless_nucl_B.UnitDelay2 * 0.01F;

          /* Product: '<S27>/Product' */
          Bias = mcb_param_est_sensorless_nucl_B.Switch_h[0];

          /* Product: '<S27>/Product' */
          Product = Bias * 0.01F;
          mcb_param_est_sensorless_nucl_B.Product[0] = Product;

          /* UnitDelay: '<S27>/Unit Delay' */
          timeInstance2 = mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_a[0];
          mcb_param_est_sensorless_nucl_B.UnitDelay_e[0] = timeInstance2;

          /* Product: '<S27>/Product1' */
          timeInstance2 *= 0.99F;
          mcb_param_est_sensorless_nucl_B.Product1[0] = timeInstance2;

          /* Sum: '<S27>/Add1' */
          Product += timeInstance2;
          mcb_param_est_sensorless_nucl_B.Add1[0] = Product;

          /* Sum: '<S21>/Sum6' */
          mcb_param_est_sensorless_nucl_B.Sum6[0] = Bias - Product;

          /* UnitDelay: '<S31>/Unit Delay' */
          Bias = mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_d[0];
          mcb_param_est_sensorless_nucl_B.UnitDelay_o[0] = Bias;

          /* Product: '<S31>/Product1' */
          Bias *= 0.99F;
          mcb_param_est_sensorless_nucl_B.Product1_b[0] = Bias;

          /* Sum: '<S31>/Add1' */
          mcb_param_est_sensorless_nucl_B.Add1_i[0] =
            mcb_param_est_sensorless_nucl_B.Product_c[0] + Bias;

          /* Product: '<S27>/Product' */
          Bias = mcb_param_est_sensorless_nucl_B.Switch_h[1];

          /* Product: '<S27>/Product' */
          Product = Bias * 0.01F;
          mcb_param_est_sensorless_nucl_B.Product[1] = Product;

          /* UnitDelay: '<S27>/Unit Delay' */
          timeInstance2 = mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_a[1];
          mcb_param_est_sensorless_nucl_B.UnitDelay_e[1] = timeInstance2;

          /* Product: '<S27>/Product1' */
          timeInstance2 *= 0.99F;
          mcb_param_est_sensorless_nucl_B.Product1[1] = timeInstance2;

          /* Sum: '<S27>/Add1' */
          Product += timeInstance2;
          mcb_param_est_sensorless_nucl_B.Add1[1] = Product;

          /* Sum: '<S21>/Sum6' */
          mcb_param_est_sensorless_nucl_B.Sum6[1] = Bias - Product;

          /* UnitDelay: '<S31>/Unit Delay' */
          Bias = mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_d[1];
          mcb_param_est_sensorless_nucl_B.UnitDelay_o[1] = Bias;

          /* Product: '<S31>/Product1' */
          Bias *= 0.99F;
          mcb_param_est_sensorless_nucl_B.Product1_b[1] = Bias;

          /* Sum: '<S31>/Add1' */
          mcb_param_est_sensorless_nucl_B.Add1_i[1] =
            mcb_param_est_sensorless_nucl_B.Product_c[1] + Bias;

          /* Sum: '<S22>/Sum6' */
          mcb_param_est_sensorless_nucl_B.Sum6_p[0] =
            mcb_param_est_sensorless_nucl_B.UnitDelay1 -
            mcb_param_est_sensorless_nucl_B.Add1_i[0];
          mcb_param_est_sensorless_nucl_B.Sum6_p[1] =
            mcb_param_est_sensorless_nucl_B.UnitDelay2 -
            mcb_param_est_sensorless_nucl_B.Add1_i[1];

          /* DataStoreRead: '<S7>/Data Store Read2' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead2 =
            mcb_param_est_sensorless__DWork.currentPU_RWV;

          /* DataStoreRead: '<S7>/Data Store Read' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead_n =
            mcb_param_est_sensorless__DWork.Rs;

          /* Product: '<S18>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_i =
            mcb_param_est_sensorless_nucl_B.DataStoreRead2 *
            mcb_param_est_sensorless_nucl_B.DataStoreRead_n;

          /* DataStoreRead: '<S7>/Data Store Read1' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead1 =
            mcb_param_est_sensorless__DWork.V_rated;

          /* Gain: '<S7>/Gain' */
          mcb_param_est_sensorless_nucl_B.Gain = 0.577350259F *
            mcb_param_est_sensorless_nucl_B.DataStoreRead1;

          /* Product: '<S18>/Scaling' */
          mcb_param_est_sensorless_nucl_B.Scaling =
            mcb_param_est_sensorless_nucl_B.Product_i /
            mcb_param_est_sensorless_nucl_B.Gain;

          /* Product: '<S45>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_l =
            mcb_param_est_sensorless_nucl_B.Sum6_p[1] *
            mcb_param_est_sensorless_nucl_B.Scaling;

          /* Sum: '<S37>/Sum3' */
          mcb_param_est_sensorless_nucl_B.Sum3_i =
            mcb_param_est_sensorless_nucl_B.Sum6[1] -
            mcb_param_est_sensorless_nucl_B.Product_l;

          /* Gain: '<S37>/Gain' */
          mcb_param_est_sensorless_nucl_B.Gain_l = (real32_T)(0.0001 *
            mcb_param_est_sensorless_nucl_B.Sum3_i);

          /* RelationalOperator: '<S32>/Compare' incorporates:
           *  Constant: '<S32>/Constant'
           */
          mcb_param_est_sensorless_nucl_B.Compare_g =
            (mcb_param_est_sensorless_nucl_B.UnitDelay_a >= 4.0F);

          /* Logic: '<S23>/NOT' */
          mcb_param_est_sensorless_nucl_B.NOT_h =
            !mcb_param_est_sensorless_nucl_B.Compare_g;

          /* Delay: '<S37>/Delay' */
          zcEvent = (((mcb_param_est_se_PrevZCSigState.Delay_Reset_ZCE ==
                       POS_ZCSIG) != (int32_T)
                      mcb_param_est_sensorless_nucl_B.NOT_h) &&
                     (mcb_param_est_se_PrevZCSigState.Delay_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || mcb_param_est_sensorless_nucl_B.NOT_h) {
            mcb_param_est_sensorless__DWork.Delay_DSTATE = 0.0F;
          }

          mcb_param_est_se_PrevZCSigState.Delay_Reset_ZCE =
            mcb_param_est_sensorless_nucl_B.NOT_h;

          /* Delay: '<S37>/Delay' */
          mcb_param_est_sensorless_nucl_B.Delay_j =
            mcb_param_est_sensorless__DWork.Delay_DSTATE;

          /* Sum: '<S37>/Sum' */
          mcb_param_est_sensorless_nucl_B.Sum_k =
            mcb_param_est_sensorless_nucl_B.Gain_l +
            mcb_param_est_sensorless_nucl_B.Delay_j;

          /* DataStoreRead: '<S7>/Data Store Read3' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead3 =
            mcb_param_est_sensorless__DWork.Ld;

          /* Product: '<S18>/Product1' */
          mcb_param_est_sensorless_nucl_B.Product1_g =
            mcb_param_est_sensorless_nucl_B.DataStoreRead2 *
            mcb_param_est_sensorless_nucl_B.DataStoreRead3;

          /* Product: '<S18>/Scaling1' */
          mcb_param_est_sensorless_nucl_B.Scaling1 =
            mcb_param_est_sensorless_nucl_B.Product1_g /
            mcb_param_est_sensorless_nucl_B.Gain;

          /* Product: '<S37>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_m =
            mcb_param_est_sensorless_nucl_B.Sum6_p[1] *
            mcb_param_est_sensorless_nucl_B.Scaling1;

          /* Sum: '<S37>/Sum1' */
          mcb_param_est_sensorless_nucl_B.Sum1 =
            mcb_param_est_sensorless_nucl_B.Sum_k -
            mcb_param_est_sensorless_nucl_B.Product_m;

          /* Switch: '<S44>/Switch1' incorporates:
           *  Constant: '<S44>/FilterConstant'
           *  Constant: '<S44>/OneMinusFilterConstant'
           */
          mcb_param_est_sensorless_nucl_B.Switch1_ej[0] = 0.002F;
          mcb_param_est_sensorless_nucl_B.Switch1_ej[1] = 0.998F;

          /* Product: '<S48>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_io =
            mcb_param_est_sensorless_nucl_B.Sum1 * 0.002F;

          /* UnitDelay: '<S48>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_g =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_m;

          /* Product: '<S48>/Product1' */
          mcb_param_est_sensorless_nucl_B.Product1_p = 0.998F *
            mcb_param_est_sensorless_nucl_B.UnitDelay_g;

          /* Sum: '<S48>/Add1' */
          mcb_param_est_sensorless_nucl_B.Add1_io =
            mcb_param_est_sensorless_nucl_B.Product_io +
            mcb_param_est_sensorless_nucl_B.Product1_p;

          /* Sum: '<S37>/Sum6' */
          mcb_param_est_sensorless_nucl_B.Sum6_l =
            mcb_param_est_sensorless_nucl_B.Sum1 -
            mcb_param_est_sensorless_nucl_B.Add1_io;

          /* Product: '<S40>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_k =
            mcb_param_est_sensorless_nucl_B.Sum6_p[0] *
            mcb_param_est_sensorless_nucl_B.Scaling;

          /* Sum: '<S36>/Sum3' */
          mcb_param_est_sensorless_nucl_B.Sum3_h =
            mcb_param_est_sensorless_nucl_B.Sum6[0] -
            mcb_param_est_sensorless_nucl_B.Product_k;

          /* Gain: '<S36>/Gain' */
          mcb_param_est_sensorless_nucl_B.Gain_d = (real32_T)(0.0001 *
            mcb_param_est_sensorless_nucl_B.Sum3_h);

          /* Delay: '<S36>/Delay' */
          zcEvent = (((mcb_param_est_se_PrevZCSigState.Delay_Reset_ZCE_l ==
                       POS_ZCSIG) != (int32_T)
                      mcb_param_est_sensorless_nucl_B.NOT_h) &&
                     (mcb_param_est_se_PrevZCSigState.Delay_Reset_ZCE_l !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || mcb_param_est_sensorless_nucl_B.NOT_h) {
            mcb_param_est_sensorless__DWork.Delay_DSTATE_h = 0.0F;
          }

          mcb_param_est_se_PrevZCSigState.Delay_Reset_ZCE_l =
            mcb_param_est_sensorless_nucl_B.NOT_h;

          /* Delay: '<S36>/Delay' */
          mcb_param_est_sensorless_nucl_B.Delay_b =
            mcb_param_est_sensorless__DWork.Delay_DSTATE_h;

          /* Sum: '<S36>/Sum' */
          mcb_param_est_sensorless_nucl_B.Sum_h =
            mcb_param_est_sensorless_nucl_B.Gain_d +
            mcb_param_est_sensorless_nucl_B.Delay_b;

          /* Product: '<S36>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_im =
            mcb_param_est_sensorless_nucl_B.Sum6_p[0] *
            mcb_param_est_sensorless_nucl_B.Scaling1;

          /* Sum: '<S36>/Sum1' */
          mcb_param_est_sensorless_nucl_B.Sum1_o =
            mcb_param_est_sensorless_nucl_B.Sum_h -
            mcb_param_est_sensorless_nucl_B.Product_im;

          /* Switch: '<S39>/Switch1' incorporates:
           *  Constant: '<S39>/FilterConstant'
           *  Constant: '<S39>/OneMinusFilterConstant'
           */
          mcb_param_est_sensorless_nucl_B.Switch1_b[0] = 0.002F;
          mcb_param_est_sensorless_nucl_B.Switch1_b[1] = 0.998F;

          /* Product: '<S43>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_a =
            mcb_param_est_sensorless_nucl_B.Sum1_o * 0.002F;

          /* UnitDelay: '<S43>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_oq =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_b;

          /* Product: '<S43>/Product1' */
          mcb_param_est_sensorless_nucl_B.Product1_h = 0.998F *
            mcb_param_est_sensorless_nucl_B.UnitDelay_oq;

          /* Sum: '<S43>/Add1' */
          mcb_param_est_sensorless_nucl_B.Add1_c =
            mcb_param_est_sensorless_nucl_B.Product_a +
            mcb_param_est_sensorless_nucl_B.Product1_h;

          /* Sum: '<S36>/Sum6' */
          mcb_param_est_sensorless_nucl_B.Sum6_h =
            mcb_param_est_sensorless_nucl_B.Sum1_o -
            mcb_param_est_sensorless_nucl_B.Add1_c;

          /* Outputs for Atomic SubSystem: '<S33>/atan2' */
          mcb_param_est_sensorl_atan2(mcb_param_est_sensorless_nucl_B.Sum6_l,
            mcb_param_est_sensorless_nucl_B.Sum6_h, 2,
            &mcb_param_est_sensorless_nucl_B.atan2_n);

          /* End of Outputs for SubSystem: '<S33>/atan2' */

          /* Switch: '<S19>/Switch' */
          if (mcb_param_est_sensorless_nucl_B.UnitDelay_a >= 4.0F) {
            /* Switch: '<S19>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_d =
              mcb_param_est_sensorless_nucl_B.atan2_n.algDD;
          } else {
            /* Switch: '<S19>/Switch' incorporates:
             *  Constant: '<S10>/Ref_pos'
             */
            mcb_param_est_sensorless_nucl_B.Switch_d = 0.0F;
          }

          /* End of Switch: '<S19>/Switch' */

          /* RelationalOperator: '<S253>/Compare' incorporates:
           *  Constant: '<S253>/Constant'
           */
          mcb_param_est_sensorless_nucl_B.Compare_j =
            (mcb_param_est_sensorless_nucl_B.Switch_d < 0.0F);

          /* DataTypeConversion: '<S252>/Data Type Conversion' */
          mcb_param_est_sensorless_nucl_B.DataTypeConversion_bv =
            mcb_param_est_sensorless_nucl_B.Compare_j;

          /* If: '<S252>/If' */
          if (mcb_param_est_sensorless_nucl_B.DataTypeConversion_bv > 0) {
            /* Outputs for IfAction SubSystem: '<S252>/If Action Subsystem' incorporates:
             *  ActionPort: '<S254>/Action Port'
             */
            mcb_param_IfActionSubsystem(mcb_param_est_sensorless_nucl_B.Switch_d,
              &mcb_param_est_sensorless_nucl_B.Merge_p,
              &mcb_param_est_sensorless_nucl_B.IfActionSubsystem);

            /* End of Outputs for SubSystem: '<S252>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S252>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S255>/Action Port'
             */
            mcb_para_IfActionSubsystem1(mcb_param_est_sensorless_nucl_B.Switch_d,
              &mcb_param_est_sensorless_nucl_B.Merge_p,
              &mcb_param_est_sensorless_nucl_B.IfActionSubsystem1);

            /* End of Outputs for SubSystem: '<S252>/If Action Subsystem1' */
          }

          /* End of If: '<S252>/If' */

          /* Gain: '<S62>/indexing' */
          mcb_param_est_sensorless_nucl_B.indexing = 800.0F *
            mcb_param_est_sensorless_nucl_B.Merge_p;

          /* DataTypeConversion: '<S62>/Get_Integer' */
          mcb_param_est_sensorless_nucl_B.Get_Integer = (uint16_T)
            mcb_param_est_sensorless_nucl_B.indexing;

          /* Sum: '<S62>/Sum' incorporates:
           *  Constant: '<S62>/offset'
           */
          pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer + 1U;
          mcb_param_est_sensorless_nucl_B.Sum[0] = pinWriteLoc;

          /* Selector: '<S62>/Lookup' incorporates:
           *  Constant: '<S62>/sine_table_values'
           */
          mcb_param_est_sensorless_nucl_B.Lookup[0] =
            mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

          /* Sum: '<S62>/Sum' */
          pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer;
          mcb_param_est_sensorless_nucl_B.Sum[1] = pinWriteLoc;

          /* Selector: '<S62>/Lookup' incorporates:
           *  Constant: '<S62>/sine_table_values'
           */
          mcb_param_est_sensorless_nucl_B.Lookup[1] =
            mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

          /* Sum: '<S62>/Sum' incorporates:
           *  Constant: '<S62>/offset'
           */
          pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer + 201U;
          mcb_param_est_sensorless_nucl_B.Sum[2] = pinWriteLoc;

          /* Selector: '<S62>/Lookup' incorporates:
           *  Constant: '<S62>/sine_table_values'
           */
          mcb_param_est_sensorless_nucl_B.Lookup[2] =
            mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

          /* Sum: '<S62>/Sum' incorporates:
           *  Constant: '<S62>/offset'
           */
          pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer + 200U;
          mcb_param_est_sensorless_nucl_B.Sum[3] = pinWriteLoc;

          /* Selector: '<S62>/Lookup' incorporates:
           *  Constant: '<S62>/sine_table_values'
           */
          mcb_param_est_sensorless_nucl_B.Lookup[3] =
            mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

          /* Sum: '<S251>/Sum3' */
          mcb_param_est_sensorless_nucl_B.Sum3_f =
            mcb_param_est_sensorless_nucl_B.Lookup[0] -
            mcb_param_est_sensorless_nucl_B.Lookup[1];

          /* DataTypeConversion: '<S62>/Data Type Conversion1' */
          mcb_param_est_sensorless_nucl_B.DataTypeConversion1_f =
            mcb_param_est_sensorless_nucl_B.Get_Integer;

          /* Sum: '<S62>/Sum2' */
          mcb_param_est_sensorless_nucl_B.Sum2 =
            mcb_param_est_sensorless_nucl_B.indexing -
            mcb_param_est_sensorless_nucl_B.DataTypeConversion1_f;

          /* Product: '<S251>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_b =
            mcb_param_est_sensorless_nucl_B.Sum3_f *
            mcb_param_est_sensorless_nucl_B.Sum2;

          /* Sum: '<S251>/Sum4' */
          mcb_param_est_sensorless_nucl_B.Sum4_h =
            mcb_param_est_sensorless_nucl_B.Product_b +
            mcb_param_est_sensorless_nucl_B.Lookup[1];

          /* Sum: '<S251>/Sum5' */
          mcb_param_est_sensorless_nucl_B.Sum5 =
            mcb_param_est_sensorless_nucl_B.Lookup[2] -
            mcb_param_est_sensorless_nucl_B.Lookup[3];

          /* Product: '<S251>/Product1' */
          mcb_param_est_sensorless_nucl_B.Product1_e =
            mcb_param_est_sensorless_nucl_B.Sum5 *
            mcb_param_est_sensorless_nucl_B.Sum2;

          /* Sum: '<S251>/Sum6' */
          mcb_param_est_sensorless_nucl_B.Sum6_f =
            mcb_param_est_sensorless_nucl_B.Product1_e +
            mcb_param_est_sensorless_nucl_B.Lookup[3];

          /* Outputs for Atomic SubSystem: '<S65>/Two inputs CRL' */
          mcb_param_est__TwoinputsCRL
            (mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap.algDD_o1,
             mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap.algDD_o2,
             mcb_param_est_sensorless_nucl_B.Sum4_h,
             mcb_param_est_sensorless_nucl_B.Sum6_f,
             &mcb_param_est_sensorless_nucl_B.TwoinputsCRL);

          /* End of Outputs for SubSystem: '<S65>/Two inputs CRL' */

          /* DataStoreRead: '<S17>/Data Store Read' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead_o =
            mcb_param_est_sensorless__DWork.Ia_avg_cal;

          /* DataTypeConversion: '<S17>/Data Type Conversion2' */
          mcb_param_est_sensorless_nucl_B.DataTypeConversion2_a = (int32_T)
            mcb_param_est_sensorless_nucl_B.DataStoreRead_o;

          /* DataStoreRead: '<S17>/Data Store Read1' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead1_p =
            mcb_param_est_sensorless__DWork.Ib_avg_cal;

          /* DataTypeConversion: '<S17>/Data Type Conversion3' */
          mcb_param_est_sensorless_nucl_B.DataTypeConversion3 = (int32_T)
            mcb_param_est_sensorless_nucl_B.DataStoreRead1_p;

          /* DataTypeConversion: '<S17>/Data Type Conversion' */
          mcb_param_est_sensorless_nucl_B.DataTypeConversion_o[0] =
            mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter[0];
          mcb_param_est_sensorless_nucl_B.DataTypeConversion_o[1] =
            mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter[1];

          /* Sum: '<S17>/Add' */
          mcb_param_est_sensorless_nucl_B.Add_b[0] =
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_o[0] -
            mcb_param_est_sensorless_nucl_B.DataTypeConversion2_a;
          mcb_param_est_sensorless_nucl_B.Add_b[1] =
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_o[1] -
            mcb_param_est_sensorless_nucl_B.DataTypeConversion3;

          /* DataTypeConversion: '<S17>/Data Type Conversion4' */
          Bias = (real32_T)mcb_param_est_sensorless_nucl_B.Add_b[0];
          mcb_param_est_sensorless_nucl_B.DataTypeConversion4_f[0] = Bias;

          /* Gain: '<S17>/count_to_PU1' */
          mcb_param_est_sensorless_nucl_B.count_to_PU1[0] = -0.00048828125F *
            Bias;

          /* DataTypeConversion: '<S17>/Data Type Conversion4' */
          Bias = (real32_T)mcb_param_est_sensorless_nucl_B.Add_b[1];
          mcb_param_est_sensorless_nucl_B.DataTypeConversion4_f[1] = Bias;

          /* Gain: '<S17>/count_to_PU1' */
          mcb_param_est_sensorless_nucl_B.count_to_PU1[1] = -0.00048828125F *
            Bias;

          /* Outputs for Atomic SubSystem: '<S73>/Two phase CRL wrap' */
          mcb_param_e_TwophaseCRLwrap
            (mcb_param_est_sensorless_nucl_B.count_to_PU1[0],
             mcb_param_est_sensorless_nucl_B.count_to_PU1[1],
             &mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k);

          /* End of Outputs for SubSystem: '<S73>/Two phase CRL wrap' */

          /* Outputs for Atomic SubSystem: '<S72>/Two inputs CRL' */
          mcb_param_est__TwoinputsCRL
            (mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k.algDD_o1,
             mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k.algDD_o2,
             mcb_param_est_sensorless_nucl_B.Sum4_h,
             mcb_param_est_sensorless_nucl_B.Sum6_f,
             &mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o);

          /* End of Outputs for SubSystem: '<S72>/Two inputs CRL' */

          /* DataStoreRead: '<S19>/Data Store Read1' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead1_jd =
            mcb_param_est_sensorless__DWork.EnClosedLoop;

          /* DataStoreRead: '<S19>/Data Store Read2' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead2_c =
            mcb_param_est_sensorless__DWork.disableOL;

          /* UnitDelay: '<S13>/Unit Delay2' */
          mcb_param_est_sensorless_nucl_B.UnitDelay2_g =
            mcb_param_est_sensorless__DWork.UnitDelay2_DSTATE_m;

          /* UnitDelay: '<S1>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_n =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_i;

          /* Switch: '<S9>/Switch1' incorporates:
           *  Constant: '<S9>/FilterConstant'
           *  Constant: '<S9>/OneMinusFilterConstant'
           */
          mcb_param_est_sensorless_nucl_B.Switch1_g[0] = 0.02F;
          mcb_param_est_sensorless_nucl_B.Switch1_g[1] = 0.98F;

          /* Product: '<S268>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_o =
            mcb_param_est_sensorless_nucl_B.UnitDelay_n * 0.02F;

          /* UnitDelay: '<S268>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_nf =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_f;

          /* Product: '<S268>/Product1' */
          mcb_param_est_sensorless_nucl_B.Product1_em = 0.98F *
            mcb_param_est_sensorless_nucl_B.UnitDelay_nf;

          /* Sum: '<S268>/Add1' */
          mcb_param_est_sensorless_nucl_B.Add1_k =
            mcb_param_est_sensorless_nucl_B.Product_o +
            mcb_param_est_sensorless_nucl_B.Product1_em;

          /* DataStoreRead: '<S1>/Data Store Read' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead_k =
            mcb_param_est_sensorless__DWork.testEnableFromHost;

          /* Product: '<S1>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_e =
            mcb_param_est_sensorless_nucl_B.DataStoreRead_k *
            mcb_param_est_sensorless_nucl_B.UnitDelay9;

          /* RelationalOperator: '<S280>/Compare' incorporates:
           *  Constant: '<S280>/Constant'
           */
          mcb_param_est_sensorless_nucl_B.Compare_c =
            (mcb_param_est_sensorless_nucl_B.UnitDelay_a >= 4.0F);

          /* Outputs for Enabled SubSystem: '<S14>/Torque_control_with_speed_limit' incorporates:
           *  EnablePort: '<S281>/Enable'
           */
          if (mcb_param_est_sensorless_nucl_B.Compare_c) {
            /* DataStoreRead: '<S281>/Data Store Read' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead_g =
              mcb_param_est_sensorless__DWork.I_rated;

            /* DataStoreRead: '<S281>/Data Store Read1' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead1_j =
              mcb_param_est_sensorless__DWork.currentPU_RWV;

            /* Abs: '<S282>/Abs' */
            mcb_param_est_sensorless_nucl_B.Abs = fabsf
              (mcb_param_est_sensorless_nucl_B.Add1_k);

            /* Abs: '<S282>/Abs1' */
            mcb_param_est_sensorless_nucl_B.Abs1 = fabsf
              (mcb_param_est_sensorless_nucl_B.UnitDelay3);

            /* Product: '<S282>/Product' incorporates:
             *  Constant: '<S282>/One_minus_derating'
             */
            mcb_param_est_sensorless_nucl_B.Product_ms =
              mcb_param_est_sensorless_nucl_B.Abs1 * 0.1F;

            /* RelationalOperator: '<S283>/Compare' incorporates:
             *  Constant: '<S283>/Constant'
             */
            mcb_param_est_sensorless_nucl_B.Compare_cl =
              (mcb_param_est_sensorless_nucl_B.Product_ms > 0.0F);

            /* DataTypeConversion: '<S282>/Data Type Conversion' */
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_n =
              mcb_param_est_sensorless_nucl_B.Compare_cl;

            /* Gain: '<S282>/derating' */
            mcb_param_est_sensorless_nucl_B.derating = 0.9F *
              mcb_param_est_sensorless_nucl_B.Abs1;

            /* Sum: '<S282>/Sum' */
            mcb_param_est_sensorless_nucl_B.Sum_b =
              mcb_param_est_sensorless_nucl_B.Abs -
              mcb_param_est_sensorless_nucl_B.derating;

            /* If: '<S282>/If' */
            if (mcb_param_est_sensorless_nucl_B.DataTypeConversion_n > 0) {
              /* Outputs for IfAction SubSystem: '<S282>/If Action Subsystem' incorporates:
               *  ActionPort: '<S285>/Action Port'
               */
              /* Product: '<S285>/Divide1' */
              mcb_param_est_sensorless_nucl_B.Divide1 =
                mcb_param_est_sensorless_nucl_B.Sum_b /
                mcb_param_est_sensorless_nucl_B.Product_ms;

              /* Saturate: '<S285>/Saturation' */
              Bias = mcb_param_est_sensorless_nucl_B.Divide1;
              if (Bias > 1.0F) {
                /* Merge: '<S282>/Merge' */
                mcb_param_est_sensorless_nucl_B.Merge_c = 1.0F;
              } else if (Bias < 0.0F) {
                /* Merge: '<S282>/Merge' */
                mcb_param_est_sensorless_nucl_B.Merge_c = 0.0F;
              } else {
                /* Merge: '<S282>/Merge' */
                mcb_param_est_sensorless_nucl_B.Merge_c = Bias;
              }

              /* End of Saturate: '<S285>/Saturation' */
              /* End of Outputs for SubSystem: '<S282>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S282>/Handle divide by 0' incorporates:
               *  ActionPort: '<S284>/Action Port'
               */
              /* Merge: '<S282>/Merge' incorporates:
               *  Constant: '<S282>/Const'
               *  SignalConversion generated from: '<S284>/In1'
               */
              mcb_param_est_sensorless_nucl_B.Merge_c = 1.0F;

              /* End of Outputs for SubSystem: '<S282>/Handle divide by 0' */
            }

            /* End of If: '<S282>/If' */

            /* Sum: '<S282>/Sum2' incorporates:
             *  Constant: '<S282>/One'
             */
            mcb_param_est_sensorless_nucl_B.Sum2_d = 1.0F -
              mcb_param_est_sensorless_nucl_B.Merge_c;

            /* Product: '<S281>/Product1' */
            mcb_param_est_sensorless_nucl_B.Product1_pz =
              mcb_param_est_sensorless_nucl_B.UnitDelay2_g *
              mcb_param_est_sensorless_nucl_B.DataStoreRead_g;

            /* Product: '<S281>/Divide' */
            mcb_param_est_sensorless_nucl_B.Divide_n =
              mcb_param_est_sensorless_nucl_B.Product1_pz /
              mcb_param_est_sensorless_nucl_B.DataStoreRead1_j;

            /* Product: '<S281>/Product' */
            mcb_param_est_sensorless_nucl_B.Product_by =
              mcb_param_est_sensorless_nucl_B.Divide_n *
              mcb_param_est_sensorless_nucl_B.Sum2_d *
              mcb_param_est_sensorless_nucl_B.Product_e;
          }

          /* End of Outputs for SubSystem: '<S14>/Torque_control_with_speed_limit' */

          /* Switch: '<S14>/Switch' */
          if (mcb_param_est_sensorless_nucl_B.UnitDelay_a >= 4.0F) {
            /* Switch: '<S14>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_m =
              mcb_param_est_sensorless_nucl_B.Product_by;
          } else {
            /* Switch: '<S14>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_m =
              mcb_param_est_sensorless_nucl_B.UnitDelay3;
          }

          /* End of Switch: '<S14>/Switch' */

          /* RelationalOperator: '<S103>/Compare' incorporates:
           *  Constant: '<S103>/Constant'
           */
          mcb_param_est_sensorless_nucl_B.Compare_e =
            (mcb_param_est_sensorless_nucl_B.UnitDelay_a >= 4.0F);

          /* Outputs for Enabled SubSystem: '<S60>/Control' incorporates:
           *  EnablePort: '<S104>/Enable'
           */
          if (mcb_param_est_sensorless_nucl_B.Compare_e) {
            /* DataStoreRead: '<S104>/Data Store Read3' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead3_d =
              mcb_param_est_sensorless__DWork.EnClosedLoop;

            /* DataStoreRead: '<S104>/Data Store Read' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead_ga =
              mcb_param_est_sensorless__DWork.testEnableFromHost;

            /* Logic: '<S104>/AND' */
            mcb_param_est_sensorless_nucl_B.AND =
              (mcb_param_est_sensorless_nucl_B.DataStoreRead3_d &&
               (mcb_param_est_sensorless_nucl_B.DataStoreRead_ga != 0.0F));

            /* DataStoreRead: '<S104>/Data Store Read4' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead4_j =
              mcb_param_est_sensorless__DWork.Kp_i;

            /* Sum: '<S104>/Sum' incorporates:
             *  Constant: '<S104>/Id Desired'
             */
            mcb_param_est_sensorless_nucl_B.Sum_i = 0.0F -
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o1;

            /* Product: '<S104>/Product1' */
            mcb_param_est_sensorless_nucl_B.Product1_o =
              mcb_param_est_sensorless_nucl_B.DataStoreRead4_j *
              mcb_param_est_sensorless_nucl_B.Sum_i;

            /* Sum: '<S104>/Add' */
            mcb_param_est_sensorless_nucl_B.Add_ge =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL.algDD_o1 -
              mcb_param_est_sensorless_nucl_B.Product1_o;

            /* Sum: '<S104>/Sum1' */
            mcb_param_est_sensorless_nucl_B.Sum1_j =
              mcb_param_est_sensorless_nucl_B.Switch_m -
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o2;

            /* Product: '<S104>/Product2' */
            mcb_param_est_sensorless_nucl_B.Product2 =
              mcb_param_est_sensorless_nucl_B.DataStoreRead4_j *
              mcb_param_est_sensorless_nucl_B.Sum1_j;

            /* Sum: '<S104>/Add1' */
            mcb_param_est_sensorless_nucl_B.Add1_a =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL.algDD_o2 -
              mcb_param_est_sensorless_nucl_B.Product2;

            /* Switch: '<S111>/Switch1' incorporates:
             *  Constant: '<S111>/ChosenMethod'
             */
            mcb_param_est_sensorless_nucl_B.Switch1_cp = 3U;

            /* DataStoreRead: '<S104>/Data Store Read1' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead1_g =
              mcb_param_est_sensorless__DWork.Kp_i;

            /* Product: '<S215>/PProd Out' */
            mcb_param_est_sensorless_nucl_B.PProdOut =
              mcb_param_est_sensorless_nucl_B.Sum1_j *
              mcb_param_est_sensorless_nucl_B.DataStoreRead1_g;

            /* Logic: '<S104>/NOT' */
            mcb_param_est_sensorless_nucl_B.NOT_fd =
              !mcb_param_est_sensorless_nucl_B.AND;

            /* DiscreteIntegrator: '<S210>/Integrator' */
            if (mcb_param_est_sensorless__DWork.Integrator_IC_LOADING != 0) {
              mcb_param_est_sensorless__DWork.Integrator_DSTATE =
                mcb_param_est_sensorless_nucl_B.Add1_a;
            }

            if (mcb_param_est_sensorless_nucl_B.NOT_fd ||
                (mcb_param_est_sensorless__DWork.Integrator_PrevResetState != 0))
            {
              mcb_param_est_sensorless__DWork.Integrator_DSTATE =
                mcb_param_est_sensorless_nucl_B.Add1_a;
            }

            /* DiscreteIntegrator: '<S210>/Integrator' */
            mcb_param_est_sensorless_nucl_B.Integrator =
              mcb_param_est_sensorless__DWork.Integrator_DSTATE;

            /* Sum: '<S219>/Sum' */
            mcb_param_est_sensorless_nucl_B.Sum_j =
              mcb_param_est_sensorless_nucl_B.PProdOut +
              mcb_param_est_sensorless_nucl_B.Integrator;

            /* Saturate: '<S217>/Saturation' */
            Bias = mcb_param_est_sensorless_nucl_B.Sum_j;
            if (Bias > 1.0F) {
              /* Saturate: '<S217>/Saturation' */
              mcb_param_est_sensorless_nucl_B.Saturation_g = 1.0F;
            } else if (Bias < -1.0F) {
              /* Saturate: '<S217>/Saturation' */
              mcb_param_est_sensorless_nucl_B.Saturation_g = -1.0F;
            } else {
              /* Saturate: '<S217>/Saturation' */
              mcb_param_est_sensorless_nucl_B.Saturation_g = Bias;
            }

            /* End of Saturate: '<S217>/Saturation' */

            /* Product: '<S163>/PProd Out' */
            mcb_param_est_sensorless_nucl_B.PProdOut_k =
              mcb_param_est_sensorless_nucl_B.Sum_i *
              mcb_param_est_sensorless_nucl_B.DataStoreRead1_g;

            /* DiscreteIntegrator: '<S158>/Integrator' */
            if (mcb_param_est_sensorless__DWork.Integrator_IC_LOADING_g != 0) {
              mcb_param_est_sensorless__DWork.Integrator_DSTATE_c =
                mcb_param_est_sensorless_nucl_B.Add_ge;
            }

            if (mcb_param_est_sensorless_nucl_B.NOT_fd ||
                (mcb_param_est_sensorless__DWork.Integrator_PrevResetState_k !=
                 0)) {
              mcb_param_est_sensorless__DWork.Integrator_DSTATE_c =
                mcb_param_est_sensorless_nucl_B.Add_ge;
            }

            /* DiscreteIntegrator: '<S158>/Integrator' */
            mcb_param_est_sensorless_nucl_B.Integrator_i =
              mcb_param_est_sensorless__DWork.Integrator_DSTATE_c;

            /* Sum: '<S167>/Sum' */
            mcb_param_est_sensorless_nucl_B.Sum_c =
              mcb_param_est_sensorless_nucl_B.PProdOut_k +
              mcb_param_est_sensorless_nucl_B.Integrator_i;

            /* Saturate: '<S165>/Saturation' */
            Bias = mcb_param_est_sensorless_nucl_B.Sum_c;
            if (Bias > 1.0F) {
              /* Saturate: '<S165>/Saturation' */
              mcb_param_est_sensorless_nucl_B.Saturation_jy = 1.0F;
            } else if (Bias < -1.0F) {
              /* Saturate: '<S165>/Saturation' */
              mcb_param_est_sensorless_nucl_B.Saturation_jy = -1.0F;
            } else {
              /* Saturate: '<S165>/Saturation' */
              mcb_param_est_sensorless_nucl_B.Saturation_jy = Bias;
            }

            /* End of Saturate: '<S165>/Saturation' */

            /* Switch: '<S111>/Switch' incorporates:
             *  Constant: '<S111>/Constant3'
             */
            mcb_param_est_sensorless_nucl_B.Switch_p = 0.95F;

            /* Product: '<S111>/Product' */
            mcb_param_est_sensorless_nucl_B.Product_lw = 0.9025F;

            /* Product: '<S112>/Product' */
            mcb_param_est_sensorless_nucl_B.Product_lr =
              mcb_param_est_sensorless_nucl_B.Saturation_jy *
              mcb_param_est_sensorless_nucl_B.Saturation_jy;

            /* Product: '<S112>/Product1' */
            mcb_param_est_sensorless_nucl_B.Product1_n =
              mcb_param_est_sensorless_nucl_B.Saturation_g *
              mcb_param_est_sensorless_nucl_B.Saturation_g;

            /* Sum: '<S112>/Sum1' */
            mcb_param_est_sensorless_nucl_B.Sum1_e =
              mcb_param_est_sensorless_nucl_B.Product_lr +
              mcb_param_est_sensorless_nucl_B.Product1_n;

            /* Outputs for IfAction SubSystem: '<S106>/D-Q Equivalence' incorporates:
             *  ActionPort: '<S109>/Action Port'
             */
            /* If: '<S106>/If' incorporates:
             *  DataTypeConversion: '<S109>/Data Type Conversion'
             *  RelationalOperator: '<S109>/Relational Operator'
             */
            mcb_param_est_sensorless_nucl_B.RelationalOperator_o =
              (mcb_param_est_sensorless_nucl_B.Sum1_e > 0.9025F);
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_l =
              mcb_param_est_sensorless_nucl_B.RelationalOperator_o;

            /* If: '<S109>/If' incorporates:
             *  If: '<S106>/If'
             */
            if (mcb_param_est_sensorless_nucl_B.DataTypeConversion_l != 0) {
              /* Outputs for IfAction SubSystem: '<S109>/Limiter' incorporates:
               *  ActionPort: '<S113>/Action Port'
               */
              /* Product: '<S113>/Product' */
              mcb_param_est_sensorless_nucl_B.Product_l5[0] =
                mcb_param_est_sensorless_nucl_B.Saturation_jy * 0.95F;
              mcb_param_est_sensorless_nucl_B.Product_l5[1] =
                mcb_param_est_sensorless_nucl_B.Saturation_g * 0.95F;

              /* Sqrt: '<S113>/Square Root' */
              mw_arm_sqrt_f32(&mcb_param_est_sensorless_nucl_B.Sum1_e,
                              &mcb_param_est_sensorless_nucl_B.SquareRoot, 1U);

              /* Switch: '<S113>/Switch' */
              if (mcb_param_est_sensorless_nucl_B.SquareRoot != 0.0F) {
                /* Switch: '<S113>/Switch' */
                mcb_param_est_sensorless_nucl_B.Switch_a =
                  mcb_param_est_sensorless_nucl_B.SquareRoot;
              } else {
                /* Switch: '<S113>/Switch' incorporates:
                 *  Constant: '<S113>/Constant'
                 */
                mcb_param_est_sensorless_nucl_B.Switch_a = 1.0F;
              }

              /* End of Switch: '<S113>/Switch' */

              /* Merge: '<S106>/Merge' incorporates:
               *  Product: '<S113>/Divide'
               */
              mcb_param_est_sensorless_nucl_B.Merge_b[0] =
                mcb_param_est_sensorless_nucl_B.Product_l5[0] /
                mcb_param_est_sensorless_nucl_B.Switch_a;
              mcb_param_est_sensorless_nucl_B.Merge_b[1] =
                mcb_param_est_sensorless_nucl_B.Product_l5[1] /
                mcb_param_est_sensorless_nucl_B.Switch_a;

              /* End of Outputs for SubSystem: '<S109>/Limiter' */
            } else {
              /* Outputs for IfAction SubSystem: '<S109>/Passthrough' incorporates:
               *  ActionPort: '<S114>/Action Port'
               */
              /* Merge: '<S106>/Merge' incorporates:
               *  SignalConversion generated from: '<S114>/dqRef'
               */
              mcb_param_est_sensorless_nucl_B.Merge_b[0] =
                mcb_param_est_sensorless_nucl_B.Saturation_jy;
              mcb_param_est_sensorless_nucl_B.Merge_b[1] =
                mcb_param_est_sensorless_nucl_B.Saturation_g;

              /* End of Outputs for SubSystem: '<S109>/Passthrough' */
            }

            /* End of If: '<S109>/If' */
            /* End of Outputs for SubSystem: '<S106>/D-Q Equivalence' */

            /* DataStoreRead: '<S104>/Data Store Read2' */
            mcb_param_est_sensorless_nucl_B.DataStoreRead2_n =
              mcb_param_est_sensorless__DWork.Ki_i;

            /* DeadZone: '<S150>/DeadZone' */
            if (mcb_param_est_sensorless_nucl_B.Sum_c > 1.0F) {
              /* DeadZone: '<S150>/DeadZone' */
              mcb_param_est_sensorless_nucl_B.DeadZone =
                mcb_param_est_sensorless_nucl_B.Sum_c - 1.0F;
            } else if (mcb_param_est_sensorless_nucl_B.Sum_c >= -1.0F) {
              /* DeadZone: '<S150>/DeadZone' */
              mcb_param_est_sensorless_nucl_B.DeadZone = 0.0F;
            } else {
              /* DeadZone: '<S150>/DeadZone' */
              mcb_param_est_sensorless_nucl_B.DeadZone =
                mcb_param_est_sensorless_nucl_B.Sum_c - -1.0F;
            }

            /* End of DeadZone: '<S150>/DeadZone' */

            /* RelationalOperator: '<S148>/Relational Operator' incorporates:
             *  Constant: '<S148>/Clamping_zero'
             */
            mcb_param_est_sensorless_nucl_B.RelationalOperator_k =
              (mcb_param_est_sensorless_nucl_B.DeadZone != 0.0F);

            /* RelationalOperator: '<S148>/fix for DT propagation issue' incorporates:
             *  Constant: '<S148>/Clamping_zero'
             */
            mcb_param_est_sensorless_nucl_B.fixforDTpropagationissue =
              (mcb_param_est_sensorless_nucl_B.DeadZone > 0.0F);

            /* Switch: '<S148>/Switch1' */
            if (mcb_param_est_sensorless_nucl_B.fixforDTpropagationissue) {
              /* Switch: '<S148>/Switch1' incorporates:
               *  Constant: '<S148>/Constant'
               */
              mcb_param_est_sensorless_nucl_B.Switch1_j = 1;
            } else {
              /* Switch: '<S148>/Switch1' incorporates:
               *  Constant: '<S148>/Constant2'
               */
              mcb_param_est_sensorless_nucl_B.Switch1_j = -1;
            }

            /* End of Switch: '<S148>/Switch1' */

            /* Product: '<S104>/Product' incorporates:
             *  Constant: '<S104>/Ts'
             */
            mcb_param_est_sensorless_nucl_B.Product_oa = 0.0001F *
              mcb_param_est_sensorless_nucl_B.DataStoreRead2_n;

            /* Product: '<S155>/IProd Out' */
            mcb_param_est_sensorless_nucl_B.IProdOut =
              mcb_param_est_sensorless_nucl_B.Sum_i *
              mcb_param_est_sensorless_nucl_B.Product_oa;

            /* RelationalOperator: '<S148>/fix for DT propagation issue1' incorporates:
             *  Constant: '<S148>/Clamping_zero'
             */
            mcb_param_est_sensorless_nucl_B.fixforDTpropagationissue1 =
              (mcb_param_est_sensorless_nucl_B.IProdOut > 0.0F);

            /* Switch: '<S148>/Switch2' */
            if (mcb_param_est_sensorless_nucl_B.fixforDTpropagationissue1) {
              /* Switch: '<S148>/Switch2' incorporates:
               *  Constant: '<S148>/Constant3'
               */
              mcb_param_est_sensorless_nucl_B.Switch2_n = 1;
            } else {
              /* Switch: '<S148>/Switch2' incorporates:
               *  Constant: '<S148>/Constant4'
               */
              mcb_param_est_sensorless_nucl_B.Switch2_n = -1;
            }

            /* End of Switch: '<S148>/Switch2' */

            /* RelationalOperator: '<S148>/Equal1' */
            mcb_param_est_sensorless_nucl_B.Equal1 =
              (mcb_param_est_sensorless_nucl_B.Switch1_j ==
               mcb_param_est_sensorless_nucl_B.Switch2_n);

            /* Logic: '<S148>/AND3' */
            mcb_param_est_sensorless_nucl_B.AND3 =
              (mcb_param_est_sensorless_nucl_B.RelationalOperator_k &&
               mcb_param_est_sensorless_nucl_B.Equal1);

            /* Switch: '<S148>/Switch' */
            if (mcb_param_est_sensorless_nucl_B.AND3) {
              /* Switch: '<S148>/Switch' incorporates:
               *  Constant: '<S148>/Constant1'
               */
              mcb_param_est_sensorless_nucl_B.Switch_i = 0.0F;
            } else {
              /* Switch: '<S148>/Switch' */
              mcb_param_est_sensorless_nucl_B.Switch_i =
                mcb_param_est_sensorless_nucl_B.IProdOut;
            }

            /* End of Switch: '<S148>/Switch' */

            /* DeadZone: '<S202>/DeadZone' */
            if (mcb_param_est_sensorless_nucl_B.Sum_j > 1.0F) {
              /* DeadZone: '<S202>/DeadZone' */
              mcb_param_est_sensorless_nucl_B.DeadZone_p =
                mcb_param_est_sensorless_nucl_B.Sum_j - 1.0F;
            } else if (mcb_param_est_sensorless_nucl_B.Sum_j >= -1.0F) {
              /* DeadZone: '<S202>/DeadZone' */
              mcb_param_est_sensorless_nucl_B.DeadZone_p = 0.0F;
            } else {
              /* DeadZone: '<S202>/DeadZone' */
              mcb_param_est_sensorless_nucl_B.DeadZone_p =
                mcb_param_est_sensorless_nucl_B.Sum_j - -1.0F;
            }

            /* End of DeadZone: '<S202>/DeadZone' */

            /* RelationalOperator: '<S200>/Relational Operator' incorporates:
             *  Constant: '<S200>/Clamping_zero'
             */
            mcb_param_est_sensorless_nucl_B.RelationalOperator_c =
              (mcb_param_est_sensorless_nucl_B.DeadZone_p != 0.0F);

            /* RelationalOperator: '<S200>/fix for DT propagation issue' incorporates:
             *  Constant: '<S200>/Clamping_zero'
             */
            mcb_param_est_sensorless_nucl_B.fixforDTpropagationissue_o =
              (mcb_param_est_sensorless_nucl_B.DeadZone_p > 0.0F);

            /* Switch: '<S200>/Switch1' */
            if (mcb_param_est_sensorless_nucl_B.fixforDTpropagationissue_o) {
              /* Switch: '<S200>/Switch1' incorporates:
               *  Constant: '<S200>/Constant'
               */
              mcb_param_est_sensorless_nucl_B.Switch1_n = 1;
            } else {
              /* Switch: '<S200>/Switch1' incorporates:
               *  Constant: '<S200>/Constant2'
               */
              mcb_param_est_sensorless_nucl_B.Switch1_n = -1;
            }

            /* End of Switch: '<S200>/Switch1' */

            /* Product: '<S207>/IProd Out' */
            mcb_param_est_sensorless_nucl_B.IProdOut_c =
              mcb_param_est_sensorless_nucl_B.Sum1_j *
              mcb_param_est_sensorless_nucl_B.Product_oa;

            /* RelationalOperator: '<S200>/fix for DT propagation issue1' incorporates:
             *  Constant: '<S200>/Clamping_zero'
             */
            mcb_param_est_sensorless_nucl_B.fixforDTpropagationissue1_d =
              (mcb_param_est_sensorless_nucl_B.IProdOut_c > 0.0F);

            /* Switch: '<S200>/Switch2' */
            if (mcb_param_est_sensorless_nucl_B.fixforDTpropagationissue1_d) {
              /* Switch: '<S200>/Switch2' incorporates:
               *  Constant: '<S200>/Constant3'
               */
              mcb_param_est_sensorless_nucl_B.Switch2_j = 1;
            } else {
              /* Switch: '<S200>/Switch2' incorporates:
               *  Constant: '<S200>/Constant4'
               */
              mcb_param_est_sensorless_nucl_B.Switch2_j = -1;
            }

            /* End of Switch: '<S200>/Switch2' */

            /* RelationalOperator: '<S200>/Equal1' */
            mcb_param_est_sensorless_nucl_B.Equal1_g =
              (mcb_param_est_sensorless_nucl_B.Switch1_n ==
               mcb_param_est_sensorless_nucl_B.Switch2_j);

            /* Logic: '<S200>/AND3' */
            mcb_param_est_sensorless_nucl_B.AND3_i =
              (mcb_param_est_sensorless_nucl_B.RelationalOperator_c &&
               mcb_param_est_sensorless_nucl_B.Equal1_g);

            /* Switch: '<S200>/Switch' */
            if (mcb_param_est_sensorless_nucl_B.AND3_i) {
              /* Switch: '<S200>/Switch' incorporates:
               *  Constant: '<S200>/Constant1'
               */
              mcb_param_est_sensorless_nucl_B.Switch_o = 0.0F;
            } else {
              /* Switch: '<S200>/Switch' */
              mcb_param_est_sensorless_nucl_B.Switch_o =
                mcb_param_est_sensorless_nucl_B.IProdOut_c;
            }

            /* End of Switch: '<S200>/Switch' */

            /* Update for DiscreteIntegrator: '<S210>/Integrator' */
            mcb_param_est_sensorless__DWork.Integrator_IC_LOADING = 0U;
            mcb_param_est_sensorless__DWork.Integrator_DSTATE +=
              mcb_param_est_sensorless_nucl_B.Switch_o;
            mcb_param_est_sensorless__DWork.Integrator_PrevResetState = (int8_T)
              mcb_param_est_sensorless_nucl_B.NOT_fd;

            /* Update for DiscreteIntegrator: '<S158>/Integrator' */
            mcb_param_est_sensorless__DWork.Integrator_IC_LOADING_g = 0U;
            mcb_param_est_sensorless__DWork.Integrator_DSTATE_c +=
              mcb_param_est_sensorless_nucl_B.Switch_i;
            mcb_param_est_sensorless__DWork.Integrator_PrevResetState_k =
              (int8_T)mcb_param_est_sensorless_nucl_B.NOT_fd;
          }

          /* End of Outputs for SubSystem: '<S60>/Control' */

          /* UnitDelay: '<S13>/Unit Delay1' */
          mcb_param_est_sensorless_nucl_B.UnitDelay1_a =
            mcb_param_est_sensorless__DWork.UnitDelay1_DSTATE_m;

          /* Logic: '<S60>/NOT' */
          mcb_param_est_sensorless_nucl_B.NOT_p =
            !mcb_param_est_sensorless_nucl_B.Compare_e;

          /* Outputs for Enabled SubSystem: '<S60>/OpenLoop' incorporates:
           *  EnablePort: '<S105>/Enable'
           */
          if (mcb_param_est_sensorless_nucl_B.NOT_p) {
            /* Gain: '<S231>/Gain' */
            mcb_param_est_sensorless_nucl_B.Gain_ll = 0.0001F *
              mcb_param_est_sensorless_nucl_B.UnitDelay1_a;

            /* UnitDelay: '<S232>/Unit Delay' */
            mcb_param_est_sensorless_nucl_B.UnitDelay_b =
              mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_o;

            /* Logic: '<S232>/NOT' */
            mcb_param_est_sensorless_nucl_B.NOT_o = true;

            /* Outputs for Enabled SubSystem: '<S232>/Accumulate' */
            mcb_param_est_se_Accumulate(true,
              mcb_param_est_sensorless_nucl_B.Gain_ll,
              mcb_param_est_sensorless_nucl_B.UnitDelay_b,
              &mcb_param_est_sensorless_nucl_B.Accumulate_f,
              &mcb_param_est_sensorless__DWork.Accumulate_f);

            /* End of Outputs for SubSystem: '<S232>/Accumulate' */

            /* RelationalOperator: '<S238>/Compare' incorporates:
             *  Constant: '<S238>/Constant'
             */
            mcb_param_est_sensorless_nucl_B.Compare_k =
              (mcb_param_est_sensorless_nucl_B.Accumulate_f.Add1 < 0.0F);

            /* DataTypeConversion: '<S237>/Data Type Conversion' */
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_e =
              mcb_param_est_sensorless_nucl_B.Compare_k;

            /* If: '<S237>/If' */
            if (mcb_param_est_sensorless_nucl_B.DataTypeConversion_e > 0) {
              /* Outputs for IfAction SubSystem: '<S237>/If Action Subsystem' incorporates:
               *  ActionPort: '<S239>/Action Port'
               */
              mcb_param_IfActionSubsystem
                (mcb_param_est_sensorless_nucl_B.Accumulate_f.Add1,
                 &mcb_param_est_sensorless_nucl_B.Merge_c5,
                 &mcb_param_est_sensorless_nucl_B.IfActionSubsystem_d);

              /* End of Outputs for SubSystem: '<S237>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S237>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S240>/Action Port'
               */
              mcb_para_IfActionSubsystem1
                (mcb_param_est_sensorless_nucl_B.Accumulate_f.Add1,
                 &mcb_param_est_sensorless_nucl_B.Merge_c5,
                 &mcb_param_est_sensorless_nucl_B.IfActionSubsystem1_b);

              /* End of Outputs for SubSystem: '<S237>/If Action Subsystem1' */
            }

            /* End of If: '<S237>/If' */

            /* Gain: '<S241>/Gain' */
            mcb_param_est_sensorless_nucl_B.Gain_p = 0.0001F *
              mcb_param_est_sensorless_nucl_B.UnitDelay1_a;

            /* UnitDelay: '<S242>/Unit Delay' */
            mcb_param_est_sensorless_nucl_B.UnitDelay_p =
              mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_j;

            /* Logic: '<S242>/NOT' */
            mcb_param_est_sensorless_nucl_B.NOT_f = true;

            /* Outputs for Enabled SubSystem: '<S242>/Accumulate' */
            mcb_param_est_se_Accumulate(true,
              mcb_param_est_sensorless_nucl_B.Gain_p,
              mcb_param_est_sensorless_nucl_B.UnitDelay_p,
              &mcb_param_est_sensorless_nucl_B.Accumulate_k,
              &mcb_param_est_sensorless__DWork.Accumulate_k);

            /* End of Outputs for SubSystem: '<S242>/Accumulate' */

            /* RelationalOperator: '<S248>/Compare' incorporates:
             *  Constant: '<S248>/Constant'
             */
            mcb_param_est_sensorless_nucl_B.Compare_k5 =
              (mcb_param_est_sensorless_nucl_B.Accumulate_k.Add1 < 0.0F);

            /* DataTypeConversion: '<S247>/Data Type Conversion' */
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_nx =
              mcb_param_est_sensorless_nucl_B.Compare_k5;

            /* If: '<S247>/If' */
            if (mcb_param_est_sensorless_nucl_B.DataTypeConversion_nx > 0) {
              /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem' incorporates:
               *  ActionPort: '<S249>/Action Port'
               */
              mcb_param_IfActionSubsystem
                (mcb_param_est_sensorless_nucl_B.Accumulate_k.Add1,
                 &mcb_param_est_sensorless_nucl_B.Merge_i,
                 &mcb_param_est_sensorless_nucl_B.IfActionSubsystem_h);

              /* End of Outputs for SubSystem: '<S247>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S247>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S250>/Action Port'
               */
              mcb_para_IfActionSubsystem1
                (mcb_param_est_sensorless_nucl_B.Accumulate_k.Add1,
                 &mcb_param_est_sensorless_nucl_B.Merge_i,
                 &mcb_param_est_sensorless_nucl_B.IfActionSubsystem1_a);

              /* End of Outputs for SubSystem: '<S247>/If Action Subsystem1' */
            }

            /* End of If: '<S247>/If' */

            /* MultiPortSwitch: '<S105>/Index Vector' */
            switch ((int32_T)mcb_param_est_sensorless_nucl_B.UnitDelay_a) {
             case 0:
              /* MultiPortSwitch: '<S105>/Index Vector' incorporates:
               *  Constant: '<S227>/Constant1'
               *  Constant: '<S227>/Constant2'
               */
              mcb_param_est_sensorless_nucl_B.IndexVector_b[0] = 0.0F;
              mcb_param_est_sensorless_nucl_B.IndexVector_b[1] = 0.0F;
              break;

             case 1:
              /* MultiPortSwitch: '<S105>/Index Vector' incorporates:
               *  Constant: '<S229>/Vq_ref'
               */
              mcb_param_est_sensorless_nucl_B.IndexVector_b[0] =
                mcb_param_est_sensorless_nucl_B.Switch_m;
              mcb_param_est_sensorless_nucl_B.IndexVector_b[1] = 0.0F;
              break;

             case 2:
              /* Gain: '<S233>/indexing' */
              mcb_param_est_sensorless_nucl_B.indexing_a = 800.0F *
                mcb_param_est_sensorless_nucl_B.Merge_c5;

              /* DataTypeConversion: '<S233>/Get_Integer' */
              mcb_param_est_sensorless_nucl_B.Get_Integer_f = (uint16_T)
                mcb_param_est_sensorless_nucl_B.indexing_a;

              /* DataTypeConversion: '<S233>/Data Type Conversion1' */
              mcb_param_est_sensorless_nucl_B.DataTypeConversion1_a =
                mcb_param_est_sensorless_nucl_B.Get_Integer_f;

              /* Sum: '<S233>/Sum2' */
              mcb_param_est_sensorless_nucl_B.Sum2_h =
                mcb_param_est_sensorless_nucl_B.indexing_a -
                mcb_param_est_sensorless_nucl_B.DataTypeConversion1_a;

              /* Sum: '<S233>/Sum' incorporates:
               *  Constant: '<S233>/offset'
               */
              pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_f + 1U;
              mcb_param_est_sensorless_nucl_B.Sum_o[0] = pinWriteLoc;

              /* Selector: '<S233>/Lookup' incorporates:
               *  Constant: '<S233>/sine_table_values'
               */
              mcb_param_est_sensorless_nucl_B.Lookup_g[0] =
                mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

              /* Sum: '<S233>/Sum' */
              pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_f;
              mcb_param_est_sensorless_nucl_B.Sum_o[1] = pinWriteLoc;

              /* Selector: '<S233>/Lookup' incorporates:
               *  Constant: '<S233>/sine_table_values'
               */
              mcb_param_est_sensorless_nucl_B.Lookup_g[1] =
                mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

              /* Sum: '<S233>/Sum' incorporates:
               *  Constant: '<S233>/offset'
               */
              pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_f + 201U;
              mcb_param_est_sensorless_nucl_B.Sum_o[2] = pinWriteLoc;

              /* Selector: '<S233>/Lookup' incorporates:
               *  Constant: '<S233>/sine_table_values'
               */
              mcb_param_est_sensorless_nucl_B.Lookup_g[2] =
                mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

              /* Sum: '<S233>/Sum' incorporates:
               *  Constant: '<S233>/offset'
               */
              pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_f + 200U;
              mcb_param_est_sensorless_nucl_B.Sum_o[3] = pinWriteLoc;

              /* Selector: '<S233>/Lookup' incorporates:
               *  Constant: '<S233>/sine_table_values'
               */
              mcb_param_est_sensorless_nucl_B.Lookup_g[3] =
                mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

              /* Sum: '<S236>/Sum3' */
              mcb_param_est_sensorless_nucl_B.Sum3_d =
                mcb_param_est_sensorless_nucl_B.Lookup_g[0] -
                mcb_param_est_sensorless_nucl_B.Lookup_g[1];

              /* Product: '<S236>/Product' */
              mcb_param_est_sensorless_nucl_B.Product_cm =
                mcb_param_est_sensorless_nucl_B.Sum3_d *
                mcb_param_est_sensorless_nucl_B.Sum2_h;

              /* Sum: '<S236>/Sum4' */
              mcb_param_est_sensorless_nucl_B.Sum4_hf =
                mcb_param_est_sensorless_nucl_B.Product_cm +
                mcb_param_est_sensorless_nucl_B.Lookup_g[1];

              /* Product: '<S231>/Product' */
              mcb_param_est_sensorless_nucl_B.Product_oe =
                mcb_param_est_sensorless_nucl_B.Sum4_hf *
                mcb_param_est_sensorless_nucl_B.UnitDelay2_g;

              /* Sum: '<S231>/Sum' */
              mcb_param_est_sensorless_nucl_B.Sum_l =
                mcb_param_est_sensorless_nucl_B.Product_oe +
                mcb_param_est_sensorless_nucl_B.Switch_m;

              /* MultiPortSwitch: '<S105>/Index Vector' incorporates:
               *  Constant: '<S228>/Constant1'
               */
              mcb_param_est_sensorless_nucl_B.IndexVector_b[0] =
                mcb_param_est_sensorless_nucl_B.Sum_l;
              mcb_param_est_sensorless_nucl_B.IndexVector_b[1] = 0.0F;
              break;

             default:
              /* Gain: '<S243>/indexing' */
              mcb_param_est_sensorless_nucl_B.indexing_k = 800.0F *
                mcb_param_est_sensorless_nucl_B.Merge_i;

              /* DataTypeConversion: '<S243>/Get_Integer' */
              mcb_param_est_sensorless_nucl_B.Get_Integer_b = (uint16_T)
                mcb_param_est_sensorless_nucl_B.indexing_k;

              /* DataTypeConversion: '<S243>/Data Type Conversion1' */
              mcb_param_est_sensorless_nucl_B.DataTypeConversion1_b =
                mcb_param_est_sensorless_nucl_B.Get_Integer_b;

              /* Sum: '<S243>/Sum2' */
              mcb_param_est_sensorless_nucl_B.Sum2_k =
                mcb_param_est_sensorless_nucl_B.indexing_k -
                mcb_param_est_sensorless_nucl_B.DataTypeConversion1_b;

              /* Sum: '<S243>/Sum' incorporates:
               *  Constant: '<S243>/offset'
               */
              pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_b + 1U;
              mcb_param_est_sensorless_nucl_B.Sum_d[0] = pinWriteLoc;

              /* Selector: '<S243>/Lookup' incorporates:
               *  Constant: '<S243>/sine_table_values'
               */
              mcb_param_est_sensorless_nucl_B.Lookup_j[0] =
                mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

              /* Sum: '<S243>/Sum' */
              pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_b;
              mcb_param_est_sensorless_nucl_B.Sum_d[1] = pinWriteLoc;

              /* Selector: '<S243>/Lookup' incorporates:
               *  Constant: '<S243>/sine_table_values'
               */
              mcb_param_est_sensorless_nucl_B.Lookup_j[1] =
                mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

              /* Sum: '<S243>/Sum' incorporates:
               *  Constant: '<S243>/offset'
               */
              pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_b + 201U;
              mcb_param_est_sensorless_nucl_B.Sum_d[2] = pinWriteLoc;

              /* Selector: '<S243>/Lookup' incorporates:
               *  Constant: '<S243>/sine_table_values'
               */
              mcb_param_est_sensorless_nucl_B.Lookup_j[2] =
                mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

              /* Sum: '<S243>/Sum' incorporates:
               *  Constant: '<S243>/offset'
               */
              pinWriteLoc = mcb_param_est_sensorless_nucl_B.Get_Integer_b + 200U;
              mcb_param_est_sensorless_nucl_B.Sum_d[3] = pinWriteLoc;

              /* Selector: '<S243>/Lookup' incorporates:
               *  Constant: '<S243>/sine_table_values'
               */
              mcb_param_est_sensorless_nucl_B.Lookup_j[3] =
                mcb_param_est_sensorless_ConstP.pooled12[(int32_T)pinWriteLoc];

              /* Sum: '<S246>/Sum3' */
              mcb_param_est_sensorless_nucl_B.Sum3_b =
                mcb_param_est_sensorless_nucl_B.Lookup_j[0] -
                mcb_param_est_sensorless_nucl_B.Lookup_j[1];

              /* Product: '<S246>/Product' */
              mcb_param_est_sensorless_nucl_B.Product_j =
                mcb_param_est_sensorless_nucl_B.Sum3_b *
                mcb_param_est_sensorless_nucl_B.Sum2_k;

              /* Sum: '<S246>/Sum4' */
              mcb_param_est_sensorless_nucl_B.Sum4_f =
                mcb_param_est_sensorless_nucl_B.Product_j +
                mcb_param_est_sensorless_nucl_B.Lookup_j[1];

              /* Product: '<S241>/Product' */
              mcb_param_est_sensorless_nucl_B.Product_g =
                mcb_param_est_sensorless_nucl_B.Sum4_f *
                mcb_param_est_sensorless_nucl_B.UnitDelay2_g;

              /* MultiPortSwitch: '<S105>/Index Vector' */
              mcb_param_est_sensorless_nucl_B.IndexVector_b[0] =
                mcb_param_est_sensorless_nucl_B.Switch_m;
              mcb_param_est_sensorless_nucl_B.IndexVector_b[1] =
                mcb_param_est_sensorless_nucl_B.Product_g;
              break;
            }

            /* End of MultiPortSwitch: '<S105>/Index Vector' */

            /* SignalConversion generated from: '<S105>/RefVq' */
            mcb_param_est_sensorless_nucl_B.OutportBufferForRefVq =
              mcb_param_est_sensorless_nucl_B.IndexVector_b[1];

            /* Update for UnitDelay: '<S232>/Unit Delay' */
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_o =
              mcb_param_est_sensorless_nucl_B.Accumulate_f.Add1;

            /* Update for UnitDelay: '<S242>/Unit Delay' */
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_j =
              mcb_param_est_sensorless_nucl_B.Accumulate_k.Add1;
          }

          /* End of Outputs for SubSystem: '<S60>/OpenLoop' */

          /* Switch: '<S60>/Switch' */
          if (mcb_param_est_sensorless_nucl_B.UnitDelay_a >= 4.0F) {
            /* Switch: '<S60>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_c[0] =
              mcb_param_est_sensorless_nucl_B.Merge_b[0];
            mcb_param_est_sensorless_nucl_B.Switch_c[1] =
              mcb_param_est_sensorless_nucl_B.Merge_b[1];
          } else {
            /* Switch: '<S60>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_c[0] =
              mcb_param_est_sensorless_nucl_B.IndexVector_b[0];
            mcb_param_est_sensorless_nucl_B.Switch_c[1] =
              mcb_param_est_sensorless_nucl_B.OutportBufferForRefVq;
          }

          /* End of Switch: '<S60>/Switch' */

          /* Outputs for Atomic SubSystem: '<S77>/Two inputs CRL' */
          mcb_param_es_TwoinputsCRL_j(mcb_param_est_sensorless_nucl_B.Switch_c[0],
            mcb_param_est_sensorless_nucl_B.Switch_c[1],
            mcb_param_est_sensorless_nucl_B.Sum4_h,
            mcb_param_est_sensorless_nucl_B.Sum6_f,
            &mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j);

          /* End of Outputs for SubSystem: '<S77>/Two inputs CRL' */

          /* Logic: '<S19>/OR' */
          mcb_param_est_sensorless_nucl_B.OR =
            (mcb_param_est_sensorless_nucl_B.DataStoreRead1_jd ||
             mcb_param_est_sensorless_nucl_B.DataStoreRead2_c);

          /* Switch: '<S19>/OpenLoop2CloseLoop' */
          if (mcb_param_est_sensorless_nucl_B.OR) {
            /* Gain: '<S262>/sqrt3_by_two' */
            mcb_param_est_sensorless_nucl_B.sqrt3_by_two = 0.866025388F *
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o2;

            /* Gain: '<S262>/one_by_two' */
            mcb_param_est_sensorless_nucl_B.one_by_two = 0.5F *
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o1;

            /* Sum: '<S262>/add_c' */
            mcb_param_est_sensorless_nucl_B.add_c = (0.0F -
              mcb_param_est_sensorless_nucl_B.one_by_two) -
              mcb_param_est_sensorless_nucl_B.sqrt3_by_two;

            /* Sum: '<S262>/add_b' */
            mcb_param_est_sensorless_nucl_B.add_b =
              mcb_param_est_sensorless_nucl_B.sqrt3_by_two -
              mcb_param_est_sensorless_nucl_B.one_by_two;

            /* MinMax: '<S259>/Min' */
            Bias = fminf(mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o1,
                         mcb_param_est_sensorless_nucl_B.add_b);
            Bias = fminf(Bias, mcb_param_est_sensorless_nucl_B.add_c);

            /* MinMax: '<S259>/Min' */
            mcb_param_est_sensorless_nucl_B.Min = Bias;

            /* MinMax: '<S259>/Max' */
            Bias = fmaxf(mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o1,
                         mcb_param_est_sensorless_nucl_B.add_b);
            Bias = fmaxf(Bias, mcb_param_est_sensorless_nucl_B.add_c);

            /* MinMax: '<S259>/Max' */
            mcb_param_est_sensorless_nucl_B.Max = Bias;

            /* Sum: '<S259>/Add' */
            mcb_param_est_sensorless_nucl_B.Add_g =
              mcb_param_est_sensorless_nucl_B.Max +
              mcb_param_est_sensorless_nucl_B.Min;

            /* Gain: '<S259>/one_by_two' */
            mcb_param_est_sensorless_nucl_B.one_by_two_b = -0.5F *
              mcb_param_est_sensorless_nucl_B.Add_g;

            /* Sum: '<S258>/Add2' */
            mcb_param_est_sensorless_nucl_B.Add2 =
              mcb_param_est_sensorless_nucl_B.one_by_two_b +
              mcb_param_est_sensorless_nucl_B.add_c;

            /* Sum: '<S258>/Add1' */
            mcb_param_est_sensorless_nucl_B.Add1_p =
              mcb_param_est_sensorless_nucl_B.add_b +
              mcb_param_est_sensorless_nucl_B.one_by_two_b;

            /* Sum: '<S258>/Add3' */
            mcb_param_est_sensorless_nucl_B.Add3 =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o1 +
              mcb_param_est_sensorless_nucl_B.one_by_two_b;

            /* Gain: '<S258>/Gain' */
            mcb_param_est_sensorless_nucl_B.Gain_a[0] = 1.15470052F *
              mcb_param_est_sensorless_nucl_B.Add3;
            mcb_param_est_sensorless_nucl_B.Gain_a[1] = 1.15470052F *
              mcb_param_est_sensorless_nucl_B.Add1_p;
            mcb_param_est_sensorless_nucl_B.Gain_a[2] = 1.15470052F *
              mcb_param_est_sensorless_nucl_B.Add2;

            /* Switch: '<S19>/OpenLoop2CloseLoop' */
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[0] =
              mcb_param_est_sensorless_nucl_B.Gain_a[0];
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[1] =
              mcb_param_est_sensorless_nucl_B.Gain_a[1];
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[2] =
              mcb_param_est_sensorless_nucl_B.Gain_a[2];
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[3] =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o1;
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[4] =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_j.algDD_o2;
          } else {
            /* Switch: '<S19>/OpenLoop2CloseLoop' */
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[0] =
              mcb_param_est_sensorless_nucl_B.Ka;
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[1] =
              mcb_param_est_sensorless_nucl_B.Kb;
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[2] =
              mcb_param_est_sensorless_nucl_B.Kc;
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[3] =
              mcb_param_est_sensorless_nucl_B.Kalpha;
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[4] =
              mcb_param_est_sensorless_nucl_B.Kbeta;
          }

          /* End of Switch: '<S19>/OpenLoop2CloseLoop' */

          /* MultiPortSwitch: '<S61>/Multiport Switch' */
          switch ((int32_T)mcb_param_est_sensorless_nucl_B.UnitDelay_a) {
           case 4:
            /* MultiPortSwitch: '<S61>/Multiport Switch' */
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[0] =
              mcb_param_est_sensorless_nucl_B.count_to_PU[0];
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[1] =
              mcb_param_est_sensorless_nucl_B.count_to_PU[1];
            break;

           case 3:
            /* MultiPortSwitch: '<S61>/Multiport Switch' */
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[0] =
              mcb_param_est_sensorless_nucl_B.Switch_c[1];
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[1] =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o2;
            break;

           case 2:
            /* MultiPortSwitch: '<S61>/Multiport Switch' */
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[0] =
              mcb_param_est_sensorless_nucl_B.Switch_c[0];
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[1] =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o1;
            break;

           case 1:
            /* MultiPortSwitch: '<S61>/Multiport Switch' */
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[0] =
              mcb_param_est_sensorless_nucl_B.Switch_c[0];
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[1] =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o1;
            break;

           default:
            /* MultiPortSwitch: '<S61>/Multiport Switch' */
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[0] =
              mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter[0];
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[1] =
              mcb_param_est_sensorless_nucl_B.AnalogtoDigitalConverter[1];
            break;
          }

          /* End of MultiPortSwitch: '<S61>/Multiport Switch' */

          /* DataStoreRead: '<S34>/Data Store Read' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead_oc =
            mcb_param_est_sensorless__DWork.speed_rated;

          /* DataStoreRead: '<S34>/Data Store Read1' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead1_f =
            mcb_param_est_sensorless__DWork.pole_pairs;

          /* Outputs for Atomic SubSystem: '<S34>/atan2' */
          mcb_param_est_sensorl_atan2(mcb_param_est_sensorless_nucl_B.Sum6[1],
            mcb_param_est_sensorless_nucl_B.Sum6[0], 2,
            &mcb_param_est_sensorless_nucl_B.atan2_e);

          /* End of Outputs for SubSystem: '<S34>/atan2' */

          /* Gain: '<S50>/SpeedToCount' */
          mcb_param_est_sensorless_nucl_B.SpeedToCount = (uint32_T)
            (4.2949673E+9F * mcb_param_est_sensorless_nucl_B.atan2_e.algDD);

          /* Delay: '<S50>/Delay' */
          if (mcb_param_est_sensorless__DWork.CircBufIdx >= 10U) {
            pinWriteLoc = mcb_param_est_sensorless__DWork.CircBufIdx - 10U;
          } else {
            pinWriteLoc = mcb_param_est_sensorless__DWork.CircBufIdx + 790U;
          }

          /* Delay: '<S50>/Delay' */
          mcb_param_est_sensorless_nucl_B.Delay =
            mcb_param_est_sensorless__DWork.Delay_DSTATE_o[pinWriteLoc];

          /* Sum: '<S50>/SpeedCount' */
          mcb_param_est_sensorless_nucl_B.SpeedCount = (int32_T)
            mcb_param_est_sensorless_nucl_B.SpeedToCount - (int32_T)
            mcb_param_est_sensorless_nucl_B.Delay;

          /* Product: '<S50>/Product' incorporates:
           *  Constant: '<S50>/2^32//2'
           *  Constant: '<S50>/DelayLength'
           *  Constant: '<S50>/SampleTime'
           */
          mcb_param_est_sensorless_nucl_B.Product_ct = 0.0001F *
            mcb_param_est_sensorless_nucl_B.DataStoreRead_oc * 2.14748365E+9F *
            10.0F;

          /* Product: '<S50>/Divide' incorporates:
           *  Constant: '<S50>/Constant'
           */
          mcb_param_est_sensorless_nucl_B.Divide = 30.0F /
            mcb_param_est_sensorless_nucl_B.Product_ct;

          /* Product: '<S50>/Product1' */
          mcb_param_est_sensorless_nucl_B.Product1_g0 = (real32_T)
            mcb_param_est_sensorless_nucl_B.SpeedCount *
            mcb_param_est_sensorless_nucl_B.Divide;

          /* Switch: '<S49>/Switch1' incorporates:
           *  Constant: '<S49>/FilterConstant'
           *  Constant: '<S49>/OneMinusFilterConstant'
           */
          mcb_param_est_sensorless_nucl_B.Switch1_c[0] = 0.02F;
          mcb_param_est_sensorless_nucl_B.Switch1_c[1] = 0.98F;

          /* Product: '<S54>/Product' */
          mcb_param_est_sensorless_nucl_B.Product_f =
            mcb_param_est_sensorless_nucl_B.Product1_g0 * 0.02F;

          /* UnitDelay: '<S54>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_l =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_c;

          /* Product: '<S54>/Product1' */
          mcb_param_est_sensorless_nucl_B.Product1_a = 0.98F *
            mcb_param_est_sensorless_nucl_B.UnitDelay_l;

          /* Sum: '<S54>/Add1' */
          mcb_param_est_sensorless_nucl_B.Add1_j =
            mcb_param_est_sensorless_nucl_B.Product_f +
            mcb_param_est_sensorless_nucl_B.Product1_a;

          /* Product: '<S34>/Divide' */
          mcb_param_est_sensorless_nucl_B.Divide_b =
            mcb_param_est_sensorless_nucl_B.Add1_j /
            mcb_param_est_sensorless_nucl_B.DataStoreRead1_f;

          /* DataStoreRead: '<S276>/Data Store Read' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead_a =
            mcb_param_est_sensorless__DWork.Vd_ref_OL;

          /* DataStoreRead: '<S276>/Data Store Read1' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead1_k =
            mcb_param_est_sensorless__DWork.freq_low;

          /* DataStoreRead: '<S276>/Data Store Read2' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead2_p =
            mcb_param_est_sensorless__DWork.freq_high;

          /* DataStoreRead: '<S276>/Data Store Read3' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead3_l =
            mcb_param_est_sensorless__DWork.freq_step;

          /* DataStoreRead: '<S276>/Data Store Read4' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead4 =
            mcb_param_est_sensorless__DWork.Vd_dc;

          /* DataStoreRead: '<S276>/Data Store Read5' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead5 =
            mcb_param_est_sensorless__DWork.Vdq_amp;

          /* DataStoreRead: '<S276>/Data Store Read6' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead6 =
            mcb_param_est_sensorless__DWork.Iq_ref_CL;

          /* DataStoreRead: '<S276>/Data Store Read7' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead7 =
            mcb_param_est_sensorless__DWork.under_voltage_limit;

          /* DataStoreRead: '<S276>/Data Store Read8' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead8 =
            mcb_param_est_sensorless__DWork.over_current_limit;

          /* DataStoreRead: '<S276>/Data Store Read9' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead9 =
            mcb_param_est_sensorless__DWork.inertia_end_speed;

          /* DataStoreRead: '<S13>/Data Store Read2' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead2_a =
            mcb_param_est_sensorless__DWork.testEnableFromHost;

          /* Product: '<S13>/Product' incorporates:
           *  Constant: '<S13>/Constant'
           */
          mcb_param_est_sensorless_nucl_B.Product_n = 0.0001F *
            mcb_param_est_sensorless_nucl_B.DataStoreRead2_a;

          /* UnitDelay: '<S279>/Unit Delay8' */
          mcb_param_est_sensorless_nucl_B.UnitDelay8 =
            mcb_param_est_sensorless__DWork.UnitDelay8_DSTATE;

          /* Switch: '<S279>/Switch' */
          if (mcb_param_est_sensorless_nucl_B.DataStoreRead2_a > 0.0F) {
            /* Switch: '<S279>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_l =
              mcb_param_est_sensorless_nucl_B.UnitDelay8;
          } else {
            /* Switch: '<S279>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_l =
              mcb_param_est_sensorless_nucl_B.DataStoreRead2_a;
          }

          /* End of Switch: '<S279>/Switch' */

          /* Sum: '<S279>/Sum' */
          mcb_param_est_sensorless_nucl_B.curTime =
            mcb_param_est_sensorless_nucl_B.Product_n +
            mcb_param_est_sensorless_nucl_B.Switch_l;

          /* DataStoreRead: '<S13>/Data Store Read' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead_ad =
            mcb_param_est_sensorless__DWork.RsMeasTestTime;

          /* DataStoreRead: '<S13>/Data Store Read3' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead3_e =
            mcb_param_est_sensorless__DWork.I_rated;

          /* DataStoreRead: '<S13>/Data Store Read4' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead4_p =
            mcb_param_est_sensorless__DWork.pole_pairs;

          /* DataStoreRead: '<S13>/Data Store Read5' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead5_p =
            mcb_param_est_sensorless__DWork.Rs;

          /* DataStoreRead: '<S13>/Data Store Read8' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead8_p =
            mcb_param_est_sensorless__DWork.Ld;

          /* DataStoreRead: '<S13>/Data Store Read7' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead7_h =
            mcb_param_est_sensorless__DWork.R_board;

          /* DataStoreRead: '<S13>/Data Store Read1' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead1_km =
            mcb_param_est_sensorless__DWork.V_rated;

          /* DataStoreRead: '<S13>/Data Store Read6' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead6_f =
            mcb_param_est_sensorless__DWork.currentPU_RWV;

          /* DataStoreRead: '<S13>/Data Store Read9' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead9_e =
            mcb_param_est_sensorless__DWork.sigma;

          /* DataStoreRead: '<S13>/inverter_V_max' */
          mcb_param_est_sensorless_nucl_B.inverter_V_max =
            mcb_param_est_sensorless__DWork.inverter_V_max;

          /* DataStoreRead: '<S13>/Data Store Read10' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead10 =
            mcb_param_est_sensorless__DWork.speed_rated;

          /* SignalConversion generated from: '<S277>/ SFunction ' incorporates:
           *  MATLAB Function: '<S13>/MATLAB Function'
           */
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[0] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead_a;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[1] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead1_k;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[2] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead2_p;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[3] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead3_l;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[4] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead4;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[5] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead5;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[6] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead6;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[7] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead7;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[8] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead8;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[9] =
            mcb_param_est_sensorless_nucl_B.DataStoreRead9;

          /* SignalConversion generated from: '<S277>/ SFunction ' incorporates:
           *  MATLAB Function: '<S13>/MATLAB Function'
           */
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[0] =
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[0];
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[1] =
            mcb_param_est_sensorless_nucl_B.MultiportSwitch[1];
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[2] =
            mcb_param_est_sensorless_nucl_B.Switch_c[0];
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[3] =
            mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o1;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[4] =
            mcb_param_est_sensorless_nucl_B.Switch_c[1];
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[5] =
            mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o2;

          /* SignalConversion generated from: '<S277>/ SFunction ' incorporates:
           *  MATLAB Function: '<S13>/MATLAB Function'
           */
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j[0] =
            mcb_param_est_sensorless_nucl_B.count_to_PU1[0];
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j[1] =
            mcb_param_est_sensorless_nucl_B.count_to_PU1[1];
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j[2] =
            mcb_param_est_sensorless_nucl_B.count_to_PU[3];

          /* MATLAB Function: '<S13>/MATLAB Function' */
          /* MATLAB Function 'Alogrithm/ParameterEstimationTests/MATLAB Function': '<S277>:1' */
          /* '<S277>:1:4' */
          if (!mcb_param_est_sensorless__DWork.voltagePU_RWV_not_empty) {
            mcb_param_est_sensorless__DWork.voltagePU_RWV =
              mcb_param_est_sensorless_nucl_B.DataStoreRead1_km / 1.73205078F;
            mcb_param_est_sensorless__DWork.voltagePU_RWV_not_empty = true;
          }

          Bias = floorf(100.0F /
                        mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI
                        [3]);
          if ((mcb_param_est_sensorless__DWork.testNum > 0.0F) &&
              (mcb_param_est_sensorless__DWork.testEnable != 0.0F)) {
            if ((fabsf
                 (mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j
                  [0]) * mcb_param_est_sensorless_nucl_B.DataStoreRead6_f >
                 mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[
                 8] * mcb_param_est_sensorless_nucl_B.DataStoreRead3_e) ||
                (fabsf
                 (mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j
                  [1]) * mcb_param_est_sensorless_nucl_B.DataStoreRead6_f >
                 mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[
                 8] * mcb_param_est_sensorless_nucl_B.DataStoreRead3_e)) {
              mcb_param_est_sensorless__DWork.flag = 15.0F;
              mcb_param_est_sensorless__DWork.errorID_m = 1.0F;
            } else if
                (mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_j[
                 2] * mcb_param_est_sensorless_nucl_B.inverter_V_max <
                 mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[
                 7] * mcb_param_est_sensorless_nucl_B.DataStoreRead1_km) {
              mcb_param_est_sensorless__DWork.flag = 15.0F;
              mcb_param_est_sensorless__DWork.errorID_m = 2.0F;
            }
          }

          switch ((int32_T)mcb_param_est_sensorless__DWork.flag) {
           case 0:
            if (mcb_param_est_sensorless_nucl_B.curTime >=
                mcb_param_est_sensorless__DWork.savedTimeInstance +
                mcb_param_est_sensorless__DWork.delay) {
              mcb_param_est_sensorless__DWork.flag =
                mcb_param_est_sensorless__DWork.flagNextVal;
              mcb_param_est_sensorless__DWork.savedTimeInstance =
                mcb_param_est_sensorless_nucl_B.curTime;
            }
            break;

           case 1:
            if (mcb_param_est_sensorless_nucl_B.curTime <
                mcb_param_est_sensorless__DWork.savedTimeInstance + 0.1F) {
              mcb_param_est_sensorless__DWork.Sig1 +=
                mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g
                [0];
              mcb_param_est_sensorless__DWork.Sig2 +=
                mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g
                [1];
            } else {
              mcb_param_est_sensorless__DWork.savedTimeInstance =
                mcb_param_est_sensorless_nucl_B.curTime;
              mcb_param_est_sensorless__DWork.flagNextVal = 2.0F;
              mcb_param_est_sensorless__DWork.delay = 0.5F;
              mcb_param_est_sensorless__DWork.flag = 0.0F;
            }
            break;

           case 2:
            mcb_param_est_sensorless__DWork.voltagePU_RWV =
              mcb_param_est_sensorless_nucl_B.DataStoreRead1_km / 1.73205078F;
            mcb_param_est_sensorless__DWork.estimatedParameter =
              mcb_param_est_sensorless__DWork.Sig1 * 0.0001F / (0.1F /
              mcb_param_est_sensorless_nucl_B.Product_n);
            mcb_param_est_sensorless__DWork.savedTimeInstance =
              mcb_param_est_sensorless_nucl_B.curTime;
            mcb_param_est_sensorless__DWork.flagNextVal = 3.0F;
            mcb_param_est_sensorless__DWork.delay = 0.5F;
            mcb_param_est_sensorless__DWork.flag = 0.0F;
            mcb_param_est_sensorless__DWork.estParIdx = 0.0F;
            break;

           case 3:
            mcb_param_est_sensorless__DWork.estimatedParameter =
              mcb_param_est_sensorless__DWork.Sig2 * 0.0001F / (0.1F /
              mcb_param_est_sensorless_nucl_B.Product_n);
            mcb_param_est_sensorless__DWork.refSignal =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[0];
            mcb_param_est_sensorless__DWork.Sig1 = 0.0F;
            mcb_param_est_sensorless__DWork.Sig2 = 0.0F;
            mcb_param_est_sensorless__DWork.savedTimeInstance =
              mcb_param_est_sensorless_nucl_B.curTime;
            mcb_param_est_sensorless__DWork.flagNextVal = 4.0F;
            mcb_param_est_sensorless__DWork.delay = 0.5F;
            mcb_param_est_sensorless__DWork.flag = 0.0F;
            mcb_param_est_sensorless__DWork.estParIdx = 1.0F;
            mcb_param_est_sensorless__DWork.testNum = 1.0F;
            break;

           case 4:
            if (mcb_param_est_sensorless_nucl_B.curTime <
                mcb_param_est_sensorless__DWork.savedTimeInstance +
                mcb_param_est_sensorless_nucl_B.DataStoreRead_ad) {
              mcb_param_est_sensorless__DWork.Sig1 +=
                mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g
                [0] * 0.001F;
              mcb_param_est_sensorless__DWork.Sig2 +=
                mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g
                [1] * 0.001F;
            } else {
              mcb_param_est_sensorless__DWork.flagNextVal = 5.0F;
              mcb_param_est_sensorless__DWork.delay = 0.1F;
              mcb_param_est_sensorless__DWork.flag = 0.0F;
              mcb_param_est_sensorless__DWork.savedTimeInstance =
                mcb_param_est_sensorless_nucl_B.curTime;
            }
            break;

           case 5:
            mcb_param_est_sensorless__DWork.Sig1 =
              mcb_param_est_sensorless__DWork.Sig1 *
              mcb_param_est_sensorless__DWork.voltagePU_RWV /
              (mcb_param_est_sensorless_nucl_B.DataStoreRead_ad * 0.001F /
               mcb_param_est_sensorless_nucl_B.Product_n);
            mcb_param_est_sensorless__DWork.Sig2 =
              mcb_param_est_sensorless__DWork.Sig2 *
              mcb_param_est_sensorless_nucl_B.DataStoreRead6_f /
              (mcb_param_est_sensorless_nucl_B.DataStoreRead_ad * 0.001F /
               mcb_param_est_sensorless_nucl_B.Product_n);
            mcb_param_est_sensorless__DWork.estimatedParameter =
              mcb_param_est_sensorless__DWork.Sig1 /
              mcb_param_est_sensorless__DWork.Sig2 -
              mcb_param_est_sensorless_nucl_B.DataStoreRead7_h;
            mcb_param_est_sensorless__DWork.estParIdx = 2.0F;
            mcb_param_est_sensorless__DWork.injFreq =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[2];
            timeInstance2 = roundf(1.0F /
              (mcb_param_est_sensorless_nucl_B.Product_n *
               mcb_param_est_sensorless__DWork.injFreq) * 0.5F);
            if (timeInstance2 < 65536.0F) {
              if (timeInstance2 >= 0.0F) {
                DataTypeConversion_a = (uint16_T)timeInstance2;
              } else {
                DataTypeConversion_a = 0U;
              }
            } else if (timeInstance2 >= 65536.0F) {
              DataTypeConversion_a = MAX_uint16_T;
            } else {
              DataTypeConversion_a = 0U;
            }

            mcb_param_est_sensorless__DWork.samplesPerHalfCycle =
              DataTypeConversion_a;
            mcb_param_est_sensorless__DWork.Sig1 = 0.0F;
            mcb_param_est_sensorless__DWork.Sig2 = 0.0F;
            mcb_param_est_sensorless__DWork.numWaves = 5.0F;
            mcb_param_est_sensorless__DWork.savedTimeInstance =
              mcb_param_est_sensorless_nucl_B.curTime;
            mcb_param_est_sensorless__DWork.flagNextVal = 6.0F;
            mcb_param_est_sensorless__DWork.delay = 0.5F;
            mcb_param_est_sensorless__DWork.flag = 0.0F;
            mcb_param_est_sensorless__DWork.refSignal =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[4];
            mcb_param_est_sensorless__DWork.refSignal1 =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[5];
            mcb_param_est_sensorless__DWork.testNum = 2.0F;
            break;

           case 6:
            timeInstance2 =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[1]
              * mcb_param_est_sensorless_nucl_B.DataStoreRead6_f;
            mcb_param_est_sensorless__DWork.Sig1 += (timeInstance2 -
              mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              mcb_param_est_sensorless__DWork.sinIdx - 1]) /
              mcb_param_est_sensorless__DWork.samplesPerHalfCycle;
            if (mcb_param_est_sensorless__DWork.count1 >=
                mcb_param_est_sensorless__DWork.numWaves) {
              mcb_param_est_sensorless__DWork.arraySine[(int32_T)
                mcb_param_est_sensorless__DWork.sinIdx - 1] = 0.0F;
            } else {
              mcb_param_est_sensorless__DWork.arraySine[(int32_T)
                mcb_param_est_sensorless__DWork.sinIdx - 1] = timeInstance2;
            }

            if (mcb_param_est_sensorless__DWork.Sig1 >
                mcb_param_est_sensorless__DWork.max) {
              mcb_param_est_sensorless__DWork.max =
                mcb_param_est_sensorless__DWork.Sig1;
            } else if (mcb_param_est_sensorless__DWork.Sig1 <
                       mcb_param_est_sensorless__DWork.min) {
              mcb_param_est_sensorless__DWork.min =
                mcb_param_est_sensorless__DWork.Sig1;
            }

            if (mcb_param_est_sensorless__DWork.sinIdx >=
                mcb_param_est_sensorless__DWork.samplesPerHalfCycle) {
              mcb_param_est_sensorless__DWork.sinIdx = 1.0F;
              if (mcb_param_est_sensorless__DWork.count1 == 0.0F) {
                mcb_param_est_sensorless__DWork.max =
                  mcb_param_est_sensorless__DWork.Sig1;
                mcb_param_est_sensorless__DWork.min =
                  mcb_param_est_sensorless__DWork.max;
              }

              mcb_param_est_sensorless__DWork.count1++;
              if (mcb_param_est_sensorless__DWork.count1 >
                  mcb_param_est_sensorless__DWork.numWaves) {
                mcb_param_est_sensorless__DWork.flagNextVal = 7.0F;
                mcb_param_est_sensorless__DWork.flag = 7.0F;
              }
            } else {
              mcb_param_est_sensorless__DWork.sinIdx++;
            }
            break;

           case 7:
            if (((mcb_param_est_sensorless__DWork.max -
                  mcb_param_est_sensorless__DWork.min) * 3.14159274F * 0.25F +
                 (mcb_param_est_sensorless__DWork.max +
                  mcb_param_est_sensorless__DWork.min) / 2.0F <
                 mcb_param_est_sensorless_nucl_B.DataStoreRead3_e) &&
                (mcb_param_est_sensorless__DWork.injFreq >
                 mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[
                 1])) {
              mcb_param_est_sensorless__DWork.flagNextVal = 6.0F;
              mcb_param_est_sensorless__DWork.injFreq -= 100.0F;
              timeInstance2 = roundf(1.0F /
                (mcb_param_est_sensorless_nucl_B.Product_n *
                 mcb_param_est_sensorless__DWork.injFreq) * 0.5F);
              if (timeInstance2 < 65536.0F) {
                if (timeInstance2 >= 0.0F) {
                  DataTypeConversion_a = (uint16_T)timeInstance2;
                } else {
                  DataTypeConversion_a = 0U;
                }
              } else if (timeInstance2 >= 65536.0F) {
                DataTypeConversion_a = MAX_uint16_T;
              } else {
                DataTypeConversion_a = 0U;
              }

              mcb_param_est_sensorless__DWork.samplesPerHalfCycle =
                DataTypeConversion_a;
            } else {
              mcb_param_est_sensorless__DWork.flagNextVal = 8.0F;
              mcb_param_est_sensorless__DWork.numWaves = 8.0F;
            }

            mcb_param_est_sensorless__DWork.delay = 0.2F;
            mcb_param_est_sensorless__DWork.flag = 0.0F;
            mcb_param_est_sensorless__DWork.savedTimeInstance =
              mcb_param_est_sensorless_nucl_B.curTime;
            mcb_param_est_sensorless__DWork.count1 = 0.0F;
            mcb_param_est_sensorless__DWork.count2 = 0.0F;
            mcb_param_est_sensorless__DWork.Sig1 = 0.0F;
            mcb_param_est_sensorless__DWork.Sig2 = 0.0F;
            mcb_param_est_sensorless__DWork.sinIdx = 1.0F;
            break;

           case 8:
            Product =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[0]
              * mcb_param_est_sensorless__DWork.voltagePU_RWV;
            timeInstance2 =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[1]
              * mcb_param_est_sensorless_nucl_B.DataStoreRead6_f;
            mcb_param_est_sensorless__DWork.Sig1 += (Product -
              mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              mcb_param_est_sensorless__DWork.sinIdx - 1]) /
              mcb_param_est_sensorless__DWork.samplesPerHalfCycle;
            mcb_param_est_sensorless__DWork.Sig2 += (timeInstance2 -
              mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              (mcb_param_est_sensorless__DWork.sinIdx + 500.0F) - 1]) /
              mcb_param_est_sensorless__DWork.samplesPerHalfCycle;
            mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              mcb_param_est_sensorless__DWork.sinIdx - 1] = Product;
            mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              (mcb_param_est_sensorless__DWork.sinIdx + 500.0F) - 1] =
              timeInstance2;
            if (mcb_param_est_sensorless__DWork.count1 > 0.0F) {
              mcb_param_est_sensorless__DWork.Sig1Mean +=
                mcb_param_est_sensorless__DWork.Sig1;
              mcb_param_est_sensorless__DWork.Sig2Mean +=
                mcb_param_est_sensorless__DWork.Sig2;
              mcb_param_est_sensorless__DWork.count2++;
            }

            if (mcb_param_est_sensorless__DWork.sinIdx >=
                mcb_param_est_sensorless__DWork.samplesPerHalfCycle) {
              mcb_param_est_sensorless__DWork.sinIdx = 1.0F;
              mcb_param_est_sensorless__DWork.count1++;
            } else {
              mcb_param_est_sensorless__DWork.sinIdx++;
            }

            if (mcb_param_est_sensorless_nucl_B.curTime >
                (mcb_param_est_sensorless__DWork.numWaves + 1.0F) * (0.5F /
                 mcb_param_est_sensorless__DWork.injFreq) +
                mcb_param_est_sensorless__DWork.savedTimeInstance) {
              mcb_param_est_sensorless__DWork.Sig1Mean /=
                mcb_param_est_sensorless__DWork.count2;
              mcb_param_est_sensorless__DWork.Sig2Mean /=
                mcb_param_est_sensorless__DWork.count2;
              mcb_param_est_sensorless__DWork.flagNextVal = 9.0F;
              mcb_param_est_sensorless__DWork.flag = 9.0F;
              mcb_param_est_sensorless__DWork.count1 = 0.0F;
              mcb_param_est_sensorless__DWork.count2 = 0.0F;
              mcb_param_est_sensorless__DWork.numWaves = 5.0F;
              mcb_param_est_sensorless__DWork.Sig1Prev =
                mcb_param_est_sensorless__DWork.Sig1;
              mcb_param_est_sensorless__DWork.Sig2Prev =
                mcb_param_est_sensorless__DWork.Sig2;
            }
            break;

           case 9:
            Product =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[0]
              * mcb_param_est_sensorless__DWork.voltagePU_RWV;
            timeInstance2 =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[1]
              * mcb_param_est_sensorless_nucl_B.DataStoreRead6_f;
            mcb_param_est_sensorless__DWork.Sig1 += (Product -
              mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              mcb_param_est_sensorless__DWork.sinIdx - 1]) /
              mcb_param_est_sensorless__DWork.samplesPerHalfCycle;
            mcb_param_est_sensorless__DWork.Sig2 += (timeInstance2 -
              mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              (mcb_param_est_sensorless__DWork.sinIdx + 500.0F) - 1]) /
              mcb_param_est_sensorless__DWork.samplesPerHalfCycle;
            mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              mcb_param_est_sensorless__DWork.sinIdx - 1] = Product;
            mcb_param_est_sensorless__DWork.arraySine[(int32_T)
              (mcb_param_est_sensorless__DWork.sinIdx + 500.0F) - 1] =
              timeInstance2;
            if (mcb_param_est_sensorless__DWork.sinIdx >=
                mcb_param_est_sensorless__DWork.samplesPerHalfCycle) {
              mcb_param_est_sensorless__DWork.sinIdx = 1.0F;
            } else {
              mcb_param_est_sensorless__DWork.sinIdx++;
            }

            if ((mcb_param_est_sensorless__DWork.Sig1 >
                 mcb_param_est_sensorless__DWork.Sig1Mean) &&
                (mcb_param_est_sensorless__DWork.Sig1Prev <
                 mcb_param_est_sensorless__DWork.Sig1Mean)) {
              mcb_param_est_sensorless__DWork.timeInstance1 =
                mcb_param_est_sensorless_nucl_B.curTime -
                (mcb_param_est_sensorless__DWork.Sig1 -
                 mcb_param_est_sensorless__DWork.Sig1Mean) /
                (mcb_param_est_sensorless__DWork.Sig1 -
                 mcb_param_est_sensorless__DWork.Sig1Prev) *
                mcb_param_est_sensorless_nucl_B.Product_n;
              mcb_param_est_sensorless__DWork.count2 = 1.0F;
            } else if ((mcb_param_est_sensorless__DWork.Sig2 >
                        mcb_param_est_sensorless__DWork.Sig2Mean) &&
                       (mcb_param_est_sensorless__DWork.Sig2Prev <
                        mcb_param_est_sensorless__DWork.Sig2Mean) &&
                       (mcb_param_est_sensorless__DWork.count2 != 0.0F)) {
              timeInstance2 = (mcb_param_est_sensorless_nucl_B.curTime -
                               (mcb_param_est_sensorless__DWork.Sig2 -
                                mcb_param_est_sensorless__DWork.Sig2Mean) /
                               (mcb_param_est_sensorless__DWork.Sig2 -
                                mcb_param_est_sensorless__DWork.Sig2Prev) *
                               mcb_param_est_sensorless_nucl_B.Product_n) - 2.0F
                * mcb_param_est_sensorless_nucl_B.Product_n;
              mcb_param_est_sensorless__DWork.PhaseDiffVal = (timeInstance2 -
                mcb_param_est_sensorless__DWork.timeInstance1) *
                mcb_param_est_sensorless__DWork.injFreq * 2.0F * 3.14159274F;
              if ((mcb_param_est_sensorless__DWork.PhaseDiffVal > 0.87266463F) ||
                  ((mcb_param_est_sensorless__DWork.PhaseDiffVal < 0.52359879F) &&
                   (mcb_param_est_sensorless__DWork.testNum == 2.0F) &&
                   (mcb_param_est_sensorless__DWork.PhaseDiffValidityLd != 0.0F)))
              {
                mcb_param_est_sensorless__DWork.PhaseDiffValidityLd = 0.0F;
              }

              if ((mcb_param_est_sensorless__DWork.PhaseDiffVal > 0.87266463F) ||
                  ((mcb_param_est_sensorless__DWork.PhaseDiffVal < 0.52359879F) &&
                   (mcb_param_est_sensorless__DWork.testNum == 3.0F) &&
                   (mcb_param_est_sensorless__DWork.PhaseDiffValidityLq != 0.0F)))
              {
                mcb_param_est_sensorless__DWork.PhaseDiffValidityLq = 0.0F;
              }

              mcb_param_est_sensorless__DWork.phaseDiffRad += (timeInstance2 -
                mcb_param_est_sensorless__DWork.timeInstance1) *
                mcb_param_est_sensorless__DWork.injFreq * 2.0F * 3.14159274F;
              mcb_param_est_sensorless__DWork.count1++;
              if (mcb_param_est_sensorless__DWork.count1 < Bias) {
                mcb_param_est_sensorless__DWork.count2 = 0.0F;
              } else {
                mcb_param_est_sensorless__DWork.estL += tanf
                  (mcb_param_est_sensorless__DWork.phaseDiffRad / Bias) *
                  (mcb_param_est_sensorless_nucl_B.DataStoreRead5_p +
                   mcb_param_est_sensorless_nucl_B.DataStoreRead7_h) /
                  (mcb_param_est_sensorless__DWork.injFreq * 2.0F * 3.14159274F);
                mcb_param_est_sensorless__DWork.injFreq +=
                  mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI
                  [3];
                timeInstance2 = roundf(1.0F /
                  (mcb_param_est_sensorless_nucl_B.Product_n *
                   mcb_param_est_sensorless__DWork.injFreq) * 0.5F);
                if (timeInstance2 < 65536.0F) {
                  if (timeInstance2 >= 0.0F) {
                    DataTypeConversion_a = (uint16_T)timeInstance2;
                  } else {
                    DataTypeConversion_a = 0U;
                  }
                } else if (timeInstance2 >= 65536.0F) {
                  DataTypeConversion_a = MAX_uint16_T;
                } else {
                  DataTypeConversion_a = 0U;
                }

                mcb_param_est_sensorless__DWork.samplesPerHalfCycle =
                  DataTypeConversion_a;
                mcb_param_est_sensorless__DWork.numWaves = 8.0F;
                mcb_param_est_sensorless__DWork.flagNextVal = 8.0F;
                mcb_param_est_sensorless__DWork.delay = 0.2F;
                mcb_param_est_sensorless__DWork.flag = 0.0F;
                mcb_param_est_sensorless__DWork.savedTimeInstance =
                  mcb_param_est_sensorless_nucl_B.curTime;
                mcb_param_est_sensorless__DWork.sinIdx = 1.0F;
                mcb_param_est_sensorless__DWork.count1 = 0.0F;
                mcb_param_est_sensorless__DWork.count2 = 0.0F;
                mcb_param_est_sensorless__DWork.phaseDiffRad = 0.0F;
                mcb_param_est_sensorless__DWork.Sig1 = 0.0F;
                mcb_param_est_sensorless__DWork.Sig2 = 0.0F;
                mcb_param_est_sensorless__DWork.Sig1Mean = 0.0F;
                mcb_param_est_sensorless__DWork.Sig2Mean = 0.0F;
                for (i = 0; i < 1000; i++) {
                  mcb_param_est_sensorless__DWork.arraySine[i] = 0.0F;
                }

                mcb_param_est_sensorless__DWork.count3++;
                if (mcb_param_est_sensorless__DWork.count3 >= Bias) {
                  mcb_param_est_sensorless__DWork.estimatedParameter =
                    mcb_param_est_sensorless__DWork.estL / Bias;
                  mcb_param_est_sensorless__DWork.estL = 0.0F;
                  if (mcb_param_est_sensorless__DWork.testNum == 2.0F) {
                    mcb_param_est_sensorless__DWork.estParIdx = 3.0F;
                    mcb_param_est_sensorless__DWork.testNum = 3.0F;
                    mcb_param_est_sensorless__DWork.flagNextVal = 6.0F;
                    mcb_param_est_sensorless__DWork.delay = 0.5F;
                    mcb_param_est_sensorless__DWork.injFreq =
                      mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI
                      [2];
                    timeInstance2 = roundf(1.0F /
                      (mcb_param_est_sensorless_nucl_B.Product_n *
                       mcb_param_est_sensorless__DWork.injFreq) * 0.5F);
                    if (timeInstance2 < 65536.0F) {
                      if (timeInstance2 >= 0.0F) {
                        DataTypeConversion_a = (uint16_T)timeInstance2;
                      } else {
                        DataTypeConversion_a = 0U;
                      }
                    } else if (timeInstance2 >= 65536.0F) {
                      DataTypeConversion_a = MAX_uint16_T;
                    } else {
                      DataTypeConversion_a = 0U;
                    }

                    mcb_param_est_sensorless__DWork.samplesPerHalfCycle =
                      DataTypeConversion_a;
                    mcb_param_est_sensorless__DWork.numWaves = 5.0F;
                  } else {
                    mcb_param_est_sensorless__DWork.estParIdx = 4.0F;
                    mcb_param_est_sensorless__DWork.flagNextVal = 10.0F;
                    mcb_param_est_sensorless__DWork.delay = 5.0F;
                    mcb_param_est_sensorless__DWork.testNum = 4.0F;
                    mcb_param_est_sensorless__DWork.refSignal = 0.9F;
                    mcb_param_est_sensorless__DWork.refSignal1 =
                      mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI
                      [6];
                    mcb_param_est_sensorless__DWork.numWaves = 60000.0F;
                    mcb_param_est_sensorless__DWork.Kp_i_d =
                      mcb_param_est_sensorless_nucl_B.DataStoreRead8_p / (2.0F *
                      mcb_param_est_sensorless_nucl_B.DataStoreRead9_e * 1.0E-6F)
                      * (mcb_param_est_sensorless_nucl_B.DataStoreRead6_f /
                         mcb_param_est_sensorless__DWork.voltagePU_RWV);
                    mcb_param_est_sensorless__DWork.Ki_i_d =
                      (mcb_param_est_sensorless_nucl_B.DataStoreRead5_p +
                       mcb_param_est_sensorless_nucl_B.DataStoreRead7_h) / (2.0F
                      * mcb_param_est_sensorless_nucl_B.DataStoreRead9_e *
                      1.0E-6F) *
                      (mcb_param_est_sensorless_nucl_B.DataStoreRead6_f /
                       mcb_param_est_sensorless__DWork.voltagePU_RWV);
                  }

                  mcb_param_est_sensorless__DWork.count3 = 0.0F;
                }
              }
            }

            mcb_param_est_sensorless__DWork.Sig1Prev =
              mcb_param_est_sensorless__DWork.Sig1;
            mcb_param_est_sensorless__DWork.Sig2Prev =
              mcb_param_est_sensorless__DWork.Sig2;
            break;

           case 10:
            mcb_param_est_sensorless__DWork.Sig1Mean +=
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[0]
              - mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g
              [1];
            mcb_param_est_sensorless__DWork.Sig2Mean +=
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[2];
            mcb_param_est_sensorless__DWork.Sig3Mean +=
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[3];
            mcb_param_est_sensorless__DWork.Sig4Mean +=
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[4];
            mcb_param_est_sensorless__DWork.Sig5Mean +=
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[5];
            mcb_param_est_sensorless__DWork.count2++;
            if (mcb_param_est_sensorless__DWork.count2 >
                mcb_param_est_sensorless__DWork.numWaves) {
              mcb_param_est_sensorless__DWork.Sig1Mean =
                mcb_param_est_sensorless__DWork.Sig1Mean *
                mcb_param_est_sensorless__DWork.voltagePU_RWV /
                mcb_param_est_sensorless__DWork.count2;
              mcb_param_est_sensorless__DWork.Sig2Mean =
                mcb_param_est_sensorless__DWork.Sig2Mean *
                mcb_param_est_sensorless__DWork.voltagePU_RWV /
                mcb_param_est_sensorless__DWork.count2;
              mcb_param_est_sensorless__DWork.Sig3Mean =
                mcb_param_est_sensorless__DWork.Sig3Mean *
                mcb_param_est_sensorless_nucl_B.DataStoreRead6_f /
                mcb_param_est_sensorless__DWork.count2;
              mcb_param_est_sensorless__DWork.Sig4Mean =
                mcb_param_est_sensorless__DWork.Sig4Mean *
                mcb_param_est_sensorless__DWork.voltagePU_RWV /
                mcb_param_est_sensorless__DWork.count2;
              mcb_param_est_sensorless__DWork.Sig5Mean =
                mcb_param_est_sensorless__DWork.Sig5Mean *
                mcb_param_est_sensorless_nucl_B.DataStoreRead6_f /
                mcb_param_est_sensorless__DWork.count2;
              mcb_param_est_sensorless__DWork.flagNextVal = 11.0F;
              mcb_param_est_sensorless__DWork.flag = 11.0F;
              mcb_param_est_sensorless__DWork.count2 = 0.0F;
              mcb_param_est_sensorless__DWork.Sig1Prev =
                (mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[
                 0] -
                 mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[
                 1]) * mcb_param_est_sensorless__DWork.voltagePU_RWV;
            }
            break;

           case 11:
            mcb_param_est_sensorless__DWork.Sig1 =
              (mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[0]
               - mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctio_g[
               1]) * mcb_param_est_sensorless__DWork.voltagePU_RWV;
            if ((mcb_param_est_sensorless__DWork.Sig1 >
                 mcb_param_est_sensorless__DWork.Sig1Mean) &&
                (mcb_param_est_sensorless__DWork.Sig1Prev <
                 mcb_param_est_sensorless__DWork.Sig1Mean)) {
              if (!(mcb_param_est_sensorless__DWork.count2 != 0.0F)) {
                mcb_param_est_sensorless__DWork.timeInstance1 =
                  mcb_param_est_sensorless_nucl_B.curTime -
                  (mcb_param_est_sensorless__DWork.Sig1 -
                   mcb_param_est_sensorless__DWork.Sig1Mean) /
                  (mcb_param_est_sensorless__DWork.Sig1 -
                   mcb_param_est_sensorless__DWork.Sig1Prev) *
                  mcb_param_est_sensorless_nucl_B.Product_n;
                mcb_param_est_sensorless__DWork.count2 = 1.0F;
              } else {
                mcb_param_est_sensorless__DWork.injFreq = 1.0F /
                  ((mcb_param_est_sensorless_nucl_B.curTime -
                    (mcb_param_est_sensorless__DWork.Sig1 -
                     mcb_param_est_sensorless__DWork.Sig1Mean) /
                    (mcb_param_est_sensorless__DWork.Sig1 -
                     mcb_param_est_sensorless__DWork.Sig1Prev) *
                    mcb_param_est_sensorless_nucl_B.Product_n) -
                   mcb_param_est_sensorless__DWork.timeInstance1);
                timeInstance2 = roundf(1.0F /
                  (mcb_param_est_sensorless_nucl_B.Product_n *
                   mcb_param_est_sensorless__DWork.injFreq) * 0.5F);
                if (timeInstance2 < 65536.0F) {
                  if (timeInstance2 >= 0.0F) {
                    DataTypeConversion_a = (uint16_T)timeInstance2;
                  } else {
                    DataTypeConversion_a = 0U;
                  }
                } else if (timeInstance2 >= 65536.0F) {
                  DataTypeConversion_a = MAX_uint16_T;
                } else {
                  DataTypeConversion_a = 0U;
                }

                mcb_param_est_sensorless__DWork.samplesPerHalfCycle =
                  DataTypeConversion_a;
                mcb_param_est_sensorless__DWork.lambda =
                  ((mcb_param_est_sensorless__DWork.Sig4Mean -
                    mcb_param_est_sensorless_nucl_B.DataStoreRead5_p *
                    mcb_param_est_sensorless__DWork.Sig5Mean) -
                   mcb_param_est_sensorless__DWork.injFreq * 2.0F * 3.14159274F *
                   (mcb_param_est_sensorless_nucl_B.DataStoreRead8_p *
                    mcb_param_est_sensorless__DWork.Sig3Mean)) /
                  (mcb_param_est_sensorless__DWork.injFreq * 2.0F * 3.14159274F);
                mcb_param_est_sensorless__DWork.estimatedParameter =
                  mcb_param_est_sensorless__DWork.injFreq * 2.0F * 3.14159274F *
                  mcb_param_est_sensorless__DWork.lambda * 1.73205078F / (60.0F *
                  mcb_param_est_sensorless__DWork.injFreq /
                  mcb_param_est_sensorless_nucl_B.DataStoreRead4_p * 0.001F);
                mcb_param_est_sensorless__DWork.estParIdx = 5.0F;
                mcb_param_est_sensorless__DWork.count2 = 0.0F;
                mcb_param_est_sensorless__DWork.Sig1 = 0.0F;
                mcb_param_est_sensorless__DWork.flagNextVal = 12.0F;
                mcb_param_est_sensorless__DWork.savedTimeInstance =
                  mcb_param_est_sensorless_nucl_B.curTime;
                mcb_param_est_sensorless__DWork.delay = 0.02F;
                mcb_param_est_sensorless__DWork.flag = 0.0F;
                mcb_param_est_sensorless__DWork.speed_radPerSec = 60.0F *
                  mcb_param_est_sensorless__DWork.injFreq /
                  mcb_param_est_sensorless_nucl_B.DataStoreRead4_p * 2.0F *
                  3.14159274F / 60.0F;
                mcb_param_est_sensorless__DWork.testEnable = 0.0F;
                mcb_param_est_sensorless__DWork.count1 =
                  mcb_param_est_sensorless_nucl_B.curTime;
              }
            }

            mcb_param_est_sensorless__DWork.Sig1Prev =
              mcb_param_est_sensorless__DWork.Sig1;
            break;

           case 12:
            if (fabsf(mcb_param_est_sensorless_nucl_B.Divide_b *
                      mcb_param_est_sensorless_nucl_B.DataStoreRead10) <
                mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI
                [9] * mcb_param_est_sensorless_nucl_B.DataStoreRead10) {
              mcb_param_est_sensorless__DWork.estimatedParameter =
                ((mcb_param_est_sensorless__DWork.Sig2Mean *
                  mcb_param_est_sensorless__DWork.Sig3Mean +
                  mcb_param_est_sensorless__DWork.Sig4Mean *
                  mcb_param_est_sensorless__DWork.Sig5Mean) * 1.5F -
                 (mcb_param_est_sensorless__DWork.Sig5Mean *
                  mcb_param_est_sensorless__DWork.Sig5Mean +
                  mcb_param_est_sensorless__DWork.Sig3Mean *
                  mcb_param_est_sensorless__DWork.Sig3Mean) * 1.5F *
                 mcb_param_est_sensorless_nucl_B.DataStoreRead5_p) /
                ((mcb_param_est_sensorless__DWork.speed_radPerSec -
                  mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI
                  [9] * mcb_param_est_sensorless_nucl_B.DataStoreRead10 * 2.0F *
                  3.14159274F / 60.0F) /
                 (mcb_param_est_sensorless_nucl_B.curTime -
                  mcb_param_est_sensorless__DWork.count1) *
                 mcb_param_est_sensorless__DWork.speed_radPerSec);
              mcb_param_est_sensorless__DWork.estParIdx = 6.0F;
              mcb_param_est_sensorless__DWork.flagNextVal = 13.0F;
              mcb_param_est_sensorless__DWork.savedTimeInstance =
                mcb_param_est_sensorless_nucl_B.curTime;
              mcb_param_est_sensorless__DWork.delay = 0.5F;
              mcb_param_est_sensorless__DWork.flag = 0.0F;
            }
            break;

           case 13:
            mcb_param_est_sensorless__DWork.estimatedParameter = 1.5F *
              mcb_param_est_sensorless_nucl_B.DataStoreRead4_p *
              (mcb_param_est_sensorless__DWork.lambda *
               mcb_param_est_sensorless__DWork.Sig5Mean) /
              mcb_param_est_sensorless__DWork.speed_radPerSec;
            mcb_param_est_sensorless__DWork.estParIdx = 7.0F;
            mcb_param_est_sensorless__DWork.flagNextVal = 14.0F;
            mcb_param_est_sensorless__DWork.savedTimeInstance =
              mcb_param_est_sensorless_nucl_B.curTime;
            mcb_param_est_sensorless__DWork.delay = 0.5F;
            mcb_param_est_sensorless__DWork.flag = 0.0F;
            break;

           case 14:
            mcb_param_est_sensorless__DWork.estimatedParameter = ldexpf
              (mcb_param_est_sensorless__DWork.PhaseDiffValidityLd, 1) +
              mcb_param_est_sensorless__DWork.PhaseDiffValidityLq;
            mcb_param_est_sensorless__DWork.estParIdx = 9.0F;
            mcb_param_est_sensorless__DWork.flagNextVal = 16.0F;
            mcb_param_est_sensorless__DWork.savedTimeInstance =
              mcb_param_est_sensorless_nucl_B.curTime;
            mcb_param_est_sensorless__DWork.delay = 0.5F;
            mcb_param_est_sensorless__DWork.flag = 0.0F;
            mcb_param_est_sensorless__DWork.testNum = 0.0F;
            break;

           case 15:
            mcb_param_est_sensorless__DWork.testEnable = 0.0F;
            mcb_param_est_sensorless__DWork.estimatedParameter =
              mcb_param_est_sensorless__DWork.errorID_m;
            mcb_param_est_sensorless__DWork.estParIdx = 8.0F;
            mcb_param_est_sensorless__DWork.flagNextVal = 16.0F;
            mcb_param_est_sensorless__DWork.delay = 0.5F;
            mcb_param_est_sensorless__DWork.flag = 0.0F;
            break;

           case 16:
            mcb_param_est_sensorless__DWork.flag = 0.0F;
            mcb_param_est_sensorless__DWork.errorID_m = 0.0F;
            mcb_param_est_sensorless__DWork.estParIdx = 20.0F;
            mcb_param_est_sensorless__DWork.phaseDiffRad = 0.0F;
            mcb_param_est_sensorless__DWork.PhaseDiffValidityLd = 1.0F;
            mcb_param_est_sensorless__DWork.PhaseDiffValidityLq = 1.0F;
            mcb_param_est_sensorless__DWork.flagNextVal = 1.0F;
            mcb_param_est_sensorless__DWork.delay = 1.0F;
            mcb_param_est_sensorless__DWork.estimatedParameter = 0.0F;
            mcb_param_est_sensorless__DWork.voltagePU_RWV =
              mcb_param_est_sensorless_nucl_B.DataStoreRead1_km / 1.73205078F;
            mcb_param_est_sensorless__DWork.Kp_i_d = 0.0F;
            mcb_param_est_sensorless__DWork.Ki_i_d = 0.0F;
            mcb_param_est_sensorless__DWork.PhaseDiffVal = 0.0F;
            mcb_param_est_sensorless__DWork.testNum = 0.0F;
            mcb_param_est_sensorless__DWork.testEnable = 1.0F;
            mcb_param_est_sensorless__DWork.injFreq =
              mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtSFunctionI[2];
            mcb_param_est_sensorless__DWork.lambda = 0.0F;
            mcb_param_est_sensorless__DWork.speed_radPerSec = 0.0F;
            mcb_param_est_sensorless__DWork.estL = 0.0F;
            mcb_param_est_sensorless__DWork.numWaves = 0.0F;
            mcb_param_est_sensorless__DWork.refSignal = 0.0F;
            mcb_param_est_sensorless__DWork.refSignal1 = 0.0F;
            mcb_param_est_sensorless__DWork.savedTimeInstance = 0.0F;
            mcb_param_est_sensorless__DWork.timeInstance1 = 0.0F;
            mcb_param_est_sensorless__DWork.samplesPerHalfCycle = 0.0F;
            mcb_param_est_sensorless__DWork.sinIdx = 1.0F;
            mcb_param_est_sensorless__DWork.count1 = 0.0F;
            mcb_param_est_sensorless__DWork.count2 = 0.0F;
            mcb_param_est_sensorless__DWork.count3 = 0.0F;
            for (i = 0; i < 1000; i++) {
              mcb_param_est_sensorless__DWork.arraySine[i] = 0.0F;
            }

            mcb_param_est_sensorless__DWork.max = 0.0F;
            mcb_param_est_sensorless__DWork.min = 0.0F;
            mcb_param_est_sensorless__DWork.Sig1 = 0.0F;
            mcb_param_est_sensorless__DWork.Sig2 = 0.0F;
            mcb_param_est_sensorless__DWork.Sig1Prev = 0.0F;
            mcb_param_est_sensorless__DWork.Sig2Prev = 0.0F;
            mcb_param_est_sensorless__DWork.Sig1Mean = 0.0F;
            mcb_param_est_sensorless__DWork.Sig2Mean = 0.0F;
            mcb_param_est_sensorless__DWork.Sig3Mean = 0.0F;
            mcb_param_est_sensorless__DWork.Sig4Mean = 0.0F;
            mcb_param_est_sensorless__DWork.Sig5Mean = 0.0F;
            break;

           default:
            /* no actions */
            break;
          }

          mcb_param_est_sensorless_nucl_B.testNumOut =
            mcb_param_est_sensorless__DWork.testNum;
          mcb_param_est_sensorless_nucl_B.injFreqOut =
            mcb_param_est_sensorless__DWork.injFreq;
          mcb_param_est_sensorless_nucl_B.refSignalOut =
            mcb_param_est_sensorless__DWork.refSignal;
          mcb_param_est_sensorless_nucl_B.refSignalOut1 =
            mcb_param_est_sensorless__DWork.refSignal1;
          mcb_param_est_sensorless_nucl_B.estimatedParameterOut =
            mcb_param_est_sensorless__DWork.estimatedParameter;
          mcb_param_est_sensorless_nucl_B.testEnableOut =
            mcb_param_est_sensorless__DWork.testEnable;
          mcb_param_est_sensorless_nucl_B.estParIdxOut =
            mcb_param_est_sensorless__DWork.estParIdx;
          mcb_param_est_sensorless_nucl_B.Kp_iOut =
            mcb_param_est_sensorless__DWork.Kp_i_d;
          mcb_param_est_sensorless_nucl_B.Ki_iOut =
            mcb_param_est_sensorless__DWork.Ki_i_d;
          mcb_param_est_sensorless_nucl_B.PhaseDiff =
            mcb_param_est_sensorless__DWork.PhaseDiffVal;

          /* DataStoreWrite: '<S13>/Data Store Write' */
          /* '<S277>:1:4' */
          mcb_param_est_sensorless__DWork.Kp_i =
            mcb_param_est_sensorless_nucl_B.Kp_iOut;

          /* DataStoreWrite: '<S13>/Data Store Write1' */
          mcb_param_est_sensorless__DWork.Ki_i =
            mcb_param_est_sensorless_nucl_B.Ki_iOut;

          /* Outputs for Triggered SubSystem: '<S13>/Triggered Subsystem' incorporates:
           *  TriggerPort: '<S278>/Trigger'
           */
          zcEvent_p = rt_R32ZCFcn(RISING_ZERO_CROSSING,
            &mcb_param_est_se_PrevZCSigState.TriggeredSubsystem_Trig_ZCE,
            (mcb_param_est_sensorless_nucl_B.testEnableOut));
          if (zcEvent_p != NO_ZCEVENT) {
            /* DataStoreWrite: '<S278>/Data Store Write1' incorporates:
             *  Constant: '<S278>/Constant'
             */
            mcb_param_est_sensorless__DWork.testEnableFromHost = 0.0F;
          }

          /* End of Outputs for SubSystem: '<S13>/Triggered Subsystem' */

          /* DataTypeConversion: '<S13>/Data Type Conversion' */
          mcb_param_est_sensorless_nucl_B.DataTypeConversion_b = (uint32_T)
            mcb_param_est_sensorless_nucl_B.estParIdxOut;

          /* UnitDelay: '<S13>/Unit Delay4' */
          mcb_param_est_sensorless_nucl_B.UnitDelay4_m =
            mcb_param_est_sensorless__DWork.UnitDelay4_DSTATE_n;

          /* Switch: '<S8>/Switch' */
          mcb_param_est_sensorless_nucl_B.Switch_fl = (uint16_T)
            (mcb_param_est_sensorless_nucl_B.Product_e != 0.0F);

          /* MATLABSystem: '<S265>/Digital Port Write' */
          portNameLoc = GPIOC;
          if (mcb_param_est_sensorless_nucl_B.Switch_fl != 0) {
            pinWriteLoc = 1024U;
            sentLength = 2048U;
            i = 4096;
          } else {
            pinWriteLoc = 0U;
            sentLength = 0U;
            i = 0;
          }

          pinWriteLoc = pinWriteLoc | sentLength | (uint32_T)i;
          LL_GPIO_SetOutputPin(portNameLoc, pinWriteLoc);
          LL_GPIO_ResetOutputPin(portNameLoc, ~pinWriteLoc & 7168U);

          /* End of MATLABSystem: '<S265>/Digital Port Write' */

          /* DataStoreRead: '<S273>/Data Store Read' */
          mcb_param_est_sensorless_nucl_B.PWM_Enable =
            mcb_param_est_sensorless__DWork.testEnableFromHost;

          /* Switch: '<S273>/Switch1' */
          if (mcb_param_est_sensorless_nucl_B.PWM_Enable >= 0.5F) {
            /* Sum: '<S273>/Add' incorporates:
             *  Constant: '<S273>/Constant'
             */
            timeInstance2 = mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[0]
              + 1.0F;
            mcb_param_est_sensorless_nucl_B.Add_k[0] = timeInstance2;

            /* Gain: '<S273>/PWM_Counter_Period' */
            timeInstance2 *= 4250.0F;
            mcb_param_est_sensorless_nucl_B.PWM_Counter_Period[0] =
              timeInstance2;

            /* DataTypeConversion: '<S273>/Data Type Conversion' */
            DataTypeConversion_a = (uint16_T)timeInstance2;
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_a[0] =
              DataTypeConversion_a;

            /* Switch: '<S273>/Switch1' */
            mcb_param_est_sensorless_nucl_B.Switch1_o[0] = DataTypeConversion_a;

            /* Sum: '<S273>/Add' incorporates:
             *  Constant: '<S273>/Constant'
             */
            timeInstance2 = mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[1]
              + 1.0F;
            mcb_param_est_sensorless_nucl_B.Add_k[1] = timeInstance2;

            /* Gain: '<S273>/PWM_Counter_Period' */
            timeInstance2 *= 4250.0F;
            mcb_param_est_sensorless_nucl_B.PWM_Counter_Period[1] =
              timeInstance2;

            /* DataTypeConversion: '<S273>/Data Type Conversion' */
            DataTypeConversion_a = (uint16_T)timeInstance2;
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_a[1] =
              DataTypeConversion_a;

            /* Switch: '<S273>/Switch1' */
            mcb_param_est_sensorless_nucl_B.Switch1_o[1] = DataTypeConversion_a;

            /* Sum: '<S273>/Add' incorporates:
             *  Constant: '<S273>/Constant'
             */
            timeInstance2 = mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[2]
              + 1.0F;
            mcb_param_est_sensorless_nucl_B.Add_k[2] = timeInstance2;

            /* Gain: '<S273>/PWM_Counter_Period' */
            timeInstance2 *= 4250.0F;
            mcb_param_est_sensorless_nucl_B.PWM_Counter_Period[2] =
              timeInstance2;

            /* DataTypeConversion: '<S273>/Data Type Conversion' */
            DataTypeConversion_a = (uint16_T)timeInstance2;
            mcb_param_est_sensorless_nucl_B.DataTypeConversion_a[2] =
              DataTypeConversion_a;

            /* Switch: '<S273>/Switch1' */
            mcb_param_est_sensorless_nucl_B.Switch1_o[2] = DataTypeConversion_a;
          } else {
            /* Switch: '<S273>/Switch1' incorporates:
             *  Constant: '<S273>/stop'
             */
            mcb_param_est_sensorless_nucl_B.Switch1_o[0] = 0.0F;
            mcb_param_est_sensorless_nucl_B.Switch1_o[1] = 0.0F;
            mcb_param_est_sensorless_nucl_B.Switch1_o[2] = 0.0F;
          }

          /* End of Switch: '<S273>/Switch1' */

          /* MATLABSystem: '<S275>/PWM Output' */
          i = (int32_T)mcb_param_est_sensorless_nucl_B.Switch1_o[0];
          pinWriteLoc = checkFrequencyAndDutyCycleLimits
            (mcb_param_est_sensorless__DWork.obj_f.TimerHandle, (uint32_T)i);
          setDutyCycleChannel1(mcb_param_est_sensorless__DWork.obj_f.TimerHandle,
                               pinWriteLoc);
          i = (int32_T)mcb_param_est_sensorless_nucl_B.Switch1_o[1];
          pinWriteLoc = checkFrequencyAndDutyCycleLimits
            (mcb_param_est_sensorless__DWork.obj_f.TimerHandle, (uint32_T)i);
          setDutyCycleChannel2(mcb_param_est_sensorless__DWork.obj_f.TimerHandle,
                               pinWriteLoc);
          i = (int32_T)mcb_param_est_sensorless_nucl_B.Switch1_o[2];
          pinWriteLoc = checkFrequencyAndDutyCycleLimits
            (mcb_param_est_sensorless__DWork.obj_f.TimerHandle, (uint32_T)i);
          setDutyCycleChannel3(mcb_param_est_sensorless__DWork.obj_f.TimerHandle,
                               pinWriteLoc);

          /* UnitDelay: '<S302>/Output' */
          mcb_param_est_sensorless_nucl_B.Output =
            mcb_param_est_sensorless__DWork.Output_DSTATE;

          /* UnitDelay: '<S286>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_j =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_e;

          /* RelationalOperator: '<S286>/Equal' */
          mcb_param_est_sensorless_nucl_B.Equal =
            (mcb_param_est_sensorless_nucl_B.UnitDelay_j !=
             mcb_param_est_sensorless_nucl_B.estimatedParameterOut);

          /* Outputs for Triggered SubSystem: '<S15>/SaveToMemory' incorporates:
           *  TriggerPort: '<S287>/Trigger'
           */
          zcEvent = (((mcb_param_est_se_PrevZCSigState.SaveToMemory_Trig_ZCE ==
                       POS_ZCSIG) != (int32_T)
                      mcb_param_est_sensorless_nucl_B.Equal) &&
                     (mcb_param_est_se_PrevZCSigState.SaveToMemory_Trig_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent) {
            /* SignalConversion generated from: '<S287>/estParIdx' */
            mcb_param_est_sensorless_nucl_B.estParIdx =
              mcb_param_est_sensorless_nucl_B.DataTypeConversion_b;

            /* SignalConversion generated from: '<S287>/estimatedParameter' */
            mcb_param_est_sensorless_nucl_B.estimatedParameter =
              mcb_param_est_sensorless_nucl_B.estimatedParameterOut;

            /* SwitchCase: '<S287>/Switch Case' */
            switch ((int32_T)mcb_param_est_sensorless_nucl_B.estParIdx) {
             case 0:
              /* Outputs for IfAction SubSystem: '<S287>/Ia_cal_val' incorporates:
               *  ActionPort: '<S292>/Action Port'
               */
              /* Gain: '<S292>/Gain' */
              mcb_param_est_sensorless_nucl_B.Gain_lx = 10000.0F *
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* DataStoreWrite: '<S292>/Data Store Write1' */
              mcb_param_est_sensorless__DWork.Ia_avg_cal =
                mcb_param_est_sensorless_nucl_B.Gain_lx;

              /* End of Outputs for SubSystem: '<S287>/Ia_cal_val' */
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S287>/Ib_cal_val' incorporates:
               *  ActionPort: '<S293>/Action Port'
               */
              /* Gain: '<S293>/Gain' */
              mcb_param_est_sensorless_nucl_B.Gain_h = 10000.0F *
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* DataStoreWrite: '<S293>/Data Store Write2' */
              mcb_param_est_sensorless__DWork.Ib_avg_cal =
                mcb_param_est_sensorless_nucl_B.Gain_h;

              /* End of Outputs for SubSystem: '<S287>/Ib_cal_val' */
              break;

             case 2:
              /* Outputs for IfAction SubSystem: '<S287>/Rs' incorporates:
               *  ActionPort: '<S298>/Action Port'
               */
              /* DataStoreWrite: '<S298>/Data Store Write2' */
              mcb_param_est_sensorless__DWork.Rs =
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* End of Outputs for SubSystem: '<S287>/Rs' */
              break;

             case 3:
              /* Outputs for IfAction SubSystem: '<S287>/Ld' incorporates:
               *  ActionPort: '<S295>/Action Port'
               */
              /* DataStoreWrite: '<S295>/Data Store Write4' */
              mcb_param_est_sensorless__DWork.Ld =
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* End of Outputs for SubSystem: '<S287>/Ld' */
              break;

             case 4:
              /* Outputs for IfAction SubSystem: '<S287>/Lq' incorporates:
               *  ActionPort: '<S296>/Action Port'
               */
              /* DataStoreWrite: '<S296>/Data Store Write3' */
              mcb_param_est_sensorless__DWork.Lq =
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* End of Outputs for SubSystem: '<S287>/Lq' */
              break;

             case 5:
              /* Outputs for IfAction SubSystem: '<S287>/Bemf' incorporates:
               *  ActionPort: '<S290>/Action Port'
               */
              /* DataStoreWrite: '<S290>/Data Store Write3' */
              mcb_param_est_sensorless__DWork.Bemf =
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* End of Outputs for SubSystem: '<S287>/Bemf' */
              break;

             case 6:
              /* Outputs for IfAction SubSystem: '<S287>/J' incorporates:
               *  ActionPort: '<S294>/Action Port'
               */
              /* DataStoreWrite: '<S294>/Data Store Write3' */
              mcb_param_est_sensorless__DWork.J =
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* End of Outputs for SubSystem: '<S287>/J' */
              break;

             case 7:
              /* Outputs for IfAction SubSystem: '<S287>/B' incorporates:
               *  ActionPort: '<S289>/Action Port'
               */
              /* DataStoreWrite: '<S289>/Data Store Write3' */
              mcb_param_est_sensorless__DWork.B =
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* End of Outputs for SubSystem: '<S287>/B' */
              break;

             case 8:
              /* Outputs for IfAction SubSystem: '<S287>/ErrorCase' incorporates:
               *  ActionPort: '<S291>/Action Port'
               */
              /* DataStoreWrite: '<S291>/Data Store Write3' */
              mcb_param_est_sensorless__DWork.errorID =
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* End of Outputs for SubSystem: '<S287>/ErrorCase' */
              break;

             case 9:
              /* Outputs for IfAction SubSystem: '<S287>/PhaseDiffValidity' incorporates:
               *  ActionPort: '<S297>/Action Port'
               */
              /* DataStoreWrite: '<S297>/Data Store Write' */
              mcb_param_est_sensorless__DWork.PhaseDiffValid =
                mcb_param_est_sensorless_nucl_B.estimatedParameter;

              /* End of Outputs for SubSystem: '<S287>/PhaseDiffValidity' */
              break;

             default:
              /* no actions */
              break;
            }

            /* End of SwitchCase: '<S287>/Switch Case' */
          }

          mcb_param_est_se_PrevZCSigState.SaveToMemory_Trig_ZCE =
            mcb_param_est_sensorless_nucl_B.Equal;

          /* End of Outputs for SubSystem: '<S15>/SaveToMemory' */

          /* UnitDelay: '<S301>/Unit Delay' */
          mcb_param_est_sensorless_nucl_B.UnitDelay_g2 =
            mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_oq;

          /* Logic: '<S301>/NOT' */
          mcb_param_est_sensorless_nucl_B.NOT_j =
            !mcb_param_est_sensorless_nucl_B.UnitDelay_g2;

          /* Switch: '<S299>/Switch' */
          if (mcb_param_est_sensorless_nucl_B.NOT_j) {
            /* Switch: '<S299>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_n =
              mcb_param_est_sensorless_nucl_B.estimatedParameter;
          } else {
            /* Switch: '<S299>/Switch' */
            mcb_param_est_sensorless_nucl_B.Switch_n = (real32_T)
              mcb_param_est_sensorless_nucl_B.estParIdx;
          }

          /* End of Switch: '<S299>/Switch' */

          /* DataStoreRead: '<S16>/Data Store Read' */
          mcb_param_est_sensorless_nucl_B.DataStoreRead_e =
            mcb_param_est_sensorless__DWork.selSig1;

          /* MultiPortSwitch: '<S16>/SelectSignal1' */
          switch ((int32_T)mcb_param_est_sensorless_nucl_B.DataStoreRead_e) {
           case 0:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.Switch_c[1];
            break;

           case 1:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.Switch_c[0];
            break;

           case 2:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.count_to_PU[3];
            break;

           case 3:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL.algDD_o2;
            break;

           case 4:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL.algDD_o1;
            break;

           case 5:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.Divide_b;
            break;

           case 6:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.atan2_n.algDD;
            break;

           case 7:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o2;
            break;

           case 8:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.TwoinputsCRL_o.algDD_o1;
            break;

           case 9:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.count_to_PU1[0];
            break;

           case 10:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.count_to_PU1[1];
            break;

           default:
            /* MultiPortSwitch: '<S16>/SelectSignal1' */
            mcb_param_est_sensorless_nucl_B.Vq =
              mcb_param_est_sensorless_nucl_B.UnitDelay4_m;
            break;
          }

          /* End of MultiPortSwitch: '<S16>/SelectSignal1' */

          /* SignalConversion generated from: '<S288>/Byte Pack' */
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtBytePackIn[0] =
            mcb_param_est_sensorless_nucl_B.Switch_n;
          mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtBytePackIn[1] =
            mcb_param_est_sensorless_nucl_B.Vq;

          /* S-Function (any2byte_svd): '<S288>/Byte Pack' */

          /* Pack: <S288>/Byte Pack */
          {
            uint32_T MW_outputPortOffset = 0U;
            uint16_T MW_inputPortWidth = 0U;

            /* Packed output data type - uint32_T */
            /* Packing the values of Input 1 */
            /* Input data type - real32_T, size - 2 */
            {
              MW_inputPortWidth = (uint16_T)2 * sizeof(real32_T);
              memcpy((void*)
                     &mcb_param_est_sensorless_nucl_B.BytePack[MW_outputPortOffset],
                     (void*)
                     &mcb_param_est_sensorless_nucl_B.TmpSignalConversionAtBytePackIn
                     [0], MW_inputPortWidth);
            }
          }

          /* If: '<S300>/If' */
          if (mcb_param_est_sensorless_nucl_B.Output == 0) {
            /* Outputs for IfAction SubSystem: '<S300>/Start' incorporates:
             *  ActionPort: '<S305>/Action Port'
             */
            /* Merge: '<S300>/Merge' incorporates:
             *  Constant: '<S305>/End'
             *  SignalConversion generated from: '<S305>/Data_out'
             */
            mcb_param_est_sensorless_nucl_B.Merge[0] = 1397969747U;

            /* SignalConversion generated from: '<S305>/Data' */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.BytePack[0];

            /* End of Outputs for SubSystem: '<S300>/Start' */
            mcb_param_est_sensorless_nucl_B.Data_fw[0] = pinWriteLoc;

            /* Outputs for IfAction SubSystem: '<S300>/Start' incorporates:
             *  ActionPort: '<S305>/Action Port'
             */
            /* Merge: '<S300>/Merge' incorporates:
             *  SignalConversion generated from: '<S305>/Data_out'
             */
            mcb_param_est_sensorless_nucl_B.Merge[1] = pinWriteLoc;

            /* SignalConversion generated from: '<S305>/Data' */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.BytePack[1];

            /* End of Outputs for SubSystem: '<S300>/Start' */
            mcb_param_est_sensorless_nucl_B.Data_fw[1] = pinWriteLoc;

            /* Outputs for IfAction SubSystem: '<S300>/Start' incorporates:
             *  ActionPort: '<S305>/Action Port'
             */
            /* Merge: '<S300>/Merge' incorporates:
             *  SignalConversion generated from: '<S305>/Data_out'
             */
            mcb_param_est_sensorless_nucl_B.Merge[2] = pinWriteLoc;

            /* Merge: '<S300>/Merge1' incorporates:
             *  Bias: '<S305>/Bias'
             */
            mcb_param_est_sensorless_nucl_B.Merge1 = 3U;

            /* End of Outputs for SubSystem: '<S300>/Start' */
          } else if (mcb_param_est_sensorless_nucl_B.Output == 599) {
            /* Outputs for IfAction SubSystem: '<S300>/End' incorporates:
             *  ActionPort: '<S304>/Action Port'
             */
            /* SignalConversion generated from: '<S304>/Data' */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.BytePack[0];

            /* End of Outputs for SubSystem: '<S300>/End' */
            mcb_param_est_sensorless_nucl_B.Data_f[0] = pinWriteLoc;

            /* Outputs for IfAction SubSystem: '<S300>/End' incorporates:
             *  ActionPort: '<S304>/Action Port'
             */
            /* Merge: '<S300>/Merge' incorporates:
             *  SignalConversion generated from: '<S304>/Data_out'
             */
            mcb_param_est_sensorless_nucl_B.Merge[0] = pinWriteLoc;

            /* SignalConversion generated from: '<S304>/Data' */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.BytePack[1];

            /* End of Outputs for SubSystem: '<S300>/End' */
            mcb_param_est_sensorless_nucl_B.Data_f[1] = pinWriteLoc;

            /* Outputs for IfAction SubSystem: '<S300>/End' incorporates:
             *  ActionPort: '<S304>/Action Port'
             */
            /* Merge: '<S300>/Merge' incorporates:
             *  Constant: '<S304>/Start'
             *  SignalConversion generated from: '<S304>/Data_out'
             */
            mcb_param_est_sensorless_nucl_B.Merge[1] = pinWriteLoc;
            mcb_param_est_sensorless_nucl_B.Merge[2] = 1162167621U;

            /* Merge: '<S300>/Merge1' incorporates:
             *  Bias: '<S304>/Bias'
             */
            mcb_param_est_sensorless_nucl_B.Merge1 = 3U;

            /* End of Outputs for SubSystem: '<S300>/End' */
          } else {
            /* Outputs for IfAction SubSystem: '<S300>/Data' incorporates:
             *  ActionPort: '<S303>/Action Port'
             */
            /* SignalConversion generated from: '<S303>/Data' */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.BytePack[0];

            /* End of Outputs for SubSystem: '<S300>/Data' */
            mcb_param_est_sensorless_nucl_B.Data[0] = pinWriteLoc;

            /* Outputs for IfAction SubSystem: '<S300>/Data' incorporates:
             *  ActionPort: '<S303>/Action Port'
             */
            /* Merge: '<S300>/Merge' incorporates:
             *  SignalConversion generated from: '<S303>/Data_out'
             */
            mcb_param_est_sensorless_nucl_B.Merge[0] = pinWriteLoc;

            /* SignalConversion generated from: '<S303>/Data' */
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.BytePack[1];

            /* End of Outputs for SubSystem: '<S300>/Data' */
            mcb_param_est_sensorless_nucl_B.Data[1] = pinWriteLoc;

            /* Outputs for IfAction SubSystem: '<S300>/Data' incorporates:
             *  ActionPort: '<S303>/Action Port'
             */
            /* Merge: '<S300>/Merge' incorporates:
             *  Constant: '<S303>/Start'
             *  SignalConversion generated from: '<S303>/Data_out'
             */
            mcb_param_est_sensorless_nucl_B.Merge[1] = pinWriteLoc;
            mcb_param_est_sensorless_nucl_B.Merge[2] = 0U;

            /* Merge: '<S300>/Merge1' incorporates:
             *  SignalConversion generated from: '<S303>/Data_width'
             */
            mcb_param_est_sensorless_nucl_B.Merge1 = 2U;

            /* End of Outputs for SubSystem: '<S300>/Data' */
          }

          /* End of If: '<S300>/If' */

          /* Outputs for Iterator SubSystem: '<S300>/While Iterator Subsystem' incorporates:
           *  WhileIterator: '<S306>/While Iterator'
           */
          s306_iter = 1;
          do {
            mcb_param_est_sensorless_nucl_B.WhileIterator = s306_iter;
            mcb_param_est_sensorless_nucl_B.IndexVector =
              mcb_param_est_sensorless_nucl_B.Merge[mcb_param_est_sensorless_nucl_B.WhileIterator
              - 1];
            pinWriteLoc = mcb_param_est_sensorless_nucl_B.IndexVector;
            MW_LPUART_TransmitUsingDMA
              (mcb_param_est_sensorless__DWork.obj_o.UARTHandle, &pinWriteLoc,
               4U, 1U, &sentLength);
            mcb_param_est_sensorless_nucl_B.Add =
              mcb_param_est_sensorless_nucl_B.Merge1 - (uint32_T)
              mcb_param_est_sensorless_nucl_B.WhileIterator;
            s306_iter++;
          } while (mcb_param_est_sensorless_nucl_B.Add != 0U);

          /* End of Outputs for SubSystem: '<S300>/While Iterator Subsystem' */

          /* Sum: '<S307>/FixPt Sum1' incorporates:
           *  Constant: '<S307>/FixPt Constant'
           */
          mcb_param_est_sensorless_nucl_B.FixPtSum1 = (uint16_T)
            (mcb_param_est_sensorless_nucl_B.Output + 1U);

          /* Switch: '<S308>/FixPt Switch' */
          if (mcb_param_est_sensorless_nucl_B.FixPtSum1 > 599) {
            /* Switch: '<S308>/FixPt Switch' incorporates:
             *  Constant: '<S308>/Constant'
             */
            mcb_param_est_sensorless_nucl_B.FixPtSwitch = 0U;
          } else {
            /* Switch: '<S308>/FixPt Switch' */
            mcb_param_est_sensorless_nucl_B.FixPtSwitch =
              mcb_param_est_sensorless_nucl_B.FixPtSum1;
          }

          /* End of Switch: '<S308>/FixPt Switch' */
          /* user code (Output function Trailer for TID4) */

          /* System '<Root>/Alogrithm' */
          LL_GPIO_ResetOutputPin(GPIOC, LL_GPIO_PIN_8);

          /* Update for UnitDelay: '<S13>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE =
            mcb_param_est_sensorless_nucl_B.testNumOut;

          /* Update for UnitDelay: '<S59>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_g =
            mcb_param_est_sensorless_nucl_B.Compare_h;

          /* Update for UnitDelay: '<S13>/Unit Delay3' */
          mcb_param_est_sensorless__DWork.UnitDelay3_DSTATE =
            mcb_param_est_sensorless_nucl_B.refSignalOut;

          /* Update for UnitDelay: '<S19>/Unit Delay3' */
          mcb_param_est_sensorless__DWork.UnitDelay3_DSTATE_i =
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[3];

          /* Update for UnitDelay: '<S19>/Unit Delay4' */
          mcb_param_est_sensorless__DWork.UnitDelay4_DSTATE =
            mcb_param_est_sensorless_nucl_B.OpenLoop2CloseLoop[4];

          /* Update for UnitDelay: '<S13>/Unit Delay9' */
          mcb_param_est_sensorless__DWork.UnitDelay9_DSTATE =
            mcb_param_est_sensorless_nucl_B.testEnableOut;

          /* Update for UnitDelay: '<S27>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_a[0] =
            mcb_param_est_sensorless_nucl_B.Add1[0];
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_a[1] =
            mcb_param_est_sensorless_nucl_B.Add1[1];

          /* Update for UnitDelay: '<S19>/Unit Delay1' */
          mcb_param_est_sensorless__DWork.UnitDelay1_DSTATE =
            mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k.algDD_o1;

          /* Update for UnitDelay: '<S19>/Unit Delay2' */
          mcb_param_est_sensorless__DWork.UnitDelay2_DSTATE =
            mcb_param_est_sensorless_nucl_B.TwophaseCRLwrap_k.algDD_o2;

          /* Update for UnitDelay: '<S31>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_d[0] =
            mcb_param_est_sensorless_nucl_B.Add1_i[0];
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_d[1] =
            mcb_param_est_sensorless_nucl_B.Add1_i[1];

          /* Update for Delay: '<S37>/Delay' */
          mcb_param_est_sensorless__DWork.Delay_DSTATE =
            mcb_param_est_sensorless_nucl_B.Sum_k;

          /* Update for UnitDelay: '<S48>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_m =
            mcb_param_est_sensorless_nucl_B.Add1_io;

          /* Update for Delay: '<S36>/Delay' */
          mcb_param_est_sensorless__DWork.Delay_DSTATE_h =
            mcb_param_est_sensorless_nucl_B.Sum_h;

          /* Update for UnitDelay: '<S43>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_b =
            mcb_param_est_sensorless_nucl_B.Add1_c;

          /* Update for UnitDelay: '<S13>/Unit Delay2' */
          mcb_param_est_sensorless__DWork.UnitDelay2_DSTATE_m =
            mcb_param_est_sensorless_nucl_B.refSignalOut1;

          /* Update for UnitDelay: '<S1>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_i =
            mcb_param_est_sensorless_nucl_B.Divide_b;

          /* Update for UnitDelay: '<S268>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_f =
            mcb_param_est_sensorless_nucl_B.Add1_k;

          /* Update for UnitDelay: '<S13>/Unit Delay1' */
          mcb_param_est_sensorless__DWork.UnitDelay1_DSTATE_m =
            mcb_param_est_sensorless_nucl_B.injFreqOut;

          /* Update for Delay: '<S50>/Delay' */
          mcb_param_est_sensorless__DWork.Delay_DSTATE_o[mcb_param_est_sensorless__DWork.CircBufIdx]
            = mcb_param_est_sensorless_nucl_B.SpeedToCount;
          if (mcb_param_est_sensorless__DWork.CircBufIdx < 799U) {
            mcb_param_est_sensorless__DWork.CircBufIdx++;
          } else {
            mcb_param_est_sensorless__DWork.CircBufIdx = 0U;
          }

          /* End of Update for Delay: '<S50>/Delay' */

          /* Update for UnitDelay: '<S54>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_c =
            mcb_param_est_sensorless_nucl_B.Add1_j;

          /* Update for UnitDelay: '<S279>/Unit Delay8' */
          mcb_param_est_sensorless__DWork.UnitDelay8_DSTATE =
            mcb_param_est_sensorless_nucl_B.curTime;

          /* Update for UnitDelay: '<S13>/Unit Delay4' */
          mcb_param_est_sensorless__DWork.UnitDelay4_DSTATE_n =
            mcb_param_est_sensorless_nucl_B.PhaseDiff;

          /* Update for UnitDelay: '<S302>/Output' */
          mcb_param_est_sensorless__DWork.Output_DSTATE =
            mcb_param_est_sensorless_nucl_B.FixPtSwitch;

          /* Update for UnitDelay: '<S286>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_e =
            mcb_param_est_sensorless_nucl_B.estimatedParameterOut;

          /* Update for UnitDelay: '<S301>/Unit Delay' */
          mcb_param_est_sensorless__DWork.UnitDelay_DSTATE_oq =
            mcb_param_est_sensorless_nucl_B.NOT_j;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S313>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
}

void mcb_param_est_sensorless_nucleo_g474re_ihm07m1_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
