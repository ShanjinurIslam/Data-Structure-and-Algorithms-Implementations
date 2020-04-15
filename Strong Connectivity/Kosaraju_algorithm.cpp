#include <bits/stdc++.h>

using namespace std;

class Graph
{
    vector<int> *adj;
    vector<int> *reverse;
    int N;
    bool directed;
    int *start;
    int *fin;
    bool *visited;
    int time;
    stack<int> fin_order;

public:
    Graph(int N, bool directed)
    {
        this->N = N;
        this->directed = directed;
        adj = new vector<int>[N];
        reverse = new vector<int>[N];

        start = new int[N];
        fin = new int[N];
        visited = new bool[N];
    }

    void addEdge(int a, int b)
    {
        --a;
        --b;
        if (directed)
        {
            adj[a].push_back(b);
            reverse[b].push_back(a);
        }
        else
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
            reverse[b].push_back(a);
            reverse[a].push_back(b);
        }
    }

    void dfs_visit(vector<int> *adj, int i, bool flag)
    {
        if (visited[i])
            return;
        visited[i] = true;
        time = time + 1;
        start[i] = time;

        if (flag)
        {
            cout << i + 1 << " ";
        }

        for (auto u : adj[i])
        {
            dfs_visit(adj, u, flag);
        }
        time = time + 1;
        fin[i] = time;
        fin_order.push(i);
    }

    void Kosaraju()
    {
        for (int i = 0; i < N; i++)
        {
            start[i] = 0;
            fin[i] = 0;
            visited[i] = false;
        }
        time = 0;
        for (int i = 0; i < N; i++)
        {
            dfs_visit(this->adj, i, false);
        }
        //adj = reverse;
        for (int i = 0; i < N; i++)
        {
            start[i] = 0;
            fin[i] = 0;
            visited[i] = false;
        }

        cout << "Strongly Connected Components: " << endl;
        while (!fin_order.empty())
        {
            int s = fin_order.top();
            fin_order.pop();
            dfs_visit(this->reverse, s, true);
            cout << endl;
        }
    }

    ~Graph()
    {
        delete[] adj;
        delete[] reverse;
        delete[] start;
        delete[] fin;
        delete[] visited;
    }
};

int main()
{
    Graph g(7, true);
    g.addEdge(1, 2);
    g.addEdge(2, 1);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(5, 4);
    g.addEdge(3, 2);
    g.addEdge(6, 3);
    g.addEdge(6, 5);
    g.addEdge(3, 7);
    g.addEdge(7, 6);
    g.Kosaraju();
    return 0;
}