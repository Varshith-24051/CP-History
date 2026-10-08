#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int minIdx = min_element(a.begin(), a.end()) - a.begin();
    int maxIdx = max_element(a.begin(), a.end()) - a.begin();

    if (a[minIdx] == a[maxIdx]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    for (int i = 0; i < n; i++) {
        if (i != minIdx && a[i] != a[minIdx]) {
            cout << minIdx + 1 << " " << i + 1 << "\n";
        }
        else{
            cout << maxIdx + 1 << " " << i + 1 << "\n";
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