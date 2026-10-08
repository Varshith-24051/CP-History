#include <bits/stdc++.h>
using namespace std;

void solution() {
     int n ; cin >> n ; 
     vector<int>a(n);
        for(int& x : a)cin >> x ;
    int minone = 0 , zero = 0 ; 
    int ans= 0 ; 
    for(int i = 0 ; i < n ; i++){
        if(a[i]==-1)minone++;
        else if(a[i]==0)zero++;
    }
    if(minone %2 ==1)ans=ans+2;
    ans=ans+zero;
    cout<<ans<<endl;
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