#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll binSearch(ll val, ll ind, ll x) {
    if (val > x) return 0;
    
    ll low = 0, high = x;
    ll ans = 0;
    
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        
        if (val + mid * (ind + 1) <= x) {
            ans = mid + 1;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

void solution() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll &y : a) cin >> y;

    sort(a.begin(), a.end());
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += binSearch(a[i], i, x);
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