#include <reg51.h>
void delay(){
	unsigned int i,j;
	for(i=0;i<300;i++)
	for(j=0;j<1275;j++);
}
void main()
{
    while(1)
    {  
        
			P1=0x00;
			P2 = P1;	
			delay();
			P1=0xFF;
			P2 = P1;	
			delay(); 
		
    }
}