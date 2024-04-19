#include<iostream>
using namespace std;
void sort(int *arr,int n){
    if(n==0 ) return;
    for(int i=0 ; i<n ; i++){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
    }
    sort(arr,n-1);
}
int main(){
    int n=7;
    int arr[]={12,65,34,98,00,11,18};
    sort(arr,n);
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}