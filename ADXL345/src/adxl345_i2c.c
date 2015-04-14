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
#include "adxl345_i2c.h"

static volatile uint8_t _ADXL345_Device_Address;
static volatile I2C_TypeDef* _ADXL345_I2C;

void ADXL345_I2C_Init(ADXL345_InitTypeDef* adxl345_init_s)
{
	_ADXL345_Device_Address = adxl345_init_s->ADXL345_AltAddrStatus == ADXL345_AltAddr_ENABLE ?
														ADXL345_DEVICE_ADDR_ALT : ADXL345_DEVICE_ADDR;
	
	// Enable clock gating for GPIO Pins
	RCC_AHB1PeriphClockCmd(adxl345_init_s->ADXL345_I2C_SCL_GPIO_CLK | adxl345_init_s->ADXL345_I2C_SDA_GPIO_CLK,
													ENABLE);
	
	// I LOVE YOU
	// https://my.st.com/public/STe2ecommunities/mcu/Lists/STM32Discovery/Flat.aspx?RootFolder=%2Fpublic%2FSTe2ecommunities%2Fmcu%2FLists%2FSTM32Discovery%2FSTM32F4%20I2C%20Issues%20solved&FolderCTID=0x01200200770978C69A1141439FE559EB459D75800084C20D8867EAD444A5987D47BE638E0F&currentviews=1638
	// ALWAYS CONFIGURE AF BEFORE INITIALIZIN GPIO PINS
	// Configure AF functions
	GPIO_PinAFConfig(adxl345_init_s->ADXL345_I2C_SCL_GPIO_Port, adxl345_init_s->ADXL345_I2C_SCL_GPIO_PinSource, adxl345_init_s->ADXL345_I2C_SCL_AF);
	GPIO_PinAFConfig(adxl345_init_s->ADXL345_I2C_SDA_GPIO_Port, adxl345_init_s->ADXL345_I2C_SDA_GPIO_PinSource, adxl345_init_s->ADXL345_I2C_SDA_AF);
	
	// Initialize GPIO Pins
	GPIO_InitTypeDef gpio_init_s;
	gpio_init_s.GPIO_Mode = GPIO_Mode_AF;
	gpio_init_s.GPIO_OType = GPIO_OType_OD;
	gpio_init_s.GPIO_PuPd = GPIO_PuPd_UP;
	gpio_init_s.GPIO_Speed = GPIO_Speed_50MHz;
	
	// SCL
	gpio_init_s.GPIO_Pin = adxl345_init_s->ADXL345_I2C_SCL_GPIO_Pin;
	GPIO_Init(adxl345_init_s->ADXL345_I2C_SCL_GPIO_Port, &gpio_init_s);
	
	// SDA
	gpio_init_s.GPIO_Pin = adxl345_init_s->ADXL345_I2C_SDA_GPIO_Pin;
	GPIO_Init(adxl345_init_s->ADXL345_I2C_SDA_GPIO_Port, &gpio_init_s);

	// Enable clock gating for I2C
	RCC_APB1PeriphClockCmd(adxl345_init_s->ADXL345_I2C_CLK, ENABLE);
	
	// Initialize I2C
	I2C_InitTypeDef i2c_init_s;
	i2c_init_s.I2C_ClockSpeed = 100000;							// 100 kHz
	i2c_init_s.I2C_Mode = I2C_Mode_I2C;
	i2c_init_s.I2C_DutyCycle = I2C_DutyCycle_2;
	i2c_init_s.I2C_Ack = I2C_Ack_Disable;
	i2c_init_s.I2C_OwnAddress1 = 0x00;
	i2c_init_s.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	
	I2C_Init(adxl345_init_s->ADXL345_I2C, &i2c_init_s);
	// Enable I2C
	I2C_Cmd(adxl345_init_s->ADXL345_I2C, ENABLE);
	
	// Update static variables
	_ADXL345_I2C = adxl345_init_s->ADXL345_I2C;
}

void ADXL345_I2C_Start(uint8_t direction)
{
	// Wait until I2C is not busy
	while(I2C_GetFlagStatus(_ADXL345_I2C, I2C_FLAG_BUSY) != ADXL345_FlagReset);
	
	I2C_GenerateSTART(_ADXL345_I2C, ENABLE);
	
	// Wait until slave acknowledges
	while(I2C_CheckEvent(_ADXL345_I2C, I2C_EVENT_MASTER_MODE_SELECT) != ADXL345_FlagSet);
	
	// Send slave address
	I2C_Send7bitAddress(_ADXL345_I2C, _ADXL345_Device_Address << 1, direction);
	
	// Wait for transmit or receive event
	if (direction == I2C_Direction_Transmitter)
	{
		while(!I2C_CheckEvent(_ADXL345_I2C, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	}
	else if (direction == I2C_Direction_Receiver)
	{
		while(!I2C_CheckEvent(_ADXL345_I2C, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	}
}

void ADXL345_I2C_Stop(void)
{
	I2C_GenerateSTOP(_ADXL345_I2C, ENABLE);
}

// Read and acknowledge. Requests next byte to read
uint8_t ADXL345_I2C_ReadAck(void)
{
	I2C_AcknowledgeConfig(_ADXL345_I2C, ENABLE);
	
	// Wait until a byte has been received
	while(I2C_CheckEvent(_ADXL345_I2C, I2C_EVENT_MASTER_BYTE_RECEIVED) != ADXL345_FlagSet);
	
	return I2C_ReceiveData(_ADXL345_I2C);
}

// Read and not acknowledge. Stops the I2C
uint8_t ADXL345_I2C_ReadNack(void)
{
	I2C_AcknowledgeConfig(_ADXL345_I2C, DISABLE);
	I2C_GenerateSTOP(_ADXL345_I2C, ENABLE);
	
	// Wait until a byte has been received
	while(!I2C_CheckEvent(_ADXL345_I2C, I2C_EVENT_MASTER_BYTE_RECEIVED));
	
	return I2C_ReceiveData(_ADXL345_I2C);
}

void ADXL345_I2C_Write(uint8_t byte)
{
	I2C_SendData(_ADXL345_I2C, byte);
	
	// Wait until the data is transmitted
	while(!I2C_CheckEvent(_ADXL345_I2C, I2C_EVENT_MASTER_BYTE_TRANSMITTED));
}

uint8_t ADXL345_I2C_ReadReg(uint8_t address)
{
	// Notify slave with the register address
	ADXL345_I2C_Start(I2C_Direction_Transmitter);
	ADXL345_I2C_Write(address);
	ADXL345_I2C_Stop();
	
	// Read one byte
	ADXL345_I2C_Start(I2C_Direction_Receiver);
	return ADXL345_I2C_ReadNack();
}

void ADXL345_I2C_ReadRegMulti(uint8_t address, uint8_t* buffer, uint8_t count)
{
	// Notify slave with the register address
	ADXL345_I2C_Start(I2C_Direction_Transmitter);
	ADXL345_I2C_Write(address);
	ADXL345_I2C_Stop();
	
	uint8_t i;
	ADXL345_I2C_Start(I2C_Direction_Receiver);
	// Read every but last byte
	for (i = 0; i < count - 1; i++)
	{
		buffer[i] = ADXL345_I2C_ReadAck();
	}
	// Read last byte without acknowledgement
	buffer[count - 1] = ADXL345_I2C_ReadNack();
}

void ADXL345_I2C_WriteReg(uint8_t address, uint8_t byte)
{
	ADXL345_I2C_Start(I2C_Direction_Transmitter);
	
	// Notify slave with the register address
	ADXL345_I2C_Write(address);
	// Write data
	ADXL345_I2C_Write(byte);
	
	ADXL345_I2C_Stop();
}

void ADXL345_I2C_WriteRegMulti(uint8_t address, uint8_t* buffer, uint8_t count)
{
	ADXL345_I2C_Start(I2C_Direction_Transmitter);
	
	// Notify slave with the starting register address
	ADXL345_I2C_Write(address);
	// Write all bytes
	uint8_t i;
	for (i = 0; i < count; i++)
	{
		ADXL345_I2C_Write(buffer[i]);
	}
	
	ADXL345_I2C_Stop();
}