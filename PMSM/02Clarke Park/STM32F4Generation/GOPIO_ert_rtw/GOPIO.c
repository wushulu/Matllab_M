/*
 * File: GOPIO.c
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Sep  4 21:01:52 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "GOPIO.h"
#include "GOPIO_types.h"
#include "GOPIO_private.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include <math.h>
#include "rt_nonfinite.h"
#include "stm_timer_ll.h"
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
static void GOPIO_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
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

  /* Start for MATLABSystem: '<S21>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S21>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S21>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/* Model step function */
void GOPIO_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_Gain1;
  real_T rtb_Kalphabeta0_idx_0;
  real_T rtb_Sum6_tmp;
  real_T rtb_bsin;
  real_T rtb_convert_pu;
  int32_T c;
  uint32_T rtb_TmpRTBAtGainInport1;
  uint16_T rtb_Get_Integer;

  /* Reset subsysRan breadcrumbs */
  srClearBC(GOPIO_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(GOPIO_DW.IfActionSubsystem1_SubsysRanBC);

  /* RateTransition generated from: '<Root>/Gain' */
  rtb_TmpRTBAtGainInport1 = GOPIO_B.Output;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Gain: '<Root>/Gain'
   */
  GOPIO_B.DataTypeConversion = (real_T)((uint64_T)GOPIO_P.Gain_Gain_o *
    rtb_TmpRTBAtGainInport1) * 1.4210854715202004E-14;

  /* Gain: '<Root>/Gain1' */
  rtb_Gain1 = GOPIO_P.Gain1_Gain * GOPIO_B.DataTypeConversion;

  /* Gain: '<S26>/convert_pu' incorporates:
   *  Gain: '<S8>/Gain'
   */
  rtb_convert_pu = GOPIO_P.Gain_Gain * rtb_Gain1 * GOPIO_P.convert_pu_Gain;

  /* If: '<S26>/If' incorporates:
   *  Constant: '<S27>/Constant'
   *  RelationalOperator: '<S27>/Compare'
   */
  if (rtb_convert_pu < GOPIO_P.Constant_Value) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* DataTypeConversion: '<S28>/Convert_uint16' */
    rtb_Kalphabeta0_idx_0 = floor(rtb_convert_pu);
    if (rtIsInf(rtb_Kalphabeta0_idx_0)) {
      rtb_Kalphabeta0_idx_0 = 0.0;
    } else {
      rtb_Kalphabeta0_idx_0 = fmod(rtb_Kalphabeta0_idx_0, 65536.0);
    }

    /* Sum: '<S28>/Sum' incorporates:
     *  DataTypeConversion: '<S28>/Convert_back'
     *  DataTypeConversion: '<S28>/Convert_uint16'
     */
    rtb_convert_pu -= (real_T)(rtb_Kalphabeta0_idx_0 < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Kalphabeta0_idx_0 : (int32_T)(int16_T)(uint16_T)
      rtb_Kalphabeta0_idx_0);

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S26>/If Action Subsystem' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    /* Update for If: '<S26>/If' */
    srUpdateBC(GOPIO_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S26>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* DataTypeConversion: '<S29>/Convert_uint16' */
    rtb_Kalphabeta0_idx_0 = trunc(rtb_convert_pu);
    if (rtIsNaN(rtb_Kalphabeta0_idx_0) || rtIsInf(rtb_Kalphabeta0_idx_0)) {
      rtb_Kalphabeta0_idx_0 = 0.0;
    } else {
      rtb_Kalphabeta0_idx_0 = fmod(rtb_Kalphabeta0_idx_0, 65536.0);
    }

    /* Sum: '<S29>/Sum' incorporates:
     *  DataTypeConversion: '<S29>/Convert_back'
     *  DataTypeConversion: '<S29>/Convert_uint16'
     */
    rtb_convert_pu -= (real_T)(rtb_Kalphabeta0_idx_0 < 0.0 ? (int32_T)(int16_T)
      -(int16_T)(uint16_T)-rtb_Kalphabeta0_idx_0 : (int32_T)(int16_T)(uint16_T)
      rtb_Kalphabeta0_idx_0);

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S26>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    /* Update for If: '<S26>/If' */
    srUpdateBC(GOPIO_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S26>/If Action Subsystem1' */
  }

  /* End of If: '<S26>/If' */

  /* Gain: '<S24>/indexing' */
  rtb_convert_pu *= GOPIO_P.indexing_Gain;

  /* DataTypeConversion: '<S24>/Get_Integer' */
  rtb_Kalphabeta0_idx_0 = trunc(rtb_convert_pu);
  if (rtIsNaN(rtb_Kalphabeta0_idx_0) || rtIsInf(rtb_Kalphabeta0_idx_0)) {
    rtb_Kalphabeta0_idx_0 = 0.0;
  } else {
    rtb_Kalphabeta0_idx_0 = fmod(rtb_Kalphabeta0_idx_0, 65536.0);
  }

  rtb_Get_Integer = (uint16_T)(rtb_Kalphabeta0_idx_0 < 0.0 ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_Kalphabeta0_idx_0 : (int32_T)(uint16_T)
    rtb_Kalphabeta0_idx_0);

  /* End of DataTypeConversion: '<S24>/Get_Integer' */

  /* Sin: '<Root>/Sine Wave' */
  GOPIO_B.Ia = sin(GOPIO_P.SineWave_Freq * GOPIO_B.DataTypeConversion +
                   GOPIO_P.SineWave_Phase) * GOPIO_P.SineWave_Amp +
    GOPIO_P.SineWave_Bias;

  /* Sin: '<Root>/Sine Wave1' */
  GOPIO_B.Ib = sin(GOPIO_P.SineWave1_Freq * GOPIO_B.DataTypeConversion +
                   GOPIO_P.SineWave1_Phase) * GOPIO_P.SineWave1_Amp +
    GOPIO_P.SineWave1_Bias;

  /* Sin: '<Root>/Sine Wave2' */
  GOPIO_B.Ic = sin(GOPIO_P.SineWave2_Freq * GOPIO_B.DataTypeConversion +
                   GOPIO_P.SineWave2_Phase) * GOPIO_P.SineWave2_Amp +
    GOPIO_P.SineWave2_Bias;

  /* Gain: '<S7>/Gain1' incorporates:
   *  Fcn: '<S7>/d'
   *  Fcn: '<S7>/q'
   */
  GOPIO_B.Gain1[0] = ((sin(rtb_Gain1 - 2.0943951023931953) * GOPIO_B.Ib + sin
                       (rtb_Gain1) * GOPIO_B.Ia) + sin(rtb_Gain1 +
    2.0943951023931953) * GOPIO_B.Ic) * GOPIO_P.Gain1_Gain_o;
  GOPIO_B.Gain1[1] = ((cos(rtb_Gain1 - 2.0943951023931953) * GOPIO_B.Ib + cos
                       (rtb_Gain1) * GOPIO_B.Ia) + cos(rtb_Gain1 +
    2.0943951023931953) * GOPIO_B.Ic) * GOPIO_P.Gain1_Gain_o;

  /* Fcn: '<S7>/0' incorporates:
   *  Sum: '<S9>/Sum'
   */
  rtb_Kalphabeta0_idx_0 = (GOPIO_B.Ia + GOPIO_B.Ib) + GOPIO_B.Ic;

  /* Gain: '<S7>/Gain1' incorporates:
   *  Fcn: '<S7>/0'
   */
  GOPIO_B.Gain1[2] = rtb_Kalphabeta0_idx_0 * 0.5 * GOPIO_P.Gain1_Gain_o;

  /* Gain: '<S9>/Kalphabeta0' incorporates:
   *  Gain: '<S9>/one_by_3'
   *  Gain: '<S9>/one_by_sqrt3_'
   *  Sum: '<S9>/Sum1'
   *  Sum: '<S9>/Sum2'
   */
  rtb_Kalphabeta0_idx_0 = (GOPIO_B.Ia - rtb_Kalphabeta0_idx_0 *
    GOPIO_P.one_by_3_Gain) * GOPIO_P.Kalphabeta0_Gain[0];
  rtb_Gain1 = (GOPIO_B.Ib - GOPIO_B.Ic) * GOPIO_P.one_by_sqrt3_Gain *
    GOPIO_P.Kalphabeta0_Gain[1];

  /* Sum: '<S24>/Sum2' incorporates:
   *  DataTypeConversion: '<S24>/Data Type Conversion1'
   */
  rtb_bsin = rtb_convert_pu - (real_T)rtb_Get_Integer;

  /* Selector: '<S24>/Lookup' incorporates:
   *  Constant: '<S24>/offset'
   *  Constant: '<S24>/sine_table_values'
   *  Sum: '<S24>/Sum'
   *  Sum: '<S25>/Sum3'
   */
  rtb_convert_pu = GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
    GOPIO_P.offset_Value[1] + rtb_Get_Integer)];

  /* Sum: '<S25>/Sum4' incorporates:
   *  Constant: '<S24>/offset'
   *  Constant: '<S24>/sine_table_values'
   *  Product: '<S25>/Product'
   *  Selector: '<S24>/Lookup'
   *  Sum: '<S24>/Sum'
   *  Sum: '<S25>/Sum3'
   */
  rtb_convert_pu += (GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
    GOPIO_P.offset_Value[0] + rtb_Get_Integer)] - rtb_convert_pu) * rtb_bsin;

  /* Selector: '<S24>/Lookup' incorporates:
   *  Constant: '<S24>/offset'
   *  Constant: '<S24>/sine_table_values'
   *  Sum: '<S24>/Sum'
   *  Sum: '<S25>/Sum5'
   */
  rtb_Sum6_tmp = GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
    GOPIO_P.offset_Value[3] + rtb_Get_Integer)];

  /* Sum: '<S25>/Sum6' incorporates:
   *  Constant: '<S24>/offset'
   *  Constant: '<S24>/sine_table_values'
   *  Product: '<S25>/Product1'
   *  Selector: '<S24>/Lookup'
   *  Sum: '<S24>/Sum'
   *  Sum: '<S25>/Sum5'
   */
  rtb_bsin = (GOPIO_P.sine_table_values_Value[(int32_T)((uint32_T)
    GOPIO_P.offset_Value[2] + rtb_Get_Integer)] - rtb_Sum6_tmp) * rtb_bsin +
    rtb_Sum6_tmp;

  /* Outputs for Atomic SubSystem: '<S6>/Two inputs CRL' */
  /* Switch: '<S30>/Switch' incorporates:
   *  Constant: '<S30>/Offset'
   */
  if (GOPIO_P.Offset_Value > GOPIO_P.Switch_Threshold) {
    /* AlgorithmDescriptorDelegate generated from: '<S23>/a16' incorporates:
     *  Product: '<S23>/asin'
     *  Product: '<S23>/bcos'
     *  Sum: '<S23>/sum_Qs'
     *  UnaryMinus: '<S30>/Unary_Minus'
     */
    GOPIO_B.algDD_o1 = -(rtb_Gain1 * rtb_bsin - rtb_Kalphabeta0_idx_0 *
                         rtb_convert_pu);

    /* AlgorithmDescriptorDelegate generated from: '<S23>/a16' incorporates:
     *  Product: '<S23>/acos'
     *  Product: '<S23>/bsin'
     *  Sum: '<S23>/sum_Ds'
     */
    GOPIO_B.algDD_o2 = rtb_Kalphabeta0_idx_0 * rtb_bsin + rtb_Gain1 *
      rtb_convert_pu;
  } else {
    /* AlgorithmDescriptorDelegate generated from: '<S23>/a16' incorporates:
     *  Product: '<S23>/acos'
     *  Product: '<S23>/bsin'
     *  Sum: '<S23>/sum_Ds'
     */
    GOPIO_B.algDD_o1 = rtb_Kalphabeta0_idx_0 * rtb_bsin + rtb_Gain1 *
      rtb_convert_pu;

    /* AlgorithmDescriptorDelegate generated from: '<S23>/a16' incorporates:
     *  Product: '<S23>/asin'
     *  Product: '<S23>/bcos'
     *  Sum: '<S23>/sum_Qs'
     */
    GOPIO_B.algDD_o2 = rtb_Gain1 * rtb_bsin - rtb_Kalphabeta0_idx_0 *
      rtb_convert_pu;
  }

  /* End of Switch: '<S30>/Switch' */
  /* End of Outputs for SubSystem: '<S6>/Two inputs CRL' */

  /* SignalConversion generated from: '<Root>/Mux' */
  GOPIO_B.TmpSignalConversionAtTAQSigLogg[0] = GOPIO_B.algDD_o1;
  GOPIO_B.TmpSignalConversionAtTAQSigLogg[1] = GOPIO_B.algDD_o2;

  /* MATLABSystem: '<S21>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  rtb_Kalphabeta0_idx_0 = rt_roundd_snf(GOPIO_P.Constant3_Value);
  if (rtb_Kalphabeta0_idx_0 < 4.294967296E+9) {
    if (rtb_Kalphabeta0_idx_0 >= 0.0) {
      rtb_TmpRTBAtGainInport1 = (uint32_T)rtb_Kalphabeta0_idx_0;
    } else {
      rtb_TmpRTBAtGainInport1 = 0U;
    }
  } else {
    rtb_TmpRTBAtGainInport1 = MAX_uint32_T;
  }

  rtb_TmpRTBAtGainInport1 = checkFrequencyAndDutyCycleLimits
    (GOPIO_DW.obj_e.TimerHandle, rtb_TmpRTBAtGainInport1);
  setFrequencyAccToInput(GOPIO_DW.obj_e.TimerHandle, rtb_TmpRTBAtGainInport1);
  setDutyCycleInPercentageChannel1(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Constant1_Value);
  setDutyCycleInPercentageChannel2(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Constant2_Value);
  setDutyCycleInPercentageChannel3(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Constant2_Value);

  /* End of MATLABSystem: '<S21>/PWM Output' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_Kalphabeta0_idx_0 = (GOPIO_DW.clockTickCounter <
    GOPIO_P.PulseGenerator_Duty) && (GOPIO_DW.clockTickCounter >= 0) ?
    GOPIO_P.PulseGenerator_Amp : 0.0;
  if (GOPIO_DW.clockTickCounter >= GOPIO_P.PulseGenerator_Period - 1.0) {
    GOPIO_DW.clockTickCounter = 0;
  } else {
    GOPIO_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S11>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_Kalphabeta0_idx_0 != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S11>/Digital Port Write' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  GOPIO_M->Timing.taskTime0 =
    ((time_T)(++GOPIO_M->Timing.clockTick0)) * GOPIO_M->Timing.stepSize0;
}

/* Model initialize function */
void GOPIO_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(GOPIO_M, -1);
  GOPIO_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  GOPIO_M->Sizes.checksums[0] = (3688463956U);
  GOPIO_M->Sizes.checksums[1] = (2716376005U);
  GOPIO_M->Sizes.checksums[2] = (2130942519U);
  GOPIO_M->Sizes.checksums[3] = (2663157626U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    GOPIO_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[3] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = (sysRanDType *)&GOPIO_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&GOPIO_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&GOPIO_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[8] = &rtAlwaysEnabled;
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(GOPIO_M->extModeInfo,
      &GOPIO_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(GOPIO_M->extModeInfo, GOPIO_M->Sizes.checksums);
    rteiSetTPtr(GOPIO_M->extModeInfo, rtmGetTPtr(GOPIO_M));
  }

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  GOPIO_M->Timing.clockTick1 = GOPIO_M->Timing.clockTick0;

  /* InitializeConditions for Sum: '<S16>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S13>/Output'
   */
  GOPIO_DW.Output_DSTATE = GOPIO_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
  GOPIO_DW.obj.isInitialized = 0;
  GOPIO_DW.obj.matlabCodegenIsDeleted = false;
  GOPIO_SystemCore_setup(&GOPIO_DW.obj);

  /* SystemInitialize for UnitDelay: '<S13>/Output' incorporates:
   *  Outport: '<S3>/Out2'
   */
  GOPIO_B.Output = GOPIO_P.Out2_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S21>/PWM Output' */
  GOPIO_DW.obj_e.matlabCodegenIsDeleted = false;
  GOPIO_DW.obj_e.isSetupComplete = false;
  GOPIO_DW.obj_e.isInitialized = 1;
  GOPIO_PWMOutput_setupImpl(&GOPIO_DW.obj_e);
  GOPIO_DW.obj_e.isSetupComplete = true;
}

/* Model terminate function */
void GOPIO_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */
  if (!GOPIO_DW.obj.matlabCodegenIsDeleted) {
    GOPIO_DW.obj.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj.isInitialized == 1) && GOPIO_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(GOPIO_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S21>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S21>/PWM Output' */
}

void GOPIO_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S19>/Hardware Interrupt' */
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
        srClearBC(GOPIO_DW.FunctionCallSubsystem_SubsysRan);

        /* S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          uint16_T tmp[2];
          GOPIO_M->Timing.clockTick1 = GOPIO_M->Timing.clockTick0;

          /* MATLABSystem: '<S15>/Analog to Digital Converter' */
          injectedReadADCIntr(GOPIO_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* UnitDelay: '<S13>/Output' */
          GOPIO_B.Output = GOPIO_DW.Output_DSTATE;

          /* Sum: '<S16>/FixPt Sum1' incorporates:
           *  Constant: '<S16>/FixPt Constant'
           */
          GOPIO_DW.Output_DSTATE = GOPIO_B.Output + GOPIO_P.FixPtConstant_Value;

          /* Switch: '<S17>/FixPt Switch' */
          if (GOPIO_DW.Output_DSTATE > GOPIO_P.WrapToZero_Threshold) {
            /* Sum: '<S16>/FixPt Sum1' incorporates:
             *  Constant: '<S17>/Constant'
             *  UnitDelay: '<S13>/Output'
             */
            GOPIO_DW.Output_DSTATE = GOPIO_P.Constant_Value_a;
          }

          /* End of Switch: '<S17>/FixPt Switch' */
          GOPIO_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((GOPIO_M->Timing.clockTick1) *
        0.1);
      extmodeEvent(1,currentTime);
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
