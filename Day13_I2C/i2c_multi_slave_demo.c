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
    unsigned char i; 
	  bit ack;
    for(i=0;i<8;i++){SDA=(dat&0x80)?1:0;
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
unsigned char I2C_ReadByte(bit ack){
    unsigned char i, dat=0;
    SDA=1;
    for(i=0;i<8;i++){
        SCL=1; I2C_Delay();
        dat<<=1;
        if(SDA) dat |= 0x01;
        SCL=0; I2C_Delay();
    }
    SDA = ack ? 0 : 1;
    SCL=1; I2C_Delay(); SCL=0;
    return dat;
}
#define EEPROM_ADDR 0xA0
#define RTC_ADDR    0xD0
void EEPROM_Write(unsigned char memAddr, unsigned char dat) {
    I2C_Start();
    I2C_WriteByte(EEPROM_ADDR);
    I2C_WriteByte(memAddr);
    I2C_WriteByte(dat);
    I2C_Stop();
}
unsigned char RTC_ReadSeconds(void) {
    unsigned char sec;
    I2C_Start();
    I2C_WriteByte(RTC_ADDR);
    I2C_WriteByte(0x00);
    I2C_Start();
    I2C_WriteByte(RTC_ADDR | 0x01);
    sec = I2C_ReadByte(0);
    I2C_Stop();
    return sec;
}
void main(void) {
    unsigned char currentSec;
    currentSec = RTC_ReadSeconds();     
    EEPROM_Write(0x10, currentSec);     

    while(1);
}