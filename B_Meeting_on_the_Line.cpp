#include <bits/stdc++.h>
using namespace std;
#define int long double

void solution() {
    int n ; cin >> n ; 
    vector<int> x(n) ,t(n);
    for(int &xx :x )cin >> xx;
    for(int&tt : t)cin >> tt; 

    int left = 2e18 , right = -2e18;

    for(int i = 0 ; i < n ;i++){
        left = min(left , x[i] - t[i]);
        right = max(right , x[i] + t[i]);
    }
    int ans = (left+right )/2.0;
    cout<<setprecision(16)<<ans<<endl;
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