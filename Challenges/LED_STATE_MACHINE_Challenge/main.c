/*
 * LED_STATE_MACHINE_Challenge.c
 *
 * Created: 1/18/2020 6:01:24 PM
 * Author : ahmed
 */ 

#include "std_types.h"
#include "led.h"
#include "softwareDelay.h"

/*Three LEDs interfaces with led module*/
#define GO_LED			LED_0
#define GET_READY_LED	LED_1
#define STOP_LED		LED_2

int main(void)
{
    Led_Init(GO_LED);
    Led_Init(GET_READY_LED);
    Led_Init(STOP_LED);
	
    while (1) 
    {
		Led_On(GO_LED);
		Led_Off(GET_READY_LED);
		Led_Off(STOP_LED);
		
		softwareDelayMs(1000);
		
		Led_Off(GO_LED);
		Led_Off(GET_READY_LED);
		Led_On(STOP_LED);

		softwareDelayMs(1000);

		Led_Off(GO_LED);
		Led_On(GET_READY_LED);
		Led_Off(STOP_LED);

		softwareDelayMs(1000);
    }
	return 0;
}

