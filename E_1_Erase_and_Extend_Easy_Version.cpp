#include <bits/stdc++.h>
using namespace std;
void solution(){

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int len = 1; 
    for (int i = 1; i < n; ++i) {
        if (s[i] > s[i % len]) {
            break; 
        }
        if (s[i] < s[i % len]) {
            len = i + 1; 
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << s[i % len];
    }
    cout <<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution();
    return 0;
}