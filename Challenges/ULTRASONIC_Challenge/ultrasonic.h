/*
 * ultrasonic.h
 *
 * Created: 1/30/2020 12:52:25 PM
 *  Author: ahmed
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define ULTRASONIC_GPIO_PORT	(GPIOB)
#define ULTRASONIC_TRIG_PIN		(BIT1)
#define ULTRASONIC_ECHO_PIN		(BIT2)

/************************************************************************/
/*                          Ultrasonic functions                        */
/************************************************************************/

/*
 * Description : Initializes the ultrasonic module
*/
void ultrasonic_init(void);

/*
 * Description : Reads the distance measured by the ultrasonic module
 * @ret : returns distance
*/
uint32_t ultrasonic_readDistance(void);

#endif /* ULTRASONIC_H_ */