#include <reg51.h>
sbit BTN_INC = P3^0;
sbit BTN_DEC = P3^1;
void delay(unsigned int t)
{
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 100; j++);
}
void DAC_Write(unsigned char value)
{
    P1 = value;
}
void main(void)
{
    unsigned char dac_value = 0;
    P1 = 0x00;
    BTN_INC = 1;   
    BTN_DEC = 1;
    DAC_Write(dac_value);
    while (1)
    {
        if (BTN_INC == 0)          
        {
            delay(20);              
            if (BTN_INC == 0)
            {
                if (dac_value < 255)
                    dac_value++;
                DAC_Write(dac_value);
                while (BTN_INC == 0);  
            }
        }
        if (BTN_DEC == 0)        
        {
            delay(20);
            if (BTN_DEC == 0)
            {
                if (dac_value > 0)
                    dac_value--;
                DAC_Write(dac_value);
                while (BTN_DEC == 0);   
            }
        }
    }
}