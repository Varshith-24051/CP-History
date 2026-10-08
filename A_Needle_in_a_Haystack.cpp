#include <bits/stdc++.h>
using namespace std;

void solution() {
    string s, t;
    cin >> s >> t;

    vector<int> s_count(26, 0), t_count(26, 0);
    for (char c : s) s_count[c - 'a']++;
    for (char c : t) t_count[c - 'a']++;

    for (int i = 0; i < 26; ++i) {
        if (t_count[i] < s_count[i]) {
            cout << "Impossible\n";
            return;
        }
    }

    int index_s = 0;
    int n = (int)s.size();

    for (int c = 0; c < 26; ++c) {
        int extras = t_count[c] - s_count[c]; 

        while (extras > 0 || (index_s < n && s[index_s] - 'a' <= c)) {
            if (extras == 0) {
                cout << s[index_s];
                index_s++;
            }
            else if (index_s == n || s[index_s] - 'a' > c) {
                cout << char('a' + c);
                extras--;
            }
            else {
                cout << s[index_s];
                index_s++;
            }
        }
    }

    while (index_s < n) {
        cout << s[index_s++];
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; if (!(cin >> T)) return 0;
    while (T--) solution();
    return 0;
}
