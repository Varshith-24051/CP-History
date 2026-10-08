#include <bits/stdc++.h>
using namespace std;
using ll = long long ; 

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    bool yasser_wins = true;
    ll sum = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum <= 0) {
            yasser_wins = false;
            break;
        }
    }

    sum = 0; 

    for (int i = n - 1; i >= 0; i--) {
        sum += a[i];
        if (sum <= 0) {
            yasser_wins = false;
            break;
        }
    }

    if (yasser_wins) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}