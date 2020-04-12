// double dfs
// find fartest node from arbitary node
// then find fartest node from that fartest node
// easier than previous one

#include <bits/stdc++.h>

using namespace std;

class Tree
{
private:
    vector<int> *list;
    int N;
    int *distance;

public:
    Tree(int N)
    {
        this->N = N;
        this->list = new vector<int>[N];
        this->distance = new int[N];
    }

    void addEdge(int a, int b)
    {
        list[a].push_back(b);
        list[b].push_back(a);
    }

    void dfs(int s, int e)
    {
        for (auto u : list[s])
        {
            if (u != e)
            {
                distance[u] = distance[s] + 1;
                dfs(u, s);
            }
        }
    }

    void get_diameter()
    {
        for (int i = 0; i < N; i++)
        {
            distance[i] = 0;
        }

        
        dfs(0, 0);
        
        int max = -1;
        int index = -1;
        for (int i = 0; i < N; i++)
        {
            if (max < distance[i])
            {
                max = distance[i] ;
                index = i;
            }
        }
        
        distance[index] = 0;
        dfs(index, index);
        max = -1;
        for (int i = 0; i < N; i++)
        {
            if (max < distance[i])
            {
                max = distance[i] ;
            }
        }
        cout << max << endl;
        
    }

    ~Tree()
    {
        delete[] list;
        delete[] distance;
    }
};

int main()
{
    // N nodes, N-1 Edges
    Tree tree(7);
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(2, 3);
    tree.addEdge(1, 4);
    tree.addEdge(1, 5);
    tree.addEdge(5, 6);
    tree.get_diameter();
    return 0;
}