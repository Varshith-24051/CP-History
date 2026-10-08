#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n;
    cin >> n;

    vector<pair<long long,int>> s(n), m(n), b(n);

    for(int i = 0; i < n; i++) {
        cin >> s[i].first;
        s[i].second = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> m[i].first;
        m[i].second = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    sort(s.begin(), s.end(), greater<>());
    sort(m.begin(), m.end(), greater<>());
    sort(b.begin(), b.end(), greater<>());

    int i = 0, j = 0, k = 0;

    while(i < n && j < n && k < n) {

        int d1 = s[i].second;
        int d2 = m[j].second;
        int d3 = b[k].second;

        // if all days distinct → done
        if(d1 != d2 && d1 != d3 && d2 != d3) {
            cout << s[i].first + m[j].first + b[k].first << "\n";
            return;
        }

        long long v1 = s[i].first;
        long long v2 = m[j].first;
        long long v3 = b[k].first;

        if(v1 <= v2 && v1 <= v3) i++;
        else if(v2 <= v1 && v2 <= v3) j++;
        else k++;
    }

    cout << 0 << "\n"; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solution();
}