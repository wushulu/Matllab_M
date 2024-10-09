/*
 * File: STMF4Hall_data.c
 *
 * Code generated for Simulink model 'STMF4Hall'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct  8 09:01:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "STMF4Hall.h"

/* Block parameters (default storage) */
P_STMF4Hall_T STMF4Hall_P = {
  /* Mask Parameter: SoftwareWatchdogTimer_maxCount
   * Referenced by: '<S87>/Delay One Step'
   */
  2500U,

  /* Expression: EnableSecondOrder
   * Referenced by: '<S102>/Constant'
   */
  1.0,

  /* Expression: 3
   * Referenced by: '<S4>/Constant'
   */
  3.0,

  /* Expression: 2
   * Referenced by: '<S3>/Constant'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S2>/Constant'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S8>/Constant1'
   */
  2.0,

  /* Expression: 60
   * Referenced by: '<S8>/Constant8'
   */
  60.0,

  /* Expression: 4
   * Referenced by: '<S8>/Constant2'
   */
  4.0,

  /* Expression: 180
   * Referenced by: '<S8>/Constant9'
   */
  180.0,

  /* Expression: 3
   * Referenced by: '<S8>/Constant3'
   */
  3.0,

  /* Expression: 120
   * Referenced by: '<S8>/Constant10'
   */
  120.0,

  /* Expression: 6
   * Referenced by: '<S8>/Constant4'
   */
  6.0,

  /* Expression: 300
   * Referenced by: '<S8>/Constant11'
   */
  300.0,

  /* Expression: 1
   * Referenced by: '<S8>/Constant5'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<S8>/Constant6'
   */
  5.0,

  /* Expression: 240
   * Referenced by: '<S8>/Constant14'
   */
  240.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory5'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S8>/Constant12'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory4'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Pulse Generator'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<Root>/Pulse Generator'
   */
  10.0,

  /* Expression: 5
   * Referenced by: '<Root>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<Root>/Pulse Generator'
   */
  0.0,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S106>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S106>/Gain1'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S106>/Gain'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S105>/Gain'
   */
  0.5F,

  /* Expression: single(0.16667)
   * Referenced by: '<S102>/Saturation'
   */
  0.16667F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S102>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S102>/Merge'
   */
  0.0F,

  /* Expression: single(MinSpeed)
   * Referenced by: '<S89>/SpeedGain'
   */
  20.0F,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S88>/Constant'
   */
  0.0F,

  /* Expression: uint32(30*ClkFreq/(PolePairs*MinSpeed))
   * Referenced by: '<S89>/SpeedConst'
   */
  33750000U,

  /* Computed Parameter: speedcheck_Threshold
   * Referenced by: '<S90>/speed check'
   */
  33750000U,

  /* Computed Parameter: TmpRTBAtFunctionCallSubsystem1I
   * Referenced by:
   */
  0U,

  /* Computed Parameter: TmpRTBAtFunctionCallSubsystem2I
   * Referenced by:
   */
  0U,

  /* Computed Parameter: time3_InitialCondition
   * Referenced by:
   */
  0U,

  /* Computed Parameter: speedCountDelay_InitialConditio
   * Referenced by: '<S86>/speedCountDelay'
   */
  0U,

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  0U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S4>/Out1'
   */
  0,

  /* Computed Parameter: Out1_Y0_b
   * Referenced by: '<S3>/Out1'
   */
  0,

  /* Computed Parameter: Out1_Y0_l
   * Referenced by: '<S2>/Out1'
   */
  0,

  /* Computed Parameter: DataStoreMemory2_InitialValue
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0,

  /* Computed Parameter: PositionEnable_Value
   * Referenced by: '<S89>/PositionEnable'
   */
  1U,

  /* Computed Parameter: Constant_Value_np
   * Referenced by: '<S91>/Constant'
   */
  0U,

  /* Computed Parameter: Order_Value
   * Referenced by: '<S86>/Order'
   */
  0U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S86>/Switch'
   */
  0U,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S90>/Constant'
   */
  0U,

  /* Computed Parameter: Constant2_Value_m
   * Referenced by: '<S87>/Constant2'
   */
  1U,

  /* Computed Parameter: validityDelay_InitialCondition
   * Referenced by: '<S86>/validityDelay'
   */
  false,

  /* Computed Parameter: DelayOneStep1_InitialCondition
   * Referenced by: '<S87>/Delay One Step1'
   */
  true,

  /* Computed Parameter: Gain_Gain_g
   * Referenced by: '<S62>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_h
   * Referenced by: '<S37>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_a
   * Referenced by: '<S12>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S123>/Gain'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_c
   * Referenced by: '<S62>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_d
   * Referenced by: '<S37>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_i
   * Referenced by: '<S12>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_p
   * Referenced by: '<S123>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S62>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_m
   * Referenced by: '<S37>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_f
   * Referenced by: '<S12>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_n
   * Referenced by: '<S123>/Gain2'
   */
  128U,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<Root>/Data Store Memory'
   */
  0U,

  /* Start of '<S14>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S15>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S15>/Constant1'
     */
    false
  }
  ,

  /* End of '<S14>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S14>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S16>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S25>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S16>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S16>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S16>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_j
     * Referenced by: '<S16>/Constant'
     */
    false,

    /* Start of '<S66>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S22>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S22>/next'
       */
      5U
    }
    ,

    /* End of '<S66>/If Action Subsystem5' */

    /* Start of '<S66>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S21>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S21>/next'
       */
      1U
    }
    ,

    /* End of '<S66>/If Action Subsystem4' */

    /* Start of '<S66>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S20>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S20>/next'
       */
      3U
    }
    ,

    /* End of '<S66>/If Action Subsystem3' */

    /* Start of '<S66>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S19>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S19>/next'
       */
      2U
    }
    ,

    /* End of '<S66>/If Action Subsystem2' */

    /* Start of '<S66>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S18>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S18>/next'
       */
      6U
    }
    ,

    /* End of '<S66>/If Action Subsystem1' */

    /* Start of '<S66>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S17>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S17>/next'
       */
      4U
    }
    ,

    /* End of '<S66>/If Action Subsystem' */

    /* Start of '<S66>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S24>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S24>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S66>/If Action Subsystem7' */

    /* Start of '<S66>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S23>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S23>/Constant1'
       */
      0U
    }
    /* End of '<S66>/If Action Subsystem6' */
  }
  ,

  /* End of '<S14>/Valid Halls' */

  /* Start of '<S39>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S40>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S40>/Constant1'
     */
    false
  }
  ,

  /* End of '<S39>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S39>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S41>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S50>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S41>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S41>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S41>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_j
     * Referenced by: '<S41>/Constant'
     */
    false,

    /* Start of '<S66>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S47>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S47>/next'
       */
      5U
    }
    ,

    /* End of '<S66>/If Action Subsystem5' */

    /* Start of '<S66>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S46>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S46>/next'
       */
      1U
    }
    ,

    /* End of '<S66>/If Action Subsystem4' */

    /* Start of '<S66>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S45>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S45>/next'
       */
      3U
    }
    ,

    /* End of '<S66>/If Action Subsystem3' */

    /* Start of '<S66>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S44>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S44>/next'
       */
      2U
    }
    ,

    /* End of '<S66>/If Action Subsystem2' */

    /* Start of '<S66>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S43>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S43>/next'
       */
      6U
    }
    ,

    /* End of '<S66>/If Action Subsystem1' */

    /* Start of '<S66>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S42>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S42>/next'
       */
      4U
    }
    ,

    /* End of '<S66>/If Action Subsystem' */

    /* Start of '<S66>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S49>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S49>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S66>/If Action Subsystem7' */

    /* Start of '<S66>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S48>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S48>/Constant1'
       */
      0U
    }
    /* End of '<S66>/If Action Subsystem6' */
  }
  ,

  /* End of '<S39>/Valid Halls' */

  /* Start of '<S64>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S65>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S65>/Constant1'
     */
    false
  }
  ,

  /* End of '<S64>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S64>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S66>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S75>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S66>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S66>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S66>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_j
     * Referenced by: '<S66>/Constant'
     */
    false,

    /* Start of '<S66>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S72>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S72>/next'
       */
      5U
    }
    ,

    /* End of '<S66>/If Action Subsystem5' */

    /* Start of '<S66>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S71>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S71>/next'
       */
      1U
    }
    ,

    /* End of '<S66>/If Action Subsystem4' */

    /* Start of '<S66>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S70>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S70>/next'
       */
      3U
    }
    ,

    /* End of '<S66>/If Action Subsystem3' */

    /* Start of '<S66>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S69>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S69>/next'
       */
      2U
    }
    ,

    /* End of '<S66>/If Action Subsystem2' */

    /* Start of '<S66>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S68>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S68>/next'
       */
      6U
    }
    ,

    /* End of '<S66>/If Action Subsystem1' */

    /* Start of '<S66>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S67>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S67>/next'
       */
      4U
    }
    ,

    /* End of '<S66>/If Action Subsystem' */

    /* Start of '<S66>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S74>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S74>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S66>/If Action Subsystem7' */

    /* Start of '<S66>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S73>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S73>/Constant1'
       */
      0U
    }
    /* End of '<S66>/If Action Subsystem6' */
  }
  ,

  /* End of '<S64>/Valid Halls' */

  /* Start of '<S92>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S99>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S92>/Hall Value of 7' */

  /* Start of '<S92>/Hall Value of 6' */
  {
    /* Expression: single(0.91667)
     * Referenced by: '<S98>/Constant'
     */
    0.91667F
  }
  ,

  /* End of '<S92>/Hall Value of 6' */

  /* Start of '<S92>/Hall Value of 5' */
  {
    /* Expression: single(0.75)
     * Referenced by: '<S97>/Constant'
     */
    0.75F
  }
  ,

  /* End of '<S92>/Hall Value of 5' */

  /* Start of '<S92>/Hall Value of 4' */
  {
    /* Expression: single(0.58333)
     * Referenced by: '<S96>/Constant'
     */
    0.58333F
  }
  ,

  /* End of '<S92>/Hall Value of 4' */

  /* Start of '<S92>/Hall Value of 3' */
  {
    /* Expression: single(0.41667)
     * Referenced by: '<S95>/Constant'
     */
    0.41667F
  }
  ,

  /* End of '<S92>/Hall Value of 3' */

  /* Start of '<S92>/Hall Value of 2' */
  {
    /* Expression: single(0.25)
     * Referenced by: '<S94>/Constant'
     */
    0.25F
  }
  ,

  /* End of '<S92>/Hall Value of 2' */

  /* Start of '<S92>/Hall Value of 1' */
  {
    /* Expression: single(0.083333)
     * Referenced by: '<S93>/Constant'
     */
    0.083333F
  }
  ,

  /* End of '<S92>/Hall Value of 1' */

  /* Start of '<S103>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S113>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S103>/Hall Value of 7' */

  /* Start of '<S103>/Hall Value of 6' */
  {
    /* Expression: single(0.83333)
     * Referenced by: '<S112>/Constant'
     */
    0.83333F
  }
  ,

  /* End of '<S103>/Hall Value of 6' */

  /* Start of '<S103>/Hall Value of 5' */
  {
    /* Expression: single(0.66667)
     * Referenced by: '<S111>/Constant'
     */
    0.66667F
  }
  ,

  /* End of '<S103>/Hall Value of 5' */

  /* Start of '<S103>/Hall Value of 4' */
  {
    /* Expression: single(0.5)
     * Referenced by: '<S110>/Constant'
     */
    0.5F
  }
  ,

  /* End of '<S103>/Hall Value of 4' */

  /* Start of '<S103>/Hall Value of 3' */
  {
    /* Expression: single(0.33333)
     * Referenced by: '<S109>/Constant'
     */
    0.33333F
  }
  ,

  /* End of '<S103>/Hall Value of 3' */

  /* Start of '<S103>/Hall Value of 2' */
  {
    /* Expression: single(0.16667)
     * Referenced by: '<S108>/Constant'
     */
    0.16667F
  }
  ,

  /* End of '<S103>/Hall Value of 2' */

  /* Start of '<S103>/Hall Value of 1' */
  {
    /* Expression: single(0)
     * Referenced by: '<S107>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S103>/Hall Value of 1' */

  /* Start of '<S104>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S120>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S104>/Hall Value of 7' */

  /* Start of '<S104>/Hall Value of 6' */
  {
    /* Expression: single(1)
     * Referenced by: '<S119>/Constant'
     */
    1.0F
  }
  ,

  /* End of '<S104>/Hall Value of 6' */

  /* Start of '<S104>/Hall Value of 5' */
  {
    /* Expression: single(0.83333)
     * Referenced by: '<S118>/Constant'
     */
    0.83333F
  }
  ,

  /* End of '<S104>/Hall Value of 5' */

  /* Start of '<S104>/Hall Value of 4' */
  {
    /* Expression: single(0.66667)
     * Referenced by: '<S117>/Constant'
     */
    0.66667F
  }
  ,

  /* End of '<S104>/Hall Value of 4' */

  /* Start of '<S104>/Hall Value of 3' */
  {
    /* Expression: single(0.5)
     * Referenced by: '<S116>/Constant'
     */
    0.5F
  }
  ,

  /* End of '<S104>/Hall Value of 3' */

  /* Start of '<S104>/Hall Value of 2' */
  {
    /* Expression: single(0.33333)
     * Referenced by: '<S115>/Constant'
     */
    0.33333F
  }
  ,

  /* End of '<S104>/Hall Value of 2' */

  /* Start of '<S104>/Hall Value of 1' */
  {
    /* Expression: single(0.16667)
     * Referenced by: '<S114>/Constant'
     */
    0.16667F
  }
  /* End of '<S104>/Hall Value of 1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
