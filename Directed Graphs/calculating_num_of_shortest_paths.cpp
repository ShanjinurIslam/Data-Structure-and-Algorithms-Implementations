#include <bits/stdc++.h>

using namespace std;

stack<int> s;

class Graph
{
private:
    vector<pair<int, int>> *adj;
    vector<pair<int, int>> *graph;
    int **map;
    bool has_cycle;
    int *num_path;
    int N;
    bool directed;
    int *node_color;

public:
    Graph(int N, bool directed = false)
    {
        this->N = N;
        adj = new vector<pair<int, int>>[N];
        graph = new vector<pair<int, int>>[N];
        node_color = new int[N];
        this->directed = directed;
        num_path = new int[N];
        map = new int *[N];
        for (int i = 0; i < N; i++)
        {
            map[i] = new int[N];
        }
    }

    void add_edge(int a, int b, int w)
    {
        a = --a;
        b = --b;
        if (directed)
        {
            adj[a].push_back({b, w});
            map[a][b] = w;
        }
        else
        {
            adj[a].push_back({b, w});
            adj[b].push_back({a, w});
            map[a][b] = w;
            map[b][a] = w;
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
            num_path[i] = 0;
        }
        distances[starting_node] = 0;
        num_path[starting_node] = 1;
        priority_queue<tuple<int, int, int>> queue;
        queue.push({0, starting_node, starting_node});

        while (!queue.empty()) // O(n + mlogm )
        {
            tuple<int, int, int> p = queue.top();
            queue.pop();
            int w, a, s;
            tie(w, a, s) = p;
            if (visited[s])
            {
                if (s != starting_node)
                {
                    if (distances[s] == distances[a] + map[a][s])
                    {
                        graph[a].push_back({s, map[a][s]});
                    }
                }
                continue;
            }
            else
                visited[s] = true;
            if (s != starting_node)
            {
                graph[a].push_back({s, map[a][s]});
            }
            for (auto u : adj[s])
            {
                int b = u.first;
                int w = u.second;
                if (distances[s] + w <= distances[b])
                {
                    distances[b] = distances[s] + w;
                    queue.push({-distances[b], s, b});
                }
            }
        }

        cout << "Output Graph: " << endl;

        for (int i = 0; i < N; i++)
        {
            cout << (i + 1) << " : ";
            for (auto u : graph[i])
            {
                int b, w;
                tie(b, w) = u;
                printf("(%d,%d) ", b + 1, w);
            }
            cout << endl;
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
            dfs_visit(u.first);
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
            cout<<"Topological Sort :"<<endl; 
            while (!s.empty())
            {
                int a = s.top();
                s.pop();
                for (auto u : graph[a])
                {
                    num_paths[u.first] += num_paths[a];
                }
                cout << a << " ";
            }
            cout << "\n";

            cout<<"Number of shortest paths :"<<endl; 
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
        delete[] adj;
    }
};

int main()
{
    Graph graph(5, true);
    graph.add_edge(1, 2, 3);
    graph.add_edge(1, 3, 5);
    graph.add_edge(2, 3, 2);
    graph.add_edge(3, 4, 2);
    graph.add_edge(2, 4, 4);
    graph.add_edge(2, 5, 8);
    graph.add_edge(4, 5, 1);
    //g.printGraph();
    graph.dijkstra(0);
    graph.topological_sort();
    return 0;
}