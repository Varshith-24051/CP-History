#include <bits/stdc++.h>
using namespace std;

long long rec(int curr, int chance, const vector<long long> &a, const vector<long long> &b, vector<vector<long long>> &dp) {
    if (curr >= a.size()) return 0;
    
    if (dp[curr][chance] != -1) return dp[curr][chance];
    
    long long temp = rec(curr + 1, chance, a, b, dp);
    long long ans = 0;
    
    if (chance == 0) {
        ans = rec(curr + 1, 1, a, b, dp) + a[curr];
    } else {
        ans = rec(curr + 1, 0, a, b, dp) + b[curr];
    }
    return dp[curr][chance] = max(ans, temp);
}

void solution() {
    int n; 
    cin >> n; 
    
    vector<long long> a(n);
    vector<long long> b(n);
    
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    vector<vector<long long>> dp(n, vector<long long>(2, -1));
    
    long long temp1 = rec(0, 0, a, b, dp);
    long long temp2 = rec(0, 1, a, b, dp);
    
    cout << max(temp1, temp2) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}