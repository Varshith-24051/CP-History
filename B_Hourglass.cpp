#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    long long s, k, m;
    cin >> s >> k >> m;
    long long n = m / k; 
    long long r = m % k; 

    if (s <= k) {
        cout << max(0LL, s - r) << "\n";
    } else {
        if (n % 2 == 0) {
            cout << s - r << "\n";
        } else {
            cout << k - r << "\n";
        }
    }
}

int main() {
    // Fast I/O
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