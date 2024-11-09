/*
 * File: mcb_pmsm_foc_sensorless_nucleo_f401re.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_nucleo_f401re'.
 *
 * Model version                  : 8.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Nov  8 22:37:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_sensorless_nucleo_f401re.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_sensorless_nucleo_f401re_types.h"
#include "mcb_pmsm_foc_sensorless_nucleo_f401re_private.h"
#include <math.h>
#include "stm_adc_ll.h"
#include "arm_math.h"
#include "mw_cmsis.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "zero_crossing_types.h"
#include <string.h>
#include "rt_defines.h"

/* Block signals (default storage) */
BlockIO_mcb_pmsm_foc_sensorless mcb_pmsm_foc_sensorless_nucle_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_foc_sensorless_ mcb_pmsm_foc_sensorless_n_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_mcb_pmsm_foc_se mcb_pmsm_foc_sen_PrevZCSigState;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_sensorles mcb_pmsm_foc_sensorless_nucl_M_;
RT_MODEL_mcb_pmsm_foc_sensorles *const mcb_pmsm_foc_sensorless_nucl_M =
  &mcb_pmsm_foc_sensorless_nucl_M_;

/* Forward declaration for local functions */
static void mcb_pmsm_foc_s_SystemCore_setup(stm32cube_blocks_AnalogInput_mc *obj);

/* Forward declaration for local functions */
static void mcb_pmsm_foc_SystemCore_setup_b(stm32cube_blocks_AnalogInput_f *obj);
static void mcb_pmsm_fo_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mcb_ *obj);

/* Forward declaration for local functions */
static void mcb_pmsm_fo_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_mcb_ *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_sensorless_nucleo_f401re_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_sensorless_nucl_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_sensorless_nucl_M, 2));
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
  (mcb_pmsm_foc_sensorless_nucl_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_sensorless_nucl_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.0005s, 0.0s] */
    mcb_pmsm_foc_sensorless_nucl_M->Timing.TaskCounters.TID[1] = 0;
  }

  (mcb_pmsm_foc_sensorless_nucl_M->Timing.TaskCounters.TID[2])++;
  if ((mcb_pmsm_foc_sensorless_nucl_M->Timing.TaskCounters.TID[2]) > 4999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_sensorless_nucl_M->Timing.TaskCounters.TID[2] = 0;
  }
}

static void mcb_pmsm_foc_SystemCore_setup_b(stm32cube_blocks_AnalogInput_f *obj)
{
  void * internalBufferPtr;
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S170>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  internalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S170>/Analog to Digital Converter' */
  adcStructLoc.RegularNoOfConversion = 0U;
  adcStructLoc.InternalBufferPtr = internalBufferPtr;

  /* Start for MATLABSystem: '<S170>/Analog to Digital Converter' */
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

static void mcb_pmsm_fo_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_mcb_ *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S205>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S205>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S205>/PWM Output' */
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

static void mcb_pmsm_foc_s_SystemCore_setup(stm32cube_blocks_AnalogInput_mc *obj)
{
  void * internalBufferPtr;
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S222>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  internalBufferPtr = (void*)(&obj->ADCInternalBuffer[0]);
  adcStructLoc.InjectedNoOfConversion = 0U;
  adcStructLoc.InternalBufferPtr = internalBufferPtr;

  /* Start for MATLABSystem: '<S222>/Analog to Digital Converter' */
  adcStructLoc.peripheralPtr = ADC1;
  adcStructLoc.dmaPeripheralPtr = DMA2;
  adcStructLoc.dmastream = LL_DMA_STREAM_0;
  adcStructLoc.DataTransferMode = ADC_DR_TRANSFER;
  adcStructLoc.DmaTransferMode = ADC_DMA_TRANSFER_LIMITED;
  adcStructLoc.InternalBufferSize = 1U;
  adcStructLoc.RegularNoOfConversion = 1U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_DMA_INTERRUPT_MODE, 1,
    ADC_TRIGGER_AND_READ, LL_ADC_REG_SEQ_SCAN_DISABLE);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 1);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void mcb_pmsm__SpeedControl_Init(rtB_SpeedControl_mcb_pmsm_foc_s *localB,
  rtDW_SpeedControl_mcb_pmsm_foc_ *localDW)
{
  /* Start for Constant: '<S215>/Ki2' */
  localB->Ki2 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S220>/Integrate Time' */
  localDW->IntegrateTime_PrevResetState = 2;

  /* InitializeConditions for RateLimiter: '<S216>/Rate Limiter' */
  localDW->PrevY = 0.1F;

  /* InitializeConditions for RateLimiter: '<S216>/Rate Limiter1' */
  localDW->PrevY_d = -0.1F;

  /* InitializeConditions for DiscreteIntegrator: '<S260>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
  localDW->Integrator_PrevResetState = 0;

  /* SystemInitialize for Enabled SubSystem: '<S218>/Enabled Subsystem' */
  /* InitializeConditions for UnitDelay: '<S282>/Unit Delay' */
  localDW->UnitDelay_DSTATE_n = true;

  /* End of SystemInitialize for SubSystem: '<S218>/Enabled Subsystem' */

  /* Start for MATLABSystem: '<S222>/Analog to Digital Converter' */
  localDW->obj.isInitialized = 0;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty_m = true;
  mcb_pmsm_foc_s_SystemCore_setup(&localDW->obj);

  /* Start for MATLABSystem: '<S285>/Digital Port Read' */
  localDW->objisempty_h = true;
  localDW->obj_n.isInitialized = 1;

  /* Start for MATLABSystem: '<S288>/Digital Port Write' */
  localDW->objisempty = true;
  localDW->obj_j.isInitialized = 1;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void mcb_pmsm_foc_s_SpeedControl(real32_T rtu_Speed_Meas_PU,
  rtB_SpeedControl_mcb_pmsm_foc_s *localB, rtDW_SpeedControl_mcb_pmsm_foc_
  *localDW)
{
  GPIO_TypeDef * portNameLoc;
  int32_T c;
  int32_T c_0;
  real32_T rateLimiterRate;
  uint32_T pinReadLoc;
  uint16_T data;
  boolean_T tmp;

  /* MATLABSystem: '<S222>/Analog to Digital Converter' */
  regularReadADCDMA(localDW->obj.ADCHandle, ADC_TRIGGER_AND_READ, &data);

  /* MATLABSystem: '<S222>/Analog to Digital Converter' */
  localB->AnalogtoDigitalConverter = data;

  /* MATLABSystem: '<S285>/Digital Port Read' */
  pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);
  tmp = ((pinReadLoc & 8192U) != 0U);

  /* MATLABSystem: '<S285>/Digital Port Read' */
  localB->DigitalPortRead = tmp;

  /* Logic: '<S218>/NOT' */
  localB->NOT = !localB->DigitalPortRead;

  /* UnitDelay: '<S218>/Unit Delay' */
  localB->UnitDelay_n = localDW->UnitDelay_DSTATE_l;

  /* Logic: '<S218>/NOT2' */
  localB->NOT2 = !localB->UnitDelay_n;

  /* Logic: '<S218>/AND' */
  localB->AND = (localB->NOT && localB->NOT2);

  /* Outputs for Enabled SubSystem: '<S218>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S282>/Enable'
   */
  if (localB->AND) {
    /* UnitDelay: '<S282>/Unit Delay' */
    localB->UnitDelay_k = localDW->UnitDelay_DSTATE_n;

    /* Logic: '<S282>/NOT' */
    localB->NOT_b = !localB->UnitDelay_k;

    /* Update for UnitDelay: '<S282>/Unit Delay' */
    localDW->UnitDelay_DSTATE_n = localB->NOT_b;
  }

  /* End of Outputs for SubSystem: '<S218>/Enabled Subsystem' */

  /* UnitDelay: '<S220>/Unit Delay' */
  localB->UnitDelay_l = localDW->UnitDelay_DSTATE_b;

  /* RelationalOperator: '<S220>/Relational Operator' */
  localB->RelationalOperator = (localB->UnitDelay_k != localB->UnitDelay_l);

  /* DiscreteIntegrator: '<S220>/Integrate Time' */
  if (localB->RelationalOperator && (localDW->IntegrateTime_PrevResetState <= 0))
  {
    localDW->IntegrateTime_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S220>/Integrate Time' */
  localB->IntegrateTime = localDW->IntegrateTime_DSTATE;

  /* Switch: '<S214>/Switch' */
  if (localB->UnitDelay_k) {
    /* RelationalOperator: '<S223>/Compare' incorporates:
     *  Constant: '<S223>/Constant'
     */
    localB->Compare = (localB->IntegrateTime <= 1.0);

    /* Switch: '<S220>/Pass value' */
    if (localB->Compare) {
      /* Gain: '<S214>/rpm2PU1' incorporates:
       *  Constant: '<S214>/Constant'
       */
      localB->rpm2PU1 = 0.1F;

      /* Switch: '<S220>/Pass value' */
      localB->Passvalue = 0.1F;
    } else {
      /* Gain: '<S214>/Gain1' */
      localB->Gain1 = 0.000244140625F * (real32_T)
        localB->AnalogtoDigitalConverter;

      /* Switch: '<S220>/Pass value' */
      localB->Passvalue = localB->Gain1;
    }

    /* End of Switch: '<S220>/Pass value' */

    /* Switch: '<S214>/Switch' */
    localB->Switch = localB->Passvalue;
  } else {
    /* Switch: '<S214>/Switch' incorporates:
     *  Constant: '<S214>/Constant4'
     */
    localB->Switch = 0.0F;
  }

  /* End of Switch: '<S214>/Switch' */

  /* Constant: '<S6>/Constant2' */
  localB->Constant2 = 0.0F;

  /* RateLimiter: '<S216>/Rate Limiter' */
  rateLimiterRate = localB->Switch - localDW->PrevY;
  if (rateLimiterRate > 0.00204834086F) {
    /* RateLimiter: '<S216>/Rate Limiter' */
    localB->RateLimiter = localDW->PrevY + 0.00204834086F;
  } else if (rateLimiterRate < -0.00204834086F) {
    /* RateLimiter: '<S216>/Rate Limiter' */
    localB->RateLimiter = localDW->PrevY - 0.00204834086F;
  } else {
    /* RateLimiter: '<S216>/Rate Limiter' */
    localB->RateLimiter = localB->Switch;
  }

  localDW->PrevY = localB->RateLimiter;

  /* End of RateLimiter: '<S216>/Rate Limiter' */

  /* RateLimiter: '<S216>/Rate Limiter1' */
  rateLimiterRate = localB->Switch - localDW->PrevY_d;
  if (rateLimiterRate > 0.00204834086F) {
    /* RateLimiter: '<S216>/Rate Limiter1' */
    localB->RateLimiter1 = localDW->PrevY_d + 0.00204834086F;
  } else if (rateLimiterRate < -0.00204834086F) {
    /* RateLimiter: '<S216>/Rate Limiter1' */
    localB->RateLimiter1 = localDW->PrevY_d - 0.00204834086F;
  } else {
    /* RateLimiter: '<S216>/Rate Limiter1' */
    localB->RateLimiter1 = localB->Switch;
  }

  localDW->PrevY_d = localB->RateLimiter1;

  /* End of RateLimiter: '<S216>/Rate Limiter1' */

  /* Switch: '<S216>/Switch' */
  localB->Switch_p = localB->RateLimiter;

  /* Switch: '<S277>/Switch1' incorporates:
   *  Constant: '<S277>/FilterConstant'
   *  Constant: '<S277>/OneMinusFilterConstant'
   */
  localB->Switch1[0] = 0.1F;
  localB->Switch1[1] = 0.9F;

  /* Product: '<S280>/Product' */
  localB->Product = localB->Switch_p * 0.1F;

  /* UnitDelay: '<S280>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* Product: '<S280>/Product1' */
  localB->Product1 = 0.9F * localB->UnitDelay;

  /* Sum: '<S280>/Add1' */
  localB->Add1 = localB->Product + localB->Product1;

  /* Abs: '<S217>/Abs' */
  localB->Abs = fabsf(localB->Add1);

  /* Switch: '<S217>/Switch2' */
  localB->Switch2_m = (localB->Abs > 0.1F);

  /* Logic: '<S215>/AND' */
  localB->AND_g = (localB->UnitDelay_k && localB->Switch2_m);

  /* Switch: '<S217>/Switch' incorporates:
   *  Switch: '<S217>/Switch1'
   */
  if (localB->Switch2_m) {
    /* Switch: '<S217>/Switch' */
    localB->Switch_i = localB->Add1;
  } else {
    if (localB->Add1 > 0.0F) {
      /* Switch: '<S217>/Switch1' incorporates:
       *  Constant: '<S217>/Constant'
       */
      localB->Switch1_l = 0.1F;
    } else {
      /* Switch: '<S217>/Switch1' incorporates:
       *  Constant: '<S217>/Constant1'
       */
      localB->Switch1_l = -0.1F;
    }

    /* Switch: '<S217>/Switch' */
    localB->Switch_i = localB->Switch1_l;
  }

  /* End of Switch: '<S217>/Switch' */

  /* Sum: '<S215>/Sum' */
  localB->Sum = localB->Switch_i - rtu_Speed_Meas_PU;

  /* Product: '<S265>/PProd Out' incorporates:
   *  Constant: '<S215>/Kp1'
   */
  localB->PProdOut = localB->Sum * 0.410410672F;

  /* Logic: '<S215>/Logical Operator' */
  localB->LogicalOperator = !localB->AND_g;

  /* Constant: '<S215>/Ki2' */
  localB->Ki2 = 0.0F;

  /* DiscreteIntegrator: '<S260>/Integrator' */
  if (localB->LogicalOperator || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S260>/Integrator' */
  localB->Integrator = localDW->Integrator_DSTATE;

  /* Sum: '<S269>/Sum' */
  localB->Sum_b = localB->PProdOut + localB->Integrator;

  /* DeadZone: '<S252>/DeadZone' */
  if (localB->Sum_b > 1.0F) {
    /* DeadZone: '<S252>/DeadZone' */
    localB->DeadZone = localB->Sum_b - 1.0F;
  } else if (localB->Sum_b >= -1.0F) {
    /* DeadZone: '<S252>/DeadZone' */
    localB->DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S252>/DeadZone' */
    localB->DeadZone = localB->Sum_b - -1.0F;
  }

  /* End of DeadZone: '<S252>/DeadZone' */

  /* RelationalOperator: '<S250>/Relational Operator' incorporates:
   *  Constant: '<S250>/Clamping_zero'
   */
  localB->RelationalOperator_l = (localB->DeadZone != 0.0F);

  /* RelationalOperator: '<S250>/fix for DT propagation issue' incorporates:
   *  Constant: '<S250>/Clamping_zero'
   */
  localB->fixforDTpropagationissue = (localB->DeadZone > 0.0F);

  /* Switch: '<S250>/Switch1' */
  if (localB->fixforDTpropagationissue) {
    /* Switch: '<S250>/Switch1' incorporates:
     *  Constant: '<S250>/Constant'
     */
    localB->Switch1_o = 1;
  } else {
    /* Switch: '<S250>/Switch1' incorporates:
     *  Constant: '<S250>/Constant2'
     */
    localB->Switch1_o = -1;
  }

  /* End of Switch: '<S250>/Switch1' */

  /* Product: '<S257>/IProd Out' incorporates:
   *  Constant: '<S215>/Ki1'
   */
  localB->IProdOut = localB->Sum * 0.0029937753F;

  /* RelationalOperator: '<S250>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S250>/Clamping_zero'
   */
  localB->fixforDTpropagationissue1 = (localB->IProdOut > 0.0F);

  /* Switch: '<S250>/Switch2' */
  if (localB->fixforDTpropagationissue1) {
    /* Switch: '<S250>/Switch2' incorporates:
     *  Constant: '<S250>/Constant3'
     */
    localB->Switch2 = 1;
  } else {
    /* Switch: '<S250>/Switch2' incorporates:
     *  Constant: '<S250>/Constant4'
     */
    localB->Switch2 = -1;
  }

  /* End of Switch: '<S250>/Switch2' */

  /* RelationalOperator: '<S250>/Equal1' */
  localB->Equal1 = (localB->Switch1_o == localB->Switch2);

  /* Logic: '<S250>/AND3' */
  localB->AND3 = (localB->RelationalOperator_l && localB->Equal1);

  /* Switch: '<S250>/Switch' */
  if (localB->AND3) {
    /* Switch: '<S250>/Switch' incorporates:
     *  Constant: '<S250>/Constant1'
     */
    localB->Switch_pd = 0.0F;
  } else {
    /* Switch: '<S250>/Switch' */
    localB->Switch_pd = localB->IProdOut;
  }

  /* End of Switch: '<S250>/Switch' */

  /* Saturate: '<S267>/Saturation' */
  rateLimiterRate = localB->Sum_b;
  if (rateLimiterRate > 1.0F) {
    /* Saturate: '<S267>/Saturation' */
    localB->Saturation = 1.0F;
  } else if (rateLimiterRate < -1.0F) {
    /* Saturate: '<S267>/Saturation' */
    localB->Saturation = -1.0F;
  } else {
    /* Saturate: '<S267>/Saturation' */
    localB->Saturation = rateLimiterRate;
  }

  /* End of Saturate: '<S267>/Saturation' */

  /* Switch: '<S283>/Switch' */
  localB->Switch_o = localB->UnitDelay_k;

  /* MATLABSystem: '<S288>/Digital Port Write' */
  portNameLoc = GPIOC;
  if (localB->Switch_o) {
    pinReadLoc = 1024U;
    c = 2048;
    c_0 = 4096;
  } else {
    pinReadLoc = 0U;
    c = 0;
    c_0 = 0;
  }

  pinReadLoc = pinReadLoc | (uint32_T)c | (uint32_T)c_0;
  LL_GPIO_SetOutputPin(portNameLoc, pinReadLoc);
  LL_GPIO_ResetOutputPin(portNameLoc, ~pinReadLoc & 7168U);

  /* End of MATLABSystem: '<S288>/Digital Port Write' */

  /* Update for UnitDelay: '<S218>/Unit Delay' */
  localDW->UnitDelay_DSTATE_l = localB->NOT;

  /* Update for UnitDelay: '<S220>/Unit Delay' */
  localDW->UnitDelay_DSTATE_b = localB->UnitDelay_k;

  /* Update for DiscreteIntegrator: '<S220>/Integrate Time' */
  localDW->IntegrateTime_DSTATE += 0.0005;
  localDW->IntegrateTime_PrevResetState = (int8_T)localB->RelationalOperator;

  /* Update for UnitDelay: '<S280>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;

  /* Update for DiscreteIntegrator: '<S260>/Integrator' */
  localDW->Integrator_DSTATE += localB->Switch_pd;
  localDW->Integrator_PrevResetState = (int8_T)localB->LogicalOperator;
}

/* Termination for atomic system: '<Root>/Speed Control' */
void mcb_pmsm__SpeedControl_Term(rtDW_SpeedControl_mcb_pmsm_foc_ *localDW)
{
  /* Terminate for MATLABSystem: '<S222>/Analog to Digital Converter' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      ADC_Handle_Deinit(localDW->obj.ADCHandle, ADC_DMA_INTERRUPT_MODE, 1);
    }
  }

  /* End of Terminate for MATLABSystem: '<S222>/Analog to Digital Converter' */
}

static void mcb_pmsm_fo_UARTWrite_setupImpl(stm32cube_blocks_UARTWrite_mcb_ *obj)
{
  uint8_T * txBufferPtr;
  UART_Type_T b;
  txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);

  /* Start for MATLABSystem: '<S290>/UART//USART Write1' incorporates:
   *  MATLABSystem: '<S289>/UART//USART Write'
   */
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = USART2;
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  b.buffer.txBufferPtr = txBufferPtr;
  obj->UARTHandle = MW_UART_Initialize(&b);
}

/* Model step function for TID0 */
void mcb_pmsm_foc_sensorless_nucleo_f401re_step0(void) /* Sample time: [0.0001s, 0.0s] */
{
  real32_T uartWriteData[3];
  uint32_T sentLength;
  uint16_T status;
  uint8_T uartWriteData_0[4];

  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Sin: '<Root>/Sine Wave' */
  mcb_pmsm_foc_sensorless_nucle_B.SineWave = sin((real_T)
    mcb_pmsm_foc_sensorless_n_DWork.counter * 2.0 * 3.1415926535897931 / 10.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion = (real32_T)
    mcb_pmsm_foc_sensorless_nucle_B.SineWave;

  /* Assignment: '<S7>/Assignment' incorporates:
   *  Constant: '<S7>/Constant'
   */
  mcb_pmsm_foc_sensorless_nucle_B.Assignment[1] = 200.0F;
  mcb_pmsm_foc_sensorless_nucle_B.Assignment[2] = 22.0F;

  /* Assignment: '<S7>/Assignment' incorporates:
   *  Constant: '<S7>/Constant2'
   */
  mcb_pmsm_foc_sensorless_nucle_B.Assignment[0] =
    mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion;

  /* Sin: '<Root>/Sine Wave1' */
  mcb_pmsm_foc_sensorless_nucle_B.SineWave1 = sin(((real_T)
    mcb_pmsm_foc_sensorless_n_DWork.counter_g + 3.0) * 2.0 * 3.1415926535897931 /
    10.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1 = (real32_T)
    mcb_pmsm_foc_sensorless_nucle_B.SineWave1;

  /* Assignment: '<S7>/Assignment1' */
  mcb_pmsm_foc_sensorless_nucle_B.Assignment1[0] =
    mcb_pmsm_foc_sensorless_nucle_B.Assignment[0];
  mcb_pmsm_foc_sensorless_nucle_B.Assignment1[2] =
    mcb_pmsm_foc_sensorless_nucle_B.Assignment[2];

  /* Assignment: '<S7>/Assignment1' incorporates:
   *  Constant: '<S7>/Constant3'
   */
  mcb_pmsm_foc_sensorless_nucle_B.Assignment1[1] =
    mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1;

  /* Sin: '<Root>/Sine Wave2' */
  mcb_pmsm_foc_sensorless_nucle_B.SineWave2 = sin(((real_T)
    mcb_pmsm_foc_sensorless_n_DWork.counter_k + 7.0) * 2.0 * 3.1415926535897931 /
    10.0);

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion2 = (real32_T)
    mcb_pmsm_foc_sensorless_nucle_B.SineWave2;

  /* Assignment: '<S7>/Assignment2' */
  mcb_pmsm_foc_sensorless_nucle_B.Assignment2[0] =
    mcb_pmsm_foc_sensorless_nucle_B.Assignment1[0];
  mcb_pmsm_foc_sensorless_nucle_B.Assignment2[1] =
    mcb_pmsm_foc_sensorless_nucle_B.Assignment1[1];

  /* Assignment: '<S7>/Assignment2' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  mcb_pmsm_foc_sensorless_nucle_B.Assignment2[2] =
    mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion2;

  /* MATLABSystem: '<S289>/UART//USART Write' */
  uartWriteData[0] = mcb_pmsm_foc_sensorless_nucle_B.Assignment2[0];
  uartWriteData[1] = mcb_pmsm_foc_sensorless_nucle_B.Assignment2[1];
  uartWriteData[2] = mcb_pmsm_foc_sensorless_nucle_B.Assignment2[2];
  status = MW_UART_TransmitUsingInterrupt
    (mcb_pmsm_foc_sensorless_n_DWork.obj.UARTHandle, &uartWriteData[0], 12U, 0U,
     &sentLength);

  /* MATLABSystem: '<S289>/UART//USART Write' */
  mcb_pmsm_foc_sensorless_nucle_B.UARTUSARTWrite = status;

  /* Logic: '<S289>/NOT' */
  mcb_pmsm_foc_sensorless_nucle_B.NOT =
    (mcb_pmsm_foc_sensorless_nucle_B.UARTUSARTWrite == 0);

  /* Outputs for Enabled SubSystem: '<S289>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S290>/Enable'
   */
  if (mcb_pmsm_foc_sensorless_nucle_B.NOT) {
    /* MATLABSystem: '<S290>/UART//USART Write1' incorporates:
     *  Constant: '<S290>/Constant1'
     */
    uartWriteData_0[0] = 0U;
    uartWriteData_0[1] = 0U;
    uartWriteData_0[2] = 128U;
    uartWriteData_0[3] = 127U;
    MW_UART_TransmitUsingInterrupt
      (mcb_pmsm_foc_sensorless_n_DWork.obj_h.UARTHandle, &uartWriteData_0[0], 4U,
       0U, &sentLength);
  }

  /* End of Outputs for SubSystem: '<S289>/Enabled Subsystem' */

  /* Update for Sin: '<Root>/Sine Wave' */
  mcb_pmsm_foc_sensorless_n_DWork.counter++;
  if (mcb_pmsm_foc_sensorless_n_DWork.counter == 10) {
    mcb_pmsm_foc_sensorless_n_DWork.counter = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */

  /* Update for Sin: '<Root>/Sine Wave1' */
  mcb_pmsm_foc_sensorless_n_DWork.counter_g++;
  if (mcb_pmsm_foc_sensorless_n_DWork.counter_g == 10) {
    mcb_pmsm_foc_sensorless_n_DWork.counter_g = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave1' */

  /* Update for Sin: '<Root>/Sine Wave2' */
  mcb_pmsm_foc_sensorless_n_DWork.counter_k++;
  if (mcb_pmsm_foc_sensorless_n_DWork.counter_k == 10) {
    mcb_pmsm_foc_sensorless_n_DWork.counter_k = 0;
  }

  /* End of Update for Sin: '<Root>/Sine Wave2' */
}

/* Model step function for TID1 */
void mcb_pmsm_foc_sensorless_nucleo_f401re_step1(void) /* Sample time: [0.0005s, 0.0s] */
{
  /* RateTransition: '<Root>/RT3' */
  mcb_pmsm_foc_sensorless_nucle_B.RT3 =
    mcb_pmsm_foc_sensorless_nucle_B.SpeedConversion;

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  mcb_pmsm_foc_s_SpeedControl(mcb_pmsm_foc_sensorless_nucle_B.RT3,
    &mcb_pmsm_foc_sensorless_nucle_B.SpeedControl,
    &mcb_pmsm_foc_sensorless_n_DWork.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/RT' */
  mcb_pmsm_foc_sensorless_n_DWork.RT_Buffer0 =
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.UnitDelay_k;

  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_sensorless_n_DWork.RT1_Buffer0 =
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch_i;

  /* RateTransition: '<Root>/RT5' */
  mcb_pmsm_foc_sensorless_n_DWork.RT5_Buffer0 =
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch2_m;
}

/* Model step function for TID2 */
void mcb_pmsm_foc_sensorless_nucleo_f401re_step2(void) /* Sample time: [0.5s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  int32_T c;

  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* UnitDelay: '<S4>/Unit Delay' */
  mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_o1 =
    mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_c;

  /* MATLABSystem: '<S212>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_o1) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S212>/Digital Port Write' */

  /* Logic: '<S4>/NOT' */
  mcb_pmsm_foc_sensorless_nucle_B.NOT_n =
    !mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_o1;

  /* Update for UnitDelay: '<S4>/Unit Delay' */
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_c =
    mcb_pmsm_foc_sensorless_nucle_B.NOT_n;

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_sensorless_nucleo_f401re_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_sensorless_nucl_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_sensorles));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_sensorless_nucle_B), 0,
                sizeof(BlockIO_mcb_pmsm_foc_sensorless));

  {
    mcb_pmsm_foc_sensorless_nucle_B.SineWave = 0.0;
    mcb_pmsm_foc_sensorless_nucle_B.SineWave1 = 0.0;
    mcb_pmsm_foc_sensorless_nucle_B.SineWave2 = 0.0;
    mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment1[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment2[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment2[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Assignment2[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.RT3 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.RT1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.GetADCVoltage[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.GetADCVoltage[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.GetCurrents[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.GetCurrents[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.PU_Conversion[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.PU_Conversion[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.InvertingNoninvertingCurrentmea[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.InvertingNoninvertingCurrentmea[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.a = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay5[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay5[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay5[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay5[3] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay_g = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum3 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.b_invg = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum4 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_o = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay1_k = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_e = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.a_g = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay_c = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum2_b = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum3_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.b_invg_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay1_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum4_g = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch1_b[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch1_b[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_e = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_l = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product1_m = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add1_i = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Merge = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Merge1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Delay_f = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Gain = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_p = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Merge_g = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.indexing = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Lookup[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Lookup[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Lookup[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Lookup[3] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum3_p = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1_o = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum2_bl = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_ez = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum4_f = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum5 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product1_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum6 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_g = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.PProdOut = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_c = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Integrator = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_l = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_h = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_k = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.PProdOut_a = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_m = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Integrator_c = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_kn = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_l = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_f = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_b = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_k = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product1_no = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Merge_e[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Merge_e[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.DeadZone = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.IProdOut = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_fm = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.DeadZone_d = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.IProdOut_h = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_m = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sign = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Eta = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_i = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.b = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.a_o = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum1_c = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sign_m = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Eta_e = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_iv = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.b_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.a_gy = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum1_h = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.DTC = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedGain = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch1_bl[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch1_bl[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_m = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_g = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product1_mm = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add1_c = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedConversion = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.one_by_two = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.add_c = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.add_b = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Min = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Max = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.one_by_two_p = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add3 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add1_i4 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Gain_f[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Gain_f[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Gain_f[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.One_by_Two[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.One_by_Two[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.One_by_Two[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_h[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_h[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_h[2] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_c = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum1_h1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product1_f = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product3 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum2_k = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_l4 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Atan2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_i = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.algDD = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Gain_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_b = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Bias = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Bias_e = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Convert_back = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Convert_back_a = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.acos_k = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.bsin = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.sum_Ds = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.bcos = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.asin_e = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.sum_Qs = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_o[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_o[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.algDD_o1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.algDD_o2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.AngleConversion = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add_o = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1_j = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Add1_g = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Input = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.qcos = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.dsin = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.sum_beta = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.dcos = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.qsin = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.sum_alpha = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_ih[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_ih[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_o = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.algDD_o2_k = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Saturation = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Abs = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Saturation_h = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Saturation_i = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_l[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_l[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SquareRoot = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_a = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_fu[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_fu[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product_d = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sum_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Product2_l = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Merge_gk = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Gain_d = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch_p = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Switch1_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Sqrt = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.Gain_du = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.a_plus_2b = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_n = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.algDD_o2_e = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.IntegrateTime = 0.0;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Constant2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.RateLimiter = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.RateLimiter1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch_p = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch1[0] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch1[1] = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Product = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.UnitDelay = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Product1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Add1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Abs = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch_i = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Sum = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.PProdOut = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Ki2 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Integrator = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Sum_b = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.DeadZone = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.IProdOut = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch_pd = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Saturation = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Switch1_l = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Passvalue = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Gain1 = 0.0F;
    mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.rpm2PU1 = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_sensorless_n_DWork, 0,
                sizeof(D_Work_mcb_pmsm_foc_sensorless_));
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay1_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[2] = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[3] = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_o = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay1_DSTATE_n = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_m = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_k = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE_e = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_g = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_e = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_h = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_a = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_p = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE_a = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_hu = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.RT1_Buffer0 = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.SpeedControl.IntegrateTime_DSTATE = 0.0;
  mcb_pmsm_foc_sensorless_n_DWork.SpeedControl.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.SpeedControl.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.SpeedControl.PrevY = 0.0F;
  mcb_pmsm_foc_sensorless_n_DWork.SpeedControl.PrevY_d = 0.0F;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  mcb_pmsm_foc_sensorless_n_DWork.IaOffset = 1665U;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  mcb_pmsm_foc_sensorless_n_DWork.IbOffset = 1943U;
  mcb_pmsm_foc_sen_PrevZCSigState.Dir_Sense_Trig_ZCE = POS_ZCSIG;
  mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
  mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
  mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_h = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  mcb_pmsm_foc_sensorless_n_DWork.counter = 0;

  /* InitializeConditions for Sin: '<Root>/Sine Wave1' */
  mcb_pmsm_foc_sensorless_n_DWork.counter_g = 0;

  /* InitializeConditions for Sin: '<Root>/Sine Wave2' */
  mcb_pmsm_foc_sensorless_n_DWork.counter_k = 0;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Current Control'
   */
  /* System initialize for function-call system: '<Root>/Current Control' */

  /* InitializeConditions for Delay: '<S178>/Delay' */
  mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S188>/Delay1' */
  mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S179>/Delay' */
  mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_k = 0.0F;

  /* InitializeConditions for Delay: '<S189>/Delay1' */
  mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE_e = 0.0F;

  /* InitializeConditions for Delay: '<S176>/Delay' */
  mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_e = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S131>/Integrator' */
  mcb_pmsm_foc_sensorless_n_DWork.Integrator_PrevResetState = 0;
  mcb_pmsm_foc_sensorless_n_DWork.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator' */
  mcb_pmsm_foc_sensorless_n_DWork.Integrator_PrevResetState_e = 0;
  mcb_pmsm_foc_sensorless_n_DWork.Integrator_IC_LOADING_b = 1U;

  /* InitializeConditions for Delay: '<S183>/Delay' */
  mcb_pmsm_foc_sensorless_n_DWork.CircBufIdx = 0U;

  /* Start for MATLABSystem: '<S170>/Analog to Digital Converter' */
  mcb_pmsm_foc_sensorless_n_DWork.obj_d.isInitialized = 0;
  mcb_pmsm_foc_sensorless_n_DWork.obj_d.matlabCodegenIsDeleted = false;
  mcb_pmsm_foc_sensorless_n_DWork.objisempty_e = true;
  mcb_pmsm_foc_SystemCore_setup_b(&mcb_pmsm_foc_sensorless_n_DWork.obj_d);

  /* Start for MATLABSystem: '<S205>/PWM Output' */
  mcb_pmsm_foc_sensorless_n_DWork.obj_b.matlabCodegenIsDeleted = false;
  mcb_pmsm_foc_sensorless_n_DWork.objisempty_a = true;
  mcb_pmsm_foc_sensorless_n_DWork.obj_b.isSetupComplete = false;
  mcb_pmsm_foc_sensorless_n_DWork.obj_b.isInitialized = 1;
  mcb_pmsm_fo_PWMOutput_setupImpl(&mcb_pmsm_foc_sensorless_n_DWork.obj_b);
  mcb_pmsm_foc_sensorless_n_DWork.obj_b.isSetupComplete = true;

  /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
  mcb_pmsm__SpeedControl_Init(&mcb_pmsm_foc_sensorless_nucle_B.SpeedControl,
    &mcb_pmsm_foc_sensorless_n_DWork.SpeedControl);

  /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

  /* SystemInitialize for Enabled SubSystem: '<S289>/Enabled Subsystem' */
  /* Start for MATLABSystem: '<S290>/UART//USART Write1' */
  mcb_pmsm_foc_sensorless_n_DWork.obj_h.matlabCodegenIsDeleted = false;
  mcb_pmsm_foc_sensorless_n_DWork.objisempty_n = true;
  mcb_pmsm_foc_sensorless_n_DWork.obj_h.isSetupComplete = false;
  mcb_pmsm_foc_sensorless_n_DWork.obj_h.isInitialized = 1;
  mcb_pmsm_fo_UARTWrite_setupImpl(&mcb_pmsm_foc_sensorless_n_DWork.obj_h);
  mcb_pmsm_foc_sensorless_n_DWork.obj_h.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<S289>/Enabled Subsystem' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* Start for MATLABSystem: '<S212>/Digital Port Write' */
  mcb_pmsm_foc_sensorless_n_DWork.objisempty_c = true;
  mcb_pmsm_foc_sensorless_n_DWork.obj_ds.isInitialized = 1;

  /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

  /* Start for MATLABSystem: '<S289>/UART//USART Write' */
  mcb_pmsm_foc_sensorless_n_DWork.obj.matlabCodegenIsDeleted = false;
  mcb_pmsm_foc_sensorless_n_DWork.objisempty = true;
  mcb_pmsm_foc_sensorless_n_DWork.obj.isSetupComplete = false;
  mcb_pmsm_foc_sensorless_n_DWork.obj.isInitialized = 1;
  mcb_pmsm_fo_UARTWrite_setupImpl(&mcb_pmsm_foc_sensorless_n_DWork.obj);
  mcb_pmsm_foc_sensorless_n_DWork.obj.isSetupComplete = true;

  /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
  /* Outputs for Atomic SubSystem: '<S207>/Default ADC Offset' */
  /* DataStoreWrite: '<S208>/Data Store Write1' incorporates:
   *  Constant: '<S208>/Constant'
   */
  mcb_pmsm_foc_sensorless_n_DWork.IaOffset = 1665U;

  /* DataStoreWrite: '<S208>/Data Store Write2' incorporates:
   *  Constant: '<S208>/Constant1'
   */
  mcb_pmsm_foc_sensorless_n_DWork.IbOffset = 1943U;

  /* End of Outputs for SubSystem: '<S207>/Default ADC Offset' */
  /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
}

/* Model terminate function */
void mcb_pmsm_foc_sensorless_nucleo_f401re_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Current Control'
   */
  /* Termination for function-call system: '<Root>/Current Control' */

  /* Terminate for MATLABSystem: '<S170>/Analog to Digital Converter' */
  if (!mcb_pmsm_foc_sensorless_n_DWork.obj_d.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_sensorless_n_DWork.obj_d.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_sensorless_n_DWork.obj_d.isInitialized == 1) &&
        mcb_pmsm_foc_sensorless_n_DWork.obj_d.isSetupComplete) {
      ADC_Handle_Deinit(mcb_pmsm_foc_sensorless_n_DWork.obj_d.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S170>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S205>/PWM Output' */
  if (!mcb_pmsm_foc_sensorless_n_DWork.obj_b.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_sensorless_n_DWork.obj_b.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_sensorless_n_DWork.obj_b.isInitialized == 1) &&
        mcb_pmsm_foc_sensorless_n_DWork.obj_b.isSetupComplete) {
      disableCounter(mcb_pmsm_foc_sensorless_n_DWork.obj_b.TimerHandle);
      disableTimerInterrupts(mcb_pmsm_foc_sensorless_n_DWork.obj_b.TimerHandle,
        0);
      disableTimerChannel1(mcb_pmsm_foc_sensorless_n_DWork.obj_b.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel2(mcb_pmsm_foc_sensorless_n_DWork.obj_b.TimerHandle,
                           ENABLE_CH);
      disableTimerChannel3(mcb_pmsm_foc_sensorless_n_DWork.obj_b.TimerHandle,
                           ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S205>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */

  /* Terminate for MATLABSystem: '<S289>/UART//USART Write' */
  if (!mcb_pmsm_foc_sensorless_n_DWork.obj.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_sensorless_n_DWork.obj.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_sensorless_n_DWork.obj.isInitialized == 1) &&
        mcb_pmsm_foc_sensorless_n_DWork.obj.isSetupComplete) {
      MW_UART_DeInit(mcb_pmsm_foc_sensorless_n_DWork.obj.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S289>/UART//USART Write' */

  /* Terminate for Enabled SubSystem: '<S289>/Enabled Subsystem' */
  /* Terminate for MATLABSystem: '<S290>/UART//USART Write1' */
  if (!mcb_pmsm_foc_sensorless_n_DWork.obj_h.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_sensorless_n_DWork.obj_h.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_sensorless_n_DWork.obj_h.isInitialized == 1) &&
        mcb_pmsm_foc_sensorless_n_DWork.obj_h.isSetupComplete) {
      MW_UART_DeInit(mcb_pmsm_foc_sensorless_n_DWork.obj_h.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S290>/UART//USART Write1' */
  /* End of Terminate for SubSystem: '<S289>/Enabled Subsystem' */

  /* Terminate for Atomic SubSystem: '<Root>/Speed Control' */
  mcb_pmsm__SpeedControl_Term(&mcb_pmsm_foc_sensorless_n_DWork.SpeedControl);

  /* End of Terminate for SubSystem: '<Root>/Speed Control' */
}

void mcb_pmsm_foc_sensorless_nucleo_f401re_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S10>/Hardware Interrupt' */
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
        /* RateTransition: '<Root>/RT1' */
        mcb_pmsm_foc_sensorless_nucle_B.RT1 =
          mcb_pmsm_foc_sensorless_n_DWork.RT1_Buffer0;

        /* RateTransition: '<Root>/RT5' */
        mcb_pmsm_foc_sensorless_nucle_B.RT5 =
          mcb_pmsm_foc_sensorless_n_DWork.RT5_Buffer0;

        /* RateTransition: '<Root>/RT' */
        mcb_pmsm_foc_sensorless_nucle_B.RT_f =
          mcb_pmsm_foc_sensorless_n_DWork.RT_Buffer0;

        /* S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Current Control' */
        {
          real32_T Bias;
          uint32_T Sum;
          uint16_T tmp[2];
          uint16_T AnalogtoDigitalConverter;
          ZCSigState Delay_Reset_ZCE_tmp;
          int8_T Integrator_PrevResetState_tmp;
          boolean_T zcEvent;

          /* DataStoreRead: '<S171>/Data Store Read1' */
          mcb_pmsm_foc_sensorless_nucle_B.DataStoreRead1 =
            mcb_pmsm_foc_sensorless_n_DWork.IaOffset;

          /* DataStoreRead: '<S171>/Data Store Read2' */
          mcb_pmsm_foc_sensorless_nucle_B.DataStoreRead2 =
            mcb_pmsm_foc_sensorless_n_DWork.IbOffset;

          /* MATLABSystem: '<S170>/Analog to Digital Converter' */
          injectedReadADCIntr(mcb_pmsm_foc_sensorless_n_DWork.obj_d.ADCHandle,
                              ADC_READ, &tmp[0]);

          /* MATLABSystem: '<S170>/Analog to Digital Converter' */
          AnalogtoDigitalConverter = tmp[0];
          mcb_pmsm_foc_sensorless_nucle_B.AnalogtoDigitalConverter[0] =
            AnalogtoDigitalConverter;

          /* DataTypeConversion: '<S171>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S170>/Analog to Digital Converter'
           */
          mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_j[0] =
            AnalogtoDigitalConverter;

          /* MATLABSystem: '<S170>/Analog to Digital Converter' */
          AnalogtoDigitalConverter = tmp[1];
          mcb_pmsm_foc_sensorless_nucle_B.AnalogtoDigitalConverter[1] =
            AnalogtoDigitalConverter;

          /* DataTypeConversion: '<S171>/Data Type Conversion' incorporates:
           *  MATLABSystem: '<S170>/Analog to Digital Converter'
           */
          mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_j[1] =
            AnalogtoDigitalConverter;

          /* Sum: '<S171>/Add' incorporates:
           *  DataTypeConversion: '<S171>/Data Type Conversion'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Add_p[0] =
            mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_j[0] -
            mcb_pmsm_foc_sensorless_nucle_B.DataStoreRead1;
          mcb_pmsm_foc_sensorless_nucle_B.Add_p[1] =
            mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_j[1] -
            mcb_pmsm_foc_sensorless_nucle_B.DataStoreRead2;

          /* Gain: '<S174>/Get ADC Voltage' incorporates:
           *  Sum: '<S171>/Add'
           */
          Bias = 0.000805860793F * (real32_T)
            mcb_pmsm_foc_sensorless_nucle_B.Add_p[0];
          mcb_pmsm_foc_sensorless_nucle_B.GetADCVoltage[0] = Bias;

          /* Gain: '<S174>/Get Currents' incorporates:
           *  Gain: '<S174>/Get ADC Voltage'
           */
          Bias *= 1.98019803F;
          mcb_pmsm_foc_sensorless_nucle_B.GetCurrents[0] = Bias;

          /* Gain: '<S174>/PU_Conversion' incorporates:
           *  Gain: '<S174>/Get Currents'
           */
          Bias *= 0.306060612F;
          mcb_pmsm_foc_sensorless_nucle_B.PU_Conversion[0] = Bias;

          /* Gain: '<S171>/Inverting // Non-inverting  Current measurement  amplifier' incorporates:
           *  Gain: '<S174>/PU_Conversion'
           */
          mcb_pmsm_foc_sensorless_nucle_B.InvertingNoninvertingCurrentmea[0] =
            -Bias;

          /* Gain: '<S174>/Get ADC Voltage' incorporates:
           *  Sum: '<S171>/Add'
           */
          Bias = 0.000805860793F * (real32_T)
            mcb_pmsm_foc_sensorless_nucle_B.Add_p[1];
          mcb_pmsm_foc_sensorless_nucle_B.GetADCVoltage[1] = Bias;

          /* Gain: '<S174>/Get Currents' incorporates:
           *  Gain: '<S174>/Get ADC Voltage'
           */
          Bias *= 1.98019803F;
          mcb_pmsm_foc_sensorless_nucle_B.GetCurrents[1] = Bias;

          /* Gain: '<S174>/PU_Conversion' incorporates:
           *  Gain: '<S174>/Get Currents'
           */
          Bias *= 0.306060612F;
          mcb_pmsm_foc_sensorless_nucle_B.PU_Conversion[1] = Bias;

          /* Gain: '<S171>/Inverting // Non-inverting  Current measurement  amplifier' incorporates:
           *  Gain: '<S174>/PU_Conversion'
           */
          mcb_pmsm_foc_sensorless_nucle_B.InvertingNoninvertingCurrentmea[1] =
            -Bias;

          /* Outputs for Atomic SubSystem: '<S23>/Two phase CRL wrap' */
          /* AlgorithmDescriptorDelegate generated from: '<S24>/a16' */
          arm_clarke_f32
            (mcb_pmsm_foc_sensorless_nucle_B.InvertingNoninvertingCurrentmea[0],
             mcb_pmsm_foc_sensorless_nucle_B.InvertingNoninvertingCurrentmea[1],
             &mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_n,
             &mcb_pmsm_foc_sensorless_nucle_B.algDD_o2_e);

          /* End of Outputs for SubSystem: '<S23>/Two phase CRL wrap' */

          /* Switch: '<S30>/Switch1' incorporates:
           *  Constant: '<S30>/ChosenMethod'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Switch1_h = 3U;

          /* UnitDelay: '<S188>/Unit Delay1' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay1 =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay1_DSTATE;

          /* UnitDelay: '<S188>/Unit Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE;

          /* Gain: '<S188>/a' */
          mcb_pmsm_foc_sensorless_nucle_B.a = 0.958230734F *
            mcb_pmsm_foc_sensorless_nucle_B.UnitDelay;

          /* Delay: '<S2>/Delay5' */
          mcb_pmsm_foc_sensorless_nucle_B.Delay5[0] =
            mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[0];
          mcb_pmsm_foc_sensorless_nucle_B.Delay5[1] =
            mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[1];
          mcb_pmsm_foc_sensorless_nucle_B.Delay5[2] =
            mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[2];
          mcb_pmsm_foc_sensorless_nucle_B.Delay5[3] =
            mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[3];

          /* Logic: '<S175>/Logical Operator' */
          mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator =
            !mcb_pmsm_foc_sensorless_nucle_B.RT_f;

          /* Delay: '<S178>/Delay' */
          zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE ==
                       POS_ZCSIG) != (int32_T)
                      mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) &&
                     (mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) {
            mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE = 0.0F;
          }

          Delay_Reset_ZCE_tmp = mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator;
          mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S178>/Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.Delay_g =
            mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE;

          /* Sum: '<S178>/Sum2' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum2 =
            mcb_pmsm_foc_sensorless_nucle_B.Delay_g -
            mcb_pmsm_foc_sensorless_nucle_B.Delay5[2];

          /* Sum: '<S188>/Sum3' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum3 =
            (mcb_pmsm_foc_sensorless_nucle_B.UnitDelay1 -
             mcb_pmsm_foc_sensorless_nucle_B.a) +
            mcb_pmsm_foc_sensorless_nucle_B.Sum2;

          /* Gain: '<S188>/b_inv*g' */
          mcb_pmsm_foc_sensorless_nucle_B.b_invg = 2.60134363F *
            mcb_pmsm_foc_sensorless_nucle_B.Sum3;

          /* Delay: '<S188>/Delay1' */
          zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE ==
                       POS_ZCSIG) != (int32_T)
                      mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) &&
                     (mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) {
            mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE = 0.0F;
          }

          mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE = Delay_Reset_ZCE_tmp;

          /* Delay: '<S188>/Delay1' */
          mcb_pmsm_foc_sensorless_nucle_B.Delay1 =
            mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE;

          /* Sum: '<S188>/Sum4' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum4 =
            mcb_pmsm_foc_sensorless_nucle_B.b_invg +
            mcb_pmsm_foc_sensorless_nucle_B.Delay1;

          /* Switch: '<S180>/Switch1' incorporates:
           *  Constant: '<S180>/FilterConstant'
           *  Constant: '<S180>/OneMinusFilterConstant'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Switch1[0] = 0.158600137F;
          mcb_pmsm_foc_sensorless_nucle_B.Switch1[1] = 0.841399848F;

          /* Product: '<S192>/Product' */
          mcb_pmsm_foc_sensorless_nucle_B.Product =
            mcb_pmsm_foc_sensorless_nucle_B.Sum4 * 0.158600137F;

          /* UnitDelay: '<S192>/Unit Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_o =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_o;

          /* Product: '<S192>/Product1' */
          mcb_pmsm_foc_sensorless_nucle_B.Product1 = 0.841399848F *
            mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_o;

          /* Sum: '<S192>/Add1' */
          mcb_pmsm_foc_sensorless_nucle_B.Add1 =
            mcb_pmsm_foc_sensorless_nucle_B.Product +
            mcb_pmsm_foc_sensorless_nucle_B.Product1;

          /* Relay: '<S177>/AlphaRelay' */
          Bias = mcb_pmsm_foc_sensorless_nucle_B.Add1;
          mcb_pmsm_foc_sensorless_n_DWork.AlphaRelay_Mode = ((Bias >= 0.02F) ||
            ((!(Bias <= -0.02F)) &&
             mcb_pmsm_foc_sensorless_n_DWork.AlphaRelay_Mode));

          /* Relay: '<S177>/AlphaRelay' */
          mcb_pmsm_foc_sensorless_nucle_B.AlphaRelay =
            mcb_pmsm_foc_sensorless_n_DWork.AlphaRelay_Mode;

          /* UnitDelay: '<S189>/Unit Delay1' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay1_k =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay1_DSTATE_n;

          /* UnitDelay: '<S189>/Unit Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_e =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_m;

          /* Gain: '<S189>/a' */
          mcb_pmsm_foc_sensorless_nucle_B.a_g = 0.958230734F *
            mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_e;

          /* Delay: '<S179>/Delay' */
          zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_l ==
                       POS_ZCSIG) != (int32_T)
                      mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) &&
                     (mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_l !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) {
            mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_k = 0.0F;
          }

          mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_l =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S179>/Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.Delay_c =
            mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_k;

          /* Sum: '<S179>/Sum2' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum2_b =
            mcb_pmsm_foc_sensorless_nucle_B.Delay_c -
            mcb_pmsm_foc_sensorless_nucle_B.Delay5[3];

          /* Sum: '<S189>/Sum3' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum3_n =
            (mcb_pmsm_foc_sensorless_nucle_B.UnitDelay1_k -
             mcb_pmsm_foc_sensorless_nucle_B.a_g) +
            mcb_pmsm_foc_sensorless_nucle_B.Sum2_b;

          /* Gain: '<S189>/b_inv*g' */
          mcb_pmsm_foc_sensorless_nucle_B.b_invg_n = 2.60134363F *
            mcb_pmsm_foc_sensorless_nucle_B.Sum3_n;

          /* Delay: '<S189>/Delay1' */
          zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_n ==
                       POS_ZCSIG) != (int32_T)
                      mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) &&
                     (mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_n !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) {
            mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE_e = 0.0F;
          }

          mcb_pmsm_foc_sen_PrevZCSigState.Delay1_Reset_ZCE_n =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S189>/Delay1' */
          mcb_pmsm_foc_sensorless_nucle_B.Delay1_n =
            mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE_e;

          /* Sum: '<S189>/Sum4' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum4_g =
            mcb_pmsm_foc_sensorless_nucle_B.b_invg_n +
            mcb_pmsm_foc_sensorless_nucle_B.Delay1_n;

          /* Switch: '<S181>/Switch1' incorporates:
           *  Constant: '<S181>/FilterConstant'
           *  Constant: '<S181>/OneMinusFilterConstant'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Switch1_b[0] = 0.158600137F;
          mcb_pmsm_foc_sensorless_nucle_B.Switch1_b[1] = 0.841399848F;

          /* Product: '<S195>/Product' */
          mcb_pmsm_foc_sensorless_nucle_B.Product_e =
            mcb_pmsm_foc_sensorless_nucle_B.Sum4_g * 0.158600137F;

          /* UnitDelay: '<S195>/Unit Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_l =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_g;

          /* Product: '<S195>/Product1' */
          mcb_pmsm_foc_sensorless_nucle_B.Product1_m = 0.841399848F *
            mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_l;

          /* Sum: '<S195>/Add1' */
          mcb_pmsm_foc_sensorless_nucle_B.Add1_i =
            mcb_pmsm_foc_sensorless_nucle_B.Product_e +
            mcb_pmsm_foc_sensorless_nucle_B.Product1_m;

          /* Relay: '<S177>/BetaRelay' */
          Bias = mcb_pmsm_foc_sensorless_nucle_B.Add1_i;
          mcb_pmsm_foc_sensorless_n_DWork.BetaRelay_Mode = ((Bias >= 0.02F) ||
            ((!(Bias <= -0.02F)) &&
             mcb_pmsm_foc_sensorless_n_DWork.BetaRelay_Mode));

          /* Relay: '<S177>/BetaRelay' */
          mcb_pmsm_foc_sensorless_nucle_B.BetaRelay =
            mcb_pmsm_foc_sensorless_n_DWork.BetaRelay_Mode;

          /* Outputs for Triggered SubSystem: '<S177>/Dir_Sense' incorporates:
           *  TriggerPort: '<S185>/Trigger'
           */
          zcEvent = (mcb_pmsm_foc_sensorless_nucle_B.AlphaRelay &&
                     (mcb_pmsm_foc_sen_PrevZCSigState.Dir_Sense_Trig_ZCE !=
                      POS_ZCSIG));
          if (zcEvent) {
            /* Logic: '<S185>/Logical Operator' */
            mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator_f =
              (mcb_pmsm_foc_sensorless_nucle_B.AlphaRelay &&
               mcb_pmsm_foc_sensorless_nucle_B.BetaRelay);

            /* Switch: '<S185>/Switch' */
            if (mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator_f) {
              /* Switch: '<S185>/Switch' incorporates:
               *  Constant: '<S185>/Constant'
               */
              mcb_pmsm_foc_sensorless_nucle_B.Switch_oo = -1;
            } else {
              /* Switch: '<S185>/Switch' incorporates:
               *  Constant: '<S185>/Constant1'
               */
              mcb_pmsm_foc_sensorless_nucle_B.Switch_oo = 1;
            }

            /* End of Switch: '<S185>/Switch' */
          }

          mcb_pmsm_foc_sen_PrevZCSigState.Dir_Sense_Trig_ZCE =
            mcb_pmsm_foc_sensorless_nucle_B.AlphaRelay;

          /* End of Outputs for SubSystem: '<S177>/Dir_Sense' */

          /* If: '<S177>/If' */
          if (mcb_pmsm_foc_sensorless_nucle_B.Switch_oo > 0) {
            /* Outputs for IfAction SubSystem: '<S177>/Subsystem2' incorporates:
             *  ActionPort: '<S186>/Action Port'
             */
            /* Merge: '<S177>/Merge' incorporates:
             *  UnaryMinus: '<S186>/Unary Minus'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Merge =
              -mcb_pmsm_foc_sensorless_nucle_B.Add1;

            /* Merge: '<S177>/Merge1' incorporates:
             *  SignalConversion generated from: '<S186>/SigmaBeta'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Merge1 =
              mcb_pmsm_foc_sensorless_nucle_B.Add1_i;

            /* End of Outputs for SubSystem: '<S177>/Subsystem2' */
          } else {
            /* Outputs for IfAction SubSystem: '<S177>/Subsystem3' incorporates:
             *  ActionPort: '<S187>/Action Port'
             */
            /* Merge: '<S177>/Merge1' incorporates:
             *  UnaryMinus: '<S187>/Unary Minus'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Merge1 =
              -mcb_pmsm_foc_sensorless_nucle_B.Add1_i;

            /* Merge: '<S177>/Merge' incorporates:
             *  SignalConversion generated from: '<S187>/SigmaAlpha'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Merge =
              mcb_pmsm_foc_sensorless_nucle_B.Add1;

            /* End of Outputs for SubSystem: '<S177>/Subsystem3' */
          }

          /* End of If: '<S177>/If' */

          /* Delay: '<S176>/Delay' */
          zcEvent = (((mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_h ==
                       POS_ZCSIG) != (int32_T)
                      mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) &&
                     (mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_h !=
                      UNINITIALIZED_ZCSIG));
          if (zcEvent || mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator) {
            mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_e = 0.0F;
          }

          mcb_pmsm_foc_sen_PrevZCSigState.Delay_Reset_ZCE_h =
            Delay_Reset_ZCE_tmp;

          /* Delay: '<S176>/Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.Delay_f =
            mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_e;

          /* Outputs for Atomic SubSystem: '<S176>/angleCompensation' */
          /* Product: '<S184>/Product' incorporates:
           *  Constant: '<S176>/PhaseDelay'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Product_c =
            mcb_pmsm_foc_sensorless_nucle_B.Merge * 1.84350681F;

          /* Product: '<S184>/Product2' */
          mcb_pmsm_foc_sensorless_nucle_B.Product2 =
            mcb_pmsm_foc_sensorless_nucle_B.Merge1 *
            mcb_pmsm_foc_sensorless_nucle_B.Delay_f;

          /* Sum: '<S184>/Sum1' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum1_h1 =
            mcb_pmsm_foc_sensorless_nucle_B.Product_c +
            mcb_pmsm_foc_sensorless_nucle_B.Product2;

          /* Product: '<S184>/Product1' incorporates:
           *  Constant: '<S176>/PhaseDelay'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Product1_f =
            mcb_pmsm_foc_sensorless_nucle_B.Merge1 * 1.84350681F;

          /* Product: '<S184>/Product3' */
          mcb_pmsm_foc_sensorless_nucle_B.Product3 =
            mcb_pmsm_foc_sensorless_nucle_B.Merge *
            mcb_pmsm_foc_sensorless_nucle_B.Delay_f;

          /* Sum: '<S184>/Sum2' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum2_k =
            mcb_pmsm_foc_sensorless_nucle_B.Product1_f -
            mcb_pmsm_foc_sensorless_nucle_B.Product3;

          /* Outputs for Atomic SubSystem: '<S184>/atan1' */
          /* Trigonometry: '<S201>/Atan2' */
          mcb_pmsm_foc_sensorless_nucle_B.Atan2 = rt_atan2f_snf
            (mcb_pmsm_foc_sensorless_nucle_B.Sum1_h1,
             mcb_pmsm_foc_sensorless_nucle_B.Sum2_k);

          /* Switch: '<S201>/Switch' */
          mcb_pmsm_foc_sensorless_nucle_B.Switch_i =
            mcb_pmsm_foc_sensorless_nucle_B.Atan2;

          /* AlgorithmDescriptorDelegate generated from: '<S201>/a16' */
          mcb_pmsm_foc_sensorless_nucle_B.algDD =
            mcb_pmsm_foc_sensorless_nucle_B.Switch_i;

          /* End of Outputs for SubSystem: '<S184>/atan1' */

          /* Switch: '<S184>/Switch' */
          if (mcb_pmsm_foc_sensorless_nucle_B.algDD > 0.0F) {
            /* Switch: '<S184>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_l4 =
              mcb_pmsm_foc_sensorless_nucle_B.algDD;
          } else {
            /* Bias: '<S184>/Bias' */
            mcb_pmsm_foc_sensorless_nucle_B.Bias_e =
              mcb_pmsm_foc_sensorless_nucle_B.algDD + 6.28318548F;

            /* Switch: '<S184>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_l4 =
              mcb_pmsm_foc_sensorless_nucle_B.Bias_e;
          }

          /* End of Switch: '<S184>/Switch' */
          /* End of Outputs for SubSystem: '<S176>/angleCompensation' */

          /* Gain: '<S19>/Gain' */
          mcb_pmsm_foc_sensorless_nucle_B.Gain = 0.0162733328F *
            mcb_pmsm_foc_sensorless_nucle_B.RT1;

          /* UnitDelay: '<S150>/Unit Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_p =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_h;

          /* Logic: '<S150>/NOT' */
          mcb_pmsm_foc_sensorless_nucle_B.NOT_f = true;

          /* Outputs for Enabled SubSystem: '<S150>/Accumulate' incorporates:
           *  EnablePort: '<S151>/Enable'
           */
          /* Delay: '<S151>/Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.Delay_fv =
            mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_b;

          /* Outputs for Enabled SubSystem: '<S151>/Subsystem' incorporates:
           *  EnablePort: '<S152>/Enable'
           */
          if (mcb_pmsm_foc_sensorless_nucle_B.Delay_fv) {
            /* SignalConversion generated from: '<S152>/Input' */
            mcb_pmsm_foc_sensorless_nucle_B.Input =
              mcb_pmsm_foc_sensorless_nucle_B.Gain;
          }

          /* End of Outputs for SubSystem: '<S151>/Subsystem' */

          /* Sum: '<S151>/Add' */
          mcb_pmsm_foc_sensorless_nucle_B.Add_o =
            mcb_pmsm_foc_sensorless_nucle_B.Input +
            mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_p;

          /* DataTypeConversion: '<S151>/Data Type Conversion' */
          mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_a = (int16_T)floorf
            (mcb_pmsm_foc_sensorless_nucle_B.Add_o);

          /* DataTypeConversion: '<S151>/Data Type Conversion1' */
          mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1_j =
            mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_a;

          /* Sum: '<S151>/Add1' */
          mcb_pmsm_foc_sensorless_nucle_B.Add1_g =
            mcb_pmsm_foc_sensorless_nucle_B.Add_o -
            mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1_j;

          /* Update for Delay: '<S151>/Delay' incorporates:
           *  Constant: '<S151>/Constant'
           */
          mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_b = true;

          /* End of Outputs for SubSystem: '<S150>/Accumulate' */

          /* Switch: '<S19>/Switch' */
          if (mcb_pmsm_foc_sensorless_nucle_B.RT5) {
            /* Gain: '<S176>/AngleConversion' */
            mcb_pmsm_foc_sensorless_nucle_B.AngleConversion = 0.159154937F *
              mcb_pmsm_foc_sensorless_nucle_B.Switch_l4;

            /* Switch: '<S19>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch =
              mcb_pmsm_foc_sensorless_nucle_B.AngleConversion;
          } else {
            /* Switch: '<S19>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch =
              mcb_pmsm_foc_sensorless_nucle_B.Add1_g;
          }

          /* End of Switch: '<S19>/Switch' */

          /* RelationalOperator: '<S157>/Compare' incorporates:
           *  Constant: '<S157>/Constant'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Compare =
            (mcb_pmsm_foc_sensorless_nucle_B.Switch < 0.0F);

          /* DataTypeConversion: '<S156>/Data Type Conversion' */
          mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_jp =
            mcb_pmsm_foc_sensorless_nucle_B.Compare;

          /* If: '<S156>/If' */
          if (mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_jp > 0) {
            /* Outputs for IfAction SubSystem: '<S156>/If Action Subsystem' incorporates:
             *  ActionPort: '<S158>/Action Port'
             */
            /* DataTypeConversion: '<S158>/Convert_uint16' */
            mcb_pmsm_foc_sensorless_nucle_B.Convert_uint16_h = (int16_T)floorf
              (mcb_pmsm_foc_sensorless_nucle_B.Switch);

            /* DataTypeConversion: '<S158>/Convert_back' */
            mcb_pmsm_foc_sensorless_nucle_B.Convert_back_a =
              mcb_pmsm_foc_sensorless_nucle_B.Convert_uint16_h;

            /* Merge: '<S156>/Merge' incorporates:
             *  Sum: '<S158>/Sum'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Merge_g =
              mcb_pmsm_foc_sensorless_nucle_B.Switch -
              mcb_pmsm_foc_sensorless_nucle_B.Convert_back_a;

            /* End of Outputs for SubSystem: '<S156>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S156>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S159>/Action Port'
             */
            /* DataTypeConversion: '<S159>/Convert_uint16' */
            mcb_pmsm_foc_sensorless_nucle_B.Convert_uint16 = (int16_T)
              mcb_pmsm_foc_sensorless_nucle_B.Switch;

            /* DataTypeConversion: '<S159>/Convert_back' */
            mcb_pmsm_foc_sensorless_nucle_B.Convert_back =
              mcb_pmsm_foc_sensorless_nucle_B.Convert_uint16;

            /* Merge: '<S156>/Merge' incorporates:
             *  Sum: '<S159>/Sum'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Merge_g =
              mcb_pmsm_foc_sensorless_nucle_B.Switch -
              mcb_pmsm_foc_sensorless_nucle_B.Convert_back;

            /* End of Outputs for SubSystem: '<S156>/If Action Subsystem1' */
          }

          /* End of If: '<S156>/If' */

          /* Gain: '<S21>/indexing' */
          mcb_pmsm_foc_sensorless_nucle_B.indexing = 800.0F *
            mcb_pmsm_foc_sensorless_nucle_B.Merge_g;

          /* DataTypeConversion: '<S21>/Get_Integer' */
          mcb_pmsm_foc_sensorless_nucle_B.Get_Integer = (uint16_T)
            mcb_pmsm_foc_sensorless_nucle_B.indexing;

          /* Sum: '<S21>/Sum' incorporates:
           *  Constant: '<S21>/offset'
           */
          Sum = mcb_pmsm_foc_sensorless_nucle_B.Get_Integer + 1U;
          mcb_pmsm_foc_sensorless_nucle_B.Sum[0] = Sum;

          /* Selector: '<S21>/Lookup' incorporates:
           *  Constant: '<S21>/sine_table_values'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Lookup[0] =
            mcb_pmsm_foc_sensorless__ConstP.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S21>/Sum' */
          Sum = mcb_pmsm_foc_sensorless_nucle_B.Get_Integer;
          mcb_pmsm_foc_sensorless_nucle_B.Sum[1] = Sum;

          /* Selector: '<S21>/Lookup' incorporates:
           *  Constant: '<S21>/sine_table_values'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Lookup[1] =
            mcb_pmsm_foc_sensorless__ConstP.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S21>/Sum' incorporates:
           *  Constant: '<S21>/offset'
           */
          Sum = mcb_pmsm_foc_sensorless_nucle_B.Get_Integer + 201U;
          mcb_pmsm_foc_sensorless_nucle_B.Sum[2] = Sum;

          /* Selector: '<S21>/Lookup' incorporates:
           *  Constant: '<S21>/sine_table_values'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Lookup[2] =
            mcb_pmsm_foc_sensorless__ConstP.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S21>/Sum' incorporates:
           *  Constant: '<S21>/offset'
           */
          Sum = mcb_pmsm_foc_sensorless_nucle_B.Get_Integer + 200U;
          mcb_pmsm_foc_sensorless_nucle_B.Sum[3] = Sum;

          /* Selector: '<S21>/Lookup' incorporates:
           *  Constant: '<S21>/sine_table_values'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Lookup[3] =
            mcb_pmsm_foc_sensorless__ConstP.sine_table_values_Value[(int32_T)Sum];

          /* Sum: '<S155>/Sum3' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum3_p =
            mcb_pmsm_foc_sensorless_nucle_B.Lookup[0] -
            mcb_pmsm_foc_sensorless_nucle_B.Lookup[1];

          /* DataTypeConversion: '<S21>/Data Type Conversion1' */
          mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1_o =
            mcb_pmsm_foc_sensorless_nucle_B.Get_Integer;

          /* Sum: '<S21>/Sum2' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum2_bl =
            mcb_pmsm_foc_sensorless_nucle_B.indexing -
            mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion1_o;

          /* Product: '<S155>/Product' */
          mcb_pmsm_foc_sensorless_nucle_B.Product_ez =
            mcb_pmsm_foc_sensorless_nucle_B.Sum3_p *
            mcb_pmsm_foc_sensorless_nucle_B.Sum2_bl;

          /* Sum: '<S155>/Sum4' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum4_f =
            mcb_pmsm_foc_sensorless_nucle_B.Product_ez +
            mcb_pmsm_foc_sensorless_nucle_B.Lookup[1];

          /* Sum: '<S155>/Sum5' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum5 =
            mcb_pmsm_foc_sensorless_nucle_B.Lookup[2] -
            mcb_pmsm_foc_sensorless_nucle_B.Lookup[3];

          /* Product: '<S155>/Product1' */
          mcb_pmsm_foc_sensorless_nucle_B.Product1_n =
            mcb_pmsm_foc_sensorless_nucle_B.Sum5 *
            mcb_pmsm_foc_sensorless_nucle_B.Sum2_bl;

          /* Sum: '<S155>/Sum6' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum6 =
            mcb_pmsm_foc_sensorless_nucle_B.Product1_n +
            mcb_pmsm_foc_sensorless_nucle_B.Lookup[3];

          /* Outputs for Atomic SubSystem: '<S20>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S153>/a16' */
          arm_park_f32(mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_n,
                       mcb_pmsm_foc_sensorless_nucle_B.algDD_o2_e,
                       &mcb_pmsm_foc_sensorless_nucle_B.algDD_o1,
                       &mcb_pmsm_foc_sensorless_nucle_B.algDD_o2,
                       mcb_pmsm_foc_sensorless_nucle_B.Sum4_f,
                       mcb_pmsm_foc_sensorless_nucle_B.Sum6);

          /* End of Outputs for SubSystem: '<S20>/Two inputs CRL' */

          /* Sum: '<S27>/Sum' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum_g =
            mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Saturation -
            mcb_pmsm_foc_sensorless_nucle_B.algDD_o2;

          /* Product: '<S136>/PProd Out' incorporates:
           *  Constant: '<S27>/Kp'
           */
          mcb_pmsm_foc_sensorless_nucle_B.PProdOut =
            mcb_pmsm_foc_sensorless_nucle_B.Sum_g * 0.707397F;

          /* Logic: '<S27>/Logical Operator' incorporates:
           *  Logic: '<S26>/Logical Operator'
           */
          zcEvent = !mcb_pmsm_foc_sensorless_nucle_B.RT5;

          /* Logic: '<S27>/Logical Operator' */
          mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator_i = zcEvent;

          /* UnitDelay: '<S27>/Unit Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_c =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_a;

          /* DiscreteIntegrator: '<S131>/Integrator' */
          if (mcb_pmsm_foc_sensorless_n_DWork.Integrator_IC_LOADING != 0) {
            mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE =
              mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_c;
          }

          if (mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator_i ||
              (mcb_pmsm_foc_sensorless_n_DWork.Integrator_PrevResetState != 0))
          {
            mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE =
              mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_c;
          }

          /* DiscreteIntegrator: '<S131>/Integrator' */
          mcb_pmsm_foc_sensorless_nucle_B.Integrator =
            mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE;

          /* Sum: '<S140>/Sum' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum_l =
            mcb_pmsm_foc_sensorless_nucle_B.PProdOut +
            mcb_pmsm_foc_sensorless_nucle_B.Integrator;

          /* Switch: '<S27>/Switch' */
          if (mcb_pmsm_foc_sensorless_nucle_B.RT5) {
            /* Saturate: '<S138>/Saturation' */
            Bias = mcb_pmsm_foc_sensorless_nucle_B.Sum_l;
            if (Bias > 1.0F) {
              /* Saturate: '<S138>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation = 1.0F;
            } else if (Bias < -1.0F) {
              /* Saturate: '<S138>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation = -1.0F;
            } else {
              /* Saturate: '<S138>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation = Bias;
            }

            /* End of Saturate: '<S138>/Saturation' */

            /* Switch: '<S27>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_h =
              mcb_pmsm_foc_sensorless_nucle_B.Saturation;
          } else {
            /* Switch: '<S27>/Switch' incorporates:
             *  Constant: '<S27>/Vq_OpenLoop'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_h = 0.0F;
          }

          /* End of Switch: '<S27>/Switch' */

          /* Sum: '<S26>/Sum' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum_k =
            mcb_pmsm_foc_sensorless_nucle_B.SpeedControl.Constant2 -
            mcb_pmsm_foc_sensorless_nucle_B.algDD_o1;

          /* Product: '<S83>/PProd Out' incorporates:
           *  Constant: '<S26>/Kp'
           */
          mcb_pmsm_foc_sensorless_nucle_B.PProdOut_a =
            mcb_pmsm_foc_sensorless_nucle_B.Sum_k * 0.707397F;

          /* Logic: '<S26>/Logical Operator' */
          mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator_n = zcEvent;

          /* UnitDelay: '<S26>/Unit Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_m =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_p;

          /* DiscreteIntegrator: '<S78>/Integrator' */
          if (mcb_pmsm_foc_sensorless_n_DWork.Integrator_IC_LOADING_b != 0) {
            mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE_a =
              mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_m;
          }

          if (mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator_n ||
              (mcb_pmsm_foc_sensorless_n_DWork.Integrator_PrevResetState_e != 0))
          {
            mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE_a =
              mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_m;
          }

          /* DiscreteIntegrator: '<S78>/Integrator' */
          mcb_pmsm_foc_sensorless_nucle_B.Integrator_c =
            mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE_a;

          /* Sum: '<S87>/Sum' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum_kn =
            mcb_pmsm_foc_sensorless_nucle_B.PProdOut_a +
            mcb_pmsm_foc_sensorless_nucle_B.Integrator_c;

          /* Switch: '<S26>/Switch' */
          if (mcb_pmsm_foc_sensorless_nucle_B.RT5) {
            /* Saturate: '<S85>/Saturation' */
            Bias = mcb_pmsm_foc_sensorless_nucle_B.Sum_kn;
            if (Bias > 1.0F) {
              /* Saturate: '<S85>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation_i = 1.0F;
            } else if (Bias < -1.0F) {
              /* Saturate: '<S85>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation_i = -1.0F;
            } else {
              /* Saturate: '<S85>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation_i = Bias;
            }

            /* End of Saturate: '<S85>/Saturation' */

            /* Switch: '<S26>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_l =
              mcb_pmsm_foc_sensorless_nucle_B.Saturation_i;
          } else {
            /* Abs: '<S26>/Abs' */
            mcb_pmsm_foc_sensorless_nucle_B.Abs = fabsf
              (mcb_pmsm_foc_sensorless_nucle_B.RT1);

            /* Saturate: '<S26>/Saturation' */
            Bias = mcb_pmsm_foc_sensorless_nucle_B.Abs;
            if (Bias > 0.5F) {
              /* Saturate: '<S26>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation_h = 0.5F;
            } else if (Bias < 0.15F) {
              /* Saturate: '<S26>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation_h = 0.15F;
            } else {
              /* Saturate: '<S26>/Saturation' */
              mcb_pmsm_foc_sensorless_nucle_B.Saturation_h = Bias;
            }

            /* End of Saturate: '<S26>/Saturation' */

            /* Switch: '<S26>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_l =
              mcb_pmsm_foc_sensorless_nucle_B.Saturation_h;
          }

          /* End of Switch: '<S26>/Switch' */

          /* Switch: '<S30>/Switch' incorporates:
           *  Constant: '<S30>/Constant3'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Switch_f = 0.95F;

          /* Product: '<S30>/Product' */
          mcb_pmsm_foc_sensorless_nucle_B.Product_b = 0.9025F;

          /* Product: '<S31>/Product' */
          mcb_pmsm_foc_sensorless_nucle_B.Product_k =
            mcb_pmsm_foc_sensorless_nucle_B.Switch_l *
            mcb_pmsm_foc_sensorless_nucle_B.Switch_l;

          /* Product: '<S31>/Product1' */
          mcb_pmsm_foc_sensorless_nucle_B.Product1_no =
            mcb_pmsm_foc_sensorless_nucle_B.Switch_h *
            mcb_pmsm_foc_sensorless_nucle_B.Switch_h;

          /* Sum: '<S31>/Sum1' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum1 =
            mcb_pmsm_foc_sensorless_nucle_B.Product_k +
            mcb_pmsm_foc_sensorless_nucle_B.Product1_no;

          /* Outputs for IfAction SubSystem: '<S25>/D-Q Equivalence' incorporates:
           *  ActionPort: '<S28>/Action Port'
           */
          /* If: '<S25>/If' incorporates:
           *  DataTypeConversion: '<S28>/Data Type Conversion'
           *  RelationalOperator: '<S28>/Relational Operator'
           */
          mcb_pmsm_foc_sensorless_nucle_B.RelationalOperator_e =
            (mcb_pmsm_foc_sensorless_nucle_B.Sum1 > 0.9025F);
          mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_m =
            mcb_pmsm_foc_sensorless_nucle_B.RelationalOperator_e;

          /* If: '<S28>/If' incorporates:
           *  If: '<S25>/If'
           */
          if (mcb_pmsm_foc_sensorless_nucle_B.DataTypeConversion_m != 0) {
            /* Outputs for IfAction SubSystem: '<S28>/Limiter' incorporates:
             *  ActionPort: '<S32>/Action Port'
             */
            /* Product: '<S32>/Product' */
            mcb_pmsm_foc_sensorless_nucle_B.Product_l[0] =
              mcb_pmsm_foc_sensorless_nucle_B.Switch_l * 0.95F;
            mcb_pmsm_foc_sensorless_nucle_B.Product_l[1] =
              mcb_pmsm_foc_sensorless_nucle_B.Switch_h * 0.95F;

            /* Sqrt: '<S32>/Square Root' */
            mw_arm_sqrt_f32(&mcb_pmsm_foc_sensorless_nucle_B.Sum1,
                            &mcb_pmsm_foc_sensorless_nucle_B.SquareRoot, 1U);

            /* Switch: '<S32>/Switch' */
            if (mcb_pmsm_foc_sensorless_nucle_B.SquareRoot != 0.0F) {
              /* Switch: '<S32>/Switch' */
              mcb_pmsm_foc_sensorless_nucle_B.Switch_a =
                mcb_pmsm_foc_sensorless_nucle_B.SquareRoot;
            } else {
              /* Switch: '<S32>/Switch' incorporates:
               *  Constant: '<S32>/Constant'
               */
              mcb_pmsm_foc_sensorless_nucle_B.Switch_a = 1.0F;
            }

            /* End of Switch: '<S32>/Switch' */

            /* Merge: '<S25>/Merge' incorporates:
             *  Product: '<S32>/Divide'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Merge_e[0] =
              mcb_pmsm_foc_sensorless_nucle_B.Product_l[0] /
              mcb_pmsm_foc_sensorless_nucle_B.Switch_a;
            mcb_pmsm_foc_sensorless_nucle_B.Merge_e[1] =
              mcb_pmsm_foc_sensorless_nucle_B.Product_l[1] /
              mcb_pmsm_foc_sensorless_nucle_B.Switch_a;

            /* End of Outputs for SubSystem: '<S28>/Limiter' */
          } else {
            /* Outputs for IfAction SubSystem: '<S28>/Passthrough' incorporates:
             *  ActionPort: '<S33>/Action Port'
             */
            /* Merge: '<S25>/Merge' incorporates:
             *  SignalConversion generated from: '<S33>/dqRef'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Merge_e[0] =
              mcb_pmsm_foc_sensorless_nucle_B.Switch_l;
            mcb_pmsm_foc_sensorless_nucle_B.Merge_e[1] =
              mcb_pmsm_foc_sensorless_nucle_B.Switch_h;

            /* End of Outputs for SubSystem: '<S28>/Passthrough' */
          }

          /* End of If: '<S28>/If' */
          /* End of Outputs for SubSystem: '<S25>/D-Q Equivalence' */

          /* DeadZone: '<S70>/DeadZone' */
          if (mcb_pmsm_foc_sensorless_nucle_B.Sum_kn > 1.0F) {
            /* DeadZone: '<S70>/DeadZone' */
            mcb_pmsm_foc_sensorless_nucle_B.DeadZone =
              mcb_pmsm_foc_sensorless_nucle_B.Sum_kn - 1.0F;
          } else if (mcb_pmsm_foc_sensorless_nucle_B.Sum_kn >= -1.0F) {
            /* DeadZone: '<S70>/DeadZone' */
            mcb_pmsm_foc_sensorless_nucle_B.DeadZone = 0.0F;
          } else {
            /* DeadZone: '<S70>/DeadZone' */
            mcb_pmsm_foc_sensorless_nucle_B.DeadZone =
              mcb_pmsm_foc_sensorless_nucle_B.Sum_kn - -1.0F;
          }

          /* End of DeadZone: '<S70>/DeadZone' */

          /* RelationalOperator: '<S68>/Relational Operator' incorporates:
           *  Constant: '<S68>/Clamping_zero'
           */
          mcb_pmsm_foc_sensorless_nucle_B.RelationalOperator =
            (mcb_pmsm_foc_sensorless_nucle_B.DeadZone != 0.0F);

          /* RelationalOperator: '<S68>/fix for DT propagation issue' incorporates:
           *  Constant: '<S68>/Clamping_zero'
           */
          mcb_pmsm_foc_sensorless_nucle_B.fixforDTpropagationissue =
            (mcb_pmsm_foc_sensorless_nucle_B.DeadZone > 0.0F);

          /* Switch: '<S68>/Switch1' */
          if (mcb_pmsm_foc_sensorless_nucle_B.fixforDTpropagationissue) {
            /* Switch: '<S68>/Switch1' incorporates:
             *  Constant: '<S68>/Constant'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch1_m = 1;
          } else {
            /* Switch: '<S68>/Switch1' incorporates:
             *  Constant: '<S68>/Constant2'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch1_m = -1;
          }

          /* End of Switch: '<S68>/Switch1' */

          /* Product: '<S75>/IProd Out' incorporates:
           *  Constant: '<S26>/Ki'
           */
          mcb_pmsm_foc_sensorless_nucle_B.IProdOut =
            mcb_pmsm_foc_sensorless_nucle_B.Sum_k * 0.0301822722F;

          /* RelationalOperator: '<S68>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S68>/Clamping_zero'
           */
          mcb_pmsm_foc_sensorless_nucle_B.fixforDTpropagationissue1 =
            (mcb_pmsm_foc_sensorless_nucle_B.IProdOut > 0.0F);

          /* Switch: '<S68>/Switch2' */
          if (mcb_pmsm_foc_sensorless_nucle_B.fixforDTpropagationissue1) {
            /* Switch: '<S68>/Switch2' incorporates:
             *  Constant: '<S68>/Constant3'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch2_p = 1;
          } else {
            /* Switch: '<S68>/Switch2' incorporates:
             *  Constant: '<S68>/Constant4'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch2_p = -1;
          }

          /* End of Switch: '<S68>/Switch2' */

          /* RelationalOperator: '<S68>/Equal1' */
          mcb_pmsm_foc_sensorless_nucle_B.Equal1 =
            (mcb_pmsm_foc_sensorless_nucle_B.Switch1_m ==
             mcb_pmsm_foc_sensorless_nucle_B.Switch2_p);

          /* Logic: '<S68>/AND3' */
          mcb_pmsm_foc_sensorless_nucle_B.AND3 =
            (mcb_pmsm_foc_sensorless_nucle_B.RelationalOperator &&
             mcb_pmsm_foc_sensorless_nucle_B.Equal1);

          /* Switch: '<S68>/Switch' */
          if (mcb_pmsm_foc_sensorless_nucle_B.AND3) {
            /* Switch: '<S68>/Switch' incorporates:
             *  Constant: '<S68>/Constant1'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_fm = 0.0F;
          } else {
            /* Switch: '<S68>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_fm =
              mcb_pmsm_foc_sensorless_nucle_B.IProdOut;
          }

          /* End of Switch: '<S68>/Switch' */

          /* DeadZone: '<S123>/DeadZone' */
          if (mcb_pmsm_foc_sensorless_nucle_B.Sum_l > 1.0F) {
            /* DeadZone: '<S123>/DeadZone' */
            mcb_pmsm_foc_sensorless_nucle_B.DeadZone_d =
              mcb_pmsm_foc_sensorless_nucle_B.Sum_l - 1.0F;
          } else if (mcb_pmsm_foc_sensorless_nucle_B.Sum_l >= -1.0F) {
            /* DeadZone: '<S123>/DeadZone' */
            mcb_pmsm_foc_sensorless_nucle_B.DeadZone_d = 0.0F;
          } else {
            /* DeadZone: '<S123>/DeadZone' */
            mcb_pmsm_foc_sensorless_nucle_B.DeadZone_d =
              mcb_pmsm_foc_sensorless_nucle_B.Sum_l - -1.0F;
          }

          /* End of DeadZone: '<S123>/DeadZone' */

          /* RelationalOperator: '<S121>/Relational Operator' incorporates:
           *  Constant: '<S121>/Clamping_zero'
           */
          mcb_pmsm_foc_sensorless_nucle_B.RelationalOperator_c =
            (mcb_pmsm_foc_sensorless_nucle_B.DeadZone_d != 0.0F);

          /* RelationalOperator: '<S121>/fix for DT propagation issue' incorporates:
           *  Constant: '<S121>/Clamping_zero'
           */
          mcb_pmsm_foc_sensorless_nucle_B.fixforDTpropagationissue_p =
            (mcb_pmsm_foc_sensorless_nucle_B.DeadZone_d > 0.0F);

          /* Switch: '<S121>/Switch1' */
          if (mcb_pmsm_foc_sensorless_nucle_B.fixforDTpropagationissue_p) {
            /* Switch: '<S121>/Switch1' incorporates:
             *  Constant: '<S121>/Constant'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch1_l = 1;
          } else {
            /* Switch: '<S121>/Switch1' incorporates:
             *  Constant: '<S121>/Constant2'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch1_l = -1;
          }

          /* End of Switch: '<S121>/Switch1' */

          /* Product: '<S128>/IProd Out' incorporates:
           *  Constant: '<S27>/Ki'
           */
          mcb_pmsm_foc_sensorless_nucle_B.IProdOut_h =
            mcb_pmsm_foc_sensorless_nucle_B.Sum_g * 0.0301822722F;

          /* RelationalOperator: '<S121>/fix for DT propagation issue1' incorporates:
           *  Constant: '<S121>/Clamping_zero'
           */
          mcb_pmsm_foc_sensorless_nucle_B.fixforDTpropagationissue1_o =
            (mcb_pmsm_foc_sensorless_nucle_B.IProdOut_h > 0.0F);

          /* Switch: '<S121>/Switch2' */
          if (mcb_pmsm_foc_sensorless_nucle_B.fixforDTpropagationissue1_o) {
            /* Switch: '<S121>/Switch2' incorporates:
             *  Constant: '<S121>/Constant3'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch2_k = 1;
          } else {
            /* Switch: '<S121>/Switch2' incorporates:
             *  Constant: '<S121>/Constant4'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch2_k = -1;
          }

          /* End of Switch: '<S121>/Switch2' */

          /* RelationalOperator: '<S121>/Equal1' */
          mcb_pmsm_foc_sensorless_nucle_B.Equal1_b =
            (mcb_pmsm_foc_sensorless_nucle_B.Switch1_l ==
             mcb_pmsm_foc_sensorless_nucle_B.Switch2_k);

          /* Logic: '<S121>/AND3' */
          mcb_pmsm_foc_sensorless_nucle_B.AND3_b =
            (mcb_pmsm_foc_sensorless_nucle_B.RelationalOperator_c &&
             mcb_pmsm_foc_sensorless_nucle_B.Equal1_b);

          /* Switch: '<S121>/Switch' */
          if (mcb_pmsm_foc_sensorless_nucle_B.AND3_b) {
            /* Switch: '<S121>/Switch' incorporates:
             *  Constant: '<S121>/Constant1'
             */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_m = 0.0F;
          } else {
            /* Switch: '<S121>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.Switch_m =
              mcb_pmsm_foc_sensorless_nucle_B.IProdOut_h;
          }

          /* End of Switch: '<S121>/Switch' */

          /* Outputs for Atomic SubSystem: '<S18>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S148>/a16' */
          arm_inv_park_f32(mcb_pmsm_foc_sensorless_nucle_B.Merge_e[0],
                           mcb_pmsm_foc_sensorless_nucle_B.Merge_e[1],
                           &mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_o,
                           &mcb_pmsm_foc_sensorless_nucle_B.algDD_o2_k,
                           mcb_pmsm_foc_sensorless_nucle_B.Sum4_f,
                           mcb_pmsm_foc_sensorless_nucle_B.Sum6);

          /* End of Outputs for SubSystem: '<S18>/Two inputs CRL' */

          /* Signum: '<S178>/Sign' */
          Bias = mcb_pmsm_foc_sensorless_nucle_B.Sum2;
          if (rtIsNaNF(Bias)) {
            /* Signum: '<S178>/Sign' */
            mcb_pmsm_foc_sensorless_nucle_B.Sign = (rtNaNF);
          } else if (Bias < 0.0F) {
            /* Signum: '<S178>/Sign' */
            mcb_pmsm_foc_sensorless_nucle_B.Sign = -1.0F;
          } else {
            /* Signum: '<S178>/Sign' */
            mcb_pmsm_foc_sensorless_nucle_B.Sign = (real32_T)(Bias > 0.0F);
          }

          /* End of Signum: '<S178>/Sign' */

          /* Gain: '<S178>/Eta' */
          mcb_pmsm_foc_sensorless_nucle_B.Eta = 0.0432371832F *
            mcb_pmsm_foc_sensorless_nucle_B.Sign;

          /* Sum: '<S178>/Sum' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum_i =
            mcb_pmsm_foc_sensorless_nucle_B.Delay5[0] -
            mcb_pmsm_foc_sensorless_nucle_B.Sum4;

          /* Gain: '<S178>/b' */
          mcb_pmsm_foc_sensorless_nucle_B.b = 0.345975071F *
            mcb_pmsm_foc_sensorless_nucle_B.Sum_i;

          /* Gain: '<S178>/a' */
          mcb_pmsm_foc_sensorless_nucle_B.a_o = 0.958230734F *
            mcb_pmsm_foc_sensorless_nucle_B.Delay_g;

          /* Sum: '<S178>/Sum1' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum1_c =
            (mcb_pmsm_foc_sensorless_nucle_B.b -
             mcb_pmsm_foc_sensorless_nucle_B.Eta) +
            mcb_pmsm_foc_sensorless_nucle_B.a_o;

          /* Signum: '<S179>/Sign' */
          Bias = mcb_pmsm_foc_sensorless_nucle_B.Sum2_b;
          if (rtIsNaNF(Bias)) {
            /* Signum: '<S179>/Sign' */
            mcb_pmsm_foc_sensorless_nucle_B.Sign_m = (rtNaNF);
          } else if (Bias < 0.0F) {
            /* Signum: '<S179>/Sign' */
            mcb_pmsm_foc_sensorless_nucle_B.Sign_m = -1.0F;
          } else {
            /* Signum: '<S179>/Sign' */
            mcb_pmsm_foc_sensorless_nucle_B.Sign_m = (real32_T)(Bias > 0.0F);
          }

          /* End of Signum: '<S179>/Sign' */

          /* Gain: '<S179>/Eta' */
          mcb_pmsm_foc_sensorless_nucle_B.Eta_e = 0.0432371832F *
            mcb_pmsm_foc_sensorless_nucle_B.Sign_m;

          /* Sum: '<S179>/Sum' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum_iv =
            mcb_pmsm_foc_sensorless_nucle_B.Delay5[1] -
            mcb_pmsm_foc_sensorless_nucle_B.Sum4_g;

          /* Gain: '<S179>/b' */
          mcb_pmsm_foc_sensorless_nucle_B.b_n = 0.345975071F *
            mcb_pmsm_foc_sensorless_nucle_B.Sum_iv;

          /* Gain: '<S179>/a' */
          mcb_pmsm_foc_sensorless_nucle_B.a_gy = 0.958230734F *
            mcb_pmsm_foc_sensorless_nucle_B.Delay_c;

          /* Sum: '<S179>/Sum1' */
          mcb_pmsm_foc_sensorless_nucle_B.Sum1_h =
            (mcb_pmsm_foc_sensorless_nucle_B.b_n -
             mcb_pmsm_foc_sensorless_nucle_B.Eta_e) +
            mcb_pmsm_foc_sensorless_nucle_B.a_gy;

          /* Gain: '<S183>/PositionToCount' */
          mcb_pmsm_foc_sensorless_nucle_B.PositionToCount = (uint32_T)
            (6.83563648E+8F * mcb_pmsm_foc_sensorless_nucle_B.Switch_l4);

          /* Delay: '<S183>/Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.Delay =
            mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_p[mcb_pmsm_foc_sensorless_n_DWork.CircBufIdx];

          /* Sum: '<S183>/SpeedCount' */
          mcb_pmsm_foc_sensorless_nucle_B.SpeedCount = (int32_T)
            mcb_pmsm_foc_sensorless_nucle_B.PositionToCount - (int32_T)
            mcb_pmsm_foc_sensorless_nucle_B.Delay;

          /* DataTypeConversion: '<S200>/DTC' */
          mcb_pmsm_foc_sensorless_nucle_B.DTC = (real32_T)
            mcb_pmsm_foc_sensorless_nucle_B.SpeedCount;

          /* Gain: '<S183>/SpeedGain' */
          mcb_pmsm_foc_sensorless_nucle_B.SpeedGain = 4.93361907E-10F *
            mcb_pmsm_foc_sensorless_nucle_B.DTC;

          /* Switch: '<S182>/Switch1' incorporates:
           *  Constant: '<S182>/FilterConstant'
           *  Constant: '<S182>/OneMinusFilterConstant'
           */
          mcb_pmsm_foc_sensorless_nucle_B.Switch1_bl[0] = 0.00406833319F;
          mcb_pmsm_foc_sensorless_nucle_B.Switch1_bl[1] = 0.995931685F;

          /* Product: '<S198>/Product' */
          mcb_pmsm_foc_sensorless_nucle_B.Product_m =
            mcb_pmsm_foc_sensorless_nucle_B.SpeedGain * 0.00406833319F;

          /* UnitDelay: '<S198>/Unit Delay' */
          mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_g =
            mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_hu;

          /* Product: '<S198>/Product1' */
          mcb_pmsm_foc_sensorless_nucle_B.Product1_mm = 0.995931685F *
            mcb_pmsm_foc_sensorless_nucle_B.UnitDelay_g;

          /* Sum: '<S198>/Add1' */
          mcb_pmsm_foc_sensorless_nucle_B.Add1_c =
            mcb_pmsm_foc_sensorless_nucle_B.Product_m +
            mcb_pmsm_foc_sensorless_nucle_B.Product1_mm;

          /* Gain: '<S176>/SpeedConversion' */
          mcb_pmsm_foc_sensorless_nucle_B.SpeedConversion =
            mcb_pmsm_foc_sensorless_nucle_B.Add1_c;

          /* Switch: '<S15>/Switch' */
          if (mcb_pmsm_foc_sensorless_nucle_B.RT_f) {
            /* Gain: '<S166>/sqrt3_by_two' */
            mcb_pmsm_foc_sensorless_nucle_B.sqrt3_by_two = 0.866025388F *
              mcb_pmsm_foc_sensorless_nucle_B.algDD_o2_k;

            /* Gain: '<S166>/one_by_two' */
            mcb_pmsm_foc_sensorless_nucle_B.one_by_two = 0.5F *
              mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_o;

            /* Sum: '<S166>/add_c' */
            mcb_pmsm_foc_sensorless_nucle_B.add_c = (0.0F -
              mcb_pmsm_foc_sensorless_nucle_B.one_by_two) -
              mcb_pmsm_foc_sensorless_nucle_B.sqrt3_by_two;

            /* Sum: '<S166>/add_b' */
            mcb_pmsm_foc_sensorless_nucle_B.add_b =
              mcb_pmsm_foc_sensorless_nucle_B.sqrt3_by_two -
              mcb_pmsm_foc_sensorless_nucle_B.one_by_two;

            /* MinMax: '<S163>/Min' */
            Bias = fminf(mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_o,
                         mcb_pmsm_foc_sensorless_nucle_B.add_b);
            Bias = fminf(Bias, mcb_pmsm_foc_sensorless_nucle_B.add_c);

            /* MinMax: '<S163>/Min' */
            mcb_pmsm_foc_sensorless_nucle_B.Min = Bias;

            /* MinMax: '<S163>/Max' */
            Bias = fmaxf(mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_o,
                         mcb_pmsm_foc_sensorless_nucle_B.add_b);
            Bias = fmaxf(Bias, mcb_pmsm_foc_sensorless_nucle_B.add_c);

            /* MinMax: '<S163>/Max' */
            mcb_pmsm_foc_sensorless_nucle_B.Max = Bias;

            /* Sum: '<S163>/Add' */
            mcb_pmsm_foc_sensorless_nucle_B.Add =
              mcb_pmsm_foc_sensorless_nucle_B.Max +
              mcb_pmsm_foc_sensorless_nucle_B.Min;

            /* Gain: '<S163>/one_by_two' */
            mcb_pmsm_foc_sensorless_nucle_B.one_by_two_p = -0.5F *
              mcb_pmsm_foc_sensorless_nucle_B.Add;

            /* Sum: '<S162>/Add3' */
            mcb_pmsm_foc_sensorless_nucle_B.Add3 =
              mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_o +
              mcb_pmsm_foc_sensorless_nucle_B.one_by_two_p;

            /* Sum: '<S162>/Add2' */
            mcb_pmsm_foc_sensorless_nucle_B.Add2 =
              mcb_pmsm_foc_sensorless_nucle_B.one_by_two_p +
              mcb_pmsm_foc_sensorless_nucle_B.add_c;

            /* Sum: '<S162>/Add1' */
            mcb_pmsm_foc_sensorless_nucle_B.Add1_i4 =
              mcb_pmsm_foc_sensorless_nucle_B.add_b +
              mcb_pmsm_foc_sensorless_nucle_B.one_by_two_p;

            /* Gain: '<S162>/Gain' */
            mcb_pmsm_foc_sensorless_nucle_B.Gain_f[0] = 1.15470052F *
              mcb_pmsm_foc_sensorless_nucle_B.Add3;
            mcb_pmsm_foc_sensorless_nucle_B.Gain_f[1] = 1.15470052F *
              mcb_pmsm_foc_sensorless_nucle_B.Add1_i4;
            mcb_pmsm_foc_sensorless_nucle_B.Gain_f[2] = 1.15470052F *
              mcb_pmsm_foc_sensorless_nucle_B.Add2;

            /* Gain: '<S15>/One_by_Two' */
            Bias = 0.5F * mcb_pmsm_foc_sensorless_nucle_B.Gain_f[0];
            mcb_pmsm_foc_sensorless_nucle_B.One_by_Two[0] = Bias;

            /* Sum: '<S15>/Sum' incorporates:
             *  Constant: '<S15>/Constant'
             */
            Bias += 0.5F;
            mcb_pmsm_foc_sensorless_nucle_B.Sum_h[0] = Bias;

            /* Switch: '<S15>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[0] = Bias;

            /* Gain: '<S15>/One_by_Two' */
            Bias = 0.5F * mcb_pmsm_foc_sensorless_nucle_B.Gain_f[1];
            mcb_pmsm_foc_sensorless_nucle_B.One_by_Two[1] = Bias;

            /* Sum: '<S15>/Sum' incorporates:
             *  Constant: '<S15>/Constant'
             */
            Bias += 0.5F;
            mcb_pmsm_foc_sensorless_nucle_B.Sum_h[1] = Bias;

            /* Switch: '<S15>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[1] = Bias;

            /* Gain: '<S15>/One_by_Two' */
            Bias = 0.5F * mcb_pmsm_foc_sensorless_nucle_B.Gain_f[2];
            mcb_pmsm_foc_sensorless_nucle_B.One_by_Two[2] = Bias;

            /* Sum: '<S15>/Sum' incorporates:
             *  Constant: '<S15>/Constant'
             */
            Bias += 0.5F;
            mcb_pmsm_foc_sensorless_nucle_B.Sum_h[2] = Bias;

            /* Switch: '<S15>/Switch' */
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[2] = Bias;
          } else {
            /* Switch: '<S15>/Switch' incorporates:
             *  Constant: '<S15>/stop'
             */
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[0] = 0.0F;
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[1] = 0.0F;
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[2] = 0.0F;
          }

          /* End of Switch: '<S15>/Switch' */

          /* Gain: '<S14>/Scale_to_PWM_Counter_PRD' */
          mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[0] = 100.0F *
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[0];
          mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[1] = 100.0F *
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[1];
          mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[2] = 100.0F *
            mcb_pmsm_foc_sensorless_nucle_B.PWM_Duty_Cycles[2];

          /* MATLABSystem: '<S205>/PWM Output' */
          setDutyCycleInPercentageChannel1
            (mcb_pmsm_foc_sensorless_n_DWork.obj_b.TimerHandle,
             mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[0]);
          setDutyCycleInPercentageChannel2
            (mcb_pmsm_foc_sensorless_n_DWork.obj_b.TimerHandle,
             mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[1]);
          setDutyCycleInPercentageChannel3
            (mcb_pmsm_foc_sensorless_n_DWork.obj_b.TimerHandle,
             mcb_pmsm_foc_sensorless_nucle_B.Scale_to_PWM_Counter_PRD[2]);

          /* SignalConversion generated from: '<S2>/Delay5' */
          mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[0] =
            mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_o;
          mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[1] =
            mcb_pmsm_foc_sensorless_nucle_B.algDD_o2_k;
          mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[2] =
            mcb_pmsm_foc_sensorless_nucle_B.algDD_o1_n;
          mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[3] =
            mcb_pmsm_foc_sensorless_nucle_B.algDD_o2_e;

          /* Update for UnitDelay: '<S188>/Unit Delay1' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay1_DSTATE =
            mcb_pmsm_foc_sensorless_nucle_B.Eta;

          /* Update for UnitDelay: '<S188>/Unit Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE =
            mcb_pmsm_foc_sensorless_nucle_B.Sum2;

          /* Update for Delay: '<S2>/Delay5' */
          mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[0] =
            mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[0];
          mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[1] =
            mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[1];
          mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[2] =
            mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[2];
          mcb_pmsm_foc_sensorless_n_DWork.Delay5_DSTATE[3] =
            mcb_pmsm_foc_sensorless_nucle_B.TmpSignalConversionAtDelay5Inpo[3];

          /* Update for Delay: '<S178>/Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE =
            mcb_pmsm_foc_sensorless_nucle_B.Sum1_c;

          /* Update for Delay: '<S188>/Delay1' */
          mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE =
            mcb_pmsm_foc_sensorless_nucle_B.Sum4;

          /* Update for UnitDelay: '<S192>/Unit Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_o =
            mcb_pmsm_foc_sensorless_nucle_B.Add1;

          /* Update for UnitDelay: '<S189>/Unit Delay1' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay1_DSTATE_n =
            mcb_pmsm_foc_sensorless_nucle_B.Eta_e;

          /* Update for UnitDelay: '<S189>/Unit Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_m =
            mcb_pmsm_foc_sensorless_nucle_B.Sum2_b;

          /* Update for Delay: '<S179>/Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_k =
            mcb_pmsm_foc_sensorless_nucle_B.Sum1_h;

          /* Update for Delay: '<S189>/Delay1' */
          mcb_pmsm_foc_sensorless_n_DWork.Delay1_DSTATE_e =
            mcb_pmsm_foc_sensorless_nucle_B.Sum4_g;

          /* Update for UnitDelay: '<S195>/Unit Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_g =
            mcb_pmsm_foc_sensorless_nucle_B.Add1_i;

          /* Update for Delay: '<S176>/Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_e =
            mcb_pmsm_foc_sensorless_nucle_B.Add1_c;

          /* Update for UnitDelay: '<S150>/Unit Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_h =
            mcb_pmsm_foc_sensorless_nucle_B.Add1_g;

          /* Update for UnitDelay: '<S27>/Unit Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_a =
            mcb_pmsm_foc_sensorless_nucle_B.Switch_h;

          /* Update for DiscreteIntegrator: '<S131>/Integrator' */
          mcb_pmsm_foc_sensorless_n_DWork.Integrator_IC_LOADING = 0U;
          mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE +=
            mcb_pmsm_foc_sensorless_nucle_B.Switch_m;
          Integrator_PrevResetState_tmp = (int8_T)
            mcb_pmsm_foc_sensorless_nucle_B.LogicalOperator_i;
          mcb_pmsm_foc_sensorless_n_DWork.Integrator_PrevResetState =
            Integrator_PrevResetState_tmp;

          /* Update for UnitDelay: '<S26>/Unit Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_p =
            mcb_pmsm_foc_sensorless_nucle_B.Switch_l;

          /* Update for DiscreteIntegrator: '<S78>/Integrator' */
          mcb_pmsm_foc_sensorless_n_DWork.Integrator_IC_LOADING_b = 0U;
          mcb_pmsm_foc_sensorless_n_DWork.Integrator_DSTATE_a +=
            mcb_pmsm_foc_sensorless_nucle_B.Switch_fm;
          mcb_pmsm_foc_sensorless_n_DWork.Integrator_PrevResetState_e =
            Integrator_PrevResetState_tmp;

          /* Update for Delay: '<S183>/Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.Delay_DSTATE_p[mcb_pmsm_foc_sensorless_n_DWork.CircBufIdx]
            = mcb_pmsm_foc_sensorless_nucle_B.PositionToCount;
          if (mcb_pmsm_foc_sensorless_n_DWork.CircBufIdx < 28U) {
            mcb_pmsm_foc_sensorless_n_DWork.CircBufIdx++;
          } else {
            mcb_pmsm_foc_sensorless_n_DWork.CircBufIdx = 0U;
          }

          /* End of Update for Delay: '<S183>/Delay' */

          /* Update for UnitDelay: '<S198>/Unit Delay' */
          mcb_pmsm_foc_sensorless_n_DWork.UnitDelay_DSTATE_hu =
            mcb_pmsm_foc_sensorless_nucle_B.Add1_c;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S10>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
}

void mcb_pmsm_foc_sensorless_nucleo_f401re_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
