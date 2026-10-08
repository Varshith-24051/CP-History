#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector<int> v(10,0);


void solution() {
    string s; cin>> s ;
    int ans = 1 ; 
    for(char x : s ){
        ans*= v[x-'0'];
    }
    cout<<ans<<endl; 
    return; 
}

int32_t  main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

for (int i = 0 ; i < 10 ; i++){
    for(int j = 0 ; j < 10 ; j++){
        for(int k = 0 ; k < 10 ; k++){
            if(i+j+k < 10)v[i+j+k]++;
        }
    }
}
    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}