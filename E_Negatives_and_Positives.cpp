#include <bits/stdc++.h>
using namespace std;

void solution() {
    bool found_zero = false;  
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) found_zero = true;
    }

    if (found_zero) {
        long long temp = 0;
        for (int i = 0; i < n; i++) {
            temp += llabs(a[i]);  
        }
        cout << temp << "\n";
        return;
    }
    else {
        int neg = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) neg++;
        }

        long long temp0o = 0;
        for (int i = 0; i < n; i++) {
            temp0o += llabs(a[i]);
        }

        if (neg % 2 == 0) {
            cout << temp0o << "\n";
        }
        else {
            long long minn = LLONG_MAX;
            for (int i = 0; i < n; i++) {
                minn = min(minn, llabs(a[i]));
            }
            cout << temp0o - 2LL * minn << "\n"; 
        }
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
