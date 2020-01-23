
#include "softwareDelay.h"

void softwareDelayMs(uint32_t u32_delay_in_ms)
{
	while(u32_delay_in_ms > 0)
	{
		for (uint16_t i = 0 ; i < 2000 ; i++);
		u32_delay_in_ms--;
	}
	return;
}