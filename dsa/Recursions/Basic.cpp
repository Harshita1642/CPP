#include<iostream>
using namespace std;
int factorial(int n)
{
    //Base Case
    if(n==0)
    {
        return 1;
    }
    //Recursive relation
    return n*factorial(n-1);
}
int power(int n)
{
    //Base Case
    if(n==0)
        return 1;
    //Recursive relation
    return 2*power(n-1);
}
void print(int n)
{
    //Base Case
    if(n==0)
    {
        return;
    }
    //processing
    cout<<n<<"\t";
    //Recursive relation
    print(n-1);
}
void printing(int n)
{
    //Base Case
    if(n==0)
    {
        return;
    }
    //Recursive relation
    printing(n-1);
    //processing
    cout<<n<<"\t";
}
int main()
{
    int n;
    cin>>n;
    cout<<"factorial of "<<n<<" is "<<factorial(n)<<endl;
    cout<<"2^"<<n<<" is "<<power(n)<<endl;
    cout<<"numbers from n to 0:\t";
    print(n);
    cout<<endl<<"numbers from 0 to n:\t";
    printing(n);
    return 0;
}