/*
 * SPI_cfg.h
 *
 * Created: 2/10/2020 4:18:10 PM
 *  Author: ahmed
 */ 

#ifndef __SPI_CFG_H__
#define __SPI_CFG_H__

/*SPI user configurations*/
#define SPI_INTERRUPT_ENABLE_CFG	(SPI_INT_DISABLE)
#define SPI_ENABLE_CFG				(SPI_ENABLE)
#define SPI_MODE_CFG				(SPI_SLAVE)
#define SPI_DOR_CFG					(SPI_MSB_FIRST)
#define SPI_SCK_MODE_CFG			(R_SAMPLE_R_SETUP_F)
#define SPI_PRESCALER_CFG			(SPI_PRE_16)

/*Configuration structure data*/
#define SPI_CFG_DATA				{SPI_INTERRUPT_ENABLE_CFG,\
									 SPI_ENABLE_CFG,\	
									 SPI_MODE_CFG,\
									 SPI_DOR_CFG,\
									 SPI_SCK_MODE_CFG,\
									 SPI_PRESCALER_CFG}


#endif /* SPI_CFG_H_ */