#include <bits/stdc++.h>

using namespace std;

stack<int> s;

class Graph
{
private:
    vector<int> *graph;
    bool directed;
    bool has_cycle;
    int N;
    int *node_color;

public:
    Graph(int N, bool directed = false)
    {
        this->N = N;
        this->directed = directed;
        graph = new vector<int>[N];
        node_color = new int[N];
    }

    void addEdge(int a, int b)
    {
        if (directed)
        {
            graph[a].push_back(b);
        }
        else
        {
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
    }

    void dfs_visit(int i)
    {
        if (node_color[i] == 0)
        {
            node_color[i] = 1;
        }
        else if (node_color[i] == 1)
        {
            has_cycle = true;
            return;
        }
        else
        {
            return;
        }
        for (auto u : graph[i])
        {
            dfs_visit(u);
        }
        node_color[i] = 2;
        if (!has_cycle && node_color[i] == 2)
        {
            s.push(i);
        }
    }

    void topological_sort()
    {
        // if graph contains a cycle then no topological sorting can be found
        // if the graph is acyclic then a simple dfs would return an ordering
        while (!s.empty())
        {
            s.pop();
        }
        has_cycle = false;
        int num_paths[N];
        for (int i = 0; i < N; i++)
        {
            node_color[i] = 0;
            num_paths[i] = 0;
        }
        int starting_node = 0;
        dfs_visit(starting_node);

        num_paths[starting_node] = 1;
        if (!has_cycle)
        {
            while (!s.empty())
            {
                int a = s.top();
                s.pop();
                for (auto u : graph[a])
                {
                    num_paths[u] += num_paths[a];
                }
                cout << a << " ";
            }
            cout << "\n";

            for (int i = 0; i < N; i++)
            {
                cout<<i<<" "<<num_paths[i]<<"\n" ;
            }
        }
        else
        {
            cout << "the graph has cycle" << endl;
        }
    }

    ~Graph()
    {
        delete[] graph;
        delete[] node_color;
    }
};

int main()
{
    Graph g(6, true);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2);
    g.addEdge(4, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 5);
    g.topological_sort();
    return 0;
}