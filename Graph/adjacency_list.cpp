#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

void adjListVector(vector<vector<int>> &edg, vector<vector<int>> &adj) {

    for (int i = 0; i < edg.size(); i++) {
        int u = edg[i][0];
        int v = edg[i][1];
        adj[u].push_back(v);
        // adj[v].push_back(u); // coz this is an undirected graph
    }

    // display
    for (int i = 0; i < adj.size(); i++) {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

void adjListMap(vector<vector<int>> &edges, unordered_map<int, set<int>> &adj) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].insert(v);
        // adj[v].insert(u);
    }
    for (auto i : adj) {
        cout << i.first << " -> ";
        for (auto j : i.second)
            cout << j << ", ";
        cout << endl;
    }
}

int main() {
    // Using Vector
    vector<vector<int>> edg1 = {{0, 1}, {0, 3}, {1, 2}, {2, 3}};
    int vertex1 = 4;
    vector<vector<int>> edg2 = {{0, 1}, {0, 4}, {1, 2}, {2, 0}, {2, 4}, {3, 0}, {3, 2}, {4, 3}};
    int vertex2 = 5;
    vector<vector<int>> adj1(vertex1);
    vector<vector<int>> adj2(vertex2);
    adjListVector(edg1, adj1);
    cout << endl;
    adjListVector(edg2, adj2);

    return 0;
}