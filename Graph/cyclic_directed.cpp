#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

bool isCyclicBFS(int node, unordered_map<int, vector<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &bfsCall) {
    visited[node] = true;
    bfsCall[node] = true;
    for (auto neighbours : adj[node]) {
        if (!visited[neighbours]) {
            bool cycleDetected = isCyclicBFS(neighbours, adj, visited, bfsCall);
            if (cycleDetected)
                return true;
        }
        // else when visited[negihbours]=true && bfsCall[neighbours]=true
        else if (bfsCall[neighbours]) {
            return true;
        }
    }
    bfsCall[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<vector<int>> &edges) {
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v); // directed graph
    }
    unordered_map<int, bool> visited;
    unordered_map<int, bool> bfsCall;

    for (int i = 0; i < n; i++) {
        while (!visited[i]) {
            bool isCycleDetected = isCyclicBFS(i, adj, visited, bfsCall);
            if (isCycleDetected)
                return 1;
        }
    }
    return 0;
}
int main() {
    // vector<vector<int>> edges = {{1, 4}, {4, 3}, {3, 1}};
    vector<vector<int>> edges = {{4}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int V = 5;
    cout << detectCycleInDirectedGraph(V, edges);
    return 0;
}