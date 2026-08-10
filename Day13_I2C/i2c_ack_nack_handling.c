#include <reg51.h>
sbit SDA = P1^0;
sbit SCL = P1^1;
void I2C_Delay(void){
unsigned char i;
for(i=0;i<10;i++);}
void I2C_Start(void){
SDA=1;
SCL=1;
I2C_Delay();
SDA=0;
I2C_Delay();
SCL=0;}
void I2C_Stop(void){
SDA=0;
SCL=1;
I2C_Delay();
SDA=1;
I2C_Delay();}
bit I2C_WriteByte(unsigned char dat){
    unsigned char i; bit ack;
    for(i=0;i<8;i++){
		SDA=(dat&0x80)?1:0;
		dat<<=1; 
		SCL=1;
		I2C_Delay();
		SCL=0;
		I2C_Delay();}
    SDA=1; 
		SCL=1;
		I2C_Delay(); 
		ack=SDA; 
		SCL=0;
    return ack;
}
bit CheckSlavePresence(unsigned char devAddr) {
    bit ack;
    I2C_Start();
    ack = I2C_WriteByte(devAddr);
    I2C_Stop();
    return ack;
}
sbit LED = P2^0;
void main(void) {
    if (CheckSlavePresence(0xA0) == 0) {
        LED = 1;   
    } else {
        LED = 0;   
    }
    while(1);
}