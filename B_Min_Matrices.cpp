#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, k;
    cin >> n >> k;
    
    if (k < n || k > 2 * n - 1) {
        cout << -1 << endl;
        return;
    }

    int full = k - n; 
    vector<vector<int>> a(n, vector<int>(n, -1)); 
    int start = 1;
    a[0][0] = start++;

    for (int i = 1; i <= full; i++) {
        a[i][0] = start++; a[0][i] = start++; 
    }

    for (int i = full + 1; i < n; i++) {
        a[i][i] = start++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == -1) {
                a[i][j] = start++;
            }
            cout << a[i][j] << " ";
        }
        cout << "\n"; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}