#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = n - 1;
    long long lsum = 0, rsum = 0;
    int ans = 0;

    while (l <= r) {
        if (lsum <= rsum) {
            lsum += a[l++];
        } else {
            rsum += a[r--];
        }

        if (lsum == rsum) {
            ans = l + (n - 1 - r);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
