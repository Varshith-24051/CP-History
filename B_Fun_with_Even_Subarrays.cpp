#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    int last = a[n - 1];
    int op = 0;
    int length = 1;   

    while (length < n) {
        if (a[n - length - 1] == last) {
            length++;
        } else {
            op++;
            length *= 2;
        }
    }

    cout << op << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solution();

    return 0;
}
