#include <reg51.h>
typedef unsigned char uint8;
typedef unsigned int  uint16;
sbit LED1 = P1^0;
sbit LED2 = P1^1;
#define MAX_TASKS 2
typedef void (*TaskFunc)(void);
typedef struct {
    TaskFunc func;
    uint16   delayTicks;   
    uint16   lastRunTick;
} TCB;
TCB taskList[MAX_TASKS];
uint8 taskCount = 0;
volatile uint16 tickCount = 0;   
void Timer0_ISR(void) interrupt 1
{
    TH0 = 0xD8;         
    TL0 = 0xF0;
    tickCount++;
}
void Timer0_Init()
{
    TMOD |= 0x01;            
    TH0 = 0xD8;
    TL0 = 0xF0;
    ET0 = 1;                 
    TR0 = 1;                  
    EA  = 1;                  
}
void OS_CreateTask(TaskFunc f, uint16 periodTicks)
{
    if (taskCount < MAX_TASKS) {
        taskList[taskCount].func         = f;
        taskList[taskCount].delayTicks   = periodTicks;
        taskList[taskCount].lastRunTick  = 0;
        taskCount++;
    }
}
void OS_Start()
{
    uint8 i;
    for (;;) {
        for (i = 0; i < taskCount; i++) {
            if ((uint16)(tickCount - taskList[i].lastRunTick) >= taskList[i].delayTicks) {
                taskList[i].lastRunTick = tickCount;
                taskList[i].func();      
            }
        }
    }
}
void Task1_LedBlink(void)
{
    LED1 = !LED1;
}
void Task2_LedBlink(void)
{
    LED2 = !LED2;
}
void main(void)
{
    Timer0_Init();
    OS_CreateTask(Task1_LedBlink, 50);
    OS_CreateTask(Task2_LedBlink, 20);
    OS_Start();   
}