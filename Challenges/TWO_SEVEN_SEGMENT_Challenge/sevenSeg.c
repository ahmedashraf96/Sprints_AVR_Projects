#include "sevenSeg.h"

void sevenSegInit(En_SevenSegId_t a_segment_id)
{
	gpioPinDirection(SEG_BCD_GPIO,SEG_BCD_BITS,OUTPUT);
	gpioPinDirection(SEG_BCD_DP_GPIO,SEG_BCD_DP_BIT,OUTPUT);

	switch(a_segment_id)
	{
		case SEG_0:
			gpioPinDirection(SEG_EN1_GPIO,SEG_EN1_BIT,OUTPUT);
			break;

		case SEG_1:
			gpioPinDirection(SEG_EN2_GPIO,SEG_EN2_BIT,OUTPUT);
			break;			
	}
	
	return;
}

void sevenSegEnable(En_SevenSegId_t en_segment_id)
{
	switch(en_segment_id)
	{
		case SEG_0:
			gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,LOW);
			break;
			
		case SEG_1:
			gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,LOW);
			break;	
	}
}

void sevenSegDisable(En_SevenSegId_t en_segment_id)
{
	switch(en_segment_id)
	{
		case SEG_0:
		gpioPinWrite(SEG_EN1_GPIO,SEG_EN1_BIT,HIGH);
		break;
		
		case SEG_1:
		gpioPinWrite(SEG_EN2_GPIO,SEG_EN2_BIT,HIGH);
		break;
	}
	return;
}

void sevenSegWrite(En_SevenSegId_t en_segment_id, uint8_t u8_number)
{
	switch(en_segment_id)
	{
		case SEG_0:
			for (uint8_t i = 0 ; i < CONTROL_PINS_NUM ; i++)
			{
				if (GET_BIT(u8_number,i))
				{
					gpioPinWrite(SEG_BCD_GPIO,(SEG_BCD_BITA<<i),HIGH);
				}
				else
				{
					gpioPinWrite(SEG_BCD_GPIO,(SEG_BCD_BITA<<i),LOW);
				}
			}
			break;

		case SEG_1:
			for (uint8_t i = 0 ; i < CONTROL_PINS_NUM ; i++)
			{
				if (GET_BIT(u8_number,i))
				{
					gpioPinWrite(SEG_BCD_GPIO,(SEG_BCD_BITA<<i),HIGH);
				}
				else
				{
					gpioPinWrite(SEG_BCD_GPIO,(SEG_BCD_BITA<<i),LOW);
				}
			}
			break;	
	}
	return;
}