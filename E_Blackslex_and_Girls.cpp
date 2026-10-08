#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    vector<ll> p(n);
    ll sum_p = 0;
    ll n0 = 0, n1 = 0;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        sum_p += p[i];
        if (s[i] == '0') n0++;
        else n1++;
    }

    ll min_x_for_0 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') min_x_for_0 += max(1LL, p[i] / 2 + 1);
    }

    ll min_y_for_1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') min_y_for_1 += max(1LL, p[i] / 2 + 1);
    }

    if (x + y < sum_p) { cout << "NO" << endl; return; }

    
    if (x >= (y - min_y_for_1) + n0 && y >= (x - min_x_for_0) + n1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}