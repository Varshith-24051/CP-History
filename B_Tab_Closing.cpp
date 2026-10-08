#include <bits/stdc++.h>
using namespace std;

void solution(){
    int a , b , n ; cin >> a >> b >> n ; 
    cout << (((long long )n * b <= a || b >= a) ? "1\n" : "2\n");

    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t ; 
    while(t--)solution();
    return 0;
}
