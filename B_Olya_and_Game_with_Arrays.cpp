#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long T;
    cin >> T;
    while (T--) {
        long long k;
        cin >> k;

        vector<long long> v;
        long long mn = LLONG_MAX;

        for (long long i = 0; i < k; i++) {
            long long sz;
            cin >> sz;
            vector<long long> b(sz);
            for (long long j = 0; j < sz; j++) cin >> b[j];
            nth_element(b.begin(), b.begin() + 1, b.end());
            long long x = min(b[0], b[1]);
            long long y = max(b[0], b[1]);
            mn = min(mn, x);
            v.push_back(y);
        }

        sort(v.begin(), v.end());
        long long res = mn;
        for (long long i = 1; i < (long long)v.size(); i++) res += v[i];
        cout << res << '\n';
    }
    return 0;
}
