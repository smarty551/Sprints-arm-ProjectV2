/*
 * I2C.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ali Shawky
 */


#include <I2C_3.h>


void I2C_Init(void)
{
    /*GPIO initialization*/
    RCC_EnableCLK(RCC_GPIOD_EN);
//    /SYSCTL_RCGCGPIO_R |= 0x03;
    GPIO_PORTD_AFSEL_R |= 0x03;
    GPIO_PORTD_DEN_R |= 0x03;
    GPIO_PORTD_ODR_R |= 0x02 ;
    GPIO_PORTD_PCTL_R|= GPIO_PCTL_PD0_I2C3SCL ;

    /*I2C module initialization*/
    /*enabling I2C module*/
    RCC_EnableCLK (RCC_I2C3_EN);
    /*selecting I2C mode*/
#if I2C_3_NODE_TYPE == MASTER
    I2C3_MCR_R |= 0x10 ;
#elif I2C_3_NODE_TYPE == SLAVE
    I2C3_MCR_R |= 0x20;
#endif
    /*initializing I2C module slave address*/
    I2C3_SOAR_R |= I2C_1_NODE_SLAVE_ADDRESS ;
    /*setting I2C clock*/
    I2C3_MTPR_R |=  CLK_100kHZ;

}


void I2C_SlaveAdress(char adrr)
{
    /*select the desired slave*/
    I2C3_MSA_R |= (adrr << 1);
}


void I2C_Operation(char op)
{
    /*select the operation*/
    I2C3_MSA_R |= op;
}


void I2C_SendFrame(void)
{
    /*enable beginning the frame*/
    I2C3_MCS_R |= 0x01;
}


void I2C_StartCondition(void)
{
    /*enable start condition to be sent before the last data byte*/
    I2C3_MCS_R |= 0x02;
}


void I2C_StopCondition(void)
{
    /*enable stop condition to be sent after the last data byte*/
    I2C3_MCS_R |= 0x04;
}


static char I2C_Check_BusAvailable(void)
{
    /*return the status of the I2C BUS idle or not*/
    return ((I2C3_MCS_R) & (1 << 6));
}


static char I2C_Check_NodeIdle(void)
{
    /*return the status of the I2C node idle or not*/
    return ((I2C3_MCS_R) & (1 << 0));
}


void I2C_WriteByte(char data, char slave_addr, char op)
{
    /*write the slave address*/
    I2C_SlaveAdress(slave_addr);
    /*write the operation*/
    I2C_Operation(op);
    /*write data on I2C data register*/
    I2C3_MDR_R = data;
    /*check if the I2C bus is idle*/
   // while(( I2C_Check_BusAvailable() ));

    /*beginning the frame*/
    I2C_SendFrame();
    /*send start condition*/
    I2C_StartCondition();
    /*send stop condition*/
    I2C_StopCondition();

    /*check if the frame is sent and the I2C node is idle*/
   // while(( I2C_Check_NodeIdle() ));

}


char I2C_ReadByte(char slave_addr)
{
    /*write the slave address*/
     I2C_SlaveAdress(slave_addr);
     /*write the operation*/
     I2C_Operation(READ_OPERATION);
     /*check if the I2C bus is idle*/
     while(( I2C_Check_BusAvailable() ));

     /*beginning the frame*/
     I2C_SendFrame();
     /*send start condition*/
     I2C_StartCondition();
     /*send stop condition*/
     I2C_StopCondition();

     /*check if the frame is sent and the I2C node is idle*/
     while(( I2C_Check_NodeIdle() ));

     return I2C3_MDR_R;
}


void I2C_LoopBack_Test(void)
{
    I2C3_MCR_R |= 0x01;
}


