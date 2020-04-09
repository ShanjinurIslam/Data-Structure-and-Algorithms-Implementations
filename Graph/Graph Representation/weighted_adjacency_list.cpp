#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    vector<pair<int, int>> *adj;
    int N;
    bool directed;

public:
    Graph(int N, bool directed = false)
    {
        this->N = N;
        adj = new vector<pair<int, int>>[N];
        this->directed = directed;
    }

    void addEdge(int a, int b, int w)
    {
        if (directed)
        {
            adj[a].push_back({b, w});
        }
        else
        {
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
        }
    }

    void printGraph()
    {
        for (int i = 0; i < this->N; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << "(" << adj[i][j].first << "," << adj[i][j].second << ")"
                     << " ";
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
    g.addEdge(0, 1, 5);
    g.addEdge(3, 0, 7);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 5);
    g.addEdge(2, 3, 2);
    g.printGraph();
    return 0;
}