#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> s = {1, 3, 4, 5, 6};
    random_shuffle(s.begin(), s.end());
    for (auto u : s)
    {
        cout << u << " ";
    }
    cout << "\n";
    sort(s.begin(), s.end());
    for (auto u : s)
    {
        cout << u << " ";
    }
    cout << "\n";
    reverse(s.begin(), s.end());
    for (auto u : s)
    {
        cout << u << " ";
    }
    cout << "\n";
    return 0;
}