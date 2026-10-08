#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, k; 
    cin >> n >> k;
    
    vector<vector<int>> a(n);
    for(int i = 0; i < n - 1; i++){
        int u, v; 
        cin >> u >> v;
        a[--u].push_back(--v); 
        a[v].push_back(u);
    }
    
    vector<int> d(n), s(n), score(n);

    auto dfs = [&](auto &self, int u, int p, int curr_depth) -> void {
        d[u] = curr_depth; 
        s[u] = 1;  
        
        for(int v : a[u]){
            if(v != p){
                self(self, v, u, curr_depth + 1);
                s[u] += s[v]; 
            }
        }
        score[u] = d[u] - s[u] + 1; 
    };
    
    dfs(dfs, 0, -1, 0);

    sort(score.begin(), score.end(), greater<int>());
    
    cout << accumulate(score.begin(), score.begin() + k, 0LL) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
    
    return 0;
}