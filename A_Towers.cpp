#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    int max_height = 0;
    for (auto &p : freq) {
        max_height = max(max_height, p.second);
    }

    cout << max_height << " " << freq.size() << endl;
    return 0;
}
