/*
 * File: STMF4Hall.c
 *
 * Code generated for Simulink model 'STMF4Hall'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Sep 30 14:28:23 2024
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
static void STMF4Hall_SystemCore_setup_o(stm32cube_blocks_TimerBlock_S_T *obj);
static void STMF4Hall_SystemCore_setup(stm32cube_blocks_TimerBlock_S_T *obj);
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
 *    '<S104>/Hall Value of 1'
 *    '<S104>/Hall Value of 2'
 *    '<S104>/Hall Value of 3'
 *    '<S104>/Hall Value of 4'
 *    '<S104>/Hall Value of 5'
 *    '<S104>/Hall Value of 6'
 *    '<S104>/Hall Value of 7'
 *    '<S103>/Hall Value of 1'
 *    '<S103>/Hall Value of 2'
 *    '<S103>/Hall Value of 3'
 *    ...
 */
void STMF4Hall_HallValueof1(real32_T *rty_position, P_HallValueof1_STMF4Hall_T
  *localP)
{
  /* SignalConversion generated from: '<S114>/position' incorporates:
   *  Constant: '<S114>/Constant'
   */
  *rty_position = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S66>/If Action Subsystem6'
 *    '<S66>/If Action Subsystem7'
 *    '<S41>/If Action Subsystem6'
 *    '<S41>/If Action Subsystem7'
 *    '<S16>/If Action Subsystem6'
 *    '<S16>/If Action Subsystem7'
 */
void STMF4Hal_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_STMF4Hal_T *localP)
{
  /* SignalConversion generated from: '<S73>/direction' incorporates:
   *  Constant: '<S73>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S73>/sequence_check' incorporates:
   *  Constant: '<S73>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S66>/If Action Subsystem'
 *    '<S66>/If Action Subsystem1'
 *    '<S66>/If Action Subsystem2'
 *    '<S66>/If Action Subsystem3'
 *    '<S66>/If Action Subsystem4'
 *    '<S66>/If Action Subsystem5'
 *    '<S41>/If Action Subsystem'
 *    '<S41>/If Action Subsystem1'
 *    '<S41>/If Action Subsystem2'
 *    '<S41>/If Action Subsystem3'
 *    ...
 */
void STMF4Hall_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_STMF4Hall_T *localP)
{
  /* SignalConversion generated from: '<S67>/Out1' incorporates:
   *  Constant: '<S67>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S67>/Out2' incorporates:
   *  Constant: '<S67>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S64>/Valid Halls'
 *    '<S39>/Valid Halls'
 *    '<S14>/Valid Halls'
 */
void STMF4Hall_ValidHalls_Init(B_ValidHalls_STMF4Hall_T *localB,
  P_ValidHalls_STMF4Hall_T *localP)
{
  /* SystemInitialize for Merge: '<S66>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S66>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S66>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S66>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S64>/Valid Halls'
 *    '<S39>/Valid Halls'
 *    '<S14>/Valid Halls'
 */
void STMF4Hall_ValidHalls(uint16_T rtu_hallReading, uint16_T rtu_previousState,
  int16_T rtu_previous_direction, boolean_T *rty_directional_speed_valid_fla,
  int16_T *rty_direction, uint16_T *rty_inValidHall, B_ValidHalls_STMF4Hall_T
  *localB, DW_ValidHalls_STMF4Hall_T *localDW, P_ValidHalls_STMF4Hall_T *localP)
{
  /* SwitchCase: '<S66>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S68>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S69>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S70>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S71>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S72>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem5' */
    break;

   default:
    /* Update for IfAction SubSystem: '<S66>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S76>/Action Port'
     */
    /* Update for SwitchCase: '<S66>/Switch Case' */
    localDW->SwitchCaseActionSubsystem_Subsy = 4;

    /* End of Update for SubSystem: '<S66>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S66>/Switch Case' */

  /* If: '<S66>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    STMF4Hal_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    STMF4Hal_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S66>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    /* Merge: '<S66>/Merge3' incorporates:
     *  Constant: '<S75>/Constant'
     *  SignalConversion generated from: '<S75>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S66>/If Action Subsystem8' */

    /* Update for IfAction SubSystem: '<S66>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S75>/Action Port'
     */
    /* Update for If: '<S66>/If' */
    localDW->IfActionSubsystem8_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S66>/If Action Subsystem8' */
  }

  /* End of If: '<S66>/If' */

  /* SignalConversion: '<S66>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S66>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S66>/Switch' incorporates:
   *  Constant: '<S66>/Constant'
   *  RelationalOperator: '<S66>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_j;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S66>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S64>/Bad hall (glitch or wrong connection)'
 *    '<S39>/Bad hall (glitch or wrong connection)'
 *    '<S14>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S65>/inValidHall' incorporates:
   *  Constant: '<S65>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S65>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S65>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S65>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
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

static void STMF4Hall_SystemCore_setup(stm32cube_blocks_TimerBlock_S_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void STMF4Hall_step0(void)             /* Sample time: [5.0E-5s, 0.0s] */
{
  real32_T rtb_Merge1;
  int16_T rtb_RT;
  int16_T rtb_RT4;
  uint16_T Switch;
  uint16_T tmp;
  boolean_T OR;

  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.HallValueof1.HallValueof1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.veDirection_SubsysRanBC_c);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.veDirection_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.second_order_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.first_order_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.Subsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.SpeedanddirectionarevalidUsespe);

  /* Reset subsysRan breadcrumbs */
  srClearBC(STMF4Hall_DW.SpeedanddirectionarenotvalidPos);

  /* DataStoreRead: '<Root>/Data Store Read' */
  STMF4Hall_B.Halls = STMF4Hall_DW.Hall_State;

  /* MultiPortSwitch: '<S8>/Multiport Switch' */
  switch (STMF4Hall_B.Halls) {
   case 1:
    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/Constant8'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant1_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant8_Value;
    break;

   case 2:
    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Constant2'
     *  Constant: '<S8>/Constant9'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant2_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant9_Value;
    break;

   case 3:
    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Constant10'
     *  Constant: '<S8>/Constant3'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant3_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant10_Value;
    break;

   case 4:
    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Constant11'
     *  Constant: '<S8>/Constant4'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant4_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant11_Value;
    break;

   case 5:
    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Constant12'
     *  Constant: '<S8>/Constant5'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant5_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant12_Value;
    break;

   case 6:
    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Constant14'
     *  Constant: '<S8>/Constant6'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant6_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant14_Value;
    break;

   default:
    /* MultiPortSwitch: '<S8>/Multiport Switch' incorporates:
     *  Constant: '<S8>/Constant12'
     *  Constant: '<S8>/Constant7'
     */
    STMF4Hall_B.MultiportSwitch[0] = STMF4Hall_P.Constant7_Value;
    STMF4Hall_B.MultiportSwitch[1] = STMF4Hall_P.Constant12_Value;
    break;
  }

  /* End of MultiPortSwitch: '<S8>/Multiport Switch' */

  /* Outport: '<Root>/Hall state' */
  STMF4Hall_Y.Hallstate = STMF4Hall_B.MultiportSwitch[0];

  /* Outport: '<Root>/Hall angle' */
  STMF4Hall_Y.Hallangle = STMF4Hall_B.MultiportSwitch[1];

  /* RateTransition: '<Root>/RT4' */
  rtb_RT4 = STMF4Hall_B.Sum;

  /* RateTransition: '<Root>/RT' */
  rtb_RT = STMF4Hall_B.Sum_p;

  /* RateTransition: '<Root>/RT2' */
  STMF4Hall_B.gethalltimer = STMF4Hall_B.Sum_b;

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
  STMF4Hall_B.time3_k = getTimerCounterValue(STMF4Hall_DW.obj.TimerHandle);

  /* RateTransition generated from: '<Root>/Function-Call Subsystem1' */
  STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem1I = STMF4Hall_B.time3_k;

  /* RateTransition generated from: '<Root>/Function-Call Subsystem2' */
  STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem2I = STMF4Hall_B.time3_k;

  /* RateTransition generated from: '<Root>/Function-Call Subsystem' */
  STMF4Hall_DW.time3_Buffer0 = STMF4Hall_B.time3_k;

  /* Switch: '<S86>/Switch' incorporates:
   *  Constant: '<S86>/Order'
   */
  if (STMF4Hall_P.Order_Value > STMF4Hall_P.Switch_Threshold) {
    /* Switch: '<S86>/Switch' */
    Switch = 0U;
  } else {
    /* Switch: '<S86>/Switch' */
    Switch = STMF4Hall_P.Order_Value;
  }

  /* End of Switch: '<S86>/Switch' */

  /* Delay: '<S86>/validityDelay' incorporates:
   *  Delay: '<S86>/speedCountDelay'
   */
  if (Switch != 0) {
    /* Delay: '<S86>/validityDelay' */
    STMF4Hall_B.validityDelay = STMF4Hall_DW.validityDelay_DSTATE;
  }

  /* End of Delay: '<S86>/validityDelay' */

  /* Logic: '<S87>/OR' incorporates:
   *  Delay: '<S87>/Delay One Step1'
   */
  OR = STMF4Hall_DW.DelayOneStep1_DSTATE;

  /* Delay: '<S87>/Delay One Step' incorporates:
   *  Delay: '<S87>/Delay One Step1'
   *  Logic: '<S87>/OR'
   */
  if (STMF4Hall_DW.DelayOneStep1_DSTATE) {
    /* Delay: '<S87>/Delay One Step' */
    STMF4Hall_B.DelayOneStep = STMF4Hall_DW.DelayOneStep_DSTATE;
  }

  /* End of Delay: '<S87>/Delay One Step' */

  /* RelationalOperator: '<S91>/Compare' incorporates:
   *  Constant: '<S91>/Constant'
   *  Delay: '<S87>/Delay One Step1'
   */
  STMF4Hall_DW.DelayOneStep1_DSTATE = (STMF4Hall_B.DelayOneStep >
    STMF4Hall_P.Constant_Value_np);

  /* Switch: '<S90>/watchdog check' incorporates:
   *  Constant: '<S90>/Constant'
   *  Delay: '<S87>/Delay One Step1'
   */
  if (STMF4Hall_DW.DelayOneStep1_DSTATE) {
    /* Switch: '<S90>/speed check' incorporates:
     *  Constant: '<S90>/Constant'
     *  Logic: '<S86>/Logical Operator'
     *  MinMax: '<S90>/Max'
     */
    if (STMF4Hall_P.speedcheck_Threshold <= 0U) {
      tmp = STMF4Hall_P.Constant_Value_m;
    } else {
      tmp = STMF4Hall_B.validityDelay;
    }

    /* End of Switch: '<S90>/speed check' */
  } else {
    tmp = STMF4Hall_P.Constant_Value_m;
  }

  /* If: '<S5>/If' incorporates:
   *  Constant: '<S89>/PositionEnable'
   *  Switch: '<S90>/watchdog check'
   */
  if (tmp != 0) {
    /* Outputs for IfAction SubSystem: '<S5>/Speed and direction are valid Use speed to extrapolate position' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    /* Update for IfAction SubSystem: '<S89>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S101>/Action Port'
     */
    /* Update for If: '<S89>/If' */
    srUpdateBC(STMF4Hall_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S89>/If Action Subsystem1' */

    /* Outputs for Enabled SubSystem: '<S89>/Subsystem1' incorporates:
     *  EnablePort: '<S102>/Enable'
     */
    if (STMF4Hall_P.PositionEnable_Value > 0) {
      /* If: '<S102>/If1' incorporates:
       *  Constant: '<S102>/Constant'
       */
      if (STMF4Hall_P.Constant_Value > 1.0) {
        /* Update for IfAction SubSystem: '<S102>/second_order' incorporates:
         *  ActionPort: '<S106>/Action Port'
         */
        /* Update for If: '<S102>/If1' */
        srUpdateBC(STMF4Hall_DW.second_order_SubsysRanBC);

        /* End of Update for SubSystem: '<S102>/second_order' */
      } else {
        /* Update for IfAction SubSystem: '<S102>/first_order' incorporates:
         *  ActionPort: '<S105>/Action Port'
         */
        /* Update for If: '<S102>/If1' */
        srUpdateBC(STMF4Hall_DW.first_order_SubsysRanBC);

        /* End of Update for SubSystem: '<S102>/first_order' */
      }

      /* End of If: '<S102>/If1' */

      /* Outputs for IfAction SubSystem: '<S102>/-ve Direction' incorporates:
       *  ActionPort: '<S104>/Action Port'
       */
      /* Outputs for IfAction SubSystem: '<S104>/Hall Value of 7' incorporates:
       *  ActionPort: '<S120>/Action Port'
       */
      /* SwitchCase: '<S104>/Switch Case' incorporates:
       *  If: '<S102>/If'
       */
      STMF4Hall_HallValueof1(&rtb_Merge1, &STMF4Hall_P.HallValueof7);

      /* End of Outputs for SubSystem: '<S104>/Hall Value of 7' */
      /* End of Outputs for SubSystem: '<S102>/-ve Direction' */

      /* Update for IfAction SubSystem: '<S102>/-ve Direction' incorporates:
       *  ActionPort: '<S104>/Action Port'
       */
      /* Update for If: '<S102>/If' */
      srUpdateBC(STMF4Hall_DW.veDirection_SubsysRanBC_c);

      /* End of Update for SubSystem: '<S102>/-ve Direction' */
      srUpdateBC(STMF4Hall_DW.Subsystem1_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S89>/Subsystem1' */
    /* End of Outputs for SubSystem: '<S5>/Speed and direction are valid Use speed to extrapolate position' */

    /* Update for IfAction SubSystem: '<S5>/Speed and direction are valid Use speed to extrapolate position' incorporates:
     *  ActionPort: '<S89>/Action Port'
     */
    /* Update for If: '<S5>/If' incorporates:
     *  Constant: '<S89>/PositionEnable'
     */
    srUpdateBC(STMF4Hall_DW.SpeedanddirectionarevalidUsespe);

    /* End of Update for SubSystem: '<S5>/Speed and direction are valid Use speed to extrapolate position' */
  } else {
    /* Outputs for IfAction SubSystem: '<S5>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S92>/Hall Value of 7' incorporates:
     *  ActionPort: '<S99>/Action Port'
     */
    /* SwitchCase: '<S92>/Switch Case' */
    STMF4Hall_HallValueof1(&rtb_Merge1, &STMF4Hall_P.HallValueof7_a);

    /* End of Outputs for SubSystem: '<S92>/Hall Value of 7' */
    /* End of Outputs for SubSystem: '<S5>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */

    /* Update for IfAction SubSystem: '<S5>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
     *  ActionPort: '<S88>/Action Port'
     */
    /* Update for If: '<S5>/If' */
    srUpdateBC(STMF4Hall_DW.SpeedanddirectionarenotvalidPos);

    /* End of Update for SubSystem: '<S5>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
  }

  /* End of If: '<S5>/If' */

  /* MATLABSystem: '<Root>/Timer' */
  getTimerCounterValue(STMF4Hall_DW.obj_p.TimerHandle);

  /* Update for Delay: '<S86>/validityDelay' incorporates:
   *  DataTypeConversion: '<S86>/Data Type Conversion'
   *  Delay: '<S86>/speedCountDelay'
   */
  if (Switch != 0) {
    STMF4Hall_DW.validityDelay_DSTATE = false;
    STMF4Hall_DW.speedCountDelay_DSTATE = 0U;
  }

  /* End of Update for Delay: '<S86>/validityDelay' */

  /* Update for Delay: '<S87>/Delay One Step' incorporates:
   *  Constant: '<S87>/Constant2'
   *  Sum: '<S87>/Sum'
   */
  if (OR) {
    STMF4Hall_DW.DelayOneStep_DSTATE = (uint16_T)((uint32_T)
      STMF4Hall_B.DelayOneStep - STMF4Hall_P.Constant2_Value_m);
  }

  /* End of Update for Delay: '<S87>/Delay One Step' */

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

  /* MATLABSystem: '<S10>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S10>/Digital Port Write' */

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
  STMF4Hall_M->Sizes.checksums[0] = (3611993672U);
  STMF4Hall_M->Sizes.checksums[1] = (2235637706U);
  STMF4Hall_M->Sizes.checksums[2] = (427071602U);
  STMF4Hall_M->Sizes.checksums[3] = (247808379U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[101];
    STMF4Hall_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &STMF4Hall_DW.Badhallglitchorwrongconnecti_a1.Badhallglitchorwrongconnection_;
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
      &STMF4Hall_DW.Badhallglitchorwrongconnectio_a.Badhallglitchorwrongconnection_;
    systemRan[21] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.IfActionSubsystem8_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.SwitchCaseActionSubsystem_Subsy;
    systemRan[31] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.ValidHalls_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.ValidHalls_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_h.ValidHalls_SubsysRanBC;
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
    systemRan[56] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof1_j.HallValueof1_SubsysRanBC;
    systemRan[57] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof2_i.HallValueof1_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof3_h.HallValueof1_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof4_b.HallValueof1_SubsysRanBC;
    systemRan[60] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof5_k.HallValueof1_SubsysRanBC;
    systemRan[61] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof6_o.HallValueof1_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof7_a.HallValueof1_SubsysRanBC;
    systemRan[63] = (sysRanDType *)&STMF4Hall_DW.SpeedanddirectionarenotvalidPos;
    systemRan[64] = (sysRanDType *)&STMF4Hall_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[65] = (sysRanDType *)&STMF4Hall_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof1_b.HallValueof1_SubsysRanBC;
    systemRan[67] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof2_l.HallValueof1_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof3_d.HallValueof1_SubsysRanBC;
    systemRan[69] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof4_h.HallValueof1_SubsysRanBC;
    systemRan[70] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof5_j.HallValueof1_SubsysRanBC;
    systemRan[71] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof6_b.HallValueof1_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof7_e.HallValueof1_SubsysRanBC;
    systemRan[73] = (sysRanDType *)&STMF4Hall_DW.veDirection_SubsysRanBC;
    systemRan[74] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof1.HallValueof1_SubsysRanBC;
    systemRan[75] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof2.HallValueof1_SubsysRanBC;
    systemRan[76] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof3.HallValueof1_SubsysRanBC;
    systemRan[77] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof4.HallValueof1_SubsysRanBC;
    systemRan[78] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof5.HallValueof1_SubsysRanBC;
    systemRan[79] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof6.HallValueof1_SubsysRanBC;
    systemRan[80] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof7.HallValueof1_SubsysRanBC;
    systemRan[81] = (sysRanDType *)&STMF4Hall_DW.veDirection_SubsysRanBC_c;
    systemRan[82] = (sysRanDType *)&STMF4Hall_DW.first_order_SubsysRanBC;
    systemRan[83] = (sysRanDType *)&STMF4Hall_DW.second_order_SubsysRanBC;
    systemRan[84] = (sysRanDType *)&STMF4Hall_DW.Subsystem1_SubsysRanBC;
    systemRan[85] = (sysRanDType *)&STMF4Hall_DW.SpeedanddirectionarevalidUsespe;
    systemRan[86] = &rtAlwaysEnabled;
    systemRan[87] = &rtAlwaysEnabled;
    systemRan[88] = &rtAlwaysEnabled;
    systemRan[89] = &rtAlwaysEnabled;
    systemRan[90] = &rtAlwaysEnabled;
    systemRan[91] = &rtAlwaysEnabled;
    systemRan[92] = &rtAlwaysEnabled;
    systemRan[93] = &rtAlwaysEnabled;
    systemRan[94] = &rtAlwaysEnabled;
    systemRan[95] = &rtAlwaysEnabled;
    systemRan[96] = &rtAlwaysEnabled;
    systemRan[97] = &rtAlwaysEnabled;
    systemRan[98] = &rtAlwaysEnabled;
    systemRan[99] = &rtAlwaysEnabled;
    systemRan[100] = &rtAlwaysEnabled;
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
    STMF4Hall_DW.Hall_State = STMF4Hall_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    STMF4Hall_DW.Timehall = STMF4Hall_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    STMF4Hall_DW.Timercntprev = STMF4Hall_P.DataStoreMemory3_InitialValue;

    /* InitializeConditions for RateTransition generated from: '<Root>/Function-Call Subsystem1' */
    STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem1I =
      STMF4Hall_P.TmpRTBAtFunctionCallSubsystem1I;

    /* InitializeConditions for RateTransition generated from: '<Root>/Function-Call Subsystem2' */
    STMF4Hall_DW.TmpRTBAtFunctionCallSubsystem2I =
      STMF4Hall_P.TmpRTBAtFunctionCallSubsystem2I;

    /* InitializeConditions for RateTransition generated from: '<Root>/Function-Call Subsystem' */
    STMF4Hall_DW.time3_Buffer0 = STMF4Hall_P.time3_InitialCondition;

    /* InitializeConditions for Delay: '<S86>/validityDelay' */
    STMF4Hall_DW.validityDelay_DSTATE =
      STMF4Hall_P.validityDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S86>/speedCountDelay' */
    STMF4Hall_DW.speedCountDelay_DSTATE =
      STMF4Hall_P.speedCountDelay_InitialConditio;

    /* InitializeConditions for Delay: '<S87>/Delay One Step1' */
    STMF4Hall_DW.DelayOneStep1_DSTATE =
      STMF4Hall_P.DelayOneStep1_InitialCondition;

    /* InitializeConditions for Delay: '<S87>/Delay One Step' */
    STMF4Hall_DW.DelayOneStep_DSTATE =
      STMF4Hall_P.SoftwareWatchdogTimer_maxCount;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem2'
     */
    /* System initialize for function-call system: '<Root>/Function-Call Subsystem2' */
    STMF4Hall_M->Timing.clockTick2 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S64>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls, &STMF4Hall_P.ValidHalls);

    /* End of SystemInitialize for SubSystem: '<S64>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S4>/Out2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2_e2 = STMF4Hall_P.Constant_Value_e;

    /* SystemInitialize for Sum: '<S4>/Sum' incorporates:
     *  Outport: '<S4>/Out1'
     */
    STMF4Hall_B.Sum_b = STMF4Hall_P.Out1_Y0;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem1'
     */
    /* System initialize for function-call system: '<Root>/Function-Call Subsystem1' */
    STMF4Hall_M->Timing.clockTick3 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S39>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls_h,
      &STMF4Hall_P.ValidHalls_h);

    /* End of SystemInitialize for SubSystem: '<S39>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S3>/Out2' incorporates:
     *  Constant: '<S3>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2_e = STMF4Hall_P.Constant_Value_n;

    /* SystemInitialize for Sum: '<S3>/Sum' incorporates:
     *  Outport: '<S3>/Out1'
     */
    STMF4Hall_B.Sum_p = STMF4Hall_P.Out1_Y0_b;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Function-Call Subsystem'
     */

    /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
    STMF4Hall_M->Timing.clockTick4 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S14>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls_d,
      &STMF4Hall_P.ValidHalls_d);

    /* End of SystemInitialize for SubSystem: '<S14>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S2>/Out2' incorporates:
     *  Constant: '<S2>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2 = STMF4Hall_P.Constant_Value_f;

    /* SystemInitialize for Sum: '<S2>/Sum' incorporates:
     *  Outport: '<S2>/Out1'
     */
    STMF4Hall_B.Sum = STMF4Hall_P.Out1_Y0_l;

    /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */

    /* Start for MATLABSystem: '<Root>/Timer1' */
    STMF4Hall_DW.obj.isInitialized = 0;
    STMF4Hall_DW.obj.matlabCodegenIsDeleted = false;
    STMF4Hall_SystemCore_setup_o(&STMF4Hall_DW.obj);

    /* Start for MATLABSystem: '<Root>/Timer' */
    STMF4Hall_DW.obj_p.isInitialized = 0;
    STMF4Hall_DW.obj_p.matlabCodegenIsDeleted = false;
    STMF4Hall_SystemCore_setup(&STMF4Hall_DW.obj_p);

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* MATLABSystem: '<S128>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S130>/Digital Port Read' */
    pinReadLoc_0 = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S132>/Digital Port Read' */
    pinReadLoc_1 = LL_GPIO_ReadInputPort(GPIOC);

    /* Sum: '<S123>/Sum' incorporates:
     *  DataStoreWrite: '<S7>/Data Store Write'
     *  Gain: '<S123>/Gain'
     *  Gain: '<S123>/Gain1'
     *  Gain: '<S123>/Gain2'
     *  MATLABSystem: '<S128>/Digital Port Read'
     *  MATLABSystem: '<S130>/Digital Port Read'
     *  MATLABSystem: '<S132>/Digital Port Read'
     * */
    STMF4Hall_DW.Hall_State = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
      STMF4Hall_P.Gain_Gain_m >> 5 : 0) + (uint32_T)((pinReadLoc_0 & 2048U) !=
      0U ? STMF4Hall_P.Gain1_Gain_p >> 6 : 0)) + (uint32_T)((pinReadLoc_1 &
      4096U) != 0U ? STMF4Hall_P.Gain2_Gain_n >> 7 : 0));

    /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
  }
}

/* Model terminate function */
void STMF4Hall_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/Timer1' */
  if (!STMF4Hall_DW.obj.matlabCodegenIsDeleted) {
    STMF4Hall_DW.obj.matlabCodegenIsDeleted = true;
    if ((STMF4Hall_DW.obj.isInitialized == 1) &&
        STMF4Hall_DW.obj.isSetupComplete) {
      disableCounter(STMF4Hall_DW.obj.TimerHandle);
      disableTimerInterrupts(STMF4Hall_DW.obj.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Timer1' */
  /* Terminate for MATLABSystem: '<Root>/Timer' */
  if (!STMF4Hall_DW.obj_p.matlabCodegenIsDeleted) {
    STMF4Hall_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((STMF4Hall_DW.obj_p.isInitialized == 1) &&
        STMF4Hall_DW.obj_p.isSetupComplete) {
      disableCounter(STMF4Hall_DW.obj_p.TimerHandle);
      disableTimerInterrupts(STMF4Hall_DW.obj_p.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Timer' */
}

void STMF4Hall_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(55,&EXTI15_10_IRQHandler,2);
  MW_NVIC_EnableIRQ(55);
}

/* Hardware Interrupt Block: '<S122>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem2' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          int16_T rtb_Merge1;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick2 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S81>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S83>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S85>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S62>/Sum' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  Gain: '<S62>/Gain'
           *  Gain: '<S62>/Gain1'
           *  Gain: '<S62>/Gain2'
           *  MATLABSystem: '<S81>/Digital Port Read'
           *  MATLABSystem: '<S83>/Digital Port Read'
           *  MATLABSystem: '<S85>/Digital Port Read'
           * */
          STMF4Hall_DW.Hall_State = (uint8_T)(((uint32_T)((pinReadLoc & 1024U)
            != 0U ? STMF4Hall_P.Gain_Gain_g >> 5 : 0) + (uint32_T)((pinReadLoc_p
            & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain_c >> 6 : 0)) + (uint32_T)
            ((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain >> 7 : 0));

          /* Sum: '<S4>/Sum' incorporates:
           *  DataStoreRead: '<S4>/Data Store Read1'
           *  DataTypeConversion: '<S4>/Data Type Conversion'
           *  DataTypeConversion: '<S4>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum_b = (int16_T)((int16_T)STMF4Hall_B.time3 - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataStoreWrite: '<S63>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum_b;

          /* DataStoreWrite: '<S63>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3;

          /* SwitchCase: '<S61>/Detects if the halls reading is valid' incorporates:
           *  DataStoreRead: '<S4>/Data Store Read'
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  DataTypeConversion: '<S61>/Data Type Conversion1'
           *  DataTypeConversion: '<S61>/Data Type Conversion2'
           */
          switch (STMF4Hall_DW.Hall_State) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S64>/Valid Halls' incorporates:
             *  ActionPort: '<S66>/Action Port'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.Hall_State, (uint16_T)
                                 STMF4Hall_DW.Hall_State, 0, &rtb_Merge3,
                                 &rtb_Merge1, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls,
                                 &STMF4Hall_DW.ValidHalls,
                                 &STMF4Hall_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S64>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S64>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S65>/Action Port'
             */
            Badhallglitchorwrongconnect(0, &rtb_Merge, &rtb_Merge1, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnection);

            /* End of Outputs for SubSystem: '<S64>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S61>/Detects if the halls reading is valid' */

          /* SignalConversion generated from: '<S4>/Out2' incorporates:
           *  Constant: '<S4>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2_e2 = STMF4Hall_P.Constant_Value_e;
          STMF4Hall_DW.FunctionCallSubsystem2_SubsysRa = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          int16_T rtb_Merge1;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick3 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S56>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S58>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S60>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S37>/Sum' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  Gain: '<S37>/Gain'
           *  Gain: '<S37>/Gain1'
           *  Gain: '<S37>/Gain2'
           *  MATLABSystem: '<S56>/Digital Port Read'
           *  MATLABSystem: '<S58>/Digital Port Read'
           *  MATLABSystem: '<S60>/Digital Port Read'
           * */
          STMF4Hall_DW.Hall_State = (uint8_T)(((uint32_T)((pinReadLoc & 1024U)
            != 0U ? STMF4Hall_P.Gain_Gain_h >> 5 : 0) + (uint32_T)((pinReadLoc_p
            & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain_d >> 6 : 0)) + (uint32_T)
            ((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain_m >> 7 : 0));

          /* Sum: '<S3>/Sum' incorporates:
           *  DataStoreRead: '<S3>/Data Store Read1'
           *  DataTypeConversion: '<S3>/Data Type Conversion'
           *  DataTypeConversion: '<S3>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum_p = (int16_T)((int16_T)STMF4Hall_B.time3_g - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataStoreWrite: '<S38>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum_p;

          /* DataStoreWrite: '<S38>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3_g;

          /* SwitchCase: '<S36>/Detects if the halls reading is valid' incorporates:
           *  DataStoreRead: '<S3>/Data Store Read'
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  DataTypeConversion: '<S36>/Data Type Conversion1'
           *  DataTypeConversion: '<S36>/Data Type Conversion2'
           */
          switch (STMF4Hall_DW.Hall_State) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S39>/Valid Halls' incorporates:
             *  ActionPort: '<S41>/Action Port'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.Hall_State, (uint16_T)
                                 STMF4Hall_DW.Hall_State, 0, &rtb_Merge3,
                                 &rtb_Merge1, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls_h,
                                 &STMF4Hall_DW.ValidHalls_h,
                                 &STMF4Hall_P.ValidHalls_h);

            /* End of Outputs for SubSystem: '<S39>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S39>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S40>/Action Port'
             */
            Badhallglitchorwrongconnect(0, &rtb_Merge, &rtb_Merge1, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnectio_a);

            /* End of Outputs for SubSystem: '<S39>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S36>/Detects if the halls reading is valid' */

          /* SignalConversion generated from: '<S3>/Out2' incorporates:
           *  Constant: '<S3>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2_e = STMF4Hall_P.Constant_Value_n;
          STMF4Hall_DW.FunctionCallSubsystem1_SubsysRa = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */
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

        /* S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          int16_T rtb_Merge1;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick4 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S31>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S33>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S35>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S12>/Sum' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  Gain: '<S12>/Gain'
           *  Gain: '<S12>/Gain1'
           *  Gain: '<S12>/Gain2'
           *  MATLABSystem: '<S31>/Digital Port Read'
           *  MATLABSystem: '<S33>/Digital Port Read'
           *  MATLABSystem: '<S35>/Digital Port Read'
           * */
          STMF4Hall_DW.Hall_State = (uint8_T)(((uint32_T)((pinReadLoc & 1024U)
            != 0U ? STMF4Hall_P.Gain_Gain_a >> 5 : 0) + (uint32_T)((pinReadLoc_p
            & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain_i >> 6 : 0)) + (uint32_T)
            ((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain_f >> 7 : 0));

          /* Sum: '<S2>/Sum' incorporates:
           *  DataStoreRead: '<S2>/Data Store Read1'
           *  DataTypeConversion: '<S2>/Data Type Conversion'
           *  DataTypeConversion: '<S2>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum = (int16_T)((int16_T)STMF4Hall_B.time3_gw - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataStoreWrite: '<S13>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum;

          /* DataStoreWrite: '<S13>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3_gw;

          /* SwitchCase: '<S11>/Detects if the halls reading is valid' incorporates:
           *  DataStoreRead: '<S2>/Data Store Read'
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  DataTypeConversion: '<S11>/Data Type Conversion1'
           *  DataTypeConversion: '<S11>/Data Type Conversion2'
           */
          switch (STMF4Hall_DW.Hall_State) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S14>/Valid Halls' incorporates:
             *  ActionPort: '<S16>/Action Port'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.Hall_State, (uint16_T)
                                 STMF4Hall_DW.Hall_State, 0, &rtb_Merge3,
                                 &rtb_Merge1, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls_d,
                                 &STMF4Hall_DW.ValidHalls_d,
                                 &STMF4Hall_P.ValidHalls_d);

            /* End of Outputs for SubSystem: '<S14>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S14>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S15>/Action Port'
             */
            Badhallglitchorwrongconnect(0, &rtb_Merge, &rtb_Merge1, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnecti_a1);

            /* End of Outputs for SubSystem: '<S14>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S11>/Detects if the halls reading is valid' */

          /* SignalConversion generated from: '<S2>/Out2' incorporates:
           *  Constant: '<S2>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2 = STMF4Hall_P.Constant_Value_f;
          STMF4Hall_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S122>/Hardware Interrupt' */
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

void STMF4Hall_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(55);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
