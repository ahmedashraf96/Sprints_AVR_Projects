/*
 * ULTRASONIC_challenge.c
 *
 * Created: 1/29/2020 5:11:32 PM
 * Author : ahmed
 */ 

#include "led.h"
#include "ultrasonic.h"

#define HIGH_VAL				(1)

#define LED_0_BIT_MAPPING		(0)
#define LED_1_BIT_MAPPING		(1)
#define LED_2_BIT_MAPPING		(2)
#define LED_3_BIT_MAPPING		(3)

#define ULTRASONIC_MAX_DISTANCE	(15)

uint32_t gu32_distance = 0;

int main(void)
{
	
	Led_Init(LED_0);
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	
	ultrasonic_init();
	
    while (1) 
    {	
		gu32_distance = ultrasonic_readDistance();
		
		if(gu32_distance > ULTRASONIC_MAX_DISTANCE)
		{
			gu32_distance = ULTRASONIC_MAX_DISTANCE;
		}
		else
		{
			
		}
		
		if (GET_BIT(gu32_distance,LED_0_BIT_MAPPING) == HIGH_VAL)
		{
			Led_On(LED_0);
		}
		else
		{
			Led_Off(LED_0);
		}
		
		if (GET_BIT(gu32_distance,LED_1_BIT_MAPPING) == HIGH_VAL)
		{
			Led_On(LED_1);
		}
		else
		{
			Led_Off(LED_1);
		}

		if (GET_BIT(gu32_distance,LED_2_BIT_MAPPING) == HIGH_VAL)
		{
			Led_On(LED_2);
		}
		else
		{
			Led_Off(LED_2);
		}

		if (GET_BIT(gu32_distance,LED_3_BIT_MAPPING) == HIGH_VAL)
		{
			Led_On(LED_3);
		}
		else
		{
			Led_Off(LED_3);
		}
    }
	
	return 0;
}

