#include <bits/stdc++.h>
using namespace std;

bool can_win(int a, int k) {
    int pop = __builtin_popcount(a);
    int len = 32 - __builtin_clz(a);
    return (pop + len - 1) <= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int low = 1, high = n, ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (can_win(mid, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << (long long)n - ans << "\n";
    }
    return 0;
}
