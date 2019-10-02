/*
 * common_macros.h
 *
 *  Created on: Oct 2, 2019
 *      Author: Taher
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/* BIT MACROS */
#define SET_BIT(REGISTER, BIT)      ((REGISTER) = (REGISTER) | (1 << BIT))
#define CLEAR_BIT(REGISTER, BIT)    ((REGISTER) = (REGISTER) & (~(1 << BIT)))
#define GET_BIT(REGISTER, BIT)      ((REGISTER & (1 << BIT)) >> BIT)
#define TOGGLE_BIT(REGISTER, BIT)   ((REGISTER) = (REGISTER) ^ (1 << BIT))

/* PORT MACROS */
#define WRITE_PORT(REGISTER, VALUE)     ((REGISTER) = (VALUE))
#define READ_PORT(RGISTER)              (REGISTER)





#endif /* COMMON_MACROS_H_ */
