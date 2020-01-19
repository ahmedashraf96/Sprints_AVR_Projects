#include "gpio.h"

void gpioPortDirection(uint8_t u8_port, uint8_t u8_direction)
{
	switch(u8_port)
	{
		case GPIOA:
			PORTA_DIR = u8_direction;
			break;
			
		case GPIOB:
			PORTB_DIR = u8_direction;
			break;

		case GPIOC:
			PORTC_DIR = u8_direction;
			break;

		case GPIOD:
			PORTD_DIR = u8_direction;
			break;
		
		default: break;	
	}
	return;
}

void gpioPortWrite(uint8_t u8_port, uint8_t u8_value)
{
	switch(u8_port)
	{
		case GPIOA:
			PORTA_DATA = u8_value;
			break;
		
		case GPIOB:
			PORTB_DATA = u8_value;
			break;

		case GPIOC:
			PORTC_DATA = u8_value;
			break;

		case GPIOD:
			PORTD_DATA = u8_value;
			break;
		
		default: break;
	}
	return;
}

void gpioPortToggle(uint8_t u8_port)
{
	switch(u8_port)
	{
		case GPIOA:
			PORTA_DATA ^= HIGH;
			break;
		
		case GPIOB:
			PORTB_DATA ^= HIGH;
			break;

		case GPIOC:
			PORTC_DATA ^= HIGH;
			break;

		case GPIOD:
			PORTD_DATA ^= HIGH;
			break;
		
		default: break;
	}
	return;
}

uint8_t gpioPortRead(uint8_t u8_port)
{
	uint8_t u8_port_value = 0;
	
	switch(u8_port)
	{
		case GPIOA:
			u8_port_value = PORTA_PIN;
			break;
		
		case GPIOB:
			u8_port_value = PORTB_PIN;
			break;
		
		case GPIOC:
			u8_port_value = PORTC_PIN;
			break;
		
		case GPIOD:
			u8_port_value = PORTD_PIN;
			break;
		
		default: break;						
	}
	return u8_port_value; 
}

void gpioPinDirection(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_direction)
{
	switch(u8_port)
	{
		case GPIOA:
			switch(u8_direction)
			{
				case OUTPUT:
					PORTA_DIR |= u8_pins;
					break;
				
				case INPUT:
					PORTA_DIR &= ~(u8_pins);
					break;	 
			}
			break;

		case GPIOB:
			switch(u8_direction)
			{
				case OUTPUT:
					PORTB_DIR |= u8_pins;
					break;
			
				case INPUT:
					PORTB_DIR &= ~(u8_pins);
					break;
			}
		break;

		case GPIOC:
			switch(u8_direction)
			{
				case OUTPUT:
					PORTC_DIR |= u8_pins;
					break;
			
				case INPUT:
					PORTC_DIR &= ~(u8_pins);
					break;
			}
		break;

		case GPIOD:
		switch(u8_direction)
		{
			case OUTPUT:
				PORTD_DIR |= u8_pins;
				break;
			
			case INPUT:
				PORTD_DIR &= ~(u8_pins);
				break;
		}
		break;			
	}
	return;
}

void gpioPinWrite(uint8_t u8_port, uint8_t u8_pins, uint8_t u8_value)
{
	switch(u8_port)
	{
		case GPIOA:
			switch(u8_value)
			{
				case HIGH:
					PORTA_DATA |= u8_pins;
					break;
				
				case LOW:
					PORTA_DATA &= ~(u8_pins);
					break;	
			}
			break;

		case GPIOB:
			switch(u8_value)
			{
				case HIGH:
					PORTB_DATA |= u8_pins;
					break;
			
				case LOW:
					PORTB_DATA &= ~(u8_pins);
					break;
			}
			break;
		
		case GPIOC:
			switch(u8_value)
			{
				case HIGH:
					PORTC_DATA |= u8_pins;
					break;
			
				case LOW:
					PORTC_DATA &= ~(u8_pins);
					break;
			}
			break;
		
		case GPIOD:
			switch(u8_value)
			{
				case HIGH:
					PORTD_DATA |= u8_pins;
					break;
			
				case LOW:
					PORTD_DATA &= ~(u8_pins);
					break;
			}
			break;
	}
}

void gpioPinToggle(uint8_t u8_port, uint8_t u8_pins)
{
	switch(u8_port)
	{
		case GPIOA:
			PORTA_DATA ^= u8_pins;
			break;

		case GPIOB:
			PORTB_DATA ^= u8_pins;
			break;
		
		case GPIOC:
			PORTC_DATA ^= u8_pins;
			break;
		
		case GPIOD:
			PORTD_DATA ^= u8_pins;
			break;		
	}
}

uint8_t gpioPinRead(uint8_t u8_port, uint8_t u8_pin)
{
	uint8_t u8_pin_value = 0;
	
	switch(u8_port)
	{
		case GPIOA:
			u8_pin_value = PORTA_PIN & u8_pin;
			break;

		case GPIOB:
			u8_pin_value = PORTB_PIN & u8_pin;
			break;

		case GPIOC:
			u8_pin_value = PORTC_PIN & u8_pin;
			break;

		case GPIOD:
			u8_pin_value = PORTD_PIN & u8_pin;
			break;
	}
	
	if (u8_pin_value)
	{
		u8_pin_value = HIGH;
	} 
	else
	{
		u8_pin_value = LOW;
	}
	
	return u8_pin_value;
}