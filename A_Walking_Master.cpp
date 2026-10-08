#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (d < b) { 
        cout << -1 << '\n';
        return;
    }

    long long up_moves = d - b;
    long long after_up_x = a + up_moves;

    if (after_up_x < c) { 
        cout << -1 << '\n';
        return;
    }

    long long total_moves = 2 * up_moves + (a - c);
    cout << total_moves << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solution();
}
