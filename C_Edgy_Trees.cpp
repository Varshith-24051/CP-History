#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int MOD = 1e9 + 7; 

int pwr(int x, int n) { 
    x %= MOD;
    if(n == 0) return 1; 
    
    int temp = pwr((x * x) % MOD, n / 2);
    if(n % 2) return (temp * x) % MOD;
    else return temp; 
}

vector<vector<int>> adj; 
vector<int> vis; 
int comp_size = 0; 

void dfs(int x) {
    vis[x] = 1; 
    comp_size++; 
    for(auto &i : adj[x]) {
        if(!vis[i]) dfs(i);
    }
}

void solution() {
    int n, k; 
    cin >> n >> k; 
    
    adj.assign(n + 1, {});
    vis.assign(n + 1, 0);

    for(int i = 0; i < n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if(x == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    
    int ans = 0; 
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            comp_size = 0;
            dfs(i);
            ans = (ans + pwr(comp_size, k)) % MOD;
        }
    }
    
    ans = (pwr(n, k) - ans + MOD) % MOD;
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
    return 0;
}