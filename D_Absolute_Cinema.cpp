#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> f(n);
    for (int i = 0; i < n; ++i) {
        cin >> f[i];
    }

    vector<ll> a(n);
    ll S = (f[0] + f[n - 1]) / (n - 1);
    a[0] = (f[1] - f[0] + S) / 2;

    ll current_sum = a[0];

    for (int i = 1; i < n - 1; ++i) {
        a[i] = (f[i - 1] + f[i + 1] - 2 * f[i]) / 2;
        current_sum += a[i];
    }

    a[n - 1] = S - current_sum;

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout <<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}