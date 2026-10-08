#include <bits/stdc++.h>
using namespace std;

#define int long long  

const int MAXN = 1000000;
int dp[1500][1500];
int ans[MAXN + 5];

void precompute() {
    int cur = 1;
    for (int i = 1; cur <= MAXN; i++) {
        for (int j = 1; j <= i && cur <= MAXN; j++) {
            // First, add the two parents and the current square
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + (1LL * cur * cur);
            
            // Only subtract the grandparent if it actually exists!
            if (i >= 2) {
                dp[i][j] -= dp[i-2][j-1];
            }
            
            ans[cur] = dp[i][j];
            cur++;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    if (cin >> t) {
        while (t--) {
            int n;
            cin >> n;
            cout << ans[n] << "\n";
        }
    }

    return 0;
}