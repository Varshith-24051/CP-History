#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> pos(51, -1);

    for (int i = 0; i < n; i++) {
        if (pos[a[i]] == -1)
            pos[a[i]] = i + 1;
    }

    while (q--) {
        int col;
        cin >> col;

        int p = pos[col];
        cout << p << " ";

        for (int c = 1; c <= 50; c++) {
            if (pos[c] < p)
                pos[c]++;
        }

        pos[col] = 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}