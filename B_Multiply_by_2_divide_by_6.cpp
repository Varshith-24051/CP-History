#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        long long n; cin >> n;
        int a = 0, b = 0;
        long long temp = n;

        while (temp % 2 == 0) {
            temp /= 2;
            a++;
        }

        while (temp % 3 == 0) {
            temp /= 3;
            b++;
        }

        if (temp != 1) {
            cout << -1 << '\n';
            continue;
        }

        if (b < a) {
            cout << -1 << '\n';
            continue;
        }

        int moves = 2 * b - a;
        cout << moves << '\n';
    }
    return 0;
}
