#include <reg51.h>

void SPI_Send(unsigned char);

void SPI_SendString(char *str)
{
    while(*str)
    {
        SPI_Send(*str++);
    }
}

void main()
{
    SPI_SendString("HELLO");

    while(1);
}

void SPI_Send(unsigned char d)
{
     char i;

    SS=0;

    for(i=0;i<8;i++)
    {
        MOSI=(d&0x80)?1:0;

        SCK=1;
        delay();

        SCK=0;
        delay();

        d<<=1;
    }

    SS=1;
}