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
#ifndef ADXL345_I2C_H_
#define ADXL345_I2C_H_

#include "adxl345_general.h"

/* Initialize I2C */
void ADXL345_I2C_Init(ADXL345_InitTypeDef* adxl345_init_s);

/* Read a byte from a single register */
uint8_t ADXL345_I2C_ReadReg(uint8_t address);

/* Read multiple bytes from multiple registers */
void ADXL345_I2C_ReadRegMulti(uint8_t address, uint8_t* buffer, uint8_t count);

/* Write a byte to a single register */
void ADXL345_I2C_WriteReg(uint8_t address, uint8_t byte);

/* Write multiple bytes to multiple registers */
void ADXL345_I2C_WriteRegMulti(uint8_t address, uint8_t* buffer, uint8_t count);

#endif