/*
 * File: Motorparasmeters_types.h
 *
 * Code generated for Simulink model 'Motorparasmeters'.
 *
 * Model version                  : 8.24
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Nov 28 16:29:34 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Motorparasmeters_types_h_
#define Motorparasmeters_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "stm_adc_ll.h"

/* Custom Type definition for MATLABSystem: '<S20>/Analog to Digital Converter' */
#include "stm_adc_ll.h"
#include "stm_adc_ll.h"

/* Custom Type definition for MATLABSystem: '<S214>/PWM Output' */
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

#ifndef typedef_stm32cube_blocks_PWMOutput_Moto
#define typedef_stm32cube_blocks_PWMOutput_Moto

typedef struct tag_C3ug75osl8w3UN1OXa3ipB stm32cube_blocks_PWMOutput_Moto;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_Moto */

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

#ifndef typedef_stm32cube_blocks_AnalogInput_Mo
#define typedef_stm32cube_blocks_AnalogInput_Mo

typedef struct tag_ryp2yWF35eJG09Km2BkoGG stm32cube_blocks_AnalogInput_Mo;

#endif                             /* typedef_stm32cube_blocks_AnalogInput_Mo */

#ifndef struct_tag_wiywjhRn0JhvylthmapQgB
#define struct_tag_wiywjhRn0JhvylthmapQgB

struct tag_wiywjhRn0JhvylthmapQgB
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_wiywjhRn0JhvylthmapQgB */

#ifndef typedef_stm32cube_blocks_DigitalPortRea
#define typedef_stm32cube_blocks_DigitalPortRea

typedef struct tag_wiywjhRn0JhvylthmapQgB stm32cube_blocks_DigitalPortRea;

#endif                             /* typedef_stm32cube_blocks_DigitalPortRea */

#ifndef struct_tag_S5MMpcz8vT0FlmhmEl4q5C
#define struct_tag_S5MMpcz8vT0FlmhmEl4q5C

struct tag_S5MMpcz8vT0FlmhmEl4q5C
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_S5MMpcz8vT0FlmhmEl4q5C */

#ifndef typedef_stm32cube_blocks_DigitalPortWri
#define typedef_stm32cube_blocks_DigitalPortWri

typedef struct tag_S5MMpcz8vT0FlmhmEl4q5C stm32cube_blocks_DigitalPortWri;

#endif                             /* typedef_stm32cube_blocks_DigitalPortWri */

#ifndef struct_tag_K5QCAuLh2FF8FsZmLWzJxB
#define struct_tag_K5QCAuLh2FF8FsZmLWzJxB

struct tag_K5QCAuLh2FF8FsZmLWzJxB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[128];
};

#endif                                 /* struct_tag_K5QCAuLh2FF8FsZmLWzJxB */

#ifndef typedef_stm32cube_blocks_UARTWrite_Moto
#define typedef_stm32cube_blocks_UARTWrite_Moto

typedef struct tag_K5QCAuLh2FF8FsZmLWzJxB stm32cube_blocks_UARTWrite_Moto;

#endif                             /* typedef_stm32cube_blocks_UARTWrite_Moto */

/* Parameters (default storage) */
typedef struct Parameters_Motorparasmeters_ Parameters_Motorparasmeters;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Motorparasmeters RT_MODEL_Motorparasmeters;

#endif                                 /* Motorparasmeters_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
