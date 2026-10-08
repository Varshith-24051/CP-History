#include <bits/stdc++.h>
using namespace std;

long long maxDandelionsMiddleSplit(vector<long long> &fields) {
    vector<long long> odd, even;
    long long sum = 0;

    for (long long x : fields) {
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    if (odd.empty()) return 0;

    sort(odd.rbegin(), odd.rend());
    sum += odd[0];

    for (long long x : even) sum += x;

    vector<long long> remOdd(odd.begin() + 1, odd.end());
    sort(remOdd.begin(), remOdd.end());

    int len = remOdd.size();
    int start = ceil(len / 2.0);
    for (int i = start; i < len; i++) sum += remOdd[i];

    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> fields(n);
        for (int i = 0; i < n; i++) cin >> fields[i];

        cout << maxDandelionsMiddleSplit(fields) << "\n";
    }

    return 0;
}
