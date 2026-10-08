#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        long long ans = 0, sumA = 0, maxB = 0;

        for (int i = 0; i < n && i < k; i++) {
            sumA += a[i];
            maxB = max(maxB, b[i]);
            ans = max(ans, sumA + (long long)(k - i - 1) * maxB);
        }

        cout << ans << '\n';
    }
    return 0;
}
