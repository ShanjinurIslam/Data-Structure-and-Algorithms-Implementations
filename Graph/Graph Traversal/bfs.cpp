#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    vector<int> *adj;
    int N;
    bool directed;
    bool *visited;
    int  *distance;

    void dfs_visit(int u)
    {
        if (visited[u])
            return;
        visited[u] = true;
        cout << u << " ";
        for (auto n : adj[u])
        {
            dfs_visit(n);
        }
    }

public:
    Graph(int N, bool directed = false)
    {
        this->N = N;
        adj = new vector<int>[N];
        visited = new bool[N];
        distance = new int[N];
        this->directed = directed;
    }

    void addEdge(int a, int b)
    {
        if (directed)
        {
            adj[a].push_back(b);
        }
        else
        {
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }

    void printGraph()
    {
        for (int i = 0; i < this->N; i++)
        {
            cout << i << ": ";
            for (int j = 0; j < adj[i].size(); j++)
            {
                cout << adj[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void bfs(int starting_node){
        //iterative approach
        //will have a distance array to calculate distance of each node from starting node
        //queue is required
        queue<int> q ;
        
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
            distance[i] = 0 ;
        }

        visited[starting_node] = true ;
        distance[starting_node] = 0 ;
        q.push(starting_node) ;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto u:adj[top]){
                if(visited[u]) continue;
                visited[u] = true ;
                distance[u] = distance[top] + 1 ; //
                q.push(u) ;
            }
        }

    }

    void dfs(int starting_node)
    {
        // DFS follows a single path in the graph as long as it finds new nodes. After this, it returns to previous nodes and begins to explore others parts of the graph
        // keeps track of the visited nodes
        // time complexity of DFS is O(n+m) n-> nodes m-> edges because dfs processes each node and edges exactly once
        for (int i = 0; i < N; i++)
        {
            visited[i] = false;
        }
        dfs_visit(starting_node);
    }

    ~Graph()
    {
        delete[] adj;
        delete[] visited;
        delete[] distance;
    }
};

int main()
{
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 5);
    g.addEdge(1, 4);
    g.addEdge(0, 3);
    g.printGraph();
    g.bfs(0);
    return 0;
}