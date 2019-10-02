

#include "LED.h"
#include "PWM.h"

static PatternTime  CurrentPeriod = MALFUNCTION_PATTERN_TIME;
/**
 * main.c
 */
void main(void)
{
    PWM_Init(CurrentPeriod, 0);
    static PatternState CurrentState= RISING_STATE;
    static uint32_t RateOfChange = 0;
    static uint32_t RisisgTimeCtr = 0;
    static uint32_t HighTimeCtr = 0;
    static uint32_t FallingTimeCtr = 100;
    static uint32_t LowTimeCtr = 0;


    RateOfChange = (100 * PATTERN_STEP * PATTERN_STATES) / CurrentPeriod;


    switch(CurrentState)
    {
    case RISING_STATE:
        RisisgTimeCtr += RateOfChange;
        PWM_SetDutycycle(RisisgTimeCtr);
        if(RisisgTimeCtr == 100)
        {
            CurrentState = HIGH_STATE;
            RisisgTimeCtr = 0;
        }
        break;

    case HIGH_STATE:
        PWM_SetDutycycle(100);
        HighTimeCtr += RateOfChange;
        if(HighTimeCtr == 100)
        {
            CurrentState = FALLING_STATE;
            HighTimeCtr = 0;
        }
        break;

    case FALLING_STATE:
        FallingTimeCtr -= RateOfChange;
        PWM_SetDutycycle(FallingTimeCtr);
        if(FallingTimeCtr == 0)
        {
            CurrentState = LOW_STATE;
            FallingTimeCtr = 100;
        }

        break;

    case LOW_STATE:
        PWM_SetDutycycle(0);
        LowTimeCtr += RateOfChange;
        if(LowTimeCtr == 300)
        {
            CurrentState = RISING_STATE;
            LowTimeCtr = 0;
        }
        break;
    }
}
