#include <bits/stdc++.h>

using namespace std;

class Tree
{
private:
    vector<int> *list;
    int N;

public:
    Tree(int N)
    {
        this->N = N;
        this->list = new vector<int>[N];
    }

    void addEdge(int a, int b)
    {
        list[a].push_back(b);
        list[b].push_back(a);
    }

    void dfs(int s, int e)
    {
        cout << s << endl;
        for (auto u : list[s])
        {
            if (u != e)
            {
                dfs(u, s);
            }
        }
    }

    ~Tree()
    {
        delete[] list;
    }
};

int main()
{
    // N nodes, N-1 Edges
    Tree tree(5) ;
    tree.addEdge(0,1);
    tree.addEdge(0,2);
    tree.addEdge(2,3);
    tree.addEdge(1,4);
    tree.dfs(0,0) ;
    return 0;
}