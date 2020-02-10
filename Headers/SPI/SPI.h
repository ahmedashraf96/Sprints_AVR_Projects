/*
 * SPI.h
 *
 * Created: 2/10/2020 4:17:38 PM
 *  Author: ahmed
 */ 


#ifndef __SPI_H__
#define __SPI_H__

/*SPI pins configurations*/
#define SPI_MOSI_REG		(PORTB_DIR)
#define SPI_MISO_REG		(PORTB_DIR)
#define SPI_SCK_REG			(PORTB_DIR)
#define SPI_SS_REG			(PORTB_DIR)
#define SPI_SS_PIN			(4)
#define SPI_MOSI_PIN		(5)
#define SPI_MISO_PIN		(6)
#define SPI_SCK_PIN			(7)
	
/*SPI interrupt enable - disable*/
#define SPI_INT_ENABLE		(0x80)
#define SPI_INT_DISABLE		(0x00)

/*SPI enable - disable*/
#define SPI_ENABLE			(0x40)
#define SPI_DISABLE			(0x00)

/*Data order modes*/
#define SPI_LSB_FIRST		(0x20)
#define SPI_MSB_FIRST		(0x00)

/*SPI modes*/
#define SPI_MASTER			(0x10)
#define SPI_SLAVE			(0x00) 

/*SPI clock polarity and phase*/
#define R_SAMPLE_R_SETUP_F	(0x00) /*Mode 1*/
#define R_SETUP_R_SAMPLE_F	(0x04) /*Mode 2*/
#define F_SAMPLE_F_SETUP_R	(0x08) /*Mode 3*/
#define F_SETUP_F_SAMPLE_R	(0x0C) /*Mode 4*/

/*SPI clock prescalers*/
#define SPI_PRE_4			(0x00)
#define SPI_PRE_16			(0x01)
#define SPI_PRE_64			(0x02)
#define SPI_PRE_128			(0x03)

typedef struct
{
	uint8_t spi_interrupt_enable;
	uint8_t spi_enable;
	uint8_t spi_mode;
	uint8_t spi_dataOrder;
	uint8_t spi_sck_mode;
	uint8_t spi_prescaler;
}ST_spi_cfg_t;

/************************************************************************/
/*                          SPI Functions                               */
/************************************************************************/

/*
 * Description : Initialization of SPI module
 * @param configuration structure
 */
void SPI_init(ST_spi_cfg_t *spi_cfg);

/*
 * Description : Starting of SPI transmission
 */
void SPI_start(void);

/*
 * Description : Stopping of SPI transmission
 */
void SPI_stop(void);

/*
 * Description : Sending and receiving one byte function
 * @param data to b sent
 * @ret data returned
 */
uint8_t SPI_sendRecvByte(uint8_t au8_data);

#endif /* SPI_H_ */