/*
 * File: STMF4Hall.c
 *
 * Code generated for Simulink model 'STMF4Hall'.
 *
 * Model version                  : 1.33
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Oct  9 10:59:32 2024
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
B_STMF4Hall_T STMF4Hall_B;

/* Block states (default storage) */
DW_STMF4Hall_T STMF4Hall_DW;

/* External outputs (root outports fed by signals with default storage) */
ExtY_STMF4Hall_T STMF4Hall_Y;

/* Real-time model */
static RT_MODEL_STMF4Hall_T STMF4Hall_M_;
RT_MODEL_STMF4Hall_T *const STMF4Hall_M = &STMF4Hall_M_;

/* Forward declaration for local functions */
static void STMF4Hall_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_ST_T *obj);
static void STMF4Hall_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);

/* Forward declaration for local functions */
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
 *    '<S151>/If Action Subsystem6'
 *    '<S151>/If Action Subsystem7'
 *    '<S126>/If Action Subsystem6'
 *    '<S126>/If Action Subsystem7'
 *    '<S101>/If Action Subsystem6'
 *    '<S101>/If Action Subsystem7'
 */
void STMF4Hal_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_STMF4Hal_T *localP)
{
  /* SignalConversion generated from: '<S158>/direction' incorporates:
   *  Constant: '<S158>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S158>/sequence_check' incorporates:
   *  Constant: '<S158>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S151>/If Action Subsystem'
 *    '<S151>/If Action Subsystem1'
 *    '<S151>/If Action Subsystem2'
 *    '<S151>/If Action Subsystem3'
 *    '<S151>/If Action Subsystem4'
 *    '<S151>/If Action Subsystem5'
 *    '<S126>/If Action Subsystem'
 *    '<S126>/If Action Subsystem1'
 *    '<S126>/If Action Subsystem2'
 *    '<S126>/If Action Subsystem3'
 *    ...
 */
void STMF4Hall_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_STMF4Hall_T *localP)
{
  /* SignalConversion generated from: '<S152>/Out1' incorporates:
   *  Constant: '<S152>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S152>/Out2' incorporates:
   *  Constant: '<S152>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S149>/Valid Halls'
 *    '<S124>/Valid Halls'
 *    '<S99>/Valid Halls'
 */
void STMF4Hall_ValidHalls_Init(B_ValidHalls_STMF4Hall_T *localB,
  P_ValidHalls_STMF4Hall_T *localP)
{
  /* SystemInitialize for Merge: '<S151>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S151>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S151>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S151>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S149>/Valid Halls'
 *    '<S124>/Valid Halls'
 *    '<S99>/Valid Halls'
 */
void STMF4Hall_ValidHalls(uint16_T rtu_hallReading, uint16_T rtu_previousState,
  int16_T rtu_previous_direction, boolean_T *rty_directional_speed_valid_fla,
  int16_T *rty_direction, uint16_T *rty_inValidHall, B_ValidHalls_STMF4Hall_T
  *localB, DW_ValidHalls_STMF4Hall_T *localDW, P_ValidHalls_STMF4Hall_T *localP)
{
  /* SwitchCase: '<S151>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    STMF4Hall_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem5' */
    break;

   default:
    /* Update for IfAction SubSystem: '<S151>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S161>/Action Port'
     */
    /* Update for SwitchCase: '<S151>/Switch Case' */
    localDW->SwitchCaseActionSubsystem_Subsy = 4;

    /* End of Update for SubSystem: '<S151>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S151>/Switch Case' */

  /* If: '<S151>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    STMF4Hal_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S159>/Action Port'
     */
    STMF4Hal_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S151>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    /* Merge: '<S151>/Merge3' incorporates:
     *  Constant: '<S160>/Constant'
     *  SignalConversion generated from: '<S160>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S151>/If Action Subsystem8' */

    /* Update for IfAction SubSystem: '<S151>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    /* Update for If: '<S151>/If' */
    localDW->IfActionSubsystem8_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S151>/If Action Subsystem8' */
  }

  /* End of If: '<S151>/If' */

  /* SignalConversion: '<S151>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S151>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S151>/Switch' incorporates:
   *  Constant: '<S151>/Constant'
   *  RelationalOperator: '<S151>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_i;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S151>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S149>/Bad hall (glitch or wrong connection)'
 *    '<S124>/Bad hall (glitch or wrong connection)'
 *    '<S99>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S150>/inValidHall' incorporates:
   *  Constant: '<S150>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S150>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S150>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S150>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S79>/Hall Value of 1'
 *    '<S79>/Hall Value of 2'
 *    '<S79>/Hall Value of 3'
 *    '<S79>/Hall Value of 4'
 *    '<S79>/Hall Value of 5'
 *    '<S79>/Hall Value of 6'
 *    '<S79>/Hall Value of 7'
 *    '<S78>/Hall Value of 1'
 *    '<S78>/Hall Value of 2'
 *    '<S78>/Hall Value of 3'
 *    ...
 */
void STMF4Hall_HallValueof1(real32_T *rty_position, P_HallValueof1_STMF4Hall_T
  *localP)
{
  /* SignalConversion generated from: '<S89>/position' incorporates:
   *  Constant: '<S89>/Constant'
   */
  *rty_position = localP->Constant_Value;
}

static void STMF4Hall_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_ST_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S58>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S58>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S58>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void STMF4Hall_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
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
  real_T Exitnumber;
  int16_T rtb_RT;
  int16_T rtb_RT4;

  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* DataStoreWrite: '<Root>/Data Store Write3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  STMF4Hall_DW.Enable = STMF4Hall_P.Constant_Value_k;

  /* RateTransition: '<Root>/RT3' incorporates:
   *  DataStoreWrite: '<Root>/Data Store Write2'
   */
  Exitnumber = STMF4Hall_B.OutportBufferForOut2_e2;

  /* RateTransition: '<Root>/RT6' */
  STMF4Hall_B.testcounter = STMF4Hall_B.Output;

  /* RateTransition: '<Root>/RT4' */
  rtb_RT4 = STMF4Hall_B.Sum;

  /* RateTransition: '<Root>/RT' */
  rtb_RT = STMF4Hall_B.Sum_c;

  /* RateTransition: '<Root>/RT2' */
  STMF4Hall_B.gethalltimer = STMF4Hall_B.Sum_i;

  /* MultiPortSwitch: '<Root>/Multiport Switch' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read2'
   */
  switch ((int32_T)Exitnumber) {
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

  /* RateTransition generated from: '<Root>/Hall sensor B' */
  STMF4Hall_DW.TmpRTBAtHallsensorBInport1_Buff = STMF4Hall_B.time3_k;

  /* RateTransition generated from: '<Root>/Hall sensor C' */
  STMF4Hall_DW.TmpRTBAtHallsensorCInport1_Buff = STMF4Hall_B.time3_k;

  /* RateTransition generated from: '<Root>/Hall sensor A' */
  STMF4Hall_DW.time3_Buffer0 = STMF4Hall_B.time3_k;

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

  /* MATLABSystem: '<S176>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0.0) {
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
  STMF4Hall_M->Timing.clockTick1++;
}

/* Model initialize function */
void STMF4Hall_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(STMF4Hall_M, -1);
  STMF4Hall_M->Timing.stepSize0 = 5.0E-5;

  /* External mode info */
  STMF4Hall_M->Sizes.checksums[0] = (64047783U);
  STMF4Hall_M->Sizes.checksums[1] = (4087948327U);
  STMF4Hall_M->Sizes.checksums[2] = (2525882293U);
  STMF4Hall_M->Sizes.checksums[3] = (1047551597U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[116];
    STMF4Hall_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&STMF4Hall_DW.Subsystem_SubsysRanBC_l;
    systemRan[3] = (sysRanDType *)&STMF4Hall_DW.Subsystem_SubsysRanBC_l;
    systemRan[4] = (sysRanDType *)&STMF4Hall_DW.Subsystem_SubsysRanBC_l;
    systemRan[5] = (sysRanDType *)&STMF4Hall_DW.FindOffset_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&STMF4Hall_DW.Subsystem_SubsysRanBC_p;
    systemRan[9] = (sysRanDType *)&STMF4Hall_DW.IfActionSubsystem_SubsysRanBC_n;
    systemRan[10] = (sysRanDType *)&STMF4Hall_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&STMF4Hall_DW.Subsystem_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&STMF4Hall_DW.Accumulate_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&STMF4Hall_DW.UpCounter_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&STMF4Hall_DW.PosGen_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&STMF4Hall_DW.IfActionSubsystem_SubsysRanBC_j;
    systemRan[16] = (sysRanDType *)&STMF4Hall_DW.IfActionSubsystem1_SubsysRanB_e;
    systemRan[17] = (sysRanDType *)&STMF4Hall_DW.Subsystem1_SubsysRanBC_f;
    systemRan[18] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[21] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof1_a.HallValueof1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof2_n.HallValueof1_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof3_m.HallValueof1_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof4_n.HallValueof1_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof5_o.HallValueof1_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof6_d.HallValueof1_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof7_n.HallValueof1_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&STMF4Hall_DW.SpeedanddirectionarenotvalidPos;
    systemRan[30] = (sysRanDType *)&STMF4Hall_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[31] = (sysRanDType *)&STMF4Hall_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof1_d.HallValueof1_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof2_i.HallValueof1_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof3_k.HallValueof1_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof4_l.HallValueof1_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof5_h.HallValueof1_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof6_i.HallValueof1_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof7_h.HallValueof1_SubsysRanBC;
    systemRan[39] = (sysRanDType *)&STMF4Hall_DW.veDirection_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof1.HallValueof1_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof2.HallValueof1_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof3.HallValueof1_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof4.HallValueof1_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof5.HallValueof1_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof6.HallValueof1_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &STMF4Hall_DW.HallValueof7.HallValueof1_SubsysRanBC;
    systemRan[47] = (sysRanDType *)&STMF4Hall_DW.veDirection_SubsysRanBC_n;
    systemRan[48] = (sysRanDType *)&STMF4Hall_DW.first_order_SubsysRanBC;
    systemRan[49] = (sysRanDType *)&STMF4Hall_DW.second_order_SubsysRanBC;
    systemRan[50] = (sysRanDType *)&STMF4Hall_DW.Subsystem1_SubsysRanBC;
    systemRan[51] = (sysRanDType *)&STMF4Hall_DW.SpeedanddirectionarevalidUsespe;
    systemRan[52] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[53] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[54] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[55] = (sysRanDType *)&STMF4Hall_DW.ADCSIC_SubsysRanBC;
    systemRan[56] = (sysRanDType *)
      &STMF4Hall_DW.Badhallglitchorwrongconnectio_a.Badhallglitchorwrongconnection_;
    systemRan[57] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[60] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[61] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[65] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.IfActionSubsystem8_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.SwitchCaseActionSubsystem_Subsy;
    systemRan[67] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.ValidHalls_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.ValidHalls_SubsysRanBC;
    systemRan[69] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_d.ValidHalls_SubsysRanBC;
    systemRan[70] = (sysRanDType *)&STMF4Hall_DW.HallsensorA_SubsysRanBC;
    systemRan[71] = (sysRanDType *)&STMF4Hall_DW.HallsensorA_SubsysRanBC;
    systemRan[72] = (sysRanDType *)&STMF4Hall_DW.HallsensorA_SubsysRanBC;
    systemRan[73] = (sysRanDType *)&STMF4Hall_DW.HallsensorA_SubsysRanBC;
    systemRan[74] = (sysRanDType *)
      &STMF4Hall_DW.Badhallglitchorwrongconnectio_c.Badhallglitchorwrongconnection_;
    systemRan[75] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[76] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[77] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[78] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[79] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[80] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[81] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[82] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[83] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.IfActionSubsystem8_SubsysRanBC;
    systemRan[84] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.SwitchCaseActionSubsystem_Subsy;
    systemRan[85] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.ValidHalls_SubsysRanBC;
    systemRan[86] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.ValidHalls_SubsysRanBC;
    systemRan[87] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls_l.ValidHalls_SubsysRanBC;
    systemRan[88] = (sysRanDType *)&STMF4Hall_DW.HallsensorB_SubsysRanBC;
    systemRan[89] = (sysRanDType *)&STMF4Hall_DW.HallsensorB_SubsysRanBC;
    systemRan[90] = (sysRanDType *)&STMF4Hall_DW.HallsensorB_SubsysRanBC;
    systemRan[91] = (sysRanDType *)&STMF4Hall_DW.HallsensorB_SubsysRanBC;
    systemRan[92] = (sysRanDType *)
      &STMF4Hall_DW.Badhallglitchorwrongconnection.Badhallglitchorwrongconnection_;
    systemRan[93] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[94] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[95] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[96] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[97] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[98] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[99] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[100] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[101] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC;
    systemRan[102] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy;
    systemRan[103] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[104] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[105] = (sysRanDType *)
      &STMF4Hall_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[106] = (sysRanDType *)&STMF4Hall_DW.HallsensorC_SubsysRanBC;
    systemRan[107] = (sysRanDType *)&STMF4Hall_DW.HallsensorC_SubsysRanBC;
    systemRan[108] = (sysRanDType *)&STMF4Hall_DW.HallsensorC_SubsysRanBC;
    systemRan[109] = (sysRanDType *)&STMF4Hall_DW.HallsensorC_SubsysRanBC;
    systemRan[110] = &rtAlwaysEnabled;
    systemRan[111] = &rtAlwaysEnabled;
    systemRan[112] = &rtAlwaysEnabled;
    systemRan[113] = &rtAlwaysEnabled;
    systemRan[114] = &rtAlwaysEnabled;
    systemRan[115] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(STMF4Hall_M->extModeInfo,
      &STMF4Hall_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(STMF4Hall_M->extModeInfo, STMF4Hall_M->Sizes.checksums);
    rteiSetTPtr(STMF4Hall_M->extModeInfo, rtmGetTPtr(STMF4Hall_M));
  }

  {
    uint32_T pinReadLoc;
    uint32_T pinReadLoc_0;
    uint32_T pinReadLoc_1;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
    STMF4Hall_DW.Enable = STMF4Hall_P.DataStoreMemory9_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    STMF4Hall_DW.GlobalHallState = STMF4Hall_P.DataStoreMemory_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory12' */
    STMF4Hall_DW.HallCcapture = STMF4Hall_P.DataStoreMemory12_InitialValue;

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

    /* Start for DataStoreMemory: '<Root>/Data Store Memory11' */
    STMF4Hall_DW.HallBcapture = STMF4Hall_P.DataStoreMemory11_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
    STMF4Hall_DW.HallAcapture = STMF4Hall_P.DataStoreMemory10_InitialValue;

    /* InitializeConditions for RateTransition generated from: '<Root>/Hall sensor B' */
    STMF4Hall_DW.TmpRTBAtHallsensorBInport1_Buff =
      STMF4Hall_P.TmpRTBAtHallsensorBInport1_Init;

    /* InitializeConditions for RateTransition generated from: '<Root>/Hall sensor C' */
    STMF4Hall_DW.TmpRTBAtHallsensorCInport1_Buff =
      STMF4Hall_P.TmpRTBAtHallsensorCInport1_Init;

    /* InitializeConditions for RateTransition generated from: '<Root>/Hall sensor A' */
    STMF4Hall_DW.time3_Buffer0 = STMF4Hall_P.time3_InitialCondition;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S174>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/ADC SIC'
     */

    /* System initialize for function-call system: '<Root>/ADC SIC' */
    STMF4Hall_M->Timing.clockTick5 = STMF4Hall_M->Timing.clockTick0;

    /* InitializeConditions for Delay: '<S61>/validityDelay' */
    STMF4Hall_DW.validityDelay_DSTATE =
      STMF4Hall_P.validityDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S61>/speedCountDelay' */
    STMF4Hall_DW.speedCountDelay_DSTATE =
      STMF4Hall_P.speedCountDelay_InitialConditio;

    /* InitializeConditions for RelationalOperator: '<S66>/Compare' incorporates:
     *  Delay: '<S62>/Delay One Step1'
     */
    STMF4Hall_DW.DelayOneStep1_DSTATE =
      STMF4Hall_P.DelayOneStep1_InitialCondition;

    /* InitializeConditions for Delay: '<S62>/Delay One Step' */
    STMF4Hall_DW.DelayOneStep_DSTATE =
      STMF4Hall_P.SoftwareWatchdogTimer_maxCount;

    /* InitializeConditions for UnitDelay: '<S11>/Output' */
    STMF4Hall_DW.Output_DSTATE = STMF4Hall_P.Output_InitialCondition;

    /* SystemInitialize for IfAction SubSystem: '<S60>/Speed and direction are valid Use speed to extrapolate position' */
    /* SystemInitialize for Enabled SubSystem: '<S64>/Subsystem1' */
    /* SystemInitialize for Merge: '<S77>/Merge' */
    STMF4Hall_B.Merge = STMF4Hall_P.Merge_InitialOutput;

    /* End of SystemInitialize for SubSystem: '<S64>/Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<S60>/Speed and direction are valid Use speed to extrapolate position' */

    /* SystemInitialize for Enabled SubSystem: '<S10>/Find Offset' */
    /* InitializeConditions for Delay: '<S18>/Delay' */
    STMF4Hall_DW.Delay_DSTATE_k = STMF4Hall_P.Delay_InitialCondition;

    /* SystemInitialize for Enabled SubSystem: '<S18>/Subsystem' */
    /* InitializeConditions for UnitDelay: '<S30>/Unit Delay' */
    STMF4Hall_DW.UnitDelay_DSTATE_j = STMF4Hall_P.UnitDelay_InitialCondition;

    /* End of SystemInitialize for SubSystem: '<S18>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S10>/Find Offset' */

    /* SystemInitialize for Enabled SubSystem: '<S10>/PosGen' */
    /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
    STMF4Hall_DW.UnitDelay_DSTATE = STMF4Hall_P.UnitDelay_InitialCondition_o;

    /* SystemInitialize for IfAction SubSystem: '<S36>/If Action Subsystem2' */
    /* InitializeConditions for Saturate: '<S39>/Saturate to 'motor.calibSpeed' RPM' incorporates:
     *  Delay: '<S39>/Delay'
     */
    STMF4Hall_DW.Delay_DSTATE = STMF4Hall_P.Delay_InitialCondition_p;

    /* End of SystemInitialize for SubSystem: '<S36>/If Action Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S40>/Accumulate' */
    /* InitializeConditions for Delay: '<S41>/Delay' */
    STMF4Hall_DW.Delay_DSTATE_o = STMF4Hall_P.Delay_InitialCondition_h;

    /* SystemInitialize for Enabled SubSystem: '<S41>/Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S42>/Input' incorporates:
     *  Outport: '<S42>/Out1'
     */
    STMF4Hall_B.Input = STMF4Hall_P.Out1_Y0;

    /* End of SystemInitialize for SubSystem: '<S41>/Subsystem' */

    /* SystemInitialize for Sum: '<S41>/Add1' incorporates:
     *  Outport: '<S41>/theta_e'
     */
    STMF4Hall_B.Add1_h = STMF4Hall_P.theta_e_Y0;

    /* End of SystemInitialize for SubSystem: '<S40>/Accumulate' */

    /* SystemInitialize for Enabled SubSystem: '<S20>/Up Counter' */
    /* InitializeConditions for Delay: '<S37>/Delay' */
    STMF4Hall_DW.Delay_DSTATE_a = STMF4Hall_P.Delay_InitialCondition_m;

    /* SystemInitialize for Sum: '<S37>/Add1' incorporates:
     *  Outport: '<S37>/Count'
     */
    STMF4Hall_B.Add1 = STMF4Hall_P.Count_Y0;

    /* End of SystemInitialize for SubSystem: '<S20>/Up Counter' */

    /* SystemInitialize for Gain: '<S40>/scaleOut' incorporates:
     *  Outport: '<S20>/Theta'
     */
    STMF4Hall_B.scaleOut = STMF4Hall_P.Theta_Y0;

    /* SystemInitialize for RelationalOperator: '<S34>/Compare' incorporates:
     *  Outport: '<S20>/EnPWM'
     */
    STMF4Hall_B.Compare = STMF4Hall_P.EnPWM_Y0;

    /* End of SystemInitialize for SubSystem: '<S10>/PosGen' */

    /* Start for MATLABSystem: '<S58>/PWM Output' */
    STMF4Hall_DW.obj_l.matlabCodegenIsDeleted = false;
    STMF4Hall_DW.obj_l.isSetupComplete = false;
    STMF4Hall_DW.obj_l.isInitialized = 1;
    STMF4Hall_PWMOutput_setupImpl(&STMF4Hall_DW.obj_l);
    STMF4Hall_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<S17>/Analog to Digital Converter' */
    STMF4Hall_DW.obj.isInitialized = 0;
    STMF4Hall_DW.obj.matlabCodegenIsDeleted = false;
    STMF4Hall_SystemCore_setup(&STMF4Hall_DW.obj);

    /* SystemInitialize for UnitDelay: '<S11>/Output' incorporates:
     *  Outport: '<S1>/Out1'
     */
    STMF4Hall_B.Output = STMF4Hall_P.Out1_Y0_hj;

    /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S174>/Hardware Interrupt' */

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Hall sensor C'
     */
    /* System initialize for function-call system: '<Root>/Hall sensor C' */
    STMF4Hall_M->Timing.clockTick2 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S149>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls, &STMF4Hall_P.ValidHalls);

    /* End of SystemInitialize for SubSystem: '<S149>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S4>/Out2' incorporates:
     *  Constant: '<S4>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2_e2 = STMF4Hall_P.Constant_Value;

    /* SystemInitialize for Sum: '<S4>/Sum' incorporates:
     *  Outport: '<S4>/Out1'
     */
    STMF4Hall_B.Sum_i = STMF4Hall_P.Out1_Y0_m;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Hall sensor B'
     */
    /* System initialize for function-call system: '<Root>/Hall sensor B' */
    STMF4Hall_M->Timing.clockTick3 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S124>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls_l,
      &STMF4Hall_P.ValidHalls_l);

    /* End of SystemInitialize for SubSystem: '<S124>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S3>/Out2' incorporates:
     *  Constant: '<S3>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2_e = STMF4Hall_P.Constant_Value_p;

    /* SystemInitialize for Sum: '<S3>/Sum' incorporates:
     *  Outport: '<S3>/Out1'
     */
    STMF4Hall_B.Sum_c = STMF4Hall_P.Out1_Y0_h;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Hall sensor A'
     */

    /* System initialize for function-call system: '<Root>/Hall sensor A' */
    STMF4Hall_M->Timing.clockTick4 = STMF4Hall_M->Timing.clockTick0;

    /* SystemInitialize for IfAction SubSystem: '<S99>/Valid Halls' */
    STMF4Hall_ValidHalls_Init(&STMF4Hall_B.ValidHalls_d,
      &STMF4Hall_P.ValidHalls_d);

    /* End of SystemInitialize for SubSystem: '<S99>/Valid Halls' */

    /* SystemInitialize for SignalConversion generated from: '<S2>/Out2' incorporates:
     *  Constant: '<S2>/Constant'
     */
    STMF4Hall_B.OutportBufferForOut2 = STMF4Hall_P.Constant_Value_f;

    /* SystemInitialize for Sum: '<S2>/Sum' incorporates:
     *  Outport: '<S2>/Out1'
     */
    STMF4Hall_B.Sum = STMF4Hall_P.Out1_Y0_l;

    /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' */

    /* Start for MATLABSystem: '<Root>/Timer1' */
    STMF4Hall_DW.obj_b.isInitialized = 0;
    STMF4Hall_DW.obj_b.matlabCodegenIsDeleted = false;
    STMF4Hall_SystemCore_setup_o(&STMF4Hall_DW.obj_b);

    /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
    /* MATLABSystem: '<S182>/Digital Port Read' */
    pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S184>/Digital Port Read' */
    pinReadLoc_0 = LL_GPIO_ReadInputPort(GPIOC);

    /* MATLABSystem: '<S186>/Digital Port Read' */
    pinReadLoc_1 = LL_GPIO_ReadInputPort(GPIOC);

    /* Sum: '<S177>/Sum' incorporates:
     *  DataStoreWrite: '<S8>/Data Store Write'
     *  Gain: '<S177>/Gain'
     *  Gain: '<S177>/Gain1'
     *  Gain: '<S177>/Gain2'
     *  MATLABSystem: '<S182>/Digital Port Read'
     *  MATLABSystem: '<S184>/Digital Port Read'
     *  MATLABSystem: '<S186>/Digital Port Read'
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
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S174>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S174>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */
  /* Termination for function-call system: '<Root>/ADC SIC' */

  /* Terminate for MATLABSystem: '<S58>/PWM Output' */
  if (!STMF4Hall_DW.obj_l.matlabCodegenIsDeleted) {
    STMF4Hall_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((STMF4Hall_DW.obj_l.isInitialized == 1) &&
        STMF4Hall_DW.obj_l.isSetupComplete) {
      disableCounter(STMF4Hall_DW.obj_l.TimerHandle);
      disableTimerInterrupts(STMF4Hall_DW.obj_l.TimerHandle, 0);
      disableTimerChannel1(STMF4Hall_DW.obj_l.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel2(STMF4Hall_DW.obj_l.TimerHandle, ENABLE_CH_CHN);
      disableTimerChannel3(STMF4Hall_DW.obj_l.TimerHandle, ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S58>/PWM Output' */

  /* Terminate for MATLABSystem: '<S17>/Analog to Digital Converter' */
  if (!STMF4Hall_DW.obj.matlabCodegenIsDeleted) {
    STMF4Hall_DW.obj.matlabCodegenIsDeleted = true;
    if ((STMF4Hall_DW.obj.isInitialized == 1) &&
        STMF4Hall_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(STMF4Hall_DW.obj.ADCHandle, ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S17>/Analog to Digital Converter' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S174>/Hardware Interrupt' */

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
}

void STMF4Hall_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,3);
  MW_NVIC_EnableIRQ(33);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(55,&EXTI15_10_IRQHandler,2);
  MW_NVIC_EnableIRQ(55);
}

/* Hardware Interrupt Block: '<S172>/Hardware Interrupt' */
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
        srClearBC(STMF4Hall_DW.HallsensorC_SubsysRanBC);

        /* RateTransition generated from: '<Root>/Hall sensor C' */
        STMF4Hall_B.time3 = STMF4Hall_DW.TmpRTBAtHallsensorCInport1_Buff;

        /* S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Hall sensor C' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick2 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S166>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S168>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S170>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S147>/Sum' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  Gain: '<S147>/Gain'
           *  Gain: '<S147>/Gain1'
           *  Gain: '<S147>/Gain2'
           *  MATLABSystem: '<S166>/Digital Port Read'
           *  MATLABSystem: '<S168>/Digital Port Read'
           *  MATLABSystem: '<S170>/Digital Port Read'
           * */
          STMF4Hall_DW.GlobalHallState = (uint8_T)(((uint32_T)((pinReadLoc &
            1024U) != 0U ? STMF4Hall_P.Gain_Gain_h >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain_k >> 6 : 0))
            + (uint32_T)((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain >>
                         7 : 0));

          /* SwitchCase: '<S146>/Detects if the halls reading is valid' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  DataTypeConversion: '<S146>/Data Type Conversion1'
           */
          switch (STMF4Hall_DW.GlobalHallState) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S149>/Valid Halls' incorporates:
             *  ActionPort: '<S151>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S146>/Data Type Conversion2'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.GlobalHallState,
                                 (uint16_T)STMF4Hall_DW.GlobalHallState,
                                 STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
                                 &STMF4Hall_DW.GlobalDirection, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls,
                                 &STMF4Hall_DW.ValidHalls,
                                 &STMF4Hall_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S149>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S149>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S150>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(STMF4Hall_DW.GlobalDirection, &rtb_Merge,
              &STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnection);

            /* End of Outputs for SubSystem: '<S149>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S146>/Detects if the halls reading is valid' */

          /* Sum: '<S4>/Sum' incorporates:
           *  DataStoreRead: '<S4>/Data Store Read1'
           *  DataTypeConversion: '<S4>/Data Type Conversion'
           *  DataTypeConversion: '<S4>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum_i = (int16_T)((int16_T)STMF4Hall_B.time3 - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataTypeConversion: '<S146>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           */
          STMF4Hall_DW.GlobalSpeedCount = (uint16_T)STMF4Hall_B.Sum_i;

          /* DataTypeConversion: '<S149>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          STMF4Hall_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S146>/Constant'
           */
          STMF4Hall_DW.HallStateChangeFlag = STMF4Hall_P.Constant_Value_fm;

          /* DataStoreWrite: '<S4>/Data Store Write5' */
          STMF4Hall_DW.HallCcapture = STMF4Hall_B.Sum_i;

          /* DataStoreWrite: '<S148>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum_i;

          /* DataStoreWrite: '<S148>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3;

          /* SignalConversion generated from: '<S4>/Out2' incorporates:
           *  Constant: '<S4>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2_e2 = STMF4Hall_P.Constant_Value;
          STMF4Hall_DW.HallsensorC_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' */
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
        srClearBC(STMF4Hall_DW.HallsensorB_SubsysRanBC);

        /* RateTransition generated from: '<Root>/Hall sensor B' */
        STMF4Hall_B.time3_g = STMF4Hall_DW.TmpRTBAtHallsensorBInport1_Buff;

        /* S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Hall sensor B' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick3 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S141>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S143>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S145>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S122>/Sum' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  Gain: '<S122>/Gain'
           *  Gain: '<S122>/Gain1'
           *  Gain: '<S122>/Gain2'
           *  MATLABSystem: '<S141>/Digital Port Read'
           *  MATLABSystem: '<S143>/Digital Port Read'
           *  MATLABSystem: '<S145>/Digital Port Read'
           * */
          STMF4Hall_DW.GlobalHallState = (uint8_T)(((uint32_T)((pinReadLoc &
            1024U) != 0U ? STMF4Hall_P.Gain_Gain_n >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain_l >> 6 : 0))
            + (uint32_T)((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain_d
                         >> 7 : 0));

          /* SwitchCase: '<S121>/Detects if the halls reading is valid' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  DataTypeConversion: '<S121>/Data Type Conversion1'
           */
          switch (STMF4Hall_DW.GlobalHallState) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S124>/Valid Halls' incorporates:
             *  ActionPort: '<S126>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S121>/Data Type Conversion2'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.GlobalHallState,
                                 (uint16_T)STMF4Hall_DW.GlobalHallState,
                                 STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
                                 &STMF4Hall_DW.GlobalDirection, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls_l,
                                 &STMF4Hall_DW.ValidHalls_l,
                                 &STMF4Hall_P.ValidHalls_l);

            /* End of Outputs for SubSystem: '<S124>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S124>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S125>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(STMF4Hall_DW.GlobalDirection, &rtb_Merge,
              &STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnectio_c);

            /* End of Outputs for SubSystem: '<S124>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S121>/Detects if the halls reading is valid' */

          /* Sum: '<S3>/Sum' incorporates:
           *  DataStoreRead: '<S3>/Data Store Read1'
           *  DataTypeConversion: '<S3>/Data Type Conversion'
           *  DataTypeConversion: '<S3>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum_c = (int16_T)((int16_T)STMF4Hall_B.time3_g - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataTypeConversion: '<S121>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           */
          STMF4Hall_DW.GlobalSpeedCount = (uint16_T)STMF4Hall_B.Sum_c;

          /* DataTypeConversion: '<S124>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          STMF4Hall_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S121>/Constant'
           */
          STMF4Hall_DW.HallStateChangeFlag = STMF4Hall_P.Constant_Value_d;

          /* DataStoreWrite: '<S3>/Data Store Write5' */
          STMF4Hall_DW.HallBcapture = STMF4Hall_B.Sum_c;

          /* DataStoreWrite: '<S123>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum_c;

          /* DataStoreWrite: '<S123>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3_g;

          /* SignalConversion generated from: '<S3>/Out2' incorporates:
           *  Constant: '<S3>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2_e = STMF4Hall_P.Constant_Value_p;
          STMF4Hall_DW.HallsensorB_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' */
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
        srClearBC(STMF4Hall_DW.HallsensorA_SubsysRanBC);

        /* RateTransition generated from: '<Root>/Hall sensor A' */
        STMF4Hall_B.time3_gw = STMF4Hall_DW.time3_Buffer0;

        /* S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Hall sensor A' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          boolean_T rtb_Merge3;
          STMF4Hall_M->Timing.clockTick4 = STMF4Hall_M->Timing.clockTick0;

          /* MATLABSystem: '<S116>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S118>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S120>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S97>/Sum' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  Gain: '<S97>/Gain'
           *  Gain: '<S97>/Gain1'
           *  Gain: '<S97>/Gain2'
           *  MATLABSystem: '<S116>/Digital Port Read'
           *  MATLABSystem: '<S118>/Digital Port Read'
           *  MATLABSystem: '<S120>/Digital Port Read'
           * */
          STMF4Hall_DW.GlobalHallState = (uint8_T)(((uint32_T)((pinReadLoc &
            1024U) != 0U ? STMF4Hall_P.Gain_Gain_av >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? STMF4Hall_P.Gain1_Gain_i >> 6 : 0))
            + (uint32_T)((pinReadLoc_e & 4096U) != 0U ? STMF4Hall_P.Gain2_Gain_f
                         >> 7 : 0));

          /* SwitchCase: '<S96>/Detects if the halls reading is valid' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  DataTypeConversion: '<S96>/Data Type Conversion1'
           */
          switch (STMF4Hall_DW.GlobalHallState) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S99>/Valid Halls' incorporates:
             *  ActionPort: '<S101>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S96>/Data Type Conversion2'
             */
            STMF4Hall_ValidHalls((uint16_T)STMF4Hall_DW.GlobalHallState,
                                 (uint16_T)STMF4Hall_DW.GlobalHallState,
                                 STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
                                 &STMF4Hall_DW.GlobalDirection, &rtb_Merge,
                                 &STMF4Hall_B.ValidHalls_d,
                                 &STMF4Hall_DW.ValidHalls_d,
                                 &STMF4Hall_P.ValidHalls_d);

            /* End of Outputs for SubSystem: '<S99>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S99>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S100>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(STMF4Hall_DW.GlobalDirection, &rtb_Merge,
              &STMF4Hall_DW.GlobalDirection, &rtb_Merge3,
              &STMF4Hall_P.Badhallglitchorwrongconnectio_a);

            /* End of Outputs for SubSystem: '<S99>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S96>/Detects if the halls reading is valid' */

          /* Sum: '<S2>/Sum' incorporates:
           *  DataStoreRead: '<S2>/Data Store Read1'
           *  DataTypeConversion: '<S2>/Data Type Conversion'
           *  DataTypeConversion: '<S2>/Data Type Conversion1'
           */
          STMF4Hall_B.Sum = (int16_T)((int16_T)STMF4Hall_B.time3_gw - (int16_T)
            STMF4Hall_DW.Timercntprev);

          /* DataTypeConversion: '<S96>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           */
          STMF4Hall_DW.GlobalSpeedCount = (uint16_T)STMF4Hall_B.Sum;

          /* DataTypeConversion: '<S99>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          STMF4Hall_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S96>/Constant'
           */
          STMF4Hall_DW.HallStateChangeFlag = STMF4Hall_P.Constant_Value_bh;

          /* DataStoreWrite: '<S2>/Data Store Write5' */
          STMF4Hall_DW.HallAcapture = STMF4Hall_B.Sum;

          /* DataStoreWrite: '<S98>/Data Store Write2' */
          STMF4Hall_DW.Timehall = STMF4Hall_B.Sum;

          /* DataStoreWrite: '<S98>/Data Store Write1' */
          STMF4Hall_DW.Timercntprev = STMF4Hall_B.time3_gw;

          /* SignalConversion generated from: '<S2>/Out2' incorporates:
           *  Constant: '<S2>/Constant'
           */
          STMF4Hall_B.OutportBufferForOut2 = STMF4Hall_P.Constant_Value_f;
          STMF4Hall_DW.HallsensorA_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S172>/Hardware Interrupt' */
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

/* Hardware Interrupt Block: '<S174>/Hardware Interrupt' */
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
        srClearBC(STMF4Hall_DW.Subsystem_SubsysRanBC_l);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.FindOffset_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.Subsystem_SubsysRanBC_p);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.IfActionSubsystem_SubsysRanBC_n);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.IfActionSubsystem2_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.Subsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.Accumulate_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.UpCounter_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.PosGen_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.IfActionSubsystem_SubsysRanBC_j);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.IfActionSubsystem1_SubsysRanB_e);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.Subsystem1_SubsysRanBC_f);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.IfActionSubsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.HallValueof1.HallValueof1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.veDirection_SubsysRanBC_n);

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

        /* Reset subsysRan breadcrumbs */
        srClearBC(STMF4Hall_DW.ADCSIC_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S174>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC SIC' */
        {
          real_T rtb_Switch4_idx_1;
          real_T rtb_Switch4_idx_2;
          uint64_T tmp_p;
          real32_T rtb_Add1;
          real32_T rtb_Max_g;
          real32_T rtb_Merge1;
          real32_T rtb_Merge1_l;
          real32_T rtb_algDD_o1;
          uint32_T rtb_counterSize1;
          int16_T y;
          int16_T y_p;
          uint16_T tmp[3];
          uint16_T Switch;
          uint16_T rtb_Get_Integer;
          boolean_T OR;
          STMF4Hall_M->Timing.clockTick5 = STMF4Hall_M->Timing.clockTick0;

          /* DataStoreRead: '<S59>/Data Store Read5' */
          rtb_Get_Integer = STMF4Hall_DW.HallStateChangeFlag;

          /* Switch: '<S60>/Switch' incorporates:
           *  Constant: '<S60>/WatchDog'
           *  DataStoreRead: '<S59>/Data Store Read5'
           *  DataStoreWrite: '<S59>/Data Store Write2'
           */
          if (STMF4Hall_DW.HallStateChangeFlag != 0) {
            STMF4Hall_DW.HallStateChangeFlag = STMF4Hall_P.WatchDog_Value;
          }

          /* End of Switch: '<S60>/Switch' */

          /* Switch: '<S61>/Switch' incorporates:
           *  Constant: '<S61>/Order'
           */
          if (STMF4Hall_P.Order_Value > STMF4Hall_P.Switch_Threshold_i) {
            /* Switch: '<S61>/Switch' */
            Switch = rtb_Get_Integer;
          } else {
            /* Switch: '<S61>/Switch' */
            Switch = STMF4Hall_P.Order_Value;
          }

          /* End of Switch: '<S61>/Switch' */

          /* Delay: '<S61>/validityDelay' incorporates:
           *  Delay: '<S61>/speedCountDelay'
           */
          if (Switch != 0) {
            /* Delay: '<S61>/validityDelay' */
            STMF4Hall_B.validityDelay = STMF4Hall_DW.validityDelay_DSTATE;

            /* Delay: '<S61>/speedCountDelay' */
            STMF4Hall_B.speedCountDelay = STMF4Hall_DW.speedCountDelay_DSTATE;
          }

          /* End of Delay: '<S61>/validityDelay' */

          /* MinMax: '<S59>/Min' incorporates:
           *  DataStoreRead: '<S59>/Data Store Read1'
           *  DataStoreRead: '<S59>/Data Store Read6'
           *  DataStoreRead: '<S59>/Data Store Read7'
           */
          if (STMF4Hall_DW.HallAcapture <= STMF4Hall_DW.HallBcapture) {
            y = STMF4Hall_DW.HallAcapture;
          } else {
            y = STMF4Hall_DW.HallBcapture;
          }

          if (y <= STMF4Hall_DW.HallCcapture) {
            y_p = y;
          } else {
            y_p = STMF4Hall_DW.HallCcapture;
          }

          if (y <= STMF4Hall_DW.HallCcapture) {
            /* DataTypeConversion: '<S60>/counterSize1' */
            rtb_counterSize1 = (uint32_T)y;
          } else {
            /* DataTypeConversion: '<S60>/counterSize1' */
            rtb_counterSize1 = (uint32_T)STMF4Hall_DW.HallCcapture;
          }

          /* End of MinMax: '<S59>/Min' */

          /* Logic: '<S62>/OR' incorporates:
           *  DataTypeConversion: '<S60>/Data Type Conversion4'
           *  Delay: '<S62>/Delay One Step1'
           */
          OR = (STMF4Hall_DW.DelayOneStep1_DSTATE || (rtb_Get_Integer != 0));

          /* Delay: '<S62>/Delay One Step' incorporates:
           *  DataTypeConversion: '<S60>/Data Type Conversion4'
           */
          if (OR) {
            if (rtb_Get_Integer != 0) {
              STMF4Hall_DW.DelayOneStep_DSTATE =
                STMF4Hall_P.SoftwareWatchdogTimer_maxCount;
            }

            /* Delay: '<S62>/Delay One Step' incorporates:
             *  DataTypeConversion: '<S60>/Data Type Conversion4'
             */
            STMF4Hall_B.DelayOneStep = STMF4Hall_DW.DelayOneStep_DSTATE;
          }

          /* End of Delay: '<S62>/Delay One Step' */

          /* RelationalOperator: '<S66>/Compare' incorporates:
           *  Constant: '<S66>/Constant'
           */
          STMF4Hall_DW.DelayOneStep1_DSTATE = (STMF4Hall_B.DelayOneStep >
            STMF4Hall_P.Constant_Value_a);

          /* Switch: '<S65>/watchdog check' incorporates:
           *  Constant: '<S65>/Constant'
           */
          if (STMF4Hall_DW.DelayOneStep1_DSTATE) {
            /* MinMax: '<S65>/Max' incorporates:
             *  DataStoreRead: '<S59>/Data Store Read2'
             *  DataTypeConversion: '<S60>/counterSize2'
             */
            if (STMF4Hall_DW.GlobalSpeedCount >= rtb_counterSize1) {
              rtb_counterSize1 = STMF4Hall_DW.GlobalSpeedCount;
            }

            /* Switch: '<S65>/speed check' incorporates:
             *  Constant: '<S65>/Constant'
             *  DataStoreRead: '<S59>/Data Store Read4'
             *  DataTypeConversion: '<S61>/Data Type Conversion'
             *  Logic: '<S61>/Logical Operator'
             *  MinMax: '<S65>/Max'
             */
            if (rtb_counterSize1 >= STMF4Hall_P.speedcheck_Threshold) {
              rtb_Get_Integer = STMF4Hall_P.Constant_Value_g;
            } else {
              rtb_Get_Integer = (uint16_T)((STMF4Hall_DW.GlobalSpeedValidity !=
                0) || STMF4Hall_B.validityDelay);
            }

            /* End of Switch: '<S65>/speed check' */
          } else {
            rtb_Get_Integer = STMF4Hall_P.Constant_Value_g;
          }

          /* End of Switch: '<S65>/watchdog check' */

          /* If: '<S60>/If' incorporates:
           *  Constant: '<S64>/PositionEnable'
           */
          if (rtb_Get_Integer != 0) {
            /* Outputs for IfAction SubSystem: '<S60>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* If: '<S64>/If' incorporates:
             *  DataStoreRead: '<S59>/Data Store Read3'
             */
            if (STMF4Hall_DW.GlobalDirection > 0) {
              /* Update for IfAction SubSystem: '<S64>/If Action Subsystem' incorporates:
               *  ActionPort: '<S75>/Action Port'
               */
              /* Update for If: '<S64>/If' */
              STMF4Hall_DW.IfActionSubsystem_SubsysRanBC = 4;

              /* End of Update for SubSystem: '<S64>/If Action Subsystem' */
            } else {
              /* Update for IfAction SubSystem: '<S64>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S76>/Action Port'
               */
              /* Update for If: '<S64>/If' */
              STMF4Hall_DW.IfActionSubsystem1_SubsysRanBC = 4;

              /* End of Update for SubSystem: '<S64>/If Action Subsystem1' */
            }

            /* End of If: '<S64>/If' */

            /* Outputs for Enabled SubSystem: '<S64>/Subsystem1' incorporates:
             *  EnablePort: '<S77>/Enable'
             */
            if (STMF4Hall_P.PositionEnable_Value > 0) {
              /* If: '<S77>/If1' incorporates:
               *  Constant: '<S77>/Constant'
               */
              if (STMF4Hall_P.Constant_Value_b > 1.0) {
                /* Outputs for IfAction SubSystem: '<S77>/second_order' incorporates:
                 *  ActionPort: '<S81>/Action Port'
                 */
                /* Product: '<S81>/Divide1' incorporates:
                 *  DataStoreRead: '<S59>/Data Store Read2'
                 *  DataTypeConversion: '<S60>/counterSize1'
                 *  DataTypeConversion: '<S60>/counterSize2'
                 *  DataTypeConversion: '<S81>/countData'
                 *  DataTypeConversion: '<S81>/currentSpeedData'
                 */
                rtb_Merge1 = (real32_T)(uint32_T)y_p / (real32_T)
                  STMF4Hall_DW.GlobalSpeedCount;

                /* Gain: '<S81>/Gain' incorporates:
                 *  Constant: '<S81>/Constant'
                 *  DataTypeConversion: '<S60>/counterSize1'
                 *  DataTypeConversion: '<S81>/countData'
                 *  DataTypeConversion: '<S81>/previousSpeedData'
                 *  Gain: '<S81>/Gain1'
                 *  Product: '<S81>/Divide'
                 *  Product: '<S81>/Product'
                 *  Sum: '<S81>/Sum'
                 *  Sum: '<S81>/Sum1'
                 */
                rtb_Merge1 = ((rtb_Merge1 - (real32_T)(uint32_T)y_p / (real32_T)
                               STMF4Hall_B.speedCountDelay) *
                              STMF4Hall_P.Gain1_Gain +
                              STMF4Hall_P.Constant_Value_e) * rtb_Merge1 *
                  STMF4Hall_P.Gain_Gain;

                /* End of Outputs for SubSystem: '<S77>/second_order' */

                /* Update for IfAction SubSystem: '<S77>/second_order' incorporates:
                 *  ActionPort: '<S81>/Action Port'
                 */
                /* Update for If: '<S77>/If1' */
                STMF4Hall_DW.second_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S77>/second_order' */
              } else {
                /* Outputs for IfAction SubSystem: '<S77>/first_order' incorporates:
                 *  ActionPort: '<S80>/Action Port'
                 */
                /* Gain: '<S80>/Gain' incorporates:
                 *  DataStoreRead: '<S59>/Data Store Read2'
                 *  DataTypeConversion: '<S60>/counterSize1'
                 *  DataTypeConversion: '<S60>/counterSize2'
                 *  DataTypeConversion: '<S80>/countData'
                 *  DataTypeConversion: '<S80>/currentSpeedData'
                 *  Product: '<S80>/Divide'
                 */
                rtb_Merge1 = (real32_T)(uint32_T)y_p / (real32_T)
                  STMF4Hall_DW.GlobalSpeedCount * STMF4Hall_P.Gain_Gain_e;

                /* End of Outputs for SubSystem: '<S77>/first_order' */

                /* Update for IfAction SubSystem: '<S77>/first_order' incorporates:
                 *  ActionPort: '<S80>/Action Port'
                 */
                /* Update for If: '<S77>/If1' */
                STMF4Hall_DW.first_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S77>/first_order' */
              }

              /* End of If: '<S77>/If1' */

              /* Saturate: '<S77>/Saturation' */
              if (rtb_Merge1 > STMF4Hall_P.Saturation_UpperSat) {
                rtb_Merge1 = STMF4Hall_P.Saturation_UpperSat;
              } else if (rtb_Merge1 < STMF4Hall_P.Saturation_LowerSat) {
                rtb_Merge1 = STMF4Hall_P.Saturation_LowerSat;
              }

              /* End of Saturate: '<S77>/Saturation' */

              /* If: '<S77>/If' incorporates:
               *  DataStoreRead: '<S59>/Data Store Read3'
               */
              if (STMF4Hall_DW.GlobalDirection != 1) {
                /* Outputs for IfAction SubSystem: '<S77>/-ve Direction' incorporates:
                 *  ActionPort: '<S79>/Action Port'
                 */
                /* SwitchCase: '<S79>/Switch Case' incorporates:
                 *  DataStoreRead: '<S59>/Data Store Read'
                 */
                switch (STMF4Hall_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S79>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S89>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof1);

                  /* End of Outputs for SubSystem: '<S79>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S79>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S90>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof2);

                  /* End of Outputs for SubSystem: '<S79>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S79>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S91>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof3);

                  /* End of Outputs for SubSystem: '<S79>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S79>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S92>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof4);

                  /* End of Outputs for SubSystem: '<S79>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S79>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S93>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof5);

                  /* End of Outputs for SubSystem: '<S79>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S79>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S94>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof6);

                  /* End of Outputs for SubSystem: '<S79>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S79>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S95>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof7);

                  /* End of Outputs for SubSystem: '<S79>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S79>/Switch Case' */

                /* Merge: '<S77>/Merge' incorporates:
                 *  Sum: '<S79>/Sum'
                 */
                STMF4Hall_B.Merge = rtb_Merge1_l - rtb_Merge1;

                /* End of Outputs for SubSystem: '<S77>/-ve Direction' */

                /* Update for IfAction SubSystem: '<S77>/-ve Direction' incorporates:
                 *  ActionPort: '<S79>/Action Port'
                 */
                /* Update for If: '<S77>/If' */
                STMF4Hall_DW.veDirection_SubsysRanBC_n = 4;

                /* End of Update for SubSystem: '<S77>/-ve Direction' */
              } else {
                /* Outputs for IfAction SubSystem: '<S77>/+ve Direction' incorporates:
                 *  ActionPort: '<S78>/Action Port'
                 */
                /* SwitchCase: '<S78>/Switch Case' incorporates:
                 *  DataStoreRead: '<S59>/Data Store Read'
                 */
                switch (STMF4Hall_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S78>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S82>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof1_d);

                  /* End of Outputs for SubSystem: '<S78>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S78>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S83>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof2_i);

                  /* End of Outputs for SubSystem: '<S78>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S78>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S84>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof3_k);

                  /* End of Outputs for SubSystem: '<S78>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S78>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S85>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof4_l);

                  /* End of Outputs for SubSystem: '<S78>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S78>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S86>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof5_h);

                  /* End of Outputs for SubSystem: '<S78>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S78>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S87>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof6_i);

                  /* End of Outputs for SubSystem: '<S78>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S78>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S88>/Action Port'
                   */
                  STMF4Hall_HallValueof1(&rtb_Merge1_l,
                    &STMF4Hall_P.HallValueof7_h);

                  /* End of Outputs for SubSystem: '<S78>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S78>/Switch Case' */

                /* Merge: '<S77>/Merge' incorporates:
                 *  Sum: '<S78>/Sum'
                 */
                STMF4Hall_B.Merge = rtb_Merge1_l + rtb_Merge1;

                /* End of Outputs for SubSystem: '<S77>/+ve Direction' */

                /* Update for IfAction SubSystem: '<S77>/+ve Direction' incorporates:
                 *  ActionPort: '<S78>/Action Port'
                 */
                /* Update for If: '<S77>/If' */
                STMF4Hall_DW.veDirection_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S77>/+ve Direction' */
              }

              /* End of If: '<S77>/If' */
              STMF4Hall_DW.Subsystem1_SubsysRanBC = 4;
            }

            /* End of Outputs for SubSystem: '<S64>/Subsystem1' */

            /* SignalConversion generated from: '<S64>/rawPosition' incorporates:
             *  Constant: '<S64>/PositionEnable'
             */
            rtb_Max_g = STMF4Hall_B.Merge;

            /* End of Outputs for SubSystem: '<S60>/Speed and direction are valid Use speed to extrapolate position' */

            /* Update for IfAction SubSystem: '<S60>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S64>/Action Port'
             */
            /* Update for If: '<S60>/If' */
            STMF4Hall_DW.SpeedanddirectionarevalidUsespe = 4;

            /* End of Update for SubSystem: '<S60>/Speed and direction are valid Use speed to extrapolate position' */
          } else {
            /* Outputs for IfAction SubSystem: '<S60>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S63>/Action Port'
             */
            /* SwitchCase: '<S67>/Switch Case' incorporates:
             *  DataStoreRead: '<S59>/Data Store Read'
             */
            switch (STMF4Hall_DW.GlobalHallState) {
             case 5:
              /* Outputs for IfAction SubSystem: '<S67>/Hall Value of 1' incorporates:
               *  ActionPort: '<S68>/Action Port'
               */
              STMF4Hall_HallValueof1(&rtb_Max_g, &STMF4Hall_P.HallValueof1_a);

              /* End of Outputs for SubSystem: '<S67>/Hall Value of 1' */
              break;

             case 4:
              /* Outputs for IfAction SubSystem: '<S67>/Hall Value of 2' incorporates:
               *  ActionPort: '<S69>/Action Port'
               */
              STMF4Hall_HallValueof1(&rtb_Max_g, &STMF4Hall_P.HallValueof2_n);

              /* End of Outputs for SubSystem: '<S67>/Hall Value of 2' */
              break;

             case 6:
              /* Outputs for IfAction SubSystem: '<S67>/Hall Value of 3' incorporates:
               *  ActionPort: '<S70>/Action Port'
               */
              STMF4Hall_HallValueof1(&rtb_Max_g, &STMF4Hall_P.HallValueof3_m);

              /* End of Outputs for SubSystem: '<S67>/Hall Value of 3' */
              break;

             case 2:
              /* Outputs for IfAction SubSystem: '<S67>/Hall Value of 4' incorporates:
               *  ActionPort: '<S71>/Action Port'
               */
              STMF4Hall_HallValueof1(&rtb_Max_g, &STMF4Hall_P.HallValueof4_n);

              /* End of Outputs for SubSystem: '<S67>/Hall Value of 4' */
              break;

             case 3:
              /* Outputs for IfAction SubSystem: '<S67>/Hall Value of 5' incorporates:
               *  ActionPort: '<S72>/Action Port'
               */
              STMF4Hall_HallValueof1(&rtb_Max_g, &STMF4Hall_P.HallValueof5_o);

              /* End of Outputs for SubSystem: '<S67>/Hall Value of 5' */
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S67>/Hall Value of 6' incorporates:
               *  ActionPort: '<S73>/Action Port'
               */
              STMF4Hall_HallValueof1(&rtb_Max_g, &STMF4Hall_P.HallValueof6_d);

              /* End of Outputs for SubSystem: '<S67>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S67>/Hall Value of 7' incorporates:
               *  ActionPort: '<S74>/Action Port'
               */
              STMF4Hall_HallValueof1(&rtb_Max_g, &STMF4Hall_P.HallValueof7_n);

              /* End of Outputs for SubSystem: '<S67>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S67>/Switch Case' */
            /* End of Outputs for SubSystem: '<S60>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */

            /* Update for IfAction SubSystem: '<S60>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S63>/Action Port'
             */
            /* Update for If: '<S60>/If' */
            STMF4Hall_DW.SpeedanddirectionarenotvalidPos = 4;

            /* End of Update for SubSystem: '<S60>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
          }

          /* End of If: '<S60>/If' */

          /* Gain: '<S60>/PositionUnit' */
          rtb_Merge1 = STMF4Hall_P.PositionUnit_Gain * rtb_Max_g;

          /* UnitDelay: '<S11>/Output' */
          STMF4Hall_B.Output = STMF4Hall_DW.Output_DSTATE;

          /* Sum: '<S55>/FixPt Sum1' incorporates:
           *  Constant: '<S55>/FixPt Constant'
           */
          rtb_Get_Integer = (uint16_T)((uint32_T)STMF4Hall_B.Output +
            STMF4Hall_P.FixPtConstant_Value);

          /* Switch: '<S56>/FixPt Switch' */
          if (rtb_Get_Integer > STMF4Hall_P.WrapToZero_Threshold) {
            /* Update for UnitDelay: '<S11>/Output' incorporates:
             *  Constant: '<S56>/Constant'
             */
            STMF4Hall_DW.Output_DSTATE = STMF4Hall_P.Constant_Value_o;
          } else {
            /* Update for UnitDelay: '<S11>/Output' */
            STMF4Hall_DW.Output_DSTATE = rtb_Get_Integer;
          }

          /* End of Switch: '<S56>/FixPt Switch' */

          /* Outputs for Enabled SubSystem: '<S10>/PosGen' incorporates:
           *  EnablePort: '<S20>/Enable'
           */
          /* DataStoreRead: '<S10>/Data Store Read' incorporates:
           *  Constant: '<S33>/Constant'
           *  Constant: '<S40>/Constant_Reset'
           *  Delay: '<S41>/Delay'
           *  Logic: '<S20>/NOT'
           *  Logic: '<S40>/NOT'
           *  RelationalOperator: '<S33>/Compare'
           */
          if (STMF4Hall_DW.Enable > 0.0) {
            if (!STMF4Hall_DW.PosGen_MODE) {
              /* InitializeConditions for UnitDelay: '<S40>/Unit Delay' */
              STMF4Hall_DW.UnitDelay_DSTATE =
                STMF4Hall_P.UnitDelay_InitialCondition_o;
              STMF4Hall_DW.PosGen_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S20>/Up Counter' incorporates:
             *  EnablePort: '<S37>/Enable'
             */
            if (STMF4Hall_DW.Enable > 0.0) {
              if (!STMF4Hall_DW.UpCounter_MODE) {
                /* InitializeConditions for Delay: '<S37>/Delay' */
                STMF4Hall_DW.Delay_DSTATE_a =
                  STMF4Hall_P.Delay_InitialCondition_m;
                STMF4Hall_DW.UpCounter_MODE = true;
              }

              /* Sum: '<S37>/Add1' incorporates:
               *  Constant: '<S37>/Constant'
               *  Delay: '<S37>/Delay'
               */
              tmp_p = (uint64_T)STMF4Hall_P.Constant_Value_ns +
                STMF4Hall_DW.Delay_DSTATE_a;
              if (tmp_p > 4294967295ULL) {
                tmp_p = 4294967295ULL;
              }

              /* Sum: '<S37>/Add1' */
              STMF4Hall_B.Add1 = (uint32_T)tmp_p;

              /* Update for Delay: '<S37>/Delay' */
              STMF4Hall_DW.Delay_DSTATE_a = STMF4Hall_B.Add1;
              STMF4Hall_DW.UpCounter_SubsysRanBC = 4;
            } else if (STMF4Hall_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S37>/Add1' incorporates:
               *  Outport: '<S37>/Count'
               */
              STMF4Hall_B.Add1 = STMF4Hall_P.Count_Y0;
              STMF4Hall_DW.UpCounter_MODE = false;
            }

            /* End of Outputs for SubSystem: '<S20>/Up Counter' */

            /* Outputs for Enabled SubSystem: '<S20>/Subsystem' incorporates:
             *  EnablePort: '<S35>/Enable'
             */
            if (STMF4Hall_B.Add1 > STMF4Hall_P.Disablehostafter22seconds_const)
            {
              /* DataStoreWrite: '<S35>/Data Store Write' incorporates:
               *  Constant: '<S35>/Constant'
               */
              STMF4Hall_DW.Enable = STMF4Hall_P.Constant_Value_pu;
              STMF4Hall_DW.Subsystem_SubsysRanBC_p = 4;
            }

            /* End of Outputs for SubSystem: '<S20>/Subsystem' */

            /* RelationalOperator: '<S34>/Compare' incorporates:
             *  Constant: '<S33>/Constant'
             *  Constant: '<S34>/Constant'
             *  Logic: '<S20>/NOT'
             *  RelationalOperator: '<S33>/Compare'
             */
            STMF4Hall_B.Compare = (STMF4Hall_B.Add1 <=
              STMF4Hall_P.EnablePWMfor20seconds_const);

            /* If: '<S36>/If' incorporates:
             *  Constant: '<S36>/Count for 2 sec'
             */
            if (STMF4Hall_B.Add1 < STMF4Hall_P.Countfor2sec_Value) {
              /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem' incorporates:
               *  ActionPort: '<S38>/Action Port'
               */
              /* SignalConversion generated from: '<S38>/Out1' incorporates:
               *  Constant: '<S38>/Constant'
               */
              rtb_Merge1_l = STMF4Hall_P.Constant_Value_l;

              /* End of Outputs for SubSystem: '<S36>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S36>/If Action Subsystem' incorporates:
               *  ActionPort: '<S38>/Action Port'
               */
              /* Update for If: '<S36>/If' */
              STMF4Hall_DW.IfActionSubsystem_SubsysRanBC_n = 4;

              /* End of Update for SubSystem: '<S36>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S36>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S39>/Action Port'
               */
              /* Saturate: '<S39>/Saturate to 'motor.calibSpeed' RPM' incorporates:
               *  Constant: '<S39>/Constant1'
               *  Delay: '<S39>/Delay'
               *  Sum: '<S39>/Add1'
               */
              STMF4Hall_DW.Delay_DSTATE += STMF4Hall_P.Constant1_Value_i;

              /* Saturate: '<S39>/Saturate to 'motor.calibSpeed' RPM' */
              if (STMF4Hall_DW.Delay_DSTATE >
                  STMF4Hall_P.SaturatetomotorcalibSpeedRPM_Up) {
                /* Saturate: '<S39>/Saturate to 'motor.calibSpeed' RPM' */
                STMF4Hall_DW.Delay_DSTATE =
                  STMF4Hall_P.SaturatetomotorcalibSpeedRPM_Up;
              } else if (STMF4Hall_DW.Delay_DSTATE <
                         STMF4Hall_P.SaturatetomotorcalibSpeedRPM_Lo) {
                /* Saturate: '<S39>/Saturate to 'motor.calibSpeed' RPM' */
                STMF4Hall_DW.Delay_DSTATE =
                  STMF4Hall_P.SaturatetomotorcalibSpeedRPM_Lo;
              }

              /* End of Saturate: '<S39>/Saturate to 'motor.calibSpeed' RPM' */

              /* Gain: '<S39>/Multiply' */
              rtb_Merge1_l = STMF4Hall_P.Ts * STMF4Hall_DW.Delay_DSTATE;

              /* End of Outputs for SubSystem: '<S36>/If Action Subsystem2' */

              /* Update for IfAction SubSystem: '<S36>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S39>/Action Port'
               */
              /* Update for If: '<S36>/If' */
              STMF4Hall_DW.IfActionSubsystem2_SubsysRanBC = 4;

              /* End of Update for SubSystem: '<S36>/If Action Subsystem2' */
            }

            /* End of If: '<S36>/If' */

            /* Outputs for Enabled SubSystem: '<S40>/Accumulate' incorporates:
             *  EnablePort: '<S41>/Enable'
             */
            if (!STMF4Hall_P.Constant_Reset_Value) {
              /* Outputs for Enabled SubSystem: '<S41>/Subsystem' incorporates:
               *  EnablePort: '<S42>/Enable'
               */
              if (STMF4Hall_DW.Delay_DSTATE_o) {
                /* SignalConversion generated from: '<S42>/Input' incorporates:
                 *  Gain: '<S40>/scaleIn'
                 */
                STMF4Hall_B.Input = STMF4Hall_P.scaleIn_Gain * rtb_Merge1_l;
                STMF4Hall_DW.Subsystem_SubsysRanBC = 4;
              }

              /* End of Outputs for SubSystem: '<S41>/Subsystem' */

              /* Sum: '<S41>/Add' incorporates:
               *  Delay: '<S41>/Delay'
               *  UnitDelay: '<S40>/Unit Delay'
               */
              rtb_Max_g = STMF4Hall_B.Input + STMF4Hall_DW.UnitDelay_DSTATE;

              /* DataTypeConversion: '<S41>/Data Type Conversion' */
              rtb_Merge1_l = floorf(rtb_Max_g);
              if (rtIsNaNF(rtb_Merge1_l) || rtIsInfF(rtb_Merge1_l)) {
                rtb_Merge1_l = 0.0F;
              } else {
                rtb_Merge1_l = fmodf(rtb_Merge1_l, 65536.0F);
              }

              /* Sum: '<S41>/Add1' incorporates:
               *  DataTypeConversion: '<S41>/Data Type Conversion'
               *  DataTypeConversion: '<S41>/Data Type Conversion1'
               */
              STMF4Hall_B.Add1_h = rtb_Max_g - (real32_T)(rtb_Merge1_l < 0.0F ?
                (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Merge1_l : (int32_T)
                (int16_T)(uint16_T)rtb_Merge1_l);

              /* Update for Delay: '<S41>/Delay' incorporates:
               *  Constant: '<S41>/Constant'
               */
              STMF4Hall_DW.Delay_DSTATE_o = STMF4Hall_P.Constant_Value_n0;
              STMF4Hall_DW.Accumulate_SubsysRanBC = 4;
            }

            /* End of Outputs for SubSystem: '<S40>/Accumulate' */

            /* Gain: '<S40>/scaleOut' incorporates:
             *  Constant: '<S40>/Constant_Reset'
             *  Delay: '<S41>/Delay'
             *  Logic: '<S40>/NOT'
             */
            STMF4Hall_B.scaleOut = STMF4Hall_P.scaleOut_Gain *
              STMF4Hall_B.Add1_h;

            /* Update for UnitDelay: '<S40>/Unit Delay' */
            STMF4Hall_DW.UnitDelay_DSTATE = STMF4Hall_B.Add1_h;
            STMF4Hall_DW.PosGen_SubsysRanBC = 4;
          } else if (STMF4Hall_DW.PosGen_MODE) {
            /* Disable for Enabled SubSystem: '<S20>/Up Counter' */
            if (STMF4Hall_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S37>/Add1' incorporates:
               *  Outport: '<S37>/Count'
               */
              STMF4Hall_B.Add1 = STMF4Hall_P.Count_Y0;
              STMF4Hall_DW.UpCounter_MODE = false;
            }

            /* End of Disable for SubSystem: '<S20>/Up Counter' */

            /* Disable for RelationalOperator: '<S34>/Compare' incorporates:
             *  Outport: '<S20>/EnPWM'
             */
            STMF4Hall_B.Compare = STMF4Hall_P.EnPWM_Y0;
            STMF4Hall_DW.PosGen_MODE = false;
          }

          /* End of DataStoreRead: '<S10>/Data Store Read' */
          /* End of Outputs for SubSystem: '<S10>/PosGen' */

          /* Gain: '<S44>/convert_pu' */
          rtb_Max_g = STMF4Hall_P.convert_pu_Gain * STMF4Hall_B.scaleOut;

          /* If: '<S44>/If' incorporates:
           *  Constant: '<S45>/Constant'
           *  RelationalOperator: '<S45>/Compare'
           */
          if (rtb_Max_g < STMF4Hall_P.Constant_Value_ls) {
            /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem' incorporates:
             *  ActionPort: '<S46>/Action Port'
             */
            /* DataTypeConversion: '<S46>/Convert_uint16' */
            rtb_Merge1_l = floorf(rtb_Max_g);
            if (rtIsInfF(rtb_Merge1_l)) {
              rtb_Merge1_l = 0.0F;
            } else {
              rtb_Merge1_l = fmodf(rtb_Merge1_l, 65536.0F);
            }

            /* Sum: '<S46>/Sum' incorporates:
             *  DataTypeConversion: '<S46>/Convert_back'
             *  DataTypeConversion: '<S46>/Convert_uint16'
             */
            rtb_Max_g -= (real32_T)(rtb_Merge1_l < 0.0F ? (int32_T)(int16_T)
              -(int16_T)(uint16_T)-rtb_Merge1_l : (int32_T)(int16_T)(uint16_T)
              rtb_Merge1_l);

            /* End of Outputs for SubSystem: '<S44>/If Action Subsystem' */

            /* Update for IfAction SubSystem: '<S44>/If Action Subsystem' incorporates:
             *  ActionPort: '<S46>/Action Port'
             */
            /* Update for If: '<S44>/If' */
            STMF4Hall_DW.IfActionSubsystem_SubsysRanBC_j = 4;

            /* End of Update for SubSystem: '<S44>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S44>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S47>/Action Port'
             */
            /* DataTypeConversion: '<S47>/Convert_uint16' */
            rtb_Merge1_l = truncf(rtb_Max_g);
            if (rtIsNaNF(rtb_Merge1_l) || rtIsInfF(rtb_Merge1_l)) {
              rtb_Merge1_l = 0.0F;
            } else {
              rtb_Merge1_l = fmodf(rtb_Merge1_l, 65536.0F);
            }

            /* Sum: '<S47>/Sum' incorporates:
             *  DataTypeConversion: '<S47>/Convert_back'
             *  DataTypeConversion: '<S47>/Convert_uint16'
             */
            rtb_Max_g -= (real32_T)(rtb_Merge1_l < 0.0F ? (int32_T)(int16_T)
              -(int16_T)(uint16_T)-rtb_Merge1_l : (int32_T)(int16_T)(uint16_T)
              rtb_Merge1_l);

            /* End of Outputs for SubSystem: '<S44>/If Action Subsystem1' */

            /* Update for IfAction SubSystem: '<S44>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S47>/Action Port'
             */
            /* Update for If: '<S44>/If' */
            STMF4Hall_DW.IfActionSubsystem1_SubsysRanB_e = 4;

            /* End of Update for SubSystem: '<S44>/If Action Subsystem1' */
          }

          /* End of If: '<S44>/If' */

          /* Gain: '<S21>/indexing' */
          rtb_Max_g *= STMF4Hall_P.indexing_Gain;

          /* DataTypeConversion: '<S21>/Get_Integer' */
          rtb_Merge1_l = truncf(rtb_Max_g);
          if (rtIsNaNF(rtb_Merge1_l) || rtIsInfF(rtb_Merge1_l)) {
            rtb_Merge1_l = 0.0F;
          } else {
            rtb_Merge1_l = fmodf(rtb_Merge1_l, 65536.0F);
          }

          rtb_Get_Integer = (uint16_T)(rtb_Merge1_l < 0.0F ? (int32_T)(uint16_T)
            -(int16_T)(uint16_T)-rtb_Merge1_l : (int32_T)(uint16_T)rtb_Merge1_l);

          /* End of DataTypeConversion: '<S21>/Get_Integer' */

          /* Sum: '<S21>/Sum2' incorporates:
           *  DataTypeConversion: '<S21>/Data Type Conversion1'
           */
          rtb_Merge1_l = rtb_Max_g - (real32_T)rtb_Get_Integer;

          /* Outputs for Atomic SubSystem: '<S19>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S31>/a16' incorporates:
           *  Constant: '<S10>/Vd_Ref'
           *  Constant: '<S10>/Vq'
           *  Constant: '<S21>/offset'
           *  Constant: '<S21>/sine_table_values'
           *  Product: '<S43>/Product'
           *  Product: '<S43>/Product1'
           *  Selector: '<S21>/Lookup'
           *  Sum: '<S21>/Sum'
           *  Sum: '<S43>/Sum3'
           *  Sum: '<S43>/Sum4'
           *  Sum: '<S43>/Sum5'
           *  Sum: '<S43>/Sum6'
           */
          arm_inv_park_f32(STMF4Hall_P.Vd_Ref_Value, STMF4Hall_P.Vq_Value,
                           &rtb_algDD_o1, &rtb_Max_g,
                           (STMF4Hall_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)STMF4Hall_P.offset_Value[0] +
                             rtb_Get_Integer)] -
                            STMF4Hall_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)STMF4Hall_P.offset_Value[1] +
                             rtb_Get_Integer)]) * rtb_Merge1_l +
                           STMF4Hall_P.sine_table_values_Value[(int32_T)
                           ((uint32_T)STMF4Hall_P.offset_Value[1] +
                            rtb_Get_Integer)],
                           (STMF4Hall_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)STMF4Hall_P.offset_Value[2] +
                             rtb_Get_Integer)] -
                            STMF4Hall_P.sine_table_values_Value[(int32_T)
                            ((uint32_T)STMF4Hall_P.offset_Value[3] +
                             rtb_Get_Integer)]) * rtb_Merge1_l +
                           STMF4Hall_P.sine_table_values_Value[(int32_T)
                           ((uint32_T)STMF4Hall_P.offset_Value[3] +
                            rtb_Get_Integer)]);

          /* End of Outputs for SubSystem: '<S19>/Two inputs CRL' */

          /* Gain: '<S54>/Ka' */
          rtb_Merge1_l = STMF4Hall_P.Ka_Gain * rtb_algDD_o1;

          /* Gain: '<S54>/one_by_two' */
          rtb_algDD_o1 *= STMF4Hall_P.one_by_two_Gain;

          /* Gain: '<S54>/sqrt3_by_two' */
          rtb_Max_g *= STMF4Hall_P.sqrt3_by_two_Gain;

          /* Gain: '<S54>/Kb' incorporates:
           *  Sum: '<S54>/add_b'
           */
          rtb_Add1 = (rtb_Max_g - rtb_algDD_o1) * STMF4Hall_P.Kb_Gain;

          /* Gain: '<S54>/Kc' incorporates:
           *  Sum: '<S54>/add_c'
           */
          rtb_algDD_o1 = ((0.0F - rtb_algDD_o1) - rtb_Max_g) *
            STMF4Hall_P.Kc_Gain;

          /* Gain: '<S51>/one_by_two' incorporates:
           *  MinMax: '<S51>/Max'
           *  MinMax: '<S51>/Min'
           *  Sum: '<S51>/Add'
           */
          rtb_Max_g = (fmaxf(fmaxf(rtb_Merge1_l, rtb_Add1), rtb_algDD_o1) +
                       fminf(fminf(rtb_Merge1_l, rtb_Add1), rtb_algDD_o1)) *
            STMF4Hall_P.one_by_two_Gain_j;

          /* Gain: '<S12>/Gain4' incorporates:
           *  Constant: '<S12>/Constant1'
           *  Gain: '<S12>/Gain3'
           *  Gain: '<S50>/Gain'
           *  Sum: '<S12>/Add'
           *  Sum: '<S50>/Add1'
           *  Sum: '<S50>/Add2'
           *  Sum: '<S50>/Add3'
           */
          STMF4Hall_B.Gain4[0] = ((rtb_Merge1_l + rtb_Max_g) *
            STMF4Hall_P.Gain_Gain_a * STMF4Hall_P.Gain3_Gain +
            STMF4Hall_P.Constant1_Value) * STMF4Hall_P.Gain4_Gain;
          STMF4Hall_B.Gain4[1] = ((rtb_Add1 + rtb_Max_g) *
            STMF4Hall_P.Gain_Gain_a * STMF4Hall_P.Gain3_Gain +
            STMF4Hall_P.Constant1_Value) * STMF4Hall_P.Gain4_Gain;
          STMF4Hall_B.Gain4[2] = ((rtb_Max_g + rtb_algDD_o1) *
            STMF4Hall_P.Gain_Gain_a * STMF4Hall_P.Gain3_Gain +
            STMF4Hall_P.Constant1_Value) * STMF4Hall_P.Gain4_Gain;

          /* Switch: '<S12>/Switch4' incorporates:
           *  Constant: '<S12>/stop'
           */
          if (STMF4Hall_B.Compare) {
            STMF4Hall_B.rtb_Switch4_idx_0 = STMF4Hall_B.Gain4[0];
            rtb_Switch4_idx_1 = STMF4Hall_B.Gain4[1];
            rtb_Switch4_idx_2 = STMF4Hall_B.Gain4[2];
          } else {
            STMF4Hall_B.rtb_Switch4_idx_0 = STMF4Hall_P.stop_Value;
            rtb_Switch4_idx_1 = STMF4Hall_P.stop_Value;
            rtb_Switch4_idx_2 = STMF4Hall_P.stop_Value;
          }

          /* End of Switch: '<S12>/Switch4' */

          /* MATLABSystem: '<S58>/PWM Output' */
          setDutyCycleInPercentageChannel1(STMF4Hall_DW.obj_l.TimerHandle,
            STMF4Hall_B.rtb_Switch4_idx_0);
          setDutyCycleInPercentageChannel2(STMF4Hall_DW.obj_l.TimerHandle,
            rtb_Switch4_idx_1);
          setDutyCycleInPercentageChannel3(STMF4Hall_DW.obj_l.TimerHandle,
            rtb_Switch4_idx_2);
          setMOEBitAccToInput(STMF4Hall_DW.obj_l.TimerHandle,
                              STMF4Hall_B.Compare);

          /* MATLABSystem: '<S17>/Analog to Digital Converter' */
          injectedReadADCIntr(STMF4Hall_DW.obj.ADCHandle, ADC_READ, &tmp[0]);

          /* Outputs for Enabled SubSystem: '<S10>/Find Offset' incorporates:
           *  EnablePort: '<S18>/Enable'
           */
          if (STMF4Hall_B.Compare) {
            if (!STMF4Hall_DW.FindOffset_MODE) {
              /* InitializeConditions for Delay: '<S18>/Delay' */
              STMF4Hall_DW.Delay_DSTATE_k = STMF4Hall_P.Delay_InitialCondition;
              STMF4Hall_DW.FindOffset_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S18>/Subsystem' incorporates:
             *  EnablePort: '<S26>/Enable'
             */
            /* Logic: '<S18>/AND' incorporates:
             *  Constant: '<S24>/Constant'
             *  Constant: '<S25>/Constant'
             *  Delay: '<S18>/Delay'
             *  RelationalOperator: '<S24>/Compare'
             *  RelationalOperator: '<S25>/Compare'
             */
            if ((STMF4Hall_B.scaleOut <= STMF4Hall_P.CompareToConstant_const) &&
                (STMF4Hall_DW.Delay_DSTATE_k >=
                 STMF4Hall_P.CompareToConstant1_const)) {
              /* Switch: '<S27>/Switch1' incorporates:
               *  Constant: '<S27>/FilterConstant'
               *  Constant: '<S27>/One'
               *  Constant: '<S27>/OneMinusFilterConstant'
               *  Constant: '<S27>/UseInputPort'
               *  Constant: '<S27>/a'
               *  Sum: '<S27>/Sum'
               */
              if (STMF4Hall_P.UseInputPort_Value > STMF4Hall_P.Switch1_Threshold)
              {
                rtb_algDD_o1 = STMF4Hall_P.a_Value;
                rtb_Add1 = STMF4Hall_P.One_Value - STMF4Hall_P.a_Value;
              } else {
                rtb_algDD_o1 = STMF4Hall_P.FilterConstant_Value;
                rtb_Add1 = STMF4Hall_P.OneMinusFilterConstant_Value;
              }

              /* End of Switch: '<S27>/Switch1' */

              /* Update for UnitDelay: '<S30>/Unit Delay' incorporates:
               *  Product: '<S30>/Product'
               *  Product: '<S30>/Product1'
               *  Sum: '<S30>/Add1'
               */
              STMF4Hall_DW.UnitDelay_DSTATE_j = rtb_Merge1 * rtb_algDD_o1 +
                rtb_Add1 * STMF4Hall_DW.UnitDelay_DSTATE_j;
              STMF4Hall_DW.Subsystem_SubsysRanBC_l = 4;
            }

            /* End of Logic: '<S18>/AND' */
            /* End of Outputs for SubSystem: '<S18>/Subsystem' */

            /* Update for Delay: '<S18>/Delay' */
            STMF4Hall_DW.Delay_DSTATE_k = STMF4Hall_B.scaleOut;
            STMF4Hall_DW.FindOffset_SubsysRanBC = 4;
          } else {
            STMF4Hall_DW.FindOffset_MODE = false;

            /* Outputs for Enabled SubSystem: '<S10>/Subsystem1' incorporates:
             *  EnablePort: '<S23>/Enable'
             */
            STMF4Hall_DW.Subsystem1_SubsysRanBC_f = 4;

            /* End of Outputs for SubSystem: '<S10>/Subsystem1' */
          }

          /* End of Outputs for SubSystem: '<S10>/Find Offset' */
          /* Update for Delay: '<S61>/validityDelay' incorporates:
           *  DataStoreRead: '<S59>/Data Store Read2'
           *  DataStoreRead: '<S59>/Data Store Read4'
           *  DataTypeConversion: '<S60>/counterSize2'
           *  DataTypeConversion: '<S61>/Data Type Conversion'
           *  Delay: '<S61>/speedCountDelay'
           */
          if (Switch != 0) {
            STMF4Hall_DW.validityDelay_DSTATE =
              (STMF4Hall_DW.GlobalSpeedValidity != 0);
            STMF4Hall_DW.speedCountDelay_DSTATE = STMF4Hall_DW.GlobalSpeedCount;
          }

          /* End of Update for Delay: '<S61>/validityDelay' */

          /* Update for Delay: '<S62>/Delay One Step' incorporates:
           *  Constant: '<S62>/Constant2'
           *  Sum: '<S62>/Sum'
           */
          if (OR) {
            STMF4Hall_DW.DelayOneStep_DSTATE = (uint16_T)((uint32_T)
              STMF4Hall_B.DelayOneStep - STMF4Hall_P.Constant2_Value);
          }

          /* End of Update for Delay: '<S62>/Delay One Step' */
          STMF4Hall_DW.ADCSIC_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S174>/Hardware Interrupt' */
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
  MW_NVIC_DisableIRQ(33);
  MW_NVIC_DisableIRQ(55);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
