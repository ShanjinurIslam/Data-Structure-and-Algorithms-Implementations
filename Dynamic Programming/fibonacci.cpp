#include <bits/stdc++.h>

using namespace std;
typedef long long ll ;


bool ready[10000] = {false};
ll value[10000] = {0};

ll fib(int n)
{
    if (n == 1)
    {
        ready[1] = true;
        return value[1];
    }
    else if (n == 2)
    {
        ready[2] = true;
        value[2] = 1 ;
        return value[2];
    }

    else if(ready[n]){
        return value[n] ;
    }

    else{
        ready[n] = true ;
        value[n] = fib(n - 1) + fib(n - 2);
        return value[n] ;
    }
}

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        cout << fib(i) << "\n";
    }
    return 0;
}