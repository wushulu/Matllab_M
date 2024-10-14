/*
 * File: Testerr.c
 *
 * Code generated for Simulink model 'Testerr'.
 *
 * Model version                  : 1.38
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Oct 12 17:33:35 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Testerr.h"
#include "rtwtypes.h"
#include "Testerr_types.h"
#include "Testerr_private.h"
#include "stm_timer_ll.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "stm_adc_ll.h"
#include <stddef.h>

/* Block signals (default storage) */
B_Testerr_T Testerr_B;

/* Block states (default storage) */
DW_Testerr_T Testerr_DW;

/* Real-time model */
static RT_MODEL_Testerr_T Testerr_M_;
RT_MODEL_Testerr_T *const Testerr_M = &Testerr_M_;

/* Forward declaration for local functions */
static void Testerr_SystemCore_setup(stm32cube_blocks_TimerBlock_T_T *obj);

/* Forward declaration for local functions */
static void Testerr_SystemCore_setup_o(stm32cube_blocks_TimerBlock_T_T *obj);

/* Forward declaration for local functions */
static void Testerr_SystemCore_setup_f(stm32cube_blocks_TimerBlock_T_T *obj);

/* Forward declaration for local functions */
static void Testerr_SystemCore_setup_h(stm32cube_blocks_AnalogInput__T *obj);

/* Forward declaration for local functions */
static void Testerr_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Te_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Testerr_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Testerr_M, 1));
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
  (Testerr_M->Timing.TaskCounters.TID[1])++;
  if ((Testerr_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    Testerr_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S109>/If Action Subsystem6'
 *    '<S109>/If Action Subsystem7'
 *    '<S84>/If Action Subsystem6'
 *    '<S84>/If Action Subsystem7'
 *    '<S59>/If Action Subsystem6'
 *    '<S59>/If Action Subsystem7'
 */
void Testerr_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_Testerr_T *localP)
{
  /* SignalConversion generated from: '<S116>/direction' incorporates:
   *  Constant: '<S116>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S116>/sequence_check' incorporates:
   *  Constant: '<S116>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S109>/If Action Subsystem'
 *    '<S109>/If Action Subsystem1'
 *    '<S109>/If Action Subsystem2'
 *    '<S109>/If Action Subsystem3'
 *    '<S109>/If Action Subsystem4'
 *    '<S109>/If Action Subsystem5'
 *    '<S84>/If Action Subsystem'
 *    '<S84>/If Action Subsystem1'
 *    '<S84>/If Action Subsystem2'
 *    '<S84>/If Action Subsystem3'
 *    ...
 */
void Testerr_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_Testerr_T *localP)
{
  /* SignalConversion generated from: '<S110>/Out1' incorporates:
   *  Constant: '<S110>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S110>/Out2' incorporates:
   *  Constant: '<S110>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S107>/Valid Halls'
 *    '<S82>/Valid Halls'
 *    '<S57>/Valid Halls'
 */
void Testerr_ValidHalls_Init(B_ValidHalls_Testerr_T *localB,
  P_ValidHalls_Testerr_T *localP)
{
  /* SystemInitialize for Merge: '<S109>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S109>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S109>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S109>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S107>/Valid Halls'
 *    '<S82>/Valid Halls'
 *    '<S57>/Valid Halls'
 */
void Testerr_ValidHalls(uint16_T rtu_hallReading, uint16_T rtu_previousState,
  int16_T rtu_previous_direction, boolean_T *rty_directional_speed_valid_fla,
  int16_T *rty_direction, uint16_T *rty_inValidHall, B_ValidHalls_Testerr_T
  *localB, P_ValidHalls_Testerr_T *localP)
{
  /* SwitchCase: '<S109>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem' incorporates:
     *  ActionPort: '<S110>/Action Port'
     */
    Testerr_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S111>/Action Port'
     */
    Testerr_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S112>/Action Port'
     */
    Testerr_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S113>/Action Port'
     */
    Testerr_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S114>/Action Port'
     */
    Testerr_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S115>/Action Port'
     */
    Testerr_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem5' */
    break;
  }

  /* End of SwitchCase: '<S109>/Switch Case' */

  /* If: '<S109>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S116>/Action Port'
     */
    Testerr_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S117>/Action Port'
     */
    Testerr_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S109>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S118>/Action Port'
     */
    /* Merge: '<S109>/Merge3' incorporates:
     *  Constant: '<S118>/Constant'
     *  SignalConversion generated from: '<S118>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S109>/If Action Subsystem8' */
  }

  /* End of If: '<S109>/If' */

  /* SignalConversion: '<S109>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S109>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S109>/Switch' incorporates:
   *  Constant: '<S109>/Constant'
   *  RelationalOperator: '<S109>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_g;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S109>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S107>/Bad hall (glitch or wrong connection)'
 *    '<S82>/Bad hall (glitch or wrong connection)'
 *    '<S57>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S108>/inValidHall' incorporates:
   *  Constant: '<S108>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S108>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S108>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S108>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

static void Testerr_SystemCore_setup(stm32cube_blocks_TimerBlock_T_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S106>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S106>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S106>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Testerr_SystemCore_setup_o(stm32cube_blocks_TimerBlock_T_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S81>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S81>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S81>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Testerr_SystemCore_setup_f(stm32cube_blocks_TimerBlock_T_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S56>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S56>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S56>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/*
 * Output and update for action system:
 *    '<S37>/Hall Value of 1'
 *    '<S37>/Hall Value of 2'
 *    '<S37>/Hall Value of 3'
 *    '<S37>/Hall Value of 4'
 *    '<S37>/Hall Value of 5'
 *    '<S37>/Hall Value of 6'
 *    '<S37>/Hall Value of 7'
 *    '<S36>/Hall Value of 1'
 *    '<S36>/Hall Value of 2'
 *    '<S36>/Hall Value of 3'
 *    ...
 */
void Testerr_HallValueof1(real32_T *rty_position, P_HallValueof1_Testerr_T
  *localP)
{
  /* SignalConversion generated from: '<S47>/position' incorporates:
   *  Constant: '<S47>/Constant'
   */
  *rty_position = localP->Constant_Value;
}

static void Testerr_SystemCore_setup_h(stm32cube_blocks_AnalogInput__T *obj)
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

static void Testerr_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Te_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S137>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S137>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S137>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/* Model step function for TID0 */
void Testerr_step0(void)               /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void Testerr_step1(void)               /* Sample time: [0.1s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T c;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (Testerr_DW.clockTickCounter <
                        Testerr_P.PulseGenerator_Duty) &&
    (Testerr_DW.clockTickCounter >= 0) ? Testerr_P.PulseGenerator_Amp : 0.0;
  if (Testerr_DW.clockTickCounter >= Testerr_P.PulseGenerator_Period - 1.0) {
    Testerr_DW.clockTickCounter = 0;
  } else {
    Testerr_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S134>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S134>/Digital Port Write' */
}

/* Model initialize function */
void Testerr_initialize(void)
{
  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  Testerr_DW.GlobalHallState = Testerr_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  Testerr_DW.Timercntprev = Testerr_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  Testerr_DW.HallCcapture = Testerr_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  Testerr_DW.Timehall = Testerr_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  Testerr_DW.GlobalDirection = Testerr_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  Testerr_DW.GlobalSpeedCount = Testerr_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  Testerr_DW.GlobalSpeedValidity = Testerr_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  Testerr_DW.HallStateChangeFlag = Testerr_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  Testerr_DW.HallBcapture = Testerr_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  Testerr_DW.HallAcapture = Testerr_P.DataStoreMemory2_InitialValue;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S132>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */

  /* System initialize for function-call system: '<Root>/ADC SIC' */

  /* InitializeConditions for Delay: '<S19>/validityDelay' */
  Testerr_DW.validityDelay_DSTATE = Testerr_P.validityDelay_InitialCondition;

  /* InitializeConditions for Delay: '<S19>/speedCountDelay' */
  Testerr_DW.speedCountDelay_DSTATE = Testerr_P.speedCountDelay_InitialConditio;

  /* InitializeConditions for RelationalOperator: '<S24>/Compare' incorporates:
   *  Delay: '<S20>/Delay One Step1'
   */
  Testerr_DW.DelayOneStep1_DSTATE = Testerr_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Delay: '<S20>/Delay One Step' */
  Testerr_DW.DelayOneStep_DSTATE = Testerr_P.SoftwareWatchdogTimer_maxCount;

  /* Start for MATLABSystem: '<S14>/Analog to Digital Converter' */
  Testerr_DW.obj.isInitialized = 0;
  Testerr_DW.obj.matlabCodegenIsDeleted = false;
  Testerr_SystemCore_setup_h(&Testerr_DW.obj);

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S132>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HC'
   */
  /* System initialize for function-call system: '<Root>/HC' */

  /* InitializeConditions for Delay: '<S106>/Delay' */
  Testerr_DW.Delay_DSTATE_k = Testerr_P.Delay_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S107>/Valid Halls' */
  Testerr_ValidHalls_Init(&Testerr_B.ValidHalls, &Testerr_P.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S107>/Valid Halls' */

  /* Start for MATLABSystem: '<S106>/Timer' */
  Testerr_DW.obj_o.isInitialized = 0;
  Testerr_DW.obj_o.matlabCodegenIsDeleted = false;
  Testerr_SystemCore_setup(&Testerr_DW.obj_o);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HB'
   */
  /* System initialize for function-call system: '<Root>/HB' */

  /* InitializeConditions for Delay: '<S81>/Delay' */
  Testerr_DW.Delay_DSTATE_i = Testerr_P.Delay_InitialCondition_p;

  /* SystemInitialize for IfAction SubSystem: '<S82>/Valid Halls' */
  Testerr_ValidHalls_Init(&Testerr_B.ValidHalls_k, &Testerr_P.ValidHalls_k);

  /* End of SystemInitialize for SubSystem: '<S82>/Valid Halls' */

  /* Start for MATLABSystem: '<S81>/Timer' */
  Testerr_DW.obj_h.isInitialized = 0;
  Testerr_DW.obj_h.matlabCodegenIsDeleted = false;
  Testerr_SystemCore_setup_o(&Testerr_DW.obj_h);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HA'
   */

  /* System initialize for function-call system: '<Root>/HA' */

  /* InitializeConditions for Delay: '<S56>/Delay' */
  Testerr_DW.Delay_DSTATE = Testerr_P.Delay_InitialCondition_b;

  /* SystemInitialize for IfAction SubSystem: '<S57>/Valid Halls' */
  Testerr_ValidHalls_Init(&Testerr_B.ValidHalls_f, &Testerr_P.ValidHalls_f);

  /* End of SystemInitialize for SubSystem: '<S57>/Valid Halls' */

  /* Start for MATLABSystem: '<S56>/Timer' */
  Testerr_DW.obj_l.isInitialized = 0;
  Testerr_DW.obj_l.matlabCodegenIsDeleted = false;
  Testerr_SystemCore_setup_f(&Testerr_DW.obj_l);

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Parameters' */
  /* Start for MATLABSystem: '<S137>/PWM Output' */
  Testerr_DW.obj_ob.matlabCodegenIsDeleted = false;
  Testerr_DW.obj_ob.isSetupComplete = false;
  Testerr_DW.obj_ob.isInitialized = 1;
  Testerr_PWMOutput_setupImpl(&Testerr_DW.obj_ob);
  Testerr_DW.obj_ob.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Parameters' */

  /* Outputs for Atomic SubSystem: '<Root>/Parameters' */
  /* MATLABSystem: '<S137>/PWM Output' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  setDutyCycleInPercentageChannel1(Testerr_DW.obj_ob.TimerHandle,
    Testerr_P.Constant1_Value_na);
  setDutyCycleInPercentageChannel2(Testerr_DW.obj_ob.TimerHandle,
    Testerr_P.Constant1_Value_na);
  setDutyCycleInPercentageChannel3(Testerr_DW.obj_ob.TimerHandle,
    Testerr_P.Constant1_Value_na);

  /* End of Outputs for SubSystem: '<Root>/Parameters' */
}

/* Model terminate function */
void Testerr_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S132>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S132>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */
  /* Termination for function-call system: '<Root>/ADC SIC' */

  /* Terminate for MATLABSystem: '<S14>/Analog to Digital Converter' */
  if (!Testerr_DW.obj.matlabCodegenIsDeleted) {
    Testerr_DW.obj.matlabCodegenIsDeleted = true;
    if ((Testerr_DW.obj.isInitialized == 1) && Testerr_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Testerr_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S14>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S132>/Hardware Interrupt' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HC'
   */
  /* Termination for function-call system: '<Root>/HC' */

  /* Terminate for MATLABSystem: '<S106>/Timer' */
  if (!Testerr_DW.obj_o.matlabCodegenIsDeleted) {
    Testerr_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((Testerr_DW.obj_o.isInitialized == 1) &&
        Testerr_DW.obj_o.isSetupComplete) {
      disableCounter(Testerr_DW.obj_o.TimerHandle);
      disableTimerInterrupts(Testerr_DW.obj_o.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S106>/Timer' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HB'
   */
  /* Termination for function-call system: '<Root>/HB' */

  /* Terminate for MATLABSystem: '<S81>/Timer' */
  if (!Testerr_DW.obj_h.matlabCodegenIsDeleted) {
    Testerr_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Testerr_DW.obj_h.isInitialized == 1) &&
        Testerr_DW.obj_h.isSetupComplete) {
      disableCounter(Testerr_DW.obj_h.TimerHandle);
      disableTimerInterrupts(Testerr_DW.obj_h.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S81>/Timer' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HA'
   */
  /* Termination for function-call system: '<Root>/HA' */

  /* Terminate for MATLABSystem: '<S56>/Timer' */
  if (!Testerr_DW.obj_l.matlabCodegenIsDeleted) {
    Testerr_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((Testerr_DW.obj_l.isInitialized == 1) &&
        Testerr_DW.obj_l.isSetupComplete) {
      disableCounter(Testerr_DW.obj_l.TimerHandle);
      disableTimerInterrupts(Testerr_DW.obj_l.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S56>/Timer' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */

  /* Terminate for Atomic SubSystem: '<Root>/Parameters' */
  /* Terminate for MATLABSystem: '<S137>/PWM Output' */
  if (!Testerr_DW.obj_ob.matlabCodegenIsDeleted) {
    Testerr_DW.obj_ob.matlabCodegenIsDeleted = true;
    if ((Testerr_DW.obj_ob.isInitialized == 1) &&
        Testerr_DW.obj_ob.isSetupComplete) {
      disableCounter(Testerr_DW.obj_ob.TimerHandle);
      disableTimerInterrupts(Testerr_DW.obj_ob.TimerHandle, 0);
      disableTimerChannel1(Testerr_DW.obj_ob.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(Testerr_DW.obj_ob.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(Testerr_DW.obj_ob.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S137>/PWM Output' */
  /* End of Terminate for SubSystem: '<Root>/Parameters' */
}

void Testerr_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(55,&EXTI15_10_IRQHandler,2);
  MW_NVIC_EnableIRQ(55);
}

/* Hardware Interrupt Block: '<S130>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HC' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;

          /* MATLABSystem: '<S106>/Timer' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           */
          Testerr_DW.Timercntprev = getTimerCounterValue
            (Testerr_DW.obj_o.TimerHandle);

          /* MATLABSystem: '<S124>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S126>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S128>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S105>/Sum' incorporates:
           *  Gain: '<S105>/Gain'
           *  Gain: '<S105>/Gain1'
           *  Gain: '<S105>/Gain2'
           *  MATLABSystem: '<S124>/Digital Port Read'
           *  MATLABSystem: '<S126>/Digital Port Read'
           *  MATLABSystem: '<S128>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Testerr_P.Gain_Gain_k >> 5 : 0) + (uint32_T)((pinReadLoc_p & 2048U)
            != 0U ? Testerr_P.Gain1_Gain_g >> 6 : 0)) + (uint32_T)((pinReadLoc_e
            & 4096U) != 0U ? Testerr_P.Gain2_Gain >> 7 : 0));

          /* SwitchCase: '<S104>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S104>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S107>/Valid Halls' incorporates:
             *  ActionPort: '<S109>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S104>/Data Type Conversion2'
             */
            Testerr_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
                               Testerr_DW.GlobalHallState,
                               Testerr_DW.GlobalDirection, &rtb_Merge3,
                               &Testerr_DW.GlobalDirection, &rtb_Merge,
                               &Testerr_B.ValidHalls, &Testerr_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S107>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S107>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S108>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(Testerr_DW.GlobalDirection, &rtb_Merge,
              &Testerr_DW.GlobalDirection, &rtb_Merge3,
              &Testerr_P.Badhallglitchorwrongconnection);

            /* End of Outputs for SubSystem: '<S107>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S104>/Detects if the halls reading is valid' */

          /* Gain: '<S4>/Gain' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  DataTypeConversion: '<S106>/Data Type Conversion'
           *  DataTypeConversion: '<S106>/Data Type Conversion1'
           *  Delay: '<S106>/Delay'
           *  Sum: '<S106>/Sum'
           */
          Testerr_DW.Timehall = (int64_T)((int32_T)Testerr_DW.Timercntprev -
            (int32_T)Testerr_DW.Delay_DSTATE_k) * Testerr_P.Gain_Gain;

          /* DataTypeConversion: '<S104>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  Gain: '<S4>/Gain'
           */
          Testerr_DW.GlobalSpeedCount = (uint32_T)(Testerr_DW.Timehall >> 30);

          /* DataTypeConversion: '<S107>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          Testerr_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S104>/Constant'
           */
          Testerr_DW.HallStateChangeFlag = Testerr_P.Constant_Value_k;

          /* DataStoreWrite: '<S4>/Data Store Write6' */
          Testerr_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S4>/Data Store Write5' incorporates:
           *  Constant: '<S4>/Constant1'
           */
          Testerr_DW.HallCcapture = Testerr_P.Constant1_Value;

          /* Update for Delay: '<S106>/Delay' incorporates:
           *  DataStoreRead: '<S106>/Data Store Read1'
           */
          Testerr_DW.Delay_DSTATE_k = Testerr_DW.Timercntprev;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HB' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;

          /* MATLABSystem: '<S81>/Timer' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           */
          Testerr_DW.Timercntprev = getTimerCounterValue
            (Testerr_DW.obj_h.TimerHandle);

          /* MATLABSystem: '<S99>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S101>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S103>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S80>/Sum' incorporates:
           *  Gain: '<S80>/Gain'
           *  Gain: '<S80>/Gain1'
           *  Gain: '<S80>/Gain2'
           *  MATLABSystem: '<S101>/Digital Port Read'
           *  MATLABSystem: '<S103>/Digital Port Read'
           *  MATLABSystem: '<S99>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Testerr_P.Gain_Gain_ko >> 5 : 0) + (uint32_T)((pinReadLoc_p & 2048U)
            != 0U ? Testerr_P.Gain1_Gain_o >> 6 : 0)) + (uint32_T)((pinReadLoc_e
            & 4096U) != 0U ? Testerr_P.Gain2_Gain_b >> 7 : 0));

          /* SwitchCase: '<S79>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S79>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S82>/Valid Halls' incorporates:
             *  ActionPort: '<S84>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S79>/Data Type Conversion2'
             */
            Testerr_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
                               Testerr_DW.GlobalHallState,
                               Testerr_DW.GlobalDirection, &rtb_Merge3,
                               &Testerr_DW.GlobalDirection, &rtb_Merge,
                               &Testerr_B.ValidHalls_k, &Testerr_P.ValidHalls_k);

            /* End of Outputs for SubSystem: '<S82>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S82>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S83>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(Testerr_DW.GlobalDirection, &rtb_Merge,
              &Testerr_DW.GlobalDirection, &rtb_Merge3,
              &Testerr_P.Badhallglitchorwrongconnectio_i);

            /* End of Outputs for SubSystem: '<S82>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S79>/Detects if the halls reading is valid' */

          /* Gain: '<S3>/Gain' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  DataTypeConversion: '<S81>/Data Type Conversion'
           *  DataTypeConversion: '<S81>/Data Type Conversion1'
           *  Delay: '<S81>/Delay'
           *  Sum: '<S81>/Sum'
           */
          Testerr_DW.Timehall = (int64_T)((int32_T)Testerr_DW.Timercntprev -
            (int32_T)Testerr_DW.Delay_DSTATE_i) * Testerr_P.Gain_Gain_b;

          /* DataTypeConversion: '<S79>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  Gain: '<S3>/Gain'
           */
          Testerr_DW.GlobalSpeedCount = (uint32_T)(Testerr_DW.Timehall >> 30);

          /* DataTypeConversion: '<S82>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          Testerr_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S79>/Constant'
           */
          Testerr_DW.HallStateChangeFlag = Testerr_P.Constant_Value_jq;

          /* DataStoreWrite: '<S3>/Data Store Write6' */
          Testerr_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S3>/Data Store Write5' incorporates:
           *  Constant: '<S3>/Constant1'
           */
          Testerr_DW.HallBcapture = Testerr_P.Constant1_Value_i;

          /* Update for Delay: '<S81>/Delay' incorporates:
           *  DataStoreRead: '<S81>/Data Store Read1'
           */
          Testerr_DW.Delay_DSTATE_i = Testerr_DW.Timercntprev;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HA' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;

          /* MATLABSystem: '<S56>/Timer' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           */
          Testerr_DW.Timercntprev = getTimerCounterValue
            (Testerr_DW.obj_l.TimerHandle);

          /* MATLABSystem: '<S74>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S76>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S78>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S55>/Sum' incorporates:
           *  Gain: '<S55>/Gain'
           *  Gain: '<S55>/Gain1'
           *  Gain: '<S55>/Gain2'
           *  MATLABSystem: '<S74>/Digital Port Read'
           *  MATLABSystem: '<S76>/Digital Port Read'
           *  MATLABSystem: '<S78>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Testerr_P.Gain_Gain_f >> 5 : 0) + (uint32_T)((pinReadLoc_p & 2048U)
            != 0U ? Testerr_P.Gain1_Gain_l >> 6 : 0)) + (uint32_T)((pinReadLoc_e
            & 4096U) != 0U ? Testerr_P.Gain2_Gain_j >> 7 : 0));

          /* SwitchCase: '<S54>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S54>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S57>/Valid Halls' incorporates:
             *  ActionPort: '<S59>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S54>/Data Type Conversion2'
             */
            Testerr_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
                               Testerr_DW.GlobalHallState,
                               Testerr_DW.GlobalDirection, &rtb_Merge3,
                               &Testerr_DW.GlobalDirection, &rtb_Merge,
                               &Testerr_B.ValidHalls_f, &Testerr_P.ValidHalls_f);

            /* End of Outputs for SubSystem: '<S57>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S57>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S58>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(Testerr_DW.GlobalDirection, &rtb_Merge,
              &Testerr_DW.GlobalDirection, &rtb_Merge3,
              &Testerr_P.Badhallglitchorwrongconnectio_a);

            /* End of Outputs for SubSystem: '<S57>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S54>/Detects if the halls reading is valid' */

          /* Gain: '<S2>/Gain' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  DataTypeConversion: '<S56>/Data Type Conversion'
           *  DataTypeConversion: '<S56>/Data Type Conversion1'
           *  Delay: '<S56>/Delay'
           *  Sum: '<S56>/Sum'
           */
          Testerr_DW.Timehall = (int64_T)((int32_T)Testerr_DW.Timercntprev -
            (int32_T)Testerr_DW.Delay_DSTATE) * Testerr_P.Gain_Gain_i;

          /* DataTypeConversion: '<S54>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  Gain: '<S2>/Gain'
           */
          Testerr_DW.GlobalSpeedCount = (uint32_T)(Testerr_DW.Timehall >> 30);

          /* DataTypeConversion: '<S57>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          Testerr_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S54>/Constant'
           */
          Testerr_DW.HallStateChangeFlag = Testerr_P.Constant_Value_m;

          /* DataStoreWrite: '<S2>/Data Store Write6' */
          Testerr_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S2>/Data Store Write5' incorporates:
           *  Constant: '<S2>/Constant1'
           */
          Testerr_DW.HallAcapture = Testerr_P.Constant1_Value_n;

          /* Update for Delay: '<S56>/Delay' incorporates:
           *  DataStoreRead: '<S56>/Data Store Read1'
           */
          Testerr_DW.Delay_DSTATE = Testerr_DW.Timercntprev;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S130>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

/* Hardware Interrupt Block: '<S132>/Hardware Interrupt' */
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
        /* S-Function (HardwareInterrupt_sfun): '<S132>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC SIC' */
        {
          real_T tmp_p;
          real32_T rtb_Merge1_f;
          uint32_T u1;
          uint16_T tmp[3];
          uint16_T Switch;
          uint16_T rtb_watchdogcheck;
          boolean_T OR;

          /* DataStoreRead: '<S17>/Data Store Read6' */
          rtb_watchdogcheck = Testerr_DW.HallStateChangeFlag;

          /* Switch: '<S18>/Switch' incorporates:
           *  Constant: '<S18>/WatchDog'
           *  DataStoreRead: '<S17>/Data Store Read6'
           *  DataStoreWrite: '<S17>/Data Store Write3'
           */
          if (Testerr_DW.HallStateChangeFlag != 0) {
            Testerr_DW.HallStateChangeFlag = Testerr_P.WatchDog_Value;
          }

          /* End of Switch: '<S18>/Switch' */

          /* Switch: '<S19>/Switch' incorporates:
           *  Constant: '<S19>/Order'
           */
          if (Testerr_P.Order_Value > Testerr_P.Switch_Threshold) {
            /* Switch: '<S19>/Switch' */
            Switch = rtb_watchdogcheck;
          } else {
            /* Switch: '<S19>/Switch' */
            Switch = Testerr_P.Order_Value;
          }

          /* End of Switch: '<S19>/Switch' */

          /* Delay: '<S19>/validityDelay' incorporates:
           *  Delay: '<S19>/speedCountDelay'
           */
          if (Switch != 0) {
            /* Delay: '<S19>/validityDelay' */
            Testerr_B.validityDelay = Testerr_DW.validityDelay_DSTATE;
          }

          /* End of Delay: '<S19>/validityDelay' */

          /* Logic: '<S20>/OR' incorporates:
           *  DataTypeConversion: '<S18>/Data Type Conversion4'
           *  Delay: '<S20>/Delay One Step1'
           */
          OR = (Testerr_DW.DelayOneStep1_DSTATE || (rtb_watchdogcheck != 0));

          /* Delay: '<S20>/Delay One Step' incorporates:
           *  DataTypeConversion: '<S18>/Data Type Conversion4'
           */
          if (OR) {
            if (rtb_watchdogcheck != 0) {
              Testerr_DW.DelayOneStep_DSTATE =
                Testerr_P.SoftwareWatchdogTimer_maxCount;
            }

            /* Delay: '<S20>/Delay One Step' incorporates:
             *  DataTypeConversion: '<S18>/Data Type Conversion4'
             */
            Testerr_B.DelayOneStep = Testerr_DW.DelayOneStep_DSTATE;
          }

          /* End of Delay: '<S20>/Delay One Step' */

          /* RelationalOperator: '<S24>/Compare' incorporates:
           *  Constant: '<S24>/Constant'
           */
          Testerr_DW.DelayOneStep1_DSTATE = (Testerr_B.DelayOneStep >
            Testerr_P.Constant_Value_d);

          /* Switch: '<S23>/watchdog check' incorporates:
           *  Constant: '<S23>/Constant'
           */
          if (Testerr_DW.DelayOneStep1_DSTATE) {
            /* DataTypeConversion: '<S18>/counterSize1' incorporates:
             *  DataStoreRead: '<S17>/Data Store Read'
             *  DataStoreRead: '<S17>/Data Store Read2'
             *  DataStoreRead: '<S17>/Data Store Read7'
             *  MinMax: '<S17>/Min'
             */
            tmp_p = floor(fmin(fmin(Testerr_DW.HallAcapture,
              Testerr_DW.HallBcapture), Testerr_DW.HallCcapture));
            if (rtIsNaN(tmp_p) || rtIsInf(tmp_p)) {
              tmp_p = 0.0;
            } else {
              tmp_p = fmod(tmp_p, 4.294967296E+9);
            }

            u1 = tmp_p < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp_p : (uint32_T)
              tmp_p;

            /* End of DataTypeConversion: '<S18>/counterSize1' */

            /* MinMax: '<S23>/Max' incorporates:
             *  DataStoreRead: '<S17>/Data Store Read3'
             */
            if (Testerr_DW.GlobalSpeedCount >= u1) {
              u1 = Testerr_DW.GlobalSpeedCount;
            }

            /* Switch: '<S23>/speed check' incorporates:
             *  Constant: '<S23>/Constant'
             *  DataStoreRead: '<S17>/Data Store Read5'
             *  DataTypeConversion: '<S19>/Data Type Conversion'
             *  Logic: '<S19>/Logical Operator'
             *  MinMax: '<S23>/Max'
             */
            if (u1 >= Testerr_P.speedcheck_Threshold) {
              rtb_watchdogcheck = Testerr_P.Constant_Value_p;
            } else {
              rtb_watchdogcheck = (uint16_T)((Testerr_DW.GlobalSpeedValidity !=
                0) || Testerr_B.validityDelay);
            }

            /* End of Switch: '<S23>/speed check' */
          } else {
            rtb_watchdogcheck = Testerr_P.Constant_Value_p;
          }

          /* End of Switch: '<S23>/watchdog check' */

          /* If: '<S18>/If' incorporates:
           *  Constant: '<S22>/PositionEnable'
           */
          if (rtb_watchdogcheck != 0) {
            /* Outputs for IfAction SubSystem: '<S18>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S22>/Action Port'
             */
            /* Outputs for Enabled SubSystem: '<S22>/Subsystem1' incorporates:
             *  EnablePort: '<S35>/Enable'
             */
            if (Testerr_P.PositionEnable_Value > 0) {
              /* If: '<S35>/If' incorporates:
               *  DataStoreRead: '<S17>/Data Store Read4'
               */
              if (Testerr_DW.GlobalDirection != 1) {
                /* Outputs for IfAction SubSystem: '<S35>/-ve Direction' incorporates:
                 *  ActionPort: '<S37>/Action Port'
                 */
                /* SwitchCase: '<S37>/Switch Case' incorporates:
                 *  DataStoreRead: '<S17>/Data Store Read1'
                 */
                switch (Testerr_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S47>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof1);

                  /* End of Outputs for SubSystem: '<S37>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S48>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof2);

                  /* End of Outputs for SubSystem: '<S37>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S49>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof3);

                  /* End of Outputs for SubSystem: '<S37>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S50>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof4);

                  /* End of Outputs for SubSystem: '<S37>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S51>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof5);

                  /* End of Outputs for SubSystem: '<S37>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S52>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof6);

                  /* End of Outputs for SubSystem: '<S37>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S53>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof7);

                  /* End of Outputs for SubSystem: '<S37>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S37>/Switch Case' */
                /* End of Outputs for SubSystem: '<S35>/-ve Direction' */
              } else {
                /* Outputs for IfAction SubSystem: '<S35>/+ve Direction' incorporates:
                 *  ActionPort: '<S36>/Action Port'
                 */
                /* SwitchCase: '<S36>/Switch Case' incorporates:
                 *  DataStoreRead: '<S17>/Data Store Read1'
                 */
                switch (Testerr_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S40>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof1_g);

                  /* End of Outputs for SubSystem: '<S36>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S41>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof2_m);

                  /* End of Outputs for SubSystem: '<S36>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S42>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof3_b);

                  /* End of Outputs for SubSystem: '<S36>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S43>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof4_j);

                  /* End of Outputs for SubSystem: '<S36>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S44>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof5_n);

                  /* End of Outputs for SubSystem: '<S36>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S45>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof6_i);

                  /* End of Outputs for SubSystem: '<S36>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S46>/Action Port'
                   */
                  Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof7_o);

                  /* End of Outputs for SubSystem: '<S36>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S36>/Switch Case' */
                /* End of Outputs for SubSystem: '<S35>/+ve Direction' */
              }

              /* End of If: '<S35>/If' */
            }

            /* End of Outputs for SubSystem: '<S22>/Subsystem1' */
            /* End of Outputs for SubSystem: '<S18>/Speed and direction are valid Use speed to extrapolate position' */
          } else {
            /* Outputs for IfAction SubSystem: '<S18>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S21>/Action Port'
             */
            /* SwitchCase: '<S25>/Switch Case' incorporates:
             *  DataStoreRead: '<S17>/Data Store Read1'
             */
            switch (Testerr_DW.GlobalHallState) {
             case 5:
              /* Outputs for IfAction SubSystem: '<S25>/Hall Value of 1' incorporates:
               *  ActionPort: '<S26>/Action Port'
               */
              Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof1_o);

              /* End of Outputs for SubSystem: '<S25>/Hall Value of 1' */
              break;

             case 4:
              /* Outputs for IfAction SubSystem: '<S25>/Hall Value of 2' incorporates:
               *  ActionPort: '<S27>/Action Port'
               */
              Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof2_d);

              /* End of Outputs for SubSystem: '<S25>/Hall Value of 2' */
              break;

             case 6:
              /* Outputs for IfAction SubSystem: '<S25>/Hall Value of 3' incorporates:
               *  ActionPort: '<S28>/Action Port'
               */
              Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof3_f);

              /* End of Outputs for SubSystem: '<S25>/Hall Value of 3' */
              break;

             case 2:
              /* Outputs for IfAction SubSystem: '<S25>/Hall Value of 4' incorporates:
               *  ActionPort: '<S29>/Action Port'
               */
              Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof4_o);

              /* End of Outputs for SubSystem: '<S25>/Hall Value of 4' */
              break;

             case 3:
              /* Outputs for IfAction SubSystem: '<S25>/Hall Value of 5' incorporates:
               *  ActionPort: '<S30>/Action Port'
               */
              Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof5_o);

              /* End of Outputs for SubSystem: '<S25>/Hall Value of 5' */
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S25>/Hall Value of 6' incorporates:
               *  ActionPort: '<S31>/Action Port'
               */
              Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof6_a);

              /* End of Outputs for SubSystem: '<S25>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S25>/Hall Value of 7' incorporates:
               *  ActionPort: '<S32>/Action Port'
               */
              Testerr_HallValueof1(&rtb_Merge1_f, &Testerr_P.HallValueof7_e);

              /* End of Outputs for SubSystem: '<S25>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S25>/Switch Case' */
            /* End of Outputs for SubSystem: '<S18>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
          }

          /* End of If: '<S18>/If' */

          /* MATLABSystem: '<S14>/Analog to Digital Converter' */
          injectedReadADCIntr(Testerr_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* Update for Delay: '<S19>/validityDelay' incorporates:
           *  DataStoreRead: '<S17>/Data Store Read3'
           *  DataStoreRead: '<S17>/Data Store Read5'
           *  DataTypeConversion: '<S19>/Data Type Conversion'
           *  Delay: '<S19>/speedCountDelay'
           */
          if (Switch != 0) {
            Testerr_DW.validityDelay_DSTATE = (Testerr_DW.GlobalSpeedValidity !=
              0);
            Testerr_DW.speedCountDelay_DSTATE = Testerr_DW.GlobalSpeedCount;
          }

          /* End of Update for Delay: '<S19>/validityDelay' */

          /* Update for Delay: '<S20>/Delay One Step' incorporates:
           *  Constant: '<S20>/Constant2'
           *  Sum: '<S20>/Sum'
           */
          if (OR) {
            Testerr_DW.DelayOneStep_DSTATE = (uint16_T)((uint32_T)
              Testerr_B.DelayOneStep - Testerr_P.Constant2_Value);
          }

          /* End of Update for Delay: '<S20>/Delay One Step' */
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S132>/Hardware Interrupt' */
      }
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void Testerr_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
  MW_NVIC_DisableIRQ(55);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
