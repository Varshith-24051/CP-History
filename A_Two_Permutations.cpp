#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, a, b;
    cin >> n >> a >> b;
    ((a + b +2<= n||(a==b&&b==n)) ? cout << "YES" : cout << "NO");
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
