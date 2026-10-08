#include <bits/stdc++.h>
using namespace std;

const int  MOD = 1e9 + 7 ;
#define int long long

void solution() {
    string s ; 
    cin>> s ;
    int count = 0 , p = 1 ; 

    for(int i = 0 ; i < s.size() ; i++){
        if(s[i] =='a'){
            count++;

        }
        else if(s[i] =='b'){
            p= p*(count +1 )%MOD;
            count = 0 ; 
        }
    }
    p = p*(count + 1 ) %MOD; 
    int ans = ( p-1 +  MOD) % MOD ; 

    cout << ans << endl ; 
    return ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
    return 0;
}