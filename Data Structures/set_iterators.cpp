/*
The main advantage of an iterator is to provide a common interface for all the containers type vector,set,map
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s = {5,-1,2,1};
    set<int>::iterator it = s.begin();
    //auto it = s.begin() ;

    cout << *it << endl;

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout<<"\n" ;
    // to get the largest value ;

    it = s.end() ;
    int largest = *(--it) ;
    cout<<largest<<"\n" ;

    // to find an element in the container

    it = s.find(5) ;
    if(it!=s.end()){
        // 5 is found 
    }
    return 0;
}