/*
 * File: G431debug_data.c
 *
 * Code generated for Simulink model 'G431debug'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Oct 23 10:58:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "G431debug.h"

/* Block parameters (default storage) */
P_G431debug_T G431debug_P = {
  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S70>/Constant'
   */
  0.01F,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S71>/Constant'
   */
  0.99F,

  /* Mask Parameter: Disablehostafter42seconds_const
   * Referenced by: '<S19>/Constant'
   */
  420000U,

  /* Mask Parameter: EnablePWMfor40seconds_const
   * Referenced by: '<S20>/Constant'
   */
  4000000U,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S16>/FixPt Switch'
   */
  20000U,

  /* Mask Parameter: SoftwareWatchdogTimer_maxCount
   * Referenced by: '<S31>/Delay One Step'
   */
  5000U,

  /* Expression: EnableSecondOrder
   * Referenced by: '<S46>/Constant'
   */
  2.0,

  /* Expression: 0.5
   * Referenced by: '<S67>/Constant1'
   */
  0.5,

  /* Expression: 100
   * Referenced by: '<S67>/Gain1'
   */
  100.0,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S18>/Discrete-Time Integrator'
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
   * Referenced by: '<Root>/Data Store Memory11'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Data Store Memory9'
   */
  0.0,

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
   * Referenced by: '<S24>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant1_Value_g
   * Referenced by: '<S25>/Constant1'
   */
  0.0002F,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S25>/Delay'
   */
  0.0F,

  /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Up
   * Referenced by: '<S25>/Saturate to 'motor.calibSpeed' RPM'
   */
  6.0F,

  /* Computed Parameter: SaturatetomotorcalibSpeedRPM_Lo
   * Referenced by: '<S25>/Saturate to 'motor.calibSpeed' RPM'
   */
  0.0F,

  /* Computed Parameter: Multiply_Gain
   * Referenced by: '<S25>/Multiply'
   */
  0.0001F,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S28>/Out1'
   */
  0.0F,

  /* Computed Parameter: theta_e_Y0
   * Referenced by: '<S27>/theta_e'
   */
  0.0F,

  /* Computed Parameter: Theta_Y0
   * Referenced by: '<S17>/Theta'
   */
  0.0F,

  /* Computed Parameter: scaleIn_Gain
   * Referenced by: '<S26>/scaleIn'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition
   * Referenced by: '<S26>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: scaleOut_Gain
   * Referenced by: '<S26>/scaleOut'
   */
  1.0F,

  /* Computed Parameter: Constant_Value_g
   * Referenced by: '<S50>/Constant'
   */
  1.0F,

  /* Computed Parameter: Gain1_Gain_k
   * Referenced by: '<S50>/Gain1'
   */
  0.5F,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<S50>/Gain'
   */
  0.166666672F,

  /* Computed Parameter: Gain_Gain_j
   * Referenced by: '<S49>/Gain'
   */
  0.166666672F,

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

  /* Computed Parameter: Constant_Value_n
   * Referenced by: '<S32>/Constant'
   */
  0.0F,

  /* Computed Parameter: a_Value
   * Referenced by: '<S73>/a'
   */
  0.0F,

  /* Computed Parameter: One_Value
   * Referenced by: '<S73>/One'
   */
  1.0F,

  /* Computed Parameter: FilterConstant_Value
   * Referenced by: '<S73>/FilterConstant'
   */
  0.5F,

  /* Computed Parameter: OneMinusFilterConstant_Value
   * Referenced by: '<S73>/OneMinusFilterConstant'
   */
  0.5F,

  /* Computed Parameter: Offset_Y0
   * Referenced by: '<S72>/Offset'
   */
  0.0F,

  /* Computed Parameter: UseInputPort_Value
   * Referenced by: '<S73>/UseInputPort'
   */
  1.0F,

  /* Computed Parameter: Switch1_Threshold
   * Referenced by: '<S73>/Switch1'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_l
   * Referenced by: '<S76>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: Delay_InitialCondition_b
   * Referenced by: '<S65>/Delay'
   */
  0.0F,

  /* Computed Parameter: sqrt3_by_two_Gain
   * Referenced by: '<S95>/sqrt3_by_two'
   */
  0.866025388F,

  /* Computed Parameter: one_by_two_Gain
   * Referenced by: '<S95>/one_by_two'
   */
  0.5F,

  /* Computed Parameter: Kc_Gain
   * Referenced by: '<S95>/Kc'
   */
  1.0F,

  /* Computed Parameter: Kb_Gain
   * Referenced by: '<S95>/Kb'
   */
  1.0F,

  /* Computed Parameter: Ka_Gain
   * Referenced by: '<S95>/Ka'
   */
  1.0F,

  /* Computed Parameter: one_by_two_Gain_k
   * Referenced by: '<S92>/one_by_two'
   */
  -0.5F,

  /* Computed Parameter: Gain_Gain_d
   * Referenced by: '<S91>/Gain'
   */
  1.15470052F,

  /* Computed Parameter: Gain_Gain_m
   * Referenced by: '<S67>/Gain'
   */
  0.5F,

  /* Computed Parameter: Offset_Y0_c
   * Referenced by: '<S68>/Offset'
   */
  0.0F,

  /* Computed Parameter: poswlfilter_Y0
   * Referenced by: '<S96>/poswlfilter'
   */
  0.0F,

  /* Computed Parameter: Delay_InitialCondition_l
   * Referenced by: '<S96>/Delay'
   */
  0.0F,

  /* Computed Parameter: Delay1_InitialCondition
   * Referenced by: '<S96>/Delay1'
   */
  0.0F,

  /* Computed Parameter: Delay2_InitialCondition
   * Referenced by: '<S96>/Delay2'
   */
  0.0F,

  /* Computed Parameter: Delay3_InitialCondition
   * Referenced by: '<S96>/Delay3'
   */
  0.0F,

  /* Computed Parameter: Delay4_InitialCondition
   * Referenced by: '<S96>/Delay4'
   */
  0.0F,

  /* Computed Parameter: Gain_Gain_da
   * Referenced by: '<S96>/Gain'
   */
  0.166666672F,

  /* Computed Parameter: a_Value_h
   * Referenced by: '<S97>/a'
   */
  0.0F,

  /* Computed Parameter: One_Value_c
   * Referenced by: '<S97>/One'
   */
  1.0F,

  /* Computed Parameter: FilterConstant_Value_i
   * Referenced by: '<S97>/FilterConstant'
   */
  0.001F,

  /* Computed Parameter: OneMinusFilterConstant_Value_a
   * Referenced by: '<S97>/OneMinusFilterConstant'
   */
  0.999F,

  /* Computed Parameter: a_Value_k
   * Referenced by: '<S98>/a'
   */
  0.0F,

  /* Computed Parameter: One_Value_a
   * Referenced by: '<S98>/One'
   */
  1.0F,

  /* Computed Parameter: FilterConstant_Value_a
   * Referenced by: '<S98>/FilterConstant'
   */
  0.003F,

  /* Computed Parameter: OneMinusFilterConstant_Value_d
   * Referenced by: '<S98>/OneMinusFilterConstant'
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
   * Referenced by: '<S79>/Constant'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_IC
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  0.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_UpperSat
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  60.0F,

  /* Computed Parameter: DiscreteTimeIntegrator_LowerSat
   * Referenced by: '<S18>/Discrete-Time Integrator'
   */
  -60.0F,

  /* Computed Parameter: Merge_InitialOutput_p
   * Referenced by: '<S29>/Merge'
   */
  0.0F,

  /* Expression: single(360)
   * Referenced by: '<S29>/PositionUnit'
   */
  360.0F,

  /* Computed Parameter: Vd_Ref_Value
   * Referenced by: '<S69>/Vd_Ref'
   */
  0.0F,

  /* Computed Parameter: Vq_Value
   * Referenced by: '<S69>/Vq'
   */
  0.18F,

  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S66>/sine_table_values'
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
   * Referenced by: '<S78>/convert_pu'
   */
  1.0F,

  /* Computed Parameter: indexing_Gain
   * Referenced by: '<S66>/indexing'
   */
  800.0F,

  /* Computed Parameter: UseInputPort_Value_j
   * Referenced by: '<S98>/UseInputPort'
   */
  1.0F,

  /* Computed Parameter: Switch1_Threshold_p
   * Referenced by: '<S98>/Switch1'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_le
   * Referenced by: '<S104>/Unit Delay'
   */
  0.0F,

  /* Computed Parameter: UseInputPort_Value_i
   * Referenced by: '<S97>/UseInputPort'
   */
  1.0F,

  /* Computed Parameter: Switch1_Threshold_b
   * Referenced by: '<S97>/Switch1'
   */
  1.0F,

  /* Computed Parameter: UnitDelay_InitialCondition_d
   * Referenced by: '<S101>/Unit Delay'
   */
  0.0F,

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
   * Referenced by: '<S23>/Count'
   */
  0U,

  /* Computed Parameter: Constant_Value_j
   * Referenced by: '<S23>/Constant'
   */
  1U,

  /* Computed Parameter: Delay_InitialCondition_e
   * Referenced by: '<S23>/Delay'
   */
  0U,

  /* Computed Parameter: Countfor2sec_Value
   * Referenced by: '<S22>/Count for 2 sec'
   */
  25000U,

  /* Computed Parameter: offset_Value
   * Referenced by: '<S66>/offset'
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

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S16>/Constant'
   */
  0U,

  /* Expression: uint16(10*ClkFreq/(PolePairs*MinSpeed))
   * Referenced by: '<S33>/SpeedConst'
   */
  50000U,

  /* Computed Parameter: PositionEnable_Value
   * Referenced by: '<S33>/PositionEnable'
   */
  1U,

  /* Computed Parameter: WatchDog_Value
   * Referenced by: '<S29>/WatchDog'
   */
  0U,

  /* Computed Parameter: speedcheck_Threshold
   * Referenced by: '<S34>/speed check'
   */
  50000U,

  /* Computed Parameter: stop_Value
   * Referenced by: '<S67>/stop'
   */
  0U,

  /* Computed Parameter: Offset_Value
   * Referenced by: '<S88>/Offset'
   */
  0U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S88>/Switch'
   */
  1U,

  /* Computed Parameter: ct_Y0
   * Referenced by: '<S1>/ct'
   */
  0U,

  /* Computed Parameter: Constant_Value_mo
   * Referenced by: '<S35>/Constant'
   */
  0U,

  /* Computed Parameter: Order_Value
   * Referenced by: '<S30>/Order'
   */
  1U,

  /* Computed Parameter: Switch_Threshold_h
   * Referenced by: '<S30>/Switch'
   */
  0U,

  /* Computed Parameter: speedCountDelay_InitialConditio
   * Referenced by: '<S30>/speedCountDelay'
   */
  0U,

  /* Computed Parameter: Constant_Value_p
   * Referenced by: '<S34>/Constant'
   */
  0U,

  /* Computed Parameter: Constant2_Value_p3
   * Referenced by: '<S31>/Constant2'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S15>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S9>/Output'
   */
  0U,

  /* Computed Parameter: Constant_Value_l5
   * Referenced by: '<S131>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S106>/Constant'
   */
  1U,

  /* Computed Parameter: Constant_Value_pl
   * Referenced by: '<S156>/Constant'
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
   * Referenced by: '<S27>/Delay'
   */
  false,

  /* Computed Parameter: Constant_Value_f
   * Referenced by: '<S27>/Constant'
   */
  true,

  /* Computed Parameter: EnPWM_Y0
   * Referenced by: '<S17>/EnPWM'
   */
  false,

  /* Computed Parameter: Constant_Reset_Value
   * Referenced by: '<S26>/Constant_Reset'
   */
  false,

  /* Computed Parameter: validityDelay_InitialCondition
   * Referenced by: '<S30>/validityDelay'
   */
  false,

  /* Computed Parameter: DelayOneStep1_InitialCondition
   * Referenced by: '<S31>/Delay One Step1'
   */
  true,

  /* Computed Parameter: Gain_Gain_de
   * Referenced by: '<S130>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_jm
   * Referenced by: '<S105>/Gain'
   */
  128U,

  /* Computed Parameter: Gain_Gain_e
   * Referenced by: '<S155>/Gain'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_n
   * Referenced by: '<S130>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_o
   * Referenced by: '<S105>/Gain1'
   */
  128U,

  /* Computed Parameter: Gain1_Gain_oh
   * Referenced by: '<S155>/Gain1'
   */
  128U,

  /* Computed Parameter: DataStoreMemory_InitialValue
   * Referenced by: '<Root>/Data Store Memory'
   */
  0U,

  /* Start of '<S167>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S168>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S168>/Constant1'
     */
    false
  }
  ,

  /* End of '<S167>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S167>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S169>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S178>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S169>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S169>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S169>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S169>/Constant'
     */
    false,

    /* Start of '<S144>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S175>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S175>/next'
       */
      5U
    }
    ,

    /* End of '<S144>/If Action Subsystem5' */

    /* Start of '<S144>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S174>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S174>/next'
       */
      1U
    }
    ,

    /* End of '<S144>/If Action Subsystem4' */

    /* Start of '<S144>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S173>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S173>/next'
       */
      3U
    }
    ,

    /* End of '<S144>/If Action Subsystem3' */

    /* Start of '<S144>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S172>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S172>/next'
       */
      2U
    }
    ,

    /* End of '<S144>/If Action Subsystem2' */

    /* Start of '<S144>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S171>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S171>/next'
       */
      6U
    }
    ,

    /* End of '<S144>/If Action Subsystem1' */

    /* Start of '<S144>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S170>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S170>/next'
       */
      4U
    }
    ,

    /* End of '<S144>/If Action Subsystem' */

    /* Start of '<S144>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S177>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S177>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S144>/If Action Subsystem7' */

    /* Start of '<S144>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S176>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S176>/Constant1'
       */
      0U
    }
    /* End of '<S144>/If Action Subsystem6' */
  }
  ,

  /* End of '<S167>/Valid Halls' */

  /* Start of '<S117>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S118>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S118>/Constant1'
     */
    false
  }
  ,

  /* End of '<S117>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S117>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S119>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S128>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S119>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S119>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S119>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S119>/Constant'
     */
    false,

    /* Start of '<S144>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S125>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S125>/next'
       */
      5U
    }
    ,

    /* End of '<S144>/If Action Subsystem5' */

    /* Start of '<S144>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S124>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S124>/next'
       */
      1U
    }
    ,

    /* End of '<S144>/If Action Subsystem4' */

    /* Start of '<S144>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S123>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S123>/next'
       */
      3U
    }
    ,

    /* End of '<S144>/If Action Subsystem3' */

    /* Start of '<S144>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S122>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S122>/next'
       */
      2U
    }
    ,

    /* End of '<S144>/If Action Subsystem2' */

    /* Start of '<S144>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S121>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S121>/next'
       */
      6U
    }
    ,

    /* End of '<S144>/If Action Subsystem1' */

    /* Start of '<S144>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S120>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S120>/next'
       */
      4U
    }
    ,

    /* End of '<S144>/If Action Subsystem' */

    /* Start of '<S144>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S127>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S127>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S144>/If Action Subsystem7' */

    /* Start of '<S144>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S126>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S126>/Constant1'
       */
      0U
    }
    /* End of '<S144>/If Action Subsystem6' */
  }
  ,

  /* End of '<S117>/Valid Halls' */

  /* Start of '<S142>/Bad hall (glitch or wrong connection)' */
  {
    /* Computed Parameter: Constant_Value
     * Referenced by: '<S143>/Constant'
     */
    1U,

    /* Computed Parameter: Constant1_Value
     * Referenced by: '<S143>/Constant1'
     */
    false
  }
  ,

  /* End of '<S142>/Bad hall (glitch or wrong connection)' */

  /* Start of '<S142>/Valid Halls' */
  {
    /* Computed Parameter: Merge2_InitialOutput
     * Referenced by: '<S144>/Merge2'
     */
    0,

    /* Computed Parameter: Constant_Value
     * Referenced by: '<S153>/Constant'
     */
    1U,

    /* Computed Parameter: Merge_InitialOutput
     * Referenced by: '<S144>/Merge'
     */
    0U,

    /* Computed Parameter: Merge1_InitialOutput
     * Referenced by: '<S144>/Merge1'
     */
    0U,

    /* Computed Parameter: Merge3_InitialOutput
     * Referenced by: '<S144>/Merge3'
     */
    0U,

    /* Computed Parameter: Constant_Value_k
     * Referenced by: '<S144>/Constant'
     */
    false,

    /* Start of '<S144>/If Action Subsystem5' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S150>/previous'
       */
      3U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S150>/next'
       */
      5U
    }
    ,

    /* End of '<S144>/If Action Subsystem5' */

    /* Start of '<S144>/If Action Subsystem4' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S149>/previous'
       */
      2U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S149>/next'
       */
      1U
    }
    ,

    /* End of '<S144>/If Action Subsystem4' */

    /* Start of '<S144>/If Action Subsystem3' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S148>/previous'
       */
      6U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S148>/next'
       */
      3U
    }
    ,

    /* End of '<S144>/If Action Subsystem3' */

    /* Start of '<S144>/If Action Subsystem2' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S147>/previous'
       */
      4U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S147>/next'
       */
      2U
    }
    ,

    /* End of '<S144>/If Action Subsystem2' */

    /* Start of '<S144>/If Action Subsystem1' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S146>/previous'
       */
      5U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S146>/next'
       */
      6U
    }
    ,

    /* End of '<S144>/If Action Subsystem1' */

    /* Start of '<S144>/If Action Subsystem' */
    {
      /* Computed Parameter: previous_Value
       * Referenced by: '<S145>/previous'
       */
      1U,

      /* Computed Parameter: next_Value
       * Referenced by: '<S145>/next'
       */
      4U
    }
    ,

    /* End of '<S144>/If Action Subsystem' */

    /* Start of '<S144>/If Action Subsystem7' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S152>/Constant'
       */
      -1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S152>/Constant1'
       */
      0U
    }
    ,

    /* End of '<S144>/If Action Subsystem7' */

    /* Start of '<S144>/If Action Subsystem6' */
    {
      /* Computed Parameter: Constant_Value
       * Referenced by: '<S151>/Constant'
       */
      1,

      /* Computed Parameter: Constant1_Value
       * Referenced by: '<S151>/Constant1'
       */
      0U
    }
    /* End of '<S144>/If Action Subsystem6' */
  }
  ,

  /* End of '<S142>/Valid Halls' */

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
  /* End of '<S48>/Hall Value of 1' */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */