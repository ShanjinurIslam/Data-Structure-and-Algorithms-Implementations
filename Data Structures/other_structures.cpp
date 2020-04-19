#include <bits/stdc++.h>

using namespace std;

int main()
{
    deque<int> d;
    queue<int> q;
    stack<int> s;
    priority_queue<int, vector<int>, greater<int>> pq; // finding and removing the smallest element

    d.push_back(3);
    q.push(3);
    s.push(3);
    pq.push(3);

    d.push_front(5);
    q.push(5);
    s.push(5);
    pq.push(5);

    d.push_front(7);
    q.push(7);
    s.push(7);
    pq.push(7);

    d.push_back(2);
    q.push(2);
    s.push(2);
    pq.push(2);

    cout << d.front() << "\n";
    cout << q.front() << "\n";
    cout << s.top() << "\n";
    cout << pq.top() << "\n";

    for (auto u : d)
    {
        cout << u << " ";
    }
    cout << "\n";

    //every structure contains pop
    return 0;
}