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
#ifndef ADXL345_H_
#define ADXL345_H_

#include "adxl345_general.h"
#include "adxl345_i2c.h"

#define ADXL345_DATA_COUNT						6

#define ADXL345_ACCX_Index						0
#define ADXL345_ACCY_Index						1
#define ADXL345_ACCZ_Index						2

#define ADXL345_Pitch_Index						0
#define ADXL345_Roll_Index						1

/* Initialize Accelerometer Chip */
void ADXL345_Init(ADXL345_InitTypeDef* adxl345_init_s);

/* Interrupt Configurations */
void ADXL345_InterruptConfig(ADXL345_InterruptTypeDef* adxl345_interrupt_s);

/* Read Accelerometer raw data */
void ADXL345_ReadAcc(float* acc);

/* Convert acceleration to tilt angles */
void ADXL345_AccToTilt(float* acc, float* angles);

/* Convert radians to degrees */
void ADXL345_RadianToDegree(float* angles);

#endif