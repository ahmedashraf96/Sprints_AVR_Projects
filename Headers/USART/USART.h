/*
 * USART.h
 *
 * Created: 2/10/2020 1:05:02 PM
 *  Author: ahmed
 */ 


#ifndef __USART_H__
#define __USART_H__

/*GPIO interfaces*/
#define TX_GPIO_REG			(PORTD_DIR)
#define TX_GPIO_PIN			(1)
#define RX_GPIO_REG			(PORTD_DIR)
#define RX_GPIO_PIN			(0)

/*Enable configurations*/
#define UCSRC_ENABLE	(0x80)
#define UBRRH_ENABLE	(0x00)
#define UBRRH_SHIFTING	(8)
#define UBRRL_SIZE		(255)

/*
 *USART Modes
 */

/*Rx config*/
#define RX_ENABLE		 (0x10)
#define RX_DISABLE		 (0x00)
#define RX_INT_ENABLE    (0x80)
#define RX_INT_DISABLE   (0x00)

/*Tx config*/
#define TX_ENABLE		 (0x08)
#define TX_DISABLE		 (0x00)
#define TX_INT_ENABLE    (0x40)
#define TX_INT_DISABLE   (0x00)

/*UDR config*/
#define UDRE_INT_ENABLE	 (0x20)
#define UDRE_INT_DISABLE (0x00)

/*USART modes*/
#define UART_MODE		 (0x00)
#define USRT_MODE		 (0x40)

/*Parity modes*/
#define PARITY_DISABLE	 (0x00)
#define EVEN_PARITY		 (0x20)
#define ODD_PARITY		 (0x03)

/*Stop bits config*/
#define ONE_STOP_BIT	 (0x00)
#define TWO_STOP_BITS	 (0x80)

/*Data size config*/
#define DATA_5_BITS		 (0x00)
#define DATA_6_BITS		 (0x02)
#define DATA_7_BITS		 (0x04)
#define DATA_8_BITS		 (0x06)

/*USART baud rate [16 MHz]*/
#define BAUD_4800		 (207)
#define BAUD_9600		 (103)
#define BAUD_19200		 (51)
#define BAUD_115200		 (8)


/*USART configuration data type*/
typedef struct 
{
	uint8_t  usart_mode;
	uint8_t  word_size;
	uint8_t  rx_tx_enable;
	uint8_t  usart_interrupts_enable;
	uint8_t  parity_type;
	uint8_t  stop_bits;
	uint16_t usart_baud_rate;
}ST_usart_cfg_t;

/************************************************************************/
/*                          USART Functions                             */
/************************************************************************/

/*
 * Description : Initializing USART registers with specific values.
 * @param usart configuration structure
*/
void USART_init(ST_usart_cfg_t *usart_cfg);

/*
 * Description : Sends byte of data over usart.
 * @param data to be sent
*/
void USART_sendByte(uint8_t au8_data);

/*
 * Description : Receives byte of data over usart.
 * @ret received byte
*/
uint8_t USART_recvByte(void);

#endif /* USART_H_ */