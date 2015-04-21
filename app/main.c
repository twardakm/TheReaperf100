#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "system_stm32f10x.h"
#include "stm32f10x.h"

#include "data.h"
#include "LED.h"
#include "APBClocks.h"
#include "SysTick.h"
#include "USART.h"
#include "NVIC.h"
#include "motor.h"
#include "ADC.h"
#include "I2C.h"

extern volatile Data globalData;

void Set24MHzHSI();

int main(void)
{
	SystemInit();
	Set24MHzHSI();

	initializeAPB();
	initializeLEDGPIO();
	initializeSysTick();

	initializePWMTimer();
	initializeDirectionOutput();

	initializeUSART();
	initializeI2C();

	initializeADC();

	initializeNVIC();

    while(1)
    {
    }
}

void Set24MHzHSI()
{
	/* Enable Internal High Speed oscillator */
	RCC_HSICmd(ENABLE);


	/* Set PLL clock output to 24MHz using HSI (8MHz) as entry clock */
	RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_6);


	/* Select the PLL as system clock source */
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);


	/* Enable the PLL */
	RCC_PLLCmd(ENABLE);


	/* Output PLL clock divided by 2 on MCO pin */
	RCC_MCOConfig(RCC_MCO_PLLCLK_Div2);


	/* Configure HCLK such as HCLK = SYSCLK */
	RCC_HCLKConfig(RCC_SYSCLK_Div1);


	/* Configure PCLK1 such as PCLK1 = HCLK/2 */
	RCC_PCLK1Config(RCC_HCLK_Div1);


	/* Configure PCLK2 such as PCLK2 = HCLK */
	RCC_PCLK2Config(RCC_HCLK_Div1);
}
