#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; cin >> n ; 
    string s; cin >> s;  
    int ans = 0 ; 
    for(int i = n-1 ; i >=0 ; i--){
        if(s[i]!=s[n-1]){
        ans++;}
    }
    cout<< ans<<"\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin>> t ; 
    while(t--)solution();
    return 0;
}