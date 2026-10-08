#include <bits/stdc++.h>
using namespace std;
void solution(){
    int n ; cin >> n ; 
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++) cin >> a[i];
    int x = a[0];
    for( int i = 1 ; i < n ; i++){
        x&=a[i];
    }
    cout << x<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ;cin>> t; 
    while (t--)solution();
    return 0;
}
