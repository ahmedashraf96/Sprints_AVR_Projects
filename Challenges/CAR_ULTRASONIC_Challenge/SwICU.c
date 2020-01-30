#include "SwICU.h"

/*User defined important macros*/
#define GENERAL_INTERRUPTS_EN_DIS_BIT	(7)
#define EXTI2_SENSE_CTRL_BIT			(6)
#define EXTI2_EN_DIS_BIT				(5)

#define T0_CNT_ZERO						(0)

#define ICU_FLAG_NEVER_USED				(0)
#define ICU_FLAG_USED_ONCE				(1)

/*Variable used in reading timer0 counter value*/
static volatile uint8_t gu8_swICU_val = 0;

/*Global variable used to count timer overflows*/
static volatile uint32_t gu32_timer0_ovf_count = 0;

/*Global variable used to indicate icu status*/
static volatile uint8_t gu8_icuFlag = 0;

void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge)
{
	/*Initializing timer0*/
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_1024,0,0,T0_POLLING);
	
	/*Enabling global interrupts*/
	SET_BIT(SREG,GENERAL_INTERRUPTS_EN_DIS_BIT);
	
	/*Setting INT2 edge triggering*/
	switch (a_en_inputCaptureEdge)
	{
		case SwICU_EdgeRising:
			SET_BIT(MCUCSR,EXTI2_SENSE_CTRL_BIT);
			break;
		
		case SwICU_EdgeFalling:	
			CLEAR_BIT(MCUCSR,EXTI2_SENSE_CTRL_BIT);
			break;
		
		default: break;	
	}
	
	/*Enabling INT2*/
	SET_BIT(GICR,EXTI2_EN_DIS_BIT);
}

void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdgeedge)
{
	/*Disabling INT2*/
	CLEAR_BIT(GICR,EXTI2_EN_DIS_BIT);

	/*Setting INT2 edge triggering*/
	switch (a_en_inputCaptureEdgeedge)
	{
		case SwICU_EdgeRising:
			SET_BIT(MCUCSR,EXTI2_SENSE_CTRL_BIT);
			break;
		
		case SwICU_EdgeFalling:	
			CLEAR_BIT(MCUCSR,EXTI2_SENSE_CTRL_BIT);
			break;
		
		default: break;	
	}
	
	/*Enabling INT2*/
	SET_BIT(GICR,EXTI2_EN_DIS_BIT);
	
	return;
}

void SwICU_Read(volatile uint8_t * a_pu8_capt)
{
	/*Reading timer ticks*/
	*a_pu8_capt = gu8_swICU_val;
	return;
}

void SwICU_Start(void)
{
	/*Starting timer0*/
	timer0Start();
	return;
}

void SwICU_Stop(void)
{
	/*Stopping timer0 and resetting its counter*/
	timer0Stop();
	timer0Set(T0_CNT_ZERO);
	return;
}

ISR(INT2_vect)
{
	/*Rising edge selected*/
	if (GET_BIT(MCUCSR,EXTI2_SENSE_CTRL_BIT))
	{		
		if(gu8_icuFlag == ICU_FLAG_NEVER_USED)
		{
			SwICU_Start();
			SwICU_SetCfgEdge(SwICU_EdgeFalling);
			gu8_icuFlag = ICU_FLAG_USED_ONCE;
		}
		else if(gu8_icuFlag == ICU_FLAG_USED_ONCE)
		{
			gu8_swICU_val = timer0Read();
			SwICU_Stop();
			SwICU_SetCfgEdge(SwICU_EdgeFalling);
			gu8_icuFlag = ICU_FLAG_NEVER_USED;
		}
	} 
	/*Falling edge selected*/
	else
	{
		if(gu8_icuFlag == ICU_FLAG_NEVER_USED)
		{
			SwICU_Start();
			SwICU_SetCfgEdge(SwICU_EdgeRising);
			gu8_icuFlag = ICU_FLAG_USED_ONCE;
		}
		else if(gu8_icuFlag == ICU_FLAG_USED_ONCE)
		{
			gu8_swICU_val = timer0Read();
			SwICU_Stop();
			SwICU_SetCfgEdge(SwICU_EdgeRising);
			gu8_icuFlag = ICU_FLAG_NEVER_USED;
		}

	}
}
