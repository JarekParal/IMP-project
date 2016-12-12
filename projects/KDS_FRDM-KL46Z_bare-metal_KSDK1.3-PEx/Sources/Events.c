/* ###################################################################
**     Filename    : Events.c
**     Project     : KDS_FRDM-KL46Z_bare-metal_KSDK1.3-PEx
**     Processor   : MKL46Z256VLL4
**     Component   : Events
**     Version     : Driver 01.00
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-11, 11:25, # CodeGen: 0
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

/*
** ===================================================================
**     Interrupt handler : PORTC_PORTD_IRQHandler
**
**     Description :
**         User interrupt service routine. 
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void PORTC_PORTD_IRQHandler(void)
{
  if(GPIO_DRV_IsPinIntPending(BUTTON_SW1))
	  GPIO_DRV_TogglePinOutput(LED2_RED); // LED turn ON

  /* Clear interrupt flag.*/
  PORT_HAL_ClearPortIntFlag(PORTC_BASE_PTR);
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
