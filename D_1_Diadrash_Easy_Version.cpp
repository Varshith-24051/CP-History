#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; cin>>n;
    vector<int> a(n) ;
    for(int i =0 ; i<n ; i++) cin>>a[i];
    bool ans = false; 
    for( int i= 0 ; i < n ; i++){
        if(a[i]==a[i-1]){ans=true;
        break;}
    }
    if(ans){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t;
    while(t--){solution();
    }
    return 0;
}