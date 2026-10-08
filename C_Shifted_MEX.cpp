#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto &x : a) cin >> x;

    sort(a.begin(), a.end());

    long long ans = 1;
    long long temp = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1]) {
            continue;
        }
        else if (a[i] == a[i - 1] + 1) {
            temp++;
        }
        else {
            temp = 1;
        }
        ans = max(ans, temp);
    }

    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}