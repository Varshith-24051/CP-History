#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<vector<int>> a(n, vector<int>(n));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];

        long long need = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                int ni = n - 1 - i;
                int nj = n - 1 - j;

                if (i < ni || (i == ni && j < nj)) {
                    need += (a[i][j] ^ a[ni][nj]);
                }
            }
        }

        if (k < need) {
            cout << "NO\n";
        }
        else {
            long long extra = k - need;

            if (n % 2 == 1) {
                cout << "YES\n";
            }
            else {
                cout << (extra % 2 == 0 ? "YES\n" : "NO\n");
            }
        }
    }

    return 0;
}

