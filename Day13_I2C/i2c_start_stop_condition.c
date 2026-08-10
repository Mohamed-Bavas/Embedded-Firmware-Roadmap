#include <reg51.h>
sbit SDA=P1^0;
sbit SCL=P1^1;
void I2C_delay(){
	unsigned char i;
	for(i=0;i<10;i++);
}
void I2C_start(){
	SDA=1;
	SCL=1;
	I2C_delay();
	SDA=0;
	I2C_delay();
	SCL=0;
}
void I2C_stop(){
	SDA=0;
	SCL=1;
	I2C_delay();
	SDA=1;
	I2C_delay();
}
void main(){
	I2C_start();
	I2C_stop();
	while(1);
}
