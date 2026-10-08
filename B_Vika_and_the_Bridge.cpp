#include <bits/stdc++.h>
using namespace std;

void solution() {
int n, k;
        cin >> n >> k;
        vector<int> c(n);
        for (int i = 0; i < n; ++i) {
            cin >> c[i];
        }
        vector<int> last(k, -1);
        vector<int> max_step(k), max2_step(k);
        for (int i = 0; i < n; ++i) {
            int step = i - last[c[i] - 1];
            if (step > max_step[c[i] - 1]) {
                max2_step[c[i] - 1] = max_step[c[i] - 1];
                max_step[c[i] - 1] = step;
            } else if (step > max2_step[c[i] - 1]) {
                max2_step[c[i] - 1] = step;
            }
            last[c[i] - 1] = i;
        }
        for (int i = 0; i < k; ++i) {
            int step = n - last[i];
            if (step > max_step[i]) {
                max2_step[i] = max_step[i];
                max_step[i] = step;
            } else if (step > max2_step[i]) {
                max2_step[i] = step;
            }
        }
        int ans = INT_MAX;;
        for (int i = 0; i < k; ++i) {
            ans = min(ans, max((max_step[i] + 1) / 2, max2_step[i]));
        }
        cout << ans - 1 <<endl;
    }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}