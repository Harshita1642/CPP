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
void deletionInHeap(vector<int>& arr){
    int lastIdx=arr.size()-1;
    swap(arr[0],arr[lastIdx]);
    arr.pop_back();
    int idx=0;
    while(idx<arr.size()){
        int leftChild=arr[2*idx+1];
        int rightChild=arr[2*idx+2];
        int swapIdx=-1;
        if(leftChild<rightChild){
            swapIdx=2*idx+1;
        }
        else{
            swapIdx=2*idx+2;
        }
        if(arr[swapIdx]<arr[idx]){
            swap(arr[swapIdx],arr[idx]);
            idx=swapIdx;
        }
        else break;
    }
}
int main(){

    return 0;
}