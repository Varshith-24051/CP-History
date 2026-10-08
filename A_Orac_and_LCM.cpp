#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> suf(n);
    suf[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf[i] =gcd(a[i], suf[i + 1]);
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans = gcd(ans, lcm(a[i], suf[i + 1]));
    }

    cout << ans << "\n";
    return 0;
}