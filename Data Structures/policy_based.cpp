#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
    indexed_set s;
    s.insert(2);
    s.insert(5);
    s.insert(7);
    s.insert(-2);

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";

    auto x = s.find_by_order(2) ; // find by index 

    cout<<*x<<"\n" ; // returns an iterator 

    int val = s.order_of_key(2) ; // find by index 

    cout<<val<<"\n" ; // returns an iterator 

    
}