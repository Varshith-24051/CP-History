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
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;

        int A0 = 0, B0 = 0;
        int odd_cnt = 0, even_cnt = 0;

        for (int i = 0; i < n; i++) {
            A0 ^= a[i];
            B0 ^= b[i];
            if (a[i] != b[i]) {
                if ((i + 1) & 1) odd_cnt++;
                else even_cnt++;
            }
        }

        if (A0 == B0) {
            cout << "Tie\n";
        }
        else if (odd_cnt > 0 && even_cnt > 0) {
            cout << "Tie\n";
        }
        else if (odd_cnt > 0) {
            cout << "Ajisai\n";
        }
        else if (even_cnt > 0) {
            cout << "Mai\n";
        }
        else {
            if (A0 > B0) cout << "Ajisai\n";
            else cout << "Mai\n";
        }
    }
    return 0;
}
