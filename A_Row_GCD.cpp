#include <bits/stdc++.h>
using namespace std;

#define int long long 
void solution() {
    int n , m ; 
    cin>> n >> m ; 
    
    vector<int> a(n);
    for(int i = 0 ; i < n ;i++)cin>>a[i] ;

    int gg = 0 ; 
    for(int i = 1 ; i < n ;i++) gg = __gcd(gg, abs(a[i] - a[0]));

    for(int i = 0 ; i < m ;i++){
        int x ; 
        cin >> x; 
        cout<< (__gcd(gg,a[0]+x)) << " " ;
    }
    return ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solution();
    return 0;
}