#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
template<typename T>
unordered_map<T,vector<T>> createGraph(vector<pair<T,T>> &input){
    // Undirected Graph
    unordered_map<T,vector<T>> graph;
    for(auto edge: input){
        int u=edge.first;
        int v=edge.second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    return graph;
}
template<typename T>
unordered_map<T,vector<T>> createGraphDirected(vector<pair<T,T>> &input){
    // directed Graph
    unordered_map<T,vector<T>> graph;
    for(auto edge: input){
        int u=edge.first;
        int v=edge.second;
        graph[u].push_back(v);
    }
    return graph;
}
int main(){
    vector<pair<int,int>> input;

    int points,x,y;
    cin>>points;
    for(int i=0 ; i<points ; i++){
        cin>>x>>y;
        input.push_back({x,y});
    }
    //Input [(0,1),(1,2),(1,3),(2,3)]--->edge list representation
    //Printing the graph
    unordered_map<int,vector<int>> graph=createGraph(input);
    for(auto i: graph){
        cout<<i.first<<"->";
        for( int j: i.second){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return  0;
}