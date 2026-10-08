#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;

        int best = 0, bestl = n, bestr = 0;
        int l = 0;
        while (l < n) {
            if (a[l] == 0) {
                l++;
                continue;
            }

            int r = l;
            int tc = 0;
            int neg_count = 0;
            while (r < n && a[r] != 0) {
                if (abs(a[r]) == 2) tc++;
                if (a[r] < 0) neg_count++;
                r++;
            }
            r--;

            if (neg_count % 2 == 0) {
                if (tc > best) {
                    best = tc;
                    bestl = l;
                    bestr = (n - 1) - r;
                }
            } else {
                int cur_l = l, cur_tc = tc;
                while (a[cur_l] > 0) {
                    if (abs(a[cur_l]) == 2) cur_tc--;
                    cur_l++;
                }
                if (abs(a[cur_l]) == 2) cur_tc--;
                cur_l++;
                
                if (cur_tc > best) {
                    best = cur_tc;
                    bestl = cur_l;
                    bestr = (n - 1) - r;
                }

                int cur_r = r, cur_tc2 = tc;
                while (a[cur_r] > 0) {
                    if (abs(a[cur_r]) == 2) cur_tc2--;
                    cur_r--;
                }
                if (abs(a[cur_r]) == 2) cur_tc2--;
                cur_r--;

                if (cur_tc2 > best) {
                    best = cur_tc2;
                    bestl = l;
                    bestr = n - 1 - cur_r;
                }
            }
            l = r + 1;
        }
        cout << bestl << " " << bestr << "\n";
    }
    return 0;
}