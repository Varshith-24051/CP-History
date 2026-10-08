#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        if (x == 1) c1++;
        else if (x == 2) c2++;
        else if (x == 3) c3++;
        else c4++;
    }

    long long ans = c4 + c3 + c2 / 2;
    c1 -= min(c1, c3);

    if (c2 % 2) {
        ans++;
        c1 -= min(2LL, c1);
    }

    ans += (c1 + 3) / 4;

    cout << ans;
}
