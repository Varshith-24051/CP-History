#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n; 
    string s ; 
    cin>> n >> s;
    for ( int i= 0 ; i < n/2; i++){
        if( s[i]==s[n-i-1]){
            cout<< abs(i+i-n-1)-1 << endl;
            return;
        }
    }
    if ( n%2==0)cout<< 0<< endl;
    else cout<< 1 << endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>> t; 
    while( t--){
        solution();
    }
    return 0;
}
