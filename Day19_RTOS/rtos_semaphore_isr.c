#include <reg51.h>
typedef unsigned char uint8;
typedef unsigned int  uint16;
sbit LED=P1^0;
volatile bit buttonSemaphore=0;
void Delay_ms(uint16 ms)
{
    uint16 i,j;
    for(i=0;i<ms;i++)
        for(j=0;j<120;j++);   
}
void EXT0_ISR(void) interrupt 0
{
    buttonSemaphore=1;    
}
void EXT0_Init(void)
{
    IT0=1;   
    EX0=1;   
    EA=1;   
}
void ButtonTask()
{
    if (buttonSemaphore) {              
        buttonSemaphore=0;            
        LED=1;
        Delay_ms(200);
        LED=0;
    }
}
void main()
{
    EXT0_Init();
    for (;;) {
        ButtonTask();
    }
}
