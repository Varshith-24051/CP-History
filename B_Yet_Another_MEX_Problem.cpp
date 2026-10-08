#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int>a(n),f(n+2);
        for(auto &x:a){
            cin>>x;
            if(x<=n) f[x]++;
        }

        int mex=0;
        while(f[mex]) mex++;

        cout<<min(mex, k-1)<<"\n";
    }
}