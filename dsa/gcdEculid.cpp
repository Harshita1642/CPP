#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)
    return b;

    if(b==0)
    return a;

    while (a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}
int lcm(int a,int b)
{
    int gcdans=gcd(a,b);
    int lcmans=(a*b)/gcdans;
    return lcmans;
}
int main()
{
    int a,b;
    cout<<"enter the two numbers: ";
    cin>>a>>b;
    cout<<"gcd = "<<gcd(a,b)<<endl;
    cout<<"lcm = "<<lcm(a,b);
    return 0;
}