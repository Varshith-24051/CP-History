#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; cin>>n;
    vector<int> a(n);
    int ans=0;
    for( int i = 0 ; i < n ; i++)cin>>a[i];
    for(int i = 0 ; i < n-1 ;i++){
        if(a[i]%2==a[i+1]%2 ){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--)solution();
    return 0;
}