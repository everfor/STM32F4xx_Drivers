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
#include "ti_ccxxx0_example.h"

void TI_CCxxx0_InitSetup(void)
{
	TI_CCxxx0_InitTypeDef TI_CCxxx0_init_s;
	
	TI_CCxxx0_init_s.TI_CCxxx0_SPI = CONFIG_TI_CCxxx0_SPI;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_CLK = CONFIG_TI_CCxxx0_SPI_CLK;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_Periph = TI_CCxxx0_SPI_Periph_APB2;
	
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_CSn_GPIO_CLK = CONFIG_TI_CCxxx0_CSn_CLK;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_CSn_GPIO_Pin = CONFIG_TI_CCxxx0_CSn_Pin;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_CSn_GPIO_Port = CONFIG_TI_CCxxx0_CSn_Port;
	
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MISO_AF = CONFIG_TI_CCxxx0_MISO_AF;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MISO_GPIO_CLK = CONFIG_TI_CCxxx0_MISO_CLK;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MISO_GPIO_Pin = CONFIG_TI_CCxxx0_MISO_Pin;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MISO_GPIO_PinSource = CONFIG_TI_CCxxx0_MISO_Source;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MISO_GPIO_Port = CONFIG_TI_CCxxx0_MISO_Port;
	
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MOSI_AF = CONFIG_TI_CCxxx0_MOSI_AF;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MOSI_GPIO_CLK = CONFIG_TI_CCxxx0_MOSI_CLK;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MOSI_GPIO_Pin = CONFIG_TI_CCxxx0_MOSI_Pin;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MOSI_GPIO_PinSource = CONFIG_TI_CCxxx0_MOSI_Source;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_MOSI_GPIO_Port = CONFIG_TI_CCxxx0_MOSI_Port;
	
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_SCK_AF = CONFIG_TI_CCxxx0_SCK_AF;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_SCK_GPIO_CLK = CONFIG_TI_CCxxx0_SCK_CLK;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_SCK_GPIO_Pin = CONFIG_TI_CCxxx0_SCK_Pin;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_SCK_GPIO_PinSource = CONFIG_TI_CCxxx0_SCK_Source;
	TI_CCxxx0_init_s.TI_CCxxx0_SPI_SCK_GPIO_Port = CONFIG_TI_CCxxx0_SCK_Port;
	
	TI_CCxxx0_Init(&TI_CCxxx0_init_s);
}

void TI_CCxxx0_RegConfig(void)
{
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_IOCFG2, VAL_TI_CCxxx0_IOCFG2);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_IOCFG0, VAL_TI_CCxxx0_IOCFG0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FIFOTHR, VAL_TI_CCxxx0_FIFOTHR);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_PKTLEN, VAL_TI_CCxxx0_PKTLEN);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_PKTCTRL1, VAL_TI_CCxxx0_PKTCTRL1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_PKTCTRL0, VAL_TI_CCxxx0_PKTCTRL0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_ADDR, VAL_TI_CCxxx0_ADDR);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_CHANNR, VAL_TI_CCxxx0_CHANNR);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FSCTRL1, VAL_TI_CCxxx0_FSCTRL1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FSCTRL0, VAL_TI_CCxxx0_FSCTRL0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FREQ2, VAL_TI_CCxxx0_FREQ2);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FREQ1, VAL_TI_CCxxx0_FREQ1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FREQ0, VAL_TI_CCxxx0_FREQ0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_MDMCFG4, VAL_TI_CCxxx0_MDMCFG4);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_MDMCFG3, VAL_TI_CCxxx0_MDMCFG3);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_MDMCFG2, VAL_TI_CCxxx0_MDMCFG2);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_MDMCFG1, VAL_TI_CCxxx0_MDMCFG1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_MDMCFG0, VAL_TI_CCxxx0_MDMCFG0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_DEVIATN, VAL_TI_CCxxx0_DEVIATN);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_MCSM1, VAL_TI_CCxxx0_MCSM1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_MCSM0, VAL_TI_CCxxx0_MCSM0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FOCCFG, VAL_TI_CCxxx0_FOCCFG);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_BSCFG, VAL_TI_CCxxx0_BSCFG);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_AGCTRL2, VAL_TI_CCxxx0_AGCTRL2);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_AGCTRL1, VAL_TI_CCxxx0_AGCTRL1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_AGCTRL0, VAL_TI_CCxxx0_AGCTRL0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FREND1, VAL_TI_CCxxx0_FREND1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FREND0, VAL_TI_CCxxx0_FREND0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FSCAL3, VAL_TI_CCxxx0_FSCAL3);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FSCAL2, VAL_TI_CCxxx0_FSCAL2);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FSCAL1, VAL_TI_CCxxx0_FSCAL1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FSCAL0, VAL_TI_CCxxx0_FSCAL0);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_FSTEST, VAL_TI_CCxxx0_FSTEST);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_TEST2, VAL_TI_CCxxx0_TEST2);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_TEST1, VAL_TI_CCxxx0_TEST1);
	TI_CCxxx0_SPI_WriteReg(REG_TI_CCxxx0_TEST0, VAL_TI_CCxxx0_TEST0);
	
	TI_CCxxx0_SPI_Strobe(REG_TI_CCxxx0_SFRX);
	TI_CCxxx0_SPI_Strobe(REG_TI_CCxxx0_SFTX);
}

void TI_CCxxx0_RxInterruptSetup(void)
{
	TI_CCxxx0_RxInterruptTypeDef TI_CCxxx0_rx_s;
	
	TI_CCxxx0_rx_s.TI_CCxxx0_RxInterrupt_GPIO_CLK = CONFIG_TI_CCxxx0_Rx_CLK;
	TI_CCxxx0_rx_s.TI_CCxxx0_RxInterrupt_GPIO_Pin = CONFIG_TI_CCxxx0_Rx_Pin;
	TI_CCxxx0_rx_s.TI_CCxxx0_RxInterrupt_GPIO_Port = CONFIG_TI_CCxxx0_Rx_Port;
	TI_CCxxx0_rx_s.TI_CCxxx0_RxInterrupt_EXTI_Line = CONFIG_TI_CCxxx0_Rx_EXTI_Line;
	TI_CCxxx0_rx_s.TI_CCxxx0_RxInterrupt_EXTI_PinSource = CONFIG_TI_CCxxx0_Rx_EXTI_PinSource;
	TI_CCxxx0_rx_s.TI_CCxxx0_RxInterrupt_EXTI_PortSource = CONFIG_TI_CCxxx0_Rx_EXTI_PortSource;
	TI_CCxxx0_rx_s.TI_CCxxx0_RxInterrupt_NVIC_IRQChannel = CONFIG_TI_CCxxx0_Rx_NVIC_Channel;
	TI_CCxxx0_rx_s.TI_CCxxx0_RxInterrupt_NVIC_Priority_Cmd = TI_CCxxx0_RxInterrupt_NVIC_Priority_DISABLE;
	
	TI_CCxxx0_RxInterruptConfig(&TI_CCxxx0_rx_s);
	
	TI_CCxxx0_SPI_Strobe(REG_TI_CCxxx0_SRX);
}

void TI_CCxxx0_TxSetup(void)
{
	TI_CCxxx0_TxGDOTypeDef TI_CCxxx0_tx_s;
	
	TI_CCxxx0_tx_s.TI_CCxxx0_TxGDO_GPIO_CLK = CONFIG_TI_CCxxx0_Tx_GDO_CLK;
	TI_CCxxx0_tx_s.TI_CCxxx0_TxGDO_GPIO_Pin = CONFIG_TI_CCxxx0_Tx_GDO_Pin;
	TI_CCxxx0_tx_s.TI_CCxxx0_TxGDO_GPIO_Port = CONFIG_TI_CCxxx0_Tx_GDO_Port;
	
	TI_CCxxx0_TxGDOConfig(&TI_CCxxx0_tx_s);
}