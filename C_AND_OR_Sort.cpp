#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n; 
    string a; 
    cin >> a; 

    if (a[0] == '1') {
        int ans = 0; 
        for (char &x : a) {
            if (x == '0') ans++;
        }
        cout << ans << "\n";
        return;
    }

    int first_one = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            first_one = i;
            break;
        }
    }

    if (first_one == -1) {
        cout << 0 << "\n";
        return;
    }

    vector<int> suffz(n + 1, 0);
    vector<int> prefo(n + 1, 0);
    
    prefo[0] = (a[0] == '1');
    suffz[n - 1] = (a[n - 1] == '0');
    
    for (int i = n - 2; i >= 0; i--) suffz[i] = suffz[i + 1] + (a[i] == '0');
    for (int i = 1; i < n; i++) prefo[i] = prefo[i - 1] + (a[i] == '1');

    int ans = prefo[n - 1];
    for (int i = first_one - 1; i < n; i++) {
        ans = min(ans, prefo[i] + suffz[i + 1]);
    } 
    
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}