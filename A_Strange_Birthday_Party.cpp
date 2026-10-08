#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
        k[i]--; 
    }
    
    vector<ll> c(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    
    sort(k.rbegin(), k.rend());
    
    ll total_cost = 0;
    int p = 0;
    
    for (int i = 0; i < n; i++) {
        
        if (p < k[i]) {
            total_cost += c[p]; 
            p++;                
        } else {
            total_cost += c[k[i]];
        }
    }
    
    cout << total_cost << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}