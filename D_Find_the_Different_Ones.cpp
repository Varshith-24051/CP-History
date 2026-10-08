#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n + 1, -1); 
    
    for (int i = 2; i <= n; i++) {
        if (a[i] != a[i - 1]) {
            dp[i] = i - 1;
        } else {
            dp[i] = dp[i - 1];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
   
        if (dp[r] >= l) {

            cout << dp[r] << " " << r << "\n";
        } else {
          
            cout << "-1 -1\n";
        }
    }
    cout << "\n";
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