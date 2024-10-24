/*
 * File: G431Hallcorrection_data.c
 *
 * Code generated for Simulink model 'G431Hallcorrection'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Oct 24 14:38:06 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G431Hallcorrection.h"

/* Block parameters (default storage) */
P_G431Hallcorrection_T G431Hallcorrection_P = {
  /* Mask Parameter: PLLwithFeedForward_BlkSampleTim
   * Referenced by:
   *   '<S230>/Integral Gain'
   *   '<S254>/Gain1'
   *   '<S255>/Gain1'
   *   '<S279>/Gain1'
   *   '<S279>/Gain2'
   *   '<S280>/Gain1'
   *   '<S280>/Gain2'
   *   '<S287>/Gain1'
   *   '<S288>/Gain1'
   *   '<S300>/Gain'
   */
  5.0E-5,

  /* Mask Parameter: PLLwithFeedForward_FreqRatio
   * Referenced by: '<S300>/Gain'
   */
  1.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S233>/Integrator'
   */
  0.0,

  /* Mask Parameter: PLLwithFeedForward_Ki
   * Referenced by: '<S230>/Integral Gain'
   */
  222066.099,

  /* Mask Parameter: PLLwithFeedForward_Kp
   * Referenced by: '<S238>/Proportional Gain'
   */
  942.4778,

  /* Mask Parameter: PLLwithFeedForward_MaximumAppli
   * Referenced by:
   *   '<S252>/Switch1'
   *   '<S254>/Gain'
   *   '<S254>/Gain1'
   *   '<S255>/Gain'
   *   '<S255>/Gain1'
   *   '<S279>/Gain1'
   *   '<S279>/Gain2'
   *   '<S280>/Gain1'
   *   '<S280>/Gain2'
   *   '<S287>/Gain'
   *   '<S287>/Gain1'
   *   '<S288>/Gain'
   *   '<S288>/Gain1'
   */
  7500.0,

  /* Mask Parameter: CompareToConstant2_const
   * Referenced by: '<S271>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S270>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant4_const
   * Referenced by: '<S272>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S269>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant5_const
   * Referenced by: '<S273>/Constant'
   */
  0.0,

  /* Mask Parameter: CompareToConstant_const_o
   * Referenced by: '<S71>/Constant'
   */
  0.01F,

  /* Mask Parameter: CompareToConstant1_const_d
   * Referenced by: '<S72>/Constant'
   */
  0.99F,

  /* Mask Parameter: Comparespeedlowthan20RPM_const
   * Referenced by: '<S97>/Constant'
   */
  120.0F,

  /* Mask Parameter: SpeedFeedforward_SpeedCompMetho
   * Referenced by: '<S192>/Constant'
   */
  3U,

  /* Mask Parameter: Disablehostafter42seconds_const
   * Referenced by: '<S20>/Constant'
   */
  420000U,

  /* Mask Parameter: EnablePWMfor40seconds_const
   * Referenced by: '<S21>/Constant'
   */
  400000U,

  /* Mask Parameter: SoftwareWatchdogTimer_maxCount
   * Referenced by: '<S32>/Delay One Step'
   */
  5000U,

  /* Expression: EnableSecondOrder
   * Referenced by: '<S47>/Constant'
   */
  1.0,

  /* Expression: 0.5
   * Referenced by: '<S68>/Constant1'
   */
  0.5,

  /* Expression: 100
   * Referenced by: '<S68>/Gain1'
   */
  100.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  0.001,

  /* Expression: 1
   * Referenced by: '<S1>/Constant1'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S3>/Constant2'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S2>/Constant2'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<S4>/Constant2'
   */
  100.0,

  /* Expression: 0
   * Referenced by: '<S251>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S251>/One'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S251>/FilterConstant'
   */
  0.0046902865258454489,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S251>/OneMinusFilterConstant'
   */
  0.99530971347415453,

  /* Expression: 0
   * Referenced by: '<S256>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S256>/One'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S256>/FilterConstant'
   */
  0.95928661170794782,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S256>/OneMinusFilterConstant'
   */
  0.040713388292052177,

  /* Expression: 0
   * Referenced by: '<S257>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S257>/One'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S257>/FilterConstant'
   */
  0.00094159036806203958,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S257>/OneMinusFilterConstant'
   */
  0.99905840963193793,

  /* Expression: 0
   * Referenced by: '<S258>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S258>/One'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S258>/FilterConstant'
   */
  0.95928661170794782,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S258>/OneMinusFilterConstant'
   */
  0.040713388292052177,

  /* Expression: 1
   * Referenced by: '<S259>/Constant'
   */
  1.0,

  /* Expression: -1
   * Referenced by: '<S259>/Constant1'
   */
  -1.0,

  /* Expression: 0.0
   * Referenced by: '<S254>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S254>/Delay3'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S258>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S258>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S268>/Unit Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S255>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S255>/Delay3'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S256>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S256>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S262>/Unit Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S259>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S259>/Delay1'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S257>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S257>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S265>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S250>/Switch1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S277>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S277>/One'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S277>/FilterConstant'
   */
  0.95928661170794782,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S277>/OneMinusFilterConstant'
   */
  0.040713388292052177,

  /* Expression: 0
   * Referenced by: '<S278>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S278>/One'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S278>/FilterConstant'
   */
  0.95928661170794782,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S278>/OneMinusFilterConstant'
   */
  0.040713388292052177,

  /* Expression: 0
   * Referenced by: '<S252>/Constant'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S278>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S278>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S286>/Unit Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S279>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S279>/Delay'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S277>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S277>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S283>/Unit Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S280>/Delay1'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S280>/Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S289>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S289>/One'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S289>/FilterConstant'
   */
  0.95928661170794782,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S289>/OneMinusFilterConstant'
   */
  0.040713388292052177,

  /* Expression: 0
   * Referenced by: '<S290>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S290>/One'
   */
  1.0,

  /* Expression: Filter_constant
   * Referenced by: '<S290>/FilterConstant'
   */
  0.95928661170794782,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S290>/OneMinusFilterConstant'
   */
  0.040713388292052177,

  /* Expression: 0.0
   * Referenced by: '<S287>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S287>/Delay3'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S290>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S290>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S296>/Unit Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S288>/Delay2'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S288>/Delay3'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S289>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S289>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S293>/Unit Delay'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S304>/Out1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S303>/theta_e'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory9'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S193>/Constant'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S300>/Delay'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S233>/Integrator'
   */
  1.0,

  /* Expression: [0]
   * Referenced by: '<S192>/Merge'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S251>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S251>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S276>/Unit Delay'
   */
  0.0,

  /* Expression: 1/dlgSett.scale
   * Referenced by: '<S301>/scaleIn'
   */
  1.0,

  /* Expression: dlgSett.PhaseOffset
   * Referenced by: '<S301>/Unit Delay'
   */
  0.0,

  /* Expression: dlgSett.scale
   * Referenced by: '<S301>/scaleOut'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S7>/Pulse Generator'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S7>/Pulse Generator'
   */
  10.0,

  /* Expression: 5
   * Referenced by: '<S7>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S7>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory10'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory4'
   */
  0.0,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S25>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_g
   * Referenced by: '<S26>/Constant1'
   */
  0.0002F,

  /* Computed Parameter: Delay_InitialCondition_g
   * Referenced by: '<S26>/Delay'
   */
  0.0F,

  /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
   * Referenced by: '<S26>/Saturate to 'motor.calibSpeed' RPM'
   */
  8.0F,

  /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
   * Referenced by: '<S26>/Saturate to 'motor.calibSpeed' RPM'
   */
  0.0F,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<S26>/Multiply'
   */
  0.0001F,

  /* Computed Parameter: Out1_Y0_a
   * Referenced by: '<S29>/Out1'
   */
  0.0F,

  /* Computed Parameter: theta_e_Y0_a
   * Referenced by: '<S28>/theta_e'
   */
  0.0F,

  /* Computed Parameter: Theta_Y0
   * Referenced by: '<S18>/Theta'
   */
  0.0F,

  /* Computed Parameter: scaleIn_Gain_n
   * Referenced by: '<S27>/scaleIn'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_a
   * Referenced by: '<S27>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: scaleOut_Gain_p
   * Referenced by: '<S27>/scaleOut'
   */
  1.0F,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S51>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain1_Gain_k
   * Referenced by: '<S51>/Gain1'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S51>/Gain'
   */
  0.166666672F,

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S50>/Gain'
   */
  0.166666672F,

  /* Expression: single(0.16667)
   * Referenced by: '<S47>/Saturation'
   */
  0.16667F,

  /* Computed Parameter: Saturation_LowerSat
   * Referenced by: '<S47>/Saturation'
   */
  0.0F,

  /* Computed Parameter: Merge_InitialOutput_g
   * Referenced by: '<S47>/Merge'
   */
  0.0F,

  /* Expression: single(6*MinSpeed)
   * Referenced by: '<S34>/SpeedGain'
   */
  120.0F,

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S33>/Constant'
   */
  0.0F,

  /* Computed Parameter: a_Value_g
   * Referenced by: '<S74>/a'
   */
  0.0F,

  /* Computed Parameter: One_Value_mb
   * Referenced by: '<S74>/One'
   */
  1.0F,

  /* Computed Parameter: FilterConstant_Value_f
   * Referenced by: '<S74>/FilterConstant'
   */
  0.5F,

  /* Computed Parameter: OneMinusFilterConstant_Value_kk
   * Referenced by: '<S74>/OneMinusFilterConstant'
   */
  0.5F,

  /* Computed Parameter: Offset_Y0
   * Referenced by: '<S73>/Offset'
   */
  0.0F,

  /* Computed Parameter: UseInputPort_Value_d
   * Referenced by: '<S74>/UseInputPort'
   */
  1.0F,

  /* Computed Parameter: Switch1_Threshold_pw
   * Referenced by: '<S74>/Switch1'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_lw
   * Referenced by: '<S77>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Delay_InitialCondition_bx
   * Referenced by: '<S66>/Delay'
   */
  0.0F,

  /* Computed Parameter: sqrt3_by_two_Gain
   * Referenced by: '<S96>/sqrt3_by_two'
   */
  0.866025388F,

  /* Computed Parameter: one_by_two_Gain
   * Referenced by: '<S96>/one_by_two'
   */
  0.5F,

  /* Computed Parameter: Kc_Gain
   * Referenced by: '<S96>/Kc'
   */
  1.0F,

  /* Computed Parameter: Kb_Gain
   * Referenced by: '<S96>/Kb'
   */
  1.0F,

  /* Computed Parameter: Ka_Gain
   * Referenced by: '<S96>/Ka'
   */
  1.0F,

  /* Computed Parameter: one_by_two_Gain_k
   * Referenced by: '<S93>/one_by_two'
   */
  -0.5F,

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S92>/Gain'
   */
  1.15470052F,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S68>/Gain'
   */
  0.5F,

  /* Computed Parameter: Offset_Y0_c
   * Referenced by: '<S69>/Offset'
   */
  0.0F,

  /* Computed Parameter: poswlfilter_Y0
   * Referenced by: '<S98>/poswlfilter'
   */
  0.0F,

  /* Computed Parameter: Delay_InitialCondition_l3
   * Referenced by: '<S98>/Delay'
   */
  0.0F,

  /* Computed Parameter: Delay1_InitialCondition_f
   * Referenced by: '<S98>/Delay1'
   */
  0.0F,

  /* Computed Parameter: Delay2_InitialCondition_bu
   * Referenced by: '<S98>/Delay2'
   */
  0.0F,

  /* Computed Parameter: Delay3_InitialCondition_a
   * Referenced by: '<S98>/Delay3'
   */
  0.0F,

  /* Computed Parameter: Delay4_InitialCondition
   * Referenced by: '<S98>/Delay4'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_da
   * Referenced by: '<S98>/Gain'
   */
  0.166666672F,

  /* Computed Parameter: a_Value_h
   * Referenced by: '<S99>/a'
   */
  0.0F,

  /* Computed Parameter: One_Value_c
   * Referenced by: '<S99>/One'
   */
  1.0F,

  /* Computed Parameter: FilterConstant_Value_i
   * Referenced by: '<S99>/FilterConstant'
   */
  0.001F,

  /* Computed Parameter: OneMinusFilterConstant_Value_ar
   * Referenced by: '<S99>/OneMinusFilterConstant'
   */
  0.999F,

  /* Computed Parameter: a_Value_k
   * Referenced by: '<S100>/a'
   */
  0.0F,

  /* Computed Parameter: One_Value_ay
   * Referenced by: '<S100>/One'
   */
  1.0F,

  /* Computed Parameter: FilterConstant_Value_a
   * Referenced by: '<S100>/FilterConstant'
   */
  0.003F,

  /* Computed Parameter: OneMinusFilterConstant_Value_d
   * Referenced by: '<S100>/OneMinusFilterConstant'
   */
  0.997F,

  /* Computed Parameter: PWM_Y0
   * Referenced by: '<S1>/PWM'
   */
  0.0F,

  /* Computed Parameter: Theta_Y0_d
   * Referenced by: '<S1>/Theta'
   */
  0.0F,

  /* Computed Parameter: intedegree_Y0
   * Referenced by: '<S1>/intedegree'
   */
  0.0F,

  /* Computed Parameter: poswlfilter_Y0_c
   * Referenced by: '<S1>/poswlfilter'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S80>/Constant'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  60.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
   * Referenced by: '<S19>/Discrete-Time Integrator'
   */
  -60.0F,

  /* Computed Parameter: Merge_InitialOutput_p
   * Referenced by: '<S30>/Merge'
   */
  0.0F,

  /* Expression: single(360)
   * Referenced by: '<S30>/PositionUnit'
   */
  360.0F,

  /* Computed Parameter: Vd_Ref_Value
   * Referenced by: '<S70>/Vd_Ref'
   */
  0.0F,

  /* Computed Parameter: Vq_Value
   * Referenced by: '<S70>/Vq'
   */
  0.22F,

  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S67>/sine_table_values'
   */
  { 0.0F, 0.00785390101F, 0.0157073177F, 0.023559764F, 0.0314107575F,
    0.0392598175F, 0.0471064523F, 0.0549501814F, 0.0627905205F, 0.070626989F,
    0.0784591F, 0.086286366F, 0.0941083133F, 0.101924457F, 0.109734312F,
    0.117537394F, 0.125333235F, 0.133121341F, 0.140901238F, 0.148672432F,
    0.156434461F, 0.16418685F, 0.171929106F, 0.179660752F, 0.187381312F,
    0.195090324F, 0.202787295F, 0.210471764F, 0.21814324F, 0.225801274F,
    0.233445361F, 0.241075054F, 0.24868989F, 0.256289363F, 0.263873041F,
    0.271440446F, 0.278991103F, 0.286524564F, 0.294040322F, 0.301537961F,
    0.309017F, 0.316476971F, 0.323917419F, 0.331337899F, 0.338737935F,
    0.346117049F, 0.353474855F, 0.360810816F, 0.368124545F, 0.375415564F,
    0.382683426F, 0.389927685F, 0.397147894F, 0.404343605F, 0.411514372F,
    0.418659747F, 0.425779283F, 0.432872593F, 0.439939171F, 0.446978629F,
    0.453990489F, 0.460974365F, 0.46792981F, 0.474856377F, 0.481753677F,
    0.488621235F, 0.495458663F, 0.502265513F, 0.509041429F, 0.515785873F,
    0.522498548F, 0.529179F, 0.535826802F, 0.542441547F, 0.549022794F,
    0.555570245F, 0.562083364F, 0.568561852F, 0.575005233F, 0.581413209F,
    0.587785244F, 0.594121039F, 0.600420237F, 0.60668236F, 0.612907052F,
    0.619093955F, 0.625242651F, 0.631352782F, 0.637424F, 0.643455863F,
    0.649448037F, 0.655400157F, 0.661311865F, 0.667182744F, 0.673012495F,
    0.678800762F, 0.684547126F, 0.690251231F, 0.695912778F, 0.70153141F,
    0.707106769F, 0.712638497F, 0.718126297F, 0.723569751F, 0.72896862F,
    0.734322488F, 0.739631116F, 0.744894F, 0.750111043F, 0.755281806F,
    0.760405958F, 0.765483201F, 0.770513237F, 0.775495768F, 0.780430436F,
    0.785316944F, 0.790155F, 0.794944346F, 0.799684644F, 0.804375648F, 0.809017F,
    0.813608468F, 0.818149745F, 0.822640538F, 0.827080548F, 0.831469595F,
    0.835807383F, 0.840093553F, 0.844327927F, 0.848510206F, 0.852640152F,
    0.856717527F, 0.860742033F, 0.86471343F, 0.868631542F, 0.872496F,
    0.876306653F, 0.880063295F, 0.883765638F, 0.887413442F, 0.891006529F,
    0.894544661F, 0.898027599F, 0.901455104F, 0.904827058F, 0.908143163F,
    0.911403298F, 0.914607167F, 0.91775465F, 0.920845509F, 0.923879504F,
    0.926856577F, 0.92977649F, 0.932639F, 0.935444057F, 0.938191354F,
    0.940880775F, 0.943512142F, 0.946085334F, 0.948600173F, 0.95105654F,
    0.953454196F, 0.955793F, 0.958072901F, 0.96029371F, 0.962455213F,
    0.964557409F, 0.96660012F, 0.968583167F, 0.970506489F, 0.972369909F,
    0.974173367F, 0.975916743F, 0.977599919F, 0.979222834F, 0.980785251F,
    0.982287228F, 0.983728647F, 0.985109329F, 0.986429274F, 0.987688363F,
    0.988886476F, 0.990023673F, 0.991099775F, 0.992114723F, 0.993068457F,
    0.993961F, 0.994792163F, 0.995561957F, 0.996270359F, 0.996917307F,
    0.997502804F, 0.998026729F, 0.998489082F, 0.998889863F, 0.999229F,
    0.999506533F, 0.999722421F, 0.999876618F, 0.999969184F, 1.0F, 0.999969184F,
    0.999876618F, 0.999722421F, 0.999506533F, 0.999229F, 0.998889863F,
    0.998489082F, 0.998026729F, 0.997502804F, 0.996917307F, 0.996270359F,
    0.995561957F, 0.994792163F, 0.993961F, 0.993068457F, 0.992114723F,
    0.991099775F, 0.990023673F, 0.988886476F, 0.987688363F, 0.986429274F,
    0.985109329F, 0.983728647F, 0.982287228F, 0.980785251F, 0.979222834F,
    0.977599919F, 0.975916743F, 0.974173367F, 0.972369909F, 0.970506489F,
    0.968583167F, 0.96660012F, 0.964557409F, 0.962455213F, 0.96029371F,
    0.958072901F, 0.955793F, 0.953454196F, 0.95105654F, 0.948600173F,
    0.946085334F, 0.943512142F, 0.940880775F, 0.938191354F, 0.935444057F,
    0.932639F, 0.92977649F, 0.926856577F, 0.923879504F, 0.920845509F,
    0.91775465F, 0.914607167F, 0.911403298F, 0.908143163F, 0.904827058F,
    0.901455104F, 0.898027599F, 0.894544661F, 0.891006529F, 0.887413442F,
    0.883765638F, 0.880063295F, 0.876306653F, 0.872496F, 0.868631542F,
    0.86471343F, 0.860742033F, 0.856717527F, 0.852640152F, 0.848510206F,
    0.844327927F, 0.840093553F, 0.835807383F, 0.831469595F, 0.827080548F,
    0.822640538F, 0.818149745F, 0.813608468F, 0.809017F, 0.804375648F,
    0.799684644F, 0.794944346F, 0.790155F, 0.785316944F, 0.780430436F,
    0.775495768F, 0.770513237F, 0.765483201F, 0.760405958F, 0.755281806F,
    0.750111043F, 0.744894F, 0.739631116F, 0.734322488F, 0.72896862F,
    0.723569751F, 0.718126297F, 0.712638497F, 0.707106769F, 0.70153141F,
    0.695912778F, 0.690251231F, 0.684547126F, 0.678800762F, 0.673012495F,
    0.667182744F, 0.661311865F, 0.655400157F, 0.649448037F, 0.643455863F,
    0.637424F, 0.631352782F, 0.625242651F, 0.619093955F, 0.612907052F,
    0.60668236F, 0.600420237F, 0.594121039F, 0.587785244F, 0.581413209F,
    0.575005233F, 0.568561852F, 0.562083364F, 0.555570245F, 0.549022794F,
    0.542441547F, 0.535826802F, 0.529179F, 0.522498548F, 0.515785873F,
    0.509041429F, 0.502265513F, 0.495458663F, 0.488621235F, 0.481753677F,
    0.474856377F, 0.46792981F, 0.460974365F, 0.453990489F, 0.446978629F,
    0.439939171F, 0.432872593F, 0.425779283F, 0.418659747F, 0.411514372F,
    0.404343605F, 0.397147894F, 0.389927685F, 0.382683426F, 0.375415564F,
    0.368124545F, 0.360810816F, 0.353474855F, 0.346117049F, 0.338737935F,
    0.331337899F, 0.323917419F, 0.316476971F, 0.309017F, 0.301537961F,
    0.294040322F, 0.286524564F, 0.278991103F, 0.271440446F, 0.263873041F,
    0.256289363F, 0.24868989F, 0.241075054F, 0.233445361F, 0.225801274F,
    0.21814324F, 0.210471764F, 0.202787295F, 0.195090324F, 0.187381312F,
    0.179660752F, 0.171929106F, 0.16418685F, 0.156434461F, 0.148672432F,
    0.140901238F, 0.133121341F, 0.125333235F, 0.117537394F, 0.109734312F,
    0.101924457F, 0.0941083133F, 0.086286366F, 0.0784591F, 0.070626989F,
    0.0627905205F, 0.0549501814F, 0.0471064523F, 0.0392598175F, 0.0314107575F,
    0.023559764F, 0.0157073177F, 0.00785390101F, 1.22464685E-16F,
    -0.00785390101F, -0.0157073177F, -0.023559764F, -0.0314107575F,
    -0.0392598175F, -0.0471064523F, -0.0549501814F, -0.0627905205F,
    -0.070626989F, -0.0784591F, -0.086286366F, -0.0941083133F, -0.101924457F,
    -0.109734312F, -0.117537394F, -0.125333235F, -0.133121341F, -0.140901238F,
    -0.148672432F, -0.156434461F, -0.16418685F, -0.171929106F, -0.179660752F,
    -0.187381312F, -0.195090324F, -0.202787295F, -0.210471764F, -0.21814324F,
    -0.225801274F, -0.233445361F, -0.241075054F, -0.24868989F, -0.256289363F,
    -0.263873041F, -0.271440446F, -0.278991103F, -0.286524564F, -0.294040322F,
    -0.301537961F, -0.309017F, -0.316476971F, -0.323917419F, -0.331337899F,
    -0.338737935F, -0.346117049F, -0.353474855F, -0.360810816F, -0.368124545F,
    -0.375415564F, -0.382683426F, -0.389927685F, -0.397147894F, -0.404343605F,
    -0.411514372F, -0.418659747F, -0.425779283F, -0.432872593F, -0.439939171F,
    -0.446978629F, -0.453990489F, -0.460974365F, -0.46792981F, -0.474856377F,
    -0.481753677F, -0.488621235F, -0.495458663F, -0.502265513F, -0.509041429F,
    -0.515785873F, -0.522498548F, -0.529179F, -0.535826802F, -0.542441547F,
    -0.549022794F, -0.555570245F, -0.562083364F, -0.568561852F, -0.575005233F,
    -0.581413209F, -0.587785244F, -0.594121039F, -0.600420237F, -0.60668236F,
    -0.612907052F, -0.619093955F, -0.625242651F, -0.631352782F, -0.637424F,
    -0.643455863F, -0.649448037F, -0.655400157F, -0.661311865F, -0.667182744F,
    -0.673012495F, -0.678800762F, -0.684547126F, -0.690251231F, -0.695912778F,
    -0.70153141F, -0.707106769F, -0.712638497F, -0.718126297F, -0.723569751F,
    -0.72896862F, -0.734322488F, -0.739631116F, -0.744894F, -0.750111043F,
    -0.755281806F, -0.760405958F, -0.765483201F, -0.770513237F, -0.775495768F,
    -0.780430436F, -0.785316944F, -0.790155F, -0.794944346F, -0.799684644F,
    -0.804375648F, -0.809017F, -0.813608468F, -0.818149745F, -0.822640538F,
    -0.827080548F, -0.831469595F, -0.835807383F, -0.840093553F, -0.844327927F,
    -0.848510206F, -0.852640152F, -0.856717527F, -0.860742033F, -0.86471343F,
    -0.868631542F, -0.872496F, -0.876306653F, -0.880063295F, -0.883765638F,
    -0.887413442F, -0.891006529F, -0.894544661F, -0.898027599F, -0.901455104F,
    -0.904827058F, -0.908143163F, -0.911403298F, -0.914607167F, -0.91775465F,
    -0.920845509F, -0.923879504F, -0.926856577F, -0.92977649F, -0.932639F,
    -0.935444057F, -0.938191354F, -0.940880775F, -0.943512142F, -0.946085334F,
    -0.948600173F, -0.95105654F, -0.953454196F, -0.955793F, -0.958072901F,
    -0.96029371F, -0.962455213F, -0.964557409F, -0.96660012F, -0.968583167F,
    -0.970506489F, -0.972369909F, -0.974173367F, -0.975916743F, -0.977599919F,
    -0.979222834F, -0.980785251F, -0.982287228F, -0.983728647F, -0.985109329F,
    -0.986429274F, -0.987688363F, -0.988886476F, -0.990023673F, -0.991099775F,
    -0.992114723F, -0.993068457F, -0.993961F, -0.994792163F, -0.995561957F,
    -0.996270359F, -0.996917307F, -0.997502804F, -0.998026729F, -0.998489082F,
    -0.998889863F, -0.999229F, -0.999506533F, -0.999722421F, -0.999876618F,
    -0.999969184F, -1.0F, -0.999969184F, -0.999876618F, -0.999722421F,
    -0.999506533F, -0.999229F, -0.998889863F, -0.998489082F, -0.998026729F,
    -0.997502804F, -0.996917307F, -0.996270359F, -0.995561957F, -0.994792163F,
    -0.993961F, -0.993068457F, -0.992114723F, -0.991099775F, -0.990023673F,
    -0.988886476F, -0.987688363F, -0.986429274F, -0.985109329F, -0.983728647F,
    -0.982287228F, -0.980785251F, -0.979222834F, -0.977599919F, -0.975916743F,
    -0.974173367F, -0.972369909F, -0.970506489F, -0.968583167F, -0.96660012F,
    -0.964557409F, -0.962455213F, -0.96029371F, -0.958072901F, -0.955793F,
    -0.953454196F, -0.95105654F, -0.948600173F, -0.946085334F, -0.943512142F,
    -0.940880775F, -0.938191354F, -0.935444057F, -0.932639F, -0.92977649F,
    -0.926856577F, -0.923879504F, -0.920845509F, -0.91775465F, -0.914607167F,
    -0.911403298F, -0.908143163F, -0.904827058F, -0.901455104F, -0.898027599F,
    -0.894544661F, -0.891006529F, -0.887413442F, -0.883765638F, -0.880063295F,
    -0.876306653F, -0.872496F, -0.868631542F, -0.86471343F, -0.860742033F,
    -0.856717527F, -0.852640152F, -0.848510206F, -0.844327927F, -0.840093553F,
    -0.835807383F, -0.831469595F, -0.827080548F, -0.822640538F, -0.818149745F,
    -0.813608468F, -0.809017F, -0.804375648F, -0.799684644F, -0.794944346F,
    -0.790155F, -0.785316944F, -0.780430436F, -0.775495768F, -0.770513237F,
    -0.765483201F, -0.760405958F, -0.755281806F, -0.750111043F, -0.744894F,
    -0.739631116F, -0.734322488F, -0.72896862F, -0.723569751F, -0.718126297F,
    -0.712638497F, -0.707106769F, -0.70153141F, -0.695912778F, -0.690251231F,
    -0.684547126F, -0.678800762F, -0.673012495F, -0.667182744F, -0.661311865F,
    -0.655400157F, -0.649448037F, -0.643455863F, -0.637424F, -0.631352782F,
    -0.625242651F, -0.619093955F, -0.612907052F, -0.60668236F, -0.600420237F,
    -0.594121039F, -0.587785244F, -0.581413209F, -0.575005233F, -0.568561852F,
    -0.562083364F, -0.555570245F, -0.549022794F, -0.542441547F, -0.535826802F,
    -0.529179F, -0.522498548F, -0.515785873F, -0.509041429F, -0.502265513F,
    -0.495458663F, -0.488621235F, -0.481753677F, -0.474856377F, -0.46792981F,
    -0.460974365F, -0.453990489F, -0.446978629F, -0.439939171F, -0.432872593F,
    -0.425779283F, -0.418659747F, -0.411514372F, -0.404343605F, -0.397147894F,
    -0.389927685F, -0.382683426F, -0.375415564F, -0.368124545F, -0.360810816F,
    -0.353474855F, -0.346117049F, -0.338737935F, -0.331337899F, -0.323917419F,
    -0.316476971F, -0.309017F, -0.301537961F, -0.294040322F, -0.286524564F,
    -0.278991103F, -0.271440446F, -0.263873041F, -0.256289363F, -0.24868989F,
    -0.241075054F, -0.233445361F, -0.225801274F, -0.21814324F, -0.210471764F,
    -0.202787295F, -0.195090324F, -0.187381312F, -0.179660752F, -0.171929106F,
    -0.16418685F, -0.156434461F, -0.148672432F, -0.140901238F, -0.133121341F,
    -0.125333235F, -0.117537394F, -0.109734312F, -0.101924457F, -0.0941083133F,
    -0.086286366F, -0.0784591F, -0.070626989F, -0.0627905205F, -0.0549501814F,
    -0.0471064523F, -0.0392598175F, -0.0314107575F, -0.023559764F,
    -0.0157073177F, -0.00785390101F, -2.44929371E-16F, 0.00785390101F,
    0.0157073177F, 0.023559764F, 0.0314107575F, 0.0392598175F, 0.0471064523F,
    0.0549501814F, 0.0627905205F, 0.070626989F, 0.0784591F, 0.086286366F,
    0.0941083133F, 0.101924457F, 0.109734312F, 0.117537394F, 0.125333235F,
    0.133121341F, 0.140901238F, 0.148672432F, 0.156434461F, 0.16418685F,
    0.171929106F, 0.179660752F, 0.187381312F, 0.195090324F, 0.202787295F,
    0.210471764F, 0.21814324F, 0.225801274F, 0.233445361F, 0.241075054F,
    0.24868989F, 0.256289363F, 0.263873041F, 0.271440446F, 0.278991103F,
    0.286524564F, 0.294040322F, 0.301537961F, 0.309017F, 0.316476971F,
    0.323917419F, 0.331337899F, 0.338737935F, 0.346117049F, 0.353474855F,
    0.360810816F, 0.368124545F, 0.375415564F, 0.382683426F, 0.389927685F,
    0.397147894F, 0.404343605F, 0.411514372F, 0.418659747F, 0.425779283F,
    0.432872593F, 0.439939171F, 0.446978629F, 0.453990489F, 0.460974365F,
    0.46792981F, 0.474856377F, 0.481753677F, 0.488621235F, 0.495458663F,
    0.502265513F, 0.509041429F, 0.515785873F, 0.522498548F, 0.529179F,
    0.535826802F, 0.542441547F, 0.549022794F, 0.555570245F, 0.562083364F,
    0.568561852F, 0.575005233F, 0.581413209F, 0.587785244F, 0.594121039F,
    0.600420237F, 0.60668236F, 0.612907052F, 0.619093955F, 0.625242651F,
    0.631352782F, 0.637424F, 0.643455863F, 0.649448037F, 0.655400157F,
    0.661311865F, 0.667182744F, 0.673012495F, 0.678800762F, 0.684547126F,
    0.690251231F, 0.695912778F, 0.70153141F, 0.707106769F, 0.712638497F,
    0.718126297F, 0.723569751F, 0.72896862F, 0.734322488F, 0.739631116F,
    0.744894F, 0.750111043F, 0.755281806F, 0.760405958F, 0.765483201F,
    0.770513237F, 0.775495768F, 0.780430436F, 0.785316944F, 0.790155F,
    0.794944346F, 0.799684644F, 0.804375648F, 0.809017F, 0.813608468F,
    0.818149745F, 0.822640538F, 0.827080548F, 0.831469595F, 0.835807383F,
    0.840093553F, 0.844327927F, 0.848510206F, 0.852640152F, 0.856717527F,
    0.860742033F, 0.86471343F, 0.868631542F, 0.872496F, 0.876306653F,
    0.880063295F, 0.883765638F, 0.887413442F, 0.891006529F, 0.894544661F,
    0.898027599F, 0.901455104F, 0.904827058F, 0.908143163F, 0.911403298F,
    0.914607167F, 0.91775465F, 0.920845509F, 0.923879504F, 0.926856577F,
    0.92977649F, 0.932639F, 0.935444057F, 0.938191354F, 0.940880775F,
    0.943512142F, 0.946085334F, 0.948600173F, 0.95105654F, 0.953454196F,
    0.955793F, 0.958072901F, 0.96029371F, 0.962455213F, 0.964557409F,
    0.96660012F, 0.968583167F, 0.970506489F, 0.972369909F, 0.974173367F,
    0.975916743F, 0.977599919F, 0.979222834F, 0.980785251F, 0.982287228F,
    0.983728647F, 0.985109329F, 0.986429274F, 0.987688363F, 0.988886476F,
    0.990023673F, 0.991099775F, 0.992114723F, 0.993068457F, 0.993961F,
    0.994792163F, 0.995561957F, 0.996270359F, 0.996917307F, 0.997502804F,
    0.998026729F, 0.998489082F, 0.998889863F, 0.999229F, 0.999506533F,
    0.999722421F, 0.999876618F, 0.999969184F, 1.0F, 0.999969184F },

  /* Computed Parameter: convert_pu_Gain
   * Referenced by: '<S79>/convert_pu'
   */
  1.0F,

  /* Computed Parameter: indexing_Gain
   * Referenced by: '<S67>/indexing'
   */
  800.0F,

  /* Computed Parameter: UseInputPort_Value_jy
   * Referenced by: '<S100>/UseInputPort'
   */
  1.0F,

  /* Computed Parameter: Switch1_Threshold_pwq
   * Referenced by: '<S100>/Switch1'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_le
   * Referenced by: '<S106>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UseInputPort_Value_if
   * Referenced by: '<S99>/UseInputPort'
   */
  1.0F,

  /* Computed Parameter: Switch1_Threshold_bz
   * Referenced by: '<S99>/Switch1'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_di
   * Referenced by: '<S103>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_e3
   * Referenced by: '<S307>/Constant'
   */
  0.0F,

  /* Computed Parameter: sine_table_values_Value_o
   * Referenced by: '<S302>/sine_table_values'
   */
  { 0.0F, 0.00785390101F, 0.0157073177F, 0.023559764F, 0.0314107575F,
    0.0392598175F, 0.0471064523F, 0.0549501814F, 0.0627905205F, 0.070626989F,
    0.0784591F, 0.086286366F, 0.0941083133F, 0.101924457F, 0.109734312F,
    0.117537394F, 0.125333235F, 0.133121341F, 0.140901238F, 0.148672432F,
    0.156434461F, 0.16418685F, 0.171929106F, 0.179660752F, 0.187381312F,
    0.195090324F, 0.202787295F, 0.210471764F, 0.21814324F, 0.225801274F,
    0.233445361F, 0.241075054F, 0.24868989F, 0.256289363F, 0.263873041F,
    0.271440446F, 0.278991103F, 0.286524564F, 0.294040322F, 0.301537961F,
    0.309017F, 0.316476971F, 0.323917419F, 0.331337899F, 0.338737935F,
    0.346117049F, 0.353474855F, 0.360810816F, 0.368124545F, 0.375415564F,
    0.382683426F, 0.389927685F, 0.397147894F, 0.404343605F, 0.411514372F,
    0.418659747F, 0.425779283F, 0.432872593F, 0.439939171F, 0.446978629F,
    0.453990489F, 0.460974365F, 0.46792981F, 0.474856377F, 0.481753677F,
    0.488621235F, 0.495458663F, 0.502265513F, 0.509041429F, 0.515785873F,
    0.522498548F, 0.529179F, 0.535826802F, 0.542441547F, 0.549022794F,
    0.555570245F, 0.562083364F, 0.568561852F, 0.575005233F, 0.581413209F,
    0.587785244F, 0.594121039F, 0.600420237F, 0.60668236F, 0.612907052F,
    0.619093955F, 0.625242651F, 0.631352782F, 0.637424F, 0.643455863F,
    0.649448037F, 0.655400157F, 0.661311865F, 0.667182744F, 0.673012495F,
    0.678800762F, 0.684547126F, 0.690251231F, 0.695912778F, 0.70153141F,
    0.707106769F, 0.712638497F, 0.718126297F, 0.723569751F, 0.72896862F,
    0.734322488F, 0.739631116F, 0.744894F, 0.750111043F, 0.755281806F,
    0.760405958F, 0.765483201F, 0.770513237F, 0.775495768F, 0.780430436F,
    0.785316944F, 0.790155F, 0.794944346F, 0.799684644F, 0.804375648F, 0.809017F,
    0.813608468F, 0.818149745F, 0.822640538F, 0.827080548F, 0.831469595F,
    0.835807383F, 0.840093553F, 0.844327927F, 0.848510206F, 0.852640152F,
    0.856717527F, 0.860742033F, 0.86471343F, 0.868631542F, 0.872496F,
    0.876306653F, 0.880063295F, 0.883765638F, 0.887413442F, 0.891006529F,
    0.894544661F, 0.898027599F, 0.901455104F, 0.904827058F, 0.908143163F,
    0.911403298F, 0.914607167F, 0.91775465F, 0.920845509F, 0.923879504F,
    0.926856577F, 0.92977649F, 0.932639F, 0.935444057F, 0.938191354F,
    0.940880775F, 0.943512142F, 0.946085334F, 0.948600173F, 0.95105654F,
    0.953454196F, 0.955793F, 0.958072901F, 0.96029371F, 0.962455213F,
    0.964557409F, 0.96660012F, 0.968583167F, 0.970506489F, 0.972369909F,
    0.974173367F, 0.975916743F, 0.977599919F, 0.979222834F, 0.980785251F,
    0.982287228F, 0.983728647F, 0.985109329F, 0.986429274F, 0.987688363F,
    0.988886476F, 0.990023673F, 0.991099775F, 0.992114723F, 0.993068457F,
    0.993961F, 0.994792163F, 0.995561957F, 0.996270359F, 0.996917307F,
    0.997502804F, 0.998026729F, 0.998489082F, 0.998889863F, 0.999229F,
    0.999506533F, 0.999722421F, 0.999876618F, 0.999969184F, 1.0F, 0.999969184F,
    0.999876618F, 0.999722421F, 0.999506533F, 0.999229F, 0.998889863F,
    0.998489082F, 0.998026729F, 0.997502804F, 0.996917307F, 0.996270359F,
    0.995561957F, 0.994792163F, 0.993961F, 0.993068457F, 0.992114723F,
    0.991099775F, 0.990023673F, 0.988886476F, 0.987688363F, 0.986429274F,
    0.985109329F, 0.983728647F, 0.982287228F, 0.980785251F, 0.979222834F,
    0.977599919F, 0.975916743F, 0.974173367F, 0.972369909F, 0.970506489F,
    0.968583167F, 0.96660012F, 0.964557409F, 0.962455213F, 0.96029371F,
    0.958072901F, 0.955793F, 0.953454196F, 0.95105654F, 0.948600173F,
    0.946085334F, 0.943512142F, 0.940880775F, 0.938191354F, 0.935444057F,
    0.932639F, 0.92977649F, 0.926856577F, 0.923879504F, 0.920845509F,
    0.91775465F, 0.914607167F, 0.911403298F, 0.908143163F, 0.904827058F,
    0.901455104F, 0.898027599F, 0.894544661F, 0.891006529F, 0.887413442F,
    0.883765638F, 0.880063295F, 0.876306653F, 0.872496F, 0.868631542F,
    0.86471343F, 0.860742033F, 0.856717527F, 0.852640152F, 0.848510206F,
    0.844327927F, 0.840093553F, 0.835807383F, 0.831469595F, 0.827080548F,
    0.822640538F, 0.818149745F, 0.813608468F, 0.809017F, 0.804375648F,
    0.799684644F, 0.794944346F, 0.790155F, 0.785316944F, 0.780430436F,
    0.775495768F, 0.770513237F, 0.765483201F, 0.760405958F, 0.755281806F,
    0.750111043F, 0.744894F, 0.739631116F, 0.734322488F, 0.72896862F,
    0.723569751F, 0.718126297F, 0.712638497F, 0.707106769F, 0.70153141F,
    0.695912778F, 0.690251231F, 0.684547126F, 0.678800762F, 0.673012495F,
    0.667182744F, 0.661311865F, 0.655400157F, 0.649448037F, 0.643455863F,
    0.637424F, 0.631352782F, 0.625242651F, 0.619093955F, 0.612907052F,
    0.60668236F, 0.600420237F, 0.594121039F, 0.587785244F, 0.581413209F,
    0.575005233F, 0.568561852F, 0.562083364F, 0.555570245F, 0.549022794F,
    0.542441547F, 0.535826802F, 0.529179F, 0.522498548F, 0.515785873F,
    0.509041429F, 0.502265513F, 0.495458663F, 0.488621235F, 0.481753677F,
    0.474856377F, 0.46792981F, 0.460974365F, 0.453990489F, 0.446978629F,
    0.439939171F, 0.432872593F, 0.425779283F, 0.418659747F, 0.411514372F,
    0.404343605F, 0.397147894F, 0.389927685F, 0.382683426F, 0.375415564F,
    0.368124545F, 0.360810816F, 0.353474855F, 0.346117049F, 0.338737935F,
    0.331337899F, 0.323917419F, 0.316476971F, 0.309017F, 0.301537961F,
    0.294040322F, 0.286524564F, 0.278991103F, 0.271440446F, 0.263873041F,
    0.256289363F, 0.24868989F, 0.241075054F, 0.233445361F, 0.225801274F,
    0.21814324F, 0.210471764F, 0.202787295F, 0.195090324F, 0.187381312F,
    0.179660752F, 0.171929106F, 0.16418685F, 0.156434461F, 0.148672432F,
    0.140901238F, 0.133121341F, 0.125333235F, 0.117537394F, 0.109734312F,
    0.101924457F, 0.0941083133F, 0.086286366F, 0.0784591F, 0.070626989F,
    0.0627905205F, 0.0549501814F, 0.0471064523F, 0.0392598175F, 0.0314107575F,
    0.023559764F, 0.0157073177F, 0.00785390101F, 1.22464685E-16F,
    -0.00785390101F, -0.0157073177F, -0.023559764F, -0.0314107575F,
    -0.0392598175F, -0.0471064523F, -0.0549501814F, -0.0627905205F,
    -0.070626989F, -0.0784591F, -0.086286366F, -0.0941083133F, -0.101924457F,
    -0.109734312F, -0.117537394F, -0.125333235F, -0.133121341F, -0.140901238F,
    -0.148672432F, -0.156434461F, -0.16418685F, -0.171929106F, -0.179660752F,
    -0.187381312F, -0.195090324F, -0.202787295F, -0.210471764F, -0.21814324F,
    -0.225801274F, -0.233445361F, -0.241075054F, -0.24868989F, -0.256289363F,
    -0.263873041F, -0.271440446F, -0.278991103F, -0.286524564F, -0.294040322F,
    -0.301537961F, -0.309017F, -0.316476971F, -0.323917419F, -0.331337899F,
    -0.338737935F, -0.346117049F, -0.353474855F, -0.360810816F, -0.368124545F,
    -0.375415564F, -0.382683426F, -0.389927685F, -0.397147894F, -0.404343605F,
    -0.411514372F, -0.418659747F, -0.425779283F, -0.432872593F, -0.439939171F,
    -0.446978629F, -0.453990489F, -0.460974365F, -0.46792981F, -0.474856377F,
    -0.481753677F, -0.488621235F, -0.495458663F, -0.502265513F, -0.509041429F,
    -0.515785873F, -0.522498548F, -0.529179F, -0.535826802F, -0.542441547F,
    -0.549022794F, -0.555570245F, -0.562083364F, -0.568561852F, -0.575005233F,
    -0.581413209F, -0.587785244F, -0.594121039F, -0.600420237F, -0.60668236F,
    -0.612907052F, -0.619093955F, -0.625242651F, -0.631352782F, -0.637424F,
    -0.643455863F, -0.649448037F, -0.655400157F, -0.661311865F, -0.667182744F,
    -0.673012495F, -0.678800762F, -0.684547126F, -0.690251231F, -0.695912778F,
    -0.70153141F, -0.707106769F, -0.712638497F, -0.718126297F, -0.723569751F,
    -0.72896862F, -0.734322488F, -0.739631116F, -0.744894F, -0.750111043F,
    -0.755281806F, -0.760405958F, -0.765483201F, -0.770513237F, -0.775495768F,
    -0.780430436F, -0.785316944F, -0.790155F, -0.794944346F, -0.799684644F,
    -0.804375648F, -0.809017F, -0.813608468F, -0.818149745F, -0.822640538F,
    -0.827080548F, -0.831469595F, -0.835807383F, -0.840093553F, -0.844327927F,
    -0.848510206F, -0.852640152F, -0.856717527F, -0.860742033F, -0.86471343F,
    -0.868631542F, -0.872496F, -0.876306653F, -0.880063295F, -0.883765638F,
    -0.887413442F, -0.891006529F, -0.894544661F, -0.898027599F, -0.901455104F,
    -0.904827058F, -0.908143163F, -0.911403298F, -0.914607167F, -0.91775465F,
    -0.920845509F, -0.923879504F, -0.926856577F, -0.92977649F, -0.932639F,
    -0.935444057F, -0.938191354F, -0.940880775F, -0.943512142F, -0.946085334F,
    -0.948600173F, -0.95105654F, -0.953454196F, -0.955793F, -0.958072901F,
    -0.96029371F, -0.962455213F, -0.964557409F, -0.96660012F, -0.968583167F,
    -0.970506489F, -0.972369909F, -0.974173367F, -0.975916743F, -0.977599919F,
    -0.979222834F, -0.980785251F, -0.982287228F, -0.983728647F, -0.985109329F,
    -0.986429274F, -0.987688363F, -0.988886476F, -0.990023673F, -0.991099775F,
    -0.992114723F, -0.993068457F, -0.993961F, -0.994792163F, -0.995561957F,
    -0.996270359F, -0.996917307F, -0.997502804F, -0.998026729F, -0.998489082F,
    -0.998889863F, -0.999229F, -0.999506533F, -0.999722421F, -0.999876618F,
    -0.999969184F, -1.0F, -0.999969184F, -0.999876618F, -0.999722421F,
    -0.999506533F, -0.999229F, -0.998889863F, -0.998489082F, -0.998026729F,
    -0.997502804F, -0.996917307F, -0.996270359F, -0.995561957F, -0.994792163F,
    -0.993961F, -0.993068457F, -0.992114723F, -0.991099775F, -0.990023673F,
    -0.988886476F, -0.987688363F, -0.986429274F, -0.985109329F, -0.983728647F,
    -0.982287228F, -0.980785251F, -0.979222834F, -0.977599919F, -0.975916743F,
    -0.974173367F, -0.972369909F, -0.970506489F, -0.968583167F, -0.96660012F,
    -0.964557409F, -0.962455213F, -0.96029371F, -0.958072901F, -0.955793F,
    -0.953454196F, -0.95105654F, -0.948600173F, -0.946085334F, -0.943512142F,
    -0.940880775F, -0.938191354F, -0.935444057F, -0.932639F, -0.92977649F,
    -0.926856577F, -0.923879504F, -0.920845509F, -0.91775465F, -0.914607167F,
    -0.911403298F, -0.908143163F, -0.904827058F, -0.901455104F, -0.898027599F,
    -0.894544661F, -0.891006529F, -0.887413442F, -0.883765638F, -0.880063295F,
    -0.876306653F, -0.872496F, -0.868631542F, -0.86471343F, -0.860742033F,
    -0.856717527F, -0.852640152F, -0.848510206F, -0.844327927F, -0.840093553F,
    -0.835807383F, -0.831469595F, -0.827080548F, -0.822640538F, -0.818149745F,
    -0.813608468F, -0.809017F, -0.804375648F, -0.799684644F, -0.794944346F,
    -0.790155F, -0.785316944F, -0.780430436F, -0.775495768F, -0.770513237F,
    -0.765483201F, -0.760405958F, -0.755281806F, -0.750111043F, -0.744894F,
    -0.739631116F, -0.734322488F, -0.72896862F, -0.723569751F, -0.718126297F,
    -0.712638497F, -0.707106769F, -0.70153141F, -0.695912778F, -0.690251231F,
    -0.684547126F, -0.678800762F, -0.673012495F, -0.667182744F, -0.661311865F,
    -0.655400157F, -0.649448037F, -0.643455863F, -0.637424F, -0.631352782F,
    -0.625242651F, -0.619093955F, -0.612907052F, -0.60668236F, -0.600420237F,
    -0.594121039F, -0.587785244F, -0.581413209F, -0.575005233F, -0.568561852F,
    -0.562083364F, -0.555570245F, -0.549022794F, -0.542441547F, -0.535826802F,
    -0.529179F, -0.522498548F, -0.515785873F, -0.509041429F, -0.502265513F,
    -0.495458663F, -0.488621235F, -0.481753677F, -0.474856377F, -0.46792981F,
    -0.460974365F, -0.453990489F, -0.446978629F, -0.439939171F, -0.432872593F,
    -0.425779283F, -0.418659747F, -0.411514372F, -0.404343605F, -0.397147894F,
    -0.389927685F, -0.382683426F, -0.375415564F, -0.368124545F, -0.360810816F,
    -0.353474855F, -0.346117049F, -0.338737935F, -0.331337899F, -0.323917419F,
    -0.316476971F, -0.309017F, -0.301537961F, -0.294040322F, -0.286524564F,
    -0.278991103F, -0.271440446F, -0.263873041F, -0.256289363F, -0.24868989F,
    -0.241075054F, -0.233445361F, -0.225801274F, -0.21814324F, -0.210471764F,
    -0.202787295F, -0.195090324F, -0.187381312F, -0.179660752F, -0.171929106F,
    -0.16418685F, -0.156434461F, -0.148672432F, -0.140901238F, -0.133121341F,
    -0.125333235F, -0.117537394F, -0.109734312F, -0.101924457F, -0.0941083133F,
    -0.086286366F, -0.0784591F, -0.070626989F, -0.0627905205F, -0.0549501814F,
    -0.0471064523F, -0.0392598175F, -0.0314107575F, -0.023559764F,
    -0.0157073177F, -0.00785390101F, -2.44929371E-16F, 0.00785390101F,
    0.0157073177F, 0.023559764F, 0.0314107575F, 0.0392598175F, 0.0471064523F,
    0.0549501814F, 0.0627905205F, 0.070626989F, 0.0784591F, 0.086286366F,
    0.0941083133F, 0.101924457F, 0.109734312F, 0.117537394F, 0.125333235F,
    0.133121341F, 0.140901238F, 0.148672432F, 0.156434461F, 0.16418685F,
    0.171929106F, 0.179660752F, 0.187381312F, 0.195090324F, 0.202787295F,
    0.210471764F, 0.21814324F, 0.225801274F, 0.233445361F, 0.241075054F,
    0.24868989F, 0.256289363F, 0.263873041F, 0.271440446F, 0.278991103F,
    0.286524564F, 0.294040322F, 0.301537961F, 0.309017F, 0.316476971F,
    0.323917419F, 0.331337899F, 0.338737935F, 0.346117049F, 0.353474855F,
    0.360810816F, 0.368124545F, 0.375415564F, 0.382683426F, 0.389927685F,
    0.397147894F, 0.404343605F, 0.411514372F, 0.418659747F, 0.425779283F,
    0.432872593F, 0.439939171F, 0.446978629F, 0.453990489F, 0.460974365F,
    0.46792981F, 0.474856377F, 0.481753677F, 0.488621235F, 0.495458663F,
    0.502265513F, 0.509041429F, 0.515785873F, 0.522498548F, 0.529179F,
    0.535826802F, 0.542441547F, 0.549022794F, 0.555570245F, 0.562083364F,
    0.568561852F, 0.575005233F, 0.581413209F, 0.587785244F, 0.594121039F,
    0.600420237F, 0.60668236F, 0.612907052F, 0.619093955F, 0.625242651F,
    0.631352782F, 0.637424F, 0.643455863F, 0.649448037F, 0.655400157F,
    0.661311865F, 0.667182744F, 0.673012495F, 0.678800762F, 0.684547126F,
    0.690251231F, 0.695912778F, 0.70153141F, 0.707106769F, 0.712638497F,
    0.718126297F, 0.723569751F, 0.72896862F, 0.734322488F, 0.739631116F,
    0.744894F, 0.750111043F, 0.755281806F, 0.760405958F, 0.765483201F,
    0.770513237F, 0.775495768F, 0.780430436F, 0.785316944F, 0.790155F,
    0.794944346F, 0.799684644F, 0.804375648F, 0.809017F, 0.813608468F,
    0.818149745F, 0.822640538F, 0.827080548F, 0.831469595F, 0.835807383F,
    0.840093553F, 0.844327927F, 0.848510206F, 0.852640152F, 0.856717527F,
    0.860742033F, 0.86471343F, 0.868631542F, 0.872496F, 0.876306653F,
    0.880063295F, 0.883765638F, 0.887413442F, 0.891006529F, 0.894544661F,
    0.898027599F, 0.901455104F, 0.904827058F, 0.908143163F, 0.911403298F,
    0.914607167F, 0.91775465F, 0.920845509F, 0.923879504F, 0.926856577F,
    0.92977649F, 0.932639F, 0.935444057F, 0.938191354F, 0.940880775F,
    0.943512142F, 0.946085334F, 0.948600173F, 0.95105654F, 0.953454196F,
    0.955793F, 0.958072901F, 0.96029371F, 0.962455213F, 0.964557409F,
    0.96660012F, 0.968583167F, 0.970506489F, 0.972369909F, 0.974173367F,
    0.975916743F, 0.977599919F, 0.979222834F, 0.980785251F, 0.982287228F,
    0.983728647F, 0.985109329F, 0.986429274F, 0.987688363F, 0.988886476F,
    0.990023673F, 0.991099775F, 0.992114723F, 0.993068457F, 0.993961F,
    0.994792163F, 0.995561957F, 0.996270359F, 0.996917307F, 0.997502804F,
    0.998026729F, 0.998489082F, 0.998889863F, 0.999229F, 0.999506533F,
    0.999722421F, 0.999876618F, 0.999969184F, 1.0F, 0.999969184F },

  /* Computed Parameter: convert_pu_Gain_e
   * Referenced by: '<S306>/convert_pu'
   */
  1.0F,

  /* Computed Parameter: indexing_Gain_b
   * Referenced by: '<S302>/indexing'
   */
  800.0F,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S3>/Out2'
   */
  0U,

  /* Computed Parameter: Out2_Y0_g
   * Referenced by: '<S2>/Out2'
   */
  0U,

  /* Computed Parameter: Out2_Y0_a
   * Referenced by: '<S4>/Out2'
   */
  0U,

  /* Computed Parameter: DataStoreMemory3_InitialValue
   * Referenced by: '<Root>/Data Store Memory3'
   */
  0U,

  /* Computed Parameter: Count_Y0
   * Referenced by: '<S24>/Count'
   */
  0U,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S24>/Constant'
   */
  1U,

  /* Computed Parameter: Delay_InitialCondition_e
   * Referenced by: '<S24>/Delay'
   */
  0U,

  /* Computed Parameter: Countfor2sec_Value
   * Referenced by: '<S23>/Count for 2 sec'
   */
  25000U,

  /* Computed Parameter: offset_Value
   * Referenced by: '<S67>/offset'
   */
  { 1, 0, 201, 200 },

  /* Computed Parameter: offset_Value_o
   * Referenced by: '<S302>/offset'
   */
  { 1, 0, 201, 200 },

  /* Computed Parameter: DataStoreMemory5_InitialValue
   * Referenced by: '<Root>/Data Store Memory5'
   */
  0,

  /* Computed Parameter: DataStoreMemory1_InitialValue
   * Referenced by: '<Root>/Data Store Memory1'
   */
  0,

  /* Computed Parameter: Gain_Gain_l
   * Referenced by: '<S3>/Gain'
   */
  32768U,

  /* Computed Parameter: Gain_Gain_b
   * Referenced by: '<S2>/Gain'
   */
  32768U,

  /* Computed Parameter: Gain_Gain_i
   * Referenced by: '<S4>/Gain'
   */
  32768U,

  /* Expression: uint16(10*ClkFreq/(PolePairs*MinSpeed))
   * Referenced by: '<S34>/SpeedConst'
   */
  50000U,

  /* Computed Parameter: PositionEnable_Value
   * Referenced by: '<S34>/PositionEnable'
   */
  1U,

  /* Computed Parameter: WatchDog_Value
   * Referenced by: '<S30>/WatchDog'
   */
  0U,

  /* Computed Parameter: speedcheck_Threshold
   * Referenced by: '<S35>/speed check'
   */
  50000U,

  /* Computed Parameter: stop_Value
   * Referenced by: '<S68>/stop'
   */
  0U,

  /* Computed Parameter: Offset_Value
   * Referenced by: '<S89>/Offset'
   */
  0U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S89>/Switch'
   */
  1U,

  /* Computed Parameter: ct_Y0
   * Referenced by: '<S1>/ct'
   */
  0U,

  /* Computed Parameter: Constant_Value_mo
   * Referenced by: '<S36>/Constant'
   */
  0U,

  /* Computed Parameter: Order_Value
   * Referenced by: '<S31>/Order'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_h
   * Referenced by: '<S31>/Switch'
   */
  0U,

  /* Computed Parameter: speedCountDelay_InitialConditio
   * Referenced by: '<S31>/speedCountDelay'
   */
  0U,

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S35>/Constant'
   */
  0U,

  /* Computed Parameter: Constant2_Value_p3
   * Referenced by: '<S32>/Constant2'
   */
  1U,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S133>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_ih
   * Referenced by: '<S108>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_pl
   * Referenced by: '<S158>/Constant'
   */
  1U,

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

  /* Computed Parameter: Delay_InitialCondition_f
   * Referenced by: '<S28>/Delay'
   */
  false,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S28>/Constant'
   */
  true,

  /* Computed Parameter: EnPWM_Y0
   * Referenced by: '<S18>/EnPWM'
   */
  false,

  /* Computed Parameter: Constant_Reset_Value
   * Referenced by: '<S27>/Constant_Reset'
   */
  false,

  /* Computed Parameter: validityDelay_InitialCondition
   * Referenced by: '<S31>/validityDelay'
   */
  false,

  /* Computed Parameter: DelayOneStep1_InitialCondition
   * Referenced by: '<S32>/Delay One Step1'
   */
  true,

  /* Computed Parameter: UnitDelay_InitialCondition_kj
   * Referenced by: '<S259>/Unit Delay'
   */
  false,

  /* Computed Parameter: Delay_InitialCondition_o
   * Referenced by: '<S303>/Delay'
   */
  false,

  /* Computed Parameter: Constant_Value_a
   * Referenced by: '<S303>/Constant'
   */
  true,

  /* Computed Parameter: Constant_Reset_Value_c
   * Referenced by: '<S301>/Constant_Reset'
   */
  false,

  /* Computed Parameter: Gain_Gain_de
   * Referenced by: '<S132>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_jm
   * Referenced by: '<S107>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S157>/Gain'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_n
   * Referenced by: '<S132>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_o
   * Referenced by: '<S107>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_oh
   * Referenced by: '<S157>/Gain1'
   */
  128U,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<Root>/Data Store Memory'
   */
  0U,

  /* Start of '<S169>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S170>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S170>/Constant1'
     */
    false
  }
  ,

  /* End of '<S169>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S169>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S171>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S180>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S171>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S171>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S171>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S171>/Constant'
     */
    false,

    /* Start of '<S146>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S177>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S177>/next'
       */
      5U
    }
    ,

    /* End of '<S146>/If Action Subsystem5' */

    /* Start of '<S146>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S176>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S176>/next'
       */
      1U
    }
    ,

    /* End of '<S146>/If Action Subsystem4' */

    /* Start of '<S146>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S175>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S175>/next'
       */
      3U
    }
    ,

    /* End of '<S146>/If Action Subsystem3' */

    /* Start of '<S146>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S174>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S174>/next'
       */
      2U
    }
    ,

    /* End of '<S146>/If Action Subsystem2' */

    /* Start of '<S146>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S173>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S173>/next'
       */
      6U
    }
    ,

    /* End of '<S146>/If Action Subsystem1' */

    /* Start of '<S146>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S172>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S172>/next'
       */
      4U
    }
    ,

    /* End of '<S146>/If Action Subsystem' */

    /* Start of '<S146>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S179>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S179>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S146>/If Action Subsystem7' */

    /* Start of '<S146>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S178>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S178>/Constant1'
       */
      0U
    }
    /* End of '<S146>/If Action Subsystem6' */
  }
  ,

  /* End of '<S169>/Valid Halls' */

  /* Start of '<S119>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S120>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S120>/Constant1'
     */
    false
  }
  ,

  /* End of '<S119>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S119>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S121>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S130>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S121>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S121>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S121>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S121>/Constant'
     */
    false,

    /* Start of '<S146>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S127>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S127>/next'
       */
      5U
    }
    ,

    /* End of '<S146>/If Action Subsystem5' */

    /* Start of '<S146>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S126>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S126>/next'
       */
      1U
    }
    ,

    /* End of '<S146>/If Action Subsystem4' */

    /* Start of '<S146>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S125>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S125>/next'
       */
      3U
    }
    ,

    /* End of '<S146>/If Action Subsystem3' */

    /* Start of '<S146>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S124>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S124>/next'
       */
      2U
    }
    ,

    /* End of '<S146>/If Action Subsystem2' */

    /* Start of '<S146>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S123>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S123>/next'
       */
      6U
    }
    ,

    /* End of '<S146>/If Action Subsystem1' */

    /* Start of '<S146>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S122>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S122>/next'
       */
      4U
    }
    ,

    /* End of '<S146>/If Action Subsystem' */

    /* Start of '<S146>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S129>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S129>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S146>/If Action Subsystem7' */

    /* Start of '<S146>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S128>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S128>/Constant1'
       */
      0U
    }
    /* End of '<S146>/If Action Subsystem6' */
  }
  ,

  /* End of '<S119>/Valid Halls' */

  /* Start of '<S144>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S145>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S145>/Constant1'
     */
    false
  }
  ,

  /* End of '<S144>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S144>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S146>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S155>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S146>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S146>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S146>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S146>/Constant'
     */
    false,

    /* Start of '<S146>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S152>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S152>/next'
       */
      5U
    }
    ,

    /* End of '<S146>/If Action Subsystem5' */

    /* Start of '<S146>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S151>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S151>/next'
       */
      1U
    }
    ,

    /* End of '<S146>/If Action Subsystem4' */

    /* Start of '<S146>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S150>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S150>/next'
       */
      3U
    }
    ,

    /* End of '<S146>/If Action Subsystem3' */

    /* Start of '<S146>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S149>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S149>/next'
       */
      2U
    }
    ,

    /* End of '<S146>/If Action Subsystem2' */

    /* Start of '<S146>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S148>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S148>/next'
       */
      6U
    }
    ,

    /* End of '<S146>/If Action Subsystem1' */

    /* Start of '<S146>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S147>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S147>/next'
       */
      4U
    }
    ,

    /* End of '<S146>/If Action Subsystem' */

    /* Start of '<S146>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S154>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S154>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S146>/If Action Subsystem7' */

    /* Start of '<S146>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S153>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S153>/Constant1'
       */
      0U
    }
    /* End of '<S146>/If Action Subsystem6' */
  }
  ,

  /* End of '<S144>/Valid Halls' */

  /* Start of '<S37>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S44>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S37>/Hall Value of 7' */

  /* Start of '<S37>/Hall Value of 6' */
  {
    /* Expression: single(0.91667)
     * Referenced by: '<S43>/Constant'
     */
    0.91667F
  }
  ,

  /* End of '<S37>/Hall Value of 6' */

  /* Start of '<S37>/Hall Value of 5' */
  {
    /* Expression: single(0.75)
     * Referenced by: '<S42>/Constant'
     */
    0.75F
  }
  ,

  /* End of '<S37>/Hall Value of 5' */

  /* Start of '<S37>/Hall Value of 4' */
  {
    /* Expression: single(0.58333)
     * Referenced by: '<S41>/Constant'
     */
    0.58333F
  }
  ,

  /* End of '<S37>/Hall Value of 4' */

  /* Start of '<S37>/Hall Value of 3' */
  {
    /* Expression: single(0.41667)
     * Referenced by: '<S40>/Constant'
     */
    0.41667F
  }
  ,

  /* End of '<S37>/Hall Value of 3' */

  /* Start of '<S37>/Hall Value of 2' */
  {
    /* Expression: single(0.25)
     * Referenced by: '<S39>/Constant'
     */
    0.25F
  }
  ,

  /* End of '<S37>/Hall Value of 2' */

  /* Start of '<S37>/Hall Value of 1' */
  {
    /* Expression: single(0.083333)
     * Referenced by: '<S38>/Constant'
     */
    0.083333F
  }
  ,

  /* End of '<S37>/Hall Value of 1' */

  /* Start of '<S48>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S58>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S48>/Hall Value of 7' */

  /* Start of '<S48>/Hall Value of 6' */
  {
    /* Expression: single(0.83333)
     * Referenced by: '<S57>/Constant'
     */
    0.83333F
  }
  ,

  /* End of '<S48>/Hall Value of 6' */

  /* Start of '<S48>/Hall Value of 5' */
  {
    /* Expression: single(0.66667)
     * Referenced by: '<S56>/Constant'
     */
    0.66667F
  }
  ,

  /* End of '<S48>/Hall Value of 5' */

  /* Start of '<S48>/Hall Value of 4' */
  {
    /* Expression: single(0.5)
     * Referenced by: '<S55>/Constant'
     */
    0.5F
  }
  ,

  /* End of '<S48>/Hall Value of 4' */

  /* Start of '<S48>/Hall Value of 3' */
  {
    /* Expression: single(0.33333)
     * Referenced by: '<S54>/Constant'
     */
    0.33333F
  }
  ,

  /* End of '<S48>/Hall Value of 3' */

  /* Start of '<S48>/Hall Value of 2' */
  {
    /* Expression: single(0.16667)
     * Referenced by: '<S53>/Constant'
     */
    0.16667F
  }
  ,

  /* End of '<S48>/Hall Value of 2' */

  /* Start of '<S48>/Hall Value of 1' */
  {
    /* Expression: single(0)
     * Referenced by: '<S52>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S48>/Hall Value of 1' */

  /* Start of '<S49>/Hall Value of 7' */
  {
    /* Expression: single(0)
     * Referenced by: '<S65>/Constant'
     */
    0.0F
  }
  ,

  /* End of '<S49>/Hall Value of 7' */

  /* Start of '<S49>/Hall Value of 6' */
  {
    /* Expression: single(1)
     * Referenced by: '<S64>/Constant'
     */
    1.0F
  }
  ,

  /* End of '<S49>/Hall Value of 6' */

  /* Start of '<S49>/Hall Value of 5' */
  {
    /* Expression: single(0.83333)
     * Referenced by: '<S63>/Constant'
     */
    0.83333F
  }
  ,

  /* End of '<S49>/Hall Value of 5' */

  /* Start of '<S49>/Hall Value of 4' */
  {
    /* Expression: single(0.66667)
     * Referenced by: '<S62>/Constant'
     */
    0.66667F
  }
  ,

  /* End of '<S49>/Hall Value of 4' */

  /* Start of '<S49>/Hall Value of 3' */
  {
    /* Expression: single(0.5)
     * Referenced by: '<S61>/Constant'
     */
    0.5F
  }
  ,

  /* End of '<S49>/Hall Value of 3' */

  /* Start of '<S49>/Hall Value of 2' */
  {
    /* Expression: single(0.33333)
     * Referenced by: '<S60>/Constant'
     */
    0.33333F
  }
  ,

  /* End of '<S49>/Hall Value of 2' */

  /* Start of '<S49>/Hall Value of 1' */
  {
    /* Expression: single(0.16667)
     * Referenced by: '<S59>/Constant'
     */
    0.16667F
  }
  /* End of '<S49>/Hall Value of 1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
