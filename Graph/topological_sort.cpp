#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void adjList(vector<vector<int>> &adj, vector<vector<int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
void topSort(int node, vector<vector<int>> &adj, stack<int> &s, vector<bool> &visited) {
    visited[node] = true;
    for (auto neighbours : adj[node]) {
        if (!visited[neighbours]) {
            topSort(neighbours, adj, s, visited);
        }
    }
    s.push(node);
}
int main() {
    // vector<vector<int>> edg = {{0, 1}, {0, 2}};
    // int vertex = 3;
    vector<vector<int>> edg = {{0, 1}, {0, 3}, {1, 2}, {3, 2}};
    int vertex = 4;
    vector<vector<int>> adj(vertex);
    adjList(adj, edg);
    vector<bool> visited(vertex);
    stack<int> s;

    for (int i = 0; i < vertex; i++) {
        if (!visited[i])
            topSort(i, adj, s, visited);
    }

    vector<int> res;
    while (!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    cout << "Topological Order : ";
    for (auto a : res)
        cout << a << " ";

    return 0;
}