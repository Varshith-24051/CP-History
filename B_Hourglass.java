#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long s, k, m;
        cin >> s >> k >> m;

        long long last = (m / k) * k;
        long long ans = last + s - m;
        cout << max(0LL, ans) << '\n';
    }
    return 0;
}
