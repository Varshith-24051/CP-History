#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int N = 200005;

int fact[N];

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    int total = -1; 
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total &= a[i]; 
    }
    
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == total) {
            c++;
        }
    }
    
    if (c < 2) {
        cout << 0 << "\n";
        return;
    }
    
    int ans = -1;
    ans = c * (c - 1) % MOD * fact[n - 2] % MOD;
    
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}