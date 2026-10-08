#include <bits/stdc++.h>
using namespace std;

vector<int> a, b;

bool trace(int mid) {
    int c = 0; 
    int N = a.size();
    
    for(int i = 0; i < N; i++) {
        if(a[i] >= mid - c - 1 && b[i] >= c) {
            c++;
        }
    }
    return (c >= mid);
}

void solution() {
    int n; 
    cin >> n; 
    
    a.resize(n);
    b.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i]; 
    }
    
    int l = 1, r = n;
    int ans = 0;
    
    while(l <= r) {
        int mid = l + (r - l) / 2;
        
        if(trace(mid)) {
            ans = mid;       
            l = mid + 1;
        } else {
            r = mid - 1;    
        }
    }
    
    cout << ans << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}