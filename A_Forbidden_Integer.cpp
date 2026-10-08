#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;

        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) cout << 1 << " ";
            cout << "\n";
        } else {
            if (k == 1) {
                cout << "NO\n";
                continue;
            }

            if (k == 2 && n % 2 == 1) {
                cout << "NO\n";
                continue;
            }

            cout << "YES\n";
            if (n % 2 == 0) {
                cout << n / 2 << "\n";
                for (int i = 0; i < n / 2; i++) cout << 2 << " ";
                cout << "\n";
            } else {
                if (k >= 3) {
                    cout << n / 2 << "\n";
                    cout << "3 ";
                    for (int i = 1; i < n / 2; i++) cout << 2 << " ";
                    cout << "\n";
                } else {
                    cout << "NO\n";
                }
            }
        }
    }

    return 0;
}
