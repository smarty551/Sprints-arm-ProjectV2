/*
 * UART.c
 *
 *  Created on: Oct 2, 2019
 *      Author: Hossam-PC
 */
/**************************************************************************
 *                      Included Libraries
 **************************************************************************/
#include "UART.h"
void UART0Tx(char c)
{
    while((UART0_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
    UART0_DR_R = c;    /* before giving it another byte */
}
char UART0Rx(void)
{
    char c ;
    while((UART1_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
     c = UART0_DR_R ;    /* before giving it another byte */
    return c;
}


void UART1Tx(char c)
{
    while((UART1_FR_R & 0x20) != 0); /* wait until Tx buffer not full */
    UART1_DR_R = c;    /* before giving it another byte */
}
char UART1Rx(void)
{
    char c ;
    while((UART1_FR_R & 0x10) != 0); /* wait until Tx buffer not full */
    c = UART1_DR_R;    /* before giving it another byte */
    return c;
}
void Enable_CLK_UART0(void)
{
    RCC_EnableCLK(RCC_UART0_EN);    /* provide clock to UART0 */
    RCC_EnableCLK(RCC_GPIOA_EN);    /* enable clock to PORTA */
}
void Enable_CLK_UART1(void)
{
    RCC_EnableCLK(RCC_UART1_EN);    /* provide clock to UART0 */
    RCC_EnableCLK(RCC_GPIOB_EN);    /* enable clock to PORTA */
}
void UART0_Init(void)
{
    /* UART0 initialization */
    UART0_CTL_R &= ~UART_CTL_UARTEN ;   /* disable UART0 */
    UART0_IBRD_R=104;    /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
    UART0_FBRD_R=11;    /* fraction part, see Example 4-4 */
    UART0_CC_R &=0X00;
    UART0_LCRH_R=(UART_LCRH_WLEN_8|UART_LCRH_FEN);  /* 8-bit, no parity, 1-stop bit, no FIFO */
    UART0_CTL_R |= (UART_CTL_UARTEN|UART_CTL_RXE|UART_CTL_TXE);     /* enable UART0, TXE, RXE */
    /* UART0 TX0 and RX0 use PA0 and PA1. Set them up. */
    GPIO_PORTA_DEN_R |= 0x03;   /* Make PA0 and PA1 as digital */
    GPIO_PORTA_AFSEL_R |=0x03;/* Use PA0,PA1 alternate function */
    GPIO_PORTA_PCTL_R |= (GPIO_PCTL_PA1_U0TX|GPIO_PCTL_PA0_U0RX);   /* configure PA0 and PA1 for UART */
}

void UART0_Int_Init(void)
{
    /* UART0 initialization */
    UART0_CTL_R &= ~UART_CTL_UARTEN ;   /* disable UART0 */

    UART0_IBRD_R=104;    /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */

    UART0_FBRD_R=11;    /* fraction part, see Example 4-4 */

    UART0_CC_R &=0X00;

    UART0_LCRH_R=(UART_LCRH_WLEN_8|UART_LCRH_FEN);  /* 8-bit, no parity, 1-stop bit, no FIFO */

    UART0_IM_R |= 0x0010;/* enable RX interrupt */
    UART0_CTL_R |= (UART_CTL_UARTEN|UART_CTL_RXE|UART_CTL_TXE);     /* enable UART0, TXE, RXE */
    /* UART0 TX0 and RX0 use PA0 and PA1. Set them up. */
    GPIO_PORTA_DEN_R |= 0x03;   /* Make PA0 and PA1 as digital */

    GPIO_PORTA_AFSEL_R |=0x03;/* Use PA0,PA1 alternate function */

    GPIO_PORTA_PCTL_R |= (GPIO_PCTL_PA1_U0TX|GPIO_PCTL_PA0_U0RX);   /* configure PA0 and PA1 for UART */
}
void Enable_Int(void)
{
      /* enable interrupt in NVIC and set priority to 6 */
      NVIC_EN0_R=0x00000020;
}
void UART1_Init(void)
{
    /* UART0 initialization */
    UART1_CTL_R &= ~UART_CTL_UARTEN ;   /* disable UART1 */
    UART1_IBRD_R=104;    /* 16MHz/16=1MHz, 1MHz/104=9600 baud rate */
    UART1_FBRD_R=11;    /* fraction part, see Example 4-4 */
    UART1_CC_R &=0X00;
    UART1_LCRH_R=(UART_LCRH_WLEN_8|UART_LCRH_FEN);  /* 8-bit, no parity, 1-stop bit, no FIFO */
    UART1_CTL_R |= (UART_CTL_UARTEN|UART_CTL_RXE|UART_CTL_TXE);     /* enable UART0, TXE, RXE */
    /* UART1 TX1 and RX1 use PB0 and PB1. Set them up. */
    GPIO_PORTB_DEN_R |= 0x03;   /* Make PB0 and PA1 as digital */
    GPIO_PORTB_AFSEL_R |=0x03;/* Use PB0,PB1 alternate function */
    GPIO_PORTB_PCTL_R |= (GPIO_PCTL_PB0_U1RX|GPIO_PCTL_PB1_U1TX);   /* configure PA0 and PA1 for UART */
}

void intb(void)
{
  volatile int readback;
  char c;
  if (UART0_MIS_R & 0x0010)
  {
      c = UART0_DR_R;            /* read the received data */
      GPIO_PORTF_DATA_R = c << 1;     /* shift left and write it to LEDs */
      UART0_ICR_R = 0x0010;      /* clear Rx interrupt flag */
      readback = UART0_ICR_R;    /* a read to force clearing of interrupt flag*/
      UART0_DR_R=c;
  }
  else
  {
      /* should not get here. But if it does, */
      UART0_ICR_R= UART0_MIS_R;  /* clear all interrupt flags */
      readback = UART0_ICR_R;    /* a read to force clearing of interrupt flag*/
  }
}
void global(void)
{
    __asm("    mrs     r0, PRIMASK\n"
              "    cpsie   i\n"
              "    bx      lr\n");
}
