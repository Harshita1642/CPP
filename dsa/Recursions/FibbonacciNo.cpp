#include<iostream>
using namespace std;
int FibbonacciNthTerm(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    return FibbonacciNthTerm(n-1)+FibbonacciNthTerm(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<n<<"th term of fibbonacci series is "<<FibbonacciNthTerm(n);
    return 0;
}