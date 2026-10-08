#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, m;
    string x, s;
    cin >> n >> m >> x >> s;

    string repeated = x;
    int repeats = 0;

    while (repeated.size() <s.size()) {
        repeated += repeated;
        repeats++;
    }
    if (repeated.find(s) != string::npos) {
        cout << repeats << endl;
        return;
    }

    repeated += repeated;
    repeats++;

    if (repeated.find(s) != string::npos) {
        cout << repeats << endl;
    } else {
        cout << -1 << endl; 
    }
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
