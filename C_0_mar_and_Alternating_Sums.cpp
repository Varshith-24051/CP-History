#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MOD = 1e9 +7;

int power(int base , int exp){
    int temp = 1;
    base %= MOD;
    while(exp>0){ 
        if(exp%2){temp= (temp * base)%MOD;}
        base= (base*base)%MOD;
        exp /= 2; 
    }
    return temp;
}

void solution() {
    int n ; cin >> n; 
    
    int dist = 0;
    int negpair = 0;
    bool neg = false;
    
    int prev = -2;
    
    for(int i = 0 ; i < n ;i++){
        int temp ; cin >> temp; 
        
        if(temp == -1) {
            if(!neg) {
                neg = true;
                dist++;
            }
        } else {


            if(temp != prev) {
                dist++;
                if(temp == prev + 1 && prev != -2) {
                    negpair++;
                }
                prev = temp;
            }
        }
    }
    
    int ans = power(2, n - dist);
    
    if(neg){
        ans = (ans * (negpair + 1)) % MOD;
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