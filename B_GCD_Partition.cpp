#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    long long total = accumulate(a.begin(), a.end(), 0LL);

    long long pref = 0;
    long long ans = 0;

    for(int i = 0; i < n - 1; i++) {  
        pref += a[i];
        ans = max(ans, gcd(pref, total - pref ));
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solution();

    return 0;
}
