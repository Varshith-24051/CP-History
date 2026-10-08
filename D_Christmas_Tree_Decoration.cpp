#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;}
    return res;
}

long long MODD(long long n) {return power(n, MOD - 2);}

long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n + 1);
    long long sum_a = 0;
    
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
        sum_a += a[i];
    }
    long long k = sum_a / n;
    int r = sum_a % n;

    long long base1 = 0;
    int c1 = 0; 
    int c0 = 0; 

    for (int i = 1; i <= n; ++i) {
        if (a[i] < k) {
            base1 += (k - a[i]);
        }
        
        if (a[i] <= k) c1++;
        else c0++;
    }

    long long isok = a[0] - base1;

    if (isok < 0) {
        cout << 0 << endl;
        return;
    }

    vector<long long> fact(n + 1);
    vector<long long> invFact(n + 1);
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = MODD(fact[i]);
    }

    long long possible = 0;

    for (int j = 0; j <= r; ++j) {
        if (j <= isok) {
            long long ways = nCr(c1, j, fact, invFact);
            long long ways2 = nCr(c0, r - j, fact, invFact);
            long long term = (ways * ways2) % MOD;
            possible = (possible + term) % MOD;
        }
    }

    long long result = possible;
    result = (result * fact[r]) % MOD;
    result = (result * fact[n - r]) % MOD;

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}