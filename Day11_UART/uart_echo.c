#include <reg51.h>
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
void Tx_ch(char ch){
	SBUF=ch;
	while(TI==0);
	TI=0;
}
void main(){
	char ch;
	uart_init();
	while(1){
		ch=Rx_ch();
		Tx_ch(ch);
	}
}