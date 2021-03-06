#include "SysTick.h"
#include "data.h"
#include "motor.h"
#include "I2C.h"

extern volatile Data globalData;

void initializeSysTick()
{
	/*
	 * Interrupt every 1s:
	 * 24 MHz / 8 = 3 -> count to 3000000
	 */
	SysTick_Config(600000ul);
	SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
}

void SysTick_Handler(void)
{
   LED5_GPIO->ODR ^= LED5_PIN;

   // check connection
   if (globalData.communication_safety == 0)
	   safeStop();
   globalData.communication_safety = 0;
}
