/*
 * systick.h
 *
 *  Created on: Oct 1, 2019
 *      Author: Taher
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_
#include "std.h"
#include "common_macros.h"
#include "tm4c123gh6pm.h"

#define COUNT_FLAG        (16U)         /* Count Flag #Bit Number in the SysTick Control and Status Register */

void SYSTICK_Init_1ms(void);
void SYSTICK_Delay_ms(uint64_t a_Delay);


#endif /* SYSTICK_H_ */
