#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; cin >> n ; 
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];

    long long  zeroCount = 0;
    long long  oneCount = 0;
    for( int i = 0 ; i < n ; i++){
        if(a[i] == 0) zeroCount++;
        if(a[i] == 1) oneCount++;
    }
    if(oneCount){
        long long ans = oneCount * pow(2,zeroCount);
        cout<<ans <<endl;
        return;
    }
    cout<<0<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t; 
    while(t--)solution();
    return 0;
}