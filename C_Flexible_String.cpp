#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solution() {
    int n , k ; cin >> n >> k ; 
    string a , b ; 
    cin>> a>> b ; 

    vector<int> v ( 26,-1) ; 
    vector<int> u ;
     for(char x : a ){
        if(v[x-'a']==-1){v[x-'a']=u.size(),
        u.push_back(x);}
     }

int ans = 0 ; 
int uc = u.size();
int bc = min(k,uc) ; 

for(int bm = 0 ; bm<(1<<uc);bm++){
    if(__builtin_popcount(bm) != bc)continue;
    
    int count = 0 , match =0 ; 
    for(int i = 0; i < n;i++){
       
        if(a[i]==b[i] || (bm & (1<<v[a[i] -'a']))){
            match++; 
        }
        else{
            count+= match*(match+1)/2; 
            match = 0 ; 
        }
    }
    count+= match*(match+1)/2;
    ans = max(count, ans);

}
cout<<ans<<'\n';
return ; 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}