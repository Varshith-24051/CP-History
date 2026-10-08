#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    vector<int> pos, neg;
    int mx = -2e9, mn = 2e9; 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
        
        if (a[i] >= 0) {
            pos.push_back(a[i]);
        } else {
            neg.push_back(a[i]);
        }
    }

    if (mx == 0 && mn == 0) {
        cout << "No\n";
        return;
    }

    sort(pos.begin(), pos.end()); 
    sort(neg.begin(), neg.end()); 

    cout << "Yes\n";
    long long cs = 0;
    
    for (int i = 0; i < n; i++) {
        if (cs <= 0) {
            cout << pos.back() << " ";
            cs += pos.back();
            pos.pop_back();
        } else {
            cout << neg.back() << " ";
            cs += neg.back();
            neg.pop_back();
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}