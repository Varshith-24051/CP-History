#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> mn(n + 1, n);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        
        if (u > v) swap(u, v);

        mn[u] = min(mn[u], v - 1);
    }

    for (int i = n - 1; i >= 1; --i) {
        mn[i] = min(mn[i], mn[i + 1]);
    }

    long long ans = n;

    for (int i = 1; i <= n; ++i) {
        ans += (mn[i] - i);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}