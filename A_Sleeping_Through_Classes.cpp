#include <bits/stdc++.h>
using namespace std;

void solution(){
    int  n , k ; cin >> n >> k ; 
    string s ; cin >> s ;
    int ans = 0 ; 
    int flag = 0 ; 
    for( int i = 0 ; i < n ; i++){
        if( s[i] !='1' && flag==0){
            ans++;
        }
        else if (  s[i] !='1' && flag){
            flag--;
        }
        else if(s[i]=='1'){
            flag = k ;
        }
    }
    cout << ans << endl ;
    return ; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ;
    while(t--)solution();
    return 0;
}
