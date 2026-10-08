#include <bits/stdc++.h>
using namespace std;
using ll = long long; 

/*
    Solution By:
        Your_Fav_Varsh
*/
void solution() {
    ll n; cin >> n ; 
    vector<ll> a(n);
    for(ll &x : a)cin >> x; 

    ll anss = 0 ;
    vector<ll> ans(65,0);
    for( int i = 0 ; i < n ; i++){
        ll len = __builtin_clzll(a[i]); // clz
        anss +=ans[len];
        ans[len]++;
    }
    cout << anss << endl;
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