#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n, m; 
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        
        int neg_count = 0;
        long long sum_abs = 0;
        int min_abs = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
                int val = grid[i][j];
                if (val < 0) neg_count++;
                sum_abs += abs(val);
                min_abs = min(min_abs, abs(val));
            }
        }

        if (neg_count % 2 == 1) {
            sum_abs -= 2LL * min_abs;
        }

        cout << sum_abs << "\n";
    }

    return 0;
}
