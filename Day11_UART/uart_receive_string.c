#include <reg51.h>
char str[20];
void uart_init(){
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
}
int Rx_ch(){
	while(RI==0);
	RI=0;
	return SBUF;
}
void main(){
	unsigned  char i=0;
	uart_init();
	while(1){
		char ch=Rx_ch();
		if(ch=='\r'){
			str[i]='\0';
			i=0;
		}else{
			str[i++]=ch;
		}
	}
	}