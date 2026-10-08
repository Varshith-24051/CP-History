#include <bits/stdc++.h>
using namespace std;

long long bestValue(long long a, long long b) {
    long double target = sqrt((long double)b / a);
    long long k = max(1LL, (long long)target - 5); // small window around sqrt(b/a)

    long long best = -1;
    for (long long offset = -5; offset <= 5; offset++) {
        long long cand = (long long)(target + offset);
        if (cand > 0 && b % cand == 0) {
            long long sum = a * cand + b / cand;
            if (sum % 2 == 0) best = max(best, sum);
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        cout << bestValue(a, b) << "\n";
    }
    return 0;
}
