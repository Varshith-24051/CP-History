#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int pos = 0, neg = 0; 
    for (int i = 0; i < n; i++) {
        if (a[i] >= 0) pos++;
        else neg++;
    }
    int op = 0 ; 

    while( pos<neg || neg%2!=0){
        op++;
        neg--;
        pos++;
    }
    cout<<op <<endl ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t; 
    while (t--) {
        solution();
    }
    return 0;
}
