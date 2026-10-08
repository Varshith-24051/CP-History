#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n; 
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(31, 0); 
    
    for(auto &x : a){
        for(int bit = 0; bit <= 30; bit++){
            if (x & (1 << bit)) {
                b[bit]++;
            }
        }
    } 
    
    int total_gcd = 0; 
    for(int i = 0; i <= 30; i++){
        total_gcd = __gcd(total_gcd, b[i]);
    }
    
    for(int k = 1; k <= n; k++){
        if (total_gcd % k == 0) {
            cout << k << " ";
        }
    }
    cout << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}