#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;
        freq[type]++;
    }
    vector<int> counts;
    for (auto const& [type, count] : freq) {
        counts.push_back(count);
    }
    
    sort(counts.rbegin(), counts.rend());
    
    int total = 0;
    int maxx = INT_MAX; 
    
    for (int count : counts) {
        if (maxx == 0) break;
        
        int take = min(count, maxx - 1);
        
        total += take;
        maxx = take; 
    }
    
    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}