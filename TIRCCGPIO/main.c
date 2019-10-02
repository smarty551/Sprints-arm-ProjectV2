
#include "tm4c123gh6pm.h"
#include "RCC_Control.h"
#include "GPIO_Control.h"
/**
 * main.c
 */
void pinnconfig (void);
void Delay(long int x)
{
    volatile long int Loop;
    for(Loop = 0; Loop < x; Loop++);
}
int main(void)
{
    RCC_EnableCLK(RCC_GPIOF_EN);
    RCC_EnableCLK(RCC_GPIOC_EN);

//

pinnconfig();
    while(1)
        {
        uint8_t te=GPIO_PinRead(GPIO_PORTC_BASE, GPIO_PIN_6);
        if (te==0)
        {
            /*Set the data*/
        GPIO_PinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,1);

            Delay(500000);
            /*clear the Data*/
            GPIO_PinWrite(GPIO_PORTF_BASE,GPIO_PIN_3,0);

            Delay(500000);

        }

        }
}
void pinnconfig (void)
{
    GPIO_InitTypeDef x;
    x.DriveStrength= GPIO_STRENGTH_2MA;
    x.Mode=PIN_OUTPUT;
    x.Pin= GPIO_PIN_3;
    x.OpenDrain=OPENDRAIN_DISABLED;
    x.Pull=PULLDOWN;

    GPIO_PinConfig(GPIO_PORTF_BASE,&x);
    x.Pin= GPIO_PIN_6;
    x.Mode=PIN_INPUT;
    GPIO_PinConfig(GPIO_PORTC_BASE,&x);
}
