#include <bits/stdc++.h>
using namespace std;

void solution(){
long long  n ; cin >> n ; 
cout<<(((n&(n-1)))? "YES":"NO" )<< endl; 
return; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t; 
    while(t--)solution();
    return 0;
}