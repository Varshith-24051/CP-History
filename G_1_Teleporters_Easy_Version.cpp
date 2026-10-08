#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    long long c;
    cin >> n >> c;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        a[i] = temp + (i + 1);  
    }

    sort(a.begin(), a.end());

    long long sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (sum + a[i] <= c) {
            sum += a[i];
            count++;
        } else break;
    }

    cout << count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();

    return 0;
}
