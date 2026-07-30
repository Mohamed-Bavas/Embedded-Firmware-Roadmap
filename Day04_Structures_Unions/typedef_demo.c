#include <stdio.h>
typedef unsigned int unit;
typedef struct {
    int id;
    char name[20];
} student;
void main() {
    unit a=10;
    student s1={101,"bavas"};
    printf("Unit Value : %u\n",a);
    printf("Student ID : %d\n",s1.id);
    printf("Student Name :%s\n",s1.name);
}
