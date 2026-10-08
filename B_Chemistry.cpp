#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s) freq[c - 'a']++;

    int odd_count = 0;
    for (int f : freq) {
        if (f % 2 == 1) odd_count++;
    }

    if (odd_count - k <= 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solution();
    return 0;
}
