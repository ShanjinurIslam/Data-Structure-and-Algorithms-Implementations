#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    for (auto u : v)
    {
        cout << u << "\n";
    }

    int v = v.back(); // returns last element
    v.pop_back();     // removes last element

    v = {1,3,4,5,6} ;
    
    vector<int> new_vector(10,0) ; // vector of size 10 initial value of 0 
    return 0;
}