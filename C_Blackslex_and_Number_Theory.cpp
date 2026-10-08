#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long long x = a[1] - a[0]; 
    long long y = a[0];
    
    cout << max(x, y) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}