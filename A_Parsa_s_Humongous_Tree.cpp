#include <bits/stdc++.h>
using namespace std;
#define int long long 
void dfs(int u , int v , vector<pair<int,int>> &a,vector<vector<int>> &adj,vector<vector<int>> &dp){

    for(auto x:adj[u]){
        if(x == v)continue;
        dfs(x,u,a,adj,dp);
        dp[u][0] += max(dp[x][0]+abs(a[u].first-a[x].first),dp[x][1]+abs(a[u].first-a[x].second));
        dp[u][1] += max(dp[x][0]+abs(a[u].second-a[x].first),dp[x][1]+abs(a[u].second-a[x].second));
    }

}
void solution() {
    int n ;cin>> n ;
    vector<pair<int,int>> a(n); 
    for(auto &x:a)cin>>x.first>>x.second;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    vector<vector<int>> adj(n);
    for(int i=1 ;i < n ;i++){
        int u , v ; cin>> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, a, adj, dp);
    cout<< max(dp[0][0],dp[0][1]) << endl;
    return; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}