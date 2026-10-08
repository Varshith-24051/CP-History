#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        pq.push({l, 1});       
        pq.push({r + 1, -1});  
    }

    int tv = 0;

    while (!pq.empty()) {
        auto [time, change] = pq.top();
        pq.pop();

        tv += change;

        if (tv > 2) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}