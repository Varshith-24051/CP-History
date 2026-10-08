#include <bits/stdc++.h>
using namespace std;

long long check(long long val, vector<long long> a, vector<long long>& b, int n) {
    a[0] = val;
    sort(a.begin(), a.end());
    int i = 0, j = 0, matches = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            matches++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    return n - matches;
}

void solution() {
    long long n, m; 
    cin >> n >> m;
    
    vector<long long> a(n);
    for (int i = 1; i < n; i++) cin >> a[i];
    
    vector<long long> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    
    sort(b.begin(), b.end());

    long long k = check(1, a, b, n);
    long long low = 1, high = m, t = 1;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, a, b, n) == k) {
            t = mid;       
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }

    long long total_sum = (t * k) + ((m - t) * (k + 1));
    cout << total_sum << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1; 
    cin >> t;
    while (t--) solution();
    return 0;
}