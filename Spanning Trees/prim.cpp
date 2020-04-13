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

    void add_edge(int a, int b, int w)
    {
        a = --a;
        b = --b;
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

    void prims()
    {
        // jodi visited baire dao tahole starting node true set kore diba na naile loop e dhukbe na
        int distances[N];
        bool visited[N];
        for (int i = 0; i < N; i++)
        {
            distances[i] = INT_MAX;
            visited[i] = false;
        }
        distances[0] = 0;
        priority_queue<pair<int, int>> queue;
        vector<tuple<int, int>> tree[N];
        queue.push({0, 0});

        while (!queue.empty()) // O(n + mlogm )
        {
            pair<int, int> p = queue.top();
            queue.pop();
            int s = p.second;

            if (visited[s])
                continue;
            else
                visited[s] = true;

            for (auto u : adj[s])
            {
                int b = u.first;
                int w = u.second;
                if (distances[s] + w < distances[b])
                {
                    distances[b] = distances[s] + w;
                    queue.push({-distances[b], b}); 
                    tree[s].push_back({b, w});
                    tree[b].push_back({s, w});
                }
            }
        }


        cout << "Output Tree: " << endl;

        for (int i = 0; i < N; i++)
        {
            cout << (i + 1) << " : ";
            for (auto u : tree[i])
            {
                int b, w;
                tie(b, w) = u;
                printf("(%d,%d) ", b + 1, w);
            }
            cout << endl;
        }
    }

    ~Graph()
    {
        delete[] adj;
    }
};

int main()
{
    Graph graph(6);
    graph.add_edge(1, 5, 5);
    graph.add_edge(3, 6, 3);
    graph.add_edge(1, 2, 3);
    graph.add_edge(4, 6, 7);
    graph.add_edge(2, 5, 6);
    graph.add_edge(2, 3, 5);
    graph.add_edge(5, 6, 2);
    graph.add_edge(3, 4, 9);
    //g.printGraph();
    graph.prims();
    return 0;
}