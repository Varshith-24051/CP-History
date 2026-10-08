#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;
#define int long long

void solve() {
    int a, b, k;
    int ans = 0;
    cin >> a >> b >> k;

    vector<int> boys(k);
    vector<int> girls(k);

    vector<int> fb(a + 1, 0);
    vector<int> fg(b + 1, 0);

    for (int i = 0; i < k; i++) {
        cin >> boys[i];
        fb [boys[i]]++;
    }

    for (int i = 0; i < k; i++) {
        cin >> girls[i];
        fg[girls[i]]++;
    }


    for (int i = 0; i < k; i++) {
        int u = boys[i];
        int v = girls[i];
        
        ans += (k - fb[u] - fg[v] + 1);
    }
    cout << ans / 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}