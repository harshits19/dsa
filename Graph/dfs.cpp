#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

void adjList(vector<vector<int>> &edges, unordered_map<int, set<int>> &adj)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].insert(v);
        adj[v].insert(u);
    }
}
void dfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, vector<int> &comp, int node)
{
    visited[node] = 1;
    comp.push_back(node);
    // adding all the child nodes
    for (auto a : adj[node])
    {
        if (!visited[a])
        {
            dfs(adj, visited, comp, a);
        }
    }
}
void display(vector<vector<int>> res)
{
    for (vector<int> comp : res)
    {
        for (int i : comp)
            cout << i << " ";
        cout << endl;
    }
}
int main()
{
    // vector<vector<int>> edges = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}, {9, 0}};
    // int V = 9, E = 10;
    vector<vector<int>> edges = {{9, 0}, {8, 1}, {7, 2}, {6, 3}, {5, 4}};
    int V = 5, E = 10;

    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited; // by-defalut set to false for every
    vector<vector<int>> res;
    adjList(edges, adj);
    for (int i = 0; i < V; i++)
    { // for all components of disconnected graph, we traverse each vertex
        if (!visited[i])
        {
            vector<int> comp; // component
            dfs(adj, visited, comp, i);
            res.push_back(comp);
        }
    }
    display(res);
    return 0;
}