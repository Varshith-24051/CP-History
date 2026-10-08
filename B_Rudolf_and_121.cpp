#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool ok = true;

        for (int i = 0; i + 2 < n; i++) {
            if (a[i] < 0) {
                ok = false;
                break;
            }
            long long op = a[i];
            a[i]     -= op;
            a[i+1]   -= 2 * op;
            a[i+2]   -= op;
        }

        if (a[n-1] != 0 || a[n-2] != 0) ok = false;

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
