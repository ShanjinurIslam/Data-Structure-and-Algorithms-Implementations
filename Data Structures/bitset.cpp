#include <bits/stdc++.h>

using namespace std;

int main()
{
    bitset<10> s;
    s[1] = 1;
    s[3] = 1;
    s[4] = 1;
    s[7] = 1;
    cout << s << "\n";

    bitset<10> s1(string("01010"));
    cout << s1 << "\n";

    cout << (s | s1) << "\n";  //or
    cout << (s & s1) << "\n";  //and
    cout << (s ^ s1) << "\n";  //xor
    cout << (s << 4) << "\n";  //leftshift
    cout << (s >> 4) << "\n";  //leftshift
    cout << ~(s ^ s1) << "\n"; //xor

    return 0;
}