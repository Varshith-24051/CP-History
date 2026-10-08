#include <iostream>
#include <algorithm>
using namespace std;

void solve() {
    int n, x, m;
    cin >> n >> x >> m;
    
    int L = x;
    int R = x;
    
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        
        if (l <= R && r >= L) {
            L = min(L, l);
            R = max(R, r);
        }
    }
    
    cout << (R - L + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}