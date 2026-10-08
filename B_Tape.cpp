#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n , m , k ; 
    cin >>n >> m >> k ; 

    vector< int > a (n);
    for( int &x : a )cin >> x ; 

    sort( a.begin() , a.end() );
    vector< int > l (n-1);

    for( int i = 0 ; i < n-1 ;i++){
        l[i] = a[i+1]-a[i] - 1; 
    }
    sort( l.begin() , l.end() );
    long long ans = n;
    for( int i = 0 ; i < n-k ;i++){
        ans += l[i]; 
    }
    cout<< ans << endl ; 
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
solution();
    return 0;
}