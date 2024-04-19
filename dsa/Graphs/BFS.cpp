//levelOrderTraveral Of Graph
// graph is 
// 0 -> 1, 3
// 1 -> 0,2,3
// 2 -> 1,4,5
// 3 -> 0,1,4
// 4 -> 2,3
// 5 -> 2
//edges={{0,1},{0,3},{1,2},{1,3},{2,4},{3,4},{2,5}}
// Output--> 0 1 3 2 4 5
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<int> bfs(vector<vector<int>> & graph,int vertices){
    vector<int> ans;
    queue<int> q;
    q.push(0);
    vector<bool> visited(vertices,false);
    visited[0]=1;
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
     vector<int> ans=bfs(graph,v);
     for(auto i: ans){
        cout<<i<<" ";
     }
    return 0;
}