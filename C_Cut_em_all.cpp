#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;  
vector<int> sizee; 

void dfs(int u, int from) {
    sizee[u] = 1; 
    for(int v : adj[u]) {
        if(v == from) continue; 
        dfs(v, u);
        sizee[u] += sizee[v];
    }
}

void solution() {
    int n; 
    cin >> n; 

    adj.assign(n + 1, {});
    for(int i = 0; i < n - 1; i++) {
        int u, v; 
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if(n % 2) {
        cout << -1 << "\n"; 
        return; 
    }
    
    sizee.assign(n + 1, 0);
    dfs(1, -1);

    int ans = 0; 
    for(int i = 2; i <= n; ++i) {
        if(sizee[i] % 2 == 0) ans++;
    }
    
    cout << ans << "\n"; 
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
solution();
    
    return 0;
}