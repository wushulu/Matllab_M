/*
 * File: GOPIO.c
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Oct  9 11:43:38 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GOPIO.h"
#include "rtwtypes.h"
#include "GOPIO_types.h"
#include "GOPIO_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"

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
static void GOPIO_SystemCore_setup_b(stm32cube_blocks_TimerBlock_G_T *obj);
static void GOPIO_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
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

/*
 * Output and update for action system:
 *    '<S26>/If Action Subsystem'
 *    '<S97>/If Action Subsystem'
 */
void GOPIO_IfActionSubsystem(real_T rtu_In1, real_T *rty_Out1)
{
  real_T tmp;

  /* DataTypeConversion: '<S28>/Convert_uint16' */
  tmp = floor(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S28>/Sum' incorporates:
   *  DataTypeConversion: '<S28>/Convert_back'
   *  DataTypeConversion: '<S28>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S26>/If Action Subsystem1'
 *    '<S97>/If Action Subsystem1'
 */
void GOPIO_IfActionSubsystem1(real_T rtu_In1, real_T *rty_Out1)
{
  real_T tmp;

  /* DataTypeConversion: '<S29>/Convert_uint16' */
  tmp = trunc(rtu_In1);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 65536.0);
  }

  /* Sum: '<S29>/Sum' incorporates:
   *  DataTypeConversion: '<S29>/Convert_back'
   *  DataTypeConversion: '<S29>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real_T)(tmp < 0.0 ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
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

  /* Start for MATLABSystem: '<S85>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S85>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S85>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void GOPIO_SystemCore_setup_b(stm32cube_blocks_TimerBlock_G_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function */
void GOPIO_step(void)
{
  real_T rtb_Add1;
  real_T rtb_Add2;
  real_T rtb_Kc;
  real_T rtb_Min;
  real_T rtb_convert_pu;
  int32_T c;
  uint32_T rtb_TmpRTBAtFunctionCallSubsyst;
  uint16_T rtb_Get_Integer;
  uint16_T rtb_Get_Integer_n;

  /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
  rtb_TmpRTBAtFunctionCallSubsyst = GOPIO_B.Output;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Gain'
   */
  rtb_Kc = (real_T)((uint64_T)GOPIO_P.Gain_Gain_o *
                    rtb_TmpRTBAtFunctionCallSubsyst) * 1.4210854715202004E-14;

  /* Gain: '<S11>/Gain' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   *  Gain: '<Root>/Gain1'
   */
  GOPIO_B.indexing = rtb_Kc * GOPIO_P.Gain1_Gain * GOPIO_P.Gain_Gain;

  /* Gain: '<S26>/convert_pu' */
  rtb_convert_pu = GOPIO_P.convert_pu_Gain * GOPIO_B.indexing;

  /* If: '<S26>/If' incorporates:
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S27>/Compare'
   */
  if (rtb_convert_pu < GOPIO_P.Constant_Value) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    GOPIO_IfActionSubsystem(rtb_convert_pu, &rtb_Min);

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    GOPIO_IfActionSubsystem1(rtb_convert_pu, &rtb_Min);

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem1' */
  }

  /* End of If: '<S26>/If' */

  /* Gain: '<S23>/indexing' */
  rtb_Min *= GOPIO_P.indexing_Gain;

  /* DataTypeConversion: '<S23>/Get_Integer' */
  rtb_convert_pu = trunc(rtb_Min);
  if (rtIsNaN(rtb_convert_pu) || rtIsInf(rtb_convert_pu)) {
    rtb_convert_pu = 0.0;
  } else {
    rtb_convert_pu = fmod(rtb_convert_pu, 65536.0);
  }

  rtb_Get_Integer = (uint16_T)(rtb_convert_pu < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_convert_pu : (int32_T)(uint16_T)rtb_convert_pu);

  /* End of DataTypeConversion: '<S23>/Get_Integer' */

  /* Gain: '<S97>/convert_pu' */
  rtb_convert_pu = GOPIO_P.convert_pu_Gain_n * GOPIO_B.indexing;

  /* If: '<S97>/If' incorporates:
   *  Constant: '<S98>/Constant'
   *  RelationalOperator: '<S98>/Compare'
   */
  if (rtb_convert_pu < GOPIO_P.Constant_Value_d) {
    /* Outputs for IfAction SubSystem: '<S97>/If Action Subsystem' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    GOPIO_IfActionSubsystem(rtb_convert_pu, &GOPIO_B.indexing);

    /* End of Outputs for SubSystem: '<S97>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S97>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    GOPIO_IfActionSubsystem1(rtb_convert_pu, &GOPIO_B.indexing);

    /* End of Outputs for SubSystem: '<S97>/If Action Subsystem1' */
  }

  /* End of If: '<S97>/If' */

  /* Gain: '<S95>/indexing' */
  GOPIO_B.indexing *= GOPIO_P.indexing_Gain_c;

  /* DataTypeConversion: '<S95>/Get_Integer' */
  rtb_convert_pu = trunc(GOPIO_B.indexing);
  if (rtIsNaN(rtb_convert_pu) || rtIsInf(rtb_convert_pu)) {
    rtb_convert_pu = 0.0;
  } else {
    rtb_convert_pu = fmod(rtb_convert_pu, 65536.0);
  }

  rtb_Get_Integer_n = (uint16_T)(rtb_convert_pu < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_convert_pu : (int32_T)(uint16_T)rtb_convert_pu);

  /* End of DataTypeConversion: '<S95>/Get_Integer' */

  /* Sin: '<Root>/Sine Wave' */
  rtb_Add1 = sin(rtb_Kc * GOPIO_P.SineWave_Freq + GOPIO_P.SineWave_Phase) *
    GOPIO_P.SineWave_Amp + GOPIO_P.SineWave_Bias;

  /* Sin: '<Root>/Sine Wave1' */
  rtb_Add2 = sin(rtb_Kc * GOPIO_P.SineWave1_Freq + GOPIO_P.SineWave1_Phase) *
    GOPIO_P.SineWave1_Amp + GOPIO_P.SineWave1_Bias;

  /* Sin: '<Root>/Sine Wave2' */
  rtb_Kc = sin(rtb_Kc * GOPIO_P.SineWave2_Freq + GOPIO_P.SineWave2_Phase) *
    GOPIO_P.SineWave2_Amp + GOPIO_P.SineWave2_Bias;

  /* Gain: '<S12>/Kalphabeta0' incorporates:
   *  Gain: '<S12>/one_by_3'
   *  Gain: '<S12>/one_by_sqrt3_'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S12>/Sum1'
   *  Sum: '<S12>/Sum2'
   */
  rtb_convert_pu = (rtb_Add1 - ((rtb_Add1 + rtb_Add2) + rtb_Kc) *
                    GOPIO_P.one_by_3_Gain) * GOPIO_P.Kalphabeta0_Gain[0];
  rtb_Add2 = (rtb_Add2 - rtb_Kc) * GOPIO_P.one_by_sqrt3_Gain *
    GOPIO_P.Kalphabeta0_Gain[1];

  /* Sum: '<S95>/Sum2' incorporates:
   *  DataTypeConversion: '<S95>/Data Type Conversion1'
   */
  rtb_Kc = GOPIO_B.indexing - (real_T)rtb_Get_Integer_n;

  /* Selector: '<S95>/Lookup' incorporates:
   *  Constant: '<S95>/offset'
   *  Constant: '<S95>/sine_table_values'
   *  Sum: '<S95>/Sum'
   *  Sum: '<S96>/Sum3'
   */
  GOPIO_B.indexing = GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
    GOPIO_P.offset_Value_h[1] + rtb_Get_Integer_n)];

  /* Sum: '<S96>/Sum4' incorporates:
   *  Constant: '<S95>/offset'
   *  Constant: '<S95>/sine_table_values'
   *  Product: '<S96>/Product'
   *  Selector: '<S95>/Lookup'
   *  Sum: '<S95>/Sum'
   *  Sum: '<S96>/Sum3'
   */
  rtb_Add1 = (GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
    GOPIO_P.offset_Value_h[0] + rtb_Get_Integer_n)] - GOPIO_B.indexing) * rtb_Kc
    + GOPIO_B.indexing;

  /* Selector: '<S95>/Lookup' incorporates:
   *  Constant: '<S95>/offset'
   *  Constant: '<S95>/sine_table_values'
   *  Sum: '<S95>/Sum'
   *  Sum: '<S96>/Sum5'
   */
  GOPIO_B.indexing = GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
    GOPIO_P.offset_Value_h[3] + rtb_Get_Integer_n)];

  /* Sum: '<S96>/Sum6' incorporates:
   *  Constant: '<S95>/offset'
   *  Constant: '<S95>/sine_table_values'
   *  Product: '<S96>/Product1'
   *  Selector: '<S95>/Lookup'
   *  Sum: '<S95>/Sum'
   *  Sum: '<S96>/Sum5'
   */
  rtb_Kc = (GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
             GOPIO_P.offset_Value_h[2] + rtb_Get_Integer_n)] - GOPIO_B.indexing)
    * rtb_Kc + GOPIO_B.indexing;

  /* Outputs for Atomic SubSystem: '<S9>/Two inputs CRL' */
  /* Switch: '<S101>/Switch' incorporates:
   *  Constant: '<S101>/Offset'
   *  Product: '<S94>/acos'
   *  Product: '<S94>/asin'
   *  Product: '<S94>/bcos'
   *  Product: '<S94>/bsin'
   *  Sum: '<S94>/sum_Ds'
   *  Sum: '<S94>/sum_Qs'
   *  UnaryMinus: '<S101>/Unary_Minus'
   */
  if (GOPIO_P.Offset_Value_i > GOPIO_P.Switch_Threshold_i) {
    GOPIO_B.indexing = -(rtb_Add2 * rtb_Kc - rtb_convert_pu * rtb_Add1);
    rtb_Add2 = rtb_convert_pu * rtb_Kc + rtb_Add2 * rtb_Add1;
  } else {
    GOPIO_B.indexing = rtb_convert_pu * rtb_Kc + rtb_Add2 * rtb_Add1;
    rtb_Add2 = rtb_Add2 * rtb_Kc - rtb_convert_pu * rtb_Add1;
  }

  /* End of Switch: '<S101>/Switch' */
  /* End of Outputs for SubSystem: '<S9>/Two inputs CRL' */

  /* Sum: '<S23>/Sum2' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion1'
   */
  rtb_Kc = rtb_Min - (real_T)rtb_Get_Integer;

  /* Selector: '<S23>/Lookup' incorporates:
   *  Constant: '<S23>/offset'
   *  Constant: '<S23>/sine_table_values'
   *  Sum: '<S23>/Sum'
   *  Sum: '<S25>/Sum3'
   */
  rtb_Min = GOPIO_P.sine_table_values_Value_b[(int32_T)((uint32_T)
    GOPIO_P.offset_Value[1] + rtb_Get_Integer)];

  /* Sum: '<S25>/Sum4' incorporates:
   *  Constant: '<S23>/offset'
   *  Constant: '<S23>/sine_table_values'
   *  Product: '<S25>/Product'
   *  Selector: '<S23>/Lookup'
   *  Sum: '<S23>/Sum'
   *  Sum: '<S25>/Sum3'
   */
  rtb_Min += (GOPIO_P.sine_table_values_Value_b[(int32_T)((uint32_T)
    GOPIO_P.offset_Value[0] + rtb_Get_Integer)] - rtb_Min) * rtb_Kc;

  /* Selector: '<S23>/Lookup' incorporates:
   *  Constant: '<S23>/offset'
   *  Constant: '<S23>/sine_table_values'
   *  Sum: '<S23>/Sum'
   *  Sum: '<S25>/Sum5'
   */
  rtb_convert_pu = GOPIO_P.sine_table_values_Value_b[(int32_T)((uint32_T)
    GOPIO_P.offset_Value[3] + rtb_Get_Integer)];

  /* Sum: '<S25>/Sum6' incorporates:
   *  Constant: '<S23>/offset'
   *  Constant: '<S23>/sine_table_values'
   *  Product: '<S25>/Product1'
   *  Selector: '<S23>/Lookup'
   *  Sum: '<S23>/Sum'
   *  Sum: '<S25>/Sum5'
   */
  rtb_Kc = (GOPIO_P.sine_table_values_Value_b[(int32_T)((uint32_T)
             GOPIO_P.offset_Value[2] + rtb_Get_Integer)] - rtb_convert_pu) *
    rtb_Kc + rtb_convert_pu;

  /* Outputs for Atomic SubSystem: '<S24>/Two inputs CRL' */
  /* Switch: '<S31>/Switch' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S94>/a16'
   *  Constant: '<S31>/Offset'
   *  Product: '<S30>/dcos'
   *  Product: '<S30>/dsin'
   *  Product: '<S30>/qcos'
   *  Product: '<S30>/qsin'
   *  Sum: '<S30>/sum_alpha'
   *  Sum: '<S30>/sum_beta'
   *  UnaryMinus: '<S31>/Unary_Minus'
   */
  if (GOPIO_P.Offset_Value > GOPIO_P.Switch_Threshold) {
    /* Outputs for Atomic SubSystem: '<S9>/Two inputs CRL' */
    /* AlgorithmDescriptorDelegate generated from: '<S94>/a16' */
    rtb_convert_pu = GOPIO_B.indexing;
    GOPIO_B.indexing = rtb_Add2 * rtb_Kc + GOPIO_B.indexing * rtb_Min;
    rtb_Add2 = -(rtb_convert_pu * rtb_Kc - rtb_Add2 * rtb_Min);

    /* End of Outputs for SubSystem: '<S9>/Two inputs CRL' */
  } else {
    /* Outputs for Atomic SubSystem: '<S9>/Two inputs CRL' */
    /* AlgorithmDescriptorDelegate generated from: '<S94>/a16' */
    rtb_convert_pu = GOPIO_B.indexing;
    GOPIO_B.indexing = GOPIO_B.indexing * rtb_Kc - rtb_Add2 * rtb_Min;
    rtb_Add2 = rtb_Add2 * rtb_Kc + rtb_convert_pu * rtb_Min;

    /* End of Outputs for SubSystem: '<S9>/Two inputs CRL' */
  }

  /* End of Switch: '<S31>/Switch' */

  /* Gain: '<Root>/Gain2' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S30>/a16'
   */
  rtb_convert_pu = GOPIO_P.Gain2_Gain * GOPIO_B.indexing;

  /* End of Outputs for SubSystem: '<S24>/Two inputs CRL' */

  /* Gain: '<S92>/Ka' */
  rtb_Min = GOPIO_P.Ka_Gain * rtb_convert_pu;

  /* Gain: '<S92>/one_by_two' */
  rtb_Kc = GOPIO_P.one_by_two_Gain * rtb_convert_pu;

  /* Outputs for Atomic SubSystem: '<S24>/Two inputs CRL' */
  /* Gain: '<S92>/sqrt3_by_two' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S30>/a16'
   *  Gain: '<Root>/Gain2'
   */
  rtb_Add2 = GOPIO_P.Gain2_Gain * rtb_Add2 * GOPIO_P.sqrt3_by_two_Gain;

  /* End of Outputs for SubSystem: '<S24>/Two inputs CRL' */

  /* Gain: '<S92>/Kb' incorporates:
   *  Sum: '<S92>/add_b'
   */
  rtb_Add1 = (rtb_Add2 - rtb_Kc) * GOPIO_P.Kb_Gain;

  /* Gain: '<S92>/Kc' incorporates:
   *  Sum: '<S92>/add_c'
   */
  rtb_Kc = ((0.0 - rtb_Kc) - rtb_Add2) * GOPIO_P.Kc_Gain;

  /* Gain: '<S89>/one_by_two' incorporates:
   *  MinMax: '<S89>/Max'
   *  MinMax: '<S89>/Min'
   *  Sum: '<S89>/Add'
   */
  rtb_Add2 = (fmax(fmax(rtb_Min, rtb_Add1), rtb_Kc) + fmin(fmin(rtb_Min,
    rtb_Add1), rtb_Kc)) * GOPIO_P.one_by_two_Gain_d;

  /* MATLABSystem: '<S85>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant3'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<S88>/Gain'
   *  Sum: '<Root>/Add'
   *  Sum: '<S88>/Add1'
   *  Sum: '<S88>/Add2'
   *  Sum: '<S88>/Add3'
   */
  rtb_convert_pu = rt_roundd_snf(GOPIO_P.Constant3_Value);
  if (rtb_convert_pu < 4.294967296E+9) {
    if (rtb_convert_pu >= 0.0) {
      rtb_TmpRTBAtFunctionCallSubsyst = (uint32_T)rtb_convert_pu;
    } else {
      rtb_TmpRTBAtFunctionCallSubsyst = 0U;
    }
  } else {
    rtb_TmpRTBAtFunctionCallSubsyst = MAX_uint32_T;
  }

  rtb_TmpRTBAtFunctionCallSubsyst = checkFrequencyAndDutyCycleLimits
    (GOPIO_DW.obj_e.TimerHandle, rtb_TmpRTBAtFunctionCallSubsyst);
  setFrequencyAccToInput(GOPIO_DW.obj_e.TimerHandle,
    rtb_TmpRTBAtFunctionCallSubsyst);
  setDutyCycleInPercentageChannel1(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Gain4_Gain * (GOPIO_P.Gain3_Gain * (GOPIO_P.Gain_Gain_m * (rtb_Min +
    rtb_Add2)) + GOPIO_P.Constant_Value_p));
  setDutyCycleInPercentageChannel2(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Gain4_Gain * (GOPIO_P.Gain3_Gain * (GOPIO_P.Gain_Gain_m * (rtb_Add1
    + rtb_Add2)) + GOPIO_P.Constant_Value_p));
  setDutyCycleInPercentageChannel3(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Gain4_Gain * (GOPIO_P.Gain3_Gain * (GOPIO_P.Gain_Gain_m * (rtb_Add2
    + rtb_Kc)) + GOPIO_P.Constant_Value_p));

  /* End of MATLABSystem: '<S85>/PWM Output' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_Min = (GOPIO_DW.clockTickCounter < GOPIO_P.PulseGenerator_Duty) &&
    (GOPIO_DW.clockTickCounter >= 0) ? GOPIO_P.PulseGenerator_Amp : 0.0;
  if (GOPIO_DW.clockTickCounter >= GOPIO_P.PulseGenerator_Period - 1.0) {
    GOPIO_DW.clockTickCounter = 0;
  } else {
    GOPIO_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S14>/Digital Port Write' */
  GOPIO_B.portNameLoc = GPIOA;
  if (rtb_Min != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(GOPIO_B.portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(GOPIO_B.portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S14>/Digital Port Write' */

  /* MATLABSystem: '<Root>/Timer' */
  getTimerCounterValue(GOPIO_DW.obj_j.TimerHandle);
}

/* Model initialize function */
void GOPIO_initialize(void)
{
  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* InitializeConditions for Sum: '<S19>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S16>/Output'
   */
  GOPIO_DW.Output_DSTATE = GOPIO_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  GOPIO_DW.obj.isInitialized = 0;
  GOPIO_DW.obj.matlabCodegenIsDeleted = false;
  GOPIO_SystemCore_setup(&GOPIO_DW.obj);

  /* SystemInitialize for UnitDelay: '<S16>/Output' incorporates:
   *  Outport: '<S3>/Out2'
   */
  GOPIO_B.Output = GOPIO_P.Out2_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S85>/PWM Output' */
  GOPIO_DW.obj_e.matlabCodegenIsDeleted = false;
  GOPIO_DW.obj_e.isSetupComplete = false;
  GOPIO_DW.obj_e.isInitialized = 1;
  GOPIO_PWMOutput_setupImpl(&GOPIO_DW.obj_e);
  GOPIO_DW.obj_e.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/Timer' */
  GOPIO_DW.obj_j.isInitialized = 0;
  GOPIO_DW.obj_j.matlabCodegenIsDeleted = false;
  GOPIO_SystemCore_setup_b(&GOPIO_DW.obj_j);
}

/* Model terminate function */
void GOPIO_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */
  if (!GOPIO_DW.obj.matlabCodegenIsDeleted) {
    GOPIO_DW.obj.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj.isInitialized == 1) && GOPIO_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(GOPIO_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S85>/PWM Output' */
  if (!GOPIO_DW.obj_e.matlabCodegenIsDeleted) {
    GOPIO_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj_e.isInitialized == 1) && GOPIO_DW.obj_e.isSetupComplete) {
      disableCounter(GOPIO_DW.obj_e.TimerHandle);
      disableTimerInterrupts(GOPIO_DW.obj_e.TimerHandle, 0);
      disableTimerChannel1(GOPIO_DW.obj_e.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(GOPIO_DW.obj_e.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(GOPIO_DW.obj_e.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S85>/PWM Output' */

  /* Terminate for MATLABSystem: '<Root>/Timer' */
  if (!GOPIO_DW.obj_j.matlabCodegenIsDeleted) {
    GOPIO_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj_j.isInitialized == 1) && GOPIO_DW.obj_j.isSetupComplete) {
      disableCounter(GOPIO_DW.obj_j.TimerHandle);
      disableTimerInterrupts(GOPIO_DW.obj_j.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Timer' */
}

void GOPIO_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S22>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          uint16_T tmp[2];

          /* MATLABSystem: '<S18>/Analog to Digital Converter' */
          injectedReadADCIntr(GOPIO_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* UnitDelay: '<S16>/Output' */
          GOPIO_B.Output = GOPIO_DW.Output_DSTATE;

          /* Sum: '<S19>/FixPt Sum1' incorporates:
           *  Constant: '<S19>/FixPt Constant'
           */
          GOPIO_DW.Output_DSTATE = GOPIO_B.Output + GOPIO_P.FixPtConstant_Value;

          /* Switch: '<S20>/FixPt Switch' */
          if (GOPIO_DW.Output_DSTATE > GOPIO_P.WrapToZero_Threshold) {
            /* Sum: '<S19>/FixPt Sum1' incorporates:
             *  Constant: '<S20>/Constant'
             *  UnitDelay: '<S16>/Output'
             */
            GOPIO_DW.Output_DSTATE = GOPIO_P.Constant_Value_a;
          }

          /* End of Switch: '<S20>/FixPt Switch' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */
      }
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
