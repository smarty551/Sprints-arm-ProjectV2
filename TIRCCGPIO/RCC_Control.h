/*
 * RCC_Control.h
 *
 *  Created on: Oct 1, 2019
 *      Author: smart
 */

#ifndef RCC_CONTROL_H_
#define RCC_CONTROL_H_

typedef enum
{
    RCC_GPIOA_EN=0,
    RCC_GPIOB_EN,
    RCC_GPIOC_EN,
    RCC_GPIOD_EN,
    RCC_GPIOE_EN,
    RCC_GPIOF_EN,
    RCC_UART0_EN,
    RCC_UART1_EN,
    RCC_UART2_EN,
    RCC_UART3_EN,
    RCC_UART4_EN,
    RCC_UART5_EN,
    RCC_UART6_EN,
    RCC_UART7_EN,
    RCC_TIMER0_EN,
    RCC_TIMER1_EN,
    RCC_TIMER2_EN,
    RCC_TIMER3_EN,
    RCC_TIMER4_EN,
    RCC_TIMER5_EN,
    RCC_I2C0_EN,
    RCC_I2C1_EN,
    RCC_I2C2_EN,
    RCC_I2C3_EN,
    RCC_PWM0_EN,
    RCC_PWM1_EN,
}EnumRcc_EnConfigType;
void RCC_EnableCLK (EnumRcc_EnConfigType RCC_Selected);
#endif /* RCC_CONTROL_H_ */
