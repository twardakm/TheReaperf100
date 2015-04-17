#ifndef DATA_H_
#define DATA_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct
{
	uint8_t communication_safety; //in SysTick, if still 0, safeStop

	uint32_t battery_level_sum;
	uint8_t sample;
	uint8_t battery_level; // average from 256 samples
} Data;

volatile Data globalData;

#endif
