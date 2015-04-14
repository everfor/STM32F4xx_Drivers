/*****************************************************************************
   Copyright 2015 everfor

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
******************************************************************************/
#ifndef ADXL345_EXAMPLE_H_
#define ADXL345_EXAMPLE_H_

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#define CONFIG_ADXL345_I2C									I2C2
#define CONFIG_ADXL345_I2C_CLK							RCC_APB1Periph_I2C2

#define CONFIG_ADXL345_I2C_SCL_GPIO_Pin						GPIO_Pin_10
#define CONFIG_ADXL345_I2C_SCL_GPIO_PinSource			GPIO_PinSource10
#define CONFIG_ADXL345_I2C_SCL_GPIO_Port					GPIOB
#define CONFIG_ADXL345_I2C_SCL_GPIO_CLK						RCC_AHB1Periph_GPIOB
#define CONFIG_ADXL345_I2C_SCL_AF									GPIO_AF_I2C2

#define CONFIG_ADXL345_I2C_SDA_GPIO_Pin						GPIO_Pin_11
#define CONFIG_ADXL345_I2C_SDA_GPIO_PinSource			GPIO_PinSource11
#define CONFIG_ADXL345_I2C_SDA_GPIO_Port					GPIOB
#define CONFIG_ADXL345_I2C_SDA_GPIO_CLK						RCC_AHB1Periph_GPIOB
#define CONFIG_ADXL345_I2C_SDA_AF									GPIO_AF_I2C2

typedef struct
{
	float q;
	float r;
	float x;
	float p;
	float k;
} ADXL345_kalman_t;

/* Initialize chip */
void ADXL345_InitSetup(void);

/* Configuration registers */
void ADXL345_RegConfig(void);

#endif