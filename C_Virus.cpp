#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solution() {
    ll  n , m ; cin >> n >> m ; 
    vector<ll> a(m);
    for(ll &x : a ) cin >> x ; 

    sort(a.begin() , a.end());
    vector<ll> d;
    d.push_back(a[0] + n -a[m-1]-1);

    for(int i = 1 ; i < m ; i++){
        d.push_back(a[i] - a[i-1] - 1);
    }
    sort(d.begin() , d.end() , greater<ll>());

    ll ans = 0, day = 0 ; 
    for(ll i = 0 ; i < m ; i++){
        ll x = d[i] - 2*day  ;
        if(x ==1 || x==2  ){ ans += 1 ; day++; }
        else if(x > 0 ) {ans += x -1 ;
        day+=2;} 
        else break ;
    }
    cout<<  n - ans << endl ; 
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}