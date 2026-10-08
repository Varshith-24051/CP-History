#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool bad = false;

        for (int i = 0; i < (int)s.size() - 1; i++) {
            if (s[i] != '<' && s[i + 1] != '>') {
                cout << -1 << '\n';
                bad = true;
                break;
            }
        }

        if (!bad) {
            int cntL = 0, cntR = 0;
            for (char c : s) {
                if (c == '<') cntL++;
                else if (c == '>') cntR++;
            }
            cout << (int)s.size() - min(cntL, cntR) << '\n';
        }
    }

    return 0;
}
