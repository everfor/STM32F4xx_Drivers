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
#include "ti_ccxxx0_spi.h"

/** Information extracted from initializaiton */
static volatile SPI_TypeDef* _TI_CCxxx0_SPI;
static volatile GPIO_TypeDef* _TI_CCxxx0_CSn_GPIO_Port;
static volatile uint32_t _TI_CCxxx0_CSn_GPIO_Pin;
static volatile GPIO_TypeDef* _TI_CCxxx0_MISO_GPIO_Port;
static volatile uint32_t _TI_CCxxx0_MISO_GPIO_Pin;
static volatile GPIO_TypeDef* _TI_CCxxx0_GDO0_GPIO_Port;
static volatile uint32_t _TI_CCxxx0_GDO0_GPIO_Pin;

void TI_CCxxx0_SPI_Init(TI_CCxxx0_InitTypeDef *TI_CCxxx0_SPI_InitStruct)
{
	// Enable SPI Periph
	if (TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_Periph == TI_CCxxx0_SPI_Periph_APB1)
	{
		RCC_APB1PeriphClockCmd(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_CLK, ENABLE);
	}
	else
	{
		RCC_APB2PeriphClockCmd(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_CLK, ENABLE);
	}
	
	// Enable GPIO Periphs
	RCC_AHB1PeriphClockCmd(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_SCK_GPIO_CLK | TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MISO_GPIO_CLK
												|TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MOSI_GPIO_CLK,
												ENABLE);
	RCC_AHB1PeriphClockCmd(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_CSn_GPIO_CLK, ENABLE);
	
	// Initialize GPIO Pins for SCK, MOSI, MISO and CSn
	GPIO_InitTypeDef gpio_init_s;
	// GPIO configurations
	gpio_init_s.GPIO_Mode = GPIO_Mode_AF;
	gpio_init_s.GPIO_OType = GPIO_OType_PP;
	gpio_init_s.GPIO_PuPd = GPIO_PuPd_NOPULL;
	gpio_init_s.GPIO_Speed = GPIO_Speed_50MHz;
	
	// SCK
	gpio_init_s.GPIO_Pin = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_SCK_GPIO_Pin;
	GPIO_Init(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_SCK_GPIO_Port, &gpio_init_s);
	
	// MOSI
	gpio_init_s.GPIO_Pin = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MOSI_GPIO_Pin;
	GPIO_Init(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MOSI_GPIO_Port, &gpio_init_s);
	
	// MISO
	gpio_init_s.GPIO_Pin = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MISO_GPIO_Pin;
	GPIO_Init(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MISO_GPIO_Port, &gpio_init_s);
	
	GPIO_PinAFConfig(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_SCK_GPIO_Port, TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_SCK_GPIO_PinSource, TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_SCK_AF);
	GPIO_PinAFConfig(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MOSI_GPIO_Port, TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MOSI_GPIO_PinSource, TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MOSI_AF);
	GPIO_PinAFConfig(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MISO_GPIO_Port, TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MISO_GPIO_PinSource, TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MISO_AF);
	
	// CSn
	gpio_init_s.GPIO_Mode = GPIO_Mode_OUT;
	gpio_init_s.GPIO_PuPd = GPIO_PuPd_UP;
	gpio_init_s.GPIO_Pin = GPIO_Pin_13;
	GPIO_Init(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_CSn_GPIO_Port, &gpio_init_s);
	
	// Deselect CSn for periph SPI
	GPIO_SetBits(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_CSn_GPIO_Port, TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_CSn_GPIO_Pin);
	
	// Initialize SPI
	SPI_InitTypeDef spi_init_s;
	// SPI Configurations
	spi_init_s.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	spi_init_s.SPI_DataSize = SPI_DataSize_8b;
	spi_init_s.SPI_CPOL = SPI_CPOL_High;
	spi_init_s.SPI_CPHA = SPI_CPHA_2Edge;
	spi_init_s.SPI_NSS = SPI_NSS_Soft | SPI_NSSInternalSoft_Set;
	spi_init_s.SPI_BaudRatePrescaler = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_Periph == TI_CCxxx0_SPI_Periph_APB1 ? 
																				SPI_BaudRatePrescaler_16 : SPI_BaudRatePrescaler_32;			// SPI1 has clock freq of 84MHz and SPI2/SPI3 has 42MHz, this sets the clock freq to be 5.25/2.875 MHz
	spi_init_s.SPI_FirstBit = SPI_FirstBit_MSB;
	spi_init_s.SPI_Mode = SPI_Mode_Master;
	// Deinit and then init just to be safe
	SPI_I2S_DeInit(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI);
	SPI_Init(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI, &spi_init_s);
	// Enable SPI
	SPI_Cmd(TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI, ENABLE);
	
	// Update initialization info
	_TI_CCxxx0_SPI = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI;
	_TI_CCxxx0_CSn_GPIO_Port = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_CSn_GPIO_Port;
	_TI_CCxxx0_CSn_GPIO_Pin = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_CSn_GPIO_Pin;
	_TI_CCxxx0_MISO_GPIO_Port = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MISO_GPIO_Port;
	_TI_CCxxx0_MISO_GPIO_Pin = TI_CCxxx0_SPI_InitStruct->TI_CCxxx0_SPI_MISO_GPIO_Pin;
	
	// Power-up reset
	TI_CCxxx0_SPI_PowerupReset();
}

uint8_t TI_CCxxx0_SPI_SendByte(uint8_t byte)
{
	while (SPI_I2S_GetFlagStatus(_TI_CCxxx0_SPI, SPI_I2S_FLAG_TXE) == RESET);
	//SPI_I2S_ClearFlag(_TI_CCxxx0_SPI, SPI_I2S_FLAG_TXE);
	SPI_I2S_SendData(_TI_CCxxx0_SPI, byte);
	while (SPI_I2S_GetFlagStatus(_TI_CCxxx0_SPI, SPI_I2S_FLAG_BSY) != RESET);
	
	while (SPI_I2S_GetFlagStatus(_TI_CCxxx0_SPI, SPI_I2S_FLAG_RXNE) == RESET);
	//SPI_I2S_ClearFlag(_TI_CCxxx0_SPI, SPI_I2S_FLAG_RXNE);
	uint8_t result = (uint8_t)SPI_I2S_ReceiveData(_TI_CCxxx0_SPI);
	while (SPI_I2S_GetFlagStatus(_TI_CCxxx0_SPI, SPI_I2S_FLAG_BSY) != RESET);
	
	return result;
}

void TI_CCxxx0_SPI_CSn_Select(void)
{
	// Pull down CSn
	GPIO_ResetBits(_TI_CCxxx0_CSn_GPIO_Port, _TI_CCxxx0_CSn_GPIO_Pin);
}

void TI_CCxxx0_SPI_CSn_Deselect(void)
{
	// Pull up CSn
	GPIO_SetBits(_TI_CCxxx0_CSn_GPIO_Port, _TI_CCxxx0_CSn_GPIO_Pin);
}

uint8_t TI_CCxxx0_SPI_ReadReg(uint8_t addr)
{
	TI_CCxxx0_SPI_CSn_Select();
	
	// Notify TI_CCxxx0 with the destination register address
	TI_CCxxx0_SPI_SendByte(addr | TI_CCxxx0_Read_Single);
	
	// Read the byte stored in the register
	uint8_t byte = TI_CCxxx0_SPI_SendByte(TI_CCxxx0_Dummy_Byte);
	
	TI_CCxxx0_SPI_CSn_Deselect();
	
	return byte;
}

uint8_t TI_CCxxx0_SPI_ReadStatusReg(uint8_t addr)
{
	TI_CCxxx0_SPI_CSn_Select();
	
	// Notify TI_CCxxx0 with the destination register address
	TI_CCxxx0_SPI_SendByte(addr | TI_CCxxx0_Read_Burst);
	
	// Read the byte stored in the register
	uint8_t byte = TI_CCxxx0_SPI_SendByte(TI_CCxxx0_Dummy_Byte);
	
	TI_CCxxx0_SPI_CSn_Deselect();
	
	return byte;
}

void TI_CCxxx0_SPI_ReadRegBurst(uint8_t addr, uint8_t *buffer, uint8_t count)
{
	TI_CCxxx0_SPI_CSn_Select();
	
	// Notify TI_CCxxx0 with the starting address of burst reading registers
	TI_CCxxx0_SPI_SendByte(addr | TI_CCxxx0_Read_Burst);
	
	uint8_t i;
	for (i = 0; i < count; i++)
	{
		buffer[i] = TI_CCxxx0_SPI_SendByte(TI_CCxxx0_Dummy_Byte);
	}
	
	TI_CCxxx0_SPI_CSn_Deselect();
}

void TI_CCxxx0_SPI_WriteReg(uint8_t addr, uint8_t byte)
{
	TI_CCxxx0_SPI_CSn_Select();
	
	// Notify TI_CCxxx0 with the destination register address
	TI_CCxxx0_SPI_SendByte(addr | TI_CCxxx0_Write_Single);
	
	// Write the byte to the register
	TI_CCxxx0_SPI_SendByte(byte);

	TI_CCxxx0_SPI_CSn_Deselect();
}

void TI_CCxxx0_SPI_WriteRegBurst(uint8_t addr, uint8_t *buffer, uint8_t count)
{
	TI_CCxxx0_SPI_CSn_Select();
	
	// Notify TI_CCxxx0 with the starting address of burst writing registers
	TI_CCxxx0_SPI_SendByte(addr | TI_CCxxx0_Write_Burst);
	
	uint8_t i;
	for (i = 0; i < count; i++)
	{
		TI_CCxxx0_SPI_SendByte(buffer[i]);
	}
	
	TI_CCxxx0_SPI_CSn_Deselect();
}

uint8_t TI_CCxxx0_SPI_Strobe(uint8_t addr)
{
	TI_CCxxx0_SPI_CSn_Select();
	
	TI_CCxxx0_SPI_SendByte(addr);
	uint8_t status = TI_CCxxx0_SPI_SendByte(TI_CCxxx0_Dummy_Byte);
	
	TI_CCxxx0_SPI_CSn_Deselect();
	
	return status;
}

void TI_CCxxx0_Wait(uint8_t cycles)
{
	while (cycles > 15)
	{
		cycles -= 6;
	}
}

void TI_CCxxx0_SPI_PowerupReset(void)
{
	// Disable CSn
	GPIO_SetBits(_TI_CCxxx0_CSn_GPIO_Port, _TI_CCxxx0_CSn_GPIO_Pin);
	TI_CCxxx0_Wait(30);
	
	// Enable CSn
	GPIO_ResetBits(_TI_CCxxx0_CSn_GPIO_Port, _TI_CCxxx0_CSn_GPIO_Pin);
	TI_CCxxx0_Wait(30);
	
	// Disable CSn
	GPIO_SetBits(_TI_CCxxx0_CSn_GPIO_Port, _TI_CCxxx0_CSn_GPIO_Pin);
	TI_CCxxx0_Wait(45);
	
	TI_CCxxx0_SPI_Strobe(REG_TI_CCxxx0_SRES);
}
