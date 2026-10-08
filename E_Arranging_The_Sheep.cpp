#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
 
void solution() {
    int n ; cin >> n ;
    string s ; cin >> s ; 

    vector<int> a ; 
    for(int i = 0; i  < n ; i++){
        if(s[i] == '*') a.push_back(i);
    }
    int ind = a.size() / 2 ;
    ll ans = 0;
    for(int i = 0 ; i < a.size() ; i++){
        ans+= abs (a[i] - (a[ind] - ind + i ));
    }
    cout<< ans << endl ; 
    return ; 
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}