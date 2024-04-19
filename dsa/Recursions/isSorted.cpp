#include<iostream>
using namespace std;
bool isSorted(int arr[],int n)
{
    //base case
    if(n==1 || n==0)
        return true;
    //processing
    if(arr[0]>arr[1])
    {
        return false;
    }
    else
    {
        return isSorted(arr+1,n-1);
    }
  
}
int main()
{
    int n=5;
    int arr[]={2,4,6,8,9};
    cout<<isSorted(arr,n);
    return 0;
}