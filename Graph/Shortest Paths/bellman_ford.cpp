#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    vector<tuple<int, int, int>> edges;
    int N;
    int *distances;

public:
    Graph(int N)
    {
        this->N = N;
        distances = new int[N];
    }

    void add_edge(int a, int b, int w)
    {
        edges.push_back(make_tuple(--a, --b, w));
    }

    void bellman_ford(int starting_node)
    {
        for (int i = 0; i < N; i++)
        {
            distances[i] = INFINITY;
        }
        distances[starting_node] = 0;

        for (int i = 0; i < N; i++)
        {
            for (auto e : edges)
            {
                int a, b, w;
                tie(a, b, w) = e;

                distances[b] = min(distances[b], distances[a] + w);
            }
        }

        for(int i=0;i<N;i++){
            cout<<distances[i]<<endl ;
        }
    }

    ~Graph()
    {
        delete[] distances;
    }
};

int main()
{
    int N = 5;
    Graph g(N);
    g.add_edge(1, 2, 5);
    g.add_edge(1, 3, 3);
    g.add_edge(3, 4, 1);
    g.add_edge(1, 4, 7);
    g.add_edge(2, 4, 3);
    g.add_edge(2, 5, 2);
    g.add_edge(4, 5, 2);
    g.bellman_ford(0);
    return 0;
}