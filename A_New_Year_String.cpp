#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    string s;
    cin >> n >> s;

    bool has2025 = false;
    bool has2026 = false;

    for (int i = 0; i + 3 < n; i++) {
        if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '5')
            has2025 = true;
        if (s[i] == '2' && s[i+1] == '0' && s[i+2] == '2' && s[i+3] == '6')
            has2026 = true;
    }

    if (has2026 || !has2025)
        cout << 0 << '\n';
    else
        cout << 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
