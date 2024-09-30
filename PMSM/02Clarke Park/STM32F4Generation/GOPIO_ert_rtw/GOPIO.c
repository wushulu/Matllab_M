/*
 * File: GOPIO.c
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.12
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Sep 27 23:20:48 2024
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
#include "stm_timer_ll.h"
#include <math.h>

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
  real_T rtb_PulseGenerator;
  int32_T c;
  uint32_T freq;

  /* MATLABSystem: '<S21>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  rtb_PulseGenerator = rt_roundd_snf(GOPIO_P.Constant3_Value);
  if (rtb_PulseGenerator < 4.294967296E+9) {
    if (rtb_PulseGenerator >= 0.0) {
      freq = (uint32_T)rtb_PulseGenerator;
    } else {
      freq = 0U;
    }
  } else {
    freq = MAX_uint32_T;
  }

  freq = checkFrequencyAndDutyCycleLimits(GOPIO_DW.obj_e.TimerHandle, freq);
  setFrequencyAccToInput(GOPIO_DW.obj_e.TimerHandle, freq);
  setDutyCycleInPercentageChannel1(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Constant1_Value);
  setDutyCycleInPercentageChannel2(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Constant2_Value);
  setDutyCycleInPercentageChannel3(GOPIO_DW.obj_e.TimerHandle,
    GOPIO_P.Constant2_Value);

  /* End of MATLABSystem: '<S21>/PWM Output' */
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (GOPIO_DW.clockTickCounter < GOPIO_P.PulseGenerator_Duty)
    && (GOPIO_DW.clockTickCounter >= 0) ? GOPIO_P.PulseGenerator_Amp : 0.0;
  if (GOPIO_DW.clockTickCounter >= GOPIO_P.PulseGenerator_Period - 1.0) {
    GOPIO_DW.clockTickCounter = 0;
  } else {
    GOPIO_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S11>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S11>/Digital Port Write' */
}

/* Model initialize function */
void GOPIO_initialize(void)
{
  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

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
        /* S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          uint16_T tmp[2];

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
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S19>/Hardware Interrupt' */
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
