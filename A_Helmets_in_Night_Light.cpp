#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n, p;
        cin >> n >> p;

        vector<pair<long long, long long>> v(n);
        vector<long long> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        for (int i = 0; i < n; i++)
            v[i] = {b[i], a[i]};

        sort(v.begin(), v.end());

        long long minimum_cost = p;
        long long informed = 1;

        for (auto it : v) {
            long long share_cost = it.first;
            long long max_shares = it.second;

            if (share_cost >= p) break;

            if (informed + max_shares > n) {
                minimum_cost += (n - informed) * share_cost;
                informed = n;
                break;
            } else {
                minimum_cost += max_shares * share_cost;
                informed += max_shares;
            }
        }

        minimum_cost += (n - informed) * p;
        cout << minimum_cost << endl;
    }

    return 0;
}
