#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, r, b;
        cin >> n >> r >> b;

        int base = r / (b + 1);
        int extra = r % (b + 1);

        string ans;

        for (int i = 0; i <= b; i++) {
            for (int j = 0; j < base; j++) ans += 'R';

            if (extra > 0) {
                ans += 'R';
                extra--;
            }

            if (i < b) ans += 'B';
        }

        cout << ans << "\n";
    }
    return 0;
}
