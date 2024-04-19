#include<iostream>
using namespace std;
int Sum(int arr[],int n)
{
    //base case
    if(n==0)
        return 0;
    int remainingPart = Sum(arr+1, n-1);
    int sum = arr[0] + remainingPart;
    return sum;
}
int main()
{
    
    int n=5;
    int arr[]={2,4,6,8,9};
    cout<<Sum(arr,n)<<endl;
    return 0;
}