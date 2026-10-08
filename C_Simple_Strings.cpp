#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();

    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c != s[i - 1] && (i + 1 == n || c != s[i + 1])) {
                    s[i] = c;
                    break;
                }
            }
        }
    }

    cout << s << "\n";

    return 0;
}