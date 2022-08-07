#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

// implementing graph using unordered map
// map key -> (nodes) value -> {connected nodes}
class graph1
{
public:
    // making an adjencary list for a graph
    unordered_map<int, vector<int>> adj;
    void insertEdge(int u, int v, bool dir)
    {
        // dir= direction
        // 1-> directed graph, 0-> undirected graph
        adj[u].push_back(v);
        if (dir == 0) // if there's an undirected graph
            adj[v].push_back(u);
    }
    void display()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
                cout << j << ", ";
            cout << endl;
        }
    }
};
/* class graph2
{
public:
    int n=6;
    vector<vector<int>> adj(n);
    void insertEdge(int u, int v, bool dir)
    {
        vector<int> cols = {u, v};
        adj[u] = cols;
    }
}; */

int main()
{
    int nodes = 0, edges = 0;
    cout << "Enter no of nodes" << endl;
    cin >> nodes;
    cout << "Enter no of edges" << endl;
    cin >> edges;

    graph1 g;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g.insertEdge(u, v, 0);
    }
    g.display();
    return 0;
}

/*
Example :Undircted Graph
        0--------1 \
        |        |  \
        |        |   2
        |        |  /
        4--------3 /

    Adjacency list: (for undirected graph)
    Node  nodes connected
    0->     1,4
    1->     0,2,3
    2->     1,3
    3->     1,2,4
    4->     0,3

    Adjacency Matrix (for undirected graph)
       | 0  1  2  3  4
    ---|-----------------
    0  | 0  1  0  0  1
    1  | 1  0  1  1  0
    2  | 0  1  0  1  0
    3  | 0  1  1  0  1
    4  | 1  0  0  1  0

Input:
5
6
0 1
1 2
2 3
3 1
3 4
0 4
 */