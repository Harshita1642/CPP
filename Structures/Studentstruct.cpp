#include<stdio.h>
#include<string.h>
struct student{
    int roll;
    float cgpa;
    char name[100];
};
int main()
{
    struct student s1;
    s1.roll=1664;
    s1.cgpa=9.2;
    strcpy(s1.name,"shradha");
    printf("student name = %s\n",s1.name);
    printf("student roll no =%d \n",s1.roll);
    printf("student cgpa=%f\n  ",s1.cgpa);
    struct student s3={0};
    struct student s2={ 1246,6.7,"harshita"};
    printf("%s\n",s2.name);
    printf("%f\n",s3.cgpa);
    //we can make arrays of structures 
    struct student ece[100];
    for(int i=0 ; i<3 ; i++)
    {
        scanf("%d %s %f",&ece[i].roll,&ece[i].name,&ece[i].cgpa);
    }
    for(int i=0 ; i<3 ; i++)
    {
        printf("%d %s %f",ece[i].roll,ece[i].name,ece[i].cgpa);
    }
}