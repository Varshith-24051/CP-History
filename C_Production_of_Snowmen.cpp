#include <iostream>
#include <vector>

using namespace std;

long long countt(int n, const vector<int>& lower, const vector<int>& upper) {
    long long vc = 0;
    vector<int> safe = upper;
    safe.insert(safe.end(), upper.begin(), upper.end());

    for (int shift = 0; shift < n; ++shift) {
        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (lower[i] >= safe[i + shift]) {
                possible = false;
                break;
            }
        }
        if (possible) {
            vc++;
        }
    }
    return vc;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;
    for (int &x : c) cin >> x;


    cout << countt(n, a, b) * countt(n, b, c) * n << endl;
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