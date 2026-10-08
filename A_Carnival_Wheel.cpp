#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int l, a, b;
        cin >> l >> a >> b;

        int ans = l - 1 - ((l - 1 - a) % gcd(l, b));
        cout << ans << endl;
    }
    return 0;
}
