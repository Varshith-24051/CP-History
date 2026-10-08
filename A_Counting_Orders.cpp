#include <bits/stdc++.h>
using namespace std;
typedef long long ll ; 
void solution() {
     int n ; cin >> n ; 
     vector<ll>a(n);
        for(ll& x : a)cin >> x ;
    vector<ll> b(n);
    for(ll&y : b )cin >> y ; 

sort(a.begin(), a.end(), greater<ll>());
sort(b.begin(), b.end(), greater<ll>()); 

ll ans = 1;
int index = 0;
int temp = 0;

for (ll l : b) {
    while (index < n && a[index] > l) {
        temp++;
        index++;
    }

    if (temp <= 0) {
        ans = 0;
        break;
    }

    ans = ans * temp % 1000000007;
    temp--;
}

    cout<<ans<<endl; 
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}