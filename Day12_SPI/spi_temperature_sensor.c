#include <reg51.h>

unsigned char SPI_Read();

void main()
{
    unsigned char temp;

    temp=SPI_Read();

    while(1);
}

unsigned char SPI_Read()
{
    return 30;
}