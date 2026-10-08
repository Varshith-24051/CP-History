#include <bits/stdc++.h>
using namespace std;

void solution(){
    vector<int> v(4);
    for(int i =0; i <4; i++)cin>>v[i];
    int ans = v[0];
    for(int i =1; i <4; i++){
        if(ans!=v[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solution();
    }
    return 0;
}