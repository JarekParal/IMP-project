/* ###################################################################
**     Filename    : main.c
**     Project     : KDS_FITkit3_KSDK1.3_PEx
**     Processor   : MK60DN512VLQ10
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-12, 23:38, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "osa1.h"
#include "gpio1.h"
#include "WAIT1.h"
#include "KSDK1.h"
#include "FRTOS1.h"
#include "UTIL1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */

static void BlinkyTask(void *pvParameters) {
  (void)pvParameters; /* parameter not used */
  for(;;) {
    GPIO_DRV_TogglePinOutput(MCU_LED3);
    vTaskDelay(500/portTICK_RATE_MS); /* wait for 500 ms */
  }
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  GPIO_DRV_WritePinOutput(MCU_LED1, 1);
  GPIO_DRV_WritePinOutput(MCU_LED2, 0);
  GPIO_DRV_WritePinOutput(MCU_LED0, 0);
  GPIO_DRV_WritePinOutput(MCU_LED3, 1);

  if (FRTOS1_xTaskCreate(
        BlinkyTask,  /* pointer to the task */
        "Blinky", /* task name for kernel awareness debugging */
        configMINIMAL_STACK_SIZE, /* task stack size */
        (void*)NULL, /* optional task startup argument */
        1,  /* initial priority */
        (xTaskHandle*)NULL /* optional task handle to create */
      ) != pdPASS)
	{
	  for(;;){
		  GPIO_DRV_TogglePinOutput(MCU_LED0);
	  } /* error! probably out of memory */
	}

  vTaskStartScheduler(); /* start FreeRTOS scheduler, does usually not return! */

//  for(;;) {
//	  GPIO_DRV_TogglePinOutput(MCU_LED0);
//	  GPIO_DRV_TogglePinOutput(MCU_LED1);
//	  WAIT1_Waitms(500);
//  }


  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.5 [05.21]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
