#include "HwPWM.h"

extern uint8_t gu8_t1_prescaler_value;

void HwPWMInit(void)
{
	timer1Init(T1_PC_PWM_8BIT_MODE,T1_OC1_DIS,T1_PRESCALER_NO,0,0,0,0,T1_POLLING);
	gpioPinDirection(OCR1A_GPIO_PORT,OCR1A_GPIO_PIN,OUTPUT);
	gpioPinDirection(OCR1B_GPIO_PORT,OCR1B_GPIO_PIN,OUTPUT);
	
	return;
}

void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency)
{
	gu8_t1_prescaler_value = (uint8_t)a_u32_frequency;
	T1_OCR1A_SET(DUTY_CYCLE_MAPPING(a_u8_duty));
	timer1Start();
	return;
}
