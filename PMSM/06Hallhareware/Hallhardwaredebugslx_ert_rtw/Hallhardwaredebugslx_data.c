/*
 * File: Hallhardwaredebugslx_data.c
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

/* Block parameters (default storage) */
P_Hallhardwaredebugslx_T Hallhardwaredebugslx_P = {
  /* Mask Parameter: SoftwareWatchdogTimer_maxCount
   * Referenced by: '<S31>/Delay One Step'
   */
  5000U,

  /* Expression: 0
   * Referenced by: '<S4>/Constant1'
   */
  0.0,

  /* Expression: 100
   * Referenced by: '<S3>/Constant1'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S2>/Constant1'
   */
  100.0,

  /* Expression: EnableSecondOrder
   * Referenced by: '<S46>/Constant'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Constant'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S27>/Ka'
   */
  1.0,

  /* Expression: 1/2
   * Referenced by: '<S27>/one_by_two'
   */
  0.5,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S27>/sqrt3_by_two'
   */
  0.8660254037844386,

  /* Expression: 1
   * Referenced by: '<S27>/Kb'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S27>/Kc'
   */
  1.0,

  /* Expression: -0.5
   * Referenced by: '<S24>/one_by_two'
   */
  -0.5,

  /* Expression: 2/sqrt(3)
   * Referenced by: '<S23>/Gain'
   */
  1.1547005383792517,

  /* Expression: 100
   * Referenced by: '<S1>/Gain'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S1>/Gain1'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S1>/Gain2'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S8>/Constant1'
   */
  10.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory9'
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

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S4>/Out1'
   */
  (0LL),

  /* Computed Parameter: Out1_Y0_p
   * Referenced by: '<S3>/Out1'
   */
  (0LL),

  /* Computed Parameter: Out1_Y0_g
   * Referenced by: '<S2>/Out1'
   */
  (0LL),

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  (0LL),

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S4>/Gain'
   */
  1073741824,

  /* Computed Parameter: Gain_Gain_ei
   * Referenced by: '<S3>/Gain'
   */
  1073741824,

  /* Computed Parameter: Gain_Gain_p
   * Referenced by: '<S2>/Gain'
   */
  1073741824,

  /* Computed Parameter: Constant_Value_a1
   * Referenced by: '<S50>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain1_Gain_j
   * Referenced by: '<S50>/Gain1'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S50>/Gain'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain_d0
   * Referenced by: '<S49>/Gain'
   */
  0.5F,

  /* Expression: single(0.16667)
   * Referenced by: '<S46>/Saturation'
   */
  0.16667F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S46>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S46>/Merge'
   */
  0.0F,

  /* Expression: single(6*MinSpeed)
   * Referenced by: '<S33>/SpeedGain'
   */
  120.0F,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S32>/Constant'
   */
  0.0F,

  /* Computed Parameter: Posdegree_Y0
   * Referenced by: '<S1>/Posdegree'
   */
  0.0F,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S117>/Delay'
   */
  0U,

  /* Computed Parameter: Delay_InitialCondition_j
   * Referenced by: '<S92>/Delay'
   */
  0U,

  /* Computed Parameter: Delay_InitialCondition_n
   * Referenced by: '<S67>/Delay'
   */
  0U,

  /* Expression: uint32(30*ClkFreq/(PolePairs*MinSpeed))
   * Referenced by: '<S33>/SpeedConst'
   */
  63000000U,

  /* Computed Parameter: speedcheck_Threshold
   * Referenced by: '<S34>/speed check'
   */
  63000000U,

  /* Computed Parameter: speedCountDelay_InitialConditio
   * Referenced by: '<S30>/speedCountDelay'
   */
  0U,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0U,

  /* Computed Parameter: DataStoreMemory6_InitialValue
   * Referenced by: '<Root>/Data Store Memory6'
   */
  0U,

  /* Computed Parameter: DataStoreMemory5_InitialValue
   * Referenced by: '<Root>/Data Store Memory5'
   */
  0,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S115>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S90>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_oj
   * Referenced by: '<S65>/Constant'
   */
  1U,

  /* Computed Parameter: PositionEnable_Value
   * Referenced by: '<S33>/PositionEnable'
   */
  1U,

  /* Computed Parameter: WatchDog_Value
   * Referenced by: '<S29>/WatchDog'
   */
  0U,

  /* Computed Parameter: ct_Y0
   * Referenced by: '<S1>/ct'
   */
  0U,

  /* Computed Parameter: Constant_Value_dj
   * Referenced by: '<S35>/Constant'
   */
  0U,

  /* Computed Parameter: Order_Value
   * Referenced by: '<S30>/Order'
   */
  0U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S30>/Switch'
   */
  0U,

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S34>/Constant'
   */
  0U,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S31>/Constant2'
   */
  1U,

  /* Computed Parameter: DataStoreMemory7_InitialValue
   * Referenced by: '<Root>/Data Store Memory7'
   */
  0U,

  /* Computed Parameter: DataStoreMemory8_InitialValue
   * Referenced by: '<Root>/Data Store Memory8'
   */
  0U,

  /* Computed Parameter: validityDelay_InitialCondition
   * Referenced by: '<S30>/validityDelay'
   */
  false,

  /* Computed Parameter: DelayOneStep1_InitialCondition
   * Referenced by: '<S31>/Delay One Step1'
   */
  true,

  /* Computed Parameter: Gain_Gain_ea
   * Referenced by: '<S116>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_n
   * Referenced by: '<S91>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_l
   * Referenced by: '<S66>/Gain'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_e
   * Referenced by: '<S116>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_et
   * Referenced by: '<S91>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_jt
   * Referenced by: '<S66>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_d
   * Referenced by: '<S116>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_g
   * Referenced by: '<S91>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_h
   * Referenced by: '<S66>/Gain2'
   */
  128U,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<Root>/Data Store Memory'
   */
  0U,

  /* Start of '<S36>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S43>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S36>/Hall Value of 7' */

  /* Start of '<S36>/Hall Value of 6' */
  {
    /* Expression: single(0.91667)
     * Referenced by: '<S42>/Constant'
     */
    0.91667F
  }
  ,

  /* End of '<S36>/Hall Value of 6' */

  /* Start of '<S36>/Hall Value of 5' */
  {
    /* Expression: single(0.75)
     * Referenced by: '<S41>/Constant'
     */
    0.75F
  }
  ,

  /* End of '<S36>/Hall Value of 5' */

  /* Start of '<S36>/Hall Value of 4' */
  {
    /* Expression: single(0.58333)
     * Referenced by: '<S40>/Constant'
     */
    0.58333F
  }
  ,

  /* End of '<S36>/Hall Value of 4' */

  /* Start of '<S36>/Hall Value of 3' */
  {
    /* Expression: single(0.41667)
     * Referenced by: '<S39>/Constant'
     */
    0.41667F
  }
  ,

  /* End of '<S36>/Hall Value of 3' */

  /* Start of '<S36>/Hall Value of 2' */
  {
    /* Expression: single(0.25)
     * Referenced by: '<S38>/Constant'
     */
    0.25F
  }
  ,

  /* End of '<S36>/Hall Value of 2' */

  /* Start of '<S36>/Hall Value of 1' */
  {
    /* Expression: single(0.083333)
     * Referenced by: '<S37>/Constant'
     */
    0.083333F
  }
  ,

  /* End of '<S36>/Hall Value of 1' */

  /* Start of '<S47>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S57>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S47>/Hall Value of 7' */

  /* Start of '<S47>/Hall Value of 6' */
  {
    /* Expression: single(0.83333)
     * Referenced by: '<S56>/Constant'
     */
    0.83333F
  }
  ,

  /* End of '<S47>/Hall Value of 6' */

  /* Start of '<S47>/Hall Value of 5' */
  {
    /* Expression: single(0.66667)
     * Referenced by: '<S55>/Constant'
     */
    0.66667F
  }
  ,

  /* End of '<S47>/Hall Value of 5' */

  /* Start of '<S47>/Hall Value of 4' */
  {
    /* Expression: single(0.5)
     * Referenced by: '<S54>/Constant'
     */
    0.5F
  }
  ,

  /* End of '<S47>/Hall Value of 4' */

  /* Start of '<S47>/Hall Value of 3' */
  {
    /* Expression: single(0.33333)
     * Referenced by: '<S53>/Constant'
     */
    0.33333F
  }
  ,

  /* End of '<S47>/Hall Value of 3' */

  /* Start of '<S47>/Hall Value of 2' */
  {
    /* Expression: single(0.16667)
     * Referenced by: '<S52>/Constant'
     */
    0.16667F
  }
  ,

  /* End of '<S47>/Hall Value of 2' */

  /* Start of '<S47>/Hall Value of 1' */
  {
    /* Expression: single(0)
     * Referenced by: '<S51>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S47>/Hall Value of 1' */

  /* Start of '<S48>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S64>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S48>/Hall Value of 7' */

  /* Start of '<S48>/Hall Value of 6' */
  {
    /* Expression: single(1)
     * Referenced by: '<S63>/Constant'
     */
    1.0F
  }
  ,

  /* End of '<S48>/Hall Value of 6' */

  /* Start of '<S48>/Hall Value of 5' */
  {
    /* Expression: single(0.83333)
     * Referenced by: '<S62>/Constant'
     */
    0.83333F
  }
  ,

  /* End of '<S48>/Hall Value of 5' */

  /* Start of '<S48>/Hall Value of 4' */
  {
    /* Expression: single(0.66667)
     * Referenced by: '<S61>/Constant'
     */
    0.66667F
  }
  ,

  /* End of '<S48>/Hall Value of 4' */

  /* Start of '<S48>/Hall Value of 3' */
  {
    /* Expression: single(0.5)
     * Referenced by: '<S60>/Constant'
     */
    0.5F
  }
  ,

  /* End of '<S48>/Hall Value of 3' */

  /* Start of '<S48>/Hall Value of 2' */
  {
    /* Expression: single(0.33333)
     * Referenced by: '<S59>/Constant'
     */
    0.33333F
  }
  ,

  /* End of '<S48>/Hall Value of 2' */

  /* Start of '<S48>/Hall Value of 1' */
  {
    /* Expression: single(0.16667)
     * Referenced by: '<S58>/Constant'
     */
    0.16667F
  }
  ,

  /* End of '<S48>/Hall Value of 1' */

  /* Start of '<S68>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S69>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S69>/Constant1'
     */
    false
  }
  ,

  /* End of '<S68>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S68>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S70>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S79>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S70>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S70>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S70>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_d
     * Referenced by: '<S70>/Constant'
     */
    false,

    /* Start of '<S120>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S76>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S76>/next'
       */
      5U
    }
    ,

    /* End of '<S120>/If Action Subsystem5' */

    /* Start of '<S120>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S75>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S75>/next'
       */
      1U
    }
    ,

    /* End of '<S120>/If Action Subsystem4' */

    /* Start of '<S120>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S74>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S74>/next'
       */
      3U
    }
    ,

    /* End of '<S120>/If Action Subsystem3' */

    /* Start of '<S120>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S73>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S73>/next'
       */
      2U
    }
    ,

    /* End of '<S120>/If Action Subsystem2' */

    /* Start of '<S120>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S72>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S72>/next'
       */
      6U
    }
    ,

    /* End of '<S120>/If Action Subsystem1' */

    /* Start of '<S120>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S71>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S71>/next'
       */
      4U
    }
    ,

    /* End of '<S120>/If Action Subsystem' */

    /* Start of '<S120>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S78>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S78>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S120>/If Action Subsystem7' */

    /* Start of '<S120>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S77>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S77>/Constant1'
       */
      0U
    }
    /* End of '<S120>/If Action Subsystem6' */
  }
  ,

  /* End of '<S68>/Valid Halls' */

  /* Start of '<S93>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S94>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S94>/Constant1'
     */
    false
  }
  ,

  /* End of '<S93>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S93>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S95>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S104>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S95>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S95>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S95>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_d
     * Referenced by: '<S95>/Constant'
     */
    false,

    /* Start of '<S120>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S101>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S101>/next'
       */
      5U
    }
    ,

    /* End of '<S120>/If Action Subsystem5' */

    /* Start of '<S120>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S100>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S100>/next'
       */
      1U
    }
    ,

    /* End of '<S120>/If Action Subsystem4' */

    /* Start of '<S120>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S99>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S99>/next'
       */
      3U
    }
    ,

    /* End of '<S120>/If Action Subsystem3' */

    /* Start of '<S120>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S98>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S98>/next'
       */
      2U
    }
    ,

    /* End of '<S120>/If Action Subsystem2' */

    /* Start of '<S120>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S97>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S97>/next'
       */
      6U
    }
    ,

    /* End of '<S120>/If Action Subsystem1' */

    /* Start of '<S120>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S96>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S96>/next'
       */
      4U
    }
    ,

    /* End of '<S120>/If Action Subsystem' */

    /* Start of '<S120>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S103>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S103>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S120>/If Action Subsystem7' */

    /* Start of '<S120>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S102>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S102>/Constant1'
       */
      0U
    }
    /* End of '<S120>/If Action Subsystem6' */
  }
  ,

  /* End of '<S93>/Valid Halls' */

  /* Start of '<S118>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S119>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S119>/Constant1'
     */
    false
  }
  ,

  /* End of '<S118>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S118>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S120>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S129>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S120>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S120>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S120>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_d
     * Referenced by: '<S120>/Constant'
     */
    false,

    /* Start of '<S120>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S126>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S126>/next'
       */
      5U
    }
    ,

    /* End of '<S120>/If Action Subsystem5' */

    /* Start of '<S120>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S125>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S125>/next'
       */
      1U
    }
    ,

    /* End of '<S120>/If Action Subsystem4' */

    /* Start of '<S120>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S124>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S124>/next'
       */
      3U
    }
    ,

    /* End of '<S120>/If Action Subsystem3' */

    /* Start of '<S120>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S123>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S123>/next'
       */
      2U
    }
    ,

    /* End of '<S120>/If Action Subsystem2' */

    /* Start of '<S120>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S122>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S122>/next'
       */
      6U
    }
    ,

    /* End of '<S120>/If Action Subsystem1' */

    /* Start of '<S120>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S121>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S121>/next'
       */
      4U
    }
    ,

    /* End of '<S120>/If Action Subsystem' */

    /* Start of '<S120>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S128>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S128>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S120>/If Action Subsystem7' */

    /* Start of '<S120>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S127>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S127>/Constant1'
       */
      0U
    }
    /* End of '<S120>/If Action Subsystem6' */
  }
  /* End of '<S118>/Valid Halls' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
