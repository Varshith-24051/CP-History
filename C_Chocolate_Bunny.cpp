#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
    
    cout << "? " << x << " " << y << endl; 
    int ans;
    cin >> ans;

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> ans(n + 1);
    int mx_idx = 1;

    for (int i = 2; i <= n; i++) {
        int a = query(mx_idx, i); 
        int b = query(i, mx_idx); 

        if (a > b) {
            ans[mx_idx] = a; 
            mx_idx = i; 
        } else {
            ans[i] = b;
        }
    }

    ans[mx_idx] = n;

    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << (i == n ? "" : " ");
    }
    cout << endl; 

    return 0;
}