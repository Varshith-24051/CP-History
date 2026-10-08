#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    
    for (int &x : a) {
        cin >> x;
        if (x == 1) ones++;
    }

    if (ones > 0) {
        cout << n - ones << "\n";
        return;
    }

    int minn = 1e9;
    
    for (int i = 0; i < n; i++) {
        int g = a[i];
        for (int j = i + 1; j < n; j++) {
            g = __gcd(g, a[j]);
            if (g == 1) {
                minn = min(minn, j - i + 1);
                break; 
            }
        }
    }

    if (minn > n) cout << -1 << "\n";
    else cout << minn + n - 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}