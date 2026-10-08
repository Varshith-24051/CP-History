#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ; cin >> n ; 
    vector<int> a(n);
    for (int &x: a)cin >> x ; 

    int temp = 0 ;
    for(int i  = 0 ; i <= n/2 ;i++){
      temp =gcd(temp , abs(a[i] - a[n-1-i])) ;  
    }
    cout << temp << "\n";
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