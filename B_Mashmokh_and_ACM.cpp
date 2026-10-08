#include <bits/stdc++.h>
using namespace std;

#define int long long
const int  MOD = 1000000007;

void solution() {
    int n ,k ;
    if( !(cin >> n >> k ))return ; 
    
    vector<int> dp (n+ 1 , 1 ); 
    dp[0] = 0 ; 
for( int len = 2 ; len <=k ; len++ ){
    
        vector<int >ndp ( n+1 , 0 ); 
    for(int i = 1 ; i <= n ;i++){
        
        if(dp[i]==0) continue ;
        
        for(int j = i ; j <= n ; j+=i ){
             ndp[j] = (ndp[j] + dp[i]) % MOD;
        }
    }
    dp = move(ndp) ; 
}
int sum = 0 ; 
for( int i = 1 ; i <= n ;i++){
    sum = (sum + dp[i]) % MOD;
}
cout << sum << endl;
}

int_fast32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution();
    return 0;
}