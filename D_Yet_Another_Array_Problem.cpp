#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    long long g = v[0];
    for (int i = 1; i < n; i++) g = gcd(g, v[i]);
    for (long long x = 2; x <= 108; x++) {
        if (gcd(g, x) == 1) {
            cout << x << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
