#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pwr_naive(ll x, ll n) {
    ll result = 1;
    for (ll i = 0; i < n; i++) {
        result *= x;
    }
    return result;
}

ll pwr_dnc(ll x, ll n) {
    if (n == 0) return 1;
    ll half = pwr_dnc(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return half * half * x;
}

ll pwr_be(ll x, ll n) {
    ll result = 1;
    while (n > 0) {
        if (n & 1) result *= x;
        x *= x;
        n >>= 1;
    }
    return result;
}

void solution() {
    ll x, n;
    cin >> x >> n;
    cout << "naive: " << pwr_naive(x, n)
         << " divide_and_conquer: " << pwr_dnc(x, n)
         << " binary_exponentiation: " << pwr_be(x, n)
         << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
