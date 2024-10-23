/*
 * File: G431debug.c
 *
 * Code generated for Simulink model 'G431debug'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct 22 17:37:57 2024
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

/*
 * Output and update for action system:
 *    '<S47>/Hall Value of 1'
 *    '<S47>/Hall Value of 2'
 *    '<S47>/Hall Value of 3'
 *    '<S47>/Hall Value of 4'
 *    '<S47>/Hall Value of 5'
 *    '<S47>/Hall Value of 6'
 *    '<S47>/Hall Value of 7'
 *    '<S46>/Hall Value of 1'
 *    '<S46>/Hall Value of 2'
 *    '<S46>/Hall Value of 3'
 *    ...
 */
void G431debug_HallValueof1(real32_T *rty_position, P_HallValueof1_G431debug_T
  *localP)
{
  /* SignalConversion generated from: '<S57>/position' incorporates:
   *  Constant: '<S57>/Constant'
   */
  *rty_position = localP->Constant_Value;
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

  /* Start for MATLABSystem: '<S83>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S83>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S83>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/*
 * Output and update for action system:
 *    '<S134>/If Action Subsystem6'
 *    '<S134>/If Action Subsystem7'
 *    '<S109>/If Action Subsystem6'
 *    '<S109>/If Action Subsystem7'
 *    '<S159>/If Action Subsystem6'
 *    '<S159>/If Action Subsystem7'
 */
void G431debu_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_G431debu_T *localP)
{
  /* SignalConversion generated from: '<S141>/direction' incorporates:
   *  Constant: '<S141>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S141>/sequence_check' incorporates:
   *  Constant: '<S141>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S134>/If Action Subsystem'
 *    '<S134>/If Action Subsystem1'
 *    '<S134>/If Action Subsystem2'
 *    '<S134>/If Action Subsystem3'
 *    '<S134>/If Action Subsystem4'
 *    '<S134>/If Action Subsystem5'
 *    '<S109>/If Action Subsystem'
 *    '<S109>/If Action Subsystem1'
 *    '<S109>/If Action Subsystem2'
 *    '<S109>/If Action Subsystem3'
 *    ...
 */
void G431debug_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_G431debug_T *localP)
{
  /* SignalConversion generated from: '<S135>/Out1' incorporates:
   *  Constant: '<S135>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S135>/Out2' incorporates:
   *  Constant: '<S135>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S132>/Valid Halls'
 *    '<S107>/Valid Halls'
 *    '<S157>/Valid Halls'
 */
void G431debug_ValidHalls_Init(B_ValidHalls_G431debug_T *localB,
  P_ValidHalls_G431debug_T *localP)
{
  /* SystemInitialize for Merge: '<S134>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S134>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S134>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S134>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S132>/Valid Halls'
 *    '<S107>/Valid Halls'
 *    '<S157>/Valid Halls'
 */
void G431debug_ValidHalls(uint16_T rtu_hallReading, uint16_T rtu_previousState,
  int16_T rtu_previous_direction, boolean_T *rty_directional_speed_valid_fla,
  int16_T *rty_direction, uint16_T *rty_inValidHall, B_ValidHalls_G431debug_T
  *localB, DW_ValidHalls_G431debug_T *localDW, P_ValidHalls_G431debug_T *localP)
{
  /* SwitchCase: '<S134>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem' incorporates:
     *  ActionPort: '<S135>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S136>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S137>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S138>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S139>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S140>/Action Port'
     */
    G431debug_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem5' */
    break;

   default:
    /* Update for IfAction SubSystem: '<S134>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S144>/Action Port'
     */
    /* Update for SwitchCase: '<S134>/Switch Case' */
    localDW->SwitchCaseActionSubsystem_Subsy = 4;

    /* End of Update for SubSystem: '<S134>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S134>/Switch Case' */

  /* If: '<S134>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S141>/Action Port'
     */
    G431debu_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S142>/Action Port'
     */
    G431debu_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S134>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    /* Merge: '<S134>/Merge3' incorporates:
     *  Constant: '<S143>/Constant'
     *  SignalConversion generated from: '<S143>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S134>/If Action Subsystem8' */

    /* Update for IfAction SubSystem: '<S134>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S143>/Action Port'
     */
    /* Update for If: '<S134>/If' */
    localDW->IfActionSubsystem8_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S134>/If Action Subsystem8' */
  }

  /* End of If: '<S134>/If' */

  /* SignalConversion: '<S134>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S134>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S134>/Switch' incorporates:
   *  Constant: '<S134>/Constant'
   *  RelationalOperator: '<S134>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_k;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S134>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S132>/Bad hall (glitch or wrong connection)'
 *    '<S107>/Bad hall (glitch or wrong connection)'
 *    '<S157>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S133>/inValidHall' incorporates:
   *  Constant: '<S133>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S133>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S133>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S133>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

static void G431debug_SystemCore_setup_i(stm32cube_blocks_TimerCapture_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S3>/Timer Capture' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S3>/Timer Capture' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 26);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S3>/Timer Capture' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void G431debug_SystemCore_setup_g(stm32cube_blocks_TimerCapture_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S2>/Timer Capture' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S2>/Timer Capture' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 26);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S2>/Timer Capture' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void G431debug_SystemCore_setup_i2(stm32cube_blocks_TimerCapture_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S4>/Timer Capture' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM3;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S4>/Timer Capture' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 26);
  enableTimerChannel4(obj->TimerHandle, ENABLE_CH);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S4>/Timer Capture' */
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

  /* RateTransition: '<Root>/Rate Transition2' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   */
  G431debug_B.Halls = G431debug_DW.GlobalHallState;

  /* RateTransition: '<Root>/Rate Transition3' */
  G431debug_B.pstheta = G431debug_B.PositionUnit;

  /* RateTransition: '<Root>/Rate Transition4' */
  G431debug_B.Psw = G431debug_B.Gain1;

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

  /* MATLABSystem: '<S176>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_LED != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S176>/Digital Port Write' */

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
  G431debug_M->Sizes.checksums[0] = (1869144547U);
  G431debug_M->Sizes.checksums[1] = (1301610572U);
  G431debug_M->Sizes.checksums[2] = (2752403192U);
  G431debug_M->Sizes.checksums[3] = (687195286U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[114];
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
    systemRan[10] = (sysRanDType *)
      &G431debug_DW.HallValueof1_e.HallValueof1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &G431debug_DW.HallValueof2_o.HallValueof1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &G431debug_DW.HallValueof3_b.HallValueof1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &G431debug_DW.HallValueof4_e.HallValueof1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &G431debug_DW.HallValueof5_j.HallValueof1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &G431debug_DW.HallValueof6_m.HallValueof1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &G431debug_DW.HallValueof7_e.HallValueof1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&G431debug_DW.SpeedanddirectionarenotvalidPos;
    systemRan[18] = (sysRanDType *)&G431debug_DW.IfActionSubsystem_SubsysRanBC_k;
    systemRan[19] = (sysRanDType *)&G431debug_DW.IfActionSubsystem1_SubsysRanB_p;
    systemRan[20] = (sysRanDType *)
      &G431debug_DW.HallValueof1_b.HallValueof1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &G431debug_DW.HallValueof2_p.HallValueof1_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &G431debug_DW.HallValueof3_p.HallValueof1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &G431debug_DW.HallValueof4_l.HallValueof1_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &G431debug_DW.HallValueof5_o.HallValueof1_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &G431debug_DW.HallValueof6_g.HallValueof1_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &G431debug_DW.HallValueof7_b.HallValueof1_SubsysRanBC;
    systemRan[27] = (sysRanDType *)&G431debug_DW.veDirection_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &G431debug_DW.HallValueof1.HallValueof1_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &G431debug_DW.HallValueof2.HallValueof1_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &G431debug_DW.HallValueof3.HallValueof1_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &G431debug_DW.HallValueof4.HallValueof1_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &G431debug_DW.HallValueof5.HallValueof1_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &G431debug_DW.HallValueof6.HallValueof1_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &G431debug_DW.HallValueof7.HallValueof1_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&G431debug_DW.veDirection_SubsysRanBC_h;
    systemRan[36] = (sysRanDType *)&G431debug_DW.first_order_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&G431debug_DW.second_order_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&G431debug_DW.Subsystem1_SubsysRanBC_m;
    systemRan[39] = (sysRanDType *)&G431debug_DW.SpeedanddirectionarevalidUsespe;
    systemRan[40] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[41] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[42] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[43] = (sysRanDType *)&G431debug_DW.Subsystem_SubsysRanBC;
    systemRan[44] = (sysRanDType *)&G431debug_DW.Subsystem_SubsysRanBC;
    systemRan[45] = (sysRanDType *)&G431debug_DW.Subsystem_SubsysRanBC;
    systemRan[46] = (sysRanDType *)&G431debug_DW.FindOffset_SubsysRanBC;
    systemRan[47] = (sysRanDType *)&G431debug_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[48] = (sysRanDType *)&G431debug_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[49] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[50] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[51] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[52] = (sysRanDType *)&G431debug_DW.Subsystem1_SubsysRanBC;
    systemRan[53] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[54] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[55] = (sysRanDType *)&G431debug_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[56] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[57] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[58] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &G431debug_DW.Badhallglitchorwrongconnectio_f.Badhallglitchorwrongconnection_;
    systemRan[60] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[61] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[65] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[67] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.IfActionSubsystem8_SubsysRanBC;
    systemRan[69] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.SwitchCaseActionSubsystem_Subsy;
    systemRan[70] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[71] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &G431debug_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[73] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[74] = (sysRanDType *)&G431debug_DW.HALL_A_SubsysRanBC;
    systemRan[75] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[76] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[77] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[78] = (sysRanDType *)
      &G431debug_DW.Badhallglitchorwrongconnection.Badhallglitchorwrongconnection_;
    systemRan[79] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[80] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[81] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[82] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[83] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[84] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[85] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[86] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[87] = (sysRanDType *)
      &G431debug_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC;
    systemRan[88] = (sysRanDType *)
      &G431debug_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy;
    systemRan[89] = (sysRanDType *)
      &G431debug_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[90] = (sysRanDType *)
      &G431debug_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[91] = (sysRanDType *)
      &G431debug_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[92] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[93] = (sysRanDType *)&G431debug_DW.HALL_B_SubsysRanBC;
    systemRan[94] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[95] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[96] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[97] = (sysRanDType *)
      &G431debug_DW.Badhallglitchorwrongconnectio_n.Badhallglitchorwrongconnection_;
    systemRan[98] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[99] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[100] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[101] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[102] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[103] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[104] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[105] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[106] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.IfActionSubsystem8_SubsysRanBC;
    systemRan[107] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.SwitchCaseActionSubsystem_Subsy;
    systemRan[108] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[109] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[110] = (sysRanDType *)
      &G431debug_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[111] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[112] = (sysRanDType *)&G431debug_DW.HALL_C_SubsysRanBC;
    systemRan[113] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(G431debug_M->extModeInfo,
      &G431debug_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(G431debug_M->extModeInfo, G431debug_M->Sizes.checksums);
    rteiSetTPtr(G431debug_M->extModeInfo, rtmGetTPtr(G431debug_M));
  }

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  G431debug_DW.GlobalHallState = G431debug_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  G431debug_DW.Timehall = G431debug_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  G431debug_DW.HallCcapture = G431debug_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  G431debug_DW.HallAcapture = G431debug_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  G431debug_DW.HallBcapture = G431debug_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  G431debug_DW.GlobalDirection = G431debug_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  G431debug_DW.GlobalSpeedCount = G431debug_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  G431debug_DW.GlobalSpeedValidity = G431debug_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  G431debug_DW.HallStateChangeFlag = G431debug_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  G431debug_DW.Timercntprev = G431debug_P.DataStoreMemory1_InitialValue;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  G431debug_M->Timing.clockTick2 = G431debug_M->Timing.clockTick0;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  G431debug_DW.DiscreteTimeIntegrator_DSTATE =
    G431debug_P.DiscreteTimeIntegrator_IC;
  G431debug_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for Delay: '<S29>/validityDelay' */
  G431debug_DW.validityDelay_DSTATE = G431debug_P.validityDelay_InitialCondition;

  /* InitializeConditions for RelationalOperator: '<S34>/Compare' incorporates:
   *  Delay: '<S30>/Delay One Step1'
   */
  G431debug_DW.DelayOneStep1_DSTATE = G431debug_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Delay: '<S30>/Delay One Step' */
  G431debug_DW.DelayOneStep_DSTATE = G431debug_P.SoftwareWatchdogTimer_maxCount;

  /* InitializeConditions for Delay: '<S29>/speedCountDelay' */
  G431debug_DW.speedCountDelay_DSTATE =
    G431debug_P.speedCountDelay_InitialConditio;

  /* InitializeConditions for UnitDelay: '<S9>/Output' */
  G431debug_DW.Output_DSTATE = G431debug_P.Output_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem1' */
  /* SystemInitialize for Merge: '<S45>/Merge' */
  G431debug_B.Merge = G431debug_P.Merge_InitialOutput;

  /* End of SystemInitialize for SubSystem: '<S32>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' */

  /* SystemInitialize for Enabled SubSystem: '<S10>/PosGen' */
  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
  G431debug_DW.UnitDelay_DSTATE_i = G431debug_P.UnitDelay_InitialCondition;

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
  G431debug_B.Add1 = G431debug_P.Count_Y0;

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
  /* InitializeConditions for Delay: '<S64>/Delay' */
  G431debug_DW.Delay_DSTATE = G431debug_P.Delay_InitialCondition_b;

  /* SystemInitialize for Enabled SubSystem: '<S64>/Subsystem' */
  /* InitializeConditions for UnitDelay: '<S75>/Unit Delay' */
  G431debug_DW.UnitDelay_DSTATE = G431debug_P.UnitDelay_InitialCondition_l;

  /* End of SystemInitialize for SubSystem: '<S64>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S11>/Find Offset' */

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  G431debug_DW.obj.isInitialized = 0;
  G431debug_DW.obj.matlabCodegenIsDeleted = false;
  G431debug_SystemCore_setup(&G431debug_DW.obj);

  /* Start for MATLABSystem: '<S83>/PWM Output' */
  G431debug_DW.obj_i.matlabCodegenIsDeleted = false;
  G431debug_DW.obj_i.isSetupComplete = false;
  G431debug_DW.obj_i.isInitialized = 1;
  G431debug_PWMOutput_setupImpl(&G431debug_DW.obj_i);
  G431debug_DW.obj_i.isSetupComplete = true;

  /* SystemInitialize for UnitDelay: '<S9>/Output' incorporates:
   *  Outport: '<S1>/ct'
   */
  G431debug_B.Output = G431debug_P.ct_Y0;

  /* SystemInitialize for Gain: '<S17>/Gain1' incorporates:
   *  Outport: '<S1>/posw'
   */
  G431debug_B.Gain1 = G431debug_P.posw_Y0;

  /* SystemInitialize for Gain: '<S28>/PositionUnit' incorporates:
   *  Outport: '<S1>/Theta'
   */
  G431debug_B.PositionUnit = G431debug_P.Theta_Y0_d;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_B'
   */
  /* System initialize for function-call system: '<Root>/HALL_B' */
  G431debug_M->Timing.clockTick3 = G431debug_M->Timing.clockTick0;

  /* SystemInitialize for IfAction SubSystem: '<S132>/Valid Halls' */
  G431debug_ValidHalls_Init(&G431debug_B.ValidHalls, &G431debug_P.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S132>/Valid Halls' */

  /* Start for MATLABSystem: '<S3>/Timer Capture' */
  G431debug_DW.obj_h.isInitialized = 0;
  G431debug_DW.obj_h.matlabCodegenIsDeleted = false;
  G431debug_SystemCore_setup_i(&G431debug_DW.obj_h);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_A'
   */
  /* System initialize for function-call system: '<Root>/HALL_A' */
  G431debug_M->Timing.clockTick4 = G431debug_M->Timing.clockTick0;

  /* SystemInitialize for IfAction SubSystem: '<S107>/Valid Halls' */
  G431debug_ValidHalls_Init(&G431debug_B.ValidHalls_p, &G431debug_P.ValidHalls_p);

  /* End of SystemInitialize for SubSystem: '<S107>/Valid Halls' */

  /* Start for MATLABSystem: '<S2>/Timer Capture' */
  G431debug_DW.obj_a.isInitialized = 0;
  G431debug_DW.obj_a.matlabCodegenIsDeleted = false;
  G431debug_SystemCore_setup_g(&G431debug_DW.obj_a);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_C'
   */

  /* System initialize for function-call system: '<Root>/HALL_C' */
  G431debug_M->Timing.clockTick5 = G431debug_M->Timing.clockTick0;

  /* SystemInitialize for IfAction SubSystem: '<S157>/Valid Halls' */
  G431debug_ValidHalls_Init(&G431debug_B.ValidHalls_b, &G431debug_P.ValidHalls_b);

  /* End of SystemInitialize for SubSystem: '<S157>/Valid Halls' */

  /* Start for MATLABSystem: '<S4>/Timer Capture' */
  G431debug_DW.obj_e.isInitialized = 0;
  G431debug_DW.obj_e.matlabCodegenIsDeleted = false;
  G431debug_SystemCore_setup_i2(&G431debug_DW.obj_e);

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Enable for function-call system: '<Root>/Function-Call Subsystem' */
  G431debug_M->Timing.clockTick2 = G431debug_M->Timing.clockTick0;
  G431debug_DW.FunctionCallSubsystem_RESET_ELA = true;

  /* Enable for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  G431debug_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */
}

/* Model terminate function */
void G431debug_terminate(void)
{
  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
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

  /* Terminate for MATLABSystem: '<S83>/PWM Output' */
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

  /* End of Terminate for MATLABSystem: '<S83>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_B'
   */
  /* Termination for function-call system: '<Root>/HALL_B' */

  /* Terminate for MATLABSystem: '<S3>/Timer Capture' */
  if (!G431debug_DW.obj_h.matlabCodegenIsDeleted) {
    G431debug_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((G431debug_DW.obj_h.isInitialized == 1) &&
        G431debug_DW.obj_h.isSetupComplete) {
      disableCounter(G431debug_DW.obj_h.TimerHandle);
      disableTimerInterrupts(G431debug_DW.obj_h.TimerHandle, 26);
      disableTimerChannel1(G431debug_DW.obj_h.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Timer Capture' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_A'
   */
  /* Termination for function-call system: '<Root>/HALL_A' */

  /* Terminate for MATLABSystem: '<S2>/Timer Capture' */
  if (!G431debug_DW.obj_a.matlabCodegenIsDeleted) {
    G431debug_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((G431debug_DW.obj_a.isInitialized == 1) &&
        G431debug_DW.obj_a.isSetupComplete) {
      disableCounter(G431debug_DW.obj_a.TimerHandle);
      disableTimerInterrupts(G431debug_DW.obj_a.TimerHandle, 26);
      disableTimerChannel3(G431debug_DW.obj_a.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Timer Capture' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_C'
   */

  /* Termination for function-call system: '<Root>/HALL_C' */

  /* Terminate for MATLABSystem: '<S4>/Timer Capture' */
  if (!G431debug_DW.obj_e.matlabCodegenIsDeleted) {
    G431debug_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((G431debug_DW.obj_e.isInitialized == 1) &&
        G431debug_DW.obj_e.isSetupComplete) {
      disableCounter(G431debug_DW.obj_e.TimerHandle);
      disableTimerInterrupts(G431debug_DW.obj_e.TimerHandle, 26);
      disableTimerChannel4(G431debug_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Timer Capture' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */
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

/* Hardware Interrupt Block: '<S171>/Hardware Interrupt' */
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
        srClearBC(G431debug_DW.IfActionSubsystem_SubsysRanBC_k);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.IfActionSubsystem1_SubsysRanB_p);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.HallValueof1.HallValueof1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.veDirection_SubsysRanBC_h);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.veDirection_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.second_order_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.first_order_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.Subsystem1_SubsysRanBC_m);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.SpeedanddirectionarevalidUsespe);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431debug_DW.SpeedanddirectionarenotvalidPos);

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

        /* S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          real_T rtb_Switch4_idx_1;
          real_T rtb_Switch4_idx_2;
          uint64_T tmp_p;
          real32_T rtb_Add1_e;
          real32_T rtb_Merge1;
          real32_T rtb_algDD_o2;
          real32_T rtb_indexing;
          uint32_T FunctionCallSubsystem_ELAPS_T;
          uint16_T tmp[3];
          uint16_T Switch;
          uint16_T rtb_DataStoreRead6;
          uint16_T rtb_Get_Integer;
          uint16_T rtb_counterSize1;
          boolean_T OR;
          G431debug_M->Timing.clockTick2 = G431debug_M->Timing.clockTick0;
          if (G431debug_DW.FunctionCallSubsystem_RESET_ELA) {
            FunctionCallSubsystem_ELAPS_T = 0U;
          } else {
            FunctionCallSubsystem_ELAPS_T = G431debug_M->Timing.clockTick2 -
              G431debug_DW.FunctionCallSubsystem_PREV_T;
          }

          G431debug_DW.FunctionCallSubsystem_PREV_T =
            G431debug_M->Timing.clockTick2;
          G431debug_DW.FunctionCallSubsystem_RESET_ELA = false;

          /* DataStoreRead: '<S17>/Data Store Read6' */
          rtb_DataStoreRead6 = G431debug_DW.HallStateChangeFlag;

          /* Switch: '<S28>/Switch' incorporates:
           *  Constant: '<S28>/WatchDog'
           *  DataStoreRead: '<S17>/Data Store Read6'
           *  DataStoreWrite: '<S17>/Data Store Write3'
           */
          if (G431debug_DW.HallStateChangeFlag != 0) {
            G431debug_DW.HallStateChangeFlag = G431debug_P.WatchDog_Value;
          }

          /* End of Switch: '<S28>/Switch' */

          /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
          if (G431debug_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
            if ((rtb_DataStoreRead6 > 0) &&
                (G431debug_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
              G431debug_DW.DiscreteTimeIntegrator_DSTATE =
                G431debug_P.DiscreteTimeIntegrator_IC;
            } else {
              /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
              G431debug_DW.DiscreteTimeIntegrator_DSTATE += (real32_T)
                (G431debug_P.DiscreteTimeIntegrator_gainval * (real_T)
                 FunctionCallSubsystem_ELAPS_T
                 * G431debug_DW.DiscreteTimeIntegrator_PREV_U);
            }
          }

          if (G431debug_DW.DiscreteTimeIntegrator_DSTATE >
              G431debug_P.DiscreteTimeIntegrator_UpperSat) {
            /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
            G431debug_DW.DiscreteTimeIntegrator_DSTATE =
              G431debug_P.DiscreteTimeIntegrator_UpperSat;
          } else if (G431debug_DW.DiscreteTimeIntegrator_DSTATE <
                     G431debug_P.DiscreteTimeIntegrator_LowerSat) {
            /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
            G431debug_DW.DiscreteTimeIntegrator_DSTATE =
              G431debug_P.DiscreteTimeIntegrator_LowerSat;
          }

          /* End of DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */

          /* DataTypeConversion: '<S28>/counterSize1' incorporates:
           *  DataStoreRead: '<S17>/Data Store Read'
           *  DataStoreRead: '<S17>/Data Store Read2'
           *  DataStoreRead: '<S17>/Data Store Read7'
           *  MinMax: '<S17>/Min'
           */
          G431debug_B.rtb_Switch4_idx_0 = floor(fmin(fmin
            (G431debug_DW.HallAcapture, G431debug_DW.HallBcapture),
            G431debug_DW.HallCcapture));
          if (rtIsNaN(G431debug_B.rtb_Switch4_idx_0) || rtIsInf
              (G431debug_B.rtb_Switch4_idx_0)) {
            G431debug_B.rtb_Switch4_idx_0 = 0.0;
          } else {
            G431debug_B.rtb_Switch4_idx_0 = fmod(G431debug_B.rtb_Switch4_idx_0,
              65536.0);
          }

          rtb_counterSize1 = (uint16_T)(G431debug_B.rtb_Switch4_idx_0 < 0.0 ?
            (int32_T)(uint16_T)-(int16_T)(uint16_T)
            -G431debug_B.rtb_Switch4_idx_0 : (int32_T)(uint16_T)
            G431debug_B.rtb_Switch4_idx_0);

          /* End of DataTypeConversion: '<S28>/counterSize1' */

          /* Switch: '<S29>/Switch' incorporates:
           *  Constant: '<S29>/Order'
           */
          if (G431debug_P.Order_Value > G431debug_P.Switch_Threshold_h) {
            /* Switch: '<S29>/Switch' */
            Switch = rtb_DataStoreRead6;
          } else {
            /* Switch: '<S29>/Switch' */
            Switch = G431debug_P.Order_Value;
          }

          /* End of Switch: '<S29>/Switch' */

          /* Delay: '<S29>/validityDelay' */
          if (Switch != 0) {
            /* Delay: '<S29>/validityDelay' */
            G431debug_B.validityDelay = G431debug_DW.validityDelay_DSTATE;
          }

          /* End of Delay: '<S29>/validityDelay' */

          /* Logic: '<S30>/OR' incorporates:
           *  DataTypeConversion: '<S28>/Data Type Conversion4'
           *  Delay: '<S30>/Delay One Step1'
           */
          OR = (G431debug_DW.DelayOneStep1_DSTATE || (rtb_DataStoreRead6 != 0));

          /* Delay: '<S30>/Delay One Step' incorporates:
           *  DataTypeConversion: '<S28>/Data Type Conversion4'
           */
          if (OR) {
            if (rtb_DataStoreRead6 != 0) {
              G431debug_DW.DelayOneStep_DSTATE =
                G431debug_P.SoftwareWatchdogTimer_maxCount;
            }

            /* Delay: '<S30>/Delay One Step' incorporates:
             *  DataTypeConversion: '<S28>/Data Type Conversion4'
             */
            G431debug_B.DelayOneStep = G431debug_DW.DelayOneStep_DSTATE;
          }

          /* End of Delay: '<S30>/Delay One Step' */

          /* RelationalOperator: '<S34>/Compare' incorporates:
           *  Constant: '<S34>/Constant'
           */
          G431debug_DW.DelayOneStep1_DSTATE = (G431debug_B.DelayOneStep >
            G431debug_P.Constant_Value_mo);

          /* Switch: '<S33>/watchdog check' incorporates:
           *  Constant: '<S33>/Constant'
           */
          if (G431debug_DW.DelayOneStep1_DSTATE) {
            /* MinMax: '<S33>/Max' incorporates:
             *  DataStoreRead: '<S17>/Data Store Read3'
             */
            if (G431debug_DW.GlobalSpeedCount >= rtb_counterSize1) {
              rtb_Get_Integer = G431debug_DW.GlobalSpeedCount;
            } else {
              rtb_Get_Integer = rtb_counterSize1;
            }

            /* Switch: '<S33>/speed check' incorporates:
             *  Constant: '<S33>/Constant'
             *  DataStoreRead: '<S17>/Data Store Read5'
             *  DataTypeConversion: '<S29>/Data Type Conversion'
             *  Logic: '<S29>/Logical Operator'
             *  MinMax: '<S33>/Max'
             */
            if (rtb_Get_Integer >= G431debug_P.speedcheck_Threshold) {
              rtb_Get_Integer = G431debug_P.Constant_Value_p;
            } else {
              rtb_Get_Integer = (uint16_T)((G431debug_DW.GlobalSpeedValidity !=
                0) && G431debug_B.validityDelay);
            }

            /* End of Switch: '<S33>/speed check' */
          } else {
            rtb_Get_Integer = G431debug_P.Constant_Value_p;
          }

          /* End of Switch: '<S33>/watchdog check' */

          /* Delay: '<S29>/speedCountDelay' */
          if (Switch != 0) {
            /* Delay: '<S29>/speedCountDelay' */
            G431debug_B.speedCountDelay = G431debug_DW.speedCountDelay_DSTATE;
          }

          /* End of Delay: '<S29>/speedCountDelay' */

          /* If: '<S28>/If' incorporates:
           *  Constant: '<S32>/PositionEnable'
           */
          if (rtb_Get_Integer != 0) {
            /* Outputs for IfAction SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S32>/Action Port'
             */
            /* If: '<S32>/If' incorporates:
             *  DataStoreRead: '<S17>/Data Store Read4'
             */
            if (G431debug_DW.GlobalDirection > 0) {
              /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem' incorporates:
               *  ActionPort: '<S43>/Action Port'
               */
              /* Merge: '<S28>/Merge' incorporates:
               *  Constant: '<S32>/SpeedConst'
               *  DataStoreRead: '<S17>/Data Store Read3'
               *  DataTypeConversion: '<S32>/SpeedConstData'
               *  DataTypeConversion: '<S32>/currentSpeedData'
               *  Gain: '<S32>/SpeedGain'
               *  Product: '<S32>/Divide'
               *  SignalConversion generated from: '<S43>/In1'
               */
              G431debug_DW.DiscreteTimeIntegrator_PREV_U = (real32_T)
                G431debug_P.SpeedConst_Value / (real32_T)
                G431debug_DW.GlobalSpeedCount * G431debug_P.SpeedGain_Gain;

              /* End of Outputs for SubSystem: '<S32>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S32>/If Action Subsystem' incorporates:
               *  ActionPort: '<S43>/Action Port'
               */
              /* Update for If: '<S32>/If' */
              G431debug_DW.IfActionSubsystem_SubsysRanBC_k = 4;

              /* End of Update for SubSystem: '<S32>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S44>/Action Port'
               */
              /* Merge: '<S28>/Merge' incorporates:
               *  Constant: '<S32>/SpeedConst'
               *  DataStoreRead: '<S17>/Data Store Read3'
               *  DataTypeConversion: '<S32>/SpeedConstData'
               *  DataTypeConversion: '<S32>/currentSpeedData'
               *  Gain: '<S32>/SpeedGain'
               *  Product: '<S32>/Divide'
               *  UnaryMinus: '<S44>/Unary Minus'
               */
              G431debug_DW.DiscreteTimeIntegrator_PREV_U = -((real32_T)
                G431debug_P.SpeedConst_Value / (real32_T)
                G431debug_DW.GlobalSpeedCount * G431debug_P.SpeedGain_Gain);

              /* End of Outputs for SubSystem: '<S32>/If Action Subsystem1' */

              /* Update for IfAction SubSystem: '<S32>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S44>/Action Port'
               */
              /* Update for If: '<S32>/If' */
              G431debug_DW.IfActionSubsystem1_SubsysRanB_p = 4;

              /* End of Update for SubSystem: '<S32>/If Action Subsystem1' */
            }

            /* End of If: '<S32>/If' */

            /* Outputs for Enabled SubSystem: '<S32>/Subsystem1' incorporates:
             *  EnablePort: '<S45>/Enable'
             */
            if (G431debug_P.PositionEnable_Value > 0) {
              /* If: '<S45>/If1' incorporates:
               *  Constant: '<S45>/Constant'
               */
              if (G431debug_P.Constant_Value > 1.0) {
                /* Outputs for IfAction SubSystem: '<S45>/second_order' incorporates:
                 *  ActionPort: '<S49>/Action Port'
                 */
                /* Product: '<S49>/Divide1' incorporates:
                 *  DataStoreRead: '<S17>/Data Store Read3'
                 *  DataTypeConversion: '<S49>/countData'
                 *  DataTypeConversion: '<S49>/currentSpeedData'
                 */
                rtb_Merge1 = (real32_T)rtb_counterSize1 / (real32_T)
                  G431debug_DW.GlobalSpeedCount;

                /* Gain: '<S49>/Gain' incorporates:
                 *  Constant: '<S49>/Constant'
                 *  DataTypeConversion: '<S49>/countData'
                 *  DataTypeConversion: '<S49>/previousSpeedData'
                 *  Gain: '<S49>/Gain1'
                 *  Product: '<S49>/Divide'
                 *  Product: '<S49>/Product'
                 *  Sum: '<S49>/Sum'
                 *  Sum: '<S49>/Sum1'
                 */
                rtb_Merge1 = ((rtb_Merge1 - (real32_T)rtb_counterSize1 /
                               (real32_T)G431debug_B.speedCountDelay) *
                              G431debug_P.Gain1_Gain_k +
                              G431debug_P.Constant_Value_g) * rtb_Merge1 *
                  G431debug_P.Gain_Gain;

                /* End of Outputs for SubSystem: '<S45>/second_order' */

                /* Update for IfAction SubSystem: '<S45>/second_order' incorporates:
                 *  ActionPort: '<S49>/Action Port'
                 */
                /* Update for If: '<S45>/If1' */
                G431debug_DW.second_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S45>/second_order' */
              } else {
                /* Outputs for IfAction SubSystem: '<S45>/first_order' incorporates:
                 *  ActionPort: '<S48>/Action Port'
                 */
                /* Gain: '<S48>/Gain' incorporates:
                 *  DataStoreRead: '<S17>/Data Store Read3'
                 *  DataTypeConversion: '<S48>/countData'
                 *  DataTypeConversion: '<S48>/currentSpeedData'
                 *  Product: '<S48>/Divide'
                 */
                rtb_Merge1 = (real32_T)rtb_counterSize1 / (real32_T)
                  G431debug_DW.GlobalSpeedCount * G431debug_P.Gain_Gain_j;

                /* End of Outputs for SubSystem: '<S45>/first_order' */

                /* Update for IfAction SubSystem: '<S45>/first_order' incorporates:
                 *  ActionPort: '<S48>/Action Port'
                 */
                /* Update for If: '<S45>/If1' */
                G431debug_DW.first_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S45>/first_order' */
              }

              /* End of If: '<S45>/If1' */

              /* Saturate: '<S45>/Saturation' */
              if (rtb_Merge1 > G431debug_P.Saturation_UpperSat) {
                rtb_Merge1 = G431debug_P.Saturation_UpperSat;
              } else if (rtb_Merge1 < G431debug_P.Saturation_LowerSat) {
                rtb_Merge1 = G431debug_P.Saturation_LowerSat;
              }

              /* End of Saturate: '<S45>/Saturation' */

              /* If: '<S45>/If' incorporates:
               *  DataStoreRead: '<S17>/Data Store Read4'
               */
              if (G431debug_DW.GlobalDirection != 1) {
                /* Outputs for IfAction SubSystem: '<S45>/-ve Direction' incorporates:
                 *  ActionPort: '<S47>/Action Port'
                 */
                /* SwitchCase: '<S47>/Switch Case' incorporates:
                 *  DataStoreRead: '<S17>/Data Store Read1'
                 */
                switch (G431debug_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S57>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof1);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S58>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof2);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S59>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof3);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S60>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof4);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S61>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof5);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S62>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof6);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S63>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof7);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S47>/Switch Case' */

                /* Merge: '<S45>/Merge' incorporates:
                 *  Sum: '<S47>/Sum'
                 */
                G431debug_B.Merge = rtb_indexing - rtb_Merge1;

                /* End of Outputs for SubSystem: '<S45>/-ve Direction' */

                /* Update for IfAction SubSystem: '<S45>/-ve Direction' incorporates:
                 *  ActionPort: '<S47>/Action Port'
                 */
                /* Update for If: '<S45>/If' */
                G431debug_DW.veDirection_SubsysRanBC_h = 4;

                /* End of Update for SubSystem: '<S45>/-ve Direction' */
              } else {
                /* Outputs for IfAction SubSystem: '<S45>/+ve Direction' incorporates:
                 *  ActionPort: '<S46>/Action Port'
                 */
                /* SwitchCase: '<S46>/Switch Case' incorporates:
                 *  DataStoreRead: '<S17>/Data Store Read1'
                 */
                switch (G431debug_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S50>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof1_b);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S51>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof2_p);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S52>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof3_p);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S53>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof4_l);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S54>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof5_o);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S55>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof6_g);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S56>/Action Port'
                   */
                  G431debug_HallValueof1(&rtb_indexing,
                    &G431debug_P.HallValueof7_b);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S46>/Switch Case' */

                /* Merge: '<S45>/Merge' incorporates:
                 *  Sum: '<S46>/Sum'
                 */
                G431debug_B.Merge = rtb_indexing + rtb_Merge1;

                /* End of Outputs for SubSystem: '<S45>/+ve Direction' */

                /* Update for IfAction SubSystem: '<S45>/+ve Direction' incorporates:
                 *  ActionPort: '<S46>/Action Port'
                 */
                /* Update for If: '<S45>/If' */
                G431debug_DW.veDirection_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S45>/+ve Direction' */
              }

              /* End of If: '<S45>/If' */
              G431debug_DW.Subsystem1_SubsysRanBC_m = 4;
            }

            /* End of Outputs for SubSystem: '<S32>/Subsystem1' */

            /* SignalConversion generated from: '<S32>/rawPosition' incorporates:
             *  Constant: '<S32>/PositionEnable'
             */
            rtb_indexing = G431debug_B.Merge;

            /* End of Outputs for SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' */

            /* Update for IfAction SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S32>/Action Port'
             */
            /* Update for If: '<S28>/If' */
            G431debug_DW.SpeedanddirectionarevalidUsespe = 4;

            /* End of Update for SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' */
          } else {
            /* Outputs for IfAction SubSystem: '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S31>/Action Port'
             */
            /* SwitchCase: '<S35>/Switch Case' incorporates:
             *  DataStoreRead: '<S17>/Data Store Read1'
             */
            switch (G431debug_DW.GlobalHallState) {
             case 5:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 1' incorporates:
               *  ActionPort: '<S36>/Action Port'
               */
              G431debug_HallValueof1(&rtb_indexing, &G431debug_P.HallValueof1_e);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 1' */
              break;

             case 4:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 2' incorporates:
               *  ActionPort: '<S37>/Action Port'
               */
              G431debug_HallValueof1(&rtb_indexing, &G431debug_P.HallValueof2_o);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 2' */
              break;

             case 6:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 3' incorporates:
               *  ActionPort: '<S38>/Action Port'
               */
              G431debug_HallValueof1(&rtb_indexing, &G431debug_P.HallValueof3_b);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 3' */
              break;

             case 2:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 4' incorporates:
               *  ActionPort: '<S39>/Action Port'
               */
              G431debug_HallValueof1(&rtb_indexing, &G431debug_P.HallValueof4_e);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 4' */
              break;

             case 3:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 5' incorporates:
               *  ActionPort: '<S40>/Action Port'
               */
              G431debug_HallValueof1(&rtb_indexing, &G431debug_P.HallValueof5_j);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 5' */
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 6' incorporates:
               *  ActionPort: '<S41>/Action Port'
               */
              G431debug_HallValueof1(&rtb_indexing, &G431debug_P.HallValueof6_m);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 7' incorporates:
               *  ActionPort: '<S42>/Action Port'
               */
              G431debug_HallValueof1(&rtb_indexing, &G431debug_P.HallValueof7_e);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S35>/Switch Case' */

            /* Merge: '<S28>/Merge' incorporates:
             *  Constant: '<S31>/Constant'
             *  SignalConversion generated from: '<S31>/Speed(r.p.m)'
             */
            G431debug_DW.DiscreteTimeIntegrator_PREV_U =
              G431debug_P.Constant_Value_n;

            /* End of Outputs for SubSystem: '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */

            /* Update for IfAction SubSystem: '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S31>/Action Port'
             */
            /* Update for If: '<S28>/If' */
            G431debug_DW.SpeedanddirectionarenotvalidPos = 4;

            /* End of Update for SubSystem: '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
          }

          /* End of If: '<S28>/If' */

          /* Gain: '<S17>/Gain1' */
          G431debug_B.Gain1 = G431debug_P.Gain1_Gain_p *
            G431debug_DW.DiscreteTimeIntegrator_PREV_U;

          /* Gain: '<S28>/PositionUnit' */
          G431debug_B.PositionUnit = G431debug_P.PositionUnit_Gain *
            rtb_indexing;

          /* Outputs for Enabled SubSystem: '<S10>/PosGen' incorporates:
           *  EnablePort: '<S16>/Enable'
           */
          /* Constant: '<S1>/Constant1' */
          if (G431debug_P.Constant1_Value_d > 0.0) {
            if (!G431debug_DW.PosGen_MODE) {
              /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
              G431debug_DW.UnitDelay_DSTATE_i =
                G431debug_P.UnitDelay_InitialCondition;
              G431debug_DW.PosGen_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S16>/Up Counter' incorporates:
             *  EnablePort: '<S22>/Enable'
             */
            if (G431debug_P.Constant1_Value_d > 0.0) {
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
              G431debug_B.Add1 = (uint32_T)tmp_p;

              /* Update for Delay: '<S22>/Delay' */
              G431debug_DW.Delay_DSTATE_h = G431debug_B.Add1;
              G431debug_DW.UpCounter_SubsysRanBC = 4;
            } else if (G431debug_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S22>/Add1' incorporates:
               *  Outport: '<S22>/Count'
               */
              G431debug_B.Add1 = G431debug_P.Count_Y0;
              G431debug_DW.UpCounter_MODE = false;
            }

            /* End of Outputs for SubSystem: '<S16>/Up Counter' */

            /* RelationalOperator: '<S19>/Compare' incorporates:
             *  Constant: '<S19>/Constant'
             */
            G431debug_B.Compare = (G431debug_B.Add1 <=
              G431debug_P.EnablePWMfor40seconds_const);

            /* If: '<S21>/If' incorporates:
             *  Constant: '<S21>/Count for 2 sec'
             */
            if (G431debug_B.Add1 < G431debug_P.Countfor2sec_Value) {
              /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
               *  ActionPort: '<S23>/Action Port'
               */
              /* SignalConversion generated from: '<S23>/Out1' incorporates:
               *  Constant: '<S23>/Constant'
               */
              rtb_Merge1 = G431debug_P.Constant_Value_m;

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
              rtb_Merge1 = G431debug_P.Multiply_Gain *
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
                G431debug_B.Input = G431debug_P.scaleIn_Gain * rtb_Merge1;
                G431debug_DW.Subsystem_SubsysRanBC_o = 4;
              }

              /* End of Outputs for SubSystem: '<S26>/Subsystem' */

              /* Sum: '<S26>/Add' incorporates:
               *  Delay: '<S26>/Delay'
               *  UnitDelay: '<S25>/Unit Delay'
               */
              rtb_indexing = G431debug_B.Input + G431debug_DW.UnitDelay_DSTATE_i;

              /* DataTypeConversion: '<S26>/Data Type Conversion' */
              rtb_Merge1 = floorf(rtb_indexing);
              if (rtIsNaNF(rtb_Merge1) || rtIsInfF(rtb_Merge1)) {
                rtb_Merge1 = 0.0F;
              } else {
                rtb_Merge1 = fmodf(rtb_Merge1, 65536.0F);
              }

              /* Sum: '<S26>/Add1' incorporates:
               *  DataTypeConversion: '<S26>/Data Type Conversion'
               *  DataTypeConversion: '<S26>/Data Type Conversion1'
               */
              G431debug_B.Add1_j = rtb_indexing - (real32_T)(rtb_Merge1 < 0.0F ?
                (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Merge1 : (int32_T)
                (int16_T)(uint16_T)rtb_Merge1);

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
              G431debug_B.Add1 = G431debug_P.Count_Y0;
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

          /* Gain: '<S77>/convert_pu' */
          rtb_indexing = G431debug_P.convert_pu_Gain * G431debug_B.scaleOut;

          /* If: '<S77>/If' incorporates:
           *  Constant: '<S78>/Constant'
           *  RelationalOperator: '<S78>/Compare'
           */
          if (rtb_indexing < G431debug_P.Constant_Value_d) {
            /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem' incorporates:
             *  ActionPort: '<S79>/Action Port'
             */
            /* DataTypeConversion: '<S79>/Convert_uint16' */
            rtb_Merge1 = floorf(rtb_indexing);
            if (rtIsInfF(rtb_Merge1)) {
              rtb_Merge1 = 0.0F;
            } else {
              rtb_Merge1 = fmodf(rtb_Merge1, 65536.0F);
            }

            /* Sum: '<S79>/Sum' incorporates:
             *  DataTypeConversion: '<S79>/Convert_back'
             *  DataTypeConversion: '<S79>/Convert_uint16'
             */
            rtb_indexing -= (real32_T)(rtb_Merge1 < 0.0F ? (int32_T)(int16_T)
              -(int16_T)(uint16_T)-rtb_Merge1 : (int32_T)(int16_T)(uint16_T)
              rtb_Merge1);

            /* End of Outputs for SubSystem: '<S77>/If Action Subsystem' */

            /* Update for IfAction SubSystem: '<S77>/If Action Subsystem' incorporates:
             *  ActionPort: '<S79>/Action Port'
             */
            /* Update for If: '<S77>/If' */
            G431debug_DW.IfActionSubsystem_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S77>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S77>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S80>/Action Port'
             */
            /* DataTypeConversion: '<S80>/Convert_uint16' */
            rtb_Merge1 = truncf(rtb_indexing);
            if (rtIsNaNF(rtb_Merge1) || rtIsInfF(rtb_Merge1)) {
              rtb_Merge1 = 0.0F;
            } else {
              rtb_Merge1 = fmodf(rtb_Merge1, 65536.0F);
            }

            /* Sum: '<S80>/Sum' incorporates:
             *  DataTypeConversion: '<S80>/Convert_back'
             *  DataTypeConversion: '<S80>/Convert_uint16'
             */
            rtb_indexing -= (real32_T)(rtb_Merge1 < 0.0F ? (int32_T)(int16_T)
              -(int16_T)(uint16_T)-rtb_Merge1 : (int32_T)(int16_T)(uint16_T)
              rtb_Merge1);

            /* End of Outputs for SubSystem: '<S77>/If Action Subsystem1' */

            /* Update for IfAction SubSystem: '<S77>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S80>/Action Port'
             */
            /* Update for If: '<S77>/If' */
            G431debug_DW.IfActionSubsystem1_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S77>/If Action Subsystem1' */
          }

          /* End of If: '<S77>/If' */

          /* Gain: '<S65>/indexing' */
          rtb_indexing *= G431debug_P.indexing_Gain;

          /* DataTypeConversion: '<S65>/Get_Integer' */
          rtb_Merge1 = truncf(rtb_indexing);
          if (rtIsNaNF(rtb_Merge1) || rtIsInfF(rtb_Merge1)) {
            rtb_Merge1 = 0.0F;
          } else {
            rtb_Merge1 = fmodf(rtb_Merge1, 65536.0F);
          }

          rtb_Get_Integer = (uint16_T)(rtb_Merge1 < 0.0F ? (int32_T)(uint16_T)
            -(int16_T)(uint16_T)-rtb_Merge1 : (int32_T)(uint16_T)rtb_Merge1);

          /* End of DataTypeConversion: '<S65>/Get_Integer' */

          /* Sum: '<S65>/Sum2' incorporates:
           *  DataTypeConversion: '<S65>/Data Type Conversion1'
           */
          rtb_indexing -= (real32_T)rtb_Get_Integer;

          /* Outputs for Atomic SubSystem: '<S84>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S86>/a16' incorporates:
           *  Constant: '<S65>/offset'
           *  Constant: '<S65>/sine_table_values'
           *  Constant: '<S68>/Vd_Ref'
           *  Constant: '<S68>/Vq'
           *  Product: '<S76>/Product'
           *  Product: '<S76>/Product1'
           *  Selector: '<S65>/Lookup'
           *  Sum: '<S65>/Sum'
           *  Sum: '<S76>/Sum3'
           *  Sum: '<S76>/Sum4'
           *  Sum: '<S76>/Sum5'
           *  Sum: '<S76>/Sum6'
           */
          arm_inv_park_f32(G431debug_P.Vd_Ref_Value, G431debug_P.Vq_Value,
                           &rtb_Merge1, &rtb_algDD_o2,
                           (G431debug_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)G431debug_P.offset_Value[0] +
                             rtb_Get_Integer)] -
                            G431debug_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)G431debug_P.offset_Value[1] +
                             rtb_Get_Integer)]) * rtb_indexing +
                           G431debug_P.sine_table_values_Value[(int32_T)
                           ((uint32_T)G431debug_P.offset_Value[1] +
                            rtb_Get_Integer)],
                           (G431debug_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)G431debug_P.offset_Value[2] +
                             rtb_Get_Integer)] -
                            G431debug_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)G431debug_P.offset_Value[3] +
                             rtb_Get_Integer)]) * rtb_indexing +
                           G431debug_P.sine_table_values_Value[(int32_T)
                           ((uint32_T)G431debug_P.offset_Value[3] +
                            rtb_Get_Integer)]);

          /* End of Outputs for SubSystem: '<S84>/Two inputs CRL' */

          /* Switch: '<S66>/Switch4' incorporates:
           *  Constant: '<S66>/Constant1'
           *  Constant: '<S66>/stop'
           *  Gain: '<S66>/Gain'
           *  Gain: '<S66>/Gain1'
           *  Gain: '<S90>/Gain'
           *  Sum: '<S66>/Add'
           *  Sum: '<S90>/Add1'
           *  Sum: '<S90>/Add2'
           *  Sum: '<S90>/Add3'
           */
          if (G431debug_B.Compare) {
            /* Gain: '<S94>/sqrt3_by_two' */
            rtb_algDD_o2 *= G431debug_P.sqrt3_by_two_Gain;

            /* Gain: '<S94>/one_by_two' */
            rtb_Add1_e = G431debug_P.one_by_two_Gain * rtb_Merge1;

            /* Gain: '<S94>/Kc' incorporates:
             *  Sum: '<S94>/add_c'
             */
            rtb_indexing = ((0.0F - rtb_Add1_e) - rtb_algDD_o2) *
              G431debug_P.Kc_Gain;

            /* Gain: '<S94>/Kb' incorporates:
             *  Sum: '<S94>/add_b'
             */
            rtb_Add1_e = (rtb_algDD_o2 - rtb_Add1_e) * G431debug_P.Kb_Gain;

            /* Gain: '<S94>/Ka' */
            rtb_algDD_o2 = G431debug_P.Ka_Gain * rtb_Merge1;

            /* Gain: '<S91>/one_by_two' incorporates:
             *  MinMax: '<S91>/Max'
             *  MinMax: '<S91>/Min'
             *  Sum: '<S91>/Add'
             */
            rtb_Merge1 = (fmaxf(fmaxf(rtb_algDD_o2, rtb_Add1_e), rtb_indexing) +
                          fminf(fminf(rtb_algDD_o2, rtb_Add1_e), rtb_indexing)) *
              G431debug_P.one_by_two_Gain_k;
            G431debug_B.rtb_Switch4_idx_0 = ((rtb_algDD_o2 + rtb_Merge1) *
              G431debug_P.Gain_Gain_d * G431debug_P.Gain_Gain_m +
              G431debug_P.Constant1_Value) * G431debug_P.Gain1_Gain;
            rtb_Switch4_idx_1 = ((rtb_Add1_e + rtb_Merge1) *
                                 G431debug_P.Gain_Gain_d *
                                 G431debug_P.Gain_Gain_m +
                                 G431debug_P.Constant1_Value) *
              G431debug_P.Gain1_Gain;
            rtb_Switch4_idx_2 = ((rtb_Merge1 + rtb_indexing) *
                                 G431debug_P.Gain_Gain_d *
                                 G431debug_P.Gain_Gain_m +
                                 G431debug_P.Constant1_Value) *
              G431debug_P.Gain1_Gain;
          } else {
            G431debug_B.rtb_Switch4_idx_0 = G431debug_P.stop_Value;
            rtb_Switch4_idx_1 = G431debug_P.stop_Value;
            rtb_Switch4_idx_2 = G431debug_P.stop_Value;
          }

          /* End of Switch: '<S66>/Switch4' */

          /* MATLABSystem: '<S83>/PWM Output' */
          setDutyCycleInPercentageChannel1(G431debug_DW.obj_i.TimerHandle,
            G431debug_B.rtb_Switch4_idx_0);
          setDutyCycleInPercentageChannel2(G431debug_DW.obj_i.TimerHandle,
            rtb_Switch4_idx_1);
          setDutyCycleInPercentageChannel3(G431debug_DW.obj_i.TimerHandle,
            rtb_Switch4_idx_2);

          /* Outputs for Enabled SubSystem: '<S11>/Find Offset' incorporates:
           *  EnablePort: '<S64>/Enable'
           */
          if (G431debug_B.Compare) {
            if (!G431debug_DW.FindOffset_MODE) {
              /* InitializeConditions for Delay: '<S64>/Delay' */
              G431debug_DW.Delay_DSTATE = G431debug_P.Delay_InitialCondition_b;
              G431debug_DW.FindOffset_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S64>/Subsystem' incorporates:
             *  EnablePort: '<S71>/Enable'
             */
            /* Logic: '<S64>/AND' incorporates:
             *  Constant: '<S69>/Constant'
             *  Constant: '<S70>/Constant'
             *  Delay: '<S64>/Delay'
             *  RelationalOperator: '<S69>/Compare'
             *  RelationalOperator: '<S70>/Compare'
             */
            if ((G431debug_B.scaleOut <= G431debug_P.CompareToConstant_const) &&
                (G431debug_DW.Delay_DSTATE >=
                 G431debug_P.CompareToConstant1_const)) {
              /* Switch: '<S72>/Switch1' incorporates:
               *  Constant: '<S72>/FilterConstant'
               *  Constant: '<S72>/One'
               *  Constant: '<S72>/OneMinusFilterConstant'
               *  Constant: '<S72>/UseInputPort'
               *  Constant: '<S72>/a'
               *  Sum: '<S72>/Sum'
               */
              if (G431debug_P.UseInputPort_Value > G431debug_P.Switch1_Threshold)
              {
                rtb_algDD_o2 = G431debug_P.a_Value;
                rtb_Add1_e = G431debug_P.One_Value - G431debug_P.a_Value;
              } else {
                rtb_algDD_o2 = G431debug_P.FilterConstant_Value;
                rtb_Add1_e = G431debug_P.OneMinusFilterConstant_Value;
              }

              /* End of Switch: '<S72>/Switch1' */

              /* Update for UnitDelay: '<S75>/Unit Delay' incorporates:
               *  Product: '<S75>/Product'
               *  Product: '<S75>/Product1'
               *  Sum: '<S17>/Sum'
               *  Sum: '<S75>/Add1'
               */
              G431debug_DW.UnitDelay_DSTATE = (G431debug_B.PositionUnit +
                G431debug_DW.DiscreteTimeIntegrator_DSTATE) * rtb_algDD_o2 +
                rtb_Add1_e * G431debug_DW.UnitDelay_DSTATE;
              G431debug_DW.Subsystem_SubsysRanBC = 4;
            }

            /* End of Logic: '<S64>/AND' */
            /* End of Outputs for SubSystem: '<S64>/Subsystem' */

            /* Update for Delay: '<S64>/Delay' */
            G431debug_DW.Delay_DSTATE = G431debug_B.scaleOut;
            G431debug_DW.FindOffset_SubsysRanBC = 4;
          } else {
            G431debug_DW.FindOffset_MODE = false;

            /* Outputs for Enabled SubSystem: '<S11>/Subsystem1' incorporates:
             *  EnablePort: '<S67>/Enable'
             */
            G431debug_DW.Subsystem1_SubsysRanBC = 4;

            /* End of Outputs for SubSystem: '<S11>/Subsystem1' */
          }

          /* End of Outputs for SubSystem: '<S11>/Find Offset' */

          /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
          G431debug_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
          G431debug_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
            (rtb_DataStoreRead6 > 0);

          /* Update for Delay: '<S29>/validityDelay' incorporates:
           *  DataStoreRead: '<S17>/Data Store Read3'
           *  DataStoreRead: '<S17>/Data Store Read5'
           *  DataTypeConversion: '<S29>/Data Type Conversion'
           *  Delay: '<S29>/speedCountDelay'
           */
          if (Switch != 0) {
            G431debug_DW.validityDelay_DSTATE =
              (G431debug_DW.GlobalSpeedValidity != 0);
            G431debug_DW.speedCountDelay_DSTATE = G431debug_DW.GlobalSpeedCount;
          }

          /* End of Update for Delay: '<S29>/validityDelay' */

          /* Update for Delay: '<S30>/Delay One Step' incorporates:
           *  Constant: '<S30>/Constant2'
           *  Sum: '<S30>/Sum'
           */
          if (OR) {
            G431debug_DW.DelayOneStep_DSTATE = (uint16_T)((uint32_T)
              G431debug_B.DelayOneStep - G431debug_P.Constant2_Value_p3);
          }

          /* End of Update for Delay: '<S30>/Delay One Step' */
          G431debug_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T) ((G431debug_M->Timing.clockTick2) *
        0.001);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

/* Hardware Interrupt Block: '<S173>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_B' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge_p;
          uint8_T rtb_Sum_b;
          boolean_T rtb_Merge3;
          G431debug_M->Timing.clockTick3 = G431debug_M->Timing.clockTick0;

          /* MATLABSystem: '<S127>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S129>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S131>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S120>/Sum' incorporates:
           *  Gain: '<S120>/Gain'
           *  Gain: '<S120>/Gain1'
           *  MATLABSystem: '<S127>/Digital Port Read'
           *  MATLABSystem: '<S129>/Digital Port Read'
           *  MATLABSystem: '<S131>/Digital Port Read'
           * */
          rtb_Sum_b = (uint8_T)(((((uint32_T)((pinReadLoc & 256U) != 0U ?
            (int32_T)G431debug_P.Gain_Gain_de : 0) << 1) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? (int32_T)G431debug_P.Gain1_Gain_n : 0))
            + ((uint32_T)((pinReadLoc_e & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S121>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S121>/Data Type Conversion1'
           */
          switch (rtb_Sum_b) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S132>/Valid Halls' incorporates:
             *  ActionPort: '<S134>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S121>/Data Type Conversion2'
             */
            G431debug_ValidHalls((uint16_T)rtb_Sum_b, (uint16_T)
                                 G431debug_DW.GlobalHallState,
                                 G431debug_DW.GlobalDirection, &rtb_Merge3,
                                 &G431debug_DW.GlobalDirection, &rtb_Merge_p,
                                 &G431debug_B.ValidHalls,
                                 &G431debug_DW.ValidHalls,
                                 &G431debug_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S132>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S132>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S133>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431debug_DW.GlobalDirection,
              &rtb_Merge_p, &G431debug_DW.GlobalDirection, &rtb_Merge3,
              &G431debug_P.Badhallglitchorwrongconnection);

            /* End of Outputs for SubSystem: '<S132>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S121>/Detects if the halls reading is valid' */

          /* MATLABSystem: '<S3>/Timer Capture' */
          getCCR1RegisterValuePollingMode(G431debug_DW.obj_h.TimerHandle,
            &rtb_Merge_p, &pinReadLoc);

          /* Gain: '<S3>/Gain' incorporates:
           *  DataStoreRead: '<S3>/Data Store Read1'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  DataTypeConversion: '<S3>/Data Type Conversion1'
           *  DataTypeConversion: '<S3>/Data Type Conversion4'
           *  MATLABSystem: '<S3>/Timer Capture'
           *  Sum: '<S3>/Sum1'
           */
          G431debug_DW.Timehall = (uint32_T)(uint16_T)((int16_T)rtb_Merge_p -
            G431debug_DW.Timercntprev) * G431debug_P.Gain_Gain_l;

          /* DataTypeConversion: '<S121>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  Gain: '<S3>/Gain'
           */
          G431debug_DW.GlobalSpeedCount = (uint16_T)(G431debug_DW.Timehall >> 15);

          /* DataTypeConversion: '<S132>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          G431debug_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S121>/Constant'
           */
          G431debug_DW.HallStateChangeFlag = G431debug_P.Constant_Value_l5;

          /* DataStoreWrite: '<S3>/Data Store Write6' */
          G431debug_DW.GlobalHallState = rtb_Sum_b;

          /* DataStoreWrite: '<S122>/Data Store Write' incorporates:
           *  DataTypeConversion: '<S3>/Data Type Conversion1'
           *  MATLABSystem: '<S3>/Timer Capture'
           */
          G431debug_DW.Timercntprev = (int16_T)rtb_Merge_p;

          /* DataStoreWrite: '<S3>/Data Store Write5' incorporates:
           *  Constant: '<S3>/Constant2'
           */
          G431debug_DW.HallAcapture = G431debug_P.Constant2_Value;
          G431debug_DW.HALL_B_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_A' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge_h;
          uint8_T rtb_Sum_i;
          boolean_T rtb_Merge3;
          G431debug_M->Timing.clockTick4 = G431debug_M->Timing.clockTick0;

          /* MATLABSystem: '<S102>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S104>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S106>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S95>/Sum' incorporates:
           *  Gain: '<S95>/Gain'
           *  Gain: '<S95>/Gain1'
           *  MATLABSystem: '<S102>/Digital Port Read'
           *  MATLABSystem: '<S104>/Digital Port Read'
           *  MATLABSystem: '<S106>/Digital Port Read'
           * */
          rtb_Sum_i = (uint8_T)(((((uint32_T)((pinReadLoc & 256U) != 0U ?
            (int32_T)G431debug_P.Gain_Gain_jm : 0) << 1) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? (int32_T)G431debug_P.Gain1_Gain_o : 0))
            + ((uint32_T)((pinReadLoc_e & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S96>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S96>/Data Type Conversion1'
           */
          switch (rtb_Sum_i) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S107>/Valid Halls' incorporates:
             *  ActionPort: '<S109>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S96>/Data Type Conversion2'
             */
            G431debug_ValidHalls((uint16_T)rtb_Sum_i, (uint16_T)
                                 G431debug_DW.GlobalHallState,
                                 G431debug_DW.GlobalDirection, &rtb_Merge3,
                                 &G431debug_DW.GlobalDirection, &rtb_Merge_h,
                                 &G431debug_B.ValidHalls_p,
                                 &G431debug_DW.ValidHalls_p,
                                 &G431debug_P.ValidHalls_p);

            /* End of Outputs for SubSystem: '<S107>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S107>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S108>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431debug_DW.GlobalDirection,
              &rtb_Merge_h, &G431debug_DW.GlobalDirection, &rtb_Merge3,
              &G431debug_P.Badhallglitchorwrongconnectio_f);

            /* End of Outputs for SubSystem: '<S107>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S96>/Detects if the halls reading is valid' */

          /* MATLABSystem: '<S2>/Timer Capture' */
          getCCR3RegisterValuePollingMode(G431debug_DW.obj_a.TimerHandle,
            &rtb_Merge_h, &pinReadLoc);

          /* Gain: '<S2>/Gain' incorporates:
           *  DataStoreRead: '<S2>/Data Store Read1'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  DataTypeConversion: '<S2>/Data Type Conversion1'
           *  DataTypeConversion: '<S2>/Data Type Conversion4'
           *  MATLABSystem: '<S2>/Timer Capture'
           *  Sum: '<S2>/Sum1'
           */
          G431debug_DW.Timehall = (uint32_T)(uint16_T)((int16_T)rtb_Merge_h -
            G431debug_DW.Timercntprev) * G431debug_P.Gain_Gain_b;

          /* DataTypeConversion: '<S96>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  Gain: '<S2>/Gain'
           */
          G431debug_DW.GlobalSpeedCount = (uint16_T)(G431debug_DW.Timehall >> 15);

          /* DataTypeConversion: '<S107>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          G431debug_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S96>/Constant'
           */
          G431debug_DW.HallStateChangeFlag = G431debug_P.Constant_Value_i;

          /* DataStoreWrite: '<S2>/Data Store Write6' */
          G431debug_DW.GlobalHallState = rtb_Sum_i;

          /* DataStoreWrite: '<S97>/Data Store Write' incorporates:
           *  DataTypeConversion: '<S2>/Data Type Conversion1'
           *  MATLABSystem: '<S2>/Timer Capture'
           */
          G431debug_DW.Timercntprev = (int16_T)rtb_Merge_h;

          /* DataStoreWrite: '<S2>/Data Store Write5' incorporates:
           *  Constant: '<S2>/Constant2'
           */
          G431debug_DW.HallAcapture = G431debug_P.Constant2_Value_b;
          G431debug_DW.HALL_A_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_C' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge_ce;
          uint8_T rtb_Sum_cz;
          boolean_T rtb_Merge3;
          G431debug_M->Timing.clockTick5 = G431debug_M->Timing.clockTick0;

          /* MATLABSystem: '<S152>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S154>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S156>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S145>/Sum' incorporates:
           *  Gain: '<S145>/Gain'
           *  Gain: '<S145>/Gain1'
           *  MATLABSystem: '<S152>/Digital Port Read'
           *  MATLABSystem: '<S154>/Digital Port Read'
           *  MATLABSystem: '<S156>/Digital Port Read'
           * */
          rtb_Sum_cz = (uint8_T)(((((uint32_T)((pinReadLoc & 256U) != 0U ?
            (int32_T)G431debug_P.Gain_Gain_e : 0) << 1) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? (int32_T)G431debug_P.Gain1_Gain_oh : 0))
            + ((uint32_T)((pinReadLoc_e & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S146>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S146>/Data Type Conversion1'
           */
          switch (rtb_Sum_cz) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S157>/Valid Halls' incorporates:
             *  ActionPort: '<S159>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S146>/Data Type Conversion2'
             */
            G431debug_ValidHalls((uint16_T)rtb_Sum_cz, (uint16_T)
                                 G431debug_DW.GlobalHallState,
                                 G431debug_DW.GlobalDirection, &rtb_Merge3,
                                 &G431debug_DW.GlobalDirection, &rtb_Merge_ce,
                                 &G431debug_B.ValidHalls_b,
                                 &G431debug_DW.ValidHalls_b,
                                 &G431debug_P.ValidHalls_b);

            /* End of Outputs for SubSystem: '<S157>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S157>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S158>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431debug_DW.GlobalDirection,
              &rtb_Merge_ce, &G431debug_DW.GlobalDirection, &rtb_Merge3,
              &G431debug_P.Badhallglitchorwrongconnectio_n);

            /* End of Outputs for SubSystem: '<S157>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S146>/Detects if the halls reading is valid' */

          /* MATLABSystem: '<S4>/Timer Capture' */
          getCCR4RegisterValuePollingMode(G431debug_DW.obj_e.TimerHandle,
            &rtb_Merge_ce, &pinReadLoc);

          /* Gain: '<S4>/Gain' incorporates:
           *  DataStoreRead: '<S4>/Data Store Read1'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  DataTypeConversion: '<S4>/Data Type Conversion1'
           *  DataTypeConversion: '<S4>/Data Type Conversion4'
           *  MATLABSystem: '<S4>/Timer Capture'
           *  Sum: '<S4>/Sum1'
           */
          G431debug_DW.Timehall = (uint32_T)(uint16_T)((int16_T)rtb_Merge_ce -
            G431debug_DW.Timercntprev) * G431debug_P.Gain_Gain_i;

          /* DataTypeConversion: '<S146>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  Gain: '<S4>/Gain'
           */
          G431debug_DW.GlobalSpeedCount = (uint16_T)(G431debug_DW.Timehall >> 15);

          /* DataTypeConversion: '<S157>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          G431debug_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S146>/Constant'
           */
          G431debug_DW.HallStateChangeFlag = G431debug_P.Constant_Value_pl;

          /* DataStoreWrite: '<S4>/Data Store Write6' */
          G431debug_DW.GlobalHallState = rtb_Sum_cz;

          /* DataStoreWrite: '<S147>/Data Store Write' incorporates:
           *  DataTypeConversion: '<S4>/Data Type Conversion1'
           *  MATLABSystem: '<S4>/Timer Capture'
           */
          G431debug_DW.Timercntprev = (int16_T)rtb_Merge_ce;

          /* DataStoreWrite: '<S4>/Data Store Write5' incorporates:
           *  Constant: '<S4>/Constant2'
           */
          G431debug_DW.HallAcapture = G431debug_P.Constant2_Value_p;
          G431debug_DW.HALL_C_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */
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
