#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll s, m; 
    cin >> s >> m;
    
    auto check = [&](ll n) {
        ll rem = s;
        for (int i = 60; i >= 0; --i) {
            if ((m >> i) & 1) {
                ll take = min(n, rem >> i);
                rem -= take << i;
            }
        }
        return rem == 0;
    };

    if (!check(s)) { 
        cout << -1 << "\n"; 
        return; 
    }
    
    ll l = 1, r = s, ans = s;
    while (l <= r) {
        ll mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1; 
        } else {
            l = mid + 1; 
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}