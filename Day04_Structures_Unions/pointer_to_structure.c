#include <stdio.h>
struct student{
    int id;
    char name[50];
    float marks;
};
void main(){
    struct student s1={101,"bavas",99.97};
    struct student *ptr=&s1;
    printf("Student ID : %d\n",(*ptr).id);
    printf("Student Name : %s\n",ptr->name);
    printf("Student Marks : %.2f\n",ptr->marks);
}