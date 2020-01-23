/*
 * LED_STATE_BUTTON_Challenge.c
 *
 * Created: 1/23/2020 9:38:04 PM
 * Author : ahmed
 */ 

#include "timers.h"
#include "led.h"
#include "pushButton.h"

#define RED_LED			LED_0
#define YELLOW_LED		LED_2
#define GREEN_LED		LED_3


#define GREEN_LED_SELECT	(0)
#define RED_LED_SELECT		(1)
#define YELLOW_LED_SELECT	(2)

#define looping_delay_1sec	(10)
int main(void)
{
	
	uint8_t au8_looping_var = 0;
	uint8_t au8_led_select_var = 0;
	
	timer0Init(T0_COMP_MODE,T0_OC0_DIS,T0_PRESCALER_64,0,0,T0_POLLING);
	
	Led_Init(RED_LED);
	Led_Init(YELLOW_LED);
	Led_Init(GREEN_LED);
	
	pushButtonInit(BTN_0);
    
	while (1) 
    {
		//loop terminates after 1 second
		for (au8_looping_var = 0; au8_looping_var < looping_delay_1sec ; au8_looping_var++)
		{
			if (pushButtonGetStatus(BTN_0) == Pressed)
			{
				Led_On(RED_LED);
				Led_Off(YELLOW_LED);
				Led_Off(GREEN_LED);
						
				while(pushButtonGetStatus(BTN_0) == Pressed);
				
				timer0DelayMs(1000);
				
				au8_looping_var = 0;						
			}
			else
			{
				switch(au8_led_select_var)
				{
					case GREEN_LED_SELECT:
						Led_On(GREEN_LED);
						Led_Off(RED_LED);
						Led_Off(YELLOW_LED);
						break;
						
					case RED_LED_SELECT:	
						Led_Off(GREEN_LED);
						Led_On(RED_LED);
						Led_Off(YELLOW_LED);
						break;
					
					case YELLOW_LED_SELECT:
						Led_Off(GREEN_LED);
						Led_Off(RED_LED);
						Led_On(YELLOW_LED);
						break;
						
					default: 
						au8_led_select_var = 0;
						break;	
				}
			}
			timer0DelayMs(10);
		}
		au8_led_select_var++;
    }
	
	return 0;
}