#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <utility>
using namespace std;

void bfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited, vector<int> &res, int node)
{
    queue<int> rq;
    rq.push(node);     // push the first node in queue
    visited[node] = 1; // mark true for visiting first node
    while (!rq.empty())
    {
        int frontNode = rq.front(); // push frontnode of queue in result array
        rq.pop();
        res.push_back(frontNode);

        // traverse thru all adjacent neighbours of frontNode
        for (auto i : adj[frontNode])
        {
            if (!visited[i])
            {
                rq.push(i);
                visited[i] = 1;
            }
        }
    }
}

void adjList(vector<pair<int, int>> &edges, unordered_map<int, set<int>> &adj)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].insert(v);
        adj[v].insert(u); // coz this is an undirected graph
    }
}

void display(vector<int> res)
{
    for (auto a : res)
        cout << a << " -> ";
    cout << endl;
}
int main()
{
    // vector<pair<int, int>> edg = {{0, 1}, {0, 3}, {1, 2}, {2, 3}};
    // int vertex = 4;
    vector<pair<int, int>> edg = {{0, 1}, {0, 4}, {1, 2}, {2, 0}, {2, 4}, {3, 0}, {3, 2}, {4, 3}};
    int vertex = 5;
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    vector<int> res;
    adjList(edg, adj);
    for (int i = 0; i < vertex; i++)
    {
        while (!visited[i])
        {
            bfs(adj, visited, res, i);
        }
    }
    display(res);
    return 0;
}