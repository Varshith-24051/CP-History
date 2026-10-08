#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    long long ans = 0;
    long long cnt = 0;

    for(int i = 0; i < n; i++){
        if(a[i] <= q){
            cnt++;
        } else {
            if(cnt >= k){
                long long y = cnt - k + 1;
                ans += y * (y + 1) / 2;
            }
            cnt = 0;
        }
    }

    if(cnt >= k){
        long long y = cnt - k + 1;
        ans += y * (y + 1) / 2;
    }

    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solution();

    return 0;
}
