#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());

    vector<int> candidates;
    candidates.push_back(0);
    candidates.push_back(x);
    for (int i = 0; i < n; i++) candidates.push_back(a[i]);
    for (int i = 0; i + 1 < n; i++) {
        int mid = (a[i] + a[i + 1]) / 2;
        candidates.push_back(mid);
    }

    sort(candidates.begin(), candidates.end());
    candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

    map<int, int> dist;
    for (auto pos : candidates) {
        int d = LLONG_MAX;
        for (auto f : a)
            d = min(d, abs(pos - f));
        dist[pos] = d;
    }

    vector<pair<int, int>> v(dist.begin(), dist.end());

    // 🔻 MINIMIZE distance
    sort(v.begin(), v.end(), [](auto &A, auto &B) {
        if (A.second != B.second) return A.second < B.second;
        return A.first < B.first;
    });

    vector<int> ans;
    for (int i = 0; i < k && i < (int)v.size(); i++)
        ans.push_back(v[i].first);

    sort(ans.begin(), ans.end());
    for (auto val : ans) cout << val << " ";
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) solve();
}
