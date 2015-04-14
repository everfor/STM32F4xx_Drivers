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
#include "ti_ccxxx0.h"
#include "ti_ccxxx0_settings.h"

/** For TX Mode */
static volatile GPIO_TypeDef* _TI_CCxxx0_TXGDO_GPIO_Port;
static volatile uint32_t _TI_CCxxx0_TXGDO_GPIO_Pin;

void TI_CCxxx0_Init(TI_CCxxx0_InitTypeDef *TI_CCxxx0_InitStruct)
{
	// Init SPI configs for TI_CCxxx0
	TI_CCxxx0_SPI_Init(TI_CCxxx0_InitStruct);
}

void TI_CCxxx0_TxGDOConfig(TI_CCxxx0_TxGDOTypeDef *TI_CCxxx0_TxStruct)
{
	// Enable clock gating
	RCC_AHB1PeriphClockCmd(TI_CCxxx0_TxStruct->TI_CCxxx0_TxGDO_GPIO_CLK, ENABLE);
	
	GPIO_InitTypeDef gpio_init_s;
	
	gpio_init_s.GPIO_Mode = GPIO_Mode_IN;
	gpio_init_s.GPIO_OType = GPIO_OType_PP;
	gpio_init_s.GPIO_PuPd = GPIO_PuPd_DOWN;
	gpio_init_s.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init_s.GPIO_Pin = TI_CCxxx0_TxStruct->TI_CCxxx0_TxGDO_GPIO_Pin;
	
	GPIO_Init(TI_CCxxx0_TxStruct->TI_CCxxx0_TxGDO_GPIO_Port, &gpio_init_s);
	
	// Update private variables in this module
	_TI_CCxxx0_TXGDO_GPIO_Port = TI_CCxxx0_TxStruct->TI_CCxxx0_TxGDO_GPIO_Port;
	_TI_CCxxx0_TXGDO_GPIO_Pin = TI_CCxxx0_TxStruct->TI_CCxxx0_TxGDO_GPIO_Pin;
}

void TI_CCxxx0_RxInterruptConfig(TI_CCxxx0_RxInterruptTypeDef *TI_CCxxx0_RxStruct)
{
	// Enable clock gating for GPIO pin
	RCC_AHB1PeriphClockCmd(TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_GPIO_CLK, ENABLE);
	// Enable clock gating for SYSCONFIG
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	
	// Initialize GPIO pin
	GPIO_InitTypeDef gpio_init_s;
	gpio_init_s.GPIO_Mode = GPIO_Mode_IN;
	gpio_init_s.GPIO_OType = GPIO_OType_PP;
	gpio_init_s.GPIO_PuPd = GPIO_PuPd_DOWN;
	gpio_init_s.GPIO_Speed = GPIO_Speed_50MHz;
	gpio_init_s.GPIO_Pin = TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_GPIO_Pin;
	GPIO_Init(TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_GPIO_Port, &gpio_init_s);
	
	// Configure EXTI line to GPIO Pin
	SYSCFG_EXTILineConfig(TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_EXTI_PortSource, TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_EXTI_PinSource);
	
	// Initialize EXTI
	EXTI_InitTypeDef exti_init_s;
	exti_init_s.EXTI_Line = TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_EXTI_Line;
	exti_init_s.EXTI_LineCmd = ENABLE;
	exti_init_s.EXTI_Mode = EXTI_Mode_Interrupt;
	exti_init_s.EXTI_Trigger = EXTI_Trigger_Falling;
	EXTI_Init(&exti_init_s);
	
	// Initialize NVIC
	NVIC_InitTypeDef nvic_init_s;
	nvic_init_s.NVIC_IRQChannel = TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_NVIC_IRQChannel;
	nvic_init_s.NVIC_IRQChannelCmd = ENABLE;
	nvic_init_s.NVIC_IRQChannelPreemptionPriority = TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_NVIC_Priority_Cmd == TI_CCxxx0_RxInterrupt_NVIC_Priority_ENABLE ?
																									TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_NVIC_Priotity : 0x00;
	nvic_init_s.NVIC_IRQChannelSubPriority = TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_NVIC_Priority_Cmd == TI_CCxxx0_RxInterrupt_NVIC_Priority_ENABLE ?
																					TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_NVIC_Subpriority : 0x00;
	NVIC_Init(&nvic_init_s);
	
	// Force software interrupt once to enable the interrupt routine
	EXTI_GenerateSWInterrupt(TI_CCxxx0_RxStruct->TI_CCxxx0_RxInterrupt_EXTI_Line);
}

void TI_CCxxx0_TransmitPacket(uint8_t *txBuffer, uint8_t size)
{
	// Flush tx FIFO
	// TI_CCxxx0_SPI_Strobe(REG_TI_CCxxx0_SFTX);
	// Write data to tx fifo buffer
	TI_CCxxx0_SPI_WriteRegBurst(TI_CCxxx0_TXFIFO, txBuffer, size);
	// Strobe to enable TX mode
	TI_CCxxx0_SPI_Strobe(REG_TI_CCxxx0_STX);
	
	// Wait for sync word to be tranmitted - wait until GDO0 is high
	while(GPIO_ReadInputDataBit(_TI_CCxxx0_TXGDO_GPIO_Port, _TI_CCxxx0_TXGDO_GPIO_Pin) != TI_CCxxx0_SetFlag);
	
	// Wait for packet to finish transmitting - wait until GDO0 is reset to low
	while(GPIO_ReadInputDataBit(_TI_CCxxx0_TXGDO_GPIO_Port, _TI_CCxxx0_TXGDO_GPIO_Pin) != TI_CCxxx0_ResetFlag);
}

uint8_t TI_CCxxx0_ReceivePacket(uint8_t *rxBuffer, uint8_t *size)
{
	uint8_t packet_len;
	uint8_t status[2];
	
	packet_len = TI_CCxxx0_SPI_ReadStatusReg(REG_TI_CCxxx0_RXBYTES) & TI_CCxxx0_RXBytes_Mask;

	// Read data if packet length is larger than 0
	if (packet_len != TI_CCxxx0_ResetFlag)
	{
		if (packet_len <= *size)
		{
			// If legnth byte is attached at the head of the payload
			if ((TI_CCxxx0_SPI_ReadReg(REG_TI_CCxxx0_PKTCTRL0) & TI_CCxxx0_PKTCTRL0_LENGTH_CONFIG_Mask) == 
						TI_CCxxx0_PKTCTRL0_LENGTH_CONFIG_VariableLength)
			{
				packet_len = TI_CCxxx0_SPI_ReadReg(TI_CCxxx0_RXFIFO);
			}
			
			// Just read
			TI_CCxxx0_SPI_ReadRegBurst(TI_CCxxx0_RXFIFO, rxBuffer, packet_len);
			// Update correct packet size
			*size = packet_len;
			
			// Read the appended status byte
			if ((TI_CCxxx0_SPI_ReadReg(REG_TI_CCxxx0_PKTCTRL1) & TI_CCxxx0_PKTCTRL1_APPEND_STATUS_Mask) != TI_CCxxx0_ResetFlag)
			{
				TI_CCxxx0_SPI_ReadRegBurst(TI_CCxxx0_RXFIFO, status, 2);
				return status[TI_CCxxx0_RX_LQI_Index] & TI_CCxxx0_RX_LQI_CRC_OK_Mask;
			}

			return TI_CCxxx0_Status_OK;
		}
		else
		{
			// Requested size larger than available packet length
			*size = packet_len;
			// Flush the RX buffer
			TI_CCxxx0_SPI_Strobe(REG_TI_CCxxx0_SFRX);
			
			return TI_CCxxx0_Status_Error;
		}
	}
	
	// Nothing happened - return error
	return TI_CCxxx0_Status_Error;
}