#include<iostream>
#include<vector>
using namespace std;

//Undirected
bool dfsHelper(int curr, vector<vector<int>> &graph, vector<bool> &vis, int parent) {
    vis[curr] = true;
    for(int nbr : graph[curr]) {
        if(!vis[nbr]) {
            if(dfsHelper(nbr, graph, vis, curr)) {
                return true;
            }
        }
        else if(nbr != parent) {
            return true;
        }
    }
    return false;
}

bool cycleDetect(vector<vector<int>> &graph, int v) {
    vector<bool> vis(v, false);
    for(int i = 0; i < v; i++) {
        if(!vis[i]) {
            if(dfsHelper(i, graph, vis, -1)) {
                return true;
            }
        }
    }
    return false;
}

int main() {


    //Undirected Graph Cycle Detection
    // int v = 5;
    // // vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,2},{3,4}};
    // vector<vector<int>> adj={{1},{0,2,3},{1,3},{1,2,4},{3}};
    // vector<vector<int>> graph(v); // Initialize graph with v vectors

    // // for(auto edge : edges) {
    // //     int u = edge[0];
    // //     int v = edge[1];
    // //     graph[u].push_back(v);
    // //     graph[v].push_back(u);
    // // }
    // graph=adj;
    // for(auto me: graph){
    //     for(int ele: me){
    //         cout<<ele<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout << cycleDetect(graph, v);

    //directed Graph
    vector<vector<int>> adj={{1},{2,4},{3},{},{3,5},{1}};
    
    return 0;
}
