#include<iostream>
#include<vector>
using namespace std;
void insertionInHeap(vector<int>& arr,int val){
    arr.push_back(val);
    int idx=arr.size()-1;
    while(idx>0){
        int par=(idx-1)/2;
        if(arr[par]>arr[idx]){
            swap(arr[par],arr[idx]);
            idx=par;
        }
        else break;
    }
}
void heapify(vector<int>& arr,int idx,int n){
    int left=2*idx+1,right=2*idx+2;
    int smallest=idx;
    if(left<n&& arr[left]<arr[smallest]) {
        smallest=left;
    }
    if(right<n && arr[right]<arr[smallest]) {
        smallest=right;
    }
    if(smallest!=idx){
        swap(arr[idx],arr[smallest]);
        heapify(arr,smallest,n);
    }
}
void BuildHeap(vector<int>& arr){
    int n=arr.size();
    for(int i= (n/2-1) ; i>=0 ; i--){
        heapify(arr,i,n);
    }
}
int main(){
    // vector<int> arr={2,10,12,5,6,8};
    vector<int> arr={4,5,1,3,2};
    BuildHeap(arr);
    for( int i: arr){
        cout<<i<<" ";
    }
    return 0;
}