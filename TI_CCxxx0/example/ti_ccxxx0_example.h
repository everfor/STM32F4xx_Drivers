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
#ifndef TI_CCxxx0_EXAMPLE_H_
#define TI_CCxxx0_EXAMPLE_H_

#include "stm32f4xx.h"
#include "stm32f4xx_conf.h"

/* !! THESE ARE DUMMY VALUES */
#define VAL_TI_CCxxx0_IOCFG2 	0x00 		
#define VAL_TI_CCxxx0_IOCFG0 	0x06		// GDO0 pulls up at sync word and pulls down at end of packet

#define VAL_TI_CCxxx0_FIFOTHR 	0x00

#define VAL_TI_CCxxx0_PKTLEN 	0x00

#define VAL_TI_CCxxx0_PKTCTRL1 	0x00	
#define VAL_TI_CCxxx0_PKTCTRL0 	0x00	

#define VAL_TI_CCxxx0_ADDR 		0x00	

#define VAL_TI_CCxxx0_CHANNR 	0x00

#define VAL_TI_CCxxx0_FSCTRL1 	0x00	
#define VAL_TI_CCxxx0_FSCTRL0 	0x00	

#define VAL_TI_CCxxx0_FREQ2 	0x00	
#define VAL_TI_CCxxx0_FREQ1 	0x00	
#define VAL_TI_CCxxx0_FREQ0 	0x00	

#define VAL_TI_CCxxx0_MDMCFG4 	0x00
#define VAL_TI_CCxxx0_MDMCFG3 	0x00
#define VAL_TI_CCxxx0_MDMCFG2 	0x00	
#define VAL_TI_CCxxx0_MDMCFG1 	0x00	
#define VAL_TI_CCxxx0_MDMCFG0 	0x00	

#define VAL_TI_CCxxx0_DEVIATN 	0x00	


#define VAL_TI_CCxxx0_MCSM1 	0x00	
#define VAL_TI_CCxxx0_MCSM0 	0x00	

#define VAL_TI_CCxxx0_FOCCFG 	0x00	
#define VAL_TI_CCxxx0_BSCFG 	0x00	

#define VAL_TI_CCxxx0_AGCTRL2 	0x00	 
#define VAL_TI_CCxxx0_AGCTRL1 	0x00	
#define VAL_TI_CCxxx0_AGCTRL0 	0x00

#define VAL_TI_CCxxx0_FREND1 	0x00	 
#define VAL_TI_CCxxx0_FREND0 	0x00	

#define VAL_TI_CCxxx0_FSCAL3 	0x00	 
#define VAL_TI_CCxxx0_FSCAL2 	0x00	
#define VAL_TI_CCxxx0_FSCAL1 	0x00	 
#define VAL_TI_CCxxx0_FSCAL0 	0x00	

#define VAL_TI_CCxxx0_FSTEST 	0x00

#define VAL_TI_CCxxx0_TEST2 	0x00	
#define VAL_TI_CCxxx0_TEST1 	0x00	
#define VAL_TI_CCxxx0_TEST0 	0x00

/** Setup configs */
#define CONFIG_TI_CCxxx0_SPI						SPI4
#define CONFIG_TI_CCxxx0_SPI_CLK					RCC_APB2Periph_SPI4

#define CONFIG_TI_CCxxx0_SCK_Pin					GPIO_Pin_2
#define CONFIG_TI_CCxxx0_SCK_Port					GPIOE
#define CONFIG_TI_CCxxx0_SCK_CLK					RCC_AHB1Periph_GPIOE
#define CONFIG_TI_CCxxx0_SCK_Source					GPIO_PinSource2
#define CONFIG_TI_CCxxx0_SCK_AF						GPIO_AF_SPI4

#define CONFIG_TI_CCxxx0_MISO_Pin					GPIO_Pin_5
#define CONFIG_TI_CCxxx0_MISO_Port					GPIOE
#define CONFIG_TI_CCxxx0_MISO_CLK					RCC_AHB1Periph_GPIOE
#define CONFIG_TI_CCxxx0_MISO_Source				GPIO_PinSource5
#define CONFIG_TI_CCxxx0_MISO_AF					GPIO_AF_SPI4

#define CONFIG_TI_CCxxx0_MOSI_Pin					GPIO_Pin_6
#define CONFIG_TI_CCxxx0_MOSI_Port					GPIOE
#define CONFIG_TI_CCxxx0_MOSI_CLK					RCC_AHB1Periph_GPIOE
#define CONFIG_TI_CCxxx0_MOSI_Source				GPIO_PinSource6
#define CONFIG_TI_CCxxx0_MOSI_AF					GPIO_AF_SPI4

#define CONFIG_TI_CCxxx0_CSn_Pin					GPIO_Pin_13
#define CONFIG_TI_CCxxx0_CSn_Port					GPIOC
#define CONFIG_TI_CCxxx0_CSn_CLK					RCC_AHB1Periph_GPIOC

/** Rx Interrupt configs */
#define CONFIG_TI_CCxxx0_Rx_Pin						GPIO_Pin_3
#define CONFIG_TI_CCxxx0_Rx_Port					GPIOC
#define CONFIG_TI_CCxxx0_Rx_CLK						RCC_AHB1Periph_GPIOC
#define CONFIG_TI_CCxxx0_Rx_EXTI_Line				EXTI_Line3
#define CONFIG_TI_CCxxx0_Rx_EXTI_PinSource			EXTI_PinSource3
#define CONFIG_TI_CCxxx0_Rx_EXTI_PortSource			EXTI_PortSourceGPIOC
#define CONFIG_TI_CCxxx0_Rx_NVIC_Channel			EXTI3_IRQn

/** Tx GDO configs */
#define CONFIG_TI_CCxxx0_Tx_GDO_Port				GPIOC
#define CONFIG_TI_CCxxx0_Tx_GDO_CLK					RCC_AHB1Periph_GPIOC
#define CONFIG_TI_CCxxx0_Tx_GDO_Pin					GPIO_Pin_3

/* Initialize ccxxx0 chip */
void TI_CCxxx0_InitSetup(void);

/* Configure ccxxx0 by setting configuration registers */
void TI_CCxxx0_RegConfig(void);

/* Rx Setup for GDO Pin */
void TI_CCxxx0_RxInterruptSetup(void);

/* Tx Setup for GDO Pin */
void TI_CCxxx0_TxSetup(void);

#endif