/***************************************************************************************************************
 *************************************
 * LED.h                             *
 * Author    : AHMED ASHRY           *
 * DATE      : Oct 2, 2019           *
 * VERSION   : 001                   *
 *************************************
 ***************************************************************************************************************/


/***************************************************************************************************************
*  HEADER FILE GUARDIAN
****************************************************************************************************************/
#ifndef LED_H_
#define LED_H_

/***************************************************************************************************************
 * include(s)
 ***************************************************************************************************************/

/***************************************************************************************************************
 * definition(s) by user
 ***************************************************************************************************************/
#define PATTERN_STATES   (6)
#define PATTERN_STEP    (1000)


/***************************************************************************************************************
 * type definition(s)
 ***************************************************************************************************************/
typedef enum
{
    RISING_STATE,
    HIGH_STATE,
    FALLING_STATE,
    LOW_STATE
}PatternState;

typedef enum
{
    MALFUNCTION_PATTERN_TIME = 300000,
    DEVICE_SEARCH_PATTERN_TIME = 1500,
    VERIFICATION_TIME = 1200,
    CONNECTION_ON_PATTERN_TIME = 300
}PatternTime;


/***************************************************************************************************************
 * external variable(s)
 ***************************************************************************************************************/

/***************************************************************************************************************
 * external function prototype(s)
 ***************************************************************************************************************/


#endif /* LED_H_ */
