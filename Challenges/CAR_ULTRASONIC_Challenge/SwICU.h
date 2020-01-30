/*
 * SwICU.h
 *
 *  Created on: Oct 27, 2019
 *      Author: Sprints
 */

#ifndef SWICU_H_
#define SWICU_H_

#include "interrupts.h"
#include "timers.h"

typedef enum EN_SwICU_Edge_t{
	SwICU_EdgeFalling = 2,
	SwICU_EdgeRising = 3
}EN_SwICU_Edge_t;

/*
* Description : Initialization of SW ICU
* @param Edge type to be applied
*/
void SwICU_Init(EN_SwICU_Edge_t a_en_inputCaptureEdge);

/*
* Description : Setting SW ICU edge detector
* @param Edge type to be applied
*/void SwICU_SetCfgEdge(EN_SwICU_Edge_t a_en_inputCaptureEdgeedge);

/*
* Description : Reading timer0 ticks
* @param pointer to 8-bit variable
*/
void SwICU_Read(volatile uint8_t * a_pu8_capt);

/*
* Description : Stopping ICU operation
*/
void SwICU_Stop(void);

/*
* Description : Starting ICU operation
*/
void SwICU_Start(void);

#endif /* SWICU_H_ */
