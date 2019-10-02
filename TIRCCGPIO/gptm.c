/*
 * gptm.c
 *
 *  Created on: Oct 2, 2019
 *      Author: Taher
 */

#include "gptm.h"

volatile uint32_t g_flag_counter = 0U;

void TIMER0A_Hnader(void)
{
    SET_BIT(TIMER0_ICR_R, TATOCINT);                    /* clear timeout flag by writing a 1 to this bit clears the TATORIS bit in the GPTMRIS register*/
    /* put yr code */
    g_flag_counter++;
}


void GPTM_Init(GPTM_POBConfig_t* a_GPTMConfig_ptr)
{
    /* enable the clock to Timer block */
    SYSCTL_RCGCTIMER_R = (SYSCTL_RCGCTIMER_R & 0xFFFFFFC0U) | (a_GPTMConfig_ptr->TimerCLK_ID);
    while(GET_BIT(SYSCTL_RCGCTIMER_R, 0) == 0);

    switch(a_GPTMConfig_ptr->TimerID)
    {
    case TIMER0:
        /* disable timer while the configuration is being modified */
        TIMER0_CTL_R = (TIMER0_CTL_R & 0xFFFFFFFEU) | TIMER_DISBALE;

        /* choose the timer bit range */
        TIMER0_CFG_R = (TIMER0_CFG_R & 0xFFFFFFF8U) | (a_GPTMConfig_ptr->TimerBitRange);

        /* select timer mode and count direction mode */
        TIMER0_TAMR_R = (TIMER0_TAMR_R & 0xFFFFFFFCU) | (a_GPTMConfig_ptr->TimerMode);
        TIMER0_TAMR_R = (TIMER0_TAMR_R & 0xFFFFFFEFU) | (a_GPTMConfig_ptr->CountDirection);

        /* set interval load register value */
        if (a_GPTMConfig_ptr->PeriodType == ONE_MILLISECONDS)
        {
            TIMER0_TAILR_R = 15000;
        }
        else if(a_GPTMConfig_ptr->PeriodType == ONE_MICROSECONDS)
        {
            TIMER0_TAILR_R = 15U;
        }
        else
        {
            /* should not enter here */
        }

        /* clear timeout flag*/
        //TIMER0_ICR_R = 0x1U;
        SET_BIT(TIMER0_ICR_R, TATOCINT);                    /* clear timeout flag by writing a 1 to this bit clears the TATORIS bit in the GPTMRIS register*/

        /* enable/disable time out INT */
        if(a_GPTMConfig_ptr->INT_State == TIMEOUT_INT_ENABLE)
        {

            TIMER0_IMR_R = (TIMER0_IMR_R & 0xFFFFFFFEU) | ((a_GPTMConfig_ptr->INT_State)  << GPTM_TIMERA_TIMEOUT_INT_MASK_BIT);

            /* enable NVIC Interrupt */
         //   NVIC->ISER[0] = ( NVIC->ISER[0]) | (1 << 19U);
        }
        else if(a_GPTMConfig_ptr->INT_State == POLLING)
        {
            //TIMER0_IMR_R = 0U;
            TIMER0_IMR_R = (TIMER0_IMR_R & 0xFFFFFFFEU) | ((a_GPTMConfig_ptr->INT_State)  << GPTM_TIMERA_TIMEOUT_INT_MASK_BIT);
        }

        /* Enable TimerA after Initialization  */
        TIMER0_CTL_R = (TIMER0_CTL_R & 0xFFFFFFFEU) | TIMER_ENABLE;
        break;

    case TIMER1:
        /* can be implemented later */
        break;

    case TIMER2:
        /* can be implemented later */
        break;

    case TIMER3:
        /* can be implemented later */
        break;

    case TIMER4:
        /* can be implemented later */
        break;

    case TIMER5:
        /* can be implemented later */
        break;

    default:
        /* shouldn't enter here */
        break;
    }
}


void GPTM_Delay(uint32_t a_Delay)
{
    volatile uint32_t loop_index;

    for(loop_index = 0U; loop_index < a_Delay; loop_index++)
    {
        while(GET_BIT(TIMER0_RIS_R, TATORIS) == 0 );         /* wait for TimerA timeout flag to set */
        SET_BIT(TIMER0_ICR_R, TATOCINT);                    /* clear timeout flag by writing a 1 to this bit clears the TATORIS bit in the GPTMRIS register*/
    }
}



