#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ;
    cin>>n;
    vector<int> a(n);
    for(int i = 0 ; i < n ;i++)cin>>a[i];
    int ans = a[0] -1;
    for( int i = 0 ; i +1< n ; i++){
        if (a[i] !=i+1){
            ans = gcd(ans,abs(a[i]-1-i));
        }
    }
    cout<<ans<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--)solution();
    return 0;
}