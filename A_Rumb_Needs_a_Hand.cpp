#include <bits/stdc++.h>
#define int long long
using namespace std;

void solution() {
    int n ; cin >> n ; 
    vector<int> a ; 
    for(int i = 1 ; i <= n ; i++){
        int x ; cin >> x ; 
        if(x != i) a.push_back(x) ;
    }
    
    for(int i = 1 ; i < a.size() ; i++){
        if(a[i] > a[i-1]){
            cout << "NO"<<endl ; 
            return;
        }
    }
    cout << "YES"<<endl ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}