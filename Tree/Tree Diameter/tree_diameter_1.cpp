// tree diameter is the maximum length of path between any two nodes

// Algorithm 1

// choose any node as root
// try to solve each subtree separately ( Dynamic Programming )

#include <bits/stdc++.h>

using namespace std;

class Tree
{
private:
    vector<int> *list;
    vector<int> *temp;
    int N;
    int *max_dist_to_leaf;
    int *max_length;

public:
    Tree(int N)
    {
        this->N = N;
        this->list = new vector<int>[N];
        this->temp = new vector<int>[N];

        this->max_dist_to_leaf = new int[N];

        for (int i = 0; i < N; i++)
        {
            max_dist_to_leaf[i] = 0;
        }
    }

    void addEdge(int a, int b)
    {
        list[a].push_back(b);
        list[b].push_back(a);
        temp[a].push_back(b);
    }

    void dfs(int s, int e)
    {

        for (auto u : list[s])
        {
            if (u != e)
            {
                dfs(u, s);
                int current = max_dist_to_leaf[u] + 1;
                max_dist_to_leaf[s] = max(max_dist_to_leaf[s], current);
            }
            else
            {
                max_dist_to_leaf[s] = 0;
            }
        }
    }

    void print_graph()
    {
        for (int i = 0; i < N; i++)
        {
            cout << i << ": ";
            for (auto u : list[i])
            {
                cout << u << " ";
            }
            cout << "\n";
        }
    }

    void get_distances()
    {
        dfs(0, 0);
        for (int i = 0; i < N; i++)
        {
            cout << i << " " << max_dist_to_leaf[i] << endl;
        }
    }

    int to_leaf(int x)
    {
        return max_dist_to_leaf[x];
    }

    void get_diameter()
    {
        dfs(0, 0);
        vector<int> highest_points;
        for (int i = 0; i < N; i++)
        {
            if (!max_dist_to_leaf[i])
            {
                highest_points.push_back(i);
            }
        }
        int maximum = -1;
        for (int i = 0; i < highest_points.size(); i++)
        {
            int children = temp[i].size();
            if (children < 2)
            {
                maximum = max(maximum, temp[i][0]+1);
            }
            else
            {
                for (int j = 0; j < temp[i].size() - 1; j++)
                {
                    for (int k = 1; k < temp[i].size(); k++)
                    {
                        if(temp[i][j]!=temp[i][k]){
                            maximum = max(maximum, (to_leaf(temp[i][j]) + to_leaf(temp[i][k]))+2) ;
                        }
                    }
                }
            }
        }

        cout << maximum << endl;
    }

    ~Tree()
    {
        delete[] list;
        delete[] max_dist_to_leaf;
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