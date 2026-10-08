#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;

        vector<long long> a(n+1);
        a[0] = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];

        vector<int> res;
        res.reserve(n);

        for(int i = 0; i < n; i++){
            long long diff = a[i+1] - a[i];
            if(i - diff >= 0)
                res.push_back(res[i - diff]);
            else
                res.push_back(i + 1);
        }

        for(int x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
