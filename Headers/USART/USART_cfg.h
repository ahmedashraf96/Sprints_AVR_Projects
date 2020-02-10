/*
 * USART_cfg.h
 *
 * Created: 2/10/2020 2:56:50 PM
 *  Author: ahmed
 */ 

#ifndef __USART_CFG_H__
#define __USART_CFG_H__

/*USART user configurations*/
#define USART_MODE_CFG				(UART_MODE)
#define USART_WORD_SIZE_CFG			(DATA_8_BITS)
#define USART_RX_TX_ENABLE_CFG		(TX_ENABLE | RX_ENABLE)
#define USART_INTS_ENABLE_CFG		(TX_INT_DISABLE | RX_INT_DISABLE | UDRE_INT_DISABLE)
#define USART_PARITY_CFG			(PARITY_DISABLE)
#define USART_STOP_CFG				(ONE_STOP_BIT)
#define USART_BAUD_RATE_CFG			(BAUD_9600)

/*Configuration structure data*/
#define USART_CFG_DATA					{USART_MODE_CFG,\
									 USART_WORD_SIZE_CFG,\
									 USART_RX_TX_ENABLE_CFG,\
									 USART_INTS_ENABLE_CFG,\
									 USART_PARITY_CFG,\
									 USART_STOP_CFG,\
									 USART_BAUD_RATE_CFG}


#endif									 