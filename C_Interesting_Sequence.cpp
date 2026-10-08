#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solution() {
    int n , x ; 
    cin >> n >> x ;

    if(n ==x ){
        cout<<n << endl ; 
        return;  
    }
    int ans = -1; 
    for(int i = 0 ; i <=61 ;i++){
        if(((n>>i)<<i)==x){
            int m = x | ((int)1<<i);
            ans=(m>=n) ? m :-1;
            break; 
        }
    }
    cout<<ans<<endl;
    return;
     
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}