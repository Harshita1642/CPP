#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> arr,int j,int n,vector<int> left,vector<int> right,int &cnt){
    if(j==n){
        int lsum=0;
        int rsum=0;
        for(int i=0 ; i<left.size() ; i++){
            lsum+=left[i];
        }
        for(int i=0 ; i<right.size() ; i++){
            rsum+=right[i];
        }
        if(lsum==rsum){
        for(int i=0 ; i<left.size() ; i++){
            cout<<left[i]<<" ";
        }
        cout<<"and ";
        for(int i=0 ; i<right.size() ; i++){
            cout<<right[i]<<" ";
        }
        cnt++;
        cout<<endl;
    }
        return;
    }
    //include in left
    int a=arr[j];
    left.push_back(a);
    solve(arr,j+1,n,left,right,cnt);
    left.pop_back();
    //include in right
    right.push_back(a);
    solve(arr,j+1,n,left,right,cnt);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0 ; i<n ; i++){
        int data;
        cin>>data;
        arr.push_back(data);
    }
    vector<int> left;
    vector<int> right;
    int ans=0;
    solve(arr,0,n,left,right,ans);
    cout<<ans<<endl;
}