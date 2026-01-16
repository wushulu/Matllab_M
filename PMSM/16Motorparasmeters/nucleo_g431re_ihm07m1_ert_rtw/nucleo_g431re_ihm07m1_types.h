/*
 * File: nucleo_g431re_ihm07m1_types.h
 *
 * Code generated for Simulink model 'nucleo_g431re_ihm07m1'.
 *
 * Model version                  : 8.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jan 16 10:47:28 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef nucleo_g431re_ihm07m1_types_h_
#define nucleo_g431re_ihm07m1_types_h_
#include "rtwtypes.h"
#include "stm_adc_ll.h"
#include "stm_timer_ll.h"

/* Custom Type definition for MATLABSystem: '<S311>/Analog to Digital Converter' */
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

#ifndef typedef_stm32cube_blocks_AnalogInput_nu
#define typedef_stm32cube_blocks_AnalogInput_nu

typedef struct tag_ryp2yWF35eJG09Km2BkoGG stm32cube_blocks_AnalogInput_nu;

#endif                             /* typedef_stm32cube_blocks_AnalogInput_nu */

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

/* Custom Type definition for MATLABSystem: '<S275>/PWM Output' */
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

#ifndef typedef_stm32cube_blocks_PWMOutput_nucl
#define typedef_stm32cube_blocks_PWMOutput_nucl

typedef struct tag_C3ug75osl8w3UN1OXa3ipB stm32cube_blocks_PWMOutput_nucl;

#endif                             /* typedef_stm32cube_blocks_PWMOutput_nucl */

#ifndef struct_tag_dDJgJ62VTmF2bvJ0E7hdrC
#define struct_tag_dDJgJ62VTmF2bvJ0E7hdrC

struct tag_dDJgJ62VTmF2bvJ0E7hdrC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T * UARTInternalBuffer;
};

#endif                                 /* struct_tag_dDJgJ62VTmF2bvJ0E7hdrC */

#ifndef typedef_stm32cube_blocks_UARTWrite_nucl
#define typedef_stm32cube_blocks_UARTWrite_nucl

typedef struct tag_dDJgJ62VTmF2bvJ0E7hdrC stm32cube_blocks_UARTWrite_nucl;

#endif                             /* typedef_stm32cube_blocks_UARTWrite_nucl */

#ifndef struct_tag_oT8gwZKC39t2mZKevTHsf
#define struct_tag_oT8gwZKC39t2mZKevTHsf

struct tag_oT8gwZKC39t2mZKevTHsf
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T * UARTInternalBuffer;
};

#endif                                 /* struct_tag_oT8gwZKC39t2mZKevTHsf */

#ifndef typedef_stm32cube_blocks_UARTRead_nucle
#define typedef_stm32cube_blocks_UARTRead_nucle

typedef struct tag_oT8gwZKC39t2mZKevTHsf stm32cube_blocks_UARTRead_nucle;

#endif                             /* typedef_stm32cube_blocks_UARTRead_nucle */

/* Forward declaration for rtModel */
typedef struct tag_RTM_nucleo_g431re_ihm07m1 RT_MODEL_nucleo_g431re_ihm07m1;

#endif                                 /* nucleo_g431re_ihm07m1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
