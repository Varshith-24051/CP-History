#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            a[i] = n - a[i];   
        }

        sort(a.begin(), a.end());  

        long long sum = 0;
        int ans = 0;

        for (int i = 0; i < k; i++) {
            if (sum + a[i] < n) {   
                sum += a[i];
                ans++;
            } else {
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
