#include <iostream>

using namespace std;

void solve() {
    long long n, k;
    cin >> n >> k;
    if (k > n) {
        cout << -1 << "\n";
        return;
    }
    for (int t = 0; t <= 62; ++t) {
        long long divisor = 1LL << t;
        long long q = n / divisor;
        long long r = n % divisor;

        if (k == q + 1 && r > 0) {
            cout << t << "\n";
            return;
        }
        if (k == q) {
            cout << t << "\n";
            return;
        }
        if (divisor > n) break;
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}