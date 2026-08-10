#include <reg51.h>
sbit SDA = P1^0;
sbit SCL = P1^1;
void I2C_Delay(void) {
unsigned char i; 
for(i = 0; i < 10; i++); }
unsigned char I2C_ReadByte(bit ack) {
    unsigned char i, dat = 0;
    SDA = 1;   
    for (i = 0; i < 8; i++) {
        SCL = 1; I2C_Delay();
        dat <<= 1;
        if (SDA) dat |= 0x01;
        SCL = 0; I2C_Delay();
    }
    SDA = ack ? 0 : 1;   
    SCL = 1; I2C_Delay();
    SCL = 0;
    return dat;
}
void main(void) {
    unsigned char received;
    received = I2C_ReadByte(0);  
    while(1);
}