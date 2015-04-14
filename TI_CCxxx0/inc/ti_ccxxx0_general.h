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
#ifndef TI_CCxxx0_GENERAL_H_
#define TI_CCxxx0_GENERAL_H_

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

/**  Register Addresses */
// Conmfiguration Registers
#define REG_TI_CCxxx0_IOCFG2			0x00
#define REG_TI_CCxxx0_IOCFG1			0x01
#define REG_TI_CCxxx0_IOCFG0			0x02
#define REG_TI_CCxxx0_FIFOTHR			0x03
#define REG_TI_CCxxx0_SYNC1				0x04
#define REG_TI_CCxxx0_SYNC0				0x05
#define REG_TI_CCxxx0_PKTLEN			0x06
#define REG_TI_CCxxx0_PKTCTRL1			0x07
#define REG_TI_CCxxx0_PKTCTRL0			0x08
#define REG_TI_CCxxx0_ADDR				0x09
#define REG_TI_CCxxx0_CHANNR			0x0A
#define REG_TI_CCxxx0_FSCTRL1			0x0B
#define REG_TI_CCxxx0_FSCTRL0			0x0C
#define REG_TI_CCxxx0_FREQ2				0x0D
#define REG_TI_CCxxx0_FREQ1				0x0E
#define REG_TI_CCxxx0_FREQ0				0x0F
#define REG_TI_CCxxx0_MDMCFG4			0x10
#define REG_TI_CCxxx0_MDMCFG3			0x11
#define REG_TI_CCxxx0_MDMCFG2			0x12
#define REG_TI_CCxxx0_MDMCFG1			0x13
#define REG_TI_CCxxx0_MDMCFG0			0x14
#define REG_TI_CCxxx0_DEVIATN			0x15
#define REG_TI_CCxxx0_MCSM2				0x16
#define REG_TI_CCxxx0_MCSM1				0x17
#define REG_TI_CCxxx0_MCSM0				0x18
#define REG_TI_CCxxx0_FOCCFG			0x19
#define REG_TI_CCxxx0_BSCFG				0x1A
#define REG_TI_CCxxx0_AGCTRL2			0x1B
#define REG_TI_CCxxx0_AGCTRL1			0x1C
#define REG_TI_CCxxx0_AGCTRL0			0x1D
#define REG_TI_CCxxx0_WOREVT1			0x1E
#define REG_TI_CCxxx0_WOREVT0			0x1F
#define REG_TI_CCxxx0_WORCTRL			0x20
#define REG_TI_CCxxx0_FREND1			0x21
#define REG_TI_CCxxx0_FREND0			0x22
#define REG_TI_CCxxx0_FSCAL3			0x23
#define REG_TI_CCxxx0_FSCAL2			0x24
#define REG_TI_CCxxx0_FSCAL1			0x25
#define REG_TI_CCxxx0_FSCAL0			0x26
#define REG_TI_CCxxx0_RCCTRL1			0x27
#define REG_TI_CCxxx0_RCCTRL0			0x28
#define REG_TI_CCxxx0_FSTEST			0x29
#define REG_TI_CCxxx0_PTEST				0x2A
#define REG_TI_CCxxx0_AGCTEST			0x2B
#define REG_TI_CCxxx0_TEST2				0x2C
#define REG_TI_CCxxx0_TEST1				0x2D
#define REG_TI_CCxxx0_TEST0				0x2E

// Status Registers
#define REG_TI_CCxxx0_PARTNUM			0x30
#define REG_TI_CCxxx0_VERSION			0x31
#define REG_TI_CCxxx0_FREQEST			0x32
#define REG_TI_CCxxx0_LQI				0x33
#define REG_TI_CCxxx0_RSSI				0x34
#define REG_TI_CCxxx0_MARCSTATE			0x35
#define REG_TI_CCxxx0_WORTIME1			0x36
#define REG_TI_CCxxx0_WORTIME0			0x37
#define REG_TI_CCxxx0_PKTSTATUS			0x38
#define REG_TI_CCxxx0_VCO_VC_DAC		0x39
#define REG_TI_CCxxx0_TXBYTES			0x3A
#define REG_TI_CCxxx0_RXBYTES			0x3B
#define REG_TI_CCxxx0_RCCTRL1_STATUS	0x3C
#define REG_TI_CCxxx0_RCCTRL0_STATUS	0x3D

// Strobe Registers
#define REG_TI_CCxxx0_SRES				0x30
#define REG_TI_CCxxx0_SFSTXON			0x31
#define REG_TI_CCxxx0_SXOFF				0x32
#define REG_TI_CCxxx0_SCAL				0x33
#define REG_TI_CCxxx0_SRX				0x34
#define REG_TI_CCxxx0_STX				0x35
#define REG_TI_CCxxx0_SIDLE				0x36
#define REG_TI_CCxxx0_SWOR				0x38
#define REG_TI_CCxxx0_SPWD				0x39
#define REG_TI_CCxxx0_SFRX				0x3A
#define REG_TI_CCxxx0_SFTX				0x3B
#define REG_TI_CCxxx0_SWORRST			0x3C
#define REG_TI_CCxxx0_SNOP				0x3D

/** Other Memory Locations */
#define TI_CCxxx0_PATABLE				0x3E
#define TI_CCxxx0_TXFIFO				0x3F
#define TI_CCxxx0_RXFIFO				0x3F

/** Read/Write Code */
#define TI_CCxxx0_Write_Single			0x00
#define TI_CCxxx0_Write_Burst			0x40
#define TI_CCxxx0_Read_Single			0x80
#define TI_CCxxx0_Read_Burst			0xC0

/** Utilities */
#define TI_CCxxx0_Dummy_Byte			0x00
#define TI_CCxxx0_SetFlag				0x01
#define TI_CCxxx0_ResetFlag				0x00
#define TI_CCxxx0_Status_Error			0x00
#define TI_CCxxx0_Status_OK				0x80
#define TI_CCxxx0_PKTCTRL0_LENGTH_CONFIG_VariableLength	0x01

/** Masks */
#define TI_CCxxx0_CHIP_RDYn_Mask				0x80
#define TI_CCxxx0_RXBytes_Mask					0x7F
#define TI_CCxxx0_RX_LQI_CRC_OK_Mask			0x80
#define TI_CCxxx0_PKTCTRL1_APPEND_STATUS_Mask	0x04
#define TI_CCxxx0_PKTCTRL0_LENGTH_CONFIG_Mask	0x03

/** Status Bytes Indices */
#define TI_CCxxx0_RX_RSSI_Index			0
#define TI_CCxxx0_RX_LQI_Index			1

#define TI_CCxxx0_SPI_Periph_APB1		0x00
#define TI_CCxxx0_SPI_Periph_APB2		0x01

/** Data Structures */
/** Initialization Struct */
typedef struct
{
	// The SPI used for communication with the chip from the board
	SPI_TypeDef*				TI_CCxxx0_SPI;
	uint32_t					TI_CCxxx0_SPI_CLK;
	uint8_t						TI_CCxxx0_SPI_Periph;
	
	// SCK Pin for SPI
	uint32_t					TI_CCxxx0_SPI_SCK_GPIO_Pin;
	uint16_t					TI_CCxxx0_SPI_SCK_GPIO_PinSource;
	GPIO_TypeDef*				TI_CCxxx0_SPI_SCK_GPIO_Port;
	uint32_t					TI_CCxxx0_SPI_SCK_GPIO_CLK;
	uint8_t						TI_CCxxx0_SPI_SCK_AF;
	
	// MOSI Pin for SPI
	uint32_t					TI_CCxxx0_SPI_MOSI_GPIO_Pin;
	uint16_t					TI_CCxxx0_SPI_MOSI_GPIO_PinSource;
	GPIO_TypeDef*				TI_CCxxx0_SPI_MOSI_GPIO_Port;
	uint32_t					TI_CCxxx0_SPI_MOSI_GPIO_CLK;
	uint8_t						TI_CCxxx0_SPI_MOSI_AF;
	
	// MISO Pin for MISO
	uint32_t					TI_CCxxx0_SPI_MISO_GPIO_Pin;
	uint16_t					TI_CCxxx0_SPI_MISO_GPIO_PinSource;
	GPIO_TypeDef*				TI_CCxxx0_SPI_MISO_GPIO_Port;
	uint32_t					TI_CCxxx0_SPI_MISO_GPIO_CLK;
	uint8_t						TI_CCxxx0_SPI_MISO_AF;
	
	// CSn Pin for MISO
	uint32_t					TI_CCxxx0_SPI_CSn_GPIO_Pin;
	GPIO_TypeDef*				TI_CCxxx0_SPI_CSn_GPIO_Port;
	uint32_t					TI_CCxxx0_SPI_CSn_GPIO_CLK;
} TI_CCxxx0_InitTypeDef;

/** GDO Pin Config for Tx mode */
typedef struct
{
	uint32_t					TI_CCxxx0_TxGDO_GPIO_Pin;
	GPIO_TypeDef*				TI_CCxxx0_TxGDO_GPIO_Port;
	uint32_t					TI_CCxxx0_TxGDO_GPIO_CLK;
} TI_CCxxx0_TxGDOTypeDef;

/** Flags indicating interrupt priorities are customized or not */
#define TI_CCxxx0_RxInterrupt_NVIC_Priority_ENABLE			0x01
#define TI_CCxxx0_RxInterrupt_NVIC_Priority_DISABLE		0x00

/** GDO Pin Interrupt Config for Rx mode */
typedef struct
{
	uint32_t					TI_CCxxx0_RxInterrupt_GPIO_Pin;
	GPIO_TypeDef*				TI_CCxxx0_RxInterrupt_GPIO_Port;
	uint32_t					TI_CCxxx0_RxInterrupt_GPIO_CLK;
	
	uint32_t					TI_CCxxx0_RxInterrupt_EXTI_Line;
	uint8_t						TI_CCxxx0_RxInterrupt_EXTI_PortSource;
	uint8_t						TI_CCxxx0_RxInterrupt_EXTI_PinSource;
	
	uint8_t						TI_CCxxx0_RxInterrupt_NVIC_IRQChannel;
	uint8_t						TI_CCxxx0_RxInterrupt_NVIC_Priority_Cmd;
	uint8_t						TI_CCxxx0_RxInterrupt_NVIC_Priotity;
	uint8_t						TI_CCxxx0_RxInterrupt_NVIC_Subpriority;
} TI_CCxxx0_RxInterruptTypeDef;

#endif