#include <reg51.h>
sbit red=P2^0;
sbit yellow=P2^1;
sbit green=P2^2;
unsigned char num[]={
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x07,
	0x7F,
	0x6F
};
void delay(){
	TMOD=0x01;
	TH0=0xFC;
	TL0=0x18;
	TR0=1;
	while(TF0==0);
	TR0=0;
	TF0=0;
}
void delay1s(){
	unsigned int i;
	for(i=0;i<1000;i++){
		delay();
	}
}
void countdown(unsigned int c){
	unsigned int i;
	 for(i=0;i<=c;i++){
		 P3=num[i];
		 delay1s();
}
}
void main(){
	while(1){
		red=1;
		yellow=0;
		green=0;
		countdown(5);
		red=0;
		yellow=1;
		green=0;
		countdown(4);
		red=0;
		yellow=0;
		green=1;
		countdown(3);	
	}
}
	