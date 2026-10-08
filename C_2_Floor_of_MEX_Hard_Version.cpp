#include <bits/stdc++.h>
#define int long long
using namespace std;

void solution() {
    int n; 
    cin >> n; 
    
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; 
    }
    int ans = 0 ;
    vector<int> change(n + 1, 0);
    for(int k = 1; k <= n; k++){
        int L = a[k] * k, R = a[k] * k + k - 1;
        if(L < n){
            change[L]++;
            if(R + 1 < n){ change[R + 1]--; ans++; }
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