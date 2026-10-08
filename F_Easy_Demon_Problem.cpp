#include <bits/stdc++.h>
using namespace std;
#define int long long 

const int maxx = 200000;
const int off = 200000;

// Boolean hash maps for O(1) lookups
bool hasA[400005];
bool hasB[400005];

bool check(int x, int y) {
    if(abs(x) > maxx || abs(y) > maxx)
        return false;
    return hasA[x + off] && hasB[y + off];
}

void solution() {
    int n, m, q; 
    cin >> n >> m >> q;
    
    vector<int> a(n), b(m);
    int asum = 0, bsum = 0; 
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        asum += a[i];
    }
    
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        bsum += b[i]; 
    }

    for(int i = 0; i < n; i++) {
        int val = asum - a[i]; 
        if(abs(val) <= maxx) hasA[val + off] = true;
    }
    
    for(int i = 0; i < m; i++) {
        int val = bsum - b[i]; 
        if(abs(val) <= maxx) hasB[val + off] = true;
    }
    
    while(q--) {
        int x; 
        cin >> x; 
        int absx = abs(x);
        bool possible = false; 

        for(int i = 1; i * i <= absx; i++) {
            if(absx % i == 0) {
                int j = absx / i; 
                
                if (x < 0) j = -j;
                
                if(check(i, j) || check(-i, -j) || check(j, i) || check(-j, -i)) {
                    possible = true; 
                    break;
                }
            }
        }
        cout << (possible ? "YES" : "NO") << "\n";
    }

    for(int i = 0; i < n; i++) {
        int val = asum - a[i]; 
        if(abs(val) <= maxx) hasA[val + off] = false;
    }
    for(int i = 0; i < m; i++) {
        int val = bsum - b[i]; 
        if(abs(val) <= maxx) hasB[val + off] = false;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solution();
    
    return 0;
}