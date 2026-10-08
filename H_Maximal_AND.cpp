#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    vector<int> count(31, 0); 
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int bit = 0; bit <= 30; bit++) {

            if (a[i] & (1 << bit)) {
                count[bit]++;
            }
        }
    }
    
    int ans = 0;
    
    for (int bit = 30; bit >= 0; bit--) {

        int missing = n - count[bit]; 
        if (missing <= k) {
            k -= missing;        
            ans += (1 << bit);   
        }
    }
    
    cout << ans << "\n";
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