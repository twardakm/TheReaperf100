#include "SysTick.h"

void initializeSysTick()
{
	/*
	 * Interrupt every 1s:
	 * 24 MHz / 8 = 3 -> count to 3000000
	 */
	SysTick_Config(3000000ul);
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
}

void SysTick_Handler(void)
{
   LED5_GPIO->ODR ^= LED5_PIN;
}
