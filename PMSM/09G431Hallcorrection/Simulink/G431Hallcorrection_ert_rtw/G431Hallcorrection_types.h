/*
 * File: G431Hallcorrection_types.h
 *
 * Code generated for Simulink model 'G431Hallcorrection'.
 *
 * Model version                  : 1.20
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Oct 30 13:06:54 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef G431Hallcorrection_types_h_
#define G431Hallcorrection_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"

/* Custom Type definition for MATLABSystem: '<S15>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"

/* Custom Type definition for MATLABSystem: '<S85>/PWM Output' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_C3ug75osl8w3UN1OXa3ipB
#define struct_tag_C3ug75osl8w3UN1OXa3ipB

struct tag_C3ug75osl8w3UN1OXa3ipB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_C3ug75osl8w3UN1OXa3ipB */

#ifndef typedef_stm32cube_blocks_PWMOutput_G4_T
#define typedef_stm32cube_blocks_PWMOutput_G4_T

typedef struct tag_C3ug75osl8w3UN1OXa3ipB stm32cube_blocks_PWMOutput_G4_T;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_G4_T */

#ifndef struct_tag_ryp2yWF35eJG09Km2BkoGG
#define struct_tag_ryp2yWF35eJG09Km2BkoGG

struct tag_ryp2yWF35eJG09Km2BkoGG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  ADC_Type_T* ADCHandle;
};

#endif                                 /* struct_tag_ryp2yWF35eJG09Km2BkoGG */

#ifndef typedef_stm32cube_blocks_AnalogInput__T
#define typedef_stm32cube_blocks_AnalogInput__T

typedef struct tag_ryp2yWF35eJG09Km2BkoGG stm32cube_blocks_AnalogInput__T;

#endif                             /* typedef_stm32cube_blocks_AnalogInput__T */

#ifndef struct_tag_wiywjhRn0JhvylthmapQgB
#define struct_tag_wiywjhRn0JhvylthmapQgB

struct tag_wiywjhRn0JhvylthmapQgB
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_wiywjhRn0JhvylthmapQgB */

#ifndef typedef_stm32cube_blocks_DigitalPortR_T
#define typedef_stm32cube_blocks_DigitalPortR_T

typedef struct tag_wiywjhRn0JhvylthmapQgB stm32cube_blocks_DigitalPortR_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortR_T */

#ifndef struct_tag_BAqjeaqOiaF5foOwXEapOH
#define struct_tag_BAqjeaqOiaF5foOwXEapOH

struct tag_BAqjeaqOiaF5foOwXEapOH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_BAqjeaqOiaF5foOwXEapOH */

#ifndef typedef_stm32cube_blocks_TimerCapture_T
#define typedef_stm32cube_blocks_TimerCapture_T

typedef struct tag_BAqjeaqOiaF5foOwXEapOH stm32cube_blocks_TimerCapture_T;

#endif                             /* typedef_stm32cube_blocks_TimerCapture_T */

#ifndef struct_tag_S5MMpcz8vT0FlmhmEl4q5C
#define struct_tag_S5MMpcz8vT0FlmhmEl4q5C

struct tag_S5MMpcz8vT0FlmhmEl4q5C
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_S5MMpcz8vT0FlmhmEl4q5C */

#ifndef typedef_stm32cube_blocks_DigitalPortW_T
#define typedef_stm32cube_blocks_DigitalPortW_T

typedef struct tag_S5MMpcz8vT0FlmhmEl4q5C stm32cube_blocks_DigitalPortW_T;

#endif                             /* typedef_stm32cube_blocks_DigitalPortW_T */

/* Parameters for system: '<S49>/Hall Value of 1' */
typedef struct P_HallValueof1_G431Hallcorrec_T_ P_HallValueof1_G431Hallcorrec_T;

/* Parameters for system: '<S146>/If Action Subsystem6' */
typedef struct P_IfActionSubsystem6_G431Hall_T_ P_IfActionSubsystem6_G431Hall_T;

/* Parameters for system: '<S146>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_G431Hal_g_T_ P_IfActionSubsystem_G431Hal_g_T;

/* Parameters for system: '<S144>/Valid Halls' */
typedef struct P_ValidHalls_G431Hallcorrecti_T_ P_ValidHalls_G431Hallcorrecti_T;

/* Parameters for system: '<S144>/Bad hall (glitch or wrong connection)' */
typedef struct P_Badhallglitchorwrongconnect_T_ P_Badhallglitchorwrongconnect_T;

/* Parameters (default storage) */
typedef struct P_G431Hallcorrection_T_ P_G431Hallcorrection_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_G431Hallcorrection_T RT_MODEL_G431Hallcorrection_T;

#endif                                 /* G431Hallcorrection_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */