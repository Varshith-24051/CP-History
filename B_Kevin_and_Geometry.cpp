#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    sort(a.begin(), a.end());

    for (int i = 0; i + 1 < n; i++) {
        if (a[i] != a[i + 1]) continue;

        int c = a[i];

        for (int j = i + 2; j + 1 < n; j++) {
            if (a[j + 1] - a[j] < 2 * c) {
                cout << c << " " << c << " " << a[j] << " " << a[j + 1] << "\n";
                return;
            }
        }

        for (int j = i - 1; j - 1 >= 0; j--) {
            if (a[j] - a[j - 1] < 2 * c) {
                cout << c << " " << c << " " << a[j - 1] << " " << a[j] << "\n";
                return;
            }
        }

        if (i > 0 && i + 2 < n) {
            if (a[i + 2] - a[i - 1] < 2 * c) {
                cout << c << " " << c << " " << a[i - 1] << " " << a[i + 2] << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
