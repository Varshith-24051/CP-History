#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solution() {
    int n; 
    cin >> n;
    vector<int> a(n + 1), b(n + 1); 

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i - 1] + b[i];
    }
    vector<int> ans(n + 1, 0), count(n + 2, 0);

    for(int i = 1; i <= n; i++){
        int x = a[i] + pref[i - 1];
        int j = upper_bound(pref.begin(), pref.end(), x) - pref.begin();

        if(j <= n) {
            ans[j] += x - pref[j - 1]; 
        }

        count[i]++; 
        count[j]--; 
    }
    for(int i = 1; i <= n; i++){
        count[i] += count[i - 1];
        ans[i] += count[i] * b[i];
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";}
    cout << endl; 
    return ;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}