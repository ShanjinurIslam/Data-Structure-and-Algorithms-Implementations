// There are two kind of sets implementations in C++
// set which manages a balanced binary tree O(log n) on average
// unordered set which uses hashing O(1) on average

#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;
    s.insert(3) ;
    s.insert(2) ;
    s.insert(5) ;
    s.insert(5) ;
    s.insert(5) ;
    for(auto u:s){
        cout<<u<<" ";
    }
    cout<<"\n" ;

    cout<<s.count(5)<<endl ; // number of occurances of an element in the set returns only 0 or 1
    return 0;
}