#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> c(n);
        for (int i = 0; i < n; i++)
            cin >> c[i];

        sort(c.begin(), c.end());

        if (c[0] != 1) {
            cout << "NO\n";
            continue;
        }

        long long sum = 1;
        bool ok = true;

        for (int i = 1; i < n; i++) {
            if (c[i] > sum) {
                ok = false;
                break;
            }
            sum += c[i];
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
