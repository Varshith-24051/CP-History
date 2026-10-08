#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n , m ; 
    cin >> n >> m ; 
	vector<vector<int>> adj(n + 1);

    for(int i = 0 ; i < m ;i++){
        int u , v ;
        cin >> u >> v; 
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> vis ( n+1);
    vector<int> ans ;

    pq.push(1);
    vis[1] = 1; 
    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        ans.push_back(u);
        for(int v : adj[u]){
        if(!vis[v]){
            pq.push(v);
            vis[v] = 1 ; 
        }
        }
    }
    for( int &x : ans)cout<<x << " "; 
    cout << endl ; 
    return; 

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
solution();
    return 0;
}