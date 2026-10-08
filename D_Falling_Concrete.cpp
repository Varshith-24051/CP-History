#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solution() {
    int n; 
    cin >> n; 
    set<int> a;
    
    int ballast = 0;
    
    for(int i = 0; i < n; i++) {
        int temp; 
        cin >> temp; 
        a.insert(temp - i);
    }
    if(a.empty()) {
        cout << 0 << endl; 
        return;
    }
    int ans = 1, count = 1; 
    int past = -1;

    for(int curr : a) {
        if(curr == past + 1) {
            count++;
        } else {
            count = 1; 
        }
        ans = max(ans, count);
        past = curr;
    }
    cout << ans << endl;
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