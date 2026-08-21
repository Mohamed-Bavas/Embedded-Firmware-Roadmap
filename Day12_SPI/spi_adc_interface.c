#include <reg51.h>
unsigned char SPI_Read();
unsigned int Read_ADC()
{
    unsigned int value;
    value=SPI_Read();
    return value;
}
void main()
{
    unsigned int adc;
    adc=Read_ADC();
    while(1);
}
unsigned char SPI_Read()
{
    return 120;
}