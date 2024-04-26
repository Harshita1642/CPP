#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//Directed Graph
// Intuition:- if we try topo sort on the graph and all the nodes are 
//included in the topo sort then there is no loop present but if all nodes are not present in the final topo sort
// array then there is a loop present in the graph
bool cycleDetection(vector<vector<int>>& graph,int v){
    vector<int> indeg(v,0);
    for(auto i: graph){
        for(int ele: i){
            indeg[ele]++;
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
        for(int nbr: graph[node]){
            indeg[nbr]--;
            if(indeg[nbr]==0){
                q.push(nbr);
            }
        }
    }
    for(auto &i:ans)cout<<i<<" ";
    return ans.size()!=v;
}



//Undirected Graph
bool cycleDetect(vector<vector<int>>&graph,int v){
    vector<bool> vis(v,false);
    queue<int> q;
    q.push(0);
    int parent=-1;
    while(!q.empty()){
        int node=q.front();
        vis[node]=true;
        q.pop();
        for( int nbr: graph[node]){
            if(!vis[nbr]){
                parent=node;
                q.push(nbr);
            }
            else if(vis[nbr]==true && nbr!=parent){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int v=5;
    // vector<vector<int>> adj={{1},{0,2},{1,3},{2,4},{3}};
    // cout<<cycleDetect(adj,v);
     vector<vector<int>> adj={{1},{2,4},{3},{},{3,5},{1}};
    cout<<cycleDetection(adj,v);
    return 0;
}