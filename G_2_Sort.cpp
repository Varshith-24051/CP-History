#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n , k ; cin >> n >> k ; 
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ; 
    }

    int ans = 0 ;
    int streak = 0 ;
    
    for(int i = 1 ; i < n ; i++) {
        if(a[i - 1] < 2LL * a[i]) {
            streak++ ;
        }
        else {
            streak = 0 ;
        }
        
        if(streak >= k) {
            ans++ ;
        }
    }
    
    cout << ans << endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}