#include <reg51.h>
typedef unsigned char uint8;
typedef unsigned int  uint16;
sbit HIGH_LED = P1^0;
sbit MED_LED  = P1^1;
sbit LOW_LED  = P1^2;
#define MAX_TASKS 3
typedef void (*TaskFunc)(void);
typedef struct {
    TaskFunc func;
    uint8 priority;      
    uint16 periodTicks;
    uint16 lastRunTick;
    uint8 ready;
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
void OS_CreateTask(TaskFunc f,uint8 priority,uint16 periodTicks)
{
    if (taskCount<MAX_TASKS) {
        taskList[taskCount].func=f;
        taskList[taskCount].priority=priority;
        taskList[taskCount].periodTicks=periodTicks;
        taskList[taskCount].lastRunTick=0;
        taskList[taskCount].ready=0;
        taskCount++;
    }
}
void OS_UpdateReadyFlags(void)
{
    uint8 i;
    for (i = 0; i < taskCount; i++) {
        if ((uint16)(tickCount-taskList[i].lastRunTick)>=taskList[i].periodTicks) {
            taskList[i].ready=1;
        }
    }
}
void OS_Start(void)
{
    uint8 i, highestIdx;
    for (;;) {
        OS_UpdateReadyFlags();
        highestIdx = 0xFF;
        for (i = 0; i < taskCount; i++) {
            if (taskList[i].ready) {
                if (highestIdx==0xFF||taskList[i].priority<taskList[highestIdx].priority) {
                    highestIdx=i;
                }
            }
        }
        if (highestIdx!=0xFF) {
            taskList[highestIdx].func();
            taskList[highestIdx].ready=0;
            taskList[highestIdx].lastRunTick=tickCount;
        }
    }
}
void Task_High()  {
HIGH_LED=!HIGH_LED;
}
void Task_Medium()
{
MED_LED=!MED_LED;
}
void Task_Low()
{
LOW_LED = !LOW_LED;
}
void main()
{
    Timer0_Init();
    OS_CreateTask(Task_High,0,10);   
    OS_CreateTask(Task_Medium,1,30);
    OS_CreateTask(Task_Low,2,100);  
    OS_Start();
}