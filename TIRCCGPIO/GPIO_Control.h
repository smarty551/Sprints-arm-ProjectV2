/*
 * GPIO_Control.h
 *
 *  Created on: Oct 1, 2019
 *      Author: smart
 */

#ifndef GPIO_CONTROL_H_
#define GPIO_CONTROL_H_
#include "tm4c123gh6pm.h"
typedef struct
{
  uint32_t Pin;       /* Specifies the GPIO pins to be configured.*/

  uint32_t Mode;      /* Specifies the operating mode for the selected pins.*/

  uint32_t Pull;      /* Specifies the Pull-up or Pull-Down activation for the selected pins.*/

  uint32_t DriveStrength;

} GPIO_InitTypeDef;

#define GPIO_PIN_0              0x00000001  /* GPIO pin 0 */
#define GPIO_PIN_1              0x00000002  /* GPIO pin 1 */
#define GPIO_PIN_2              0x00000004  /* GPIO pin 2 */
#define GPIO_PIN_3              0x00000008  /* GPIO pin 3 */
#define GPIO_PIN_4              0x00000010  /* GPIO pin 4 */
#define GPIO_PIN_5              0x00000020  /* GPIO pin 5 */
#define GPIO_PIN_6              0x00000040  /* GPIO pin 6 */
#define GPIO_PIN_7              0x00000080  /* GPIO pin 7 */

#define GPIO_STRENGTH_2MA       0x00000001  /* 2mA drive strength */
#define GPIO_STRENGTH_4MA       0x00000002  /* 4mA drive strength */
#define GPIO_STRENGTH_6MA       0x00000065  /* 6mA drive strength */
#define GPIO_STRENGTH_8MA       0x00000066  /* 8mA drive strength */




#endif /* GPIO_CONTROL_H_ */
