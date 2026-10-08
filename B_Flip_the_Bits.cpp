#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int ones = 0, zeros = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') ones++;
        else zeros++;
    }

    bool f = false;
    
    for (int i = n - 1; i >= 0; i--) {

        char current_a = a[i];
        if (f) {
            current_a = (current_a == '1') ? '0' : '1';
        }

        if (current_a != b[i]) {
            if (ones != zeros) {
                cout << "NO\n";
                return;
            }
            f = !f;
        }

        if (a[i] == '1') ones--;
        else zeros--;
    }

    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}