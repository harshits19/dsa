#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> rq;

    rq.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!rq.empty())
    {
        int frontNode = rq.front();
        rq.pop();
        for (auto neighbours : adj[frontNode])
        {
            if (!visited[neighbours])
            {
                visited[neighbours] = true;
                parent[neighbours] = frontNode;
                rq.push(neighbours);
            }
        }
    }
    // a parent array is constructed which have shortest value from 1 node to another
    vector<int> path;
    int currNode = t;
    path.push_back(currNode);
    while (currNode != s)
    {
        currNode = parent[currNode];
        path.push_back(currNode);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    vector<int> path;
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    path = shortestPath(edges, 4, 4, 1, 4); // OP: 134
    /* vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {4, 6}, {6, 7}, {3, 8}, {4, 8}, {7, 8}};
    path = shortestPath(edges, 8, 9, 1, 8); // OP: 138 */
    /* vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 8}, {3, 8}, {4, 6}, {6, 7}, {7, 8}};
    path = shortestPath(edges, 8, 9, 1, 8); //OP : 138 */
    for (auto a : path)
        cout << a << " ";
    cout << endl;
    return 0;
}