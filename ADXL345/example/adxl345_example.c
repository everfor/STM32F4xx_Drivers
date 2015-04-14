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
#include "adxl345.h"
#include "adxl345_example.h"

void ADXL345_InitSetup(void)
{
	ADXL345_InitTypeDef adxl345_init_s;
	
	adxl345_init_s.ADXL345_AltAddrStatus = ADXL345_AltAddr_ENABLE;
	
	adxl345_init_s.ADXL345_I2C = CONFIG_ADXL345_I2C;
	adxl345_init_s.ADXL345_I2C_CLK = CONFIG_ADXL345_I2C_CLK;
	
	adxl345_init_s.ADXL345_I2C_SCL_GPIO_Pin = CONFIG_ADXL345_I2C_SCL_GPIO_Pin;
	adxl345_init_s.ADXL345_I2C_SCL_GPIO_Port = CONFIG_ADXL345_I2C_SCL_GPIO_Port;
	adxl345_init_s.ADXL345_I2C_SCL_GPIO_CLK = CONFIG_ADXL345_I2C_SCL_GPIO_CLK;
	adxl345_init_s.ADXL345_I2C_SCL_GPIO_PinSource = CONFIG_ADXL345_I2C_SCL_GPIO_PinSource;
	adxl345_init_s.ADXL345_I2C_SCL_AF = CONFIG_ADXL345_I2C_SCL_AF;
	
	adxl345_init_s.ADXL345_I2C_SDA_GPIO_Pin = CONFIG_ADXL345_I2C_SDA_GPIO_Pin;
	adxl345_init_s.ADXL345_I2C_SDA_GPIO_Port = CONFIG_ADXL345_I2C_SDA_GPIO_Port;
	adxl345_init_s.ADXL345_I2C_SDA_GPIO_CLK = CONFIG_ADXL345_I2C_SDA_GPIO_CLK;
	adxl345_init_s.ADXL345_I2C_SDA_GPIO_PinSource = CONFIG_ADXL345_I2C_SDA_GPIO_PinSource;
	adxl345_init_s.ADXL345_I2C_SDA_AF = CONFIG_ADXL345_I2C_SDA_AF;
	
	ADXL345_Init(&adxl345_init_s);
}

void ADXL345_RegConfig(void)
{
	// Enable measurement mode
	ADXL345_I2C_WriteReg(REG_ADXL345_POWER_CTL, 0x08);
}