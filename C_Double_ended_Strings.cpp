#include <bits/stdc++.h>
using namespace std;

void solution() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size(), m = s2.size();
    int best = 0;

    for (int i = 0; i < n; i++) {
        for (int len = 1; i + len <= n; len++) {
            string sub = s1.substr(i, len);
            if (s2.find(sub) != string::npos) {
                best = max(best, len);
            }
        }
    }

    cout << (n + m - 2 * best) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
}
