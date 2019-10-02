/***************************************************************************************************************
 *************************************
 * PWM.c                             *
 * Author    : AHMED ASHRY           *
 * DATE      : 8 OCT 19              *
 * VERSION   : 001                   *
 *************************************
 ***************************************************************************************************************/

/*******************************************************************************************************************
 * include(s)
 *******************************************************************************************************************/
#include "PWM.h"
/*******************************************************************************************************************
 * shared global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * static global variable(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * ISR & static function prototype(s)
 *******************************************************************************************************************/

/*******************************************************************************************************************
 * shared function definition(s)
 *******************************************************************************************************************/

/*..................................................................................
 * name:                PWM_Init
 * description:         Function to initialize PWM module
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     - Frequency : Desired output PWM signal frequency
						- Dutycycle : Desired output PWM signal dutycycle
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 *..................................................................................*/
 void PWM_Init(uint32_t Frequency , uint32_t Dutycycle)
 {

    /* enable PWM0 clock */
    SYSCTL_RCGCPWM_R |= 0x1;
    while(!(SYSCTL_PRPWM_R |= 0x1));


    /*
     * 1- Enable System Clock Divider
     * 2- divide by 4 -> for 16MHZ processor 16/4 = 4
     */
    SYSCTL_RCC_R |= SYSCTL_RCC_USEPWMDIV;
    SYSCTL_RCC_R |= SYSCTL_RCC_PWMDIV_4;


    /*
     * initialize the gpio
     */

    SYSCTL_RCGCGPIO_R |= 0x00000002;
    while(!(SYSCTL_PRGPIO_R |= 0x00000002));
    GPIO_PORTB_AFSEL_R |= 0x00000040;
    GPIO_PORTB_DEN_R |= 0x00000040;
    GPIO_PORTB_PCTL_R |= 0x04000000;



    PWM0_0_CTL_R  &= 0;
    /*
     * act zero -> low
     * act load -> low
     * act comp down -> high
     */
    PWM0_0_GENA_R |= 0x000000CA;

    PWM0_0_LOAD_R = ((Period * 4000) - 1);
    /*
     * calculate and set duty cycle
     */
    PWM0_0_CMPA_R |= ((DutyCycle * PWM0_0_LOAD_R) / 100) - 1;
    /*
     * start the timer
     */
    PWM0_0_CTL_R  |= 0x00000001;
    /*
     * enable
     */
    PWM0_ENABLE_R |= 0x00000001;
}

 
 /*..................................................................................
 * name:                PWM_SetDutycycle
 * description:         function to update output PWM signal dutycycle
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     - Dutycycle : Desired output PWM signal dutycycle
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 *..................................................................................*/
 void PWM_SetDutycycle(uint32_t Dutycycle)
 {
    /* Reset DutyCycle value */
    PWM0_0_CMPA_R = 0;
    PWM0_0_CMPA_R = ((DutyCycle * PWM0_0_LOAD_R) / 100) - 1;
}
 
 /*..................................................................................
 * name:                PWM_Deinit
 * description:         Function to deinitialize PWM module
 * sync/async:          synchronous
 * reentrancy:          reentrant
 * parameters (in):     none
 * parameters (in/out): none
 * parameters (out):    none
 * return:              none
 *..................................................................................*/
 void PWM_Deinit(void)
 {
	 /* Disable PWM Clock */
	 SYSCTL_RCGCPWM_R &= 0xFFFFFFFE;
	 /* Reset PWM 0 timer */
	 PWM0_0_CTL_R  &= 0;
	 /* clear load value */
	 PWM0_0_LOAD_R = 0;
	 /* clear compare value */
	 PWM0_0_CMPA_R = 0
	 /* PWM 0 disable */
	 PWM0_ENABLE_R &= 0;
 }
 
 
/*******************************************************************************************************************
 * ISR & static function definition(s)
 *******************************************************************************************************************/
