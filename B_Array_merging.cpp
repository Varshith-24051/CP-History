#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        unordered_map<int,int> bestA, bestB;
        bestA.reserve(n * 2);
        bestB.reserve(n * 2);

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) j++;
            bestA[a[i]] = max(bestA[a[i]], j - i);
            i = j;
        }

        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && b[j] == b[i]) j++;
            bestB[b[i]] = max(bestB[b[i]], j - i);
            i = j;
        }

        int ans = 0;
        for (auto &p : bestA) {
            int x = p.first;
            ans = max(ans, bestA[x] + bestB[x]);
        }
        for (auto &p : bestB) {
            int x = p.first;
            ans = max(ans, bestA[x] + bestB[x]);
        }

        cout << ans << '\n';
    }
    return 0;
}
