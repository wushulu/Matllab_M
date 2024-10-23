/*
 * File: HalltimerInterface.c
 *
 * Code generated for Simulink model 'HalltimerInterface'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Oct 17 16:59:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HalltimerInterface.h"
#include "HalltimerInterface_types.h"
#include "HalltimerInterface_private.h"
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_HalltimerInterface_T HalltimerInterface_B;

/* Block states (default storage) */
DW_HalltimerInterface_T HalltimerInterface_DW;

/* Real-time model */
static RT_MODEL_HalltimerInterface_T HalltimerInterface_M_;
RT_MODEL_HalltimerInterface_T *const HalltimerInterface_M =
  &HalltimerInterface_M_;

/* Forward declaration for local functions */
static void HalltimerInter_SystemCore_setup(stm32cube_blocks_TimerCapture_T *obj);

/* Forward declaration for local functions */
static void HalltimerInt_SystemCore_setup_g(stm32cube_blocks_AnalogInput__T *obj);

/* Forward declaration for local functions */
static void HalltimerIn_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ha_T *obj);
static void HalltimerInter_SystemCore_setup(stm32cube_blocks_TimerCapture_T *obj)
{
  Channel_DMA_T b;
  TIM_Type_T b_p;
  int32_T i;
  boolean_T isSlaveModeTriggerEnabled;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S3>/Timer Capture' */
  obj->isInitialized = 1;
  b_p.PeripheralPtr = TIM3;
  b_p.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S3>/Timer Capture' */
  b_p.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b_p);
  enableTimerInterrupts(obj->TimerHandle, 2);
  for (i = 0; i < 16; i++) {
    /* Start for MATLABSystem: '<S3>/Timer Capture' */
    obj->TimerInternalBuffer[i] = 0U;
  }

  /* Start for MATLABSystem: '<S3>/Timer Capture' */
  b.buffer.bufferPtr16Bit = (uint16_T *)(&obj->TimerInternalBuffer[0]);
  b.dmaPeripheralPtr = DMA1;
  b.dmastream = LL_DMA_STREAM_4;
  b.buffer.bufferSize = 16U;
  b.buffer.bufferPtr32Bit = NULL;
  b.buffer.readPos = 0U;
  b.buffer.writeRollOver = false;
  b.errorStatus = 0U;
  configureDMAForChannel(obj->TimerHandle, b, 1);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S3>/Timer Capture' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void HalltimerInt_SystemCore_setup_g(stm32cube_blocks_AnalogInput__T *obj)
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
  adcStructLoc.InternalBufferSize = 3U;
  adcStructLoc.InjectedNoOfConversion = 3U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

static void HalltimerIn_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ha_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S27>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S27>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S27>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/* Model step function */
void HalltimerInterface_step(void)
{
  GPIO_TypeDef * portNameLoc;
  int32_T c;
  uint32_T pinReadLoc;

  /* MATLABSystem: '<S9>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOA);

  /* MATLABSystem: '<S11>/Digital Port Write' incorporates:
   *  MATLABSystem: '<S9>/Digital Port Read'
   * */
  portNameLoc = GPIOA;
  if ((pinReadLoc & 64U) != 0U) {
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
  HalltimerInterface_M->Timing.taskTime0 =
    ((time_T)(++HalltimerInterface_M->Timing.clockTick0)) *
    HalltimerInterface_M->Timing.stepSize0;
}

/* Model initialize function */
void HalltimerInterface_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(HalltimerInterface_M, -1);
  HalltimerInterface_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  HalltimerInterface_M->Sizes.checksums[0] = (1468969849U);
  HalltimerInterface_M->Sizes.checksums[1] = (1823062893U);
  HalltimerInterface_M->Sizes.checksums[2] = (2811512700U);
  HalltimerInterface_M->Sizes.checksums[3] = (3668837322U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[11];
    HalltimerInterface_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = (sysRanDType *)
      &HalltimerInterface_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = (sysRanDType *)
      &HalltimerInterface_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[5] = (sysRanDType *)
      &HalltimerInterface_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[6] = (sysRanDType *)
      &HalltimerInterface_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[7] = (sysRanDType *)
      &HalltimerInterface_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[8] = (sysRanDType *)
      &HalltimerInterface_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[9] = &rtAlwaysEnabled;
    systemRan[10] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(HalltimerInterface_M->extModeInfo,
      &HalltimerInterface_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(HalltimerInterface_M->extModeInfo,
                        HalltimerInterface_M->Sizes.checksums);
    rteiSetTPtr(HalltimerInterface_M->extModeInfo, rtmGetTPtr
                (HalltimerInterface_M));
  }

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  HalltimerInterface_M->Timing.clockTick1 =
    HalltimerInterface_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S12>/Output' */
  HalltimerInterface_DW.Output_DSTATE_k =
    HalltimerInterface_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<S3>/Timer Capture' */
  HalltimerInterface_DW.obj.isInitialized = 0;
  HalltimerInterface_DW.obj.matlabCodegenIsDeleted = false;
  HalltimerInter_SystemCore_setup(&HalltimerInterface_DW.obj);

  /* SystemInitialize for DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
   *  Outport: '<S3>/Out1'
   */
  HalltimerInterface_B.DataTypeConversion_b = HalltimerInterface_P.Out1_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S24>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem1'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem1' */
  HalltimerInterface_M->Timing.clockTick2 =
    HalltimerInterface_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S16>/Output' */
  HalltimerInterface_DW.Output_DSTATE =
    HalltimerInterface_P.Output_InitialCondition_j;

  /* Start for MATLABSystem: '<S18>/Analog to Digital Converter' */
  HalltimerInterface_DW.obj_j.isInitialized = 0;
  HalltimerInterface_DW.obj_j.matlabCodegenIsDeleted = false;
  HalltimerInt_SystemCore_setup_g(&HalltimerInterface_DW.obj_j);

  /* SystemInitialize for DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
   *  Outport: '<S4>/Out1'
   */
  HalltimerInterface_B.DataTypeConversion = HalltimerInterface_P.Out1_Y0_b;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S24>/Hardware Interrupt' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Parameters' */
  /* Start for MATLABSystem: '<S27>/PWM Output' */
  HalltimerInterface_DW.obj_o.matlabCodegenIsDeleted = false;
  HalltimerInterface_DW.obj_o.isSetupComplete = false;
  HalltimerInterface_DW.obj_o.isInitialized = 1;
  HalltimerIn_PWMOutput_setupImpl(&HalltimerInterface_DW.obj_o);
  HalltimerInterface_DW.obj_o.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Parameters' */

  /* Outputs for Atomic SubSystem: '<Root>/Parameters' */
  /* MATLABSystem: '<S27>/PWM Output' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  setDutyCycleInPercentageChannel1(HalltimerInterface_DW.obj_o.TimerHandle,
    HalltimerInterface_P.Constant1_Value);
  setDutyCycleInPercentageChannel2(HalltimerInterface_DW.obj_o.TimerHandle,
    HalltimerInterface_P.Constant1_Value);
  setDutyCycleInPercentageChannel3(HalltimerInterface_DW.obj_o.TimerHandle,
    HalltimerInterface_P.Constant1_Value);

  /* End of Outputs for SubSystem: '<Root>/Parameters' */
}

/* Model terminate function */
void HalltimerInterface_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S3>/Timer Capture' */
  if (!HalltimerInterface_DW.obj.matlabCodegenIsDeleted) {
    HalltimerInterface_DW.obj.matlabCodegenIsDeleted = true;
    if ((HalltimerInterface_DW.obj.isInitialized == 1) &&
        HalltimerInterface_DW.obj.isSetupComplete) {
      disableCounter(HalltimerInterface_DW.obj.TimerHandle);
      disableTimerInterrupts(HalltimerInterface_DW.obj.TimerHandle, 2);
      disableTimerChannel1(HalltimerInterface_DW.obj.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Timer Capture' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S24>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S24>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem1'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem1' */

  /* Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */
  if (!HalltimerInterface_DW.obj_j.matlabCodegenIsDeleted) {
    HalltimerInterface_DW.obj_j.matlabCodegenIsDeleted = true;
    if ((HalltimerInterface_DW.obj_j.isInitialized == 1) &&
        HalltimerInterface_DW.obj_j.isSetupComplete) {
      ADC_Handle_Deinit(HalltimerInterface_DW.obj_j.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S18>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S24>/Hardware Interrupt' */

  /* Terminate for Atomic SubSystem: '<Root>/Parameters' */
  /* Terminate for MATLABSystem: '<S27>/PWM Output' */
  if (!HalltimerInterface_DW.obj_o.matlabCodegenIsDeleted) {
    HalltimerInterface_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((HalltimerInterface_DW.obj_o.isInitialized == 1) &&
        HalltimerInterface_DW.obj_o.isSetupComplete) {
      disableCounter(HalltimerInterface_DW.obj_o.TimerHandle);
      disableTimerInterrupts(HalltimerInterface_DW.obj_o.TimerHandle, 0);
      disableTimerChannel1(HalltimerInterface_DW.obj_o.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(HalltimerInterface_DW.obj_o.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(HalltimerInterface_DW.obj_o.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S27>/PWM Output' */
  /* End of Terminate for SubSystem: '<Root>/Parameters' */
}

void HalltimerInterface_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(44,&TIM3_IRQHandler,2);
  MW_NVIC_EnableIRQ(44);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S22>/Hardware Interrupt' */
void TIM3_IRQHandler(void)
{
  /* Event: TIM3 CC1 */
  /* Check event TIM3 CC1 occurred */
  if (0 != (
#if defined(MW_TIM3_ENABLED) && defined(MW_TIM3_CAPTURE_VAR)
            (0 != LL_TIM_IsEnabledIT_CC1(TIM3)) && (0 != TIM_IsActiveFlag_CC1
        (&(MW_TIM3_CAPTURE_VAR)))
#else
            (0 != LL_TIM_IsEnabledIT_CC1(TIM3)) && (0 != LL_TIM_IsActiveFlag_CC1
        (TIM3))
#endif
            )) {
    /* Clear occurred TIM3 CC1 event */
    LL_TIM_ClearFlag_CC1(TIM3);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(HalltimerInterface_DW.FunctionCallSubsystem_SubsysRan);

        /* S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          uint32_T length;
          uint16_T tmp[16];
          uint16_T rtb_FixPtSum1;
          HalltimerInterface_M->Timing.clockTick1 =
            HalltimerInterface_M->Timing.clockTick0;

          /* Sum: '<S13>/FixPt Sum1' incorporates:
           *  Constant: '<S13>/FixPt Constant'
           *  UnitDelay: '<S12>/Output'
           */
          rtb_FixPtSum1 = (uint16_T)((uint32_T)
            HalltimerInterface_DW.Output_DSTATE_k +
            HalltimerInterface_P.FixPtConstant_Value);

          /* DataTypeConversion: '<S3>/Data Type Conversion' incorporates:
           *  UnitDelay: '<S12>/Output'
           */
          HalltimerInterface_B.DataTypeConversion_b =
            HalltimerInterface_DW.Output_DSTATE_k;

          /* MATLABSystem: '<S3>/Timer Capture' */
          getCCR1RegisterValueDMAMode(HalltimerInterface_DW.obj.TimerHandle,
            &tmp[0], 16U, &length);

          /* Switch: '<S14>/FixPt Switch' */
          if (rtb_FixPtSum1 > HalltimerInterface_P.WrapToZero_Threshold) {
            /* Update for UnitDelay: '<S12>/Output' incorporates:
             *  Constant: '<S14>/Constant'
             */
            HalltimerInterface_DW.Output_DSTATE_k =
              HalltimerInterface_P.Constant_Value;
          } else {
            /* Update for UnitDelay: '<S12>/Output' */
            HalltimerInterface_DW.Output_DSTATE_k = rtb_FixPtSum1;
          }

          /* End of Switch: '<S14>/FixPt Switch' */
          HalltimerInterface_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S22>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((HalltimerInterface_M->Timing.clockTick1) * 0.2);
      extmodeEvent(1,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S24>/Hardware Interrupt' */
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
        /* Reset subsysRan breadcrumbs */
        srClearBC(HalltimerInterface_DW.FunctionCallSubsystem1_SubsysRa);

        /* S-Function (HardwareInterrupt_sfun): '<S24>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */
        {
          uint16_T tmp[3];
          uint16_T rtb_FixPtSum1;
          HalltimerInterface_M->Timing.clockTick2 =
            HalltimerInterface_M->Timing.clockTick0;

          /* Sum: '<S19>/FixPt Sum1' incorporates:
           *  Constant: '<S19>/FixPt Constant'
           *  UnitDelay: '<S16>/Output'
           */
          rtb_FixPtSum1 = (uint16_T)((uint32_T)
            HalltimerInterface_DW.Output_DSTATE +
            HalltimerInterface_P.FixPtConstant_Value_n);

          /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
           *  UnitDelay: '<S16>/Output'
           */
          HalltimerInterface_B.DataTypeConversion =
            HalltimerInterface_DW.Output_DSTATE;

          /* MATLABSystem: '<S18>/Analog to Digital Converter' */
          injectedReadADCIntr(HalltimerInterface_DW.obj_j.ADCHandle, ADC_READ,
                              &tmp[0]);

          /* Switch: '<S20>/FixPt Switch' */
          if (rtb_FixPtSum1 > HalltimerInterface_P.WrapToZero_Threshold_a) {
            /* Update for UnitDelay: '<S16>/Output' incorporates:
             *  Constant: '<S20>/Constant'
             */
            HalltimerInterface_DW.Output_DSTATE =
              HalltimerInterface_P.Constant_Value_a;
          } else {
            /* Update for UnitDelay: '<S16>/Output' */
            HalltimerInterface_DW.Output_DSTATE = rtb_FixPtSum1;
          }

          /* End of Switch: '<S20>/FixPt Switch' */
          HalltimerInterface_DW.FunctionCallSubsystem1_SubsysRa = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S24>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((HalltimerInterface_M->Timing.clockTick2) * 0.2);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void HalltimerInterface_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(44);
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
