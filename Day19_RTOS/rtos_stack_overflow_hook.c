#include <reg51.h>
typedef unsigned char uint8;
typedef unsigned int  uint16;
sbit ALARM_LED=P1^7;
#define STACK_SAFE_LIMIT 0x70   
volatile bit stackOverflowFlag=0;
volatile uint16 tickCount=0;
void Timer0_ISR(void) interrupt 1
{
    TH0=0xD8;
    TL0=0xF0;
    tickCount++;
}
void Timer0_Init()
{
    TMOD|=0x01;
    TH0=0xD8;
    TL0=0xF0;
    ET0=1;
    TR0=1;
    EA=1;
}
void OS_CheckStackOverflow()
{
    if (SP>STACK_SAFE_LIMIT) {
        stackOverflowFlag=1;
        ALARM_LED=1;
    }
}
void RecursiveDemo(uint8 depth)
{
    uint8 localBuffer[4];  
    localBuffer[0]=depth;
    OS_CheckStackOverflow();
    if (stackOverflowFlag) 
			return;  
    if (depth<40) {
        RecursiveDemo(depth+1);
    }
}
void main()
{
    uint16 lastCheck=0;
    Timer0_Init();
    ALARM_LED=0;
    for (;;) {
        if ((uint16)(tickCount-lastCheck)>=10) {
            lastCheck=tickCount;
            OS_CheckStackOverflow();
        }
    }
}