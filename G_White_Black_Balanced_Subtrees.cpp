#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    
    string s;
    cin >> s;
    vector<int> weight(n + 1, 0);
    
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'W') {
            weight[i] = 1;
        } else {
            weight[i] = -1;
        }
    }
    for (int i = n; i >= 2; i--) {
        weight[a[i]] += weight[i];
    }
    
    int bal = 0;
    for (int i = 1; i <= n; i++) {
        if (weight[i] == 0) {
            bal++;
        }
    }
    
    cout << bal << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}