/*
 * File: G431Hallcorrection.c
 *
 * Code generated for Simulink model 'G431Hallcorrection'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Nov  6 11:03:14 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G431Hallcorrection.h"
#include "rtwtypes.h"
#include "G431Hallcorrection_types.h"
#include "G431Hallcorrection_private.h"
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
B_G431Hallcorrection_T G431Hallcorrection_B;

/* Block states (default storage) */
DW_G431Hallcorrection_T G431Hallcorrection_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_G431Hallcorrection_T G431Hallcorrection_PrevZCX;

/* Real-time model */
static RT_MODEL_G431Hallcorrection_T G431Hallcorrection_M_;
RT_MODEL_G431Hallcorrection_T *const G431Hallcorrection_M =
  &G431Hallcorrection_M_;

/* Forward declaration for local functions */
static void G431Hallcorrec_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj);
static void G431Hallcor_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_G4_T *obj);

/* Forward declaration for local functions */
static void G431Hallcorr_SystemCore_setup_i(stm32cube_blocks_TimerCapture_T *obj);

/* Forward declaration for local functions */
static void G431Hallcorr_SystemCore_setup_g(stm32cube_blocks_TimerCapture_T *obj);

/* Forward declaration for local functions */
static void G431Hallcor_SystemCore_setup_i2(stm32cube_blocks_TimerCapture_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void G431Hallcorrection_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(G431Hallcorrection_M, 1));
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
  (G431Hallcorrection_M->Timing.TaskCounters.TID[1])++;
  if ((G431Hallcorrection_M->Timing.TaskCounters.TID[1]) > 99) {/* Sample time: [0.1s, 0.0s] */
    G431Hallcorrection_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S49>/Hall Value of 1'
 *    '<S49>/Hall Value of 2'
 *    '<S49>/Hall Value of 3'
 *    '<S49>/Hall Value of 4'
 *    '<S49>/Hall Value of 5'
 *    '<S49>/Hall Value of 6'
 *    '<S49>/Hall Value of 7'
 *    '<S48>/Hall Value of 1'
 *    '<S48>/Hall Value of 2'
 *    '<S48>/Hall Value of 3'
 *    ...
 */
void G431Hallcorrec_HallValueof1(real32_T *rty_position,
  P_HallValueof1_G431Hallcorrec_T *localP)
{
  /* SignalConversion generated from: '<S59>/position' incorporates:
   *  Constant: '<S59>/Constant'
   */
  *rty_position = localP->Constant_Value;
}

/*
 * Output and update for action system:
 *    '<S79>/If Action Subsystem'
 *    '<S306>/If Action Subsystem'
 */
void G431Hallc_IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1)
{
  real32_T tmp;

  /* DataTypeConversion: '<S81>/Convert_uint16' */
  tmp = floorf(rtu_In1);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  /* Sum: '<S81>/Sum' incorporates:
   *  DataTypeConversion: '<S81>/Convert_back'
   *  DataTypeConversion: '<S81>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real32_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S79>/If Action Subsystem1'
 *    '<S306>/If Action Subsystem1'
 */
void G431Hall_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1)
{
  real32_T tmp;

  /* DataTypeConversion: '<S82>/Convert_uint16' */
  tmp = truncf(rtu_In1);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = fmodf(tmp, 65536.0F);
  }

  /* Sum: '<S82>/Sum' incorporates:
   *  DataTypeConversion: '<S82>/Convert_back'
   *  DataTypeConversion: '<S82>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real32_T)(tmp < 0.0F ? (int32_T)(int16_T)-(int16_T)
    (uint16_T)-tmp : (int32_T)(int16_T)(uint16_T)tmp);
}

static void G431Hallcorrec_SystemCore_setup(stm32cube_blocks_AnalogInput__T *obj)
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
  adcStructLoc.InternalBufferSize = 3U;
  adcStructLoc.InjectedNoOfConversion = 3U;
  obj->ADCHandle = ADC_Handle_Init(&adcStructLoc, ADC_INTERRUPT_MODE, 0,
    ADC_READ, LL_ADC_INJ_SEQ_SCAN_ENABLE_3RANKS);
  enableADC(obj->ADCHandle);
  startADCConversionForExternalTrigger(obj->ADCHandle, 0);
  obj->isSetupComplete = true;
}

static void G431Hallcor_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_G4_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S85>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S85>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S85>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/*
 * Output and update for action system:
 *    '<S146>/If Action Subsystem6'
 *    '<S146>/If Action Subsystem7'
 *    '<S121>/If Action Subsystem6'
 *    '<S121>/If Action Subsystem7'
 *    '<S171>/If Action Subsystem6'
 *    '<S171>/If Action Subsystem7'
 */
void G431Hall_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_G431Hall_T *localP)
{
  /* SignalConversion generated from: '<S153>/direction' incorporates:
   *  Constant: '<S153>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S153>/sequence_check' incorporates:
   *  Constant: '<S153>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S146>/If Action Subsystem'
 *    '<S146>/If Action Subsystem1'
 *    '<S146>/If Action Subsystem2'
 *    '<S146>/If Action Subsystem3'
 *    '<S146>/If Action Subsystem4'
 *    '<S146>/If Action Subsystem5'
 *    '<S121>/If Action Subsystem'
 *    '<S121>/If Action Subsystem1'
 *    '<S121>/If Action Subsystem2'
 *    '<S121>/If Action Subsystem3'
 *    ...
 */
void G431Hal_IfActionSubsystem_b(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_G431Hal_g_T *localP)
{
  /* SignalConversion generated from: '<S147>/Out1' incorporates:
   *  Constant: '<S147>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S147>/Out2' incorporates:
   *  Constant: '<S147>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S144>/Valid Halls'
 *    '<S119>/Valid Halls'
 *    '<S169>/Valid Halls'
 */
void G431Hallcor_ValidHalls_Init(B_ValidHalls_G431Hallcorrecti_T *localB,
  P_ValidHalls_G431Hallcorrecti_T *localP)
{
  /* SystemInitialize for Merge: '<S146>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S146>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S146>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S146>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S144>/Valid Halls'
 *    '<S119>/Valid Halls'
 *    '<S169>/Valid Halls'
 */
void G431Hallcorrecti_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, B_ValidHalls_G431Hallcorrecti_T *localB,
  DW_ValidHalls_G431Hallcorrect_T *localDW, P_ValidHalls_G431Hallcorrecti_T
  *localP)
{
  /* SwitchCase: '<S146>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem' incorporates:
     *  ActionPort: '<S147>/Action Port'
     */
    G431Hal_IfActionSubsystem_b(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S148>/Action Port'
     */
    G431Hal_IfActionSubsystem_b(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    G431Hal_IfActionSubsystem_b(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    G431Hal_IfActionSubsystem_b(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    G431Hal_IfActionSubsystem_b(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    G431Hal_IfActionSubsystem_b(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem5' */
    break;

   default:
    /* Update for IfAction SubSystem: '<S146>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    /* Update for SwitchCase: '<S146>/Switch Case' */
    localDW->SwitchCaseActionSubsystem_Subsy = 4;

    /* End of Update for SubSystem: '<S146>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S146>/Switch Case' */

  /* If: '<S146>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    G431Hall_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    G431Hall_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S146>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* Merge: '<S146>/Merge3' incorporates:
     *  Constant: '<S155>/Constant'
     *  SignalConversion generated from: '<S155>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S146>/If Action Subsystem8' */

    /* Update for IfAction SubSystem: '<S146>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* Update for If: '<S146>/If' */
    localDW->IfActionSubsystem8_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S146>/If Action Subsystem8' */
  }

  /* End of If: '<S146>/If' */

  /* SignalConversion: '<S146>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S146>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S146>/Switch' incorporates:
   *  Constant: '<S146>/Constant'
   *  RelationalOperator: '<S146>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_k;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S146>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S144>/Bad hall (glitch or wrong connection)'
 *    '<S119>/Bad hall (glitch or wrong connection)'
 *    '<S169>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnect(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S145>/inValidHall' incorporates:
   *  Constant: '<S145>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S145>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S145>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S145>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

static void G431Hallcorr_SystemCore_setup_i(stm32cube_blocks_TimerCapture_T *obj)
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

static void G431Hallcorr_SystemCore_setup_g(stm32cube_blocks_TimerCapture_T *obj)
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

static void G431Hallcor_SystemCore_setup_i2(stm32cube_blocks_TimerCapture_T *obj)
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
void G431Hallcorrection_step0(void)    /* Sample time: [0.001s, 0.0s] */
{
  real_T rtb_Delay2_kx;
  real_T rtb_Delay2_pj;
  real_T rtb_Merge_n;
  real_T rtb_Merge_o_idx_0;
  real_T rtb_Merge_o_idx_1;
  real_T rtb_Sum_g;
  real32_T rtb_convert_pu_f;
  real32_T rtb_indexing;
  uint16_T rtb_Get_Integer;
  boolean_T rtb_Compare_g;

  {                                    /* Sample time: [0.001s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.Subsystem_SubsysRanBC_a);

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.DifferentiationMethod_SubsysRan);

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.IntegralMethod_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.OptimizedDifferentiationMethod_);

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.Subsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(G431Hallcorrection_DW.Accumulate_SubsysRanBC);

  /* RateTransition: '<Root>/Rate Transition1' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read'
   */
  G431Hallcorrection_B.HallCt = G431Hallcorrection_DW.Timehall;

  /* RateTransition: '<Root>/Rate Transition2' incorporates:
   *  DataStoreRead: '<Root>/Data Store Read1'
   */
  G431Hallcorrection_B.Halls = G431Hallcorrection_DW.GlobalHallState;

  /* RateTransition: '<Root>/Rate Transition5' */
  G431Hallcorrection_B.Intedegree = G431Hallcorrection_B.Sum;

  /* RateTransition: '<Root>/Rate Transition6' incorporates:
   *  UnitDelay: '<S103>/Unit Delay'
   */
  G431Hallcorrection_B.Pswfilter = G431Hallcorrection_DW.UnitDelay_DSTATE_hs;

  /* Update for IfAction SubSystem: '<S193>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S298>/Action Port'
   */
  /* Update for SwitchCase: '<S193>/Switch Case' */
  srUpdateBC(G431Hallcorrection_DW.IfActionSubsystem1_SubsysRanBC);

  /* End of Update for SubSystem: '<S193>/If Action Subsystem1' */

  /* Outputs for IfAction SubSystem: '<S193>/If Action Subsystem1' incorporates:
   *  ActionPort: '<S298>/Action Port'
   */
  /* SwitchCase: '<S193>/Switch Case' incorporates:
   *  Product: '<S190>/Product'
   *  Product: '<S190>/Product1'
   *  SignalConversion generated from: '<S298>/In1'
   *  Sum: '<S190>/Sum'
   */
  rtb_Sum_g = 0.0 * 0.0 + 0.0 * 0.0;

  /* End of Outputs for SubSystem: '<S193>/If Action Subsystem1' */

  /* If: '<S190>/If' incorporates:
   *  DataTypeConversion: '<S190>/Cast To Boolean'
   */
  if (rtb_Sum_g != 0.0) {
    /* Outputs for IfAction SubSystem: '<S190>/Subsystem' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    /* Sqrt: '<S199>/Sqrt' */
    rtb_Sum_g = sqrt(rtb_Sum_g);

    /* Outputs for IfAction SubSystem: '<S193>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S298>/Action Port'
     */
    /* SwitchCase: '<S193>/Switch Case' incorporates:
     *  Product: '<S199>/Divide'
     *  Product: '<S199>/Divide1'
     *  SignalConversion generated from: '<S199>/Out1'
     *  SignalConversion generated from: '<S199>/Out2'
     *  SignalConversion generated from: '<S298>/In1'
     */
    rtb_Merge_n = 0.0 / rtb_Sum_g;
    rtb_Sum_g = 1.0 / rtb_Sum_g * 0.0;

    /* End of Outputs for SubSystem: '<S193>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S190>/Subsystem' */

    /* Update for IfAction SubSystem: '<S190>/Subsystem' incorporates:
     *  ActionPort: '<S199>/Action Port'
     */
    /* Update for If: '<S190>/If' */
    srUpdateBC(G431Hallcorrection_DW.Subsystem_SubsysRanBC_a);

    /* End of Update for SubSystem: '<S190>/Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S190>/If Action Subsystem' incorporates:
     *  ActionPort: '<S198>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S193>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S298>/Action Port'
     */
    /* SwitchCase: '<S193>/Switch Case' incorporates:
     *  SignalConversion generated from: '<S198>/Out1'
     *  SignalConversion generated from: '<S198>/Out2'
     *  SignalConversion generated from: '<S298>/In1'
     */
    rtb_Merge_n = 0.0;
    rtb_Sum_g = 0.0;

    /* End of Outputs for SubSystem: '<S193>/If Action Subsystem1' */
    /* End of Outputs for SubSystem: '<S190>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S190>/If Action Subsystem' incorporates:
     *  ActionPort: '<S198>/Action Port'
     */
    /* Update for If: '<S190>/If' */
    srUpdateBC(G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_h);

    /* End of Update for SubSystem: '<S190>/If Action Subsystem' */
  }

  /* End of If: '<S190>/If' */

  /* Delay: '<S300>/Delay' */
  if (G431Hallcorrection_PrevZCX.Delay_Reset_ZCE == POS_ZCSIG) {
    G431Hallcorrection_DW.Delay_DSTATE =
      G431Hallcorrection_P.Delay_InitialCondition_bj;
  }

  G431Hallcorrection_PrevZCX.Delay_Reset_ZCE = 0U;

  /* DataTypeConversion: '<S300>/Data Type Conversion3' incorporates:
   *  Delay: '<S300>/Delay'
   */
  rtb_indexing = (real32_T)G431Hallcorrection_DW.Delay_DSTATE;

  /* Gain: '<S306>/convert_pu' incorporates:
   *  DataTypeConversion: '<S300>/Data Type Conversion3'
   *  Delay: '<S300>/Delay'
   */
  rtb_convert_pu_f = G431Hallcorrection_P.convert_pu_Gain_e * (real32_T)
    G431Hallcorrection_DW.Delay_DSTATE;

  /* If: '<S306>/If' incorporates:
   *  Constant: '<S307>/Constant'
   *  RelationalOperator: '<S307>/Compare'
   */
  if (rtb_convert_pu_f < G431Hallcorrection_P.Constant_Value_e3) {
    /* Outputs for IfAction SubSystem: '<S306>/If Action Subsystem' incorporates:
     *  ActionPort: '<S308>/Action Port'
     */
    G431Hallc_IfActionSubsystem(rtb_convert_pu_f, &rtb_indexing);

    /* End of Outputs for SubSystem: '<S306>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S306>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S309>/Action Port'
     */
    G431Hall_IfActionSubsystem1(rtb_convert_pu_f, &rtb_indexing);

    /* End of Outputs for SubSystem: '<S306>/If Action Subsystem1' */
  }

  /* End of If: '<S306>/If' */

  /* Gain: '<S302>/indexing' */
  rtb_indexing *= G431Hallcorrection_P.indexing_Gain_b;

  /* DataTypeConversion: '<S302>/Get_Integer' */
  rtb_convert_pu_f = truncf(rtb_indexing);
  if (rtIsNaNF(rtb_convert_pu_f) || rtIsInfF(rtb_convert_pu_f)) {
    rtb_convert_pu_f = 0.0F;
  } else {
    rtb_convert_pu_f = fmodf(rtb_convert_pu_f, 65536.0F);
  }

  rtb_Get_Integer = (uint16_T)(rtb_convert_pu_f < 0.0F ? (int32_T)(uint16_T)
    -(int16_T)(uint16_T)-rtb_convert_pu_f : (int32_T)(uint16_T)rtb_convert_pu_f);

  /* End of DataTypeConversion: '<S302>/Get_Integer' */

  /* Sum: '<S302>/Sum2' incorporates:
   *  DataTypeConversion: '<S302>/Data Type Conversion1'
   */
  rtb_indexing -= (real32_T)rtb_Get_Integer;

  /* Selector: '<S302>/Lookup' incorporates:
   *  Constant: '<S302>/offset'
   *  Constant: '<S302>/sine_table_values'
   *  Sum: '<S302>/Sum'
   *  Sum: '<S305>/Sum5'
   */
  rtb_convert_pu_f = G431Hallcorrection_P.sine_table_values_Value_o[(int32_T)
    ((uint32_T)G431Hallcorrection_P.offset_Value_o[3] + rtb_Get_Integer)];

  /* Sum: '<S8>/Sum' incorporates:
   *  Constant: '<S302>/offset'
   *  Constant: '<S302>/sine_table_values'
   *  DataTypeConversion: '<S300>/Data Type Conversion'
   *  DataTypeConversion: '<S300>/Data Type Conversion1'
   *  Product: '<S305>/Product'
   *  Product: '<S305>/Product1'
   *  Product: '<S8>/Product'
   *  Product: '<S8>/Product1'
   *  Selector: '<S302>/Lookup'
   *  Sum: '<S302>/Sum'
   *  Sum: '<S305>/Sum3'
   *  Sum: '<S305>/Sum4'
   *  Sum: '<S305>/Sum5'
   *  Sum: '<S305>/Sum6'
   */
  G431Hallcorrection_B.Add_n = ((G431Hallcorrection_P.sine_table_values_Value_o
    [(int32_T)((uint32_T)G431Hallcorrection_P.offset_Value_o[2] +
               rtb_Get_Integer)] - rtb_convert_pu_f) * rtb_indexing +
    rtb_convert_pu_f) * rtb_Merge_n -
    ((G431Hallcorrection_P.sine_table_values_Value_o[(int32_T)((uint32_T)
       G431Hallcorrection_P.offset_Value_o[0] + rtb_Get_Integer)] -
      G431Hallcorrection_P.sine_table_values_Value_o[(int32_T)((uint32_T)
       G431Hallcorrection_P.offset_Value_o[1] + rtb_Get_Integer)]) *
     rtb_indexing + G431Hallcorrection_P.sine_table_values_Value_o[(int32_T)
     ((uint32_T)G431Hallcorrection_P.offset_Value_o[1] + rtb_Get_Integer)]) *
    rtb_Sum_g;

  /* DiscreteIntegrator: '<S233>/Integrator' */
  if (G431Hallcorrection_DW.Integrator_PrevResetState != 0) {
    G431Hallcorrection_DW.Integrator_DSTATE =
      G431Hallcorrection_P.PIDController_InitialConditionF;
  }

  /* DiscreteIntegrator: '<S233>/Integrator' incorporates:
   *  Gain: '<S230>/Integral Gain'
   */
  G431Hallcorrection_DW.Integrator_DSTATE +=
    G431Hallcorrection_P.PLLwithFeedForward_Ki *
    G431Hallcorrection_P.PLLwithFeedForward_BlkSampleTim *
    G431Hallcorrection_B.Add_n * G431Hallcorrection_P.Integrator_gainval;

  /* SwitchCase: '<S192>/Switch Case' incorporates:
   *  Constant: '<S192>/Constant'
   */
  switch ((int32_T)G431Hallcorrection_P.SpeedFeedforward_SpeedCompMetho) {
   case 1:
    /* Outputs for IfAction SubSystem: '<S192>/DifferentiationMethod' incorporates:
     *  ActionPort: '<S250>/Action Port'
     */
    /* Delay: '<S254>/Delay2' */
    if (G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_k == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay2_DSTATE_o =
        G431Hallcorrection_P.Delay2_InitialCondition;
    }

    G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_k = 0U;
    rtb_Delay2_kx = G431Hallcorrection_DW.Delay2_DSTATE_o;

    /* Delay: '<S254>/Delay3' */
    if (G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_o == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay3_DSTATE_m =
        G431Hallcorrection_P.Delay3_InitialCondition;
    }

    G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_o = 0U;

    /* Switch: '<S258>/Switch1' incorporates:
     *  Constant: '<S258>/FilterConstant'
     *  Constant: '<S258>/One'
     *  Constant: '<S258>/OneMinusFilterConstant'
     *  Constant: '<S258>/UseInputPort'
     *  Constant: '<S258>/a'
     *  Sum: '<S258>/Sum'
     */
    if (G431Hallcorrection_P.UseInputPort_Value >
        G431Hallcorrection_P.Switch1_Threshold) {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.a_Value_j;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.One_Value_a -
        G431Hallcorrection_P.a_Value_j;
    } else {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.FilterConstant_Value_d;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.OneMinusFilterConstant_Value_l;
    }

    /* End of Switch: '<S258>/Switch1' */

    /* Sum: '<S268>/Add1' incorporates:
     *  Product: '<S268>/Product'
     *  Product: '<S268>/Product1'
     *  UnitDelay: '<S268>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_n = rtb_Merge_n * rtb_Merge_o_idx_0 +
      rtb_Merge_o_idx_1 * G431Hallcorrection_DW.UnitDelay_DSTATE_n;

    /* Gain: '<S254>/Gain' incorporates:
     *  Delay: '<S254>/Delay2'
     *  UnitDelay: '<S268>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay2_DSTATE_o = 314.15926535897933 *
      G431Hallcorrection_P.PLLwithFeedForward_MaximumAppli *
      G431Hallcorrection_DW.UnitDelay_DSTATE_n;

    /* Gain: '<S254>/Gain1' incorporates:
     *  Delay: '<S254>/Delay2'
     *  Delay: '<S254>/Delay3'
     *  Gain: '<S255>/Gain1'
     *  Sum: '<S254>/Sum1'
     */
    rtb_Merge_n = 1.0 / (314.15926535897933 *
                         G431Hallcorrection_P.PLLwithFeedForward_MaximumAppli *
                         G431Hallcorrection_P.PLLwithFeedForward_BlkSampleTim +
                         1.0);
    G431Hallcorrection_DW.Delay3_DSTATE_m =
      ((G431Hallcorrection_DW.Delay3_DSTATE_m +
        G431Hallcorrection_DW.Delay2_DSTATE_o) - rtb_Delay2_kx) * rtb_Merge_n;

    /* Delay: '<S255>/Delay2' */
    if (G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_g == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay2_DSTATE_l =
        G431Hallcorrection_P.Delay2_InitialCondition_b;
    }

    G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_g = 0U;
    rtb_Delay2_kx = G431Hallcorrection_DW.Delay2_DSTATE_l;

    /* Delay: '<S255>/Delay3' */
    if (G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_k == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay3_DSTATE_g =
        G431Hallcorrection_P.Delay3_InitialCondition_j;
    }

    G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_k = 0U;

    /* Switch: '<S256>/Switch1' incorporates:
     *  Constant: '<S256>/FilterConstant'
     *  Constant: '<S256>/One'
     *  Constant: '<S256>/OneMinusFilterConstant'
     *  Constant: '<S256>/UseInputPort'
     *  Constant: '<S256>/a'
     *  Sum: '<S256>/Sum'
     */
    if (G431Hallcorrection_P.UseInputPort_Value_f >
        G431Hallcorrection_P.Switch1_Threshold_b) {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.a_Value_c;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.One_Value_l -
        G431Hallcorrection_P.a_Value_c;
    } else {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.FilterConstant_Value_o;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.OneMinusFilterConstant_Value_a;
    }

    /* End of Switch: '<S256>/Switch1' */

    /* Sum: '<S262>/Add1' incorporates:
     *  Product: '<S262>/Product'
     *  Product: '<S262>/Product1'
     *  UnitDelay: '<S262>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_dz = rtb_Sum_g * rtb_Merge_o_idx_0 +
      rtb_Merge_o_idx_1 * G431Hallcorrection_DW.UnitDelay_DSTATE_dz;

    /* Gain: '<S255>/Gain' incorporates:
     *  Delay: '<S255>/Delay2'
     *  UnitDelay: '<S262>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay2_DSTATE_l = 314.15926535897933 *
      G431Hallcorrection_P.PLLwithFeedForward_MaximumAppli *
      G431Hallcorrection_DW.UnitDelay_DSTATE_dz;

    /* Gain: '<S255>/Gain1' incorporates:
     *  Delay: '<S255>/Delay2'
     *  Delay: '<S255>/Delay3'
     *  Sum: '<S255>/Sum1'
     */
    G431Hallcorrection_DW.Delay3_DSTATE_g =
      ((G431Hallcorrection_DW.Delay3_DSTATE_g +
        G431Hallcorrection_DW.Delay2_DSTATE_l) - rtb_Delay2_kx) * rtb_Merge_n;

    /* RelationalOperator: '<S270>/Compare' incorporates:
     *  Constant: '<S270>/Constant'
     *  UnitDelay: '<S262>/Unit Delay'
     */
    rtb_Compare_g = (G431Hallcorrection_DW.UnitDelay_DSTATE_dz >
                     G431Hallcorrection_P.CompareToConstant1_const);

    /* Switch: '<S259>/Switch' incorporates:
     *  Constant: '<S269>/Constant'
     *  Constant: '<S271>/Constant'
     *  Constant: '<S272>/Constant'
     *  Constant: '<S273>/Constant'
     *  Delay: '<S259>/Delay'
     *  Delay: '<S259>/Delay1'
     *  Logic: '<S259>/AND'
     *  Logic: '<S259>/Logical Operator'
     *  Logic: '<S259>/Logical Operator1'
     *  Logic: '<S259>/Logical Operator2'
     *  RelationalOperator: '<S269>/Compare'
     *  RelationalOperator: '<S271>/Compare'
     *  RelationalOperator: '<S272>/Compare'
     *  RelationalOperator: '<S273>/Compare'
     *  Sum: '<S259>/Sum'
     *  UnitDelay: '<S259>/Unit Delay'
     *  UnitDelay: '<S268>/Unit Delay'
     */
    if (((G431Hallcorrection_DW.Delay_DSTATE_f >
          G431Hallcorrection_P.CompareToConstant4_const) ==
         (G431Hallcorrection_DW.UnitDelay_DSTATE_n >
          G431Hallcorrection_P.CompareToConstant_const)) &&
        ((G431Hallcorrection_DW.Delay1_DSTATE_e >
          G431Hallcorrection_P.CompareToConstant5_const) == (int32_T)
         rtb_Compare_g)) {
      G431Hallcorrection_DW.UnitDelay_DSTATE_ov =
        ((G431Hallcorrection_DW.UnitDelay_DSTATE_n -
          G431Hallcorrection_DW.Delay_DSTATE_f >
          G431Hallcorrection_P.CompareToConstant2_const) == (int32_T)
         rtb_Compare_g);
    }

    /* End of Switch: '<S259>/Switch' */

    /* Switch: '<S257>/Switch1' incorporates:
     *  Constant: '<S257>/FilterConstant'
     *  Constant: '<S257>/One'
     *  Constant: '<S257>/OneMinusFilterConstant'
     *  Constant: '<S257>/UseInputPort'
     *  Constant: '<S257>/a'
     *  Sum: '<S257>/Sum'
     */
    if (G431Hallcorrection_P.UseInputPort_Value_n >
        G431Hallcorrection_P.Switch1_Threshold_l) {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.a_Value_i;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.One_Value_i -
        G431Hallcorrection_P.a_Value_i;
    } else {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.FilterConstant_Value_e;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.OneMinusFilterConstant_Value_h;
    }

    /* End of Switch: '<S257>/Switch1' */

    /* Switch: '<S259>/Switch1' incorporates:
     *  Constant: '<S259>/Constant'
     *  Constant: '<S259>/Constant1'
     *  UnitDelay: '<S259>/Unit Delay'
     */
    if (G431Hallcorrection_DW.UnitDelay_DSTATE_ov) {
      rtb_Sum_g = G431Hallcorrection_P.Constant_Value_i;
    } else {
      rtb_Sum_g = G431Hallcorrection_P.Constant1_Value_e;
    }

    /* Sum: '<S265>/Add1' incorporates:
     *  Product: '<S265>/Product'
     *  Product: '<S265>/Product1'
     *  Switch: '<S259>/Switch1'
     *  UnitDelay: '<S265>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_o = rtb_Sum_g * rtb_Merge_o_idx_0 +
      rtb_Merge_o_idx_1 * G431Hallcorrection_DW.UnitDelay_DSTATE_o;

    /* Switch: '<S250>/Switch1' */
    if (G431Hallcorrection_DW.UnitDelay_DSTATE_o >
        G431Hallcorrection_P.Switch1_Threshold_k) {
      /* Math: '<S252>/Math Function' incorporates:
       *  Delay: '<S254>/Delay3'
       *  Delay: '<S255>/Delay3'
       *  Math: '<S250>/Square'
       *  Math: '<S250>/Square1'
       *  Merge: '<S192>/Merge'
       *  Sqrt: '<S250>/Sqrt'
       *  Sum: '<S250>/Sum2'
       *
       * About '<S252>/Math Function':
       *  Operator: reciprocal
       */
      G431Hallcorrection_B.Merge = sqrt(G431Hallcorrection_DW.Delay3_DSTATE_m *
        G431Hallcorrection_DW.Delay3_DSTATE_m +
        G431Hallcorrection_DW.Delay3_DSTATE_g *
        G431Hallcorrection_DW.Delay3_DSTATE_g);
    } else {
      /* Math: '<S252>/Math Function' incorporates:
       *  Delay: '<S254>/Delay3'
       *  Delay: '<S255>/Delay3'
       *  Math: '<S250>/Square'
       *  Math: '<S250>/Square1'
       *  Merge: '<S192>/Merge'
       *  Sqrt: '<S250>/Sqrt'
       *  Sum: '<S250>/Sum2'
       *  UnaryMinus: '<S250>/Unary Minus'
       *
       * About '<S252>/Math Function':
       *  Operator: reciprocal
       */
      G431Hallcorrection_B.Merge = -sqrt(G431Hallcorrection_DW.Delay3_DSTATE_m *
        G431Hallcorrection_DW.Delay3_DSTATE_m +
        G431Hallcorrection_DW.Delay3_DSTATE_g *
        G431Hallcorrection_DW.Delay3_DSTATE_g);
    }

    /* End of Switch: '<S250>/Switch1' */

    /* Update for Delay: '<S259>/Delay' incorporates:
     *  UnitDelay: '<S268>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay_DSTATE_f =
      G431Hallcorrection_DW.UnitDelay_DSTATE_n;

    /* Update for Delay: '<S259>/Delay1' incorporates:
     *  UnitDelay: '<S262>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay1_DSTATE_e =
      G431Hallcorrection_DW.UnitDelay_DSTATE_dz;

    /* End of Outputs for SubSystem: '<S192>/DifferentiationMethod' */

    /* Update for IfAction SubSystem: '<S192>/DifferentiationMethod' incorporates:
     *  ActionPort: '<S250>/Action Port'
     */
    /* Update for SwitchCase: '<S192>/Switch Case' */
    srUpdateBC(G431Hallcorrection_DW.DifferentiationMethod_SubsysRan);

    /* End of Update for SubSystem: '<S192>/DifferentiationMethod' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S192>/IntegralMethod' incorporates:
     *  ActionPort: '<S252>/Action Port'
     */
    /* Switch: '<S278>/Switch1' incorporates:
     *  Constant: '<S278>/FilterConstant'
     *  Constant: '<S278>/One'
     *  Constant: '<S278>/OneMinusFilterConstant'
     *  Constant: '<S278>/UseInputPort'
     *  Constant: '<S278>/a'
     *  Sum: '<S278>/Sum'
     */
    if (G431Hallcorrection_P.UseInputPort_Value_g >
        G431Hallcorrection_P.Switch1_Threshold_e) {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.a_Value_e;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.One_Value_e -
        G431Hallcorrection_P.a_Value_e;
    } else {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.FilterConstant_Value_ep;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.OneMinusFilterConstant_Value_p;
    }

    /* End of Switch: '<S278>/Switch1' */

    /* Sum: '<S286>/Add1' incorporates:
     *  Product: '<S286>/Product'
     *  Product: '<S286>/Product1'
     *  UnitDelay: '<S286>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_h = rtb_Merge_n * rtb_Merge_o_idx_0 +
      rtb_Merge_o_idx_1 * G431Hallcorrection_DW.UnitDelay_DSTATE_h;

    /* Delay: '<S279>/Delay1' */
    if (G431Hallcorrection_PrevZCX.Delay1_Reset_ZCE == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay1_DSTATE =
        G431Hallcorrection_P.Delay1_InitialCondition_b;
    }

    G431Hallcorrection_PrevZCX.Delay1_Reset_ZCE = 0U;

    /* Delay: '<S279>/Delay' */
    if (G431Hallcorrection_PrevZCX.Delay_Reset_ZCE_k == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay_DSTATE_g =
        G431Hallcorrection_P.Delay_InitialCondition_l;
    }

    G431Hallcorrection_PrevZCX.Delay_Reset_ZCE_k = 0U;

    /* Gain: '<S279>/Gain1' incorporates:
     *  Gain: '<S279>/Gain2'
     *  Gain: '<S280>/Gain1'
     */
    rtb_Delay2_kx = 3.1415926535897931 *
      G431Hallcorrection_P.PLLwithFeedForward_MaximumAppli * 0.002 *
      G431Hallcorrection_P.PLLwithFeedForward_BlkSampleTim;
    rtb_Delay2_pj = G431Hallcorrection_P.PLLwithFeedForward_BlkSampleTim / 2.0 /
      (rtb_Delay2_kx + 1.0);

    /* Gain: '<S279>/Gain2' incorporates:
     *  Gain: '<S279>/Gain1'
     *  Gain: '<S280>/Gain2'
     */
    rtb_Delay2_kx = (1.0 - rtb_Delay2_kx) / (rtb_Delay2_kx + 1.0);

    /* Sum: '<S279>/Sum1' incorporates:
     *  Delay: '<S279>/Delay'
     *  Delay: '<S279>/Delay1'
     *  Gain: '<S279>/Gain1'
     *  Gain: '<S279>/Gain2'
     *  Sum: '<S279>/Sum'
     *  UnitDelay: '<S286>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay_DSTATE_g =
      (G431Hallcorrection_DW.UnitDelay_DSTATE_h +
       G431Hallcorrection_DW.Delay1_DSTATE) * rtb_Delay2_pj + rtb_Delay2_kx *
      G431Hallcorrection_DW.Delay_DSTATE_g;

    /* Switch: '<S277>/Switch1' incorporates:
     *  Constant: '<S277>/FilterConstant'
     *  Constant: '<S277>/One'
     *  Constant: '<S277>/OneMinusFilterConstant'
     *  Constant: '<S277>/UseInputPort'
     *  Constant: '<S277>/a'
     *  Sum: '<S277>/Sum'
     */
    if (G431Hallcorrection_P.UseInputPort_Value_j >
        G431Hallcorrection_P.Switch1_Threshold_o) {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.a_Value_n;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.One_Value_n -
        G431Hallcorrection_P.a_Value_n;
    } else {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.FilterConstant_Value_p;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.OneMinusFilterConstant_Value_k;
    }

    /* End of Switch: '<S277>/Switch1' */

    /* Sum: '<S283>/Add1' incorporates:
     *  Product: '<S283>/Product'
     *  Product: '<S283>/Product1'
     *  UnitDelay: '<S283>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_he = rtb_Sum_g * rtb_Merge_o_idx_0 +
      rtb_Merge_o_idx_1 * G431Hallcorrection_DW.UnitDelay_DSTATE_he;

    /* Delay: '<S280>/Delay1' */
    if (G431Hallcorrection_PrevZCX.Delay1_Reset_ZCE_e == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay1_DSTATE_i =
        G431Hallcorrection_P.Delay1_InitialCondition_d;
    }

    G431Hallcorrection_PrevZCX.Delay1_Reset_ZCE_e = 0U;

    /* Delay: '<S280>/Delay' */
    if (G431Hallcorrection_PrevZCX.Delay_Reset_ZCE_a == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay_DSTATE_a =
        G431Hallcorrection_P.Delay_InitialCondition_b;
    }

    G431Hallcorrection_PrevZCX.Delay_Reset_ZCE_a = 0U;

    /* Sum: '<S280>/Sum1' incorporates:
     *  Delay: '<S280>/Delay'
     *  Delay: '<S280>/Delay1'
     *  Gain: '<S280>/Gain1'
     *  Gain: '<S280>/Gain2'
     *  Sum: '<S280>/Sum'
     *  UnitDelay: '<S283>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay_DSTATE_a =
      (G431Hallcorrection_DW.UnitDelay_DSTATE_he +
       G431Hallcorrection_DW.Delay1_DSTATE_i) * rtb_Delay2_pj + rtb_Delay2_kx *
      G431Hallcorrection_DW.Delay_DSTATE_a;

    /* Math: '<S252>/Math Function' incorporates:
     *  Delay: '<S279>/Delay'
     *  Delay: '<S280>/Delay'
     *  Product: '<S252>/Product'
     *  Product: '<S252>/Product1'
     *  Sum: '<S252>/Sum'
     *
     * About '<S252>/Math Function':
     *  Operator: reciprocal
     */
    G431Hallcorrection_B.Merge = 1.0 / (G431Hallcorrection_DW.Delay_DSTATE_a *
      rtb_Merge_n - G431Hallcorrection_DW.Delay_DSTATE_g * rtb_Sum_g);

    /* Switch: '<S252>/Switch1' incorporates:
     *  Abs: '<S252>/Abs'
     */
    if (fabs(G431Hallcorrection_B.Merge) > 6.2831853071795862 *
        G431Hallcorrection_P.PLLwithFeedForward_MaximumAppli * 2.0) {
      /* Math: '<S252>/Math Function' incorporates:
       *  Constant: '<S252>/Constant'
       *  Merge: '<S192>/Merge'
       *
       * About '<S252>/Math Function':
       *  Operator: reciprocal
       */
      G431Hallcorrection_B.Merge = G431Hallcorrection_P.Constant_Value_e;
    }

    /* End of Switch: '<S252>/Switch1' */

    /* Update for Delay: '<S279>/Delay1' incorporates:
     *  UnitDelay: '<S286>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay1_DSTATE =
      G431Hallcorrection_DW.UnitDelay_DSTATE_h;

    /* Update for Delay: '<S280>/Delay1' incorporates:
     *  UnitDelay: '<S283>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay1_DSTATE_i =
      G431Hallcorrection_DW.UnitDelay_DSTATE_he;

    /* End of Outputs for SubSystem: '<S192>/IntegralMethod' */

    /* Update for IfAction SubSystem: '<S192>/IntegralMethod' incorporates:
     *  ActionPort: '<S252>/Action Port'
     */
    /* Update for SwitchCase: '<S192>/Switch Case' */
    srUpdateBC(G431Hallcorrection_DW.IntegralMethod_SubsysRanBC);

    /* End of Update for SubSystem: '<S192>/IntegralMethod' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S192>/OptimizedDifferentiationMethod' incorporates:
     *  ActionPort: '<S253>/Action Port'
     */
    /* Delay: '<S287>/Delay2' */
    if (G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay2_DSTATE =
        G431Hallcorrection_P.Delay2_InitialCondition_j;
    }

    G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE = 0U;
    rtb_Delay2_pj = G431Hallcorrection_DW.Delay2_DSTATE;

    /* Delay: '<S287>/Delay3' */
    if (G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay3_DSTATE =
        G431Hallcorrection_P.Delay3_InitialCondition_l;
    }

    G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE = 0U;

    /* Switch: '<S290>/Switch1' incorporates:
     *  Constant: '<S290>/FilterConstant'
     *  Constant: '<S290>/One'
     *  Constant: '<S290>/OneMinusFilterConstant'
     *  Constant: '<S290>/UseInputPort'
     *  Constant: '<S290>/a'
     *  Sum: '<S290>/Sum'
     */
    if (G431Hallcorrection_P.UseInputPort_Value_m >
        G431Hallcorrection_P.Switch1_Threshold_g) {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.a_Value_p;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.One_Value_f -
        G431Hallcorrection_P.a_Value_p;
    } else {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.FilterConstant_Value_j;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.OneMinusFilterConstant_Value_pq;
    }

    /* End of Switch: '<S290>/Switch1' */

    /* Sum: '<S296>/Add1' incorporates:
     *  Product: '<S296>/Product'
     *  Product: '<S296>/Product1'
     *  UnitDelay: '<S296>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_m = rtb_Merge_n * rtb_Merge_o_idx_0 +
      rtb_Merge_o_idx_1 * G431Hallcorrection_DW.UnitDelay_DSTATE_m;

    /* Gain: '<S287>/Gain' incorporates:
     *  Delay: '<S287>/Delay2'
     *  UnitDelay: '<S296>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay2_DSTATE = 314.15926535897933 *
      G431Hallcorrection_P.PLLwithFeedForward_MaximumAppli *
      G431Hallcorrection_DW.UnitDelay_DSTATE_m;

    /* Gain: '<S287>/Gain1' incorporates:
     *  Delay: '<S287>/Delay2'
     *  Delay: '<S287>/Delay3'
     *  Gain: '<S288>/Gain1'
     *  Sum: '<S287>/Sum1'
     */
    rtb_Delay2_kx = 1.0 / (314.15926535897933 *
      G431Hallcorrection_P.PLLwithFeedForward_MaximumAppli *
      G431Hallcorrection_P.PLLwithFeedForward_BlkSampleTim + 1.0);
    G431Hallcorrection_DW.Delay3_DSTATE = ((G431Hallcorrection_DW.Delay3_DSTATE
      + G431Hallcorrection_DW.Delay2_DSTATE) - rtb_Delay2_pj) * rtb_Delay2_kx;

    /* Delay: '<S288>/Delay2' */
    if (G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_m == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay2_DSTATE_b =
        G431Hallcorrection_P.Delay2_InitialCondition_k;
    }

    G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_m = 0U;
    rtb_Delay2_pj = G431Hallcorrection_DW.Delay2_DSTATE_b;

    /* Delay: '<S288>/Delay3' */
    if (G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_b == POS_ZCSIG) {
      G431Hallcorrection_DW.Delay3_DSTATE_f =
        G431Hallcorrection_P.Delay3_InitialCondition_l4;
    }

    G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_b = 0U;

    /* Switch: '<S289>/Switch1' incorporates:
     *  Constant: '<S289>/FilterConstant'
     *  Constant: '<S289>/One'
     *  Constant: '<S289>/OneMinusFilterConstant'
     *  Constant: '<S289>/UseInputPort'
     *  Constant: '<S289>/a'
     *  Sum: '<S289>/Sum'
     */
    if (G431Hallcorrection_P.UseInputPort_Value_i >
        G431Hallcorrection_P.Switch1_Threshold_f) {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.a_Value_o;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.One_Value_m -
        G431Hallcorrection_P.a_Value_o;
    } else {
      rtb_Merge_o_idx_0 = G431Hallcorrection_P.FilterConstant_Value_h;
      rtb_Merge_o_idx_1 = G431Hallcorrection_P.OneMinusFilterConstant_Value_j;
    }

    /* End of Switch: '<S289>/Switch1' */

    /* Sum: '<S293>/Add1' incorporates:
     *  Product: '<S293>/Product'
     *  Product: '<S293>/Product1'
     *  UnitDelay: '<S293>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_b = rtb_Sum_g * rtb_Merge_o_idx_0 +
      rtb_Merge_o_idx_1 * G431Hallcorrection_DW.UnitDelay_DSTATE_b;

    /* Gain: '<S288>/Gain' incorporates:
     *  Delay: '<S288>/Delay2'
     *  UnitDelay: '<S293>/Unit Delay'
     */
    G431Hallcorrection_DW.Delay2_DSTATE_b = 314.15926535897933 *
      G431Hallcorrection_P.PLLwithFeedForward_MaximumAppli *
      G431Hallcorrection_DW.UnitDelay_DSTATE_b;

    /* Gain: '<S288>/Gain1' incorporates:
     *  Delay: '<S288>/Delay2'
     *  Delay: '<S288>/Delay3'
     *  Sum: '<S288>/Sum1'
     */
    G431Hallcorrection_DW.Delay3_DSTATE_f =
      ((G431Hallcorrection_DW.Delay3_DSTATE_f +
        G431Hallcorrection_DW.Delay2_DSTATE_b) - rtb_Delay2_pj) * rtb_Delay2_kx;

    /* Math: '<S252>/Math Function' incorporates:
     *  Delay: '<S287>/Delay3'
     *  Delay: '<S288>/Delay3'
     *  Merge: '<S192>/Merge'
     *  Product: '<S253>/Product'
     *  Product: '<S253>/Product1'
     *  Sum: '<S253>/Sum'
     *
     * About '<S252>/Math Function':
     *  Operator: reciprocal
     */
    G431Hallcorrection_B.Merge = G431Hallcorrection_DW.Delay3_DSTATE * rtb_Sum_g
      - G431Hallcorrection_DW.Delay3_DSTATE_f * rtb_Merge_n;

    /* End of Outputs for SubSystem: '<S192>/OptimizedDifferentiationMethod' */

    /* Update for IfAction SubSystem: '<S192>/OptimizedDifferentiationMethod' incorporates:
     *  ActionPort: '<S253>/Action Port'
     */
    /* Update for SwitchCase: '<S192>/Switch Case' */
    srUpdateBC(G431Hallcorrection_DW.OptimizedDifferentiationMethod_);

    /* End of Update for SubSystem: '<S192>/OptimizedDifferentiationMethod' */
    break;
  }

  /* End of SwitchCase: '<S192>/Switch Case' */

  /* Switch: '<S251>/Switch1' incorporates:
   *  Constant: '<S251>/FilterConstant'
   *  Constant: '<S251>/One'
   *  Constant: '<S251>/OneMinusFilterConstant'
   *  Constant: '<S251>/UseInputPort'
   *  Constant: '<S251>/a'
   *  Sum: '<S251>/Sum'
   */
  if (G431Hallcorrection_P.UseInputPort_Value_h >
      G431Hallcorrection_P.Switch1_Threshold_p) {
    rtb_Merge_o_idx_0 = G431Hallcorrection_P.a_Value;
    rtb_Merge_o_idx_1 = G431Hallcorrection_P.One_Value -
      G431Hallcorrection_P.a_Value;
  } else {
    rtb_Merge_o_idx_0 = G431Hallcorrection_P.FilterConstant_Value;
    rtb_Merge_o_idx_1 = G431Hallcorrection_P.OneMinusFilterConstant_Value;
  }

  /* End of Switch: '<S251>/Switch1' */

  /* Sum: '<S276>/Add1' incorporates:
   *  Product: '<S276>/Product'
   *  Product: '<S276>/Product1'
   *  UnitDelay: '<S276>/Unit Delay'
   */
  G431Hallcorrection_DW.UnitDelay_DSTATE = G431Hallcorrection_B.Merge *
    rtb_Merge_o_idx_0 + rtb_Merge_o_idx_1 *
    G431Hallcorrection_DW.UnitDelay_DSTATE;

  /* Outputs for Enabled SubSystem: '<S301>/Accumulate' incorporates:
   *  EnablePort: '<S303>/Enable'
   */
  /* Logic: '<S301>/NOT' incorporates:
   *  Constant: '<S301>/Constant_Reset'
   *  Delay: '<S303>/Delay'
   */
  if (!G431Hallcorrection_P.Constant_Reset_Value_c) {
    /* Outputs for Enabled SubSystem: '<S303>/Subsystem' incorporates:
     *  EnablePort: '<S304>/Enable'
     */
    if (G431Hallcorrection_DW.Delay_DSTATE_hn) {
      /* SignalConversion generated from: '<S304>/Input' incorporates:
       *  Gain: '<S238>/Proportional Gain'
       *  Gain: '<S300>/Gain'
       *  Gain: '<S301>/scaleIn'
       *  Sum: '<S242>/Sum'
       *  Sum: '<S8>/Sum1'
       *  UnitDelay: '<S276>/Unit Delay'
       */
      G431Hallcorrection_B.Input = ((G431Hallcorrection_P.PLLwithFeedForward_Kp *
        G431Hallcorrection_B.Add_n + G431Hallcorrection_DW.Integrator_DSTATE) +
        G431Hallcorrection_DW.UnitDelay_DSTATE) *
        (G431Hallcorrection_P.PLLwithFeedForward_BlkSampleTim *
         G431Hallcorrection_P.PLLwithFeedForward_FreqRatio / 6.2831853071795862)
        * G431Hallcorrection_P.scaleIn_Gain;
      srUpdateBC(G431Hallcorrection_DW.Subsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S303>/Subsystem' */

    /* Sum: '<S303>/Add' incorporates:
     *  Delay: '<S303>/Delay'
     *  UnitDelay: '<S301>/Unit Delay'
     */
    G431Hallcorrection_B.Add_n = G431Hallcorrection_B.Input +
      G431Hallcorrection_DW.UnitDelay_DSTATE_d;

    /* DataTypeConversion: '<S303>/Data Type Conversion' */
    rtb_Sum_g = floor(G431Hallcorrection_B.Add_n);
    if (rtIsNaN(rtb_Sum_g) || rtIsInf(rtb_Sum_g)) {
      rtb_Sum_g = 0.0;
    } else {
      rtb_Sum_g = fmod(rtb_Sum_g, 65536.0);
    }

    /* Sum: '<S303>/Add1' incorporates:
     *  DataTypeConversion: '<S303>/Data Type Conversion'
     *  DataTypeConversion: '<S303>/Data Type Conversion1'
     *  UnitDelay: '<S301>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_d = G431Hallcorrection_B.Add_n -
      (real_T)(rtb_Sum_g < 0.0 ? (int32_T)(int16_T)-(int16_T)(uint16_T)
               -rtb_Sum_g : (int32_T)(int16_T)(uint16_T)rtb_Sum_g);

    /* Update for Delay: '<S303>/Delay' incorporates:
     *  Constant: '<S303>/Constant'
     */
    G431Hallcorrection_DW.Delay_DSTATE_hn =
      G431Hallcorrection_P.Constant_Value_a;
    srUpdateBC(G431Hallcorrection_DW.Accumulate_SubsysRanBC);
  }

  /* End of Logic: '<S301>/NOT' */
  /* End of Outputs for SubSystem: '<S301>/Accumulate' */

  /* Gain: '<S301>/scaleOut' incorporates:
   *  Delay: '<S300>/Delay'
   *  UnitDelay: '<S301>/Unit Delay'
   */
  G431Hallcorrection_DW.Delay_DSTATE = G431Hallcorrection_P.scaleOut_Gain *
    G431Hallcorrection_DW.UnitDelay_DSTATE_d;

  /* Update for DiscreteIntegrator: '<S233>/Integrator' */
  G431Hallcorrection_DW.Integrator_PrevResetState = 0;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  G431Hallcorrection_M->Timing.taskTime0 =
    ((time_T)(++G431Hallcorrection_M->Timing.clockTick0)) *
    G431Hallcorrection_M->Timing.stepSize0;
}

/* Model step function for TID1 */
void G431Hallcorrection_step1(void)    /* Sample time: [0.1s, 0.0s] */
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_LED;
  int32_T c;

  /* DiscretePulseGenerator: '<S7>/Pulse Generator' */
  rtb_LED = (G431Hallcorrection_DW.clockTickCounter <
             G431Hallcorrection_P.PulseGenerator_Duty) &&
    (G431Hallcorrection_DW.clockTickCounter >= 0) ?
    G431Hallcorrection_P.PulseGenerator_Amp : 0.0;
  if (G431Hallcorrection_DW.clockTickCounter >=
      G431Hallcorrection_P.PulseGenerator_Period - 1.0) {
    G431Hallcorrection_DW.clockTickCounter = 0;
  } else {
    G431Hallcorrection_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S7>/Pulse Generator' */

  /* MATLABSystem: '<S188>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_LED != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S188>/Digital Port Write' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  G431Hallcorrection_M->Timing.clockTick1++;
}

/* Model initialize function */
void G431Hallcorrection_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(G431Hallcorrection_M, -1);
  G431Hallcorrection_M->Timing.stepSize0 = 0.001;

  /* External mode info */
  G431Hallcorrection_M->Sizes.checksums[0] = (1618639037U);
  G431Hallcorrection_M->Sizes.checksums[1] = (3173770748U);
  G431Hallcorrection_M->Sizes.checksums[2] = (1877920315U);
  G431Hallcorrection_M->Sizes.checksums[3] = (66436241U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[150];
    G431Hallcorrection_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[2] = (sysRanDType *)&G431Hallcorrection_DW.Subsystem_SubsysRanBC_m;
    systemRan[3] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_n;
    systemRan[4] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&G431Hallcorrection_DW.Subsystem_SubsysRanBC_o;
    systemRan[6] = (sysRanDType *)
      &G431Hallcorrection_DW.Accumulate_SubsysRanBC_a;
    systemRan[7] = (sysRanDType *)&G431Hallcorrection_DW.UpCounter_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&G431Hallcorrection_DW.PosGen_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof1_e.HallValueof1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof2_o.HallValueof1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof3_b.HallValueof1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof4_e.HallValueof1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof5_j.HallValueof1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof6_m.HallValueof1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof7_e.HallValueof1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &G431Hallcorrection_DW.SpeedanddirectionarenotvalidPos;
    systemRan[17] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_k;
    systemRan[18] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem1_SubsysRanB_p;
    systemRan[19] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof1_b.HallValueof1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof2_p.HallValueof1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof3_p.HallValueof1_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof4_l.HallValueof1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof5_o.HallValueof1_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof6_g.HallValueof1_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof7_b.HallValueof1_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &G431Hallcorrection_DW.veDirection_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof1.HallValueof1_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof2.HallValueof1_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof3.HallValueof1_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof4.HallValueof1_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof5.HallValueof1_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof6.HallValueof1_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &G431Hallcorrection_DW.HallValueof7.HallValueof1_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &G431Hallcorrection_DW.veDirection_SubsysRanBC_h;
    systemRan[35] = (sysRanDType *)
      &G431Hallcorrection_DW.first_order_SubsysRanBC;
    systemRan[36] = (sysRanDType *)
      &G431Hallcorrection_DW.second_order_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &G431Hallcorrection_DW.Subsystem1_SubsysRanBC_m;
    systemRan[38] = (sysRanDType *)
      &G431Hallcorrection_DW.SpeedanddirectionarevalidUsespe;
    systemRan[39] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[40] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[41] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[42] = (sysRanDType *)
      &G431Hallcorrection_DW.Subsystem_SubsysRanBC_b;
    systemRan[43] = (sysRanDType *)
      &G431Hallcorrection_DW.Subsystem_SubsysRanBC_b;
    systemRan[44] = (sysRanDType *)
      &G431Hallcorrection_DW.Subsystem_SubsysRanBC_b;
    systemRan[45] = (sysRanDType *)&G431Hallcorrection_DW.FindOffset_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem_a.IfActionSubsystem_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[49] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[50] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[51] = (sysRanDType *)&G431Hallcorrection_DW.Subsystem1_SubsysRanBC;
    systemRan[52] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[53] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[54] = (sysRanDType *)
      &G431Hallcorrection_DW.EnabledSubsystem_SubsysRanBC;
    systemRan[55] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[56] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[57] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[58] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[59] = (sysRanDType *)
      &G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan;
    systemRan[60] = (sysRanDType *)&G431Hallcorrection_DW.HALL_A_SubsysRanBC;
    systemRan[61] = (sysRanDType *)&G431Hallcorrection_DW.HALL_A_SubsysRanBC;
    systemRan[62] = (sysRanDType *)&G431Hallcorrection_DW.HALL_A_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &G431Hallcorrection_DW.Badhallglitchorwrongconnectio_f.Badhallglitchorwrongconnection_;
    systemRan[64] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[65] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[67] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[69] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[70] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[71] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[72] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.IfActionSubsystem8_SubsysRanBC;
    systemRan[73] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.SwitchCaseActionSubsystem_Subsy;
    systemRan[74] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[75] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[76] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_p.ValidHalls_SubsysRanBC;
    systemRan[77] = (sysRanDType *)&G431Hallcorrection_DW.HALL_A_SubsysRanBC;
    systemRan[78] = (sysRanDType *)&G431Hallcorrection_DW.HALL_A_SubsysRanBC;
    systemRan[79] = (sysRanDType *)&G431Hallcorrection_DW.HALL_B_SubsysRanBC;
    systemRan[80] = (sysRanDType *)&G431Hallcorrection_DW.HALL_B_SubsysRanBC;
    systemRan[81] = (sysRanDType *)&G431Hallcorrection_DW.HALL_B_SubsysRanBC;
    systemRan[82] = (sysRanDType *)
      &G431Hallcorrection_DW.Badhallglitchorwrongconnection.Badhallglitchorwrongconnection_;
    systemRan[83] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[84] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[85] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[86] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[87] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[88] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[89] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[90] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[91] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC;
    systemRan[92] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy;
    systemRan[93] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[94] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[95] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[96] = (sysRanDType *)&G431Hallcorrection_DW.HALL_B_SubsysRanBC;
    systemRan[97] = (sysRanDType *)&G431Hallcorrection_DW.HALL_B_SubsysRanBC;
    systemRan[98] = (sysRanDType *)&G431Hallcorrection_DW.HALL_C_SubsysRanBC;
    systemRan[99] = (sysRanDType *)&G431Hallcorrection_DW.HALL_C_SubsysRanBC;
    systemRan[100] = (sysRanDType *)&G431Hallcorrection_DW.HALL_C_SubsysRanBC;
    systemRan[101] = (sysRanDType *)
      &G431Hallcorrection_DW.Badhallglitchorwrongconnectio_n.Badhallglitchorwrongconnection_;
    systemRan[102] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[103] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[104] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[105] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[106] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[107] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[108] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[109] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[110] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.IfActionSubsystem8_SubsysRanBC;
    systemRan[111] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.SwitchCaseActionSubsystem_Subsy;
    systemRan[112] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[113] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[114] = (sysRanDType *)
      &G431Hallcorrection_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[115] = (sysRanDType *)&G431Hallcorrection_DW.HALL_C_SubsysRanBC;
    systemRan[116] = (sysRanDType *)&G431Hallcorrection_DW.HALL_C_SubsysRanBC;
    systemRan[117] = &rtAlwaysEnabled;
    systemRan[118] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_h;
    systemRan[119] = (sysRanDType *)
      &G431Hallcorrection_DW.Subsystem_SubsysRanBC_a;
    systemRan[120] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[121] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[122] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[123] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[124] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[125] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[126] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[127] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[128] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[129] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[130] = (sysRanDType *)
      &G431Hallcorrection_DW.DifferentiationMethod_SubsysRan;
    systemRan[131] = &rtAlwaysEnabled;
    systemRan[132] = &rtAlwaysEnabled;
    systemRan[133] = (sysRanDType *)
      &G431Hallcorrection_DW.IntegralMethod_SubsysRanBC;
    systemRan[134] = (sysRanDType *)
      &G431Hallcorrection_DW.IntegralMethod_SubsysRanBC;
    systemRan[135] = (sysRanDType *)
      &G431Hallcorrection_DW.IntegralMethod_SubsysRanBC;
    systemRan[136] = (sysRanDType *)
      &G431Hallcorrection_DW.IntegralMethod_SubsysRanBC;
    systemRan[137] = (sysRanDType *)
      &G431Hallcorrection_DW.IntegralMethod_SubsysRanBC;
    systemRan[138] = (sysRanDType *)
      &G431Hallcorrection_DW.IntegralMethod_SubsysRanBC;
    systemRan[139] = (sysRanDType *)
      &G431Hallcorrection_DW.OptimizedDifferentiationMethod_;
    systemRan[140] = (sysRanDType *)
      &G431Hallcorrection_DW.OptimizedDifferentiationMethod_;
    systemRan[141] = (sysRanDType *)
      &G431Hallcorrection_DW.OptimizedDifferentiationMethod_;
    systemRan[142] = (sysRanDType *)
      &G431Hallcorrection_DW.OptimizedDifferentiationMethod_;
    systemRan[143] = (sysRanDType *)
      &G431Hallcorrection_DW.OptimizedDifferentiationMethod_;
    systemRan[144] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[145] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[146] = (sysRanDType *)&G431Hallcorrection_DW.Subsystem_SubsysRanBC;
    systemRan[147] = (sysRanDType *)
      &G431Hallcorrection_DW.Accumulate_SubsysRanBC;
    systemRan[148] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem_m.IfActionSubsystem_SubsysRanBC;
    systemRan[149] = (sysRanDType *)
      &G431Hallcorrection_DW.IfActionSubsystem1_k.IfActionSubsystem1_SubsysRanBC;
    rteiSetModelMappingInfoPtr(G431Hallcorrection_M->extModeInfo,
      &G431Hallcorrection_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(G431Hallcorrection_M->extModeInfo,
                        G431Hallcorrection_M->Sizes.checksums);
    rteiSetTPtr(G431Hallcorrection_M->extModeInfo, rtmGetTPtr
                (G431Hallcorrection_M));
  }

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  G431Hallcorrection_DW.GlobalHallState =
    G431Hallcorrection_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  G431Hallcorrection_DW.Timehall =
    G431Hallcorrection_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  G431Hallcorrection_DW.HallCcapture =
    G431Hallcorrection_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  G431Hallcorrection_DW.HallAcapture =
    G431Hallcorrection_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  G431Hallcorrection_DW.HallBcapture =
    G431Hallcorrection_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  G431Hallcorrection_DW.GlobalDirection =
    G431Hallcorrection_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  G431Hallcorrection_DW.GlobalSpeedCount =
    G431Hallcorrection_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  G431Hallcorrection_DW.GlobalSpeedValidity =
    G431Hallcorrection_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  G431Hallcorrection_DW.HallStateChangeFlag =
    G431Hallcorrection_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  G431Hallcorrection_DW.Timercntprev =
    G431Hallcorrection_P.DataStoreMemory1_InitialValue;
  G431Hallcorrection_PrevZCX.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_o = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_g = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay_Reset_ZCE_k = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay1_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay2_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
  G431Hallcorrection_PrevZCX.Delay3_Reset_ZCE_b = UNINITIALIZED_ZCSIG;

  /* InitializeConditions for Delay: '<S300>/Delay' */
  G431Hallcorrection_DW.Delay_DSTATE =
    G431Hallcorrection_P.Delay_InitialCondition_bj;

  /* InitializeConditions for DiscreteIntegrator: '<S233>/Integrator' */
  G431Hallcorrection_DW.Integrator_DSTATE =
    G431Hallcorrection_P.PIDController_InitialConditionF;

  /* InitializeConditions for UnitDelay: '<S276>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE =
    G431Hallcorrection_P.UnitDelay_InitialCondition_g;

  /* InitializeConditions for UnitDelay: '<S301>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE_d =
    G431Hallcorrection_P.UnitDelay_InitialCondition_k;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S183>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* System initialize for function-call system: '<Root>/Function-Call Subsystem' */
  {
    int32_T i;
    G431Hallcorrection_M->Timing.clockTick2 =
      G431Hallcorrection_M->Timing.clockTick0;

    /* InitializeConditions for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
    G431Hallcorrection_DW.DiscreteTimeIntegrator_DSTATE =
      G431Hallcorrection_P.DiscreteTimeIntegrator_IC;
    G431Hallcorrection_DW.DiscreteTimeIntegrator_PrevRese = 2;

    /* InitializeConditions for Delay: '<S31>/validityDelay' */
    G431Hallcorrection_DW.validityDelay_DSTATE =
      G431Hallcorrection_P.validityDelay_InitialCondition;

    /* InitializeConditions for Delay: '<S31>/speedCountDelay' */
    G431Hallcorrection_DW.speedCountDelay_DSTATE =
      G431Hallcorrection_P.speedCountDelay_InitialConditio;

    /* InitializeConditions for RelationalOperator: '<S36>/Compare' incorporates:
     *  Delay: '<S32>/Delay One Step1'
     */
    G431Hallcorrection_DW.DelayOneStep1_DSTATE =
      G431Hallcorrection_P.DelayOneStep1_InitialCondition;

    /* InitializeConditions for Delay: '<S32>/Delay One Step' */
    G431Hallcorrection_DW.DelayOneStep_DSTATE =
      G431Hallcorrection_P.SoftwareWatchdogTimer_maxCount;

    /* InitializeConditions for Sum: '<S106>/Add1' incorporates:
     *  UnitDelay: '<S106>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_k =
      G431Hallcorrection_P.UnitDelay_InitialCondition_le;

    /* SystemInitialize for IfAction SubSystem: '<S30>/Speed and direction are valid Use speed to extrapolate position' */
    /* SystemInitialize for Enabled SubSystem: '<S34>/Subsystem1' */
    /* SystemInitialize for Merge: '<S47>/Merge' */
    G431Hallcorrection_B.Merge_h = G431Hallcorrection_P.Merge_InitialOutput_g;

    /* End of SystemInitialize for SubSystem: '<S34>/Subsystem1' */
    /* End of SystemInitialize for SubSystem: '<S30>/Speed and direction are valid Use speed to extrapolate position' */

    /* SystemInitialize for Enabled SubSystem: '<S11>/PosGen' */
    /* InitializeConditions for UnitDelay: '<S27>/Unit Delay' */
    G431Hallcorrection_DW.UnitDelay_DSTATE_i =
      G431Hallcorrection_P.UnitDelay_InitialCondition_a;

    /* SystemInitialize for IfAction SubSystem: '<S23>/If Action Subsystem2' */
    /* InitializeConditions for Saturate: '<S26>/Saturate to 'motor.calibSpeed' RPM' incorporates:
     *  Delay: '<S26>/Delay'
     */
    G431Hallcorrection_DW.Delay_DSTATE_gq =
      G431Hallcorrection_P.Delay_InitialCondition_g;

    /* End of SystemInitialize for SubSystem: '<S23>/If Action Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<S27>/Accumulate' */
    /* InitializeConditions for Delay: '<S28>/Delay' */
    G431Hallcorrection_DW.Delay_DSTATE_p =
      G431Hallcorrection_P.Delay_InitialCondition_f;

    /* SystemInitialize for Enabled SubSystem: '<S28>/Subsystem' */
    /* SystemInitialize for SignalConversion generated from: '<S29>/Input' incorporates:
     *  Outport: '<S29>/Out1'
     */
    G431Hallcorrection_B.Input_m = G431Hallcorrection_P.Out1_Y0_a;

    /* End of SystemInitialize for SubSystem: '<S28>/Subsystem' */

    /* SystemInitialize for Sum: '<S28>/Add1' incorporates:
     *  Outport: '<S28>/theta_e'
     */
    G431Hallcorrection_B.Add1_j = G431Hallcorrection_P.theta_e_Y0_a;

    /* End of SystemInitialize for SubSystem: '<S27>/Accumulate' */

    /* SystemInitialize for Enabled SubSystem: '<S18>/Up Counter' */
    /* InitializeConditions for Delay: '<S24>/Delay' */
    G431Hallcorrection_DW.Delay_DSTATE_h =
      G431Hallcorrection_P.Delay_InitialCondition_e;

    /* SystemInitialize for Sum: '<S24>/Add1' incorporates:
     *  Outport: '<S24>/Count'
     */
    G431Hallcorrection_B.Add1_c = G431Hallcorrection_P.Count_Y0;

    /* End of SystemInitialize for SubSystem: '<S18>/Up Counter' */

    /* SystemInitialize for Gain: '<S27>/scaleOut' incorporates:
     *  Outport: '<S18>/Theta'
     */
    G431Hallcorrection_B.scaleOut = G431Hallcorrection_P.Theta_Y0;

    /* SystemInitialize for RelationalOperator: '<S21>/Compare' incorporates:
     *  Outport: '<S18>/EnPWM'
     */
    G431Hallcorrection_B.Compare = G431Hallcorrection_P.EnPWM_Y0;

    /* End of SystemInitialize for SubSystem: '<S11>/PosGen' */

    /* SystemInitialize for Enabled SubSystem: '<S12>/Find Offset' */
    /* InitializeConditions for Delay: '<S66>/Delay' */
    G431Hallcorrection_DW.Delay_DSTATE_d =
      G431Hallcorrection_P.Delay_InitialCondition_bx;

    /* SystemInitialize for Enabled SubSystem: '<S66>/Subsystem' */
    /* InitializeConditions for UnitDelay: '<S77>/Unit Delay' */
    G431Hallcorrection_DW.UnitDelay_DSTATE_f =
      G431Hallcorrection_P.UnitDelay_InitialCondition_lw;

    /* End of SystemInitialize for SubSystem: '<S66>/Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S12>/Find Offset' */

    /* SystemInitialize for Enabled SubSystem: '<S13>/Enabled Subsystem' */
    /* InitializeConditions for Delay: '<S98>/Delay' */
    G431Hallcorrection_DW.Delay_DSTATE_ge =
      G431Hallcorrection_P.Delay_InitialCondition_l3;

    /* InitializeConditions for Delay: '<S98>/Delay1' */
    G431Hallcorrection_DW.Delay1_DSTATE_m[0] =
      G431Hallcorrection_P.Delay1_InitialCondition_f;
    G431Hallcorrection_DW.Delay1_DSTATE_m[1] =
      G431Hallcorrection_P.Delay1_InitialCondition_f;

    /* InitializeConditions for Delay: '<S98>/Delay2' */
    G431Hallcorrection_DW.Delay2_DSTATE_c[0] =
      G431Hallcorrection_P.Delay2_InitialCondition_bu;

    /* InitializeConditions for Delay: '<S98>/Delay3' */
    G431Hallcorrection_DW.Delay3_DSTATE_c[0] =
      G431Hallcorrection_P.Delay3_InitialCondition_a;

    /* InitializeConditions for Delay: '<S98>/Delay2' */
    G431Hallcorrection_DW.Delay2_DSTATE_c[1] =
      G431Hallcorrection_P.Delay2_InitialCondition_bu;

    /* InitializeConditions for Delay: '<S98>/Delay3' */
    G431Hallcorrection_DW.Delay3_DSTATE_c[1] =
      G431Hallcorrection_P.Delay3_InitialCondition_a;

    /* InitializeConditions for Delay: '<S98>/Delay2' */
    G431Hallcorrection_DW.Delay2_DSTATE_c[2] =
      G431Hallcorrection_P.Delay2_InitialCondition_bu;

    /* InitializeConditions for Delay: '<S98>/Delay3' */
    G431Hallcorrection_DW.Delay3_DSTATE_c[2] =
      G431Hallcorrection_P.Delay3_InitialCondition_a;

    /* InitializeConditions for Delay: '<S98>/Delay4' */
    for (i = 0; i < 5; i++) {
      G431Hallcorrection_DW.Delay4_DSTATE[i] =
        G431Hallcorrection_P.Delay4_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S98>/Delay4' */

    /* SystemInitialize for Gain: '<S98>/Gain' incorporates:
     *  Outport: '<S98>/poswlfilter'
     */
    G431Hallcorrection_B.Gain = G431Hallcorrection_P.poswlfilter_Y0;

    /* End of SystemInitialize for SubSystem: '<S13>/Enabled Subsystem' */

    /* Start for MATLABSystem: '<S15>/Analog to Digital Converter' */
    G431Hallcorrection_DW.obj.isInitialized = 0;
    G431Hallcorrection_DW.obj.matlabCodegenIsDeleted = false;
    G431Hallcorrec_SystemCore_setup(&G431Hallcorrection_DW.obj);

    /* Start for MATLABSystem: '<S85>/PWM Output' */
    G431Hallcorrection_DW.obj_i.matlabCodegenIsDeleted = false;
    G431Hallcorrection_DW.obj_i.isSetupComplete = false;
    G431Hallcorrection_DW.obj_i.isInitialized = 1;
    G431Hallcor_PWMOutput_setupImpl(&G431Hallcorrection_DW.obj_i);
    G431Hallcorrection_DW.obj_i.isSetupComplete = true;

    /* SystemInitialize for Sum: '<S19>/Sum' incorporates:
     *  Outport: '<S1>/intedegree'
     */
    G431Hallcorrection_B.Sum = G431Hallcorrection_P.intedegree_Y0;

    /* SystemInitialize for Outport: '<S1>/poswlfilter' incorporates:
     *  Sum: '<S103>/Add1'
     *  UnitDelay: '<S103>/Unit Delay'
     */
    G431Hallcorrection_DW.UnitDelay_DSTATE_hs =
      G431Hallcorrection_P.poswlfilter_Y0_c;
  }

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_B'
   */
  /* System initialize for function-call system: '<Root>/HALL_B' */
  G431Hallcorrection_M->Timing.clockTick3 =
    G431Hallcorrection_M->Timing.clockTick0;

  /* SystemInitialize for IfAction SubSystem: '<S144>/Valid Halls' */
  G431Hallcor_ValidHalls_Init(&G431Hallcorrection_B.ValidHalls,
    &G431Hallcorrection_P.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S144>/Valid Halls' */

  /* Start for MATLABSystem: '<S3>/Timer Capture' */
  G431Hallcorrection_DW.obj_h.isInitialized = 0;
  G431Hallcorrection_DW.obj_h.matlabCodegenIsDeleted = false;
  G431Hallcorr_SystemCore_setup_i(&G431Hallcorrection_DW.obj_h);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_A'
   */
  /* System initialize for function-call system: '<Root>/HALL_A' */
  G431Hallcorrection_M->Timing.clockTick4 =
    G431Hallcorrection_M->Timing.clockTick0;

  /* SystemInitialize for IfAction SubSystem: '<S119>/Valid Halls' */
  G431Hallcor_ValidHalls_Init(&G431Hallcorrection_B.ValidHalls_p,
    &G431Hallcorrection_P.ValidHalls_p);

  /* End of SystemInitialize for SubSystem: '<S119>/Valid Halls' */

  /* Start for MATLABSystem: '<S2>/Timer Capture' */
  G431Hallcorrection_DW.obj_a.isInitialized = 0;
  G431Hallcorrection_DW.obj_a.matlabCodegenIsDeleted = false;
  G431Hallcorr_SystemCore_setup_g(&G431Hallcorrection_DW.obj_a);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_C'
   */
  /* System initialize for function-call system: '<Root>/HALL_C' */
  G431Hallcorrection_M->Timing.clockTick5 =
    G431Hallcorrection_M->Timing.clockTick0;

  /* SystemInitialize for IfAction SubSystem: '<S169>/Valid Halls' */
  G431Hallcor_ValidHalls_Init(&G431Hallcorrection_B.ValidHalls_b,
    &G431Hallcorrection_P.ValidHalls_b);

  /* End of SystemInitialize for SubSystem: '<S169>/Valid Halls' */

  /* Start for MATLABSystem: '<S4>/Timer Capture' */
  G431Hallcorrection_DW.obj_e.isInitialized = 0;
  G431Hallcorrection_DW.obj_e.matlabCodegenIsDeleted = false;
  G431Hallcor_SystemCore_setup_i2(&G431Hallcorrection_DW.obj_e);

  /* SystemInitialize for IfAction SubSystem: '<S192>/DifferentiationMethod' */
  /* InitializeConditions for Delay: '<S254>/Delay2' */
  G431Hallcorrection_DW.Delay2_DSTATE_o =
    G431Hallcorrection_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S254>/Delay3' */
  G431Hallcorrection_DW.Delay3_DSTATE_m =
    G431Hallcorrection_P.Delay3_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S268>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE_n =
    G431Hallcorrection_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Delay: '<S255>/Delay2' */
  G431Hallcorrection_DW.Delay2_DSTATE_l =
    G431Hallcorrection_P.Delay2_InitialCondition_b;

  /* InitializeConditions for Delay: '<S255>/Delay3' */
  G431Hallcorrection_DW.Delay3_DSTATE_g =
    G431Hallcorrection_P.Delay3_InitialCondition_j;

  /* InitializeConditions for UnitDelay: '<S262>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE_dz =
    G431Hallcorrection_P.UnitDelay_InitialCondition_p;

  /* InitializeConditions for Delay: '<S259>/Delay' */
  G431Hallcorrection_DW.Delay_DSTATE_f =
    G431Hallcorrection_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S259>/Delay1' */
  G431Hallcorrection_DW.Delay1_DSTATE_e =
    G431Hallcorrection_P.Delay1_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S259>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE_ov =
    G431Hallcorrection_P.UnitDelay_InitialCondition_kj;

  /* InitializeConditions for Sum: '<S265>/Add1' incorporates:
   *  UnitDelay: '<S265>/Unit Delay'
   */
  G431Hallcorrection_DW.UnitDelay_DSTATE_o =
    G431Hallcorrection_P.UnitDelay_InitialCondition_l;

  /* End of SystemInitialize for SubSystem: '<S192>/DifferentiationMethod' */

  /* SystemInitialize for IfAction SubSystem: '<S192>/IntegralMethod' */
  /* InitializeConditions for UnitDelay: '<S286>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE_h =
    G431Hallcorrection_P.UnitDelay_InitialCondition_d;

  /* InitializeConditions for Delay: '<S279>/Delay1' */
  G431Hallcorrection_DW.Delay1_DSTATE =
    G431Hallcorrection_P.Delay1_InitialCondition_b;

  /* InitializeConditions for Delay: '<S279>/Delay' */
  G431Hallcorrection_DW.Delay_DSTATE_g =
    G431Hallcorrection_P.Delay_InitialCondition_l;

  /* InitializeConditions for UnitDelay: '<S283>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE_he =
    G431Hallcorrection_P.UnitDelay_InitialCondition_l4;

  /* InitializeConditions for Delay: '<S280>/Delay1' */
  G431Hallcorrection_DW.Delay1_DSTATE_i =
    G431Hallcorrection_P.Delay1_InitialCondition_d;

  /* InitializeConditions for Delay: '<S280>/Delay' */
  G431Hallcorrection_DW.Delay_DSTATE_a =
    G431Hallcorrection_P.Delay_InitialCondition_b;

  /* End of SystemInitialize for SubSystem: '<S192>/IntegralMethod' */

  /* SystemInitialize for IfAction SubSystem: '<S192>/OptimizedDifferentiationMethod' */
  /* InitializeConditions for Delay: '<S287>/Delay2' */
  G431Hallcorrection_DW.Delay2_DSTATE =
    G431Hallcorrection_P.Delay2_InitialCondition_j;

  /* InitializeConditions for Delay: '<S287>/Delay3' */
  G431Hallcorrection_DW.Delay3_DSTATE =
    G431Hallcorrection_P.Delay3_InitialCondition_l;

  /* InitializeConditions for UnitDelay: '<S296>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE_m =
    G431Hallcorrection_P.UnitDelay_InitialCondition_n;

  /* InitializeConditions for Delay: '<S288>/Delay2' */
  G431Hallcorrection_DW.Delay2_DSTATE_b =
    G431Hallcorrection_P.Delay2_InitialCondition_k;

  /* InitializeConditions for Delay: '<S288>/Delay3' */
  G431Hallcorrection_DW.Delay3_DSTATE_f =
    G431Hallcorrection_P.Delay3_InitialCondition_l4;

  /* InitializeConditions for UnitDelay: '<S293>/Unit Delay' */
  G431Hallcorrection_DW.UnitDelay_DSTATE_b =
    G431Hallcorrection_P.UnitDelay_InitialCondition_c;

  /* End of SystemInitialize for SubSystem: '<S192>/OptimizedDifferentiationMethod' */

  /* SystemInitialize for Math: '<S252>/Math Function' incorporates:
   *  Merge: '<S192>/Merge'
   *
   * About '<S252>/Math Function':
   *  Operator: reciprocal
   */
  G431Hallcorrection_B.Merge = G431Hallcorrection_P.Merge_InitialOutput;

  /* SystemInitialize for Enabled SubSystem: '<S301>/Accumulate' */
  /* InitializeConditions for Delay: '<S303>/Delay' */
  G431Hallcorrection_DW.Delay_DSTATE_hn =
    G431Hallcorrection_P.Delay_InitialCondition_o;

  /* SystemInitialize for Enabled SubSystem: '<S303>/Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S304>/Input' incorporates:
   *  Outport: '<S304>/Out1'
   */
  G431Hallcorrection_B.Input = G431Hallcorrection_P.Out1_Y0;

  /* End of SystemInitialize for SubSystem: '<S303>/Subsystem' */

  /* SystemInitialize for Outport: '<S303>/theta_e' incorporates:
   *  Sum: '<S303>/Add1'
   *  UnitDelay: '<S301>/Unit Delay'
   */
  G431Hallcorrection_DW.UnitDelay_DSTATE_d = G431Hallcorrection_P.theta_e_Y0;

  /* End of SystemInitialize for SubSystem: '<S301>/Accumulate' */
  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S183>/Hardware Interrupt' */

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S183>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */
  /* Enable for function-call system: '<Root>/Function-Call Subsystem' */
  G431Hallcorrection_M->Timing.clockTick2 =
    G431Hallcorrection_M->Timing.clockTick0;
  G431Hallcorrection_DW.FunctionCallSubsystem_RESET_ELA = true;

  /* Enable for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
  G431Hallcorrection_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S183>/Hardware Interrupt' */
}

/* Model terminate function */
void G431Hallcorrection_terminate(void)
{
  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S183>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem'
   */

  /* Termination for function-call system: '<Root>/Function-Call Subsystem' */

  /* Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */
  if (!G431Hallcorrection_DW.obj.matlabCodegenIsDeleted) {
    G431Hallcorrection_DW.obj.matlabCodegenIsDeleted = true;
    if ((G431Hallcorrection_DW.obj.isInitialized == 1) &&
        G431Hallcorrection_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(G431Hallcorrection_DW.obj.ADCHandle, ADC_INTERRUPT_MODE,
                        0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S15>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S85>/PWM Output' */
  if (!G431Hallcorrection_DW.obj_i.matlabCodegenIsDeleted) {
    G431Hallcorrection_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((G431Hallcorrection_DW.obj_i.isInitialized == 1) &&
        G431Hallcorrection_DW.obj_i.isSetupComplete) {
      disableCounter(G431Hallcorrection_DW.obj_i.TimerHandle);
      disableTimerInterrupts(G431Hallcorrection_DW.obj_i.TimerHandle, 0);
      disableTimerChannel1(G431Hallcorrection_DW.obj_i.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(G431Hallcorrection_DW.obj_i.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(G431Hallcorrection_DW.obj_i.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S85>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S183>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_B'
   */
  /* Termination for function-call system: '<Root>/HALL_B' */

  /* Terminate for MATLABSystem: '<S3>/Timer Capture' */
  if (!G431Hallcorrection_DW.obj_h.matlabCodegenIsDeleted) {
    G431Hallcorrection_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((G431Hallcorrection_DW.obj_h.isInitialized == 1) &&
        G431Hallcorrection_DW.obj_h.isSetupComplete) {
      disableCounter(G431Hallcorrection_DW.obj_h.TimerHandle);
      disableTimerInterrupts(G431Hallcorrection_DW.obj_h.TimerHandle, 26);
      disableTimerChannel1(G431Hallcorrection_DW.obj_h.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S3>/Timer Capture' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_A'
   */
  /* Termination for function-call system: '<Root>/HALL_A' */

  /* Terminate for MATLABSystem: '<S2>/Timer Capture' */
  if (!G431Hallcorrection_DW.obj_a.matlabCodegenIsDeleted) {
    G431Hallcorrection_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((G431Hallcorrection_DW.obj_a.isInitialized == 1) &&
        G431Hallcorrection_DW.obj_a.isSetupComplete) {
      disableCounter(G431Hallcorrection_DW.obj_a.TimerHandle);
      disableTimerInterrupts(G431Hallcorrection_DW.obj_a.TimerHandle, 26);
      disableTimerChannel3(G431Hallcorrection_DW.obj_a.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Timer Capture' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HALL_C'
   */

  /* Termination for function-call system: '<Root>/HALL_C' */

  /* Terminate for MATLABSystem: '<S4>/Timer Capture' */
  if (!G431Hallcorrection_DW.obj_e.matlabCodegenIsDeleted) {
    G431Hallcorrection_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((G431Hallcorrection_DW.obj_e.isInitialized == 1) &&
        G431Hallcorrection_DW.obj_e.isSetupComplete) {
      disableCounter(G431Hallcorrection_DW.obj_e.TimerHandle);
      disableTimerInterrupts(G431Hallcorrection_DW.obj_e.TimerHandle, 26);
      disableTimerChannel4(G431Hallcorrection_DW.obj_e.TimerHandle, ENABLE_CH);
    }
  }

  /* End of Terminate for MATLABSystem: '<S4>/Timer Capture' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' */
}

void G431Hallcorrection_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC1_2_IRQHandler,3);
  MW_NVIC_EnableIRQ(33);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(44,&TIM3_IRQHandler,2);
  MW_NVIC_EnableIRQ(44);
}

/* Hardware Interrupt Block: '<S183>/Hardware Interrupt' */
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
        srClearBC(G431Hallcorrection_DW.Subsystem_SubsysRanBC_m);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_n);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.IfActionSubsystem2_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.Subsystem_SubsysRanBC_o);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.Accumulate_SubsysRanBC_a);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.UpCounter_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.PosGen_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_k);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.IfActionSubsystem1_SubsysRanB_p);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.HallValueof1.HallValueof1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.veDirection_SubsysRanBC_h);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.veDirection_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.second_order_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.first_order_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.Subsystem1_SubsysRanBC_m);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.SpeedanddirectionarevalidUsespe);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.SpeedanddirectionarenotvalidPos);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.Subsystem_SubsysRanBC_b);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.FindOffset_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (G431Hallcorrection_DW.IfActionSubsystem_a.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (G431Hallcorrection_DW.IfActionSubsystem1_f.IfActionSubsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.Subsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.EnabledSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan);

        /* S-Function (HardwareInterrupt_sfun): '<S183>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/Function-Call Subsystem' */
        {
          real_T rtb_Switch4_idx_1;
          real_T rtb_Switch4_idx_2;
          uint64_T tmp_p;
          real32_T rtb_Add1_e;
          real32_T rtb_Merge1_d;
          real32_T rtb_algDD_o2;
          real32_T rtb_indexing;
          uint32_T FunctionCallSubsystem_ELAPS_T;
          uint16_T tmp[3];
          uint16_T Switch;
          uint16_T rtb_DataStoreRead6;
          uint16_T rtb_Get_Integer;
          uint16_T rtb_counterSize1;
          boolean_T OR;
          G431Hallcorrection_M->Timing.clockTick2 =
            G431Hallcorrection_M->Timing.clockTick0;
          if (G431Hallcorrection_DW.FunctionCallSubsystem_RESET_ELA) {
            FunctionCallSubsystem_ELAPS_T = 0U;
          } else {
            FunctionCallSubsystem_ELAPS_T =
              G431Hallcorrection_M->Timing.clockTick2 -
              G431Hallcorrection_DW.FunctionCallSubsystem_PREV_T;
          }

          G431Hallcorrection_DW.FunctionCallSubsystem_PREV_T =
            G431Hallcorrection_M->Timing.clockTick2;
          G431Hallcorrection_DW.FunctionCallSubsystem_RESET_ELA = false;

          /* DataStoreRead: '<S19>/Data Store Read6' */
          rtb_DataStoreRead6 = G431Hallcorrection_DW.HallStateChangeFlag;

          /* Switch: '<S30>/Switch' incorporates:
           *  Constant: '<S30>/WatchDog'
           *  DataStoreRead: '<S19>/Data Store Read6'
           *  DataStoreWrite: '<S19>/Data Store Write3'
           */
          if (G431Hallcorrection_DW.HallStateChangeFlag != 0) {
            G431Hallcorrection_DW.HallStateChangeFlag =
              G431Hallcorrection_P.WatchDog_Value;
          }

          /* End of Switch: '<S30>/Switch' */

          /* DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
          if (G431Hallcorrection_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
            if ((rtb_DataStoreRead6 > 0) &&
                (G431Hallcorrection_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
              G431Hallcorrection_DW.DiscreteTimeIntegrator_DSTATE =
                G431Hallcorrection_P.DiscreteTimeIntegrator_IC;
            } else {
              /* DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
              G431Hallcorrection_DW.DiscreteTimeIntegrator_DSTATE += (real32_T)
                (G431Hallcorrection_P.DiscreteTimeIntegrator_gainval * (real_T)
                 FunctionCallSubsystem_ELAPS_T
                 * G431Hallcorrection_DW.DiscreteTimeIntegrator_PREV_U);
            }
          }

          if (G431Hallcorrection_DW.DiscreteTimeIntegrator_DSTATE >
              G431Hallcorrection_P.DiscreteTimeIntegrator_UpperSat) {
            /* DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
            G431Hallcorrection_DW.DiscreteTimeIntegrator_DSTATE =
              G431Hallcorrection_P.DiscreteTimeIntegrator_UpperSat;
          } else if (G431Hallcorrection_DW.DiscreteTimeIntegrator_DSTATE <
                     G431Hallcorrection_P.DiscreteTimeIntegrator_LowerSat) {
            /* DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
            G431Hallcorrection_DW.DiscreteTimeIntegrator_DSTATE =
              G431Hallcorrection_P.DiscreteTimeIntegrator_LowerSat;
          }

          /* End of DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */

          /* Switch: '<S31>/Switch' incorporates:
           *  Constant: '<S31>/Order'
           */
          if (G431Hallcorrection_P.Order_Value >
              G431Hallcorrection_P.Switch_Threshold_h) {
            /* Switch: '<S31>/Switch' */
            Switch = rtb_DataStoreRead6;
          } else {
            /* Switch: '<S31>/Switch' */
            Switch = G431Hallcorrection_P.Order_Value;
          }

          /* End of Switch: '<S31>/Switch' */

          /* Delay: '<S31>/validityDelay' incorporates:
           *  Delay: '<S31>/speedCountDelay'
           */
          if (Switch != 0) {
            /* Delay: '<S31>/validityDelay' */
            G431Hallcorrection_B.validityDelay =
              G431Hallcorrection_DW.validityDelay_DSTATE;

            /* Delay: '<S31>/speedCountDelay' */
            G431Hallcorrection_B.speedCountDelay =
              G431Hallcorrection_DW.speedCountDelay_DSTATE;
          }

          /* End of Delay: '<S31>/validityDelay' */

          /* DataTypeConversion: '<S30>/counterSize1' incorporates:
           *  DataStoreRead: '<S19>/Data Store Read'
           *  DataStoreRead: '<S19>/Data Store Read2'
           *  DataStoreRead: '<S19>/Data Store Read7'
           *  MinMax: '<S19>/Min'
           */
          G431Hallcorrection_B.rtb_Switch4_idx_0 = floor(fmin(fmin
            (G431Hallcorrection_DW.HallAcapture,
             G431Hallcorrection_DW.HallBcapture),
            G431Hallcorrection_DW.HallCcapture));
          if (rtIsNaN(G431Hallcorrection_B.rtb_Switch4_idx_0) || rtIsInf
              (G431Hallcorrection_B.rtb_Switch4_idx_0)) {
            G431Hallcorrection_B.rtb_Switch4_idx_0 = 0.0;
          } else {
            G431Hallcorrection_B.rtb_Switch4_idx_0 = fmod
              (G431Hallcorrection_B.rtb_Switch4_idx_0, 65536.0);
          }

          rtb_counterSize1 = (uint16_T)(G431Hallcorrection_B.rtb_Switch4_idx_0 <
            0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
            -G431Hallcorrection_B.rtb_Switch4_idx_0 : (int32_T)(uint16_T)
            G431Hallcorrection_B.rtb_Switch4_idx_0);

          /* End of DataTypeConversion: '<S30>/counterSize1' */

          /* Logic: '<S32>/OR' incorporates:
           *  DataTypeConversion: '<S30>/Data Type Conversion4'
           *  Delay: '<S32>/Delay One Step1'
           */
          OR = (G431Hallcorrection_DW.DelayOneStep1_DSTATE ||
                (rtb_DataStoreRead6 != 0));

          /* Delay: '<S32>/Delay One Step' incorporates:
           *  DataTypeConversion: '<S30>/Data Type Conversion4'
           */
          if (OR) {
            if (rtb_DataStoreRead6 != 0) {
              G431Hallcorrection_DW.DelayOneStep_DSTATE =
                G431Hallcorrection_P.SoftwareWatchdogTimer_maxCount;
            }

            /* Delay: '<S32>/Delay One Step' incorporates:
             *  DataTypeConversion: '<S30>/Data Type Conversion4'
             */
            G431Hallcorrection_B.DelayOneStep =
              G431Hallcorrection_DW.DelayOneStep_DSTATE;
          }

          /* End of Delay: '<S32>/Delay One Step' */

          /* RelationalOperator: '<S36>/Compare' incorporates:
           *  Constant: '<S36>/Constant'
           */
          G431Hallcorrection_DW.DelayOneStep1_DSTATE =
            (G431Hallcorrection_B.DelayOneStep >
             G431Hallcorrection_P.Constant_Value_mo);

          /* Switch: '<S35>/watchdog check' incorporates:
           *  Constant: '<S35>/Constant'
           */
          if (G431Hallcorrection_DW.DelayOneStep1_DSTATE) {
            /* MinMax: '<S35>/Max' incorporates:
             *  DataStoreRead: '<S19>/Data Store Read3'
             */
            if (G431Hallcorrection_DW.GlobalSpeedCount >= rtb_counterSize1) {
              rtb_Get_Integer = G431Hallcorrection_DW.GlobalSpeedCount;
            } else {
              rtb_Get_Integer = rtb_counterSize1;
            }

            /* Switch: '<S35>/speed check' incorporates:
             *  Constant: '<S35>/Constant'
             *  DataStoreRead: '<S19>/Data Store Read5'
             *  DataTypeConversion: '<S31>/Data Type Conversion'
             *  Logic: '<S31>/Logical Operator'
             *  MinMax: '<S35>/Max'
             */
            if (rtb_Get_Integer >= G431Hallcorrection_P.speedcheck_Threshold) {
              rtb_Get_Integer = G431Hallcorrection_P.Constant_Value_p;
            } else {
              rtb_Get_Integer = (uint16_T)
                ((G431Hallcorrection_DW.GlobalSpeedValidity != 0) ||
                 G431Hallcorrection_B.validityDelay);
            }

            /* End of Switch: '<S35>/speed check' */
          } else {
            rtb_Get_Integer = G431Hallcorrection_P.Constant_Value_p;
          }

          /* End of Switch: '<S35>/watchdog check' */

          /* If: '<S30>/If' incorporates:
           *  Constant: '<S34>/PositionEnable'
           */
          if (rtb_Get_Integer != 0) {
            /* Outputs for IfAction SubSystem: '<S30>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S34>/Action Port'
             */
            /* If: '<S34>/If' incorporates:
             *  DataStoreRead: '<S19>/Data Store Read4'
             */
            if (G431Hallcorrection_DW.GlobalDirection > 0) {
              /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
               *  ActionPort: '<S45>/Action Port'
               */
              /* Merge: '<S30>/Merge' incorporates:
               *  Constant: '<S34>/SpeedConst'
               *  DataStoreRead: '<S19>/Data Store Read3'
               *  DataTypeConversion: '<S34>/SpeedConstData'
               *  DataTypeConversion: '<S34>/currentSpeedData'
               *  Gain: '<S34>/SpeedGain'
               *  Product: '<S34>/Divide'
               *  SignalConversion generated from: '<S45>/In1'
               */
              G431Hallcorrection_DW.DiscreteTimeIntegrator_PREV_U = (real32_T)
                G431Hallcorrection_P.SpeedConst_Value / (real32_T)
                G431Hallcorrection_DW.GlobalSpeedCount *
                G431Hallcorrection_P.SpeedGain_Gain;

              /* End of Outputs for SubSystem: '<S34>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S34>/If Action Subsystem' incorporates:
               *  ActionPort: '<S45>/Action Port'
               */
              /* Update for If: '<S34>/If' */
              G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_k = 4;

              /* End of Update for SubSystem: '<S34>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S46>/Action Port'
               */
              /* Merge: '<S30>/Merge' incorporates:
               *  Constant: '<S34>/SpeedConst'
               *  DataStoreRead: '<S19>/Data Store Read3'
               *  DataTypeConversion: '<S34>/SpeedConstData'
               *  DataTypeConversion: '<S34>/currentSpeedData'
               *  Gain: '<S34>/SpeedGain'
               *  Product: '<S34>/Divide'
               *  UnaryMinus: '<S46>/Unary Minus'
               */
              G431Hallcorrection_DW.DiscreteTimeIntegrator_PREV_U = -((real32_T)
                G431Hallcorrection_P.SpeedConst_Value / (real32_T)
                G431Hallcorrection_DW.GlobalSpeedCount *
                G431Hallcorrection_P.SpeedGain_Gain);

              /* End of Outputs for SubSystem: '<S34>/If Action Subsystem1' */

              /* Update for IfAction SubSystem: '<S34>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S46>/Action Port'
               */
              /* Update for If: '<S34>/If' */
              G431Hallcorrection_DW.IfActionSubsystem1_SubsysRanB_p = 4;

              /* End of Update for SubSystem: '<S34>/If Action Subsystem1' */
            }

            /* End of If: '<S34>/If' */

            /* Outputs for Enabled SubSystem: '<S34>/Subsystem1' incorporates:
             *  EnablePort: '<S47>/Enable'
             */
            if (G431Hallcorrection_P.PositionEnable_Value > 0) {
              /* If: '<S47>/If1' incorporates:
               *  Constant: '<S47>/Constant'
               */
              if (G431Hallcorrection_P.Constant_Value > 1.0) {
                /* Outputs for IfAction SubSystem: '<S47>/second_order' incorporates:
                 *  ActionPort: '<S51>/Action Port'
                 */
                /* Product: '<S51>/Divide1' incorporates:
                 *  DataStoreRead: '<S19>/Data Store Read3'
                 *  DataTypeConversion: '<S51>/countData'
                 *  DataTypeConversion: '<S51>/currentSpeedData'
                 */
                rtb_indexing = (real32_T)rtb_counterSize1 / (real32_T)
                  G431Hallcorrection_DW.GlobalSpeedCount;

                /* Gain: '<S51>/Gain' incorporates:
                 *  Constant: '<S51>/Constant'
                 *  DataTypeConversion: '<S51>/countData'
                 *  DataTypeConversion: '<S51>/previousSpeedData'
                 *  Gain: '<S51>/Gain1'
                 *  Product: '<S51>/Divide'
                 *  Product: '<S51>/Product'
                 *  Sum: '<S51>/Sum'
                 *  Sum: '<S51>/Sum1'
                 */
                rtb_indexing = ((rtb_indexing - (real32_T)rtb_counterSize1 /
                                 (real32_T)G431Hallcorrection_B.speedCountDelay)
                                * G431Hallcorrection_P.Gain1_Gain_k +
                                G431Hallcorrection_P.Constant_Value_g) *
                  rtb_indexing * G431Hallcorrection_P.Gain_Gain;

                /* End of Outputs for SubSystem: '<S47>/second_order' */

                /* Update for IfAction SubSystem: '<S47>/second_order' incorporates:
                 *  ActionPort: '<S51>/Action Port'
                 */
                /* Update for If: '<S47>/If1' */
                G431Hallcorrection_DW.second_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S47>/second_order' */
              } else {
                /* Outputs for IfAction SubSystem: '<S47>/first_order' incorporates:
                 *  ActionPort: '<S50>/Action Port'
                 */
                /* Gain: '<S50>/Gain' incorporates:
                 *  DataStoreRead: '<S19>/Data Store Read3'
                 *  DataTypeConversion: '<S50>/countData'
                 *  DataTypeConversion: '<S50>/currentSpeedData'
                 *  Product: '<S50>/Divide'
                 */
                rtb_indexing = (real32_T)rtb_counterSize1 / (real32_T)
                  G431Hallcorrection_DW.GlobalSpeedCount *
                  G431Hallcorrection_P.Gain_Gain_j;

                /* End of Outputs for SubSystem: '<S47>/first_order' */

                /* Update for IfAction SubSystem: '<S47>/first_order' incorporates:
                 *  ActionPort: '<S50>/Action Port'
                 */
                /* Update for If: '<S47>/If1' */
                G431Hallcorrection_DW.first_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S47>/first_order' */
              }

              /* End of If: '<S47>/If1' */

              /* Saturate: '<S47>/Saturation' */
              if (rtb_indexing > G431Hallcorrection_P.Saturation_UpperSat) {
                rtb_indexing = G431Hallcorrection_P.Saturation_UpperSat;
              } else if (rtb_indexing < G431Hallcorrection_P.Saturation_LowerSat)
              {
                rtb_indexing = G431Hallcorrection_P.Saturation_LowerSat;
              }

              /* End of Saturate: '<S47>/Saturation' */

              /* If: '<S47>/If' incorporates:
               *  DataStoreRead: '<S19>/Data Store Read4'
               */
              if (G431Hallcorrection_DW.GlobalDirection != 1) {
                /* Outputs for IfAction SubSystem: '<S47>/-ve Direction' incorporates:
                 *  ActionPort: '<S49>/Action Port'
                 */
                /* SwitchCase: '<S49>/Switch Case' incorporates:
                 *  DataStoreRead: '<S19>/Data Store Read1'
                 */
                switch (G431Hallcorrection_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S49>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S59>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof1);

                  /* End of Outputs for SubSystem: '<S49>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S49>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S60>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof2);

                  /* End of Outputs for SubSystem: '<S49>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S49>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S61>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof3);

                  /* End of Outputs for SubSystem: '<S49>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S49>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S62>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof4);

                  /* End of Outputs for SubSystem: '<S49>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S49>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S63>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof5);

                  /* End of Outputs for SubSystem: '<S49>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S49>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S64>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof6);

                  /* End of Outputs for SubSystem: '<S49>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S49>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S65>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof7);

                  /* End of Outputs for SubSystem: '<S49>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S49>/Switch Case' */

                /* Merge: '<S47>/Merge' incorporates:
                 *  Sum: '<S49>/Sum'
                 */
                G431Hallcorrection_B.Merge_h = rtb_Merge1_d - rtb_indexing;

                /* End of Outputs for SubSystem: '<S47>/-ve Direction' */

                /* Update for IfAction SubSystem: '<S47>/-ve Direction' incorporates:
                 *  ActionPort: '<S49>/Action Port'
                 */
                /* Update for If: '<S47>/If' */
                G431Hallcorrection_DW.veDirection_SubsysRanBC_h = 4;

                /* End of Update for SubSystem: '<S47>/-ve Direction' */
              } else {
                /* Outputs for IfAction SubSystem: '<S47>/+ve Direction' incorporates:
                 *  ActionPort: '<S48>/Action Port'
                 */
                /* SwitchCase: '<S48>/Switch Case' incorporates:
                 *  DataStoreRead: '<S19>/Data Store Read1'
                 */
                switch (G431Hallcorrection_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S52>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof1_b);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S53>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof2_p);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S54>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof3_p);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S55>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof4_l);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S56>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof5_o);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S57>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof6_g);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S58>/Action Port'
                   */
                  G431Hallcorrec_HallValueof1(&rtb_Merge1_d,
                    &G431Hallcorrection_P.HallValueof7_b);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S48>/Switch Case' */

                /* Merge: '<S47>/Merge' incorporates:
                 *  Sum: '<S48>/Sum'
                 */
                G431Hallcorrection_B.Merge_h = rtb_Merge1_d + rtb_indexing;

                /* End of Outputs for SubSystem: '<S47>/+ve Direction' */

                /* Update for IfAction SubSystem: '<S47>/+ve Direction' incorporates:
                 *  ActionPort: '<S48>/Action Port'
                 */
                /* Update for If: '<S47>/If' */
                G431Hallcorrection_DW.veDirection_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S47>/+ve Direction' */
              }

              /* End of If: '<S47>/If' */
              G431Hallcorrection_DW.Subsystem1_SubsysRanBC_m = 4;
            }

            /* End of Outputs for SubSystem: '<S34>/Subsystem1' */

            /* SignalConversion generated from: '<S34>/rawPosition' incorporates:
             *  Constant: '<S34>/PositionEnable'
             */
            rtb_indexing = G431Hallcorrection_B.Merge_h;

            /* End of Outputs for SubSystem: '<S30>/Speed and direction are valid Use speed to extrapolate position' */

            /* Update for IfAction SubSystem: '<S30>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S34>/Action Port'
             */
            /* Update for If: '<S30>/If' */
            G431Hallcorrection_DW.SpeedanddirectionarevalidUsespe = 4;

            /* End of Update for SubSystem: '<S30>/Speed and direction are valid Use speed to extrapolate position' */
          } else {
            /* Outputs for IfAction SubSystem: '<S30>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S33>/Action Port'
             */
            /* SwitchCase: '<S37>/Switch Case' incorporates:
             *  DataStoreRead: '<S19>/Data Store Read1'
             */
            switch (G431Hallcorrection_DW.GlobalHallState) {
             case 5:
              /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 1' incorporates:
               *  ActionPort: '<S38>/Action Port'
               */
              G431Hallcorrec_HallValueof1(&rtb_indexing,
                &G431Hallcorrection_P.HallValueof1_e);

              /* End of Outputs for SubSystem: '<S37>/Hall Value of 1' */
              break;

             case 4:
              /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 2' incorporates:
               *  ActionPort: '<S39>/Action Port'
               */
              G431Hallcorrec_HallValueof1(&rtb_indexing,
                &G431Hallcorrection_P.HallValueof2_o);

              /* End of Outputs for SubSystem: '<S37>/Hall Value of 2' */
              break;

             case 6:
              /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 3' incorporates:
               *  ActionPort: '<S40>/Action Port'
               */
              G431Hallcorrec_HallValueof1(&rtb_indexing,
                &G431Hallcorrection_P.HallValueof3_b);

              /* End of Outputs for SubSystem: '<S37>/Hall Value of 3' */
              break;

             case 2:
              /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 4' incorporates:
               *  ActionPort: '<S41>/Action Port'
               */
              G431Hallcorrec_HallValueof1(&rtb_indexing,
                &G431Hallcorrection_P.HallValueof4_e);

              /* End of Outputs for SubSystem: '<S37>/Hall Value of 4' */
              break;

             case 3:
              /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 5' incorporates:
               *  ActionPort: '<S42>/Action Port'
               */
              G431Hallcorrec_HallValueof1(&rtb_indexing,
                &G431Hallcorrection_P.HallValueof5_j);

              /* End of Outputs for SubSystem: '<S37>/Hall Value of 5' */
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 6' incorporates:
               *  ActionPort: '<S43>/Action Port'
               */
              G431Hallcorrec_HallValueof1(&rtb_indexing,
                &G431Hallcorrection_P.HallValueof6_m);

              /* End of Outputs for SubSystem: '<S37>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S37>/Hall Value of 7' incorporates:
               *  ActionPort: '<S44>/Action Port'
               */
              G431Hallcorrec_HallValueof1(&rtb_indexing,
                &G431Hallcorrection_P.HallValueof7_e);

              /* End of Outputs for SubSystem: '<S37>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S37>/Switch Case' */

            /* Merge: '<S30>/Merge' incorporates:
             *  Constant: '<S33>/Constant'
             *  SignalConversion generated from: '<S33>/Speed(r.p.m)'
             */
            G431Hallcorrection_DW.DiscreteTimeIntegrator_PREV_U =
              G431Hallcorrection_P.Constant_Value_n;

            /* End of Outputs for SubSystem: '<S30>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */

            /* Update for IfAction SubSystem: '<S30>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S33>/Action Port'
             */
            /* Update for If: '<S30>/If' */
            G431Hallcorrection_DW.SpeedanddirectionarenotvalidPos = 4;

            /* End of Update for SubSystem: '<S30>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
          }

          /* End of If: '<S30>/If' */

          /* Sum: '<S19>/Sum' incorporates:
           *  Gain: '<S30>/PositionUnit'
           */
          G431Hallcorrection_B.Sum = G431Hallcorrection_P.PositionUnit_Gain *
            rtb_indexing + G431Hallcorrection_DW.DiscreteTimeIntegrator_DSTATE;

          /* Outputs for Enabled SubSystem: '<S11>/PosGen' incorporates:
           *  EnablePort: '<S18>/Enable'
           */
          /* Constant: '<S1>/Constant1' */
          if (G431Hallcorrection_P.Constant1_Value_d > 0.0) {
            if (!G431Hallcorrection_DW.PosGen_MODE) {
              /* InitializeConditions for UnitDelay: '<S27>/Unit Delay' */
              G431Hallcorrection_DW.UnitDelay_DSTATE_i =
                G431Hallcorrection_P.UnitDelay_InitialCondition_a;
              G431Hallcorrection_DW.PosGen_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S18>/Up Counter' incorporates:
             *  EnablePort: '<S24>/Enable'
             */
            if (G431Hallcorrection_P.Constant1_Value_d > 0.0) {
              if (!G431Hallcorrection_DW.UpCounter_MODE) {
                /* InitializeConditions for Delay: '<S24>/Delay' */
                G431Hallcorrection_DW.Delay_DSTATE_h =
                  G431Hallcorrection_P.Delay_InitialCondition_e;
                G431Hallcorrection_DW.UpCounter_MODE = true;
              }

              /* Sum: '<S24>/Add1' incorporates:
               *  Constant: '<S24>/Constant'
               *  Delay: '<S24>/Delay'
               */
              tmp_p = (uint64_T)G431Hallcorrection_P.Constant_Value_j +
                G431Hallcorrection_DW.Delay_DSTATE_h;
              if (tmp_p > 4294967295ULL) {
                tmp_p = 4294967295ULL;
              }

              /* Sum: '<S24>/Add1' */
              G431Hallcorrection_B.Add1_c = (uint32_T)tmp_p;

              /* Update for Delay: '<S24>/Delay' */
              G431Hallcorrection_DW.Delay_DSTATE_h = G431Hallcorrection_B.Add1_c;
              G431Hallcorrection_DW.UpCounter_SubsysRanBC = 4;
            } else if (G431Hallcorrection_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S24>/Add1' incorporates:
               *  Outport: '<S24>/Count'
               */
              G431Hallcorrection_B.Add1_c = G431Hallcorrection_P.Count_Y0;
              G431Hallcorrection_DW.UpCounter_MODE = false;
            }

            /* End of Outputs for SubSystem: '<S18>/Up Counter' */

            /* RelationalOperator: '<S21>/Compare' incorporates:
             *  Constant: '<S21>/Constant'
             */
            G431Hallcorrection_B.Compare = (G431Hallcorrection_B.Add1_c <=
              G431Hallcorrection_P.EnablePWMfor40seconds_const);

            /* If: '<S23>/If' incorporates:
             *  Constant: '<S23>/Count for 2 sec'
             */
            if (G431Hallcorrection_B.Add1_c <
                G431Hallcorrection_P.Countfor2sec_Value) {
              /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
               *  ActionPort: '<S25>/Action Port'
               */
              /* SignalConversion generated from: '<S25>/Out1' incorporates:
               *  Constant: '<S25>/Constant'
               */
              rtb_indexing = G431Hallcorrection_P.Constant_Value_m;

              /* End of Outputs for SubSystem: '<S23>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S23>/If Action Subsystem' incorporates:
               *  ActionPort: '<S25>/Action Port'
               */
              /* Update for If: '<S23>/If' */
              G431Hallcorrection_DW.IfActionSubsystem_SubsysRanBC_n = 4;

              /* End of Update for SubSystem: '<S23>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S23>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S26>/Action Port'
               */
              /* Saturate: '<S26>/Saturate to 'motor.calibSpeed' RPM' incorporates:
               *  Constant: '<S26>/Constant1'
               *  Delay: '<S26>/Delay'
               *  Sum: '<S26>/Add1'
               */
              G431Hallcorrection_DW.Delay_DSTATE_gq +=
                G431Hallcorrection_P.Constant1_Value_g;

              /* Saturate: '<S26>/Saturate to 'motor.calibSpeed' RPM' */
              if (G431Hallcorrection_DW.Delay_DSTATE_gq >
                  G431Hallcorrection_P.SaturatetomotorcalibSpeedRPM_Up) {
                /* Saturate: '<S26>/Saturate to 'motor.calibSpeed' RPM' */
                G431Hallcorrection_DW.Delay_DSTATE_gq =
                  G431Hallcorrection_P.SaturatetomotorcalibSpeedRPM_Up;
              } else if (G431Hallcorrection_DW.Delay_DSTATE_gq <
                         G431Hallcorrection_P.SaturatetomotorcalibSpeedRPM_Lo) {
                /* Saturate: '<S26>/Saturate to 'motor.calibSpeed' RPM' */
                G431Hallcorrection_DW.Delay_DSTATE_gq =
                  G431Hallcorrection_P.SaturatetomotorcalibSpeedRPM_Lo;
              }

              /* End of Saturate: '<S26>/Saturate to 'motor.calibSpeed' RPM' */

              /* Gain: '<S26>/Multiply' */
              rtb_indexing = G431Hallcorrection_P.Multiply_Gain *
                G431Hallcorrection_DW.Delay_DSTATE_gq;

              /* End of Outputs for SubSystem: '<S23>/If Action Subsystem2' */

              /* Update for IfAction SubSystem: '<S23>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S26>/Action Port'
               */
              /* Update for If: '<S23>/If' */
              G431Hallcorrection_DW.IfActionSubsystem2_SubsysRanBC = 4;

              /* End of Update for SubSystem: '<S23>/If Action Subsystem2' */
            }

            /* End of If: '<S23>/If' */

            /* Outputs for Enabled SubSystem: '<S27>/Accumulate' incorporates:
             *  EnablePort: '<S28>/Enable'
             */
            /* Logic: '<S27>/NOT' incorporates:
             *  Constant: '<S27>/Constant_Reset'
             *  Delay: '<S28>/Delay'
             */
            if (!G431Hallcorrection_P.Constant_Reset_Value) {
              /* Outputs for Enabled SubSystem: '<S28>/Subsystem' incorporates:
               *  EnablePort: '<S29>/Enable'
               */
              if (G431Hallcorrection_DW.Delay_DSTATE_p) {
                /* SignalConversion generated from: '<S29>/Input' incorporates:
                 *  Gain: '<S27>/scaleIn'
                 */
                G431Hallcorrection_B.Input_m =
                  G431Hallcorrection_P.scaleIn_Gain_n * rtb_indexing;
                G431Hallcorrection_DW.Subsystem_SubsysRanBC_o = 4;
              }

              /* End of Outputs for SubSystem: '<S28>/Subsystem' */

              /* Sum: '<S28>/Add' incorporates:
               *  Delay: '<S28>/Delay'
               *  UnitDelay: '<S27>/Unit Delay'
               */
              rtb_indexing = G431Hallcorrection_B.Input_m +
                G431Hallcorrection_DW.UnitDelay_DSTATE_i;

              /* DataTypeConversion: '<S28>/Data Type Conversion' */
              rtb_Merge1_d = floorf(rtb_indexing);
              if (rtIsNaNF(rtb_Merge1_d) || rtIsInfF(rtb_Merge1_d)) {
                rtb_Merge1_d = 0.0F;
              } else {
                rtb_Merge1_d = fmodf(rtb_Merge1_d, 65536.0F);
              }

              /* Sum: '<S28>/Add1' incorporates:
               *  DataTypeConversion: '<S28>/Data Type Conversion'
               *  DataTypeConversion: '<S28>/Data Type Conversion1'
               */
              G431Hallcorrection_B.Add1_j = rtb_indexing - (real32_T)
                (rtb_Merge1_d < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
                 -rtb_Merge1_d : (int32_T)(int16_T)(uint16_T)rtb_Merge1_d);

              /* Update for Delay: '<S28>/Delay' incorporates:
               *  Constant: '<S28>/Constant'
               */
              G431Hallcorrection_DW.Delay_DSTATE_p =
                G431Hallcorrection_P.Constant_Value_f;
              G431Hallcorrection_DW.Accumulate_SubsysRanBC_a = 4;
            }

            /* End of Logic: '<S27>/NOT' */
            /* End of Outputs for SubSystem: '<S27>/Accumulate' */

            /* Gain: '<S27>/scaleOut' */
            G431Hallcorrection_B.scaleOut = G431Hallcorrection_P.scaleOut_Gain_p
              * G431Hallcorrection_B.Add1_j;

            /* Update for UnitDelay: '<S27>/Unit Delay' */
            G431Hallcorrection_DW.UnitDelay_DSTATE_i =
              G431Hallcorrection_B.Add1_j;
            G431Hallcorrection_DW.PosGen_SubsysRanBC = 4;
          } else if (G431Hallcorrection_DW.PosGen_MODE) {
            /* Disable for Enabled SubSystem: '<S18>/Up Counter' */
            if (G431Hallcorrection_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S24>/Add1' incorporates:
               *  Outport: '<S24>/Count'
               */
              G431Hallcorrection_B.Add1_c = G431Hallcorrection_P.Count_Y0;
              G431Hallcorrection_DW.UpCounter_MODE = false;
            }

            /* End of Disable for SubSystem: '<S18>/Up Counter' */

            /* Disable for RelationalOperator: '<S21>/Compare' incorporates:
             *  Outport: '<S18>/EnPWM'
             */
            G431Hallcorrection_B.Compare = G431Hallcorrection_P.EnPWM_Y0;
            G431Hallcorrection_DW.PosGen_MODE = false;
          }

          /* End of Constant: '<S1>/Constant1' */
          /* End of Outputs for SubSystem: '<S11>/PosGen' */

          /* MATLABSystem: '<S15>/Analog to Digital Converter' */
          injectedReadADCIntr(G431Hallcorrection_DW.obj.ADCHandle, ADC_READ,
                              &tmp[0]);

          /* Gain: '<S79>/convert_pu' */
          rtb_Merge1_d = G431Hallcorrection_P.convert_pu_Gain *
            G431Hallcorrection_B.scaleOut;

          /* If: '<S79>/If' incorporates:
           *  Constant: '<S80>/Constant'
           *  RelationalOperator: '<S80>/Compare'
           */
          if (rtb_Merge1_d < G431Hallcorrection_P.Constant_Value_d) {
            /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem' incorporates:
             *  ActionPort: '<S81>/Action Port'
             */
            G431Hallc_IfActionSubsystem(rtb_Merge1_d, &rtb_indexing);

            /* End of Outputs for SubSystem: '<S79>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S79>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S82>/Action Port'
             */
            G431Hall_IfActionSubsystem1(rtb_Merge1_d, &rtb_indexing);

            /* End of Outputs for SubSystem: '<S79>/If Action Subsystem1' */
          }

          /* End of If: '<S79>/If' */

          /* Gain: '<S67>/indexing' */
          rtb_indexing *= G431Hallcorrection_P.indexing_Gain;

          /* DataTypeConversion: '<S67>/Get_Integer' */
          rtb_Merge1_d = truncf(rtb_indexing);
          if (rtIsNaNF(rtb_Merge1_d) || rtIsInfF(rtb_Merge1_d)) {
            rtb_Merge1_d = 0.0F;
          } else {
            rtb_Merge1_d = fmodf(rtb_Merge1_d, 65536.0F);
          }

          rtb_Get_Integer = (uint16_T)(rtb_Merge1_d < 0.0F ? (int32_T)(uint16_T)
            -(int16_T)(uint16_T)-rtb_Merge1_d : (int32_T)(uint16_T)rtb_Merge1_d);

          /* End of DataTypeConversion: '<S67>/Get_Integer' */

          /* Sum: '<S67>/Sum2' incorporates:
           *  DataTypeConversion: '<S67>/Data Type Conversion1'
           */
          rtb_Merge1_d = rtb_indexing - (real32_T)rtb_Get_Integer;

          /* Outputs for Atomic SubSystem: '<S86>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S88>/a16' incorporates:
           *  Constant: '<S67>/offset'
           *  Constant: '<S67>/sine_table_values'
           *  Constant: '<S70>/Vd_Ref'
           *  Constant: '<S70>/Vq'
           *  Product: '<S78>/Product'
           *  Product: '<S78>/Product1'
           *  Selector: '<S67>/Lookup'
           *  Sum: '<S67>/Sum'
           *  Sum: '<S78>/Sum3'
           *  Sum: '<S78>/Sum4'
           *  Sum: '<S78>/Sum5'
           *  Sum: '<S78>/Sum6'
           */
          arm_inv_park_f32(G431Hallcorrection_P.Vd_Ref_Value,
                           G431Hallcorrection_P.Vq_Value, &rtb_indexing,
                           &rtb_algDD_o2,
                           (G431Hallcorrection_P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            G431Hallcorrection_P.offset_Value[0] + rtb_Get_Integer)] -
                            G431Hallcorrection_P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            G431Hallcorrection_P.offset_Value[1] + rtb_Get_Integer)]) *
                           rtb_Merge1_d +
                           G431Hallcorrection_P.sine_table_values_Value[(int32_T)
                           ((uint32_T)G431Hallcorrection_P.offset_Value[1] +
                            rtb_Get_Integer)],
                           (G431Hallcorrection_P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            G431Hallcorrection_P.offset_Value[2] + rtb_Get_Integer)] -
                            G431Hallcorrection_P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            G431Hallcorrection_P.offset_Value[3] + rtb_Get_Integer)]) *
                           rtb_Merge1_d +
                           G431Hallcorrection_P.sine_table_values_Value[(int32_T)
                           ((uint32_T)G431Hallcorrection_P.offset_Value[3] +
                            rtb_Get_Integer)]);

          /* End of Outputs for SubSystem: '<S86>/Two inputs CRL' */

          /* Switch: '<S68>/Switch4' incorporates:
           *  Constant: '<S68>/Constant1'
           *  Constant: '<S68>/stop'
           *  Gain: '<S68>/Gain'
           *  Gain: '<S68>/Gain1'
           *  Gain: '<S92>/Gain'
           *  Sum: '<S68>/Add'
           *  Sum: '<S92>/Add1'
           *  Sum: '<S92>/Add2'
           *  Sum: '<S92>/Add3'
           */
          if (G431Hallcorrection_B.Compare) {
            /* Gain: '<S96>/sqrt3_by_two' */
            rtb_algDD_o2 *= G431Hallcorrection_P.sqrt3_by_two_Gain;

            /* Gain: '<S96>/one_by_two' */
            rtb_Add1_e = G431Hallcorrection_P.one_by_two_Gain * rtb_indexing;

            /* Gain: '<S96>/Kc' incorporates:
             *  Sum: '<S96>/add_c'
             */
            rtb_Merge1_d = ((0.0F - rtb_Add1_e) - rtb_algDD_o2) *
              G431Hallcorrection_P.Kc_Gain;

            /* Gain: '<S96>/Kb' incorporates:
             *  Sum: '<S96>/add_b'
             */
            rtb_Add1_e = (rtb_algDD_o2 - rtb_Add1_e) *
              G431Hallcorrection_P.Kb_Gain;

            /* Gain: '<S96>/Ka' */
            rtb_algDD_o2 = G431Hallcorrection_P.Ka_Gain * rtb_indexing;

            /* Gain: '<S93>/one_by_two' incorporates:
             *  MinMax: '<S93>/Max'
             *  MinMax: '<S93>/Min'
             *  Sum: '<S93>/Add'
             */
            rtb_indexing = (fmaxf(fmaxf(rtb_algDD_o2, rtb_Add1_e), rtb_Merge1_d)
                            + fminf(fminf(rtb_algDD_o2, rtb_Add1_e),
              rtb_Merge1_d)) * G431Hallcorrection_P.one_by_two_Gain_k;
            G431Hallcorrection_B.rtb_Switch4_idx_0 = ((rtb_algDD_o2 +
              rtb_indexing) * G431Hallcorrection_P.Gain_Gain_d *
              G431Hallcorrection_P.Gain_Gain_m +
              G431Hallcorrection_P.Constant1_Value) *
              G431Hallcorrection_P.Gain1_Gain;
            rtb_Switch4_idx_1 = ((rtb_Add1_e + rtb_indexing) *
                                 G431Hallcorrection_P.Gain_Gain_d *
                                 G431Hallcorrection_P.Gain_Gain_m +
                                 G431Hallcorrection_P.Constant1_Value) *
              G431Hallcorrection_P.Gain1_Gain;
            rtb_Switch4_idx_2 = ((rtb_indexing + rtb_Merge1_d) *
                                 G431Hallcorrection_P.Gain_Gain_d *
                                 G431Hallcorrection_P.Gain_Gain_m +
                                 G431Hallcorrection_P.Constant1_Value) *
              G431Hallcorrection_P.Gain1_Gain;
          } else {
            G431Hallcorrection_B.rtb_Switch4_idx_0 =
              G431Hallcorrection_P.stop_Value;
            rtb_Switch4_idx_1 = G431Hallcorrection_P.stop_Value;
            rtb_Switch4_idx_2 = G431Hallcorrection_P.stop_Value;
          }

          /* End of Switch: '<S68>/Switch4' */

          /* MATLABSystem: '<S85>/PWM Output' */
          setDutyCycleInPercentageChannel1
            (G431Hallcorrection_DW.obj_i.TimerHandle,
             G431Hallcorrection_B.rtb_Switch4_idx_0);
          setDutyCycleInPercentageChannel2
            (G431Hallcorrection_DW.obj_i.TimerHandle, rtb_Switch4_idx_1);
          setDutyCycleInPercentageChannel3
            (G431Hallcorrection_DW.obj_i.TimerHandle, rtb_Switch4_idx_2);

          /* Outputs for Enabled SubSystem: '<S12>/Find Offset' incorporates:
           *  EnablePort: '<S66>/Enable'
           */
          if (G431Hallcorrection_B.Compare) {
            if (!G431Hallcorrection_DW.FindOffset_MODE) {
              /* InitializeConditions for Delay: '<S66>/Delay' */
              G431Hallcorrection_DW.Delay_DSTATE_d =
                G431Hallcorrection_P.Delay_InitialCondition_bx;
              G431Hallcorrection_DW.FindOffset_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S66>/Subsystem' incorporates:
             *  EnablePort: '<S73>/Enable'
             */
            /* Logic: '<S66>/AND' incorporates:
             *  Constant: '<S71>/Constant'
             *  Constant: '<S72>/Constant'
             *  Delay: '<S66>/Delay'
             *  RelationalOperator: '<S71>/Compare'
             *  RelationalOperator: '<S72>/Compare'
             */
            if ((G431Hallcorrection_B.scaleOut <=
                 G431Hallcorrection_P.CompareToConstant_const_o) &&
                (G431Hallcorrection_DW.Delay_DSTATE_d >=
                 G431Hallcorrection_P.CompareToConstant1_const_d)) {
              /* Switch: '<S74>/Switch1' incorporates:
               *  Constant: '<S74>/FilterConstant'
               *  Constant: '<S74>/One'
               *  Constant: '<S74>/OneMinusFilterConstant'
               *  Constant: '<S74>/UseInputPort'
               *  Constant: '<S74>/a'
               *  Sum: '<S74>/Sum'
               */
              if (G431Hallcorrection_P.UseInputPort_Value_d >
                  G431Hallcorrection_P.Switch1_Threshold_pw) {
                rtb_algDD_o2 = G431Hallcorrection_P.a_Value_g;
                rtb_Add1_e = G431Hallcorrection_P.One_Value_mb -
                  G431Hallcorrection_P.a_Value_g;
              } else {
                rtb_algDD_o2 = G431Hallcorrection_P.FilterConstant_Value_f;
                rtb_Add1_e =
                  G431Hallcorrection_P.OneMinusFilterConstant_Value_kk;
              }

              /* End of Switch: '<S74>/Switch1' */

              /* Update for UnitDelay: '<S77>/Unit Delay' incorporates:
               *  Product: '<S77>/Product'
               *  Product: '<S77>/Product1'
               *  Sum: '<S77>/Add1'
               */
              G431Hallcorrection_DW.UnitDelay_DSTATE_f =
                G431Hallcorrection_B.Sum * rtb_algDD_o2 + rtb_Add1_e *
                G431Hallcorrection_DW.UnitDelay_DSTATE_f;
              G431Hallcorrection_DW.Subsystem_SubsysRanBC_b = 4;
            }

            /* End of Logic: '<S66>/AND' */
            /* End of Outputs for SubSystem: '<S66>/Subsystem' */

            /* Update for Delay: '<S66>/Delay' */
            G431Hallcorrection_DW.Delay_DSTATE_d = G431Hallcorrection_B.scaleOut;
            G431Hallcorrection_DW.FindOffset_SubsysRanBC = 4;
          } else {
            G431Hallcorrection_DW.FindOffset_MODE = false;

            /* Outputs for Enabled SubSystem: '<S12>/Subsystem1' incorporates:
             *  EnablePort: '<S69>/Enable'
             */
            G431Hallcorrection_DW.Subsystem1_SubsysRanBC = 4;

            /* End of Outputs for SubSystem: '<S12>/Subsystem1' */
          }

          /* End of Outputs for SubSystem: '<S12>/Find Offset' */

          /* Switch: '<S100>/Switch1' incorporates:
           *  Constant: '<S100>/FilterConstant'
           *  Constant: '<S100>/One'
           *  Constant: '<S100>/OneMinusFilterConstant'
           *  Constant: '<S100>/UseInputPort'
           *  Constant: '<S100>/a'
           *  Sum: '<S100>/Sum'
           */
          if (G431Hallcorrection_P.UseInputPort_Value_jy >
              G431Hallcorrection_P.Switch1_Threshold_pwq) {
            rtb_algDD_o2 = G431Hallcorrection_P.a_Value_k;
            rtb_Add1_e = G431Hallcorrection_P.One_Value_ay -
              G431Hallcorrection_P.a_Value_k;
          } else {
            rtb_algDD_o2 = G431Hallcorrection_P.FilterConstant_Value_a;
            rtb_Add1_e = G431Hallcorrection_P.OneMinusFilterConstant_Value_d;
          }

          /* End of Switch: '<S100>/Switch1' */

          /* Sum: '<S106>/Add1' incorporates:
           *  Product: '<S106>/Product'
           *  Product: '<S106>/Product1'
           *  UnitDelay: '<S106>/Unit Delay'
           */
          G431Hallcorrection_DW.UnitDelay_DSTATE_k =
            G431Hallcorrection_DW.DiscreteTimeIntegrator_PREV_U * rtb_algDD_o2 +
            rtb_Add1_e * G431Hallcorrection_DW.UnitDelay_DSTATE_k;

          /* Outputs for Enabled SubSystem: '<S13>/Enabled Subsystem' incorporates:
           *  EnablePort: '<S98>/Enable'
           */
          /* Logic: '<S13>/OR' incorporates:
           *  Constant: '<S97>/Constant'
           *  RelationalOperator: '<S97>/Compare'
           */
          if ((rtb_DataStoreRead6 != 0) ||
              (G431Hallcorrection_DW.UnitDelay_DSTATE_k <=
               G431Hallcorrection_P.Comparespeedlowthan20RPM_const)) {
            /* Gain: '<S98>/Gain' incorporates:
             *  Delay: '<S98>/Delay'
             *  Delay: '<S98>/Delay1'
             *  Delay: '<S98>/Delay2'
             *  Delay: '<S98>/Delay3'
             *  Delay: '<S98>/Delay4'
             *  Sum: '<S98>/Sum'
             */
            G431Hallcorrection_B.Gain =
              (((((G431Hallcorrection_DW.UnitDelay_DSTATE_k +
                   G431Hallcorrection_DW.Delay_DSTATE_ge) +
                  G431Hallcorrection_DW.Delay1_DSTATE_m[0]) +
                 G431Hallcorrection_DW.Delay2_DSTATE_c[0]) +
                G431Hallcorrection_DW.Delay3_DSTATE_c[0]) +
               G431Hallcorrection_DW.Delay4_DSTATE[0]) *
              G431Hallcorrection_P.Gain_Gain_da;

            /* Update for Delay: '<S98>/Delay' */
            G431Hallcorrection_DW.Delay_DSTATE_ge =
              G431Hallcorrection_DW.UnitDelay_DSTATE_k;

            /* Update for Delay: '<S98>/Delay1' */
            G431Hallcorrection_DW.Delay1_DSTATE_m[0] =
              G431Hallcorrection_DW.Delay1_DSTATE_m[1];
            G431Hallcorrection_DW.Delay1_DSTATE_m[1] =
              G431Hallcorrection_DW.UnitDelay_DSTATE_k;

            /* Update for Delay: '<S98>/Delay2' */
            G431Hallcorrection_DW.Delay2_DSTATE_c[0] =
              G431Hallcorrection_DW.Delay2_DSTATE_c[1];

            /* Update for Delay: '<S98>/Delay3' */
            G431Hallcorrection_DW.Delay3_DSTATE_c[0] =
              G431Hallcorrection_DW.Delay3_DSTATE_c[1];

            /* Update for Delay: '<S98>/Delay2' */
            G431Hallcorrection_DW.Delay2_DSTATE_c[1] =
              G431Hallcorrection_DW.Delay2_DSTATE_c[2];

            /* Update for Delay: '<S98>/Delay3' */
            G431Hallcorrection_DW.Delay3_DSTATE_c[1] =
              G431Hallcorrection_DW.Delay3_DSTATE_c[2];

            /* Update for Delay: '<S98>/Delay2' */
            G431Hallcorrection_DW.Delay2_DSTATE_c[2] =
              G431Hallcorrection_DW.UnitDelay_DSTATE_k;

            /* Update for Delay: '<S98>/Delay3' */
            G431Hallcorrection_DW.Delay3_DSTATE_c[2] =
              G431Hallcorrection_DW.UnitDelay_DSTATE_k;

            /* Update for Delay: '<S98>/Delay4' */
            G431Hallcorrection_DW.Delay4_DSTATE[0] =
              G431Hallcorrection_DW.Delay4_DSTATE[1];
            G431Hallcorrection_DW.Delay4_DSTATE[1] =
              G431Hallcorrection_DW.Delay4_DSTATE[2];
            G431Hallcorrection_DW.Delay4_DSTATE[2] =
              G431Hallcorrection_DW.Delay4_DSTATE[3];
            G431Hallcorrection_DW.Delay4_DSTATE[3] =
              G431Hallcorrection_DW.Delay4_DSTATE[4];
            G431Hallcorrection_DW.Delay4_DSTATE[4] =
              G431Hallcorrection_DW.UnitDelay_DSTATE_k;
            G431Hallcorrection_DW.EnabledSubsystem_SubsysRanBC = 4;
          }

          /* End of Logic: '<S13>/OR' */
          /* End of Outputs for SubSystem: '<S13>/Enabled Subsystem' */

          /* Switch: '<S99>/Switch1' incorporates:
           *  Constant: '<S99>/FilterConstant'
           *  Constant: '<S99>/One'
           *  Constant: '<S99>/OneMinusFilterConstant'
           *  Constant: '<S99>/UseInputPort'
           *  Constant: '<S99>/a'
           *  Sum: '<S99>/Sum'
           */
          if (G431Hallcorrection_P.UseInputPort_Value_if >
              G431Hallcorrection_P.Switch1_Threshold_bz) {
            rtb_algDD_o2 = G431Hallcorrection_P.a_Value_h;
            rtb_Add1_e = G431Hallcorrection_P.One_Value_c -
              G431Hallcorrection_P.a_Value_h;
          } else {
            rtb_algDD_o2 = G431Hallcorrection_P.FilterConstant_Value_i;
            rtb_Add1_e = G431Hallcorrection_P.OneMinusFilterConstant_Value_ar;
          }

          /* End of Switch: '<S99>/Switch1' */

          /* Sum: '<S103>/Add1' incorporates:
           *  Product: '<S103>/Product'
           *  Product: '<S103>/Product1'
           *  UnitDelay: '<S103>/Unit Delay'
           */
          G431Hallcorrection_DW.UnitDelay_DSTATE_hs = G431Hallcorrection_B.Gain *
            rtb_algDD_o2 + rtb_Add1_e *
            G431Hallcorrection_DW.UnitDelay_DSTATE_hs;

          /* Update for DiscreteIntegrator: '<S19>/Discrete-Time Integrator' */
          G431Hallcorrection_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
          G431Hallcorrection_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
            (rtb_DataStoreRead6 > 0);

          /* Update for Delay: '<S31>/validityDelay' incorporates:
           *  DataStoreRead: '<S19>/Data Store Read3'
           *  DataStoreRead: '<S19>/Data Store Read5'
           *  DataTypeConversion: '<S31>/Data Type Conversion'
           *  Delay: '<S31>/speedCountDelay'
           */
          if (Switch != 0) {
            G431Hallcorrection_DW.validityDelay_DSTATE =
              (G431Hallcorrection_DW.GlobalSpeedValidity != 0);
            G431Hallcorrection_DW.speedCountDelay_DSTATE =
              G431Hallcorrection_DW.GlobalSpeedCount;
          }

          /* End of Update for Delay: '<S31>/validityDelay' */

          /* Update for Delay: '<S32>/Delay One Step' incorporates:
           *  Constant: '<S32>/Constant2'
           *  Sum: '<S32>/Sum'
           */
          if (OR) {
            G431Hallcorrection_DW.DelayOneStep_DSTATE = (uint16_T)((uint32_T)
              G431Hallcorrection_B.DelayOneStep -
              G431Hallcorrection_P.Constant2_Value_p3);
          }

          /* End of Update for Delay: '<S32>/Delay One Step' */
          G431Hallcorrection_DW.FunctionCallSubsystem_SubsysRan = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S183>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((G431Hallcorrection_M->Timing.clockTick2) * 0.001);
      extmodeEvent(2,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

/* Hardware Interrupt Block: '<S185>/Hardware Interrupt' */
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
          (G431Hallcorrection_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (G431Hallcorrection_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (G431Hallcorrection_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (G431Hallcorrection_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.ValidHalls.ValidHalls_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (G431Hallcorrection_DW.Badhallglitchorwrongconnection.Badhallglitchorwrongconnection_);

        /* Reset subsysRan breadcrumbs */
        srClearBC(G431Hallcorrection_DW.HALL_B_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_B' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge_p;
          uint8_T rtb_Sum_nt;
          boolean_T rtb_Merge3;
          G431Hallcorrection_M->Timing.clockTick3 =
            G431Hallcorrection_M->Timing.clockTick0;

          /* MATLABSystem: '<S141>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S139>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S143>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S132>/Sum' incorporates:
           *  Gain: '<S132>/Gain'
           *  Gain: '<S132>/Gain1'
           *  MATLABSystem: '<S139>/Digital Port Read'
           *  MATLABSystem: '<S141>/Digital Port Read'
           *  MATLABSystem: '<S143>/Digital Port Read'
           * */
          rtb_Sum_nt = (uint8_T)(((((uint32_T)((pinReadLoc & 256U) != 0U ?
            (int32_T)G431Hallcorrection_P.Gain_Gain_de : 0) << 1) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? (int32_T)
             G431Hallcorrection_P.Gain1_Gain_n : 0)) + ((uint32_T)((pinReadLoc_e
            & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S133>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S133>/Data Type Conversion1'
           */
          switch (rtb_Sum_nt) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S144>/Valid Halls' incorporates:
             *  ActionPort: '<S146>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S133>/Data Type Conversion2'
             */
            G431Hallcorrecti_ValidHalls((uint16_T)rtb_Sum_nt, (uint16_T)
              G431Hallcorrection_DW.GlobalHallState,
              G431Hallcorrection_DW.GlobalDirection, &rtb_Merge3,
              &G431Hallcorrection_DW.GlobalDirection, &rtb_Merge_p,
              &G431Hallcorrection_B.ValidHalls,
              &G431Hallcorrection_DW.ValidHalls,
              &G431Hallcorrection_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S144>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S144>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S145>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431Hallcorrection_DW.GlobalDirection,
              &rtb_Merge_p, &G431Hallcorrection_DW.GlobalDirection, &rtb_Merge3,
              &G431Hallcorrection_P.Badhallglitchorwrongconnection);

            /* End of Outputs for SubSystem: '<S144>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S133>/Detects if the halls reading is valid' */

          /* MATLABSystem: '<S3>/Timer Capture' */
          getCCR1RegisterValuePollingMode
            (G431Hallcorrection_DW.obj_h.TimerHandle, &rtb_Merge_p, &pinReadLoc);

          /* Gain: '<S3>/Gain' incorporates:
           *  DataStoreRead: '<S3>/Data Store Read1'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  DataTypeConversion: '<S3>/Data Type Conversion1'
           *  DataTypeConversion: '<S3>/Data Type Conversion4'
           *  MATLABSystem: '<S3>/Timer Capture'
           *  Sum: '<S3>/Sum1'
           */
          G431Hallcorrection_DW.Timehall = (uint32_T)(uint16_T)((int16_T)
            rtb_Merge_p - G431Hallcorrection_DW.Timercntprev) *
            G431Hallcorrection_P.Gain_Gain_l;

          /* DataTypeConversion: '<S133>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  Gain: '<S3>/Gain'
           */
          G431Hallcorrection_DW.GlobalSpeedCount = (uint16_T)
            (G431Hallcorrection_DW.Timehall >> 15);

          /* DataTypeConversion: '<S144>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          G431Hallcorrection_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S133>/Constant'
           */
          G431Hallcorrection_DW.HallStateChangeFlag =
            G431Hallcorrection_P.Constant_Value_l;

          /* DataStoreWrite: '<S3>/Data Store Write6' */
          G431Hallcorrection_DW.GlobalHallState = rtb_Sum_nt;

          /* DataStoreWrite: '<S134>/Data Store Write' incorporates:
           *  DataTypeConversion: '<S3>/Data Type Conversion1'
           *  MATLABSystem: '<S3>/Timer Capture'
           */
          G431Hallcorrection_DW.Timercntprev = (int16_T)rtb_Merge_p;

          /* DataStoreWrite: '<S3>/Data Store Write5' incorporates:
           *  Constant: '<S3>/Constant2'
           */
          G431Hallcorrection_DW.HallAcapture =
            G431Hallcorrection_P.Constant2_Value;
          G431Hallcorrection_DW.HALL_B_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((G431Hallcorrection_M->Timing.clockTick3) * 0.001);
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
        srClearBC(G431Hallcorrection_DW.HALL_A_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_A' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge_h;
          uint8_T rtb_Sum_do;
          boolean_T rtb_Merge3;
          G431Hallcorrection_M->Timing.clockTick4 =
            G431Hallcorrection_M->Timing.clockTick0;

          /* MATLABSystem: '<S116>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S114>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S118>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S107>/Sum' incorporates:
           *  Gain: '<S107>/Gain'
           *  Gain: '<S107>/Gain1'
           *  MATLABSystem: '<S114>/Digital Port Read'
           *  MATLABSystem: '<S116>/Digital Port Read'
           *  MATLABSystem: '<S118>/Digital Port Read'
           * */
          rtb_Sum_do = (uint8_T)(((((uint32_T)((pinReadLoc & 256U) != 0U ?
            (int32_T)G431Hallcorrection_P.Gain_Gain_jm : 0) << 1) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? (int32_T)
             G431Hallcorrection_P.Gain1_Gain_o : 0)) + ((uint32_T)((pinReadLoc_e
            & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S108>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S108>/Data Type Conversion1'
           */
          switch (rtb_Sum_do) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S119>/Valid Halls' incorporates:
             *  ActionPort: '<S121>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S108>/Data Type Conversion2'
             */
            G431Hallcorrecti_ValidHalls((uint16_T)rtb_Sum_do, (uint16_T)
              G431Hallcorrection_DW.GlobalHallState,
              G431Hallcorrection_DW.GlobalDirection, &rtb_Merge3,
              &G431Hallcorrection_DW.GlobalDirection, &rtb_Merge_h,
              &G431Hallcorrection_B.ValidHalls_p,
              &G431Hallcorrection_DW.ValidHalls_p,
              &G431Hallcorrection_P.ValidHalls_p);

            /* End of Outputs for SubSystem: '<S119>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S119>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S120>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431Hallcorrection_DW.GlobalDirection,
              &rtb_Merge_h, &G431Hallcorrection_DW.GlobalDirection, &rtb_Merge3,
              &G431Hallcorrection_P.Badhallglitchorwrongconnectio_f);

            /* End of Outputs for SubSystem: '<S119>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S108>/Detects if the halls reading is valid' */

          /* MATLABSystem: '<S2>/Timer Capture' */
          getCCR3RegisterValuePollingMode
            (G431Hallcorrection_DW.obj_a.TimerHandle, &rtb_Merge_h, &pinReadLoc);

          /* Gain: '<S2>/Gain' incorporates:
           *  DataStoreRead: '<S2>/Data Store Read1'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  DataTypeConversion: '<S2>/Data Type Conversion1'
           *  DataTypeConversion: '<S2>/Data Type Conversion4'
           *  MATLABSystem: '<S2>/Timer Capture'
           *  Sum: '<S2>/Sum1'
           */
          G431Hallcorrection_DW.Timehall = (uint32_T)(uint16_T)((int16_T)
            rtb_Merge_h - G431Hallcorrection_DW.Timercntprev) *
            G431Hallcorrection_P.Gain_Gain_b;

          /* DataTypeConversion: '<S108>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  Gain: '<S2>/Gain'
           */
          G431Hallcorrection_DW.GlobalSpeedCount = (uint16_T)
            (G431Hallcorrection_DW.Timehall >> 15);

          /* DataTypeConversion: '<S119>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          G431Hallcorrection_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S108>/Constant'
           */
          G431Hallcorrection_DW.HallStateChangeFlag =
            G431Hallcorrection_P.Constant_Value_ih;

          /* DataStoreWrite: '<S2>/Data Store Write6' */
          G431Hallcorrection_DW.GlobalHallState = rtb_Sum_do;

          /* DataStoreWrite: '<S109>/Data Store Write' incorporates:
           *  DataTypeConversion: '<S2>/Data Type Conversion1'
           *  MATLABSystem: '<S2>/Timer Capture'
           */
          G431Hallcorrection_DW.Timercntprev = (int16_T)rtb_Merge_h;

          /* DataStoreWrite: '<S2>/Data Store Write5' incorporates:
           *  Constant: '<S2>/Constant2'
           */
          G431Hallcorrection_DW.HallAcapture =
            G431Hallcorrection_P.Constant2_Value_b;
          G431Hallcorrection_DW.HALL_A_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((G431Hallcorrection_M->Timing.clockTick4) * 0.001);
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
        srClearBC(G431Hallcorrection_DW.HALL_C_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HALL_C' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge_i;
          uint8_T rtb_Sum_n;
          boolean_T rtb_Merge3;
          G431Hallcorrection_M->Timing.clockTick5 =
            G431Hallcorrection_M->Timing.clockTick0;

          /* MATLABSystem: '<S166>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S164>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S168>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S157>/Sum' incorporates:
           *  Gain: '<S157>/Gain'
           *  Gain: '<S157>/Gain1'
           *  MATLABSystem: '<S164>/Digital Port Read'
           *  MATLABSystem: '<S166>/Digital Port Read'
           *  MATLABSystem: '<S168>/Digital Port Read'
           * */
          rtb_Sum_n = (uint8_T)(((((uint32_T)((pinReadLoc & 256U) != 0U ?
            (int32_T)G431Hallcorrection_P.Gain_Gain_e : 0) << 1) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? (int32_T)
             G431Hallcorrection_P.Gain1_Gain_oh : 0)) + ((uint32_T)
            ((pinReadLoc_e & 512U) != 0U) << 6)) >> 6);

          /* SwitchCase: '<S158>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S158>/Data Type Conversion1'
           */
          switch (rtb_Sum_n) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S169>/Valid Halls' incorporates:
             *  ActionPort: '<S171>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S158>/Data Type Conversion2'
             */
            G431Hallcorrecti_ValidHalls((uint16_T)rtb_Sum_n, (uint16_T)
              G431Hallcorrection_DW.GlobalHallState,
              G431Hallcorrection_DW.GlobalDirection, &rtb_Merge3,
              &G431Hallcorrection_DW.GlobalDirection, &rtb_Merge_i,
              &G431Hallcorrection_B.ValidHalls_b,
              &G431Hallcorrection_DW.ValidHalls_b,
              &G431Hallcorrection_P.ValidHalls_b);

            /* End of Outputs for SubSystem: '<S169>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S169>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S170>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnect(G431Hallcorrection_DW.GlobalDirection,
              &rtb_Merge_i, &G431Hallcorrection_DW.GlobalDirection, &rtb_Merge3,
              &G431Hallcorrection_P.Badhallglitchorwrongconnectio_n);

            /* End of Outputs for SubSystem: '<S169>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S158>/Detects if the halls reading is valid' */

          /* MATLABSystem: '<S4>/Timer Capture' */
          getCCR4RegisterValuePollingMode
            (G431Hallcorrection_DW.obj_e.TimerHandle, &rtb_Merge_i, &pinReadLoc);

          /* Gain: '<S4>/Gain' incorporates:
           *  DataStoreRead: '<S4>/Data Store Read1'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  DataTypeConversion: '<S4>/Data Type Conversion1'
           *  DataTypeConversion: '<S4>/Data Type Conversion4'
           *  MATLABSystem: '<S4>/Timer Capture'
           *  Sum: '<S4>/Sum1'
           */
          G431Hallcorrection_DW.Timehall = (uint32_T)(uint16_T)((int16_T)
            rtb_Merge_i - G431Hallcorrection_DW.Timercntprev) *
            G431Hallcorrection_P.Gain_Gain_i;

          /* DataTypeConversion: '<S158>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  Gain: '<S4>/Gain'
           */
          G431Hallcorrection_DW.GlobalSpeedCount = (uint16_T)
            (G431Hallcorrection_DW.Timehall >> 15);

          /* DataTypeConversion: '<S169>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          G431Hallcorrection_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S158>/Constant'
           */
          G431Hallcorrection_DW.HallStateChangeFlag =
            G431Hallcorrection_P.Constant_Value_pl;

          /* DataStoreWrite: '<S4>/Data Store Write6' */
          G431Hallcorrection_DW.GlobalHallState = rtb_Sum_n;

          /* DataStoreWrite: '<S159>/Data Store Write' incorporates:
           *  DataTypeConversion: '<S4>/Data Type Conversion1'
           *  MATLABSystem: '<S4>/Timer Capture'
           */
          G431Hallcorrection_DW.Timercntprev = (int16_T)rtb_Merge_i;

          /* DataStoreWrite: '<S4>/Data Store Write5' incorporates:
           *  Constant: '<S4>/Constant2'
           */
          G431Hallcorrection_DW.HallAcapture =
            G431Hallcorrection_P.Constant2_Value_p;
          G431Hallcorrection_DW.HALL_C_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S185>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((G431Hallcorrection_M->Timing.clockTick5) * 0.001);
      extmodeEvent(5,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void G431Hallcorrection_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
  MW_NVIC_DisableIRQ(44);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
