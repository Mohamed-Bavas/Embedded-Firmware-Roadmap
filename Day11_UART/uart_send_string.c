#include <reg51.h>
void uart_init(){
	TMOD=0x20;
	TH1=0xFD;
	SCON=0x50;
	TR1=1;
}
void Tx_char(char ch){
	SBUF=ch;
	while(TI==0);
	TI=0;
}
void Tx_str(char *str){
	while(*str){
		Tx_char(*str);
		str++;
	}
}
void main(){
	uart_init();
  while(1){
		Tx_str("HELLO WORLD\r\n");
	}
}