#include <reg51.h>
typedef unsigned char uint8;
typedef unsigned int  uint16;
#define QUEUE_SIZE 8
typedef struct {
    uint8 buffer[QUEUE_SIZE];
    uint8 head;     
    uint8 tail;      
    uint8 count;     
} Queue_t;
Queue_t dataQueue;
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
void Queue_Init(Queue_t *q)
{
    q->head=0;
    q->tail=0;
    q->count=0;
}
bit Queue_Send(Queue_t *q, uint8 value)
{
    if (q->count >= QUEUE_SIZE) return 0;   
    q->buffer[q->head] = value;
    q->head = (q->head + 1) % QUEUE_SIZE;
    q->count++;
    return 1;
}
bit Queue_Receive(Queue_t *q, uint8 *value)
{
    if(q->count==0) 
		return 0;            
    *value=q->buffer[q->tail];
    q->tail=(q->tail + 1)%QUEUE_SIZE;
    q->count--;
    return 1;
}
void main()
{
    uint8 producedValue=0;
    uint8 consumedValue=0;
    uint16 lastProduceTick=0;
    uint16 lastConsumeTick=0;
    Timer0_Init();
    Queue_Init(&dataQueue);
    for (;;) {
        if ((uint16)(tickCount-lastProduceTick)>=20) {
            lastProduceTick=tickCount;
            if(Queue_Send(&dataQueue,producedValue)) {
                producedValue++;
            }
        }
        if((uint16)(tickCount-lastConsumeTick)>=35) {
            lastConsumeTick = tickCount;
            if(Queue_Receive(&dataQueue,&consumedValue)) {
                P2=consumedValue;   
            }
        }
    }
}
