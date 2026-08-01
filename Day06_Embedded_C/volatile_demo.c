#include <stdio.h>
volatile int sensor = 100;
int main() {
    printf("Sensor Value = %d\n", sensor);
    sensor = 150;
    printf("Updated Value = %d\n", sensor);
    return 0;
}