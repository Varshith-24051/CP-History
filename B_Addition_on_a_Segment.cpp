#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n; cin >> n ; 
    vector< int> v(n);
    int summ = 0 , non_zero=0;
    for(int i = 0 ; i < n ;i++)cin>>v[i];
    for(int x : v){
        if(x!=0){
            non_zero++;
        }
        summ+=x;
    }
    int ans = min(non_zero,summ);
    if(summ<=n){
        cout<<1<<endl;
        return;
    }
    else { 
        cout<< non_zero<<endl;
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >>t;
    while(t--)solution();
    return 0;
}