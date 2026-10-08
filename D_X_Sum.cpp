#include <bits/stdc++.h>
using namespace std;
c
long long moveDiag(vector<vector<long long>> &a, int n, int m, int x, int y, int dx, int dy) {
    if (x < 0 || y < 0 || x >= n || y >= m) return 0;
    return a[x][y] + moveDiag(a, n, m, x + dx, y + dy, dx, dy);
}

long long finder(vector<vector<long long>> &a, int n, int m, int x, int y) {
    long long sum = a[x][y];

    sum += moveDiag(a, n, m, x + 1, y + 1, +1, +1); // ↘
    sum += moveDiag(a, n, m, x + 1, y - 1, +1, -1); // ↙
    sum += moveDiag(a, n, m, x - 1, y - 1, -1, -1); // ↖
    sum += moveDiag(a, n, m, x - 1, y + 1, -1, +1); // ↗

    return sum;
}

void reader() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    long long best = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            best = max(best, finder(a, n, m, i, j));
        }
    }

    cout << best << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        reader();
    }
    return 0;
}
