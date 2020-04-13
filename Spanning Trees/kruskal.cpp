//implementing using union find structure

#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    priority_queue<tuple<int, int, int>> edges;
    int N;
    int *link;
    int *size;

public:
    Graph(int N)
    {
        this->N = N;
        link = new int[N + 1];
        size = new int[N + 1];
    }

    void add_edge(int a, int b, int w)
    {
        edges.push(make_tuple(-w, a, b));
    }

    void print_graph()
    {
        priority_queue<tuple<int, int, int>> new_edges = edges;
        for (; !new_edges.empty();)
        {
            tuple<int, int, int> e = new_edges.top();
            new_edges.pop();
            int w, a, b;
            tie(w, a, b) = e;
            cout << a << " " << b << " " << -w << "\n";
        }
    }

    int find(int x)
    {
        while (x != link[x])
        {
            x = link[x]; // finds the representator node of the component, length = log(N)
        }
        return x;
    }

    bool same(int a, int b)
    {
        return find(a) == find(b);
    }

    void unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (size[a] < size[b])
            swap(a, b);
        size[a] += size[b];
        link[b] = a;
    }

    void Kruskal()
    {
        for (int i = 1; i <= N; i++)
        {
            link[i] = i; // disjoint set
            size[i] = 1; // size of each component ;
        }

        priority_queue<tuple<int, int, int>> new_edges = edges;
        vector<tuple<int, int>> tree[N + 1];
        for (; !new_edges.empty();)
        {
            tuple<int, int, int> e = new_edges.top();
            new_edges.pop();
            int w, a, b;
            tie(w, a, b) = e;
            if (!same(a, b))
            {
                unite(a, b);
                tree[a].push_back({b, -w});
                tree[b].push_back({a, -w});
            }
        }

        cout << "Output Tree: " << endl;

        for (int i = 1; i <= N; i++)
        {
            cout << i << " : ";
            for (auto u : tree[i])
            {
                int b, w;
                tie(b, w) = u;
                printf("(%d,%d) ", b, w);
            }
            cout << endl;
        }
    }

    ~Graph()
    {
        delete[] link;
        delete[] size;
    }
};

int main()
{
    int N;
    N = 6;
    Graph graph(N);
    graph.add_edge(1, 5, 5);
    graph.add_edge(3, 6, 3);
    graph.add_edge(1, 2, 3);
    graph.add_edge(4, 6, 7);
    graph.add_edge(2, 5, 6);
    graph.add_edge(2, 3, 5);
    graph.add_edge(5, 6, 2);
    graph.add_edge(3, 4, 9);
    graph.Kruskal();
    return 0;
}