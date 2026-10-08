#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long n, k; 
    cin >> n >> k;
    vector<long long> a(n);
    
    for(auto& x : a) cin >> x; 
    
    if(k > 2 && n >= 2){
        cout << 0 << "\n"; 
        return; 
    }
    
    sort(a.begin(), a.end());
    
    long long minn = a[0]; 
    
    for(int i = 1; i < n; i++){
        minn = min(minn, a[i] - a[i-1]);
    }
    
    if(k == 1){
        cout << minn << "\n"; 
        return; 
    }
    else {
       
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long d = a[j] - a[i]; 
                
                auto it = lower_bound(a.begin(), a.end(), d);

                if(it != a.end()){
                    minn = min(minn, *it - d);
                }
                if(it != a.begin()){
                    it--; 
                    minn = min(minn, d - *it);
                }
            }
        }
        cout << minn << "\n"; 
        return; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}