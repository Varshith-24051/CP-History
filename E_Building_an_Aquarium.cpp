#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solution() {
    int n , total ; cin >> n >> total ; 
    vector<int>a(n);
    for(int& x : a)cin >> x ;
    sort(a.begin(),a.end());
    ll lo = a[0] , hi=a[0] + total  , ans = a[0] ;
    while(lo<=hi){
    ll mid = (lo+ hi )/2;
    ll need = 0 ; 

    for (ll i = 0 ; i < n ;i++){
        if(a[i]<mid)need += mid - a[i];
        if(need> total)break;
    }

    if(need <= total){
        ans = mid;
        lo = mid +1;
    }
    else{ 
        hi = mid -1; 
    }
    }
    cout<< ans<< endl; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}