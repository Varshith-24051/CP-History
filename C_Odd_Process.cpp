#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> odds;
    vector<long long> evens;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 != 0) {
            odds.push_back(a[i]);
        } else {
            evens.push_back(a[i]);
        }
    }

    sort(odds.rbegin(), odds.rend());
    sort(evens.rbegin(), evens.rend());

    int n_odd = odds.size();
    int n_even = evens.size();

    vector<long long> even_pref(n_even + 1, 0);
    for (int i = 0; i < n_even; ++i) {
        even_pref[i + 1] = even_pref[i] + evens[i];
    }

    if (n_odd == 0) {
        for (int k = 1; k <= n; ++k) {
            cout << 0 << (k == n ? "" : " ");
        }
        cout << "\n";
        return;
    }

    long long max_odd = odds[0];

    for (int k = 1; k <= n; ++k) {
        int j = min(k - 1, n_even);
        int i = k - j;

       
        if (i % 2 == 0) {
            j--;
            i++;
        }
        if (j < 0 || i > n_odd) {
            cout << 0 << (k == n ? "" : " ");
        } else {
            long long current_score = max_odd + even_pref[j];
            cout << current_score << (k == n ? "" : " ");
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}