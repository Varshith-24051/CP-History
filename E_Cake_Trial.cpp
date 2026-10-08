#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ;
    string s ; 
    cin >> n >> s; 
    vector<vector<int>> dp(n+1 ,vector<int>(n+1,INT_MAX));

    dp[0][0] = 0 ; 
    for(int i = 0 ; i < n;i++){
        vector<vector<int>> newdp(n+1, vector<int>(n+1,INT_MAX));
        for(int f = 0 ; f <=i;f++){
            for(int summ = 0 ; summ <=i;summ++ ){
                if(s[i] != 'T'){//F and N 
                    newdp[f+1][summ+1] = min(newdp[f+1][summ+1], max(dp[f][summ] , summ+1));
                }
                if(s[i] != 'F'){
                    newdp[f][max(0, summ-1)] = min(newdp[f][max(0, summ -1)],dp[f][summ]);
                }
            }
        }swap(dp,newdp);
    }
    int ans = 0 ; 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ;j++){
            ans = max (ans , i - dp[i][j]);
        }
    }
    cout << ans << endl; 
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