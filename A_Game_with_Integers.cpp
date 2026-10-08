#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n;

    int remainder = n % 3;
    int counter = 19; 

    if ((n - 1) % 3 == 0 || (n + 1) % 3 == 0) {
        cout << "First\n";
    } else {
        if (n > 19) {
            cout << "Second\n";
            return;
        }
        if (remainder % 2 == 0)
            cout << "Second\n";
        else
            cout << "First\n";
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
