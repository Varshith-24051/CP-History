#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n , k ; cin >> n>>k;
    vector<int> a(n);
    for(int i =0 ; i < n ; i++) cin >> a[i];
    int minn = INT_MAX, maxx= INT_MIN;
    int ans = 0 ; 

    for(int i =0 ; i < n ; i++){
        minn = min(minn , a[i]);
        maxx = max(maxx , a[i]);
        if(maxx - minn > 2*k){
            ans++;
            minn  = maxx = a[i];
        }
    }
    cout<< ans <<endl;
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t; 
    while(t--)solution();
    return 0;
}