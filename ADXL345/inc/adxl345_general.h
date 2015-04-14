#ifndef ADXL345_GENERAL_H_
#define ADXL345_GENERAL_H_

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

#define ADXL345_DEVICE_ADDR				0x1D
#define ADXL345_DEVICE_ADDR_ALT			0x53

/* Register addresses */
#define REG_ADXL345_DEVID				0x00
#define REG_ADXL345_THRESH_TAP			0x1D
#define REG_ADXL345_OFSX				0x1E
#define REG_ADXL345_OFSY				0x1F
#define REG_ADXL345_OFSZ				0x20
#define REG_ADXL345_DUR					0x21
#define REG_ADXL345_Latent				0x22
#define REG_ADXL345_Window				0x23
#define REG_ADXL345_THRESH_ACT			0x24
#define REG_ADXL345_THRESH_INACT		0x25
#define REG_ADXL345_TIME_INACT			0x26
#define REG_ADXL345_ACT_INACT_CTL		0x27
#define REG_ADXL345_THRESH_FF			0x28
#define REG_ADXL345_TIME_FF				0x29
#define REG_ADXL345_TAP_AXES			0x2A
#define REG_ADXL345_ACT_TAP_STATUS		0x2B
#define REG_ADXL345_BW_RATE				0x2C
#define REG_ADXL345_POWER_CTL			0x2D
#define REG_ADXL345_INT_ENABLE			0x2E
#define REG_ADXL345_INT_MAP				0x2F
#define REG_ADXL345_INT_SOURCE			0x30
#define REG_ADXL345_DATA_FORMAT			0x31
#define REG_ADXL345_DATAX0				0x32
#define REG_ADXL345_DATAX1				0x33
#define REG_ADXL345_DATAY0				0x34
#define REG_ADXL345_DATAY1				0x35
#define REG_ADXL345_DATAZ0				0x36
#define REG_ADXL345_DATAZ1				0x37
#define REG_ADXL345_FIFO_CTL			0x38
#define REG_ADXL345_FIFO_STATUS			0x39

/* Masks */
#define ADXL345_RangeBit_Mask			0x03
#define ADXL345_FullResBit_Mask			0x04

/* Data Ranges */
static float ADXL345_Ranges[4] = {4.0f, 8.0f, 16.0f, 32.0f};
#define ADXL345_RangeBit_2G				0x00
#define ADXL345_RangeBit_4G				0x01
#define ADXL345_RangeBit_8G				0x02
#define ADXL345_RangeBit_16G			0x03
#define ADXL345_Data_FullRange			0x400
static uint16_t ADXL345_Data_FullRanges[4] = {0x0400, 0x0800, 0x1000, 0x2000};

/* Data Indices */
#define ADXL345_DataX0_Index			0
#define ADXL345_DataX1_Index			1
#define ADXL345_DataY0_Index			2
#define ADXL345_DataY1_Index			3
#define ADXL345_DataZ0_Index			4
#define ADXL345_DataZ1_Index			5

/* Flags */
#define ADXL345_FlagReset				0x00
#define ADXL345_FlagSet					0x01

/* Data structures */
#define ADXL345_AltAddr_ENABLE			0x01
#define ADXL345_AltAddr_DISABLE			0x00

/* Initialization Struct */
typedef struct
{
	uint8_t				ADXL345_AltAddrStatus;

	I2C_TypeDef*		ADXL345_I2C;
	uint32_t			ADXL345_I2C_CLK;

	uint32_t			ADXL345_I2C_SCL_GPIO_Pin;
	uint16_t			ADXL345_I2C_SCL_GPIO_PinSource;
	GPIO_TypeDef*		ADXL345_I2C_SCL_GPIO_Port;
	uint32_t			ADXL345_I2C_SCL_GPIO_CLK;
	uint8_t				ADXL345_I2C_SCL_AF;

	uint32_t			ADXL345_I2C_SDA_GPIO_Pin;
	uint16_t			ADXL345_I2C_SDA_GPIO_PinSource;
	GPIO_TypeDef*		ADXL345_I2C_SDA_GPIO_Port;
	uint32_t			ADXL345_I2C_SDA_GPIO_CLK;
	uint8_t				ADXL345_I2C_SDA_AF;
} ADXL345_InitTypeDef;

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
#define ADXL345_InterruptEnable_INT1		0x01
#define ADXL345_InterruptEnable_INT2		0x02

#define ADXL345_INT1_NVIC_Priority_Cmd_ENABLE			0x01
#define ADXL345_INT1_NVIC_Priority_Cmd_DISABLE			0x00
#define ADXL345_INT2_NVIC_Priority_Cmd_ENABLE			0x01
#define ADXL345_INT2_NVIC_Priority_Cmd_DISABLE			0x00

/* Interrupt Configuration Struct */
typedef struct
{
	uint8_t					ADXL345_InterruptEnable;

	uint32_t				ADXL345_INT1_GPIO_Pin;
	uint16_t				ADXL345_INT1_PinSource;
	GPIO_TypeDef*		ADXL345_INT1_Port;
	uint32_t				ADXL345_INT1_CLK;
	
	uint32_t				ADXL345_INT1_EXTI_Line;
	uint8_t					ADXL345_INT1_EXTI_PortSource;
	uint8_t					ADXL345_INT1_EXTI_PinSource;
	
	uint8_t					ADXL345_INT1_NVIC_IRQChannel;
	uint8_t					ADXL345_INT1_NVIC_Priority_Cmd;
	uint8_t					ADXL345_INT1_NVIC_Priotity;
	uint8_t					ADXL345_INT1_NVIC_Subpriority;

	uint32_t				ADXL345_INT2_GPIO_Pin;
	uint16_t				ADXL345_INT2_PinSource;
	GPIO_TypeDef*		ADXL345_INT2_Port;
	uint32_t				ADXL345_INT2_CLK;
	
	uint32_t				ADXL345_INT2_EXTI_Line;
	uint8_t					ADXL345_INT2_EXTI_PortSource;
	uint8_t					ADXL345_INT2_EXTI_PinSource;
	
	uint8_t					ADXL345_INT2_NVIC_IRQChannel;
	uint8_t					ADXL345_INT2_NVIC_Priority_Cmd;
	uint8_t					ADXL345_INT2_NVIC_Priotity;
	uint8_t					ADXL345_INT2_NVIC_Subpriority;
} ADXL345_InterruptTypeDef;

#endif