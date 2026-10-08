#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;
    map < int, long long> counts;
    for (int i = 0; i < n; i++) {
        int x;
        cin >>  x;
        counts[x - i]++;
    }

    long long ans = 0;
    for (auto const & [val, num] : counts) {
        if (num >= 2) {
            ans += (num * (num - 1) )  / 2;
        }
    }
    cout <<ans << endl ;
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