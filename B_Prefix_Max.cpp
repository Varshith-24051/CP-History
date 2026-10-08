#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ;cin >> n ;
    vector<int> a(n); 
    for( int& x : a)cin >> x;

int maxx = *max_element(a.begin(), a.end());
cout<< maxx*n << endl ;
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