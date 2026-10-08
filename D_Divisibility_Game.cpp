#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m; 
    cin >> n >> m;
    
    vector<int> a(n), b(m);
    for (int& x : a) cin >> x;
    
    int max_b = 0;
    for (int& y : b) {
        cin >> y;
        max_b = max(max_b, y);}
    
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int U = a.size(); 

    vector<int> div_count(max_b + 1, 0);
    for (int x : a) {
        for (int j = x; j <= max_b; j += x) {
            div_count[j]++;
        }
    }
    
    int A = 0, B = 0, C = 0;
    for (int y : b) {
        if (div_count[y] == 0) B++;         
        else if (div_count[y] == U) A++;    
        else C++;                           
    }
    if (A + (C % 2) > B) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}