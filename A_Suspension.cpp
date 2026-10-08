#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ,y , r ;
    cin>> n>>y >> r;
    cout<<min(r+y/2, n)<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; 
    while(t--)solution();
    return 0;
}