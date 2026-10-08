#include <bits/stdc++.h>
using namespace std;

void solution(){
  long long n;
    cin >> n;
    long long ans = 1;
    for(long long i = 1; i <= n; i++){
        if(n % i == 0) ans = i;
        else break;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>> t; 
    while( t--)solution();

    return 0;
} 