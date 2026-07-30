#include <stdio.h>
struct Address
{
    char city[20];
    int pincode;
};
struct Student
{
    int id;
    char name[20];
    struct Address addr;
};
int main()
{
    struct Student s;
    printf("Enter ID: ");
    scanf("%d", &s.id);
    printf("Enter Name: ");
    scanf("%s", s.name);
    printf("Enter City: ");
    scanf("%s", s.addr.city);
    printf("Enter Pincode: ");
    scanf("%d", &s.addr.pincode);
    printf("\nStudent Details\n");
    printf("ID : %d\n", s.id);
    printf("Name : %s\n", s.name);
    printf("City : %s\n", s.addr.city);
    printf("Pincode : %d\n", s.addr.pincode);
    return 0;
}