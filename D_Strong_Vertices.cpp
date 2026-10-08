#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int max_diff = -2e9 - 7;
    vector<int> ans;
    ans.reserve(n); 
    
    for(int i = 0; i < n; i++) {
        int b;
        cin >> b;
        
        int diff = a[i] - b;
        
        if(diff > max_diff) {
            max_diff = diff;
            ans.clear(); 
            ans.pb(i + 1);
        } else if(diff == max_diff) {
            ans.pb(i + 1);
        }
    }
    
    cout << ans.size() << "\n";
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    fast_io;
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}