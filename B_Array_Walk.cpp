#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n , k , Z ; 
    cin >> n >> k >> Z ;
    vector<int> a(n) ;
    for(int &i :a)cin>> i;

    vector<int> pre(n) ;
    vector<int> best(n);

    pre[0] = a[0] ;
    for(int i = 1 ; i  < n ; i++){
        pre[i] = pre[i-1] + a[i] ;
    }
    
    int max_pair =a[0]+a[1] ;
    best[0] = max_pair ;

    for(int i = 1 ; i < n;i++){
        if(i+1<n){
            max_pair = max(max_pair , a[i]+a[i+1]) ;
        }
        best[i] = max_pair ;
    }
    int ans = 0;
    for(int z = Z; z>=0;z-- ){
        int right = k-2*z;
        if(right>=0 && right<n){
            ans=max(ans , pre[right]+best[right]*z) ;
        }
    }
cout<<ans <<endl; 
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