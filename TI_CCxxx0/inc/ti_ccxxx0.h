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
#ifndef TI_CCxxx0_H_
#define TI_CCxxx0_H_

#include "ti_ccxxx0_general.h"
#include "ti_ccxxx0_spi.h"

/* Initialize TI CCxxx0 Chip */
void TI_CCxxx0_Init(TI_CCxxx0_InitTypeDef *TI_CCxxx0_InitStruct);

/* Tranmit a packet wirelessly */
void TI_CCxxx0_TransmitPacket(uint8_t *txBuffer, uint8_t size);

/* Receive a packet wirelessly */
uint8_t TI_CCxxx0_ReceivePacket(uint8_t *rxBuffer, uint8_t *size);

/* Configure GDO Pin */
void TI_CCxxx0_TxGDOConfig(TI_CCxxx0_TxGDOTypeDef *TI_CCxxx0_TxStruct);

/* Configure GDO Pin interrupt used in receive mode */
void TI_CCxxx0_RxInterruptConfig(TI_CCxxx0_RxInterruptTypeDef *TI_CCxxx0_RxStruct);

#endif