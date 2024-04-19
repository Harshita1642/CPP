// i/p-> arr={1,2,3,4,5} check 6 is present in it or not
#include<iostream>
using namespace std;
bool CheckPresence(int arr[],int n ,int ele)
{
    if(n==0)
        return 0;
    if(ele==arr[0])
    {
        cout<<"found"<<endl;
        return 1;
    }
    else{
        bool remainingPart=CheckPresence(arr+1,n-1,ele);
        return remainingPart;
    }
}
bool search(int n,int arr[],int target){
    if(n==0 ) return false;
    if(arr[0]==target) return true;
    return search(n-1,arr+1,target);
}
int main()
{
    int n=5;
    int arr[]={1,2,3,4,5};
    int ele=1;
    // cout<<CheckPresence(arr,n,ele)<<endl;
    cout<<search(n,arr,ele);
    return 0;
}