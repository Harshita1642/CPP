#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<vector<pair<int,int>>> createGraph(vector<vector<int>> &input,int V){
    vector<vector<pair<int,int>>> adj(V);
    for(auto edge: input){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    return adj;
}
int main(){
    vector<vector<int>>arr;
    int vertices;
    cin>>vertices;
    for(int i=0 ; i<vertices ; i++){
        int u,v,w;
        cin>>u>>v>>w;
        arr.push_back({u,v,w});
    }
    vector<vector<pair<int,int>>> graph=createGraph(arr,vertices);
    for(int i=0 ; i<graph.size() ; i++){
        cout<<i<<" -> ";
        for(auto edge: graph[i]){
            cout<<"{"<<edge.first<<" "<<edge.second<<"} ";
        }
        cout<<endl;
    }
    return  0;
}