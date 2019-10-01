
#include "tm4c123gh6pm.h"
#include "RCC_Control.h"
/**
 * main.c
 */
void Delay(long int x)
{
    volatile long int Loop;
    for(Loop = 0; Loop < x; Loop++);
    }
int main(void)
{
    RCC_EnableCLK(RCC_GPIOF_EN);

    /*clear Alternate function*/
    GPIO_PORTF_AFSEL_R &= ~(0x02);
    /*Set the direction to putput*/
    GPIO_PORTF_DIR_R |= (0x02);
    /*Disable open drain*/
    GPIO_PORTF_ODR_R &= ~(0x02);
    /*enable the Digital function*/
    GPIO_PORTF_DEN_R |= 0x02;
    /*Select pull down resistor*/
    GPIO_PORTF_PDR_R |= 0x02;
    /*select 2mA Current*/
    GPIO_PORTF_DR2R_R |= 0x02;

    while(1)
        {
            /*Set the data*/
            GPIO_PORTF_DATA_R |= 0x02;
            Delay(500000);
            /*clear the Data*/
            GPIO_PORTF_DATA_R &= ~(0x02);
            Delay(500000);

        }

}
