/*
 * ultrasonic.c
 *
 * Created: 1/30/2020 12:51:33 PM
 *  Author: ahmed
 */ 

#include "softwareDelay.h"
#include "SwICU.h"
#include "ultrasonic.h"

/*User defined important macros*/
#define ULTRASONIC_MAX_RANGE			(275)
#define ULTRASONIC_MIN_RANGE			(2)

#define ULTRASONIC_TRIG_PULSE_DELAY_MS	(1)
#define ULTRASONIC_CONVERSION_CM_US		(58.0)

#define TIMER_TICK_TIME_US				(64)


void ultrasonic_init(void)
{
	/*Initializing SwICU*/
	SwICU_Init(SwICU_EdgeRising);
	
	/*Configure trig as output and echo as input*/    
	gpioPinDirection(ULTRASONIC_GPIO_PORT,ULTRASONIC_TRIG_PIN,OUTPUT);
	gpioPinDirection(ULTRASONIC_GPIO_PORT,ULTRASONIC_ECHO_PIN,INPUT);

	return;
}

uint32_t ultrasonic_readDistance(void)
{
	uint32_t au32_distance = 0;
	uint32_t au32_total_time = 0;
	uint8_t  au8_ICUread  = 0;
	
	/*Ultrasonic triggering operation*/
	gpioPinWrite(ULTRASONIC_GPIO_PORT,ULTRASONIC_TRIG_PIN,HIGH);
	softwareDelayMs(ULTRASONIC_TRIG_PULSE_DELAY_MS);
	gpioPinWrite(ULTRASONIC_GPIO_PORT,ULTRASONIC_TRIG_PIN,LOW);
	
	/*Reading timer ticks*/		
	SwICU_Read(&au8_ICUread);
	
	/*Total time of received pulse calculation*/
	au32_total_time = ((uint32_t)au8_ICUread * TIMER_TICK_TIME_US);
	
	/*Distance calculations*/
	au32_distance = au32_total_time / ULTRASONIC_CONVERSION_CM_US;
	
	/*Maximum distance validation*/
	if (au32_distance > ULTRASONIC_MAX_RANGE)
	{
		au32_distance = ULTRASONIC_MAX_RANGE;
	} 
	else
	{
		/*Do nothing*/
	}
	return au32_distance;
}