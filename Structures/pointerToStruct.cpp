#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    float cgpa;
    char name[100];
};
int main()
{
    struct student s1={0,12.4,"Abc"};
    struct student *ptr=&s1;
    printf("student roll =%d",(*ptr));
    printf("student name =%s",(*ptr).name);
    printf("student cgpa =%f ",ptr->cgpa);
    return 0;
}