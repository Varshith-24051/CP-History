#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n; cin >> n ; 
    string s; cin >> s ;
    int ans = 0 ; 
    for(int i = 0 ; i < n ; i++){
        if(s[i]!='0')break;
        ans++;
    }
    for( int i = n-1 ; i >=0 ; i--){
        if(s[i]!='0')break;
        ans++;
    }
    int con = 0 ; 
    for(int i = 0 ; i < n ; i++){
        if(s[i]=='0'){con++;}
        else {
            ans=max(ans,con);
            con=0;
        }
    }
    ans=max(ans,con);
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t; 
    while(t--)solution();
    return 0;
}
