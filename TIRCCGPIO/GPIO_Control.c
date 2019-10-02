/*
 * GPIO_Control.c
 *
 *  Created on: Oct 1, 2019
 *      Author: Samir Ibrahim
 */
#include "GPIO_Control.h"

#define DATA_REG_OFFSET                             (0x3FCU)


void GPIO_PinConfig (uint32_t Port_Base, GPIO_InitTypeDef * GPIO_InitPtr)
{
    switch(Port_Base)
    {
    case GPIO_PORTA_BASE :
    {
        GPIO_PORTA_AFSEL_R &= ~(GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Mode)
        {
        case PIN_OUTPUT:
        {
            /*Set the direction to output*/
            GPIO_PORTA_DIR_R |= (GPIO_InitPtr->Pin);
        }
        break;

        case PIN_INPUT:
        {
            /*Set the direction to input*/
            GPIO_PORTA_DIR_R &= ~(GPIO_InitPtr->Pin);
        }
        break;
        default:
            break;
        }

        switch (GPIO_InitPtr->OpenDrain) {
        case OPENDRAIN_ENABLED:
            /*enable open drain*/
            GPIO_PORTA_ODR_R |= (GPIO_InitPtr->Pin);
            break;
        case OPENDRAIN_DISABLED:
            /*Disable open drain*/
            GPIO_PORTA_ODR_R &= ~(GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        /*enable the Digital function*/
        GPIO_PORTA_DEN_R |= (GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Pull) {
        case PULLUP:
            /*Select pull down resistor*/
            GPIO_PORTA_PUR_R |= (GPIO_InitPtr->Pin);
            break;
        case PULLDOWN:
            /*Select pull down resistor*/
            GPIO_PORTA_PDR_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        switch (GPIO_InitPtr->DriveStrength) {
        case GPIO_STRENGTH_2MA:
            /*select 2mA Current*/
            GPIO_PORTA_DR2R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_4MA:
            /*select 4mA Current*/
            GPIO_PORTA_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_6MA:
            /*select 6mA Current*/
            GPIO_PORTA_DR2R_R |= (GPIO_InitPtr->Pin);
            GPIO_PORTA_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_8MA:
            /*select 8mA Current*/
            GPIO_PORTA_DR8R_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }
    }
    break;
    case GPIO_PORTB_BASE :
    {
        GPIO_PORTB_AFSEL_R &= ~(GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Mode)
        {
        case PIN_OUTPUT:
        {
            /*Set the direction to output*/
            GPIO_PORTB_DIR_R |= (GPIO_InitPtr->Pin);
        }
        break;

        case PIN_INPUT:
        {
            /*Set the direction to input*/
            GPIO_PORTB_DIR_R &= ~(GPIO_InitPtr->Pin);
        }
        break;
        default:
            break;
        }

        switch (GPIO_InitPtr->OpenDrain) {
        case OPENDRAIN_ENABLED:
            /*enable open drain*/
            GPIO_PORTB_ODR_R |= (GPIO_InitPtr->Pin);
            break;
        case OPENDRAIN_DISABLED:
            /*Disable open drain*/
            GPIO_PORTB_ODR_R &= ~(GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        /*enable the Digital function*/
        GPIO_PORTB_DEN_R |= (GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Pull) {
        case PULLUP:
            /*Select pull down resistor*/
            GPIO_PORTB_PUR_R |= (GPIO_InitPtr->Pin);
            break;
        case PULLDOWN:
            /*Select pull down resistor*/
            GPIO_PORTB_PDR_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        switch (GPIO_InitPtr->DriveStrength) {
        case GPIO_STRENGTH_2MA:
            /*select 2mA Current*/
            GPIO_PORTB_DR2R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_4MA:
            /*select 4mA Current*/
            GPIO_PORTB_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_6MA:
            /*select 6mA Current*/
            GPIO_PORTB_DR2R_R |= (GPIO_InitPtr->Pin);
            GPIO_PORTB_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_8MA:
            /*select 8mA Current*/
            GPIO_PORTB_DR8R_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }
    }
    break;
    case GPIO_PORTC_BASE :
    {
        GPIO_PORTC_AFSEL_R &= ~(GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Mode)
        {
        case PIN_OUTPUT:
        {
            /*Set the direction to output*/
            GPIO_PORTC_DIR_R |= (GPIO_InitPtr->Pin);
        }
        break;

        case PIN_INPUT:
        {
            /*Set the direction to input*/
            GPIO_PORTC_DIR_R &= ~(GPIO_InitPtr->Pin);
        }
        break;
        default:
            break;
        }

        switch (GPIO_InitPtr->OpenDrain) {
        case OPENDRAIN_ENABLED:
            /*enable open drain*/
            GPIO_PORTC_ODR_R |= (GPIO_InitPtr->Pin);
            break;
        case OPENDRAIN_DISABLED:
            /*Disable open drain*/
            GPIO_PORTC_ODR_R &= ~(GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        /*enable the Digital function*/
        GPIO_PORTC_DEN_R |= (GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Pull) {
        case PULLUP:
            /*Select pull down resistor*/
            GPIO_PORTC_PUR_R |= (GPIO_InitPtr->Pin);
            break;
        case PULLDOWN:
            /*Select pull down resistor*/
            GPIO_PORTC_PDR_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        switch (GPIO_InitPtr->DriveStrength) {
        case GPIO_STRENGTH_2MA:
            /*select 2mA Current*/
            GPIO_PORTC_DR2R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_4MA:
            /*select 4mA Current*/
            GPIO_PORTC_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_6MA:
            /*select 6mA Current*/
            GPIO_PORTC_DR2R_R |= (GPIO_InitPtr->Pin);
            GPIO_PORTC_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_8MA:
            /*select 8mA Current*/
            GPIO_PORTC_DR8R_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }
    }
    break;
    case GPIO_PORTD_BASE :
    {

        GPIO_PORTD_AFSEL_R &= ~(GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Mode)
        {
        case PIN_OUTPUT:
        {
            /*Set the direction to output*/
            GPIO_PORTD_DIR_R |= (GPIO_InitPtr->Pin);
        }
        break;

        case PIN_INPUT:
        {
            /*Set the direction to input*/
            GPIO_PORTD_DIR_R &= ~(GPIO_InitPtr->Pin);
        }
        break;
        default:
            break;
        }

        switch (GPIO_InitPtr->OpenDrain) {
        case OPENDRAIN_ENABLED:
            /*enable open drain*/
            GPIO_PORTD_ODR_R |= (GPIO_InitPtr->Pin);
            break;
        case OPENDRAIN_DISABLED:
            /*Disable open drain*/
            GPIO_PORTD_ODR_R &= ~(GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        /*enable the Digital function*/
        GPIO_PORTD_DEN_R |= (GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Pull) {
        case PULLUP:
            /*Select pull down resistor*/
            GPIO_PORTD_PUR_R |= (GPIO_InitPtr->Pin);
            break;
        case PULLDOWN:
            /*Select pull down resistor*/
            GPIO_PORTD_PDR_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        switch (GPIO_InitPtr->DriveStrength) {
        case GPIO_STRENGTH_2MA:
            /*select 2mA Current*/
            GPIO_PORTD_DR2R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_4MA:
            /*select 4mA Current*/
            GPIO_PORTD_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_6MA:
            /*select 6mA Current*/
            GPIO_PORTD_DR2R_R |= (GPIO_InitPtr->Pin);
            GPIO_PORTD_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_8MA:
            /*select 8mA Current*/
            GPIO_PORTD_DR8R_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }
    }
    break;
    case GPIO_PORTE_BASE :
    {
        GPIO_PORTE_AFSEL_R &= ~(GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Mode)
        {
        case PIN_OUTPUT:
        {
            /*Set the direction to output*/
            GPIO_PORTE_DIR_R |= (GPIO_InitPtr->Pin);
        }
        break;

        case PIN_INPUT:
        {
            /*Set the direction to input*/
            GPIO_PORTE_DIR_R &= ~(GPIO_InitPtr->Pin);
        }
        break;
        default:
            break;
        }

        switch (GPIO_InitPtr->OpenDrain) {
        case OPENDRAIN_ENABLED:
            /*enable open drain*/
            GPIO_PORTE_ODR_R |= (GPIO_InitPtr->Pin);
            break;
        case OPENDRAIN_DISABLED:
            /*Disable open drain*/
            GPIO_PORTE_ODR_R &= ~(GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        /*enable the Digital function*/
        GPIO_PORTE_DEN_R |= (GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Pull) {
        case PULLUP:
            /*Select pull down resistor*/
            GPIO_PORTE_PUR_R |= (GPIO_InitPtr->Pin);
            break;
        case PULLDOWN:
            /*Select pull down resistor*/
            GPIO_PORTE_PDR_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        switch (GPIO_InitPtr->DriveStrength) {
        case GPIO_STRENGTH_2MA:
            /*select 2mA Current*/
            GPIO_PORTE_DR2R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_4MA:
            /*select 4mA Current*/
            GPIO_PORTE_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_6MA:
            /*select 6mA Current*/
            GPIO_PORTE_DR2R_R |= (GPIO_InitPtr->Pin);
            GPIO_PORTE_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_8MA:
            /*select 8mA Current*/
            GPIO_PORTE_DR8R_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }
    }
    break;

    case GPIO_PORTF_BASE :
    {
        GPIO_PORTF_AFSEL_R &= ~(GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Mode)
        {
        case PIN_OUTPUT:
        {
            /*Set the direction to output*/
            GPIO_PORTF_DIR_R |= (GPIO_InitPtr->Pin);
        }
        break;

        case PIN_INPUT:
        {
            /*Set the direction to input*/
            GPIO_PORTF_DIR_R &= ~(GPIO_InitPtr->Pin);
        }
        break;
        default:
            break;
        }

        switch (GPIO_InitPtr->OpenDrain) {
        case OPENDRAIN_ENABLED:
            /*enable open drain*/
            GPIO_PORTF_ODR_R |= (GPIO_InitPtr->Pin);
            break;
        case OPENDRAIN_DISABLED:
            /*Disable open drain*/
            GPIO_PORTF_ODR_R &= ~(GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        /*enable the Digital function*/
        GPIO_PORTF_DEN_R |= (GPIO_InitPtr->Pin);

        switch (GPIO_InitPtr->Pull) {
        case PULLUP:
            /*Select pull down resistor*/
            GPIO_PORTF_PUR_R |= (GPIO_InitPtr->Pin);
            break;
        case PULLDOWN:
            /*Select pull down resistor*/
            GPIO_PORTF_PDR_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }

        switch (GPIO_InitPtr->DriveStrength) {
        case GPIO_STRENGTH_2MA:
            /*select 2mA Current*/
            GPIO_PORTF_DR2R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_4MA:
            /*select 4mA Current*/
            GPIO_PORTF_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_6MA:
            /*select 6mA Current*/
            GPIO_PORTF_DR2R_R |= (GPIO_InitPtr->Pin);
            GPIO_PORTF_DR4R_R |= (GPIO_InitPtr->Pin);
            break;
        case GPIO_STRENGTH_8MA:
            /*select 8mA Current*/
            GPIO_PORTF_DR8R_R |= (GPIO_InitPtr->Pin);
            break;
        default:
            break;
        }
    }
    break;
    }
}

void GPIO_PinWrite(uint32_t Port_Base, uint32_t PinToEdit, uint32_t PinState)
{
    Port_Base += (DATA_REG_OFFSET);
    switch (PinState)
    {
    case SET_HIGH :
        (*((volatile uint32_t *)Port_Base)) |= PinToEdit;
        break;
    case SET_LOW :
        (*((volatile uint32_t *)Port_Base)) &= ~(PinToEdit);
        break;
    }

}


uint32_t GPIO_PinRead (uint32_t Port_Base, uint32_t PinToRead)
{
    Port_Base += (DATA_REG_OFFSET);
    return ((*((volatile uint32_t *)Port_Base)) & PinToRead);
}
