#include <bits/stdc++.h>

using namespace std;

int main()
{
    priority_queue<int> coins;
    int sum;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c;
        cin >> c;
        coins.push(c);
    }

    cin >> sum;
    unordered_map<int, int> coin_map;
    int cur = 0;

    while (sum != 0)
    {
        int current = coins.top();
        coins.pop();
        int divide = sum / current;
        if (divide == 0)
        {
            continue;
        }
        else
        {
            sum -= divide * current;
            coin_map[current] = divide;
            cur += divide;
        }
    }

    for (auto u : coin_map)
    {
        cout << u.first << " " << u.second << "\n";
    }

    cout << cur << "\n";

    return 0;
}