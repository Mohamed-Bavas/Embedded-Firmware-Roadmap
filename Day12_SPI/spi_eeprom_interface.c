#include <reg51.h>

void SPI_Send(unsigned char);

void EEPROM_Write(unsigned char address,unsigned char ch)
{
    SPI_Send(0x06);      

    SPI_Send(0x02);      

    SPI_Send(address);

    SPI_Send(ch);
}

void main()
{
    EEPROM_Write(0x10,0x55);

    while(1);
}

void SPI_Send(unsigned char d)
{
}