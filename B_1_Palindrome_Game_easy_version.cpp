#include <bits/stdc++.h>
using namespace std;

bool is_pal(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
void solution() {
    int n; cin >> n;
    string s; cin >> s;

    int z = 0, mismatches = 0;
    for (char c : s) if (c == '0') z++;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) mismatches++;
    }

    if (mismatches == 0) {
        if (z % 2 == 1 && z > 1) cout << "ALICE"<<endl;
        else cout << "BOB"<<endl;
    } else {
        if (mismatches == 1 && z == 2) cout << "DRAW"<<endl;
        else cout << "ALICE"<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solution();
    return 0;
}