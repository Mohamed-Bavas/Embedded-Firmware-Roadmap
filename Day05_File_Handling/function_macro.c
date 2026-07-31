#include <stdio.h>
#define SQUARE(X) ((X)*(X))
#define MAX(a,b) ((a)>(b)?(a):(b))
void main(){
    int a=10,b=20;
    printf("Square of %d =%d\n",a,SQUARE(a));
    printf("MAX of %d and %d = %d\n",a,b,MAX(a,b));
}