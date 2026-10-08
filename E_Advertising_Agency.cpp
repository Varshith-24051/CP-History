#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
vector<vector<int>> c(1005, vector<int>(1005, 0));

void cbr() {
    for (int i = 0; i <= 1000; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
        }
    }
}

void solution() {
    int n, k; 
    cin >> n >> k;

    vector<int> a(n); 
    for (int &x : a) cin >> x;

    sort(a.rbegin(), a.rend());
    
    int temp = 0; 
    int cmp = a[k-1];

    for (int i = k; i < n; i++) {
        if (a[i] == cmp) temp++; 
        else break;
    }
    
    int deffer = 0; 
    for (int i = k - 1; i >= 0; i--) {
        if (a[i] == cmp) deffer++; 
        else break;
    }
    
    cout << c[temp + deffer][deffer] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cbr();
    
    int t;
    cin >> t;
    while (t--) solution();
    
    return 0;
}