#include "pushButton.h"

#define DEBOUNCING_TIME	(50)

void pushButtonInit(En_buttonId_t en_button_id)
{
	timer0Init(T0_COMP_MODE,T0_OC0_DIS,T0_PRESCALER_8,0,0,T0_POLLING);
	
	switch(en_button_id)
	{
		case BTN_0:
			gpioPinDirection(BTN_0_GPIO,BTN_0_BIT,INPUT);
//			gpioPinWrite(BTN_0_GPIO,BTN_0_BIT,HIGH); //Pull up feature activation
			break;

		case BTN_1:
			gpioPinDirection(BTN_1_GPIO,BTN_1_BIT,INPUT);
//			gpioPinWrite(BTN_1_GPIO,BTN_1_BIT,HIGH); //Pull up feature activation
			break;

		case BTN_2:
			gpioPinDirection(BTN_2_GPIO,BTN_2_BIT,INPUT);
//			gpioPinWrite(BTN_2_GPIO,BTN_2_BIT,HIGH); //Pull up feature activation
			break;

		case BTN_3:
			gpioPinDirection(BTN_3_GPIO,BTN_3_BIT,INPUT);
//			gpioPinWrite(BTN_3_GPIO,BTN_3_BIT,HIGH); //Pull up feature activation
			break;
	}
	return;
}

En_buttonStatus_t pushButtonGetStatus(En_buttonId_t en_button_id)
{
	//If it's equal to zero then button is pressed otherwise it's released
	uint8_t u8_btn_val = 0;
	
	//Carry the return status for the button
	En_buttonStatus_t en_button_status = 0;
	
	switch(en_button_id)
	{
		case BTN_0:
			u8_btn_val = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
			timer0DelayMs(DEBOUNCING_TIME);
			u8_btn_val = gpioPinRead(BTN_0_GPIO,BTN_0_BIT);
			
			if (u8_btn_val)
			{
				en_button_status = Pressed;
			}
			else
			{
				en_button_status = Released;
			}												
			break;

		case BTN_1:
			u8_btn_val = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
			timer0DelayMs(DEBOUNCING_TIME);
			u8_btn_val = gpioPinRead(BTN_1_GPIO,BTN_1_BIT);
			
			if (u8_btn_val)
			{
				en_button_status = Pressed;
			}
			else
			{
				en_button_status = Released;
			}
			break;

		case BTN_2:
			u8_btn_val = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
			timer0DelayMs(DEBOUNCING_TIME);
			u8_btn_val = gpioPinRead(BTN_2_GPIO,BTN_2_BIT);
			
			if (u8_btn_val)
			{
				en_button_status = Pressed;
			}
			else
			{
				en_button_status = Released;
			}
			break;

		case BTN_3:
			u8_btn_val = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
			timer0DelayMs(DEBOUNCING_TIME);
			u8_btn_val = gpioPinRead(BTN_3_GPIO,BTN_3_BIT);
			
			if (u8_btn_val)
			{
				en_button_status = Pressed;
			}
			else
			{
				en_button_status = Released;
			}
			break;
	}	
	return en_button_status;
}