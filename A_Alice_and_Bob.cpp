#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, a;
    cin >> n >> a;

    int l = 0, r = 0;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int x : v) {
        if (x < a) l++;
        if (x > a) r++;
    }

    if (l > r) {
        cout << a - 1 << '\n';
    } else {
        cout << a + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
