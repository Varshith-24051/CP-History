#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n , a , b ; 
    cin >> n >> a >> b ; c
    int L = max(a + 1, n - b);
    int ans = max(0, n - L + 1);
    cout << ans << "\n";
    return 0;
}