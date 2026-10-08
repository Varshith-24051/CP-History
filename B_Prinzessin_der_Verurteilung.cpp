#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<string> q = {""};
    for (int len = 1; len <= 3; ++len) {
        vector<string> nq;
        
        for (const string& prefix : q) {
            for (char c = 'a'; c <= 'z'; ++c) {
                string current = prefix + c;
                
                if (s.find(current) == string::npos) {
                    cout << current << endl;
                    return;
                }
                
                nq.push_back(current);
            }
        }
        q = nq;
    }
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