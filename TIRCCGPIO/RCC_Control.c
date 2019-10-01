/*
 * RCC_Control.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Samir Ibrahim
 */

#include "tm4c123gh6pm.h"
#include "RCC_Control.h"
void RCC_EnableCLK (EnumRcc_EnConfigType RCC_Selected)
{
    switch (RCC_Selected)
    {
    /*GPIO clock enable*/
    case RCC_GPIOA_EN :
    {
        SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R0);
    }
    break;
    case RCC_GPIOB_EN :
    {
        SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R1);
    }
    break;

    case RCC_GPIOC_EN:
    {
        SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R2);
    }
    break;

    case RCC_GPIOD_EN :
    {
        SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R3);
    }
    break;

    case RCC_GPIOE_EN :
    {
        SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R4);
    }
    break;

    case RCC_GPIOF_EN :
    {
        SYSCTL_RCGCGPIO_R |= (SYSCTL_RCGCGPIO_R5);
    }
    break;
    /*PWM clock enable*/
    case RCC_PWM0_EN :
    {
        SYSCTL_RCGCPWM_R |= (SYSCTL_RCGCPWM_R0);
    }
    break;

    case RCC_PWM1_EN :
    {
        SYSCTL_RCGCPWM_R |= (SYSCTL_RCGCPWM_R1);
    }
    break;
    /*I2C clock enable*/
    case RCC_I2C0_EN :
    {
        SYSCTL_RCGCI2C_R |= (SYSCTL_RCGCI2C_R0);
    }
    break;

    case RCC_I2C1_EN :
    {
        SYSCTL_RCGCI2C_R |= (SYSCTL_RCGCI2C_R1);
    }
    break;

    case RCC_I2C2_EN :
    {
        SYSCTL_RCGCI2C_R |= (SYSCTL_RCGCI2C_R2);
    }
    break;

    case RCC_I2C3_EN :
    {
        SYSCTL_RCGCI2C_R |= (SYSCTL_RCGCI2C_R3);
    }
    break;
    /*Timer clock enable*/
    case RCC_TIMER0_EN :
    {
        SYSCTL_PRTIMER_R |= (SYSCTL_PRTIMER_R0);
    }
    break;

    case RCC_TIMER1_EN :
    {
        SYSCTL_PRTIMER_R |= (SYSCTL_PRTIMER_R1);
    }
    break;

    case RCC_TIMER2_EN :
    {
        SYSCTL_PRTIMER_R |= (SYSCTL_PRTIMER_R2);
    }
    break;

    case RCC_TIMER3_EN :
    {
        SYSCTL_PRTIMER_R |= (SYSCTL_PRTIMER_R3);
    }
    break;

    case RCC_TIMER4_EN :
    {
        SYSCTL_PRTIMER_R |= (SYSCTL_PRTIMER_R4);
    }
    break;

    case RCC_TIMER5_EN :
    {
        SYSCTL_PRTIMER_R |= (SYSCTL_PRTIMER_R5);
    }
    break;
    /*UART clock enable*/

    case RCC_UART0_EN :
    {
        SYSCTL_PRUART_R |= (SYSCTL_PRUART_R0);
    }
    break;

    case RCC_UART1_EN :
    {
        SYSCTL_PRUART_R |= (SYSCTL_PRUART_R1);
    }
    break;

    case RCC_UART2_EN :
    {
        SYSCTL_PRUART_R |= (SYSCTL_PRUART_R2);
    }
    break;

    case RCC_UART3_EN :
    {
        SYSCTL_PRUART_R |= (SYSCTL_PRUART_R3);
    }
    break;

    case RCC_UART4_EN :
    {
        SYSCTL_PRUART_R |= (SYSCTL_PRUART_R4);
    }
    break;

    case RCC_UART5_EN :
    {
        SYSCTL_PRUART_R |= (SYSCTL_PRUART_R5);
    }
    break;

    case RCC_UART6_EN :
    {
        SYSCTL_PRUART_R |= (SYSCTL_PRUART_R6);
    }
    break;

    case RCC_UART7_EN :
    {
        SYSCTL_PRUART_R |= (SYSCTL_PRUART_R7);
    }
    break;
    default :
    {
        /*Do nothing*/
    }
    break;
    }
}
