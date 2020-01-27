/*
 * timers.h
 *
 *  Created on: Oct 22, 2019
 *      Author: Sprints
 */

#ifndef TIMERS_H_
#define TIMERS_H_

#include "registers.h"
#include "gpio.h"

/*
 * User Configuration Macros
 */

/*Setting OCR1A/B Registers*/
#define T1_OCR1A_SET(value)		OCR1A = value
#define T1_OCR1B_SET(value)		OCR1B = value
 
/*Timer2 Synchronous / Asynchronous operations*/
#define T2_SYNC_OPERATION	(0)
#define T2_ASYNC_OPERATION	(1)

/*Timer0 PWM Frequencies*/
#define T0_8KHZ		(250)
#define T0_16KHZ	(120)
#define T0_25KHZ	(80)
#define T0_40KHZ	(50)
#define T0_50KHZ	(40)
#define T0_100KHZ	(20)
#define T0_200KHZ	(10)

/*Timer1 PWM Frequencies*/
#define T1_40HZ		(50000)
#define T1_80HZ		(25000)
#define T1_160HZ	(12500)
#define T1_320HZ	(6250)
#define T1_640HZ	(3120)
#define T1_800HZ	(2500)
#define T1_1KHZ		(2000)
#define T1_2KHZ		(1000)
#define T1_4KHZ		(500)

/*Timer2 PWM Frequencies*/
#define T2_1KHZ		(250)
#define T2_2kHZ		(120)
#define	T2_4KHZ		(60)

/*PWM GPIO Pins*/
#define T0_PWM_GPIO	GPIOD
#define T0_PWM_BIT	BIT0

#define T1_PWM_GPIO	GPIOD
#define T1_PWM_BIT	BIT1

#define T2_PWM_GPIO GPIOD
#define T2_PWM_BIT	BIT2


/*Timer configurations*/

//for timer0
typedef enum En_timer0Mode_t{
	T0_NORMAL_MODE=0,T0_COMP_MODE=0x08
}En_timer0Mode_t;

typedef enum En_timer0OC_t{
	T0_OC0_DIS=0,T0_OC0_TOGGLE=0x10,T0_OC0_CLEAR=0x20,T0_OC0_SET=0x30
}En_timer0OC_t;

typedef enum En_timer0perscaler_t{
	T0_NO_CLOCK=0,T0_PRESCALER_NO=0x01,T0_PRESCALER_8=0x02,T0_PRESCALER_64=0x03,T0_PRESCALER_256=0x04,T0_PRESCALER_1024=0x05
}En_timer0perscaler_t;

typedef enum En_timer0Interrupt_t{
	T0_POLLING=0,T0_INTERRUPT_NORMAL=0x01,T0_INTERRUPT_CMP=0x02
}En_timer0Interrupt_t;


// for timer 1
typedef enum En_timer1Mode_t{
	T1_NORMAL_MODE=0x0000,T1_COMP_MODE_OCR1A_TOP=0x0008, T1_COMP_MODE_ICR1_TOP = 0x0018 , T1_PC_PWM_8BIT_MODE = 0x0100
}En_timer1Mode_t;

typedef enum En_timer1OC_t{
	T1_OC1_DIS=0,T1_OC1A_TOGGLE=0x4000,T1_OC1B_TOGGLE=0x1000,T1_OC1A_CLEAR=0x8000,T1_OC1B_CLEAR=0x2000,T1_OC1A_SET=0xC000,T1_OC1B_SET=0x3000
}En_timer1OC_t;

typedef enum En_timer1perscaler_t{
	T1_NO_CLOCK=0x0000,T1_PRESCALER_NO=0x0001,T1_PRESCALER_8=0x0002,T1_PRESCALER_64=0x0003,T1_PRESCALER_256=0x0004,T1_PRESCALER_1024=0x0005
}En_timer1perscaler_t;

typedef enum En_timer1Interrupt_t{
	T1_POLLING=0,T1_INTERRUPT_NORMAL=0x04,T0_INTERRUPT_CMP_1B=0x08, T1_INTERRUPT_CMP_1A=0x10, T1_INTERRUPT_ICAPTURE = 0x20
}En_timer1Interrupt_t;


// for timer 2
typedef enum En_timer2Mode_t{
	T2_NORMAL_MODE=0,T2_COMP_MODE=0x08
}En_timer2Mode_t;

typedef enum En_timer2OC_t{
	T2_OC2_DIS=0,T2_OC2_TOGGLE=0x10,T2_OC2_CLEAR=0x20,T2_OC2_SET=0x30
}En_timer2OC_t;

typedef enum En_timer2perscaler_t{
	T2_NO_CLOCK=0,T2_PRESCALER_NO=0x01,T2_PRESCALER_8=0x02, T2_PRESCALER_32=0x03, T2_PRESCALER_64=0x04, T2_PRESCALER_128=0x05, T2_PRESCALER_256 = 0x06, T2_PRESCALER_1024=0x07
}En_timer2perscaler_t;

typedef enum En_timer2Interrupt_t{
	T2_POLLING=0,T2_INTERRUPT_NORMAL=0x40,T2_INTERRUPT_CMP=0x80
}En_timer2Interrupt_t;


/*===========================Timer0 Control===============================*/
/**
 * Description: This function initializes timer0 peripheral for a specific operation
 * @param control mode
 * @param output compare pin mode
 * @param timer0/1 pre-scaler value
 * @param counter initial value
 * @param output compare initial value
 * @param interrupt mask
 */
void timer0Init(En_timer0Mode_t en_mode,En_timer0OC_t en_OC0,En_timer0perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, En_timer0Interrupt_t en_interruptMask);

/**
 * Description: This function sets the value of the timer0 counter
 * @param counter value
 */

void timer0Set(uint8_t u8_value);

/**
 * Description: This function reads timer0 counter value
 * @return counter value
 */
uint8_t timer0Read(void);

/**
 * Description: This function starts timer0 counter
 */
void timer0Start(void);

/**
 * Description: This function stops timer0 counter
 */
void timer0Stop(void);

/**
 * Description: This function uses timer0 to stop CPU operation for a certain time in milliseconds
 * @param delay in ms
 */
void timer0DelayMs(uint16_t u16_delay_in_ms);

/**
 * Description : This function uses timer0 to stop CPU operation for a certain time in microseconds
 * @param delay in us
 */
void timer0DelayUs(uint32_t u32_delay_in_us);

/**
 * Description: Using timer0 to generate PWM signal
 * @param dutyCycle
 * @param frequency
 */
void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);


/*===========================Timer1 Control===============================*/
/**
 * Description: This function initializes timer1 peripheral for a specific operation
 * @param control mode
 * @param output compare pins A and B
 * @param timer0/1 pre-scaler value
 * @param counter initial value
 * @param output compare A initial value
 * @param output compare B initial value 
 * @param input capture initial value
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t en_mode,En_timer1OC_t en_OC,En_timer1perscaler_t en_prescal, uint16_t u16_initialValue, uint16_t u16_outputCompareA, uint16_t u16_outputCompareB,uint16_t u16_inputCapture, En_timer1Interrupt_t en_interruptMask);

/**
 * Description: This function sets the value of the timer1 counter
 * @param counter value
 */
void timer1Set(uint16_t u16_value);

/**
 * Description: This function reads timer1 counter value
 * @return counter value
 */
uint16_t timer1Read(void);

/**
 * Description: This function starts timer1 counter
 */
void timer1Start(void);

/**
 * Description: This function stops timer1 counter
 */
void timer1Stop(void);

/**
 * Description: This function uses timer1 to stop CPU operation for a certain time in milliseconds
 * @param delay in ms
 */
void timer1DelayMs(uint16_t u16_delay_in_ms);

/**
 * Description : This function uses timer1 to stop CPU operation for a certain time in microseconds
 * @param delay in us
 */
void timer1DelayUs(uint32_t u32_delay_in_us);

/**
 * Description: Using timer1 to generate PWM signal
 * @param dutyCycle
 * @param frequency
 */
void timer1SwPWM(uint8_t u8_dutyCycle,uint16_t u16_frequency);


/*===========================Timer2 Control===============================*/
/**
 * Description: This function initializes timer2 peripheral for a specific operation
 * @param control mode
 * @param output compare pin mode
 * @param timer2 pre-scaler value
 * @param counter initial value
 * @param output compare initial value
 * @param synchronous / asynchronous operation modes
 * @param interrupt mask
 */
void timer2Init(En_timer2Mode_t en_mode,En_timer2OC_t en_OC,En_timer2perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, uint8_t u8_assynchronous, En_timer2Interrupt_t en_interruptMask);

/**
 * Description: This function sets the value of the timer2 counter
 * @param counter value
 */
void timer2Set(uint8_t u8_a_value);

/**
 * Description: This function reads timer2 counter value
 * @return counter value
 */
uint8_t timer2Read(void);

/**
 * Description: This function starts timer2 counter
 */
void timer2Start(void);

/**
 * Description: This function stops timer2 counter
 */
void timer2Stop(void);

/**
 * Description: This function uses timer2 to stop CPU operation for a certain time in milliseconds
 * @param delay in ms
 */
void timer2DelayMs(uint16_t u16_delay_in_ms);

/**
 * Description : This function uses timer1 to stop CPU operation for a certain time in microseconds
 * @param delay in us
 */
void timer2DelayUs(uint32_t u32_delay_in_us);

/**
 * Description: Using timer0 to generate PWM signal
 * @param dutyCycle
 * @param frequency
 */
void timer2SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);

#endif /* TIMERS_H_ */