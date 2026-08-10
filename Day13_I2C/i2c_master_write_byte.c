#include <reg51.h>
sbit SDA = P1^0;
sbit SCL = P1^1;
void I2C_Delay(void) {
unsigned char i; for(i = 0; i < 10; i++);
}
bit I2C_WriteByte(unsigned char dat) {
    unsigned char i;
    bit ack;
    for (i = 0; i < 8; i++) {
        SDA = (dat & 0x80) ? 1 : 0;   
        dat <<= 1;
        SCL = 1; I2C_Delay();
        SCL = 0; I2C_Delay();
    }
    SDA = 1;              
    SCL = 1; I2C_Delay();
    ack = SDA;             
    SCL = 0;
    return ack;
}
void main(void) {
    bit result;
    result = I2C_WriteByte(0xA0);  
    while(1);
}