#include <iostream>
#include <vector>
#include <numeric> //std::iota

using namespace std;

int main()
{
    std::vector<int> x(10);
    std::iota(std::begin(x), std::end(x), 0);
    for(auto u:x){
        cout<<u<<" " ;
    }
    cout<<"\n" ;
    return 0;
}