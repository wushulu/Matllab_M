/*
 * File: Hallhardwaredebugslx.c
 *
 * Code generated for Simulink model 'Hallhardwaredebugslx'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Oct 18 13:52:34 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Hallhardwaredebugslx.h"
#include "rtwtypes.h"
#include "Hallhardwaredebugslx_types.h"
#include "Hallhardwaredebugslx_private.h"
#include "stm_timer_ll.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "arm_math.h"

/* Block signals (default storage) */
B_Hallhardwaredebugslx_T Hallhardwaredebugslx_B;

/* Block states (default storage) */
DW_Hallhardwaredebugslx_T Hallhardwaredebugslx_DW;

/* Real-time model */
static RT_MODEL_Hallhardwaredebugslx_T Hallhardwaredebugslx_M_;
RT_MODEL_Hallhardwaredebugslx_T *const Hallhardwaredebugslx_M =
  &Hallhardwaredebugslx_M_;

/* Forward declaration for local functions */
static void Hallhardwarede_SystemCore_setup(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallhardware_SystemCore_setup_i(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallhardware_SystemCore_setup_g(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallhardwar_SystemCore_setup_gg(stm32cube_blocks_AnalogInput__T *obj);

/* Forward declaration for local functions */
static void Hallhardwar_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ha_T *obj);
static void Hallhardwar_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_Ha_T *obj);

/*
 * Output and update for action system:
 *    '<S120>/If Action Subsystem6'
 *    '<S120>/If Action Subsystem7'
 *    '<S95>/If Action Subsystem6'
 *    '<S95>/If Action Subsystem7'
 *    '<S70>/If Action Subsystem6'
 *    '<S70>/If Action Subsystem7'
 */
void Hallhardware_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_Hallhard_T *localP)
{
  /* SignalConversion generated from: '<S127>/direction' incorporates:
   *  Constant: '<S127>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S127>/sequence_check' incorporates:
   *  Constant: '<S127>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S120>/If Action Subsystem'
 *    '<S120>/If Action Subsystem1'
 *    '<S120>/If Action Subsystem2'
 *    '<S120>/If Action Subsystem3'
 *    '<S120>/If Action Subsystem4'
 *    '<S120>/If Action Subsystem5'
 *    '<S95>/If Action Subsystem'
 *    '<S95>/If Action Subsystem1'
 *    '<S95>/If Action Subsystem2'
 *    '<S95>/If Action Subsystem3'
 *    ...
 */
void Hallhardwared_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_Hallhardw_T *localP)
{
  /* SignalConversion generated from: '<S121>/Out1' incorporates:
   *  Constant: '<S121>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S121>/Out2' incorporates:
   *  Constant: '<S121>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S118>/Valid Halls'
 *    '<S93>/Valid Halls'
 *    '<S68>/Valid Halls'
 */
void Hallhardwaredeb_ValidHalls_Init(B_ValidHalls_Hallhardwaredebu_T *localB,
  P_ValidHalls_Hallhardwaredebu_T *localP)
{
  /* SystemInitialize for Merge: '<S120>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S120>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S120>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S120>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S118>/Valid Halls'
 *    '<S93>/Valid Halls'
 *    '<S68>/Valid Halls'
 */
void Hallhardwaredebugslx_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, B_ValidHalls_Hallhardwaredebu_T *localB,
  P_ValidHalls_Hallhardwaredebu_T *localP)
{
  /* SwitchCase: '<S120>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem5' */
    break;
  }

  /* End of SwitchCase: '<S120>/Switch Case' */

  /* If: '<S120>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    Hallhardware_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    Hallhardware_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* Merge: '<S120>/Merge3' incorporates:
     *  Constant: '<S129>/Constant'
     *  SignalConversion generated from: '<S129>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem8' */
  }

  /* End of If: '<S120>/If' */

  /* SignalConversion: '<S120>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S120>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S120>/Switch' incorporates:
   *  Constant: '<S120>/Constant'
   *  RelationalOperator: '<S120>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_d;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S120>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S118>/Bad hall (glitch or wrong connection)'
 *    '<S93>/Bad hall (glitch or wrong connection)'
 *    '<S68>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnection(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S119>/inValidHall' incorporates:
   *  Constant: '<S119>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S119>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S119>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S119>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

static void Hallhardwarede_SystemCore_setup(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S117>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S117>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S117>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Hallhardware_SystemCore_setup_i(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S92>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S92>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S92>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Hallhardware_SystemCore_setup_g(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S67>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S67>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S67>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/*
 * Output and update for action system:
 *    '<S48>/Hall Value of 1'
 *    '<S48>/Hall Value of 2'
 *    '<S48>/Hall Value of 3'
 *    '<S48>/Hall Value of 4'
 *    '<S48>/Hall Value of 5'
 *    '<S48>/Hall Value of 6'
 *    '<S48>/Hall Value of 7'
 *    '<S47>/Hall Value of 1'
 *    '<S47>/Hall Value of 2'
 *    '<S47>/Hall Value of 3'
 *    ...
 */
void Hallhardwaredebugs_HallValueof1(real32_T *rty_position,
  P_HallValueof1_Hallhardwarede_T *localP)
{
  /* SignalConversion generated from: '<S58>/position' incorporates:
   *  Constant: '<S58>/Constant'
   */
  *rty_position = localP->Constant_Value;
}

static void Hallhardwar_SystemCore_setup_gg(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S14>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S14>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 3U;
  adcStructLoc.InjectedNoOfConversion = 3U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

static void Hallhardwar_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ha_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S146>/PWM Output' incorporates:
   *  MATLABSystem: '<S170>/PWM Output'
   */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S146>/PWM Output' incorporates:
   *  MATLABSystem: '<S170>/PWM Output'
   */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S146>/PWM Output' incorporates:
     *  MATLABSystem: '<S170>/PWM Output'
     */
    enableCounter(obj->TimerHandle, true);
  }
}

static void Hallhardwar_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_Ha_T *obj)
{
  UART_Type_T b;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = USART2;
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
}

/* Model step function */
void Hallhardwaredebugslx_step(void)
{
  real_T rtb_Switch4_idx_0;
  real_T rtb_Switch4_idx_1;
  real_T rtb_Switch4_idx_2;
  real32_T rtb_Pos_PU;
  real32_T rtb_RT;
  real32_T rtb_Switch_j_idx_0;
  real32_T rtb_Switch_j_idx_1;
  uint32_T sentLength;
  uint16_T rtb_Get_Integer;
  boolean_T rtb_RT1;

  /* RateTransition: '<Root>/RT' */
  rtb_RT = Hallhardwaredebugslx_B.scaleOut;

  /* RateTransition: '<Root>/Rate Transition7' */
  rtb_Pos_PU = Hallhardwaredebugslx_B.Sum;

  /* RateTransition: '<Root>/RT1' */
  rtb_RT1 = Hallhardwaredebugslx_B.Compare;

  /* Outputs for Enabled SubSystem: '<S8>/Find Offset' incorporates:
   *  EnablePort: '<S147>/Enable'
   */
  if (rtb_RT1) {
    if (!Hallhardwaredebugslx_DW.FindOffset_MODE) {
      /* InitializeConditions for Delay: '<S147>/Delay' */
      Hallhardwaredebugslx_DW.Delay_DSTATE =
        Hallhardwaredebugslx_P.Delay_InitialCondition_i;
      Hallhardwaredebugslx_DW.FindOffset_MODE = true;
    }

    /* Outputs for Enabled SubSystem: '<S147>/Subsystem' incorporates:
     *  EnablePort: '<S153>/Enable'
     */
    /* Logic: '<S147>/AND' incorporates:
     *  Constant: '<S151>/Constant'
     *  Constant: '<S152>/Constant'
     *  Delay: '<S147>/Delay'
     *  RelationalOperator: '<S151>/Compare'
     *  RelationalOperator: '<S152>/Compare'
     */
    if ((rtb_RT <= Hallhardwaredebugslx_P.CompareToConstant_const) &&
        (Hallhardwaredebugslx_DW.Delay_DSTATE >=
         Hallhardwaredebugslx_P.CompareToConstant1_const)) {
      /* Switch: '<S154>/Switch1' incorporates:
       *  Constant: '<S154>/FilterConstant'
       *  Constant: '<S154>/One'
       *  Constant: '<S154>/OneMinusFilterConstant'
       *  Constant: '<S154>/UseInputPort'
       *  Constant: '<S154>/a'
       *  Sum: '<S154>/Sum'
       */
      if (Hallhardwaredebugslx_P.UseInputPort_Value >
          Hallhardwaredebugslx_P.Switch1_Threshold) {
        rtb_Switch_j_idx_0 = Hallhardwaredebugslx_P.a_Value;
        rtb_Switch_j_idx_1 = Hallhardwaredebugslx_P.One_Value -
          Hallhardwaredebugslx_P.a_Value;
      } else {
        rtb_Switch_j_idx_0 = Hallhardwaredebugslx_P.FilterConstant_Value;
        rtb_Switch_j_idx_1 = Hallhardwaredebugslx_P.OneMinusFilterConstant_Value;
      }

      /* End of Switch: '<S154>/Switch1' */

      /* Sum: '<S157>/Add1' incorporates:
       *  Product: '<S157>/Product'
       *  Product: '<S157>/Product1'
       *  UnitDelay: '<S157>/Unit Delay'
       */
      Hallhardwaredebugslx_B.Add1_e = rtb_Pos_PU * rtb_Switch_j_idx_0 +
        rtb_Switch_j_idx_1 * Hallhardwaredebugslx_DW.UnitDelay_DSTATE;

      /* Update for UnitDelay: '<S157>/Unit Delay' */
      Hallhardwaredebugslx_DW.UnitDelay_DSTATE = Hallhardwaredebugslx_B.Add1_e;
    }

    /* End of Logic: '<S147>/AND' */
    /* End of Outputs for SubSystem: '<S147>/Subsystem' */

    /* Update for Delay: '<S147>/Delay' */
    Hallhardwaredebugslx_DW.Delay_DSTATE = rtb_RT;
  } else {
    Hallhardwaredebugslx_DW.FindOffset_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S8>/Find Offset' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  rtb_Pos_PU = floorf(Hallhardwaredebugslx_B.Add1_e);
  if (rtIsNaNF(rtb_Pos_PU) || rtIsInfF(rtb_Pos_PU)) {
    rtb_Pos_PU = 0.0F;
  } else {
    rtb_Pos_PU = fmodf(rtb_Pos_PU, 65536.0F);
  }

  /* MATLABSystem: '<Root>/UART//USART Write' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   */
  rtb_Get_Integer = (uint16_T)(rtb_Pos_PU < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-rtb_Pos_PU : (int32_T)(uint16_T)rtb_Pos_PU);
  MW_UART_TransmitUsingInterrupt(Hallhardwaredebugslx_DW.obj.UARTHandle,
    &rtb_Get_Integer, 2U, 0U, &sentLength);

  /* Gain: '<S159>/convert_pu' */
  rtb_RT *= Hallhardwaredebugslx_P.convert_pu_Gain;

  /* If: '<S159>/If' incorporates:
   *  Constant: '<S160>/Constant'
   *  RelationalOperator: '<S160>/Compare'
   */
  if (rtb_RT < Hallhardwaredebugslx_P.Constant_Value_b) {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem' incorporates:
     *  ActionPort: '<S161>/Action Port'
     */
    /* DataTypeConversion: '<S161>/Convert_uint16' */
    rtb_Pos_PU = floorf(rtb_RT);
    if (rtIsInfF(rtb_Pos_PU)) {
      rtb_Pos_PU = 0.0F;
    } else {
      rtb_Pos_PU = fmodf(rtb_Pos_PU, 65536.0F);
    }

    /* Sum: '<S161>/Sum' incorporates:
     *  DataTypeConversion: '<S161>/Convert_back'
     *  DataTypeConversion: '<S161>/Convert_uint16'
     */
    rtb_RT -= (real32_T)(rtb_Pos_PU < 0.0F ? (int32_T)(int16_T)-(int16_T)
                         (uint16_T)-rtb_Pos_PU : (int32_T)(int16_T)(uint16_T)
                         rtb_Pos_PU);

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S159>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S162>/Action Port'
     */
    /* DataTypeConversion: '<S162>/Convert_uint16' */
    rtb_Pos_PU = truncf(rtb_RT);
    if (rtIsNaNF(rtb_Pos_PU) || rtIsInfF(rtb_Pos_PU)) {
      rtb_Pos_PU = 0.0F;
    } else {
      rtb_Pos_PU = fmodf(rtb_Pos_PU, 65536.0F);
    }

    /* Sum: '<S162>/Sum' incorporates:
     *  DataTypeConversion: '<S162>/Convert_back'
     *  DataTypeConversion: '<S162>/Convert_uint16'
     */
    rtb_RT -= (real32_T)(rtb_Pos_PU < 0.0F ? (int32_T)(int16_T)-(int16_T)
                         (uint16_T)-rtb_Pos_PU : (int32_T)(int16_T)(uint16_T)
                         rtb_Pos_PU);

    /* End of Outputs for SubSystem: '<S159>/If Action Subsystem1' */
  }

  /* End of If: '<S159>/If' */

  /* Gain: '<S148>/indexing' */
  rtb_RT *= Hallhardwaredebugslx_P.indexing_Gain;

  /* DataTypeConversion: '<S148>/Get_Integer' */
  rtb_Pos_PU = truncf(rtb_RT);
  if (rtIsNaNF(rtb_Pos_PU) || rtIsInfF(rtb_Pos_PU)) {
    rtb_Pos_PU = 0.0F;
  } else {
    rtb_Pos_PU = fmodf(rtb_Pos_PU, 65536.0F);
  }

  rtb_Get_Integer = (uint16_T)(rtb_Pos_PU < 0.0F ? (int32_T)(uint16_T)-(int16_T)
    (uint16_T)-rtb_Pos_PU : (int32_T)(uint16_T)rtb_Pos_PU);

  /* End of DataTypeConversion: '<S148>/Get_Integer' */

  /* Sum: '<S148>/Sum2' incorporates:
   *  DataTypeConversion: '<S148>/Data Type Conversion1'
   */
  rtb_Pos_PU = rtb_RT - (real32_T)rtb_Get_Integer;

  /* Outputs for Atomic SubSystem: '<S163>/Two inputs CRL' */
  /* AlgorithmDescriptorDelegate generated from: '<S166>/a16' incorporates:
   *  Constant: '<S148>/offset'
   *  Constant: '<S148>/sine_table_values'
   *  Constant: '<S149>/Vd_Ref'
   *  Constant: '<S149>/Vq'
   *  Product: '<S158>/Product'
   *  Product: '<S158>/Product1'
   *  Selector: '<S148>/Lookup'
   *  Sum: '<S148>/Sum'
   *  Sum: '<S158>/Sum3'
   *  Sum: '<S158>/Sum4'
   *  Sum: '<S158>/Sum5'
   *  Sum: '<S158>/Sum6'
   */
  arm_inv_park_f32(Hallhardwaredebugslx_P.Vd_Ref_Value,
                   Hallhardwaredebugslx_P.Vq_Value, &rtb_RT, &rtb_Switch_j_idx_0,
                   (Hallhardwaredebugslx_P.sine_table_values_Value[(int32_T)
                    ((uint32_T)Hallhardwaredebugslx_P.offset_Value[0] +
                     rtb_Get_Integer)] -
                    Hallhardwaredebugslx_P.sine_table_values_Value[(int32_T)
                    ((uint32_T)Hallhardwaredebugslx_P.offset_Value[1] +
                     rtb_Get_Integer)]) * rtb_Pos_PU +
                   Hallhardwaredebugslx_P.sine_table_values_Value[(int32_T)
                   ((uint32_T)Hallhardwaredebugslx_P.offset_Value[1] +
                    rtb_Get_Integer)],
                   (Hallhardwaredebugslx_P.sine_table_values_Value[(int32_T)
                    ((uint32_T)Hallhardwaredebugslx_P.offset_Value[2] +
                     rtb_Get_Integer)] -
                    Hallhardwaredebugslx_P.sine_table_values_Value[(int32_T)
                    ((uint32_T)Hallhardwaredebugslx_P.offset_Value[3] +
                     rtb_Get_Integer)]) * rtb_Pos_PU +
                   Hallhardwaredebugslx_P.sine_table_values_Value[(int32_T)
                   ((uint32_T)Hallhardwaredebugslx_P.offset_Value[3] +
                    rtb_Get_Integer)]);

  /* End of Outputs for SubSystem: '<S163>/Two inputs CRL' */

  /* Switch: '<S164>/Switch4' incorporates:
   *  Constant: '<S164>/Constant1'
   *  Constant: '<S164>/stop'
   *  Gain: '<S164>/Gain'
   *  Gain: '<S164>/Gain1'
   *  Gain: '<S173>/Gain'
   *  Sum: '<S164>/Add'
   *  Sum: '<S173>/Add1'
   *  Sum: '<S173>/Add2'
   *  Sum: '<S173>/Add3'
   */
  if (rtb_RT1) {
    /* Gain: '<S177>/sqrt3_by_two' */
    rtb_Switch_j_idx_0 *= Hallhardwaredebugslx_P.sqrt3_by_two_Gain;

    /* Gain: '<S177>/one_by_two' */
    rtb_Switch_j_idx_1 = Hallhardwaredebugslx_P.one_by_two_Gain * rtb_RT;

    /* Gain: '<S177>/Kc' incorporates:
     *  Sum: '<S177>/add_c'
     */
    rtb_Pos_PU = ((0.0F - rtb_Switch_j_idx_1) - rtb_Switch_j_idx_0) *
      Hallhardwaredebugslx_P.Kc_Gain;

    /* Gain: '<S177>/Kb' incorporates:
     *  Sum: '<S177>/add_b'
     */
    rtb_Switch_j_idx_1 = (rtb_Switch_j_idx_0 - rtb_Switch_j_idx_1) *
      Hallhardwaredebugslx_P.Kb_Gain;

    /* Gain: '<S177>/Ka' */
    rtb_Switch_j_idx_0 = Hallhardwaredebugslx_P.Ka_Gain * rtb_RT;

    /* Gain: '<S174>/one_by_two' incorporates:
     *  MinMax: '<S174>/Max'
     *  MinMax: '<S174>/Min'
     *  Sum: '<S174>/Add'
     */
    rtb_RT = (fmaxf(fmaxf(rtb_Switch_j_idx_0, rtb_Switch_j_idx_1), rtb_Pos_PU) +
              fminf(fminf(rtb_Switch_j_idx_0, rtb_Switch_j_idx_1), rtb_Pos_PU)) *
      Hallhardwaredebugslx_P.one_by_two_Gain_j;
    rtb_Switch4_idx_0 = ((rtb_Switch_j_idx_0 + rtb_RT) *
                         Hallhardwaredebugslx_P.Gain_Gain_f *
                         Hallhardwaredebugslx_P.Gain_Gain_es +
                         Hallhardwaredebugslx_P.Constant1_Value_pw) *
      Hallhardwaredebugslx_P.Gain1_Gain;
    rtb_Switch4_idx_1 = ((rtb_Switch_j_idx_1 + rtb_RT) *
                         Hallhardwaredebugslx_P.Gain_Gain_f *
                         Hallhardwaredebugslx_P.Gain_Gain_es +
                         Hallhardwaredebugslx_P.Constant1_Value_pw) *
      Hallhardwaredebugslx_P.Gain1_Gain;
    rtb_Switch4_idx_2 = ((rtb_RT + rtb_Pos_PU) *
                         Hallhardwaredebugslx_P.Gain_Gain_f *
                         Hallhardwaredebugslx_P.Gain_Gain_es +
                         Hallhardwaredebugslx_P.Constant1_Value_pw) *
      Hallhardwaredebugslx_P.Gain1_Gain;
  } else {
    rtb_Switch4_idx_0 = Hallhardwaredebugslx_P.stop_Value;
    rtb_Switch4_idx_1 = Hallhardwaredebugslx_P.stop_Value;
    rtb_Switch4_idx_2 = Hallhardwaredebugslx_P.stop_Value;
  }

  /* End of Switch: '<S164>/Switch4' */

  /* MATLABSystem: '<S170>/PWM Output' */
  setDutyCycleInPercentageChannel1(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
    rtb_Switch4_idx_0);
  setDutyCycleInPercentageChannel2(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
    rtb_Switch4_idx_1);
  setDutyCycleInPercentageChannel3(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
    rtb_Switch4_idx_2);

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.001, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  Hallhardwaredebugslx_M->Timing.clockTick0++;
}

/* Model initialize function */
void Hallhardwaredebugslx_initialize(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  Hallhardwaredebugslx_DW.GlobalHallState =
    Hallhardwaredebugslx_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  Hallhardwaredebugslx_DW.Timercntprev =
    Hallhardwaredebugslx_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  Hallhardwaredebugslx_DW.HallCcapture =
    Hallhardwaredebugslx_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  Hallhardwaredebugslx_DW.Timehall =
    Hallhardwaredebugslx_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  Hallhardwaredebugslx_DW.GlobalDirection =
    Hallhardwaredebugslx_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  Hallhardwaredebugslx_DW.GlobalSpeedCount =
    Hallhardwaredebugslx_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  Hallhardwaredebugslx_DW.GlobalSpeedValidity =
    Hallhardwaredebugslx_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  Hallhardwaredebugslx_DW.HallStateChangeFlag =
    Hallhardwaredebugslx_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  Hallhardwaredebugslx_DW.HallBcapture =
    Hallhardwaredebugslx_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  Hallhardwaredebugslx_DW.HallAcapture =
    Hallhardwaredebugslx_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  Hallhardwaredebugslx_DW.Enable =
    Hallhardwaredebugslx_P.DataStoreMemory9_InitialValue;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */
  /* System initialize for function-call system: '<Root>/ADC SIC' */
  Hallhardwaredebugslx_M->Timing.clockTick4 =
    Hallhardwaredebugslx_M->Timing.clockTick0;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_DSTATE =
    Hallhardwaredebugslx_P.DiscreteTimeIntegrator_IC;
  Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for Delay: '<S30>/validityDelay' */
  Hallhardwaredebugslx_DW.validityDelay_DSTATE =
    Hallhardwaredebugslx_P.validityDelay_InitialCondition;

  /* InitializeConditions for RelationalOperator: '<S35>/Compare' incorporates:
   *  Delay: '<S31>/Delay One Step1'
   */
  Hallhardwaredebugslx_DW.DelayOneStep1_DSTATE =
    Hallhardwaredebugslx_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Delay: '<S31>/Delay One Step' */
  Hallhardwaredebugslx_DW.DelayOneStep_DSTATE =
    Hallhardwaredebugslx_P.SoftwareWatchdogTimer_maxCount;

  /* InitializeConditions for Delay: '<S30>/speedCountDelay' */
  Hallhardwaredebugslx_DW.speedCountDelay_DSTATE =
    Hallhardwaredebugslx_P.speedCountDelay_InitialConditio;

  /* SystemInitialize for IfAction SubSystem: '<S29>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for Enabled SubSystem: '<S33>/Subsystem1' */
  /* SystemInitialize for Merge: '<S46>/Merge' */
  Hallhardwaredebugslx_B.Merge = Hallhardwaredebugslx_P.Merge_InitialOutput;

  /* End of SystemInitialize for SubSystem: '<S33>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S29>/Speed and direction are valid Use speed to extrapolate position' */

  /* SystemInitialize for Enabled SubSystem: '<S12>/PosGen' */
  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
  Hallhardwaredebugslx_DW.UnitDelay_DSTATE_e =
    Hallhardwaredebugslx_P.UnitDelay_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S22>/If Action Subsystem2' */
  /* InitializeConditions for Saturate: '<S25>/Saturate to 'motor.calibSpeed' RPM' incorporates:
   *  Delay: '<S25>/Delay'
   */
  Hallhardwaredebugslx_DW.Delay_DSTATE_f =
    Hallhardwaredebugslx_P.Delay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S22>/If Action Subsystem2' */

  /* SystemInitialize for Enabled SubSystem: '<S26>/Accumulate' */
  /* InitializeConditions for Delay: '<S27>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE_k =
    Hallhardwaredebugslx_P.Delay_InitialCondition_no;

  /* SystemInitialize for Enabled SubSystem: '<S27>/Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S28>/Input' incorporates:
   *  Outport: '<S28>/Out1'
   */
  Hallhardwaredebugslx_B.Input = Hallhardwaredebugslx_P.Out1_Y0_l;

  /* End of SystemInitialize for SubSystem: '<S27>/Subsystem' */

  /* SystemInitialize for Sum: '<S27>/Add1' incorporates:
   *  Outport: '<S27>/theta_e'
   */
  Hallhardwaredebugslx_B.Add1_n = Hallhardwaredebugslx_P.theta_e_Y0;

  /* End of SystemInitialize for SubSystem: '<S26>/Accumulate' */

  /* SystemInitialize for Enabled SubSystem: '<S17>/Up Counter' */
  /* InitializeConditions for Delay: '<S23>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE_n =
    Hallhardwaredebugslx_P.Delay_InitialCondition_p;

  /* SystemInitialize for Sum: '<S23>/Add1' incorporates:
   *  Outport: '<S23>/Count'
   */
  Hallhardwaredebugslx_B.Add1 = Hallhardwaredebugslx_P.Count_Y0;

  /* End of SystemInitialize for SubSystem: '<S17>/Up Counter' */

  /* SystemInitialize for Gain: '<S26>/scaleOut' incorporates:
   *  Outport: '<S17>/Theta'
   */
  Hallhardwaredebugslx_B.scaleOut = Hallhardwaredebugslx_P.Theta_Y0;

  /* SystemInitialize for RelationalOperator: '<S20>/Compare' incorporates:
   *  Outport: '<S17>/EnPWM'
   */
  Hallhardwaredebugslx_B.Compare = Hallhardwaredebugslx_P.EnPWM_Y0;

  /* End of SystemInitialize for SubSystem: '<S12>/PosGen' */

  /* Start for MATLABSystem: '<S14>/Analog to Digital Converter' */
  Hallhardwaredebugslx_DW.obj_g.isInitialized = 0;
  Hallhardwaredebugslx_DW.obj_g.matlabCodegenIsDeleted = false;
  Hallhardwar_SystemCore_setup_gg(&Hallhardwaredebugslx_DW.obj_g);

  /* SystemInitialize for Sum: '<S18>/Sum' incorporates:
   *  Outport: '<S1>/Posdegree'
   */
  Hallhardwaredebugslx_B.Sum = Hallhardwaredebugslx_P.Posdegree_Y0;

  /* SystemInitialize for Enabled SubSystem: '<S8>/Find Offset' */
  /* InitializeConditions for Delay: '<S147>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE =
    Hallhardwaredebugslx_P.Delay_InitialCondition_i;

  /* SystemInitialize for Enabled SubSystem: '<S147>/Subsystem' */
  /* InitializeConditions for UnitDelay: '<S157>/Unit Delay' */
  Hallhardwaredebugslx_DW.UnitDelay_DSTATE =
    Hallhardwaredebugslx_P.UnitDelay_InitialCondition_i;

  /* SystemInitialize for Sum: '<S157>/Add1' incorporates:
   *  Outport: '<S153>/Offset'
   */
  Hallhardwaredebugslx_B.Add1_e = Hallhardwaredebugslx_P.Offset_Y0;

  /* End of SystemInitialize for SubSystem: '<S147>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S8>/Find Offset' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HC'
   */
  /* System initialize for function-call system: '<Root>/HC' */

  /* InitializeConditions for Delay: '<S117>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE_mw =
    Hallhardwaredebugslx_P.Delay_InitialCondition_l;

  /* SystemInitialize for IfAction SubSystem: '<S118>/Valid Halls' */
  Hallhardwaredeb_ValidHalls_Init(&Hallhardwaredebugslx_B.ValidHalls,
    &Hallhardwaredebugslx_P.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S118>/Valid Halls' */

  /* Start for MATLABSystem: '<S117>/Timer' */
  Hallhardwaredebugslx_DW.obj_etd.isInitialized = 0;
  Hallhardwaredebugslx_DW.obj_etd.matlabCodegenIsDeleted = false;
  Hallhardwarede_SystemCore_setup(&Hallhardwaredebugslx_DW.obj_etd);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HB'
   */
  /* System initialize for function-call system: '<Root>/HB' */

  /* InitializeConditions for Delay: '<S92>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE_b =
    Hallhardwaredebugslx_P.Delay_InitialCondition_j;

  /* SystemInitialize for IfAction SubSystem: '<S93>/Valid Halls' */
  Hallhardwaredeb_ValidHalls_Init(&Hallhardwaredebugslx_B.ValidHalls_f,
    &Hallhardwaredebugslx_P.ValidHalls_f);

  /* End of SystemInitialize for SubSystem: '<S93>/Valid Halls' */

  /* Start for MATLABSystem: '<S92>/Timer' */
  Hallhardwaredebugslx_DW.obj_et.isInitialized = 0;
  Hallhardwaredebugslx_DW.obj_et.matlabCodegenIsDeleted = false;
  Hallhardware_SystemCore_setup_i(&Hallhardwaredebugslx_DW.obj_et);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HA'
   */
  /* System initialize for function-call system: '<Root>/HA' */

  /* InitializeConditions for Delay: '<S67>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE_m =
    Hallhardwaredebugslx_P.Delay_InitialCondition_n;

  /* SystemInitialize for IfAction SubSystem: '<S68>/Valid Halls' */
  Hallhardwaredeb_ValidHalls_Init(&Hallhardwaredebugslx_B.ValidHalls_i,
    &Hallhardwaredebugslx_P.ValidHalls_i);

  /* End of SystemInitialize for SubSystem: '<S68>/Valid Halls' */

  /* Start for MATLABSystem: '<S67>/Timer' */
  Hallhardwaredebugslx_DW.obj_e.isInitialized = 0;
  Hallhardwaredebugslx_DW.obj_e.matlabCodegenIsDeleted = false;
  Hallhardware_SystemCore_setup_g(&Hallhardwaredebugslx_DW.obj_e);

  /* SystemInitialize for Atomic SubSystem: '<Root>/Parameters' */
  /* Start for MATLABSystem: '<S146>/PWM Output' */
  Hallhardwaredebugslx_DW.obj_m.matlabCodegenIsDeleted = false;
  Hallhardwaredebugslx_DW.obj_m.isSetupComplete = false;
  Hallhardwaredebugslx_DW.obj_m.isInitialized = 1;
  Hallhardwar_PWMOutput_setupImpl(&Hallhardwaredebugslx_DW.obj_m);
  Hallhardwaredebugslx_DW.obj_m.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Parameters' */

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  Hallhardwaredebugslx_DW.obj.matlabCodegenIsDeleted = false;
  Hallhardwaredebugslx_DW.obj.isSetupComplete = false;
  Hallhardwaredebugslx_DW.obj.isInitialized = 1;
  Hallhardwar_UARTWrite_setupImpl(&Hallhardwaredebugslx_DW.obj);
  Hallhardwaredebugslx_DW.obj.isSetupComplete = true;

  /* Start for MATLABSystem: '<S170>/PWM Output' */
  Hallhardwaredebugslx_DW.obj_h.matlabCodegenIsDeleted = false;
  Hallhardwaredebugslx_DW.obj_h.isSetupComplete = false;
  Hallhardwaredebugslx_DW.obj_h.isInitialized = 1;
  Hallhardwar_PWMOutput_setupImpl(&Hallhardwaredebugslx_DW.obj_h);
  Hallhardwaredebugslx_DW.obj_h.isSetupComplete = true;

  /* Outputs for Atomic SubSystem: '<Root>/Parameters' */
  /* MATLABSystem: '<S146>/PWM Output' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  setDutyCycleInPercentageChannel1(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
    Hallhardwaredebugslx_P.Constant1_Value_a);
  setDutyCycleInPercentageChannel2(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
    Hallhardwaredebugslx_P.Constant1_Value_a);
  setDutyCycleInPercentageChannel3(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
    Hallhardwaredebugslx_P.Constant1_Value_a);

  /* End of Outputs for SubSystem: '<Root>/Parameters' */
  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */
  /* Enable for function-call system: '<Root>/ADC SIC' */
  Hallhardwaredebugslx_M->Timing.clockTick4 =
    Hallhardwaredebugslx_M->Timing.clockTick0;
  Hallhardwaredebugslx_DW.ADCSIC_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */
}

/* Model terminate function */
void Hallhardwaredebugslx_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */
  /* Termination for function-call system: '<Root>/ADC SIC' */

  /* Terminate for MATLABSystem: '<S14>/Analog to Digital Converter' */
  if (!Hallhardwaredebugslx_DW.obj_g.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_g.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_g.isSetupComplete) {
      ADC_Handle_Deinit(Hallhardwaredebugslx_DW.obj_g.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<Root>/UART//USART Write' */
  if (!Hallhardwaredebugslx_DW.obj.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj.isSetupComplete) {
      MW_UART_DeInit(Hallhardwaredebugslx_DW.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/UART//USART Write' */

  /* Terminate for MATLABSystem: '<S170>/PWM Output' */
  if (!Hallhardwaredebugslx_DW.obj_h.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_h.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_h.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_h.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_h.TimerHandle, 0);
      disableTimerChannel1(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S170>/PWM Output' */
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HC'
   */
  /* Termination for function-call system: '<Root>/HC' */

  /* Terminate for MATLABSystem: '<S117>/Timer' */
  if (!Hallhardwaredebugslx_DW.obj_etd.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_etd.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_etd.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_etd.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_etd.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_etd.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S117>/Timer' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HB'
   */
  /* Termination for function-call system: '<Root>/HB' */

  /* Terminate for MATLABSystem: '<S92>/Timer' */
  if (!Hallhardwaredebugslx_DW.obj_et.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_et.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_et.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_et.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_et.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_et.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S92>/Timer' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HA'
   */
  /* Termination for function-call system: '<Root>/HA' */

  /* Terminate for MATLABSystem: '<S67>/Timer' */
  if (!Hallhardwaredebugslx_DW.obj_e.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_e.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_e.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_e.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S67>/Timer' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

  /* Terminate for Atomic SubSystem: '<Root>/Parameters' */
  /* Terminate for MATLABSystem: '<S146>/PWM Output' */
  if (!Hallhardwaredebugslx_DW.obj_m.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_m.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_m.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_m.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_m.TimerHandle, 0);
      disableTimerChannel1(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S146>/PWM Output' */
  /* End of Terminate for SubSystem: '<Root>/Parameters' */
}

void Hallhardwaredebugslx_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(55,&EXTI15_10_IRQHandler,2);
  MW_NVIC_EnableIRQ(55);
}

/* Hardware Interrupt Block: '<S141>/Hardware Interrupt' */
void EXTI15_10_IRQHandler(void)
{
  uint32_T priority_mask;
  priority_mask = MW_HWI_MaskInterrupt();

  /* Event: EXTI12 Event */
  /* Check event EXTI12 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_12)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_12)))) {
    /* Clear occurred EXTI12 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_12);
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HC' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;

          /* MATLABSystem: '<S117>/Timer' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           */
          Hallhardwaredebugslx_DW.Timercntprev = getTimerCounterValue
            (Hallhardwaredebugslx_DW.obj_etd.TimerHandle);

          /* MATLABSystem: '<S135>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S137>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S139>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S116>/Sum' incorporates:
           *  Gain: '<S116>/Gain'
           *  Gain: '<S116>/Gain1'
           *  Gain: '<S116>/Gain2'
           *  MATLABSystem: '<S135>/Digital Port Read'
           *  MATLABSystem: '<S137>/Digital Port Read'
           *  MATLABSystem: '<S139>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Hallhardwaredebugslx_P.Gain_Gain_ea >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? Hallhardwaredebugslx_P.Gain1_Gain_e >>
             6 : 0)) + (uint32_T)((pinReadLoc_e & 4096U) != 0U ?
            Hallhardwaredebugslx_P.Gain2_Gain >> 7 : 0));

          /* SwitchCase: '<S115>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S115>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S118>/Valid Halls' incorporates:
             *  ActionPort: '<S120>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S115>/Data Type Conversion2'
             */
            Hallhardwaredebugslx_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              Hallhardwaredebugslx_DW.GlobalHallState,
              Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
              &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
              &Hallhardwaredebugslx_B.ValidHalls,
              &Hallhardwaredebugslx_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S118>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S118>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S119>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
               &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
               &Hallhardwaredebugslx_P.Badhallglitchorwrongconnectio_h);

            /* End of Outputs for SubSystem: '<S118>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S115>/Detects if the halls reading is valid' */

          /* Gain: '<S4>/Gain' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  DataTypeConversion: '<S117>/Data Type Conversion'
           *  DataTypeConversion: '<S117>/Data Type Conversion1'
           *  Delay: '<S117>/Delay'
           *  Sum: '<S117>/Sum'
           */
          Hallhardwaredebugslx_DW.Timehall = (int64_T)((int32_T)
            Hallhardwaredebugslx_DW.Timercntprev - (int32_T)
            Hallhardwaredebugslx_DW.Delay_DSTATE_mw) *
            Hallhardwaredebugslx_P.Gain_Gain;

          /* DataTypeConversion: '<S115>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  Gain: '<S4>/Gain'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedCount = (uint32_T)
            (Hallhardwaredebugslx_DW.Timehall >> 30);

          /* DataTypeConversion: '<S118>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S115>/Constant'
           */
          Hallhardwaredebugslx_DW.HallStateChangeFlag =
            Hallhardwaredebugslx_P.Constant_Value_d;

          /* DataStoreWrite: '<S4>/Data Store Write6' */
          Hallhardwaredebugslx_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S4>/Data Store Write5' incorporates:
           *  Constant: '<S4>/Constant1'
           */
          Hallhardwaredebugslx_DW.HallCcapture =
            Hallhardwaredebugslx_P.Constant1_Value;

          /* Update for Delay: '<S117>/Delay' incorporates:
           *  DataStoreRead: '<S117>/Data Store Read1'
           */
          Hallhardwaredebugslx_DW.Delay_DSTATE_mw =
            Hallhardwaredebugslx_DW.Timercntprev;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */
      }
    }
  }

  /* Event: EXTI11 Event */
  /* Check event EXTI11 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_11)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_11)))) {
    /* Clear occurred EXTI11 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_11);
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HB' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;

          /* MATLABSystem: '<S92>/Timer' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           */
          Hallhardwaredebugslx_DW.Timercntprev = getTimerCounterValue
            (Hallhardwaredebugslx_DW.obj_et.TimerHandle);

          /* MATLABSystem: '<S110>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S112>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S114>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S91>/Sum' incorporates:
           *  Gain: '<S91>/Gain'
           *  Gain: '<S91>/Gain1'
           *  Gain: '<S91>/Gain2'
           *  MATLABSystem: '<S110>/Digital Port Read'
           *  MATLABSystem: '<S112>/Digital Port Read'
           *  MATLABSystem: '<S114>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Hallhardwaredebugslx_P.Gain_Gain_n >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? Hallhardwaredebugslx_P.Gain1_Gain_et
             >> 6 : 0)) + (uint32_T)((pinReadLoc_e & 4096U) != 0U ?
            Hallhardwaredebugslx_P.Gain2_Gain_g >> 7 : 0));

          /* SwitchCase: '<S90>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S90>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S93>/Valid Halls' incorporates:
             *  ActionPort: '<S95>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S90>/Data Type Conversion2'
             */
            Hallhardwaredebugslx_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              Hallhardwaredebugslx_DW.GlobalHallState,
              Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
              &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
              &Hallhardwaredebugslx_B.ValidHalls_f,
              &Hallhardwaredebugslx_P.ValidHalls_f);

            /* End of Outputs for SubSystem: '<S93>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S93>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S94>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
               &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
               &Hallhardwaredebugslx_P.Badhallglitchorwrongconnectio_d);

            /* End of Outputs for SubSystem: '<S93>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S90>/Detects if the halls reading is valid' */

          /* Gain: '<S3>/Gain' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  DataTypeConversion: '<S92>/Data Type Conversion'
           *  DataTypeConversion: '<S92>/Data Type Conversion1'
           *  Delay: '<S92>/Delay'
           *  Sum: '<S92>/Sum'
           */
          Hallhardwaredebugslx_DW.Timehall = (int64_T)((int32_T)
            Hallhardwaredebugslx_DW.Timercntprev - (int32_T)
            Hallhardwaredebugslx_DW.Delay_DSTATE_b) *
            Hallhardwaredebugslx_P.Gain_Gain_e;

          /* DataTypeConversion: '<S90>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  Gain: '<S3>/Gain'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedCount = (uint32_T)
            (Hallhardwaredebugslx_DW.Timehall >> 30);

          /* DataTypeConversion: '<S93>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S90>/Constant'
           */
          Hallhardwaredebugslx_DW.HallStateChangeFlag =
            Hallhardwaredebugslx_P.Constant_Value_o;

          /* DataStoreWrite: '<S3>/Data Store Write6' */
          Hallhardwaredebugslx_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S3>/Data Store Write5' incorporates:
           *  Constant: '<S3>/Constant1'
           */
          Hallhardwaredebugslx_DW.HallBcapture =
            Hallhardwaredebugslx_P.Constant1_Value_d;

          /* Update for Delay: '<S92>/Delay' incorporates:
           *  DataStoreRead: '<S92>/Data Store Read1'
           */
          Hallhardwaredebugslx_DW.Delay_DSTATE_b =
            Hallhardwaredebugslx_DW.Timercntprev;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */
      }
    }
  }

  /* Event: EXTI10 Event */
  /* Check event EXTI10 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_10)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_10)))) {
    /* Clear occurred EXTI10 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_10);
    if (1 == runModel) {
      {
        /* S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HA' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;

          /* MATLABSystem: '<S67>/Timer' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           */
          Hallhardwaredebugslx_DW.Timercntprev = getTimerCounterValue
            (Hallhardwaredebugslx_DW.obj_e.TimerHandle);

          /* MATLABSystem: '<S85>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S87>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S89>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S66>/Sum' incorporates:
           *  Gain: '<S66>/Gain'
           *  Gain: '<S66>/Gain1'
           *  Gain: '<S66>/Gain2'
           *  MATLABSystem: '<S85>/Digital Port Read'
           *  MATLABSystem: '<S87>/Digital Port Read'
           *  MATLABSystem: '<S89>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Hallhardwaredebugslx_P.Gain_Gain_l >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? Hallhardwaredebugslx_P.Gain1_Gain_jt
             >> 6 : 0)) + (uint32_T)((pinReadLoc_e & 4096U) != 0U ?
            Hallhardwaredebugslx_P.Gain2_Gain_h >> 7 : 0));

          /* SwitchCase: '<S65>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S65>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S68>/Valid Halls' incorporates:
             *  ActionPort: '<S70>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S65>/Data Type Conversion2'
             */
            Hallhardwaredebugslx_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              Hallhardwaredebugslx_DW.GlobalHallState,
              Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
              &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
              &Hallhardwaredebugslx_B.ValidHalls_i,
              &Hallhardwaredebugslx_P.ValidHalls_i);

            /* End of Outputs for SubSystem: '<S68>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S68>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S69>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
               &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
               &Hallhardwaredebugslx_P.Badhallglitchorwrongconnectio_g);

            /* End of Outputs for SubSystem: '<S68>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S65>/Detects if the halls reading is valid' */

          /* Gain: '<S2>/Gain' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  DataTypeConversion: '<S67>/Data Type Conversion'
           *  DataTypeConversion: '<S67>/Data Type Conversion1'
           *  Delay: '<S67>/Delay'
           *  Sum: '<S67>/Sum'
           */
          Hallhardwaredebugslx_DW.Timehall = (int64_T)((int32_T)
            Hallhardwaredebugslx_DW.Timercntprev - (int32_T)
            Hallhardwaredebugslx_DW.Delay_DSTATE_m) *
            Hallhardwaredebugslx_P.Gain_Gain_p;

          /* DataTypeConversion: '<S65>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  Gain: '<S2>/Gain'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedCount = (uint32_T)
            (Hallhardwaredebugslx_DW.Timehall >> 30);

          /* DataTypeConversion: '<S68>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S65>/Constant'
           */
          Hallhardwaredebugslx_DW.HallStateChangeFlag =
            Hallhardwaredebugslx_P.Constant_Value_oj;

          /* DataStoreWrite: '<S2>/Data Store Write6' */
          Hallhardwaredebugslx_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S2>/Data Store Write5' incorporates:
           *  Constant: '<S2>/Constant1'
           */
          Hallhardwaredebugslx_DW.HallAcapture =
            Hallhardwaredebugslx_P.Constant1_Value_b;

          /* Update for Delay: '<S67>/Delay' incorporates:
           *  DataStoreRead: '<S67>/Data Store Read1'
           */
          Hallhardwaredebugslx_DW.Delay_DSTATE_m =
            Hallhardwaredebugslx_DW.Timercntprev;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

/* Hardware Interrupt Block: '<S143>/Hardware Interrupt' */
void ADC_IRQHandler(void)
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
        /* S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC SIC' */
        {
          real_T tmp_e;
          uint64_T tmp_p;
          real32_T rtb_Merge;
          real32_T rtb_Merge1_m;
          real32_T rtb_Merge1_n;
          uint32_T ADCSIC_ELAPS_T;
          uint32_T tmp_i;
          uint16_T tmp[3];
          uint16_T Switch;
          uint16_T rtb_DataStoreRead6;
          uint16_T rtb_watchdogcheck;
          boolean_T OR;
          Hallhardwaredebugslx_M->Timing.clockTick4 =
            Hallhardwaredebugslx_M->Timing.clockTick0;
          if (Hallhardwaredebugslx_DW.ADCSIC_RESET_ELAPS_T) {
            ADCSIC_ELAPS_T = 0U;
          } else {
            ADCSIC_ELAPS_T = Hallhardwaredebugslx_M->Timing.clockTick4 -
              Hallhardwaredebugslx_DW.ADCSIC_PREV_T;
          }

          Hallhardwaredebugslx_DW.ADCSIC_PREV_T =
            Hallhardwaredebugslx_M->Timing.clockTick4;
          Hallhardwaredebugslx_DW.ADCSIC_RESET_ELAPS_T = false;

          /* DataStoreRead: '<S18>/Data Store Read6' */
          rtb_DataStoreRead6 = Hallhardwaredebugslx_DW.HallStateChangeFlag;

          /* Switch: '<S29>/Switch' incorporates:
           *  Constant: '<S29>/WatchDog'
           *  DataStoreRead: '<S18>/Data Store Read6'
           *  DataStoreWrite: '<S18>/Data Store Write3'
           */
          if (Hallhardwaredebugslx_DW.HallStateChangeFlag != 0) {
            Hallhardwaredebugslx_DW.HallStateChangeFlag =
              Hallhardwaredebugslx_P.WatchDog_Value;
          }

          /* End of Switch: '<S29>/Switch' */

          /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
          if (Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
            if ((rtb_DataStoreRead6 > 0) &&
                (Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_PrevRese <= 0))
            {
              Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_DSTATE =
                Hallhardwaredebugslx_P.DiscreteTimeIntegrator_IC;
            } else {
              /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
              Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_DSTATE += (real32_T)
                (Hallhardwaredebugslx_P.DiscreteTimeIntegrator_gainval * (real_T)
                 ADCSIC_ELAPS_T
                 * Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_PREV_U);
            }
          }

          if (Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_DSTATE >
              Hallhardwaredebugslx_P.DiscreteTimeIntegrator_UpperSat) {
            /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
            Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_DSTATE =
              Hallhardwaredebugslx_P.DiscreteTimeIntegrator_UpperSat;
          } else if (Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_DSTATE <
                     Hallhardwaredebugslx_P.DiscreteTimeIntegrator_LowerSat) {
            /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
            Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_DSTATE =
              Hallhardwaredebugslx_P.DiscreteTimeIntegrator_LowerSat;
          }

          /* End of DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */

          /* DataTypeConversion: '<S29>/counterSize1' incorporates:
           *  DataStoreRead: '<S18>/Data Store Read'
           *  DataStoreRead: '<S18>/Data Store Read2'
           *  DataStoreRead: '<S18>/Data Store Read7'
           *  MinMax: '<S18>/Min'
           */
          tmp_e = floor(fmin(fmin(Hallhardwaredebugslx_DW.HallAcapture,
            Hallhardwaredebugslx_DW.HallBcapture),
                             Hallhardwaredebugslx_DW.HallCcapture));
          if (rtIsNaN(tmp_e) || rtIsInf(tmp_e)) {
            tmp_e = 0.0;
          } else {
            tmp_e = fmod(tmp_e, 4.294967296E+9);
          }

          ADCSIC_ELAPS_T = tmp_e < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp_e :
            (uint32_T)tmp_e;

          /* End of DataTypeConversion: '<S29>/counterSize1' */

          /* Switch: '<S30>/Switch' incorporates:
           *  Constant: '<S30>/Order'
           */
          if (Hallhardwaredebugslx_P.Order_Value >
              Hallhardwaredebugslx_P.Switch_Threshold) {
            /* Switch: '<S30>/Switch' */
            Switch = rtb_DataStoreRead6;
          } else {
            /* Switch: '<S30>/Switch' */
            Switch = Hallhardwaredebugslx_P.Order_Value;
          }

          /* End of Switch: '<S30>/Switch' */

          /* Delay: '<S30>/validityDelay' */
          if (Switch != 0) {
            /* Delay: '<S30>/validityDelay' */
            Hallhardwaredebugslx_B.validityDelay =
              Hallhardwaredebugslx_DW.validityDelay_DSTATE;
          }

          /* End of Delay: '<S30>/validityDelay' */

          /* Logic: '<S31>/OR' incorporates:
           *  DataTypeConversion: '<S29>/Data Type Conversion4'
           *  Delay: '<S31>/Delay One Step1'
           */
          OR = (Hallhardwaredebugslx_DW.DelayOneStep1_DSTATE ||
                (rtb_DataStoreRead6 != 0));

          /* Delay: '<S31>/Delay One Step' incorporates:
           *  DataTypeConversion: '<S29>/Data Type Conversion4'
           */
          if (OR) {
            if (rtb_DataStoreRead6 != 0) {
              Hallhardwaredebugslx_DW.DelayOneStep_DSTATE =
                Hallhardwaredebugslx_P.SoftwareWatchdogTimer_maxCount;
            }

            /* Delay: '<S31>/Delay One Step' incorporates:
             *  DataTypeConversion: '<S29>/Data Type Conversion4'
             */
            Hallhardwaredebugslx_B.DelayOneStep =
              Hallhardwaredebugslx_DW.DelayOneStep_DSTATE;
          }

          /* End of Delay: '<S31>/Delay One Step' */

          /* RelationalOperator: '<S35>/Compare' incorporates:
           *  Constant: '<S35>/Constant'
           */
          Hallhardwaredebugslx_DW.DelayOneStep1_DSTATE =
            (Hallhardwaredebugslx_B.DelayOneStep >
             Hallhardwaredebugslx_P.Constant_Value_dj);

          /* Switch: '<S34>/watchdog check' incorporates:
           *  Constant: '<S34>/Constant'
           */
          if (Hallhardwaredebugslx_DW.DelayOneStep1_DSTATE) {
            /* MinMax: '<S34>/Max' incorporates:
             *  DataStoreRead: '<S18>/Data Store Read3'
             */
            if (Hallhardwaredebugslx_DW.GlobalSpeedCount >= ADCSIC_ELAPS_T) {
              tmp_i = Hallhardwaredebugslx_DW.GlobalSpeedCount;
            } else {
              tmp_i = ADCSIC_ELAPS_T;
            }

            /* Switch: '<S34>/speed check' incorporates:
             *  Constant: '<S34>/Constant'
             *  DataStoreRead: '<S18>/Data Store Read5'
             *  DataTypeConversion: '<S30>/Data Type Conversion'
             *  Logic: '<S30>/Logical Operator'
             *  MinMax: '<S34>/Max'
             */
            if (tmp_i >= Hallhardwaredebugslx_P.speedcheck_Threshold) {
              rtb_watchdogcheck = Hallhardwaredebugslx_P.Constant_Value_p;
            } else {
              rtb_watchdogcheck = (uint16_T)
                ((Hallhardwaredebugslx_DW.GlobalSpeedValidity != 0) ||
                 Hallhardwaredebugslx_B.validityDelay);
            }

            /* End of Switch: '<S34>/speed check' */
          } else {
            rtb_watchdogcheck = Hallhardwaredebugslx_P.Constant_Value_p;
          }

          /* End of Switch: '<S34>/watchdog check' */

          /* Delay: '<S30>/speedCountDelay' */
          if (Switch != 0) {
            /* Delay: '<S30>/speedCountDelay' */
            Hallhardwaredebugslx_B.speedCountDelay =
              Hallhardwaredebugslx_DW.speedCountDelay_DSTATE;
          }

          /* End of Delay: '<S30>/speedCountDelay' */

          /* If: '<S29>/If' incorporates:
           *  Constant: '<S33>/PositionEnable'
           */
          if (rtb_watchdogcheck != 0) {
            /* Outputs for IfAction SubSystem: '<S29>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S33>/Action Port'
             */
            /* If: '<S33>/If' incorporates:
             *  DataStoreRead: '<S18>/Data Store Read4'
             */
            if (Hallhardwaredebugslx_DW.GlobalDirection > 0) {
              /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem' incorporates:
               *  ActionPort: '<S44>/Action Port'
               */
              /* SignalConversion generated from: '<S44>/In1' incorporates:
               *  Constant: '<S33>/SpeedConst'
               *  DataStoreRead: '<S18>/Data Store Read3'
               *  DataTypeConversion: '<S33>/SpeedConstData'
               *  DataTypeConversion: '<S33>/currentSpeedData'
               *  Gain: '<S33>/SpeedGain'
               *  Product: '<S33>/Divide'
               */
              rtb_Merge = (real32_T)Hallhardwaredebugslx_P.SpeedConst_Value /
                (real32_T)Hallhardwaredebugslx_DW.GlobalSpeedCount *
                Hallhardwaredebugslx_P.SpeedGain_Gain;

              /* End of Outputs for SubSystem: '<S33>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S33>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S45>/Action Port'
               */
              /* UnaryMinus: '<S45>/Unary Minus' incorporates:
               *  Constant: '<S33>/SpeedConst'
               *  DataStoreRead: '<S18>/Data Store Read3'
               *  DataTypeConversion: '<S33>/SpeedConstData'
               *  DataTypeConversion: '<S33>/currentSpeedData'
               *  Gain: '<S33>/SpeedGain'
               *  Product: '<S33>/Divide'
               */
              rtb_Merge = -((real32_T)Hallhardwaredebugslx_P.SpeedConst_Value /
                            (real32_T)Hallhardwaredebugslx_DW.GlobalSpeedCount *
                            Hallhardwaredebugslx_P.SpeedGain_Gain);

              /* End of Outputs for SubSystem: '<S33>/If Action Subsystem1' */
            }

            /* End of If: '<S33>/If' */

            /* Outputs for Enabled SubSystem: '<S33>/Subsystem1' incorporates:
             *  EnablePort: '<S46>/Enable'
             */
            if (Hallhardwaredebugslx_P.PositionEnable_Value > 0) {
              /* If: '<S46>/If1' incorporates:
               *  Constant: '<S46>/Constant'
               */
              if (Hallhardwaredebugslx_P.Constant_Value_i > 1.0) {
                /* Outputs for IfAction SubSystem: '<S46>/second_order' incorporates:
                 *  ActionPort: '<S50>/Action Port'
                 */
                /* Product: '<S50>/Divide1' incorporates:
                 *  DataStoreRead: '<S18>/Data Store Read3'
                 *  DataTypeConversion: '<S50>/countData'
                 *  DataTypeConversion: '<S50>/currentSpeedData'
                 */
                rtb_Merge1_n = (real32_T)ADCSIC_ELAPS_T / (real32_T)
                  Hallhardwaredebugslx_DW.GlobalSpeedCount;

                /* Gain: '<S50>/Gain' incorporates:
                 *  Constant: '<S50>/Constant'
                 *  DataTypeConversion: '<S50>/countData'
                 *  DataTypeConversion: '<S50>/previousSpeedData'
                 *  Gain: '<S50>/Gain1'
                 *  Product: '<S50>/Divide'
                 *  Product: '<S50>/Product'
                 *  Sum: '<S50>/Sum'
                 *  Sum: '<S50>/Sum1'
                 */
                rtb_Merge1_n = ((rtb_Merge1_n - (real32_T)ADCSIC_ELAPS_T /
                                 (real32_T)
                                 Hallhardwaredebugslx_B.speedCountDelay) *
                                Hallhardwaredebugslx_P.Gain1_Gain_j +
                                Hallhardwaredebugslx_P.Constant_Value_a) *
                  rtb_Merge1_n * Hallhardwaredebugslx_P.Gain_Gain_m;

                /* End of Outputs for SubSystem: '<S46>/second_order' */
              } else {
                /* Outputs for IfAction SubSystem: '<S46>/first_order' incorporates:
                 *  ActionPort: '<S49>/Action Port'
                 */
                /* Gain: '<S49>/Gain' incorporates:
                 *  DataStoreRead: '<S18>/Data Store Read3'
                 *  DataTypeConversion: '<S49>/countData'
                 *  DataTypeConversion: '<S49>/currentSpeedData'
                 *  Product: '<S49>/Divide'
                 */
                rtb_Merge1_n = (real32_T)ADCSIC_ELAPS_T / (real32_T)
                  Hallhardwaredebugslx_DW.GlobalSpeedCount *
                  Hallhardwaredebugslx_P.Gain_Gain_d;

                /* End of Outputs for SubSystem: '<S46>/first_order' */
              }

              /* End of If: '<S46>/If1' */

              /* Saturate: '<S46>/Saturation' */
              if (rtb_Merge1_n > Hallhardwaredebugslx_P.Saturation_UpperSat) {
                rtb_Merge1_n = Hallhardwaredebugslx_P.Saturation_UpperSat;
              } else if (rtb_Merge1_n <
                         Hallhardwaredebugslx_P.Saturation_LowerSat) {
                rtb_Merge1_n = Hallhardwaredebugslx_P.Saturation_LowerSat;
              }

              /* End of Saturate: '<S46>/Saturation' */

              /* If: '<S46>/If' incorporates:
               *  DataStoreRead: '<S18>/Data Store Read4'
               */
              if (Hallhardwaredebugslx_DW.GlobalDirection != 1) {
                /* Outputs for IfAction SubSystem: '<S46>/-ve Direction' incorporates:
                 *  ActionPort: '<S48>/Action Port'
                 */
                /* SwitchCase: '<S48>/Switch Case' incorporates:
                 *  DataStoreRead: '<S18>/Data Store Read1'
                 */
                switch (Hallhardwaredebugslx_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S58>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof1);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S59>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof2);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S60>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof3);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S61>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof4);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S62>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof5);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S63>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof6);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S64>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof7);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S48>/Switch Case' */

                /* Merge: '<S46>/Merge' incorporates:
                 *  Sum: '<S48>/Sum'
                 */
                Hallhardwaredebugslx_B.Merge = rtb_Merge1_m - rtb_Merge1_n;

                /* End of Outputs for SubSystem: '<S46>/-ve Direction' */
              } else {
                /* Outputs for IfAction SubSystem: '<S46>/+ve Direction' incorporates:
                 *  ActionPort: '<S47>/Action Port'
                 */
                /* SwitchCase: '<S47>/Switch Case' incorporates:
                 *  DataStoreRead: '<S18>/Data Store Read1'
                 */
                switch (Hallhardwaredebugslx_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S51>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof1_h);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S52>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof2_m);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S53>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof3_j);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S54>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof4_b);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S55>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof5_i);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S56>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof6_i);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S57>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_m,
                    &Hallhardwaredebugslx_P.HallValueof7_g);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S47>/Switch Case' */

                /* Merge: '<S46>/Merge' incorporates:
                 *  Sum: '<S47>/Sum'
                 */
                Hallhardwaredebugslx_B.Merge = rtb_Merge1_m + rtb_Merge1_n;

                /* End of Outputs for SubSystem: '<S46>/+ve Direction' */
              }

              /* End of If: '<S46>/If' */
            }

            /* End of Outputs for SubSystem: '<S33>/Subsystem1' */

            /* SignalConversion generated from: '<S33>/rawPosition' incorporates:
             *  Constant: '<S33>/PositionEnable'
             */
            rtb_Merge1_n = Hallhardwaredebugslx_B.Merge;

            /* End of Outputs for SubSystem: '<S29>/Speed and direction are valid Use speed to extrapolate position' */
          } else {
            /* Outputs for IfAction SubSystem: '<S29>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S32>/Action Port'
             */
            /* SwitchCase: '<S36>/Switch Case' incorporates:
             *  DataStoreRead: '<S18>/Data Store Read1'
             */
            switch (Hallhardwaredebugslx_DW.GlobalHallState) {
             case 5:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 1' incorporates:
               *  ActionPort: '<S37>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof1_d);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 1' */
              break;

             case 4:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 2' incorporates:
               *  ActionPort: '<S38>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof2_b);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 2' */
              break;

             case 6:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 3' incorporates:
               *  ActionPort: '<S39>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof3_jh);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 3' */
              break;

             case 2:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 4' incorporates:
               *  ActionPort: '<S40>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof4_c);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 4' */
              break;

             case 3:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 5' incorporates:
               *  ActionPort: '<S41>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof5_p);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 5' */
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 6' incorporates:
               *  ActionPort: '<S42>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof6_m);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 7' incorporates:
               *  ActionPort: '<S43>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof7_i);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S36>/Switch Case' */

            /* SignalConversion generated from: '<S32>/Speed(r.p.m)' incorporates:
             *  Constant: '<S32>/Constant'
             */
            rtb_Merge = Hallhardwaredebugslx_P.Constant_Value_g;

            /* End of Outputs for SubSystem: '<S29>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
          }

          /* End of If: '<S29>/If' */

          /* Sum: '<S18>/Sum' incorporates:
           *  Gain: '<S29>/PositionUnit'
           */
          Hallhardwaredebugslx_B.Sum = Hallhardwaredebugslx_P.PositionUnit_Gain *
            rtb_Merge1_n + Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_DSTATE;

          /* Outputs for Enabled SubSystem: '<S12>/PosGen' incorporates:
           *  EnablePort: '<S17>/Enable'
           */
          /* Constant: '<S1>/Constant1' */
          if (Hallhardwaredebugslx_P.Constant1_Value_p > 0.0) {
            if (!Hallhardwaredebugslx_DW.PosGen_MODE) {
              /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
              Hallhardwaredebugslx_DW.UnitDelay_DSTATE_e =
                Hallhardwaredebugslx_P.UnitDelay_InitialCondition;
              Hallhardwaredebugslx_DW.PosGen_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S17>/Up Counter' incorporates:
             *  EnablePort: '<S23>/Enable'
             */
            if (Hallhardwaredebugslx_P.Constant1_Value_p > 0.0) {
              if (!Hallhardwaredebugslx_DW.UpCounter_MODE) {
                /* InitializeConditions for Delay: '<S23>/Delay' */
                Hallhardwaredebugslx_DW.Delay_DSTATE_n =
                  Hallhardwaredebugslx_P.Delay_InitialCondition_p;
                Hallhardwaredebugslx_DW.UpCounter_MODE = true;
              }

              /* Sum: '<S23>/Add1' incorporates:
               *  Constant: '<S23>/Constant'
               *  Delay: '<S23>/Delay'
               */
              tmp_p = (uint64_T)Hallhardwaredebugslx_P.Constant_Value_n +
                Hallhardwaredebugslx_DW.Delay_DSTATE_n;
              if (tmp_p > 4294967295ULL) {
                tmp_p = 4294967295ULL;
              }

              /* Sum: '<S23>/Add1' */
              Hallhardwaredebugslx_B.Add1 = (uint32_T)tmp_p;

              /* Update for Delay: '<S23>/Delay' */
              Hallhardwaredebugslx_DW.Delay_DSTATE_n =
                Hallhardwaredebugslx_B.Add1;
            } else if (Hallhardwaredebugslx_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S23>/Add1' incorporates:
               *  Outport: '<S23>/Count'
               */
              Hallhardwaredebugslx_B.Add1 = Hallhardwaredebugslx_P.Count_Y0;
              Hallhardwaredebugslx_DW.UpCounter_MODE = false;
            }

            /* End of Outputs for SubSystem: '<S17>/Up Counter' */

            /* Outputs for Enabled SubSystem: '<S17>/Subsystem' incorporates:
             *  EnablePort: '<S21>/Enable'
             */
            /* Logic: '<S17>/NOT' incorporates:
             *  Constant: '<S19>/Constant'
             *  RelationalOperator: '<S19>/Compare'
             */
            if (Hallhardwaredebugslx_B.Add1 >
                Hallhardwaredebugslx_P.Disablehostafter42seconds_const) {
              /* DataStoreWrite: '<S21>/Data Store Write' incorporates:
               *  Constant: '<S21>/Constant'
               */
              Hallhardwaredebugslx_DW.Enable =
                Hallhardwaredebugslx_P.Constant_Value;
            }

            /* End of Logic: '<S17>/NOT' */
            /* End of Outputs for SubSystem: '<S17>/Subsystem' */

            /* RelationalOperator: '<S20>/Compare' incorporates:
             *  Constant: '<S20>/Constant'
             */
            Hallhardwaredebugslx_B.Compare = (Hallhardwaredebugslx_B.Add1 <=
              Hallhardwaredebugslx_P.EnablePWMfor40seconds_const);

            /* If: '<S22>/If' incorporates:
             *  Constant: '<S22>/Count for 2 sec'
             */
            if (Hallhardwaredebugslx_B.Add1 <
                Hallhardwaredebugslx_P.Countfor2sec_Value) {
              /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem' incorporates:
               *  ActionPort: '<S24>/Action Port'
               */
              /* SignalConversion generated from: '<S24>/Out1' incorporates:
               *  Constant: '<S24>/Constant'
               */
              rtb_Merge1_n = Hallhardwaredebugslx_P.Constant_Value_j;

              /* End of Outputs for SubSystem: '<S22>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S22>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S25>/Action Port'
               */
              /* Saturate: '<S25>/Saturate to 'motor.calibSpeed' RPM' incorporates:
               *  Constant: '<S25>/Constant1'
               *  Delay: '<S25>/Delay'
               *  Sum: '<S25>/Add1'
               */
              Hallhardwaredebugslx_DW.Delay_DSTATE_f +=
                Hallhardwaredebugslx_P.Constant1_Value_e;

              /* Saturate: '<S25>/Saturate to 'motor.calibSpeed' RPM' */
              if (Hallhardwaredebugslx_DW.Delay_DSTATE_f >
                  Hallhardwaredebugslx_P.SaturatetomotorcalibSpeedRPM_Up) {
                /* Saturate: '<S25>/Saturate to 'motor.calibSpeed' RPM' */
                Hallhardwaredebugslx_DW.Delay_DSTATE_f =
                  Hallhardwaredebugslx_P.SaturatetomotorcalibSpeedRPM_Up;
              } else if (Hallhardwaredebugslx_DW.Delay_DSTATE_f <
                         Hallhardwaredebugslx_P.SaturatetomotorcalibSpeedRPM_Lo)
              {
                /* Saturate: '<S25>/Saturate to 'motor.calibSpeed' RPM' */
                Hallhardwaredebugslx_DW.Delay_DSTATE_f =
                  Hallhardwaredebugslx_P.SaturatetomotorcalibSpeedRPM_Lo;
              }

              /* End of Saturate: '<S25>/Saturate to 'motor.calibSpeed' RPM' */

              /* Gain: '<S25>/Multiply' */
              rtb_Merge1_n = Hallhardwaredebugslx_P.Multiply_Gain *
                Hallhardwaredebugslx_DW.Delay_DSTATE_f;

              /* End of Outputs for SubSystem: '<S22>/If Action Subsystem2' */
            }

            /* End of If: '<S22>/If' */

            /* Outputs for Enabled SubSystem: '<S26>/Accumulate' incorporates:
             *  EnablePort: '<S27>/Enable'
             */
            /* Logic: '<S26>/NOT' incorporates:
             *  Constant: '<S26>/Constant_Reset'
             *  Delay: '<S27>/Delay'
             */
            if (!Hallhardwaredebugslx_P.Constant_Reset_Value) {
              /* Outputs for Enabled SubSystem: '<S27>/Subsystem' incorporates:
               *  EnablePort: '<S28>/Enable'
               */
              if (Hallhardwaredebugslx_DW.Delay_DSTATE_k) {
                /* SignalConversion generated from: '<S28>/Input' incorporates:
                 *  Gain: '<S26>/scaleIn'
                 */
                Hallhardwaredebugslx_B.Input =
                  Hallhardwaredebugslx_P.scaleIn_Gain * rtb_Merge1_n;
              }

              /* End of Outputs for SubSystem: '<S27>/Subsystem' */

              /* Sum: '<S27>/Add' incorporates:
               *  Delay: '<S27>/Delay'
               *  UnitDelay: '<S26>/Unit Delay'
               */
              rtb_Merge1_n = Hallhardwaredebugslx_B.Input +
                Hallhardwaredebugslx_DW.UnitDelay_DSTATE_e;

              /* DataTypeConversion: '<S27>/Data Type Conversion' */
              rtb_Merge1_m = floorf(rtb_Merge1_n);
              if (rtIsNaNF(rtb_Merge1_m) || rtIsInfF(rtb_Merge1_m)) {
                rtb_Merge1_m = 0.0F;
              } else {
                rtb_Merge1_m = fmodf(rtb_Merge1_m, 65536.0F);
              }

              /* Sum: '<S27>/Add1' incorporates:
               *  DataTypeConversion: '<S27>/Data Type Conversion'
               *  DataTypeConversion: '<S27>/Data Type Conversion1'
               */
              Hallhardwaredebugslx_B.Add1_n = rtb_Merge1_n - (real32_T)
                (rtb_Merge1_m < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
                 -rtb_Merge1_m : (int32_T)(int16_T)(uint16_T)rtb_Merge1_m);

              /* Update for Delay: '<S27>/Delay' incorporates:
               *  Constant: '<S27>/Constant'
               */
              Hallhardwaredebugslx_DW.Delay_DSTATE_k =
                Hallhardwaredebugslx_P.Constant_Value_nl;
            }

            /* End of Logic: '<S26>/NOT' */
            /* End of Outputs for SubSystem: '<S26>/Accumulate' */

            /* Gain: '<S26>/scaleOut' */
            Hallhardwaredebugslx_B.scaleOut =
              Hallhardwaredebugslx_P.scaleOut_Gain *
              Hallhardwaredebugslx_B.Add1_n;

            /* Update for UnitDelay: '<S26>/Unit Delay' */
            Hallhardwaredebugslx_DW.UnitDelay_DSTATE_e =
              Hallhardwaredebugslx_B.Add1_n;
          } else if (Hallhardwaredebugslx_DW.PosGen_MODE) {
            /* Disable for Enabled SubSystem: '<S17>/Up Counter' */
            if (Hallhardwaredebugslx_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S23>/Add1' incorporates:
               *  Outport: '<S23>/Count'
               */
              Hallhardwaredebugslx_B.Add1 = Hallhardwaredebugslx_P.Count_Y0;
              Hallhardwaredebugslx_DW.UpCounter_MODE = false;
            }

            /* End of Disable for SubSystem: '<S17>/Up Counter' */

            /* Disable for RelationalOperator: '<S20>/Compare' incorporates:
             *  Outport: '<S17>/EnPWM'
             */
            Hallhardwaredebugslx_B.Compare = Hallhardwaredebugslx_P.EnPWM_Y0;
            Hallhardwaredebugslx_DW.PosGen_MODE = false;
          }

          /* End of Constant: '<S1>/Constant1' */
          /* End of Outputs for SubSystem: '<S12>/PosGen' */

          /* MATLABSystem: '<S14>/Analog to Digital Converter' */
          injectedReadADCIntr(Hallhardwaredebugslx_DW.obj_g.ADCHandle, ADC_READ,
                              &tmp[0]);

          /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' incorporates:
           *  Gain: '<S18>/Gain'
           */
          Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
          Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
            (rtb_DataStoreRead6 > 0);
          Hallhardwaredebugslx_DW.DiscreteTimeIntegrator_PREV_U =
            Hallhardwaredebugslx_P.Gain_Gain_o * rtb_Merge;

          /* Update for Delay: '<S30>/validityDelay' incorporates:
           *  DataStoreRead: '<S18>/Data Store Read3'
           *  DataStoreRead: '<S18>/Data Store Read5'
           *  DataTypeConversion: '<S30>/Data Type Conversion'
           *  Delay: '<S30>/speedCountDelay'
           */
          if (Switch != 0) {
            Hallhardwaredebugslx_DW.validityDelay_DSTATE =
              (Hallhardwaredebugslx_DW.GlobalSpeedValidity != 0);
            Hallhardwaredebugslx_DW.speedCountDelay_DSTATE =
              Hallhardwaredebugslx_DW.GlobalSpeedCount;
          }

          /* End of Update for Delay: '<S30>/validityDelay' */

          /* Update for Delay: '<S31>/Delay One Step' incorporates:
           *  Constant: '<S31>/Constant2'
           *  Sum: '<S31>/Sum'
           */
          if (OR) {
            Hallhardwaredebugslx_DW.DelayOneStep_DSTATE = (uint16_T)((uint32_T)
              Hallhardwaredebugslx_B.DelayOneStep -
              Hallhardwaredebugslx_P.Constant2_Value);
          }

          /* End of Update for Delay: '<S31>/Delay One Step' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void Hallhardwaredebugslx_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
  MW_NVIC_DisableIRQ(55);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
