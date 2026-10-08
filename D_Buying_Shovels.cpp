#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;

    long long ans = n;

    for (long long i = 1; i * i <= n; i++) {
        
        if (n % i == 0) {
            
            if (i <= k) {
                ans = min(ans, n / i);
            }
            
            if (n / i <= k) {
                ans = min(ans, i); 
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}