#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<int, vector<int>> idx;

    for (int i = 0; i < n; i++) {
        idx[a[i]].push_back(i);
    }

    vector<int> ans(n);

    for (auto &p : idx) {
        auto &v = p.second;

        if (v.size() == 1) {
            cout << -1 << "\n";
            return;
        }
        for (int i = 0; i < v.size(); i++) {
            ans[v[i]] = v[(i + 1) % v.size()] + 1;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
}
