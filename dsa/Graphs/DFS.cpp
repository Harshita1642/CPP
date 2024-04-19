#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<vector<int>> & graph,vector<int> &ans,vector<bool>& vis,int node,int v){
    ans.push_back(node);
    vis[node]=1;
    for(auto i: graph[node]){
        if(!vis[i]){
            dfs(graph,ans,vis,i,v);
        }
    } 
}
int main(){
    vector<vector<int>> edges={{0,1},{0,3},{1,2},{1,3},{2,4},{3,4},{2,5}};
    int v=7;
    vector<vector<int>> graph(v);
    for(auto edge: edges){
        int u=edge[0];
        int v=edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(auto it: graph){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    vector<bool> vis(v,false);
    vector<int> ans;
    dfs(graph,ans,vis,0,v);
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}