#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if (s == t){ cout << "YES\n" ; return ;}
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    while (q--) {
        solution();
    }
    return 0;
}
