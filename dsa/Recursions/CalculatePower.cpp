#include<iostream>
using namespace std;
int CalculatePower(int a,int b)
{
    //base case
    if(b==0)
        return 1;
    if(b==1)
        return a;
    //Recursive Call
    int ans=CalculatePower(a,b/2);
    //if b is even
    if(b%2==0)
    {
        return ans*ans;
    }
    else //if b is odd
    {
        return a*ans*ans;
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<CalculatePower(a,b);
    return 0;
}