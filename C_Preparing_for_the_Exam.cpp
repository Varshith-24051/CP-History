#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> missing(m);
        for (int i = 0; i < m; i++) cin >> missing[i];

        unordered_set<int> knows;
        for (int i = 0; i < k; i++) {
            int q;
            cin >> q;
            knows.insert(q);
        }

        string ans(m, '0');

        int unknown_count = n - k;

        if (unknown_count == 0) {
            ans = string(m, '1');
        } 
        else if (unknown_count == 1) {

            int unknown = -1;
            for (int i = 1; i <= n; i++) {
                if (knows.find(i) == knows.end()) {
                    unknown = i;
                    break;
                }
            }
            for (int i = 0; i < m; i++) {
                if (missing[i] == unknown) ans[i] = '1';
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
