/*
 * SPI.c
 *
 * Created: 2/10/2020 4:17:25 PM
 *  Author: ahmed
 */ 
#include "std_types.h"
#include "registers.h"
#include "SPI.h"

#define SPIF_BIT	(7)

void SPI_init(ST_spi_cfg_t *spi_cfg)
{
	SPCR = 0;
	SPCR = (spi_cfg -> spi_interrupt_enable) | (spi_cfg -> spi_enable) | (spi_cfg -> spi_dataOrder) | (spi_cfg -> spi_mode) | (spi_cfg -> spi_sck_mode) | (spi_cfg -> spi_prescaler);
	
	if((spi_cfg -> spi_mode) == SPI_MASTER)
	{
		SET_BIT(SPI_MOSI_REG,SPI_MOSI_PIN);
		CLEAR_BIT(SPI_MISO_REG,SPI_MISO_PIN);
		SET_BIT(SPI_SCK_REG,SPI_SCK_PIN);
		SET_BIT(SPI_SS_REG,SPI_SS_PIN);	
	}
	else
	{
		CLEAR_BIT(SPI_MOSI_REG,SPI_MOSI_PIN);
		SET_BIT(SPI_MISO_REG,SPI_MISO_PIN);
		CLEAR_BIT(SPI_SCK_REG,SPI_SCK_PIN);
		CLEAR_BIT(SPI_SS_REG,SPI_SS_PIN);		
	}
	return;
}

void SPI_start(void)
{
	CLEAR_BIT(SPI_SS_REG,SPI_SS_PIN);
	return;
}

void SPI_stop(void)
{
	SET_BIT(SPI_SS_REG,SPI_SS_PIN);
	return;
}

uint8_t SPI_sendRecvByte(uint8_t au8_data)
{
	SPDR = au8_data;
	while(!GET_BIT(SPSR,SPIF_BIT));
	return SPDR;
}