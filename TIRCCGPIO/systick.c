/*
 * systick.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Taher
 */

#include "systick.h"

volatile uint32_t g_flag_counter = 0U;

void SYSTICK_Handler(void)
{

}

void SYSTICK_Init_1ms(void)
{
    /* SysTick Control and Status Register
     * 1- Disable the Timer/Counter
     * 2- Enable the Interrupt
     * 3- CLK Source : System CLK
     */
    NVIC_ST_CTRL_R = (NVIC_ST_CTRL_R & 0xFFFFFFF8U) | 6U;

    /* reload this value to the Current Register to give 1 ms */
    NVIC_ST_RELOAD_R = (NVIC_ST_RELOAD_R & 0xFF000000U) | 15999U;
    /* Initialize the Current Register & CLEAR Count Flag in SysTick Control and Status Register */
    NVIC_ST_CURRENT_R = (NVIC_ST_CURRENT_R & 0xFF000000U) | 0U;
    /* Enable the Timer/SYSTICK */
    NVIC_ST_CTRL_R = (NVIC_ST_CTRL_R & 0xFFFFFFFEU) | 1U;
}
