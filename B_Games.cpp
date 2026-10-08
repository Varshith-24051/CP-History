#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

        int i = 0, j = 0;
        int onlyA = 0, onlyB = 0;

        while (i < n && j < m) {
            if (a[i] == b[j]) {
                i++;
                j++;
            } else if (a[i] < b[j]) {
                onlyA++;
                i++;
            } else {
                onlyB++;
                j++;
            }
        }

        onlyA += (n - i);
        onlyB += (m - j);

        int ans;
        if (onlyA > onlyB)
            ans = 2 * min(onlyA, onlyB) + 2;
        else
            ans = 2 * min(onlyA, onlyB) + 1;

        cout << ans << '\n';
    }

    return 0;
}
