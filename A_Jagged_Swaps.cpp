#include <bits/stdc++.h>
using namespace std;

void solution(){
    int n;
    cin>>n; 
    vector<int> v(n);
    for(int i =0 ; i < n ;i++)cin>>v[i];
    int x = *min_element(v.begin(),v.end());
    if(v[0]!=x)cout<<"NO\n";
    else cout<<"YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; 
    cin>>t; 
    while(t--){
        solution();
    }
    return 0;
}