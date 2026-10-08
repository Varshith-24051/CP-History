#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 998244353;

int pwr(int x, int y) {
    int base = 1; 
    x %= MOD;
    while(y) {
        if(y % 2) base = (base * x) % MOD;
        x = (x * x) % MOD;
        y /= 2;}
    return base;
}

int invert(int x) {
    return pwr(x, MOD - 2);
}

void solution() {
    int n; cin >> n; 
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(a.begin(), a.end());

    int factorial = 1; 
    for(int i = 1; i < n; i++) factorial = (factorial *i) % MOD;
    int ans = 0, sum = 0; 

    for(int i = 0; i < n; i++) {
        int temp = sum;
        if(i < n -1) temp = (temp -1 + MOD) %MOD;
        int curr = (a[i] % MOD) *temp %MOD;
        ans = (ans + (curr * factorial) %MOD) %MOD;
    
        if(i < n -1) sum = (sum + invert(n -i -1)) % MOD;
    }
    cout << ans << endl;
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}