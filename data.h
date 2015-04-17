#ifndef DATA_H_
#define DATA_H_

#include <stdint.h>
#include <stdlib.h>

typedef struct
{
	uint32_t battery_level_sum;
	uint8_t sample;
	uint8_t battery_level; // average from 256 samples
} Data;

volatile Data data;

#endif
