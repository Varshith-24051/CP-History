#include <bits/stdc++.h>
using namespace std;

void solution() {
    string s ; 
    cin>> s ; 
    long long  n = s.size() ;
    long long  ans = 0 , temp = 1 ;
    long long possible = 1 ; 
    for( int i = 1 ; i < n;i++){
        if(s[i-1]!= s[i]){
            ans+=temp-1;
            possible =(possible*temp)%998244353;
            temp = 1 ; 
        }
        else{
            temp++;
        }
    }
    ans += temp - 1;
    possible =(possible*temp)%998244353;
    for(int i = 1; i <=ans; i++){
        possible = (possible*i)%998244353;
    }
    cout<<ans << " "<<possible<<"\n";
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