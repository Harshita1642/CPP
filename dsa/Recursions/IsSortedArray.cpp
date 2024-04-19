#include<iostream>
using namespace std;
bool Sorted(int n,int arr[]){
    if(n<=1) return true;
    if(arr[n]<arr[n-1]) return false;
    return Sorted(n-1,arr);
}
int main(){
    int n;
    n=7;
    // int arr[]={1,7,98,45,23,99,0};
    int arr[]={1,2,3,4,5,6,7};
    cout<<Sorted(n,arr);
    return 0;
}