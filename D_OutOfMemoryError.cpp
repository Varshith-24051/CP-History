#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n, m;
    long long h;
    cin >> n >> m >> h;

    vector<long long> orig(n);
    for (int i = 0; i < n; i++) cin >> orig[i];

    vector<long long> add(n, 0);   
    vector<int> last(n, 0);       
    int version = 1;             

    while (m--) {
        int b;
        long long c;
        cin >> b >> c;
        b--; 
        if (last[b] != version) {
            add[b] = 0;
            last[b] = version;
        }

        if (orig[b] + add[b] + c > h) {
            version++; 
        } else {
            add[b] += c;
        }
    }

    for (int i = 0; i < n; i++) {
        if (last[i] == version)
            cout << orig[i] + add[i] << " ";
        else
            cout << orig[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solution();

    return 0;
}
