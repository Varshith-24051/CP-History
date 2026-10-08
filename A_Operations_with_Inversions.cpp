#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; cin >> n ; 
    vector<int> a(n);
    for( int i = 0; i< n ; i++)cin>>a[i];
    if(n==1){
        cout<<0<<endl;
        return;
    }
    int cmp = a[0];
    int ans = 0 ; 
    for(int i = 1 ; i < n ; i++){
        if(a[i]<cmp)ans++;
        else cmp = a[i];
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; 
    while(t--)solution();
    return 0;
}
