/*
 * File: G431debug.c
 *
 * Code generated for Simulink model 'G431debug'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct 22 16:35:15 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G431debug.h"
#include "rtwtypes.h"
#include "G431debug_types.h"
#include "G431debug_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "arm_math.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "stm_timer_ll.h"
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_G431debug_T G431debug_B;

/* Block states (default storage) */
DW_G431debug_T G431debug_DW;

/* Real-time model */
static RT_MODEL_G431debug_T G431debug_M_;
RT_MODEL_G431debug_T *const G431debug_M = &G431debug_M_;

/* Forward declaration for local functions */
static void G431debug_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void G431debug_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_G4_T *obj);

/* Forward declaration for local functions */
static void G431debug_SystemCore_setup_i(stm32cube_blocks_TimerCapture_T *obj);

/* Forward declaration for local functions */
static void G431debug_SystemCore_setup_g(stm32cube_blocks_TimerCapture_T *obj);

/* Forward declaration for local functions */
static void G431debug_SystemCore_setup_i2(stm32cube_blocks_TimerCapture_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void G431debug_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(G431debug_M, 1));
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
  (G431debug_M->Timing.TaskCounters.TID[1])++;
  if ((G431debug_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    G431debug_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void G431debug_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
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

static void G431debug_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_G4_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S47>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S47>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S47>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/*
 * Output and update for action system:
 *    '<S98>/If Action Subsystem6'
 *    '<S98>/If Action Subsystem7'
 *    '<S73>/If Action Subsystem6'
 *    '<S73>/If Action Subsystem7'
 *    '<S123>/If Action Subsystem6'
 *    '<S123>/If Action Subsystem7'
 */
void G431debu_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_G431debu_T *localP)
{
  /* SignalConversion generated from: '<S105>/direction' incorporates:
   *  Constant: '<S105>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S105>/sequence_check' incorporates:
   *  Constant: '<S105>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S98>/If Action Subsystem'
 *    '<S98>/If Action Subsystem1'
 *    '<S98>/If Action Subsystem2'
 *    '<S98>/If Action Subsystem3'
 *    '<S98>/If Action Subsystem4'
 *    '<S98>/If Action Subsystem5'
 *    '<S73>/If Action Subsystem'
 *    '<S73>/If Action Subsystem1'
 *    '<S73>/If Action Subsystem2'
 *    '<S73>/If Action Subsystem3'
 *    ...
 */
void G431debug_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_G431debug_T *localP)
{
  /* SignalConversion generated from: '<S99>/Out1' incorporates:
   *  Constant: '<S99>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S99>/Out2' incorporates:
   *  Constant: '<S99>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S96>/Valid Halls'
 *    '<S71>/Valid Halls'
 *    '<S121>/Valid Halls'
 */
void G431debug_ValidHalls_Init(B_ValidHalls_G431debug_T *localB,
  P_ValidHalls_G431debug_T *localP)
{
  /* SystemInitialize for Merge: '<S98>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S98>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S98>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S98>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S96>/Valid Halls'
 *    '<S71>/Valid Halls'
 *    '<S121>/Valid Halls'
 */
void G431debug_ValidHalls(uint16_T rtu_hallReading, uint16_T rtu_previousState,
  int16_T rtu_previous_direction, boolean_T *rty_directional_speed_valid_fla,
  int16_T *rty_direction, uint16_T *rty_inValidHall, B_ValidHalls_G431debug_T
  *localB, DW_ValidHalls_G431debug_T *localDW, P_ValidHalls_G431debug_T *localP)
{
  /* SwitchCase: '<S98>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S100>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S102>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S103>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S104>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem5' */
    break;

   default:
    /* Update for IfAction SubSystem: '<S98>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S108>/Action Port'
     */
    /* Update for SwitchCase: '<S98>/Switch Case' */
    localDW->SwitchCaseActionSubsystem_Subsy = 4;

    /* End of Update for SubSystem: '<S98>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S98>/Switch Case' */

  /* If: '<S98>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S105>/Action Port'
     */
    G431debu_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S106>/Action Port'
     */
    G431debu_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S98>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    /* Merge: '<S98>/Merge3' incorporates:
     *  Constant: '<S107>/Constant'
     *  SignalConversion generated from: '<S107>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S98>/If Action Subsystem8' */

    /* Update for IfAction SubSystem: '<S98>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S107>/Action Port'
     */
    /* Update for If: '<S98>/If' */
    localDW->IfActionSubsystem8_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S98>/If Action Subsystem8' */
  }

  /* End of If: '<S98>/If' */

  /* SignalConversion: '<S98>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S98>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S98>/Switch' incorporates:
   *  Constant: '<S98>/Constant'
   *  RelationalOperator: '<S98>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_k;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S98>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S96>/Bad hall (glitch or wrong connection)'
 *    '<S71>/Bad hall (glitch or wrong connection)'
 *    '<S121>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S97>/inValidHall' incorporates:
   *  Constant: '<S97>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S97>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S97>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S97>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

static void G431debug_SystemCore_setup_i(stm32cube_blocks_TimerCapture_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S86>/Timer Capture' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S86>/Timer Capture' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 26);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S86>/Timer Capture' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void G431debug_SystemCore_setup_g(stm32cube_blocks_TimerCapture_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S61>/Timer Capture' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S61>/Timer Capture' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 26);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S61>/Timer Capture' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void G431debug_SystemCore_setup_i2(stm32cube_blocks_TimerCapture_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S111>/Timer Capture' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S111>/Timer Capture' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 26);
  enableTimerChannel4(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S111>/Timer Capture' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void G431debug_step0(void)             /* Sample time: [0.001s, 0.0s] */
{
  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/Rate Transition1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  G431debug_B.HallCt = G431debug_DW.Timehall;

  /* RateTransition: '<Root>/Rate Transition' */
  G431debug_B.testct = G431debug_B.Output;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  G431debug_M->Timing.taskTime0 =
    ((time_T)(++G431debug_M->Timing.clockTick0)) * G431debug_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void G431debug_step1(void)             /* Sample time: [0.1s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_LED;
  int32_T c;

  /* DiscretePulseGenerator: '<S7>/Pulse Generator' */
  rtb_LED = (G431debug_DW.clockTickCounter < G431debug_P.PulseGenerator_Duty) &&
    (G431debug_DW.clockTickCounter >= 0) ? G431debug_P.PulseGenerator_Amp : 0.0;
  if (G431debug_DW.clockTickCounter >= G431debug_P.PulseGenerator_Period - 1.0)
  {
    G431debug_DW.clockTickCounter = 0;
  } else {
    G431debug_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S7>/Pulse Generator' */

  /* MATLABSystem: '<S140>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_LED != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S140>/Digital Port Write' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  G431debug_M->Timing.clockTick1++;
}

/* Model initialize function */
void G431debug_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(G431debug_M, -1);
  G431debug_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  G431debug_M->Sizes.checksums[0] = (1557891672U);
  G431debug_M->Sizes.checksums[1] = (3580741757U);
  G431debug_M->Sizes.checksums[2] = (875575437U);
  G431debug_M->Sizes.checksums[3] = (2369608380U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[81];
    G431debug_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[2] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[3] = (sysRanDType *)&G431debug_DW.Subsystem_SubsysRanBC_m;
    systemRan[4] = (sysRanDType *)&G431debug_DW.IfActionSubsystem_SubsysRanBC_n;
    systemRan[5] = (sysRanDType *)&G431debug_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&G431debug_DW.Subsystem_SubsysRanBC_o;
    systemRan[7] = (sysRanDType *)&G431debug_DW.Accumulate_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&G431debug_DW.UpCounter_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&G431debug_DW.PosGen_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&G431debug_DW.Subsystem_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&G431debug_DW.Subsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&G431debug_DW.Subsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&G431debug_DW.FindOffset_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&G431debug_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&G431debug_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[17] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[18] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[19] = (sysRanDType *)&G431debug_DW.Subsystem1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[21] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[22] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[23] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[24] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[25] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &G431debug_DW.Badhallglitchorwrongconnectio_f.Badhallglitchorwrongconnection_;
    systemRan[27] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem8_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.SwitchCaseActionSubsystem_Subsy;
    systemRan[37] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[39] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[40] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[41] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[42] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[43] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[44] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &G431debug_DW.Badhallglitchorwrongconnection.Badhallglitchorwrongconnection_;
    systemRan[46] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[49] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[52] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[53] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[54] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC;
    systemRan[55] = (sysRanDType *)
      &G431debug_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy;
    systemRan[56] = (sysRanDType *)
      &G431debug_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[57] = (sysRanDType *)
      &G431debug_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &G431debug_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[59] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[60] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[61] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[62] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[63] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &G431debug_DW.Badhallglitchorwrongconnectio_n.Badhallglitchorwrongconnection_;
    systemRan[65] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[67] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[69] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[70] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[71] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[73] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem8_SubsysRanBC;
    systemRan[74] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.SwitchCaseActionSubsystem_Subsy;
    systemRan[75] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[76] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[77] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[78] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[79] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[80] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(G431debug_M->extModeInfo,
      &G431debug_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(G431debug_M->extModeInfo, G431debug_M->Sizes.checksums);
    rteiSetTPtr(G431debug_M->extModeInfo, rtmGetTPtr(G431debug_M));
  }

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  G431debug_DW.Timehall = G431debug_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  G431debug_DW.GlobalHallState = G431debug_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  G431debug_DW.Timercntprev = G431debug_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  G431debug_DW.HallAcapture = G431debug_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  G431debug_DW.GlobalDirection = G431debug_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  G431debug_DW.GlobalSpeedCount = G431debug_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  G431debug_DW.GlobalSpeedValidity = G431debug_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  G431debug_DW.HallStateChangeFlag = G431debug_P.DataStoreMemory8_InitialValue;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  G431debug_M->Timing.clockTick2 = G431debug_M->Timing.clockTick0;

  /* InitializeConditions for UnitDelay: '<S9>/Output' */
  G431debug_DW.Output_DSTATE = G431debug_P.Output_InitialCondition;

  /* SystemInitialize for Enabled SubSystem: '<S10>/PosGen' */
  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
  G431debug_DW.UnitDelay_DSTATE_i = G431debug_P.UnitDelay_InitialCondition_a;

  /* SystemInitialize for IfAction SubSystem: '<S21>/If Action Subsystem2' */
  /* InitializeConditions for Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' incorporates:
   *  Delay: '<S24>/Delay'
   */
  G431debug_DW.Delay_DSTATE_g = G431debug_P.Delay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S21>/If Action Subsystem2' */

  /* SystemInitialize for Enabled SubSystem: '<S25>/Accumulate' */
  /* InitializeConditions for Delay: '<S26>/Delay' */
  G431debug_DW.Delay_DSTATE_p = G431debug_P.Delay_InitialCondition_f;

  /* SystemInitialize for Enabled SubSystem: '<S26>/Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S27>/Input' incorporates:
   *  Outport: '<S27>/Out1'
   */
  G431debug_B.Input = G431debug_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S26>/Subsystem' */

  /* SystemInitialize for Sum: '<S26>/Add1' incorporates:
   *  Outport: '<S26>/theta_e'
   */
  G431debug_B.Add1_j = G431debug_P.theta_e_Y0;

  /* End of SystemInitialize for SubSystem: '<S25>/Accumulate' */

  /* SystemInitialize for Enabled SubSystem: '<S16>/Up Counter' */
  /* InitializeConditions for Delay: '<S22>/Delay' */
  G431debug_DW.Delay_DSTATE_h = G431debug_P.Delay_InitialCondition_e;

  /* SystemInitialize for Sum: '<S22>/Add1' incorporates:
   *  Outport: '<S22>/Count'
   */
  G431debug_B.Add1_c = G431debug_P.Count_Y0;

  /* End of SystemInitialize for SubSystem: '<S16>/Up Counter' */

  /* SystemInitialize for Gain: '<S25>/scaleOut' incorporates:
   *  Outport: '<S16>/Theta'
   */
  G431debug_B.scaleOut = G431debug_P.Theta_Y0;

  /* SystemInitialize for RelationalOperator: '<S19>/Compare' incorporates:
   *  Outport: '<S16>/EnPWM'
   */
  G431debug_B.Compare = G431debug_P.EnPWM_Y0;

  /* End of SystemInitialize for SubSystem: '<S10>/PosGen' */

  /* SystemInitialize for Enabled SubSystem: '<S11>/Find Offset' */
  /* InitializeConditions for Delay: '<S28>/Delay' */
  G431debug_DW.Delay_DSTATE = G431debug_P.Delay_InitialCondition_b;

  /* SystemInitialize for Enabled SubSystem: '<S28>/Subsystem' */
  /* InitializeConditions for UnitDelay: '<S39>/Unit Delay' */
  G431debug_DW.UnitDelay_DSTATE = G431debug_P.UnitDelay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S28>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S11>/Find Offset' */

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  G431debug_DW.obj.isInitialized = 0;
  G431debug_DW.obj.matlabCodegenIsDeleted = false;
  G431debug_SystemCore_setup(&G431debug_DW.obj);

  /* Start for MATLABSystem: '<S47>/PWM Output' */
  G431debug_DW.obj_i.matlabCodegenIsDeleted = false;
  G431debug_DW.obj_i.isSetupComplete = false;
  G431debug_DW.obj_i.isInitialized = 1;
  G431debug_PWMOutput_setupImpl(&G431debug_DW.obj_i);
  G431debug_DW.obj_i.isSetupComplete = true;

  /* SystemInitialize for UnitDelay: '<S9>/Output' incorporates:
   *  Outport: '<S1>/ct'
   */
  G431debug_B.Output = G431debug_P.ct_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_B'
   */
  /* System initialize for function-call system: '<Root>/HALL_B' */
  G431debug_M->Timing.clockTick3 = G431debug_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S86>/Delay' */
  G431debug_DW.Delay_DSTATE_k = G431debug_P.Delay_InitialCondition_i;

  /* SystemInitialize for IfAction SubSystem: '<S96>/Valid Halls' */
  G431debug_ValidHalls_Init(&G431debug_B.ValidHalls, &G431debug_P.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S96>/Valid Halls' */

  /* Start for MATLABSystem: '<S86>/Timer Capture' */
  G431debug_DW.obj_k.isInitialized = 0;
  G431debug_DW.obj_k.matlabCodegenIsDeleted = false;
  G431debug_SystemCore_setup_i(&G431debug_DW.obj_k);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_A'
   */
  /* System initialize for function-call system: '<Root>/HALL_A' */
  G431debug_M->Timing.clockTick4 = G431debug_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S61>/Delay' */
  G431debug_DW.Delay_DSTATE_d = G431debug_P.Delay_InitialCondition_c;

  /* SystemInitialize for IfAction SubSystem: '<S71>/Valid Halls' */
  G431debug_ValidHalls_Init(&G431debug_B.ValidHalls_p, &G431debug_P.ValidHalls_p);

  /* End of SystemInitialize for SubSystem: '<S71>/Valid Halls' */

  /* Start for MATLABSystem: '<S61>/Timer Capture' */
  G431debug_DW.obj_a.isInitialized = 0;
  G431debug_DW.obj_a.matlabCodegenIsDeleted = false;
  G431debug_SystemCore_setup_g(&G431debug_DW.obj_a);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_C'
   */

  /* System initialize for function-call system: '<Root>/HALL_C' */
  G431debug_M->Timing.clockTick5 = G431debug_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S111>/Delay' */
  G431debug_DW.Delay_DSTATE_m = G431debug_P.Delay_InitialCondition_h;

  /* SystemInitialize for IfAction SubSystem: '<S121>/Valid Halls' */
  G431debug_ValidHalls_Init(&G431debug_B.ValidHalls_b, &G431debug_P.ValidHalls_b);

  /* End of SystemInitialize for SubSystem: '<S121>/Valid Halls' */

  /* Start for MATLABSystem: '<S111>/Timer Capture' */
  G431debug_DW.obj_p.isInitialized = 0;
  G431debug_DW.obj_p.matlabCodegenIsDeleted = false;
  G431debug_SystemCore_setup_i2(&G431debug_DW.obj_p);

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' */
}

/* Model terminate function */
void G431debug_terminate(void)
{
  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  if (!G431debug_DW.obj.matlabCodegenIsDeleted) {
    G431debug_DW.obj.matlabCodegenIsDeleted = true;
    if ((G431debug_DW.obj.isInitialized == 1) &&
        G431debug_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(G431debug_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S47>/PWM Output' */
  if (!G431debug_DW.obj_i.matlabCodegenIsDeleted) {
    G431debug_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((G431debug_DW.obj_i.isInitialized == 1) &&
        G431debug_DW.obj_i.isSetupComplete) {
      disableCounter(G431debug_DW.obj_i.TimerHandle);
      disableTimerInterrupts(G431debug_DW.obj_i.TimerHandle, 0);
      disableTimerChannel1(G431debug_DW.obj_i.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(G431debug_DW.obj_i.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(G431debug_DW.obj_i.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S47>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_B'
   */
  /* Termination for function-call system: '<Root>/HALL_B' */

  /* Terminate for MATLABSystem: '<S86>/Timer Capture' */
  if (!G431debug_DW.obj_k.matlabCodegenIsDeleted) {
    G431debug_DW.obj_k.matlabCodegenIsDeleted = true;
    if ((G431debug_DW.obj_k.isInitialized == 1) &&
        G431debug_DW.obj_k.isSetupComplete) {
      disableCounter(G431debug_DW.obj_k.TimerHandle);
      disableTimerInterrupts(G431debug_DW.obj_k.TimerHandle, 26);
      disableTimerChannel1(G431debug_DW.obj_k.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S86>/Timer Capture' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_A'
   */
  /* Termination for function-call system: '<Root>/HALL_A' */

  /* Terminate for MATLABSystem: '<S61>/Timer Capture' */
  if (!G431debug_DW.obj_a.matlabCodegenIsDeleted) {
    G431debug_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((G431debug_DW.obj_a.isInitialized == 1) &&
        G431debug_DW.obj_a.isSetupComplete) {
      disableCounter(G431debug_DW.obj_a.TimerHandle);
      disableTimerInterrupts(G431debug_DW.obj_a.TimerHandle, 26);
      disableTimerChannel3(G431debug_DW.obj_a.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S61>/Timer Capture' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_C'
   */

  /* Termination for function-call system: '<Root>/HALL_C' */

  /* Terminate for MATLABSystem: '<S111>/Timer Capture' */
  if (!G431debug_DW.obj_p.matlabCodegenIsDeleted) {
    G431debug_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((G431debug_DW.obj_p.isInitialized == 1) &&
        G431debug_DW.obj_p.isSetupComplete) {
      disableCounter(G431debug_DW.obj_p.TimerHandle);
      disableTimerInterrupts(G431debug_DW.obj_p.TimerHandle, 26);
      disableTimerChannel4(G431debug_DW.obj_p.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S111>/Timer Capture' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' */
}

void G431debug_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC1_2_IRQHandler,3);
  MW_NVIC_EnableIRQ(33);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(44,&TIM3_IRQHandler,2);
  MW_NVIC_EnableIRQ(44);
}

/* Hardware Interrupt Block: '<S135>/Hardware Interrupt' */
void ADC1_2_IRQHandler(void)
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
        srClearBC(G431debug_DW.Subsystem_SubsysRanBC_m);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.IfActionSubsystem_SubsysRanBC_n);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.IfActionSubsystem2_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.Subsystem_SubsysRanBC_o);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.Accumulate_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.UpCounter_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.PosGen_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.Subsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.FindOffset_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.IfActionSubsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.Subsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.FunctionCallSubsystem_SubsysRan);

        /* S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          real_T rtb_Switch4_idx_0;
          real_T rtb_Switch4_idx_1;
          real_T rtb_Switch4_idx_2;
          real32_T rtb_Add1_e;
          real32_T rtb_Add_h;
          real32_T rtb_Merge;
          real32_T rtb_algDD_o2;
          real32_T rtb_sum_beta;
          uint16_T tmp[3];
          uint16_T rtb_Get_Integer;
          G431debug_M->Timing.clockTick2 = G431debug_M->Timing.clockTick0;

          /* MATLABSystem: '<S13>/Analog to Digital Converter' */
          injectedReadADCIntr(G431debug_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* UnitDelay: '<S9>/Output' */
          G431debug_B.Output = G431debug_DW.Output_DSTATE;

          /* Sum: '<S14>/FixPt Sum1' incorporates:
           *  Constant: '<S14>/FixPt Constant'
           */
          rtb_Get_Integer = (uint16_T)((uint32_T)G431debug_B.Output +
            G431debug_P.FixPtConstant_Value);

          /* Switch: '<S15>/FixPt Switch' */
          if (rtb_Get_Integer > G431debug_P.WrapToZero_Threshold) {
            /* Update for UnitDelay: '<S9>/Output' incorporates:
             *  Constant: '<S15>/Constant'
             */
            G431debug_DW.Output_DSTATE = G431debug_P.Constant_Value_l;
          } else {
            /* Update for UnitDelay: '<S9>/Output' */
            G431debug_DW.Output_DSTATE = rtb_Get_Integer;
          }

          /* End of Switch: '<S15>/FixPt Switch' */

          /* Outputs for Enabled SubSystem: '<S10>/PosGen' incorporates:
           *  EnablePort: '<S16>/Enable'
           */
          /* Constant: '<S1>/Constant1' */
          if (G431debug_P.Constant1_Value_d > 0.0) {
            if (!G431debug_DW.PosGen_MODE) {
              /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
              G431debug_DW.UnitDelay_DSTATE_i =
                G431debug_P.UnitDelay_InitialCondition_a;
              G431debug_DW.PosGen_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S16>/Up Counter' incorporates:
             *  EnablePort: '<S22>/Enable'
             */
            if (G431debug_P.Constant1_Value_d > 0.0) {
              uint64_T tmp_p;
              if (!G431debug_DW.UpCounter_MODE) {
                /* InitializeConditions for Delay: '<S22>/Delay' */
                G431debug_DW.Delay_DSTATE_h =
                  G431debug_P.Delay_InitialCondition_e;
                G431debug_DW.UpCounter_MODE = true;
              }

              /* Sum: '<S22>/Add1' incorporates:
               *  Constant: '<S22>/Constant'
               *  Delay: '<S22>/Delay'
               */
              tmp_p = (uint64_T)G431debug_P.Constant_Value_j +
                G431debug_DW.Delay_DSTATE_h;
              if (tmp_p > 4294967295ULL) {
                tmp_p = 4294967295ULL;
              }

              /* Sum: '<S22>/Add1' */
              G431debug_B.Add1_c = (uint32_T)tmp_p;

              /* Update for Delay: '<S22>/Delay' */
              G431debug_DW.Delay_DSTATE_h = G431debug_B.Add1_c;
              G431debug_DW.UpCounter_SubsysRanBC = 4;
            } else if (G431debug_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S22>/Add1' incorporates:
               *  Outport: '<S22>/Count'
               */
              G431debug_B.Add1_c = G431debug_P.Count_Y0;
              G431debug_DW.UpCounter_MODE = false;
            }

            /* End of Outputs for SubSystem: '<S16>/Up Counter' */

            /* RelationalOperator: '<S19>/Compare' incorporates:
             *  Constant: '<S19>/Constant'
             */
            G431debug_B.Compare = (G431debug_B.Add1_c <=
              G431debug_P.EnablePWMfor40seconds_const);

            /* If: '<S21>/If' incorporates:
             *  Constant: '<S21>/Count for 2 sec'
             */
            if (G431debug_B.Add1_c < G431debug_P.Countfor2sec_Value) {
              /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
               *  ActionPort: '<S23>/Action Port'
               */
              /* SignalConversion generated from: '<S23>/Out1' incorporates:
               *  Constant: '<S23>/Constant'
               */
              rtb_Merge = G431debug_P.Constant_Value;

              /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
               *  ActionPort: '<S23>/Action Port'
               */
              /* Update for If: '<S21>/If' */
              G431debug_DW.IfActionSubsystem_SubsysRanBC_n = 4;

              /* End of Update for SubSystem: '<S21>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S24>/Action Port'
               */
              /* Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' incorporates:
               *  Constant: '<S24>/Constant1'
               *  Delay: '<S24>/Delay'
               *  Sum: '<S24>/Add1'
               */
              G431debug_DW.Delay_DSTATE_g += G431debug_P.Constant1_Value_g;

              /* Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' */
              if (G431debug_DW.Delay_DSTATE_g >
                  G431debug_P.SaturatetomotorcalibSpeedRPM_Up) {
                /* Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' */
                G431debug_DW.Delay_DSTATE_g =
                  G431debug_P.SaturatetomotorcalibSpeedRPM_Up;
              } else if (G431debug_DW.Delay_DSTATE_g <
                         G431debug_P.SaturatetomotorcalibSpeedRPM_Lo) {
                /* Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' */
                G431debug_DW.Delay_DSTATE_g =
                  G431debug_P.SaturatetomotorcalibSpeedRPM_Lo;
              }

              /* End of Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' */

              /* Gain: '<S24>/Multiply' */
              rtb_Merge = G431debug_P.Multiply_Gain *
                G431debug_DW.Delay_DSTATE_g;

              /* End of Outputs for SubSystem: '<S21>/If Action Subsystem2' */

              /* Update for IfAction SubSystem: '<S21>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S24>/Action Port'
               */
              /* Update for If: '<S21>/If' */
              G431debug_DW.IfActionSubsystem2_SubsysRanBC = 4;

              /* End of Update for SubSystem: '<S21>/If Action Subsystem2' */
            }

            /* End of If: '<S21>/If' */

            /* Outputs for Enabled SubSystem: '<S25>/Accumulate' incorporates:
             *  EnablePort: '<S26>/Enable'
             */
            /* Logic: '<S25>/NOT' incorporates:
             *  Constant: '<S25>/Constant_Reset'
             *  Delay: '<S26>/Delay'
             */
            if (!G431debug_P.Constant_Reset_Value) {
              /* Outputs for Enabled SubSystem: '<S26>/Subsystem' incorporates:
               *  EnablePort: '<S27>/Enable'
               */
              if (G431debug_DW.Delay_DSTATE_p) {
                /* SignalConversion generated from: '<S27>/Input' incorporates:
                 *  Gain: '<S25>/scaleIn'
                 */
                G431debug_B.Input = G431debug_P.scaleIn_Gain * rtb_Merge;
                G431debug_DW.Subsystem_SubsysRanBC_o = 4;
              }

              /* End of Outputs for SubSystem: '<S26>/Subsystem' */

              /* Sum: '<S26>/Add' incorporates:
               *  Delay: '<S26>/Delay'
               *  UnitDelay: '<S25>/Unit Delay'
               */
              rtb_Add_h = G431debug_B.Input + G431debug_DW.UnitDelay_DSTATE_i;

              /* DataTypeConversion: '<S26>/Data Type Conversion' */
              rtb_Merge = floorf(rtb_Add_h);
              if (rtIsNaNF(rtb_Merge) || rtIsInfF(rtb_Merge)) {
                rtb_Merge = 0.0F;
              } else {
                rtb_Merge = fmodf(rtb_Merge, 65536.0F);
              }

              /* Sum: '<S26>/Add1' incorporates:
               *  DataTypeConversion: '<S26>/Data Type Conversion'
               *  DataTypeConversion: '<S26>/Data Type Conversion1'
               */
              G431debug_B.Add1_j = rtb_Add_h - (real32_T)(rtb_Merge < 0.0F ?
                (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Merge : (int32_T)
                (int16_T)(uint16_T)rtb_Merge);

              /* Update for Delay: '<S26>/Delay' incorporates:
               *  Constant: '<S26>/Constant'
               */
              G431debug_DW.Delay_DSTATE_p = G431debug_P.Constant_Value_f;
              G431debug_DW.Accumulate_SubsysRanBC = 4;
            }

            /* End of Logic: '<S25>/NOT' */
            /* End of Outputs for SubSystem: '<S25>/Accumulate' */

            /* Gain: '<S25>/scaleOut' */
            G431debug_B.scaleOut = G431debug_P.scaleOut_Gain *
              G431debug_B.Add1_j;

            /* Update for UnitDelay: '<S25>/Unit Delay' */
            G431debug_DW.UnitDelay_DSTATE_i = G431debug_B.Add1_j;
            G431debug_DW.PosGen_SubsysRanBC = 4;
          } else if (G431debug_DW.PosGen_MODE) {
            /* Disable for Enabled SubSystem: '<S16>/Up Counter' */
            if (G431debug_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S22>/Add1' incorporates:
               *  Outport: '<S22>/Count'
               */
              G431debug_B.Add1_c = G431debug_P.Count_Y0;
              G431debug_DW.UpCounter_MODE = false;
            }

            /* End of Disable for SubSystem: '<S16>/Up Counter' */

            /* Disable for RelationalOperator: '<S19>/Compare' incorporates:
             *  Outport: '<S16>/EnPWM'
             */
            G431debug_B.Compare = G431debug_P.EnPWM_Y0;
            G431debug_DW.PosGen_MODE = false;
          }

          /* End of Constant: '<S1>/Constant1' */
          /* End of Outputs for SubSystem: '<S10>/PosGen' */

          /* Gain: '<S41>/convert_pu' */
          rtb_Add_h = G431debug_P.convert_pu_Gain * G431debug_B.scaleOut;

          /* If: '<S41>/If' incorporates:
           *  Constant: '<S42>/Constant'
           *  RelationalOperator: '<S42>/Compare'
           */
          if (rtb_Add_h < G431debug_P.Constant_Value_d) {
            /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* DataTypeConversion: '<S43>/Convert_uint16' */
            rtb_Merge = floorf(rtb_Add_h);
            if (rtIsInfF(rtb_Merge)) {
              rtb_Merge = 0.0F;
            } else {
              rtb_Merge = fmodf(rtb_Merge, 65536.0F);
            }

            /* Sum: '<S43>/Sum' incorporates:
             *  DataTypeConversion: '<S43>/Convert_back'
             *  DataTypeConversion: '<S43>/Convert_uint16'
             */
            rtb_Add_h -= (real32_T)(rtb_Merge < 0.0F ? (int32_T)(int16_T)
              -(int16_T)(uint16_T)-rtb_Merge : (int32_T)(int16_T)(uint16_T)
              rtb_Merge);

            /* End of Outputs for SubSystem: '<S41>/If Action Subsystem' */

            /* Update for IfAction SubSystem: '<S41>/If Action Subsystem' incorporates:
             *  ActionPort: '<S43>/Action Port'
             */
            /* Update for If: '<S41>/If' */
            G431debug_DW.IfActionSubsystem_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S41>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S41>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S44>/Action Port'
             */
            /* DataTypeConversion: '<S44>/Convert_uint16' */
            rtb_Merge = truncf(rtb_Add_h);
            if (rtIsNaNF(rtb_Merge) || rtIsInfF(rtb_Merge)) {
              rtb_Merge = 0.0F;
            } else {
              rtb_Merge = fmodf(rtb_Merge, 65536.0F);
            }

            /* Sum: '<S44>/Sum' incorporates:
             *  DataTypeConversion: '<S44>/Convert_back'
             *  DataTypeConversion: '<S44>/Convert_uint16'
             */
            rtb_Add_h -= (real32_T)(rtb_Merge < 0.0F ? (int32_T)(int16_T)
              -(int16_T)(uint16_T)-rtb_Merge : (int32_T)(int16_T)(uint16_T)
              rtb_Merge);

            /* End of Outputs for SubSystem: '<S41>/If Action Subsystem1' */

            /* Update for IfAction SubSystem: '<S41>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S44>/Action Port'
             */
            /* Update for If: '<S41>/If' */
            G431debug_DW.IfActionSubsystem1_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S41>/If Action Subsystem1' */
          }

          /* End of If: '<S41>/If' */

          /* Gain: '<S29>/indexing' */
          rtb_Add_h *= G431debug_P.indexing_Gain;

          /* DataTypeConversion: '<S29>/Get_Integer' */
          rtb_Merge = truncf(rtb_Add_h);
          if (rtIsNaNF(rtb_Merge) || rtIsInfF(rtb_Merge)) {
            rtb_Merge = 0.0F;
          } else {
            rtb_Merge = fmodf(rtb_Merge, 65536.0F);
          }

          rtb_Get_Integer = (uint16_T)(rtb_Merge < 0.0F ? (int32_T)(uint16_T)
            -(int16_T)(uint16_T)-rtb_Merge : (int32_T)(uint16_T)rtb_Merge);

          /* End of DataTypeConversion: '<S29>/Get_Integer' */

          /* Sum: '<S29>/Sum2' incorporates:
           *  DataTypeConversion: '<S29>/Data Type Conversion1'
           */
          rtb_sum_beta = rtb_Add_h - (real32_T)rtb_Get_Integer;

          /* Selector: '<S29>/Lookup' incorporates:
           *  Constant: '<S29>/offset'
           *  Constant: '<S29>/sine_table_values'
           *  Sum: '<S29>/Sum'
           *  Sum: '<S40>/Sum3'
           *  Sum: '<S40>/Sum5'
           */
          rtb_Merge = G431debug_P.sine_table_values_Value[(int32_T)((uint32_T)
            G431debug_P.offset_Value[1] + rtb_Get_Integer)];
          rtb_Add1_e = G431debug_P.sine_table_values_Value[(int32_T)((uint32_T)
            G431debug_P.offset_Value[3] + rtb_Get_Integer)];

          /* Outputs for Atomic SubSystem: '<S48>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S50>/a16' incorporates:
           *  Constant: '<S29>/offset'
           *  Constant: '<S29>/sine_table_values'
           *  Constant: '<S32>/Vd_Ref'
           *  Constant: '<S32>/Vq'
           *  Product: '<S40>/Product'
           *  Product: '<S40>/Product1'
           *  Selector: '<S29>/Lookup'
           *  Sum: '<S29>/Sum'
           *  Sum: '<S40>/Sum3'
           *  Sum: '<S40>/Sum4'
           *  Sum: '<S40>/Sum5'
           *  Sum: '<S40>/Sum6'
           */
          arm_inv_park_f32(G431debug_P.Vd_Ref_Value, G431debug_P.Vq_Value,
                           &rtb_Add_h, &rtb_algDD_o2,
                           (G431debug_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)G431debug_P.offset_Value[0] +
                             rtb_Get_Integer)] - rtb_Merge) * rtb_sum_beta +
                           rtb_Merge, (G431debug_P.sine_table_values_Value
            [(int32_T)((uint32_T)G431debug_P.offset_Value[2] + rtb_Get_Integer)]
            - rtb_Add1_e) * rtb_sum_beta + rtb_Add1_e);

          /* End of Outputs for SubSystem: '<S48>/Two inputs CRL' */

          /* Switch: '<S30>/Switch4' incorporates:
           *  Constant: '<S30>/Constant1'
           *  Constant: '<S30>/stop'
           *  Gain: '<S30>/Gain'
           *  Gain: '<S30>/Gain1'
           *  Gain: '<S54>/Gain'
           *  Sum: '<S30>/Add'
           *  Sum: '<S54>/Add1'
           *  Sum: '<S54>/Add2'
           *  Sum: '<S54>/Add3'
           */
          if (G431debug_B.Compare) {
            /* Gain: '<S58>/sqrt3_by_two' */
            rtb_sum_beta = G431debug_P.sqrt3_by_two_Gain * rtb_algDD_o2;

            /* Gain: '<S58>/one_by_two' */
            rtb_Add1_e = G431debug_P.one_by_two_Gain * rtb_Add_h;

            /* Gain: '<S58>/Kc' incorporates:
             *  Sum: '<S58>/add_c'
             */
            rtb_Merge = ((0.0F - rtb_Add1_e) - rtb_sum_beta) *
              G431debug_P.Kc_Gain;

            /* Gain: '<S58>/Kb' incorporates:
             *  Sum: '<S58>/add_b'
             */
            rtb_Add1_e = (rtb_sum_beta - rtb_Add1_e) * G431debug_P.Kb_Gain;

            /* Gain: '<S58>/Ka' */
            rtb_sum_beta = G431debug_P.Ka_Gain * rtb_Add_h;

            /* Gain: '<S55>/one_by_two' incorporates:
             *  MinMax: '<S55>/Max'
             *  MinMax: '<S55>/Min'
             *  Sum: '<S55>/Add'
             */
            rtb_Add_h = (fmaxf(fmaxf(rtb_sum_beta, rtb_Add1_e), rtb_Merge) +
                         fminf(fminf(rtb_sum_beta, rtb_Add1_e), rtb_Merge)) *
              G431debug_P.one_by_two_Gain_k;
            rtb_Switch4_idx_0 = ((rtb_sum_beta + rtb_Add_h) *
                                 G431debug_P.Gain_Gain * G431debug_P.Gain_Gain_m
                                 + G431debug_P.Constant1_Value) *
              G431debug_P.Gain1_Gain;
            rtb_Switch4_idx_1 = ((rtb_Add1_e + rtb_Add_h) *
                                 G431debug_P.Gain_Gain * G431debug_P.Gain_Gain_m
                                 + G431debug_P.Constant1_Value) *
              G431debug_P.Gain1_Gain;
            rtb_Switch4_idx_2 = ((rtb_Add_h + rtb_Merge) * G431debug_P.Gain_Gain
                                 * G431debug_P.Gain_Gain_m +
                                 G431debug_P.Constant1_Value) *
              G431debug_P.Gain1_Gain;
          } else {
            rtb_Switch4_idx_0 = G431debug_P.stop_Value;
            rtb_Switch4_idx_1 = G431debug_P.stop_Value;
            rtb_Switch4_idx_2 = G431debug_P.stop_Value;
          }

          /* End of Switch: '<S30>/Switch4' */

          /* MATLABSystem: '<S47>/PWM Output' */
          setDutyCycleInPercentageChannel1(G431debug_DW.obj_i.TimerHandle,
            rtb_Switch4_idx_0);
          setDutyCycleInPercentageChannel2(G431debug_DW.obj_i.TimerHandle,
            rtb_Switch4_idx_1);
          setDutyCycleInPercentageChannel3(G431debug_DW.obj_i.TimerHandle,
            rtb_Switch4_idx_2);

          /* Outputs for Enabled SubSystem: '<S11>/Find Offset' incorporates:
           *  EnablePort: '<S28>/Enable'
           */
          if (G431debug_B.Compare) {
            if (!G431debug_DW.FindOffset_MODE) {
              /* InitializeConditions for Delay: '<S28>/Delay' */
              G431debug_DW.Delay_DSTATE = G431debug_P.Delay_InitialCondition_b;
              G431debug_DW.FindOffset_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S28>/Subsystem' incorporates:
             *  EnablePort: '<S35>/Enable'
             */
            /* Logic: '<S28>/AND' incorporates:
             *  Constant: '<S33>/Constant'
             *  Constant: '<S34>/Constant'
             *  Delay: '<S28>/Delay'
             *  RelationalOperator: '<S33>/Compare'
             *  RelationalOperator: '<S34>/Compare'
             */
            if ((G431debug_B.scaleOut <= G431debug_P.CompareToConstant_const) &&
                (G431debug_DW.Delay_DSTATE >=
                 G431debug_P.CompareToConstant1_const)) {
              /* Switch: '<S36>/Switch1' incorporates:
               *  Constant: '<S36>/FilterConstant'
               *  Constant: '<S36>/One'
               *  Constant: '<S36>/OneMinusFilterConstant'
               *  Constant: '<S36>/UseInputPort'
               *  Constant: '<S36>/a'
               *  Sum: '<S36>/Sum'
               */
              if (G431debug_P.UseInputPort_Value > G431debug_P.Switch1_Threshold)
              {
                rtb_Switch4_idx_0 = G431debug_P.a_Value;
                rtb_Switch4_idx_1 = G431debug_P.One_Value - G431debug_P.a_Value;
              } else {
                rtb_Switch4_idx_0 = G431debug_P.FilterConstant_Value;
                rtb_Switch4_idx_1 = G431debug_P.OneMinusFilterConstant_Value;
              }

              /* End of Switch: '<S36>/Switch1' */

              /* Update for UnitDelay: '<S39>/Unit Delay' incorporates:
               *  Product: '<S39>/Product'
               *  Product: '<S39>/Product1'
               *  Sum: '<S39>/Add1'
               */
              G431debug_DW.UnitDelay_DSTATE = 0.0 * rtb_Switch4_idx_0 +
                rtb_Switch4_idx_1 * G431debug_DW.UnitDelay_DSTATE;
              G431debug_DW.Subsystem_SubsysRanBC = 4;
            }

            /* End of Logic: '<S28>/AND' */
            /* End of Outputs for SubSystem: '<S28>/Subsystem' */

            /* Update for Delay: '<S28>/Delay' */
            G431debug_DW.Delay_DSTATE = G431debug_B.scaleOut;
            G431debug_DW.FindOffset_SubsysRanBC = 4;
          } else {
            G431debug_DW.FindOffset_MODE = false;

            /* Outputs for Enabled SubSystem: '<S11>/Subsystem1' incorporates:
             *  EnablePort: '<S31>/Enable'
             */
            G431debug_DW.Subsystem1_SubsysRanBC = 4;

            /* End of Outputs for SubSystem: '<S11>/Subsystem1' */
          }

          /* End of Outputs for SubSystem: '<S11>/Find Offset' */
          G431debug_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((G431debug_M->Timing.clockTick2) *
        0.001);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
}

/* Hardware Interrupt Block: '<S137>/Hardware Interrupt' */
void TIM3_IRQHandler(void)
{
  uint32_T priority_mask;
  priority_mask = MW_HWI_MaskInterrupt();

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
        srClearBC
          (G431debug_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (G431debug_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.ValidHalls.ValidHalls_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (G431debug_DW.Badhallglitchorwrongconnection.Badhallglitchorwrongconnection_);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.HALL_B_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_B' */
        {
          uint32_T length;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Sum_nt;
          boolean_T rtb_Merge3;
          G431debug_M->Timing.clockTick3 = G431debug_M->Timing.clockTick0;

          /* MATLABSystem: '<S86>/Timer Capture' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           */
          getCCR1RegisterValuePollingMode(G431debug_DW.obj_k.TimerHandle,
            &G431debug_DW.Timercntprev, &length);

          /* MATLABSystem: '<S91>/Digital Port Read' */
          length = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S93>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S95>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S84>/Sum' incorporates:
           *  Gain: '<S84>/Gain'
           *  Gain: '<S84>/Gain1'
           *  MATLABSystem: '<S91>/Digital Port Read'
           *  MATLABSystem: '<S93>/Digital Port Read'
           *  MATLABSystem: '<S95>/Digital Port Read'
           * */
          rtb_Sum_nt = (uint8_T)(((((uint32_T)((length & 256U) != 0U ? (int32_T)
            G431debug_P.Gain_Gain_d : 0) << 1) + (uint32_T)((pinReadLoc & 64U)
            != 0U ? (int32_T)G431debug_P.Gain1_Gain_n : 0)) + ((uint32_T)
            ((pinReadLoc_p & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S85>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S85>/Data Type Conversion1'
           */
          switch (rtb_Sum_nt) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S96>/Valid Halls' incorporates:
             *  ActionPort: '<S98>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S85>/Data Type Conversion2'
             */
            G431debug_ValidHalls((uint16_T)rtb_Sum_nt, (uint16_T)
                                 G431debug_DW.GlobalHallState,
                                 G431debug_DW.GlobalDirection, &rtb_Merge3,
                                 &G431debug_DW.GlobalDirection, &rtb_Merge,
                                 &G431debug_B.ValidHalls,
                                 &G431debug_DW.ValidHalls,
                                 &G431debug_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S96>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S96>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S97>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431debug_DW.GlobalDirection, &rtb_Merge,
              &G431debug_DW.GlobalDirection, &rtb_Merge3,
              &G431debug_P.Badhallglitchorwrongconnection);

            /* End of Outputs for SubSystem: '<S96>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S85>/Detects if the halls reading is valid' */

          /* Gain: '<S3>/Gain' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  DataTypeConversion: '<S86>/Data Type Conversion'
           *  DataTypeConversion: '<S86>/Data Type Conversion1'
           *  DataTypeConversion: '<S86>/Data Type Conversion2'
           *  Delay: '<S86>/Delay'
           *  Sum: '<S86>/Sum'
           */
          G431debug_DW.Timehall = (uint32_T)(uint16_T)((int16_T)
            G431debug_DW.Timercntprev - (int16_T)G431debug_DW.Delay_DSTATE_k) *
            G431debug_P.Gain_Gain_l;

          /* DataTypeConversion: '<S85>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  Gain: '<S3>/Gain'
           */
          G431debug_DW.GlobalSpeedCount = (uint16_T)(G431debug_DW.Timehall >> 15);

          /* DataTypeConversion: '<S96>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          G431debug_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S85>/Constant'
           */
          G431debug_DW.HallStateChangeFlag = G431debug_P.Constant_Value_l5;

          /* DataStoreWrite: '<S3>/Data Store Write6' */
          G431debug_DW.GlobalHallState = rtb_Sum_nt;

          /* DataStoreWrite: '<S3>/Data Store Write5' incorporates:
           *  Constant: '<S3>/Constant2'
           */
          G431debug_DW.HallAcapture = G431debug_P.Constant2_Value;

          /* Update for Delay: '<S86>/Delay' incorporates:
           *  DataStoreRead: '<S86>/Data Store Read1'
           */
          G431debug_DW.Delay_DSTATE_k = G431debug_DW.Timercntprev;
          G431debug_DW.HALL_B_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((G431debug_M->Timing.clockTick3) *
        0.001);
      extmodeEvent(3,currentTime);
    }
  }

  /* Event: TIM3 CC3 */
  /* Check event TIM3 CC3 occurred */
  if (0 != (
#if defined(MW_TIM3_ENABLED) && defined(MW_TIM3_CAPTURE_VAR)
            (0 != LL_TIM_IsEnabledIT_CC3(TIM3)) && (0 != TIM_IsActiveFlag_CC3
        (&(MW_TIM3_CAPTURE_VAR)))
#else
            (0 != LL_TIM_IsEnabledIT_CC3(TIM3)) && (0 != LL_TIM_IsActiveFlag_CC3
        (TIM3))
#endif
            )) {
    /* Clear occurred TIM3 CC3 event */
    LL_TIM_ClearFlag_CC3(TIM3);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.HALL_A_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_A' */
        {
          uint32_T length;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Sum_e;
          boolean_T rtb_Merge3;
          G431debug_M->Timing.clockTick4 = G431debug_M->Timing.clockTick0;

          /* MATLABSystem: '<S61>/Timer Capture' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           */
          getCCR3RegisterValuePollingMode(G431debug_DW.obj_a.TimerHandle,
            &G431debug_DW.Timercntprev, &length);

          /* MATLABSystem: '<S66>/Digital Port Read' */
          length = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S68>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S70>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S59>/Sum' incorporates:
           *  Gain: '<S59>/Gain'
           *  Gain: '<S59>/Gain1'
           *  MATLABSystem: '<S66>/Digital Port Read'
           *  MATLABSystem: '<S68>/Digital Port Read'
           *  MATLABSystem: '<S70>/Digital Port Read'
           * */
          rtb_Sum_e = (uint8_T)(((((uint32_T)((length & 256U) != 0U ? (int32_T)
            G431debug_P.Gain_Gain_j : 0) << 1) + (uint32_T)((pinReadLoc & 64U)
            != 0U ? (int32_T)G431debug_P.Gain1_Gain_o : 0)) + ((uint32_T)
            ((pinReadLoc_p & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S60>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S60>/Data Type Conversion1'
           */
          switch (rtb_Sum_e) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S71>/Valid Halls' incorporates:
             *  ActionPort: '<S73>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S60>/Data Type Conversion2'
             */
            G431debug_ValidHalls((uint16_T)rtb_Sum_e, (uint16_T)
                                 G431debug_DW.GlobalHallState,
                                 G431debug_DW.GlobalDirection, &rtb_Merge3,
                                 &G431debug_DW.GlobalDirection, &rtb_Merge,
                                 &G431debug_B.ValidHalls_p,
                                 &G431debug_DW.ValidHalls_p,
                                 &G431debug_P.ValidHalls_p);

            /* End of Outputs for SubSystem: '<S71>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S71>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S72>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431debug_DW.GlobalDirection, &rtb_Merge,
              &G431debug_DW.GlobalDirection, &rtb_Merge3,
              &G431debug_P.Badhallglitchorwrongconnectio_f);

            /* End of Outputs for SubSystem: '<S71>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S60>/Detects if the halls reading is valid' */

          /* Gain: '<S2>/Gain' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  DataTypeConversion: '<S61>/Data Type Conversion'
           *  DataTypeConversion: '<S61>/Data Type Conversion1'
           *  DataTypeConversion: '<S61>/Data Type Conversion2'
           *  Delay: '<S61>/Delay'
           *  Sum: '<S61>/Sum'
           */
          G431debug_DW.Timehall = (uint32_T)(uint16_T)((int16_T)
            G431debug_DW.Timercntprev - (int16_T)G431debug_DW.Delay_DSTATE_d) *
            G431debug_P.Gain_Gain_b;

          /* DataTypeConversion: '<S60>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  Gain: '<S2>/Gain'
           */
          G431debug_DW.GlobalSpeedCount = (uint16_T)(G431debug_DW.Timehall >> 15);

          /* DataTypeConversion: '<S71>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          G431debug_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S60>/Constant'
           */
          G431debug_DW.HallStateChangeFlag = G431debug_P.Constant_Value_i;

          /* DataStoreWrite: '<S2>/Data Store Write6' */
          G431debug_DW.GlobalHallState = rtb_Sum_e;

          /* DataStoreWrite: '<S2>/Data Store Write5' incorporates:
           *  Constant: '<S2>/Constant2'
           */
          G431debug_DW.HallAcapture = G431debug_P.Constant2_Value_b;

          /* Update for Delay: '<S61>/Delay' incorporates:
           *  DataStoreRead: '<S61>/Data Store Read1'
           */
          G431debug_DW.Delay_DSTATE_d = G431debug_DW.Timercntprev;
          G431debug_DW.HALL_A_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((G431debug_M->Timing.clockTick4) *
        0.001);
      extmodeEvent(4,currentTime);
    }
  }

  /* Event: TIM3 CC4 */
  /* Check event TIM3 CC4 occurred */
  if (0 != (
#if defined(MW_TIM3_ENABLED) && defined(MW_TIM3_CAPTURE_VAR)
            (0 != LL_TIM_IsEnabledIT_CC4(TIM3)) && (0 != TIM_IsActiveFlag_CC4
        (&(MW_TIM3_CAPTURE_VAR)))
#else
            (0 != LL_TIM_IsEnabledIT_CC4(TIM3)) && (0 != LL_TIM_IsActiveFlag_CC4
        (TIM3))
#endif
            )) {
    /* Clear occurred TIM3 CC4 event */
    LL_TIM_ClearFlag_CC4(TIM3);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.HALL_C_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_C' */
        {
          uint32_T length;
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Sum_f;
          boolean_T rtb_Merge3;
          G431debug_M->Timing.clockTick5 = G431debug_M->Timing.clockTick0;

          /* MATLABSystem: '<S111>/Timer Capture' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           */
          getCCR4RegisterValuePollingMode(G431debug_DW.obj_p.TimerHandle,
            &G431debug_DW.Timercntprev, &length);

          /* MATLABSystem: '<S116>/Digital Port Read' */
          length = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S118>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S120>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S109>/Sum' incorporates:
           *  Gain: '<S109>/Gain'
           *  Gain: '<S109>/Gain1'
           *  MATLABSystem: '<S116>/Digital Port Read'
           *  MATLABSystem: '<S118>/Digital Port Read'
           *  MATLABSystem: '<S120>/Digital Port Read'
           * */
          rtb_Sum_f = (uint8_T)(((((uint32_T)((length & 256U) != 0U ? (int32_T)
            G431debug_P.Gain_Gain_e : 0) << 1) + (uint32_T)((pinReadLoc & 64U)
            != 0U ? (int32_T)G431debug_P.Gain1_Gain_oh : 0)) + ((uint32_T)
            ((pinReadLoc_p & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S110>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S110>/Data Type Conversion1'
           */
          switch (rtb_Sum_f) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S121>/Valid Halls' incorporates:
             *  ActionPort: '<S123>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S110>/Data Type Conversion2'
             */
            G431debug_ValidHalls((uint16_T)rtb_Sum_f, (uint16_T)
                                 G431debug_DW.GlobalHallState,
                                 G431debug_DW.GlobalDirection, &rtb_Merge3,
                                 &G431debug_DW.GlobalDirection, &rtb_Merge,
                                 &G431debug_B.ValidHalls_b,
                                 &G431debug_DW.ValidHalls_b,
                                 &G431debug_P.ValidHalls_b);

            /* End of Outputs for SubSystem: '<S121>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S121>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S122>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431debug_DW.GlobalDirection, &rtb_Merge,
              &G431debug_DW.GlobalDirection, &rtb_Merge3,
              &G431debug_P.Badhallglitchorwrongconnectio_n);

            /* End of Outputs for SubSystem: '<S121>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S110>/Detects if the halls reading is valid' */

          /* Gain: '<S4>/Gain' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  DataTypeConversion: '<S111>/Data Type Conversion'
           *  DataTypeConversion: '<S111>/Data Type Conversion1'
           *  DataTypeConversion: '<S111>/Data Type Conversion2'
           *  Delay: '<S111>/Delay'
           *  Sum: '<S111>/Sum'
           */
          G431debug_DW.Timehall = (uint32_T)(uint16_T)((int16_T)
            G431debug_DW.Timercntprev - (int16_T)G431debug_DW.Delay_DSTATE_m) *
            G431debug_P.Gain_Gain_i;

          /* DataTypeConversion: '<S110>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  Gain: '<S4>/Gain'
           */
          G431debug_DW.GlobalSpeedCount = (uint16_T)(G431debug_DW.Timehall >> 15);

          /* DataTypeConversion: '<S121>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          G431debug_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S110>/Constant'
           */
          G431debug_DW.HallStateChangeFlag = G431debug_P.Constant_Value_p;

          /* DataStoreWrite: '<S4>/Data Store Write6' */
          G431debug_DW.GlobalHallState = rtb_Sum_f;

          /* DataStoreWrite: '<S4>/Data Store Write5' incorporates:
           *  Constant: '<S4>/Constant2'
           */
          G431debug_DW.HallAcapture = G431debug_P.Constant2_Value_p;

          /* Update for Delay: '<S111>/Delay' incorporates:
           *  DataStoreRead: '<S111>/Data Store Read1'
           */
          G431debug_DW.Delay_DSTATE_m = G431debug_DW.Timercntprev;
          G431debug_DW.HALL_C_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S137>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((G431debug_M->Timing.clockTick5) *
        0.001);
      extmodeEvent(5,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void G431debug_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
  MW_NVIC_DisableIRQ(44);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
