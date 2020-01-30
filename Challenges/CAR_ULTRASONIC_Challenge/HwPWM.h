/*
 * HwPWM.h
 *
 *  Created on: Oct 28, 2019
 *      Author: Think
 */

#ifndef HWPWM_H_
#define HWPWM_H_

#include "timers.h"

/*H/W PWM configurations*/
#define OCR1A_GPIO_PORT	(GPIOD)
#define OCR1A_GPIO_PIN	(BIT5)

#define OCR1B_GPIO_PORT	(GPIOD)
#define OCR1B_GPIO_PIN	(BIT4)

#define PWM_FRQ_31KHZ	(T1_PRESCALER_NO)
#define PWM_FRQ_4KHZ	(T1_PRESCALER_8)
#define PWM_FRQ_500HZ	(T1_PRESCALER_64)
#define PWM_FRQ_120HZ	(T1_PRESCALER_256)
#define PWM_FRQ_30HZ	(T1_PRESCALER_1024)

#define DUTY_CYCLE_MAPPING(DUTY)	(DUTY * 2.5)

/************************************************************************/
/*                          H/W PWM Functions		                    */
/************************************************************************/

/*
* Description : Initializes Phase correct H/W PWM 8-bit mode
*/
void HwPWMInit(void);

/*
* Description : Creates PWM signal with specified duty and frequency
* @param : PWM signal duty cycle
* @param : PWM signal frequency
*/
void HwPWMSetDuty(uint8_t a_u8_duty, uint32_t a_u32_frequency);

#endif /* HWPWM_H_ */
