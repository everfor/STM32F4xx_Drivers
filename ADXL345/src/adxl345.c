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

#include <math.h>
#ifndef M_PI
#define M_PI							3.1415926535
#endif

static uint8_t buffer[ADXL345_DATA_COUNT];

void ADXL345_Init(ADXL345_InitTypeDef* adxl345_init_s)
{
	ADXL345_I2C_Init(adxl345_init_s);
}

void ADXL345_InterruptConfig(ADXL345_InterruptTypeDef* adxl345_interrupt_s)
{
	if ((adxl345_interrupt_s->ADXL345_InterruptEnable & ADXL345_InterruptEnable_INT1) != ADXL345_FlagReset)
	{
		// Enable interrupt for INT1
		
		// Enable clock gating for GPIO
		RCC_AHB1PeriphClockCmd(adxl345_interrupt_s->ADXL345_INT1_CLK, ENABLE);
		// Enable clock gating for sysconfig
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
		
		GPIO_InitTypeDef gpio_init_s;
		gpio_init_s.GPIO_Mode = GPIO_Mode_IN;
		gpio_init_s.GPIO_OType = GPIO_OType_PP;
		gpio_init_s.GPIO_PuPd = GPIO_PuPd_DOWN;
		gpio_init_s.GPIO_Speed = GPIO_Speed_50MHz;
		gpio_init_s.GPIO_Pin = adxl345_interrupt_s->ADXL345_INT1_GPIO_Pin;
		GPIO_Init(adxl345_interrupt_s->ADXL345_INT1_Port, &gpio_init_s);
		
		// Configure EXTI line to GPIO Pin
		SYSCFG_EXTILineConfig(adxl345_interrupt_s->ADXL345_INT1_EXTI_PortSource, adxl345_interrupt_s->ADXL345_INT1_EXTI_PinSource);
		
		// Initialize EXTI
		EXTI_InitTypeDef exti_init_s;
		exti_init_s.EXTI_Line = adxl345_interrupt_s->ADXL345_INT1_EXTI_Line;
		exti_init_s.EXTI_LineCmd = ENABLE;
		exti_init_s.EXTI_Mode = EXTI_Mode_Interrupt;
		exti_init_s.EXTI_Trigger = EXTI_Trigger_Falling;
		EXTI_Init(&exti_init_s);
		
		// Initialize NVIC
		NVIC_InitTypeDef nvic_init_s;
		nvic_init_s.NVIC_IRQChannel = adxl345_interrupt_s->ADXL345_INT1_NVIC_IRQChannel;
		nvic_init_s.NVIC_IRQChannelCmd = ENABLE;
		nvic_init_s.NVIC_IRQChannelPreemptionPriority = adxl345_interrupt_s->ADXL345_INT1_NVIC_Priority_Cmd == ADXL345_INT1_NVIC_Priority_Cmd_ENABLE ?
																										adxl345_interrupt_s->ADXL345_INT1_NVIC_Priotity : 0x00;
		nvic_init_s.NVIC_IRQChannelSubPriority = adxl345_interrupt_s->ADXL345_INT1_NVIC_Priority_Cmd == ADXL345_INT1_NVIC_Priority_Cmd_ENABLE ?
																										adxl345_interrupt_s->ADXL345_INT1_NVIC_Subpriority : 0x00;
		NVIC_Init(&nvic_init_s);
		
		// Force software interrupt once to enable the interrupt routine
		EXTI_GenerateSWInterrupt(adxl345_interrupt_s->ADXL345_INT1_EXTI_Line);
	}
	else if ((adxl345_interrupt_s->ADXL345_InterruptEnable & ADXL345_InterruptEnable_INT2) != ADXL345_FlagReset)
	{
		// Enable interrupt for INT2
		
		// Enable clock gating for GPIO
		RCC_AHB1PeriphClockCmd(adxl345_interrupt_s->ADXL345_INT2_CLK, ENABLE);
		// Enable clock gating for sysconfig
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
		
		GPIO_InitTypeDef gpio_init_s;
		gpio_init_s.GPIO_Mode = GPIO_Mode_IN;
		gpio_init_s.GPIO_OType = GPIO_OType_PP;
		gpio_init_s.GPIO_PuPd = GPIO_PuPd_DOWN;
		gpio_init_s.GPIO_Speed = GPIO_Speed_50MHz;
		gpio_init_s.GPIO_Pin = adxl345_interrupt_s->ADXL345_INT2_GPIO_Pin;
		GPIO_Init(adxl345_interrupt_s->ADXL345_INT2_Port, &gpio_init_s);
		
		// Configure EXTI line to GPIO Pin
		SYSCFG_EXTILineConfig(adxl345_interrupt_s->ADXL345_INT2_EXTI_PortSource, adxl345_interrupt_s->ADXL345_INT2_EXTI_PinSource);
		
		// Initialize EXTI
		EXTI_InitTypeDef exti_init_s;
		exti_init_s.EXTI_Line = adxl345_interrupt_s->ADXL345_INT2_EXTI_Line;
		exti_init_s.EXTI_LineCmd = ENABLE;
		exti_init_s.EXTI_Mode = EXTI_Mode_Interrupt;
		exti_init_s.EXTI_Trigger = EXTI_Trigger_Falling;
		EXTI_Init(&exti_init_s);
		
		// Initialize NVIC
		NVIC_InitTypeDef nvic_init_s;
		nvic_init_s.NVIC_IRQChannel = adxl345_interrupt_s->ADXL345_INT2_NVIC_IRQChannel;
		nvic_init_s.NVIC_IRQChannelCmd = ENABLE;
		nvic_init_s.NVIC_IRQChannelPreemptionPriority = adxl345_interrupt_s->ADXL345_INT2_NVIC_Priority_Cmd == ADXL345_INT2_NVIC_Priority_Cmd_ENABLE ?
																										adxl345_interrupt_s->ADXL345_INT2_NVIC_Priotity : 0x00;
		nvic_init_s.NVIC_IRQChannelSubPriority = adxl345_interrupt_s->ADXL345_INT2_NVIC_Priority_Cmd == ADXL345_INT2_NVIC_Priority_Cmd_ENABLE ?
																										adxl345_interrupt_s->ADXL345_INT2_NVIC_Subpriority : 0x00;
		NVIC_Init(&nvic_init_s);
		
		// Force software interrupt once to enable the interrupt routine
		EXTI_GenerateSWInterrupt(adxl345_interrupt_s->ADXL345_INT2_EXTI_Line);
	}
}

void ADXL345_ReadAcc(float* acc)
{
	// Expecting a length-3 array
	
	// Read data
	ADXL345_I2C_ReadRegMulti(REG_ADXL345_DATAX0, buffer, ADXL345_DATA_COUNT);
	
	// Get current rage
	uint8_t range_index = ADXL345_I2C_ReadReg(REG_ADXL345_DATA_FORMAT) & ADXL345_RangeBit_Mask;
	float range = ADXL345_Ranges[range_index];
	
	// Get full range
	uint16_t full_range = ADXL345_I2C_ReadReg(REG_ADXL345_DATA_FORMAT) & ADXL345_FullResBit_Mask == 0 ?
							ADXL345_Data_FullRange :
							ADXL345_Data_FullRanges[range_index];
	// Get the data for 3 axes
	int16_t x = (int16_t)(((uint16_t)buffer[ADXL345_DataX1_Index]) << 8) | buffer[ADXL345_DataX0_Index];
	int16_t y = (int16_t)(((uint16_t)buffer[ADXL345_DataY1_Index]) << 8) | buffer[ADXL345_DataY0_Index];
	int16_t z = (int16_t)(((uint16_t)buffer[ADXL345_DataZ1_Index]) << 8) | buffer[ADXL345_DataZ0_Index];
	
	// Update the real accelerometer reading
	acc[ADXL345_ACCX_Index] = (float)x / (float)full_range * range;
	acc[ADXL345_ACCY_Index] = (float)y / (float)full_range * range;
	acc[ADXL345_ACCZ_Index] = (float)z / (float)full_range * range;
}

void ADXL345_AccToTilt(float* acc, float* angles)
{
	angles[ADXL345_Pitch_Index] = atanf(acc[ADXL345_ACCX_Index] / 
																	sqrtf(acc[ADXL345_ACCY_Index] * acc[ADXL345_ACCY_Index] + acc[ADXL345_ACCZ_Index] * acc[ADXL345_ACCZ_Index]));
	angles[ADXL345_Roll_Index] = atanf(acc[ADXL345_ACCY_Index] / 
																	sqrtf(acc[ADXL345_ACCX_Index] * acc[ADXL345_ACCX_Index] + acc[ADXL345_ACCZ_Index] * acc[ADXL345_ACCZ_Index]));
}

void ADXL345_RadianToDegree(float* angles)
{
	angles[ADXL345_Pitch_Index] = (angles[ADXL345_Pitch_Index] * 180.0f) / M_PI;
	angles[ADXL345_Roll_Index] = (angles[ADXL345_Roll_Index] * 180.0f) / M_PI;
}