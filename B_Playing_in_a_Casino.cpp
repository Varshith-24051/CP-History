#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solution() {
    ll n, k; 
    cin >> k >> n; 
    
    vector<vector<ll>> a(n, vector<ll>(k));

    for(int i = 0 ; i < k; i++){
        for(int j = 0 ; j < n ; j++){
            ll x; 
            cin >> x;
            a[j][i] = x; 
        }
    }
    
    ll ans = 0 ; 
  
    for(int i = 0 ; i < n ; i++){
        sort(a[i].begin(), a[i].end());
        
        for(int j = 0 ; j < k ; j++){

            ans -= a[i][j] * (k - j - 1);
            ans += a[i][j] * j;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}