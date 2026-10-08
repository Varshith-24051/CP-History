#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int count = 0;
    for (int x : a)
        if (x == 2) count++;

    if (count == 0) {
        cout << 1 << '\n';
        return;
    }

    if (count % 2 == 1) {
        cout << -1 << '\n';
        return;
    }

    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) temp++;
        if (temp == count / 2) {
            cout << i + 1 << '\n';
            return;
        }
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
