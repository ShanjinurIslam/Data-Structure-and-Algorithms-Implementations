// map is a data structure that contains key-value pair
// map["key"] = value
// two kinds of maps are available, map and unordered map O(log n) and O(1)

#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, int> m;
    m["monkey"] = 4;
    m["banana"] = 3;
    cout << m["banana"] << "\n";
    // if there is no value for a key then value is automatically set to zero (default value)
    if(m.count("orange")){
        cout<<"Key Exists\n" ;
    }

    for(auto x:m){
        cout<<x.first<<" "<<x.second<<"\n" ;
    }
    return 0;
}
