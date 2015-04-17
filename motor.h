#ifndef MOTOR_H_
#define MOTOR_H_

#include <stdio.h>
#include <stdint.h>
#include "PinDefines.h"
#include "system_stm32f10x.h"
#include "stm32f10x_gpio.h"
#include "stm32f10x_tim.h"

void initializePWMTimer();
void initializeDirectionOutput();

#endif
