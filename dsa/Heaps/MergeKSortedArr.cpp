#include<iostream>
#include<queue>
using namespace std;
//Input
// 1 2 3
// 2 4 6
// 0 9 10 
//Output
// 0 1 2 2 3 4 6 9 10

int main(){
    
    priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>> >,greater<pair<int,pair<int,int>> >> pq;
    vector<vector<int>> mat={
        {1,2,3},
        {2,4,6},
        {0,9,10}
    };
    for(int i=0 ;i<3;i++){
        pq.push({mat[i][0],{i,0}});
    }
    vector<int> ans;
    while(!pq.empty()){
        pair<int,pair<int,int>>  top=pq.top();
        pq.pop();
        ans.push_back(top.first);
        int row=top.second.first , col=top.second.second;
        if(col+1<mat[row].size()){
            pq.push({mat[row][col+1],{row,col+1}});
        }
    }
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}