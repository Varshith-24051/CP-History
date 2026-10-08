#include <bits/stdc++.h>
using namespace std;
#define int long long 

int MOD = 998244353; 

int pwr(int base, int e){
    int res = 1; 
    while(e){
        if(e % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        e /= 2;
    }
    return res;
}

void solution() {
    int n; 
    cin >> n; 
    int ways = 1; 

    for(int i = 0; i < n; i += 3){
        int a, b, c; 
        cin >> a >> b >> c; 
        int minn = min({a, b, c});
        int count = (a == minn) + (b == minn) + (c == minn);

        ways = (ways * count) % MOD;
    }
    
    int three = n / 3, half = n / 6;
    int num = 1, den = 1; 
    
    for(int i = 1; i <= three; i++) num = (num * i) % MOD;
    for(int i = 1; i <= half; i++) den = (den * i) % MOD;
    den = (den * den) % MOD;

    cout << ways * num % MOD * pwr(den, MOD - 2) % MOD<< '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
    
    return 0;
}