#include <reg51.h>
sbit ALE   = P2^0;
sbit START = P2^1;
sbit EOC   = P2^2;
sbit OE    = P2^3;
void delay(unsigned int t)
{
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 120; j++);
}
void UART_Init(void)
{
    TMOD = 0x20;    
    TH1  = 0xFD;    
    SCON = 0x50;    
    TR1  = 1;      
}
void UART_TxChar(unsigned char ch)
{
    SBUF = ch;
    while (TI == 0);
    TI = 0;
}
void UART_TxString(unsigned char *str)
{
    while (*str != '\0')
    {
        UART_TxChar(*str);
        str++;
    }
}
void UART_TxNumber(unsigned int num)
{
    unsigned char buffer[4];
    unsigned char i = 0;
    if (num == 0)
    {
        UART_TxChar('0');
        return;
    }
    while (num > 0)
    {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }
    while (i > 0)
    {
        UART_TxChar(buffer[--i]);
    }
}
unsigned char ADC_Read(void)
{
    unsigned char value;
    P0 = 0xFF;
    ALE = 1;
    START = 1;
    delay(1);
    ALE = 0;
    START = 0;
    while (EOC == 0);
    OE = 1;
    delay(1);
    value = P0;
    OE = 0;
    return value;
}
void main(void)
{
    unsigned char adc_value;
    P0 = 0xFF;
    ALE = 0;
    START = 0;
    OE = 0;
    UART_Init();
    while (1)
    {
        adc_value = ADC_Read();
        UART_TxString("ADC Value: ");
        UART_TxNumber((unsigned int)adc_value);
        UART_TxString("\r\n");
        delay(300);
    }
}