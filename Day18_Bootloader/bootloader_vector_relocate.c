#include <reg51.h>
typedef void (*ApplicationFunction)(void);
void Application()
{
    P1 = 0x55;
    while (1);
}
void Jump_To_Application()
{
    ApplicationFunction app;
    app = Application;
    app();
}
void main()
{
    Jump_To_Application();
    while (1);
}