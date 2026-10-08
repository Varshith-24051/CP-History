#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<int> f(n);
    long long max_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        long long v0 = a[i];
        long long v1 = -a[i] - 1;
        
        // Find the optimal choice for this specific element
        if (v1 > v0) {
            f[i] = 1; // 1 means we optimally want to flip this element
            max_sum += v1;
        } else {
            f[i] = 0; // 0 means we optimally want to leave it alone
            max_sum += v0;
        }
    }

    // Check if the optimal state is the ONE forbidden state
    bool forbidden = true;
    if (f[n - 1] != 1) {
        forbidden = false;
    } else {
        for (int i = n - 2; i >= 0; i--) {
            if (f[i] == f[i + 1]) {
                forbidden = false;
                break;
            }
        }
    }

    // If it's forbidden, we MUST take exactly one minimum penalty
    if (forbidden) {
        long long min_penalty = 2e18; // effectively infinity
        for (int i = 0; i < n; i++) {
            long long penalty = abs(2LL * a[i] + 1);
            min_penalty = min(min_penalty, penalty);
        }
        max_sum -= min_penalty;
    }

    cout << max_sum << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}