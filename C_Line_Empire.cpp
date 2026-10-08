#include <bits/stdc++.h>
using namespace std;

void solution() {

    long long n, a, b; 
    cin >> n >> a >> b;

    vector<long long> arr(n + 1, 0); 
    for(int i = 1; i <= n; i++) {
        cin >> arr[i]; 
    }

    vector<long long> suf(n + 2, 0);
    for(int i = n; i >= 1; i--){
        suf[i] = suf[i + 1] + arr[i]; 
    }

    long long ans = 2e18; 
    
    for(int i = 0; i <= n; i++){
        long long cost = arr[i] *(a + b) +(suf[i + 1] - (n - i) *arr[i]) * b;
        ans = min(ans,cost);
    }
    
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}