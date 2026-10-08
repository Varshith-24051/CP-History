#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    char cmp;
    cin >> cmp;

    string s;
    cin >> s;

    if (cmp == 'g') {
        cout << 0 << "\n";
        return;
    }

    string t = s + s;

    vector<int> green;
    for (int i = 0; i < 2 * n; i++) {
        if (t[i] == 'g')
            green.push_back(i);
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == cmp) {
            auto it = lower_bound(green.begin(), green.end(), i);
            ans = max(ans, *it - i);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
}
