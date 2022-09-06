#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> edg = {{0, 1}, {0, 3}, {1, 2}, {2, 3}};
    // int vertex = 4;
    // vector<pair<int, int>> edg = {{0, 1}, {0, 4}, {1, 2}, {2, 0}, {2, 4}, {3, 0}, {3, 2}, {4, 3}};
    int vertex = 4;
    vector<vector<int>> adj(vertex);
    // adjList(edg, adj);
    for (int i = 0; i < edg.size(); i++) {
        int u = edg[i][0];
        int v = edg[i][1];
        adj[u].push_back(v);
        // adj[v].push_back(u); // coz this is an undirected graph
    }
    for (int i = 0; i < adj.size(); i++) {
        cout << i << "->";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}