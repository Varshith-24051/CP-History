#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;

    long long diff = llabs(x - y);
    long long mn = min(x, y);

    if (2 * a < b) {
        cout << diff * a + mn * 2 * a << '\n';
    } else {
        cout << diff * a + mn * b << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
