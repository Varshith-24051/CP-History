#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ; cin >>n ; 
    for(int i = 1 ; i <= n ;i++){
        cout<<i*i<<" ";
    }
    cout<< endl ; 
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