#include <reg51.h>
sbit MOSI=P1^0;
sbit SCK=P1^2;
sbit SS=P1^3;
void delay()
{
    int i;
    for(i=0;i<100;i++);
}
void SPI_Send(unsigned char ch)
{
    char i;
    SS=0;
    for(i=0;i<8;i++)
    {
        MOSI=(ch&0x80)?1:0;
        SCK=1;
        delay();
        SCK=0;
        delay();
        ch<<=1;
    }
    SS=1;
}
void main()
{
    SPI_Send('A');
    while(1);
}