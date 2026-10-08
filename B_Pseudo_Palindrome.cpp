#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, d; 
    cin >> n >> d;
    vector<int> a(n);
    for(int &x : a) cin >> x; 
    
    sort(a.begin(), a.end());
    
    int fails = 0;
    
    for(int i = 0; i + 1 < n; ) {
        if(a[i+1] - a[i] <= d) {
            i += 2; 
        } else {
            fails++; 
            i += 1; 
        }
    }
    
    if (n % 2 == 0 && fails == 0) {
        cout << "YES\n";
    } 
    else if (n % 2 != 0 && fails <= 1) {
        cout << "YES\n";
    } 
    else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}