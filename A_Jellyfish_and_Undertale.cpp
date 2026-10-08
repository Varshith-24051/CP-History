#include <bits/stdc++.h>
using namespace std;

void solution() {
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    long long ans = b; 
    for (int i = 0; i < n; i++) {
        ans += min(v[i], a - 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) solution();
    
    return 0;
}
