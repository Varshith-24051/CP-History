#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    if (n < 2) {
        cout << -1; 
        return 0;
    }

    vector<long long> days(n); 
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    long long d = days[1] - days[0];
    bool isAP = true;
    for (int i = 1; i < n - 1; i++) {
        if (days[i+1] - days[i] != d) {
            isAP = false;
            break;
        }
    }

    if (isAP) {
        cout << days[n-1] + d; 
    } else {
        cout << days[n-1];   
    }

    return 0;
}
