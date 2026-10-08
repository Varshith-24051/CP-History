#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
       int fuel = a[0];
    for (int i = 1; i < n; i++) {
        fuel = max(fuel, a[i] - a[i - 1]);
    }
    fuel = max(fuel, 2 * (x - a[n - 1]));
    cout << fuel << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
