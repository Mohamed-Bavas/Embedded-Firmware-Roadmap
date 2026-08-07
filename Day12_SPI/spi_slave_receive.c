#include <reg51.h>

sbit MISO=P1^1;
sbit SCK=P1^2;

unsigned char SPI_Receive()
{
    char i;
    unsigned char ch=0;

    for(i=0;i<8;i++)
    {
        while(SCK==0);

        ch<<=1;

        if(MISO)
            ch|=1;

        while(SCK==1);
    }

    return ch;
}

void main()
{
    unsigned char ch;

    ch=SPI_Receive();

    while(1);
}