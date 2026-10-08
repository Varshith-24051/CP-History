#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    int total = count(s.begin(), s.end(), '1');

    if (total == 0) {
        cout << 0 << "\n";
        return;
    }

    if (total == n) {
        cout << 1LL * n * n << "\n";
        return;
    }

    int pre = 0;
    for (int i = 0; i < n && s[i] == '1'; i++)
        pre++;

    int suff = 0;
    for (int i = n-1; i >= 0 && s[i] == '1'; i--)
        suff++;

    int maxx = 0, cur = 0;
    for (char c : s) {
        if (c == '1') {
            cur++;
            maxx = max(maxx, cur);
        } else {
            cur = 0;
        }
    }

    int k = max(maxx, pre + suff);

    long long h = (k + 1) / 2;
    long long w = (k + 2) / 2;

    cout << h * w << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}
