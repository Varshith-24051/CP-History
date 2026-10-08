#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector<vector<int>> adj;
int ans; 
int n; 

int dfs(int u, int p) {
    int d1 = -1; // Longest branch depth
    int d2 = -1; // Second longest branch depth

    for (int v : adj[u]) {
        if (v == p) continue; 
        
        // Go all the way down to the leaves first
        int child_depth = dfs(v, u);
        
        // Keep track of the top two deepest branches
        if (child_depth > d1) {
            d2 = d1;
            d1 = child_depth;
        } else if (child_depth > d2) {
            d2 = child_depth;
        }
    }

    // The Geometric Trick: 
    // If a node has at least two branches merging, it creates D2 + 1 new guilds!
    if (d2 != -1) {
        ans += (d2 + 1);
    }

    // Pass the longest branch (+1 for the current edge) up to the parent
    return d1 + 1;
}

void solution() {
    cin >> n; 
    
    // Base case: every individual node forms exactly 1 guild at h = 0
    ans = n; 
    
    // Safely reset memory for the new tree size
    adj.assign(n + 1, vector<int>());
    
    // Read the parents (input starts from house 2 up to n)
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }
    
    dfs(1, 0);
    
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}