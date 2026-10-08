#include <bits/stdc++.h>
using namespace std;

#define ll long long
 ll mod = 1e9 + 7;

void solve() {
    ll n;
    cin >> n;

    ll ans = n % mod;
    ans = (ans * ((n + 1) % mod)) % mod;
    ans = (ans * ((4 * n % mod - 1 + mod) % mod)) % mod;
    ans = (ans * 337) % mod;   

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
