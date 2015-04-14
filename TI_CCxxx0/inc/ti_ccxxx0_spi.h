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
#ifndef TI_CCxxx0_SPI_H_
#define TI_CCxxx0_SPI_H_

#include "ti_ccxxx0_general.h"

/* SPI Initialization */
void TI_CCxxx0_SPI_Init(TI_CCxxx0_InitTypeDef *TI_CCxxx0_SPI_InitStruct);

/* Read a byte from a single register */
uint8_t TI_CCxxx0_SPI_ReadReg(uint8_t addr);

/* Read from a status register */
uint8_t TI_CCxxx0_SPI_ReadStatusReg(uint8_t addr);

/* Burst read multiple bytes from multiple registers */
void TI_CCxxx0_SPI_ReadRegBurst(uint8_t addr, uint8_t *buffer, uint8_t count);

/* Write a byte to a single register */
void TI_CCxxx0_SPI_WriteReg(uint8_t addr, uint8_t byte);

/* Burst write multiple bytes into multiple registers */
void TI_CCxxx0_SPI_WriteRegBurst(uint8_t addr, uint8_t *buffer, uint8_t count);

/* Strobe register */
uint8_t TI_CCxxx0_SPI_Strobe(uint8_t addr);

/* Power up reset called when first power up */
void TI_CCxxx0_SPI_PowerupReset(void);

#endif