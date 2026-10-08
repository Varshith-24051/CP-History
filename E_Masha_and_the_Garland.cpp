#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> pref(n, 0);
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + (s[i] == s[i - 1] ? 1 : 0);
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--; 
        r--;

        if (l == r) {
            cout << "YES"<<endl;
            continue;
        }
        int errors = pref[r] - pref[l];

        int minn = (errors + 1) / 2;

        if (minn <= k) {
            cout << "YES"<<endl;
        } else {
            cout << "NO"<<endl;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}