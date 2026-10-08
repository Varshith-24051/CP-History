#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    
    map<int, int> freq;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % k != 0) {
            int x = k - (a % k);
            freq[x]++;
        }
    }
    
    int maxx = 0;
    for (auto const& [req, count] : freq) {
        int cm = req + (count - 1) * k + 1;
        
        maxx = max(maxx, cm );
    }
    cout << maxx << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}