/*
 * USART.c
 *
 * Created: 2/10/2020 1:04:41 PM
 *  Author: ahmed
 */ 
#include "std_types.h"
#include "registers.h"
#include "USART.h"

#define UDRE_BIT	(5)
#define TXC_BIT		(6)
#define RXC_BIT		(5)


void USART_init(ST_usart_cfg_t *usart_cfg)
{
	/*Initializing USART registers with zeros*/
	UCSRA = 0;
	UCSRB = 0;
	UCSRC = 0;
	
	/*Setting Tx as output pin and Rx as input pin*/
	SET_BIT(TX_GPIO_REG,TX_GPIO_PIN);
	CLEAR_BIT(RX_GPIO_REG,RX_GPIO_PIN);
	
	/*Configuring interrupts, Rx and Tx enable options */
	UCSRB = (usart_cfg -> usart_interrupts_enable | usart_cfg -> rx_tx_enable);
	
	/* Configuring following options:
	 * USART mode, Word size, parity type and Stop bits
	 */
	UCSRC = (UCSRC_ENABLE | usart_cfg -> usart_mode | usart_cfg -> word_size | usart_cfg -> parity_type | usart_cfg -> stop_bits);
	
	/*Validating baud rate value is within 8-bit resolution or not*/
	if (usart_cfg -> usart_baud_rate <= UBRRL_SIZE)
	{
		/*If it's lower than 256 then we will access UBRRL only*/
		UBRRL = (uint8_t)usart_cfg -> usart_baud_rate;
	} 
	else
	{
		/*If it's bigger than 256 then we will use UBRRH besides UBRRL*/
		UBRRL = (uint8_t)(usart_cfg -> usart_baud_rate);
		UBRRH = (uint8_t)((UBRRH_ENABLE) | (usart_cfg -> usart_baud_rate >> UBRRH_SHIFTING));
	}
	
	return;	
}

void USART_sendByte(uint8_t au8_data)
{
	/*validating that data register UDR is empty or not*/
	if(GET_BIT(UCSRA , UDRE_BIT))
	{
		/*Passing data to UDR*/
		UDR = au8_data;
		
		/*Waiting the transmission to be completed*/
		while(!GET_BIT(UCSRA , TXC_BIT));
		
		/*Clearing Tx complete flag*/
		SET_BIT(UCSRA , TXC_BIT);
	}
	else
	{
		/*Do nothing*/
	}
	return;
}

uint8_t USART_recvByte(void)
{
	/*Variable holds the received data*/
	uint8_t au8_data = 0;
	
	/*Validating if there's data in Rx buffer or not*/
	if(GET_BIT(UCSRA , RXC_BIT))
	{
		/*Passing UDR register to the receiving variable*/
		au8_data = UDR;
	}
	else
	{
		/*Do nothing*/
	}
	return au8_data;
}