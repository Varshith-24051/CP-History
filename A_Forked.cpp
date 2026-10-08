#include <bits/stdc++.h>
using namespace std;

void solution(){
    int a,b,ki,kj,qi,qj;
    cin>>a>>b>>ki>>kj>>qi>>qj;
    int count = 0 ; 
    vector<int> dx = {-1, -1, 1, 1};
    vector<int> dy = {-1, 1, -1, 1};
    set<pair<int,int>> k;
    set<pair<int,int>> q;
    for( int i =0 ; i<4 ; i++){
        k.insert({ki+dx[i]*a,kj+dy[i]*b});
        q.insert({qi+dx[i]*a,qj+dy[i]*b});

        k.insert({ki+dx[i]*b,kj+dy[i]*a});
        q.insert({qi+dx[i]*b,qj+dy[i]*a});

        }
        for(auto it:k){
            if(q.find(it)!=q.end()){
                count++;
            }
        }
        cout<<count<<"\n";
        return;
    }

    int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t; 
    while(t--)solution();
    return 0;
}