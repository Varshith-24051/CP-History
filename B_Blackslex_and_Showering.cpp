#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<long long>a(n);
        for(auto &x : a) cin >> x;

        long long ans = 0, best = 0;
        for(int i = 0; i + 1 < n; i++)
            ans += llabs(a[i] - a[i + 1]);

        for(int i = 0; i < n; i++){
            long long cur = 0;
            if(i) cur += llabs(a[i] - a[i - 1]);
            if(i + 1 < n) cur += llabs(a[i] - a[i + 1]);
            if(i && i + 1 < n) cur -= llabs(a[i - 1] - a[i + 1]);
            best = max(best, cur);
        }
        cout << ans - best << "\n";
    }
}

