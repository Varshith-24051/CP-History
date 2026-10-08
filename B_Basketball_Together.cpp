#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long D;
    cin >> n >> D;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), greater<long long>());

    int wins = 0;
    int remaining = n;

    for (int i = 0; i < n; i++) {
        long long p = a[i];

        long long need = D / p + 1;

        if (remaining < need)
            break;

        wins++;
        remaining -= need;
    }

    cout << wins << "\n";
    return 0;
}
