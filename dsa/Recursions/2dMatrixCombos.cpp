#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
void solve(char arr[3][3],string output,int n,int m,int i=0){
    if(output.length()==n){
        cout<<output<<" ";
        return;
    }
    for(int j=0 ; j<m ; j++){
        output.push_back(arr[i][j]);
        solve(arr,output,n,m,i+1);
        output.pop_back();
    }
}
int main(){
    // char arr[3][2]={{'a','b'},{'c','d'},{'e','f'}};
    char arr[3][3]={{'a','b','c'},{'d','e','f'},{'g','h','i'}};
    solve(arr,"",3,3);
    // print(arr,3,2);
    return 0;
}