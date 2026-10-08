#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Fixed space
#include <ext/pb_ds/tree_policy.hpp> 

using namespace __gnu_pbds; 
using namespace std;

template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 

void solution() {
    int n;
    cin >> n; 
    
    vector<pair<int, int>> a(n); 
    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    sort(a.begin(), a.end()); 
    
    oset<int> s;
    long long ans = 0; 
    
    for (int i = 0; i < n; i++) {
        int b = a[i].second; 
        
        ans += (i - s.order_of_key(b));
        s.insert(b);
    } 
    
    cout << ans << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) solution();
    }
    return 0;
}