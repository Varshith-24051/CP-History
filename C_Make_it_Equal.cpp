#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];

        for (int i = 0; i < n; i++) {
            int r = A[i] % k;
            A[i] = min(r, k - r);
        }
        for (int i = 0; i < n; i++) {
            int r = B[i] % k;
            B[i] = min(r, k - r);
        }

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        cout << (A == B ? "YES\n" : "NO\n");
    }
}
