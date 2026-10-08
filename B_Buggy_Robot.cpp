#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int u=0, d=0, l=0, r=0;
    for (char c : s) {
        if (c == 'U') u++;
        else if (c == 'D') d++;
        else if (c == 'L') l++;
        else if (c == 'R') r++;
    }

    cout << 2 * min(u, d) + 2 * min(l, r) << "\n";
    return 0;
}
