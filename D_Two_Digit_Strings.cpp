#include <bits/stdc++.h>
using namespace std;
const int mod = 10 ;

void solution() {
    string a ,b ; cin >> a >> b ; 
    int n = a.size() , m = b.size() ; 
    
    vector<int> pa(n+1, 0) , pb(m+1, 0) ;
    for(int i = 0 ; i < n ; i++){
        pa[i+1]= (pa[i] + (a[i]-'0') ) % mod;
    }
    for(int i = 0 ; i < m ; i++){
        pb[i+1]= (pb[i] + (b[i]-'0') ) % mod;
    }
    if(pa[n] != pb[m]){
        cout << -1<<endl ; 
        return ;
    }
    vector<int> dpprev(m+1, 0) , dpcurr(m+1, 0) ;
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= m ; j++){
            dpcurr[j] = max (dpprev[j] , dpcurr[j-1]);

            if(pb[j] == pa[i]){
                dpcurr[j] = max(dpcurr[j], dpprev[j-1]+1) ;
            }
        }
        swap(dpprev, dpcurr) ;
    }
    cout<< dpprev[m]<<endl;
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