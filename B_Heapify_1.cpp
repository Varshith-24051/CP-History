#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    bool possible = true;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        int val = a;
        int idx = i;
        while (val % 2 == 0) val /= 2;
        while (idx % 2 == 0) idx /= 2;
        if (val != idx) possible = false;
    }
    if (possible) cout << "YES\n"; vect
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}