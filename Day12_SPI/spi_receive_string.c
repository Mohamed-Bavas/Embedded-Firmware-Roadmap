#include <reg51.h>
unsigned char SPI_Read();
void main()
{
    char str[10];
    char i;
    for(i=0;i<5;i++)
    {
        str[i]=SPI_Read();
    }
    str[5]='\0';
    while(1);
}
unsigned char SPI_Read()
{
    return 'A';
}