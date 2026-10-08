#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, tt; 
    cin >> n >> tt; 
    
    vector<long long> a(n);
    for(long long &x : a) cin >> x;
    
    vector<long long> res(n + 1, 0);
    for(int i = 0; i < n; i++) {
        res[i + 1] = res[i] + a[i];  
    }

    vector<long long> pref_max(n);
    long long current_max = 0;
    for(int i = 0; i < n; i++) {
        current_max = max(current_max, a[i]);
        pref_max[i] = current_max;
    }

    while(tt--) {
        long long temp; 
        cin >> temp;
        int pointer = upper_bound(pref_max.begin(), pref_max.end(), temp) - pref_max.begin();
        
        cout << res[pointer] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}