#include<iostream>
using namespace std;
bool CheckPresence(int arr[],int start,int end,int ele)
{
    if(start>end)
    {
        return false;
    }
    int mid=start+(end-start)/2;
    if(ele==arr[mid])
    {
        return true;
    }
    else if(ele>arr[mid])
    {
        start=mid+1;
    }
    else
    {
        end=mid-1;
    }
    int remainingPart=CheckPresence(arr,start,end,ele);
    return remainingPart;
}
int main()
{
    int arr[]={2,4,6,8,9};
    int ele=7;
    cout<<CheckPresence(arr,0,5,ele)<<endl;
    return  0;
}