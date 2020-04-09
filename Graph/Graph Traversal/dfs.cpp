#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    vector<int> *adj;
    int N;
    bool directed;
    bool *visited;

    void dfs_visit(int u)
    {
        if (visited[u])
            return;
        visited[u] = true;
        cout << u << " ";
        for (auto n : adj[u])
        {
            dfs_visit(n);
        }
    }

public:
    Graph(int N, bool directed = false)
    {
        this->N = N;
        adj = new vector<int>[N];
        visited = new bool[N];
        this->directed = directed;
    }

    void addEdge(int a, int b)
    {
        if (directed)
        {
            adj[a].push_back(b);
        }
        else
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    void printGraph()
    {
        for (int i = 0; i < this->N; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void dfs(int starting_node)
    {
        // DFS follows a single path in the graph as long as it finds new nodes. After this, it returns to previous nodes and begins to explore others parts of the graph
        // keeps track of the visited nodes
        // time complexity of DFS is O(n+m) n-> nodes m-> edges because dfs processes each node and edges exactly once
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
        }
        dfs_visit(starting_node);
    }

    ~Graph()
    {
        delete[] adj;
        delete[] visited;
    }
};

int main()
{
    Graph g(4, true);
    g.addEdge(0, 1);
    g.addEdge(3, 0);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.printGraph();
    g.dfs(0);
    return 0;
}