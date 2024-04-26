#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
void  dfsHelper(int curr,vector<vector<int>> &adj,vector<bool>&vis,vector<int> &ans){
    vis[curr]=true;
    for(int nbr: adj[curr]){
        if(!vis[nbr]){
             dfsHelper(nbr,adj,vis,ans);
        }
    }
    ans.push_back(curr);
}
vector<int> topoSort(vector<vector<int>> & adj,int v){
    vector<bool> vis(v,false);
    vector<int> ans;
    for(int i=0 ; i<v ; i++){
        if(!vis[i]){
            dfsHelper(i,adj,vis,ans);
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
vector<int> topoSortBfs(vector<vector<int>> &adj,int v){
    vector<int> indeg(v,0);
    for(int i=0 ; i<v ; i++){
        for(int j: adj[i]){
            indeg[j]++;
        }
    }
    vector<int> ans;
    queue<int> q;
    for(int i=0 ; i<v ; i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(int nbr: adj[node]){
            indeg[nbr]--;
            if(indeg[nbr]==0){
                q.push(nbr);
            }
        }
    }
    return ans;
}
int main(){
    int n=6;
    vector<vector<int>> graph(n);
    vector<vector<int>> edges={{2,3},{3,1},{4,0},{4,1},{5,0},{5,2}};
    vector<bool> vis(n,false);
    for(auto edge: edges){
        graph[edge[0]].push_back(edge[1]);
    }
    // for(auto edge: graph){
    //     for(int ele: edge){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }
    vector<int> arr=topoSort(graph,n);
    for(int ele: arr){
        cout<<ele<<" ";
    }
    cout<<endl;
    vector<int> rs=topoSortBfs(graph,n);
     for(int ele: rs){
        cout<<ele<<" ";
    }
    return 0;
}