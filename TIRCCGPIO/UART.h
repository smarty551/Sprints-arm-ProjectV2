/*
 * UART.h
 *
 *  Created on: Oct 2, 2019
 *      Author: Hossam-PC
 */

#ifndef UART_H_
#define UART_H_

/**************************************************************************
 *                      Included Libraries
 **************************************************************************/
#include "tm4c123gh6pm.h"
#include "RCC_Control.h"

void UART0_Init(void);
void UART1_Init(void);

void UART0_Int_Init(void);

void UART0Tx(char c);
char UART0Rx(void);

char UART1Rx(void);
void UART1Tx(char c);

void Enable_CLK_UART0(void);
void Enable_CLK_UART1(void);

void Enable_Int(void);
void intb(void);
void global(void);
#endif /* UART_H_ */
