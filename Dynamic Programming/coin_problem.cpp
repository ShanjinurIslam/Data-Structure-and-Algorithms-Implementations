#include <bits/stdc++.h>

using namespace std ;

int ready[10000] ;
int value[10000] ;

vector<int> coins = {1,3,4} ;

int solve(int x){
    if(x<0) return 10000007 ;
    if(x==0) return 0 ;
    int best = 10000007 ;
    for(auto u:coins){
        best = min(best,solve(x-u)+1) ;
    }
    return best ;
}

int main(){
    cout<<solve(6)<<"\n" ;
    return 0 ;
}