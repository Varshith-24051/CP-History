#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        vector<int> b(n*(n-1)/2);
        for(int &x : b) cin >> x;

        sort(b.begin(), b.end());

        int idx = 0;

        for(int i=n-1;i>=1;i--){
            cout << b[idx] << " ";
            idx += i;
        }

        cout << 1000000000 << "\n";
    }
}