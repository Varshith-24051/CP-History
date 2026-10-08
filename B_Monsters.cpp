#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, k;
    cin >> n >> k;

    vector<pair<long long, int>> monsters(n);

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        monsters[i] = {x, i + 1};
    }

    for (int i = 0; i < n; i++) {
        monsters[i].first %= k;
        if (monsters[i].first == 0)
            monsters[i].first = k;
    }

    sort(monsters.begin(), monsters.end(),
         [](const pair<long long, int>& a,
            const pair<long long, int>& b) {
             if (a.first != b.first)
                 return a.first > b.first;   
             return a.second < b.second;     
         });

    for (auto &x : monsters)
        cout << x.second << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();
}
