#include <reg51.h>

sbit MOSI=P1^0;
sbit MISO=P1^1;
sbit SCK=P1^2;
sbit SS=P1^3;

unsigned char SPI_Read()
{
    char i;
    unsigned char ch=0;

    SS=0;

    for(i=0;i<8;i++)
    {
        MOSI=0;

        SCK=1;

        ch<<=1;

        if(MISO)
            ch|=1;

        SCK=0;
    }

    SS=1;

    return ch;
}

void main()
{
    unsigned char value;

    value=SPI_Read();

    while(1);
}