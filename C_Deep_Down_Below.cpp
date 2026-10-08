#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n; 
    cin >> n;
    
    vector<pair<ll, ll>> a(n);
    
    for (int i = 0; i < n; i++) {
        ll k; 
        cin >> k;
        ll req = 0;
        for (int j = 0; j < k; j++) {
            ll x; 
            cin >> x;
            req = max(req, x - j + 1); 
        }
        a[i] = {req, k};
    }
    
    sort(a.begin(), a.end());
    
    ll ans = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        if (curr < a[i].first) {
            ans += a[i].first - curr;
            curr = a[i].first;
        }
        curr += a[i].second;
    }
    
    cout << ans << '\n';
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(0); 
    cin.tie(0);
    
    int t; 
    cin >> t;
    while (t--) solve();
    return 0;
}