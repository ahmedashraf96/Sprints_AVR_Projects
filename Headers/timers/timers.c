#include "timers.h"

//Timer flags
#define T0_TOV_FLAG		  (0)
#define T0_OC_FLAG		  (1)

#define T1_TOV_FLAG		  (2)
#define T1_OCB_FLAG		  (3)
#define T1_OCA_FLAG		  (4)
#define T0_ICR_FLAG		  (5)

#define T2_TOV_FLAG		  (6)
#define T2_OC_FLAG		  (7)

/*Timer2 Synchronous / Asynchronous bit*/
#define T2_SYNC_ASYNC_BIT (3)

//Masks used to clear timers used prescalers
#define T0_PRESCALER_CLEAR_MASK		(0xF8)
#define T1_PRESCALER_CLEAR_MASK		(0xFFF8)
#define T2_PRESCALER_CLEAR_MASK		(0xF8)

//OCR value to use delay functions
#define OCR_T0_DELAY_MS_VALUE			(250)
#define OCR_T0_DELAY_US_VALUE			(2)

#define OCR_T1_DELAY_MS_VALUE			(2000)
#define OCR_T1_DELAY_US_VALUE			(2)

#define OCR_T2_DELAY_MS_VALUE			(250)
#define OCR_T2_DELAY_US_VALUE			(2)

//PWM Modes
#define PWM_NON_INVERTED_MODE			(0xA000)

//Global variables used to hold the value of the timers different prescalers.
static uint8_t gu8_t0_prescaler_value = 0;
static uint8_t gu8_t1_prescaler_value = 0;
static uint8_t gu8_t2_prescaler_value = 0;


/************************************************************************/
/*					Timer0 functions                                    */
/************************************************************************/

void timer0Init(En_timer0Mode_t en_mode,En_timer0OC_t en_OC0,En_timer0perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, En_timer0Interrupt_t en_interruptMask)
{
	TCCR0 = (en_mode | en_OC0);
	TCNT0 = u8_initialValue;
	OCR0  = u8_outputCompare;
	TIMSK = en_interruptMask;
	
	gu8_t0_prescaler_value = en_prescal;
	return;
}

void timer0Set(uint8_t u8_value)
{
	TCNT0 = u8_value;
	return;
}

uint8_t timer0Read(void)
{
	return TCNT0;
}

void timer0Start(void)
{
	TCCR0 &= T0_PRESCALER_CLEAR_MASK;
	TCCR0 |= gu8_t0_prescaler_value;
	return;
}

void timer0Stop(void)
{
	TCCR0 &= T0_PRESCALER_CLEAR_MASK;
	return;
}

void timer0DelayMs(uint16_t u16_delay_in_ms)
{	
	uint16_t au16_loopCounter = 0;
	
	OCR0 = OCR_T0_DELAY_MS_VALUE;
	
	TCCR0 &= T0_PRESCALER_CLEAR_MASK; //Stopping the counter
	TCCR0 |= T0_PRESCALER_64;  //Loading the timer with prescaler_64	
	
	while(au16_loopCounter <= u16_delay_in_ms)
	{
		if (GET_BIT(TIFR,T0_OC_FLAG))
		{
			SET_BIT(TIFR,T0_OC_FLAG);
			au16_loopCounter++;
		} 
		else
		{
			/*Do nothing*/
		}
	}
	TCCR0 &= T0_PRESCALER_CLEAR_MASK;
	TCNT0 = 0;
	
	return;
}

void timer0DelayUs(uint32_t u32_delay_in_us)
{	
	uint32_t au32_loopCounter = 0;
	
	OCR0 = OCR_T0_DELAY_US_VALUE;
	
	TCCR0 &= T0_PRESCALER_CLEAR_MASK; //Stopping the counter
	TCCR0 |= T0_PRESCALER_8;  //Loading the timer with prescaler_8
	
	while(au32_loopCounter <= u32_delay_in_us)
	{
		if (GET_BIT(TIFR,T0_OC_FLAG))
		{
			SET_BIT(TIFR,T0_OC_FLAG);
			au32_loopCounter++;
		}
		else
		{
			/*Do nothing*/
		}	
	}
	TCCR0 &= T0_PRESCALER_CLEAR_MASK;
	TCNT0 = 0;
	return;
}

void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency)
{
	if (u8_dutyCycle == 100)
	{
		gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,HIGH);
	} 
	else if(u8_dutyCycle == 0)
	{
		gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,LOW);
	}
	else
	{
		TCNT0 = u8_frequency;
		OCR0  = u8_frequency + (((uint16_t)u8_dutyCycle * (u8_frequency)) / 100);

		TCCR0 &= T0_PRESCALER_CLEAR_MASK; //Stopping the counter
		TCCR0 |= T0_PRESCALER_8;  //Loading the timer with prescaler_8(0.5us tick)

		gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,HIGH);
			
		while(GET_BIT(TIFR,T0_OC_FLAG) == 0);
		SET_BIT(TIFR,T0_OC_FLAG);
			
		gpioPinWrite(T0_PWM_GPIO,T0_PWM_BIT,LOW);
			
		while(GET_BIT(TIFR,T0_TOV_FLAG) == 0);
		SET_BIT(TIFR,T0_TOV_FLAG);

		TCCR0 &= T0_PRESCALER_CLEAR_MASK;	//Stop timer0
		TCNT0 = 0;
	}
			
	return;
}

/************************************************************************/
/*					Timer1 functions                                    */
/************************************************************************/

void timer1Init(En_timer1Mode_t en_mode,En_timer1OC_t en_OC,En_timer1perscaler_t en_prescal, uint16_t u16_initialValue, uint16_t u16_outputCompareA, uint16_t u16_outputCompareB,uint16_t u16_inputCapture, En_timer1Interrupt_t en_interruptMask)
{
	TCCR1 = (en_mode | en_OC);
	TCNT1 = u16_initialValue;
	OCR1A = u16_outputCompareA;
	OCR1B = u16_outputCompareB;
	ICR1  = u16_inputCapture;
	TIMSK = en_interruptMask;
	
	if (en_mode == T1_PC_PWM_8BIT_MODE)
	{
		TCCR1 |= PWM_NON_INVERTED_MODE;
	} 
	else
	{
		/*Do nothing*/
	}
	gu8_t1_prescaler_value = en_prescal;
	
	return; 	
}

void timer1Set(uint16_t u16_value)
{
	TCNT1 = u16_value;
	return;
}

uint16_t timer1Read(void)
{
	return TCNT1;
}

void timer1Start(void)
{
	TCCR1 &= T1_PRESCALER_CLEAR_MASK;
	TCCR1 |= gu8_t1_prescaler_value;
	return;
}

void timer1Stop(void)
{
	TCCR1 &= T1_PRESCALER_CLEAR_MASK;	
	return;
}

void timer1DelayMs(uint16_t u16_delay_in_ms)
{
	uint16_t au16_loopCounter = 0;
	
	OCR1A = OCR_T1_DELAY_MS_VALUE;
	
	TCCR1 &= T1_PRESCALER_CLEAR_MASK; //Stopping the counter
	TCCR1 |= T1_PRESCALER_8;  //Loading the timer with prescaler_64
	
	while(au16_loopCounter <= u16_delay_in_ms)
	{
		if (GET_BIT(TIFR,T1_OCA_FLAG))
		{
			SET_BIT(TIFR,T1_OCA_FLAG);
			au16_loopCounter++;
		}
		else
		{
			/*Do nothing*/
		}
	}
	TCCR1 &= T1_PRESCALER_CLEAR_MASK;
	TCNT1 = 0;
	
	return;
}

void timer1DelayUs(uint32_t u32_delay_in_us)
{
	uint32_t au32_loopCounter = 0;
	
	OCR1A = OCR_T1_DELAY_US_VALUE;
	
	TCCR1 &= T1_PRESCALER_CLEAR_MASK; //Stopping the counter
	TCCR1 |= T1_PRESCALER_8;  //Loading the timer with prescaler_64
	
	while(au32_loopCounter <= u32_delay_in_us)
	{
		if (GET_BIT(TIFR,T1_OCA_FLAG))
		{
			SET_BIT(TIFR,T1_OCA_FLAG);
			au32_loopCounter++;
		}
		else
		{
			/*Do nothing*/
		}
	}
	TCCR1 &= T1_PRESCALER_CLEAR_MASK;
	TCNT1 = 0;
	
	return;
}

void timer1SwPWM(uint8_t u8_dutyCycle,uint16_t u16_frequency)
{
	if (u8_dutyCycle == 100)
	{
		gpioPinWrite(T1_PWM_GPIO,T1_PWM_BIT,HIGH);
	}
	else if(u8_dutyCycle == 0)
	{
		gpioPinWrite(T1_PWM_GPIO,T1_PWM_BIT,LOW);
	}
	else
	{
		TCNT1 = u16_frequency;
		OCR1A  = u16_frequency + (((uint16_t)u8_dutyCycle * (u16_frequency)) / 100);

		TCCR1 &= T1_PRESCALER_CLEAR_MASK; //Stopping the counter
		TCCR1 |= T1_PRESCALER_8;  //Loading the timer with prescaler_8(0.5us tick)

		gpioPinWrite(T1_PWM_GPIO,T1_PWM_BIT,HIGH);
		
		while(GET_BIT(TIFR,T1_OCA_FLAG) == 0);
		SET_BIT(TIFR,T1_OCA_FLAG);
		
		gpioPinWrite(T1_PWM_GPIO,T1_PWM_BIT,LOW);
		
		while(GET_BIT(TIFR,T1_TOV_FLAG) == 0);
		SET_BIT(TIFR,T1_TOV_FLAG);

		TCCR1 &= T1_PRESCALER_CLEAR_MASK;	//Stop timer1
		TCNT1 = 0;
	}
	
	return;
}
/************************************************************************/
/*					Timer2 functions                                    */
/************************************************************************/

void timer2Init(En_timer2Mode_t en_mode,En_timer2OC_t en_OC,En_timer2perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, uint8_t u8_assynchronous, En_timer2Interrupt_t en_interruptMask)
{
	TCCR2 = (en_mode | en_OC);
	TCNT2 = u8_initialValue;
	OCR2  = u8_outputCompare;
	TIMSK = en_interruptMask;
	
	switch (u8_assynchronous)
	{
		case T2_SYNC_OPERATION:
			CLEAR_BIT(ASSR,T2_SYNC_ASYNC_BIT);
			break;
			
		case T2_SYNC_ASYNC_BIT:
			SET_BIT(ASSR,T2_SYNC_ASYNC_BIT);
			break;
			
		default: break;		
	}
	
	gu8_t0_prescaler_value = en_prescal;
	
	return;
}

void timer2Set(uint8_t u8_a_value)
{
	TCNT2 = u8_a_value;
	return;
}

uint8_t timer2Read(void)
{
	return TCNT2;
}

void timer2Start(void)
{
	TCCR2 &= T2_PRESCALER_CLEAR_MASK;
	TCCR2 |= gu8_t2_prescaler_value;
	return;
}

void timer2Stop(void)
{
	TCCR2 &= T2_PRESCALER_CLEAR_MASK;
	return;
}

void timer2DelayMs(uint16_t u16_delay_in_ms)
{
	uint16_t au16_loopCounter = 0;
	
	OCR2 = OCR_T2_DELAY_MS_VALUE;
	
	TCCR2 &= T2_PRESCALER_CLEAR_MASK; //Stopping the counter
	TCCR2 |= T2_PRESCALER_64;  //Loading the timer with prescaler_64
	
	while(au16_loopCounter <= u16_delay_in_ms)
	{
		if (GET_BIT(TIFR,T2_OC_FLAG))
		{
			SET_BIT(TIFR,T2_OC_FLAG);
			au16_loopCounter++;
		}
		else
		{
			/*Do nothing*/
		}
	}
	TCCR2 &= T2_PRESCALER_CLEAR_MASK;
	TCNT2 = 0;
	
	return;	
}

void timer2DelayUs(uint32_t u32_delay_in_us)
{
	uint32_t au32_loopCounter = 0;
	
	OCR2 = OCR_T2_DELAY_US_VALUE;
	
	TCCR2 &= T2_PRESCALER_CLEAR_MASK; //Stopping the counter
	TCCR2 |= T2_PRESCALER_8;  //Loading the timer with prescaler_8
	
	while(au32_loopCounter <= u32_delay_in_us)
	{
		if (GET_BIT(TIFR,T2_OC_FLAG))
		{
			SET_BIT(TIFR,T2_OC_FLAG);
			au32_loopCounter++;
		}
		else
		{
			/*Do nothing*/
		}
	}
	TCCR2 &= T2_PRESCALER_CLEAR_MASK;
	TCNT2 = 0;
	
	return;
}

void timer2SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency)
{
	if (u8_dutyCycle == 100)
	{
		gpioPinWrite(T2_PWM_GPIO,T2_PWM_BIT,HIGH);
	}
	else if(u8_dutyCycle == 0)
	{
		gpioPinWrite(T2_PWM_GPIO,T2_PWM_BIT,LOW);
	}
	else
	{
		TCNT2 = u8_frequency;
		OCR2  = u8_frequency + (((uint16_t)u8_dutyCycle * (u8_frequency)) / 100);

		TCCR2 &= T2_PRESCALER_CLEAR_MASK; //Stopping the counter
		TCCR2 |= T2_PRESCALER_64;  //Loading the timer with prescaler_64(4us tick)

		gpioPinWrite(T2_PWM_GPIO,T2_PWM_BIT,HIGH);
		
		while(GET_BIT(TIFR,T2_OC_FLAG) == 0);
		SET_BIT(TIFR,T2_OC_FLAG);
		
		gpioPinWrite(T2_PWM_GPIO,T2_PWM_BIT,LOW);
		
		while(GET_BIT(TIFR,T2_TOV_FLAG) == 0);
		SET_BIT(TIFR,T2_TOV_FLAG);

		TCCR2 &= T2_PRESCALER_CLEAR_MASK;	//Stop timer2
		TCNT2 = 0;
	}
	
	return;
}