#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '0') cout << i + 1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
