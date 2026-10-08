#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; 
    cin>>n;
    vector<int> a(n);
    for( int i =0 ; i<n ; i++) cin>>a[i];
    bool ans = false;
    sort(a.begin(),a.end());
    for( int i= 2 ; i < n ; i+=2){
        if(a[i]!=a[i-1]){
            ans=true;
            break;
        }
    }
    (ans)?cout<<"NO\n":cout<<"YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t; 
    while(t--)solution();
    return 0;
}