/*
 * File: HalltimerInterface_types.h
 *
 * Code generated for Simulink model 'HalltimerInterface'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Oct 17 16:59:44 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef HalltimerInterface_types_h_
#define HalltimerInterface_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"

/* Custom Type definition for MATLABSystem: '<S3>/Timer Capture' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_gjYZJ1pkpPfKYOJ6xxN5fC
#define struct_tag_gjYZJ1pkpPfKYOJ6xxN5fC

struct tag_gjYZJ1pkpPfKYOJ6xxN5fC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
  uint16_T TimerInternalBuffer[16];
};

#endif                                 /* struct_tag_gjYZJ1pkpPfKYOJ6xxN5fC */

#ifndef typedef_stm32cube_blocks_TimerCapture_T
#define typedef_stm32cube_blocks_TimerCapture_T

typedef struct tag_gjYZJ1pkpPfKYOJ6xxN5fC stm32cube_blocks_TimerCapture_T;

#endif                             /* typedef_stm32cube_blocks_TimerCapture_T */

/* Custom Type definition for MATLABSystem: '<S18>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"
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

#ifndef typedef_stm32cube_blocks_PWMOutput_Ha_T
#define typedef_stm32cube_blocks_PWMOutput_Ha_T

typedef struct tag_C3ug75osl8w3UN1OXa3ipB stm32cube_blocks_PWMOutput_Ha_T;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_Ha_T */

/* Parameters (default storage) */
typedef struct P_HalltimerInterface_T_ P_HalltimerInterface_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_HalltimerInterface_T RT_MODEL_HalltimerInterface_T;

#endif                                 /* HalltimerInterface_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
