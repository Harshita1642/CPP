#include<iostream>
using namespace std;
int GetMinServers(int arr[], int n,int expected) {
    int mini=INT16_MAX;
   for(int i=0 ; i<n  ;i++) {
        int sum=0;
        for(int j=i ; j<n ; j++){
            sum=sum+arr[j];
            // cout<<sum<<endl;
            if(sum>=expected){
                // cout<<"*"<<sum<<endl;
                mini=min(mini,abs(j-i)+1);
                break;
            }
        }
   }
   return mini;
}
int main(){
    int arr[]={1,1,2,4,4};
    cout<<GetMinServers(arr,5,10);
    return 0;
}