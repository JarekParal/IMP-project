# IMP-project 2016

Demo applications on learning kit FITkit 3. Bare-metal and FreeRTOS projects. Showing on base peripheries (LEDs, buttons).   

For all project use Kinetis SDK: KSDK_1.3.0
- Kinetis SDK Location - Environment variable: KSDK_PATH

Processor Expert - Project Mode: Standalone

[Documentation (Czech languagle)](https://github.com/JarekParal/IMP-project/releases/download/v1.0/doc.pdf)

Video showing this project: https://youtu.be/nl1vykVDIRg

Main projects:   
[KDS_FITkit3_bare-metal_KSDK1.3_PEx](https://github.com/JarekParal/IMP-project/tree/master/projects/KDS_FITkit3_bare-metal_KSDK1.3_PEx)   
[KDS_FITkit3_FreeRTOS_KSDK2.0](https://github.com/JarekParal/IMP-project/tree/master/projects/KDS_FITkit3_FreeRTOS_KSDK2.0)

## Source

[MCU on Eclipse - Tutorial: User Interrupts with Processor Expert](https://mcuoneclipse.com/2014/04/13/tutorial-user-interrupts-with-processor-expert/)
- using *InterruptVector* or *Init_GPIO* or *ExtInt* components

[MCU on Eclipse - Tutorial: Tutorial: ADC with the Freedom Board](https://mcuoneclipse.com/2013/02/10/tutorial-adc-with-the-freedom-board/)
- using *ADC_LDD* component

[MCU on Eclipse - Tutorial: Tutorial: ADC with the Freedom Board](https://mcuoneclipse.com/2014/06/07/tutorial-pwm-with-dma-on-armkinetis/)
- using *Init_TPM*,*DMAController*,*DMAChannel_LDD* components

[MCU on Eclipse - Tutorial: Tutorial: ADC with the Freedom Board](https://mcuoneclipse.com/2013/03/16/pwm-for-processor-expert-explained/)
- using *PWM* component

[MCU on Eclipse - LED’s for Kinetis, simplified](https://mcuoneclipse.com/2012/12/27/leds-for-kinetis-simplified/)
- using *LED* component

[MCU on Eclipse - LED’s for Kinetis, simplified](https://mcuoneclipse.com/2012/08/13/tutorial-timer-led-with-processor-expert-for-kinetis/)
- using *LED*, *GPIO_LDD* and *TimerUnit_LDD* components

[MCU on Eclipse - Tutorial: Touching the Freedom KL25Z Board](https://mcuoneclipse.com/2012/09/30/tutorial-touching-the-freedom-kl25z-board/)
- using *TSS_Library*, *LED* and *GPIO_LDD* components

[MCU on Eclipse - Tutorial: Blinky with NXP Kinetis SDK V2.0 and Processor Expert](https://mcuoneclipse.com/2016/05/20/tutorial-blinky-with-nxp-kinetis-sdk-v2-0-and-processor-expert/)
- using *KinetisSDK*, *LED* and *WAIT* components

[MCU on Eclipse - Tutorial: Blinky with Kinetis SDK V1.3 and Processor Expert](https://mcuoneclipse.com/2016/10/08/tutorial-blinky-with-kinetis-sdk-v1-3-and-processor-expert/)
- using *KinetisSDK*, *LED* and *fsl_gpio* components

[MCU on Eclipse - Unboxing the Freescale FRDM-KL43Z Board](https://mcuoneclipse.com/2015/07/27/unboxing-the-freescale-frdm-kl43z-board/)
- compare FRDM-KL25Z, FRDM-KL43Z and FRDM-KL46Z

[MCU on Eclipse - Freescale Freedom Board Tutorials on Element14](https://mcuoneclipse.com/2015/07/26/freescale-freedom-board-tutorials-on-element14/)

[MCU on Eclipse - FRDM K64F Data Logger using FatFs with KSDK 1.2.0](https://mcuoneclipse.com/2015/07/29/frdm-k64f-data-logger-using-fatfs-with-ksdk-1-2-0/)

[MCU on Eclipse - First NXP Kinetis SDK Release: SDK V2.0 with Online On-Demand Package Builder](https://mcuoneclipse.com/2016/01/29/first-nxp-kinetis-sdk-release-sdk-v2-0-with-on-demand-package-builder/)

[MCU on Eclipse - Mother of Components: Processor Expert with NXP Kinetis SDK V2.0 Projects](https://mcuoneclipse.com/2016/05/15/mother-of-components-processor-expert-with-nxp-kinetis-sdk-v2-0-projects/)

[MCU on Eclipse - Tutorial: Freedom with FreeRTOS and Kinetis-L](https://mcuoneclipse.com/2012/09/29/tutorial-freedom-with-freertos-and-kinetis-l/)

[MCU on Eclipse - Tutorial: FreeRTOS with the Kinetis SDK and Processor Expert](https://mcuoneclipse.com/2014/11/08/tutorial-freertos-with-the-kinetis-sdk-and-processor-expert/)

[MCU on Eclipse - Tutorial: Using Processor Expert and FreeRTOS with Kinetis SDK V1.2](https://mcuoneclipse.com/2015/07/08/tutorial-using-processor-expert-and-freertos-with-kinetis-sdk-v1-2/)

[MCU on Eclipse - Tutorial: FreeRTOS with NXP Kinetis SDK V2.0 and Processor Expert](https://mcuoneclipse.com/2016/05/20/tutorial-freertos-with-nxp-kinetis-sdk-v2-0-and-processor-expert/)




[Element14 - FRDM-K64F + Kinetis Design Studio (KDS) - Tutorial: Toggling an RGB LED using interrupts](https://www.element14.com/community/community/designcenter/kinetis_kl2_freedom_board/blog/2014/08/03/frdm-k64f-kinetis-design-studio-kds-tutorial-toggling-an-rgb-led-using-interrupts)
- using *BitIO_LDD* component

[Element14 - Kinetis Design Studio 3.0 Kinetis SDK 1.2 Processor-Expert using FRDM-KL46Z: Quick tutorial on GPIO Interrupt (Toggling LED using button with Interrupt logic)](https://www.element14.com/community/community/designcenter/kinetis_kl2_freedom_board/blog/2015/08/24/kinetis-design-studio-30-kinetis-sdk-12-processor-expert-using-frdm-kl46z-quick-tutorial-on-gpio-interrupt-toggling-led-using-button-with-interrupt-logic)
- using *fsl_gpio* component

[Element14 - Kinetis Design Studio 3.0 Kinetis SDK 1.2 Processor-Expert using FRDM-KL43Z: Blink Red Led with TPM (Timer PWM Module) ](https://www.element14.com/community/community/designcenter/kinetis_kl2_freedom_board/blog/2015/07/31/kinetis-design-studio-30-kinetis-sdk-12-processor-expert-using-frdm-kl43z-blink-red-led-with-tpm-timer-pwm-module)
- using *fsl_tmp* component

[Element14 - Kinetis Design Studio 3.0 Kinetis SDK 1.2 Processor-Expert using FRDM-K64F:  Toggle Led_using_PIT (Periodic Interrupt Timer)) ](https://www.element14.com/community/community/designcenter/kinetis_kl2_freedom_board/blog/2015/07/22/kinetis-design-studio-30-kinetis-sdk-12-processor-expert-using-frdm-k64f-toggle-ledusingpit-periodic-interrupt-timer)
- using *fsl_gpio* and *fsl_pit* components
- KSDK1.3 + PEx

[Element14 - FRDM-K64F + Kinetis Design Studio (KDS) - Tutorial: Toggling an RGB LED using interrupts) ](https://www.element14.com/community/community/designcenter/kinetis_kl2_freedom_board/blog/2014/08/03/frdm-k64f-kinetis-design-studio-kds-tutorial-toggling-an-rgb-led-using-interrupts)
- using *BitIO_LDD* and *ExtInt_LDD* components

[NXP - Transitioning to C++ with KDS, KSDK, and Processor Expert) ](https://community.nxp.com/docs/DOC-105449)

[NXP - Having trouble with PWM using FRDM-K64F+KDS 2.0+KSDK 1.1+PEx) ](https://community.nxp.com/thread/349864)

[YouTuBe - SpazzTech - FRDM-K64F - Timer Interrupt with Kinetis Design Studio and Processor Expert) ](https://www.youtube.com/watch?v=dvJF2X6PH60)
- using *fsl_tmp* component
