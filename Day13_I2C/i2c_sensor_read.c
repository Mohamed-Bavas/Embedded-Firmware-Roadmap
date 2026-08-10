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
void I2C_Stop(void){SDA=0;
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
int LM75_ReadTemperature(void) {
    unsigned char msb, lsb;
    int temp;
    I2C_Start();
    I2C_WriteByte(0x90);      
    I2C_WriteByte(0x00);
    I2C_Start();
    I2C_WriteByte(0x91);       
    msb = I2C_ReadByte(1);     
    lsb = I2C_ReadByte(0);     
    I2C_Stop();

    temp = (msb << 1) | (lsb >> 7);  
    return temp / 2;                 
}
void main(void) {
    int temperature;
    temperature = LM75_ReadTemperature();
    while(1);
}