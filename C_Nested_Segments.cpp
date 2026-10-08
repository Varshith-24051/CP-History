#include <bits/stdc++.h>
using namespace std;

struct seg{int l , r, idx;};

void solution() {
    int n ; cin >> n ; 
    vector<seg> a(n) ; 
    for(int i = 0 ; i < n ;i++){
        cin>> a[i].l >> a[i].r;
        a[i].idx=i +1; 
    }
    sort(a.begin(),a.end(),[](const seg &x, const seg &y){
        return x.l ==y.l ? x.r > y.r : x.l < y.l ;
    });
    int maxr = -1 , maxidx = -1; 
    for(const auto& s: a ){
        if(s.r <= maxr){
            cout<< s.idx << " "<< maxidx << endl ; 
            return ; 
        }
        if(s.r > maxr){
            maxr = s.r;
            maxidx = s.idx;
        }
    }
    cout<< -1 << " "<< -1<<endl ;
    return ; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solution();
    return 0;
}