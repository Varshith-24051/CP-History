#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
long long n;
    cin >> n;

    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    long long ans = LLONG_MAX;
    for (auto x : a) ans = min(ans, llabs(x));

    cout << ans << "\n";
    return 0;
}
