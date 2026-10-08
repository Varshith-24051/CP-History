#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases; 
    cin >> cases; 
    while (cases--) {
        int n; 
        cin >> n; 

        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if (n == 2) {
            cout << "-1\n";
            continue;
        }

        vector<int> ans;
        for (int i = 1; i <= n*n; i += 2) ans.push_back(i);
        for (int i = 2; i <= n*n; i += 2) ans.push_back(i);

        for (int i = 0; i < (int)ans.size(); i++) {
            cout << ans[i] << " ";
            if ((i + 1) % n == 0) cout << "\n";
        }
    }
    return 0;
}
