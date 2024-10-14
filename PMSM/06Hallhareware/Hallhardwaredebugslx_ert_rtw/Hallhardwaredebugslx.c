/*
 * File: Hallhardwaredebugslx.c
 *
 * Code generated for Simulink model 'Hallhardwaredebugslx'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Oct 12 17:53:03 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Hallhardwaredebugslx.h"
#include "rtwtypes.h"
#include "Hallhardwaredebugslx_types.h"
#include "Hallhardwaredebugslx_private.h"
#include "stm_timer_ll.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "stm_adc_ll.h"
#include <stddef.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_Hallhardwaredebugslx_T Hallhardwaredebugslx_B;

/* Block states (default storage) */
DW_Hallhardwaredebugslx_T Hallhardwaredebugslx_DW;

/* Real-time model */
static RT_MODEL_Hallhardwaredebugslx_T Hallhardwaredebugslx_M_;
RT_MODEL_Hallhardwaredebugslx_T *const Hallhardwaredebugslx_M =
  &Hallhardwaredebugslx_M_;

/* Forward declaration for local functions */
static void Hallhardwarede_SystemCore_setup(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallhardware_SystemCore_setup_i(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallhardware_SystemCore_setup_g(stm32cube_blocks_TimerBlock_H_T *obj);

/* Forward declaration for local functions */
static void Hallhardwar_SystemCore_setup_gg(stm32cube_blocks_AnalogInput__T *obj);
static void Hallhardwar_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ha_T *obj);

/* Forward declaration for local functions */
static void Hallhardw_PWMOutput_setupImpl_f(stm32cube_blocks_PWMOutput_Ha_T *obj);

/*
 * Output and update for action system:
 *    '<S120>/If Action Subsystem6'
 *    '<S120>/If Action Subsystem7'
 *    '<S95>/If Action Subsystem6'
 *    '<S95>/If Action Subsystem7'
 *    '<S70>/If Action Subsystem6'
 *    '<S70>/If Action Subsystem7'
 */
void Hallhardware_IfActionSubsystem6(int16_T *rty_direction, uint16_T
  *rty_sequence_check, P_IfActionSubsystem6_Hallhard_T *localP)
{
  /* SignalConversion generated from: '<S127>/direction' incorporates:
   *  Constant: '<S127>/Constant'
   */
  *rty_direction = localP->Constant_Value;

  /* SignalConversion generated from: '<S127>/sequence_check' incorporates:
   *  Constant: '<S127>/Constant1'
   */
  *rty_sequence_check = localP->Constant1_Value;
}

/*
 * Output and update for action system:
 *    '<S120>/If Action Subsystem'
 *    '<S120>/If Action Subsystem1'
 *    '<S120>/If Action Subsystem2'
 *    '<S120>/If Action Subsystem3'
 *    '<S120>/If Action Subsystem4'
 *    '<S120>/If Action Subsystem5'
 *    '<S95>/If Action Subsystem'
 *    '<S95>/If Action Subsystem1'
 *    '<S95>/If Action Subsystem2'
 *    '<S95>/If Action Subsystem3'
 *    ...
 */
void Hallhardwared_IfActionSubsystem(uint16_T *rty_Out1, uint16_T *rty_Out2,
  P_IfActionSubsystem_Hallhardw_T *localP)
{
  /* SignalConversion generated from: '<S121>/Out1' incorporates:
   *  Constant: '<S121>/previous'
   */
  *rty_Out1 = localP->previous_Value;

  /* SignalConversion generated from: '<S121>/Out2' incorporates:
   *  Constant: '<S121>/next'
   */
  *rty_Out2 = localP->next_Value;
}

/*
 * System initialize for action system:
 *    '<S118>/Valid Halls'
 *    '<S93>/Valid Halls'
 *    '<S68>/Valid Halls'
 */
void Hallhardwaredeb_ValidHalls_Init(B_ValidHalls_Hallhardwaredebu_T *localB,
  P_ValidHalls_Hallhardwaredebu_T *localP)
{
  /* SystemInitialize for Merge: '<S120>/Merge' */
  localB->Merge = localP->Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S120>/Merge1' */
  localB->Merge1 = localP->Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S120>/Merge2' */
  localB->Merge2 = localP->Merge2_InitialOutput;

  /* SystemInitialize for Merge: '<S120>/Merge3' */
  localB->Merge3 = localP->Merge3_InitialOutput;
}

/*
 * Output and update for action system:
 *    '<S118>/Valid Halls'
 *    '<S93>/Valid Halls'
 *    '<S68>/Valid Halls'
 */
void Hallhardwaredebugslx_ValidHalls(uint16_T rtu_hallReading, uint16_T
  rtu_previousState, int16_T rtu_previous_direction, boolean_T
  *rty_directional_speed_valid_fla, int16_T *rty_direction, uint16_T
  *rty_inValidHall, B_ValidHalls_Hallhardwaredebu_T *localB,
  DW_ValidHalls_Hallhardwaredeb_T *localDW, P_ValidHalls_Hallhardwaredebu_T
  *localP)
{
  /* SwitchCase: '<S120>/Switch Case' */
  switch (rtu_hallReading) {
   case 5:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem' incorporates:
     *  ActionPort: '<S121>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem' */
    break;

   case 4:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S122>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem1);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem1' */
    break;

   case 6:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem2' incorporates:
     *  ActionPort: '<S123>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem2);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem2' */
    break;

   case 2:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem3' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem3);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem3' */
    break;

   case 3:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem4' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem4);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem4' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem5' incorporates:
     *  ActionPort: '<S126>/Action Port'
     */
    Hallhardwared_IfActionSubsystem(&localB->Merge, &localB->Merge1,
      &localP->IfActionSubsystem5);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem5' */
    break;

   default:
    /* Update for IfAction SubSystem: '<S120>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S130>/Action Port'
     */
    /* Update for SwitchCase: '<S120>/Switch Case' */
    localDW->SwitchCaseActionSubsystem_Subsy = 4;

    /* End of Update for SubSystem: '<S120>/Switch Case Action Subsystem' */
    break;
  }

  /* End of SwitchCase: '<S120>/Switch Case' */

  /* If: '<S120>/If' */
  if (rtu_previousState == localB->Merge) {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem6' incorporates:
     *  ActionPort: '<S127>/Action Port'
     */
    Hallhardware_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem6);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem6' */
  } else if (rtu_previousState == localB->Merge1) {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem7' incorporates:
     *  ActionPort: '<S128>/Action Port'
     */
    Hallhardware_IfActionSubsystem6(&localB->Merge2, &localB->Merge3,
      &localP->IfActionSubsystem7);

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem7' */
  } else {
    /* Outputs for IfAction SubSystem: '<S120>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* Merge: '<S120>/Merge3' incorporates:
     *  Constant: '<S129>/Constant'
     *  SignalConversion generated from: '<S129>/sequence_check'
     */
    localB->Merge3 = localP->Constant_Value;

    /* End of Outputs for SubSystem: '<S120>/If Action Subsystem8' */

    /* Update for IfAction SubSystem: '<S120>/If Action Subsystem8' incorporates:
     *  ActionPort: '<S129>/Action Port'
     */
    /* Update for If: '<S120>/If' */
    localDW->IfActionSubsystem8_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S120>/If Action Subsystem8' */
  }

  /* End of If: '<S120>/If' */

  /* SignalConversion: '<S120>/Signal Conversion' */
  *rty_inValidHall = localB->Merge3;

  /* SignalConversion: '<S120>/Signal Conversion1' */
  *rty_direction = localB->Merge2;

  /* Switch: '<S120>/Switch' incorporates:
   *  Constant: '<S120>/Constant'
   *  RelationalOperator: '<S120>/Relational Operator'
   */
  if (localB->Merge3 != 0) {
    *rty_directional_speed_valid_fla = localP->Constant_Value_d;
  } else {
    *rty_directional_speed_valid_fla = (localB->Merge2 == rtu_previous_direction);
  }

  /* End of Switch: '<S120>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S118>/Bad hall (glitch or wrong connection)'
 *    '<S93>/Bad hall (glitch or wrong connection)'
 *    '<S68>/Bad hall (glitch or wrong connection)'
 */
void Badhallglitchorwrongconnection(int16_T rtu_previous_direction, uint16_T
  *rty_inValidHall, int16_T *rty_direction, boolean_T
  *rty_directional_speed_valid_fla, P_Badhallglitchorwrongconnect_T *localP)
{
  /* SignalConversion generated from: '<S119>/inValidHall' incorporates:
   *  Constant: '<S119>/Constant'
   */
  *rty_inValidHall = localP->Constant_Value;

  /* SignalConversion: '<S119>/Signal Conversion' */
  *rty_direction = rtu_previous_direction;

  /* SignalConversion generated from: '<S119>/directional_speed_valid_flag' incorporates:
   *  Constant: '<S119>/Constant1'
   */
  *rty_directional_speed_valid_fla = localP->Constant1_Value;
}

static void Hallhardwarede_SystemCore_setup(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S117>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S117>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S117>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Hallhardware_SystemCore_setup_i(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S92>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S92>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S92>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

static void Hallhardware_SystemCore_setup_g(stm32cube_blocks_TimerBlock_H_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S67>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM2;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S67>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S67>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/*
 * Output and update for action system:
 *    '<S48>/Hall Value of 1'
 *    '<S48>/Hall Value of 2'
 *    '<S48>/Hall Value of 3'
 *    '<S48>/Hall Value of 4'
 *    '<S48>/Hall Value of 5'
 *    '<S48>/Hall Value of 6'
 *    '<S48>/Hall Value of 7'
 *    '<S47>/Hall Value of 1'
 *    '<S47>/Hall Value of 2'
 *    '<S47>/Hall Value of 3'
 *    ...
 */
void Hallhardwaredebugs_HallValueof1(real32_T *rty_position,
  P_HallValueof1_Hallhardwarede_T *localP)
{
  /* SignalConversion generated from: '<S58>/position' incorporates:
   *  Constant: '<S58>/Constant'
   */
  *rty_position = localP->Constant_Value;
}

static void Hallhardwar_SystemCore_setup_gg(stm32cube_blocks_AnalogInput__T *obj)
{
  ADC_Type_T adcStructLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  obj->isInitialized = 1;
  adcStructLoc.InternalBufferPtr = (void *)(NULL);

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
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

static void Hallhardwar_PWMOutput_setupImpl(stm32cube_blocks_PWMOutput_Ha_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S20>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S20>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S20>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

static void Hallhardw_PWMOutput_setupImpl_f(stm32cube_blocks_PWMOutput_Ha_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<S148>/PWM Output' */
  b.PeripheralPtr = TIM1;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<S148>/PWM Output' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  enableTimerChannel1(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel2(obj->TimerHandle, ENABLE_CH_CHN);
  enableTimerChannel3(obj->TimerHandle, ENABLE_CH_CHN);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<S148>/PWM Output' */
    enableCounter(obj->TimerHandle, true);
  }
}

/* Model step function */
void Hallhardwaredebugslx_step(void)
{
  GPIO_TypeDef * portNameLoc;
  real_T rtb_PulseGenerator;
  int32_T c;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (Hallhardwaredebugslx_DW.clockTickCounter <
                        Hallhardwaredebugslx_P.PulseGenerator_Duty) &&
    (Hallhardwaredebugslx_DW.clockTickCounter >= 0) ?
    Hallhardwaredebugslx_P.PulseGenerator_Amp : 0.0;
  if (Hallhardwaredebugslx_DW.clockTickCounter >=
      Hallhardwaredebugslx_P.PulseGenerator_Period - 1.0) {
    Hallhardwaredebugslx_DW.clockTickCounter = 0;
  } else {
    Hallhardwaredebugslx_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* MATLABSystem: '<S145>/Digital Port Write' */
  portNameLoc = GPIOA;
  if (rtb_PulseGenerator != 0.0) {
    c = 32;
  } else {
    c = 0;
  }

  LL_GPIO_SetOutputPin(portNameLoc, (uint32_T)c);
  LL_GPIO_ResetOutputPin(portNameLoc, ~(uint32_T)c & 32U);

  /* End of MATLABSystem: '<S145>/Digital Port Write' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  Hallhardwaredebugslx_M->Timing.taskTime0 =
    ((time_T)(++Hallhardwaredebugslx_M->Timing.clockTick0)) *
    Hallhardwaredebugslx_M->Timing.stepSize0;
}

/* Model initialize function */
void Hallhardwaredebugslx_initialize(void)
{
  /* Registration code */
  rtmSetTFinal(Hallhardwaredebugslx_M, 10.0);
  Hallhardwaredebugslx_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  Hallhardwaredebugslx_M->Sizes.checksums[0] = (3832883500U);
  Hallhardwaredebugslx_M->Sizes.checksums[1] = (2439589992U);
  Hallhardwaredebugslx_M->Sizes.checksums[2] = (2205291357U);
  Hallhardwaredebugslx_M->Sizes.checksums[3] = (2813084949U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[98];
    Hallhardwaredebugslx_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC;
    systemRan[4] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof1_d.HallValueof1_SubsysRanBC;
    systemRan[5] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof2_b.HallValueof1_SubsysRanBC;
    systemRan[6] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof3_jh.HallValueof1_SubsysRanBC;
    systemRan[7] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof4_c.HallValueof1_SubsysRanBC;
    systemRan[8] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof5_p.HallValueof1_SubsysRanBC;
    systemRan[9] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof6_m.HallValueof1_SubsysRanBC;
    systemRan[10] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof7_i.HallValueof1_SubsysRanBC;
    systemRan[11] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.SpeedanddirectionarenotvalidPos;
    systemRan[12] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[13] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[14] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof1_h.HallValueof1_SubsysRanBC;
    systemRan[15] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof2_m.HallValueof1_SubsysRanBC;
    systemRan[16] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof3_j.HallValueof1_SubsysRanBC;
    systemRan[17] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof4_b.HallValueof1_SubsysRanBC;
    systemRan[18] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof5_i.HallValueof1_SubsysRanBC;
    systemRan[19] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof6_i.HallValueof1_SubsysRanBC;
    systemRan[20] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof7_g.HallValueof1_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.veDirection_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof1.HallValueof1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof2.HallValueof1_SubsysRanBC;
    systemRan[24] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof3.HallValueof1_SubsysRanBC;
    systemRan[25] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof4.HallValueof1_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof5.HallValueof1_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof6.HallValueof1_SubsysRanBC;
    systemRan[28] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.HallValueof7.HallValueof1_SubsysRanBC;
    systemRan[29] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.veDirection_SubsysRanBC_e;
    systemRan[30] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.first_order_SubsysRanBC;
    systemRan[31] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.second_order_SubsysRanBC;
    systemRan[32] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.Subsystem1_SubsysRanBC;
    systemRan[33] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.SpeedanddirectionarevalidUsespe;
    systemRan[34] = (sysRanDType *)&Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC;
    systemRan[36] = (sysRanDType *)&Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC;
    systemRan[38] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.Badhallglitchorwrongconnectio_g.Badhallglitchorwrongconnection_;
    systemRan[39] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[40] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[41] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[42] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[43] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[44] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[45] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[46] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[47] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.IfActionSubsystem8_SubsysRanBC;
    systemRan[48] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.SwitchCaseActionSubsystem_Subsy;
    systemRan[49] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.ValidHalls_SubsysRanBC;
    systemRan[50] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.ValidHalls_SubsysRanBC;
    systemRan[51] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_i.ValidHalls_SubsysRanBC;
    systemRan[52] = (sysRanDType *)&Hallhardwaredebugslx_DW.HA_SubsysRanBC;
    systemRan[53] = (sysRanDType *)&Hallhardwaredebugslx_DW.HA_SubsysRanBC;
    systemRan[54] = (sysRanDType *)&Hallhardwaredebugslx_DW.HA_SubsysRanBC;
    systemRan[55] = (sysRanDType *)&Hallhardwaredebugslx_DW.HA_SubsysRanBC;
    systemRan[56] = (sysRanDType *)&Hallhardwaredebugslx_DW.HA_SubsysRanBC;
    systemRan[57] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.Badhallglitchorwrongconnectio_d.Badhallglitchorwrongconnection_;
    systemRan[58] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[59] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[60] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[61] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[62] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[63] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[64] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[65] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[66] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.IfActionSubsystem8_SubsysRanBC;
    systemRan[67] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.SwitchCaseActionSubsystem_Subsy;
    systemRan[68] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.ValidHalls_SubsysRanBC;
    systemRan[69] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.ValidHalls_SubsysRanBC;
    systemRan[70] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls_f.ValidHalls_SubsysRanBC;
    systemRan[71] = (sysRanDType *)&Hallhardwaredebugslx_DW.HB_SubsysRanBC;
    systemRan[72] = (sysRanDType *)&Hallhardwaredebugslx_DW.HB_SubsysRanBC;
    systemRan[73] = (sysRanDType *)&Hallhardwaredebugslx_DW.HB_SubsysRanBC;
    systemRan[74] = (sysRanDType *)&Hallhardwaredebugslx_DW.HB_SubsysRanBC;
    systemRan[75] = (sysRanDType *)&Hallhardwaredebugslx_DW.HB_SubsysRanBC;
    systemRan[76] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.Badhallglitchorwrongconnectio_h.Badhallglitchorwrongconnection_;
    systemRan[77] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC;
    systemRan[78] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem1.IfActionSubsystem_SubsysRanBC;
    systemRan[79] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem2.IfActionSubsystem_SubsysRanBC;
    systemRan[80] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem3.IfActionSubsystem_SubsysRanBC;
    systemRan[81] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem4.IfActionSubsystem_SubsysRanBC;
    systemRan[82] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem5.IfActionSubsystem_SubsysRanBC;
    systemRan[83] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC;
    systemRan[84] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem7.IfActionSubsystem6_SubsysRanBC;
    systemRan[85] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC;
    systemRan[86] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy;
    systemRan[87] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[88] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[89] = (sysRanDType *)
      &Hallhardwaredebugslx_DW.ValidHalls.ValidHalls_SubsysRanBC;
    systemRan[90] = (sysRanDType *)&Hallhardwaredebugslx_DW.HC_SubsysRanBC;
    systemRan[91] = (sysRanDType *)&Hallhardwaredebugslx_DW.HC_SubsysRanBC;
    systemRan[92] = (sysRanDType *)&Hallhardwaredebugslx_DW.HC_SubsysRanBC;
    systemRan[93] = (sysRanDType *)&Hallhardwaredebugslx_DW.HC_SubsysRanBC;
    systemRan[94] = (sysRanDType *)&Hallhardwaredebugslx_DW.HC_SubsysRanBC;
    systemRan[95] = &rtAlwaysEnabled;
    systemRan[96] = &rtAlwaysEnabled;
    systemRan[97] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Hallhardwaredebugslx_M->extModeInfo,
      &Hallhardwaredebugslx_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Hallhardwaredebugslx_M->extModeInfo,
                        Hallhardwaredebugslx_M->Sizes.checksums);
    rteiSetTPtr(Hallhardwaredebugslx_M->extModeInfo, rtmGetTPtr
                (Hallhardwaredebugslx_M));
  }

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  Hallhardwaredebugslx_DW.GlobalHallState =
    Hallhardwaredebugslx_P.DataStoreMemory_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
  Hallhardwaredebugslx_DW.Timercntprev =
    Hallhardwaredebugslx_P.DataStoreMemory1_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory10' */
  Hallhardwaredebugslx_DW.HallCcapture =
    Hallhardwaredebugslx_P.DataStoreMemory10_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  Hallhardwaredebugslx_DW.Timehall =
    Hallhardwaredebugslx_P.DataStoreMemory3_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
  Hallhardwaredebugslx_DW.GlobalDirection =
    Hallhardwaredebugslx_P.DataStoreMemory5_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
  Hallhardwaredebugslx_DW.GlobalSpeedCount =
    Hallhardwaredebugslx_P.DataStoreMemory6_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
  Hallhardwaredebugslx_DW.GlobalSpeedValidity =
    Hallhardwaredebugslx_P.DataStoreMemory7_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory8' */
  Hallhardwaredebugslx_DW.HallStateChangeFlag =
    Hallhardwaredebugslx_P.DataStoreMemory8_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
  Hallhardwaredebugslx_DW.HallBcapture =
    Hallhardwaredebugslx_P.DataStoreMemory4_InitialValue;

  /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
  Hallhardwaredebugslx_DW.HallAcapture =
    Hallhardwaredebugslx_P.DataStoreMemory2_InitialValue;

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */

  /* System initialize for function-call system: '<Root>/ADC SIC' */
  Hallhardwaredebugslx_M->Timing.clockTick4 =
    Hallhardwaredebugslx_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S30>/validityDelay' */
  Hallhardwaredebugslx_DW.validityDelay_DSTATE =
    Hallhardwaredebugslx_P.validityDelay_InitialCondition;

  /* InitializeConditions for Delay: '<S30>/speedCountDelay' */
  Hallhardwaredebugslx_DW.speedCountDelay_DSTATE =
    Hallhardwaredebugslx_P.speedCountDelay_InitialConditio;

  /* InitializeConditions for RelationalOperator: '<S35>/Compare' incorporates:
   *  Delay: '<S31>/Delay One Step1'
   */
  Hallhardwaredebugslx_DW.DelayOneStep1_DSTATE =
    Hallhardwaredebugslx_P.DelayOneStep1_InitialCondition;

  /* InitializeConditions for Delay: '<S31>/Delay One Step' */
  Hallhardwaredebugslx_DW.DelayOneStep_DSTATE =
    Hallhardwaredebugslx_P.SoftwareWatchdogTimer_maxCount;

  /* Start for MATLABSystem: '<S16>/Analog to Digital Converter' */
  Hallhardwaredebugslx_DW.obj.isInitialized = 0;
  Hallhardwaredebugslx_DW.obj.matlabCodegenIsDeleted = false;
  Hallhardwar_SystemCore_setup_gg(&Hallhardwaredebugslx_DW.obj);

  /* Start for MATLABSystem: '<S20>/PWM Output' */
  Hallhardwaredebugslx_DW.obj_h.matlabCodegenIsDeleted = false;
  Hallhardwaredebugslx_DW.obj_h.isSetupComplete = false;
  Hallhardwaredebugslx_DW.obj_h.isInitialized = 1;
  Hallhardwar_PWMOutput_setupImpl(&Hallhardwaredebugslx_DW.obj_h);
  Hallhardwaredebugslx_DW.obj_h.isSetupComplete = true;

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HC'
   */
  /* System initialize for function-call system: '<Root>/HC' */
  Hallhardwaredebugslx_M->Timing.clockTick1 =
    Hallhardwaredebugslx_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S117>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE_m =
    Hallhardwaredebugslx_P.Delay_InitialCondition;

  /* SystemInitialize for IfAction SubSystem: '<S118>/Valid Halls' */
  Hallhardwaredeb_ValidHalls_Init(&Hallhardwaredebugslx_B.ValidHalls,
    &Hallhardwaredebugslx_P.ValidHalls);

  /* End of SystemInitialize for SubSystem: '<S118>/Valid Halls' */

  /* Start for MATLABSystem: '<S117>/Timer' */
  Hallhardwaredebugslx_DW.obj_etd.isInitialized = 0;
  Hallhardwaredebugslx_DW.obj_etd.matlabCodegenIsDeleted = false;
  Hallhardwarede_SystemCore_setup(&Hallhardwaredebugslx_DW.obj_etd);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HB'
   */
  /* System initialize for function-call system: '<Root>/HB' */
  Hallhardwaredebugslx_M->Timing.clockTick2 =
    Hallhardwaredebugslx_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S92>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE_b =
    Hallhardwaredebugslx_P.Delay_InitialCondition_j;

  /* SystemInitialize for IfAction SubSystem: '<S93>/Valid Halls' */
  Hallhardwaredeb_ValidHalls_Init(&Hallhardwaredebugslx_B.ValidHalls_f,
    &Hallhardwaredebugslx_P.ValidHalls_f);

  /* End of SystemInitialize for SubSystem: '<S93>/Valid Halls' */

  /* Start for MATLABSystem: '<S92>/Timer' */
  Hallhardwaredebugslx_DW.obj_et.isInitialized = 0;
  Hallhardwaredebugslx_DW.obj_et.matlabCodegenIsDeleted = false;
  Hallhardware_SystemCore_setup_i(&Hallhardwaredebugslx_DW.obj_et);

  /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HA'
   */

  /* System initialize for function-call system: '<Root>/HA' */
  Hallhardwaredebugslx_M->Timing.clockTick3 =
    Hallhardwaredebugslx_M->Timing.clockTick0;

  /* InitializeConditions for Delay: '<S67>/Delay' */
  Hallhardwaredebugslx_DW.Delay_DSTATE =
    Hallhardwaredebugslx_P.Delay_InitialCondition_n;

  /* SystemInitialize for IfAction SubSystem: '<S68>/Valid Halls' */
  Hallhardwaredeb_ValidHalls_Init(&Hallhardwaredebugslx_B.ValidHalls_i,
    &Hallhardwaredebugslx_P.ValidHalls_i);

  /* End of SystemInitialize for SubSystem: '<S68>/Valid Halls' */

  /* Start for MATLABSystem: '<S67>/Timer' */
  Hallhardwaredebugslx_DW.obj_e.isInitialized = 0;
  Hallhardwaredebugslx_DW.obj_e.matlabCodegenIsDeleted = false;
  Hallhardware_SystemCore_setup_g(&Hallhardwaredebugslx_DW.obj_e);

  /* End of SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

  /* SystemInitialize for Atomic SubSystem: '<Root>/Parameters' */
  /* Start for MATLABSystem: '<S148>/PWM Output' */
  Hallhardwaredebugslx_DW.obj_m.matlabCodegenIsDeleted = false;
  Hallhardwaredebugslx_DW.obj_m.isSetupComplete = false;
  Hallhardwaredebugslx_DW.obj_m.isInitialized = 1;
  Hallhardw_PWMOutput_setupImpl_f(&Hallhardwaredebugslx_DW.obj_m);
  Hallhardwaredebugslx_DW.obj_m.isSetupComplete = true;

  /* End of SystemInitialize for SubSystem: '<Root>/Parameters' */

  /* Outputs for Atomic SubSystem: '<Root>/Parameters' */
  /* MATLABSystem: '<S148>/PWM Output' incorporates:
   *  Constant: '<S8>/Constant1'
   */
  setDutyCycleInPercentageChannel1(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
    Hallhardwaredebugslx_P.Constant1_Value_a);
  setDutyCycleInPercentageChannel2(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
    Hallhardwaredebugslx_P.Constant1_Value_a);
  setDutyCycleInPercentageChannel3(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
    Hallhardwaredebugslx_P.Constant1_Value_a);

  /* End of Outputs for SubSystem: '<Root>/Parameters' */
}

/* Model terminate function */
void Hallhardwaredebugslx_terminate(void)
{
  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC SIC'
   */
  /* Termination for function-call system: '<Root>/ADC SIC' */

  /* Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */
  if (!Hallhardwaredebugslx_DW.obj.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj.isSetupComplete) {
      ADC_Handle_Deinit(Hallhardwaredebugslx_DW.obj.ADCHandle,
                        ADC_INTERRUPT_MODE, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S16>/Analog to Digital Converter' */

  /* Terminate for MATLABSystem: '<S20>/PWM Output' */
  if (!Hallhardwaredebugslx_DW.obj_h.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_h.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_h.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_h.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_h.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_h.TimerHandle, 0);
      disableTimerChannel1(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(Hallhardwaredebugslx_DW.obj_h.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S20>/PWM Output' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HC'
   */
  /* Termination for function-call system: '<Root>/HC' */

  /* Terminate for MATLABSystem: '<S117>/Timer' */
  if (!Hallhardwaredebugslx_DW.obj_etd.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_etd.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_etd.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_etd.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_etd.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_etd.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S117>/Timer' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HB'
   */
  /* Termination for function-call system: '<Root>/HB' */

  /* Terminate for MATLABSystem: '<S92>/Timer' */
  if (!Hallhardwaredebugslx_DW.obj_et.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_et.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_et.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_et.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_et.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_et.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S92>/Timer' */

  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/HA'
   */
  /* Termination for function-call system: '<Root>/HA' */

  /* Terminate for MATLABSystem: '<S67>/Timer' */
  if (!Hallhardwaredebugslx_DW.obj_e.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_e.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_e.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_e.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_e.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<S67>/Timer' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

  /* Terminate for Atomic SubSystem: '<Root>/Parameters' */
  /* Terminate for MATLABSystem: '<S148>/PWM Output' */
  if (!Hallhardwaredebugslx_DW.obj_m.matlabCodegenIsDeleted) {
    Hallhardwaredebugslx_DW.obj_m.matlabCodegenIsDeleted = true;
    if ((Hallhardwaredebugslx_DW.obj_m.isInitialized == 1) &&
        Hallhardwaredebugslx_DW.obj_m.isSetupComplete) {
      disableCounter(Hallhardwaredebugslx_DW.obj_m.TimerHandle);
      disableTimerInterrupts(Hallhardwaredebugslx_DW.obj_m.TimerHandle, 0);
      disableTimerChannel1(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel2(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
                           ENABLE_CH_CHN);
      disableTimerChannel3(Hallhardwaredebugslx_DW.obj_m.TimerHandle,
                           ENABLE_CH_CHN);
    }
  }

  /* End of Terminate for MATLABSystem: '<S148>/PWM Output' */
  /* End of Terminate for SubSystem: '<Root>/Parameters' */
}

void Hallhardwaredebugslx_configure_interrupts(void)
{
  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(33,&ADC_IRQHandler,2);
  MW_NVIC_EnableIRQ(33);

  /* Register interrupt service routine */
  MW_NVIC_ConfigureIRQ(55,&EXTI15_10_IRQHandler,2);
  MW_NVIC_EnableIRQ(55);
}

/* Hardware Interrupt Block: '<S141>/Hardware Interrupt' */
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
          (Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem6.IfActionSubsystem6_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem8_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (Hallhardwaredebugslx_DW.ValidHalls.IfActionSubsystem.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (Hallhardwaredebugslx_DW.ValidHalls.SwitchCaseActionSubsystem_Subsy);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.ValidHalls.ValidHalls_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC
          (Hallhardwaredebugslx_DW.Badhallglitchorwrongconnectio_h.Badhallglitchorwrongconnection_);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.HC_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HC' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;
          Hallhardwaredebugslx_M->Timing.clockTick1 =
            Hallhardwaredebugslx_M->Timing.clockTick0;

          /* MATLABSystem: '<S117>/Timer' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           */
          Hallhardwaredebugslx_DW.Timercntprev = getTimerCounterValue
            (Hallhardwaredebugslx_DW.obj_etd.TimerHandle);

          /* MATLABSystem: '<S135>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S137>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S139>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S116>/Sum' incorporates:
           *  Gain: '<S116>/Gain'
           *  Gain: '<S116>/Gain1'
           *  Gain: '<S116>/Gain2'
           *  MATLABSystem: '<S135>/Digital Port Read'
           *  MATLABSystem: '<S137>/Digital Port Read'
           *  MATLABSystem: '<S139>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Hallhardwaredebugslx_P.Gain_Gain_ea >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? Hallhardwaredebugslx_P.Gain1_Gain_e >>
             6 : 0)) + (uint32_T)((pinReadLoc_e & 4096U) != 0U ?
            Hallhardwaredebugslx_P.Gain2_Gain_d >> 7 : 0));

          /* SwitchCase: '<S115>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S115>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S118>/Valid Halls' incorporates:
             *  ActionPort: '<S120>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read'
             *  DataStoreRead: '<S4>/Data Store Read2'
             *  DataTypeConversion: '<S115>/Data Type Conversion2'
             */
            Hallhardwaredebugslx_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              Hallhardwaredebugslx_DW.GlobalHallState,
              Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
              &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
              &Hallhardwaredebugslx_B.ValidHalls,
              &Hallhardwaredebugslx_DW.ValidHalls,
              &Hallhardwaredebugslx_P.ValidHalls);

            /* End of Outputs for SubSystem: '<S118>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S118>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S119>/Action Port'
             */
            /* DataStoreWrite: '<S4>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S4>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
               &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
               &Hallhardwaredebugslx_P.Badhallglitchorwrongconnectio_h);

            /* End of Outputs for SubSystem: '<S118>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S115>/Detects if the halls reading is valid' */

          /* Gain: '<S4>/Gain' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  DataTypeConversion: '<S117>/Data Type Conversion'
           *  DataTypeConversion: '<S117>/Data Type Conversion1'
           *  Delay: '<S117>/Delay'
           *  Sum: '<S117>/Sum'
           */
          Hallhardwaredebugslx_DW.Timehall = (int64_T)((int32_T)
            Hallhardwaredebugslx_DW.Timercntprev - (int32_T)
            Hallhardwaredebugslx_DW.Delay_DSTATE_m) *
            Hallhardwaredebugslx_P.Gain_Gain_d;

          /* DataTypeConversion: '<S115>/counterSize' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write2'
           *  DataStoreWrite: '<S4>/Data Store Write7'
           *  Gain: '<S4>/Gain'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedCount = (uint32_T)
            (Hallhardwaredebugslx_DW.Timehall >> 30);

          /* DataTypeConversion: '<S118>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S4>/Data Store Write3'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S4>/Data Store Write4' incorporates:
           *  Constant: '<S115>/Constant'
           */
          Hallhardwaredebugslx_DW.HallStateChangeFlag =
            Hallhardwaredebugslx_P.Constant_Value_d;

          /* DataStoreWrite: '<S4>/Data Store Write6' */
          Hallhardwaredebugslx_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S4>/Data Store Write5' incorporates:
           *  Constant: '<S4>/Constant1'
           */
          Hallhardwaredebugslx_DW.HallCcapture =
            Hallhardwaredebugslx_P.Constant1_Value;

          /* Update for Delay: '<S117>/Delay' incorporates:
           *  DataStoreRead: '<S117>/Data Store Read1'
           */
          Hallhardwaredebugslx_DW.Delay_DSTATE_m =
            Hallhardwaredebugslx_DW.Timercntprev;
          Hallhardwaredebugslx_DW.HC_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((Hallhardwaredebugslx_M->Timing.clockTick1) * 0.1);
      extmodeEvent(1,currentTime);
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
        srClearBC(Hallhardwaredebugslx_DW.HB_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HB' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;
          Hallhardwaredebugslx_M->Timing.clockTick2 =
            Hallhardwaredebugslx_M->Timing.clockTick0;

          /* MATLABSystem: '<S92>/Timer' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           */
          Hallhardwaredebugslx_DW.Timercntprev = getTimerCounterValue
            (Hallhardwaredebugslx_DW.obj_et.TimerHandle);

          /* MATLABSystem: '<S110>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S112>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S114>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S91>/Sum' incorporates:
           *  Gain: '<S91>/Gain'
           *  Gain: '<S91>/Gain1'
           *  Gain: '<S91>/Gain2'
           *  MATLABSystem: '<S110>/Digital Port Read'
           *  MATLABSystem: '<S112>/Digital Port Read'
           *  MATLABSystem: '<S114>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Hallhardwaredebugslx_P.Gain_Gain_n >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? Hallhardwaredebugslx_P.Gain1_Gain_et
             >> 6 : 0)) + (uint32_T)((pinReadLoc_e & 4096U) != 0U ?
            Hallhardwaredebugslx_P.Gain2_Gain_g >> 7 : 0));

          /* SwitchCase: '<S90>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S90>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S93>/Valid Halls' incorporates:
             *  ActionPort: '<S95>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read'
             *  DataStoreRead: '<S3>/Data Store Read2'
             *  DataTypeConversion: '<S90>/Data Type Conversion2'
             */
            Hallhardwaredebugslx_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              Hallhardwaredebugslx_DW.GlobalHallState,
              Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
              &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
              &Hallhardwaredebugslx_B.ValidHalls_f,
              &Hallhardwaredebugslx_DW.ValidHalls_f,
              &Hallhardwaredebugslx_P.ValidHalls_f);

            /* End of Outputs for SubSystem: '<S93>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S93>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S94>/Action Port'
             */
            /* DataStoreWrite: '<S3>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S3>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
               &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
               &Hallhardwaredebugslx_P.Badhallglitchorwrongconnectio_d);

            /* End of Outputs for SubSystem: '<S93>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S90>/Detects if the halls reading is valid' */

          /* Gain: '<S3>/Gain' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  DataTypeConversion: '<S92>/Data Type Conversion'
           *  DataTypeConversion: '<S92>/Data Type Conversion1'
           *  Delay: '<S92>/Delay'
           *  Sum: '<S92>/Sum'
           */
          Hallhardwaredebugslx_DW.Timehall = (int64_T)((int32_T)
            Hallhardwaredebugslx_DW.Timercntprev - (int32_T)
            Hallhardwaredebugslx_DW.Delay_DSTATE_b) *
            Hallhardwaredebugslx_P.Gain_Gain_ei;

          /* DataTypeConversion: '<S90>/counterSize' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write2'
           *  DataStoreWrite: '<S3>/Data Store Write7'
           *  Gain: '<S3>/Gain'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedCount = (uint32_T)
            (Hallhardwaredebugslx_DW.Timehall >> 30);

          /* DataTypeConversion: '<S93>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S3>/Data Store Write3'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S3>/Data Store Write4' incorporates:
           *  Constant: '<S90>/Constant'
           */
          Hallhardwaredebugslx_DW.HallStateChangeFlag =
            Hallhardwaredebugslx_P.Constant_Value_o;

          /* DataStoreWrite: '<S3>/Data Store Write6' */
          Hallhardwaredebugslx_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S3>/Data Store Write5' incorporates:
           *  Constant: '<S3>/Constant1'
           */
          Hallhardwaredebugslx_DW.HallBcapture =
            Hallhardwaredebugslx_P.Constant1_Value_d;

          /* Update for Delay: '<S92>/Delay' incorporates:
           *  DataStoreRead: '<S92>/Data Store Read1'
           */
          Hallhardwaredebugslx_DW.Delay_DSTATE_b =
            Hallhardwaredebugslx_DW.Timercntprev;
          Hallhardwaredebugslx_DW.HB_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((Hallhardwaredebugslx_M->Timing.clockTick2) * 0.1);
      extmodeEvent(2,currentTime);
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
        srClearBC(Hallhardwaredebugslx_DW.HA_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/HA' */
        {
          uint32_T pinReadLoc;
          uint32_T pinReadLoc_e;
          uint32_T pinReadLoc_p;
          uint16_T rtb_Merge;
          uint8_T rtb_Hallsum;
          boolean_T rtb_Merge3;
          Hallhardwaredebugslx_M->Timing.clockTick3 =
            Hallhardwaredebugslx_M->Timing.clockTick0;

          /* MATLABSystem: '<S67>/Timer' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           */
          Hallhardwaredebugslx_DW.Timercntprev = getTimerCounterValue
            (Hallhardwaredebugslx_DW.obj_e.TimerHandle);

          /* MATLABSystem: '<S85>/Digital Port Read' */
          pinReadLoc = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S87>/Digital Port Read' */
          pinReadLoc_p = LL_GPIO_ReadInputPort(GPIOC);

          /* MATLABSystem: '<S89>/Digital Port Read' */
          pinReadLoc_e = LL_GPIO_ReadInputPort(GPIOC);

          /* Sum: '<S66>/Sum' incorporates:
           *  Gain: '<S66>/Gain'
           *  Gain: '<S66>/Gain1'
           *  Gain: '<S66>/Gain2'
           *  MATLABSystem: '<S85>/Digital Port Read'
           *  MATLABSystem: '<S87>/Digital Port Read'
           *  MATLABSystem: '<S89>/Digital Port Read'
           * */
          rtb_Hallsum = (uint8_T)(((uint32_T)((pinReadLoc & 1024U) != 0U ?
            Hallhardwaredebugslx_P.Gain_Gain_l >> 5 : 0) + (uint32_T)
            ((pinReadLoc_p & 2048U) != 0U ? Hallhardwaredebugslx_P.Gain1_Gain_jt
             >> 6 : 0)) + (uint32_T)((pinReadLoc_e & 4096U) != 0U ?
            Hallhardwaredebugslx_P.Gain2_Gain_h >> 7 : 0));

          /* SwitchCase: '<S65>/Detects if the halls reading is valid' incorporates:
           *  DataTypeConversion: '<S65>/Data Type Conversion1'
           */
          switch (rtb_Hallsum) {
           case 5:
           case 4:
           case 6:
           case 2:
           case 3:
           case 1:
            /* Outputs for IfAction SubSystem: '<S68>/Valid Halls' incorporates:
             *  ActionPort: '<S70>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read'
             *  DataStoreRead: '<S2>/Data Store Read2'
             *  DataTypeConversion: '<S65>/Data Type Conversion2'
             */
            Hallhardwaredebugslx_ValidHalls((uint16_T)rtb_Hallsum, (uint16_T)
              Hallhardwaredebugslx_DW.GlobalHallState,
              Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
              &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
              &Hallhardwaredebugslx_B.ValidHalls_i,
              &Hallhardwaredebugslx_DW.ValidHalls_i,
              &Hallhardwaredebugslx_P.ValidHalls_i);

            /* End of Outputs for SubSystem: '<S68>/Valid Halls' */
            break;

           default:
            /* Outputs for IfAction SubSystem: '<S68>/Bad hall (glitch or wrong connection)' incorporates:
             *  ActionPort: '<S69>/Action Port'
             */
            /* DataStoreWrite: '<S2>/Data Store Write1' incorporates:
             *  DataStoreRead: '<S2>/Data Store Read2'
             */
            Badhallglitchorwrongconnection
              (Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge,
               &Hallhardwaredebugslx_DW.GlobalDirection, &rtb_Merge3,
               &Hallhardwaredebugslx_P.Badhallglitchorwrongconnectio_g);

            /* End of Outputs for SubSystem: '<S68>/Bad hall (glitch or wrong connection)' */
            break;
          }

          /* End of SwitchCase: '<S65>/Detects if the halls reading is valid' */

          /* Gain: '<S2>/Gain' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  DataTypeConversion: '<S67>/Data Type Conversion'
           *  DataTypeConversion: '<S67>/Data Type Conversion1'
           *  Delay: '<S67>/Delay'
           *  Sum: '<S67>/Sum'
           */
          Hallhardwaredebugslx_DW.Timehall = (int64_T)((int32_T)
            Hallhardwaredebugslx_DW.Timercntprev - (int32_T)
            Hallhardwaredebugslx_DW.Delay_DSTATE) *
            Hallhardwaredebugslx_P.Gain_Gain_p;

          /* DataTypeConversion: '<S65>/counterSize' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write2'
           *  DataStoreWrite: '<S2>/Data Store Write7'
           *  Gain: '<S2>/Gain'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedCount = (uint32_T)
            (Hallhardwaredebugslx_DW.Timehall >> 30);

          /* DataTypeConversion: '<S68>/Data Type Conversion' incorporates:
           *  DataStoreWrite: '<S2>/Data Store Write3'
           */
          Hallhardwaredebugslx_DW.GlobalSpeedValidity = rtb_Merge3;

          /* DataStoreWrite: '<S2>/Data Store Write4' incorporates:
           *  Constant: '<S65>/Constant'
           */
          Hallhardwaredebugslx_DW.HallStateChangeFlag =
            Hallhardwaredebugslx_P.Constant_Value_oj;

          /* DataStoreWrite: '<S2>/Data Store Write6' */
          Hallhardwaredebugslx_DW.GlobalHallState = rtb_Hallsum;

          /* DataStoreWrite: '<S2>/Data Store Write5' incorporates:
           *  Constant: '<S2>/Constant1'
           */
          Hallhardwaredebugslx_DW.HallAcapture =
            Hallhardwaredebugslx_P.Constant1_Value_b;

          /* Update for Delay: '<S67>/Delay' incorporates:
           *  DataStoreRead: '<S67>/Data Store Read1'
           */
          Hallhardwaredebugslx_DW.Delay_DSTATE =
            Hallhardwaredebugslx_DW.Timercntprev;
          Hallhardwaredebugslx_DW.HA_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S141>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((Hallhardwaredebugslx_M->Timing.clockTick3) * 0.1);
      extmodeEvent(3,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

/* Hardware Interrupt Block: '<S143>/Hardware Interrupt' */
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
        srClearBC(Hallhardwaredebugslx_DW.IfActionSubsystem_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.IfActionSubsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.HallValueof1.HallValueof1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.veDirection_SubsysRanBC_e);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.veDirection_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.second_order_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.first_order_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.Subsystem1_SubsysRanBC);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.SpeedanddirectionarevalidUsespe);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.SpeedanddirectionarenotvalidPos);

        /* Reset subsysRan breadcrumbs */
        srClearBC(Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC);

        /* S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */

        /* Output and update for function-call system: '<Root>/ADC SIC' */
        {
          real_T rtb_Add1;
          real_T rtb_Add3;
          real_T rtb_Kc;
          real_T rtb_Max;
          real32_T rtb_Merge1_n;
          uint32_T u1;
          uint16_T tmp[3];
          uint16_T Switch;
          uint16_T rtb_watchdogcheck;
          boolean_T OR;
          Hallhardwaredebugslx_M->Timing.clockTick4 =
            Hallhardwaredebugslx_M->Timing.clockTick0;

          /* DataStoreRead: '<S28>/Data Store Read6' */
          rtb_watchdogcheck = Hallhardwaredebugslx_DW.HallStateChangeFlag;

          /* Switch: '<S29>/Switch' incorporates:
           *  Constant: '<S29>/WatchDog'
           *  DataStoreRead: '<S28>/Data Store Read6'
           *  DataStoreWrite: '<S28>/Data Store Write3'
           */
          if (Hallhardwaredebugslx_DW.HallStateChangeFlag != 0) {
            Hallhardwaredebugslx_DW.HallStateChangeFlag =
              Hallhardwaredebugslx_P.WatchDog_Value;
          }

          /* End of Switch: '<S29>/Switch' */

          /* Switch: '<S30>/Switch' incorporates:
           *  Constant: '<S30>/Order'
           */
          if (Hallhardwaredebugslx_P.Order_Value >
              Hallhardwaredebugslx_P.Switch_Threshold) {
            /* Switch: '<S30>/Switch' */
            Switch = rtb_watchdogcheck;
          } else {
            /* Switch: '<S30>/Switch' */
            Switch = Hallhardwaredebugslx_P.Order_Value;
          }

          /* End of Switch: '<S30>/Switch' */

          /* Delay: '<S30>/validityDelay' incorporates:
           *  Delay: '<S30>/speedCountDelay'
           */
          if (Switch != 0) {
            /* Delay: '<S30>/validityDelay' */
            Hallhardwaredebugslx_B.validityDelay =
              Hallhardwaredebugslx_DW.validityDelay_DSTATE;
          }

          /* End of Delay: '<S30>/validityDelay' */

          /* Logic: '<S31>/OR' incorporates:
           *  DataTypeConversion: '<S29>/Data Type Conversion4'
           *  Delay: '<S31>/Delay One Step1'
           */
          OR = (Hallhardwaredebugslx_DW.DelayOneStep1_DSTATE ||
                (rtb_watchdogcheck != 0));

          /* Delay: '<S31>/Delay One Step' incorporates:
           *  DataTypeConversion: '<S29>/Data Type Conversion4'
           */
          if (OR) {
            if (rtb_watchdogcheck != 0) {
              Hallhardwaredebugslx_DW.DelayOneStep_DSTATE =
                Hallhardwaredebugslx_P.SoftwareWatchdogTimer_maxCount;
            }

            /* Delay: '<S31>/Delay One Step' incorporates:
             *  DataTypeConversion: '<S29>/Data Type Conversion4'
             */
            Hallhardwaredebugslx_B.DelayOneStep =
              Hallhardwaredebugslx_DW.DelayOneStep_DSTATE;
          }

          /* End of Delay: '<S31>/Delay One Step' */

          /* RelationalOperator: '<S35>/Compare' incorporates:
           *  Constant: '<S35>/Constant'
           */
          Hallhardwaredebugslx_DW.DelayOneStep1_DSTATE =
            (Hallhardwaredebugslx_B.DelayOneStep >
             Hallhardwaredebugslx_P.Constant_Value_dj);

          /* Switch: '<S34>/watchdog check' incorporates:
           *  Constant: '<S34>/Constant'
           */
          if (Hallhardwaredebugslx_DW.DelayOneStep1_DSTATE) {
            /* DataTypeConversion: '<S29>/counterSize1' incorporates:
             *  DataStoreRead: '<S28>/Data Store Read'
             *  DataStoreRead: '<S28>/Data Store Read2'
             *  DataStoreRead: '<S28>/Data Store Read7'
             *  MinMax: '<S28>/Min'
             */
            rtb_Add3 = floor(fmin(fmin(Hallhardwaredebugslx_DW.HallAcapture,
              Hallhardwaredebugslx_DW.HallBcapture),
                                  Hallhardwaredebugslx_DW.HallCcapture));
            if (rtIsNaN(rtb_Add3) || rtIsInf(rtb_Add3)) {
              rtb_Add3 = 0.0;
            } else {
              rtb_Add3 = fmod(rtb_Add3, 4.294967296E+9);
            }

            u1 = rtb_Add3 < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-rtb_Add3 :
              (uint32_T)rtb_Add3;

            /* End of DataTypeConversion: '<S29>/counterSize1' */

            /* MinMax: '<S34>/Max' incorporates:
             *  DataStoreRead: '<S28>/Data Store Read3'
             */
            if (Hallhardwaredebugslx_DW.GlobalSpeedCount >= u1) {
              u1 = Hallhardwaredebugslx_DW.GlobalSpeedCount;
            }

            /* Switch: '<S34>/speed check' incorporates:
             *  Constant: '<S34>/Constant'
             *  DataStoreRead: '<S28>/Data Store Read5'
             *  DataTypeConversion: '<S30>/Data Type Conversion'
             *  Logic: '<S30>/Logical Operator'
             *  MinMax: '<S34>/Max'
             */
            if (u1 >= Hallhardwaredebugslx_P.speedcheck_Threshold) {
              rtb_watchdogcheck = Hallhardwaredebugslx_P.Constant_Value_p;
            } else {
              rtb_watchdogcheck = (uint16_T)
                ((Hallhardwaredebugslx_DW.GlobalSpeedValidity != 0) ||
                 Hallhardwaredebugslx_B.validityDelay);
            }

            /* End of Switch: '<S34>/speed check' */
          } else {
            rtb_watchdogcheck = Hallhardwaredebugslx_P.Constant_Value_p;
          }

          /* End of Switch: '<S34>/watchdog check' */

          /* If: '<S29>/If' incorporates:
           *  Constant: '<S33>/PositionEnable'
           */
          if (rtb_watchdogcheck != 0) {
            /* Outputs for IfAction SubSystem: '<S29>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S33>/Action Port'
             */
            /* If: '<S33>/If' incorporates:
             *  DataStoreRead: '<S28>/Data Store Read4'
             */
            if (Hallhardwaredebugslx_DW.GlobalDirection > 0) {
              /* Update for IfAction SubSystem: '<S33>/If Action Subsystem' incorporates:
               *  ActionPort: '<S44>/Action Port'
               */
              /* Update for If: '<S33>/If' */
              Hallhardwaredebugslx_DW.IfActionSubsystem_SubsysRanBC = 4;

              /* End of Update for SubSystem: '<S33>/If Action Subsystem' */
            } else {
              /* Update for IfAction SubSystem: '<S33>/If Action Subsystem1' incorporates:
               *  ActionPort: '<S45>/Action Port'
               */
              /* Update for If: '<S33>/If' */
              Hallhardwaredebugslx_DW.IfActionSubsystem1_SubsysRanBC = 4;

              /* End of Update for SubSystem: '<S33>/If Action Subsystem1' */
            }

            /* End of If: '<S33>/If' */

            /* Outputs for Enabled SubSystem: '<S33>/Subsystem1' incorporates:
             *  EnablePort: '<S46>/Enable'
             */
            if (Hallhardwaredebugslx_P.PositionEnable_Value > 0) {
              /* If: '<S46>/If1' incorporates:
               *  Constant: '<S46>/Constant'
               */
              if (Hallhardwaredebugslx_P.Constant_Value > 1.0) {
                /* Update for IfAction SubSystem: '<S46>/second_order' incorporates:
                 *  ActionPort: '<S50>/Action Port'
                 */
                /* Update for If: '<S46>/If1' */
                Hallhardwaredebugslx_DW.second_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S46>/second_order' */
              } else {
                /* Update for IfAction SubSystem: '<S46>/first_order' incorporates:
                 *  ActionPort: '<S49>/Action Port'
                 */
                /* Update for If: '<S46>/If1' */
                Hallhardwaredebugslx_DW.first_order_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S46>/first_order' */
              }

              /* End of If: '<S46>/If1' */

              /* If: '<S46>/If' incorporates:
               *  DataStoreRead: '<S28>/Data Store Read4'
               */
              if (Hallhardwaredebugslx_DW.GlobalDirection != 1) {
                /* Outputs for IfAction SubSystem: '<S46>/-ve Direction' incorporates:
                 *  ActionPort: '<S48>/Action Port'
                 */
                /* SwitchCase: '<S48>/Switch Case' incorporates:
                 *  DataStoreRead: '<S28>/Data Store Read1'
                 */
                switch (Hallhardwaredebugslx_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S58>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof1);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S59>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof2);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S60>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof3);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S61>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof4);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S62>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof5);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S63>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof6);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S48>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S64>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof7);

                  /* End of Outputs for SubSystem: '<S48>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S48>/Switch Case' */
                /* End of Outputs for SubSystem: '<S46>/-ve Direction' */

                /* Update for IfAction SubSystem: '<S46>/-ve Direction' incorporates:
                 *  ActionPort: '<S48>/Action Port'
                 */
                /* Update for If: '<S46>/If' */
                Hallhardwaredebugslx_DW.veDirection_SubsysRanBC_e = 4;

                /* End of Update for SubSystem: '<S46>/-ve Direction' */
              } else {
                /* Outputs for IfAction SubSystem: '<S46>/+ve Direction' incorporates:
                 *  ActionPort: '<S47>/Action Port'
                 */
                /* SwitchCase: '<S47>/Switch Case' incorporates:
                 *  DataStoreRead: '<S28>/Data Store Read1'
                 */
                switch (Hallhardwaredebugslx_DW.GlobalHallState) {
                 case 5:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 1' incorporates:
                   *  ActionPort: '<S51>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof1_h);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 1' */
                  break;

                 case 4:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 2' incorporates:
                   *  ActionPort: '<S52>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof2_m);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 2' */
                  break;

                 case 6:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 3' incorporates:
                   *  ActionPort: '<S53>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof3_j);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 3' */
                  break;

                 case 2:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 4' incorporates:
                   *  ActionPort: '<S54>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof4_b);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 4' */
                  break;

                 case 3:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 5' incorporates:
                   *  ActionPort: '<S55>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof5_i);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 5' */
                  break;

                 case 1:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 6' incorporates:
                   *  ActionPort: '<S56>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof6_i);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 6' */
                  break;

                 default:
                  /* Outputs for IfAction SubSystem: '<S47>/Hall Value of 7' incorporates:
                   *  ActionPort: '<S57>/Action Port'
                   */
                  Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                    &Hallhardwaredebugslx_P.HallValueof7_g);

                  /* End of Outputs for SubSystem: '<S47>/Hall Value of 7' */
                  break;
                }

                /* End of SwitchCase: '<S47>/Switch Case' */
                /* End of Outputs for SubSystem: '<S46>/+ve Direction' */

                /* Update for IfAction SubSystem: '<S46>/+ve Direction' incorporates:
                 *  ActionPort: '<S47>/Action Port'
                 */
                /* Update for If: '<S46>/If' */
                Hallhardwaredebugslx_DW.veDirection_SubsysRanBC = 4;

                /* End of Update for SubSystem: '<S46>/+ve Direction' */
              }

              /* End of If: '<S46>/If' */
              Hallhardwaredebugslx_DW.Subsystem1_SubsysRanBC = 4;
            }

            /* End of Outputs for SubSystem: '<S33>/Subsystem1' */
            /* End of Outputs for SubSystem: '<S29>/Speed and direction are valid Use speed to extrapolate position' */

            /* Update for IfAction SubSystem: '<S29>/Speed and direction are valid Use speed to extrapolate position' incorporates:
             *  ActionPort: '<S33>/Action Port'
             */
            /* Update for If: '<S29>/If' incorporates:
             *  Constant: '<S33>/PositionEnable'
             */
            Hallhardwaredebugslx_DW.SpeedanddirectionarevalidUsespe = 4;

            /* End of Update for SubSystem: '<S29>/Speed and direction are valid Use speed to extrapolate position' */
          } else {
            /* Outputs for IfAction SubSystem: '<S29>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S32>/Action Port'
             */
            /* SwitchCase: '<S36>/Switch Case' incorporates:
             *  DataStoreRead: '<S28>/Data Store Read1'
             */
            switch (Hallhardwaredebugslx_DW.GlobalHallState) {
             case 5:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 1' incorporates:
               *  ActionPort: '<S37>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof1_d);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 1' */
              break;

             case 4:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 2' incorporates:
               *  ActionPort: '<S38>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof2_b);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 2' */
              break;

             case 6:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 3' incorporates:
               *  ActionPort: '<S39>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof3_jh);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 3' */
              break;

             case 2:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 4' incorporates:
               *  ActionPort: '<S40>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof4_c);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 4' */
              break;

             case 3:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 5' incorporates:
               *  ActionPort: '<S41>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof5_p);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 5' */
              break;

             case 1:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 6' incorporates:
               *  ActionPort: '<S42>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof6_m);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 6' */
              break;

             default:
              /* Outputs for IfAction SubSystem: '<S36>/Hall Value of 7' incorporates:
               *  ActionPort: '<S43>/Action Port'
               */
              Hallhardwaredebugs_HallValueof1(&rtb_Merge1_n,
                &Hallhardwaredebugslx_P.HallValueof7_i);

              /* End of Outputs for SubSystem: '<S36>/Hall Value of 7' */
              break;
            }

            /* End of SwitchCase: '<S36>/Switch Case' */
            /* End of Outputs for SubSystem: '<S29>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */

            /* Update for IfAction SubSystem: '<S29>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' incorporates:
             *  ActionPort: '<S32>/Action Port'
             */
            /* Update for If: '<S29>/If' */
            Hallhardwaredebugslx_DW.SpeedanddirectionarenotvalidPos = 4;

            /* End of Update for SubSystem: '<S29>/Speed and direction are not valid Position will be set to the middle of the Hall quadrant' */
          }

          /* End of If: '<S29>/If' */

          /* MATLABSystem: '<S16>/Analog to Digital Converter' */
          injectedReadADCIntr(Hallhardwaredebugslx_DW.obj.ADCHandle, ADC_READ,
                              &tmp[0]);

          /* Gain: '<S27>/Ka' incorporates:
           *  Constant: '<S1>/Constant'
           */
          rtb_Add3 = Hallhardwaredebugslx_P.Ka_Gain *
            Hallhardwaredebugslx_P.Constant_Value_a;

          /* Gain: '<S27>/one_by_two' incorporates:
           *  Constant: '<S1>/Constant'
           */
          rtb_Max = Hallhardwaredebugslx_P.one_by_two_Gain *
            Hallhardwaredebugslx_P.Constant_Value_a;

          /* Gain: '<S27>/sqrt3_by_two' incorporates:
           *  Constant: '<S1>/Constant'
           */
          rtb_Kc = Hallhardwaredebugslx_P.sqrt3_by_two_Gain *
            Hallhardwaredebugslx_P.Constant_Value_a;

          /* Gain: '<S27>/Kb' incorporates:
           *  Sum: '<S27>/add_b'
           */
          rtb_Add1 = (rtb_Kc - rtb_Max) * Hallhardwaredebugslx_P.Kb_Gain;

          /* Gain: '<S27>/Kc' incorporates:
           *  Sum: '<S27>/add_c'
           */
          rtb_Kc = ((0.0 - rtb_Max) - rtb_Kc) * Hallhardwaredebugslx_P.Kc_Gain;

          /* Gain: '<S24>/one_by_two' incorporates:
           *  MinMax: '<S24>/Max'
           *  MinMax: '<S24>/Min'
           *  Sum: '<S24>/Add'
           */
          rtb_Max = (fmax(fmax(rtb_Add3, rtb_Add1), rtb_Kc) + fmin(fmin(rtb_Add3,
            rtb_Add1), rtb_Kc)) * Hallhardwaredebugslx_P.one_by_two_Gain_j;

          /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
           *  Gain: '<S1>/Gain'
           *  Gain: '<S23>/Gain'
           *  Sum: '<S23>/Add3'
           */
          rtb_Add3 = floor((rtb_Add3 + rtb_Max) *
                           Hallhardwaredebugslx_P.Gain_Gain *
                           Hallhardwaredebugslx_P.Gain_Gain_e);
          if (rtIsNaN(rtb_Add3) || rtIsInf(rtb_Add3)) {
            rtb_Add3 = 0.0;
          } else {
            rtb_Add3 = fmod(rtb_Add3, 65536.0);
          }

          /* MATLABSystem: '<S20>/PWM Output' incorporates:
           *  DataTypeConversion: '<S1>/Data Type Conversion'
           */
          setDutyCycleInPercentageChannel1
            (Hallhardwaredebugslx_DW.obj_h.TimerHandle, (int16_T)(rtb_Add3 < 0.0
              ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Add3 : (int32_T)
              (int16_T)(uint16_T)rtb_Add3));

          /* DataTypeConversion: '<S1>/Data Type Conversion1' incorporates:
           *  Gain: '<S1>/Gain1'
           *  Gain: '<S23>/Gain'
           *  Sum: '<S23>/Add1'
           */
          rtb_Add3 = floor((rtb_Add1 + rtb_Max) *
                           Hallhardwaredebugslx_P.Gain_Gain *
                           Hallhardwaredebugslx_P.Gain1_Gain);
          if (rtIsNaN(rtb_Add3) || rtIsInf(rtb_Add3)) {
            rtb_Add3 = 0.0;
          } else {
            rtb_Add3 = fmod(rtb_Add3, 65536.0);
          }

          /* MATLABSystem: '<S20>/PWM Output' incorporates:
           *  DataTypeConversion: '<S1>/Data Type Conversion1'
           */
          setDutyCycleInPercentageChannel2
            (Hallhardwaredebugslx_DW.obj_h.TimerHandle, (int16_T)(rtb_Add3 < 0.0
              ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Add3 : (int32_T)
              (int16_T)(uint16_T)rtb_Add3));

          /* DataTypeConversion: '<S1>/Data Type Conversion2' incorporates:
           *  Gain: '<S1>/Gain2'
           *  Gain: '<S23>/Gain'
           *  Sum: '<S23>/Add2'
           */
          rtb_Add3 = floor((rtb_Max + rtb_Kc) * Hallhardwaredebugslx_P.Gain_Gain
                           * Hallhardwaredebugslx_P.Gain2_Gain);
          if (rtIsNaN(rtb_Add3) || rtIsInf(rtb_Add3)) {
            rtb_Add3 = 0.0;
          } else {
            rtb_Add3 = fmod(rtb_Add3, 65536.0);
          }

          /* MATLABSystem: '<S20>/PWM Output' incorporates:
           *  DataTypeConversion: '<S1>/Data Type Conversion2'
           */
          setDutyCycleInPercentageChannel3
            (Hallhardwaredebugslx_DW.obj_h.TimerHandle, (int16_T)(rtb_Add3 < 0.0
              ? (int32_T)(int16_T)-(int16_T)(uint16_T)-rtb_Add3 : (int32_T)
              (int16_T)(uint16_T)rtb_Add3));

          /* Update for Delay: '<S30>/validityDelay' incorporates:
           *  DataStoreRead: '<S28>/Data Store Read3'
           *  DataStoreRead: '<S28>/Data Store Read5'
           *  DataTypeConversion: '<S30>/Data Type Conversion'
           *  Delay: '<S30>/speedCountDelay'
           */
          if (Switch != 0) {
            Hallhardwaredebugslx_DW.validityDelay_DSTATE =
              (Hallhardwaredebugslx_DW.GlobalSpeedValidity != 0);
            Hallhardwaredebugslx_DW.speedCountDelay_DSTATE =
              Hallhardwaredebugslx_DW.GlobalSpeedCount;
          }

          /* End of Update for Delay: '<S30>/validityDelay' */

          /* Update for Delay: '<S31>/Delay One Step' incorporates:
           *  Constant: '<S31>/Constant2'
           *  Sum: '<S31>/Sum'
           */
          if (OR) {
            Hallhardwaredebugslx_DW.DelayOneStep_DSTATE = (uint16_T)((uint32_T)
              Hallhardwaredebugslx_B.DelayOneStep -
              Hallhardwaredebugslx_P.Constant2_Value);
          }

          /* End of Update for Delay: '<S31>/Delay One Step' */
          Hallhardwaredebugslx_DW.ADCSIC_SubsysRanBC = 4;
        }

        /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S143>/Hardware Interrupt' */
      }

      currentTime = (extmodeSimulationTime_T)
        ((Hallhardwaredebugslx_M->Timing.clockTick4) * 0.1);
      extmodeEvent(4,currentTime);
    }
  }

  __ISB();
  __DSB();
  MW_HWI_UnMaskInterrupt(priority_mask);
}

void Hallhardwaredebugslx_unconfigure_interrupts (void)
{
  MW_NVIC_DisableIRQ(33);
  MW_NVIC_DisableIRQ(55);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
