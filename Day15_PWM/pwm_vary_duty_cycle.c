#include <reg51.h>
sbit PWM_PIN=P1^0;
#define PERIOD 100
void delay(unsigned int t){
	unsigned int i;
	for(i=0;i<t;i++);
}
void PWM_Generate(unsigned char DUTY){
	unsigned char cycles;
	for(cycles=0;cycles<20;cycles++){
		PWM_PIN=1;
		delay(DUTY);
		PWM_PIN=0;
		delay(PERIOD-DUTY);
	}
}
void main(){
	unsigned char DUTY;
	PWM_PIN=0;
	while(1){
		for(DUTY=0;DUTY<=PERIOD;DUTY+=10){
			PWM_Generate(DUTY);
		}
		for(DUTY=PERIOD;DUTY>=10;DUTY-=10){
			PWM_Generate(DUTY);
		}
	}
	
}
