#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<pair<int, int>> adj[MAXN];
int dp[MAXN];
int ans;

void dfs (int u , int p  , int p_idx){
    for(auto& edge : adj[u]){
        int v = edge.first; 
        int idx = edge.second; 

        if(v == p ) continue ; 
        if(idx > p_idx) dp[v] = dp[u] ; 
        else dp[v] = dp[u] + 1;
        ans = max(ans, dp[v]);
        dfs(v, u, idx);
    }
}
void solution() {
    int n ; cin >>n ; 
    for(int i = 1 ; i <=n ;i++){
        adj[i].clear();
    }
    ans = 1 ; 
    for(int i = 0 ; i < n-1 ; i++){
        int u , v ; cin >> u >> v ; 
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    dp[1] = 1; 
    dfs(1,0,-1);
    cout<<ans << endl; 


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}