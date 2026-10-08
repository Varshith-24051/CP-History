#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    long long x;
    cin >> n >> x;

    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.rbegin(), a.rend());

    vector<long long> cont;
    cont.reserve(n);

    long long ans = 0;
    long long prev = 0;
    long long accum = 0;

    int left = 0, right = n - 1;

    if(x == 0){
        cout << 0 << "\n";
        for(long long v : a) cout << v << " ";
        cout << "\n";
        return;
    }

    while(left <= right){
        long long cur = (accum + a[left]) / x;

        if(cur == prev){
            cont.push_back(a[right]);
            accum += a[right];
            right--;
        } else {
            cont.push_back(a[left]);
            ans += a[left];
            accum += a[left];
            left++;
        }

        prev = accum / x;
    }

    cout << ans << "\n";
    for(long long v : cont) cout << v << " ";
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solution();

    return 0;
}
