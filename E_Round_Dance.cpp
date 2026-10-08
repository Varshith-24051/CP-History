#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<int> vis(n + 1, 0); 
    
    int open = 0, closed = 0;
    
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            int curr = i;
            
            while (vis[curr] == 0) {
                vis[curr] = i;         
                curr = a[curr];        
            }
            
            if (vis[curr] == i) {
                
                int len = 1;
                for (int v = a[curr]; v != curr; v = a[v]) {
                    len++;
                }
                
                if (len == 2) open++;
                else closed++;
            }
        }
    }
    
    cout << closed + (open > 0 ? 1 : 0) << " " << closed + open << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}