#include <bits/stdc++.h>
using namespace std;

void solution() {
    
    int n ; cin >> n; 
    vector<int> a(n );
    for(int &x : a )cin >> x ; 

    vector<int> dp(n+1 , 0 ); 

    for(int i = n-1; i>=0 ; i--){

        //skip 
        dp[i] = dp[i+1] + 1 ; 

        //no 
        
        int j = a[i] + 1 + i; 
        if(j <=n){
        dp[i] = min(dp[i], dp[j]);
}
    }
    cout<< dp[0]<< endl; 
    return; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}