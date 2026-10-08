#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for(int i =0;i<n;i++)cin>>arr[i];
    for(int x: arr){
        if(x==k){cout<<"YES\n"; return ;}
    }
    cout<<"NO\n";
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