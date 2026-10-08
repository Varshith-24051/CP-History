#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n;
    vector<long long> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    if (n == 1) {
        cout << 0 << "\n";
        return;
    }

    double prev_r = 0.5;  
    int tangent_pairs = 0;

    for (int i = 1; i < n; i++) {
        double gap = (double)(x[i] - x[i - 1]);
        double curr_r = gap - prev_r;

        if (curr_r <= 0) {
           
            curr_r = 0.5;  
        } else {
            tangent_pairs++;
        }
        prev_r = curr_r;
    }

    cout << tangent_pairs << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) solution();
    return 0;
}
