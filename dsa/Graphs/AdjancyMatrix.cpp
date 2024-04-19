#include<iostream>
#include<vector>
using namespace std;
int main(){
    int vertices=4;
    vector<vector<int>> edges={{0,1},{1,2},{1,3},{2,3}};
    vector<vector<int>> graph(vertices,vector<int>(vertices,0));
    for( auto edge: edges){
        graph[edge[0]][edge[1]]=1;
        graph[edge[1]][edge[0]]=1;
    }
    for(auto i: graph){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}