/*
 * File: RunningMotor.c
 *
 * Code generated for Simulink model 'RunningMotor'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Oct 18 11:53:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "RunningMotor.h"
#include "RunningMotor_types.h"
#include "RunningMotor_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "arm_math.h"
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_RunningMotor_T RunningMotor_B;

/* Block states (default storage) */
DW_RunningMotor_T RunningMotor_DW;

/* Real-time model */
static RT_MODEL_RunningMotor_T RunningMotor_M_;
RT_MODEL_RunningMotor_T *const RunningMotor_M = &RunningMotor_M_;

/* Forward declaration for local functions */
static void RunningMotor_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void RunningMoto_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ru_T *obj);

/* Forward declaration for local functions */
static void RunningMo_PWMOutput_setupImpl_n(stm32cube_blocks_PWMOutput_Ru_T *obj);
static void RunningMotor_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S10>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S10>/Analog to Digital Converter' */
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

static void RunningMoto_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ru_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S45>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S45>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S45>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void RunningMo_PWMOutput_setupImpl_n(stm32cube_blocks_PWMOutput_Ru_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S61>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S61>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S61>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/* Model step function */
void RunningMotor_step(void)
{
  /* RateTransition: '<Root>/RT1' */
  RunningMotor_B.PWM = RunningMotor_B.Sum6;

  /* RateTransition: '<Root>/RT3' */
  RunningMotor_B.testct = RunningMotor_B.Output;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  RunningMotor_M->Timing.taskTime0 =
    ((time_T)(++RunningMotor_M->Timing.clockTick0)) *
    RunningMotor_M->Timing.stepSize0;
}

/* Model initialize function */
void RunningMotor_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(RunningMotor_M, -1);
  RunningMotor_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  RunningMotor_M->Sizes.checksums[0] = (2373132326U);
  RunningMotor_M->Sizes.checksums[1] = (1250444794U);
  RunningMotor_M->Sizes.checksums[2] = (1843865801U);
  RunningMotor_M->Sizes.checksums[3] = (2195526022U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[26];
    RunningMotor_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&RunningMotor_DW.Subsystem_SubsysRanBC_dk;
    systemRan[5] = (sysRanDType *)
      &RunningMotor_DW.IfActionSubsystem_SubsysRanBC_m;
    systemRan[6] = (sysRanDType *)
      &RunningMotor_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&RunningMotor_DW.Subsystem_SubsysRanBC_d;
    systemRan[8] = (sysRanDType *)&RunningMotor_DW.Accumulate_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&RunningMotor_DW.UpCounter_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&RunningMotor_DW.PosGen_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&RunningMotor_DW.Subsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&RunningMotor_DW.Subsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&RunningMotor_DW.Subsystem_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&RunningMotor_DW.FindOffset_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &RunningMotor_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &RunningMotor_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&RunningMotor_DW.Subsystem1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[22] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&RunningMotor_DW.ADCSIC_SubsysRanBC;
    systemRan[24] = &rtAlwaysEnabled;
    systemRan[25] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(RunningMotor_M->extModeInfo,
      &RunningMotor_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(RunningMotor_M->extModeInfo,
                        RunningMotor_M->Sizes.checksums);
    rteiSetTPtr(RunningMotor_M->extModeInfo, rtmGetTPtr(RunningMotor_M));
  }

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S58>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */

  /* System initialize for function-call system: '<Root>/ADC SIC' */
  RunningMotor_M->Timing.clockTick1 = RunningMotor_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S5>/Output' */
  RunningMotor_DW.Output_DSTATE = RunningMotor_P.Output_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S7>/PosGen' */
  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  RunningMotor_DW.UnitDelay_DSTATE_e =
    RunningMotor_P.UnitDelay_InitialCondition_h;

  /* SystemInitialize for IfAction SubSystem: '<S18>/If Action Subsystem2' */
  /* InitializeConditions for Saturate: '<S21>/Saturate to 'motor.calibSpeed' RPM' incorporates:
   *  Delay: '<S21>/Delay'
   */
  RunningMotor_DW.Delay_DSTATE_f = RunningMotor_P.Delay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S18>/If Action Subsystem2' */

  /* SystemInitialize for Enabled SubSystem: '<S22>/Accumulate' */
  /* InitializeConditions for Delay: '<S23>/Delay' */
  RunningMotor_DW.Delay_DSTATE_k = RunningMotor_P.Delay_InitialCondition_n;

  /* SystemInitialize for Enabled SubSystem: '<S23>/Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S24>/Input' incorporates:
   *  Outport: '<S24>/Out1'
   */
  RunningMotor_B.Input = RunningMotor_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S23>/Subsystem' */

  /* SystemInitialize for Sum: '<S23>/Add1' incorporates:
   *  Outport: '<S23>/theta_e'
   */
  RunningMotor_B.Add1_n = RunningMotor_P.theta_e_Y0;

  /* End of SystemInitialize for SubSystem: '<S22>/Accumulate' */

  /* SystemInitialize for Enabled SubSystem: '<S13>/Up Counter' */
  /* InitializeConditions for Delay: '<S19>/Delay' */
  RunningMotor_DW.Delay_DSTATE_n = RunningMotor_P.Delay_InitialCondition_p;

  /* SystemInitialize for Sum: '<S19>/Add1' incorporates:
   *  Outport: '<S19>/Count'
   */
  RunningMotor_B.Add1_h = RunningMotor_P.Count_Y0;

  /* End of SystemInitialize for SubSystem: '<S13>/Up Counter' */

  /* SystemInitialize for Gain: '<S22>/scaleOut' incorporates:
   *  Outport: '<S13>/Theta'
   */
  RunningMotor_B.scaleOut = RunningMotor_P.Theta_Y0;

  /* SystemInitialize for RelationalOperator: '<S16>/Compare' incorporates:
   *  Outport: '<S13>/EnPWM'
   */
  RunningMotor_B.Compare = RunningMotor_P.EnPWM_Y0;

  /* End of SystemInitialize for SubSystem: '<S7>/PosGen' */

  /* SystemInitialize for Enabled SubSystem: '<S8>/Find Offset' */
  /* InitializeConditions for Delay: '<S25>/Delay' */
  RunningMotor_DW.Delay_DSTATE = RunningMotor_P.Delay_InitialCondition_i;

  /* SystemInitialize for Enabled SubSystem: '<S25>/Subsystem' */
  /* InitializeConditions for UnitDelay: '<S36>/Unit Delay' */
  RunningMotor_DW.UnitDelay_DSTATE = RunningMotor_P.UnitDelay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S25>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S8>/Find Offset' */

  /* Start for MATLABSystem: '<S10>/Analog to Digital Converter' */
  RunningMotor_DW.obj.isInitialized = 0;
  RunningMotor_DW.obj.matlabCodegenIsDeleted = false;
  RunningMotor_SystemCore_setup(&RunningMotor_DW.obj);

  /* Start for MATLABSystem: '<S45>/PWM Output' */
  RunningMotor_DW.obj_h.matlabCodegenIsDeleted = false;
  RunningMotor_DW.obj_h.isSetupComplete = false;
  RunningMotor_DW.obj_h.isInitialized = 1;
  RunningMoto_PWMOutput_setupImpl(&RunningMotor_DW.obj_h);
  RunningMotor_DW.obj_h.isSetupComplete = true;

  /* SystemInitialize for UnitDelay: '<S5>/Output' incorporates:
   *  Outport: '<S1>/ct'
   */
  RunningMotor_B.Output = RunningMotor_P.ct_Y0;

  /* SystemInitialize for Sum: '<S37>/Sum6' incorporates:
   *  Outport: '<S1>/PWM'
   */
  RunningMotor_B.Sum6 = RunningMotor_P.PWM_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S58>/Hardware Interrupt' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Parameters' */
  /* Start for MATLABSystem: '<S61>/PWM Output' */
  RunningMotor_DW.obj_m.matlabCodegenIsDeleted = false;
  RunningMotor_DW.obj_m.isSetupComplete = false;
  RunningMotor_DW.obj_m.isInitialized = 1;
  RunningMo_PWMOutput_setupImpl_n(&RunningMotor_DW.obj_m);
  RunningMotor_DW.obj_m.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Parameters' */

  /* Outputs for Atomic SubSystem: '<Root>/Parameters' */
  /* MATLABSystem: '<S61>/PWM Output' incorporates:
   *  Constant: '<S3>/Constant1'
   */
  setDutyCycleInPercentageChannel1(RunningMotor_DW.obj_m.TimerHandle,
    RunningMotor_P.Constant1_Value_a);
  setDutyCycleInPercentageChannel2(RunningMotor_DW.obj_m.TimerHandle,
    RunningMotor_P.Constant1_Value_a);
  setDutyCycleInPercentageChannel3(RunningMotor_DW.obj_m.TimerHandle,
    RunningMotor_P.Constant1_Value_a);

  /* End of Outputs for SubSystem: '<Root>/Parameters' */
}

/* Model terminate function */
void RunningMotor_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S58>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S58>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */
  /* Termination for function-call system: '<Root>/ADC SIC' */

  /* Terminate for MATLABSystem: '<S10>/Analog to Digital Converter' */
  if (!RunningMotor_DW.obj.matlabCodegenIsDeleted) {
    RunningMotor_DW.obj.matlabCodegenIsDeleted = true;
    if ((RunningMotor_DW.obj.isInitialized == 1) &&
        RunningMotor_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(RunningMotor_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S45>/PWM Output' */
  if (!RunningMotor_DW.obj_h.matlabCodegenIsDeleted) {
    RunningMotor_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((RunningMotor_DW.obj_h.isInitialized == 1) &&
        RunningMotor_DW.obj_h.isSetupComplete) {
      disableCounter(RunningMotor_DW.obj_h.TimerHandle);
      disableTimerInterrupts(RunningMotor_DW.obj_h.TimerHandle, 0);
      disableTimerChannel1(RunningMotor_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(RunningMotor_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(RunningMotor_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S45>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S58>/Hardware Interrupt' */

  /* Terminate for Atomic SubSystem: '<Root>/Parameters' */
  /* Terminate for MATLABSystem: '<S61>/PWM Output' */
  if (!RunningMotor_DW.obj_m.matlabCodegenIsDeleted) {
    RunningMotor_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((RunningMotor_DW.obj_m.isInitialized == 1) &&
        RunningMotor_DW.obj_m.isSetupComplete) {
      disableCounter(RunningMotor_DW.obj_m.TimerHandle);
      disableTimerInterrupts(RunningMotor_DW.obj_m.TimerHandle, 0);
      disableTimerChannel1(RunningMotor_DW.obj_m.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(RunningMotor_DW.obj_m.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(RunningMotor_DW.obj_m.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S61>/PWM Output' */
  /* End of Terminate for SubSystem: '<Root>/Parameters' */
}

void RunningMotor_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S58>/Hardware Interrupt' */
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
        srClearBC(RunningMotor_DW.Subsystem_SubsysRanBC_dk);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.IfActionSubsystem_SubsysRanBC_m);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.IfActionSubsystem2_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.Subsystem_SubsysRanBC_d);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.Accumulate_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.UpCounter_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.PosGen_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.Subsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.FindOffset_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.IfActionSubsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.Subsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(RunningMotor_DW.ADCSIC_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S58>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC SIC' */
        {
          real_T rtb_Switch4_idx_0;
          real_T rtb_Switch4_idx_1;
          real_T rtb_Switch4_idx_2;
          real32_T rtb_Add_f;
          real32_T rtb_Merge;
          real32_T rtb_algDD_o2;
          real32_T rtb_sum_beta;
          uint16_T tmp[3];
          uint16_T rtb_Get_Integer;
          RunningMotor_M->Timing.clockTick1 = RunningMotor_M->Timing.clockTick0;

          /* MATLABSystem: '<S10>/Analog to Digital Converter' */
          injectedReadADCIntr(RunningMotor_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* UnitDelay: '<S5>/Output' */
          RunningMotor_B.Output = RunningMotor_DW.Output_DSTATE;

          /* Sum: '<S11>/FixPt Sum1' incorporates:
           *  Constant: '<S11>/FixPt Constant'
           */
          rtb_Get_Integer = (uint16_T)((uint32_T)RunningMotor_B.Output +
            RunningMotor_P.FixPtConstant_Value);

          /* Switch: '<S12>/FixPt Switch' */
          if (rtb_Get_Integer > RunningMotor_P.WrapToZero_Threshold) {
            /* Update for UnitDelay: '<S5>/Output' incorporates:
             *  Constant: '<S12>/Constant'
             */
            RunningMotor_DW.Output_DSTATE = RunningMotor_P.Constant_Value_g;
          } else {
            /* Update for UnitDelay: '<S5>/Output' */
            RunningMotor_DW.Output_DSTATE = rtb_Get_Integer;
          }

          /* End of Switch: '<S12>/FixPt Switch' */

          /* Outputs for Enabled SubSystem: '<S7>/PosGen' incorporates:
           *  EnablePort: '<S13>/Enable'
           */
          /* Constant: '<S1>/Constant1' */
          if (RunningMotor_P.Constant1_Value_p > 0.0) {
            if (!RunningMotor_DW.PosGen_MODE) {
              /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
              RunningMotor_DW.UnitDelay_DSTATE_e =
                RunningMotor_P.UnitDelay_InitialCondition_h;
              RunningMotor_DW.PosGen_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S13>/Up Counter' incorporates:
             *  EnablePort: '<S19>/Enable'
             */
            if (RunningMotor_P.Constant1_Value_p > 0.0) {
              uint64_T tmp_p;
              if (!RunningMotor_DW.UpCounter_MODE) {
                /* InitializeConditions for Delay: '<S19>/Delay' */
                RunningMotor_DW.Delay_DSTATE_n =
                  RunningMotor_P.Delay_InitialCondition_p;
                RunningMotor_DW.UpCounter_MODE = true;
              }

              /* Sum: '<S19>/Add1' incorporates:
               *  Constant: '<S19>/Constant'
               *  Delay: '<S19>/Delay'
               */
              tmp_p = (uint64_T)RunningMotor_P.Constant_Value_n +
                RunningMotor_DW.Delay_DSTATE_n;
              if (tmp_p > 4294967295ULL) {
                tmp_p = 4294967295ULL;
              }

              /* Sum: '<S19>/Add1' */
              RunningMotor_B.Add1_h = (uint32_T)tmp_p;

              /* Update for Delay: '<S19>/Delay' */
              RunningMotor_DW.Delay_DSTATE_n = RunningMotor_B.Add1_h;
              RunningMotor_DW.UpCounter_SubsysRanBC = 4;
            } else if (RunningMotor_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S19>/Add1' incorporates:
               *  Outport: '<S19>/Count'
               */
              RunningMotor_B.Add1_h = RunningMotor_P.Count_Y0;
              RunningMotor_DW.UpCounter_MODE = false;
            }

            /* End of Outputs for SubSystem: '<S13>/Up Counter' */

            /* RelationalOperator: '<S16>/Compare' incorporates:
             *  Constant: '<S16>/Constant'
             */
            RunningMotor_B.Compare = (RunningMotor_B.Add1_h <=
              RunningMotor_P.EnablePWMfor40seconds_const);

            /* If: '<S18>/If' incorporates:
             *  Constant: '<S18>/Count for 2 sec'
             */
            if (RunningMotor_B.Add1_h < RunningMotor_P.Countfor2sec_Value) {
              /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem' incorporates:
               *  ActionPort: '<S20>/Action Port'
               */
              /* SignalConversion generated from: '<S20>/Out1' incorporates:
               *  Constant: '<S20>/Constant'
               */
              rtb_Merge = RunningMotor_P.Constant_Value;

              /* End of Outputs for SubSystem: '<S18>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S18>/If Action Subsystem' incorporates:
               *  ActionPort: '<S20>/Action Port'
               */
              /* Update for If: '<S18>/If' */
              RunningMotor_DW.IfActionSubsystem_SubsysRanBC_m = 4;

              /* End of Update for SubSystem: '<S18>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S18>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S21>/Action Port'
               */
              /* Saturate: '<S21>/Saturate to 'motor.calibSpeed' RPM' incorporates:
               *  Constant: '<S21>/Constant1'
               *  Delay: '<S21>/Delay'
               *  Sum: '<S21>/Add1'
               */
              RunningMotor_DW.Delay_DSTATE_f += RunningMotor_P.Constant1_Value_e;

              /* Saturate: '<S21>/Saturate to 'motor.calibSpeed' RPM' */
              if (RunningMotor_DW.Delay_DSTATE_f >
                  RunningMotor_P.SaturatetomotorcalibSpeedRPM_Up) {
                /* Saturate: '<S21>/Saturate to 'motor.calibSpeed' RPM' */
                RunningMotor_DW.Delay_DSTATE_f =
                  RunningMotor_P.SaturatetomotorcalibSpeedRPM_Up;
              } else if (RunningMotor_DW.Delay_DSTATE_f <
                         RunningMotor_P.SaturatetomotorcalibSpeedRPM_Lo) {
                /* Saturate: '<S21>/Saturate to 'motor.calibSpeed' RPM' */
                RunningMotor_DW.Delay_DSTATE_f =
                  RunningMotor_P.SaturatetomotorcalibSpeedRPM_Lo;
              }

              /* End of Saturate: '<S21>/Saturate to 'motor.calibSpeed' RPM' */

              /* Gain: '<S21>/Multiply' */
              rtb_Merge = RunningMotor_P.Multiply_Gain *
                RunningMotor_DW.Delay_DSTATE_f;

              /* End of Outputs for SubSystem: '<S18>/If Action Subsystem2' */

              /* Update for IfAction SubSystem: '<S18>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S21>/Action Port'
               */
              /* Update for If: '<S18>/If' */
              RunningMotor_DW.IfActionSubsystem2_SubsysRanBC = 4;

              /* End of Update for SubSystem: '<S18>/If Action Subsystem2' */
            }

            /* End of If: '<S18>/If' */

            /* Outputs for Enabled SubSystem: '<S22>/Accumulate' incorporates:
             *  EnablePort: '<S23>/Enable'
             */
            /* Logic: '<S22>/NOT' incorporates:
             *  Constant: '<S22>/Constant_Reset'
             *  Delay: '<S23>/Delay'
             */
            if (!RunningMotor_P.Constant_Reset_Value) {
              /* Outputs for Enabled SubSystem: '<S23>/Subsystem' incorporates:
               *  EnablePort: '<S24>/Enable'
               */
              if (RunningMotor_DW.Delay_DSTATE_k) {
                /* SignalConversion generated from: '<S24>/Input' incorporates:
                 *  Gain: '<S22>/scaleIn'
                 */
                RunningMotor_B.Input = RunningMotor_P.scaleIn_Gain * rtb_Merge;
                RunningMotor_DW.Subsystem_SubsysRanBC_d = 4;
              }

              /* End of Outputs for SubSystem: '<S23>/Subsystem' */

              /* Sum: '<S23>/Add' incorporates:
               *  Delay: '<S23>/Delay'
               *  UnitDelay: '<S22>/Unit Delay'
               */
              rtb_Add_f = RunningMotor_B.Input +
                RunningMotor_DW.UnitDelay_DSTATE_e;

              /* DataTypeConversion: '<S23>/Data Type Conversion' */
              rtb_Merge = floorf(rtb_Add_f);
              if (rtIsNaNF(rtb_Merge) || rtIsInfF(rtb_Merge)) {
                rtb_Merge = 0.0F;
              } else {
                rtb_Merge = fmodf(rtb_Merge, 65536.0F);
              }

              /* Sum: '<S23>/Add1' incorporates:
               *  DataTypeConversion: '<S23>/Data Type Conversion'
               *  DataTypeConversion: '<S23>/Data Type Conversion1'
               */
              RunningMotor_B.Add1_n = rtb_Add_f - (real32_T)(rtb_Merge < 0.0F ?
                (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Merge : (int32_T)
                (int16_T)(uint16_T)rtb_Merge);

              /* Update for Delay: '<S23>/Delay' incorporates:
               *  Constant: '<S23>/Constant'
               */
              RunningMotor_DW.Delay_DSTATE_k = RunningMotor_P.Constant_Value_nl;
              RunningMotor_DW.Accumulate_SubsysRanBC = 4;
            }

            /* End of Logic: '<S22>/NOT' */
            /* End of Outputs for SubSystem: '<S22>/Accumulate' */

            /* Gain: '<S22>/scaleOut' */
            RunningMotor_B.scaleOut = RunningMotor_P.scaleOut_Gain *
              RunningMotor_B.Add1_n;

            /* Update for UnitDelay: '<S22>/Unit Delay' */
            RunningMotor_DW.UnitDelay_DSTATE_e = RunningMotor_B.Add1_n;
            RunningMotor_DW.PosGen_SubsysRanBC = 4;
          } else if (RunningMotor_DW.PosGen_MODE) {
            /* Disable for Enabled SubSystem: '<S13>/Up Counter' */
            if (RunningMotor_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S19>/Add1' incorporates:
               *  Outport: '<S19>/Count'
               */
              RunningMotor_B.Add1_h = RunningMotor_P.Count_Y0;
              RunningMotor_DW.UpCounter_MODE = false;
            }

            /* End of Disable for SubSystem: '<S13>/Up Counter' */

            /* Disable for RelationalOperator: '<S16>/Compare' incorporates:
             *  Outport: '<S13>/EnPWM'
             */
            RunningMotor_B.Compare = RunningMotor_P.EnPWM_Y0;
            RunningMotor_DW.PosGen_MODE = false;
          }

          /* End of Constant: '<S1>/Constant1' */
          /* End of Outputs for SubSystem: '<S7>/PosGen' */

          /* Gain: '<S38>/convert_pu' */
          rtb_Add_f = RunningMotor_P.convert_pu_Gain * RunningMotor_B.scaleOut;

          /* If: '<S38>/If' incorporates:
           *  Constant: '<S39>/Constant'
           *  RelationalOperator: '<S39>/Compare'
           */
          if (rtb_Add_f < RunningMotor_P.Constant_Value_b) {
            /* Outputs for IfAction SubSystem: '<S38>/If Action Subsystem' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* DataTypeConversion: '<S40>/Convert_uint16' */
            rtb_Merge = floorf(rtb_Add_f);
            if (rtIsInfF(rtb_Merge)) {
              rtb_Merge = 0.0F;
            } else {
              rtb_Merge = fmodf(rtb_Merge, 65536.0F);
            }

            /* Sum: '<S40>/Sum' incorporates:
             *  DataTypeConversion: '<S40>/Convert_back'
             *  DataTypeConversion: '<S40>/Convert_uint16'
             */
            rtb_Add_f -= (real32_T)(rtb_Merge < 0.0F ? (int32_T)(int16_T)
              -(int16_T)(uint16_T)-rtb_Merge : (int32_T)(int16_T)(uint16_T)
              rtb_Merge);

            /* End of Outputs for SubSystem: '<S38>/If Action Subsystem' */

            /* Update for IfAction SubSystem: '<S38>/If Action Subsystem' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            /* Update for If: '<S38>/If' */
            RunningMotor_DW.IfActionSubsystem_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S38>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S38>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S41>/Action Port'
             */
            /* DataTypeConversion: '<S41>/Convert_uint16' */
            rtb_Merge = truncf(rtb_Add_f);
            if (rtIsNaNF(rtb_Merge) || rtIsInfF(rtb_Merge)) {
              rtb_Merge = 0.0F;
            } else {
              rtb_Merge = fmodf(rtb_Merge, 65536.0F);
            }

            /* Sum: '<S41>/Sum' incorporates:
             *  DataTypeConversion: '<S41>/Convert_back'
             *  DataTypeConversion: '<S41>/Convert_uint16'
             */
            rtb_Add_f -= (real32_T)(rtb_Merge < 0.0F ? (int32_T)(int16_T)
              -(int16_T)(uint16_T)-rtb_Merge : (int32_T)(int16_T)(uint16_T)
              rtb_Merge);

            /* End of Outputs for SubSystem: '<S38>/If Action Subsystem1' */

            /* Update for IfAction SubSystem: '<S38>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S41>/Action Port'
             */
            /* Update for If: '<S38>/If' */
            RunningMotor_DW.IfActionSubsystem1_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S38>/If Action Subsystem1' */
          }

          /* End of If: '<S38>/If' */

          /* Gain: '<S26>/indexing' */
          rtb_Add_f *= RunningMotor_P.indexing_Gain;

          /* DataTypeConversion: '<S26>/Get_Integer' */
          rtb_Merge = truncf(rtb_Add_f);
          if (rtIsNaNF(rtb_Merge) || rtIsInfF(rtb_Merge)) {
            rtb_Merge = 0.0F;
          } else {
            rtb_Merge = fmodf(rtb_Merge, 65536.0F);
          }

          rtb_Get_Integer = (uint16_T)(rtb_Merge < 0.0F ? (int32_T)(uint16_T)
            -(int16_T)(uint16_T)-rtb_Merge : (int32_T)(uint16_T)rtb_Merge);

          /* End of DataTypeConversion: '<S26>/Get_Integer' */

          /* Sum: '<S26>/Sum2' incorporates:
           *  DataTypeConversion: '<S26>/Data Type Conversion1'
           */
          rtb_sum_beta = rtb_Add_f - (real32_T)rtb_Get_Integer;

          /* Selector: '<S26>/Lookup' incorporates:
           *  Constant: '<S26>/offset'
           *  Constant: '<S26>/sine_table_values'
           *  Sum: '<S26>/Sum'
           *  Sum: '<S37>/Sum5'
           */
          rtb_Merge = RunningMotor_P.sine_table_values_Value[(int32_T)((uint32_T)
            RunningMotor_P.offset_Value[3] + rtb_Get_Integer)];

          /* Sum: '<S37>/Sum6' incorporates:
           *  Constant: '<S26>/offset'
           *  Constant: '<S26>/sine_table_values'
           *  Product: '<S37>/Product1'
           *  Selector: '<S26>/Lookup'
           *  Sum: '<S26>/Sum'
           *  Sum: '<S37>/Sum5'
           */
          RunningMotor_B.Sum6 = (RunningMotor_P.sine_table_values_Value[(int32_T)
            ((uint32_T)RunningMotor_P.offset_Value[2] + rtb_Get_Integer)] -
            rtb_Merge) * rtb_sum_beta + rtb_Merge;

          /* Selector: '<S26>/Lookup' incorporates:
           *  Constant: '<S26>/offset'
           *  Constant: '<S26>/sine_table_values'
           *  Sum: '<S26>/Sum'
           *  Sum: '<S37>/Sum3'
           */
          rtb_Merge = RunningMotor_P.sine_table_values_Value[(int32_T)((uint32_T)
            RunningMotor_P.offset_Value[1] + rtb_Get_Integer)];

          /* Outputs for Atomic SubSystem: '<S46>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S48>/a16' incorporates:
           *  Constant: '<S26>/offset'
           *  Constant: '<S26>/sine_table_values'
           *  Constant: '<S29>/Vd_Ref'
           *  Constant: '<S29>/Vq'
           *  Product: '<S37>/Product'
           *  Selector: '<S26>/Lookup'
           *  Sum: '<S26>/Sum'
           *  Sum: '<S37>/Sum3'
           *  Sum: '<S37>/Sum4'
           */
          arm_inv_park_f32(RunningMotor_P.Vd_Ref_Value, RunningMotor_P.Vq_Value,
                           &rtb_Add_f, &rtb_algDD_o2,
                           (RunningMotor_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)RunningMotor_P.offset_Value[0] +
                             rtb_Get_Integer)] - rtb_Merge) * rtb_sum_beta +
                           rtb_Merge, RunningMotor_B.Sum6);

          /* End of Outputs for SubSystem: '<S46>/Two inputs CRL' */

          /* Switch: '<S42>/Switch4' incorporates:
           *  Constant: '<S42>/Constant1'
           *  Constant: '<S42>/stop'
           *  Gain: '<S42>/Gain'
           *  Gain: '<S42>/Gain1'
           *  Gain: '<S52>/Gain'
           *  Sum: '<S42>/Add'
           *  Sum: '<S52>/Add1'
           *  Sum: '<S52>/Add2'
           *  Sum: '<S52>/Add3'
           */
          if (RunningMotor_B.Compare) {
            /* Gain: '<S56>/sqrt3_by_two' */
            rtb_sum_beta = RunningMotor_P.sqrt3_by_two_Gain * rtb_algDD_o2;

            /* Gain: '<S56>/one_by_two' */
            rtb_algDD_o2 = RunningMotor_P.one_by_two_Gain * rtb_Add_f;

            /* Gain: '<S56>/Kc' incorporates:
             *  Sum: '<S56>/add_c'
             */
            rtb_Merge = ((0.0F - rtb_algDD_o2) - rtb_sum_beta) *
              RunningMotor_P.Kc_Gain;

            /* Gain: '<S56>/Kb' incorporates:
             *  Sum: '<S56>/add_b'
             */
            rtb_algDD_o2 = (rtb_sum_beta - rtb_algDD_o2) *
              RunningMotor_P.Kb_Gain;

            /* Gain: '<S56>/Ka' */
            rtb_sum_beta = RunningMotor_P.Ka_Gain * rtb_Add_f;

            /* Gain: '<S53>/one_by_two' incorporates:
             *  MinMax: '<S53>/Max'
             *  MinMax: '<S53>/Min'
             *  Sum: '<S53>/Add'
             */
            rtb_Add_f = (fmaxf(fmaxf(rtb_sum_beta, rtb_algDD_o2), rtb_Merge) +
                         fminf(fminf(rtb_sum_beta, rtb_algDD_o2), rtb_Merge)) *
              RunningMotor_P.one_by_two_Gain_j;
            rtb_Switch4_idx_0 = ((rtb_sum_beta + rtb_Add_f) *
                                 RunningMotor_P.Gain_Gain *
                                 RunningMotor_P.Gain_Gain_e +
                                 RunningMotor_P.Constant1_Value) *
              RunningMotor_P.Gain1_Gain;
            rtb_Switch4_idx_1 = ((rtb_algDD_o2 + rtb_Add_f) *
                                 RunningMotor_P.Gain_Gain *
                                 RunningMotor_P.Gain_Gain_e +
                                 RunningMotor_P.Constant1_Value) *
              RunningMotor_P.Gain1_Gain;
            rtb_Switch4_idx_2 = ((rtb_Add_f + rtb_Merge) *
                                 RunningMotor_P.Gain_Gain *
                                 RunningMotor_P.Gain_Gain_e +
                                 RunningMotor_P.Constant1_Value) *
              RunningMotor_P.Gain1_Gain;
          } else {
            rtb_Switch4_idx_0 = RunningMotor_P.stop_Value;
            rtb_Switch4_idx_1 = RunningMotor_P.stop_Value;
            rtb_Switch4_idx_2 = RunningMotor_P.stop_Value;
          }

          /* End of Switch: '<S42>/Switch4' */

          /* MATLABSystem: '<S45>/PWM Output' */
          setDutyCycleInPercentageChannel1(RunningMotor_DW.obj_h.TimerHandle,
            rtb_Switch4_idx_0);
          setDutyCycleInPercentageChannel2(RunningMotor_DW.obj_h.TimerHandle,
            rtb_Switch4_idx_1);
          setDutyCycleInPercentageChannel3(RunningMotor_DW.obj_h.TimerHandle,
            rtb_Switch4_idx_2);

          /* Outputs for Enabled SubSystem: '<S8>/Find Offset' incorporates:
           *  EnablePort: '<S25>/Enable'
           */
          if (RunningMotor_B.Compare) {
            if (!RunningMotor_DW.FindOffset_MODE) {
              /* InitializeConditions for Delay: '<S25>/Delay' */
              RunningMotor_DW.Delay_DSTATE =
                RunningMotor_P.Delay_InitialCondition_i;
              RunningMotor_DW.FindOffset_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S25>/Subsystem' incorporates:
             *  EnablePort: '<S32>/Enable'
             */
            /* Logic: '<S25>/AND' incorporates:
             *  Constant: '<S30>/Constant'
             *  Constant: '<S31>/Constant'
             *  Delay: '<S25>/Delay'
             *  RelationalOperator: '<S30>/Compare'
             *  RelationalOperator: '<S31>/Compare'
             */
            if ((RunningMotor_B.scaleOut <=
                 RunningMotor_P.CompareToConstant_const) &&
                (RunningMotor_DW.Delay_DSTATE >=
                 RunningMotor_P.CompareToConstant1_const)) {
              /* Switch: '<S33>/Switch1' incorporates:
               *  Constant: '<S33>/FilterConstant'
               *  Constant: '<S33>/One'
               *  Constant: '<S33>/OneMinusFilterConstant'
               *  Constant: '<S33>/UseInputPort'
               *  Constant: '<S33>/a'
               *  Sum: '<S33>/Sum'
               */
              if (RunningMotor_P.UseInputPort_Value >
                  RunningMotor_P.Switch1_Threshold) {
                rtb_Switch4_idx_0 = RunningMotor_P.a_Value;
                rtb_Switch4_idx_1 = RunningMotor_P.One_Value -
                  RunningMotor_P.a_Value;
              } else {
                rtb_Switch4_idx_0 = RunningMotor_P.FilterConstant_Value;
                rtb_Switch4_idx_1 = RunningMotor_P.OneMinusFilterConstant_Value;
              }

              /* End of Switch: '<S33>/Switch1' */

              /* Update for UnitDelay: '<S36>/Unit Delay' incorporates:
               *  Product: '<S36>/Product'
               *  Product: '<S36>/Product1'
               *  Sum: '<S36>/Add1'
               */
              RunningMotor_DW.UnitDelay_DSTATE = 0.0 * rtb_Switch4_idx_0 +
                rtb_Switch4_idx_1 * RunningMotor_DW.UnitDelay_DSTATE;
              RunningMotor_DW.Subsystem_SubsysRanBC = 4;
            }

            /* End of Logic: '<S25>/AND' */
            /* End of Outputs for SubSystem: '<S25>/Subsystem' */

            /* Update for Delay: '<S25>/Delay' */
            RunningMotor_DW.Delay_DSTATE = RunningMotor_B.scaleOut;
            RunningMotor_DW.FindOffset_SubsysRanBC = 4;
          } else {
            RunningMotor_DW.FindOffset_MODE = false;

            /* Outputs for Enabled SubSystem: '<S8>/Subsystem1' incorporates:
             *  EnablePort: '<S28>/Enable'
             */
            RunningMotor_DW.Subsystem1_SubsysRanBC = 4;

            /* End of Outputs for SubSystem: '<S8>/Subsystem1' */
          }

          /* End of Outputs for SubSystem: '<S8>/Find Offset' */
          RunningMotor_DW.ADCSIC_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S58>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((RunningMotor_M->Timing.clockTick1) * 0.01);
      extmodeEvent(1,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void RunningMotor_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
