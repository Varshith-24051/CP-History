#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        long long k = 1;

        for (long long d = 1; d * d <= n; d++) {
            if (n % d == 0) {
                long long d1 = d;
                long long d2 = n / d;

                if (d1 <= n / 2) k = max(k, d1);
                if (d2 <= n / 2) k = max(k, d2);
            }
        }

        long long a = k;
        long long b = n - k;

        cout << a << " " << b << "\n";
    }
    return 0;
}
