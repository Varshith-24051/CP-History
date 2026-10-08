#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if(!(cin >> T)) return 0;
    while (T--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // Build frequency and unique sorted list
        unordered_map<ll,int> freq;
        freq.reserve(n * 2);
        for (ll x : a) freq[x]++;

        vector<ll> uniq;
        uniq.reserve(freq.size());
        for (auto &p : freq) uniq.push_back(p.first);
        sort(uniq.begin(), uniq.end());

        ll maxA = uniq.empty() ? 0 : uniq.back();

        // Fast presence check
        unordered_set<ll> present;
        present.reserve(freq.size()*2);
        for (ll x : uniq) present.insert(x);

        // Find valid candidates (subset of uniq)
        vector<ll> candidates;
        candidates.reserve(uniq.size());

        for (ll b : uniq) {
            // number of multiples to check: tmax = floor(k/b)
            ll tmax = k / b;
            // the largest required multiple is tmax * b
            ll largest = tmax * b;
            // If largest > maxA, at least one required multiple is missing -> invalid
            if (largest > maxA) continue;

            // Check all multiples m = b, 2b, ..., largest are present.
            bool ok = true;
            for (ll m = b; m <= largest; m += b) {
                if (present.find(m) == present.end()) { ok = false; break; }
            }
            if (ok) candidates.push_back(b);
        }

        // Coverage: mark which uniq values are covered by selected B
        unordered_map<ll,bool> covered;
        covered.reserve(uniq.size()*2);
        for (ll x : uniq) covered[x] = false;

        vector<ll> answer;
        // Process candidates in increasing order
        sort(candidates.begin(), candidates.end());
        for (ll b : candidates) {
            if (!covered[b]) {
                // Need to pick b
                answer.push_back(b);
                // Mark all present multiples of b (<= maxA) as covered
                for (ll m = b; m <= maxA; m += b) {
                    auto it = covered.find(m);
                    if (it != covered.end()) it->second = true;
                }
            }
        }

        // Check every original unique value is covered
        bool all_covered = true;
        for (ll x : uniq) {
            if (!covered[x]) { all_covered = false; break; }
        }

        if (!all_covered) {
            cout << -1 << '\n';
        } else {
            cout << answer.size() << '\n';
            for (size_t i = 0; i < answer.size(); ++i) {
                if (i) cout << ' ';
                cout << answer[i];
            }
            cout << '\n';
        }
    }
    return 0;
}
