#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    if(!(cin >> t)) return 0;
    while (t--) {
        int n; cin >> n;
        vector<long long> a(n);
        vector<int> given(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] != -1) given[i] = 1;
        }

        long long A = a[0], B = a[n-1];
        if (A == -1 && B == -1) {
            A = B = 0;
        } else if (A == -1) {
            A = B;
        } else if (B == -1) {
            B = A;
        }
        a[0] = A;
        a[n-1] = B;

        for (int i = 0; i < n; ++i) {
            if (!given[i]) {
                if (i == 0) a[i] = A;
                else if (i == n-1) a[i] = B;
                else a[i] = 0;
            }
        }

        long long ans = llabs(a[n-1] - a[0]);
        cout << ans << '\n';
        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << a[i];
        }
        cout << '\n';
    }
    return 0;
}
