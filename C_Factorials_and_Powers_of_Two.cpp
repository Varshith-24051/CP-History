#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INT_MAXX = 1e18;

vector<int> facts;

void sollu() {
    int curr = 2; 
    for (int i = 3; i <= 14; i++) {
        curr *= i; 
        facts.push_back(curr);
    }
}

void solution() {
    int n; 
    cin >> n;

    int ans = INT_MAXX;
    
    for (int i = 0; i < (1LL << 12); i++) {
        int sum = 0; 
        int count = 0; 
        
        for (int j = 0; j < 12; j++) {
            if ((i >> j) & 1) {
                sum += facts[j];
                count++;
            }
        }
        if (sum > n) continue; 
        
        int curr = count + __builtin_popcountll(n - sum);
        ans = min(ans, curr);
    }
    
    cout << ans << endl; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sollu(); 
    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}