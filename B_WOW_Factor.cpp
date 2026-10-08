#include <iostream>
#include <string>

using namespace std;

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    long long total_w = 0;
    
    for (int i = 0; i < s.length() - 1; i++) {
        if (s[i] == 'v' && s[i+1] == 'v') {
            total_w++;
        }
    }

    long long ans = 0;
    long long left_w = 0;

    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() - 1 && s[i] == 'v' && s[i+1] == 'v') {
            left_w++;
        } 
        else if (s[i] == 'o') {
            long long right_w = total_w - left_w;
            ans += (left_w * right_w);
        }
    }

    cout << ans << "\n";
    return 0;
}