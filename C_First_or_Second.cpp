#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }

    long long max_x = -suff[1];

    long long current_abs_sum = 0;

    for (int k = 1; k < n; k++) {
        long long current_score = a[0] + current_abs_sum - suff[k + 1];
        
        max_x = max(max_x, current_score);
        current_abs_sum += abs(a[k]);
    }

    cout << max_x << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}