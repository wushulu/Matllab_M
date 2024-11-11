/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_sensorless_nucleo_f401re'.
 *
 * Model version                  : 8.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat Nov  9 19:29:55 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mcb_pmsm_foc_sensorless_nucleo_f401re.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[3] = { 0, 0, 0 };

boolean_T need2runFlags[3] = { 0, 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[3];
  int_T i;

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  /*
   * For a bare-board target (i.e., no operating system), the rates
   * that execute this base step are buffered locally to allow for
   * overlapping preemption.
   */
  mcb_pmsm_foc_sensorless_nucleo_f401re_SetEventsForThisBaseStep(eventFlags);
  __enable_irq();
  mcb_pmsm_foc_sensorless_nucleo_f401re_step0();

  /* Get model outputs here */
  __disable_irq();
  isRateRunning[0]--;
  for (i = 1; i < 3; i++) {
    if (eventFlags[i]) {
      if (need2runFlags[i]++) {
        IsrOverrun = 1;
        need2runFlags[i]--;            /* allow future iterations to succeed*/
        break;
      }
    }
  }

  for (i = 1; i < 3; i++) {
    if (isRateRunning[i]) {
      /* Yield to higher priority*/
      return;
    }

    if (need2runFlags[i]) {
      isRateRunning[i]++;
      __enable_irq();

      /* Step the model for subrate "i" */
      switch (i)
      {
       case 1 :
        mcb_pmsm_foc_sensorless_nucleo_f401re_step1();

        /* Get model outputs here */
        break;

       case 2 :
        mcb_pmsm_foc_sensorless_nucleo_f401re_step2();

        /* Get model outputs here */
        break;

       default :
        break;
      }

      __disable_irq();
      need2runFlags[i]--;
      isRateRunning[i]--;
    }
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(int argc, char **argv)
{
  float modelBaseRate = 0.0005;
  float systemClock = 84.0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;
  MW_EnableNVICPeripheral();

#if !defined(MW_FREERTOS) && defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;

  // Peripheral initialization imported from STM32CubeMX project;
  HAL_Init();
  SystemClock_Config();
  PeriphCommonClock_Config();
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  rtmSetErrorStatus(mcb_pmsm_foc_sensorless_nucl_M, 0);
  mcb_pmsm_foc_sensorless_nucleo_f401re_configure_interrupts();
  mcb_pmsm_foc_sensorless_nucleo_f401re_initialize();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    rtmGetErrorStatus(mcb_pmsm_foc_sensorless_nucl_M) == (NULL);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(mcb_pmsm_foc_sensorless_nucl_M) == (NULL));
    if (stopRequested) {
      SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    ;
  }

  /* Terminate model */
  mcb_pmsm_foc_sensorless_nucleo_f401re_terminate();

#if !defined(MW_FREERTOS) && !defined(USE_RTX)

  (void) systemClock;

#endif

  ;
  mcb_pmsm_foc_sensorless_nucleo_f401re_unconfigure_interrupts();
  MW_DisableNVICPeripheral();
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
