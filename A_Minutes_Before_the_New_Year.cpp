#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<pair<int,int>> time; 
    int n ; 
    cin>> n ; 
    for ( int i = 0 ; i < n ; i++){
        int first ,second;
        cin>> first >> second;
        time.push_back({first,second});
    }
    for( pair x : time){
        cout<< abs(((x.first* 60) + x.second) - 1440)<<endl;
    }
    return 0;
}