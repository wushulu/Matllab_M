/*
 * File: mcb_pmsm_foc_sensorless_nucleo_f401re_data.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_nucleo_f401re'.
 *
 * Model version                  : 8.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Nov  8 22:37:46 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_sensorless_nucleo_f401re.h"

/* Constant parameters (default storage) */
const ConstParam_mcb_pmsm_foc_sensorl mcb_pmsm_foc_sensorless__ConstP = {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S21>/sine_table_values'
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
    0.999722421F, 0.999876618F, 0.999969184F, 1.0F, 0.999969184F }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
