#include <reg51.h>

sbit SDA = P1^0;
sbit SCL = P1^1;

void I2C_Init(void) {
    SDA = 1;   
    SCL = 1;   
}

void main(void) {
    I2C_Init();
    while(1);  
}