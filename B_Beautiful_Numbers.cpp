#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();
    if (n == 1) { cout << 0 << "\n"; return; }
    
    vector<int> a(n - 1);
    for (int i = 1; i < n; ++i) a[i - 1] = s[i] - '0';
    sort(a.begin(), a.end());
    
    int ans = n;
    
    int sum1 = s[0] - '0', k1 = 1;
    for (int x : a) {
        if (sum1 + x > 9) break;
        sum1 += x; k1++;
    }
    ans = min(ans, n - k1);
    
    int sum2 = 1, k2 = 0;
    for (int x : a) {
        if (sum2 + x > 9) break;
        sum2 += x; k2++;
    }
    ans = min(ans, n - k2);
    
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}