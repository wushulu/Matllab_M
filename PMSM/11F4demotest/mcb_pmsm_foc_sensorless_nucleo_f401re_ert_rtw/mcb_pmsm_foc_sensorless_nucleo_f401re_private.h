/*
 * File: mcb_pmsm_foc_sensorless_nucleo_f401re_private.h
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

#ifndef mcb_pmsm_foc_sensorless_nucleo_f401re_private_h_
#define mcb_pmsm_foc_sensorless_nucleo_f401re_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "mcb_pmsm_foc_sensorless_nucleo_f401re.h"
#include "mcb_pmsm_foc_sensorless_nucleo_f401re_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
extern real32_T rt_atan2f_snf(real32_T u0, real32_T u1);
extern void mcb_pmsm__SpeedControl_Init(rtB_SpeedControl_mcb_pmsm_foc_s *localB,
  rtDW_SpeedControl_mcb_pmsm_foc_ *localDW);
extern void mcb_pmsm_foc_s_SpeedControl(real32_T rtu_Speed_Meas_PU,
  rtB_SpeedControl_mcb_pmsm_foc_s *localB, rtDW_SpeedControl_mcb_pmsm_foc_
  *localDW);
extern void mcb_pmsm__SpeedControl_Term(rtDW_SpeedControl_mcb_pmsm_foc_ *localDW);

#endif                    /* mcb_pmsm_foc_sensorless_nucleo_f401re_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
