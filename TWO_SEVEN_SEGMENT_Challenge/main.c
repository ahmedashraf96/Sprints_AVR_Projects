/*
 * TWO_SEVEN_SEGMENT_Challenge.c
 *
 * Created: 1/19/2020 1:09:24 AM
 * Author : ahmed
 */ 
#include "std_types.h"
#include "sevenSeg.h"
#include "softwareDelay.h"

/*MS Segment and LS Segment*/
#define MS_SEGMENT		SEG_0
#define LS_SEGMENT		SEG_1

int main(void)
{
	uint8_t au8_ms_seg_counter = 0;
	uint8_t au8_ls_seg_counter = 0;
	
    sevenSegInit(MS_SEGMENT);
	sevenSegInit(LS_SEGMENT);
	sevenSegDisable(MS_SEGMENT);
	sevenSegDisable(LS_SEGMENT);
    while (1) 
    {
		for (au8_ls_seg_counter = 0 ; au8_ls_seg_counter < 10 ; au8_ls_seg_counter++)
		{
			/*Busy loop to achieve 1 second delay*/
			for (uint8_t i = 0 ; i < 20 ; i++)
			{
				sevenSegDisable(LS_SEGMENT);
				sevenSegEnable(MS_SEGMENT);
				sevenSegWrite(MS_SEGMENT,au8_ms_seg_counter);
				softwareDelayMs(20);
							
				sevenSegDisable(MS_SEGMENT);
				sevenSegEnable(LS_SEGMENT);
				sevenSegWrite(LS_SEGMENT,au8_ls_seg_counter);
				softwareDelayMs(20);
			}
		}
		au8_ms_seg_counter++;
		
		if (au8_ms_seg_counter == 10)
		{
			au8_ms_seg_counter = 0;
		} 
		else
		{
			/*Do nothing*/
		}
    }
	return 0;
}

