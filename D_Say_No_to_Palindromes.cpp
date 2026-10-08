#include <bits/stdc++.h>
using namespace std;

void solution() {
    vector<string> a = {"abc", "acb", "bac", "bca", "cab", "cba"};

    int n, q;
    cin >> n >> q; 
    string s; 
    cin >> s; 
    vector<vector<int>> pref(6, vector<int>(n, 0));
    
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < n; j++) {
            if (j > 0) pref[i][j] = pref[i][j - 1];
            if (s[j] != a[i][j % 3]) pref[i][j]++;
        }
    }
    
    while(q--) {
        int l, r; 
        cin >> l >> r; 
        l--; r--; 

        int best = r - l + 1;
        for(int i = 0; i < 6; i++) {
            best = min(best, pref[i][r] - (l > 0 ? pref[i][l - 1] : 0));
        }
        cout << best << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solution();
    return 0;
}