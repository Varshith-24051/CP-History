#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solution() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 1));
    
    for (int age = 2; age <= k; age++) {
        for (int rem = 1; rem <= n; rem++) {
            dp[age][rem] = (dp[age][rem - 1] + dp[age - 1][n - rem]) % MOD;
        }
    }

    cout << dp[k][n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}