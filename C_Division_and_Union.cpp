#include <bits/stdc++.h>
using namespace std;

void solution() {
    int n ; cin >> n ;
    vector<int> l(n) , r(n) ,idx(n);
    for(int i =  0 ; i < n ; i++){
        cin >> l[i]>>r[i];
        idx[i] = i;
    }

    sort(idx.begin(),idx.end(),[&](int i , int j ){return l[i]<l[j];});

    vector<int> ans(n,2);
    int maxr = -1 , change = -1; 

    for(int i = 0 ; i < n ;i++){
        int id = idx[i]; 

        if(i> 0 && l[id]> maxr){
            change = i; 
            break; 
        }
        ans[id]=1;
        maxr = max(maxr , r[id]);
    }
    if(change == -1){
        cout<< -1<< endl;
    }else{
        for(int i = 0 ; i < n ;i++){
            cout<< ans[i] << " "; 
        }
        cout<< endl ; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}