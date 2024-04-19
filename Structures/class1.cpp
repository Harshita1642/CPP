#include<stdio.h>

struct Str{
    double a;
    char b;
}__attribute__((packed));
int main()
{
    printf("%d",sizeof(Str));
    return 0;
}