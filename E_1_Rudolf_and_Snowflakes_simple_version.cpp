#include <bits/stdc++.h>
using namespace std;

using ll = long long; 



void solution(const vector<ll>& a) {
    int n ; cin >> n ; 
    if(a[n]) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
vector<ll> a(1000000,0);
int i = 2 ;
for (i = 2 ; i < 10000; i++){
    int base = i*i ; 
    int summ = 1+i+base; 

    while(summ < 1000000){
        a[summ] = 1 ; 
        base *= i ; 
        summ += base ; 
    }
}
    int t = 1;
    cin >> t;
    while (t--) solution(a);
    return 0;
}