#include<iostream>
using namespace std;
int binarySearch(int* arr, int start,int end, int key)
{
    int mid;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==key)
        {
            return mid;
        }
        if(arr[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return -1;
}
int search(int* arr, int n, int key) {
    // Write your code here.
    int max=arr[0],pivot=0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i]<max)
        {
            pivot =i;
            break;
        }
    }
    cout<<"pivot "<<pivot<<endl;
    int ans=binarySearch(arr, 0, pivot, key);
    cout<<"ans "<<ans<<endl;
    if(ans==-1)
    {
        ans=binarySearch(arr, pivot, n-1, key);
    }
    cout<<"ans "<<ans<<endl;
    return ans;
}
int main()
{
    int arr[3]={3,1,2};
    int n=3;
    int key=1;
    cout<<search(arr,n,key)<<endl;
    return 0;
}