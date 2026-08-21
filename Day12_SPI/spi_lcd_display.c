#include <reg51.h>
sbit SPI_SCK  = P1^0;
sbit SPI_MOSI = P1^1;
sbit SPI_MISO = P1^2;
sbit SPI_CS   = P1^3;
sbit LCD_RS = P3^0;
sbit LCD_EN = P3^1;
void delay_ms(unsigned int ms);
void delay_ms(unsigned int ms)
{
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}
void LCD_Enable()
{
    LCD_EN = 1;
    delay_ms(1);
    LCD_EN = 0;
    delay_ms(1);
}
void LCD_Command(unsigned char cmd)
{
    LCD_RS = 0;
    P2 = cmd;
    LCD_Enable();
}
void LCD_Data(unsigned char dat)
{
    LCD_RS = 1;
    P2 = dat;
    LCD_Enable();
}
void LCD_String(char *str)
{
    while(*str)
    {
        LCD_Data(*str);
        str++;
    }
}
void LCD_Init()
{
    delay_ms(20);
    LCD_Command(0x38);
    LCD_Command(0x0C);
    LCD_Command(0x01);
    LCD_Command(0x06);
    LCD_Command(0x80);
}
void SPI_Init(void)
{
    SPI_SCK = 0;
    SPI_MOSI = 0;
    SPI_CS = 1;
}
unsigned char SPI_Transfer(unsigned char dat)
{
    unsigned char i;
    unsigned char received = 0;
    for(i = 0; i < 8; i++)
    {
        if(dat & 0x80)
            SPI_MOSI = 1;
        else
            SPI_MOSI = 0;
        dat= dat << 1;
        SPI_SCK = 1;
        delay_ms(1);
        received = received << 1;
        if(SPI_MISO)
            received |= 0x01;
        SPI_SCK = 0;
        delay_ms(1);
    }
    return received;
}
unsigned char SPI_Read()
{
    unsigned char value;
    SPI_CS = 0;
    value = SPI_Transfer(0xFF);
    SPI_CS = 1;
    return value;
}
void main()
{
    unsigned char value;
    LCD_Init();
    SPI_Init();
    LCD_String("SPI DATA:");
    value = SPI_Read();
    LCD_Command(0xC0);
    LCD_Data(value);
    while(1);
}