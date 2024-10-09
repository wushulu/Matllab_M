/*
 * File: STMF4Hall_data.c
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

/* Block parameters (default storage) */
P_STMF4Hall_T STMF4Hall_P = {
  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S93>/FixPt Switch'
   */
  20000U,

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

  /* Expression: 0
   * Referenced by: '<S5>/Pos_PU'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<S10>/Constant1'
   */
  2.0,

  /* Expression: 60
   * Referenced by: '<S10>/Constant8'
   */
  60.0,

  /* Expression: 4
   * Referenced by: '<S10>/Constant2'
   */
  4.0,

  /* Expression: 180
   * Referenced by: '<S10>/Constant9'
   */
  180.0,

  /* Expression: 3
   * Referenced by: '<S10>/Constant3'
   */
  3.0,

  /* Expression: 120
   * Referenced by: '<S10>/Constant10'
   */
  120.0,

  /* Expression: 6
   * Referenced by: '<S10>/Constant4'
   */
  6.0,

  /* Expression: 300
   * Referenced by: '<S10>/Constant11'
   */
  300.0,

  /* Expression: 1
   * Referenced by: '<S10>/Constant5'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<S10>/Constant6'
   */
  5.0,

  /* Expression: 240
   * Referenced by: '<S10>/Constant14'
   */
  240.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant7'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant12'
   */
  0.0,

  /* Expression: 20
   * Referenced by: '<Root>/Constant'
   */
  20.0,

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

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  0U,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S4>/Out1'
   */
  0,

  /* Computed Parameter: Out1_Y0_h
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

  /* Computed Parameter: DataStoreMemory5_InitialValue
   * Referenced by: '<Root>/Data Store Memory5'
   */
  0,

  /* Computed Parameter: Constant_Value_fm
   * Referenced by: '<S63>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S38>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_bh
   * Referenced by: '<S13>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S93>/Constant'
   */
  0U,

  /* Computed Parameter: Out1_Y0_hj
   * Referenced by: '<S5>/Out1'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S92>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S89>/Output'
   */
  0U,

  /* Computed Parameter: DataStoreMemory6_InitialValue
   * Referenced by: '<Root>/Data Store Memory6'
   */
  0U,

  /* Computed Parameter: DataStoreMemory7_InitialValue
   * Referenced by: '<Root>/Data Store Memory7'
   */
  0U,

  /* Computed Parameter: DataStoreMemory8_InitialValue
   * Referenced by: '<Root>/Data Store Memory8'
   */
  0U,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S64>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_n
   * Referenced by: '<S39>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_a
   * Referenced by: '<S14>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S98>/Gain'
   */
  128U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S64>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_l
   * Referenced by: '<S39>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_i
   * Referenced by: '<S14>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_p
   * Referenced by: '<S98>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain2_Gain
   * Referenced by: '<S64>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_d
   * Referenced by: '<S39>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_f
   * Referenced by: '<S14>/Gain2'
   */
  128U,

  /* Computed Parameter: Gain2_Gain_n
   * Referenced by: '<S98>/Gain2'
   */
  128U,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<Root>/Data Store Memory'
   */
  0U,

  /* Start of '<S16>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S17>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S17>/Constant1'
     */
    false
  }
  ,

  /* End of '<S16>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S16>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S18>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S27>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S18>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S18>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S18>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_i
     * Referenced by: '<S18>/Constant'
     */
    false,

    /* Start of '<S68>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S24>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S24>/next'
       */
      5U
    }
    ,

    /* End of '<S68>/If Action Subsystem5' */

    /* Start of '<S68>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S23>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S23>/next'
       */
      1U
    }
    ,

    /* End of '<S68>/If Action Subsystem4' */

    /* Start of '<S68>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S22>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S22>/next'
       */
      3U
    }
    ,

    /* End of '<S68>/If Action Subsystem3' */

    /* Start of '<S68>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S21>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S21>/next'
       */
      2U
    }
    ,

    /* End of '<S68>/If Action Subsystem2' */

    /* Start of '<S68>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S20>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S20>/next'
       */
      6U
    }
    ,

    /* End of '<S68>/If Action Subsystem1' */

    /* Start of '<S68>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S19>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S19>/next'
       */
      4U
    }
    ,

    /* End of '<S68>/If Action Subsystem' */

    /* Start of '<S68>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S26>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S26>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S68>/If Action Subsystem7' */

    /* Start of '<S68>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S25>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S25>/Constant1'
       */
      0U
    }
    /* End of '<S68>/If Action Subsystem6' */
  }
  ,

  /* End of '<S16>/Valid Halls' */

  /* Start of '<S41>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S42>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S42>/Constant1'
     */
    false
  }
  ,

  /* End of '<S41>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S41>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S43>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S52>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S43>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S43>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S43>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_i
     * Referenced by: '<S43>/Constant'
     */
    false,

    /* Start of '<S68>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S49>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S49>/next'
       */
      5U
    }
    ,

    /* End of '<S68>/If Action Subsystem5' */

    /* Start of '<S68>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S48>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S48>/next'
       */
      1U
    }
    ,

    /* End of '<S68>/If Action Subsystem4' */

    /* Start of '<S68>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S47>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S47>/next'
       */
      3U
    }
    ,

    /* End of '<S68>/If Action Subsystem3' */

    /* Start of '<S68>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S46>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S46>/next'
       */
      2U
    }
    ,

    /* End of '<S68>/If Action Subsystem2' */

    /* Start of '<S68>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S45>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S45>/next'
       */
      6U
    }
    ,

    /* End of '<S68>/If Action Subsystem1' */

    /* Start of '<S68>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S44>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S44>/next'
       */
      4U
    }
    ,

    /* End of '<S68>/If Action Subsystem' */

    /* Start of '<S68>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S51>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S51>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S68>/If Action Subsystem7' */

    /* Start of '<S68>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S50>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S50>/Constant1'
       */
      0U
    }
    /* End of '<S68>/If Action Subsystem6' */
  }
  ,

  /* End of '<S41>/Valid Halls' */

  /* Start of '<S66>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S67>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S67>/Constant1'
     */
    false
  }
  ,

  /* End of '<S66>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S66>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S68>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S77>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S68>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S68>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S68>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_i
     * Referenced by: '<S68>/Constant'
     */
    false,

    /* Start of '<S68>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S74>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S74>/next'
       */
      5U
    }
    ,

    /* End of '<S68>/If Action Subsystem5' */

    /* Start of '<S68>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S73>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S73>/next'
       */
      1U
    }
    ,

    /* End of '<S68>/If Action Subsystem4' */

    /* Start of '<S68>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S72>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S72>/next'
       */
      3U
    }
    ,

    /* End of '<S68>/If Action Subsystem3' */

    /* Start of '<S68>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S71>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S71>/next'
       */
      2U
    }
    ,

    /* End of '<S68>/If Action Subsystem2' */

    /* Start of '<S68>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S70>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S70>/next'
       */
      6U
    }
    ,

    /* End of '<S68>/If Action Subsystem1' */

    /* Start of '<S68>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S69>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S69>/next'
       */
      4U
    }
    ,

    /* End of '<S68>/If Action Subsystem' */

    /* Start of '<S68>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S76>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S76>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S68>/If Action Subsystem7' */

    /* Start of '<S68>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S75>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S75>/Constant1'
       */
      0U
    }
    /* End of '<S68>/If Action Subsystem6' */
  }
  /* End of '<S66>/Valid Halls' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
