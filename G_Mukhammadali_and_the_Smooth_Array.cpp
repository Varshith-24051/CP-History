#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : c) cin >> x;

    // Coordinate compression
    vector<long long> vals = a;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    int m = vals.size();

    vector<long long> dp(m, 0), newdp(m, 0);

    // Base case (first element)
    for (int j = 0; j < m; j++)
        dp[j] = (vals[j] == a[0]) ? 0 : c[0];

    for (int i = 1; i < n; i++) {
        vector<long long> prefix(m);
        prefix[0] = dp[0];
        for (int j = 1; j < m; j++)
            prefix[j] = min(prefix[j-1], dp[j]);

        for (int j = 0; j < m; j++) {
            long long cost = (vals[j] == a[i]) ? 0 : c[i];
            newdp[j] = prefix[j] + cost;
        }
        dp.swap(newdp);
    }

    cout << *min_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
