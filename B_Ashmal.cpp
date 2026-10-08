#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    vector<string> a(n);

    for (int i = 0; i < n; i++)cin >> a[i];
    string s = "";

    for (int i = 0; i < n; i++) {
        string l = a[i] + s;
        string r = s + a[i];
        s = min(l, r);
    }
    cout << s << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();

    return 0;
}
