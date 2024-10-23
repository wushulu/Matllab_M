/*
 * File: HallcorrectionFimal.c
 *
 * Code generated for Simulink model 'HallcorrectionFimal'.
 *
 * Model version                  : 1.7
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Oct 18 17:25:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "HallcorrectionFimal.h"
#include "rtwtypes.h"
#include "HallcorrectionFimal_types.h"
#include "HallcorrectionFimal_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "arm_math.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_HallcorrectionFimal_T HallcorrectionFimal_B;

/* Block states (default storage) */
DW_HallcorrectionFimal_T HallcorrectionFimal_DW;

/* Real-time model */
static RT_MODEL_HallcorrectionFimal_T HallcorrectionFimal_M_;
RT_MODEL_HallcorrectionFimal_T *const HallcorrectionFimal_M =
  &HallcorrectionFimal_M_;

/* Forward declaration for local functions */
static void Hallcorrection_SystemCore_setup(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallcorrecti_SystemCore_setup_i(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallcorrecti_SystemCore_setup_d(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallcorrecti_SystemCore_setup_g(stm32cube_blocks_AnalogInput__T *obj);
static void Hallcorrect_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ha_T *obj);

/* Forward declaration for local functions */
static void Hallcorre_PWMOutput_setupImpl_i(stm32cube_blocks_PWMOutput_Ha_T *obj);
static void rate_scheduler(void);

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (HallcorrectionFimal_M->Timing.TaskCounters.TID[1])++;
  if ((HallcorrectionFimal_M->Timing.TaskCounters.TID[1]) > 4) {/* Sample time: [0.01s, 0.0s] */
    HallcorrectionFimal_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S150>/If Action Subsystem6'
 *    '<S150>/If Action Subsystem7'
 *    '<S125>/If Action Subsystem6'
 *    '<S125>/If Action Subsystem7'
 *    '<S100>/If Action Subsystem6'
 *    '<S100>/If Action Subsystem7'
 */
void Hallcorrecti_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_Hallcorr_T *localP)
{
  /* SignalConversion generated from: '<S157>/direction' incorporates:
   *  Constant: '<S157>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S157>/sequence_check' incorporates:
   *  Constant: '<S157>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S150>/If Action Subsystem'
 *    '<S150>/If Action Subsystem1'
 *    '<S150>/If Action Subsystem2'
 *    '<S150>/If Action Subsystem3'
 *    '<S150>/If Action Subsystem4'
 *    '<S150>/If Action Subsystem5'
 *    '<S125>/If Action Subsystem'
 *    '<S125>/If Action Subsystem1'
 *    '<S125>/If Action Subsystem2'
 *    '<S125>/If Action Subsystem3'
 *    ...
 */
void Hallcorrectio_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_Hallcorre_T *localP)
{
  /* SignalConversion generated from: '<S151>/Out1' incorporates:
   *  Constant: '<S151>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S151>/Out2' incorporates:
   *  Constant: '<S151>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S148>/Valid Halls'
 *    '<S123>/Valid Halls'
 *    '<S98>/Valid Halls'
 */
void HallcorrectionF_ValidHalls_Init(B_ValidHalls_HallcorrectionFi_T *localB,
  P_ValidHalls_HallcorrectionFi_T *localP)
{
  /* SystemInitialize for Merge: '<S150>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S150>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S150>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S150>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S148>/Valid Halls'
 *    '<S123>/Valid Halls'
 *    '<S98>/Valid Halls'
 */
void HallcorrectionFimal_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, B_ValidHalls_HallcorrectionFi_T *localB,
  DW_ValidHalls_HallcorrectionF_T *localDW, P_ValidHalls_HallcorrectionFi_T
  *localP)
{
  /* SwitchCase: '<S150>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    Hallcorrectio_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    Hallcorrectio_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S153>/Action Port'
     */
    Hallcorrectio_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    Hallcorrectio_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    Hallcorrectio_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    Hallcorrectio_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem5' */
    break;

   default:
    /* Update for IfAction SubSystem: '<S150>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S160>/Action Port'
     */
    /* Update for SwitchCase: '<S150>/Switch Case' */
    localDW->SwitchCaseActionSubsystem_Subsy = 4;

    /* End of Update for SubSystem: '<S150>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S150>/Switch Case' */

  /* If: '<S150>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S157>/Action Port'
     */
    Hallcorrecti_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */
    Hallcorrecti_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S150>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S159>/Action Port'
     */
    /* Merge: '<S150>/Merge3' incorporates:
     *  Constant: '<S159>/Constant'
     *  SignalConversion generated from: '<S159>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S150>/If Action Subsystem8' */

    /* Update for IfAction SubSystem: '<S150>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S159>/Action Port'
     */
    /* Update for If: '<S150>/If' */
    localDW->IfActionSubsystem8_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S150>/If Action Subsystem8' */
  }

  /* End of If: '<S150>/If' */

  /* SignalConversion: '<S150>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S150>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S150>/Switch' incorporates:
   *  Constant: '<S150>/Constant'
   *  RelationalOperator: '<S150>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_b;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S150>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S148>/Bad hall (glitch or wrong connection)'
 *    '<S123>/Bad hall (glitch or wrong connection)'
 *    '<S98>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnection(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S149>/inValidHall' incorporates:
   *  Constant: '<S149>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S149>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S149>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S149>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

static void Hallcorrection_SystemCore_setup(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S147>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S147>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S147>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Hallcorrecti_SystemCore_setup_i(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S122>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S122>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S122>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Hallcorrecti_SystemCore_setup_d(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S97>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S97>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S97>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
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
void HallcorrectionFima_HallValueof1(real32_T *rty_position,
  P_HallValueof1_Hallcorrection_T *localP)
{
  /* SignalConversion generated from: '<S57>/position' incorporates:
   *  Constant: '<S57>/Constant'
   */
  *rty_position = localP->Constant_Value;
}

static void Hallcorrecti_SystemCore_setup_g(stm32cube_blocks_AnalogInput__T *obj)
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

static void Hallcorrect_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ha_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S87>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S87>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S87>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void Hallcorre_PWMOutput_setupImpl_i(stm32cube_blocks_PWMOutput_Ha_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S176>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S176>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S176>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/* Model step function */
void HallcorrectionFimal_step(void)
{
  /* RateTransition: '<Root>/RT2' */
  HallcorrectionFimal_B.Pos = HallcorrectionFimal_B.Sum;

  /* RateTransition: '<Root>/RT3' */
  if (HallcorrectionFimal_M->Timing.TaskCounters.TID[1] == 0) {
    /* RateTransition: '<Root>/RT3' */
    HallcorrectionFimal_B.testct = HallcorrectionFimal_B.Output;

    /* RateTransition: '<Root>/Rate Transition1' */
    HallcorrectionFimal_B.Pos_offset = HallcorrectionFimal_B.Add1_d;
  }

  /* End of RateTransition: '<Root>/RT3' */

  /* RateTransition: '<Root>/Rate Transition2' */
  HallcorrectionFimal_B.W = HallcorrectionFimal_B.Gain1;

  /* RateTransition: '<Root>/Rate Transition3' */
  HallcorrectionFimal_B.Halls = HallcorrectionFimal_B.DataStoreRead1;

  {                                    /* Sample time: [0.002s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      HallcorrectionFimal_M->Timing.taskTime0;

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (HallcorrectionFimal_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [0.01s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
      ((HallcorrectionFimal_M->Timing.clockTick1) * 0.01);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1,currentTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  HallcorrectionFimal_M->Timing.taskTime0 =
    ((time_T)(++HallcorrectionFimal_M->Timing.clockTick0)) *
    HallcorrectionFimal_M->Timing.stepSize0;
  if (HallcorrectionFimal_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.01, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    HallcorrectionFimal_M->Timing.clockTick1++;
  }

  rate_scheduler();
}

/* Model initialize function */
void HallcorrectionFimal_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(HallcorrectionFimal_M, -1);
  HallcorrectionFimal_M->Timing.stepSize0 = 0.002;

  /* External mode info */
  HallcorrectionFimal_M->Sizes.checksums[0] = (3415376752U);
  HallcorrectionFimal_M->Sizes.checksums[1] = (2329935925U);
  HallcorrectionFimal_M->Sizes.checksums[2] = (525075195U);
  HallcorrectionFimal_M->Sizes.checksums[3] = (2241589761U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[115];
    HallcorrectionFimal_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[3] = (sysRanDType *)
      &HallcorrectionFimal_DW.Subsystem_SubsysRanBC_g;
    systemRan[4] = (sysRanDType *)
      &HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC_o;
    systemRan[5] = (sysRanDType *)
      &HallcorrectionFimal_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &HallcorrectionFimal_DW.Subsystem_SubsysRanBC_p;
    systemRan[7] = (sysRanDType *)&HallcorrectionFimal_DW.Accumulate_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&HallcorrectionFimal_DW.UpCounter_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&HallcorrectionFimal_DW.PosGen_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof1_l.HallValueof1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof2_b.HallValueof1_SubsysRanBC;
    systemRan[12] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof3_e.HallValueof1_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof4_j.HallValueof1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof5_l.HallValueof1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof6_b.HallValueof1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof7_b.HallValueof1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &HallcorrectionFimal_DW.SpeedanddirectionarenotvalidPos;
    systemRan[18] = (sysRanDType *)
      &HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC_k;
    systemRan[19] = (sysRanDType *)
      &HallcorrectionFimal_DW.IfActionSubsystem1_SubsysRanB_k;
    systemRan[20] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof1_j.HallValueof1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof2_j.HallValueof1_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof3_h.HallValueof1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof4_b.HallValueof1_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof5_b.HallValueof1_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof6_n.HallValueof1_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof7_e.HallValueof1_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &HallcorrectionFimal_DW.veDirection_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof1.HallValueof1_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof2.HallValueof1_SubsysRanBC;
    systemRan[30] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof3.HallValueof1_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof4.HallValueof1_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof5.HallValueof1_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof6.HallValueof1_SubsysRanBC;
    systemRan[34] = (sysRanDType *)
      &HallcorrectionFimal_DW.HallValueof7.HallValueof1_SubsysRanBC;
    systemRan[35] = (sysRanDType *)
      &HallcorrectionFimal_DW.veDirection_SubsysRanBC_g;
    systemRan[36] = (sysRanDType *)
      &HallcorrectionFimal_DW.first_order_SubsysRanBC;
    systemRan[37] = (sysRanDType *)
      &HallcorrectionFimal_DW.second_order_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &HallcorrectionFimal_DW.Subsystem1_SubsysRanBC_e;
    systemRan[39] = (sysRanDType *)
      &HallcorrectionFimal_DW.SpeedanddirectionarevalidUsespe;
    systemRan[40] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[41] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[42] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[43] = (sysRanDType *)&HallcorrectionFimal_DW.Subsystem_SubsysRanBC;
    systemRan[44] = (sysRanDType *)&HallcorrectionFimal_DW.Subsystem_SubsysRanBC;
    systemRan[45] = (sysRanDType *)&HallcorrectionFimal_DW.Subsystem_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &HallcorrectionFimal_DW.FindOffset_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &HallcorrectionFimal_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[49] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[50] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[51] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[52] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[53] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[54] = (sysRanDType *)
      &HallcorrectionFimal_DW.Subsystem1_SubsysRanBC;
    systemRan[55] = (sysRanDType *)&HallcorrectionFimal_DW.ADCSIC_SubsysRanBC;
    systemRan[56] = (sysRanDType *)
      &HallcorrectionFimal_DW.Badhallglitchorwrongconnectio_o.Badhallglitchorwrongconnection_;
    systemRan[57] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[58] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[60] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[61] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[65] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.IfActionSubsystem8_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.SwitchCaseActionSubsystem_Subsy;
    systemRan[67] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[68] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[69] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_b.ValidHalls_SubsysRanBC;
    systemRan[70] = (sysRanDType *)&HallcorrectionFimal_DW.HA_SubsysRanBC;
    systemRan[71] = (sysRanDType *)&HallcorrectionFimal_DW.HA_SubsysRanBC;
    systemRan[72] = (sysRanDType *)&HallcorrectionFimal_DW.HA_SubsysRanBC;
    systemRan[73] = (sysRanDType *)&HallcorrectionFimal_DW.HA_SubsysRanBC;
    systemRan[74] = (sysRanDType *)&HallcorrectionFimal_DW.HA_SubsysRanBC;
    systemRan[75] = (sysRanDType *)
      &HallcorrectionFimal_DW.Badhallglitchorwrongconnectio_d.Badhallglitchorwrongconnection_;
    systemRan[76] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[77] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[78] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[79] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[80] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[81] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[82] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[83] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[84] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.IfActionSubsystem8_SubsysRanBC;
    systemRan[85] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.SwitchCaseActionSubsystem_Subsy;
    systemRan[86] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.ValidHalls_SubsysRanBC;
    systemRan[87] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.ValidHalls_SubsysRanBC;
    systemRan[88] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls_n.ValidHalls_SubsysRanBC;
    systemRan[89] = (sysRanDType *)&HallcorrectionFimal_DW.HB_SubsysRanBC;
    systemRan[90] = (sysRanDType *)&HallcorrectionFimal_DW.HB_SubsysRanBC;
    systemRan[91] = (sysRanDType *)&HallcorrectionFimal_DW.HB_SubsysRanBC;
    systemRan[92] = (sysRanDType *)&HallcorrectionFimal_DW.HB_SubsysRanBC;
    systemRan[93] = (sysRanDType *)&HallcorrectionFimal_DW.HB_SubsysRanBC;
    systemRan[94] = (sysRanDType *)
      &HallcorrectionFimal_DW.Badhallglitchorwrongconnectio_k.Badhallglitchorwrongconnection_;
    systemRan[95] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[96] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[97] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[98] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[99] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[100] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[101] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[102] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[103] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC;
    systemRan[104] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy;
    systemRan[105] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[106] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[107] = (sysRanDType *)
      &HallcorrectionFimal_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[108] = (sysRanDType *)&HallcorrectionFimal_DW.HC_SubsysRanBC;
    systemRan[109] = (sysRanDType *)&HallcorrectionFimal_DW.HC_SubsysRanBC;
    systemRan[110] = (sysRanDType *)&HallcorrectionFimal_DW.HC_SubsysRanBC;
    systemRan[111] = (sysRanDType *)&HallcorrectionFimal_DW.HC_SubsysRanBC;
    systemRan[112] = (sysRanDType *)&HallcorrectionFimal_DW.HC_SubsysRanBC;
    systemRan[113] = &rtAlwaysEnabled;
    systemRan[114] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(HallcorrectionFimal_M->extModeInfo,
      &HallcorrectionFimal_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(HallcorrectionFimal_M->extModeInfo,
                        HallcorrectionFimal_M->Sizes.checksums);
    rteiSetTPtr(HallcorrectionFimal_M->extModeInfo, rtmGetTPtr
                (HallcorrectionFimal_M));
  }

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  HallcorrectionFimal_DW.GlobalHallState =
    HallcorrectionFimal_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  HallcorrectionFimal_DW.Timercntprev =
    HallcorrectionFimal_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  HallcorrectionFimal_DW.HallCcapture =
    HallcorrectionFimal_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  HallcorrectionFimal_DW.Timehall =
    HallcorrectionFimal_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  HallcorrectionFimal_DW.GlobalDirection =
    HallcorrectionFimal_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  HallcorrectionFimal_DW.GlobalSpeedCount =
    HallcorrectionFimal_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  HallcorrectionFimal_DW.GlobalSpeedValidity =
    HallcorrectionFimal_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  HallcorrectionFimal_DW.HallStateChangeFlag =
    HallcorrectionFimal_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  HallcorrectionFimal_DW.HallBcapture =
    HallcorrectionFimal_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  HallcorrectionFimal_DW.HallAcapture =
    HallcorrectionFimal_P.DataStoreMemory2_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory9' */
  HallcorrectionFimal_DW.Enable =
    HallcorrectionFimal_P.DataStoreMemory9_InitialValue;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */

  /* System initialize for function-call system: '<Root>/ADC SIC' */
  HallcorrectionFimal_M->Timing.clockTick5 =
    HallcorrectionFimal_M->Timing.clockTick0;

  /* InitializeConditions for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  HallcorrectionFimal_DW.DiscreteTimeIntegrator_DSTATE =
    HallcorrectionFimal_P.DiscreteTimeIntegrator_IC;
  HallcorrectionFimal_DW.DiscreteTimeIntegrator_PrevRese = 2;

  /* InitializeConditions for Delay: '<S29>/validityDelay' */
  HallcorrectionFimal_DW.validityDelay_DSTATE =
    HallcorrectionFimal_P.validityDelay_InitialCondition;

  /* InitializeConditions for RelationalOperator: '<S34>/Compare' incorporates:
   *  Delay: '<S30>/Delay One Step1'
   */
  HallcorrectionFimal_DW.DelayOneStep1_DSTATE =
    HallcorrectionFimal_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Delay: '<S30>/Delay One Step' */
  HallcorrectionFimal_DW.DelayOneStep_DSTATE =
    HallcorrectionFimal_P.SoftwareWatchdogTimer_maxCount;

  /* InitializeConditions for Delay: '<S29>/speedCountDelay' */
  HallcorrectionFimal_DW.speedCountDelay_DSTATE =
    HallcorrectionFimal_P.speedCountDelay_InitialConditio;

  /* InitializeConditions for UnitDelay: '<S9>/Output' */
  HallcorrectionFimal_DW.Output_DSTATE =
    HallcorrectionFimal_P.Output_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' */
  /* SystemInitialize for Enabled SubSystem: '<S32>/Subsystem1' */
  /* SystemInitialize for Merge: '<S45>/Merge' */
  HallcorrectionFimal_B.Merge = HallcorrectionFimal_P.Merge_InitialOutput;

  /* End of SystemInitialize for SubSystem: '<S32>/Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' */

  /* SystemInitialize for Enabled SubSystem: '<S10>/PosGen' */
  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
  HallcorrectionFimal_DW.UnitDelay_DSTATE_k =
    HallcorrectionFimal_P.UnitDelay_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S21>/If Action Subsystem2' */
  /* InitializeConditions for Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' incorporates:
   *  Delay: '<S24>/Delay'
   */
  HallcorrectionFimal_DW.Delay_DSTATE_a =
    HallcorrectionFimal_P.Delay_InitialCondition;

  /* End of SystemInitialize for SubSystem: '<S21>/If Action Subsystem2' */

  /* SystemInitialize for Enabled SubSystem: '<S25>/Accumulate' */
  /* InitializeConditions for Delay: '<S26>/Delay' */
  HallcorrectionFimal_DW.Delay_DSTATE_h =
    HallcorrectionFimal_P.Delay_InitialCondition_k;

  /* SystemInitialize for Enabled SubSystem: '<S26>/Subsystem' */
  /* SystemInitialize for SignalConversion generated from: '<S27>/Input' incorporates:
   *  Outport: '<S27>/Out1'
   */
  HallcorrectionFimal_B.Input = HallcorrectionFimal_P.Out1_Y0_b;

  /* End of SystemInitialize for SubSystem: '<S26>/Subsystem' */

  /* SystemInitialize for Sum: '<S26>/Add1' incorporates:
   *  Outport: '<S26>/theta_e'
   */
  HallcorrectionFimal_B.Add1_l = HallcorrectionFimal_P.theta_e_Y0;

  /* End of SystemInitialize for SubSystem: '<S25>/Accumulate' */

  /* SystemInitialize for Enabled SubSystem: '<S16>/Up Counter' */
  /* InitializeConditions for Delay: '<S22>/Delay' */
  HallcorrectionFimal_DW.Delay_DSTATE_k =
    HallcorrectionFimal_P.Delay_InitialCondition_a;

  /* SystemInitialize for Sum: '<S22>/Add1' incorporates:
   *  Outport: '<S22>/Count'
   */
  HallcorrectionFimal_B.Add1 = HallcorrectionFimal_P.Count_Y0;

  /* End of SystemInitialize for SubSystem: '<S16>/Up Counter' */

  /* SystemInitialize for Gain: '<S25>/scaleOut' incorporates:
   *  Outport: '<S16>/Theta'
   */
  HallcorrectionFimal_B.scaleOut = HallcorrectionFimal_P.Theta_Y0;

  /* SystemInitialize for SignalConversion generated from: '<S16>/Enable' incorporates:
   *  Outport: '<S16>/EnPWM'
   */
  HallcorrectionFimal_B.Enable = HallcorrectionFimal_P.EnPWM_Y0;

  /* End of SystemInitialize for SubSystem: '<S10>/PosGen' */

  /* SystemInitialize for Enabled SubSystem: '<S11>/Find Offset' */
  /* InitializeConditions for Delay: '<S64>/Delay' */
  HallcorrectionFimal_DW.Delay_DSTATE =
    HallcorrectionFimal_P.Delay_InitialCondition_b;

  /* SystemInitialize for Enabled SubSystem: '<S64>/Subsystem' */
  /* InitializeConditions for UnitDelay: '<S74>/Unit Delay' */
  HallcorrectionFimal_DW.UnitDelay_DSTATE =
    HallcorrectionFimal_P.UnitDelay_InitialCondition_c;

  /* SystemInitialize for Sum: '<S74>/Add1' incorporates:
   *  Outport: '<S70>/Offset'
   */
  HallcorrectionFimal_B.Add1_d = HallcorrectionFimal_P.Offset_Y0;

  /* End of SystemInitialize for SubSystem: '<S64>/Subsystem' */
  /* End of SystemInitialize for SubSystem: '<S11>/Find Offset' */

  /* Start for MATLABSystem: '<S13>/Analog to Digital Converter' */
  HallcorrectionFimal_DW.obj.isInitialized = 0;
  HallcorrectionFimal_DW.obj.matlabCodegenIsDeleted = false;
  Hallcorrecti_SystemCore_setup_g(&HallcorrectionFimal_DW.obj);

  /* Start for MATLABSystem: '<S87>/PWM Output' */
  HallcorrectionFimal_DW.obj_f.matlabCodegenIsDeleted = false;
  HallcorrectionFimal_DW.obj_f.isSetupComplete = false;
  HallcorrectionFimal_DW.obj_f.isInitialized = 1;
  Hallcorrect_PWMOutput_setupImpl(&HallcorrectionFimal_DW.obj_f);
  HallcorrectionFimal_DW.obj_f.isSetupComplete = true;

  /* SystemInitialize for UnitDelay: '<S9>/Output' incorporates:
   *  Outport: '<S1>/ct'
   */
  HallcorrectionFimal_B.Output = HallcorrectionFimal_P.ct_Y0;

  /* SystemInitialize for Sum: '<S17>/Sum' incorporates:
   *  Outport: '<S1>/Posdegree'
   */
  HallcorrectionFimal_B.Sum = HallcorrectionFimal_P.Posdegree_Y0;

  /* SystemInitialize for Gain: '<S17>/Gain1' incorporates:
   *  Outport: '<S1>/W'
   */
  HallcorrectionFimal_B.Gain1 = HallcorrectionFimal_P.W_Y0;

  /* SystemInitialize for DataStoreRead: '<S17>/Data Store Read1' incorporates:
   *  Outport: '<S1>/Halls'
   */
  HallcorrectionFimal_B.DataStoreRead1 = HallcorrectionFimal_P.Halls_Y0;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HC'
   */
  /* System initialize for function-call system: '<Root>/HC' */
  HallcorrectionFimal_M->Timing.clockTick2 =
    HallcorrectionFimal_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S147>/Delay' */
  HallcorrectionFimal_DW.Delay_DSTATE_c =
    HallcorrectionFimal_P.Delay_InitialCondition_h;

  /* SystemInitialize for IfAction SubSystem: '<S148>/Valid Halls' */
  HallcorrectionF_ValidHalls_Init(&HallcorrectionFimal_B.ValidHalls,
    &HallcorrectionFimal_P.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S148>/Valid Halls' */

  /* Start for MATLABSystem: '<S147>/Timer' */
  HallcorrectionFimal_DW.obj_i.isInitialized = 0;
  HallcorrectionFimal_DW.obj_i.matlabCodegenIsDeleted = false;
  Hallcorrection_SystemCore_setup(&HallcorrectionFimal_DW.obj_i);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HB'
   */
  /* System initialize for function-call system: '<Root>/HB' */
  HallcorrectionFimal_M->Timing.clockTick3 =
    HallcorrectionFimal_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S122>/Delay' */
  HallcorrectionFimal_DW.Delay_DSTATE_m =
    HallcorrectionFimal_P.Delay_InitialCondition_f;

  /* SystemInitialize for IfAction SubSystem: '<S123>/Valid Halls' */
  HallcorrectionF_ValidHalls_Init(&HallcorrectionFimal_B.ValidHalls_n,
    &HallcorrectionFimal_P.ValidHalls_n);

  /* End of SystemInitialize for SubSystem: '<S123>/Valid Halls' */

  /* Start for MATLABSystem: '<S122>/Timer' */
  HallcorrectionFimal_DW.obj_a.isInitialized = 0;
  HallcorrectionFimal_DW.obj_a.matlabCodegenIsDeleted = false;
  Hallcorrecti_SystemCore_setup_i(&HallcorrectionFimal_DW.obj_a);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HA'
   */

  /* System initialize for function-call system: '<Root>/HA' */
  HallcorrectionFimal_M->Timing.clockTick4 =
    HallcorrectionFimal_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S97>/Delay' */
  HallcorrectionFimal_DW.Delay_DSTATE_i =
    HallcorrectionFimal_P.Delay_InitialCondition_i;

  /* SystemInitialize for IfAction SubSystem: '<S98>/Valid Halls' */
  HallcorrectionF_ValidHalls_Init(&HallcorrectionFimal_B.ValidHalls_b,
    &HallcorrectionFimal_P.ValidHalls_b);

  /* End of SystemInitialize for SubSystem: '<S98>/Valid Halls' */

  /* Start for MATLABSystem: '<S97>/Timer' */
  HallcorrectionFimal_DW.obj_ff.isInitialized = 0;
  HallcorrectionFimal_DW.obj_ff.matlabCodegenIsDeleted = false;
  Hallcorrecti_SystemCore_setup_d(&HallcorrectionFimal_DW.obj_ff);

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Parameters' */
  /* Start for MATLABSystem: '<S176>/PWM Output' */
  HallcorrectionFimal_DW.obj_o.matlabCodegenIsDeleted = false;
  HallcorrectionFimal_DW.obj_o.isSetupComplete = false;
  HallcorrectionFimal_DW.obj_o.isInitialized = 1;
  Hallcorre_PWMOutput_setupImpl_i(&HallcorrectionFimal_DW.obj_o);
  HallcorrectionFimal_DW.obj_o.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Parameters' */

  /* Outputs for Atomic SubSystem: '<Root>/Parameters' */
  /* MATLABSystem: '<S176>/PWM Output' incorporates:
   *  Constant: '<S7>/Constant1'
   */
  setDutyCycleInPercentageChannel1(HallcorrectionFimal_DW.obj_o.TimerHandle,
    HallcorrectionFimal_P.Constant1_Value_o);
  setDutyCycleInPercentageChannel2(HallcorrectionFimal_DW.obj_o.TimerHandle,
    HallcorrectionFimal_P.Constant1_Value_o);
  setDutyCycleInPercentageChannel3(HallcorrectionFimal_DW.obj_o.TimerHandle,
    HallcorrectionFimal_P.Constant1_Value_o);

  /* End of Outputs for SubSystem: '<Root>/Parameters' */

  /* Enable for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */

  /* Enable for function-call system: '<Root>/ADC SIC' */
  HallcorrectionFimal_M->Timing.clockTick5 =
    HallcorrectionFimal_M->Timing.clockTick0;
  HallcorrectionFimal_DW.ADCSIC_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
  HallcorrectionFimal_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;

  /* End of Enable for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */
}

/* Model terminate function */
void HallcorrectionFimal_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */
  /* Termination for function-call system: '<Root>/ADC SIC' */

  /* Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */
  if (!HallcorrectionFimal_DW.obj.matlabCodegenIsDeleted) {
    HallcorrectionFimal_DW.obj.matlabCodegenIsDeleted = true;
    if ((HallcorrectionFimal_DW.obj.isInitialized == 1) &&
        HallcorrectionFimal_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(HallcorrectionFimal_DW.obj.ADCHandle, ADC_INTERRUPT_MODE,
                        0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S87>/PWM Output' */
  if (!HallcorrectionFimal_DW.obj_f.matlabCodegenIsDeleted) {
    HallcorrectionFimal_DW.obj_f.matlabCodegenIsDeleted = true;
    if ((HallcorrectionFimal_DW.obj_f.isInitialized == 1) &&
        HallcorrectionFimal_DW.obj_f.isSetupComplete) {
      disableCounter(HallcorrectionFimal_DW.obj_f.TimerHandle);
      disableTimerInterrupts(HallcorrectionFimal_DW.obj_f.TimerHandle, 0);
      disableTimerChannel1(HallcorrectionFimal_DW.obj_f.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(HallcorrectionFimal_DW.obj_f.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(HallcorrectionFimal_DW.obj_f.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S87>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HC'
   */
  /* Termination for function-call system: '<Root>/HC' */

  /* Terminate for MATLABSystem: '<S147>/Timer' */
  if (!HallcorrectionFimal_DW.obj_i.matlabCodegenIsDeleted) {
    HallcorrectionFimal_DW.obj_i.matlabCodegenIsDeleted = true;
    if ((HallcorrectionFimal_DW.obj_i.isInitialized == 1) &&
        HallcorrectionFimal_DW.obj_i.isSetupComplete) {
      disableCounter(HallcorrectionFimal_DW.obj_i.TimerHandle);
      disableTimerInterrupts(HallcorrectionFimal_DW.obj_i.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S147>/Timer' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HB'
   */
  /* Termination for function-call system: '<Root>/HB' */

  /* Terminate for MATLABSystem: '<S122>/Timer' */
  if (!HallcorrectionFimal_DW.obj_a.matlabCodegenIsDeleted) {
    HallcorrectionFimal_DW.obj_a.matlabCodegenIsDeleted = true;
    if ((HallcorrectionFimal_DW.obj_a.isInitialized == 1) &&
        HallcorrectionFimal_DW.obj_a.isSetupComplete) {
      disableCounter(HallcorrectionFimal_DW.obj_a.TimerHandle);
      disableTimerInterrupts(HallcorrectionFimal_DW.obj_a.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S122>/Timer' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HA'
   */
  /* Termination for function-call system: '<Root>/HA' */

  /* Terminate for MATLABSystem: '<S97>/Timer' */
  if (!HallcorrectionFimal_DW.obj_ff.matlabCodegenIsDeleted) {
    HallcorrectionFimal_DW.obj_ff.matlabCodegenIsDeleted = true;
    if ((HallcorrectionFimal_DW.obj_ff.isInitialized == 1) &&
        HallcorrectionFimal_DW.obj_ff.isSetupComplete) {
      disableCounter(HallcorrectionFimal_DW.obj_ff.TimerHandle);
      disableTimerInterrupts(HallcorrectionFimal_DW.obj_ff.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S97>/Timer' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

  /* Terminate for Atomic SubSystem: '<Root>/Parameters' */
  /* Terminate for MATLABSystem: '<S176>/PWM Output' */
  if (!HallcorrectionFimal_DW.obj_o.matlabCodegenIsDeleted) {
    HallcorrectionFimal_DW.obj_o.matlabCodegenIsDeleted = true;
    if ((HallcorrectionFimal_DW.obj_o.isInitialized == 1) &&
        HallcorrectionFimal_DW.obj_o.isSetupComplete) {
      disableCounter(HallcorrectionFimal_DW.obj_o.TimerHandle);
      disableTimerInterrupts(HallcorrectionFimal_DW.obj_o.TimerHandle, 0);
      disableTimerChannel1(HallcorrectionFimal_DW.obj_o.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(HallcorrectionFimal_DW.obj_o.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(HallcorrectionFimal_DW.obj_o.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S176>/PWM Output' */
  /* End of Terminate for SubSystem: '<Root>/Parameters' */
}

void HallcorrectionFimal_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(38,&EXTI9_5_IRQHandler,2);
  MW_NVIC_EnableIRQ(38);
}

/* Hardware Interrupt Block: '<S171>/Hardware Interrupt' */
void EXTI9_5_IRQHandler(void)
{
  uint32_T priority_mask;
  priority_mask = MW_HWI_MaskInterrupt();

  /* Event: EXTI8 Event */
  /* Check event EXTI8 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_8)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_8)))) {
    /* Clear occurred EXTI8 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_8);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC
          (HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (HallcorrectionFimal_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (HallcorrectionFimal_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.ValidHalls.ValidHalls_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (HallcorrectionFimal_DW.Badhallglitchorwrongconnectio_k.Badhallglitchorwrongconnection_);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.HC_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HC' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;
          HallcorrectionFimal_M->Timing.clockTick2 =
            HallcorrectionFimal_M->Timing.clockTick0;

          /* MATLABSystem: '<S147>/Timer' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           */
          HallcorrectionFimal_DW.Timercntprev = getTimerCounterValue
            (HallcorrectionFimal_DW.obj_i.TimerHandle);

          /* MATLABSystem: '<S165>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S167>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S169>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S146>/Sum' incorporates:
           *  Gain: '<S146>/Gain'
           *  Gain: '<S146>/Gain1'
           *  Gain: '<S146>/Gain2'
           *  MATLABSystem: '<S165>/Digital Port Read'
           *  MATLABSystem: '<S167>/Digital Port Read'
           *  MATLABSystem: '<S169>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 256U) != 0U ?
            HallcorrectionFimal_P.Gain_Gain_bp >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? HallcorrectionFimal_P.Gain1_Gain_o >>
             6 : 0)) + (uint32_T)((pinReadLoc_e & 32U) != 0U ?
            HallcorrectionFimal_P.Gain2_Gain >> 7 : 0));

          /* SwitchCase: '<S145>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S145>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S148>/Valid Halls' incorporates:
             *  ActionPort: '<S150>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S145>/Data Type Conversion2'
             */
            HallcorrectionFimal_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              HallcorrectionFimal_DW.GlobalHallState,
              HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge3,
              &HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge,
              &HallcorrectionFimal_B.ValidHalls,
              &HallcorrectionFimal_DW.ValidHalls,
              &HallcorrectionFimal_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S148>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S148>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S149>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge,
               &HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge3,
               &HallcorrectionFimal_P.Badhallglitchorwrongconnectio_k);

            /* End of Outputs for SubSystem: '<S148>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S145>/Detects if the halls reading is valid' */

          /* Gain: '<S4>/Gain' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  DataTypeConversion: '<S147>/Data Type Conversion'
           *  DataTypeConversion: '<S147>/Data Type Conversion1'
           *  Delay: '<S147>/Delay'
           *  Sum: '<S147>/Sum'
           */
          HallcorrectionFimal_DW.Timehall = (int64_T)((int32_T)
            HallcorrectionFimal_DW.Timercntprev - (int32_T)
            HallcorrectionFimal_DW.Delay_DSTATE_c) *
            HallcorrectionFimal_P.Gain_Gain;

          /* DataTypeConversion: '<S145>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  Gain: '<S4>/Gain'
           */
          HallcorrectionFimal_DW.GlobalSpeedCount = (uint32_T)
            (HallcorrectionFimal_DW.Timehall >> 30);

          /* DataTypeConversion: '<S148>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          HallcorrectionFimal_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S145>/Constant'
           */
          HallcorrectionFimal_DW.HallStateChangeFlag =
            HallcorrectionFimal_P.Constant_Value_ds;

          /* DataStoreWrite: '<S4>/Data Store Write6' */
          HallcorrectionFimal_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S4>/Data Store Write5' incorporates:
           *  Constant: '<S4>/Constant1'
           */
          HallcorrectionFimal_DW.HallCcapture =
            HallcorrectionFimal_P.Constant1_Value;

          /* Update for Delay: '<S147>/Delay' incorporates:
           *  DataStoreRead: '<S147>/Data Store Read1'
           */
          HallcorrectionFimal_DW.Delay_DSTATE_c =
            HallcorrectionFimal_DW.Timercntprev;
          HallcorrectionFimal_DW.HC_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((HallcorrectionFimal_M->Timing.clockTick2) * 0.002);
      extmodeEvent(2,currentTime);
    }
  }

  /* Event: EXTI6 Event */
  /* Check event EXTI6 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_6)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_6)))) {
    /* Clear occurred EXTI6 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_6);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.HB_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HB' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;
          HallcorrectionFimal_M->Timing.clockTick3 =
            HallcorrectionFimal_M->Timing.clockTick0;

          /* MATLABSystem: '<S122>/Timer' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           */
          HallcorrectionFimal_DW.Timercntprev = getTimerCounterValue
            (HallcorrectionFimal_DW.obj_a.TimerHandle);

          /* MATLABSystem: '<S140>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S142>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S144>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S121>/Sum' incorporates:
           *  Gain: '<S121>/Gain'
           *  Gain: '<S121>/Gain1'
           *  Gain: '<S121>/Gain2'
           *  MATLABSystem: '<S140>/Digital Port Read'
           *  MATLABSystem: '<S142>/Digital Port Read'
           *  MATLABSystem: '<S144>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 256U) != 0U ?
            HallcorrectionFimal_P.Gain_Gain_px >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? HallcorrectionFimal_P.Gain1_Gain_l >>
             6 : 0)) + (uint32_T)((pinReadLoc_e & 32U) != 0U ?
            HallcorrectionFimal_P.Gain2_Gain_p >> 7 : 0));

          /* SwitchCase: '<S120>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S120>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S123>/Valid Halls' incorporates:
             *  ActionPort: '<S125>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S120>/Data Type Conversion2'
             */
            HallcorrectionFimal_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              HallcorrectionFimal_DW.GlobalHallState,
              HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge3,
              &HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge,
              &HallcorrectionFimal_B.ValidHalls_n,
              &HallcorrectionFimal_DW.ValidHalls_n,
              &HallcorrectionFimal_P.ValidHalls_n);

            /* End of Outputs for SubSystem: '<S123>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S123>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S124>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge,
               &HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge3,
               &HallcorrectionFimal_P.Badhallglitchorwrongconnectio_d);

            /* End of Outputs for SubSystem: '<S123>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S120>/Detects if the halls reading is valid' */

          /* Gain: '<S3>/Gain' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  DataTypeConversion: '<S122>/Data Type Conversion'
           *  DataTypeConversion: '<S122>/Data Type Conversion1'
           *  Delay: '<S122>/Delay'
           *  Sum: '<S122>/Sum'
           */
          HallcorrectionFimal_DW.Timehall = (int64_T)((int32_T)
            HallcorrectionFimal_DW.Timercntprev - (int32_T)
            HallcorrectionFimal_DW.Delay_DSTATE_m) *
            HallcorrectionFimal_P.Gain_Gain_f;

          /* DataTypeConversion: '<S120>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  Gain: '<S3>/Gain'
           */
          HallcorrectionFimal_DW.GlobalSpeedCount = (uint32_T)
            (HallcorrectionFimal_DW.Timehall >> 30);

          /* DataTypeConversion: '<S123>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          HallcorrectionFimal_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S120>/Constant'
           */
          HallcorrectionFimal_DW.HallStateChangeFlag =
            HallcorrectionFimal_P.Constant_Value_o;

          /* DataStoreWrite: '<S3>/Data Store Write6' */
          HallcorrectionFimal_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S3>/Data Store Write5' incorporates:
           *  Constant: '<S3>/Constant1'
           */
          HallcorrectionFimal_DW.HallBcapture =
            HallcorrectionFimal_P.Constant1_Value_c;

          /* Update for Delay: '<S122>/Delay' incorporates:
           *  DataStoreRead: '<S122>/Data Store Read1'
           */
          HallcorrectionFimal_DW.Delay_DSTATE_m =
            HallcorrectionFimal_DW.Timercntprev;
          HallcorrectionFimal_DW.HB_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((HallcorrectionFimal_M->Timing.clockTick3) * 0.002);
      extmodeEvent(3,currentTime);
    }
  }

  /* Event: EXTI5 Event */
  /* Check event EXTI5 Event occurred */
  if (0 != ((0 != LL_EXTI_IsEnabledIT_0_31(LL_EXTI_LINE_5)) && (0 !=
        LL_EXTI_IsActiveFlag_0_31(LL_EXTI_LINE_5)))) {
    /* Clear occurred EXTI5 Event event */
    LL_EXTI_ClearFlag_0_31(LL_EXTI_LINE_5);
    if (1 == runModel) {
      {
        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.HA_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HA' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;
          HallcorrectionFimal_M->Timing.clockTick4 =
            HallcorrectionFimal_M->Timing.clockTick0;

          /* MATLABSystem: '<S97>/Timer' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           */
          HallcorrectionFimal_DW.Timercntprev = getTimerCounterValue
            (HallcorrectionFimal_DW.obj_ff.TimerHandle);

          /* MATLABSystem: '<S115>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S117>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S119>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S96>/Sum' incorporates:
           *  Gain: '<S96>/Gain'
           *  Gain: '<S96>/Gain1'
           *  Gain: '<S96>/Gain2'
           *  MATLABSystem: '<S115>/Digital Port Read'
           *  MATLABSystem: '<S117>/Digital Port Read'
           *  MATLABSystem: '<S119>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 256U) != 0U ?
            HallcorrectionFimal_P.Gain_Gain_g >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 64U) != 0U ? HallcorrectionFimal_P.Gain1_Gain_h >>
             6 : 0)) + (uint32_T)((pinReadLoc_e & 32U) != 0U ?
            HallcorrectionFimal_P.Gain2_Gain_j >> 7 : 0));

          /* SwitchCase: '<S95>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S95>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S98>/Valid Halls' incorporates:
             *  ActionPort: '<S100>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S95>/Data Type Conversion2'
             */
            HallcorrectionFimal_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              HallcorrectionFimal_DW.GlobalHallState,
              HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge3,
              &HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge,
              &HallcorrectionFimal_B.ValidHalls_b,
              &HallcorrectionFimal_DW.ValidHalls_b,
              &HallcorrectionFimal_P.ValidHalls_b);

            /* End of Outputs for SubSystem: '<S98>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S98>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S99>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge,
               &HallcorrectionFimal_DW.GlobalDirection, &rtb_Merge3,
               &HallcorrectionFimal_P.Badhallglitchorwrongconnectio_o);

            /* End of Outputs for SubSystem: '<S98>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S95>/Detects if the halls reading is valid' */

          /* Gain: '<S2>/Gain' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  DataTypeConversion: '<S97>/Data Type Conversion'
           *  DataTypeConversion: '<S97>/Data Type Conversion1'
           *  Delay: '<S97>/Delay'
           *  Sum: '<S97>/Sum'
           */
          HallcorrectionFimal_DW.Timehall = (int64_T)((int32_T)
            HallcorrectionFimal_DW.Timercntprev - (int32_T)
            HallcorrectionFimal_DW.Delay_DSTATE_i) *
            HallcorrectionFimal_P.Gain_Gain_p;

          /* DataTypeConversion: '<S95>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  Gain: '<S2>/Gain'
           */
          HallcorrectionFimal_DW.GlobalSpeedCount = (uint32_T)
            (HallcorrectionFimal_DW.Timehall >> 30);

          /* DataTypeConversion: '<S98>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          HallcorrectionFimal_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S95>/Constant'
           */
          HallcorrectionFimal_DW.HallStateChangeFlag =
            HallcorrectionFimal_P.Constant_Value_i;

          /* DataStoreWrite: '<S2>/Data Store Write6' */
          HallcorrectionFimal_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S2>/Data Store Write5' incorporates:
           *  Constant: '<S2>/Constant1'
           */
          HallcorrectionFimal_DW.HallAcapture =
            HallcorrectionFimal_P.Constant1_Value_n;

          /* Update for Delay: '<S97>/Delay' incorporates:
           *  DataStoreRead: '<S97>/Data Store Read1'
           */
          HallcorrectionFimal_DW.Delay_DSTATE_i =
            HallcorrectionFimal_DW.Timercntprev;
          HallcorrectionFimal_DW.HA_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S171>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((HallcorrectionFimal_M->Timing.clockTick4) * 0.002);
      extmodeEvent(4,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

/* Hardware Interrupt Block: '<S173>/Hardware Interrupt' */
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
        srClearBC(HallcorrectionFimal_DW.Subsystem_SubsysRanBC_g);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC_o);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.IfActionSubsystem2_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.Subsystem_SubsysRanBC_p);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.Accumulate_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.UpCounter_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.PosGen_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC_k);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.IfActionSubsystem1_SubsysRanB_k);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.HallValueof1.HallValueof1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.veDirection_SubsysRanBC_g);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.veDirection_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.second_order_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.first_order_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.Subsystem1_SubsysRanBC_e);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.SpeedanddirectionarevalidUsespe);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.SpeedanddirectionarenotvalidPos);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.Subsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.FindOffset_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.IfActionSubsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.Subsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(HallcorrectionFimal_DW.ADCSIC_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC SIC' */
        {
          real_T rtb_Switch4_idx_1;
          real_T rtb_Switch4_idx_2;
          uint64_T tmp_p;
          real32_T rtb_Add1_j;
          real32_T rtb_Merge1_m0;
          real32_T rtb_Product1_a;
          real32_T rtb_Product_h;
          uint32_T ADCSIC_ELAPS_T;
          uint32_T tmp_e;
          uint16_T tmp[3];
          uint16_T Switch;
          uint16_T rtb_DataStoreRead6;
          uint16_T rtb_Get_Integer;
          boolean_T OR;
          HallcorrectionFimal_M->Timing.clockTick5 =
            HallcorrectionFimal_M->Timing.clockTick0;
          if (HallcorrectionFimal_DW.ADCSIC_RESET_ELAPS_T) {
            ADCSIC_ELAPS_T = 0U;
          } else {
            ADCSIC_ELAPS_T = HallcorrectionFimal_M->Timing.clockTick5 -
              HallcorrectionFimal_DW.ADCSIC_PREV_T;
          }

          HallcorrectionFimal_DW.ADCSIC_PREV_T =
            HallcorrectionFimal_M->Timing.clockTick5;
          HallcorrectionFimal_DW.ADCSIC_RESET_ELAPS_T = false;

          /* DataStoreRead: '<S17>/Data Store Read6' */
          rtb_DataStoreRead6 = HallcorrectionFimal_DW.HallStateChangeFlag;

          /* Switch: '<S28>/Switch' incorporates:
           *  Constant: '<S28>/WatchDog'
           *  DataStoreRead: '<S17>/Data Store Read6'
           *  DataStoreWrite: '<S17>/Data Store Write3'
           */
          if (HallcorrectionFimal_DW.HallStateChangeFlag != 0) {
            HallcorrectionFimal_DW.HallStateChangeFlag =
              HallcorrectionFimal_P.WatchDog_Value;
          }

          /* End of Switch: '<S28>/Switch' */

          /* DataStoreRead: '<S17>/Data Store Read1' */
          HallcorrectionFimal_B.DataStoreRead1 =
            HallcorrectionFimal_DW.GlobalHallState;

          /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
          if (HallcorrectionFimal_DW.DiscreteTimeIntegrator_SYSTEM_E == 0) {
            if ((rtb_DataStoreRead6 > 0) &&
                (HallcorrectionFimal_DW.DiscreteTimeIntegrator_PrevRese <= 0)) {
              HallcorrectionFimal_DW.DiscreteTimeIntegrator_DSTATE =
                HallcorrectionFimal_P.DiscreteTimeIntegrator_IC;
            } else {
              /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
              HallcorrectionFimal_DW.DiscreteTimeIntegrator_DSTATE += (real32_T)
                (HallcorrectionFimal_P.DiscreteTimeIntegrator_gainval * (real_T)
                 ADCSIC_ELAPS_T
                 * HallcorrectionFimal_DW.DiscreteTimeIntegrator_PREV_U);
            }
          }

          if (HallcorrectionFimal_DW.DiscreteTimeIntegrator_DSTATE >
              HallcorrectionFimal_P.DiscreteTimeIntegrator_UpperSat) {
            /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
            HallcorrectionFimal_DW.DiscreteTimeIntegrator_DSTATE =
              HallcorrectionFimal_P.DiscreteTimeIntegrator_UpperSat;
          } else if (HallcorrectionFimal_DW.DiscreteTimeIntegrator_DSTATE <
                     HallcorrectionFimal_P.DiscreteTimeIntegrator_LowerSat) {
            /* DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
            HallcorrectionFimal_DW.DiscreteTimeIntegrator_DSTATE =
              HallcorrectionFimal_P.DiscreteTimeIntegrator_LowerSat;
          }

          /* End of DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */

          /* DataTypeConversion: '<S28>/counterSize1' incorporates:
           *  DataStoreRead: '<S17>/Data Store Read'
           *  DataStoreRead: '<S17>/Data Store Read2'
           *  DataStoreRead: '<S17>/Data Store Read7'
           *  MinMax: '<S17>/Min'
           */
          HallcorrectionFimal_B.rtb_Switch4_idx_0 = floor(fmin(fmin
            (HallcorrectionFimal_DW.HallAcapture,
             HallcorrectionFimal_DW.HallBcapture),
            HallcorrectionFimal_DW.HallCcapture));
          if (rtIsNaN(HallcorrectionFimal_B.rtb_Switch4_idx_0) || rtIsInf
              (HallcorrectionFimal_B.rtb_Switch4_idx_0)) {
            HallcorrectionFimal_B.rtb_Switch4_idx_0 = 0.0;
          } else {
            HallcorrectionFimal_B.rtb_Switch4_idx_0 = fmod
              (HallcorrectionFimal_B.rtb_Switch4_idx_0, 4.294967296E+9);
          }

          ADCSIC_ELAPS_T = HallcorrectionFimal_B.rtb_Switch4_idx_0 < 0.0 ?
            (uint32_T)-(int32_T)(uint32_T)
            -HallcorrectionFimal_B.rtb_Switch4_idx_0 : (uint32_T)
            HallcorrectionFimal_B.rtb_Switch4_idx_0;

          /* End of DataTypeConversion: '<S28>/counterSize1' */

          /* Switch: '<S29>/Switch' incorporates:
           *  Constant: '<S29>/Order'
           */
          if (HallcorrectionFimal_P.Order_Value >
              HallcorrectionFimal_P.Switch_Threshold_o) {
            /* Switch: '<S29>/Switch' */
            Switch = rtb_DataStoreRead6;
          } else {
            /* Switch: '<S29>/Switch' */
            Switch = HallcorrectionFimal_P.Order_Value;
          }

          /* End of Switch: '<S29>/Switch' */

          /* Delay: '<S29>/validityDelay' */
          if (Switch != 0) {
            /* Delay: '<S29>/validityDelay' */
            HallcorrectionFimal_B.validityDelay =
              HallcorrectionFimal_DW.validityDelay_DSTATE;
          }

          /* End of Delay: '<S29>/validityDelay' */

          /* Logic: '<S30>/OR' incorporates:
           *  DataTypeConversion: '<S28>/Data Type Conversion4'
           *  Delay: '<S30>/Delay One Step1'
           */
          OR = (HallcorrectionFimal_DW.DelayOneStep1_DSTATE ||
                (rtb_DataStoreRead6 != 0));

          /* Delay: '<S30>/Delay One Step' incorporates:
           *  DataTypeConversion: '<S28>/Data Type Conversion4'
           */
          if (OR) {
            if (rtb_DataStoreRead6 != 0) {
              HallcorrectionFimal_DW.DelayOneStep_DSTATE =
                HallcorrectionFimal_P.SoftwareWatchdogTimer_maxCount;
            }

            /* Delay: '<S30>/Delay One Step' incorporates:
             *  DataTypeConversion: '<S28>/Data Type Conversion4'
             */
            HallcorrectionFimal_B.DelayOneStep =
              HallcorrectionFimal_DW.DelayOneStep_DSTATE;
          }

          /* End of Delay: '<S30>/Delay One Step' */

          /* RelationalOperator: '<S34>/Compare' incorporates:
           *  Constant: '<S34>/Constant'
           */
          HallcorrectionFimal_DW.DelayOneStep1_DSTATE =
            (HallcorrectionFimal_B.DelayOneStep >
             HallcorrectionFimal_P.Constant_Value_cz);

          /* Switch: '<S33>/watchdog check' incorporates:
           *  Constant: '<S33>/Constant'
           */
          if (HallcorrectionFimal_DW.DelayOneStep1_DSTATE) {
            /* MinMax: '<S33>/Max' incorporates:
             *  DataStoreRead: '<S17>/Data Store Read3'
             */
            if (HallcorrectionFimal_DW.GlobalSpeedCount >= ADCSIC_ELAPS_T) {
              tmp_e = HallcorrectionFimal_DW.GlobalSpeedCount;
            } else {
              tmp_e = ADCSIC_ELAPS_T;
            }

            /* Switch: '<S33>/speed check' incorporates:
             *  Constant: '<S33>/Constant'
             *  DataStoreRead: '<S17>/Data Store Read5'
             *  DataTypeConversion: '<S29>/Data Type Conversion'
             *  Logic: '<S29>/Logical Operator'
             *  MinMax: '<S33>/Max'
             */
            if (tmp_e >= HallcorrectionFimal_P.speedcheck_Threshold) {
              rtb_Get_Integer = HallcorrectionFimal_P.Constant_Value_a;
            } else {
              rtb_Get_Integer = (uint16_T)
                ((HallcorrectionFimal_DW.GlobalSpeedValidity != 0) &&
                 HallcorrectionFimal_B.validityDelay);
            }

            /* End of Switch: '<S33>/speed check' */
          } else {
            rtb_Get_Integer = HallcorrectionFimal_P.Constant_Value_a;
          }

          /* End of Switch: '<S33>/watchdog check' */

          /* Delay: '<S29>/speedCountDelay' */
          if (Switch != 0) {
            /* Delay: '<S29>/speedCountDelay' */
            HallcorrectionFimal_B.speedCountDelay =
              HallcorrectionFimal_DW.speedCountDelay_DSTATE;
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
            if (HallcorrectionFimal_DW.GlobalDirection > 0) {
              /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem' incorporates:
               *  ActionPort: '<S43>/Action Port'
               */
              /* SignalConversion generated from: '<S43>/In1' incorporates:
               *  Constant: '<S32>/SpeedConst'
               *  DataStoreRead: '<S17>/Data Store Read3'
               *  DataTypeConversion: '<S32>/SpeedConstData'
               *  DataTypeConversion: '<S32>/currentSpeedData'
               *  Gain: '<S32>/SpeedGain'
               *  Product: '<S32>/Divide'
               */
              rtb_Product_h = (real32_T)HallcorrectionFimal_P.SpeedConst_Value /
                (real32_T)HallcorrectionFimal_DW.GlobalSpeedCount *
                HallcorrectionFimal_P.SpeedGain_Gain;

              /* End of Outputs for SubSystem: '<S32>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S32>/If Action Subsystem' incorporates:
               *  ActionPort: '<S43>/Action Port'
               */
              /* Update for If: '<S32>/If' */
              HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC_k = 4;

              /* End of Update for SubSystem: '<S32>/If Action Subsystem' */
            } else {
              /* Outputs for IfAction SubSystem: '<S32>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S44>/Action Port'
               */
              /* UnaryMinus: '<S44>/Unary Minus' incorporates:
               *  Constant: '<S32>/SpeedConst'
               *  DataStoreRead: '<S17>/Data Store Read3'
               *  DataTypeConversion: '<S32>/SpeedConstData'
               *  DataTypeConversion: '<S32>/currentSpeedData'
               *  Gain: '<S32>/SpeedGain'
               *  Product: '<S32>/Divide'
               */
              rtb_Product_h = -((real32_T)HallcorrectionFimal_P.SpeedConst_Value
                                / (real32_T)
                                HallcorrectionFimal_DW.GlobalSpeedCount *
                                HallcorrectionFimal_P.SpeedGain_Gain);

              /* End of Outputs for SubSystem: '<S32>/If Action Subsystem1' */

              /* Update for IfAction SubSystem: '<S32>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S44>/Action Port'
               */
              /* Update for If: '<S32>/If' */
              HallcorrectionFimal_DW.IfActionSubsystem1_SubsysRanB_k = 4;

              /* End of Update for SubSystem: '<S32>/If Action Subsystem1' */
            }

            /* End of If: '<S32>/If' */

            /* Outputs for Enabled SubSystem: '<S32>/Subsystem1' incorporates:
             *  EnablePort: '<S45>/Enable'
             */
            if (HallcorrectionFimal_P.PositionEnable_Value > 0) {
              /* If: '<S45>/If1' incorporates:
               *  Constant: '<S45>/Constant'
               */
              if (HallcorrectionFimal_P.Constant_Value_f > 1.0) {
                /* Outputs for IfAction SubSystem: '<S45>/second_order' incorporates:
                 *  ActionPort: '<S49>/Action Port'
                 */
                /* Product: '<S49>/Divide1' incorporates:
                 *  DataStoreRead: '<S17>/Data Store Read3'
                 *  DataTypeConversion: '<S49>/countData'
                 *  DataTypeConversion: '<S49>/currentSpeedData'
                 */
                rtb_Product1_a = (real32_T)ADCSIC_ELAPS_T / (real32_T)
                  HallcorrectionFimal_DW.GlobalSpeedCount;

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
                rtb_Product1_a = ((rtb_Product1_a - (real32_T)ADCSIC_ELAPS_T /
                                   (real32_T)
                                   HallcorrectionFimal_B.speedCountDelay) *
                                  HallcorrectionFimal_P.Gain1_Gain_i +
                                  HallcorrectionFimal_P.Constant_Value_d) *
                  rtb_Product1_a * HallcorrectionFimal_P.Gain_Gain_k;

                /* End of Outputs for SubSystem: '<S45>/second_order' */

                /* Update for IfAction SubSystem: '<S45>/second_order' incorporates:
                 *  ActionPort: '<S49>/Action Port'
                 */
                /* Update for If: '<S45>/If1' */
                HallcorrectionFimal_DW.second_order_SubsysRanBC = 4;

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
                rtb_Product1_a = (real32_T)ADCSIC_ELAPS_T / (real32_T)
                  HallcorrectionFimal_DW.GlobalSpeedCount *
                  HallcorrectionFimal_P.Gain_Gain_a;

                /* End of Outputs for SubSystem: '<S45>/first_order' */

                /* Update for IfAction SubSystem: '<S45>/first_order' incorporates:
                 *  ActionPort: '<S48>/Action Port'
                 */
                /* Update for If: '<S45>/If1' */
                HallcorrectionFimal_DW.first_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S45>/first_order' */
              }

              /* End of If: '<S45>/If1' */

              /* Saturate: '<S45>/Saturation' */
              if (rtb_Product1_a > HallcorrectionFimal_P.Saturation_UpperSat) {
                rtb_Product1_a = HallcorrectionFimal_P.Saturation_UpperSat;
              } else if (rtb_Product1_a <
                         HallcorrectionFimal_P.Saturation_LowerSat) {
                rtb_Product1_a = HallcorrectionFimal_P.Saturation_LowerSat;
              }

              /* End of Saturate: '<S45>/Saturation' */

              /* If: '<S45>/If' incorporates:
               *  DataStoreRead: '<S17>/Data Store Read4'
               */
              if (HallcorrectionFimal_DW.GlobalDirection != 1) {
                /* Outputs for IfAction SubSystem: '<S45>/-ve Direction' incorporates:
                 *  ActionPort: '<S47>/Action Port'
                 */
                /* SwitchCase: '<S47>/Switch Case' */
                switch (HallcorrectionFimal_B.DataStoreRead1) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S57>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof1);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S58>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof2);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S59>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof3);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S60>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof4);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S61>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof5);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S62>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof6);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S63>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof7);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S47>/Switch Case' */

                /* Merge: '<S45>/Merge' incorporates:
                 *  Sum: '<S47>/Sum'
                 */
                HallcorrectionFimal_B.Merge = rtb_Merge1_m0 - rtb_Product1_a;

                /* End of Outputs for SubSystem: '<S45>/-ve Direction' */

                /* Update for IfAction SubSystem: '<S45>/-ve Direction' incorporates:
                 *  ActionPort: '<S47>/Action Port'
                 */
                /* Update for If: '<S45>/If' */
                HallcorrectionFimal_DW.veDirection_SubsysRanBC_g = 4;

                /* End of Update for SubSystem: '<S45>/-ve Direction' */
              } else {
                /* Outputs for IfAction SubSystem: '<S45>/+ve Direction' incorporates:
                 *  ActionPort: '<S46>/Action Port'
                 */
                /* SwitchCase: '<S46>/Switch Case' */
                switch (HallcorrectionFimal_B.DataStoreRead1) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S50>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof1_j);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S51>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof2_j);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S52>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof3_h);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S53>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof4_b);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S54>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof5_b);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S55>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof6_n);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S46>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S56>/Action Port'
                   */
                  HallcorrectionFima_HallValueof1(&rtb_Merge1_m0,
                    &HallcorrectionFimal_P.HallValueof7_e);

                  /* End of Outputs for SubSystem: '<S46>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S46>/Switch Case' */

                /* Merge: '<S45>/Merge' incorporates:
                 *  Sum: '<S46>/Sum'
                 */
                HallcorrectionFimal_B.Merge = rtb_Merge1_m0 + rtb_Product1_a;

                /* End of Outputs for SubSystem: '<S45>/+ve Direction' */

                /* Update for IfAction SubSystem: '<S45>/+ve Direction' incorporates:
                 *  ActionPort: '<S46>/Action Port'
                 */
                /* Update for If: '<S45>/If' */
                HallcorrectionFimal_DW.veDirection_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S45>/+ve Direction' */
              }

              /* End of If: '<S45>/If' */
              HallcorrectionFimal_DW.Subsystem1_SubsysRanBC_e = 4;
            }

            /* End of Outputs for SubSystem: '<S32>/Subsystem1' */

            /* SignalConversion generated from: '<S32>/rawPosition' incorporates:
             *  Constant: '<S32>/PositionEnable'
             */
            rtb_Product1_a = HallcorrectionFimal_B.Merge;

            /* End of Outputs for SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' */

            /* Update for IfAction SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S32>/Action Port'
             */
            /* Update for If: '<S28>/If' */
            HallcorrectionFimal_DW.SpeedanddirectionarevalidUsespe = 4;

            /* End of Update for SubSystem: '<S28>/Speed and direction are valid Use speed to extrapolate position' */
          } else {
            /* Outputs for IfAction SubSystem: '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S31>/Action Port'
             */
            /* SwitchCase: '<S35>/Switch Case' */
            switch (HallcorrectionFimal_B.DataStoreRead1) {
             case 5:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 1' incorporates:
               *  ActionPort: '<S36>/Action Port'
               */
              HallcorrectionFima_HallValueof1(&rtb_Product1_a,
                &HallcorrectionFimal_P.HallValueof1_l);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 1' */
              break;

             case 4:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 2' incorporates:
               *  ActionPort: '<S37>/Action Port'
               */
              HallcorrectionFima_HallValueof1(&rtb_Product1_a,
                &HallcorrectionFimal_P.HallValueof2_b);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 2' */
              break;

             case 6:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 3' incorporates:
               *  ActionPort: '<S38>/Action Port'
               */
              HallcorrectionFima_HallValueof1(&rtb_Product1_a,
                &HallcorrectionFimal_P.HallValueof3_e);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 3' */
              break;

             case 2:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 4' incorporates:
               *  ActionPort: '<S39>/Action Port'
               */
              HallcorrectionFima_HallValueof1(&rtb_Product1_a,
                &HallcorrectionFimal_P.HallValueof4_j);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 4' */
              break;

             case 3:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 5' incorporates:
               *  ActionPort: '<S40>/Action Port'
               */
              HallcorrectionFima_HallValueof1(&rtb_Product1_a,
                &HallcorrectionFimal_P.HallValueof5_l);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 5' */
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 6' incorporates:
               *  ActionPort: '<S41>/Action Port'
               */
              HallcorrectionFima_HallValueof1(&rtb_Product1_a,
                &HallcorrectionFimal_P.HallValueof6_b);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S35>/Hall Value of 7' incorporates:
               *  ActionPort: '<S42>/Action Port'
               */
              HallcorrectionFima_HallValueof1(&rtb_Product1_a,
                &HallcorrectionFimal_P.HallValueof7_b);

              /* End of Outputs for SubSystem: '<S35>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S35>/Switch Case' */

            /* SignalConversion generated from: '<S31>/Speed(r.p.m)' incorporates:
             *  Constant: '<S31>/Constant'
             */
            rtb_Product_h = HallcorrectionFimal_P.Constant_Value_j;

            /* End of Outputs for SubSystem: '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */

            /* Update for IfAction SubSystem: '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S31>/Action Port'
             */
            /* Update for If: '<S28>/If' */
            HallcorrectionFimal_DW.SpeedanddirectionarenotvalidPos = 4;

            /* End of Update for SubSystem: '<S28>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
          }

          /* End of If: '<S28>/If' */

          /* Gain: '<S17>/Gain' */
          HallcorrectionFimal_DW.DiscreteTimeIntegrator_PREV_U =
            HallcorrectionFimal_P.Gain_Gain_fo * rtb_Product_h;

          /* Gain: '<S17>/Gain1' */
          HallcorrectionFimal_B.Gain1 = HallcorrectionFimal_P.Gain1_Gain_b *
            HallcorrectionFimal_DW.DiscreteTimeIntegrator_PREV_U;

          /* Sum: '<S17>/Sum' incorporates:
           *  Gain: '<S28>/PositionUnit'
           */
          HallcorrectionFimal_B.Sum = HallcorrectionFimal_P.PositionUnit_Gain *
            rtb_Product1_a +
            HallcorrectionFimal_DW.DiscreteTimeIntegrator_DSTATE;

          /* Outputs for Enabled SubSystem: '<S10>/PosGen' incorporates:
           *  EnablePort: '<S16>/Enable'
           */
          /* Constant: '<S1>/Constant1' */
          if (HallcorrectionFimal_P.Constant1_Value_a > 0.0) {
            if (!HallcorrectionFimal_DW.PosGen_MODE) {
              /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
              HallcorrectionFimal_DW.UnitDelay_DSTATE_k =
                HallcorrectionFimal_P.UnitDelay_InitialCondition;
              HallcorrectionFimal_DW.PosGen_MODE = true;
            }

            /* SignalConversion generated from: '<S16>/Enable' */
            HallcorrectionFimal_B.Enable =
              HallcorrectionFimal_P.Constant1_Value_a;

            /* Outputs for Enabled SubSystem: '<S16>/Up Counter' incorporates:
             *  EnablePort: '<S22>/Enable'
             */
            if (HallcorrectionFimal_B.Enable > 0.0) {
              if (!HallcorrectionFimal_DW.UpCounter_MODE) {
                /* InitializeConditions for Delay: '<S22>/Delay' */
                HallcorrectionFimal_DW.Delay_DSTATE_k =
                  HallcorrectionFimal_P.Delay_InitialCondition_a;
                HallcorrectionFimal_DW.UpCounter_MODE = true;
              }

              /* Sum: '<S22>/Add1' incorporates:
               *  Constant: '<S22>/Constant'
               *  Delay: '<S22>/Delay'
               */
              tmp_p = (uint64_T)HallcorrectionFimal_P.Constant_Value_k +
                HallcorrectionFimal_DW.Delay_DSTATE_k;
              if (tmp_p > 4294967295ULL) {
                tmp_p = 4294967295ULL;
              }

              /* Sum: '<S22>/Add1' */
              HallcorrectionFimal_B.Add1 = (uint32_T)tmp_p;

              /* Update for Delay: '<S22>/Delay' */
              HallcorrectionFimal_DW.Delay_DSTATE_k = HallcorrectionFimal_B.Add1;
              HallcorrectionFimal_DW.UpCounter_SubsysRanBC = 4;
            } else if (HallcorrectionFimal_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S22>/Add1' incorporates:
               *  Outport: '<S22>/Count'
               */
              HallcorrectionFimal_B.Add1 = HallcorrectionFimal_P.Count_Y0;
              HallcorrectionFimal_DW.UpCounter_MODE = false;
            }

            /* End of Outputs for SubSystem: '<S16>/Up Counter' */

            /* Outputs for Enabled SubSystem: '<S16>/Subsystem' incorporates:
             *  EnablePort: '<S20>/Enable'
             */
            /* Logic: '<S16>/NOT' incorporates:
             *  Constant: '<S18>/Constant'
             *  RelationalOperator: '<S18>/Compare'
             */
            if (HallcorrectionFimal_B.Add1 >
                HallcorrectionFimal_P.Disablehostafter42seconds_const) {
              /* DataStoreWrite: '<S20>/Data Store Write' incorporates:
               *  Constant: '<S20>/Constant'
               */
              HallcorrectionFimal_DW.Enable =
                HallcorrectionFimal_P.Constant_Value;
              HallcorrectionFimal_DW.Subsystem_SubsysRanBC_g = 4;
            }

            /* End of Logic: '<S16>/NOT' */
            /* End of Outputs for SubSystem: '<S16>/Subsystem' */

            /* If: '<S21>/If' incorporates:
             *  Constant: '<S21>/Count for 2 sec'
             */
            if (HallcorrectionFimal_B.Add1 <
                HallcorrectionFimal_P.Countfor2sec_Value) {
              /* Outputs for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
               *  ActionPort: '<S23>/Action Port'
               */
              /* SignalConversion generated from: '<S23>/Out1' incorporates:
               *  Constant: '<S23>/Constant'
               */
              rtb_Product_h = HallcorrectionFimal_P.Constant_Value_c;

              /* End of Outputs for SubSystem: '<S21>/If Action Subsystem' */

              /* Update for IfAction SubSystem: '<S21>/If Action Subsystem' incorporates:
               *  ActionPort: '<S23>/Action Port'
               */
              /* Update for If: '<S21>/If' */
              HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC_o = 4;

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
              HallcorrectionFimal_DW.Delay_DSTATE_a +=
                HallcorrectionFimal_P.Constant1_Value_op;

              /* Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' */
              if (HallcorrectionFimal_DW.Delay_DSTATE_a >
                  HallcorrectionFimal_P.SaturatetomotorcalibSpeedRPM_Up) {
                /* Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' */
                HallcorrectionFimal_DW.Delay_DSTATE_a =
                  HallcorrectionFimal_P.SaturatetomotorcalibSpeedRPM_Up;
              } else if (HallcorrectionFimal_DW.Delay_DSTATE_a <
                         HallcorrectionFimal_P.SaturatetomotorcalibSpeedRPM_Lo)
              {
                /* Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' */
                HallcorrectionFimal_DW.Delay_DSTATE_a =
                  HallcorrectionFimal_P.SaturatetomotorcalibSpeedRPM_Lo;
              }

              /* End of Saturate: '<S24>/Saturate to 'motor.calibSpeed' RPM' */

              /* Gain: '<S24>/Multiply' */
              rtb_Product_h = HallcorrectionFimal_P.Multiply_Gain *
                HallcorrectionFimal_DW.Delay_DSTATE_a;

              /* End of Outputs for SubSystem: '<S21>/If Action Subsystem2' */

              /* Update for IfAction SubSystem: '<S21>/If Action Subsystem2' incorporates:
               *  ActionPort: '<S24>/Action Port'
               */
              /* Update for If: '<S21>/If' */
              HallcorrectionFimal_DW.IfActionSubsystem2_SubsysRanBC = 4;

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
            if (!HallcorrectionFimal_P.Constant_Reset_Value) {
              /* Outputs for Enabled SubSystem: '<S26>/Subsystem' incorporates:
               *  EnablePort: '<S27>/Enable'
               */
              if (HallcorrectionFimal_DW.Delay_DSTATE_h) {
                /* SignalConversion generated from: '<S27>/Input' incorporates:
                 *  Gain: '<S25>/scaleIn'
                 */
                HallcorrectionFimal_B.Input = HallcorrectionFimal_P.scaleIn_Gain
                  * rtb_Product_h;
                HallcorrectionFimal_DW.Subsystem_SubsysRanBC_p = 4;
              }

              /* End of Outputs for SubSystem: '<S26>/Subsystem' */

              /* Sum: '<S26>/Add' incorporates:
               *  Delay: '<S26>/Delay'
               *  UnitDelay: '<S25>/Unit Delay'
               */
              rtb_Product1_a = HallcorrectionFimal_B.Input +
                HallcorrectionFimal_DW.UnitDelay_DSTATE_k;

              /* DataTypeConversion: '<S26>/Data Type Conversion' */
              rtb_Product_h = floorf(rtb_Product1_a);
              if (rtIsNaNF(rtb_Product_h) || rtIsInfF(rtb_Product_h)) {
                rtb_Product_h = 0.0F;
              } else {
                rtb_Product_h = fmodf(rtb_Product_h, 65536.0F);
              }

              /* Sum: '<S26>/Add1' incorporates:
               *  DataTypeConversion: '<S26>/Data Type Conversion'
               *  DataTypeConversion: '<S26>/Data Type Conversion1'
               */
              HallcorrectionFimal_B.Add1_l = rtb_Product1_a - (real32_T)
                (rtb_Product_h < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
                 -rtb_Product_h : (int32_T)(int16_T)(uint16_T)rtb_Product_h);

              /* Update for Delay: '<S26>/Delay' incorporates:
               *  Constant: '<S26>/Constant'
               */
              HallcorrectionFimal_DW.Delay_DSTATE_h =
                HallcorrectionFimal_P.Constant_Value_cs;
              HallcorrectionFimal_DW.Accumulate_SubsysRanBC = 4;
            }

            /* End of Logic: '<S25>/NOT' */
            /* End of Outputs for SubSystem: '<S25>/Accumulate' */

            /* Gain: '<S25>/scaleOut' */
            HallcorrectionFimal_B.scaleOut = HallcorrectionFimal_P.scaleOut_Gain
              * HallcorrectionFimal_B.Add1_l;

            /* Update for UnitDelay: '<S25>/Unit Delay' */
            HallcorrectionFimal_DW.UnitDelay_DSTATE_k =
              HallcorrectionFimal_B.Add1_l;
            HallcorrectionFimal_DW.PosGen_SubsysRanBC = 4;
          } else if (HallcorrectionFimal_DW.PosGen_MODE) {
            /* Disable for Enabled SubSystem: '<S16>/Up Counter' */
            if (HallcorrectionFimal_DW.UpCounter_MODE) {
              /* Disable for Sum: '<S22>/Add1' incorporates:
               *  Outport: '<S22>/Count'
               */
              HallcorrectionFimal_B.Add1 = HallcorrectionFimal_P.Count_Y0;
              HallcorrectionFimal_DW.UpCounter_MODE = false;
            }

            /* End of Disable for SubSystem: '<S16>/Up Counter' */

            /* Disable for SignalConversion generated from: '<S16>/Enable' incorporates:
             *  Outport: '<S16>/EnPWM'
             */
            HallcorrectionFimal_B.Enable = HallcorrectionFimal_P.EnPWM_Y0;
            HallcorrectionFimal_DW.PosGen_MODE = false;
          }

          /* End of Constant: '<S1>/Constant1' */
          /* End of Outputs for SubSystem: '<S10>/PosGen' */

          /* MATLABSystem: '<S13>/Analog to Digital Converter' */
          injectedReadADCIntr(HallcorrectionFimal_DW.obj.ADCHandle, ADC_READ,
                              &tmp[0]);

          /* UnitDelay: '<S9>/Output' */
          HallcorrectionFimal_B.Output = HallcorrectionFimal_DW.Output_DSTATE;

          /* Sum: '<S14>/FixPt Sum1' incorporates:
           *  Constant: '<S14>/FixPt Constant'
           */
          rtb_Get_Integer = (uint16_T)((uint32_T)HallcorrectionFimal_B.Output +
            HallcorrectionFimal_P.FixPtConstant_Value);

          /* Switch: '<S15>/FixPt Switch' */
          if (rtb_Get_Integer > HallcorrectionFimal_P.WrapToZero_Threshold) {
            /* Update for UnitDelay: '<S9>/Output' incorporates:
             *  Constant: '<S15>/Constant'
             */
            HallcorrectionFimal_DW.Output_DSTATE =
              HallcorrectionFimal_P.Constant_Value_g;
          } else {
            /* Update for UnitDelay: '<S9>/Output' */
            HallcorrectionFimal_DW.Output_DSTATE = rtb_Get_Integer;
          }

          /* End of Switch: '<S15>/FixPt Switch' */

          /* Gain: '<S76>/convert_pu' */
          rtb_Product1_a = HallcorrectionFimal_P.convert_pu_Gain *
            HallcorrectionFimal_B.scaleOut;

          /* If: '<S76>/If' incorporates:
           *  Constant: '<S77>/Constant'
           *  RelationalOperator: '<S77>/Compare'
           */
          if (rtb_Product1_a < HallcorrectionFimal_P.Constant_Value_e) {
            /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem' incorporates:
             *  ActionPort: '<S78>/Action Port'
             */
            /* DataTypeConversion: '<S78>/Convert_uint16' */
            rtb_Product_h = floorf(rtb_Product1_a);
            if (rtIsInfF(rtb_Product_h)) {
              rtb_Product_h = 0.0F;
            } else {
              rtb_Product_h = fmodf(rtb_Product_h, 65536.0F);
            }

            /* Sum: '<S78>/Sum' incorporates:
             *  DataTypeConversion: '<S78>/Convert_back'
             *  DataTypeConversion: '<S78>/Convert_uint16'
             */
            rtb_Product1_a -= (real32_T)(rtb_Product_h < 0.0F ? (int32_T)
              (int16_T)-(int16_T)(uint16_T)-rtb_Product_h : (int32_T)(int16_T)
              (uint16_T)rtb_Product_h);

            /* End of Outputs for SubSystem: '<S76>/If Action Subsystem' */

            /* Update for IfAction SubSystem: '<S76>/If Action Subsystem' incorporates:
             *  ActionPort: '<S78>/Action Port'
             */
            /* Update for If: '<S76>/If' */
            HallcorrectionFimal_DW.IfActionSubsystem_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S76>/If Action Subsystem' */
          } else {
            /* Outputs for IfAction SubSystem: '<S76>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S79>/Action Port'
             */
            /* DataTypeConversion: '<S79>/Convert_uint16' */
            rtb_Product_h = truncf(rtb_Product1_a);
            if (rtIsNaNF(rtb_Product_h) || rtIsInfF(rtb_Product_h)) {
              rtb_Product_h = 0.0F;
            } else {
              rtb_Product_h = fmodf(rtb_Product_h, 65536.0F);
            }

            /* Sum: '<S79>/Sum' incorporates:
             *  DataTypeConversion: '<S79>/Convert_back'
             *  DataTypeConversion: '<S79>/Convert_uint16'
             */
            rtb_Product1_a -= (real32_T)(rtb_Product_h < 0.0F ? (int32_T)
              (int16_T)-(int16_T)(uint16_T)-rtb_Product_h : (int32_T)(int16_T)
              (uint16_T)rtb_Product_h);

            /* End of Outputs for SubSystem: '<S76>/If Action Subsystem1' */

            /* Update for IfAction SubSystem: '<S76>/If Action Subsystem1' incorporates:
             *  ActionPort: '<S79>/Action Port'
             */
            /* Update for If: '<S76>/If' */
            HallcorrectionFimal_DW.IfActionSubsystem1_SubsysRanBC = 4;

            /* End of Update for SubSystem: '<S76>/If Action Subsystem1' */
          }

          /* End of If: '<S76>/If' */

          /* Gain: '<S65>/indexing' */
          rtb_Product1_a *= HallcorrectionFimal_P.indexing_Gain;

          /* DataTypeConversion: '<S65>/Get_Integer' */
          rtb_Product_h = truncf(rtb_Product1_a);
          if (rtIsNaNF(rtb_Product_h) || rtIsInfF(rtb_Product_h)) {
            rtb_Product_h = 0.0F;
          } else {
            rtb_Product_h = fmodf(rtb_Product_h, 65536.0F);
          }

          rtb_Get_Integer = (uint16_T)(rtb_Product_h < 0.0F ? (int32_T)(uint16_T)
            -(int16_T)(uint16_T)-rtb_Product_h : (int32_T)(uint16_T)
            rtb_Product_h);

          /* End of DataTypeConversion: '<S65>/Get_Integer' */

          /* Sum: '<S65>/Sum2' incorporates:
           *  DataTypeConversion: '<S65>/Data Type Conversion1'
           */
          rtb_Product1_a -= (real32_T)rtb_Get_Integer;

          /* Outputs for Atomic SubSystem: '<S80>/Two inputs CRL' */
          /* AlgorithmDescriptorDelegate generated from: '<S83>/a16' incorporates:
           *  Constant: '<S65>/offset'
           *  Constant: '<S65>/sine_table_values'
           *  Constant: '<S66>/Vd_Ref'
           *  Constant: '<S66>/Vq'
           *  Product: '<S75>/Product'
           *  Product: '<S75>/Product1'
           *  Selector: '<S65>/Lookup'
           *  Sum: '<S65>/Sum'
           *  Sum: '<S75>/Sum3'
           *  Sum: '<S75>/Sum4'
           *  Sum: '<S75>/Sum5'
           *  Sum: '<S75>/Sum6'
           */
          arm_inv_park_f32(HallcorrectionFimal_P.Vd_Ref_Value,
                           HallcorrectionFimal_P.Vq_Value, &rtb_Product_h,
                           &rtb_Merge1_m0,
                           (HallcorrectionFimal_P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            HallcorrectionFimal_P.offset_Value[0] + rtb_Get_Integer)] -
                            HallcorrectionFimal_P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            HallcorrectionFimal_P.offset_Value[1] + rtb_Get_Integer)]) *
                           rtb_Product1_a +
                           HallcorrectionFimal_P.sine_table_values_Value
                           [(int32_T)((uint32_T)
            HallcorrectionFimal_P.offset_Value[1] + rtb_Get_Integer)],
                           (HallcorrectionFimal_P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            HallcorrectionFimal_P.offset_Value[2] + rtb_Get_Integer)] -
                            HallcorrectionFimal_P.sine_table_values_Value
                            [(int32_T)((uint32_T)
            HallcorrectionFimal_P.offset_Value[3] + rtb_Get_Integer)]) *
                           rtb_Product1_a +
                           HallcorrectionFimal_P.sine_table_values_Value
                           [(int32_T)((uint32_T)
            HallcorrectionFimal_P.offset_Value[3] + rtb_Get_Integer)]);

          /* End of Outputs for SubSystem: '<S80>/Two inputs CRL' */

          /* Switch: '<S81>/Switch4' incorporates:
           *  Constant: '<S81>/Constant1'
           *  Constant: '<S81>/stop'
           *  Gain: '<S81>/Gain'
           *  Gain: '<S81>/Gain1'
           *  Gain: '<S90>/Gain'
           *  Sum: '<S81>/Add'
           *  Sum: '<S90>/Add1'
           *  Sum: '<S90>/Add2'
           *  Sum: '<S90>/Add3'
           */
          if (HallcorrectionFimal_B.Enable >=
              HallcorrectionFimal_P.Switch4_Threshold) {
            /* Gain: '<S94>/sqrt3_by_two' */
            rtb_Merge1_m0 *= HallcorrectionFimal_P.sqrt3_by_two_Gain;

            /* Gain: '<S94>/one_by_two' */
            rtb_Add1_j = HallcorrectionFimal_P.one_by_two_Gain * rtb_Product_h;

            /* Gain: '<S94>/Kc' incorporates:
             *  Sum: '<S94>/add_c'
             */
            rtb_Product1_a = ((0.0F - rtb_Add1_j) - rtb_Merge1_m0) *
              HallcorrectionFimal_P.Kc_Gain;

            /* Gain: '<S94>/Kb' incorporates:
             *  Sum: '<S94>/add_b'
             */
            rtb_Add1_j = (rtb_Merge1_m0 - rtb_Add1_j) *
              HallcorrectionFimal_P.Kb_Gain;

            /* Gain: '<S94>/Ka' */
            rtb_Merge1_m0 = HallcorrectionFimal_P.Ka_Gain * rtb_Product_h;

            /* Gain: '<S91>/one_by_two' incorporates:
             *  MinMax: '<S91>/Max'
             *  MinMax: '<S91>/Min'
             *  Sum: '<S91>/Add'
             */
            rtb_Product_h = (fmaxf(fmaxf(rtb_Merge1_m0, rtb_Add1_j),
              rtb_Product1_a) + fminf(fminf(rtb_Merge1_m0, rtb_Add1_j),
              rtb_Product1_a)) * HallcorrectionFimal_P.one_by_two_Gain_c;
            HallcorrectionFimal_B.rtb_Switch4_idx_0 = ((rtb_Merge1_m0 +
              rtb_Product_h) * HallcorrectionFimal_P.Gain_Gain_b *
              HallcorrectionFimal_P.Gain_Gain_j +
              HallcorrectionFimal_P.Constant1_Value_b) *
              HallcorrectionFimal_P.Gain1_Gain;
            rtb_Switch4_idx_1 = ((rtb_Add1_j + rtb_Product_h) *
                                 HallcorrectionFimal_P.Gain_Gain_b *
                                 HallcorrectionFimal_P.Gain_Gain_j +
                                 HallcorrectionFimal_P.Constant1_Value_b) *
              HallcorrectionFimal_P.Gain1_Gain;
            rtb_Switch4_idx_2 = ((rtb_Product_h + rtb_Product1_a) *
                                 HallcorrectionFimal_P.Gain_Gain_b *
                                 HallcorrectionFimal_P.Gain_Gain_j +
                                 HallcorrectionFimal_P.Constant1_Value_b) *
              HallcorrectionFimal_P.Gain1_Gain;
          } else {
            HallcorrectionFimal_B.rtb_Switch4_idx_0 =
              HallcorrectionFimal_P.stop_Value;
            rtb_Switch4_idx_1 = HallcorrectionFimal_P.stop_Value;
            rtb_Switch4_idx_2 = HallcorrectionFimal_P.stop_Value;
          }

          /* End of Switch: '<S81>/Switch4' */

          /* MATLABSystem: '<S87>/PWM Output' */
          setDutyCycleInPercentageChannel1
            (HallcorrectionFimal_DW.obj_f.TimerHandle,
             HallcorrectionFimal_B.rtb_Switch4_idx_0);
          setDutyCycleInPercentageChannel2
            (HallcorrectionFimal_DW.obj_f.TimerHandle, rtb_Switch4_idx_1);
          setDutyCycleInPercentageChannel3
            (HallcorrectionFimal_DW.obj_f.TimerHandle, rtb_Switch4_idx_2);

          /* Outputs for Enabled SubSystem: '<S11>/Find Offset' incorporates:
           *  EnablePort: '<S64>/Enable'
           */
          if (HallcorrectionFimal_B.Enable > 0.0) {
            if (!HallcorrectionFimal_DW.FindOffset_MODE) {
              /* InitializeConditions for Delay: '<S64>/Delay' */
              HallcorrectionFimal_DW.Delay_DSTATE =
                HallcorrectionFimal_P.Delay_InitialCondition_b;
              HallcorrectionFimal_DW.FindOffset_MODE = true;
            }

            /* Outputs for Enabled SubSystem: '<S64>/Subsystem' incorporates:
             *  EnablePort: '<S70>/Enable'
             */
            /* Logic: '<S64>/AND' incorporates:
             *  Constant: '<S68>/Constant'
             *  Constant: '<S69>/Constant'
             *  Delay: '<S64>/Delay'
             *  RelationalOperator: '<S68>/Compare'
             *  RelationalOperator: '<S69>/Compare'
             */
            if ((HallcorrectionFimal_B.scaleOut <=
                 HallcorrectionFimal_P.CompareToConstant_const) &&
                (HallcorrectionFimal_DW.Delay_DSTATE >=
                 HallcorrectionFimal_P.CompareToConstant1_const)) {
              /* Switch: '<S71>/Switch1' incorporates:
               *  Constant: '<S71>/FilterConstant'
               *  Constant: '<S71>/One'
               *  Constant: '<S71>/OneMinusFilterConstant'
               *  Constant: '<S71>/UseInputPort'
               *  Constant: '<S71>/a'
               *  Sum: '<S71>/Sum'
               */
              if (HallcorrectionFimal_P.UseInputPort_Value >
                  HallcorrectionFimal_P.Switch1_Threshold) {
                rtb_Merge1_m0 = HallcorrectionFimal_P.a_Value;
                rtb_Add1_j = HallcorrectionFimal_P.One_Value -
                  HallcorrectionFimal_P.a_Value;
              } else {
                rtb_Merge1_m0 = HallcorrectionFimal_P.FilterConstant_Value;
                rtb_Add1_j = HallcorrectionFimal_P.OneMinusFilterConstant_Value;
              }

              /* End of Switch: '<S71>/Switch1' */

              /* Sum: '<S74>/Add1' incorporates:
               *  Product: '<S74>/Product'
               *  Product: '<S74>/Product1'
               *  UnitDelay: '<S74>/Unit Delay'
               */
              HallcorrectionFimal_B.Add1_d = HallcorrectionFimal_B.Sum *
                rtb_Merge1_m0 + rtb_Add1_j *
                HallcorrectionFimal_DW.UnitDelay_DSTATE;

              /* Update for UnitDelay: '<S74>/Unit Delay' */
              HallcorrectionFimal_DW.UnitDelay_DSTATE =
                HallcorrectionFimal_B.Add1_d;
              HallcorrectionFimal_DW.Subsystem_SubsysRanBC = 4;
            }

            /* End of Logic: '<S64>/AND' */
            /* End of Outputs for SubSystem: '<S64>/Subsystem' */

            /* Update for Delay: '<S64>/Delay' */
            HallcorrectionFimal_DW.Delay_DSTATE = HallcorrectionFimal_B.scaleOut;
            HallcorrectionFimal_DW.FindOffset_SubsysRanBC = 4;
          } else {
            HallcorrectionFimal_DW.FindOffset_MODE = false;
          }

          /* End of Outputs for SubSystem: '<S11>/Find Offset' */

          /* Outputs for Enabled SubSystem: '<S11>/Subsystem1' incorporates:
           *  EnablePort: '<S67>/Enable'
           */
          /* Logic: '<S11>/NOT' */
          if (!(HallcorrectionFimal_B.Enable != 0.0)) {
            HallcorrectionFimal_DW.Subsystem1_SubsysRanBC = 4;
          }

          /* End of Logic: '<S11>/NOT' */
          /* End of Outputs for SubSystem: '<S11>/Subsystem1' */

          /* Update for DiscreteIntegrator: '<S17>/Discrete-Time Integrator' */
          HallcorrectionFimal_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
          HallcorrectionFimal_DW.DiscreteTimeIntegrator_PrevRese = (int8_T)
            (rtb_DataStoreRead6 > 0);

          /* Update for Delay: '<S29>/validityDelay' incorporates:
           *  DataStoreRead: '<S17>/Data Store Read3'
           *  DataStoreRead: '<S17>/Data Store Read5'
           *  DataTypeConversion: '<S29>/Data Type Conversion'
           *  Delay: '<S29>/speedCountDelay'
           */
          if (Switch != 0) {
            HallcorrectionFimal_DW.validityDelay_DSTATE =
              (HallcorrectionFimal_DW.GlobalSpeedValidity != 0);
            HallcorrectionFimal_DW.speedCountDelay_DSTATE =
              HallcorrectionFimal_DW.GlobalSpeedCount;
          }

          /* End of Update for Delay: '<S29>/validityDelay' */

          /* Update for Delay: '<S30>/Delay One Step' incorporates:
           *  Constant: '<S30>/Constant2'
           *  Sum: '<S30>/Sum'
           */
          if (OR) {
            HallcorrectionFimal_DW.DelayOneStep_DSTATE = (uint16_T)((uint32_T)
              HallcorrectionFimal_B.DelayOneStep -
              HallcorrectionFimal_P.Constant2_Value);
          }

          /* End of Update for Delay: '<S30>/Delay One Step' */
          HallcorrectionFimal_DW.ADCSIC_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S173>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((HallcorrectionFimal_M->Timing.clockTick5) * 0.002);
      extmodeEvent(5,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void HallcorrectionFimal_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
  MW_NVIC_DisableIRQ(38);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
