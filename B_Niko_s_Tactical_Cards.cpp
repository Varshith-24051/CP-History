#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve_one() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    ll maxx = 0, minn = 0; 
    for (int i = 0; i < n; ++i) {
        ll new_maxx= max(maxx - a[i], b[i] - minn);
        ll new_minn = min(minn - a[i], b[i] - maxx);
        maxx = new_maxx;
        minn = new_minn;
    }

    cout << maxx << endl;

    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve_one();
    return 0;
}
