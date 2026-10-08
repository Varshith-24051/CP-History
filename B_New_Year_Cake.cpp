#include <bits/stdc++.h>
using namespace std;

int solve_one(long long a, long long b, bool sw) {
    long long need = 1;
    int layers = 0;

    while (true) {
        if ((layers % 2 == 0) == sw) {
            if (a < need) break;
            a -= need;
        } else {
            if (b < need) break;
            b -= need;
        }
        layers++;
        need <<= 1; 
    }
    return layers;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        int ans = max(
            solve_one(a, b, true),   
            solve_one(a, b, false)   
        );

        cout << ans << '\n';
    }
    return 0;
}
