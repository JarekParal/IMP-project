/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : KSDK1.h
**     Project     : KDS_FITkit3_FreeRTOS_KSDK1.3_PEx
**     Processor   : MK60DN512VLQ10
**     Component   : KinetisSDK
**     Version     : Component 01.006, Driver 01.00, CPU db: 3.00.000
**     Repository  : MCUonEclipse_2016-12-12-new
**     Compiler    : GNU C Compiler
**     Date/Time   : 2016-12-13, 03:39, # CodeGen: 1
**     Abstract    :
**
**     Settings    :
**          Component name                                 : KSDK1
**          SDK Version                                    : Processor Expert
**     Contents    :
**         No public methods
**
**     License   : Open Source (LGPL)
**     Copyright : Erich Styger, 2014, all rights reserved.
**     Web       : www.mcuoneclipse.com
**     This an open source software implementing waiting routines using Processor Expert.
**     This is a free software and is opened for education,  research  and commercial developments under license policy of following terms:
**     * This is a free software and there is NO WARRANTY.
**     * No restriction on use. You can use, modify and redistribute it for personal, non-profit or commercial product UNDER YOUR RESPONSIBILITY.
**     * Redistributions of source code must retain the above copyright notice.
** ###################################################################*/
/*!
** @file KSDK1.h
** @version 01.00
** @brief
**
*/         
/*!
**  @addtogroup KSDK1_module KSDK1 module documentation
**  @{
*/         

#ifndef __KSDK1_H
#define __KSDK1_H

/* MODULE KSDK1. */
/* Identifiers used to identify the SDK selected */
#define KSDK1_SDK_VERSION_NONE    0
#define KSDK1_SDK_VERSION_1_3    13
#define KSDK1_SDK_VERSION_2_0    20

/* SDK version used */
#define KSDK1_SDK_VERSION_USED  KSDK1_SDK_VERSION_NONE

#if KSDK1_SDK_VERSION_USED != KSDK1_SDK_VERSION_NONE
  #include "PE_KSDK_Types.h"
  #ifndef __HIWARE__ /* Hiware compiler (S08, S12) only supports C89 */
    #include <stdint.h> /* uint8_t, int16_t, ... */
    #include <stdbool.h> /* bool, true, false, ... */
  #endif
#endif

#if KSDK1_SDK_VERSION_USED == KSDK1_SDK_VERSION_NONE
/* Include inherited components */
  #include "Cpu.h"
#endif


/* END KSDK1. */

#endif
/* ifndef __KSDK1_H */
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
