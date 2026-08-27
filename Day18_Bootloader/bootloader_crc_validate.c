#include <reg51.h>
unsigned long CRC32(unsigned char *dat, unsigned int length)
{
    unsigned long crc = 0xFFFFFFFF;
    unsigned int i;
    unsigned char j;
    for(i=0;i<length;i++)
    {
        crc^=dat[i];

        for(j=0;j<8;j++)
        {
            if(crc&1)
                crc=(crc >> 1)^0xEDB88320;
            else
                crc>>=1;
        }
    }
    return crc^0xFFFFFFFF;
}
void main()
{
    unsigned char firmware[]={0x10,0x20,0x30,0x40};
    unsigned long crc;
    crc=CRC32(firmware,sizeof(firmware));
    while(1);
}