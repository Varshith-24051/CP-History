#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n; 
    vector<int> a(n);

    int zero = 0;
    int longest = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            zero++;
            longest = max(longest, zero);
        } else {
            longest = max(longest, zero);
            zero = 0;
        }
    }
    cout << longest << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t; 
    while (t--) {
        solution();
    }
    return 0;
}
