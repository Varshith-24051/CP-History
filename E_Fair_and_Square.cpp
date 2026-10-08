#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<vector<int>> adj;
vector<int> a, sizee; 
int ans; 
int n; 

bool is_square(int x) {
    int root = round(sqrt(x));
    return (root * root == x);
}

void dfs(int u, int p) {
    sizee[u] = 1; 
    vector<int> child_sizes;

    for (int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == p) continue; 
        
        dfs(v, u);
        
        sizee[u] += sizee[v];
        child_sizes.push_back(sizee[v]);
    }
    
    if (p != 0) {
        child_sizes.push_back(n - sizee[u]);
    }
    child_sizes.push_back(1);
    if (is_square(a[u])) {
        int dp1 = 0, dp2 = 0, dp3 = 0; 
        for (int &i : child_sizes) {
            dp3 += dp2 * i;
            dp2 += dp1 * i;
            dp1 += i;
        }
        ans += dp3; 
    }
}

void solution() {
    cin >> n; ans = 0; 
    
    adj.assign(n + 1, vector<int>());
    a.assign(n + 1, 0);
    sizee.assign(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i]; 
    }
    
    for (int i = 0; i < n - 1; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    cout << ans << endl;
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}