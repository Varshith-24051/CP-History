#include <bits/stdc++.h>
using namespace std;

vector<int>diver(int n ){
    vector<int>d ;
    for(int i = 1 ; i * i <=n ; i++){
        if(n%i)continue; 
        d.push_back(i);
        if(i*i!=n)d.push_back(n/i);
    }
    return d;
}

void solution() {
    int n ; cin >> n; 
    vector<int> a(n) ; 
    for(int &x : a ) cin >> x ; 

    auto div = diver(n);
    int ans = 0 ; 
    for(auto &x : div){
        int m  = 0 ; 
        for(int i = x ; i<n;i++){
            m = gcd (m,abs(a[i] -a[i-x]));
        }
        if(m!= 1 )ans++;
    }
    cout<< ans << endl ;
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