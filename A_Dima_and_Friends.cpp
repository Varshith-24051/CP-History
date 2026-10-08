#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int sum = accumulate(a.begin(), a.end(), 0);

    int ans = 0;
    for (int i = 1; i <= 5; i++) {
        if ((sum + i) % (n + 1) != 1)
            ans++;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
    return 0;
}
