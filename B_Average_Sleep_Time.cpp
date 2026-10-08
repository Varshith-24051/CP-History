#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * Problem: Average Sleep Time (Contribution Method)
 * Logic: Every element a[i] contributes to a specific number of weeks.
 * The multiplier is min(i + 1, n - i, k, n - k + 1).
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total_sum = 0;
    long long total_weeks = n - k + 1;

    for (int i = 0; i < n; i++) {
        long long multiplier = min({ (long long)(i + 1), (long long)(n - i), (long long)k, total_weeks });
                                     
        total_sum += a[i] * multiplier;
    }
    double average = (double)total_sum / total_weeks;

    cout << fixed << setprecision(10) << average << endl;

    return 0;
}