/*
 * I2C.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: Ali Shawky
 */

#ifndef I2C_3_H_
#define I2C_3_H_

/***************************
 * included files
 **************************/
#include "I2C_3_Cfg.h"
#include "tm4c123gh6pm .h"
#include "RCC_Control.h"

/***************************
 * configurations
 **************************/
#define MASTER 1
#define SLAVE 0

#define WRITE_OPERATION   0
#define READ_OPERATION    1

#define CLK_100kHZ 7
#define CLK_400kHZ 1

#define I2C_1_NODE_SLAVE_ADDRESS  0x03


/***************************
 * functions prototypes
 **************************/
void I2C_Init(void);

void I2C_SlaveAdress(char adrr);

void I2C_Operation(char op);

void I2C_SendFrame(void);

void I2C_StartCondition(void);

void I2C_StopCondition(void);

void I2C_WriteByte(char data, char slave_addr, char op);

char I2C_ReadByte(char slave_addr);

void I2C_LoopBack_Test(void);

#endif /* I2C_3_H_ */
