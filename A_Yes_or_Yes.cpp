#include <bits/stdc++.h>
using namespace std;

void solution(){
    string s; 
    cin >> s ; 
    int ys = 0 ; 
    for(int i = 0 ; i < s.length() ;i++){
        if(s[i]=='Y')ys++;
        if(ys>=2){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<< "YES"<<endl; 
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t ; cin >> t ; 
    while(t--)solution();
    return 0;
} 