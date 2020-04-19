#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    for (auto u : s)
    {
        cout << u << " ";
    }
    cout << "\n";

    cout << s.count(5) << endl; // number of occurances of an element in the set returns only 0 or 1

    s.erase(s.find(5)); // to remove one occurance
    s.erase(5);         // removes all occurances of 5

    return 0;
}