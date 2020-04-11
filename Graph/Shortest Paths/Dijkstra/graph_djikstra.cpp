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

    void dijkstra(int starting_node)
    {
        // jodi visited baire dao tahole starting node true set kore diba na naile loop e dhukbe na
        int distances[N];
        bool visited[N];
        for (int i = 0; i < N; i++)
        {
            distances[i] = INT_MAX;
            visited[i] = false;
        }
        distances[starting_node] = 0;
        priority_queue<pair<int, int>> queue;
        queue.push({0, starting_node});

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
                    queue.push({-distances[b], b}); //each node exactly once
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            cout << distances[i] << "\n";
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
    g.dijkstra(0);
    return 0;
}