#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ; cin >> n ;
    if(n%3==0) cout<<0<<endl ;
    else
    cout<< 3-(n%3)<<endl ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}