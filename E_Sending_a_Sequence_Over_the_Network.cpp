#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ;cin >> n; 
    vector<int>dp ( n+1,0);
    dp[0]=1 ;

    for(int i = 1 ;i<=n;i++){
        int x ; cin >> x ;
        if(dp[i-1] && x  +i <=n)dp[x+i]=1 ; 

        if(i-x-1 >= 0)dp[i]= dp[i] || dp[i-x-1] ;
    }

    cout<<(dp[n] ? "YES\n" : "NO\n");
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