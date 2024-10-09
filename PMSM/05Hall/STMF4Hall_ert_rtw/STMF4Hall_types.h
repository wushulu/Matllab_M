/*
 * File: STMF4Hall_types.h
 *
 * Code generated for Simulink model 'STMF4Hall'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Oct  8 09:01:53 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef STMF4Hall_types_h_
#define STMF4Hall_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
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

/* Custom Type definition for MATLABSystem: '<Root>/Timer1' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_lVYsrGoTQYYB21wZ5vAzOC
#define struct_tag_lVYsrGoTQYYB21wZ5vAzOC

struct tag_lVYsrGoTQYYB21wZ5vAzOC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_lVYsrGoTQYYB21wZ5vAzOC */

#ifndef typedef_stm32cube_blocks_TimerBlock_S_T
#define typedef_stm32cube_blocks_TimerBlock_S_T

typedef struct tag_lVYsrGoTQYYB21wZ5vAzOC stm32cube_blocks_TimerBlock_S_T;

#endif                             /* typedef_stm32cube_blocks_TimerBlock_S_T */

/* Parameters for system: '<S104>/Hall Value of 1' */
typedef struct P_HallValueof1_STMF4Hall_T_ P_HallValueof1_STMF4Hall_T;

/* Parameters for system: '<S66>/If Action Subsystem6' */
typedef struct P_IfActionSubsystem6_STMF4Hal_T_ P_IfActionSubsystem6_STMF4Hal_T;

/* Parameters for system: '<S66>/If Action Subsystem' */
typedef struct P_IfActionSubsystem_STMF4Hall_T_ P_IfActionSubsystem_STMF4Hall_T;

/* Parameters for system: '<S64>/Valid Halls' */
typedef struct P_ValidHalls_STMF4Hall_T_ P_ValidHalls_STMF4Hall_T;

/* Parameters for system: '<S64>/Bad hall (glitch or wrong connection)' */
typedef struct P_Badhallglitchorwrongconnect_T_ P_Badhallglitchorwrongconnect_T;

/* Parameters (default storage) */
typedef struct P_STMF4Hall_T_ P_STMF4Hall_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_STMF4Hall_T RT_MODEL_STMF4Hall_T;

#endif                                 /* STMF4Hall_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
