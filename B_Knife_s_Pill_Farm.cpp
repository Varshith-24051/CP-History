#include <bits/stdc++.h>
#define int long long
using namespace std;

void solution() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    if (m == 1) {
        cout << *max_element(a.begin(), a.end()) << endl;
        return;
    }

    priority_queue<int> pq; 
    int sum = 0;
    int ans = -2e18; 
    
    for (int i = 0; i < n; i++) {
        if (pq.size() == m - 1) {
            int cur = (m * a[i]) - sum;
            ans = max(ans, cur);
        }
        if (pq.size() < m - 1) {
            pq.push(a[i]);
            sum += a[i];
        } 
        else if (a[i] < pq.top()) {
            sum += a[i] - pq.top();
            pq.pop(); pq.push(a[i]);
        }
    }
    cout << ans <<endl;
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}