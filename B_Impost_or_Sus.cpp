#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string r;
        cin >> r;
        int n = r.size();

        for (char c : r) {
            assert(c == 's' || c == 'u');
        }

        int ans = 0;

        if (r[0] != 's') {
            r[0] = 's';
            ans++;
        }
        if (r[n - 1] != 's') {
            r[n - 1] = 's';
            ans++;
        }

        vector<int> line;
        int cur = 0;
        for (char c : r) {
            if (c == 'u') cur++;
            else {
                if (cur > 0) line.push_back(cur);
                cur = 0;
            }
        }

        for (int len : line) {
            if (len > 1) {
                ans += len / 2;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
