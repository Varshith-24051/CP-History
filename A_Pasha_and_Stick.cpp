#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n ; 
    if(n%2!=0){cout<<0; return 0;}
    cout<<(((n+3)/4)-1);
    return 0;
}