#include <bits/stdc++.h>
using namespace std;

const int B_MAX = 1000;
vector<int> min_moves(B_MAX + 1, 1e9);

void precompute() {
    min_moves[1] = 0;
    for (int i = 1; i <= B_MAX; i++) {
        for (int x = 1; x <= i; x++) {
            int next_val = i + (i / x);
            if (next_val <= B_MAX) {
                min_moves[next_val] = min(min_moves[next_val], min_moves[i] + 1);
            }
        }
    }
}

void solution() {
    int n, k; 
    cin >> n >> k; 
    vector<int> b(n), c(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    int limit = min(k, 12 * B_MAX); 
    vector<int> kdp(limit + 1, 0);

    for(int i = 0; i < n; i++) {
        int weight = min_moves[b[i]];
        int val = c[i];
        for(int j = limit; j >= weight; j--) {
            kdp[j] = max(kdp[j], kdp[j - weight] + val);
        }
    }
    cout << kdp[limit] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute(); 

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}