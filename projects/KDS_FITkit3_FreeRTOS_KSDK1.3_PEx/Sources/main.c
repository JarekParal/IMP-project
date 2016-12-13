/* ###################################################################
**     Filename    : main.c
**     Project     : KDS_FITkit3_FreeRTOS_KSDK1.3_PEx
**     Processor   : MK60DN512VLQ10
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-13, 03:20, # CodeGen: 0
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
#include "rtos_main_task.h"
#include "clockMan1.h"
#include "pin_mux.h"
#include "osa1.h"
#include "free_rtos.h"
#include "MainTask.h"
#include "gpio1.h"
#include "WAIT1.h"
#include "KSDK1.h"
#if CPU_INIT_CONFIG
  #include "Init_Config.h"
#endif
/* User includes (#include below this line is not maintained by Processor Expert) */


/* Task priorities. */
#define hello_task_PRIORITY (configMAX_PRIORITIES - 1)

/*!
 * @brief Task responsible for printing of "Hello world." message.
 */
static void hello_task(void *pvParameters) {
  for (;;) {
	/*PRINTF("Hello world.\r\n");*/
	/* Add your code here */
    //vTaskSuspend(NULL);
	vTaskDelay(500/portTICK_RATE_MS);
	GPIO_DRV_TogglePinOutput(MCU_LED3);
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

  // Test - xTaskCreate from KSDK2.0 - don't work
  xTaskCreate(hello_task, "Hello_task", configMINIMAL_STACK_SIZE, NULL, hello_task_PRIORITY, NULL);
  vTaskStartScheduler();


  for(;;) {
  	  //GPIO_DRV_TogglePinOutput(MCU_LED0);
  	  GPIO_DRV_TogglePinOutput(MCU_LED1);
  	  WAIT1_Waitms(500);
  }


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
