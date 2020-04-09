#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    vector<int> *adj;
    int N;
    bool directed;

public:
    Graph(int N, bool directed = false)
    {
        this->N = N;
        adj = new vector<int>[N];
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

    ~Graph()
    {
        delete[] adj;
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
    return 0;
}