// space complexity = O(N2), can not be used when graph is large

#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int N;
    int **matrix;
    bool directed;

public:
    Graph(int N, bool directed = false)
    {
        this->N = N;
        this->directed = directed;
        this->matrix = new int *[N]; // number of rows
        for (int i = 0; i < N; i++)
        {
            matrix[i] = new int[N]; // number of columns
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int a, int b, int weight = 1)
    {
        if (directed)
        {
            matrix[a][b] = weight;
        }
        else
        {
            matrix[a][b] = weight;
            matrix[b][a] = weight;
        }
    }

    void printGraph()
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void floyd_warshall() //Run time O(N3)
    {
        int distances[N][N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    distances[i][j] = 0;
                }
                else if (matrix[i][j])
                {
                    distances[i][j] = matrix[i][j];
                }
                else
                {
                    distances[i][j] = 1000007;
                }
            }
        }

        for (int k = 0; k < N; k++)
        {
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cout << distances[i][j] << " ";
            }
            cout << "\n";
        }
    }

    ~Graph()
    {
        delete[] matrix;
    }
};

int main()
{
    Graph g(4, true);
    g.addEdge(0, 1, 5);
    g.addEdge(3, 0, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 5);
    g.addEdge(2, 3, 7);
    g.printGraph();
    cout<<"\n" ;
    g.floyd_warshall();
    return 0;
}