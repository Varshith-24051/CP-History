#include <bits/stdc++.h>
using namespace std;
#define int long long
void solution() {
    int n ; cin >> n ; 
    vector<int> a(n) ; 
    for(int &x : a)cin >> x ; 

    int summ = accumulate(a.begin(), a.end(), 0LL);  
    int rem  =  summ/2 ;
    int ans =  summ - rem; 
    sort(a.rbegin() , a.rend());

    for(int &x : a ){
        if(rem <= 0){
            break;
        }
        rem -= x; 
        ans++; 
    }
    cout<< ans<<endl; 

    return ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}