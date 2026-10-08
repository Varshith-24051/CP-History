#include <bits/stdc++.h>

using namespace std;

inline void solve() {
    int n; 
    cin >> n;
    
    long long ans = 0;
    long long mn = 2e18;
    int p = -1, ops = 0, lst = 0;
    
    for (int i = 0; i < n; ++i) {
        long long a; 
        cin >> a;
        long long o0 = a;
        long long o1 = -a - 1;
        
        int c = (o1 > o0) ? 1 : 0;
        
        ans += max(o0, o1);
        mn = min(mn, abs(o0 - o1));
        
        if (p != -1) {
            ops += (p ^ c);
        }
        p = c; 
        lst = c;
    }
    
    ops += lst;
    if (ops == n) {
        ans -= mn;
    }
    
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}