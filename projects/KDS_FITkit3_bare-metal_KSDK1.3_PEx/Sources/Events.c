/* ###################################################################
**     Filename    : Events.c
**     Project     : KDS_FITkit3_KSDK1.3_PEx
**     Processor   : MK60DN512VLQ10
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-12, 23:38, # CodeGen: 0
**     Abstract    :
**         This is user's event module.
**         Put your event handler code here.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file Events.c
** @version 01.00
** @brief
**         This is user's event module.
**         Put your event handler code here.
*/         
/*!
**  @addtogroup Events_module Events module documentation
**  @{
*/         
/* MODULE Events */

#include "Cpu.h"
#include "Events.h"

#ifdef __cplusplus
extern "C" {
#endif 


/* User includes (#include below this line is not maintained by Processor Expert) */

static int position = 3;
volatile int LedPeriod = 500;
const int LedPeriodAddConst = 100;

/*
** ===================================================================
**     Interrupt handler : PORTE_IRQHandler
**
**     Description :
**         User interrupt service routine.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PORTE_IRQHandler(void)
{
//  if(GPIO_DRV_IsPinIntPending(MCU_BUTTON0))
//	  GPIO_DRV_TogglePinOutput(MCU_LED1);
//  if(GPIO_DRV_IsPinIntPending(MCU_BUTTON1))
//	  GPIO_DRV_TogglePinOutput(MCU_LED2);
//  if(GPIO_DRV_IsPinIntPending(MCU_BUTTON2))
//	  GPIO_DRV_TogglePinOutput(MCU_LED3);

	if(GPIO_DRV_IsPinIntPending(MCU_BUTTON0))
	  if(position > 1)
		  position--;
	if(GPIO_DRV_IsPinIntPending(MCU_BUTTON2))
	  if(position < 3)
		  position++;

	if(GPIO_DRV_IsPinIntPending(MCU_BUTTON1))
		LedPeriod += LedPeriodAddConst;
	if(GPIO_DRV_IsPinIntPending(MCU_BUTTON3))
	  if(LedPeriod != 100)
		LedPeriod -= LedPeriodAddConst;

	GPIO_DRV_WritePinOutput(MCU_LED1, 1);
	GPIO_DRV_WritePinOutput(MCU_LED2, 1);
	GPIO_DRV_WritePinOutput(MCU_LED3, 1);

	switch(position)
	{
	  case 1:
		  GPIO_DRV_WritePinOutput(MCU_LED1, 0);
		  break;
	  case 2:
		  GPIO_DRV_WritePinOutput(MCU_LED2, 0);
		  break;
	  case 3:
		  GPIO_DRV_WritePinOutput(MCU_LED3, 0);
		  break;
	}


	/* Clear interrupt flag.*/
	PORT_HAL_ClearPortIntFlag(PORTE_BASE_PTR);
	/* Write your code here ... */
}

/* END Events */

#ifdef __cplusplus
}  /* extern "C" */
#endif 

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
