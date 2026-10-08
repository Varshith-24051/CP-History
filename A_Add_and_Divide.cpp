#include <bits/stdc++.h>
using namespace std;

void solution() {
    int a, b;
    cin >> a >> b;

    int ans = INT_MAX;

    for (int i = 0; i < 32; i++) {
        long long curr = i;
        long long b_new = b + i;

        if (b_new == 1) continue;

        long long a_new = a;
        while (a_new > 0) {
            a_new /= b_new;
            curr++;
        }

        ans = min(ans, (int)curr);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
}
