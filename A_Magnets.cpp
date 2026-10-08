#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin>> n ; 
    vector<int> magnets;
    for ( int i = 0 ; i<n ; i++){
        int save; 
        cin>>save;
        magnets.push_back(save);
    }
    int ans = 1 ; 

    for ( int i = 0 ; i < n-1;i++){
        if ( magnets[i]!= magnets[i+1] ) {
        ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}