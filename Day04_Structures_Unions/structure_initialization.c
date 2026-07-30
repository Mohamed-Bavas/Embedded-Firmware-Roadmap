#include <stdio.h>
struct Student
{
    int id;
    char name[20];
    float marks;
};
int main()
{
    struct Student s = {101, "Bavas", 95.5};
    printf("ID : %d\n", s.id);
    printf("Name : %s\n", s.name);
    printf("Marks : %.2f\n", s.marks);
    return 0;
}