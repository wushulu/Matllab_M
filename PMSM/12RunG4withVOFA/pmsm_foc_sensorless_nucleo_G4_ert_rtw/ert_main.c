/*
 * File: ert_main.c
 *
 * Code generated for Simulink model 'pmsm_foc_sensorless_nucleo_G4'.
 *
 * Model version                  : 8.13
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Nov 13 17:04:28 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pmsm_foc_sensorless_nucleo_G4.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
boolean_T isRateRunning[2] = { 0, 0 };

boolean_T need2runFlags[2] = { 0, 0 };

void rt_OneStep(void)
{
  boolean_T eventFlags[2];

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
  pmsm_foc_sensorless_nucleo_G4_SetEventsForThisBaseStep(eventFlags);
  __enable_irq();
  pmsm_foc_sensorless_nucleo_G4_step0();

  /* Get model outputs here */
  __disable_irq();
  isRateRunning[0]--;
  if (eventFlags[1]) {
    if (need2runFlags[1]++) {
      IsrOverrun = 1;
      need2runFlags[1]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[1]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[1]++;
    __enable_irq();

    /* Step the model for subrate "1" */
    switch (1)
    {
     case 1 :
      pmsm_foc_sensorless_nucleo_G4_step1();

      /* Get model outputs here */
      break;

     default :
      break;
    }

    __disable_irq();
    need2runFlags[1]--;
    isRateRunning[1]--;
  }
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(int argc, char **argv)
{
  float modelBaseRate = 0.001;
  float systemClock = 170.0;

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
  MX_LPUART1_UART_Init();
  MX_ADC1_Init();
  MX_TIM1_Init();
  rtmSetErrorStatus(pmsm_foc_sensorless_nucleo_G_M, 0);
  pmsm_foc_sensorless_nucleo_G4_configure_interrupts();
  pmsm_foc_sensorless_nucleo_G4_initialize();
  __disable_irq();
  ARMCM_SysTick_Config(modelBaseRate);
  runModel =
    rtmGetErrorStatus(pmsm_foc_sensorless_nucleo_G_M) == (NULL);
  __enable_irq();
  __enable_irq();
  while (runModel) {
    stopRequested = !(
                      rtmGetErrorStatus(pmsm_foc_sensorless_nucleo_G_M) == (NULL));
    if (stopRequested) {
      SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
    }

    ;
  }

  /* Terminate model */
  pmsm_foc_sensorless_nucleo_G4_terminate();

#if !defined(MW_FREERTOS) && !defined(USE_RTX)

  (void) systemClock;

#endif

  ;
  pmsm_foc_sensorless_nucleo_G4_unconfigure_interrupts();
  MW_DisableNVICPeripheral();
  __disable_irq();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
