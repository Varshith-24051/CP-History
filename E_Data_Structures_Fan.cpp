#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ; cin >> n ; 
    vector<int> a(n+1); 
    vector<int> pref(n+1 , 0 );
    for( int i = 1; i <= n ;i++){
        cin >> a[i]; 
        pref[i ] = pref[i-1] ^a[i] ;
    }
    string s; 
    cin >> s ;
     
    int xor1 = 0 , xor0 = 0 ; 
    for( int i = 0; i < n ;i++){
        if(s[i] == '0'){
            xor0 ^= a[i+1];
        } else {
            xor1 ^= a[i+1];
        }
    }
    int q ; cin >> q ; 
    while(q--){
        int type ; 
        cin >> type ;

        if( type==1){
            int l , r; 
            cin >> l >> r ; 

            xor0 ^= pref[r] ^ pref[l-1];
            xor1 ^= pref[r] ^ pref[l-1];
        }
        else{
            int g ; cin >> g; 

            if(g ) cout << xor1 <<" " ; 
            else cout << xor0 << " ";
        }
    }
    cout << endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}