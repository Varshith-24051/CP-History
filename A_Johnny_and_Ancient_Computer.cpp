#include <bits/stdc++.h>
using namespace std;

void solution() {
    long long a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << "\n";
        return;
    }

    long long minn = min(a, b);
    long long maxx = max(a, b);

    int counter = 0;

    while (minn < maxx) {
        minn *= 2;
        counter++;
    }

    if (minn == maxx) {
        cout << (counter + 2) / 3 << endl; 
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
