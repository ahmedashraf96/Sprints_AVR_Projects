/*
 * CAR_ULTRASONIC_Challenge.c
 *
 * Created: 1/30/2020 11:38:54 PM
 * Author : ahmed
 */ 

#include "dcMotor.h"
#include "ultrasonic.h"
#include "softwareDelay.h"

#define MOTOR_MAXIMUM_SPEED  (255)
#define MINIMUM_DISTANCE 	 (5)
#define ACTION_DELAY		 (2000)

uint32_t gu32_distance = 0;

int main(void)
{
	ultrasonic_init();
	MotorDC_Init(MOT_1);
	MotorDC_Init(MOT_2);	
		
	MotorDC_Speed_HwPWM(MOTOR_MAXIMUM_SPEED);
	while(1)
	{
		/*Reading the distance*/
		gu32_distance = ultrasonic_readDistance();
		
		/*Distance validation*/
		if(gu32_distance > MINIMUM_DISTANCE)
		{
			/*Moving forward*/
			MotorDC_Dir(MOT_1,FORWARD);
			MotorDC_Dir(MOT_2,FORWARD);
		}
		else
		{
			/*Stopping the two motors*/
			MotorDC_Dir(MOT_1,STOP);
			MotorDC_Dir(MOT_2,STOP);
			
			/*waiting a certain amount of time*/
			softwareDelayMs(ACTION_DELAY);
			
			/*Changing the heading*/
			MotorDC_Dir(MOT_1,BACKWARD);
			MotorDC_Dir(MOT_2,FORWARD);
			
			/*waiting a certain amount of time*/
			softwareDelayMs(ACTION_DELAY);
		}
		
	}
	
	return 0;	
}

