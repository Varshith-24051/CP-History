#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n; 
    string s; 
    cin >> s;

    long long pos = 0, neg = 0; 

    for (int i = 0; i < n; i++) {
        if (s[i] == '+') pos++; 
        else neg++; 
    }

    int q; 
    cin >> q;
    while (q--) {
        long long a, b; 
        cin >> a >> b; 

        if (a == b) {
            if (pos == neg) cout << "YES\n"; 
            else cout << "NO\n"; 
            continue; 
        }

        if (((neg - pos) * b) % (a - b) != 0) {
            cout << "NO\n"; 
            continue; 
        }

        long long temp = ((neg - pos) * b) / (a - b);
        if (temp >= -neg && temp <= pos) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n"; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) solution();
    return 0;
}