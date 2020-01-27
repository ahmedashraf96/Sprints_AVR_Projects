/*
 * dcMotor.c
 *
 * Created: 1/26/2020 3:59:17 PM
 *  Author: ahmed
 */ 
#include "dcMotor.h"

uint8_t gu8_t0_start_flag = 0;
uint8_t gu8_t1_start_flag = 0;

void MotorDC_Init(En_motorType_t en_motor_number)
{
	switch(en_motor_number)
	{
		case MOT_1:
			gpioPinDirection(MOTOR_EN_1_GPIO,MOTOR_EN_1_BIT,OUTPUT);
			gpioPinDirection(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,OUTPUT);
			gpioPinDirection(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,OUTPUT);
			break;
			
		case MOT_2:
			gpioPinDirection(MOTOR_EN_2_GPIO,MOTOR_EN_2_BIT,OUTPUT);
			gpioPinDirection(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,OUTPUT);
			gpioPinDirection(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,OUTPUT);
			break;
			
		default: break;		
	}
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8,0,0,T0_POLLING);
	timer1Init(T1_PC_PWM_8BIT_MODE,T1_OC1_DIS,T1_PRESCALER_8,0,0,0,0,T0_POLLING);
	
	return;
}

void MotorDC_Dir(En_motorType_t en_motor_number, En_motorDir_t en_motor_dir)
{
	switch(en_motor_number)
	{
		case MOT_1:
			switch(en_motor_dir)
			{
				case STOP:
					gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
					break;
					
				case FORWARD:
					gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
					gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
					gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
					break;
						
				case BACKWARD:
					gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
					gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);
					break;							
			}
			break;
			
		case MOT_2:
			switch(en_motor_dir)
			{
				case STOP:
					gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
					break;
			
				case FORWARD:
					gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,HIGH);
					gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,HIGH);
					gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,LOW);
					break;
			
				case BACKWARD:
					gpioPinWrite(MOTOR_OUT_1A_GPIO,MOTOR_OUT_1A_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_1B_GPIO,MOTOR_OUT_1B_BIT,HIGH);
					gpioPinWrite(MOTOR_OUT_2A_GPIO,MOTOR_OUT_2A_BIT,LOW);
					gpioPinWrite(MOTOR_OUT_2B_GPIO,MOTOR_OUT_2B_BIT,HIGH);
					break;
			}
			break;				
	}
	return;
}

void MotorDC_Speed_PollingWithT0(uint8_t u8_motor_speed)
{
	if (gu8_t0_start_flag == 0)
	{
		timer0Start();
		gu8_t0_start_flag++;
	} 
	else
	{
		/*Do nothing*/
	}
	timer0SwPWM(u8_motor_speed,T0_8KHZ);
	return;
}

void MotorDC_Speed_HwPWM(uint8_t u8_motor_speed)
{
	if (gu8_t1_start_flag == 0)
	{
		timer1Start();
		gu8_t1_start_flag++;
	}
	else
	{
		/*Do nothing*/
	}
	
	T1_OCR1A_SET(u8_motor_speed);
	T1_OCR1B_SET(u8_motor_speed);
	
	return;
}