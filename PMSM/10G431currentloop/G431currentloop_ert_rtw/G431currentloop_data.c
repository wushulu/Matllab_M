/*
 * File: G431currentloop_data.c
 *
 * Code generated for Simulink model 'G431currentloop'.
 *
 * Model version                  : 1.61
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Mon Nov 11 12:27:47 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G431currentloop.h"

/* Block parameters (default storage) */
P_G431currentloop_T G431currentloop_P = {
  /* Mask Parameter: SlidingModeObserver_CurrentObse
   * Referenced by:
   *   '<S20>/Eta'
   *   '<S21>/Eta'
   */
  0.041689,

  /* Mask Parameter: SlidingModeObserver_CutoffFreq
   * Referenced by: '<S18>/PhaseDelay'
   */
  300.0,

  /* Mask Parameter: SlidingModeObserver_Disturbance
   * Referenced by:
   *   '<S30>/b_inv*g'
   *   '<S31>/b_inv*g'
   */
  0.85,

  /* Mask Parameter: DiscretePIControllerwithantiwin
   * Referenced by:
   *   '<S192>/Saturation'
   *   '<S177>/DeadZone'
   */
  -1.0F,

  /* Mask Parameter: DiscretePIControllerwithantiw_e
   * Referenced by:
   *   '<S139>/Saturation'
   *   '<S124>/DeadZone'
   */
  -1.0F,

  /* Mask Parameter: DiscretePIControllerwithantiw_a
   * Referenced by:
   *   '<S192>/Saturation'
   *   '<S177>/DeadZone'
   */
  1.0F,

  /* Mask Parameter: DiscretePIControllerwithantiw_l
   * Referenced by:
   *   '<S139>/Saturation'
   *   '<S124>/DeadZone'
   */
  1.0F,

  /* Mask Parameter: EnablePWMfor8seconds_const
   * Referenced by: '<S46>/Constant'
   */
  50000U,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S88>/Constant'
   */
  1U,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S89>/Constant'
   */
  1U,

  /* Mask Parameter: atan1_outputUnit
   * Referenced by: '<S43>/Constant'
   */
  1U,

  /* Expression: -1
   * Referenced by: '<S27>/Constant'
   */
  -1.0,

  /* Expression: 1
   * Referenced by: '<S27>/Constant1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S22>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S22>/One'
   */
  1.0,

  /* Computed Parameter: FilterConstant_Value
   * Referenced by: '<S22>/FilterConstant'
   */
  0.27377891540527344,

  /* Computed Parameter: OneMinusFilterConstant_Value
   * Referenced by: '<S22>/OneMinusFilterConstant'
   */
  0.72622108459472656,

  /* Expression: 0
   * Referenced by: '<S23>/a'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S23>/One'
   */
  1.0,

  /* Computed Parameter: FilterConstant_Value_l
   * Referenced by: '<S23>/FilterConstant'
   */
  0.27377891540527344,

  /* Computed Parameter: OneMinusFilterConstant_Value_e
   * Referenced by: '<S23>/OneMinusFilterConstant'
   */
  0.72622108459472656,

  /* Computed Parameter: Bias_Bias
   * Referenced by: '<S26>/Bias'
   */
  6.2831854820251465,

  /* Expression: 1
   * Referenced by: '<S44>/Bias'
   */
  1.0,

  /* Expression: 1/(2*pi)
   * Referenced by: '<S44>/Gain'
   */
  0.15915494309189535,

  /* Expression: 0
   * Referenced by: '<S44>/Switch'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S26>/Switch'
   */
  0.0,

  /* Expression: 1/sqrt(3)
   * Referenced by: '<S62>/one_by_sqrt3'
   */
  0.57735026918962584,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S71>/sqrt3_by_two'
   */
  0.8660254037844386,

  /* Expression: 1/2
   * Referenced by: '<S71>/one_by_two'
   */
  0.5,

  /* Expression: 1
   * Referenced by: '<S71>/Kc'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S71>/Kb'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S71>/Ka'
   */
  1.0,

  /* Expression: -0.5
   * Referenced by: '<S68>/one_by_two'
   */
  -0.5,

  /* Expression: 2/sqrt(3)
   * Referenced by: '<S67>/Gain'
   */
  1.1547005383792517,

  /* Expression: 0.5
   * Referenced by: '<S15>/Gain'
   */
  0.5,

  /* Computed Parameter: currentab_Y0
   * Referenced by: '<S2>/currentab'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S61>/Kalpha'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S61>/Kbeta'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S30>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S30>/Unit Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S2>/Delay5'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S20>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S30>/Delay1'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S22>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S22>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S34>/Unit Delay'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S19>/AlphaRelay'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S19>/AlphaRelay'
   */
  -0.02,

  /* Expression: 0
   * Referenced by: '<S31>/Unit Delay1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S31>/Unit Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S21>/Delay'
   */
  0.0,

  /* Expression: 0.0
   * Referenced by: '<S31>/Delay1'
   */
  0.0,

  /* Expression: FilterConstantInputType
   * Referenced by: '<S23>/UseInputPort'
   */
  1.0,

  /* Expression: 1
   * Referenced by: '<S23>/Switch1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S37>/Unit Delay'
   */
  0.0,

  /* Expression: 0.02
   * Referenced by: '<S19>/BetaRelay'
   */
  0.02,

  /* Expression: -0.02
   * Referenced by: '<S19>/BetaRelay'
   */
  -0.02,

  /* Expression: (4294967296/6.2832)
   * Referenced by: '<S25>/PositionToCount'
   */
  6.8356367710720658E+8,

  /* Expression: 2051
   * Referenced by: '<S4>/Testing get offset1'
   */
  2051.0,

  /* Expression: 2075
   * Referenced by: '<S4>/Testing get offset'
   */
  2075.0,

  /* Expression: 1
   * Referenced by: '<S5>/Pulse Generator'
   */
  1.0,

  /* Expression: 10
   * Referenced by: '<S5>/Pulse Generator'
   */
  10.0,

  /* Expression: 5
   * Referenced by: '<S5>/Pulse Generator'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S5>/Pulse Generator'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory13'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory14'
   */
  0.0,

  /* Computed Parameter: a_Value_j
   * Referenced by: '<S24>/a'
   */
  0.0F,

  /* Computed Parameter: One_Value_f
   * Referenced by: '<S24>/One'
   */
  1.0F,

  /* Expression: Filter_constant
   * Referenced by: '<S24>/FilterConstant'
   */
  0.005F,

  /* Expression: 1 - Filter_constant
   * Referenced by: '<S24>/OneMinusFilterConstant'
   */
  0.995F,

  /* Computed Parameter: AngleConversion_Gain
   * Referenced by: '<S18>/AngleConversion'
   */
  0.159154937F,

  /* Computed Parameter: scaleOut_Gain
   * Referenced by: '<S52>/scaleOut'
   */
  1.0F,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S50>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant2_Value
   * Referenced by: '<S51>/Constant2'
   */
  0.0008F,

  /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
   * Referenced by: '<S51>/Saturate to 'motor.calibSpeed' RPM'
   */
  15.0F,

  /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
   * Referenced by: '<S51>/Saturate to 'motor.calibSpeed' RPM'
   */
  0.0F,

  /* Computed Parameter: Multiply1_Gain
   * Referenced by: '<S51>/Multiply1'
   */
  0.0002F,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S54>/Out1'
   */
  0.0F,

  /* Computed Parameter: theta_e_Y0
   * Referenced by: '<S53>/theta_e'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S94>/Constant'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S94>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Switch1_Threshold_b
   * Referenced by: '<S94>/Switch1'
   */
  0.0F,

  /* Computed Parameter: Switch_Threshold_g
   * Referenced by: '<S94>/Switch'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S92>/Gain'
   */
  -1.0F,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S86>/Constant'
   */
  1.0F,

  /* Computed Parameter: ReplaceInport_satLim_Value
   * Referenced by: '<S79>/ReplaceInport_satLim'
   */
  0.0F,

  /* Computed Parameter: Constant3_Value
   * Referenced by: '<S84>/Constant3'
   */
  0.95F,

  /* Computed Parameter: Constant1_Value_e
   * Referenced by: '<S15>/Constant1'
   */
  0.5F,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<S15>/Gain1'
   */
  100.0F,

  /* Computed Parameter: theta_Y0
   * Referenced by: '<S2>/theta'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S76>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_b
   * Referenced by: '<S122>/Constant1'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_ex
   * Referenced by: '<S175>/Constant1'
   */
  0.0F,

  /* Computed Parameter: Constant2_Value_c
   * Referenced by: '<S14>/Constant2'
   */
  0.4F,

  /* Computed Parameter: ADvoltage_Gain
   * Referenced by: '<S45>/AD voltage'
   */
  0.000805664051F,

  /* Computed Parameter: OP_GainR_shunt_Gain
   * Referenced by: '<S45>/OP_Gain*R_shunt'
   */
  0.604545F,

  /* Computed Parameter: OP_GainR_shunt1_Gain
   * Referenced by: '<S45>/OP_Gain*R_shunt1'
   */
  -1.0F,

  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S59>/sine_table_values'
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

  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S30>/a'
   */
  0.914672494F,

  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S31>/a'
   */
  0.914672494F,

  /* Computed Parameter: Delay_InitialCondition_m4
   * Referenced by: '<S18>/Delay'
   */
  0.0F,

  /* Computed Parameter: scaleIn_Gain
   * Referenced by: '<S52>/scaleIn'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_nx
   * Referenced by: '<S52>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: convert_pu_Gain
   * Referenced by: '<S75>/convert_pu'
   */
  1.0F,

  /* Computed Parameter: indexing_Gain
   * Referenced by: '<S59>/indexing'
   */
  800.0F,

  /* Computed Parameter: Kp_Value
   * Referenced by: '<S60>/Kp'
   */
  0.0179F,

  /* Computed Parameter: Vq_OpenLoop_Value
   * Referenced by: '<S81>/Vq_OpenLoop'
   */
  0.0F,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S185>/Integrator'
   */
  1.0F,

  /* Computed Parameter: Constant3_Value_k
   * Referenced by: '<S14>/Constant3'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S80>/Constant'
   */
  0.0F,

  /* Computed Parameter: Integrator_gainval_m
   * Referenced by: '<S132>/Integrator'
   */
  1.0F,

  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S20>/b'
   */
  0.123379149F,

  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S20>/a'
   */
  0.914672494F,

  /* Expression: single((1-exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))*double(MaxStatorVoltage)/(double(StatorResistance)*double(MaxStatorCurrent)))
   * Referenced by: '<S21>/b'
   */
  0.123379149F,

  /* Expression: single(exp(double(-double(StatorResistance)*double(BlkSampleTime(1))/double(StatorInductance))))
   * Referenced by: '<S21>/a'
   */
  0.914672494F,

  /* Computed Parameter: SpeedGain_Gain
   * Referenced by: '<S25>/SpeedGain'
   */
  4.85063822E-10F,

  /* Computed Parameter: UseInputPort_Value_o
   * Referenced by: '<S24>/UseInputPort'
   */
  1.0F,

  /* Computed Parameter: Switch1_Threshold_k
   * Referenced by: '<S24>/Switch1'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_e
   * Referenced by: '<S40>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<S49>/Data Store Memory'
   */
  0.0F,

  /* Computed Parameter: Ki_Value
   * Referenced by: '<S60>/Ki'
   */
  0.00158F,

  /* Computed Parameter: Clamping_zero_Value
   * Referenced by: '<S122>/Clamping_zero'
   */
  0.0F,

  /* Computed Parameter: Clamping_zero_Value_c
   * Referenced by: '<S175>/Clamping_zero'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_hu
   * Referenced by: '<S47>/Constant'
   */
  1U,

  /* Computed Parameter: Constant15_Value
   * Referenced by: '<S48>/Constant15'
   */
  0U,

  /* Computed Parameter: Countfor2sec_Value
   * Referenced by: '<S49>/Count for 2 sec'
   */
  10000U,

  /* Computed Parameter: Delay_InitialCondition_i
   * Referenced by: '<S25>/Delay'
   */
  0U,

  /* Computed Parameter: DataStoreMemory_InitialValue_k
   * Referenced by: '<S13>/Data Store Memory'
   */
  0U,

  /* Computed Parameter: Sign_Y0
   * Referenced by: '<S27>/Sign'
   */
  0,

  /* Computed Parameter: offset_Value
   * Referenced by: '<S59>/offset'
   */
  { 1, 0, 201, 200 },

  /* Computed Parameter: Switch_Threshold_b
   * Referenced by: '<S43>/Switch'
   */
  1U,

  /* Computed Parameter: Offset_Value
   * Referenced by: '<S64>/Offset'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_k
   * Referenced by: '<S64>/Switch'
   */
  1U,

  /* Computed Parameter: Offset_Value_p
   * Referenced by: '<S73>/Offset'
   */
  0U,

  /* Computed Parameter: Switch_Threshold_f
   * Referenced by: '<S73>/Switch'
   */
  1U,

  /* Computed Parameter: ReplaceInport_satMethod_Value
   * Referenced by: '<S79>/ReplaceInport_satMethod'
   */
  0U,

  /* Computed Parameter: ChosenMethod_Value
   * Referenced by: '<S84>/ChosenMethod'
   */
  3U,

  /* Computed Parameter: stop_Value
   * Referenced by: '<S15>/stop'
   */
  0U,

  /* Computed Parameter: enableInportSatMethod_Value
   * Referenced by: '<S84>/enableInportSatMethod'
   */
  0U,

  /* Computed Parameter: enableInportSatLim_Value
   * Referenced by: '<S84>/enableInportSatLim'
   */
  0U,

  /* Computed Parameter: Out1_Y0_h
   * Referenced by: '<S7>/Out1'
   */
  false,

  /* Expression: true
   * Referenced by: '<S7>/Unit Delay'
   */
  true,

  /* Computed Parameter: Delay_InitialCondition_f
   * Referenced by: '<S53>/Delay'
   */
  false,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S53>/Constant'
   */
  true,

  /* Computed Parameter: AlphaRelay_YOn
   * Referenced by: '<S19>/AlphaRelay'
   */
  true,

  /* Computed Parameter: AlphaRelay_YOff
   * Referenced by: '<S19>/AlphaRelay'
   */
  false,

  /* Computed Parameter: BetaRelay_YOn
   * Referenced by: '<S19>/BetaRelay'
   */
  true,

  /* Computed Parameter: BetaRelay_YOff
   * Referenced by: '<S19>/BetaRelay'
   */
  false,

  /* Computed Parameter: Constant_Reset_Value
   * Referenced by: '<S52>/Constant_Reset'
   */
  false,

  /* Expression: false
   * Referenced by: '<S1>/Unit Delay'
   */
  false,

  /* Computed Parameter: DataStoreMemory9_InitialValue
   * Referenced by: '<Root>/Data Store Memory9'
   */
  false,

  /* Computed Parameter: Constant_Value_m
   * Referenced by: '<S122>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_j
   * Referenced by: '<S122>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_j
   * Referenced by: '<S122>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value
   * Referenced by: '<S122>/Constant4'
   */
  -1,

  /* Computed Parameter: Constant_Value_c
   * Referenced by: '<S175>/Constant'
   */
  1,

  /* Computed Parameter: Constant2_Value_g
   * Referenced by: '<S175>/Constant2'
   */
  -1,

  /* Computed Parameter: Constant3_Value_m
   * Referenced by: '<S175>/Constant3'
   */
  1,

  /* Computed Parameter: Constant4_Value_p
   * Referenced by: '<S175>/Constant4'
   */
  -1
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
