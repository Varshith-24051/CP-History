#include <iostream>

using namespace std;

void solve() {
    long long n, x, y;
    cin >> n >> x >> y;
    
    long long sum_a = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        sum_a += a;
    }
    if ((x + sum_a) % 2 == y % 2) {
        cout << "Alice"<<endl;
    } else {
        cout << "Bob"<<endl;
    }
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