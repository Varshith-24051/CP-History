#include <bits/stdc++.h>
using namespace std;

int calculate(int t, int a, int b, int x, int y) {
    int cur = 0;
    cur += max((t - a + x) / x, 0);
    t -= max((t - a + x) / x, 0) * x;
    cur += max((t - b + y) / y, 0);
    return cur;
}

void solve() {
    int t, a, b, x, y;
    cin >> t >> a >> b >> x >> y;
    
    cout << max(calculate(t, a, b, x, y), calculate(t, b, a, y, x)) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}
