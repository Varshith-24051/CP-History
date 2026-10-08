#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n ; 
    cin >>n ; 
    vector< int>a(n);
    for( int i =0 ; i < n ; i++)cin>> a[i];
    for( int  i =0;i < n ; i++){
        cout<<n+1 - a[i]<<" ";
    }
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin >> t; 
    while (t--)
    {
        solution();
    }
    
    return 0;
}
