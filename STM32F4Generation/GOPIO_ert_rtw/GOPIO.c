/*
 * File: GOPIO.c
 *
 * Code generated for Simulink model 'GOPIO'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Sep  6 21:50:22 2024
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
#include "rt_nonfinite.h"
#include <math.h>
#include <float.h>

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
static void GOPIO_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_GO_T *obj);
uint32_T plook_evenc(real_T u, real_T bp0, real_T bpSpace, uint32_T maxIndex,
                     real_T *fraction)
{
  uint32_T bpIndex;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp0) {
    bpIndex = 0U;
    *fraction = 0.0;
  } else {
    real_T fbpIndex;
    real_T invSpc;
    invSpc = 1.0 / bpSpace;
    fbpIndex = (u - bp0) * invSpc;
    if (fbpIndex < maxIndex) {
      bpIndex = (uint32_T)fbpIndex;
      *fraction = (u - ((real_T)(uint32_T)fbpIndex * bpSpace + bp0)) * invSpc;
    } else {
      bpIndex = maxIndex - 1U;
      *fraction = 1.0;
    }
  }

  return bpIndex;
}

real_T intrp1d_l_pw(uint32_T bpIndex, real_T frac, const real_T table[])
{
  real_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (table[bpIndex + 1U] - yL_0d0) * frac + yL_0d0;
}

static void GOPIO_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
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
  adcStructLoc.InternalBufferSize = 2U;
  adcStructLoc.InjectedNoOfConversion = 2U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_2RANKS);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  y = u0;
  if (u1 == 0.0) {
    if (u0 == 0.0) {
      y = u1;
    }
  } else if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (u0 == 0.0) {
    y = 0.0 / u1;
  } else if (rtIsInf(u1)) {
    if ((u1 < 0.0) != (u0 < 0.0)) {
      y = u1;
    }
  } else {
    boolean_T yEq;
    y = fmod(u0, u1);
    yEq = (y == 0.0);
    if ((!yEq) && (u1 > floor(u1))) {
      real_T q;
      q = fabs(u0 / u1);
      yEq = !(fabs(q - floor(q + 0.5)) > DBL_EPSILON * q);
    }

    if (yEq) {
      y = u1 * 0.0;
    } else if ((u0 < 0.0) != (u1 < 0.0)) {
      y += u1;
    }
  }

  return y;
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

  /* Start for MATLABSystem: '<S16>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S16>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S16>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void GOPIO_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_GO_T *obj)
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
void GOPIO_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_TmpRTBAtFunctionCallSubsyst;
  int32_T c;
  real32_T uartWriteData;
  uint32_T freq;

  /* MATLABSystem: '<S16>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant3'
   */
  rtb_TmpRTBAtFunctionCallSubsyst = rt_roundd_snf(GOPIO_P.Constant3_Value);
  if (rtb_TmpRTBAtFunctionCallSubsyst < 4.294967296E+9) {
    if (rtb_TmpRTBAtFunctionCallSubsyst >= 0.0) {
      freq = (uint32_T)rtb_TmpRTBAtFunctionCallSubsyst;
    } else {
      freq = 0U;
    }
  } else {
    freq = MAX_uint32_T;
  }

  freq = checkFrequencyAndDutyCycleLimits(GOPIO_DW.obj_h.TimerHandle, freq);
  setFrequencyAccToInput(GOPIO_DW.obj_h.TimerHandle, freq);
  setDutyCycleInPercentageChannel1(GOPIO_DW.obj_h.TimerHandle,
    GOPIO_P.Constant1_Value);
  setDutyCycleInPercentageChannel2(GOPIO_DW.obj_h.TimerHandle,
    GOPIO_P.Constant2_Value);
  setDutyCycleInPercentageChannel3(GOPIO_DW.obj_h.TimerHandle,
    GOPIO_P.Constant2_Value);

  /* End of MATLABSystem: '<S16>/PWM Output' */
  /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
  rtb_TmpRTBAtFunctionCallSubsyst = GOPIO_B.Sin;

  /* MATLABSystem: '<Root>/UART//USART Write' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion'
   */
  uartWriteData = (real32_T)rtb_TmpRTBAtFunctionCallSubsyst;
  MW_UART_TransmitUsingInterrupt(GOPIO_DW.obj.UARTHandle, &uartWriteData, 4U, 0U,
    &freq);

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_TmpRTBAtFunctionCallSubsyst = (GOPIO_DW.clockTickCounter <
    GOPIO_P.PulseGenerator_Duty) && (GOPIO_DW.clockTickCounter >= 0) ?
    GOPIO_P.PulseGenerator_Amp : 0.0;
  if (GOPIO_DW.clockTickCounter >= GOPIO_P.PulseGenerator_Period - 1.0) {
    GOPIO_DW.clockTickCounter = 0;
  } else {
    GOPIO_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S6>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_TmpRTBAtFunctionCallSubsyst != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S6>/Digital Port Write' */
}

/* Model initialize function */
void GOPIO_initialize(void)
{
  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */

  /* InitializeConditions for Sum: '<S11>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S8>/Output'
   */
  GOPIO_DW.Output_DSTATE = GOPIO_P.Output_InitialCondition;

  /* Start for MATLABSystem: '<S10>/Analog to Digital Converter' */
  GOPIO_DW.obj_g.isInitialized = 0;
  GOPIO_DW.obj_g.matlabCodegenIsDeleted = false;
  GOPIO_SystemCore_setup(&GOPIO_DW.obj_g);

  /* SystemInitialize for Trigonometry: '<S2>/Sin' incorporates:
   *  Outport: '<S2>/Out1'
   */
  GOPIO_B.Sin = GOPIO_P.Out1_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

  /* Start for MATLABSystem: '<S16>/PWM Output' */
  GOPIO_DW.obj_h.matlabCodegenIsDeleted = false;
  GOPIO_DW.obj_h.isSetupComplete = false;
  GOPIO_DW.obj_h.isInitialized = 1;
  GOPIO_PWMOutput_setupImpl(&GOPIO_DW.obj_h);
  GOPIO_DW.obj_h.isSetupComplete = true;

  /* Start for MATLABSystem: '<Root>/UART//USART Write' */
  GOPIO_DW.obj.matlabCodegenIsDeleted = false;
  GOPIO_DW.obj.isSetupComplete = false;
  GOPIO_DW.obj.isInitialized = 1;
  GOPIO_UARTWrite_setupImpl(&GOPIO_DW.obj);
  GOPIO_DW.obj.isSetupComplete = true;
}

/* Model terminate function */
void GOPIO_terminate(void)
{
  /* Terminate for MATLABSystem: '<S16>/PWM Output' */
  if (!GOPIO_DW.obj_h.matlabCodegenIsDeleted) {
    GOPIO_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj_h.isInitialized == 1) && GOPIO_DW.obj_h.isSetupComplete) {
      disableCounter(GOPIO_DW.obj_h.TimerHandle);
      disableTimerInterrupts(GOPIO_DW.obj_h.TimerHandle, 0);
      disableTimerChannel1(GOPIO_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(GOPIO_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(GOPIO_DW.obj_h.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S16>/PWM Output' */
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S10>/Analog to Digital Converter' */
  if (!GOPIO_DW.obj_g.matlabCodegenIsDeleted) {
    GOPIO_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj_g.isInitialized == 1) && GOPIO_DW.obj_g.isSetupComplete) {
      ADC_Handle_Deinit(GOPIO_DW.obj_g.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S10>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<Root>/UART//USART Write' */
  if (!GOPIO_DW.obj.matlabCodegenIsDeleted) {
    GOPIO_DW.obj.matlabCodegenIsDeleted = true;
    if ((GOPIO_DW.obj.isInitialized == 1) && GOPIO_DW.obj.isSetupComplete) {
      MW_UART_DeInit(GOPIO_DW.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/UART//USART Write' */
}

void GOPIO_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S14>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          real_T frac;
          real_T uVarTmp;
          uint32_T bpIdx;
          uint16_T tmp[2];
          boolean_T negFlag;
          static const real_T tableData_c[16] = { 0.0, 0.10452846326765346,
            0.20791169081775931, 0.3090169943749474, 0.40673664307580015,
            0.49999999999999994, 0.58778525229247314, 0.66913060635885824,
            0.74314482547739424, 0.80901699437494745, 0.8660254037844386,
            0.91354545764260087, 0.95105651629515353, 0.97814760073380569,
            0.99452189536827329, 1.0 };

          /* MATLABSystem: '<S10>/Analog to Digital Converter' */
          injectedReadADCIntr(GOPIO_DW.obj_g.ADCHandle, ADC_READ, &tmp[0]);

          /* Trigonometry: '<S2>/Sin' incorporates:
           *  Constant: '<S2>/Constant'
           *  DataTypeConversion: '<S2>/Data Type Conversion'
           *  Gain: '<S2>/Gain'
           *  Math: '<S2>/Mod'
           *  UnitDelay: '<S8>/Output'
           */
          uVarTmp = rt_modd_snf((real_T)((uint64_T)GOPIO_P.Gain_Gain *
            GOPIO_DW.Output_DSTATE) * 4.5474735088646412E-13,
                                GOPIO_P.Constant_Value) / 6.2831853071795862;
          if (uVarTmp < 0.0) {
            uVarTmp++;
          }

          if (uVarTmp > 0.5) {
            uVarTmp -= 0.5;
            negFlag = true;
          } else {
            negFlag = false;
          }

          if (uVarTmp > 0.25) {
            uVarTmp = 0.5 - uVarTmp;
          }

          bpIdx = plook_evenc(uVarTmp, 0.0, 0.016666666666666666, 15U, &frac);
          uVarTmp = intrp1d_l_pw(bpIdx, frac, tableData_c);
          if (negFlag) {
            uVarTmp = -uVarTmp;
          }

          /* Trigonometry: '<S2>/Sin' */
          GOPIO_B.Sin = uVarTmp;

          /* Sum: '<S11>/FixPt Sum1' incorporates:
           *  Constant: '<S11>/FixPt Constant'
           *  UnitDelay: '<S8>/Output'
           */
          GOPIO_DW.Output_DSTATE += GOPIO_P.FixPtConstant_Value;

          /* Switch: '<S12>/FixPt Switch' */
          if (GOPIO_DW.Output_DSTATE > GOPIO_P.WrapToZero_Threshold) {
            /* Sum: '<S11>/FixPt Sum1' incorporates:
             *  Constant: '<S12>/Constant'
             *  UnitDelay: '<S8>/Output'
             */
            GOPIO_DW.Output_DSTATE = GOPIO_P.Constant_Value_a;
          }

          /* End of Switch: '<S12>/FixPt Switch' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S14>/Hardware Interrupt' */
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
