#include <iostream>
#include <vector>

using namespace std;

void solution() {
    int n; 
    cin >> n; 
    vector<int> v(n); 
    for(int &x : v) cin >> x; 

    vector<int> ans;
    ans.push_back(v[0]); 

    for(int i = 1; i < n - 1; i++) {
        if (1LL * (v[i-1] - v[i]) * (v[i+1] - v[i]) > 0) {
            ans.push_back(v[i]); 
        }
    }
    ans.push_back(v[n-1]);

    cout << ans.size() << "\n";
    for(int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}