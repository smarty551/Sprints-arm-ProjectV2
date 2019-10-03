/*
 * gptm.h
 *
 *  Created on: Oct 2, 2019
 *      Author: Taher
 */

#ifndef GPTM_H_
#define GPTM_H_

#include "std.h"
#include "common_macros.h"
#include "tm4c123gh6pm.h"

#define TATORIS         (0U)           /* GPTM Timer A #Bit Number of Time-Out Raw Interrupt */
#define TATOCINT        (0U)          /*  GPTM Timer A #Bit Number of GPTM Interrupt Clear */
#define TATOMIS         (0U)          /*  GPTM Timer A #Bit Number of GPTM Masked Interrupt Status */
#define TACDIR          (4U)          /*  GPTM Timer A #Bit Number of GPTM Timer A Count Direction */

typedef enum
{
    TIMER_16_32BIT_SELECT32 = 0U,
    TIMER_32_64BIT_SELECT64 = 0U,
    TIMER_16_32BIT_RTC_SELECT32 = 1U,
    TIMER_32_64BIT_RTC_SELECT64 = 1U,
    TIMER_16_32BIT_SELECT16 = 4U,
    TIMER_32_64BIT_SELECT32 = 4U
}GPTM_Range_t;

typedef enum
{
    COUNT_DOWN = 0U,
    COUNT_UP = 1U
}GPTM_CountDirection_t;

typedef enum
{
    ONE_SHOT_MODE = 1U,
    PERIODIC_MODE,
    CAPTURE_MODE
}GPTM_Mode_t;

typedef enum
{
    COMPARE_CAPTURE_MODE = 0U,
    PWM_MODE
}GPTM_AlternateMode_t;

typedef enum
{
    TIMER_DISBALE = 0U,
    TIMER_ENABLE
}GPTM_State_t;

typedef enum
{
    CONTINUE_COUNTING_DURING_HALTED = 0U,
    FREEZE_COUNTING_DURING_HALTED
}GPTM_StallState_t;

typedef enum
{
    POLLING = 0U,
    MATCH_INT_ENABLE = 1U,
    RTC_INT_ENABLE = 1U,
    CAPTURE_INT_EVENT_ENABLE = 1U,
    CAPTURE_INT_MATCH_ENABLE = 1U,
    TIMEOUT_INT_ENABLE = 1U
}GPTM_INT_Mask_t;

typedef enum
{
    GPTM_TIMERA_TIMEOUT_INT_MASK_BIT = 0U,
    GPTM_TIMERA_CAPTURE_MATCH_INT_MASK_BIT = 1U,
    GPTM_TIMERA_CAPTURE_EVENT_INT_MASK_BIT = 2U,
    GPTM_TIMERA_MATCH_INT_MASK_BIT = 4U
}GPTM_INT_MaskBITS_t;

typedef enum
{
    TIMER0_CLK_ENABLE = 1U,
    TIMER1_CLK_ENABLE = 2U,
    TIMER2_CLK_ENABLE = 4U,
    TIMER3_CLK_ENABLE = 8U,
    TIMER4_CLK_ENABLE = 16U,
    TIMER5_CLK_ENABLE = 32U
}GPTM_CLK_t;

typedef enum
{
    TIMER0 = 0U,
    TIMER1,
    TIMER2,
    TIMER3,
    TIMER4,
    TIMER5
}GPTM_ID_t;

typedef enum
{
    ONE_MILLISECONDS = 0U,
    ONE_MICROSECONDS
}GPTM_PeriodType_t;


typedef struct
{
    GPTM_ID_t TimerID;
    GPTM_CLK_t TimerCLK_ID;
    GPTM_Range_t TimerBitRange;
    GPTM_PeriodType_t PeriodType;
    GPTM_Mode_t TimerMode;
    GPTM_CountDirection_t CountDirection;
    GPTM_INT_Mask_t INT_State;
}GPTM_POBConfig_t;


extern volatile uint32_t g_flag_counter;

extern void GPTM_Init(GPTM_POBConfig_t* a_GPTMConfig_ptr);
extern void GPTM_Delay(uint32_t a_Delay);




#endif /* GPTM_H_ */
