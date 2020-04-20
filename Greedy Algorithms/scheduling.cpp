//inputs must be given sequencially

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, pair<int, int>> schedule;
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        schedule[i] = make_pair(x, y);
        q.push(make_pair(x - y, i));
    }

    vector<pair<int, int>> curr;
    int current = 0;

    while (!q.empty())
    {
        pair<int, int> item;
        item = q.top();
        q.pop();
        int index = item.second;
        int duration = -1 * item.first;

        if (current > 0)
        {
            int prev_start_time = curr[current - 1].first;
            int next_finish_time = schedule[index].second;

            if (next_finish_time > prev_start_time)
            {
                continue;
            }
            else
            {
                curr.push_back(schedule[index]);
                current++;
            }
        }
        else
        {
            curr.push_back(schedule[index]);
            current++;
        }
    }

    reverse(curr.begin(), curr.end());

    cout << "\n";
    for (auto u : curr)
    {
        cout << u.first << " " << u.second << "\n";
    }

    return 0;
}