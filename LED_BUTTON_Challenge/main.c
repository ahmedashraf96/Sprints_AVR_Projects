/*
 * LED_BUTTON_Challenge.c
 *
 * Created: 1/18/2020 5:21:27 PM
 * Author : ahmed
 */ 

#include "std_types.h"
#include "led.h"
#include "pushButton.h"

int main(void)
{	
	pushButtonInit(BTN_0);
	Led_Init(LED_0);
    while (1) 
    {
		if (pushButtonGetStatus(BTN_0) == Pressed)
		{
			Led_On(LED_0);
			for (uint8_t i = 0 ; i < 100 ; i++)
			{
				if (pushButtonGetStatus(BTN_0) == Pressed)
				{
					i = 0;
				}
				else
				{
					/*Do nothing*/
				}
				softwareDelayMs(10);
			}
		}
		else
		{
			Led_Off(LED_0);
		}
    }
	return 0;
}

