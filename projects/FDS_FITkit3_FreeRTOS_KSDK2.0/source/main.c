/*
 * Copyright (c) 2013 - 2016, Freescale Semiconductor, Inc.
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

/**
 * This is template for main module created by New Kinetis SDK 2.x Project Wizard. Enjoy!
 **/

#include <string.h>

#include "fsl_device_registers.h"
#include "fsl_port.h"
#include "pin_mux.h"
#include "fsl_gpio.h"

static const gpio_pin_config_t LED_configOutput = {
  kGPIO_DigitalOutput,  /* use as output pin */
  1,  /* initial value */
};

static const gpio_pin_config_t BTN_configInput = {
  kGPIO_DigitalInput,  /* use as output pin */
  0,  /* initial value */
};

/*! @brief Define the port interrupt number for the board switches */
#define MCU_BUTTON0_GPIO GPIOE
#define MCU_BUTTON0_PORT PORTE
#define MCU_BUTTON0_GPIO_PIN 10U
#define MCU_BUTTON0_IRQ PORTE_IRQn
#define MCU_BUTTON0_IRQ_HANDLER PORTE_IRQHandler
#define MCU_BUTTON0_NAME "BTN0"

#define MCU_BUTTON1_GPIO GPIOE
#define MCU_BUTTON1_PORT PORTE
#define MCU_BUTTON1_GPIO_PIN 12U
#define MCU_BUTTON1_IRQ PORTE_IRQn
#define MCU_BUTTON1_IRQ_HANDLER PORTE_IRQHandler
#define MCU_BUTTON1_NAME "BTN1"

#define MCU_BUTTON2_GPIO GPIOE
#define MCU_BUTTON2_PORT PORTE
#define MCU_BUTTON2_GPIO_PIN 27U
#define MCU_BUTTON2_IRQ PORTE_IRQn
#define MCU_BUTTON2_IRQ_HANDLER PORTE_IRQHandler
#define MCU_BUTTON2_NAME "BTN2"

#define MCU_BUTTON3_GPIO GPIOE
#define MCU_BUTTON3_PORT PORTE
#define MCU_BUTTON3_GPIO_PIN 26U
#define MCU_BUTTON3_IRQ PORTE_IRQn
#define MCU_BUTTON3_IRQ_HANDLER PORTE_IRQHandler
#define MCU_BUTTON3_NAME "BTN3"

#define MCU_BUTTON4_GPIO GPIOE
#define MCU_BUTTON4_PORT PORTE
#define MCU_BUTTON4_GPIO_PIN 11U
#define MCU_BUTTON4_IRQ PORTE_IRQn
#define MCU_BUTTON4_IRQ_HANDLER PORTE_IRQHandler
#define MCU_BUTTON4_NAME "BTN4"

/* Board led color mapping */
#define LOGIC_LED_ON 0U
#define LOGIC_LED_OFF 1U

#define MCU_LED0_GPIO GPIOB
#define MCU_LED0_GPIO_PORT PORTB
#define MCU_LED0_GPIO_PIN 5U

#define MCU_LED1_GPIO GPIOB
#define MCU_LED1_GPIO_PORT PORTB
#define MCU_LED1_GPIO_PIN 4U

#define MCU_LED2_GPIO GPIOB
#define MCU_LED2_GPIO_PORT PORTB
#define MCU_LED2_GPIO_PIN 3U

#define MCU_LED3_GPIO GPIOB
#define MCU_LED3_GPIO_PORT PORTB
#define MCU_LED3_GPIO_PIN 2U


#define MCU_LED0_INIT(output)                                 \
    GPIO_WritePinOutput(MCU_LED0_GPIO, MCU_LED0_GPIO_PIN, output);\
    MCU_LED0_GPIO->PDDR |= (1U << MCU_LED0_GPIO_PIN)  /*!< Enable target LED_RED */
#define MCU_LED0_ON() \
    GPIO_ClearPinsOutput(MCU_LED0_GPIO, 1U << MCU_LED0_GPIO_PIN) /*!< Turn on target LED_RED */
#define MCU_LED0_OFF() \
    GPIO_SetPinsOutput(MCU_LED0_GPIO, 1U << MCU_LED0_GPIO_PIN) /*!< Turn off target LED_RED */
#define MCU_LED0_TOGGLE() \
    GPIO_TogglePinsOutput(MCU_LED0_GPIO, 1U << MCU_LED0_GPIO_PIN) /*!< Toggle on target LED_RED */

#define MCU_LED1_INIT(output)                                 \
    GPIO_WritePinOutput(MCU_LED1_GPIO, MCU_LED1_GPIO_PIN, output);\
    MCU_LED1_GPIO->PDDR |= (1U << MCU_LED1_GPIO_PIN)  /*!< Enable target LED_RED */
#define MCU_LED1_ON() \
    GPIO_ClearPinsOutput(MCU_LED1_GPIO, 1U << MCU_LED1_GPIO_PIN) /*!< Turn on target LED_RED */
#define MCU_LED1_OFF() \
    GPIO_SetPinsOutput(MCU_LED1_GPIO, 1U << MCU_LED1_GPIO_PIN) /*!< Turn off target LED_RED */
#define MCU_LED1_TOGGLE() \
    GPIO_TogglePinsOutput(MCU_LED1_GPIO, 1U << MCU_LED1_GPIO_PIN) /*!< Toggle on target LED_RED */

#define MCU_LED2_INIT(output)                                 \
    GPIO_WritePinOutput(MCU_LED2_GPIO, MCU_LED2_GPIO_PIN, output);\
    MCU_LED2_GPIO->PDDR |= (1U << MCU_LED2_GPIO_PIN)  /*!< Enable target LED_RED */
#define MCU_LED2_ON() \
    GPIO_ClearPinsOutput(MCU_LED2_GPIO, 1U << MCU_LED2_GPIO_PIN) /*!< Turn on target LED_RED */
#define MCU_LED2_OFF() \
    GPIO_SetPinsOutput(MCU_LED2_GPIO, 1U << MCU_LED2_GPIO_PIN) /*!< Turn off target LED_RED */
#define MCU_LED2_TOGGLE() \
    GPIO_TogglePinsOutput(MCU_LED2_GPIO, 1U << MCU_LED2_GPIO_PIN) /*!< Toggle on target LED_RED */

#define MCU_LED3_INIT(output)                                 \
    GPIO_WritePinOutput(MCU_LED3_GPIO, MCU_LED3_GPIO_PIN, output);\
    MCU_LED3_GPIO->PDDR |= (1U << MCU_LED3_GPIO_PIN)  /*!< Enable target LED_RED */
#define MCU_LED3_ON() \
    GPIO_ClearPinsOutput(MCU_LED3_GPIO, 1U << MCU_LED3_GPIO_PIN) /*!< Turn on target LED_RED */
#define MCU_LED3_OFF() \
    GPIO_SetPinsOutput(MCU_LED3_GPIO, 1U << MCU_LED3_GPIO_PIN) /*!< Turn off target LED_RED */
#define MCU_LED3_TOGGLE() \
    GPIO_TogglePinsOutput(MCU_LED3_GPIO, 1U << MCU_LED3_GPIO_PIN) /*!< Toggle on target LED_RED */

#include "board.h"
#include "pin_mux.h"
#include "clock_config.h"
/*#include "fsl_debug_console.h"*/

/* FreeRTOS kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

#include "fsl_gpio.h"

/* Task priorities. */
#define led_task_PRIORITY (configMAX_PRIORITIES - 1)
#define btn_task_PRIORITY (configMAX_PRIORITIES - 1)

volatile int led_period = 500;
const int dif_led_period = 20;
volatile int position = 1;
volatile bool BTN0_LAST = 1;
volatile bool BTN2_LAST = 1;

static void btn_task(void *pvParameters) {
  for (;;) {
	if(GPIO_ReadPinInput(MCU_BUTTON1_GPIO, MCU_BUTTON1_GPIO_PIN) == 0)
		if(led_period > 100)
			led_period -= dif_led_period;
	if(GPIO_ReadPinInput(MCU_BUTTON3_GPIO, MCU_BUTTON3_GPIO_PIN) == 0)
		if(led_period < 2000)
			led_period += dif_led_period;

	if(GPIO_ReadPinInput(MCU_BUTTON0_GPIO, MCU_BUTTON0_GPIO_PIN) == 0 && BTN0_LAST == 1) {
		BTN0_LAST = 0;
		if(position > 1)
			position--;
	} else {
		BTN0_LAST = GPIO_ReadPinInput(MCU_BUTTON0_GPIO, MCU_BUTTON0_GPIO_PIN);
	}
	if(GPIO_ReadPinInput(MCU_BUTTON2_GPIO, MCU_BUTTON2_GPIO_PIN) == 0 && BTN2_LAST == 1) {
		BTN2_LAST = 0;
		if(position < 3)
			position++;
	} else {
		BTN2_LAST = GPIO_ReadPinInput(MCU_BUTTON2_GPIO, MCU_BUTTON2_GPIO_PIN);
	}

	MCU_LED1_OFF();
	MCU_LED2_OFF();
	MCU_LED3_OFF();
	switch(position){
	  case 1:
		  MCU_LED1_ON();
		  break;
	  case 2:
		  MCU_LED2_ON();
		  break;
	  case 3:
		  MCU_LED3_ON();
		  break;
	}
	vTaskDelay(50/portTICK_RATE_MS); // control every 50 ms
  }
}

static void led_task(void *pvParameters) {
  for (;;) {
	  MCU_LED0_TOGGLE();

	  vTaskDelay(led_period/portTICK_RATE_MS);
  }
}

int main(void) {
	/* Init board hardware. */
	BOARD_InitPins();
	BOARD_BootClockRUN();
	BOARD_InitDebugConsole();

	// Enable the clock to the PORTS
	CLOCK_EnableClock(kCLOCK_PortB);
	CLOCK_EnableClock(kCLOCK_PortE);
	PORT_SetPinMux(PORTB, 1u, kPORT_MuxAlt2);
	/* Affects PORTA_PCR2 register */
	PORT_SetPinMux(PORTB, 2u, kPORT_MuxAlt2);

	PORT_SetPinMux(PORTE, 1u, kPORT_MuxAlt2);
	/* Affects PORTA_PCR2 register */
	PORT_SetPinMux(PORTE, 2u, kPORT_MuxAlt2);

	// Setup the LEDs
	PORT_SetPinMux(MCU_LED0_GPIO_PORT, MCU_LED0_GPIO_PIN, kPORT_MuxAsGpio);
	PORT_SetPinMux(MCU_LED1_GPIO_PORT, MCU_LED1_GPIO_PIN, kPORT_MuxAsGpio);
	PORT_SetPinMux(MCU_LED2_GPIO_PORT, MCU_LED2_GPIO_PIN, kPORT_MuxAsGpio);
	PORT_SetPinMux(MCU_LED3_GPIO_PORT, MCU_LED3_GPIO_PIN, kPORT_MuxAsGpio);

	GPIO_PinInit(MCU_LED0_GPIO, MCU_LED0_GPIO_PIN, &LED_configOutput);
	GPIO_PinInit(MCU_LED1_GPIO, MCU_LED1_GPIO_PIN, &LED_configOutput);
	GPIO_PinInit(MCU_LED2_GPIO, MCU_LED2_GPIO_PIN, &LED_configOutput);
	GPIO_PinInit(MCU_LED3_GPIO, MCU_LED3_GPIO_PIN, &LED_configOutput);

	// Setup the buttons
	PORT_SetPinMux(MCU_BUTTON0_PORT, MCU_BUTTON0_GPIO_PIN, kPORT_MuxAsGpio);
	PORT_SetPinMux(MCU_BUTTON1_PORT, MCU_BUTTON1_GPIO_PIN, kPORT_MuxAsGpio);
	PORT_SetPinMux(MCU_BUTTON2_PORT, MCU_BUTTON2_GPIO_PIN, kPORT_MuxAsGpio);
	PORT_SetPinMux(MCU_BUTTON3_PORT, MCU_BUTTON3_GPIO_PIN, kPORT_MuxAsGpio);

	GPIO_PinInit(MCU_BUTTON0_GPIO, MCU_BUTTON0_GPIO_PIN, &BTN_configInput);
	GPIO_PinInit(MCU_BUTTON1_GPIO, MCU_BUTTON1_GPIO_PIN, &BTN_configInput);
	GPIO_PinInit(MCU_BUTTON2_GPIO, MCU_BUTTON2_GPIO_PIN, &BTN_configInput);
	GPIO_PinInit(MCU_BUTTON3_GPIO, MCU_BUTTON3_GPIO_PIN, &BTN_configInput);

	/* Create RTOS task */
	xTaskCreate(led_task, "led_task", configMINIMAL_STACK_SIZE, NULL, led_task_PRIORITY, NULL);
	xTaskCreate(btn_task, "btn_task", configMINIMAL_STACK_SIZE, NULL, btn_task_PRIORITY, NULL);
	vTaskStartScheduler();

	for(;;) { /* Infinite loop to avoid leaving the main function */
		__asm("NOP"); /* something to use as a breakpoint stop while looping */
	}
}



