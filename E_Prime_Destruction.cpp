#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int maxx = 200005;

vector<vector<int>> prime(maxx); 
void compute(){
    for(int i = 2; i < maxx; i++){
        if(prime[i].size() == 0){
            for(int j = i; j < maxx; j += i){
                prime[j].push_back(i);
            }
        }
    }
}

void solution() {
    int n, k; 
    cin >> n >> k; 
    int max_val = 0; 
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        max_val = std::max(max_val, a[i]);
    }

    vector<int> dp(max_val + 1, 0);
    for(int i = k + 1; i <=max_val; i++){
        dp[i] = INT_MAX;
        for(int j : prime[i]){
            int temp = 1 +j * dp[i/j];
            dp[i] = std::min(dp[i], temp);
        }
    }
    
    int ans = 0; 
    for(int x : a) ans += dp[x];
    cout << ans << endl;
    return; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    compute();

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}