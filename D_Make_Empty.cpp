#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n; 
    vector<int> a(n);
    for(int &i : a) cin >> i;

    vector<int> line1, line2;
    for(int i = 0; i < n; i++) {
        if(i < n/2) {
            if(a[i] <= n/2) {
                line1.push_back(a[i]);
            } else {
                line2.push_back(a[i]);
            }
        }
        else {
            if(a[i] > n/2) {
                line1.push_back(a[i]);
            } else {
                line2.push_back(a[i]);
            }
        }
    }
    
    if(line1.empty() || line2.empty()) {
        cout << 1 << endl;
        
        cout << n << " ";
        
        for(int &i : line1) cout << i << " ";
        for(int &x : line2) cout << x << " ";
        cout << endl;
    }
    else {
        cout << 2 << endl;
        
        cout << line1.size() << " ";
        for(int &i : line1) cout << i << " ";
        cout << endl;
        
        cout << line2.size() << " ";
        for(int &x : line2) cout << x << " ";
        cout << endl;
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