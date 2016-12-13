/*
 * Copyright (c) 2015, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_gpio.h" /* include SDK GPIO interface */

static const gpio_pin_config_t LED_configOutput = {
  kGPIO_DigitalOutput,  /* use as output pin */
  1,  /* initial value */
};

static const gpio_pin_config_t SW_configInput = {
  kGPIO_DigitalInput,  /* use as output pin */
  0,  /* initial value */
};
/*******************************************************************************
 * Code
 ******************************************************************************/

/* Function Name : BOARD_InitPins */
void BOARD_InitPins(void)
{
    /* Initialize LPSCI0 pins below */
    /* Ungate the port clock */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Affects PORTA_PCR1 register */
    PORT_SetPinMux(PORTC, 1u, kPORT_MuxAlt2);
    /* Affects PORTA_PCR2 register */
    PORT_SetPinMux(PORTC, 2u, kPORT_MuxAlt2);


	/* Initialize LPUART0 pins below */
	/* Ungate the port clock */
	CLOCK_EnableClock(kCLOCK_PortD);
	/* Affects PORTA_PCR1 register */
	PORT_SetPinMux(PORTD, 1u, kPORT_MuxAlt2);
	/* Affects PORTA_PCR2 register */
	PORT_SetPinMux(PORTD, 2u, kPORT_MuxAlt2);

	CLOCK_EnableClock(kCLOCK_PortE);
	/* Affects PORTB_PCR1 register */
	PORT_SetPinMux(PORTE, 1u, kPORT_MuxAlt2);
	/* Affects PORTB_PCR2 register */
	PORT_SetPinMux(PORTE, 2u, kPORT_MuxAlt2);


	/* additional clock and configuration for RGB LEDs (PTA13, PTB18 and PTB19) */
	PORT_SetPinMux(PORTC, 3u, kPORT_MuxAsGpio); /* SW1, PTC3 */
	PORT_SetPinMux(PORTC, 12u, kPORT_MuxAsGpio); /* SW3 , PTC12 */
	PORT_SetPinMux(PORTD, 5u, kPORT_MuxAsGpio); /* green led, PTD5 */
	PORT_SetPinMux(PORTE, 29u, kPORT_MuxAsGpio); /* red led, PTE29 */

	GPIO_PinInit(GPIOB, 5u, &LED_configOutput); /* mux PTC3 as input */
	GPIO_PinInit(GPIOB, 4u, &LED_configOutput); /* mux PTB18 as output */
	GPIO_PinInit(GPIOB, 3u, &LED_configOutput); /* mux PTB19 as output */
}
