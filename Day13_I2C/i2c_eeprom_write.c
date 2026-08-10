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

void EEPROM_WriteByte(unsigned char devAddr, unsigned char memAddr, unsigned char dat) {
    I2C_Start();
    I2C_WriteByte(devAddr);
    I2C_WriteByte(memAddr);
    I2C_WriteByte(dat);      
    I2C_Stop();
}

void main(void) {
    EEPROM_WriteByte(0xA0, 0x05, 0x7F);
    while(1);
}