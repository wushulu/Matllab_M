/*
 * File: STMF4Hall.c
 *
 * Code generated for Simulink model 'STMF4Hall'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct  8 14:53:15 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "STMF4Hall.h"
#include "rtwtypes.h"
#include "STMF4Hall_types.h"
#include "STMF4Hall_private.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_STMF4Hall_T STMF4Hall_B;

/* Block states (default storage) */
DW_STMF4Hall_T STMF4Hall_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_STMF4Hall_T STMF4Hall_Y;

/* Real-time model */
static RT_MODEL_STMF4Hall_T STMF4Hall_M_;
RT_MODEL_STMF4Hall_T *const STMF4Hall_M = &STMF4Hall_M_;

/* Forward declaration for local functions */
static void STMF4Hall_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);

/* Forward declaration for local functions */
static void STMF4Hall_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_ST_T *obj);
static void STMF4Hall_SystemCore_setup_o(stm32cube_blocks_TimerBlock_S_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void STMF4Hall_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(STMF4Hall_M, 1));
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
  (STMF4Hall_M->Timing.TaskCounters.TID[1])++;
  if ((STMF4Hall_M->Timing.TaskCounters.TID[1]) > 1999) {/* Sample time: [0.1s, 0.0s] */
    STMF4Hall_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S68>/If Action Subsystem6'
 *    '<S68>/If Action Subsystem7'
 *    '<S43>/If Action Subsystem6'
 *    '<S43>/If Action Subsystem7'
 *    '<S18>/If Action Subsystem6'
 *    '<S18>/If Action Subsystem7'
 */
void STMF4Hal_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_STMF4Hal_T *localP)
{
  /* SignalConversion generated from: '<S75>/direction' incorporates:
   *  Constant: '<S75>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S75>/sequence_check' incorporates:
   *  Constant: '<S75>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S68>/If Action Subsystem'
 *    '<S68>/If Action Subsystem1'
 *    '<S68>/If Action Subsystem2'
 *    '<S68>/If Action Subsystem3'
 *    '<S68>/If Action Subsystem4'
 *    '<S68>/If Action Subsystem5'
 *    '<S43>/If Action Subsystem'
 *    '<S43>/If Action Subsystem1'
 *    '<S43>/If Action Subsystem2'
 *    '<S43>/If Action Subsystem3'
 *    ...
 */
void STMF4Hall_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_STMF4Hall_T *localP)
{
  /* SignalConversion generated from: '<S69>/Out1' incorporates:
   *  Constant: '<S69>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S69>/Out2' incorporates:
   *  Constant: '<S69>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S66>/Valid Halls'
 *    '<S41>/Valid Halls'
 *    '<S16>/Valid Halls'
 */
void STMF4Hall_ValidHalls_Init(B_ValidHalls_STMF4Hall_T *localB,
  P_ValidHalls_STMF4Hall_T *localP)
{
  /* SystemInitialize for Merge: '<S68>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S68>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S68>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S68>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S66>/Valid Halls'
 *    '<S41>/Valid Halls'
 *    '<S16>/Valid Halls'
 */
void STMF4Hall_ValidHalls(uint16_T rtu_hallReading, uint16_T rtu_previousState,
  int16_T rtu_previous_direction, boolean_T *rty_directional_speed_valid_fla,
  int16_T *rty_direction, uint16_T *rty_inValidHall, B_ValidHalls_STMF4Hall_T
  *localB, DW_ValidHalls_STMF4Hall_T *localDW, P_ValidHalls_STMF4Hall_T *localP)
{
  /* SwitchCase: '<S68>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem' incorporates:
     *  ActionPort: '<S69>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S70>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S71>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem5' */
    break;

   default:
    /* Update for IfAction SubSystem: '<S68>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    /* Update for SwitchCase: '<S68>/Switch Case' */
    localDW->SwitchCaseActionSubsystem_Subsy = 4;

    /* End of Update for SubSystem: '<S68>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S68>/Switch Case' */

  /* If: '<S68>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    STMF4Hal_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    STMF4Hal_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S68>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    /* Merge: '<S68>/Merge3' incorporates:
     *  Constant: '<S77>/Constant'
     *  SignalConversion generated from: '<S77>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S68>/If Action Subsystem8' */

    /* Update for IfAction SubSystem: '<S68>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S77>/Action Port'
     */
    /* Update for If: '<S68>/If' */
    localDW->IfActionSubsystem8_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S68>/If Action Subsystem8' */
  }

  /* End of If: '<S68>/If' */

  /* SignalConversion: '<S68>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S68>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S68>/Switch' incorporates:
   *  Constant: '<S68>/Constant'
   *  RelationalOperator: '<S68>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_i;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S68>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S66>/Bad hall (glitch or wrong connection)'
 *    '<S41>/Bad hall (glitch or wrong connection)'
 *    '<S16>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S67>/inValidHall' incorporates:
   *  Constant: '<S67>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S67>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S67>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S67>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

static void STMF4Hall_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S91>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S91>/Analog to Digital Converter' */
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

static void STMF4Hall_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_ST_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S109>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S109>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S109>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void STMF4Hall_SystemCore_setup_o(stm32cube_blocks_TimerBlock_S_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Timer1' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Timer1' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Timer1' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void STMF4Hall_step0(void)             /* Sample time: [5.0E-5s, 0.0s] */
{
  int16_T rtb_RT;
  int16_T rtb_RT4;

  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DataStoreRead: '<Root>/Data Store Read' */
  STMF4Hall_B.Halls = STMF4Hall_DW.GlobalHallState;

  /* MultiPortSwitch: '<S10>/Multiport Switch' */
  switch (STMF4Hall_B.Halls) {
   case 1:
    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant1'
     *  Constant: '<S10>/Constant8'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant1_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant8_Value;
    break;

   case 2:
    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant2'
     *  Constant: '<S10>/Constant9'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant2_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant9_Value;
    break;

   case 3:
    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant10'
     *  Constant: '<S10>/Constant3'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant3_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant10_Value;
    break;

   case 4:
    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant11'
     *  Constant: '<S10>/Constant4'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant4_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant11_Value;
    break;

   case 5:
    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant12'
     *  Constant: '<S10>/Constant5'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant5_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant12_Value;
    break;

   case 6:
    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant14'
     *  Constant: '<S10>/Constant6'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant6_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant14_Value;
    break;

   default:
    /* MultiPortSwitch: '<S10>/Multiport Switch' incorporates:
     *  Constant: '<S10>/Constant12'
     *  Constant: '<S10>/Constant7'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant7_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant12_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S10>/Multiport Switch' */

  /* Outport: '<Root>/Hall state' */
  STMF4Hall_Y.Hallstate = STMF4Hall_B.MultiportSwitch[0];

  /* Outport: '<Root>/Hall angle' */
  STMF4Hall_Y.Hallangle = STMF4Hall_B.MultiportSwitch[1];

  /* MATLABSystem: '<S109>/PWM Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  setDutyCycleInPercentageChannel1(STMF4Hall_DW.obj_f.TimerHandle,
    STMF4Hall_P.Constant_Value_b);
  setDutyCycleInPercentageChannel2(STMF4Hall_DW.obj_f.TimerHandle,
    STMF4Hall_P.Constant_Value_b);
  setDutyCycleInPercentageChannel3(STMF4Hall_DW.obj_f.TimerHandle,
    STMF4Hall_P.Constant_Value_b);

  /* RateTransition: '<Root>/RT4' */
  rtb_RT4 = STMF4Hall_B.Sum;

  /* RateTransition: '<Root>/RT' */
  rtb_RT = STMF4Hall_B.Sum_c;

  /* RateTransition: '<Root>/RT2' */
  STMF4Hall_B.gethalltimer = STMF4Hall_B.Sum_i;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  RateTransition: '<Root>/RT3'
   */
  switch ((int32_T)STMF4Hall_B.OutportBufferForOut2_e2) {
   case 1:
    /* RateTransition: '<Root>/RT2' incorporates:
     *  MultiPortSwitch: '<Root>/Multiport Switch'
     */
    STMF4Hall_B.gethalltimer = rtb_RT4;
    break;

   case 2:
    /* RateTransition: '<Root>/RT2' incorporates:
     *  MultiPortSwitch: '<Root>/Multiport Switch'
     */
    STMF4Hall_B.gethalltimer = rtb_RT;
    break;
  }

  /* End of MultiPortSwitch: '<Root>/Multiport Switch' */
  /* MATLABSystem: '<Root>/Timer1' */
  STMF4Hall_B.time3_k = getTimerCounterValue(STMF4Hall_DW.obj_b.TimerHandle);

  /* RateTransition generated from: '<Root>/Function-Call Subsystem1' */
  STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem1I = STMF4Hall_B.time3_k;

  /* RateTransition generated from: '<Root>/Function-Call Subsystem2' */
  STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem2I = STMF4Hall_B.time3_k;

  /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
  STMF4Hall_DW.time3_Buffer0 = STMF4Hall_B.time3_k;

  /* RateTransition: '<Root>/RT6' */
  STMF4Hall_B.testcounter = STMF4Hall_B.Output;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  STMF4Hall_M->Timing.taskTime0 =
    ((time_T)(++STMF4Hall_M->Timing.clockTick0)) * STMF4Hall_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void STMF4Hall_step1(void)             /* Sample time: [0.1s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T c;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (STMF4Hall_DW.clockTickCounter <
                        STMF4Hall_P.PulseGenerator_Duty) &&
    (STMF4Hall_DW.clockTickCounter >= 0) ? STMF4Hall_P.PulseGenerator_Amp : 0.0;
  if (STMF4Hall_DW.clockTickCounter >= STMF4Hall_P.PulseGenerator_Period - 1.0)
  {
    STMF4Hall_DW.clockTickCounter = 0;
  } else {
    STMF4Hall_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S12>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S12>/Digital Port Write' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  STMF4Hall_M->Timing.clockTick1++;
}

/* Model initialize function */
void STMF4Hall_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(STMF4Hall_M, -1);
  STMF4Hall_M->Timing.stepSize0 = 5.0E-5;

  /* External mode info */
  STMF4Hall_M->Sizes.checksums[0] = (2336501917U);
  STMF4Hall_M->Sizes.checksums[1] = (4209383380U);
  STMF4Hall_M->Sizes.checksums[2] = (639197037U);
  STMF4Hall_M->Sizes.checksums[3] = (1975475682U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[72];
    STMF4Hall_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &STMF4Hall_DW.Badhallglitchorwrongconnectio_a.Badhallglitchorwrongconnection_;
    systemRan[3] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem8_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.SwitchCaseActionSubsystem_Subsy;
    systemRan[13] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.ValidHalls_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.ValidHalls_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.ValidHalls_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[17] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[18] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[19] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[20] = (sysRanDType *)
      &STMF4Hall_DW.Badhallglitchorwrongconnectio_c.Badhallglitchorwrongconnection_;
    systemRan[21] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem8_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.SwitchCaseActionSubsystem_Subsy;
    systemRan[31] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.ValidHalls_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.ValidHalls_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.ValidHalls_SubsysRanBC;
    systemRan[34] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[35] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[36] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[37] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[38] = (sysRanDType *)
      &STMF4Hall_DW.Badhallglitchorwrongconnection.Badhallglitchorwrongconnection_;
    systemRan[39] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy;
    systemRan[49] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[52] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem2_SubsysRa;
    systemRan[53] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem2_SubsysRa;
    systemRan[54] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem2_SubsysRa;
    systemRan[55] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem2_SubsysRa;
    systemRan[56] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem3_SubsysRa;
    systemRan[57] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem3_SubsysRa;
    systemRan[58] = (sysRanDType *)&STMF4Hall_DW.FunctionCallSubsystem3_SubsysRa;
    systemRan[59] = &rtAlwaysEnabled;
    systemRan[60] = &rtAlwaysEnabled;
    systemRan[61] = &rtAlwaysEnabled;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = &rtAlwaysEnabled;
    systemRan[64] = &rtAlwaysEnabled;
    systemRan[65] = &rtAlwaysEnabled;
    systemRan[66] = &rtAlwaysEnabled;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = &rtAlwaysEnabled;
    systemRan[69] = &rtAlwaysEnabled;
    systemRan[70] = &rtAlwaysEnabled;
    systemRan[71] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(STMF4Hall_M->extModeInfo,
      &STMF4Hall_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(STMF4Hall_M->extModeInfo, STMF4Hall_M->Sizes.checksums);
    rteiSetTPtr(STMF4Hall_M->extModeInfo, rtmGetTPtr(STMF4Hall_M));
  }

  {
    uint32_T pinReadLoc;
    uint32_T pinReadLoc_0;
    uint32_T pinReadLoc_1;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    STMF4Hall_DW.GlobalHallState = STMF4Hall_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    STMF4Hall_DW.Timehall = STMF4Hall_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    STMF4Hall_DW.Timercntprev = STMF4Hall_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    STMF4Hall_DW.GlobalDirection = STMF4Hall_P.DataStoreMemory5_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    STMF4Hall_DW.GlobalSpeedCount = STMF4Hall_P.DataStoreMemory6_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
    STMF4Hall_DW.GlobalSpeedValidity = STMF4Hall_P.DataStoreMemory7_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
    STMF4Hall_DW.HallStateChangeFlag = STMF4Hall_P.DataStoreMemory8_InitialValue;

    /* InitializeConditions for RateTransition generated from: '<Root>/Function-Call Subsystem1' */
    STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem1I =
      STMF4Hall_P.TmpRTBAtFunctionCallSubsystem1I;

    /* InitializeConditions for RateTransition generated from: '<Root>/Function-Call Subsystem2' */
    STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem2I =
      STMF4Hall_P.TmpRTBAtFunctionCallSubsystem2I;

    /* InitializeConditions for RateTransition generated from: '<Root>/Function-Call Subsystem' */
    STMF4Hall_DW.time3_Buffer0 = STMF4Hall_P.time3_InitialCondition;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem2'
     */
    /* System initialize for function-call system: '<Root>/Function-Call Subsystem2' */
    STMF4Hall_M->Timing.clockTick2 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S66>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls, &STMF4Hall_P.ValidHalls);

    /* End of SystemInitialize for SubSystem: '<S66>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S4>/Out2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2_e2 = STMF4Hall_P.Constant_Value;

    /* SystemInitialize for Sum: '<S4>/Sum' incorporates:
     *  Outport: '<S4>/Out1'
     */
    STMF4Hall_B.Sum_i = STMF4Hall_P.Out1_Y0;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem1'
     */
    /* System initialize for function-call system: '<Root>/Function-Call Subsystem1' */
    STMF4Hall_M->Timing.clockTick3 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S41>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls_l,
      &STMF4Hall_P.ValidHalls_l);

    /* End of SystemInitialize for SubSystem: '<S41>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S3>/Out2' incorporates:
     *  Constant: '<S3>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2_e = STMF4Hall_P.Constant_Value_p;

    /* SystemInitialize for Sum: '<S3>/Sum' incorporates:
     *  Outport: '<S3>/Out1'
     */
    STMF4Hall_B.Sum_c = STMF4Hall_P.Out1_Y0_h;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */

    /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
    STMF4Hall_M->Timing.clockTick4 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S16>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls_d,
      &STMF4Hall_P.ValidHalls_d);

    /* End of SystemInitialize for SubSystem: '<S16>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S2>/Out2' incorporates:
     *  Constant: '<S2>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2 = STMF4Hall_P.Constant_Value_f;

    /* SystemInitialize for Sum: '<S2>/Sum' incorporates:
     *  Outport: '<S2>/Out1'
     */
    STMF4Hall_B.Sum = STMF4Hall_P.Out1_Y0_l;

    /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' */

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S97>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem3'
     */

    /* System initialize for function-call system: '<Root>/Function-Call Subsystem3' */
    STMF4Hall_M->Timing.clockTick5 = STMF4Hall_M->Timing.clockTick0;

    /* InitializeConditions for Sum: '<S92>/FixPt Sum1' incorporates:
     *  UnitDelay: '<S89>/Output'
     */
    STMF4Hall_DW.Output_DSTATE = STMF4Hall_P.Output_InitialCondition;

    /* Start for MATLABSystem: '<S91>/Analog to Digital Converter' */
    STMF4Hall_DW.obj.isInitialized = 0;
    STMF4Hall_DW.obj.matlabCodegenIsDeleted = false;
    STMF4Hall_SystemCore_setup(&STMF4Hall_DW.obj);

    /* SystemInitialize for UnitDelay: '<S89>/Output' incorporates:
     *  Outport: '<S5>/Out1'
     */
    STMF4Hall_B.Output = STMF4Hall_P.Out1_Y0_hj;

    /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S97>/Hardware Interrupt' */

    /* Start for MATLABSystem: '<S109>/PWM Output' */
    STMF4Hall_DW.obj_f.matlabCodegenIsDeleted = false;
    STMF4Hall_DW.obj_f.isSetupComplete = false;
    STMF4Hall_DW.obj_f.isInitialized = 1;
    STMF4Hall_PWMOutput_setupImpl(&STMF4Hall_DW.obj_f);
    STMF4Hall_DW.obj_f.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Timer1' */
    STMF4Hall_DW.obj_b.isInitialized = 0;
    STMF4Hall_DW.obj_b.matlabCodegenIsDeleted = false;
    STMF4Hall_SystemCore_setup_o(&STMF4Hall_DW.obj_b);

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* MATLABSystem: '<S103>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S105>/Digital Port Read' */
    pinReadLoc_0 = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S107>/Digital Port Read' */
    pinReadLoc_1 = LL_GPIO_ReadInputPort(GPIOC);

    /* Sum: '<S98>/Sum' incorporates:
     *  DataStoreWrite: '<S8>/Data Store Write'
     *  Gain: '<S98>/Gain'
     *  Gain: '<S98>/Gain1'
     *  Gain: '<S98>/Gain2'
     *  MATLABSystem: '<S103>/Digital Port Read'
     *  MATLABSystem: '<S105>/Digital Port Read'
     *  MATLABSystem: '<S107>/Digital Port Read'
     * */
    STMF4Hall_DW.GlobalHallState = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) !=
      0U ? STMF4Hall_P.Gain_Gain_m >> 5 : 0) + (uint32_T)((pinReadLoc_0 & 2048U)
      != 0U ? STMF4Hall_P.Gain1_Gain_p >> 6 : 0)) + (uint32_T)((pinReadLoc_1 &
      4096U) != 0U ? STMF4Hall_P.Gain2_Gain_n >> 7 : 0));

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void STMF4Hall_terminate(void)
{
  /* Terminate for MATLABSystem: '<S109>/PWM Output' */
  if (!STMF4Hall_DW.obj_f.matlabCodegenIsDeleted) {
    STMF4Hall_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((STMF4Hall_DW.obj_f.isInitialized == 1) &&
        STMF4Hall_DW.obj_f.isSetupComplete) {
      disableCounter(STMF4Hall_DW.obj_f.TimerHandle);
      disableTimerInterrupts(STMF4Hall_DW.obj_f.TimerHandle, 0);
      disableTimerChannel1(STMF4Hall_DW.obj_f.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(STMF4Hall_DW.obj_f.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(STMF4Hall_DW.obj_f.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S109>/PWM Output' */
  /* Terminate for MATLABSystem: '<Root>/Timer1' */
  if (!STMF4Hall_DW.obj_b.matlabCodegenIsDeleted) {
    STMF4Hall_DW.obj_b.matlabCodegenIsDeleted = true;
    if ((STMF4Hall_DW.obj_b.isInitialized == 1) &&
        STMF4Hall_DW.obj_b.isSetupComplete) {
      disableCounter(STMF4Hall_DW.obj_b.TimerHandle);
      disableTimerInterrupts(STMF4Hall_DW.obj_b.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Timer1' */
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S97>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S97>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem3'
   */
  /* Termination for function-call system: '<Root>/Function-Call Subsystem3' */

  /* Terminate for MATLABSystem: '<S91>/Analog to Digital Converter' */
  if (!STMF4Hall_DW.obj.matlabCodegenIsDeleted) {
    STMF4Hall_DW.obj.matlabCodegenIsDeleted = true;
    if ((STMF4Hall_DW.obj.isInitialized == 1) &&
        STMF4Hall_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(STMF4Hall_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S91>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S97>/Hardware Interrupt' */
}

void STMF4Hall_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(55,&EXTI15_10_IRQHandler,2);
  MW_NVIC_EnableIRQ(55);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S95>/Hardware Interrupt' */
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
        /* Reset subsysRan breadcrumbs */
        srClearBC
          (STMF4Hall_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (STMF4Hall_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.ValidHalls.ValidHalls_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (STMF4Hall_DW.Badhallglitchorwrongconnection.Badhallglitchorwrongconnection_);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.FunctionCallSubsystem2_SubsysRa);

        /* RateTransition generated from: '<Root>/Function-Call Subsystem2' */
        STMF4Hall_B.time3 = STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem2I;

        /* S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem2' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick2 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S83>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S85>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S87>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S64>/Sum' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  Gain: '<S64>/Gain'
           *  Gain: '<S64>/Gain1'
           *  Gain: '<S64>/Gain2'
           *  MATLABSystem: '<S83>/Digital Port Read'
           *  MATLABSystem: '<S85>/Digital Port Read'
           *  MATLABSystem: '<S87>/Digital Port Read'
           * */
          STMF4Hall_DW.GlobalHallState = (uint8_T)(((uint32_T)((pinReadLoc &
            1024U) != 0U ? STMF4Hall_P.Gain_Gain >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain >> 6 : 0)) +
            (uint32_T)((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain >>
                       7 : 0));

          /* SwitchCase: '<S63>/Detects if the halls reading is valid' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  DataTypeConversion: '<S63>/Data Type Conversion1'
           */
          switch (STMF4Hall_DW.GlobalHallState) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S66>/Valid Halls' incorporates:
             *  ActionPort: '<S68>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S63>/Data Type Conversion2'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.GlobalHallState,
                                 (uint16_T)STMF4Hall_DW.GlobalHallState,
                                 STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
                                 &STMF4Hall_DW.GlobalDirection, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls,
                                 &STMF4Hall_DW.ValidHalls,
                                 &STMF4Hall_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S66>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S66>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S67>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(STMF4Hall_DW.GlobalDirection, &rtb_Merge,
              &STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnection);

            /* End of Outputs for SubSystem: '<S66>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S63>/Detects if the halls reading is valid' */

          /* Sum: '<S4>/Sum' incorporates:
           *  DataStoreRead: '<S4>/Data Store Read1'
           *  DataTypeConversion: '<S4>/Data Type Conversion'
           *  DataTypeConversion: '<S4>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum_i = (int16_T)((int16_T)STMF4Hall_B.time3 - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataTypeConversion: '<S63>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           */
          STMF4Hall_DW.GlobalSpeedCount = (uint16_T)STMF4Hall_B.Sum_i;

          /* DataTypeConversion: '<S66>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          STMF4Hall_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S63>/Constant'
           */
          STMF4Hall_DW.HallStateChangeFlag = STMF4Hall_P.Constant_Value_fm;

          /* DataStoreWrite: '<S65>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum_i;

          /* DataStoreWrite: '<S65>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3;

          /* SignalConversion generated from: '<S4>/Out2' incorporates:
           *  Constant: '<S4>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2_e2 = STMF4Hall_P.Constant_Value;
          STMF4Hall_DW.FunctionCallSubsystem2_SubsysRa = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((STMF4Hall_M->Timing.clockTick2) *
        5.0E-5);
      extmodeEvent(2,currentTime);
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
        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.FunctionCallSubsystem1_SubsysRa);

        /* RateTransition generated from: '<Root>/Function-Call Subsystem1' */
        STMF4Hall_B.time3_g = STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem1I;

        /* S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick3 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S58>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S60>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S62>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S39>/Sum' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  Gain: '<S39>/Gain'
           *  Gain: '<S39>/Gain1'
           *  Gain: '<S39>/Gain2'
           *  MATLABSystem: '<S58>/Digital Port Read'
           *  MATLABSystem: '<S60>/Digital Port Read'
           *  MATLABSystem: '<S62>/Digital Port Read'
           * */
          STMF4Hall_DW.GlobalHallState = (uint8_T)(((uint32_T)((pinReadLoc &
            1024U) != 0U ? STMF4Hall_P.Gain_Gain_n >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain_l >> 6 : 0))
            + (uint32_T)((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain_d
                         >> 7 : 0));

          /* SwitchCase: '<S38>/Detects if the halls reading is valid' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  DataTypeConversion: '<S38>/Data Type Conversion1'
           */
          switch (STMF4Hall_DW.GlobalHallState) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S41>/Valid Halls' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S38>/Data Type Conversion2'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.GlobalHallState,
                                 (uint16_T)STMF4Hall_DW.GlobalHallState,
                                 STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
                                 &STMF4Hall_DW.GlobalDirection, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls_l,
                                 &STMF4Hall_DW.ValidHalls_l,
                                 &STMF4Hall_P.ValidHalls_l);

            /* End of Outputs for SubSystem: '<S41>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S41>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S42>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(STMF4Hall_DW.GlobalDirection, &rtb_Merge,
              &STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnectio_c);

            /* End of Outputs for SubSystem: '<S41>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S38>/Detects if the halls reading is valid' */

          /* Sum: '<S3>/Sum' incorporates:
           *  DataStoreRead: '<S3>/Data Store Read1'
           *  DataTypeConversion: '<S3>/Data Type Conversion'
           *  DataTypeConversion: '<S3>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum_c = (int16_T)((int16_T)STMF4Hall_B.time3_g - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataTypeConversion: '<S38>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           */
          STMF4Hall_DW.GlobalSpeedCount = (uint16_T)STMF4Hall_B.Sum_c;

          /* DataTypeConversion: '<S41>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          STMF4Hall_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S38>/Constant'
           */
          STMF4Hall_DW.HallStateChangeFlag = STMF4Hall_P.Constant_Value_d;

          /* DataStoreWrite: '<S40>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum_c;

          /* DataStoreWrite: '<S40>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3_g;

          /* SignalConversion generated from: '<S3>/Out2' incorporates:
           *  Constant: '<S3>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2_e = STMF4Hall_P.Constant_Value_p;
          STMF4Hall_DW.FunctionCallSubsystem1_SubsysRa = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((STMF4Hall_M->Timing.clockTick3) *
        5.0E-5);
      extmodeEvent(3,currentTime);
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
        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.FunctionCallSubsystem_SubsysRan);

        /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
        STMF4Hall_B.time3_gw = STMF4Hall_DW.time3_Buffer0;

        /* S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick4 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S33>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S35>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S37>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S14>/Sum' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  Gain: '<S14>/Gain'
           *  Gain: '<S14>/Gain1'
           *  Gain: '<S14>/Gain2'
           *  MATLABSystem: '<S33>/Digital Port Read'
           *  MATLABSystem: '<S35>/Digital Port Read'
           *  MATLABSystem: '<S37>/Digital Port Read'
           * */
          STMF4Hall_DW.GlobalHallState = (uint8_T)(((uint32_T)((pinReadLoc &
            1024U) != 0U ? STMF4Hall_P.Gain_Gain_a >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain_i >> 6 : 0))
            + (uint32_T)((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain_f
                         >> 7 : 0));

          /* SwitchCase: '<S13>/Detects if the halls reading is valid' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  DataTypeConversion: '<S13>/Data Type Conversion1'
           */
          switch (STMF4Hall_DW.GlobalHallState) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S16>/Valid Halls' incorporates:
             *  ActionPort: '<S18>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S13>/Data Type Conversion2'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.GlobalHallState,
                                 (uint16_T)STMF4Hall_DW.GlobalHallState,
                                 STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
                                 &STMF4Hall_DW.GlobalDirection, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls_d,
                                 &STMF4Hall_DW.ValidHalls_d,
                                 &STMF4Hall_P.ValidHalls_d);

            /* End of Outputs for SubSystem: '<S16>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S16>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S17>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(STMF4Hall_DW.GlobalDirection, &rtb_Merge,
              &STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnectio_a);

            /* End of Outputs for SubSystem: '<S16>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S13>/Detects if the halls reading is valid' */

          /* Sum: '<S2>/Sum' incorporates:
           *  DataStoreRead: '<S2>/Data Store Read1'
           *  DataTypeConversion: '<S2>/Data Type Conversion'
           *  DataTypeConversion: '<S2>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum = (int16_T)((int16_T)STMF4Hall_B.time3_gw - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataTypeConversion: '<S13>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           */
          STMF4Hall_DW.GlobalSpeedCount = (uint16_T)STMF4Hall_B.Sum;

          /* DataTypeConversion: '<S16>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          STMF4Hall_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S13>/Constant'
           */
          STMF4Hall_DW.HallStateChangeFlag = STMF4Hall_P.Constant_Value_bh;

          /* DataStoreWrite: '<S15>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum;

          /* DataStoreWrite: '<S15>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3_gw;

          /* SignalConversion generated from: '<S2>/Out2' incorporates:
           *  Constant: '<S2>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2 = STMF4Hall_P.Constant_Value_f;
          STMF4Hall_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S95>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((STMF4Hall_M->Timing.clockTick4) *
        5.0E-5);
      extmodeEvent(4,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

/* Hardware Interrupt Block: '<S97>/Hardware Interrupt' */
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
        srClearBC(STMF4Hall_DW.FunctionCallSubsystem3_SubsysRa);

        /* S-Function (HardwareInterrupt_sfun): '<S97>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem3' */
        {
          uint16_T tmp[2];
          STMF4Hall_M->Timing.clockTick5 = STMF4Hall_M->Timing.clockTick0;

          /* UnitDelay: '<S89>/Output' */
          STMF4Hall_B.Output = STMF4Hall_DW.Output_DSTATE;

          /* Sum: '<S92>/FixPt Sum1' incorporates:
           *  Constant: '<S92>/FixPt Constant'
           */
          STMF4Hall_DW.Output_DSTATE = (uint16_T)((uint32_T)STMF4Hall_B.Output +
            STMF4Hall_P.FixPtConstant_Value);

          /* MATLABSystem: '<S91>/Analog to Digital Converter' */
          injectedReadADCIntr(STMF4Hall_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* Switch: '<S93>/FixPt Switch' */
          if (STMF4Hall_DW.Output_DSTATE > STMF4Hall_P.WrapToZero_Threshold) {
            /* Sum: '<S92>/FixPt Sum1' incorporates:
             *  Constant: '<S93>/Constant'
             *  UnitDelay: '<S89>/Output'
             */
            STMF4Hall_DW.Output_DSTATE = STMF4Hall_P.Constant_Value_o;
          }

          /* End of Switch: '<S93>/FixPt Switch' */
          STMF4Hall_DW.FunctionCallSubsystem3_SubsysRa = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S97>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((STMF4Hall_M->Timing.clockTick5) *
        5.0E-5);
      extmodeEvent(5,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void STMF4Hall_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(55);
  MW_NVIC_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
