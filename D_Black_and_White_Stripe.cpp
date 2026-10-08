#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int white = 0;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
    if (s[i] == 'W') white++;

    if (i >= k) {
        if (s[i-k] == 'W') white--;
    }

    if (i >= k-1) {
        ans = min(ans, white);
    }
}

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
