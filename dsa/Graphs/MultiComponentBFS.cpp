//levelOrderTraveral Of Graph
// graph is
// 0-> 1 2
// 1-> 0
//  2-> 0
// 3-> 4
// 4-> 3
// 5-> null
// output-> 0 1 2 3 4 5 
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void bfsHelper(int curr,vector<vector<int>> & graph,vector<int>& ans,vector<bool> &visited){
    queue<int> q;
    q.push(curr);
    visited[curr]=1;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: graph[node]){
                if(visited[it]==0){
                    q.push(it);
                    visited[it]=true;
                }
            }
        }
    }
}
vector<int> BFS(vector<vector<int>>& adj,int v){
    vector<int> ans;
    vector<bool> vis(v,false);
    for(int i=0 ; i<v ; i--){
        if(vis[i]){
            bfsHelper(i,adj,ans,vis);
        }
    }
    return ans;
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
     vector<int> ans=BFS(graph,v);
     for(auto i: ans){
        cout<<i<<" ";
     }
    return 0;
}