/*
 * Test_Project.c
 *
 * Created: 1/17/2020 1:53:11 PM
 * Author : ahmed
 */ 


/*
*This project is modified by team members:
-Ahmed Elnaqeeb
-Mohamed Ramadan
-Ahmed Fathi
-Menna Ehab
*/

#include "dcMotor.h"

#define MAX_SPEED		(256)
#define MIN_SPEED		(0)

int main(void)
{
	sint16_t au16_looping_var = 0;
	
	MotorDC_Init(MOT_1);
	MotorDC_Init(MOT_2);
	timer2Init(T2_COMP_MODE,T2_OC2_DIS,T2_PRESCALER_8,0,0,T2_SYNC_OPERATION,T2_POLLING);
    
	while (1) 
    {
		MotorDC_Dir(MOT_1,FORWARD);
		MotorDC_Dir(MOT_2,FORWARD);
		
		for (au16_looping_var = MIN_SPEED ; au16_looping_var < MAX_SPEED ; au16_looping_var++)
		{
			MotorDC_Speed_HwPWM(au16_looping_var);
			timer2DelayMs(20);
		}
		
		for (au16_looping_var = MAX_SPEED ; au16_looping_var > MIN_SPEED ; au16_looping_var--)
		{
			MotorDC_Speed_HwPWM(au16_looping_var);
			timer2DelayMs(20);
		}
		
		MotorDC_Dir(MOT_1,FORWARD);
		MotorDC_Dir(MOT_2,BACKWARD);
		
		timer2DelayMs(1000);
		
		MotorDC_Dir(MOT_1,STOP);
		MotorDC_Dir(MOT_2,STOP);
		
		timer2DelayMs(1000);
    }
	return 0;
}