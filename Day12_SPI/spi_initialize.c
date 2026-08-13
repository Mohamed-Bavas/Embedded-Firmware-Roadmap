#include <reg51.h>
sbit MOSI = P1^0;
sbit MISO = P1^1;
sbit SCK  = P1^2;
sbit SS   = P1^3;
void SPI_Init()
{
    MOSI = 0;
    SCK = 0;
    SS = 1;
}
void main()
{
    SPI_Init();
    while(1);
}