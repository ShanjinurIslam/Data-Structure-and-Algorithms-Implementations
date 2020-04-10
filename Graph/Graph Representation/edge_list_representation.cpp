#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    vector<tuple<int, int, int>> edges;
    int N ;
    int *distances ;
public:
    Graph(int N){
        this-> N = N ;
        distances = new int[N] ;
    }

    void add_edge(int a,int b,int w){
        edges.push_back(make_tuple(a,b,w)) ;
    }

    ~Graph(){
        delete[] distances ;
    }

};

int main()
{

    return 0;
}