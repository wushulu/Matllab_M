/*
 * File: hallcorrection.c
 *
 * Code generated for Simulink model 'hallcorrection'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Oct 12 17:20:40 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "hallcorrection.h"
#include "hallcorrection_types.h"
#include "hallcorrection_private.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_hallcorrection_T hallcorrection_B;

/* Block states (default storage) */
DW_hallcorrection_T hallcorrection_DW;

/* Real-time model */
static RT_MODEL_hallcorrection_T hallcorrection_M_;
RT_MODEL_hallcorrection_T *const hallcorrection_M = &hallcorrection_M_;

/* Forward declaration for local functions */
static void hallcorrection_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void hallcorrect_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_ha_T *obj);
static void hallcorrection_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
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

static void hallcorrect_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_ha_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S11>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S11>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S11>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/* Model step function */
void hallcorrection_step(void)
{
  /* RateTransition: '<Root>/Rate Transition' */
  hallcorrection_B.RateTransition = hallcorrection_B.Output;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  hallcorrection_M->Timing.taskTime0 =
    ((time_T)(++hallcorrection_M->Timing.clockTick0)) *
    hallcorrection_M->Timing.stepSize0;
}

/* Model initialize function */
void hallcorrection_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(hallcorrection_M, -1);
  hallcorrection_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  hallcorrection_M->Sizes.checksums[0] = (1931373417U);
  hallcorrection_M->Sizes.checksums[1] = (2314053800U);
  hallcorrection_M->Sizes.checksums[2] = (710172439U);
  hallcorrection_M->Sizes.checksums[3] = (2727720031U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[5];
    hallcorrection_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[2] = (sysRanDType *)
      &hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[3] = (sysRanDType *)
      &hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[4] = (sysRanDType *)
      &hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    rteiSetModelMappingInfoPtr(hallcorrection_M->extModeInfo,
      &hallcorrection_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(hallcorrection_M->extModeInfo,
                        hallcorrection_M->Sizes.checksums);
    rteiSetTPtr(hallcorrection_M->extModeInfo, rtmGetTPtr(hallcorrection_M));
  }

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  hallcorrection_M->Timing.clockTick1 = hallcorrection_M->Timing.clockTick0;

  /* InitializeConditions for Sum: '<S8>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S4>/Output'
   */
  hallcorrection_DW.Output_DSTATE = hallcorrection_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<S7>/Analog to Digital Converter' */
  hallcorrection_DW.obj.isInitialized = 0;
  hallcorrection_DW.obj.matlabCodegenIsDeleted = false;
  hallcorrection_SystemCore_setup(&hallcorrection_DW.obj);

  /* Start for MATLABSystem: '<S11>/PWM Output' */
  hallcorrection_DW.obj_d.matlabCodegenIsDeleted = false;
  hallcorrection_DW.obj_d.isSetupComplete = false;
  hallcorrection_DW.obj_d.isInitialized = 1;
  hallcorrect_PWMOutput_setupImpl(&hallcorrection_DW.obj_d);
  hallcorrection_DW.obj_d.isSetupComplete = true;

  /* SystemInitialize for UnitDelay: '<S4>/Output' incorporates:
   *  Outport: '<S1>/Out1'
   */
  hallcorrection_B.Output = hallcorrection_P.Out1_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' */
}

/* Model terminate function */
void hallcorrection_terminate(void)
{
  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S7>/Analog to Digital Converter' */
  if (!hallcorrection_DW.obj.matlabCodegenIsDeleted) {
    hallcorrection_DW.obj.matlabCodegenIsDeleted = true;
    if ((hallcorrection_DW.obj.isInitialized == 1) &&
        hallcorrection_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(hallcorrection_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S7>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S11>/PWM Output' */
  if (!hallcorrection_DW.obj_d.matlabCodegenIsDeleted) {
    hallcorrection_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((hallcorrection_DW.obj_d.isInitialized == 1) &&
        hallcorrection_DW.obj_d.isSetupComplete) {
      disableCounter(hallcorrection_DW.obj_d.TimerHandle);
      disableTimerInterrupts(hallcorrection_DW.obj_d.TimerHandle, 0);
      disableTimerChannel1(hallcorrection_DW.obj_d.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(hallcorrection_DW.obj_d.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(hallcorrection_DW.obj_d.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S11>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' */
}

void hallcorrection_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S13>/Hardware Interrupt' */
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
        srClearBC(hallcorrection_DW.FunctionCallSubsystem_SubsysRan);

        /* S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          uint16_T tmp[2];
          hallcorrection_M->Timing.clockTick1 =
            hallcorrection_M->Timing.clockTick0;

          /* MATLABSystem: '<S7>/Analog to Digital Converter' */
          injectedReadADCIntr(hallcorrection_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* UnitDelay: '<S4>/Output' */
          hallcorrection_B.Output = hallcorrection_DW.Output_DSTATE;

          /* Sum: '<S8>/FixPt Sum1' incorporates:
           *  Constant: '<S8>/FixPt Constant'
           */
          hallcorrection_DW.Output_DSTATE = (uint16_T)((uint32_T)
            hallcorrection_B.Output + hallcorrection_P.FixPtConstant_Value);

          /* MATLABSystem: '<S11>/PWM Output' incorporates:
           *  Constant: '<S1>/Constant'
           */
          setDutyCycleInPercentageChannel1(hallcorrection_DW.obj_d.TimerHandle,
            hallcorrection_P.Constant_Value);
          setDutyCycleInPercentageChannel2(hallcorrection_DW.obj_d.TimerHandle,
            hallcorrection_P.Constant_Value);
          setDutyCycleInPercentageChannel3(hallcorrection_DW.obj_d.TimerHandle,
            hallcorrection_P.Constant_Value);

          /* Switch: '<S9>/FixPt Switch' */
          if (hallcorrection_DW.Output_DSTATE >
              hallcorrection_P.WrapToZero_Threshold) {
            /* Sum: '<S8>/FixPt Sum1' incorporates:
             *  Constant: '<S9>/Constant'
             *  UnitDelay: '<S4>/Output'
             */
            hallcorrection_DW.Output_DSTATE = hallcorrection_P.Constant_Value_f;
          }

          /* End of Switch: '<S9>/FixPt Switch' */
          hallcorrection_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S13>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((hallcorrection_M->Timing.clockTick1) * 0.001);
      extmodeEvent(1,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void hallcorrection_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
