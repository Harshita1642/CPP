#include<iostream>
#include<vector>
using namespace std;

void generateGraphs(int n, int i, vector<vector<int>> &graph,vector<bool> &vis) {
    // Base case
    if (i == n - 1) {
        // Print the graph
        for (int m = 0; m < graph.size(); m++) {
            cout << m << "->";
            for (int p = 0; p < graph[m].size(); p++) {
                cout << graph[m][p] << " ";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    vis[i]=true;
    // Include ith index in the graph
    for (int j = 0; j < n; j++) {
        if(!vis[j] ){
            graph[i].push_back(j);
            graph[j].push_back(i);
            vis[j]=true;
            generateGraphs(n, i+1, graph,vis);

            // Backtrack
            graph[i].pop_back();
            graph[j].pop_back();
            vis[j]=false;
        }
    }

    // Exclude ith index in the graph
    generateGraphs(n, i + 1, graph,vis);
}

int main() {
    int n; // n is the number of vertices here
    cin >> n;
    vector<vector<int>> graph(n);
    vector<bool> vis(n,false);
    generateGraphs(n, 0, graph,vis);
    return 0;
}
