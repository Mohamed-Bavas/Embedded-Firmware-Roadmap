#include <stdio.h>
struct status{
    unsigned int power : 1;
    unsigned int mode :2;
    unsigned int error : 1;
};
void main(){
    struct status s;
    s.power=1;
    s.mode=3;
    s.error=0;
    printf("Power : %u\n",s.power);
    printf("Mode : %u\n",s.mode);
    printf("Error : %u\n",s.error);
}