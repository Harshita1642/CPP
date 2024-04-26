#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ifstream f("gengraf.in");
ofstream g("gengraf.out");

vector<vector<int>> adjacencyMatrix;
int n;

void printGraph() {
    for (const auto& row : adjacencyMatrix) {
        for (int val : row) {
            cout<< val << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void generateGraphs(int vertex, int numEdges) {
    if (vertex == n) {
        printGraph();
        return;
    }

    for (int i = 0; i < numEdges; ++i) {
        adjacencyMatrix[vertex][i] = 1;
        generateGraphs(vertex + 1, i + 1);
        adjacencyMatrix[vertex][i] = 0;
    }
}

int main() {
    cin>>n;
    int numPossibleEdges = (n * (n - 1)) / 2;
    cout<< pow(2, numPossibleEdges) << endl;

    adjacencyMatrix.resize(n, vector<int>(n, 0));
    generateGraphs(0, n - 1);

    return 0;
}
