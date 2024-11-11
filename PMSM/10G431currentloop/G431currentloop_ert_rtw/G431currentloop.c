/*
 * File: G431currentloop.c
 *
 * Code generated for Simulink model 'G431currentloop'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Nov 11 12:27:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G431currentloop.h"
#include "G431currentloop_types.h"
#include "G431currentloop_private.h"
#include "rtwtypes.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "mw_cmsis.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "zero_crossing_types.h"
#include <string.h>
#include "rt_defines.h"

/* Block signals (default storage) */
B_G431currentloop_T G431currentloop_B;

/* Block states (default storage) */
DW_G431currentloop_T G431currentloop_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_G431currentloop_T G431currentloop_PrevZCX;

/* Real-time model */
static RT_MODEL_G431currentloop_T G431currentloop_M_;
RT_MODEL_G431currentloop_T *const G431currentloop_M = &G431currentloop_M_;

/* Forward declaration for local functions */
static void G431currentloo_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void G431current_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_G4_T *obj);
static void G431currentloo_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  void * internalBufferPtr;
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  internalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.InternalBufferPtr = internalBufferPtr;

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = NULL;
  adcStructLoc.dmastream = 0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 2U;
  adcStructLoc.InjectedNoOfConversion = 2U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS);
  enableADCAutomaticCalibrationOffset(obj->ADCHandle, 0);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

static void G431current_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_G4_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S204>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S204>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S204>/PWM Output' */
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

/* Model step function */
void G431currentloop_step(void)
{
  GPIO_TypeDef * portNameLoc;
  uint32_T pinReadLoc;
  boolean_T tmp;

  /* MATLABSystem: '<S9>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);
  tmp = ((pinReadLoc & 8192U) != 0U);

  /* MATLABSystem: '<S9>/Digital Port Read' */
  G431currentloop_B.DigitalPortRead = tmp;

  /* UnitDelay: '<S1>/Unit Delay' */
  G431currentloop_B.UnitDelay_ok = G431currentloop_DW.UnitDelay_DSTATE_m;

  /* Logic: '<S1>/NOT2' */
  G431currentloop_B.NOT2 = !G431currentloop_B.UnitDelay_ok;

  /* Logic: '<S1>/AND' */
  G431currentloop_B.AND = (G431currentloop_B.DigitalPortRead &&
    G431currentloop_B.NOT2);

  /* Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  if (G431currentloop_B.AND) {
    /* UnitDelay: '<S7>/Unit Delay' */
    G431currentloop_B.UnitDelay_p = G431currentloop_DW.UnitDelay_DSTATE_g;

    /* Logic: '<S7>/NOT' */
    G431currentloop_B.NOT_h = !G431currentloop_B.UnitDelay_p;

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    G431currentloop_DW.UnitDelay_DSTATE_g = G431currentloop_B.NOT_h;
  }

  /* End of Outputs for SubSystem: '<S1>/Enabled Subsystem' */

  /* DataStoreWrite: '<S1>/Data Store Write' */
  G431currentloop_DW.Enable = G431currentloop_B.UnitDelay_p;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  G431currentloop_B.LED = (G431currentloop_DW.clockTickCounter <
    G431currentloop_P.PulseGenerator_Duty) &&
    (G431currentloop_DW.clockTickCounter >= 0) ?
    G431currentloop_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<S5>/Pulse Generator' */
  if (G431currentloop_DW.clockTickCounter >=
      G431currentloop_P.PulseGenerator_Period - 1.0) {
    G431currentloop_DW.clockTickCounter = 0;
  } else {
    G431currentloop_DW.clockTickCounter++;
  }

  /* MATLABSystem: '<S209>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (G431currentloop_B.LED != 0.0) {
    pinReadLoc = 32U;
  } else {
    pinReadLoc = 0U;
  }

  LL_GPIO_SetOutputPin(portNameLoc, pinReadLoc);
  LL_GPIO_ResetOutputPin(portNameLoc, ~pinReadLoc & 32U);

  /* End of MATLABSystem: '<S209>/Digital Port Write' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  G431currentloop_DW.UnitDelay_DSTATE_m = G431currentloop_B.DigitalPortRead;
}

/* Model initialize function */
void G431currentloop_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(G431currentloop_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &G431currentloop_B), 0,
                sizeof(B_G431currentloop_T));

  /* states (dwork) */
  (void) memset((void *)&G431currentloop_DW, 0,
                sizeof(DW_G431currentloop_T));

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  G431currentloop_DW.Enable = G431currentloop_P.DataStoreMemory9_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory13' */
  G431currentloop_DW.IaOffset = G431currentloop_P.DataStoreMemory13_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory14' */
  G431currentloop_DW.IbOffset = G431currentloop_P.DataStoreMemory14_InitialValue;
  G431currentloop_PrevZCX.Dir_Sense_Trig_ZCE = POS_ZCSIG;
  G431currentloop_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  G431currentloop_PrevZCX.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  G431currentloop_PrevZCX.Delay_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
  G431currentloop_PrevZCX.Delay1_Reset_ZCE_j = UNINITIALIZED_ZCSIG;
  G431currentloop_PrevZCX.Delay_Reset_ZCE_o = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  G431currentloop_DW.UnitDelay_DSTATE_m =
    G431currentloop_P.UnitDelay_InitialCondition_eq;

  /* InitializeConditions for DiscretePulseGenerator: '<S5>/Pulse Generator' */
  G431currentloop_DW.clockTickCounter = 0;

  /* SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem' */
  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  G431currentloop_DW.UnitDelay_DSTATE_g =
    G431currentloop_P.UnitDelay_InitialCondition_i;

  /* SystemInitialize for UnitDelay: '<S7>/Unit Delay' incorporates:
   *  Outport: '<S7>/Out1'
   */
  G431currentloop_B.UnitDelay_p = G431currentloop_P.Out1_Y0_h;

  /* End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S206>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  {
    int32_T i;

    /* Start for Constant: '<S81>/Vq_OpenLoop' */
    G431currentloop_B.Vq_OpenLoop = G431currentloop_P.Vq_OpenLoop_Value;

    /* Start for Constant: '<S80>/Constant' */
    G431currentloop_B.Constant = G431currentloop_P.Constant_Value_d;

    /* Start for DataStoreMemory: '<S49>/Data Store Memory' */
    G431currentloop_DW.GlobleopenspeedInt =
      G431currentloop_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<S13>/Data Store Memory' */
    G431currentloop_DW.statcount =
      G431currentloop_P.DataStoreMemory_InitialValue_k;

    /* InitializeConditions for UnitDelay: '<S30>/Unit Delay1' */
    G431currentloop_DW.UnitDelay1_DSTATE =
      G431currentloop_P.UnitDelay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S30>/Unit Delay' */
    G431currentloop_DW.UnitDelay_DSTATE =
      G431currentloop_P.UnitDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S2>/Delay5' */
    G431currentloop_DW.Delay5_DSTATE[0] =
      G431currentloop_P.Delay5_InitialCondition;
    G431currentloop_DW.Delay5_DSTATE[1] =
      G431currentloop_P.Delay5_InitialCondition;
    G431currentloop_DW.Delay5_DSTATE[2] =
      G431currentloop_P.Delay5_InitialCondition;
    G431currentloop_DW.Delay5_DSTATE[3] =
      G431currentloop_P.Delay5_InitialCondition;

    /* InitializeConditions for Delay: '<S20>/Delay' */
    G431currentloop_DW.Delay_DSTATE = G431currentloop_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<S30>/Delay1' */
    G431currentloop_DW.Delay1_DSTATE = G431currentloop_P.Delay1_InitialCondition;

    /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
    G431currentloop_DW.UnitDelay_DSTATE_c =
      G431currentloop_P.UnitDelay_InitialCondition_n;

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay1' */
    G431currentloop_DW.UnitDelay1_DSTATE_f =
      G431currentloop_P.UnitDelay1_InitialCondition_a;

    /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
    G431currentloop_DW.UnitDelay_DSTATE_j =
      G431currentloop_P.UnitDelay_InitialCondition_c;

    /* InitializeConditions for Delay: '<S21>/Delay' */
    G431currentloop_DW.Delay_DSTATE_p =
      G431currentloop_P.Delay_InitialCondition_m;

    /* InitializeConditions for Delay: '<S31>/Delay1' */
    G431currentloop_DW.Delay1_DSTATE_f =
      G431currentloop_P.Delay1_InitialCondition_j;

    /* InitializeConditions for UnitDelay: '<S37>/Unit Delay' */
    G431currentloop_DW.UnitDelay_DSTATE_ca =
      G431currentloop_P.UnitDelay_InitialCondition_k;

    /* InitializeConditions for Delay: '<S18>/Delay' */
    G431currentloop_DW.Delay_DSTATE_pt =
      G431currentloop_P.Delay_InitialCondition_m4;

    /* InitializeConditions for UnitDelay: '<S52>/Unit Delay' */
    G431currentloop_DW.UnitDelay_DSTATE_i =
      G431currentloop_P.UnitDelay_InitialCondition_nx;

    /* InitializeConditions for DiscreteIntegrator: '<S185>/Integrator' */
    G431currentloop_DW.Integrator_DSTATE = G431currentloop_B.Vq_OpenLoop;
    G431currentloop_DW.Integrator_PrevResetState = 0;

    /* InitializeConditions for DiscreteIntegrator: '<S132>/Integrator' */
    G431currentloop_DW.Integrator_DSTATE_e = G431currentloop_B.Constant;
    G431currentloop_DW.Integrator_PrevResetState_n = 0;

    /* InitializeConditions for Delay: '<S25>/Delay' */
    for (i = 0; i < 24; i++) {
      G431currentloop_DW.Delay_DSTATE_h[i] =
        G431currentloop_P.Delay_InitialCondition_i;
    }

    G431currentloop_DW.CircBufIdx = 0U;

    /* End of InitializeConditions for Delay: '<S25>/Delay' */

    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
    G431currentloop_DW.UnitDelay_DSTATE_p =
      G431currentloop_P.UnitDelay_InitialCondition_e;

    /* SystemInitialize for Triggered SubSystem: '<S19>/Dir_Sense' */
    /* SystemInitialize for Switch: '<S27>/Switch' incorporates:
     *  Outport: '<S27>/Sign'
     */
    G431currentloop_B.Switch_o = G431currentloop_P.Sign_Y0;

    /* End of SystemInitialize for SubSystem: '<S19>/Dir_Sense' */

    /* SystemInitialize for Enabled SubSystem: '<S52>/Accumulate' */
    /* InitializeConditions for Delay: '<S53>/Delay' */
    G431currentloop_DW.Delay_DSTATE_j =
      G431currentloop_P.Delay_InitialCondition_f;

    /* SystemInitialize for Enabled SubSystem: '<S53>/Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S54>/Input' incorporates:
     *  Outport: '<S54>/Out1'
     */
    G431currentloop_B.Input = G431currentloop_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S53>/Subsystem' */

    /* SystemInitialize for Sum: '<S53>/Add1' incorporates:
     *  Outport: '<S53>/theta_e'
     */
    G431currentloop_B.Add1_d = G431currentloop_P.theta_e_Y0;

    /* End of SystemInitialize for SubSystem: '<S52>/Accumulate' */

    /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
    G431currentloop_DW.obj.isInitialized = 0;
    G431currentloop_DW.obj.matlabCodegenIsDeleted = false;
    G431currentloop_DW.objisempty_a = true;
    G431currentloo_SystemCore_setup(&G431currentloop_DW.obj);

    /* Start for MATLABSystem: '<S204>/PWM Output' */
    G431currentloop_DW.obj_h.matlabCodegenIsDeleted = false;
    G431currentloop_DW.objisempty_i = true;
    G431currentloop_DW.obj_h.isSetupComplete = false;
    G431currentloop_DW.obj_h.isInitialized = 1;
    G431current_PWMOutput_setupImpl(&G431currentloop_DW.obj_h);
    G431currentloop_DW.obj_h.isSetupComplete = true;

    /* SystemInitialize for Gain: '<S18>/AngleConversion' incorporates:
     *  Outport: '<S2>/theta'
     */
    G431currentloop_B.AngleConversion = G431currentloop_P.theta_Y0;

    /* SystemInitialize for Gain: '<S45>/OP_Gain*R_shunt1' incorporates:
     *  Outport: '<S2>/currentab'
     */
    G431currentloop_B.OP_GainR_shunt1[0] = G431currentloop_P.currentab_Y0;
    G431currentloop_B.OP_GainR_shunt1[1] = G431currentloop_P.currentab_Y0;
  }

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S206>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S9>/Digital Port Read' */
  G431currentloop_DW.objisempty_e = true;
  G431currentloop_DW.obj_m.isInitialized = 1;

  /* Start for MATLABSystem: '<S209>/Digital Port Write' */
  G431currentloop_DW.objisempty = true;
  G431currentloop_DW.obj_f.isInitialized = 1;

  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* DataStoreWrite: '<S4>/Data Store Write' incorporates:
   *  Constant: '<S4>/Testing get offset1'
   */
  G431currentloop_DW.IaOffset = G431currentloop_P.Testinggetoffset1_Value;

  /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
   *  Constant: '<S4>/Testing get offset'
   */
  G431currentloop_DW.IbOffset = G431currentloop_P.Testinggetoffset_Value;

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/* Model terminate function */
void G431currentloop_terminate(void)
{
  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S206>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S17>/Analog to Digital Converter' */
  if (!G431currentloop_DW.obj.matlabCodegenIsDeleted) {
    G431currentloop_DW.obj.matlabCodegenIsDeleted = true;
    if ((G431currentloop_DW.obj.isInitialized == 1) &&
        G431currentloop_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(G431currentloop_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S17>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S204>/PWM Output' */
  if (!G431currentloop_DW.obj_h.matlabCodegenIsDeleted) {
    G431currentloop_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((G431currentloop_DW.obj_h.isInitialized == 1) &&
        G431currentloop_DW.obj_h.isSetupComplete) {
      disableCounter(G431currentloop_DW.obj_h.TimerHandle);
      disableTimerInterrupts(G431currentloop_DW.obj_h.TimerHandle, 0);
      disableTimerChannel1(G431currentloop_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(G431currentloop_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(G431currentloop_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S204>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S206>/Hardware Interrupt' */
}

void G431currentloop_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC1_2_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S206>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S206>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          real_T Bias;
          uint64_T tmp_p;
          real32_T u0;
          real32_T u1;
          real32_T u2;
          uint32_T Sum_b;
          uint16_T tmp[2];
          uint16_T AnalogtoDigitalConverter;
          ZCSigState Delay_Reset_ZCE_tmp;
          int8_T Integrator_PrevResetState_tmp;
          boolean_T LogicalOperator_tmp;
          boolean_T zcEvent;

          /* Switch: '<S84>/Switch1' incorporates:
           *  Constant: '<S84>/enableInportSatMethod'
           */
          if (G431currentloop_P.enableInportSatMethod_Value != 0) {
            /* Switch: '<S84>/Switch1' incorporates:
             *  Constant: '<S79>/ReplaceInport_satMethod'
             */
            G431currentloop_B.Switch1_pj =
              G431currentloop_P.ReplaceInport_satMethod_Value;
          } else {
            /* Switch: '<S84>/Switch1' incorporates:
             *  Constant: '<S84>/ChosenMethod'
             */
            G431currentloop_B.Switch1_pj = G431currentloop_P.ChosenMethod_Value;
          }

          /* End of Switch: '<S84>/Switch1' */

          /* DataStoreRead: '<S45>/Data Store Read' */
          G431currentloop_B.DataStoreRead = G431currentloop_DW.IaOffset;

          /* DataStoreRead: '<S45>/Data Store Read1' */
          G431currentloop_B.DataStoreRead1 = G431currentloop_DW.IbOffset;

          /* MATLABSystem: '<S17>/Analog to Digital Converter' */
          injectedReadADCIntr(G431currentloop_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* MATLABSystem: '<S17>/Analog to Digital Converter' */
          AnalogtoDigitalConverter = tmp[0];
          G431currentloop_B.AnalogtoDigitalConverter[0] =
            AnalogtoDigitalConverter;

          /* DataTypeConversion: '<S45>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S17>/Analog to Digital Converter'
           */
          G431currentloop_B.DataTypeConversion_l[0] = AnalogtoDigitalConverter;

          /* MATLABSystem: '<S17>/Analog to Digital Converter' */
          AnalogtoDigitalConverter = tmp[1];
          G431currentloop_B.AnalogtoDigitalConverter[1] =
            AnalogtoDigitalConverter;

          /* DataTypeConversion: '<S45>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S17>/Analog to Digital Converter'
           */
          G431currentloop_B.DataTypeConversion_l[1] = AnalogtoDigitalConverter;

          /* Sum: '<S45>/Add' incorporates:
           *  DataTypeConversion: '<S45>/Data Type Conversion'
           */
          G431currentloop_B.Add[0] = (real_T)
            G431currentloop_B.DataTypeConversion_l[0] -
            G431currentloop_B.DataStoreRead;
          G431currentloop_B.Add[1] = (real_T)
            G431currentloop_B.DataTypeConversion_l[1] -
            G431currentloop_B.DataStoreRead1;

          /* Gain: '<S45>/AD voltage' incorporates:
           *  Sum: '<S45>/Add'
           */
          Bias = G431currentloop_P.ADvoltage_Gain * G431currentloop_B.Add[0];
          G431currentloop_B.ADvoltage[0] = Bias;

          /* Gain: '<S45>/OP_Gain*R_shunt' incorporates:
           *  Gain: '<S45>/AD voltage'
           */
          Bias *= G431currentloop_P.OP_GainR_shunt_Gain;
          G431currentloop_B.OP_GainR_shunt[0] = Bias;

          /* Gain: '<S45>/OP_Gain*R_shunt1' incorporates:
           *  Gain: '<S45>/OP_Gain*R_shunt'
           */
          G431currentloop_B.OP_GainR_shunt1[0] =
            G431currentloop_P.OP_GainR_shunt1_Gain * Bias;

          /* Gain: '<S45>/AD voltage' incorporates:
           *  Sum: '<S45>/Add'
           */
          Bias = G431currentloop_P.ADvoltage_Gain * G431currentloop_B.Add[1];
          G431currentloop_B.ADvoltage[1] = Bias;

          /* Gain: '<S45>/OP_Gain*R_shunt' incorporates:
           *  Gain: '<S45>/AD voltage'
           */
          Bias *= G431currentloop_P.OP_GainR_shunt_Gain;
          G431currentloop_B.OP_GainR_shunt[1] = Bias;

          /* Gain: '<S45>/OP_Gain*R_shunt1' incorporates:
           *  Gain: '<S45>/OP_Gain*R_shunt'
           */
          G431currentloop_B.OP_GainR_shunt1[1] =
            G431currentloop_P.OP_GainR_shunt1_Gain * Bias;

          /* Outputs for Atomic SubSystem: '<S61>/Two phase CRL wrap' */
          /* Sum: '<S62>/a_plus_2b' */
          G431currentloop_B.a_plus_2b = (G431currentloop_B.OP_GainR_shunt1[0] +
            G431currentloop_B.OP_GainR_shunt1[1]) +
            G431currentloop_B.OP_GainR_shunt1[1];

          /* Gain: '<S62>/one_by_sqrt3' */
          G431currentloop_B.one_by_sqrt3 = G431currentloop_P.one_by_sqrt3_Gain *
            G431currentloop_B.a_plus_2b;

          /* AlgorithmDescriptorDelegate generated from: '<S62>/a16' */
          G431currentloop_B.algDD_o1_l = G431currentloop_B.OP_GainR_shunt1[0];

          /* AlgorithmDescriptorDelegate generated from: '<S62>/a16' */
          G431currentloop_B.algDD_o2_b = G431currentloop_B.one_by_sqrt3;

          /* End of Outputs for SubSystem: '<S61>/Two phase CRL wrap' */

          /* Gain: '<S61>/Kalpha' */
          G431currentloop_B.Kalpha = G431currentloop_P.Kalpha_Gain *
            G431currentloop_B.algDD_o1_l;

          /* Gain: '<S61>/Kbeta' */
          G431currentloop_B.Kbeta = G431currentloop_P.Kbeta_Gain *
            G431currentloop_B.algDD_o2_b;

          /* UnitDelay: '<S30>/Unit Delay1' */
          G431currentloop_B.UnitDelay1 = G431currentloop_DW.UnitDelay1_DSTATE;

          /* UnitDelay: '<S30>/Unit Delay' */
          G431currentloop_B.UnitDelay = G431currentloop_DW.UnitDelay_DSTATE;

          /* Gain: '<S30>/a' */
          G431currentloop_B.a = G431currentloop_P.a_Gain *
            G431currentloop_B.UnitDelay;

          /* Delay: '<S2>/Delay5' */
          G431currentloop_B.Delay5[0] = G431currentloop_DW.Delay5_DSTATE[0];
          G431currentloop_B.Delay5[1] = G431currentloop_DW.Delay5_DSTATE[1];
          G431currentloop_B.Delay5[2] = G431currentloop_DW.Delay5_DSTATE[2];
          G431currentloop_B.Delay5[3] = G431currentloop_DW.Delay5_DSTATE[3];

          /* DataStoreRead: '<S2>/Data Store Read' */
          G431currentloop_B.DataStoreRead_d = G431currentloop_DW.Enable;

          /* Logic: '<S11>/Logical Operator' incorporates:
           *  Logic: '<S80>/Logical Operator1'
           *  Logic: '<S81>/Logical Operator'
           */
          LogicalOperator_tmp = !G431currentloop_B.DataStoreRead_d;

          /* Logic: '<S11>/Logical Operator' */
          G431currentloop_B.LogicalOperator = LogicalOperator_tmp;

          /* Delay: '<S20>/Delay' */
          zcEvent = (((G431currentloop_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) !=
                      (int32_T)G431currentloop_B.LogicalOperator) &&
                     (G431currentloop_PrevZCX.Delay_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || G431currentloop_B.LogicalOperator) {
            G431currentloop_DW.Delay_DSTATE =
              G431currentloop_P.Delay_InitialCondition;
          }

          Delay_Reset_ZCE_tmp = G431currentloop_B.LogicalOperator;
          G431currentloop_PrevZCX.Delay_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S20>/Delay' */
          G431currentloop_B.Delay = G431currentloop_DW.Delay_DSTATE;

          /* Sum: '<S20>/Sum2' */
          G431currentloop_B.Sum2 = G431currentloop_B.Delay -
            G431currentloop_B.Delay5[2];

          /* Sum: '<S30>/Sum3' */
          G431currentloop_B.Sum3 = (G431currentloop_B.UnitDelay1 -
            G431currentloop_B.a) + G431currentloop_B.Sum2;

          /* Gain: '<S30>/b_inv*g' incorporates:
           *  Gain: '<S31>/b_inv*g'
           */
          Bias = G431currentloop_P.SlidingModeObserver_Disturbance * 2.2 /
            0.27143412589007004;
          u0 = (real32_T)Bias;

          /* Gain: '<S30>/b_inv*g' */
          G431currentloop_B.b_invg = u0 * G431currentloop_B.Sum3;

          /* Delay: '<S30>/Delay1' */
          zcEvent = (((G431currentloop_PrevZCX.Delay1_Reset_ZCE == POS_ZCSIG) !=
                      (int32_T)G431currentloop_B.LogicalOperator) &&
                     (G431currentloop_PrevZCX.Delay1_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || G431currentloop_B.LogicalOperator) {
            G431currentloop_DW.Delay1_DSTATE =
              G431currentloop_P.Delay1_InitialCondition;
          }

          G431currentloop_PrevZCX.Delay1_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S30>/Delay1' */
          G431currentloop_B.Delay1 = G431currentloop_DW.Delay1_DSTATE;

          /* Sum: '<S30>/Sum4' */
          G431currentloop_B.Sum4 = G431currentloop_B.b_invg +
            G431currentloop_B.Delay1;

          /* Switch: '<S22>/Switch1' incorporates:
           *  Constant: '<S22>/UseInputPort'
           */
          if (G431currentloop_P.UseInputPort_Value >
              G431currentloop_P.Switch1_Threshold) {
            /* Sum: '<S22>/Sum' incorporates:
             *  Constant: '<S22>/One'
             *  Constant: '<S22>/a'
             */
            G431currentloop_B.Sum_k = G431currentloop_P.One_Value -
              G431currentloop_P.a_Value;

            /* Switch: '<S22>/Switch1' incorporates:
             *  Constant: '<S22>/a'
             */
            G431currentloop_B.Switch1[0] = G431currentloop_P.a_Value;
            G431currentloop_B.Switch1[1] = G431currentloop_B.Sum_k;
          } else {
            /* Switch: '<S22>/Switch1' incorporates:
             *  Constant: '<S22>/FilterConstant'
             *  Constant: '<S22>/OneMinusFilterConstant'
             */
            G431currentloop_B.Switch1[0] =
              G431currentloop_P.FilterConstant_Value;
            G431currentloop_B.Switch1[1] =
              G431currentloop_P.OneMinusFilterConstant_Value;
          }

          /* End of Switch: '<S22>/Switch1' */

          /* Product: '<S34>/Product' */
          G431currentloop_B.Product = G431currentloop_B.Sum4 *
            G431currentloop_B.Switch1[0];

          /* UnitDelay: '<S34>/Unit Delay' */
          G431currentloop_B.UnitDelay_h = G431currentloop_DW.UnitDelay_DSTATE_c;

          /* Product: '<S34>/Product1' */
          G431currentloop_B.Product1 = G431currentloop_B.Switch1[1] *
            G431currentloop_B.UnitDelay_h;

          /* Sum: '<S34>/Add1' */
          G431currentloop_B.Add1 = G431currentloop_B.Product +
            G431currentloop_B.Product1;

          /* Relay: '<S19>/AlphaRelay' */
          Bias = G431currentloop_B.Add1;
          G431currentloop_DW.AlphaRelay_Mode = ((Bias >=
            G431currentloop_P.AlphaRelay_OnVal) || ((!(Bias <=
            G431currentloop_P.AlphaRelay_OffVal)) &&
            G431currentloop_DW.AlphaRelay_Mode));
          if (G431currentloop_DW.AlphaRelay_Mode) {
            /* Relay: '<S19>/AlphaRelay' */
            G431currentloop_B.AlphaRelay = G431currentloop_P.AlphaRelay_YOn;
          } else {
            /* Relay: '<S19>/AlphaRelay' */
            G431currentloop_B.AlphaRelay = G431currentloop_P.AlphaRelay_YOff;
          }

          /* End of Relay: '<S19>/AlphaRelay' */

          /* UnitDelay: '<S31>/Unit Delay1' */
          G431currentloop_B.UnitDelay1_k =
            G431currentloop_DW.UnitDelay1_DSTATE_f;

          /* UnitDelay: '<S31>/Unit Delay' */
          G431currentloop_B.UnitDelay_o = G431currentloop_DW.UnitDelay_DSTATE_j;

          /* Gain: '<S31>/a' */
          G431currentloop_B.a_e = G431currentloop_P.a_Gain_d *
            G431currentloop_B.UnitDelay_o;

          /* Delay: '<S21>/Delay' */
          zcEvent = (((G431currentloop_PrevZCX.Delay_Reset_ZCE_m == POS_ZCSIG)
                      != (int32_T)G431currentloop_B.LogicalOperator) &&
                     (G431currentloop_PrevZCX.Delay_Reset_ZCE_m !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || G431currentloop_B.LogicalOperator) {
            G431currentloop_DW.Delay_DSTATE_p =
              G431currentloop_P.Delay_InitialCondition_m;
          }

          G431currentloop_PrevZCX.Delay_Reset_ZCE_m = Delay_Reset_ZCE_tmp;

          /* Delay: '<S21>/Delay' */
          G431currentloop_B.Delay_f = G431currentloop_DW.Delay_DSTATE_p;

          /* Sum: '<S21>/Sum2' */
          G431currentloop_B.Sum2_f = G431currentloop_B.Delay_f -
            G431currentloop_B.Delay5[3];

          /* Sum: '<S31>/Sum3' */
          G431currentloop_B.Sum3_p = (G431currentloop_B.UnitDelay1_k -
            G431currentloop_B.a_e) + G431currentloop_B.Sum2_f;

          /* Gain: '<S31>/b_inv*g' */
          G431currentloop_B.b_invg_g = u0 * G431currentloop_B.Sum3_p;

          /* Delay: '<S31>/Delay1' */
          zcEvent = (((G431currentloop_PrevZCX.Delay1_Reset_ZCE_j == POS_ZCSIG)
                      != (int32_T)G431currentloop_B.LogicalOperator) &&
                     (G431currentloop_PrevZCX.Delay1_Reset_ZCE_j !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || G431currentloop_B.LogicalOperator) {
            G431currentloop_DW.Delay1_DSTATE_f =
              G431currentloop_P.Delay1_InitialCondition_j;
          }

          G431currentloop_PrevZCX.Delay1_Reset_ZCE_j = Delay_Reset_ZCE_tmp;

          /* Delay: '<S31>/Delay1' */
          G431currentloop_B.Delay1_e = G431currentloop_DW.Delay1_DSTATE_f;

          /* Sum: '<S31>/Sum4' */
          G431currentloop_B.Sum4_p = G431currentloop_B.b_invg_g +
            G431currentloop_B.Delay1_e;

          /* Switch: '<S23>/Switch1' incorporates:
           *  Constant: '<S23>/UseInputPort'
           */
          if (G431currentloop_P.UseInputPort_Value_g >
              G431currentloop_P.Switch1_Threshold_h) {
            /* Sum: '<S23>/Sum' incorporates:
             *  Constant: '<S23>/One'
             *  Constant: '<S23>/a'
             */
            G431currentloop_B.Sum_h = G431currentloop_P.One_Value_l -
              G431currentloop_P.a_Value_c;

            /* Switch: '<S23>/Switch1' incorporates:
             *  Constant: '<S23>/a'
             */
            G431currentloop_B.Switch1_c[0] = G431currentloop_P.a_Value_c;
            G431currentloop_B.Switch1_c[1] = G431currentloop_B.Sum_h;
          } else {
            /* Switch: '<S23>/Switch1' incorporates:
             *  Constant: '<S23>/FilterConstant'
             *  Constant: '<S23>/OneMinusFilterConstant'
             */
            G431currentloop_B.Switch1_c[0] =
              G431currentloop_P.FilterConstant_Value_l;
            G431currentloop_B.Switch1_c[1] =
              G431currentloop_P.OneMinusFilterConstant_Value_e;
          }

          /* End of Switch: '<S23>/Switch1' */

          /* Product: '<S37>/Product' */
          G431currentloop_B.Product_g = G431currentloop_B.Sum4_p *
            G431currentloop_B.Switch1_c[0];

          /* UnitDelay: '<S37>/Unit Delay' */
          G431currentloop_B.UnitDelay_c = G431currentloop_DW.UnitDelay_DSTATE_ca;

          /* Product: '<S37>/Product1' */
          G431currentloop_B.Product1_j = G431currentloop_B.Switch1_c[1] *
            G431currentloop_B.UnitDelay_c;

          /* Sum: '<S37>/Add1' */
          G431currentloop_B.Add1_o = G431currentloop_B.Product_g +
            G431currentloop_B.Product1_j;

          /* Relay: '<S19>/BetaRelay' */
          Bias = G431currentloop_B.Add1_o;
          G431currentloop_DW.BetaRelay_Mode = ((Bias >=
            G431currentloop_P.BetaRelay_OnVal) || ((!(Bias <=
            G431currentloop_P.BetaRelay_OffVal)) &&
            G431currentloop_DW.BetaRelay_Mode));
          if (G431currentloop_DW.BetaRelay_Mode) {
            /* Relay: '<S19>/BetaRelay' */
            G431currentloop_B.BetaRelay = G431currentloop_P.BetaRelay_YOn;
          } else {
            /* Relay: '<S19>/BetaRelay' */
            G431currentloop_B.BetaRelay = G431currentloop_P.BetaRelay_YOff;
          }

          /* End of Relay: '<S19>/BetaRelay' */

          /* Outputs for Triggered SubSystem: '<S19>/Dir_Sense' incorporates:
           *  TriggerPort: '<S27>/Trigger'
           */
          zcEvent = (G431currentloop_B.AlphaRelay &&
                     (G431currentloop_PrevZCX.Dir_Sense_Trig_ZCE != POS_ZCSIG));
          if (zcEvent) {
            /* Logic: '<S27>/Logical Operator' */
            G431currentloop_B.LogicalOperator_b = (G431currentloop_B.AlphaRelay &&
              G431currentloop_B.BetaRelay);

            /* Switch: '<S27>/Switch' incorporates:
             *  Constant: '<S27>/Constant'
             *  Constant: '<S27>/Constant1'
             */
            if (G431currentloop_B.LogicalOperator_b) {
              Bias = floor(G431currentloop_P.Constant_Value);
              if (rtIsNaN(Bias) || rtIsInf(Bias)) {
                Bias = 0.0;
              } else {
                Bias = fmod(Bias, 65536.0);
              }

              /* Switch: '<S27>/Switch' incorporates:
               *  Constant: '<S27>/Constant'
               */
              G431currentloop_B.Switch_o = (int16_T)(Bias < 0.0 ? (int32_T)
                (int16_T)-(int16_T)(uint16_T)-Bias : (int32_T)(int16_T)(uint16_T)
                Bias);
            } else {
              Bias = floor(G431currentloop_P.Constant1_Value);
              if (rtIsNaN(Bias) || rtIsInf(Bias)) {
                Bias = 0.0;
              } else {
                Bias = fmod(Bias, 65536.0);
              }

              /* Switch: '<S27>/Switch' incorporates:
               *  Constant: '<S27>/Constant1'
               */
              G431currentloop_B.Switch_o = (int16_T)(Bias < 0.0 ? (int32_T)
                (int16_T)-(int16_T)(uint16_T)-Bias : (int32_T)(int16_T)(uint16_T)
                Bias);
            }

            /* End of Switch: '<S27>/Switch' */
          }

          G431currentloop_PrevZCX.Dir_Sense_Trig_ZCE =
            G431currentloop_B.AlphaRelay;

          /* End of Outputs for SubSystem: '<S19>/Dir_Sense' */

          /* If: '<S19>/If' */
          if (G431currentloop_B.Switch_o > 0) {
            /* Outputs for IfAction SubSystem: '<S19>/Subsystem2' incorporates:
             *  ActionPort: '<S28>/Action Port'
             */
            /* Merge: '<S19>/Merge' incorporates:
             *  UnaryMinus: '<S28>/Unary Minus'
             */
            G431currentloop_B.Merge = -G431currentloop_B.Add1;

            /* Merge: '<S19>/Merge1' incorporates:
             *  SignalConversion generated from: '<S28>/SigmaBeta'
             */
            G431currentloop_B.Merge1 = G431currentloop_B.Add1_o;

            /* End of Outputs for SubSystem: '<S19>/Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S19>/Subsystem3' incorporates:
             *  ActionPort: '<S29>/Action Port'
             */
            /* Merge: '<S19>/Merge1' incorporates:
             *  UnaryMinus: '<S29>/Unary Minus'
             */
            G431currentloop_B.Merge1 = -G431currentloop_B.Add1_o;

            /* Merge: '<S19>/Merge' incorporates:
             *  SignalConversion generated from: '<S29>/SigmaAlpha'
             */
            G431currentloop_B.Merge = G431currentloop_B.Add1;

            /* End of Outputs for SubSystem: '<S19>/Subsystem3' */
          }

          /* End of If: '<S19>/If' */

          /* Delay: '<S18>/Delay' */
          zcEvent = (((G431currentloop_PrevZCX.Delay_Reset_ZCE_o == POS_ZCSIG)
                      != (int32_T)G431currentloop_B.LogicalOperator) &&
                     (G431currentloop_PrevZCX.Delay_Reset_ZCE_o !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || G431currentloop_B.LogicalOperator) {
            G431currentloop_DW.Delay_DSTATE_pt =
              G431currentloop_P.Delay_InitialCondition_m4;
          }

          G431currentloop_PrevZCX.Delay_Reset_ZCE_o = Delay_Reset_ZCE_tmp;

          /* Delay: '<S18>/Delay' */
          G431currentloop_B.Delay_i = G431currentloop_DW.Delay_DSTATE_pt;

          /* Constant: '<S18>/PhaseDelay' */
          Bias = G431currentloop_P.SlidingModeObserver_CutoffFreq / 100.0;

          /* Constant: '<S18>/PhaseDelay' */
          G431currentloop_B.PhaseDelay = (real32_T)Bias;

          /* Outputs for Atomic SubSystem: '<S18>/angleCompensation' */
          /* Product: '<S26>/Product' */
          G431currentloop_B.Product_n = G431currentloop_B.Merge *
            G431currentloop_B.PhaseDelay;

          /* Product: '<S26>/Product2' */
          G431currentloop_B.Product2 = G431currentloop_B.Merge1 *
            G431currentloop_B.Delay_i;

          /* Sum: '<S26>/Sum1' */
          G431currentloop_B.Sum1_f = G431currentloop_B.Product_n +
            G431currentloop_B.Product2;

          /* Product: '<S26>/Product1' */
          G431currentloop_B.Product1_b = G431currentloop_B.Merge1 *
            G431currentloop_B.PhaseDelay;

          /* Product: '<S26>/Product3' */
          G431currentloop_B.Product3 = G431currentloop_B.Merge *
            G431currentloop_B.Delay_i;

          /* Sum: '<S26>/Sum2' */
          G431currentloop_B.Sum2_l = G431currentloop_B.Product1_b -
            G431currentloop_B.Product3;

          /* Outputs for Atomic SubSystem: '<S26>/atan1' */
          /* DataTypeConversion: '<S43>/Data Type Conversion1' */
          G431currentloop_B.DataTypeConversion1_f = (real32_T)
            G431currentloop_B.Sum1_f;

          /* DataTypeConversion: '<S43>/Data Type Conversion2' */
          G431currentloop_B.DataTypeConversion2 = (real32_T)
            G431currentloop_B.Sum2_l;

          /* Trigonometry: '<S43>/Atan2' */
          G431currentloop_B.Atan2 = rt_atan2f_snf
            (G431currentloop_B.DataTypeConversion1_f,
             G431currentloop_B.DataTypeConversion2);

          /* DataTypeConversion: '<S43>/Data Type Conversion' */
          G431currentloop_B.DataTypeConversion = G431currentloop_B.Atan2;

          /* Outputs for Atomic SubSystem: '<S26>/atan1' */
          /* Switch: '<S43>/Switch' */
          if (G431currentloop_P.atan1_outputUnit >
              G431currentloop_P.Switch_Threshold_b) {
            /* Outputs for Atomic SubSystem: '<S43>/Per Unit' */
            /* Gain: '<S44>/Gain' */
            G431currentloop_B.Gain_p = G431currentloop_P.Gain_Gain *
              G431currentloop_B.DataTypeConversion;

            /* Switch: '<S44>/Switch' */
            if (G431currentloop_B.Gain_p >= G431currentloop_P.Switch_Threshold)
            {
              /* Switch: '<S44>/Switch' */
              G431currentloop_B.Switch_h = G431currentloop_B.Gain_p;
            } else {
              /* Bias: '<S44>/Bias' */
              G431currentloop_B.Bias = G431currentloop_B.Gain_p +
                G431currentloop_P.Bias_Bias_a;

              /* Switch: '<S44>/Switch' */
              G431currentloop_B.Switch_h = G431currentloop_B.Bias;
            }

            /* End of Switch: '<S44>/Switch' */
            /* End of Outputs for SubSystem: '<S43>/Per Unit' */

            /* Switch: '<S43>/Switch' */
            G431currentloop_B.Switch_b = G431currentloop_B.Switch_h;
          } else {
            /* Switch: '<S43>/Switch' */
            G431currentloop_B.Switch_b = G431currentloop_B.DataTypeConversion;
          }

          /* End of Switch: '<S43>/Switch' */
          /* End of Outputs for SubSystem: '<S26>/atan1' */

          /* AlgorithmDescriptorDelegate generated from: '<S43>/a16' */
          G431currentloop_B.algDD = G431currentloop_B.Switch_b;

          /* End of Outputs for SubSystem: '<S26>/atan1' */

          /* Switch: '<S26>/Switch' */
          if (G431currentloop_B.algDD > G431currentloop_P.Switch_Threshold_i) {
            /* Switch: '<S26>/Switch' */
            G431currentloop_B.Switch_l = G431currentloop_B.algDD;
          } else {
            /* Bias: '<S26>/Bias' */
            G431currentloop_B.Bias_f = G431currentloop_B.algDD +
              G431currentloop_P.Bias_Bias;

            /* Switch: '<S26>/Switch' */
            G431currentloop_B.Switch_l = G431currentloop_B.Bias_f;
          }

          /* End of Switch: '<S26>/Switch' */
          /* End of Outputs for SubSystem: '<S18>/angleCompensation' */

          /* DataStoreRead: '<S13>/Data Store Read' */
          G431currentloop_B.DataStoreRead_h = G431currentloop_DW.Enable;

          /* If: '<S13>/If1' */
          if (G431currentloop_B.DataStoreRead_h) {
            /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S47>/Action Port'
             */
            /* DataStoreRead: '<S47>/Data Store Read' */
            G431currentloop_B.DataStoreRead_p = G431currentloop_DW.statcount;

            /* Sum: '<S47>/Add1' incorporates:
             *  Constant: '<S47>/Constant'
             */
            tmp_p = (uint64_T)G431currentloop_P.Constant_Value_hu +
              G431currentloop_B.DataStoreRead_p;
            if (tmp_p > 4294967295ULL) {
              tmp_p = 4294967295ULL;
            }

            /* Sum: '<S47>/Add1' */
            G431currentloop_B.Add1_g = (uint32_T)tmp_p;

            /* DataStoreWrite: '<S47>/Data Store Write' */
            G431currentloop_DW.statcount = G431currentloop_B.Add1_g;

            /* Merge: '<S13>/Merge2' incorporates:
             *  SignalConversion generated from: '<S47>/Out1'
             */
            G431currentloop_B.cont = G431currentloop_B.Add1_g;

            /* End of Outputs for SubSystem: '<S13>/If Action Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S13>/If Action Subsystem3' incorporates:
             *  ActionPort: '<S48>/Action Port'
             */
            /* DataStoreWrite: '<S48>/Data Store Write' incorporates:
             *  Constant: '<S48>/Constant15'
             */
            G431currentloop_DW.statcount = G431currentloop_P.Constant15_Value;

            /* Merge: '<S13>/Merge2' incorporates:
             *  Constant: '<S48>/Constant15'
             *  SignalConversion generated from: '<S48>/Out1'
             */
            G431currentloop_B.cont = G431currentloop_P.Constant15_Value;

            /* End of Outputs for SubSystem: '<S13>/If Action Subsystem3' */
          }

          /* End of If: '<S13>/If1' */

          /* RelationalOperator: '<S46>/Compare' incorporates:
           *  Constant: '<S46>/Constant'
           */
          G431currentloop_B.Compare = (G431currentloop_B.cont <=
            G431currentloop_P.EnablePWMfor8seconds_const);

          /* Logic: '<S13>/NOT' */
          G431currentloop_B.NOT = !G431currentloop_B.Compare;

          /* If: '<S49>/If' incorporates:
           *  Constant: '<S49>/Count for 2 sec'
           */
          if (G431currentloop_B.cont < G431currentloop_P.Countfor2sec_Value) {
            /* Outputs for IfAction SubSystem: '<S49>/If Action Subsystem' incorporates:
             *  ActionPort: '<S50>/Action Port'
             */
            /* DataStoreWrite: '<S50>/Data Store Write' incorporates:
             *  Constant: '<S50>/Constant'
             */
            G431currentloop_DW.GlobleopenspeedInt =
              G431currentloop_P.Constant_Value_h;

            /* Merge: '<S49>/Merge' incorporates:
             *  Constant: '<S50>/Constant'
             *  SignalConversion generated from: '<S50>/Out1'
             */
            G431currentloop_B.Merge_i = G431currentloop_P.Constant_Value_h;

            /* End of Outputs for SubSystem: '<S49>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S49>/If Action Subsystem2' incorporates:
             *  ActionPort: '<S51>/Action Port'
             */
            /* DataStoreRead: '<S51>/Data Store Read' */
            G431currentloop_B.DataStoreRead_b =
              G431currentloop_DW.GlobleopenspeedInt;

            /* Sum: '<S51>/Add1' incorporates:
             *  Constant: '<S51>/Constant2'
             */
            G431currentloop_B.Add1_a = G431currentloop_P.Constant2_Value +
              G431currentloop_B.DataStoreRead_b;

            /* Saturate: '<S51>/Saturate to 'motor.calibSpeed' RPM' */
            u0 = G431currentloop_B.Add1_a;
            u1 = G431currentloop_P.SaturatetomotorcalibSpeedRPM_Lo;
            u2 = G431currentloop_P.SaturatetomotorcalibSpeedRPM_Up;
            if (u0 > u2) {
              /* Saturate: '<S51>/Saturate to 'motor.calibSpeed' RPM' */
              G431currentloop_B.SaturatetomotorcalibSpeedRPM = u2;
            } else if (u0 < u1) {
              /* Saturate: '<S51>/Saturate to 'motor.calibSpeed' RPM' */
              G431currentloop_B.SaturatetomotorcalibSpeedRPM = u1;
            } else {
              /* Saturate: '<S51>/Saturate to 'motor.calibSpeed' RPM' */
              G431currentloop_B.SaturatetomotorcalibSpeedRPM = u0;
            }

            /* End of Saturate: '<S51>/Saturate to 'motor.calibSpeed' RPM' */

            /* DataStoreWrite: '<S51>/Data Store Write' */
            G431currentloop_DW.GlobleopenspeedInt =
              G431currentloop_B.SaturatetomotorcalibSpeedRPM;

            /* Merge: '<S49>/Merge' incorporates:
             *  Gain: '<S51>/Multiply1'
             */
            G431currentloop_B.Merge_i = G431currentloop_P.Multiply1_Gain *
              G431currentloop_B.SaturatetomotorcalibSpeedRPM;

            /* End of Outputs for SubSystem: '<S49>/If Action Subsystem2' */
          }

          /* End of If: '<S49>/If' */

          /* Gain: '<S52>/scaleIn' */
          G431currentloop_B.scaleIn = G431currentloop_P.scaleIn_Gain *
            G431currentloop_B.Merge_i;

          /* UnitDelay: '<S52>/Unit Delay' */
          G431currentloop_B.UnitDelay_e = G431currentloop_DW.UnitDelay_DSTATE_i;

          /* Logic: '<S52>/NOT' incorporates:
           *  Constant: '<S52>/Constant_Reset'
           */
          G431currentloop_B.NOT_o = !G431currentloop_P.Constant_Reset_Value;

          /* Outputs for Enabled SubSystem: '<S52>/Accumulate' incorporates:
           *  EnablePort: '<S53>/Enable'
           */
          if (G431currentloop_B.NOT_o) {
            /* Delay: '<S53>/Delay' */
            G431currentloop_B.Delay_m = G431currentloop_DW.Delay_DSTATE_j;

            /* Outputs for Enabled SubSystem: '<S53>/Subsystem' incorporates:
             *  EnablePort: '<S54>/Enable'
             */
            if (G431currentloop_B.Delay_m) {
              /* SignalConversion generated from: '<S54>/Input' */
              G431currentloop_B.Input = G431currentloop_B.scaleIn;
            }

            /* End of Outputs for SubSystem: '<S53>/Subsystem' */

            /* Sum: '<S53>/Add' */
            G431currentloop_B.Add_k = G431currentloop_B.Input +
              G431currentloop_B.UnitDelay_e;

            /* DataTypeConversion: '<S53>/Data Type Conversion' */
            u0 = floorf(G431currentloop_B.Add_k);
            if (rtIsNaNF(u0) || rtIsInfF(u0)) {
              u0 = 0.0F;
            } else {
              u0 = fmodf(u0, 65536.0F);
            }

            /* DataTypeConversion: '<S53>/Data Type Conversion' */
            G431currentloop_B.DataTypeConversion_i = (int16_T)(u0 < 0.0F ?
              (int32_T)(int16_T)-(int16_T)(uint16_T)-u0 : (int32_T)(int16_T)
              (uint16_T)u0);

            /* DataTypeConversion: '<S53>/Data Type Conversion1' */
            G431currentloop_B.DataTypeConversion1_n =
              G431currentloop_B.DataTypeConversion_i;

            /* Sum: '<S53>/Add1' */
            G431currentloop_B.Add1_d = G431currentloop_B.Add_k -
              G431currentloop_B.DataTypeConversion1_n;

            /* Update for Delay: '<S53>/Delay' incorporates:
             *  Constant: '<S53>/Constant'
             */
            G431currentloop_DW.Delay_DSTATE_j =
              G431currentloop_P.Constant_Value_j;
          }

          /* End of Outputs for SubSystem: '<S52>/Accumulate' */

          /* Switch: '<S12>/Switch' */
          if (G431currentloop_B.NOT) {
            /* Gain: '<S18>/AngleConversion' */
            G431currentloop_B.AngleConversion = (real32_T)
              (G431currentloop_P.AngleConversion_Gain *
               G431currentloop_B.Switch_l);

            /* Switch: '<S12>/Switch' */
            G431currentloop_B.Switch_g = G431currentloop_B.AngleConversion;
          } else {
            /* Gain: '<S52>/scaleOut' */
            G431currentloop_B.scaleOut = G431currentloop_P.scaleOut_Gain *
              G431currentloop_B.Add1_d;

            /* Switch: '<S12>/Switch' */
            G431currentloop_B.Switch_g = G431currentloop_B.scaleOut;
          }

          /* End of Switch: '<S12>/Switch' */

          /* Gain: '<S75>/convert_pu' */
          G431currentloop_B.convert_pu = G431currentloop_P.convert_pu_Gain *
            G431currentloop_B.Switch_g;

          /* RelationalOperator: '<S76>/Compare' incorporates:
           *  Constant: '<S76>/Constant'
           */
          G431currentloop_B.Compare_h = (G431currentloop_B.convert_pu <
            G431currentloop_P.Constant_Value_p);

          /* DataTypeConversion: '<S75>/Data Type Conversion' */
          G431currentloop_B.DataTypeConversion_b = G431currentloop_B.Compare_h;

          /* If: '<S75>/If' */
          if (G431currentloop_B.DataTypeConversion_b > 0) {
            /* Outputs for IfAction SubSystem: '<S75>/If Action Subsystem' incorporates:
             *  ActionPort: '<S77>/Action Port'
             */
            /* DataTypeConversion: '<S77>/Convert_uint16' */
            u0 = floorf(G431currentloop_B.convert_pu);
            if (rtIsNaNF(u0) || rtIsInfF(u0)) {
              u0 = 0.0F;
            } else {
              u0 = fmodf(u0, 65536.0F);
            }

            /* DataTypeConversion: '<S77>/Convert_uint16' */
            G431currentloop_B.Convert_uint16_j = (int16_T)(u0 < 0.0F ? (int32_T)
              (int16_T)-(int16_T)(uint16_T)-u0 : (int32_T)(int16_T)(uint16_T)u0);

            /* DataTypeConversion: '<S77>/Convert_back' */
            G431currentloop_B.Convert_back_h =
              G431currentloop_B.Convert_uint16_j;

            /* Merge: '<S75>/Merge' incorporates:
             *  Sum: '<S77>/Sum'
             */
            G431currentloop_B.Merge_d = G431currentloop_B.convert_pu -
              G431currentloop_B.Convert_back_h;

            /* End of Outputs for SubSystem: '<S75>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S75>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S78>/Action Port'
             */
            /* DataTypeConversion: '<S78>/Convert_uint16' */
            u0 = truncf(G431currentloop_B.convert_pu);
            if (rtIsNaNF(u0) || rtIsInfF(u0)) {
              u0 = 0.0F;
            } else {
              u0 = fmodf(u0, 65536.0F);
            }

            /* DataTypeConversion: '<S78>/Convert_uint16' */
            G431currentloop_B.Convert_uint16 = (int16_T)(u0 < 0.0F ? (int32_T)
              (int16_T)-(int16_T)(uint16_T)-u0 : (int32_T)(int16_T)(uint16_T)u0);

            /* DataTypeConversion: '<S78>/Convert_back' */
            G431currentloop_B.Convert_back = G431currentloop_B.Convert_uint16;

            /* Merge: '<S75>/Merge' incorporates:
             *  Sum: '<S78>/Sum'
             */
            G431currentloop_B.Merge_d = G431currentloop_B.convert_pu -
              G431currentloop_B.Convert_back;

            /* End of Outputs for SubSystem: '<S75>/If Action Subsystem1' */
          }

          /* End of If: '<S75>/If' */

          /* Gain: '<S59>/indexing' */
          G431currentloop_B.indexing = G431currentloop_P.indexing_Gain *
            G431currentloop_B.Merge_d;

          /* DataTypeConversion: '<S59>/Get_Integer' */
          u0 = truncf(G431currentloop_B.indexing);
          if (rtIsNaNF(u0) || rtIsInfF(u0)) {
            u0 = 0.0F;
          } else {
            u0 = fmodf(u0, 65536.0F);
          }

          /* DataTypeConversion: '<S59>/Get_Integer' */
          G431currentloop_B.Get_Integer = (uint16_T)(u0 < 0.0F ? (int32_T)
            (uint16_T)-(int16_T)(uint16_T)-u0 : (int32_T)(uint16_T)u0);

          /* Sum: '<S59>/Sum' incorporates:
           *  Constant: '<S59>/offset'
           */
          Sum_b = (uint32_T)G431currentloop_P.offset_Value[0] +
            G431currentloop_B.Get_Integer;
          G431currentloop_B.Sum_b[0] = Sum_b;

          /* Selector: '<S59>/Lookup' incorporates:
           *  Constant: '<S59>/sine_table_values'
           */
          G431currentloop_B.Lookup[0] =
            G431currentloop_P.sine_table_values_Value[(int32_T)Sum_b];

          /* Sum: '<S59>/Sum' incorporates:
           *  Constant: '<S59>/offset'
           */
          Sum_b = (uint32_T)G431currentloop_P.offset_Value[1] +
            G431currentloop_B.Get_Integer;
          G431currentloop_B.Sum_b[1] = Sum_b;

          /* Selector: '<S59>/Lookup' incorporates:
           *  Constant: '<S59>/sine_table_values'
           */
          G431currentloop_B.Lookup[1] =
            G431currentloop_P.sine_table_values_Value[(int32_T)Sum_b];

          /* Sum: '<S59>/Sum' incorporates:
           *  Constant: '<S59>/offset'
           */
          Sum_b = (uint32_T)G431currentloop_P.offset_Value[2] +
            G431currentloop_B.Get_Integer;
          G431currentloop_B.Sum_b[2] = Sum_b;

          /* Selector: '<S59>/Lookup' incorporates:
           *  Constant: '<S59>/sine_table_values'
           */
          G431currentloop_B.Lookup[2] =
            G431currentloop_P.sine_table_values_Value[(int32_T)Sum_b];

          /* Sum: '<S59>/Sum' incorporates:
           *  Constant: '<S59>/offset'
           */
          Sum_b = (uint32_T)G431currentloop_P.offset_Value[3] +
            G431currentloop_B.Get_Integer;
          G431currentloop_B.Sum_b[3] = Sum_b;

          /* Selector: '<S59>/Lookup' incorporates:
           *  Constant: '<S59>/sine_table_values'
           */
          G431currentloop_B.Lookup[3] =
            G431currentloop_P.sine_table_values_Value[(int32_T)Sum_b];

          /* Sum: '<S74>/Sum3' */
          G431currentloop_B.Sum3_h = G431currentloop_B.Lookup[0] -
            G431currentloop_B.Lookup[1];

          /* DataTypeConversion: '<S59>/Data Type Conversion1' */
          G431currentloop_B.DataTypeConversion1 = G431currentloop_B.Get_Integer;

          /* Sum: '<S59>/Sum2' */
          G431currentloop_B.Sum2_p = G431currentloop_B.indexing -
            G431currentloop_B.DataTypeConversion1;

          /* Product: '<S74>/Product' */
          G431currentloop_B.Product_a = G431currentloop_B.Sum3_h *
            G431currentloop_B.Sum2_p;

          /* Sum: '<S74>/Sum4' */
          G431currentloop_B.Sum4_m = G431currentloop_B.Product_a +
            G431currentloop_B.Lookup[1];

          /* Sum: '<S74>/Sum5' */
          G431currentloop_B.Sum5 = G431currentloop_B.Lookup[2] -
            G431currentloop_B.Lookup[3];

          /* Product: '<S74>/Product1' */
          G431currentloop_B.Product1_a = G431currentloop_B.Sum5 *
            G431currentloop_B.Sum2_p;

          /* Sum: '<S74>/Sum6' */
          G431currentloop_B.Sum6 = G431currentloop_B.Product1_a +
            G431currentloop_B.Lookup[3];

          /* Outputs for Atomic SubSystem: '<S58>/Two inputs CRL' */
          /* Product: '<S72>/bcos' */
          G431currentloop_B.bcos = G431currentloop_B.Kbeta *
            G431currentloop_B.Sum6;

          /* Product: '<S72>/asin' */
          G431currentloop_B.asin_j = G431currentloop_B.Kalpha *
            G431currentloop_B.Sum4_m;

          /* Sum: '<S72>/sum_Qs' */
          G431currentloop_B.sum_Qs = G431currentloop_B.bcos -
            G431currentloop_B.asin_j;

          /* Product: '<S72>/acos' */
          G431currentloop_B.acos_p = G431currentloop_B.Kalpha *
            G431currentloop_B.Sum6;

          /* Product: '<S72>/bsin' */
          G431currentloop_B.bsin = G431currentloop_B.Kbeta *
            G431currentloop_B.Sum4_m;

          /* Sum: '<S72>/sum_Ds' */
          G431currentloop_B.sum_Ds = G431currentloop_B.acos_p +
            G431currentloop_B.bsin;

          /* Switch: '<S73>/Switch' incorporates:
           *  Constant: '<S73>/Offset'
           */
          if (G431currentloop_P.Offset_Value_p >
              G431currentloop_P.Switch_Threshold_f) {
            /* UnaryMinus: '<S73>/Unary_Minus' */
            G431currentloop_B.Unary_Minus = -G431currentloop_B.sum_Qs;

            /* Switch: '<S73>/Switch' */
            G431currentloop_B.Switch_f[0] = (real32_T)
              G431currentloop_B.Unary_Minus;
            G431currentloop_B.Switch_f[1] = (real32_T)G431currentloop_B.sum_Ds;
          } else {
            /* Switch: '<S73>/Switch' */
            G431currentloop_B.Switch_f[0] = (real32_T)G431currentloop_B.sum_Ds;
            G431currentloop_B.Switch_f[1] = (real32_T)G431currentloop_B.sum_Qs;
          }

          /* End of Switch: '<S73>/Switch' */

          /* AlgorithmDescriptorDelegate generated from: '<S72>/a16' */
          G431currentloop_B.algDD_o1_le = G431currentloop_B.Switch_f[0];

          /* AlgorithmDescriptorDelegate generated from: '<S72>/a16' */
          G431currentloop_B.algDD_o2_h = G431currentloop_B.Switch_f[1];

          /* End of Outputs for SubSystem: '<S58>/Two inputs CRL' */

          /* Sum: '<S81>/Sum' incorporates:
           *  Constant: '<S14>/Constant2'
           */
          G431currentloop_B.Sum_p = G431currentloop_P.Constant2_Value_c -
            G431currentloop_B.algDD_o2_h;

          /* Product: '<S190>/PProd Out' incorporates:
           *  Constant: '<S60>/Kp'
           */
          G431currentloop_B.PProdOut = G431currentloop_B.Sum_p *
            G431currentloop_P.Kp_Value;

          /* DataStoreRead: '<S14>/Data Store Read' */
          G431currentloop_B.DataStoreRead_d0 = G431currentloop_DW.Enable;

          /* Logic: '<S81>/Logical Operator' */
          G431currentloop_B.LogicalOperator_i = LogicalOperator_tmp;

          /* Constant: '<S81>/Vq_OpenLoop' */
          G431currentloop_B.Vq_OpenLoop = G431currentloop_P.Vq_OpenLoop_Value;

          /* DiscreteIntegrator: '<S185>/Integrator' */
          if (G431currentloop_B.LogicalOperator_i ||
              (G431currentloop_DW.Integrator_PrevResetState != 0)) {
            G431currentloop_DW.Integrator_DSTATE = G431currentloop_B.Vq_OpenLoop;
          }

          /* DiscreteIntegrator: '<S185>/Integrator' */
          G431currentloop_B.Integrator = G431currentloop_DW.Integrator_DSTATE;

          /* Sum: '<S194>/Sum' */
          G431currentloop_B.Sum_l0 = G431currentloop_B.PProdOut +
            G431currentloop_B.Integrator;

          /* Saturate: '<S192>/Saturation' */
          u0 = G431currentloop_B.Sum_l0;
          u1 = G431currentloop_P.DiscretePIControllerwithantiwin;
          u2 = G431currentloop_P.DiscretePIControllerwithantiw_a;
          if (u0 > u2) {
            /* Saturate: '<S192>/Saturation' */
            G431currentloop_B.Saturation = u2;
          } else if (u0 < u1) {
            /* Saturate: '<S192>/Saturation' */
            G431currentloop_B.Saturation = u1;
          } else {
            /* Saturate: '<S192>/Saturation' */
            G431currentloop_B.Saturation = u0;
          }

          /* End of Saturate: '<S192>/Saturation' */

          /* Sum: '<S80>/Sum' incorporates:
           *  Constant: '<S14>/Constant3'
           */
          G431currentloop_B.Sum_c = G431currentloop_P.Constant3_Value_k -
            G431currentloop_B.algDD_o1_le;

          /* Product: '<S137>/PProd Out' incorporates:
           *  Constant: '<S60>/Kp'
           */
          G431currentloop_B.PProdOut_g = G431currentloop_B.Sum_c *
            G431currentloop_P.Kp_Value;

          /* Logic: '<S80>/Logical Operator1' */
          G431currentloop_B.LogicalOperator1 = LogicalOperator_tmp;

          /* Constant: '<S80>/Constant' */
          G431currentloop_B.Constant = G431currentloop_P.Constant_Value_d;

          /* DiscreteIntegrator: '<S132>/Integrator' */
          if (G431currentloop_B.LogicalOperator1 ||
              (G431currentloop_DW.Integrator_PrevResetState_n != 0)) {
            G431currentloop_DW.Integrator_DSTATE_e = G431currentloop_B.Constant;
          }

          /* DiscreteIntegrator: '<S132>/Integrator' */
          G431currentloop_B.Integrator_e =
            G431currentloop_DW.Integrator_DSTATE_e;

          /* Sum: '<S141>/Sum' */
          G431currentloop_B.Sum_o = G431currentloop_B.PProdOut_g +
            G431currentloop_B.Integrator_e;

          /* Saturate: '<S139>/Saturation' */
          u0 = G431currentloop_B.Sum_o;
          u1 = G431currentloop_P.DiscretePIControllerwithantiw_e;
          u2 = G431currentloop_P.DiscretePIControllerwithantiw_l;
          if (u0 > u2) {
            /* Saturate: '<S139>/Saturation' */
            G431currentloop_B.Saturation_c = u2;
          } else if (u0 < u1) {
            /* Saturate: '<S139>/Saturation' */
            G431currentloop_B.Saturation_c = u1;
          } else {
            /* Saturate: '<S139>/Saturation' */
            G431currentloop_B.Saturation_c = u0;
          }

          /* End of Saturate: '<S139>/Saturation' */

          /* Switch: '<S84>/Switch' incorporates:
           *  Constant: '<S84>/enableInportSatLim'
           */
          if (G431currentloop_P.enableInportSatLim_Value != 0) {
            /* Switch: '<S84>/Switch' incorporates:
             *  Constant: '<S79>/ReplaceInport_satLim'
             */
            G431currentloop_B.Switch_c =
              G431currentloop_P.ReplaceInport_satLim_Value;
          } else {
            /* Switch: '<S84>/Switch' incorporates:
             *  Constant: '<S84>/Constant3'
             */
            G431currentloop_B.Switch_c = G431currentloop_P.Constant3_Value;
          }

          /* End of Switch: '<S84>/Switch' */

          /* Product: '<S84>/Product' */
          G431currentloop_B.Product_ah = G431currentloop_B.Switch_c *
            G431currentloop_B.Switch_c;

          /* Product: '<S85>/Product' */
          G431currentloop_B.Product_ar = G431currentloop_B.Saturation_c *
            G431currentloop_B.Saturation_c;

          /* Product: '<S85>/Product1' */
          G431currentloop_B.Product1_k = G431currentloop_B.Saturation *
            G431currentloop_B.Saturation;

          /* Sum: '<S85>/Sum1' */
          G431currentloop_B.Sum1_l = G431currentloop_B.Product_ar +
            G431currentloop_B.Product1_k;

          /* If: '<S79>/If' */
          if ((G431currentloop_B.Switch1_pj == 1) ||
              (G431currentloop_B.Switch1_pj == 2)) {
            /* Outputs for IfAction SubSystem: '<S79>/D//Q Axis Priority' incorporates:
             *  ActionPort: '<S83>/Action Port'
             */
            /* RelationalOperator: '<S88>/Compare' incorporates:
             *  Constant: '<S88>/Constant'
             */
            G431currentloop_B.Compare_d = (G431currentloop_B.Switch1_pj ==
              G431currentloop_P.CompareToConstant_const);

            /* RelationalOperator: '<S89>/Compare' incorporates:
             *  Constant: '<S89>/Constant'
             */
            G431currentloop_B.Compare_f = (G431currentloop_B.Switch1_pj ==
              G431currentloop_P.CompareToConstant1_const);

            /* Switch: '<S83>/Switch' */
            if (G431currentloop_B.Compare_d) {
              /* Switch: '<S83>/Switch' */
              G431currentloop_B.Switch_bs[0] = G431currentloop_B.Saturation_c;
              G431currentloop_B.Switch_bs[1] = G431currentloop_B.Saturation;
            } else {
              /* Switch: '<S83>/Switch' */
              G431currentloop_B.Switch_bs[0] = G431currentloop_B.Saturation;
              G431currentloop_B.Switch_bs[1] = G431currentloop_B.Saturation_c;
            }

            /* End of Switch: '<S83>/Switch' */

            /* RelationalOperator: '<S93>/LowerRelop1' */
            G431currentloop_B.LowerRelop1 = (G431currentloop_B.Switch_bs[0] >
              G431currentloop_B.Switch_c);

            /* Switch: '<S93>/Switch2' */
            if (G431currentloop_B.LowerRelop1) {
              /* Switch: '<S93>/Switch2' */
              G431currentloop_B.Switch2 = G431currentloop_B.Switch_c;
            } else {
              /* Gain: '<S92>/Gain' */
              G431currentloop_B.Gain_l = G431currentloop_P.Gain_Gain_m *
                G431currentloop_B.Switch_c;

              /* RelationalOperator: '<S93>/UpperRelop' */
              G431currentloop_B.UpperRelop = (G431currentloop_B.Switch_bs[0] <
                G431currentloop_B.Gain_l);

              /* Switch: '<S93>/Switch' */
              if (G431currentloop_B.UpperRelop) {
                /* Switch: '<S93>/Switch' */
                G431currentloop_B.Switch_k = G431currentloop_B.Gain_l;
              } else {
                /* Switch: '<S93>/Switch' */
                G431currentloop_B.Switch_k = G431currentloop_B.Switch_bs[0];
              }

              /* End of Switch: '<S93>/Switch' */

              /* Switch: '<S93>/Switch2' */
              G431currentloop_B.Switch2 = G431currentloop_B.Switch_k;
            }

            /* End of Switch: '<S93>/Switch2' */

            /* Product: '<S92>/Product' */
            G431currentloop_B.Product_n1 = G431currentloop_B.Switch2 *
              G431currentloop_B.Switch2;

            /* Sum: '<S92>/Sum' */
            G431currentloop_B.Sum_j = G431currentloop_B.Product_ah -
              G431currentloop_B.Product_n1;

            /* Product: '<S92>/Product2' */
            G431currentloop_B.Product2_b = G431currentloop_B.Switch_bs[1] *
              G431currentloop_B.Switch_bs[1];

            /* RelationalOperator: '<S92>/Relational Operator' */
            G431currentloop_B.RelationalOperator_p = (G431currentloop_B.Sum_j >=
              G431currentloop_B.Product2_b);

            /* DataTypeConversion: '<S92>/Data Type Conversion' */
            G431currentloop_B.DataTypeConversion_bl =
              G431currentloop_B.RelationalOperator_p;

            /* If: '<S92>/If' incorporates:
             *  Switch: '<S94>/Switch1'
             */
            if (G431currentloop_B.DataTypeConversion_bl != 0) {
              /* Outputs for IfAction SubSystem: '<S92>/passThrough' incorporates:
               *  ActionPort: '<S95>/Action Port'
               */
              /* Merge: '<S92>/Merge' incorporates:
               *  SignalConversion generated from: '<S95>/ref2'
               */
              G431currentloop_B.Merge_e = G431currentloop_B.Switch_bs[1];

              /* End of Outputs for SubSystem: '<S92>/passThrough' */
            } else {
              /* Outputs for IfAction SubSystem: '<S92>/limitRef2' incorporates:
               *  ActionPort: '<S94>/Action Port'
               */
              if (G431currentloop_B.Sum_j >
                  G431currentloop_P.Switch1_Threshold_b) {
                /* Switch: '<S94>/Switch1' */
                G431currentloop_B.Switch1_c1 = G431currentloop_B.Sum_j;
              } else {
                /* Switch: '<S94>/Switch1' incorporates:
                 *  Constant: '<S94>/Constant'
                 */
                G431currentloop_B.Switch1_c1 =
                  G431currentloop_P.Constant_Value_o;
              }

              /* Sqrt: '<S94>/Sqrt' */
              mw_arm_sqrt_f32(&G431currentloop_B.Switch1_c1,
                              &G431currentloop_B.Sqrt, 1U);

              /* Switch: '<S94>/Switch' */
              if (G431currentloop_B.Switch_bs[1] >=
                  G431currentloop_P.Switch_Threshold_g) {
                /* Merge: '<S92>/Merge' */
                G431currentloop_B.Merge_e = G431currentloop_B.Sqrt;
              } else {
                /* Gain: '<S94>/Gain' */
                G431currentloop_B.Gain_j = G431currentloop_P.Gain_Gain_j *
                  G431currentloop_B.Sqrt;

                /* Merge: '<S92>/Merge' */
                G431currentloop_B.Merge_e = G431currentloop_B.Gain_j;
              }

              /* End of Switch: '<S94>/Switch' */
              /* End of Outputs for SubSystem: '<S92>/limitRef2' */
            }

            /* End of If: '<S92>/If' */

            /* Switch: '<S83>/Switch1' */
            if (G431currentloop_B.Compare_f) {
              /* Merge: '<S79>/Merge' */
              G431currentloop_B.Merge_n[0] = G431currentloop_B.Switch2;
              G431currentloop_B.Merge_n[1] = G431currentloop_B.Merge_e;
            } else {
              /* Merge: '<S79>/Merge' */
              G431currentloop_B.Merge_n[0] = G431currentloop_B.Merge_e;
              G431currentloop_B.Merge_n[1] = G431currentloop_B.Switch2;
            }

            /* End of Switch: '<S83>/Switch1' */
            /* End of Outputs for SubSystem: '<S79>/D//Q Axis Priority' */
          } else {
            /* Outputs for IfAction SubSystem: '<S79>/D-Q Equivalence' incorporates:
             *  ActionPort: '<S82>/Action Port'
             */
            /* RelationalOperator: '<S82>/Relational Operator' */
            G431currentloop_B.RelationalOperator_o = (G431currentloop_B.Sum1_l >
              G431currentloop_B.Product_ah);

            /* DataTypeConversion: '<S82>/Data Type Conversion' */
            G431currentloop_B.DataTypeConversion_c =
              G431currentloop_B.RelationalOperator_o;

            /* If: '<S82>/If' */
            if (G431currentloop_B.DataTypeConversion_c != 0) {
              /* Outputs for IfAction SubSystem: '<S82>/Limiter' incorporates:
               *  ActionPort: '<S86>/Action Port'
               */
              /* Product: '<S86>/Product' */
              G431currentloop_B.Product_i[0] = G431currentloop_B.Saturation_c *
                G431currentloop_B.Switch_c;
              G431currentloop_B.Product_i[1] = G431currentloop_B.Saturation *
                G431currentloop_B.Switch_c;

              /* Sqrt: '<S86>/Square Root' */
              mw_arm_sqrt_f32(&G431currentloop_B.Sum1_l,
                              &G431currentloop_B.SquareRoot, 1U);

              /* Switch: '<S86>/Switch' */
              if (G431currentloop_B.SquareRoot != 0.0F) {
                /* Switch: '<S86>/Switch' */
                G431currentloop_B.Switch_cc = G431currentloop_B.SquareRoot;
              } else {
                /* Switch: '<S86>/Switch' incorporates:
                 *  Constant: '<S86>/Constant'
                 */
                G431currentloop_B.Switch_cc = G431currentloop_P.Constant_Value_l;
              }

              /* End of Switch: '<S86>/Switch' */

              /* Merge: '<S79>/Merge' incorporates:
               *  Product: '<S86>/Divide'
               */
              G431currentloop_B.Merge_n[0] = G431currentloop_B.Product_i[0] /
                G431currentloop_B.Switch_cc;
              G431currentloop_B.Merge_n[1] = G431currentloop_B.Product_i[1] /
                G431currentloop_B.Switch_cc;

              /* End of Outputs for SubSystem: '<S82>/Limiter' */
            } else {
              /* Outputs for IfAction SubSystem: '<S82>/Passthrough' incorporates:
               *  ActionPort: '<S87>/Action Port'
               */
              /* Merge: '<S79>/Merge' incorporates:
               *  SignalConversion generated from: '<S87>/dqRef'
               */
              G431currentloop_B.Merge_n[0] = G431currentloop_B.Saturation_c;
              G431currentloop_B.Merge_n[1] = G431currentloop_B.Saturation;

              /* End of Outputs for SubSystem: '<S82>/Passthrough' */
            }

            /* End of If: '<S82>/If' */
            /* End of Outputs for SubSystem: '<S79>/D-Q Equivalence' */
          }

          /* End of If: '<S79>/If' */

          /* Outputs for Atomic SubSystem: '<S56>/Two inputs CRL' */
          /* Product: '<S63>/qcos' */
          G431currentloop_B.qcos = G431currentloop_B.Merge_n[1] *
            G431currentloop_B.Sum6;

          /* Product: '<S63>/dsin' */
          G431currentloop_B.dsin = G431currentloop_B.Merge_n[0] *
            G431currentloop_B.Sum4_m;

          /* Sum: '<S63>/sum_beta' */
          G431currentloop_B.sum_beta = G431currentloop_B.qcos +
            G431currentloop_B.dsin;

          /* Product: '<S63>/dcos' */
          G431currentloop_B.dcos = G431currentloop_B.Merge_n[0] *
            G431currentloop_B.Sum6;

          /* Product: '<S63>/qsin' */
          G431currentloop_B.qsin = G431currentloop_B.Merge_n[1] *
            G431currentloop_B.Sum4_m;

          /* Sum: '<S63>/sum_alpha' */
          G431currentloop_B.sum_alpha = G431currentloop_B.dcos -
            G431currentloop_B.qsin;

          /* Switch: '<S64>/Switch' incorporates:
           *  Constant: '<S64>/Offset'
           */
          if (G431currentloop_P.Offset_Value >
              G431currentloop_P.Switch_Threshold_k) {
            /* UnaryMinus: '<S64>/Unary_Minus' */
            G431currentloop_B.Unary_Minus_f = -G431currentloop_B.sum_alpha;

            /* Switch: '<S64>/Switch' */
            G431currentloop_B.Switch[0] = G431currentloop_B.sum_beta;
            G431currentloop_B.Switch[1] = G431currentloop_B.Unary_Minus_f;
          } else {
            /* Switch: '<S64>/Switch' */
            G431currentloop_B.Switch[0] = G431currentloop_B.sum_alpha;
            G431currentloop_B.Switch[1] = G431currentloop_B.sum_beta;
          }

          /* End of Switch: '<S64>/Switch' */

          /* AlgorithmDescriptorDelegate generated from: '<S63>/a16' */
          G431currentloop_B.algDD_o1 = G431currentloop_B.Switch[0];

          /* AlgorithmDescriptorDelegate generated from: '<S63>/a16' */
          G431currentloop_B.algDD_o2 = G431currentloop_B.Switch[1];

          /* End of Outputs for SubSystem: '<S56>/Two inputs CRL' */

          /* DataStoreRead: '<S15>/Data Store Read1' */
          G431currentloop_B.DataStoreRead1_b = G431currentloop_DW.Enable;

          /* Switch: '<S15>/Switch4' incorporates:
           *  Constant: '<S15>/stop'
           */
          if (G431currentloop_B.DataStoreRead1_b) {
            /* Gain: '<S71>/sqrt3_by_two' */
            G431currentloop_B.sqrt3_by_two = G431currentloop_P.sqrt3_by_two_Gain
              * G431currentloop_B.algDD_o2;

            /* Gain: '<S71>/one_by_two' */
            G431currentloop_B.one_by_two = G431currentloop_P.one_by_two_Gain *
              G431currentloop_B.algDD_o1;

            /* Sum: '<S71>/add_c' */
            G431currentloop_B.add_c = (0.0 - G431currentloop_B.one_by_two) -
              G431currentloop_B.sqrt3_by_two;

            /* Gain: '<S71>/Kc' */
            G431currentloop_B.Kc = G431currentloop_P.Kc_Gain *
              G431currentloop_B.add_c;

            /* Sum: '<S71>/add_b' */
            G431currentloop_B.add_b = G431currentloop_B.sqrt3_by_two -
              G431currentloop_B.one_by_two;

            /* Gain: '<S71>/Kb' */
            G431currentloop_B.Kb = G431currentloop_P.Kb_Gain *
              G431currentloop_B.add_b;

            /* Gain: '<S71>/Ka' */
            G431currentloop_B.Ka = G431currentloop_P.Ka_Gain *
              G431currentloop_B.algDD_o1;

            /* MinMax: '<S68>/Min' */
            Bias = fmin(G431currentloop_B.Ka, G431currentloop_B.Kb);
            Bias = fmin(Bias, G431currentloop_B.Kc);

            /* MinMax: '<S68>/Min' */
            G431currentloop_B.Min = Bias;

            /* MinMax: '<S68>/Max' */
            Bias = fmax(G431currentloop_B.Ka, G431currentloop_B.Kb);
            Bias = fmax(Bias, G431currentloop_B.Kc);

            /* MinMax: '<S68>/Max' */
            G431currentloop_B.Max = Bias;

            /* Sum: '<S68>/Add' */
            G431currentloop_B.Add_j = G431currentloop_B.Max +
              G431currentloop_B.Min;

            /* Gain: '<S68>/one_by_two' */
            G431currentloop_B.one_by_two_d = G431currentloop_P.one_by_two_Gain_g
              * G431currentloop_B.Add_j;

            /* Sum: '<S67>/Add2' */
            G431currentloop_B.Add2 = G431currentloop_B.one_by_two_d +
              G431currentloop_B.Kc;

            /* Sum: '<S67>/Add1' */
            G431currentloop_B.Add1_j = G431currentloop_B.Kb +
              G431currentloop_B.one_by_two_d;

            /* Sum: '<S67>/Add3' */
            G431currentloop_B.Add3 = G431currentloop_B.Ka +
              G431currentloop_B.one_by_two_d;

            /* Gain: '<S67>/Gain' */
            G431currentloop_B.Gain[0] = G431currentloop_P.Gain_Gain_i *
              G431currentloop_B.Add3;
            G431currentloop_B.Gain[1] = G431currentloop_P.Gain_Gain_i *
              G431currentloop_B.Add1_j;
            G431currentloop_B.Gain[2] = G431currentloop_P.Gain_Gain_i *
              G431currentloop_B.Add2;

            /* Gain: '<S15>/Gain' */
            u0 = (real32_T)(G431currentloop_P.Gain_Gain_k *
                            G431currentloop_B.Gain[0]);
            G431currentloop_B.Gain_d[0] = u0;

            /* Sum: '<S15>/Add' incorporates:
             *  Constant: '<S15>/Constant1'
             */
            u0 += G431currentloop_P.Constant1_Value_e;
            G431currentloop_B.Add_l[0] = u0;

            /* Gain: '<S15>/Gain1' */
            u0 *= G431currentloop_P.Gain1_Gain;
            G431currentloop_B.Gain1[0] = u0;

            /* Switch: '<S15>/Switch4' */
            G431currentloop_B.Switch4[0] = u0;

            /* Gain: '<S15>/Gain' */
            u0 = (real32_T)(G431currentloop_P.Gain_Gain_k *
                            G431currentloop_B.Gain[1]);
            G431currentloop_B.Gain_d[1] = u0;

            /* Sum: '<S15>/Add' incorporates:
             *  Constant: '<S15>/Constant1'
             */
            u0 += G431currentloop_P.Constant1_Value_e;
            G431currentloop_B.Add_l[1] = u0;

            /* Gain: '<S15>/Gain1' */
            u0 *= G431currentloop_P.Gain1_Gain;
            G431currentloop_B.Gain1[1] = u0;

            /* Switch: '<S15>/Switch4' */
            G431currentloop_B.Switch4[1] = u0;

            /* Gain: '<S15>/Gain' */
            u0 = (real32_T)(G431currentloop_P.Gain_Gain_k *
                            G431currentloop_B.Gain[2]);
            G431currentloop_B.Gain_d[2] = u0;

            /* Sum: '<S15>/Add' incorporates:
             *  Constant: '<S15>/Constant1'
             */
            u0 += G431currentloop_P.Constant1_Value_e;
            G431currentloop_B.Add_l[2] = u0;

            /* Gain: '<S15>/Gain1' */
            u0 *= G431currentloop_P.Gain1_Gain;
            G431currentloop_B.Gain1[2] = u0;

            /* Switch: '<S15>/Switch4' */
            G431currentloop_B.Switch4[2] = u0;
          } else {
            u0 = G431currentloop_P.stop_Value;

            /* Switch: '<S15>/Switch4' incorporates:
             *  Constant: '<S15>/stop'
             */
            G431currentloop_B.Switch4[0] = u0;
            G431currentloop_B.Switch4[1] = u0;
            G431currentloop_B.Switch4[2] = u0;
          }

          /* End of Switch: '<S15>/Switch4' */

          /* MATLABSystem: '<S204>/PWM Output' */
          setDutyCycleInPercentageChannel1(G431currentloop_DW.obj_h.TimerHandle,
            G431currentloop_B.Switch4[0]);
          setDutyCycleInPercentageChannel2(G431currentloop_DW.obj_h.TimerHandle,
            G431currentloop_B.Switch4[1]);
          setDutyCycleInPercentageChannel3(G431currentloop_DW.obj_h.TimerHandle,
            G431currentloop_B.Switch4[2]);

          /* Signum: '<S20>/Sign' */
          Bias = G431currentloop_B.Sum2;
          if (rtIsNaN(Bias)) {
            /* Signum: '<S20>/Sign' */
            G431currentloop_B.Sign = (rtNaN);
          } else if (Bias < 0.0) {
            /* Signum: '<S20>/Sign' */
            G431currentloop_B.Sign = -1.0;
          } else {
            /* Signum: '<S20>/Sign' */
            G431currentloop_B.Sign = (Bias > 0.0);
          }

          /* End of Signum: '<S20>/Sign' */

          /* Gain: '<S20>/Eta' incorporates:
           *  Gain: '<S21>/Eta'
           */
          Bias = G431currentloop_P.SlidingModeObserver_CurrentObse / 2.2;
          u0 = (real32_T)Bias;

          /* Gain: '<S20>/Eta' */
          G431currentloop_B.Eta = u0 * G431currentloop_B.Sign;

          /* Sum: '<S20>/Sum' */
          G431currentloop_B.Sum = G431currentloop_B.Delay5[0] -
            G431currentloop_B.Sum4;

          /* Gain: '<S20>/b' */
          G431currentloop_B.b = G431currentloop_P.b_Gain * G431currentloop_B.Sum;

          /* Gain: '<S20>/a' */
          G431currentloop_B.a_g = G431currentloop_P.a_Gain_b *
            G431currentloop_B.Delay;

          /* Sum: '<S20>/Sum1' */
          G431currentloop_B.Sum1 = (G431currentloop_B.b - G431currentloop_B.Eta)
            + G431currentloop_B.a_g;

          /* Signum: '<S21>/Sign' */
          Bias = G431currentloop_B.Sum2_f;
          if (rtIsNaN(Bias)) {
            /* Signum: '<S21>/Sign' */
            G431currentloop_B.Sign_h = (rtNaN);
          } else if (Bias < 0.0) {
            /* Signum: '<S21>/Sign' */
            G431currentloop_B.Sign_h = -1.0;
          } else {
            /* Signum: '<S21>/Sign' */
            G431currentloop_B.Sign_h = (Bias > 0.0);
          }

          /* End of Signum: '<S21>/Sign' */

          /* Gain: '<S21>/Eta' */
          G431currentloop_B.Eta_i = u0 * G431currentloop_B.Sign_h;

          /* Sum: '<S21>/Sum' */
          G431currentloop_B.Sum_l = G431currentloop_B.Delay5[1] -
            G431currentloop_B.Sum4_p;

          /* Gain: '<S21>/b' */
          G431currentloop_B.b_g = G431currentloop_P.b_Gain_h *
            G431currentloop_B.Sum_l;

          /* Gain: '<S21>/a' */
          G431currentloop_B.a_l = G431currentloop_P.a_Gain_o *
            G431currentloop_B.Delay_f;

          /* Sum: '<S21>/Sum1' */
          G431currentloop_B.Sum1_g = (G431currentloop_B.b_g -
            G431currentloop_B.Eta_i) + G431currentloop_B.a_l;

          /* Gain: '<S25>/PositionToCount' */
          Bias = trunc(G431currentloop_P.PositionToCount_Gain *
                       G431currentloop_B.Switch_l);
          if (rtIsNaN(Bias) || rtIsInf(Bias)) {
            Bias = 0.0;
          } else {
            Bias = fmod(Bias, 4.294967296E+9);
          }

          /* Gain: '<S25>/PositionToCount' */
          G431currentloop_B.PositionToCount = Bias < 0.0 ? (uint32_T)-(int32_T)
            (uint32_T)-Bias : (uint32_T)Bias;

          /* Delay: '<S25>/Delay' */
          G431currentloop_B.Delay_o =
            G431currentloop_DW.Delay_DSTATE_h[G431currentloop_DW.CircBufIdx];

          /* Sum: '<S25>/SpeedCount' */
          G431currentloop_B.SpeedCount = (int32_T)
            G431currentloop_B.PositionToCount - (int32_T)
            G431currentloop_B.Delay_o;

          /* DataTypeConversion: '<S42>/DTC' */
          G431currentloop_B.DTC = (real32_T)G431currentloop_B.SpeedCount;

          /* Gain: '<S25>/SpeedGain' */
          G431currentloop_B.SpeedGain = G431currentloop_P.SpeedGain_Gain *
            G431currentloop_B.DTC;

          /* Switch: '<S24>/Switch1' incorporates:
           *  Constant: '<S24>/UseInputPort'
           */
          if (G431currentloop_P.UseInputPort_Value_o >
              G431currentloop_P.Switch1_Threshold_k) {
            /* Sum: '<S24>/Sum' incorporates:
             *  Constant: '<S24>/One'
             *  Constant: '<S24>/a'
             */
            G431currentloop_B.Sum_m = G431currentloop_P.One_Value_f -
              G431currentloop_P.a_Value_j;

            /* Switch: '<S24>/Switch1' incorporates:
             *  Constant: '<S24>/a'
             */
            G431currentloop_B.Switch1_p[0] = G431currentloop_P.a_Value_j;
            G431currentloop_B.Switch1_p[1] = G431currentloop_B.Sum_m;
          } else {
            /* Switch: '<S24>/Switch1' incorporates:
             *  Constant: '<S24>/FilterConstant'
             *  Constant: '<S24>/OneMinusFilterConstant'
             */
            G431currentloop_B.Switch1_p[0] =
              G431currentloop_P.FilterConstant_Value_k;
            G431currentloop_B.Switch1_p[1] =
              G431currentloop_P.OneMinusFilterConstant_Value_f;
          }

          /* End of Switch: '<S24>/Switch1' */

          /* Product: '<S40>/Product' */
          G431currentloop_B.Product_h = G431currentloop_B.SpeedGain *
            G431currentloop_B.Switch1_p[0];

          /* UnitDelay: '<S40>/Unit Delay' */
          G431currentloop_B.UnitDelay_m = G431currentloop_DW.UnitDelay_DSTATE_p;

          /* Product: '<S40>/Product1' */
          G431currentloop_B.Product1_d = G431currentloop_B.Switch1_p[1] *
            G431currentloop_B.UnitDelay_m;

          /* Sum: '<S40>/Add1' */
          G431currentloop_B.Add1_h = G431currentloop_B.Product_h +
            G431currentloop_B.Product1_d;

          /* DeadZone: '<S124>/DeadZone' */
          if (G431currentloop_B.Sum_o >
              G431currentloop_P.DiscretePIControllerwithantiw_l) {
            /* DeadZone: '<S124>/DeadZone' */
            G431currentloop_B.DeadZone = G431currentloop_B.Sum_o -
              G431currentloop_P.DiscretePIControllerwithantiw_l;
          } else if (G431currentloop_B.Sum_o >=
                     G431currentloop_P.DiscretePIControllerwithantiw_e) {
            /* DeadZone: '<S124>/DeadZone' */
            G431currentloop_B.DeadZone = 0.0F;
          } else {
            /* DeadZone: '<S124>/DeadZone' */
            G431currentloop_B.DeadZone = G431currentloop_B.Sum_o -
              G431currentloop_P.DiscretePIControllerwithantiw_e;
          }

          /* End of DeadZone: '<S124>/DeadZone' */

          /* RelationalOperator: '<S122>/Relational Operator' incorporates:
           *  Constant: '<S122>/Clamping_zero'
           */
          G431currentloop_B.RelationalOperator =
            (G431currentloop_P.Clamping_zero_Value != G431currentloop_B.DeadZone);

          /* RelationalOperator: '<S122>/fix for DT propagation issue' incorporates:
           *  Constant: '<S122>/Clamping_zero'
           */
          G431currentloop_B.fixforDTpropagationissue =
            (G431currentloop_B.DeadZone > G431currentloop_P.Clamping_zero_Value);

          /* Switch: '<S122>/Switch1' */
          if (G431currentloop_B.fixforDTpropagationissue) {
            /* Switch: '<S122>/Switch1' incorporates:
             *  Constant: '<S122>/Constant'
             */
            G431currentloop_B.Switch1_a = G431currentloop_P.Constant_Value_m;
          } else {
            /* Switch: '<S122>/Switch1' incorporates:
             *  Constant: '<S122>/Constant2'
             */
            G431currentloop_B.Switch1_a = G431currentloop_P.Constant2_Value_j;
          }

          /* End of Switch: '<S122>/Switch1' */

          /* Product: '<S129>/IProd Out' incorporates:
           *  Constant: '<S60>/Ki'
           */
          G431currentloop_B.IProdOut = G431currentloop_B.Sum_c *
            G431currentloop_P.Ki_Value;

          /* RelationalOperator: '<S122>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S122>/Clamping_zero'
           */
          G431currentloop_B.fixforDTpropagationissue1 =
            (G431currentloop_B.IProdOut > G431currentloop_P.Clamping_zero_Value);

          /* Switch: '<S122>/Switch2' */
          if (G431currentloop_B.fixforDTpropagationissue1) {
            /* Switch: '<S122>/Switch2' incorporates:
             *  Constant: '<S122>/Constant3'
             */
            G431currentloop_B.Switch2_n = G431currentloop_P.Constant3_Value_j;
          } else {
            /* Switch: '<S122>/Switch2' incorporates:
             *  Constant: '<S122>/Constant4'
             */
            G431currentloop_B.Switch2_n = G431currentloop_P.Constant4_Value;
          }

          /* End of Switch: '<S122>/Switch2' */

          /* RelationalOperator: '<S122>/Equal1' */
          G431currentloop_B.Equal1 = (G431currentloop_B.Switch1_a ==
            G431currentloop_B.Switch2_n);

          /* Logic: '<S122>/AND3' */
          G431currentloop_B.AND3 = (G431currentloop_B.RelationalOperator &&
            G431currentloop_B.Equal1);

          /* Switch: '<S122>/Switch' */
          if (G431currentloop_B.AND3) {
            /* Switch: '<S122>/Switch' incorporates:
             *  Constant: '<S122>/Constant1'
             */
            G431currentloop_B.Switch_p = G431currentloop_P.Constant1_Value_b;
          } else {
            /* Switch: '<S122>/Switch' */
            G431currentloop_B.Switch_p = G431currentloop_B.IProdOut;
          }

          /* End of Switch: '<S122>/Switch' */

          /* DeadZone: '<S177>/DeadZone' */
          if (G431currentloop_B.Sum_l0 >
              G431currentloop_P.DiscretePIControllerwithantiw_a) {
            /* DeadZone: '<S177>/DeadZone' */
            G431currentloop_B.DeadZone_p = G431currentloop_B.Sum_l0 -
              G431currentloop_P.DiscretePIControllerwithantiw_a;
          } else if (G431currentloop_B.Sum_l0 >=
                     G431currentloop_P.DiscretePIControllerwithantiwin) {
            /* DeadZone: '<S177>/DeadZone' */
            G431currentloop_B.DeadZone_p = 0.0F;
          } else {
            /* DeadZone: '<S177>/DeadZone' */
            G431currentloop_B.DeadZone_p = G431currentloop_B.Sum_l0 -
              G431currentloop_P.DiscretePIControllerwithantiwin;
          }

          /* End of DeadZone: '<S177>/DeadZone' */

          /* RelationalOperator: '<S175>/Relational Operator' incorporates:
           *  Constant: '<S175>/Clamping_zero'
           */
          G431currentloop_B.RelationalOperator_g =
            (G431currentloop_P.Clamping_zero_Value_c !=
             G431currentloop_B.DeadZone_p);

          /* RelationalOperator: '<S175>/fix for DT propagation issue' incorporates:
           *  Constant: '<S175>/Clamping_zero'
           */
          G431currentloop_B.fixforDTpropagationissue_a =
            (G431currentloop_B.DeadZone_p >
             G431currentloop_P.Clamping_zero_Value_c);

          /* Switch: '<S175>/Switch1' */
          if (G431currentloop_B.fixforDTpropagationissue_a) {
            /* Switch: '<S175>/Switch1' incorporates:
             *  Constant: '<S175>/Constant'
             */
            G431currentloop_B.Switch1_j = G431currentloop_P.Constant_Value_c;
          } else {
            /* Switch: '<S175>/Switch1' incorporates:
             *  Constant: '<S175>/Constant2'
             */
            G431currentloop_B.Switch1_j = G431currentloop_P.Constant2_Value_g;
          }

          /* End of Switch: '<S175>/Switch1' */

          /* Product: '<S182>/IProd Out' incorporates:
           *  Constant: '<S60>/Ki'
           */
          G431currentloop_B.IProdOut_i = G431currentloop_B.Sum_p *
            G431currentloop_P.Ki_Value;

          /* RelationalOperator: '<S175>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S175>/Clamping_zero'
           */
          G431currentloop_B.fixforDTpropagationissue1_o =
            (G431currentloop_B.IProdOut_i >
             G431currentloop_P.Clamping_zero_Value_c);

          /* Switch: '<S175>/Switch2' */
          if (G431currentloop_B.fixforDTpropagationissue1_o) {
            /* Switch: '<S175>/Switch2' incorporates:
             *  Constant: '<S175>/Constant3'
             */
            G431currentloop_B.Switch2_nn = G431currentloop_P.Constant3_Value_m;
          } else {
            /* Switch: '<S175>/Switch2' incorporates:
             *  Constant: '<S175>/Constant4'
             */
            G431currentloop_B.Switch2_nn = G431currentloop_P.Constant4_Value_p;
          }

          /* End of Switch: '<S175>/Switch2' */

          /* RelationalOperator: '<S175>/Equal1' */
          G431currentloop_B.Equal1_d = (G431currentloop_B.Switch1_j ==
            G431currentloop_B.Switch2_nn);

          /* Logic: '<S175>/AND3' */
          G431currentloop_B.AND3_g = (G431currentloop_B.RelationalOperator_g &&
            G431currentloop_B.Equal1_d);

          /* Switch: '<S175>/Switch' */
          if (G431currentloop_B.AND3_g) {
            /* Switch: '<S175>/Switch' incorporates:
             *  Constant: '<S175>/Constant1'
             */
            G431currentloop_B.Switch_j = G431currentloop_P.Constant1_Value_ex;
          } else {
            /* Switch: '<S175>/Switch' */
            G431currentloop_B.Switch_j = G431currentloop_B.IProdOut_i;
          }

          /* End of Switch: '<S175>/Switch' */

          /* SignalConversion generated from: '<S2>/Delay5' */
          G431currentloop_B.TmpSignalConversionAtDelay5Inpo[0] =
            G431currentloop_B.algDD_o1;
          G431currentloop_B.TmpSignalConversionAtDelay5Inpo[1] =
            G431currentloop_B.algDD_o2;
          G431currentloop_B.TmpSignalConversionAtDelay5Inpo[2] =
            G431currentloop_B.Kalpha;
          G431currentloop_B.TmpSignalConversionAtDelay5Inpo[3] =
            G431currentloop_B.Kbeta;

          /* Update for UnitDelay: '<S30>/Unit Delay1' */
          G431currentloop_DW.UnitDelay1_DSTATE = G431currentloop_B.Eta;

          /* Update for UnitDelay: '<S30>/Unit Delay' */
          G431currentloop_DW.UnitDelay_DSTATE = G431currentloop_B.Sum2;

          /* Update for Delay: '<S2>/Delay5' */
          G431currentloop_DW.Delay5_DSTATE[0] =
            G431currentloop_B.TmpSignalConversionAtDelay5Inpo[0];
          G431currentloop_DW.Delay5_DSTATE[1] =
            G431currentloop_B.TmpSignalConversionAtDelay5Inpo[1];
          G431currentloop_DW.Delay5_DSTATE[2] =
            G431currentloop_B.TmpSignalConversionAtDelay5Inpo[2];
          G431currentloop_DW.Delay5_DSTATE[3] =
            G431currentloop_B.TmpSignalConversionAtDelay5Inpo[3];

          /* Update for Delay: '<S20>/Delay' */
          G431currentloop_DW.Delay_DSTATE = G431currentloop_B.Sum1;

          /* Update for Delay: '<S30>/Delay1' */
          G431currentloop_DW.Delay1_DSTATE = G431currentloop_B.Sum4;

          /* Update for UnitDelay: '<S34>/Unit Delay' */
          G431currentloop_DW.UnitDelay_DSTATE_c = G431currentloop_B.Add1;

          /* Update for UnitDelay: '<S31>/Unit Delay1' */
          G431currentloop_DW.UnitDelay1_DSTATE_f = G431currentloop_B.Eta_i;

          /* Update for UnitDelay: '<S31>/Unit Delay' */
          G431currentloop_DW.UnitDelay_DSTATE_j = G431currentloop_B.Sum2_f;

          /* Update for Delay: '<S21>/Delay' */
          G431currentloop_DW.Delay_DSTATE_p = G431currentloop_B.Sum1_g;

          /* Update for Delay: '<S31>/Delay1' */
          G431currentloop_DW.Delay1_DSTATE_f = G431currentloop_B.Sum4_p;

          /* Update for UnitDelay: '<S37>/Unit Delay' */
          G431currentloop_DW.UnitDelay_DSTATE_ca = G431currentloop_B.Add1_o;

          /* Update for Delay: '<S18>/Delay' */
          G431currentloop_DW.Delay_DSTATE_pt = G431currentloop_B.Add1_h;

          /* Update for UnitDelay: '<S52>/Unit Delay' */
          G431currentloop_DW.UnitDelay_DSTATE_i = G431currentloop_B.Add1_d;

          /* Update for DiscreteIntegrator: '<S185>/Integrator' */
          G431currentloop_DW.Integrator_DSTATE +=
            G431currentloop_P.Integrator_gainval * G431currentloop_B.Switch_j;
          Integrator_PrevResetState_tmp = (int8_T)
            G431currentloop_B.LogicalOperator_i;
          G431currentloop_DW.Integrator_PrevResetState =
            Integrator_PrevResetState_tmp;

          /* Update for DiscreteIntegrator: '<S132>/Integrator' */
          G431currentloop_DW.Integrator_DSTATE_e +=
            G431currentloop_P.Integrator_gainval_m * G431currentloop_B.Switch_p;
          G431currentloop_DW.Integrator_PrevResetState_n =
            Integrator_PrevResetState_tmp;

          /* Update for Delay: '<S25>/Delay' */
          G431currentloop_DW.Delay_DSTATE_h[G431currentloop_DW.CircBufIdx] =
            G431currentloop_B.PositionToCount;
          if (G431currentloop_DW.CircBufIdx < 23U) {
            G431currentloop_DW.CircBufIdx++;
          } else {
            G431currentloop_DW.CircBufIdx = 0U;
          }

          /* End of Update for Delay: '<S25>/Delay' */

          /* Update for UnitDelay: '<S40>/Unit Delay' */
          G431currentloop_DW.UnitDelay_DSTATE_p = G431currentloop_B.Add1_h;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S206>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void G431currentloop_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
