#include <reg51.h>
typedef unsigned char uint8;
typedef unsigned int  uint16;
volatile bit uartMutex=1;
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
void UART_Init()
{
    TMOD|=0x20;      
    TH1=0xFD;      
    SCON=0x50;      
    TR1=1;
}
void UART_PutChar(char c)
{
    SBUF=c;
    while(TI==0);
    TI=0;
}
void UART_PutString(char *s)
{
    while(*s) {
        UART_PutChar(*s);
        s++;
    }
}
bit Mutex_Take()
{
    if (uartMutex) {
        uartMutex=0;   
        return 1;
    }
    return 0;            
}
void Mutex_Give()
{
    uartMutex=1;
}
void TaskA_Print()
{
    if (Mutex_Take()) {
        UART_PutString("TaskA: sensor OK\r\n");
        Mutex_Give();
    }
}
void TaskB_Print()
{
    if (Mutex_Take()) {
        UART_PutString("TaskB: comm link OK\r\n");
        Mutex_Give();
    }
}
void main()
{
    uint16 lastA=0,lastB=0;
    Timer0_Init();
    UART_Init();
    for (;;) {
        if ((uint16)(tickCount-lastA)>=40) {   
            lastA=tickCount;
            TaskA_Print();
        }
        if ((uint16)(tickCount-lastB)>=55) {   
            lastB=tickCount;
            TaskB_Print();
        }
    }
}
