#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;
    for (int x : a) {
        ans ^= x; 
    }

    if (n % 2 == 1) {
        cout << ans << '\n'; 
    } else {
        if (ans == 0)
            cout << 0 << '\n'; 
        else
            cout << -1 << '\n'; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}
