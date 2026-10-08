#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> used;
map<int, vector<int>> mp;

int trace(int v){
    used[v]=1;
    for(int &u : mp[v]){
        if(!used[u]){
            return(trace(u)+1);
        }
    }
    return 1 ;
}
void solution() {
    int n; cin >> n; 
    used.resize(n+1,0);
    used.clear();
    mp.clear();
    bool no = false; 
    for(int i = 0 ; i < n ;i++){
        int x , y; cin >> x >> y; 
        mp[x].push_back(y);
        mp[y].push_back(x);
        if(x==y || mp[x].size() >2 || mp[y].size()>2){no = true ; }

    }
    if(no){
        cout<<"NO"<<endl;
        return;
    }

    for(int i = 0 ; i < n;i++){
        if(!used[i+1]){
            if(trace(i+1) %2 ){
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
    return;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) solution();
    return 0;
}