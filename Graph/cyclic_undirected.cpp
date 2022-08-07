#include <iostream>
#include <set>
#include <queue>
#include <unordered_map>
#include <vector>

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

bool isCyclicBFS(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, int srcNode)
{
    unordered_map<int, int> parent; // to tract the parent of node
    queue<int> rq;                  // ready queue to have the nodes
    rq.push(srcNode);
    visited[srcNode] = 1;
    parent[srcNode] = -1;
    while (!rq.empty())
    {
        int front = rq.front();
        rq.pop();
        for (auto neighbours : adj[front])
        {
            if (visited[neighbours] == true && neighbours != parent[front])
            {
                return true;
            }
            else if (!visited[neighbours])
            {
                rq.push(neighbours);
                visited[neighbours] = 1;
                parent[neighbours] = front;
            }
        }
    }
    return false;
}

bool isCyclicDFS(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, int srcNode, int parent)
{
    visited[srcNode] = 1;
    for (auto childNode : adj[srcNode])
    {
        if (!visited[childNode])
        {
            bool isCycleDetected = isCyclicDFS(adj, visited, childNode, srcNode);
            if (isCycleDetected)
                return true;
        }
        else if (childNode != parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    // first create an adjacency list
    adjList(edges, adj);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicBFS(adj, visited, i);
            // bool ans = isCyclicDFS(adj, visited, i, -1); //-1 is parent of sourceNode
            if (ans == true)
                return "Yes";
        }
    }
    return "No";
}

int main()
{
    // vector<vector<int>> edges = {{9, 0}, {8, 1}, {7, 2}, {6, 3}, {5, 4}};
    // int V = 5, E = 10;
    vector<vector<int>> edges = {{1, 4}, {4, 3}, {3, 1}};
    int V = 3, E = 4;
    cout << cycleDetection(edges, V, E);

    return 0;
}