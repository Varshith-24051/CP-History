#include <bits/stdc++.h>
using namespace std;
using ll = long long ; 

void solution() {
    ll k , x ; 
    cin >> k >> x ; 

    ll left = 0 , right = 2*k - 1 ; 
    while(left < right){
        ll  mid = left + (right - left)/2 ;
        if(mid >(2*k-1)/2) {
            ll total = (k*(k+1))/2 + (k*(k-1))/2 - (2*k-1-mid)*(2*k-mid)/2 ;
            if(total >= x) right = mid ; 
            else left = mid + 1 ;
        }
        else if((mid * (mid + 1))/2 >= x) right = mid ; 
        else left = mid + 1 ;

    }
    cout << left << endl;
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