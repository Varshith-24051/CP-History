#include <bits/stdc++.h>
using namespace std;

void solution(){
    long long  n , k ; 
    cin >> n >>k;

    if(n%2==0 ||(n-k)%2==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long  t; 
    cin >> t; 
    while(t--){
        solution();
    }
    return 0;
}