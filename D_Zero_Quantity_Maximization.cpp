#include <bits/stdc++.h>
using namespace std;

#define int long long 
void solution() {
    int n ; cin >> n ; 
    vector<int> a(n) , b(n) ; 
    for(auto &x : a)cin >> x ; 
    for(auto &x : b)cin >> x ;

    map <pair<int,int>, int> mp;
    int ans = 0 ; 
    for(int i = 0 ; i < n ;++i ){
        if(a[i] ==0){
            if(b[i] == 0)ans++;
            continue ;
        }
        int p = -b[i];
        int q = a[i]; 

        int g = __gcd(abs(p),abs(q));
        p/=g;
        q/=g;
        if(q < 0){
            p*=-1;
            q*=-1;
        }
        mp[{p, q}]++;
    }
    int mx = 0 ; 
    for(auto &x : mp ){
        mx = max(mx , x.second);
    }
    ans+= mx ; 
    cout<< ans << endl; 
    return ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solution();
    return 0;
}