#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int> &arr,int s,int m,int e){
    int i=s;
    int j=m+1;
    vector<int> st;
    while(i<=m and j<=e){
        if(arr[i]<arr[j]){
            st.push_back(arr[i]);
            i++;
        }
        else{
            st.push_back(arr[j]);
            j++;
        }
    }
    while(i<=m){
        st.push_back(arr[i]);
        i++;
    }
    while(j<=e){
        st.push_back(arr[j]);
        j++;
    }
    int k=s;
    int t=0;
    while(k<e){
        arr[k++]=st[t++];
    }
}
void mergeSort(vector<int> &arr,int start,int end){
    if(start>end) return;
    int mid=start+(end-start)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
int main(){
    vector<int> arr;
    int n;
    cin>>n;
    int ele;
    for(int i=0 ; i<n ; i++){
        cin>>ele;
    }
    mergeSort(arr,0,n-1);
    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}