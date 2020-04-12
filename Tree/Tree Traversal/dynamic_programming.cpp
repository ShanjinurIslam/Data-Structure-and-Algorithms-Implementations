// Calculate number of nodes in the subtree

#include <bits/stdc++.h>

using namespace std;

class Tree
{
private:
    vector<int> *list;
    int N;
    int *count;

public:
    Tree(int N)
    {
        this->N = N;
        this->list = new vector<int>[N];
        this->count = new int[N];
    }

    void addEdge(int a, int b)
    {
        list[a].push_back(b);
        list[b].push_back(a);
    }

    void dfs_dynamic(int s, int e)
    {
        count[s] = 1;

        for (auto u : list[s])
        {
            if (u != e)
            {
                dfs_dynamic(u, s);
                count[s] += count[u];
            }
        }
    }

    void get_subtree_node_count(){
        for (int i = 0; i < N; i++)
        {
            cout << i<<" : "<<count[i] << "\n";
        }
    }

    ~Tree()
    {
        delete[] list;
        delete[] count;
    }
};

int main()
{
    // N nodes, N-1 Edges
    Tree tree(5);
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(2, 3);
    tree.addEdge(1, 4);
    tree.dfs_dynamic(0, 0);
    tree.get_subtree_node_count();
    return 0;
}