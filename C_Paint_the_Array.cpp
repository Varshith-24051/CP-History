#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll g1 = 0, g2 = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            g1 = __gcd(g1, a[i]);
        else
            g2 = __gcd(g2, a[i]);
    }

    bool ok = true;
    for (int i = 1; i < n; i += 2) {
        if (a[i] % g1 == 0)
            ok = false;
    }

    if (ok && g1 > 1) {
        cout << g1 << endl;
        return;
    }
    ok = true;
    for (int i = 0; i < n; i += 2) {
        if (a[i] % g2 == 0)
            ok = false;
    }

    if (ok && g2 > 1) {
        cout << g2 << endl;
        return;
    }

    cout << 0 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

