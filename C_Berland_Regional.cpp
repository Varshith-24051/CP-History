#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> u(n);
    for (int i = 0; i < n; i++) {
        cin >> u[i];
    }
    
    vector<vector<long long>> uni(n + 1);
    for (int i = 0; i < n; i++) {
        long long s;
        cin >> s;
        uni[u[i]].push_back(s);
    }
    
    vector<long long> ans(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        if (uni[i].empty()) continue;
        
        sort(uni[i].rbegin(), uni[i].rend());
        
        int m = uni[i].size();
        vector<long long> pref(m + 1, 0);
        for (int j = 0; j < m; j++) {
            pref[j + 1] = pref[j] + uni[i][j];
        }
        
        for (int k = 1; k <= m; k++) {
            int valid = m - (m % k);
            ans[k] += pref[valid];
        }
    }
    
    for (int k = 1; k <= n; k++) {
        cout << ans[k] << " ";
    }
    cout << endl ; 
    return ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}