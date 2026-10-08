#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int best = 1;     
    int current = 1;   

    for (int i = 0; i + 1 < n; i++) {
        if (a[i + 1] - a[i] <= k) {
            current++;             
        } else {
            best = max(best, current);
            current = 1;           
        }
    }
    best = max(best, current);      

    cout << n - best << "\n";   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
