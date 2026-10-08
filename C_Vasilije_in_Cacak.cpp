#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long n, k, x;
    cin >> n >> k >> x;

    if (x >= k * (k + 1) / 2 && x <= n * (n + 1) / 2 - (n - k) * (n - k + 1) / 2)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();

    return 0;
}
