#include <reg51.h>

void LCD_String(char *);
unsigned char SPI_Read();

void main()
{
    char value;

    value=SPI_Read();

    LCD_String("SPI DATA");

    while(1);
}

unsigned char SPI_Read()
{
    return 'A';
}

void LCD_String(char *s)
{
}