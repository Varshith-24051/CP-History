#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solution() {
    int n; 
    cin >> n;
    string s; 
    cin >> s;

    
    vector<int> state(n + 1);
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') state[i + 1] = 1;
        else state[i + 1] = 0;
    }

    ll ans = 0;
    for (int k = 1; k <= n; k++) {
        for (int m = k; m <= n; m += k) {

            if (state[m] == 1) break; 
            
            if (state[m] == 0) {
                ans += k;
                state[m] = -1; 
            }
            
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) solution();
    return 0;
}